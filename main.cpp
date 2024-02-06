#include "raylib.h"

int main()
{
    //These numbers are wrong. Update later.
    int windowX = 500;
    int windowY = 400;

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