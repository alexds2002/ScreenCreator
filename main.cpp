#include <vector>
#include <memory>

#include <IScreen.h>
#include "screens/tv_screen/TVScreen.h"
#include "screens/led_wall/LEDWallScreen.h"
#include "screens/led_wall/ConfigurationStrategy.h"

int main()
{
    std::vector<std::unique_ptr<IScreen>> screens;
    screens.emplace_back(std::make_unique<TVScreen>(500, 500));
    screens.emplace_back(std::make_unique<LEDWallScreen>(500, 500, 16, 9, std::make_unique<AspectConfiguration>()));
    screens.emplace_back(std::make_unique<LEDWallScreen>(500, 500, 2000, 1750, std::make_unique<FreeformConfiguration>()));

    for(const auto& screen : screens)
    {
        screen->DisplayInfo();
    }
    return 0;
}

