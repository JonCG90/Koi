//
//  integrator.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_INTEGRATOR_HPP
#define KOI_INTEGRATOR_HPP

#include <koi/camera/camera.hpp>
#include <koi/math/defs.hpp>

namespace koi
{

// Forward Declarations
class Sampler;
class Scene;
class Spectrum;

class Integrator
{
public:
    
    Integrator() = default;
    virtual ~Integrator() = default;
    
    // Computes incoming radiance
    virtual Spectrum computeLi( const Vec2u &i_filmPoint,
                                const Scene &i_scene,
                                CameraPtr i_camera,
                                const Sampler &i_sampler,
                                size_t i_depth ) = 0;
};

} // namespace koi

#endif /* integrator_hpp */
