//
//  rng.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/16/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_RNG_HPP
#define KOI_RNG_HPP

#include <koi/math/defs.hpp>

#include <random>

namespace koi
{

class RNG
{
public:
    
    RNG();
    ~RNG() = default;
    
    void setSeed( uint i_seed );
    void reset();

    double sample1D() const;
    void sample2D( Array2d &o_samples ) const;
    void sample3D( Array2d &o_samples ) const;
    
private:
    
    uint m_seed;
    mutable std::default_random_engine m_generator;
    mutable std::uniform_real_distribution< double > m_distribution;
};

} // namespace koi

#endif /* KOI_RNG_HPP */
