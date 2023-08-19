#pragma once
#include "Shape.h"

class ShapeCollection
{
	Shape** shapes;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const ShapeCollection& other);
	void resize();
	void addShape(Shape* newShape);

public:

	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);

	size_t getSize() const;

	void addCircle(int x1, int y1, size_t r, const MyString& fill);
	void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3, const MyString& fill);
	void addRectangle(int x, int y, size_t height, size_t width, const MyString& fill);
	void removeFigure(size_t i);

	double getPerOfFigureByIndex(size_t index) const;
	double getAreaOfFigureByIndex(size_t index) const;
	double getIfPointInShapeByIndex(size_t index, int x, int y) const;
	Shape* operator[](size_t i)const;

	void printFigures() const;

	~ShapeCollection();
};
