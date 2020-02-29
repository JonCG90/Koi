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

namespace koi
{

Sphere::Sphere()
    : Sphere( 1.0 )
{
}

Sphere::Sphere( float i_radius )
    : Shape()
    , m_radius( i_radius )
{
}

float Sphere::surfaceArea() const
{
    return s_4Pi * m_radius * m_radius;
}

bool Sphere::intersect( const Ray &i_ray, Intersection &o_intersection ) const
{
    const Vec3d &position = i_ray.getPosition();
    const Vec3d &direction = i_ray.getDirection();

    bool hit  = false;
    static const double epsilon = 0.001;
    double t0 = 0.0;
    double t1 = 0.0;
    
    double a = dot( direction, direction );
    double b = 2 * dot( position, direction );
    double c = dot( position, position ) - m_radius * m_radius;
    
    double discr = b * b - 4 * a * c;
    
    if ( discr > 0 ) {
        
        hit = true;
        
        double q = ( b > 0 ) ? -0.5 * ( b + std::sqrt( discr ) )
                             : -0.5 * ( b - std::sqrt( discr ) );
        double x0 = q / a;
        double x1 = c / q;
        
        // Swap
        if ( x0 > x1 )
        {
            std::swap( x0, x1 );
        }
        
        t0 = std::max( x0, 0.0 );
        t1 = std::max( x1, 0.0 );
        
    }
    else if ( discr == 0 )
    {
        hit = true;
        t0 = t1 = - 0.5 * b / a;
    }
    
    if ( hit )
    {
        if ( t0 < epsilon ) {
            t0 = t1;
        }
        
//        if ( fabs( t1 - t0 ) < epsilon || t0 > i_ray.getMaxLength() ) {
//            return false;
//        }
//
//        glm::vec3 hitPosition( position + direction * t0 );
//
//        SurfacePoint surfacePoint;
//        surfacePoint.pos = hitPosition;
//        surfacePoint.normal = glm::normalize( hitPosition );
//        surfacePoint.color = vec4f( 1.0 );
//
//        o_intersection.setSurfacePoint( surfacePoint );
//        o_intersection.t = t0;
    }
    
    return hit;
}

} // namespace koi
