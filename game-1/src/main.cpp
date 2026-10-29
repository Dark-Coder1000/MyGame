#include "../include/gameResources.h"

float ScreenHeight = 600;
float ScreenWidth = 1000;

bool jumped = true;
bool is_grounded = false;


int main() {
    //Objects
    Player player;

    player.camera = { 0 };
    player.camera.zoom = 1.0f;
    

    RenderLevel level1;
    //File Initiaton
    const char* level1_file = "input.json";
    level1.file = level1_file;
    level1.TILE_SIZE = 32.0f;

    InitWindow(ScreenWidth, ScreenHeight, "Game-1");
    SetTargetFPS(60);

    player.camera.offset = (Vector2){ GetRenderWidth()/2.0f, GetRenderHeight()/2.0f  };

    player.initPlayer();

    level1.renderLevel();


    while (!WindowShouldClose()) {
        player.updatePlayer();
        player.camera.target = (Vector2){ player.rect.x + 20.0f, ScreenHeight/2};

        std::string FPS = std::to_string(GetFPS());


        Color transparent = { 0, 0, 0, 0};

        BeginDrawing();
            ClearBackground(WHITE);

            BeginMode2D(player.camera);

            hitBox(player.rect, transparent, 10.0f, 20.0f);

            DrawText(FPS.c_str(), 0, 0, 30, YELLOW);

            level1.drawLevel(player);

            player.DrawPlayer();
            EndMode2D();

        EndDrawing();
       
    }
    CloseWindow();

    return 0;
}


