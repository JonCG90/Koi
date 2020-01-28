//
//  rng.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/16/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_RNG_HPP
#define KOI_RNG_HPP

#include <random>

namespace Koi
{

class RNG
{
public:
    
    RNG();
    ~RNG() = default;
    
    void setSeed( uint i_seed );
    void reset();

    double sample1D() const;
    void sample2D( std::array< double, 2 > &o_samples ) const;
    void sample3D( std::array< double, 3 > &o_samples ) const;
    
private:
    
    uint m_seed;
    mutable std::default_random_engine m_generator;
    mutable std::uniform_real_distribution< double > m_distribution;
};

}

#endif /* KOI_RNG_HPP */
