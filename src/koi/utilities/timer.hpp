//
//  timer.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/14/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_TIMER_HPP
#define KOI_TIMER_HPP

#include <chrono>

namespace koi
{

class Timer
{
    using high_resolution_clock = std::chrono::high_resolution_clock;
    using nanoseconds = std::chrono::nanoseconds;
    
public:
    
    Timer();
    ~Timer() = default;
    void reset();
    
    double elapsedNanoseconds();
    double elapsedMicroseconds();
    double elapsedMilliseconds();
    double elapsedSeconds();
    
private:
    
    high_resolution_clock::time_point m_start;
};

} // namespace koi

#endif /* KOI_TIMER_HPP */
