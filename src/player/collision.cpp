#include "../../include/gameResources.h" 

void Player::collision_logic(const Rectangle& rect1) {
    Rectangle overlap = GetCollisionRec(rect1, rect);
    bool collision = CheckCollisionRecs(rect1, rect);


    if(collision) {
        if(overlap.width < overlap.height) {
            if(rect.x < rect1.x) {
                rect.x -= overlap.width;
            }
            else {
                rect.x += overlap.width;
            }
        }
        else {
            if (rect.y < rect1.y) {
                rect.y -= overlap.height; //Top
                jumped = false;
                velocity.y = 0.0f;
                //Have to add some downward gravity so that you cant double jumpe from the sides and bottom
                
            }
            else {
                rect.y += overlap.height; //Bottom
                jumped = true;
                velocity.y = 1.0f;
                //Have to add some downward gravity so that you cant double jump form the sides and bottom
            }
        }
    }
}


