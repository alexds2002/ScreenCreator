#pragma once

/**
 * @class IScreen
 * @brief Abstract base class representing a generic screen interface.
 *
 * The IScreen interface defines the basic contract for different types of screens,
 * requiring derived classes to implement a `DisplayInfo` method that displays information
 * about the specific screen. This allows consistent handling of different screen types
 * through a common interface.
 */
class IScreen
{
public:
    /**
     * @brief Display information about the screen.
     *
     * This pure virtual function must be implemented by all derived classes.
     * It should output relevant information specific to the type of screen,
     * such as dimensions or configuration details.
     */
    virtual void DisplayInfo() const = 0;

    /**
     * @brief Virtual destructor for IScreen.
     *
     * Ensures that derived classes' destructors are called correctly when
     * an IScreen pointer is deleted.
     */
    virtual ~IScreen() = default;
};
