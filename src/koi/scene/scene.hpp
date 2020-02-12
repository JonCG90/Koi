//
//  scene.hpp
//  Koi
//
//  Created by Jonathan Graham on 2/3/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_SCENE_HPP
#define KOI_SCENE_HPP

#include <koi/shapes/shape.hpp>

#include <vector>

namespace Koi
{

// Forward Declarations
class Intersection;
class Ray;

class Scene
{
public:
    
    Scene() = default;
    ~Scene()= default;
    
    void addShape( ShapePtr i_shape );
    
    bool intersect( const Ray &i_ray, Intersection &o_intersection );
    
private:
    
    std::vector< ShapePtr > m_shapes;
};

} // namespace Koi

#endif /* scene_hpp */
