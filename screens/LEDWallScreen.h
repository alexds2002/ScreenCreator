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
    int m_panelWidth;
    int m_panelHeight;
    LEDWallType m_mode;
    int m_targetWidth;
    int m_targetHeight;
    int m_aspectWidth;
    int m_aspectHeight;

public:
    LEDWallScreen(int pW, int pH, int aW, int aH, LEDWallType wallType);

    void DisplayInfo() const override;
};

