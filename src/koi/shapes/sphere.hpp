//
//  sphere.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_SPHERE_HPP
#define KOI_SPHERE_HPP

#include "shape.hpp"

#include <koi/core/ray.hpp>
#include <koi/math/defs.hpp>

namespace Koi
{

class Sphere : public Shape
{
public:
    
    Sphere();
    Sphere( double i_radius );

    ~Sphere() override = default;
    
    bool intersect( const Ray &i_ray, Intersection &o_intersection ) const override;

private:
    
    double m_radius;
};

} // namespace Koi

#endif /* KOI_SPHERE_HPP */
