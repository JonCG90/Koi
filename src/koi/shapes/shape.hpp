//
//  shape.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_SHAPE_HPP
#define KOI_SHAPE_HPP

#include <iostream>

namespace koi
{

// Forward Declarations
class Intersection;
class Ray;
class Shape;

using ShapePtr = std::shared_ptr< Shape >;

class Shape
{
public:
    
    Shape() = default;
    virtual ~Shape() = default;
    
    virtual bool intersect( const Ray &i_ray, Intersection &o_intersection ) const = 0;
    
};

} // namespace koi

#endif /* KOI_SHAPE_HPP */
