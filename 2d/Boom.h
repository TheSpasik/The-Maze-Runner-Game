#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "map.h"
using namespace sf;
using namespace std;
class Boom : public Entity
{
private:
	float CurrentFrameBoom = 0;
public:
	Boom(String F, int X, int Y, float W, float H) :Entity(F, X, Y, W, H)
	{
		sprite.setTextureRect(IntRect(0, 0, 32.0, 32.0));
		speed = 0.04;
	}
	void update(float time)
	{
		dy = speed;
		y += dy * time;//координата меняется от времени
		sprite.setTextureRect(IntRect(97.0, 270.0, 24.0, 24.0));
		Moving();
		sprite.setPosition(x, y);
	}
	void Moving()//взаимодесйвтие с картой
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
		{
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'o')
				{
					if (dy > 0) { y = i * 32 - h; speed = -0.04; sprite.setTextureRect(IntRect(97.0, 270.0, 24.0, 24.0)); }
					if (dy < 0) { y = i * 32 + 32; speed = 0.04; sprite.setTextureRect(IntRect(97.0, 270.0, 24.0, 24.0)); }
				}
			}
		}
	}
};