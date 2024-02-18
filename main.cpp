#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    // Window Dimensions
    const int windowX{384};
    const int windowY{384};

    InitWindow(windowX, windowY, "RPG");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("nature_tileset/worldMap.png");
    Vector2 mapPos{0.0, 0.0};
    Character knight;
    knight.setScreenPos(windowX, windowY);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        //draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        //draw player character
        knight.tick(GetFrameTime());

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}