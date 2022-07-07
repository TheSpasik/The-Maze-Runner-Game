#pragma once
using namespace sf;

sf::View view;

View getplayercoordinateforview(float x, float y) {
	float tempX = x; float tempY = y;

	if (x < 320) tempX = 320;
	if (y < 240) tempY = 240;
	if (y > 554) tempY = 554;
	if (x > 932) tempX = 932;
	view.setCenter(tempX, tempY); // закрепили камеру на заданых координатах
	return view;
}