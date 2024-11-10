#include <iostream>
#include <vector>
#include <memory>

#include <IScreen.h>
#include "screens/TVScreen.h"
#include "screens/LEDWallScreen.h"

int main()
{
    std::vector<std::unique_ptr<IScreen>> screens;
    screens.emplace_back(std::make_unique<TVScreen>(500, 500));
    screens.emplace_back(std::make_unique<LEDWallScreen>(
                500, 500, 16, 9, LEDWallType::Aspect));

    for(const auto& screen : screens)
    {
        screen->DisplayInfo();
    }
    return 0;
}

