#include "LEDWallScreen.h"

#include <iostream>

LEDWallScreen::LEDWallScreen(int pW, int pH, int aW, int aH, LEDWallType wallType)
    : panelWidth(pW), panelHeight(pH), aspectWidth(aW), aspectHeight(aH), mode(wallType)
{
}

void LEDWallScreen::DisplayInfo() const
{
    if (mode == LEDWallType::Freeform)
    {
        int cols = targetWidth / panelWidth;
        int rows = targetHeight / panelHeight;
        int wallWidth = cols * panelWidth;
        int wallHeight = rows * panelHeight;

        std::cout << "LED Wall (Freeform) - Columns: " << cols << ", Rows: " << rows
                  << " (Width: " << wallWidth << " mm, Height: " << wallHeight << " mm)\n";
    }
    else if (mode == LEDWallType::Aspect)
    {
        int cols = aspectWidth;
        int rows = aspectHeight;
        int wallWidth = cols * panelWidth;
        int wallHeight = rows * panelHeight;

        std::cout << "LED Wall (Aspect) - Columns: " << cols << ", Rows: " << rows
                  << " (Width: " << wallWidth << " mm, Height: " << wallHeight << " mm)\n";
    }
}

