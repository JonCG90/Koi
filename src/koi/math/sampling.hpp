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

namespace Koi
{

void uniformSampleHemisphere( const Array2d &i_u, Vec3d &o_sample );

double uniformHemispherePdf();

void cosineSampleHemisphere( const Array2d &i_u, Vec3d &o_sample );

float cosineHemispherePdf( double cosTheta );

void concentricSampleDisk( const Array2d &i_u, Vec2d &o_sample );

} // namespace Koi

#endif /* KOI_SAMPLING_HPP */
