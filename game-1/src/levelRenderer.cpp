#include "../include/gameResources.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void RenderLevel::renderLevel() {
    std::ifstream level(file);

            //Error checking 
    if(!level.is_open()) {
        std::cerr << "Error, could not open levelFile" << std::endl;
        return;
    }

    json level_json;
    level >> level_json;
    level.close();

    //Extract the level information from the json file
    levelWidth = level_json["width"].get<int>();
    levelHeight = level_json["height"].get<int>();

    levelData = level_json["data"].get<std::vector<int>>();

    //Initiates tiles textures
    brick = LoadTexture("assets/tiles/brick.png");
    


    //levelData = firstLayer["data"].get<std::vector<int>>();
}

void RenderLevel::drawLevel(Player& player) {
    if (levelData.empty()) return;

    

    for (int y = 0; y < levelHeight; y++) {
        for (int x = 0; x < levelWidth; x++) {
            //Math to find tile ID
            int index = (y * levelWidth) + x;
            int tileID = levelData[index];

            float screenX = (float)(x * TILE_SIZE);
            float screenY = (float)(y * TILE_SIZE);

            Rectangle tileRect = { screenX, screenY, TILE_SIZE, TILE_SIZE };

            if (tileID == 1) { //Ground tile
                Color tileColor = BROWN;
                DrawRectangleRec(tileRect, tileColor);
                player.collision_logic(tileRect); //Adds collision to tiles
            }
            else if (tileID == 2) { //Brick tile
                DrawTextureRec(brick, tileRect, Vector2{tileRect.x, tileRect.y}, WHITE);
                player.collision_logic(tileRect); //Adds collision to tiles
            }
            else if (tileID == 5) { //World Border
                Color tileColor = DARKGRAY;
                DrawRectangleRec(tileRect, tileColor);
                //collision_logic(tileRect, player.rect, velocity); //Adds collision to tiles
            }
        }

    }
}