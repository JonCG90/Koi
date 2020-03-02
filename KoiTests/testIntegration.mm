//
//  testIntegration.m
//  KoiTests
//
//  Created by Jonathan Graham on 3/2/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#import <XCTest/XCTest.h>

#include <koi/math/math.hpp>

#include <vector>

@interface testIntegration : XCTestCase

@end

@implementation testIntegration

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testIntegrate {
    
    std::vector< double > samples { 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0 };
    std::vector< double > values { 0.0, 10.0, 0.0, 5.0, 10.0, 5.0, 5.0 };

    {
        double sum = koi::integrate( samples, values, -20.0, -10.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 0.0 );
    }
    
    {
        double sum = koi::integrate( samples, values, -20.0, 0.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 0.0 );
    }
    
    {
        double sum = koi::integrate( samples, values, -20.0, 5.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 12.5 );
    }
    
    {
        double sum = koi::integrate( samples, values, -20.0, 10.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 50.0 );
    }
    
    {
        double sum = koi::integrate( samples, values, 0.0, 10.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 50.0 );
    }
    
    {
        double sum = koi::integrate( samples, values, 5.0, 10.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 37.5 );
    }
    
    {
        double sum = koi::integrate( samples, values, 15.0, 25.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 18.75 );
    }
    
    {
        double sum = koi::integrate( samples, values, 40.0, 60.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 125 );
    }
    
    {
        double sum = koi::integrate( samples, values, 45.0, 60.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 81.25 );
    }
    
    {
        double sum = koi::integrate( samples, values, 45.0, 70.0, koi::IntegrationMode::Clamp );
        XCTAssert( sum == 81.25 );
    }
    
    {
        double sum = koi::integrate( samples, values, 45.0, 70.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 131.25 );
    }
    
    {
        double sum = koi::integrate( samples, values, 60.0, 70.0, koi::IntegrationMode::Clamp );
        XCTAssert( sum == 0 );
    }
    
    {
        double sum = koi::integrate( samples, values, 60.0, 70.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 50.0 );
    }
    
    {
        double sum = koi::integrate( samples, values, 65.0, 70.0, koi::IntegrationMode::Constant );
        XCTAssert( sum == 25.0 );
    }
}

@end
