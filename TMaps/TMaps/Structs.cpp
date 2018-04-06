//
//  Structs.cpp
//  TMaps
//
//  Created by Umang Shah on 4/1/18.
//  Copyright © 2018 US Inc. All rights reserved.
//

#include "Structs.hpp"

Point::Point(int a, int b){
    x = a;
    y = b;
}

int Point::getXcoord(){
    return x;
}
int Point::getYcoord(){
    return y;
}
void Point::setPoint(int a, int b){
    x = a;
    y = b;
}
void Point::setPtr(std::shared_ptr<Node> node_ptr){
    ptr = node_ptr;
}

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

Trapezoid::Trapezoid(Point a_, Point b_, Point c_, Point d_){
    a = a_;
    b = b_;
    c = c_;
    d = d_;
}

Trapezoid::Trapezoid(Point a_, Point b_, Point c_, Point d_, Point rp, Point lp){
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
    //0 - left, 1- right
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

