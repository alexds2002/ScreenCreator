#pragma once

#include <IScreen.h>

enum class LEDWallType : int
{
    Freeform = 1,
    Aspect = 2,
    Default = Freeform
};

class LEDWallScreen : public IScreen
{
private:
    int panelWidth;
    int panelHeight;
    LEDWallType mode;
    int targetWidth;
    int targetHeight;
    int aspectWidth;
    int aspectHeight;

public:
    LEDWallScreen(int pW, int pH, int aW, int aH, LEDWallType wallType);

    void DisplayInfo() const override;
};

