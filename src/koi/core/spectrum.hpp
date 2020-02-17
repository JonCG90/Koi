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

namespace Koi
{

#define SPECTRUM_SAMPLE_COUNT 3

class Spectrum
{
public:
    
    Spectrum();
    Spectrum( double i_value );
    
    ~Spectrum() = default;
    
    Vec3d toXYZ() const;
    Vec3d toRGB() const;
    
    Spectrum & operator=( const Spectrum &i_spectrum );
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
    
    friend Spectrum sqrt( const Spectrum &i_spectrum );
    
private:
        
    std::array< double, SPECTRUM_SAMPLE_COUNT > m_wavelengths;
};

struct SpectrumSample
{
    double wavelength;
    double value;
};

using SpectrumSamples = std::vector< SpectrumSample >;

using Wavelength = double;
using Wavelengths = std::vector< Wavelength >;

} // namespace Koi

#endif /* spectrum_hpp */
