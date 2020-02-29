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

namespace koi
{

Diffuse::Diffuse()
    : BxDF()
{
}

Spectrum Diffuse::sampleF( const Array2 &i_sample,
                           const Vec3 &i_wo,
                           Vec3 &o_wi,
                           float &o_pdf )
{
    cosineSampleHemisphere( i_sample, o_wi );
    o_pdf = cosineHemispherePdf( cosTheta( o_wi ) );
    
    return evaluateF( i_wo, o_wi );
}

Spectrum Diffuse::evaluateF( const Vec3 &i_wo, const Vec3 &i_wi )
{
    return m_albedo * M_1_PI;
}

} // namespace koi
