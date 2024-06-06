#pragma once
#include <raylib.h>

class Button {
public:
    Button(Rectangle bounds, Color color, Color textColor, const char* text);
    bool isPressed();
    void drawButton();

private:
    Rectangle bounds;
    Color color;
    Color textColor;
    const char* text;
    mutable bool pressed;

};
