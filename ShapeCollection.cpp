#include "ShapeCollection.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

void ShapeCollection::free()
{
	for (size_t i = 0; i < size; i++)
		delete shapes[i];
	delete[] shapes;
}

void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	shapes = new Shape*[other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < capacity; i++)
		shapes[i] = other.shapes[i]->clone();

}

void ShapeCollection::resize()
{
	Shape** resizedShapes = new Shape * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
	{
		resizedShapes[i] = shapes[i];
	}

	delete[] shapes;
	shapes = resizedShapes;
}

void ShapeCollection::addShape(Shape* newShape)
{
	if (size == capacity)
		resize();

	shapes[size++] = newShape;
}

void ShapeCollection::addCircle(int x1, int y1, size_t r, const MyString& fill)
{
	Circle* circle = new Circle(x1, y1, r, fill);
	addShape(circle);
}

void ShapeCollection::addTriangle(int x1, int y1, int x2, int y2, int x3, int y3, const MyString& fill)
{
	Shape* triangle = new Triangle(x1, y1, x2, y2, x3, y3, fill);
	addShape(triangle);
}

void ShapeCollection::addRectangle(int x, int y, size_t width, size_t height, const MyString& fill)
{
	Shape* rectangle = new Rectangle(x, y, width, height, fill);
	addShape(rectangle);
}

void ShapeCollection::removeFigure(size_t i)
{
	if (i >= size)
		throw std::logic_error("There is no figure with this index!");

	delete shapes[i];
	for (; i < size-1; i++)
		shapes[i] = shapes[i + 1];
	size--;

}

ShapeCollection::ShapeCollection()
{
	capacity = 8;
	size = 0;
	shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

size_t ShapeCollection::getSize() const
{
	return size;
}

double ShapeCollection::getPerOfFigureByIndex(size_t index) const
{
	if (index >= size)
		throw std::logic_error("Invalid index!");

	return shapes[index]->getPer();
}

double ShapeCollection::getAreaOfFigureByIndex(size_t index) const
{
	if (index >= size)
		throw std::logic_error("Invalid index!");

	return shapes[index]->getArea();
}

double ShapeCollection::getIfPointInShapeByIndex(size_t index, int x, int y) const
{
	if (index >= size)
		throw std::logic_error("Invalid index!");

	return shapes[index]->isPointIn(x, y);
}

Shape* ShapeCollection::operator[](size_t i)const
{
	if (i >= size)
		throw std::logic_error("Invalid index!");
	return shapes[i];
}

void ShapeCollection::printFigures() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		shapes[i]->print();
	}
}

ShapeCollection::~ShapeCollection()
{
	free();
}

