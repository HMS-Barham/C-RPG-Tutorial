#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
    width = texture.width / maxFrames;
    height = texture.height;
}



void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle {screenPos.x, screenPos.y, scale * width, scale * height};
}

void BaseCharacter::tick(float deltaTime)
{
    // Store last frame's worldPos so that I can use it to prevent movement if out of bounds
    worldPosLastFrame = worldPos;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
        {
            frame = 0;
        }
    }

    // draw enemy
    Rectangle source{frame * width, 0.0f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}