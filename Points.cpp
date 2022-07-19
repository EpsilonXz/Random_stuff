#include <iostream>
#include <cmath>

class Point {
private:
    double X;
    double Y;

public:
    Point(double x, double y){
        X = x;
        Y = y;
    }

    //Copy Constructor
    Point(const Point& other){
        X = other.X;
        Y = other.Y;
    }

    int getX() { return X; }
    int getY() { return Y; }

    void setX(double x) { X = x; }
    void setY(double y) { Y = y; }


    bool equals(Point other){
        if(other.getX() == X && other.getY() == Y){
            return true;
        }
        
        return false;
    }
    
    bool isAbove(Point other){
        if(other.getY() < Y){ return true; }
        
        return false;
    }

    bool isUnder(Point other){
        if(!isAbove(other)) { return true; }
        
        return false;
    }

    bool isLeft(Point other){
        if(other.X > X) { return true; }
        
        return false;
    }

    bool isRight(Point other){
        if(!isLeft(other)){ return true; }
        
        return false;
    }

    double distance(Point p){
        double yDis = pow(Y - p.getY(), 2.0);
        double xDis = pow(X - p.getX(), 2.0);

        double d = sqrt(yDis + xDis);

        return d;
    }

    int quadrant(){
        if     (X > 0 && Y > 0) { return 1; }
        else if(X < 0 && Y > 0) { return 2; }
        else if(X < 0 && Y < 0) { return 3; }
        else if(X > 0 && Y < 0) { return 4; }

        return 0;
    }

    void pointLocation(){
        std::cout << "Point location (x,y) -> (" << X << ", " << Y << ")" << std::endl;
    }
};


int main(){
    Point p1 = Point(2.0, 4.0);
    Point p2 = Point(6.0, 1.0);

    p1.pointLocation();
    p2.pointLocation();

    std::cout << p1.isUnder(p2) << std::endl;
    std::cout << p1.distance(p2) << std::endl;
    std::cout << p1.quadrant() << std::endl;

    return 0;
};