//
//  intersection.hpp
//  Koi
//
//  Created by Jonathan Graham on 2/3/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_INTERSECTION_HPP
#define KOI_INTERSECTION_HPP

#include <koi/math/defs.hpp>

namespace koi
{

struct IntersectionGeometry
{
    Vec3f position;
    Vec2f uv;
    Vec3f dpdu;
    Vec3f dpdv;
    Vec3f dndu;
    Vec3f dndv;
};

class Intersection
{
public:
    Intersection() = default;
    ~Intersection() = default;
    
    IntersectionGeometry geometry;
    
private:
};

} // namespace koi

#endif /* KOI_INTERSECTION_HPP */
