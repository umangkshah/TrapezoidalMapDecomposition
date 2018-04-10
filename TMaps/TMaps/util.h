//
//  util.h
//  TMaps
//
//  Created by Umang Shah on 4/7/18.
//  Copyright © 2018 US Inc. All rights reserved.
//

#ifndef util_h
#define util_h

#include "Structs.hpp"

double orientationTest(const Point &p, const Point &q, Point &r){
    double v1 = (p.getXcoord() - r.getXcoord()) * (q.getYcoord() - r.getYcoord());
    double v2 = (p.getYcoord() - r.getYcoord()) * (q.getXcoord() - r.getXcoord());
    return (v1 - v2);
}

#endif /* util_h */
