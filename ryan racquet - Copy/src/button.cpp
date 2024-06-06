#include <raylib.h>
#include "button.hpp"

Button::Button(Rectangle bounds, Color color, Color textColor, const char* text) 
{
    this -> bounds = bounds;
    this -> color = color;
    this -> textColor = textColor;
    this -> text = text;
    this -> pressed = false;
}

bool Button::isPressed()  
{
    Vector2 mousePos = GetMousePosition();
    if (CheckCollisionPointRec(mousePos, bounds)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            pressed = true;
            return true;
        }
    }
    pressed = false;
    return false;
}

void Button::drawButton() 
{
    Vector2 mousePos = GetMousePosition();

    if (CheckCollisionPointRec(mousePos, bounds)) {
        DrawRectangleRec(bounds, MAROON); 
        DrawText(text, bounds.x + bounds.width / 2 - MeasureText(text, 20) / 2, bounds.y + bounds.height / 2 - 10, 20, textColor);
    } else {
        DrawRectangleRec(bounds, color);
        DrawText(text, bounds.x + bounds.width / 2 - MeasureText(text, 20) / 2, bounds.y + bounds.height / 2 - 10, 20, textColor);     
    }

}