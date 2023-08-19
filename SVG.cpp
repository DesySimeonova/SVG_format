#include "SVG.h"
#include "MyString.h"
#include<iostream>
#include<fstream>
#pragma warning (disable:4996)
using namespace std;

SVG::SVG() :collection() {}

bool file_exists(const MyString name) 
{
    ifstream file(name.getString(), ios::_Nocreate);
    if (file.fail())
    {
        file.close();
        return false;
    }
    else
    {
        file.close();
        return true;
    }
}

void SVG::readFiguresFile()
{
    if (file_exists("figures.txt"))
    {
        fstream input("figures.txt");
        if (!input.is_open())
            throw logic_error("File is not open!");

        char lineBuff[100];
        size_t lineBuffSize = sizeof(lineBuff);
        bool startReading = false;
        while (input.getline(lineBuff, lineBuffSize))
        {
            if (strcmp(lineBuff, "<svg>") == 0)
            {
                startReading = true;
                break;
            }
        }
        if (startReading == true)
        {
            while (input.getline(lineBuff, lineBuffSize) && strcmp(lineBuff, "</svg>") != 0)
            {
                size_t currIndex = 0;
                char figureType[20];
                size_t figureTypeIter = 0;
                while (currIndex <= lineBuffSize)
                {
                    if (lineBuff[currIndex] == '<')
                    {
                        currIndex++;
                        while (lineBuff[currIndex] != ' ')
                        {
                            figureType[figureTypeIter++] = lineBuff[currIndex++];
                        }
                        figureType[figureTypeIter] = '\0';
                        break;
                    }
                    currIndex++;
                }

                if (strcmp(figureType, "rect") == 0)
                {
                    int x = 0; int y = 0;
                    size_t width = 0; size_t hight = 0;
                    char fill[20];
                    currIndex++;
                    while (lineBuff[currIndex] != '/' && lineBuff[currIndex + 1] != '>')
                    {
                        if (lineBuff[currIndex] == '"')
                        {
                            if (lineBuff[currIndex - 2] == 'x')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (x *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 2] == 'y')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (y *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 6] == 'w')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (width *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 7] == 'h')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (hight *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 5] == 'f')
                            {
                                currIndex++;
                                size_t fillIter = 0;
                                while (lineBuff[currIndex] != '"')
                                {
                                    fill[fillIter++] = lineBuff[currIndex++];
                                }
                                fill[fillIter] = '\0';
                            }
                        }
                        currIndex++;
                    }
                    collection.addRectangle(x, y, width, hight, fill);
                }

                if (strcmp(figureType, "circle") == 0)
                {
                    int x = 0; int y = 0; int r = 0;
                    char fill[20];
                    currIndex++;
                    while (lineBuff[currIndex] != '/' && lineBuff[currIndex + 1] != '>')
                    {
                        if (lineBuff[currIndex] == '"')
                        {
                            if (lineBuff[currIndex - 2] == 'x')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (x *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 2] == 'y')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (y *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 2] == 'r')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (r *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 5] == 'f')
                            {
                                currIndex++;
                                size_t fillIter = 0;
                                while (lineBuff[currIndex] != '"')
                                {
                                    fill[fillIter++] = lineBuff[currIndex++];
                                }
                                fill[fillIter] = '\0';
                            }
                        }
                        currIndex++;
                    }
                    collection.addCircle(x, y, r, fill);
                }

                if (strcmp(figureType, "triangle") == 0)
                {
                    int x1 = 0; int y1 = 0; int x2 = 0; int y2 = 0; int x3 = 0; int y3 = 0;
                    char fill[20];
                    currIndex++;
                    while (lineBuff[currIndex] != '/' && lineBuff[currIndex + 1] != '>')
                    {
                        if (lineBuff[currIndex] == '"')
                        {
                            if (lineBuff[currIndex - 3] == 'x' && lineBuff[currIndex - 2] == '1')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (x1 *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 3] == 'y' && lineBuff[currIndex - 2] == '1')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (y1 *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 3] == 'x' && lineBuff[currIndex - 2] == '2')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (x2 *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 3] == 'y' && lineBuff[currIndex - 2] == '2')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (y2 *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 3] == 'x' && lineBuff[currIndex - 2] == '3')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (x3 *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 3] == 'y' && lineBuff[currIndex - 2] == '3')
                            {
                                currIndex++;
                                while (lineBuff[currIndex] != '"')
                                {
                                    (y3 *= 10) += lineBuff[currIndex++] - '0';
                                }
                            }

                            if (lineBuff[currIndex - 5] == 'f')
                            {
                                currIndex++;
                                size_t fillIter = 0;
                                while (lineBuff[currIndex] != '"')
                                {
                                    fill[fillIter++] = lineBuff[currIndex++];
                                }
                                fill[fillIter] = '\0';
                            }
                        }
                        currIndex++;
                    }
                    collection.addTriangle(x1, y1, x2, y2, x3, y3, fill);
                }

            }
        }
        input.close();
    }
}

void SVG::LoadSVG()
{
	if (file_exists("figures.txt"))
	{
		readFiguresFile();
	}
    cout << "Successfully opened file!" << endl;
}

