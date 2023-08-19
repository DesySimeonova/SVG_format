#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3,const MyString& fill);

	const double  getArea() const override;
	const double getPer() const override;
	void translate(int horizontal, int vertical) override;
	void print() const override;


	bool isPointIn(int x, int y) const override;
	bool WithinCircle(int x, int y, size_t r) const override;
	bool WithinRect(int x, int y, size_t width, size_t height)const override;

	Shape* clone() const override;

	void createLinePath(MyString& str) const override;

};