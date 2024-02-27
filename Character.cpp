#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)
{

    width = texture.width / maxFrames;
    height = texture.height;
    
}

Vector2 Character::getScreenPos()
{
    return Vector2 {
        screenPos = {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)}
    };
}

void Character::tick(float deltaTime)
{
    // Movement input
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    BaseCharacter::tick(deltaTime);
}
