//
//  rng.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/16/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "rng.hpp"

// C++
#include <array>

namespace Koi
{

RNG::RNG()
    : m_seed( 0 )
    , m_generator( std::default_random_engine() )
    , m_distribution( std::uniform_real_distribution< double >( 0.0, 1.0 ) )
{
    reset();
}

void RNG::setSeed( uint i_seed )
{
    m_seed = i_seed;
    reset();
}

void RNG::reset()
{
    m_generator.seed( m_seed );
}

double RNG::sample1D() const
{
    return m_distribution( m_generator );
}

void RNG::sample2D( std::array< double, 2 > &o_samples ) const
{
    o_samples[ 0 ] = m_distribution( m_generator );
    o_samples[ 1 ] = m_distribution( m_generator );
}

void RNG::sample3D( std::array< double, 3 > &o_samples ) const
{
    o_samples[ 0 ] = m_distribution( m_generator );
    o_samples[ 1 ] = m_distribution( m_generator );
    o_samples[ 2 ] = m_distribution( m_generator );
}

}
