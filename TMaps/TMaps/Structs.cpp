//
//  Structs.cpp
//  TMaps
//
//  Created by Umang Shah on 4/1/18.
//  Copyright © 2018 US Inc. All rights reserved.
//

#include "Structs.hpp"
#include "util.h"

/*************** POINT **************/

Point::Point(int a, int b){
    x = a;
    y = b;
}

int Point::getXcoord() const {
    return x;
}
int Point::getYcoord() const {
    return y;
}
void Point::setPoint(int a, int b){
    x = a;
    y = b;
}
void Point::setPtr(std::shared_ptr<Node> node_ptr){
    ptr = node_ptr;
}

/*************** SEGMENT **************/

Point Segment::getPointP(){
    return p;
}

Point Segment::getPointQ(){
    return q;
}
void Segment::setPoints(Point a,Point b){
    p = a;
    q = b;
}
void Segment::setPtr(std::shared_ptr<Node> node_ptr){
    ptr = node_ptr;
}

Segment::Segment(Point a, Point b){
    this->p = a;
    this->q = b;
}

/*************** TRAPEZOID **************/
Trapezoid::Trapezoid(Point a_, Point b_, Point c_, Point d_){
    a = a_;
    b = b_;
    c = c_;
    d = d_;
}

Trapezoid::Trapezoid(Point a_, Point b_, Point c_, Point d_, Point lp, Point rp){
    a = a_;
    b = b_;
    c = c_;
    d = d_;
    rightp = rp;
    leftp = lp;
    
}
void Trapezoid::setPoints(Point a_, Point b_, Point c_, Point d_){
    a = a_;
    b = b_;
    c = c_;
    d = d_;
}


Point Trapezoid::getSupport(int LR){
    //0 - leftp, 1- rightp
    if(LR == 0)
        return leftp;
    else if(LR == 1)
        return rightp;
    else
        return Point();
}

void Trapezoid::setPtr(std::shared_ptr<Node> node_ptr){
    ptr = node_ptr;
}

void Trapezoid::merge(Trapezoid b){
    if(this->a.getXcoord() < b.getPointTopLeft().getXcoord()){
        this->setPoints(this->getPointTopLeft(), b.getPointTopRight(), b.getPointBottomRight(), this->getPointBottomLeft());
    }
    else{
        this->setPoints(b.getPointTopLeft(), this->getPointTopRight(), this->getPointBottomRight(), b.getPointBottomLeft());
    }
}

void Trapezoid::setSupport(int LR, Point x){
    if(LR == 0)
        leftp = x;
    else if(LR == 1)
        rightp = x;
} //0 - left, 1- right


void TMap::setTrapezoid(Point a, std::shared_ptr<Trapezoid> trptr){
    trapezoids[a] = trptr;
}

Trapezoid TMap::getTrapezoid(Point a){
    return *trapezoids[a];
}

void Trapezoid::split_contained(const Point &p, const Point &q, std::vector<Trapezoid> &out_trap){
    // Get the intersecting points on top and btm edge of current Trapezoid
    Point a_dash; // = intrscn of a,b and x= p.x
    Point b_dash; // = intrscn of a,b and x= q.x
    Point c_dash; // = intrscn of c,d and x= q.x
    Point d_dash; // = intrscn of c,d and x= p.x
    
    out_trap.push_back(Trapezoid(a, a_dash, d_dash, d, leftp, p));
    out_trap.push_back(Trapezoid(a_dash, b_dash, q, p, p, q));
    out_trap.push_back(Trapezoid(p, q, c_dash, d_dash, p, q));
    out_trap.push_back(Trapezoid(b_dash, b, c, c_dash, q, rightp));
    
}

Trapezoid Trapezoid::split_leftEndPoint(const Point &p, const Point &q, std::vector<Trapezoid> &out_trap){
    // Get the intersecting points on top and btm edge of current Trapezoid
    Point a_dash; // = intrscn of a,b and x= p.x
    Point d_dash; // = intrscn of c,d and x= p.x
    Point b_dash; // = intrscn of b,c and p,q
    Trapezoid carry_over;
    
    //First independent trapezoid
    out_trap.push_back(Trapezoid(a, a_dash, d_dash, d, leftp, p));
    
    //if rightp is below seg PQ then
    double cross_product = orientationTest(p, q, rightp);
    
    if(cross_product < 0 ){
        //Btm Trap is added, top is carry
        out_trap.push_back(Trapezoid(p, b_dash, c, d_dash, p, rightp));
        carry_over.setPoints(a_dash, b, b_dash, p);
        carry_over.setSupport(0, p);
    }
    
    //else if rightp is above seg PQ
    else if(cross_product > 0){
        //Top Trap is added, btm is carry
        out_trap.push_back(Trapezoid(a_dash, b, b_dash,p, p, rightp));
        carry_over.setPoints(p, b_dash, c, d_dash);
        carry_over.setSupport(0, p);
    }
    return carry_over;
}
