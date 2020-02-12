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

namespace Koi
{

static float MaxFloat = std::numeric_limits< float >::max();
static double Infinity = std::numeric_limits< double >::infinity();

template < class T >
inline T Lerp( const T &t, const T &v1, const T &v2 );

template < class T >
inline T CosTheta( const Vec3< T > &i_w );

template < class T >
inline T Cos2Theta( const Vec3< T > &i_w );

template < class T >
inline T AbsCosTheta( const Vec3< T > &i_w );

template < class T >
inline T Sin2Theta( const Vec3< T > &i_w );

template < class T >
inline T SinTheta( const Vec3< T > &i_w );

template < class T >
inline T TanTheta( const Vec3< T > &i_w );

template < class T >
inline T Tan2Theta( const Vec3< T > &i_w );

template < class T >
inline T CosPhi( const Vec3< T > &i_w );

template < class T >
inline T SinPhi( const Vec3< T > &i_w );

template < class T >
inline T Cos2Phi( const Vec3< T > &i_w );

template < class T >
inline T Sin2Phi( const Vec3< T > &i_w );

template < class T >
inline T SameHemisphere( const Vec3< T > &i_w1,  const Vec3< T > &i_w2 );

} // namespace Koi

#include "math.tpp"

#endif /* math_hpp */
