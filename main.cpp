#include "raylib.h"
#include "raymath.h"

class characters
{
public:
    Vector2 getWorldPos()
    {
        return worldPos;
    }

private:
    Texture2D texture;
    Texture2D idle;
    Texture2D run;
    Vector2 screenPos;
    Vector2 worldPos;
    // 1 = facing right, -1 = facing left
    float rightLeft{1.f};
    //animation variables
    float runningTime {};
    int frame {};
    const int maxFrames {6};
    const float updateTime {1.f/12.f};
};

int main()
{
    //Window Dimensions
    const int windowX {384};
    const int windowY {384};
    
    InitWindow(windowX, windowY, "RPG");
    SetTargetFPS(60);

    const float moveSpeed{4.0};

    Texture2D map = LoadTexture("nature_tileset/worldMap.png");
    Vector2 mapPos {0.0, 0.0};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightRun = LoadTexture("characters/knight_run_spritesheet.png");
    Vector2 knightPos {(float)windowX/2.0f - 4.0f * (0.5f * (float)knight.width/6), (float)windowY/2.0f - 4.0f * (0.5f * (float)knight.height)};
    // 1 = facing right, -1 = facing left
    float rightLeft{1.f};
    //animation variables
    float runningTime {};
    int frame {};
    const int maxFrames {6};
    const float updateTime {1.f/12.f};

    while (WindowShouldClose() == false)
    {
        const float dT{GetFrameTime()};

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
            //Also scales the vector by moveSpeed so that I have some control of the movement speed
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), moveSpeed));
            //ternary statement. Equivalent to an if/else statement
            direction.x < 0.f ? rightLeft = - 1.f : rightLeft = 1.f;
            knight = knightRun;
        }
        else knight = knightIdle;

        //draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        //update animation frame
        runningTime += dT;
        if(runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if(frame > maxFrames)
            {
                frame = 0;
            }
        }

        //draw knight
        Rectangle source {frame * (float)knight.width/6.0f, 0.0f, rightLeft * (float)knight.width/6.0f, (float)knight.height};
        Rectangle dest {knightPos.x, knightPos.y, 4.0f * ((float)knight.width/6.0f), 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.0f, WHITE);

        EndDrawing();
    }


    UnloadTexture(map);
    UnloadTexture(knight);
    CloseWindow();

}