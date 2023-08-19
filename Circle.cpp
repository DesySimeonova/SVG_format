#include "Circle.h"

const double PI = 3.1415;

Circle::Circle(int x, int y, size_t r, const MyString& fill):Shape(1,fill)
{
	setPoint(0, x, y);
	setType("circle");
	this->r = r;
}

const double Circle::getArea() const
{
	return PI * (r * r);
}

const double Circle::getPer() const
{
	return 2 * PI * r;
}

void Circle::translate(int vertical, int horizontal)
{
	setPoint(0, getPointAtIndex(0).x + horizontal, getPointAtIndex(0).y + vertical);
}

void Circle::print() const
{
	std::cout << "circle " << getPointAtIndex(0).x << " " << getPointAtIndex(0).y << " " << r <<" " << getFill() << std::endl;
}

bool Circle::isPointIn(int x, int y) const
{
	Shape::Point p(x, y);
	return p.getDist(getPointAtIndex(0)) <= r;
}


bool Circle::WithinCircle(int x, int y, size_t r) const
{
	Shape::Point p(x, y);
	double dist = p.getDist(getPointAtIndex(0));
	return r > (dist + this->r);
}

bool Circle::WithinRect(int x, int y, size_t width, size_t height)const
{
	return getPointAtIndex(0).x + r<x + width && getPointAtIndex(0).x - r > x
		&& getPointAtIndex(0).y + r < y && getPointAtIndex(0).y - r > y - height;
}

Shape* Circle::clone() const
{
	Shape* copy = new Circle(*this);
	return copy;
}

void Circle::createLinePath(MyString& str) const
{
	str += "circle x=\"";
	str += getPointAtIndex(0).x;
	str += "\" y=\"";
	str += getPointAtIndex(0).y;
	str += "\" r=\"";
	str += r;
	str += "\" fill=\""; str += getFill();
	str += "\"/>";
}