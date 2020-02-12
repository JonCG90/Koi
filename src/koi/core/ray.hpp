//
//  ray.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_RAY_HPP
#define KOI_RAY_HPP

#include <koi/math/defs.hpp>

namespace Koi
{

class Ray
{
public:
    
    Ray();
    Ray( const Vec3d &i_position, const Vec3d &i_direction );
    
    const Vec3d & getPosition() const;
    const Vec3d & getDirection() const;

    ~Ray() = default;
    
private:
    
    Vec3d m_position;
    Vec3d m_direction;
};

} // namespace Koi

#endif /* KOI_RAY_HPP */
