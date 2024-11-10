#pragma once

class IScreen
{
public:
    virtual void DisplayInfo() const = 0;
    virtual ~IScreen() = default;
};

