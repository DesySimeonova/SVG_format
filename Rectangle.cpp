
#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, size_t hight, size_t width, const MyString& fill):Shape(4,fill)
{
	setPoint(0, x, y);
	setPoint(1, x, y - hight);
	setPoint(2, x - width, y);
	setPoint(3, x - width, y-hight);
	setType("rectangle");
	this->height = hight;
	this->width = width;
}

const double Rectangle::getArea() const
{
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);
	Shape::Point p2 = getPointAtIndex(2);

	return p0.getDist(p1) * p0.getDist(p2);
}

const double Rectangle::getPer() const
{
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);
	Shape::Point p2 = getPointAtIndex(2);

	return p0.getDist(p1) * 2 + p0.getDist(p2) * 2;
}

void Rectangle::translate(int vertical, int horizontal)
{
	setPoint(0, getPointAtIndex(0).x + horizontal, getPointAtIndex(0).y + vertical);
}

void Rectangle::print() const
{
	std::cout << "rectangle " << getPointAtIndex(0).x << " " << getPointAtIndex(0).y << " " << width << " " << height<<" " << getFill() << std::endl;
}

bool Rectangle::isPointIn(int x, int y) const
{
	Shape::Point p(x, y);
	return p.x >= getPointAtIndex(0).x && p.y >= getPointAtIndex(1).x &&
		p.y <= getPointAtIndex(0).y && p.y >= getPointAtIndex(2).y;
}

int max(int a, int b)
{
	int res= a > b ? a : b;
	return res;
}

bool Rectangle::WithinCircle(int x, int y, size_t r) const
{
	double dx = max(x - getPointAtIndex(0).x, getPointAtIndex(2).x - x);
	double dy = max(y - getPointAtIndex(0).y, getPointAtIndex(2).y - y);
	return r * r >= dx * dx + dy * dy;
}

bool Rectangle::WithinRect(int x, int y, size_t width, size_t height)const
{
	return getPointAtIndex(0).x >= x && getPointAtIndex(2).x <= x + width
		&& getPointAtIndex(0).y <= y && getPointAtIndex(2).y >= y - height;
}

Shape* Rectangle::clone() const
{
	Shape* copy = new Rectangle(*this);
	return copy;
}

void Rectangle::createLinePath(MyString& str) const
{
	str += "rect x=\"";
	str += getPointAtIndex(0).x;
	str += "\" y=\"";
	str += getPointAtIndex(0).y;
	str += "\" width=\"";
	str += width;
	str += "\" height=\"";
	str += height;
	str += "\" fill=\""; str += getFill();
	str += "\"/>";
}