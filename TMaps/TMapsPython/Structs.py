import numpy
NODE_XNODE = 0
NODE_YNODE = 1
NODE_LEAF = 2
NULL = numpy.nan

class Element():
    pass

class Node():
    type = 0
    ele = Element()
    left_child = NULL 
    right_child = NULL

class Point(Element):
    x = NULL
    y = NULL
    ptr = Node()

    def __init__(self, x=-1, y=-1, ptr = NULL):
        self.x = x
        self.y = y
        self.ptr = ptr
    
    def getXcoord(self):
        return self.x

    def getYcoord(self):
        return self.y
    
    def setPoint(self,x,y):
        self.x = x
        self.y = y
    
    def setPtr(self,n):
        self.ptr = n

    def __eq__(self,a,b):
        return a.x==b.x and a.y==b.y
    

class Segment(Element):
    p = NULL
    q = NULL
    ptr = NULL

    def __init__(self, p=NULL, q=NULL, ptr=NULL):
        self.p = p
        self.q = q
        self.ptr = ptr
    
    def getPointP(self):
        return self.p

    def getPointQ(self):
        return self.q
    
    def setPoints(self,p,q):
        self.p = p
        self.q = q
    
    def setPtr(self,ptr):
        self.ptr = ptr

# Trapezoid






