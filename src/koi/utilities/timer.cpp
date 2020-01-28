//
//  timer.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/14/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include "timer.hpp"

namespace Koi
{

static const double kMicroToNano = 1000.0;
static const double kMilliToNano = 1000000.0;
static const double kSecToNano = 1000000000.0;

Timer::Timer()
{
    reset();
}

void Timer::reset()
{
    m_start = std::chrono::high_resolution_clock::now();
}

double Timer::elapsedNanoseconds()
{
    const auto elapsed = std::chrono::duration_cast< nanoseconds >( high_resolution_clock::now() - m_start );
    return static_cast< double >( elapsed.count() );
}

double Timer::elapsedMicroseconds()
{
    return elapsedNanoseconds() / kMicroToNano;
}

double Timer::elapsedMilliseconds()
{
    return elapsedNanoseconds() / kMilliToNano;
}

double Timer::elapsedSeconds()
{
    return elapsedNanoseconds() / kSecToNano;
}

}
