//
//  sphere.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "sphere.hpp"

#include <koi/core/ray.hpp>
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
    , m_zMin( -i_radius )
    , m_zMax( i_radius )
    , thetaMin( 0.0 )
    , thetaMax( 0.0 )
    , phiMax( 0.0 )
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
    
    const Vec3 hitPosition = ray( tHit );
    
    
    return false;
}

} // namespace koi
