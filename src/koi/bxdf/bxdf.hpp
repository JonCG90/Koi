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

namespace Koi
{

class Spectrum;

class BxDF
{
public:
    
    BxDF() = default;
    virtual ~BxDF() = default;
    
    virtual Spectrum sampleF( const Array2d &i_sample,
                              const Vec3d &i_wo,
                              Vec3d &o_wi,
                              float &o_pdf ) = 0;

    virtual Spectrum computeF( const Vec3d &i_wo, const Vec3d &i_wi ) = 0;

};

} // namespace Koi

#endif /* KOI_BXDF_HPP */
