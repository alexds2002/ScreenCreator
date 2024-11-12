#include "LEDWallScreen.h"
#include "ConfigurationStrategy.h"

#include <iostream>

LEDWallScreen::LEDWallScreen(int pW, int pH, int tW, int tH, std::unique_ptr<ScreenConfigurationStrategy>&& strategy)
    : panelWidth(pW), panelHeight(pH), targetWidth(tW), targetHeight(tH), configurationStrategy(std::move(strategy))
{
    if (configurationStrategy)
    {
        ScreenConfig config = configurationStrategy->Configure(panelWidth, panelHeight, targetWidth, targetHeight);
        actualWidth = config.width;
        actualHeight = config.height;
    }
    else
    {
        std::cerr << "LEDWall is missing a configuration" << std::endl;
    }
}

void LEDWallScreen::DisplayInfo() const
{
    std::cout << "LED Wall Screen Info:" << std::endl;
    std::cout << "Panel Width: " << panelWidth << " mm" << std::endl;
    std::cout << "Panel Height: " << panelHeight << " mm" << std::endl;
    std::cout << "Target Width: " << targetWidth << " mm" << std::endl;
    std::cout << "Target Height: " << targetHeight << " mm" << std::endl;

    // Print the actual calculated width and height after applying configuration
    std::cout << "Calculated Wall Width (Actual): " << actualWidth << " mm" << std::endl;
    std::cout << "Calculated Wall Height (Actual): " << actualHeight << " mm" << std::endl;
}
