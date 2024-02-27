#include "BaseCharacter.h"
#include "raymath.h"

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
    return Rectangle {getScreenPos().x, getScreenPos().y, scale * width, scale * height};
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

    if (Vector2Length(velocity) != 0.0)
    {
        // Adds vectors so that the map moves in the right direction
        // Also scales the vector by moveSpeed so that I have some control of the movement speed
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        // ternary statement. Equivalent to an if/else statement
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    velocity = {};

    // draw enemy
    Rectangle source{frame * width, 0.0f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}