void SVG::menu(const MyString command)
{
    if (command == "print")
        Print();
    if (command == "create")
        Create();
    if (command == "erase")
    {
        size_t index;
        cout << "Index of figure you want to erase: ";
        cin >> index;
        Erase(index);
    }
    if (command == "translate")
    {
        Translate();
    }
    if (command == "translate figure")
    {
        size_t index;
        cout << "Index of figure you want to translate: ";
        cin >> index;
        Translate(index);
    }
    if (command == "point in")
    {
        size_t x, y;
        cout << "Enter x:";
        cin >> x;
        cout << "Enter y:";
        cin >> y;
        PointIn(x,y);
    }
    if (command == "within")
    {
        Within();
    }
    if (command == "areas")
    {
        Areas();
    }
    if (command == "pers")
    {
        Pers();
    }
    if (command == "save")
    {
        save();
    }
}

void SVG::Print()const
{
    collection.printFigures();
}

void SVG::Create() 
{
    MyString figure;
    cout << "Type of figure: ";
    cin >> figure;

    if (figure == "rectangle")
    {
        int x, y;
        size_t height, width;
        MyString fill;
        cout << "x=";
        cin >> x;
        cout << "y=";
        cin >> y;
        cout << "width=";
        cin >> width;
        cout << "height=";
        cin >> height;
        cout << "fill: ";
        cin >> fill;
        collection.addRectangle(x, y, width, height, fill);
        cout << "Successfully created rectangle (" << collection.getSize() << ")" << endl;
    }

    if (figure == "circle")
    {
        int x, y;
        size_t r;
        MyString fill;
        cout << "x=";
        cin >> x;
        cout << "y=";
        cin >> y;
        cout << "radius=";
        cin >> r;
        cout << "fill: ";
        cin >> fill;
        collection.addCircle(x, y, r, fill);
        cout << "Successfully created circle (" << collection.getSize() << ")" << endl;
    }

    if (figure == "triangle")
    {
        int x1, y1, x2, y2, x3, y3;
        MyString fill;
        cout << "x1=";
        cin >> x1;
        cout << "y1=";
        cin >> y1;
        cout << "x2=";
        cin >> x2;
        cout << "y2=";
        cin >> y2;
        cout << "x3=";
        cin >> x3;
        cout << "y3=";
        cin >> y3;
        cout << "fill: ";
        cin >> fill;
        collection.addTriangle(x1, y1, x2, y2, x3, y3, fill);
        cout << "Successfully created triangle (" << collection.getSize() << ")" << endl;
    }
}

void SVG::Erase(size_t index)
{
    collection.removeFigure(index);
    cout << "Erased a figure (" << index << ")" << endl;
}

void SVG::Translate()
{
    int vertical, horizontal;
    cout << "vertical=";
    cin >> vertical;
    cout << "  horizontal=";
    cin >> horizontal;
    cout << endl;
    for (size_t i = 0; i < collection.getSize(); i++)
    {
        collection[i]->translate(vertical, horizontal);
    }
    cout << "Translated all figures!"<<endl;
}

void SVG::Translate(size_t index)
{
    int vertical, horizontal;
    cout << "vertical=";
    cin >> vertical;
    cout << "  horizontal=";
    cin >> horizontal;
    cout << endl;
    collection[index]->translate(vertical, horizontal);
    cout << "Translated figure ("<<index<<")" << endl;
}

void SVG::Areas() const
{
    for (size_t i = 0; i < collection.getSize(); i++)
        cout <<i<<". S=" << collection.getAreaOfFigureByIndex(i) << endl;
}

void SVG::Pers() const
{
    for (size_t i = 0; i < collection.getSize(); i++)
        cout << i << ". P=" << collection.getPerOfFigureByIndex(i) << endl;
}

void SVG::PointIn(int x, int y) const
{
    bool check = 0;
    for (size_t i = 0; i < collection.getSize(); i++)
    {
        if (collection[i]->isPointIn(x, y))
        {
            collection[i]->print();
            check = 1;
        }
    }
    if (!check)
        cout << "There is no figure around this point!"<<endl;
}


void SVG::Within() const
{
    MyString regionType;
    cout << "Region type: ";
    cin >> regionType;
    cout << endl;

    if (regionType == "rectangle")
    {
        int x, y;
        size_t height, width;
        cout << endl << "x=";
        cin >> x;
        cout << " y=";
        cin >> y;
        cout << " width=";
        cin >> width;
        cout << " height=";
        cin >> height;

        for (size_t i = 0; i < collection.getSize(); i++)
        {
            if (collection[i]->WithinRect(x, y, width, height))
                collection[i]->print();
        }
    }

    if (regionType == "circle")
    {
        int x, y;
        size_t r;
        cout << endl << "x=";
        cin >> x;
        cout << " y=";
        cin >> y;
        cout << " radius=";
        cin >> r;

        for (size_t i = 0; i < collection.getSize(); i++)
        {
            if (collection[i]->WithinCircle(x, y, r))
                collection[i]->print();
        }
    }
}

void SVG::save() const
{
    ofstream output("figures.txt");

    if (!output.is_open())
        throw logic_error("File is not open!");

    output << "<svg>" << endl;

    for (size_t i = 0; i < collection.getSize(); i++)
    {
        MyString line = " <";
        collection[i]->createLinePath(line);
        output.write(line.getString(), line.getSize());
        output << endl;
    }
    output << "</svg>";
    output.close();

    cout << "Successfully saved the changes to figures.txt!" << endl;
}