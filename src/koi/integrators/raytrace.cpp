//
//  raytrace.cpp
//  Koi
//
//  Created by Jonathan Graham on 2/3/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "raytrace.hpp"

#include <koi/camera/camera.hpp>
#include <koi/core/ray.hpp>
#include <koi/core/spectrum.hpp>

namespace Koi
{

Spectrum RayTraceIntegrator::computeLi( const Vec2u &i_filmPoint, const Scene &i_scene, CameraPtr i_camera, const Sampler &i_sampler, size_t i_depth )
{
    CameraSample cameraSample;
//    cameraSample.pixelSample = pFilm + i_sampler.sample2D();
//    cameraSample.lensSample = i_sampler.sample2D();
    
    Ray ray;
    double weight = i_camera->generateRay( cameraSample, ray );
    
    // Radiance
    Spectrum radiance;
    
    // Importance
//    Spectrum beta = Spectrum( 1.0 );
//
//    for ( int bounces = 0;; bounces++ ) {
//
//        RayIntersection intersection;
//        bool foundIntersection = i_scene.intersect( ray, intersection );
//
//        float maxDepth = 5;
//        if ( bounces >= maxDepth ) {
//            break;
//        }
//
//        if ( !foundIntersection ) {
//
//            float pdf = 0.0;
//            Spectrum envRadiance = i_scene.evaluateEnvironment( i_sampler.sample2D(), ray, pdf );
//            if ( pdf > 0.0 ) {
//                L += beta * ( envRadiance / pdf );
//            }
//            break;
//        }
//
//        Spectrum Le = intersection.Le();
//
//        // No emission, keep going
//        if ( Le.isBlack() )
//        {
//            // BSDF Sampling
//            const shading::BSDF &bsdf = intersection.getBSDF();
//            const vec3f &surfacePosition = intersection.getSurfacePoint().pos;
//
//            vec3f wo = -intersection.dir;
//            vec3f wi;
//            float pdf = 1.0;
//
//            const vec2f &bsdfSample = i_sampler.sample2D();
//            Spectrum f = bsdf.sampleF( wo, &wi, bsdfSample, &pdf );
//
//            // No point of continuing if no color
//            if ( f.isBlack() || pdf == 0.0 ) {
//                break;
//            }
//
//            // Generate new ray
//            ray = Ray( surfacePosition, wi );
//
//            beta *= ( f * absDot( wi, intersection.getSurfacePoint().normal ) ) / pdf;
//
//            // Russian Roulette termination
//            if ( beta.y() < 1.0f && bounces > 3 ) {
//
//                float q = std::max( .05f, 1 - beta.maxComponentValue() );
//
//                if ( i_sampler.sample1D() > q ) {
//                    beta /= ( 1.0 - q );
//                }
//                else {
//                    break;
//                }
//            }
//        }
//        else {
//            L += beta * intersection.Le();
//            break;
//        }
//    }
    
    return weight * radiance;
}

} // namespace Koi
