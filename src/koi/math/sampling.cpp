//
//  sampling.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "sampling.hpp"

#include <koi/math/defs.hpp>

namespace koi
{

void uniformSampleHemisphere( const Array2 &i_u, Vec3 &o_sample )
{
    // cos(theta) = r1 = y
    // cos^2(theta) + sin^2(theta) = 1 -> sin(theta) = srtf(1 - cos^2(theta))
    const float z = i_u[ 0 ];
    const float sinTheta = std::sqrt( std::max( 0.0, 1.0 - z * z ) );
    const float phi = s_2Pi * i_u[ 1 ];
    
    o_sample = { sinTheta * std::cos( phi ), sinTheta * std::sin( phi ), z };
}

float uniformHemispherePdf()
{
    return 1.0 / s_2Pi;
}

void cosineSampleHemisphere( const Array2 &i_u, Vec3 &o_sample )
{
    Vec2 diskSample;
    concentricSampleDisk( i_u, diskSample );
    
    const float x = diskSample[ 0 ];
    const float y = diskSample[ 1 ];
    const float proj = std::sqrt( std::max( 0.0, 1.0 - x * x - y * y ) );
    
    o_sample = { x, y, proj };
}

float cosineHemispherePdf( float cosTheta )
{
    return cosTheta * s_1_Pi;
}

void concentricSampleDisk( const Array2 &i_u, Vec2 &o_sample )
{
    // Map uniform random numbers to $[-1,1]^2$
    Vec2 uOffset = 2.0f * Vec2( i_u[ 0 ], i_u[ 1 ] ) - Vec2( 1.0, 1.0 );
    
    // Handle degeneracy at the origin
    if ( uOffset.x == 0 && uOffset.y == 0 )
    {
        o_sample = Vec2( 0.0, 0.0 );
        return;
    }
    
    // Apply concentric mapping to point
    float theta;
    float r;
    
    if ( std::abs( uOffset.x ) > std::abs( uOffset.y ) )
    {
        r = uOffset.x;
        theta = s_Pi_4 * ( uOffset.y / uOffset.x );
    }
    else
    {
        r = uOffset.y;
        theta = s_Pi_2 - s_Pi_4 * ( uOffset.x / uOffset.y );
    }
    
    o_sample = r * Vec2( std::cos( theta ), std::sin( theta ) );
}

} // namespace koi
