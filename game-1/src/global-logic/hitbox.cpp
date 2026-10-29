#include "../../include/gameResources.h"

void hitBox(Rectangle rect, Color color, float offset, float hitBoxGrowth) {
	rect.x -= offset;
	rect.y -= offset;

	rect.height += hitBoxGrowth;
	rect.width += hitBoxGrowth;

	DrawHitbox(rect, color);
}

void DrawHitbox(Rectangle rect, Color color) {
	DrawRectangleRec(rect, color);
}
