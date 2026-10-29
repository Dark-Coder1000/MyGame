#include "../../include/gameResources.h"


void Player::updatePlayer() {
    float dt = GetFrameTime();
    if (velocity.y == 0.0f) {
        is_grounded = true;
    }

    Playermovement(dt);

    velocity.y += gravity * dt;
    rect.y += velocity.y * dt;


    if(rect.x + rect.width >= ScreenWidth) {
        rect.x = ScreenWidth - rect.width;
    }
    if(rect.x <= 0) {
        rect.x = 0;
    }

    if(rect.y + rect.height >= ScreenHeight) {
        rect.y = ScreenHeight - rect.height;
        velocity.y = 0.0f;
        jumped = false;
    }    
}

void Player::Playermovement(float dt) {

    if(IsKeyDown(KEY_D)) {
        rect.x += dt * velocity.x;
    }

    if(IsKeyDown(KEY_A)) {
        rect.x -= dt * velocity.x;
    }

    if(is_grounded) {
        if (!jumped) {
            if(IsKeyPressed(KEY_SPACE)) {
                velocity.y = -400;
                jumped = true;
                is_grounded = false;
            }
        }
        if (velocity.y == 0.0f) {
            is_grounded = true;
        }
    }
    else {
        is_grounded = false;
    }

}

void Player::DrawPlayer() {
    float scale = 2.0f;
    destRec = { rect.x, rect.y, 32.0f * scale, 32.0f * scale }; //Image location

    DrawTexturePro(playerText, sourceRec, destRec, orgin, 0.0f, WHITE);
}

void Player::initPlayer(){
    float player_x = ScreenWidth/2;
    float player_y = ScreenHeight/2;
    float player_width = 64;
    float player_height = 64;

    Vector2 velocitys = { 300.0f, 0.0f };
    float gravity_ = 400.0f;

    rect = Rectangle {player_x, player_y, player_width, player_height};
    gravity = gravity_;
    velocity = velocitys;

    playerText = LoadTexture("assets/entities/player.png");

    sourceRec = { 0.0f, 0.0f, 32.0f, 32.0f}; //Image starts at top left and is 32x32 (the png)

    orgin = { 0.0f, 0.0f }; //Rotaion and scalling
    //Must leave destRec out of here or it wont update to player position

};

