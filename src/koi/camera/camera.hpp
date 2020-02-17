//
//  camera.hpp
//  Koi
//
//  Created by Jonathan Graham on 2/3/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_CAMERA_HPP
#define KOI_CAMERA_HPP

#include <koi/math/defs.hpp>

#include <iostream>

namespace koi
{

// Forward Declarations
class Camera;
class Ray;

using CameraPtr = std::shared_ptr< Camera >;

struct CameraSample {
    Vec2u pointFilm;
    Vec2u pointLens;
    float time;
};

class Camera
{
public:
    
    Camera() = default;
    virtual ~Camera() = default;
    
    virtual double generateRay( const CameraSample &i_sample, Ray &o_ray ) = 0;
};

} // namespace koi

#endif /* camera_hpp */
