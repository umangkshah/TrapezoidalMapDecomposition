//
//  main.cpp
//  TMaps
//
//  Created by Umang Shah on 4/1/18.
//  Copyright © 2018 US Inc. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Structs.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    TMap tmap;
    SearchTree search_tree;
    //Create [accept as input] a bunch of line segments
    // sample: (10,10,20, 20), (20,20, 40,40), (20,60, 40,50)
    Point p1(10,10); Point q1(20,20);
    Point p2(20, 10); Point q2(40, 40);
    Point p3(20, 60); Point q3(60, 70);
    std::vector<Segment> segments;
    segments.push_back(Segment(p1, q1));
    segments.push_back(Segment(p2, q2));
    segments.push_back(Segment(p3, q3));
   
    //Bounding Box
    Point b1(0,0); Point b2(100,0);
    Point b3(0, 100);
    Point b4(100, 100);
    
    
    segments.push_back(Segment(b1, b2));
    segments.push_back(Segment(b2, b3));
    segments.push_back(Segment(b1, b4));
    segments.push_back(Segment(b4, b3));
    Trapezoid bounding(b1, b2, b3, b4);
    shared_ptr<Trapezoid> boundingBox( &bounding );
    tmap.setTrapezoid(b1, boundingBox);
    //put it in TMAP
    for(std::vector<Segment>::iterator it = segments.begin(); it != segments.end(); it++){
        //i have *it
        //
        Trapezoid trap1 = search_tree.search(it->getPointP());
        Trapezoid trapN = search_tree.search(it->getPointQ());
        if(trap1 == trapN){
            //contained
        }
        else{
            //segment follow algo
            //Let p and q be the left and right endpoint of si.
//            2. Search with p in the search structure D to find Δ0. ---> trap0
            int j = 0;
            
//            while q lies to the right of rightp(Δj)
            Point rightP_tmp = trap1.getSupport(1);
            while(it->getPointQ().getXcoord() > rightP_tmp.getXcoord()){
//                if rightp(Δj) lies above si
                
//                double v1 = (it->getPointP().getXcoord() - rightP_tmp.getXcoord()) * (it->getPointQ().getYcoord() - rightP_tmp.getYcoord())
//                double v2 = (it->getPointP().getYcoord() - rightP_tmp.getYcoord()) * (it->getPointQ().getXcoord() - rightP_tmp.getXcoord())
//                double cross_product = v1 - v2;
                
                
//                if cross_product > 0:
//                    IT LIES ABOVE (LEFT)
            // 6. then Let Δj+1 be the lower right neighbor of Δj.
                //use search tree start at
//                    elif xp < 0:
//                    IT LIES BELOW (RIGHT)
//                7. else Let Δj+1 be the upper right neighbor of Δj.
//
                
                        
                        
                
                        //8. j← j+1
                        //9. return Δ0,Δ1, . . . ,Δj
                        
            }
            
            
        }
    }
    
    std::cout << "run.";
    return 0;
    
}
