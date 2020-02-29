//
//  bxdf.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_BXDF_HPP
#define KOI_BXDF_HPP

#include <koi/math/defs.hpp>

namespace koi
{

class Spectrum;

class BxDF
{
public:
    
    BxDF() = default;
    virtual ~BxDF() = default;
    
    virtual Spectrum sampleF( const Array2 &i_sample,
                              const Vec3 &i_wo,
                              Vec3 &o_wi,
                              float &o_pdf ) = 0;

    virtual Spectrum evaluateF( const Vec3 &i_wo, const Vec3 &i_wi ) = 0;

};

} // namespace koi

#endif /* KOI_BXDF_HPP */
