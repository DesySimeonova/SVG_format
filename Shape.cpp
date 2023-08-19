#include "Shape.h"

void Shape::free()
{
	delete[] points;
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.numOfPoints];
	for (size_t i = 0; i < other.numOfPoints; i++)
		points[i] = other.points[i];
	numOfPoints = other.numOfPoints;
	fill = other.fill;
	type = other.type;
}

Shape::Shape(size_t numOfPoints, const MyString& fill):numOfPoints(numOfPoints),fill(fill)
{
	points = new Point[numOfPoints];
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void Shape::setType(const MyString& type)
{
	this->type = type;
}

void Shape::setPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex > numOfPoints)
		throw std::logic_error("Invalid index");
	points[pointIndex] = Point(x, y);
}

const Shape::Point& Shape::getPointAtIndex(size_t index) const
{
	if (index > numOfPoints)
		throw std::logic_error("Invalid index!");
	return points[index];
}

const MyString& Shape::getFill() const
{
	return fill;
}

Shape::~Shape()
{
	free();
}