//
//  defs.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_MATH_DEFS_HPP
#define KOI_MATH_DEFS_HPP

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/detail/precision.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Koi
{

using vec2f = glm::fvec2;
using vec3f = glm::fvec3;
using vec4f = glm::fvec4;
using mat3f = glm::fmat3;
using mat4f = glm::fmat4;
using quatf = glm::fquat;

using vec2d = glm::dvec2;
using vec3d = glm::dvec3;
using vec4d = glm::dvec4;
using mat3d = glm::dmat3;
using mat4d = glm::dmat4;
using quatd = glm::dquat;

using vec2i = glm::ivec2;
using vec3i = glm::ivec3;
using vec4i = glm::ivec4;

using vec2u = glm::uvec2;
using vec3u = glm::uvec3;
using vec4u = glm::uvec4;

template< class T >
using vec2 = glm::tvec2< T, glm::precision::defaultp >;

template< class T >
using vec3 = glm::tvec3< T, glm::precision::defaultp >;

template< class T >
using vec4 = glm::tvec4< T, glm::precision::defaultp >;

template< class T >
using mat3 = glm::tmat3x3< T, glm::precision::defaultp >;

template< class T >
using mat4 = glm::tmat4x4< T, glm::precision::defaultp >;

}

#endif /* KOI_MATH_DEFS_HPP */
