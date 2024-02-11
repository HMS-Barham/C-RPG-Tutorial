#include "raylib.h"
#include "raymath.h"

int main()
{
    //Window Dimensions
    const int windowX {384};
    const int windowY {384};

    const float moveSpeed{2.0};
    
    InitWindow(windowX, windowY, "RPG");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("nature_tileset/worldMap.png");
    Vector2 mapCoordinates {0.0, 0.0};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Movement input
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;

        if(Vector2Length(direction) != 0.0)
        {
            //Subtracts vectors so that the map moves in the right direction
            mapCoordinates = Vector2Subtract(mapCoordinates, Vector2Scale(Vector2Normalize(direction), moveSpeed));
        }

        DrawTextureEx(map, mapCoordinates, 0.0, 4.0, WHITE);

        EndDrawing();
    }


    UnloadTexture(map);
    CloseWindow();

}