//
//  Koi.cpp
//  Koi
//
//  Created by Jonathan Graham on 1/13/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#include <iostream>
#include "Koi.hpp"
#include "KoiPriv.hpp"

void Koi::HelloWorld(const char * s)
{
    KoiPriv *theObj = new KoiPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void KoiPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << "Blah 5" << std::endl;
};

