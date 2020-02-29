//
//  sampling.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_SAMPLING_HPP
#define KOI_SAMPLING_HPP

#include <koi/math/defs.hpp>

namespace koi
{

void uniformSampleHemisphere( const Array2 &i_u, Vec3 &o_sample );

float uniformHemispherePdf();

void cosineSampleHemisphere( const Array2 &i_u, Vec3 &o_sample );

float cosineHemispherePdf( float cosTheta );

void concentricSampleDisk( const Array2 &i_u, Vec2 &o_sample );

} // namespace koi

#endif /* KOI_SAMPLING_HPP */
