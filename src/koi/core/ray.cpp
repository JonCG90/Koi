//
//  ray.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "ray.hpp"

namespace koi
{

Ray::Ray()
    : Ray( Vec3d(), Vec3d( 0.0, 0.0, 1.0 ) )
{
}

Ray::Ray( const Vec3d &i_position, const Vec3d &i_direction )
    : m_position( i_position )
    , m_direction( i_direction )
{
}

const Vec3d & Ray::getPosition() const
{
    return m_position;
}

const Vec3d & Ray::getDirection() const
{
    return m_direction;
}

} // namespace koi
