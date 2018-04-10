//
//  Structs.hpp
//  TMaps
//
//  Created by Umang Shah on 4/1/18.
//  Copyright © 2018 US Inc. All rights reserved.
//

#ifndef Structs_hpp
#define Structs_hpp

#include <stdio.h>
#include <map>
#include <memory>
#include <vector>

#define NODE_XNODE 0
#define NODE_YNODE 1
#define NODE_LEAF 2

class Element{};

class Node {
    int type;
    std::shared_ptr<Element> ele;
    Node *left_child;
    Node *right_child;
    Node* parent;
    
public:
//    Node(int type_, Element* ele_, Node* lc_, Node* rc_): type(type_), ele(ele_), left_child(lc_), right_child(rc_)
//    {}
};

class Point : Element {
    int x;
    int y;
    std::shared_ptr<Node> ptr;
    
public:
    Point(): x(-1), y(-1), ptr(nullptr) {}
    Point(int x, int y);
    int getXcoord() const;
    int getYcoord() const;
    void setPoint(int x, int y);
    void setPtr(std::shared_ptr<Node>);
    friend bool operator== (Point a, Point b){
        return a.x == b.x && a.y == b.y;
    }
};

class Segment : Element{
    Point p;
    Point q;
    std::shared_ptr<Node> ptr;
    
public:
    Segment() : p(), q(), ptr(nullptr) {}
    Segment(Point p, Point q);
    Point getPointP();
    Point getPointQ();
    void setPoints(Point p,Point q);
    void setPtr(std::shared_ptr<Node>);
};

class Trapezoid : Element{
    Point a, b, c, d;
    std::shared_ptr<Node> ptr;
    Point rightp, leftp;
public:
    Trapezoid(){}
    Trapezoid(Point a_, Point b_, Point c_, Point d_);
    Trapezoid(Point a, Point b, Point c, Point d, Point leftp, Point rightp);
    void setPoints(Point a, Point b, Point c, Point d);
    Point getPointTopLeft(){ return a; };
    Point getPointTopRight(){ return b; };
    Point getPointBottomRight(){ return c; };
    Point getPointBottomLeft(){ return d; };
    Point getSupport(int); //0 - left, 1- right
    void setPtr(std::shared_ptr<Node>);
    void merge(Trapezoid b);
    void setSupport(int LorR, Point x); //0 - left, 1- right
    
    friend bool operator== (Trapezoid &a, Trapezoid &b){
        return a.getPointTopLeft() == b.getPointTopLeft();
    }
    void split_contained(const Point &p, const Point &q, std::vector<Trapezoid> &out_trap);
    Trapezoid split_leftEndPoint(const Point &p, const Point &q, std::vector<Trapezoid> &out_trap);
};

class TMap {
    std::map <Point, std::shared_ptr<Trapezoid> > trapezoids;
    /*
     myMap[strFileName] = pObj;
     Or:
     myMap.insert(std::make_pair(strFileName,pObj));
     */
public:
    void setTrapezoid(Point a,  std::shared_ptr<Trapezoid>);
    Trapezoid getTrapezoid(Point a);
};

class SearchTree{
    Node *root;
    
public:
    Trapezoid search(const Point &query);
    Trapezoid getTopRight(const Point &start_point);
    Trapezoid getBottomRight(const Point &start_point);
};



#endif /* Structs_hpp */
