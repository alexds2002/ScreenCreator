#include <vector>
#include <memory>

#include <IScreen.h>
#include "screens/tv_screen/TVScreen.h"
#include "screens/led_wall/LEDWallScreen.h"
#include "screens/led_wall/ConfigurationStrategy.h"

/*
 * The main structure of the classes is as follows:
 * IScreen -> interface class for different types of screens
 * TVScreen, LEDWallScreen -> 2 types of screens
 * ScreenConfigurationStrategy(Aspect, Freeform) -> A configuration for the LEDWallScreen,
 * creating a new type of configuration for the LEDWallScreen is more modular this way.
 * Ofcourse for this example with only two types of LEDWallScreen it is unessential, but
 * if we had more and expected more in the future it would be a good idea.
 */

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

