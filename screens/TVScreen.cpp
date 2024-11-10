#include "TVScreen.h"

#include <iostream>

TVScreen::TVScreen(int w, int h) : width(w), height(h)
{
}

void TVScreen::DisplayInfo() const
{
    std::cout << "TV Screen - Width: " << width << " mm, Height: " << height << " mm\n";
}
