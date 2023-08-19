#pragma once
#include <iostream>
#include "MyString.h"

class Shape
{
protected:
	struct Point
	{
		int x;
		int y;
		Point(int x, int y):x(x),y(y){}
		Point():x(0),y(0){}
		double getDist(const Point& other)
		{
			int dx = x - other.x;
			int dy = y - other.y;
			return sqrt(dx * dx + dy * dy);
		}
	};

private:
	Point* points;
	size_t numOfPoints;
	MyString fill;
	MyString type;

	void free();
	void copyFrom(const Shape& other);

public:
	Shape(size_t numOfPoints, const MyString& fill);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	
	const virtual double getArea() const = 0;
	const virtual double getPer() const = 0;
	virtual void print() const = 0;

	void setType(const MyString& type);
	void setPoint(size_t pointIndex, int x, int y);
	const Point& getPointAtIndex(size_t index) const;
	const MyString& getFill() const;
	virtual bool isPointIn(int x, int y) const = 0;
	virtual bool WithinCircle(int x, int y, size_t r)const=0;
	virtual bool WithinRect(int x, int y, size_t width, size_t height)const=0;

	virtual void translate(int vertical, int horizontal)=0;
	virtual Shape* clone() const = 0;

	virtual void createLinePath(MyString& str) const=0;

	virtual ~Shape();

};