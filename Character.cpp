#include "Character.h"
#include "raymath.h"

Character::Character(int windowWidth, int windowHeight)
{

    width = texture.width / maxFrames;
    height = texture.height;
    screenPos = {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    // Store last frame's worldPos so that I can use it to prevent movement if out of bounds
    worldPosLastFrame = worldPos;

    // Movement input
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;

    if (Vector2Length(direction) != 0.0)
    {
        // Adds vectors so that the map moves in the right direction
        // Also scales the vector by moveSpeed so that I have some control of the movement speed
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        // ternary statement. Equivalent to an if/else statement
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

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

    // draw knight
    Rectangle source{frame * width, 0.0f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Character::getCollisionRec()
{
    return Rectangle {screenPos.x, screenPos.y, scale * width, scale * height};
}