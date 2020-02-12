//
//  diffuse.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_DIFFUSE_HPP
#define KOI_DIFFUSE_HPP

#include "bxdf.hpp"

#include <koi/core/spectrum.hpp>

namespace Koi
{

class Diffuse : public BxDF
{
public:
    
    Diffuse();
    ~Diffuse() override = default;
    
    Spectrum sampleF( const Array2d &i_sample,
                      const Vec3d &i_wo,
                      Vec3d &o_wi,
                      float &o_pdf ) override;
    
    Spectrum computeF( const Vec3d &i_wo, const Vec3d &i_wi ) override;

    
private:
    
    Spectrum m_albedo;
};

} // namespace Koi

#endif /* KOI_DIFFUSE_HPP */
