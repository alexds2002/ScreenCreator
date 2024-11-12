#include "LEDWallScreen.h"

#include <iostream>

LEDWallScreen::LEDWallScreen(int pW, int pH, int aW, int aH, LEDWallType wallType)
    : m_panelWidth(pW), m_panelHeight(pH), m_aspectWidth(aW), m_aspectHeight(aH), m_mode(wallType)
{
}

void LEDWallScreen::DisplayInfo() const
{
    if (m_mode == LEDWallType::Freeform)
    {
        int cols = m_targetWidth / m_panelWidth;
        int rows = m_targetHeight / m_panelHeight;
        int wallWidth = cols * m_panelWidth;
        int wallHeight = rows * m_panelHeight;

        std::cout << "LED Wall (Freeform) - Columns: " << cols << ", Rows: " << rows
                  << " (Width: " << wallWidth << " mm, Height: " << wallHeight << " mm)\n";
    }
    else if (m_mode == LEDWallType::Aspect)
    {
        int cols = m_aspectWidth;
        int rows = m_aspectHeight;
        int wallWidth = cols * m_panelWidth;
        int wallHeight = rows * m_panelHeight;

        std::cout << "LED Wall (Aspect) - Columns: " << cols << ", Rows: " << rows
                  << " (Width: " << wallWidth << " mm, Height: " << wallHeight << " mm)\n";
    }
}

