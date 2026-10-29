#pragma once
#include <raylib.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <nlohmann/json_fwd.hpp>


extern float ScreenHeight;
extern float ScreenWidth;

class Player {
    private:
        Vector2 velocity;
        float gravity;
        bool jumped;
        bool is_grounded;

        Texture2D playerText;

        Rectangle sourceRec;
        Rectangle destRec;
        Vector2 orgin;

    public:
        Rectangle rect;
        Camera2D camera;


    //Player functions
    void updatePlayer();
    void Playermovement(float dt);
    void DrawPlayer();
    void initPlayer();
    void collision_logic(const Rectangle& rect1);
};


//classes
class RenderLevel{
    private:
        int levelWidth = 0;
        int levelHeight = 0;
        std::vector<int> levelData;

        Texture2D brick;

    public:
        const char* file;
        float TILE_SIZE;

        void renderLevel();
        void drawLevel(Player& player);
};


//Functions
//void collision_logic(const Rectangle& rect1, Player& player);

void hitBox(Rectangle rect, Color color, float offset, float hitBoxGrowth);
void DrawHitbox(Rectangle rect, Color color);
