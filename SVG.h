#pragma once
#include "ShapeCollection.h"

class SVG
{
	ShapeCollection collection;
public:
	SVG();

	void readFiguresFile();
	void LoadSVG();
	void menu(const MyString command);

	void Print()const;
	void Create();
	void Erase(size_t index);
	void Translate();
	void Translate(size_t index);
	void Areas() const;
	void Pers() const;
	void PointIn(int x, int y) const;
	void Within() const;
	

	void save() const;

};