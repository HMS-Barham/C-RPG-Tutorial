#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::tick(float deltaTime)
{
    // Create a variable between enemy and character called "toTarget". knight->screenPos -screenPos
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
    // Normalize "toTarget" using the raylib function
    toTarget = Vector2Normalize(toTarget);
    // Multiply "toTarget" with BaseCharacter speed. Can do the normalization within this function
    toTarget =  Vector2Scale(toTarget, speed);
    // Change worldPos by the amount of toTarget.
    worldPos = Vector2Add(worldPos, toTarget);

    screenPos = Vector2Subtract(worldPos, target->getWorldPos());

    BaseCharacter::tick(deltaTime);
}
