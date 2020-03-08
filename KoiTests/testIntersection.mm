//
//  testIntersection.m
//  KoiTests
//
//  Created by Jonathan Graham on 3/2/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#import <XCTest/XCTest.h>

#include <koi/core/intersection.hpp>
#include <koi/core/ray.hpp>
#include <koi/math/defs.hpp>
#include <koi/shapes/sphere.hpp>

@interface testIntersection : XCTestCase

@end

@implementation testIntersection

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testSphereIntersection {
    
    koi::Ray ray( koi::Vec3f( 0.0, -15.0, 0.0 ), koi::Vec3f( 0.0, 1.0, 0.0 ) );
    koi::Sphere sphere( 10.0 );
    koi::Intersection intersection;
    
    bool hit = false;
    
    hit = sphere.intersect( ray, intersection );
    XCTAssertTrue( hit );
}

@end
