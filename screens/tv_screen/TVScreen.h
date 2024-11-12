#pragma once

#include <IScreen.h>

/**
 * @class TVScreen
 * @brief Represents a television screen with specified dimensions.
 *
 * The TVScreen class inherits from the IScreen interface and provides a concrete implementation
 * for a simple rectangular screen, such as a television. This class stores and displays
 * the screen's width and height, as specified during construction.
 */
class TVScreen : public IScreen
{
public:
    /**
     * @brief Constructs a TVScreen with a given width and height.
     *
     * @param w Width of the TV screen in millimeters.
     * @param h Height of the TV screen in millimeters.
     *
     * Initializes the TVScreen with specified width and height dimensions.
     */
    TVScreen(int w, int h);

    /**
     * @brief Default destructor for TVScreen.
     *
     * This destructor allows for clean deletion of TVScreen objects.
     * Defaulted as no custom cleanup is required.
     */
    ~TVScreen() = default;

    /**
     * @brief Display information about the TV screen.
     *
     * Implements the displayInfo method from the IScreen interface.
     * Outputs the width and height of the TV screen, providing relevant details
     * to the user or calling function.
     */
    void DisplayInfo() const override;

private:
    int m_width;  ///< Width of the TV screen in millimeters.
    int m_height; ///< Height of the TV screen in millimeters.
};
