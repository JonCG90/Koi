//
//  math.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_MATH_HPP
#define KOI_MATH_HPP

#include "defs.hpp"

namespace koi
{

static float MaxFloat = std::numeric_limits< float >::max();
static double Infinity = std::numeric_limits< double >::infinity();

enum class IntegrationMode
{
    Clamp,
    Constant,
};

template < class T >
inline T lerp( const T &i_t, const T &i_v1, const T &i_v2 );

template < class T >
inline T cosTheta( const Vec3T< T > &i_w );

template < class T >
inline T cos2Theta( const Vec3T< T > &i_w );

template < class T >
inline T absCosTheta( const Vec3T< T > &i_w );

template < class T >
inline T sin2Theta( const Vec3T< T > &i_w );

template < class T >
inline T sinTheta( const Vec3T< T > &i_w );

template < class T >
inline T tanTheta( const Vec3T< T > &i_w );

template < class T >
inline T tan2Theta( const Vec3T< T > &i_w );

template < class T >
inline T CcosPhi( const Vec3T< T > &i_w );

template < class T >
inline T sinPhi( const Vec3T< T > &i_w );

template < class T >
inline T cos2Phi( const Vec3T< T > &i_w );

template < class T >
inline T sin2Phi( const Vec3T< T > &i_w );

template < class T >
inline T sameHemisphere( const Vec3T< T > &i_w1,  const Vec3T< T > &i_w2 );

template < class T, class U >
static U integrate( const std::vector< T > &i_samples,
                    const std::vector< U > &i_values,
                    T i_intervalStart,
                    T i_intervalEnd,
                    IntegrationMode i_mode = IntegrationMode::Clamp );

template < class T >
inline bool quadratic( T i_a, T i_b, T i_c, T &o_v0, T &o_v1 );

} // namespace koi

#include "math.tpp"

#endif /* math_hpp */
