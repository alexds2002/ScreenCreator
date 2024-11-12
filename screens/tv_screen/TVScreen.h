#pragma once

#include <IScreen.h>

class TVScreen : public IScreen
{
public:
    TVScreen(int w, int h);
    ~TVScreen() = default;

    void DisplayInfo() const override;

private:
    int m_width;
    int m_height;
};

