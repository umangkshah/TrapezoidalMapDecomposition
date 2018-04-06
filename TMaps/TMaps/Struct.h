//
//  Struct.h
//  TMaps
//
//  Created by Umang Shah on 4/1/18.
//  Copyright © 2018 US Inc. All rights reserved.
//

#ifndef Struct_h
#define Struct_h

class Point {
    int x;
    int y;
    Node *ptr;
    
public:
    Point(int x, int y);
    int getXcoord();
    int getYcoord();
    void setPoint(int x, int y);
    void setPtr(Node);
};

class Segment {
    Point p;
    Point q;
    Node *ptr;
    
public:
    Segment(Point p, Point q);
    Point getPointP();
    Point getPointQ();
    void setPoints(Point p,Point q);
    void setPtr(Node);
};

class Trapezoid {
    Point a, b, c, d;
    Node *ptr; // ptr = & node_object
    Point rightp, leftp;
public:
    Trapezoid(Point a, Point b, Point c, Point d);
    Trapezoid(Point a, Point b, Point c, Point d, Point rightp, Point leftp);
    void setPoints(Point a, Point b, Point c, Point d);
    Point getPointA();
    Point getPointB();
    Point getPointC();
    Point getPointD();
    Point getSupport(int); //0 - left, 1- right
    void setPtr(Node);
    void merge(Trapezoid b);
    void setSupport(int LorR, Point x); //0 - left, 1- right
};

class TMap {
    std::map <Point, Trapezoid*> trapezoids;
    /*
     myMap[strFileName] = pObj;
     Or:
     myMap.insert(std::make_pair(strFileName,pObj));
     */
public:
    Trapezoid setTrapezoid(Point a, Trapezoid t);
    Trapezoid getTrapezoid(Point a);
};


#endif /* Struct_h */
