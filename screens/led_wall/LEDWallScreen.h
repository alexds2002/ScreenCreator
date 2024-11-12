#pragma once

#include <IScreen.h>
#include <memory>

class ScreenConfigurationStrategy;

// LEDWallScreen class that uses configuration strategies
class LEDWallScreen : public IScreen
{
private:
    int panelWidth;
    int panelHeight;
    int targetWidth;
    int targetHeight;

    // calculated based on ScreenConfiguration
    int actualWidth;
    int actualHeight;
    std::unique_ptr<ScreenConfigurationStrategy> configurationStrategy;

public:
    LEDWallScreen(int pW, int pH, int tW, int tH, std::unique_ptr<ScreenConfigurationStrategy>&& strategy);

    void DisplayInfo() const override;
};
