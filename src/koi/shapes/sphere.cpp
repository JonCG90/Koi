//
//  sphere.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "sphere.hpp"

#include <koi/core/ray.hpp>
#include <koi/core/intersection.hpp>
#include <koi/math/defs.hpp>
#include <koi/math/math.hpp>

namespace koi
{

Sphere::Sphere()
    : Sphere( 1.0 )
{
}

Sphere::Sphere( float i_radius )
    : Shape()
    , m_radius( i_radius )
    , m_thetaMin( 0.0 )
    , m_thetaMax( s_Pi )
    , m_phiMin( 0.0 )
    , m_phiMax( s_2Pi )
    , m_deltaTheta( m_thetaMax - m_thetaMin )
    , m_deltaPhi( m_phiMax - m_phiMin )
{
}

float Sphere::surfaceArea() const
{
    return s_4Pi * m_radius * m_radius;
}

bool Sphere::intersect( const Ray &i_ray, Intersection &o_intersection ) const
{
    const Ray ray = i_ray;
    
    const Vec3 &position = ray.getPosition();
    const Vec3 &direction = ray.getDirection();
    
    // Near and far hits
    float t0 = 0.0;
    float t1 = 0.0;
    
    // Compute quadratic solutions:
    // x^2 + y^2 + z^2 - r^2 = 0
    // = ( ox + t dx )^2 + ( oy + t dy )^2 + ( oy + t dy )^2 - r^2 = 0
    // = at^2 + bt + c = 0
    // where a = dx^2 + dy^2 + dz^2
    //       b = 2( dx ox + dy oy + dz oz )
    //       c = ox^2 + oy^2 + oz^2 - r^2
    const float a = direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;
    const float b = 2.0 * ( direction.x * position.x + direction.y * position.y + direction.z * position.z );
    const float c = position.x * position.x + position.y * position.y + position.z * position.z - m_radius * m_radius;
    
    if ( !quadratic( a, b, c, t0, t1 ) )
    {
        return false;
    }
    
    if ( t0 > ray.getMaxT() || t1 <= 0.0 )
    {
        return false;
    }
    
    float tHit = t0;
    if ( tHit <= 0.0 )
    {
        tHit = t1;
    }
    
    Vec3 hitPosition;
    
    // Check for intersection against partial spheres
    if ( !intersectPartial( ray, tHit, hitPosition ) )
    {
        if ( tHit == t1 )
        {
            return false;
        }
        
        tHit = t1;
        if ( !intersectPartial( ray, tHit, hitPosition ) )
        {
            return false;
        }
    }
    
    fillIntersection( hitPosition, o_intersection );

    return true;
}

bool Sphere::intersectPartial( const Ray &i_ray, float i_t, Vec3 &o_hitPosition ) const
{
    o_hitPosition = i_ray( i_t );
    
    // Compute theta and phi using spherical coordinates
    // x = r sin(θ) cos(φ)
    // y = r sin(θ) sin(φ)
    // z = r cos(θ)
    
    float theta = 0.0;
    float phi = 0.0;
    cartesianToSpherical( o_hitPosition, m_radius, theta, phi );
    
    if ( theta < m_thetaMin || theta > m_thetaMax || phi < m_phiMin || phi > m_phiMax )
    {
        return false;
    }
    
    return true;
}

void Sphere::fillIntersection( const Vec3 &i_hitPosition, Intersection &o_intersection ) const
{
    Vec3 position = i_hitPosition;
    
    float theta = 0.0;
    float phi = 0.0;
    cartesianToSpherical( position, m_radius, theta, phi );
    
    const float u = ( phi - m_phiMin ) / m_deltaPhi;
    const float v = ( theta - m_thetaMin ) / m_deltaTheta;
    
    // Take derivative for phi
    // dx/du = d/du( r sin(θ) cos(φ) ) = -r sin(θ) sin(φ) = -y
    // dy/du = d/du( r sin(θ) sin(φ) ) =  r sin(θ) cos(φ) =  x
    // dz/du = d/du( r cos(θ)        ) =  0               =  0
    const Vec3 dpdu = m_deltaPhi * Vec3( -position.y, position.x, 0.0 );

    // Take derivative for theta
    // dx/dv = d/dv( r sin(θ) cos(φ) ) =  r cos(θ) cos(φ) =  z cos(φ)
    // dy/dv = d/dv( r sin(θ) sin(φ) ) =  r cos(θ) sin(φ) =  z sin(φ)
    // dz/dv = d/dv( r cos(θ)        ) = -r sin(θ)        = -r sin(θ)
    
    // Compute sin and cos phi using trig as it's much faster than calling sin and cos
    const float hypotenuse = std::sqrt( position.x * position.x + position.y * position.y );
    const float invHypotenuse = 1.0 / hypotenuse;
    const float sinPhi = position.y * invHypotenuse;
    const float cosPhi = position.x * invHypotenuse;
    
    const Vec3 dpdv = m_deltaTheta * Vec3( position.z * cosPhi, position.z * sinPhi, -m_radius * std::sin( theta ) );
    
    // Take the second derivative for theta
    // dx^2/du = d^2/du( -r sin(θ) sin(φ) ) = -r sin(θ) cos(φ) = -x
    // dy^2/du = d^2/du(  r sin(θ) cos(φ) ) = -r sin(θ) sin(φ) = -y
    // dz^2/du = d^2/du(  0               )                    =  0
    const Vec3 d2pdudu = m_deltaPhi * m_deltaPhi * Vec3( -position.x, -position.y, 0.0 );
    
    // Take the second derivative for theta
    // dx^2/dudv = d^2/dv( -r sin(θ) sin(φ) ) = -r cos(θ) sin(φ) = -z sin(φ)
    // dy^2/dudv = d^2/dv(  r sin(θ) cos(φ) ) =  r cos(θ) cos(φ) =  z cos(φ)
    // dz^2/dudv = d^2/dv(  0               ) =                     0
    const Vec3 d2pdudv = m_deltaTheta * m_deltaPhi * Vec3( -position.z * sinPhi, position.z * cosPhi, 0.0 );

    // dx^2/dv = d^2/dv(  r cos(θ) cos(φ) ) = -r sin(θ) cos(φ) = -x
    // dy^2/dv = d^2/dv(  r cos(θ) sin(φ) ) = -r sin(θ) sin(φ) = -y
    // dz^2/dv = d^2/dv( -r sin(θ)        ) = -r cos(θ)        = -z
    const Vec3 d2pdvdv = m_deltaTheta * m_deltaTheta * Vec3( -position.x, -position.y, -position.z );

    // Compute normal partial derivatives using Weingarten equations
    const float E = dot( dpdu, dpdu );
    const float F = dot( dpdu, dpdv );
    const float G = dot( dpdv, dpdv );
    
    const Vec3 n = normalize( cross( dpdu, dpdv ) );
    
    const float e = dot( n, d2pdudu );
    const float f = dot( n, d2pdudv );
    const float g = dot( n, d2pdvdv );

    float invEGF2 = 1.0 / ( E * G - F * F );
    Vec3 dndu = ( ( f * F - e * G ) * invEGF2 * dpdu ) + ( ( e * F - f * E ) * invEGF2 * dpdv );
    Vec3 dndv = ( ( g * F - f * G ) * invEGF2 * dpdu ) + ( ( f * F - g * E ) * invEGF2 * dpdv );
    
    // Fill in geo info
    IntersectionGeometry &geoInfo = o_intersection.geometry;
    geoInfo.position = position;
    geoInfo.uv = Vec2( u, v );
    geoInfo.dpdu = dpdu;
    geoInfo.dpdv = dpdv;
    geoInfo.dndu = dndu;
    geoInfo.dndv = dndv;
}

} // namespace koi
