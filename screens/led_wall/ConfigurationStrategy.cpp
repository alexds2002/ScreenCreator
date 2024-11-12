#include "ConfigurationStrategy.h"

#include <iostream>

// Freeform configuration strategy
ScreenConfig FreeformConfiguration::Configure(int panelWidth, int panelHeight, int targetWidth, int targetHeight) const
{
    ScreenConfig config;
    int cols = targetWidth / panelWidth;
    int rows = targetHeight / panelHeight;
    config.width = cols * panelWidth;
    config.height = rows * panelHeight;

    std::cout << "Freeform LED Wall:\n";
    std::cout << "Columns: " << cols << ", Rows: " << rows << "\n";
    std::cout << "Wall Dimensions: " << config.width << " mm x " << config.height << " mm\n";

    return config;
}

// Aspect ratio configuration strategy
ScreenConfig AspectConfiguration::Configure(int aspectWidth, int aspectHeight, int panelWidth, int panelHeight) const
{
    ScreenConfig config;
    int cols = aspectWidth;
    int rows = aspectHeight;
    config.width = cols * panelWidth;
    config.height = rows * panelHeight;

    std::cout << "Aspect Ratio LED Wall (" << aspectWidth << ":" << aspectHeight << "):\n";
    std::cout << "Columns: " << cols << ", Rows: " << rows << "\n";
    std::cout << "Wall Dimensions: " << config.width << " mm x " << config.height << " mm\n";

    return config;
}

