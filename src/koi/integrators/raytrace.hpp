//
//  raytrace.hpp
//  Koi
//
//  Created by Jonathan Graham on 2/3/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_RAYTRACE_HPP
#define KOI_RAYTRACE_HPP

#include "integrator.hpp"

namespace koi
{

class RayTraceIntegrator : public Integrator
{
public:
    
    RayTraceIntegrator() = default;
    ~RayTraceIntegrator() override = default;
    
    Spectrum computeLi( const Vec2u &i_filmPoint, const Scene &i_scene, CameraPtr i_camera, const Sampler &i_sampler, size_t i_depth ) override;
    
private:
    
};

} // namespace koi


#endif /* KOI_RAYTRACE_HPP */
