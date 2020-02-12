//
//  sampling.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "sampling.hpp"

#include <koi/math/defs.hpp>

namespace Koi
{

void uniformSampleHemisphere( const Array2d &i_u, Vec3d &o_sample )
{
    // cos(theta) = r1 = y
    // cos^2(theta) + sin^2(theta) = 1 -> sin(theta) = srtf(1 - cos^2(theta))
    const double z = i_u[ 0 ];
    const double sinTheta = std::sqrtf( std::max( 0.0, 1 - z * z ) );
    const double phi = 2 * M_PI * i_u[ 1 ];
    
    o_sample = { sinTheta * std::cosf( phi ), sinTheta * std::sinf( phi ), z };
}

double uniformHemispherePdf()
{
    return 1.0 / ( 2.0 * M_PI );
}

void cosineSampleHemisphere( const Array2d &i_u, Vec3d &o_sample )
{
    Vec2d diskSample;
    concentricSampleDisk( i_u, diskSample );
    
    const double x = diskSample[ 0 ];
    const double y = diskSample[ 1 ];
    const double proj = std::sqrt( std::max( 0.0, 1.0 - x * x - y * y ) );
    
    o_sample = { x, y, proj };
}

float cosineHemispherePdf( double cosTheta )
{
    return cosTheta * M_1_PI;
}

void concentricSampleDisk( const Array2d &i_u, Vec2d &o_sample )
{
    // Map uniform random numbers to $[-1,1]^2$
    Vec2d uOffset = 2.0 * Vec2d( i_u[ 0 ], i_u[ 1 ] ) - Vec2d( 1.0, 1.0 );
    
    // Handle degeneracy at the origin
    if ( uOffset.x == 0 && uOffset.y == 0 )
    {
        o_sample = Vec2d( 0.0, 0.0 );
        return;
    }
    
    // Apply concentric mapping to point
    double theta;
    double r;
    
    if ( std::abs( uOffset.x ) > std::abs( uOffset.y ) )
    {
        r = uOffset.x;
        theta = M_PI_4 * ( uOffset.y / uOffset.x );
    }
    else
    {
        r = uOffset.y;
        theta = M_PI_2 - M_PI_4 * ( uOffset.x / uOffset.y );
    }
    
    o_sample = r * Vec2d( std::cos( theta ), std::sin( theta ) );
}

} // namespace Koi
