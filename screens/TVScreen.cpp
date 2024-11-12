#include "TVScreen.h"

#include <iostream>

TVScreen::TVScreen(int w, int h) : m_width(w), m_height(h)
{
}

void TVScreen::DisplayInfo() const
{
    std::cout << "TV Screen - Width: " << m_width << " mm, Height: " << m_height << " mm\n";
}
