#include "raylib.h"

class Prop
{
public:
Prop(Vector2 pos, Texture2D tex);
void Render(Vector2 knightPos);
Rectangle getCollisionRec(Vector2 knightPos);

private:
Vector2 worldPos{};
Vector2 screenPos{};
Texture2D texture{};
float scale {4.0f};
};