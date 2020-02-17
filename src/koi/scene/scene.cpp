//
//  scene.cpp
//  Koi
//
//  Created by Jonathan Graham on 2/3/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "scene.hpp"

#include <koi/core/ray.hpp>

namespace koi
{

void Scene::addShape( ShapePtr i_shape )
{
    m_shapes.push_back( i_shape );
}

bool Scene::intersect( const Ray &i_ray, Intersection &o_intersection )
{
    for ( const ShapePtr &shape : m_shapes )
    {
        shape->intersect( i_ray, o_intersection );
    }
    
    return false;
}

} // namespace koi

