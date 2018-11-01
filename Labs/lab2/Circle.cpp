// Rectangle.cpp file


#include <iostream>
#include "Circle.h" // The header file for the class - we need this!

using namespace std;



Circle::Circle(){     // default constructor
	X = 0;
	Y = 0;
	radius = 10.0;
}

Circle::Circle(int x, int y, double r)
{
	X = x;
	Y = y;

	if (r > 0)
	{
		radius = r;
	}
	else
		radius = 10.0;
}


// Setters -----------------------------------------------------------


void Circle::move(int horiz, int vert)
{
	X = X + horiz;
	Y = Y + vert;
}



void Circle::setRadius(double r)
{
	if (r > 0)
	{
		radius = r;
	}
	else
		radius = 10.0;
}



// Getters -----------------------------------------------------------


int Circle::getX() const {
	return X;
}

int Circle::getY() const {
	return Y;
}

double Circle::getRadius() const
{
	return radius;
}

double Circle::getArea() const {	
	return (3.1415)*(radius*radius);
}

bool intersect(Circle c)
{
	
}

// Display method ----------------------------------------------------



void Circle::displayCircle() const {
	cout << endl << "radius" << getRadius() << "at point x = " << getX();
	cout << ", y = " << getY() << endl;
}