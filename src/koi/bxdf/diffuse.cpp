//
//  diffuse.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "diffuse.hpp"

#include <koi/math/math.hpp>
#include <koi/math/sampling.hpp>

namespace Koi
{

Diffuse::Diffuse()
    : BxDF()
{
}

Spectrum Diffuse::sampleF( const Array2d &i_sample,
                           const Vec3d &i_wo,
                           Vec3d &o_wi,
                           float &o_pdf )
{
    cosineSampleHemisphere( i_sample, o_wi );
    o_pdf = cosineHemispherePdf( CosTheta( o_wi ) );
    
    return computeF( i_wo, o_wi );
}

Spectrum Diffuse::computeF( const Vec3d &i_wo, const Vec3d &i_wi )
{
    return m_albedo * M_1_PI;
}

} // namespace Koi
