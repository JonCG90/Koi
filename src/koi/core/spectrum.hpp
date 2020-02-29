//
//  spectrum.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/30/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_SPECTRUM_HPP
#define KOI_SPECTRUM_HPP

#include <koi/math/defs.hpp>

#include <array>

namespace koi
{

#define SPECTRUM_SAMPLE_COUNT 60

using Wavelength = float;
using Wavelengths = std::vector< Wavelength >;

class Spectrum
{
public:
    
    Spectrum();
    Spectrum( float i_value );
    
    ~Spectrum() = default;
    
    Spectrum & operator=( const Spectrum &i_spectrum );
    bool operator==( const Spectrum &i_spectrum ) const;
    bool operator!=( const Spectrum &i_spectrum ) const;
    Spectrum operator+( const Spectrum &i_spectrum ) const;
    Spectrum & operator+=( const Spectrum &i_spectrum );
    Spectrum operator+( float i_constant ) const;
    friend Spectrum operator+( float i_lhs, const Spectrum &i_rhs );
    Spectrum & operator+=( float i_constant );
    Spectrum operator-( const Spectrum &i_spectrum ) const;
    Spectrum & operator-=( const Spectrum &i_spectrum );
    Spectrum operator-( float i_constant ) const;
    friend Spectrum operator-( float i_lhs, const Spectrum &i_rhs );
    Spectrum & operator-=( float i_constant );
    Spectrum operator*( const Spectrum &i_spectrum ) const;
    Spectrum & operator*=( const Spectrum &i_spectrum );
    Spectrum operator*( float i_constant ) const;
    friend Spectrum operator*( float i_lhs, const Spectrum &i_rhs );
    Spectrum & operator*=( float i_constant );
    Spectrum operator/( const Spectrum &i_spectrum ) const;
    Spectrum & operator/=( const Spectrum &i_spectrum );
    Spectrum operator/( float i_constant ) const;
    friend Spectrum operator/( float i_lhs, const Spectrum &i_rhs );
    Spectrum & operator/=( float i_constant );
    Wavelength & operator[]( size_t i_index );
    Wavelength operator[]( size_t i_index ) const;
    
    friend Spectrum sqrt( const Spectrum &i_spectrum );
    
    Vec3f toXYZ() const;
    Vec3f toRGB() const;
    
private:
        
    std::array< Wavelength, SPECTRUM_SAMPLE_COUNT > m_wavelengths;

};

struct SpectrumSample
{
    float wavelength;
    float value;
};

using SpectrumSamples = std::vector< SpectrumSample >;

} // namespace koi

#endif /* spectrum_hpp */
