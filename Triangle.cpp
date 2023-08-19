#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, const MyString& fill):Shape(3,fill)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
	setType("triangle");
}

const double Triangle::getArea() const
{
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);
	Shape::Point p2 = getPointAtIndex(2);

	return abs(p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p0.y * p1.x - p1.y * p2.x - p2.y * p0.x) / 2.00;

}

const double Triangle::getPer() const
{
	Shape::Point p0 = getPointAtIndex(0);
	Shape::Point p1 = getPointAtIndex(1);
	Shape::Point p2 = getPointAtIndex(2);

	return p0.getDist(p1)+p0.getDist(p2)+p1.getDist(p2);

}

void Triangle::translate(int horizontal, int vertical)
{
	setPoint(0, getPointAtIndex(0).x + horizontal, getPointAtIndex(0).y + vertical);
	setPoint(1, getPointAtIndex(1).x + horizontal, getPointAtIndex(1).y + vertical);
	setPoint(2, getPointAtIndex(2).x + horizontal, getPointAtIndex(2).y + vertical);
}

void Triangle::print() const
{
	std::cout << "triangle " << getPointAtIndex(0).x << " " << getPointAtIndex(0).y<<" "<< getPointAtIndex(1).x << " " << getPointAtIndex(1).y <<" " << getPointAtIndex(2).x << " " << getPointAtIndex(2).y << " " << getFill() << std::endl;
}

bool Triangle::isPointIn(int x, int y) const
{
	Shape::Point p(x, y);
	Triangle t1(getPointAtIndex(0).x, getPointAtIndex(0).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y,"");
	Triangle t2(getPointAtIndex(2).x, getPointAtIndex(2).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y, "");
	Triangle t3(getPointAtIndex(2).x, getPointAtIndex(2).y, getPointAtIndex(0).x, getPointAtIndex(0).y, p.x, p.y, "");

	return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon();
}


bool Triangle::WithinCircle(int x, int y, size_t r) const
{
	return (getPointAtIndex(0).x + x)*(getPointAtIndex(0).x + x) + (getPointAtIndex(0).y + y)* (getPointAtIndex(0).y + y) <= r * r
		&& (getPointAtIndex(1).x + x) * (getPointAtIndex(1).x + x) + (getPointAtIndex(1).y + y) * (getPointAtIndex(1).y + y) <= r * r
		&& (getPointAtIndex(2).x + x) * (getPointAtIndex(2).x + x) + (getPointAtIndex(2).y + y) * (getPointAtIndex(2).y + y) <= r * r;
}

bool Triangle::WithinRect(int x, int y, size_t width, size_t height)const
{
	return (getPointAtIndex(0).x >= x && getPointAtIndex(1).x <= x + width && getPointAtIndex(0).y <= y && getPointAtIndex(1).y >= y - height)
		&& (getPointAtIndex(0).x >= x && getPointAtIndex(2).x <= x + width && getPointAtIndex(0).y <= y && getPointAtIndex(2).y >= y - height)
		&& (getPointAtIndex(1).x >= x && getPointAtIndex(2).x <= x + width && getPointAtIndex(1).y <= y && getPointAtIndex(2).y >= y - height);
}

Shape* Triangle::clone() const
{
	Shape* copy = new Triangle(*this);
	return copy;
}

void Triangle::createLinePath(MyString& str) const
{
	str += "triangle x1=\"";
	str += getPointAtIndex(0).x;
	str += "\" y1=\"";
	str+= getPointAtIndex(0).y;
	str += "\" x2=\"";
	str += getPointAtIndex(1).x;
	str += "\" y2=\"";
	str += getPointAtIndex(1).y;
	str += "\" x3=\"";
	str += getPointAtIndex(2).x;
	str += "\" y3=\"";
	str += getPointAtIndex(2).y;
	str += "\" fill=\""; str += getFill();
	str += "\"/>";

	//std::cout << str;
}