#include <iostream>
using namespace std;

class Point
{
    public:
        void setPointx(int newX); //mutator to set the private data
        void setPointy(int newY);
        int getPointx();// accessor to get the data 
        int getPointy();
        void movePoint(int vertical, int horizontal); // to move the point along the vertical and horizontal directions
        void rotatePoint(); //to rotate the point by 90 degrees clockwise around the origin
        void currentCoordinates() const; // to retrieve current coordinates of the point
        void currentPoint() const;
    private:
        int x;
        int y;
};

void Point::setPointx(int newX)
{
    cout << "Enter the value of the x coordinate of one point:" << endl;
    cin >> newX; // set x coordinate
    x = newX;
}
int Point::getPointx()
{
   return x; // get x coordinate
}
void Point::setPointy(int newY)
{
    cout << "Enter the value of the y coordinate of one point:" << endl;
    cin >> newY;
    y = newY; // set y coordinate
}
int Point::getPointy()
{
   return y; // get y coordinate
}
void Point::movePoint(int vertical, int horizontal)
{
    cout << "How many units would you like to move the point in the x-direction?" << endl;
    cin >> horizontal;
    cout << "How many units would you like to move the point in the y-direction?" << endl;
    cin >> vertical;
    y = y + vertical; // move in the x-direction
    x = x + horizontal; // move in the y-direction
}
void Point::rotatePoint()
{
    int temp;
    temp = x;
    x = y;
    y = temp * -1; //rotation by 90 degrees clockwise from the origin
    
}
void Point::currentCoordinates() const // after moving
{
    cout << "The moved coordinates of the point along the horizontal and vertical directions are: (" << x << "," << y << ")" << endl;
}
void Point::currentPoint() const // after rotating
{
    cout << "The rotated coordinates of the point by 90 degree clockwise around the origin are: (" << x << "," << y << ")" << endl;
}

int main()
{
    Point coordinate1;
    int nX, nY, vert, hori;
    char answer;
    do
    {
    cout << "Please enter the data for a point:" << endl; // point 1
    coordinate1.getPointx();
    coordinate1.setPointx(nX);
    coordinate1.getPointy();
    coordinate1.setPointy(nY);
    coordinate1.movePoint(vert, hori);
    coordinate1.currentCoordinates();
    coordinate1.rotatePoint();
    coordinate1.currentPoint();
    cout << "Would you like to repeat the functions on another point? (Please enter y/n)" << endl;
    cin >> answer;
    }while(answer == 'y');
    /*cout << "Please enter the data for another point:" << endl; // point 2
    coordinate2.getPointx();
    coordinate2.setPointx(nX);
    coordinate2.getPointy();
    coordinate2.setPointy(nY);
    coordinate2.movePoint(vert, hori);
    coordinate2.currentCoordinates();
    coordinate2.rotatePoint();
    coordinate2.currentPoint();
    cout << "Please enter the data for another point:" << endl; // point 3
    coordinate3.getPointx();
    coordinate3.setPointx(nX);
    coordinate3.getPointy();
    coordinate3.setPointy(nY);
    coordinate3.movePoint(vert, hori);
    coordinate3.currentCoordinates();
    coordinate3.rotatePoint();
    coordinate3.currentPoint();*/
    return 0;
    
}