#pragma once

#include <IScreen.h>
#include <memory>

class ScreenConfigurationStrategy;

/**
 * @class LEDWallScreen
 * @brief Represents an LED video wall composed of configurable panels.
 *
 * The LEDWallScreen class models a flexible LED wall that can be configured
 * with different strategies for determining the layout and dimensions.
 * This class uses the strategy design pattern to support multiple configuration
 * methods through a `ScreenConfigurationStrategy` object.
 */
class LEDWallScreen : public IScreen
{
private:
    int panelWidth;   ///< Width of each individual panel in millimeters.
    int panelHeight;  ///< Height of each individual panel in millimeters.
    int targetWidth;  ///< Desired width for the LED wall in millimeters.
    int targetHeight; ///< Desired height for the LED wall in millimeters.

    int actualWidth;  ///< Final width of the LED wall based on configuration.
    int actualHeight; ///< Final height of the LED wall based on configuration.

    std::unique_ptr<ScreenConfigurationStrategy> configurationStrategy; ///< Strategy used to calculate the layout of the LED wall.

public:
    /**
     * @brief Constructs an LEDWallScreen with specified panel dimensions, target dimensions, and a configuration strategy.
     *
     * @param pW Width of each panel in millimeters.
     * @param pH Height of each panel in millimeters.
     * @param tW Desired target width for the LED wall in millimeters.
     * @param tH Desired target height for the LED wall in millimeters.
     * @param strategy Unique pointer to a configuration strategy for determining the layout of the wall.
     *
     * This constructor initializes the LED wall with the given panel size, target dimensions,
     * and configuration strategy. The strategy is used to determine the final layout and
     * dimensions of the wall.
     */
    LEDWallScreen(int pW, int pH, int tW, int tH, std::unique_ptr<ScreenConfigurationStrategy>&& strategy);

    /**
     * @brief Display information about the LED wall.
     *
     * Implements the `displayInfo` method from the `IScreen` interface.
     * Outputs relevant details about the LED wall, including panel dimensions, target dimensions,
     * and the calculated final dimensions based on the chosen configuration strategy.
     */
    void DisplayInfo() const override;
};
