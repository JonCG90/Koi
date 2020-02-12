//
//  math.tpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

namespace Koi
{

template < class T >
inline T Lerp( const T &t, const T &v1, const T &v2 )
{
    return ( 1 - t ) * v1 + t * v2;
}

template < class T >
inline T CosTheta( const Vec3< T > &i_w )
{
    return i_w.y;
}

template < class T >
inline T Cos2Theta( const Vec3< T > &i_w )
{
    return i_w.y * i_w.y;
}

template < class T >
inline T AbsCosTheta( const Vec3< T > &i_w )
{
    return std::abs( CosTheta( i_w ) );
}

template < class T >
inline T Sin2Theta( const Vec3< T > &i_w )
{
    return std::max( 1 - Cos2Theta( i_w ), 0 );
}

template < class T >
inline T SinTheta( const Vec3< T > &i_w )
{
    return std::sqrt( Sin2Theta( i_w ) );
}

template < class T >
inline T TanTheta( const Vec3< T > &i_w )
{
    return SinTheta( i_w ) / CosTheta( i_w );
}

template < class T >
inline T Tan2Theta( const Vec3< T > &i_w )
{
    return Sin2Theta( i_w ) / Cos2Theta( i_w );
}

template < class T >
inline T CosPhi( const Vec3< T > &i_w )
{
    T sinTheta = SinTheta( i_w );
    return ( sinTheta == 0 ) ? 1 : std::clamp( i_w.x / sinTheta, -1, 1 );
}

template < class T >
inline T SinPhi( const Vec3< T > &i_w )
{
    T sinTheta = SinTheta( i_w );
    return ( sinTheta == 0 ) ? 1 : std::clamp( i_w.z / sinTheta, -1, 1 );
}

template < class T >
inline T Cos2Phi( const Vec3< T > &i_w )
{
    T cosPhi = CosPhi( i_w );
    return cosPhi * cosPhi;
}

template < class T >
inline T Sin2Phi( const Vec3< T > &i_w )
{
    T sinPhi = SinPhi( i_w );
    return sinPhi * sinPhi;
}

template < class T >
inline T SameHemisphere( const Vec3< T > &i_w1,  const Vec3< T > &i_w2 )
{
    return i_w1.y * i_w2.y > 0;
}

} // namespace Koi
