#pragma once

#include <iostream>

// Easily extend with more configuration parameters
struct ScreenConfig
{
    int width;
    int height;
};

// Interface for LED Wall configuration strategies
class ScreenConfigurationStrategy
{
public:
    virtual ScreenConfig Configure(int panelWidth, int panelHeight, int targetWidth, int targetHeight) const = 0;
    virtual ~ScreenConfigurationStrategy() = default;
};

// Freeform configuration strategy
class FreeformConfiguration : public ScreenConfigurationStrategy
{
public:
    ScreenConfig Configure(int panelWidth, int panelHeight, int targetWidth, int targetHeight) const override
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
};

// Aspect ratio configuration strategy
class AspectConfiguration : public ScreenConfigurationStrategy
{
public:
    ScreenConfig Configure(int aspectWidth, int aspectHeight, int panelWidth, int panelHeight) const override
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
};
