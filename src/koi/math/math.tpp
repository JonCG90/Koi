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
inline T lerp( const T &i_t, const T &i_v1, const T &i_v2 )
{
    return ( 1 - i_t ) * i_v1 + i_t * i_v2;
}

template < class T >
inline T cosTheta( const Vec3< T > &i_w )
{
    return i_w.y;
}

template < class T >
inline T cos2Theta( const Vec3< T > &i_w )
{
    return i_w.y * i_w.y;
}

template < class T >
inline T absCosTheta( const Vec3< T > &i_w )
{
    return std::abs( CosTheta( i_w ) );
}

template < class T >
inline T sin2Theta( const Vec3< T > &i_w )
{
    return std::max( 1 - Cos2Theta( i_w ), 0 );
}

template < class T >
inline T sinTheta( const Vec3< T > &i_w )
{
    return std::sqrt( Sin2Theta( i_w ) );
}

template < class T >
inline T tanTheta( const Vec3< T > &i_w )
{
    return SinTheta( i_w ) / CosTheta( i_w );
}

template < class T >
inline T tan2Theta( const Vec3< T > &i_w )
{
    return Sin2Theta( i_w ) / Cos2Theta( i_w );
}

template < class T >
inline T cosPhi( const Vec3< T > &i_w )
{
    T sinTheta = SinTheta( i_w );
    return ( sinTheta == 0 ) ? 1 : std::clamp( i_w.x / sinTheta, -1, 1 );
}

template < class T >
inline T sinPhi( const Vec3< T > &i_w )
{
    T sinTheta = SinTheta( i_w );
    return ( sinTheta == 0 ) ? 1 : std::clamp( i_w.z / sinTheta, -1, 1 );
}

template < class T >
inline T cos2Phi( const Vec3< T > &i_w )
{
    T cosPhi = CosPhi( i_w );
    return cosPhi * cosPhi;
}

template < class T >
inline T sin2Phi( const Vec3< T > &i_w )
{
    T sinPhi = SinPhi( i_w );
    return sinPhi * sinPhi;
}

template < class T >
inline T sameHemisphere( const Vec3< T > &i_w1,  const Vec3< T > &i_w2 )
{
    return i_w1.y * i_w2.y > 0;
}

template < class T, class U >
static U integrate( const std::vector< T > &i_samples,
                    const std::vector< U > &i_values,
                    T i_intervalStart,
                    T i_intervalEnd,
                    IntegrationMode i_mode )
{
    if ( i_samples.empty() || i_values.empty() || i_samples.size() != i_values.size() )
    {
        return static_cast< U >( 0.0 );
    }
    
    const T &firstSample = i_samples.front();
    
    if ( i_samples.size() == 1 )
    {
        return firstSample * ( i_intervalEnd - i_intervalStart );
    }
    
    const T &lastSample = i_samples.back();
    const T intervalDistance = i_intervalEnd - i_intervalStart;

    const U &firstValue = i_values.front();
    const U &lastValue = i_values.back();
    
    // Out of bounds left
    if ( i_intervalEnd <= firstSample )
    {
        return ( i_mode == IntegrationMode::Constant ) ? ( firstValue * ( i_intervalEnd - i_intervalStart ) ) : ( static_cast< U >( 0.0 ) );
    }
    
    // Out of bounds right
    if ( i_intervalStart >= lastSample )
    {
        return ( i_mode == IntegrationMode::Constant ) ? ( lastValue * ( i_intervalEnd - i_intervalStart ) ) : ( static_cast< U >( 0.0 ) );
    }
    
    T sum = static_cast< T  >( 0.0 );
    
    // Constant value to first wavelength
    if ( i_mode == IntegrationMode::Constant && i_intervalStart < firstSample )
    {
        sum += ( firstSample - i_intervalStart ) * firstValue;
    }
    
    auto it = std::upper_bound( i_samples.begin(), i_samples.end(), i_intervalStart );
    if ( it != i_samples.begin() )
    {
        it--;
    }
    
    int index = it - i_samples.begin();
    
    while ( index + 1 < i_samples.size() && i_samples[ index ] < i_intervalEnd )
    {
        const T samplePrev = i_samples[ index ];
        const T sampleNext = i_samples[ index + 1 ];
        const T segmentDistance = sampleNext - samplePrev;

        const U &valuePrev = i_values[ index ];
        const U &valueNext = i_values[ index + 1 ];
        
        // Clip to wavelength bounds
        const T segmentSamplePrev = std::max( samplePrev, i_intervalStart );
        const T segmentSampleNext = std::min( sampleNext, i_intervalEnd );
        
        U t1 = static_cast< U >( ( segmentSamplePrev - samplePrev ) / segmentDistance );
        const U segmentValuePrev = lerp( t1, valuePrev, valueNext );
        
        U t2 = static_cast< U >( ( segmentSampleNext - samplePrev ) / segmentDistance );
        const U segmentValueNext = lerp( t2, valuePrev, valueNext );
        
        sum += ( 0.5 * ( segmentValuePrev + segmentValueNext ) ) * ( segmentSampleNext - segmentSamplePrev );
        
        index++;
    }
    
    // Constant value to last sample
    if ( i_mode == IntegrationMode::Constant && i_intervalEnd > lastSample )
    {
        sum += ( i_intervalEnd - lastSample ) * lastValue;
    }
    
    return sum;
}

} // namespace Koi
