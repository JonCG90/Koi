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

namespace koi
{

class Ray
{
public:
    
    Ray();
    Ray( const Vec3d &i_position, const Vec3d &i_direction );
    
    Vec3d operator()( double i_t ) const;
    
    const Vec3d & getPosition() const;
    const Vec3d & getDirection() const;
    
    float getT() const;
    float getMaxT() const;

    ~Ray() = default;
    
private:
    
    Vec3d m_position;
    Vec3d m_direction;
    
    float m_t;
    float m_tMax;
};

} // namespace koi

#endif /* KOI_RAY_HPP */
