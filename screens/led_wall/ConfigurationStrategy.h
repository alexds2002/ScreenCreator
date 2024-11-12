#pragma once

/**
 * @struct ScreenConfig
 * @brief Stores the width and height of a screen or LED wall configuration.
 *
 * This structure holds the calculated dimensions (width and height) of a screen
 * or LED wall, either based on freeform layout or aspect ratio configuration.
 */
struct ScreenConfig
{
    int width;  ///< The width of the screen or LED wall in millimeters.
    int height; ///< The height of the screen or LED wall in millimeters.
};

/**
 * @class ScreenConfigurationStrategy
 * @brief Abstract base class for different LED wall configuration strategies.
 *
 * This interface defines a common contract for various strategies that calculate
 * the layout of an LED wall based on panel dimensions and target dimensions.
 */
class ScreenConfigurationStrategy
{
public:
    /**
     * @brief Configures the LED wall layout.
     *
     * This pure virtual function calculates the screen dimensions based on
     * the panel and target dimensions. Must be implemented by derived classes.
     *
     * @param panelWidth Width of each panel in millimeters.
     * @param panelHeight Height of each panel in millimeters.
     * @param targetWidth Desired width of the LED wall in millimeters.
     * @param targetHeight Desired height of the LED wall in millimeters.
     *
     * @return ScreenConfig Calculated dimensions of the wall.
     */
    virtual ScreenConfig Configure(int panelWidth, int panelHeight, int targetWidth, int targetHeight) const = 0;

    virtual ~ScreenConfigurationStrategy() = default;
};

/**
 * @class FreeformConfiguration
 * @brief Configures the LED wall based on a freeform layout.
 *
 * This strategy calculates the largest possible LED wall layout based on the
 * panel size that fits within the given target dimensions. The layout is determined
 * by the number of columns and rows that can fit within the target dimensions.
 */
class FreeformConfiguration : public ScreenConfigurationStrategy
{
public:
    /**
     * @brief Configures the LED wall using a freeform layout.
     *
     * The layout is determined by the number of full panels (columns and rows)
     * that can fit into the target dimensions. The resulting wall size is calculated.
     *
     * @param panelWidth Width of each panel in millimeters.
     * @param panelHeight Height of each panel in millimeters.
     * @param targetWidth Desired width of the LED wall in millimeters.
     * @param targetHeight Desired height of the LED wall in millimeters.
     *
     * @return ScreenConfig The calculated width and height of the wall.
     */
    ScreenConfig Configure(int panelWidth, int panelHeight, int targetWidth, int targetHeight) const override;
};

/**
 * @class AspectConfiguration
 * @brief Configures the LED wall based on an aspect ratio.
 *
 * This strategy configures the LED wall according to a fixed aspect ratio (e.g., 16:9).
 * It calculates the smallest possible LED wall that fits the given aspect ratio
 * and panel size.
 */
class AspectConfiguration : public ScreenConfigurationStrategy
{
public:
    /**
     * @brief Configures the LED wall based on a specified aspect ratio.
     *
     * This layout is based on the provided aspect ratio (e.g., 16:9), with the number
     * of columns and rows calculated from the aspect ratio and panel size.
     *
     * @param aspectWidth The width part of the aspect ratio.
     * @param aspectHeight The height part of the aspect ratio.
     * @param panelWidth Width of each panel in millimeters.
     * @param panelHeight Height of each panel in millimeters.
     *
     * @return ScreenConfig The calculated width and height of the wall.
     */
    ScreenConfig Configure(int aspectWidth, int aspectHeight, int panelWidth, int panelHeight) const override;
};
