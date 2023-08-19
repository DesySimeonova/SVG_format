#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
	size_t height;
	size_t width;

public:
	Rectangle(int x, int y, size_t height, size_t width, const MyString& fill);

	const double getArea() const override;
	const double getPer() const override;
	void translate(int vertical, int horizontal) override;
	void print() const override;


	bool isPointIn(int x, int y) const override;
	bool WithinCircle(int x, int y, size_t r) const override;
	bool WithinRect(int x, int y, size_t width, size_t height)const override;
	Shape* clone() const override;

	void createLinePath(MyString& str) const override;
};