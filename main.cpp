#include "raylib.h"

int main()
{
    //Window Dimensions
    const int windowX {384};
    const int windowY {384};
    
    InitWindow(windowX, windowY, "RPG");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("nature_tileset/worldMap.png");

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapCoordinates {0.0, 0.0};
        DrawTextureEx(map, mapCoordinates, 0.0, 4.0, WHITE);

        EndDrawing();
    }


    UnloadTexture(map);
    CloseWindow();

}