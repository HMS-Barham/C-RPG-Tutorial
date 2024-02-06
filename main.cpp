#include "raylib.h"

int main()
{
    //These numbers are wrong. Update later.
    int windowX = 800;
    int windowY = 600;

    InitWindow(windowX, windowY, "RPG");

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();

}