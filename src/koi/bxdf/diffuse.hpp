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

namespace koi
{

class Diffuse : public BxDF
{
public:
    
    Diffuse();
    ~Diffuse() override = default;
    
    Spectrum sampleF( const Array2 &i_sample,
                      const Vec3 &i_wo,
                      Vec3 &o_wi,
                      float &o_pdf ) override;
    
    Spectrum evaluateF( const Vec3 &i_wo, const Vec3 &i_wi ) override;

    
private:
    
    Spectrum m_albedo;
};

} // namespace koi

#endif /* KOI_DIFFUSE_HPP */
