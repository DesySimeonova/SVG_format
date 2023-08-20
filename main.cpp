
#include <iostream>
#include "SVG.h"
#include "MyString.h"


int main()
{
    SVG app;
    app.LoadSVG();
    MyString command;
    std::cout << ">";
    std::cin >> command;
    size_t count=0;
    while (!(command == "exit"))
    {
        if (count > 0)
        {
            std::cout << ">";
            std::cin >> command;
        }
        app.menu(command);
        count++;
    }


    return 0;
}
