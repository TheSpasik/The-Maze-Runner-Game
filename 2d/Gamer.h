#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "map.h"
#include <ctime>
using namespace sf;
using namespace std;
class Gamer : public Entity
{
private:
	int dir, playerScore;
	bool win = false;
public:
	float CurrentFrame = 0;
	Gamer(String F, int X, int Y, float W, float H) : Entity(F, X, Y, W, H)
	{
		dir = 0; playerScore = 0;
		dx = 0; dy = 0;
		win = false;
		sprite.setTextureRect(IntRect(12, 2, 44, 64));
	}
	void setDir(int _dir) { dir = _dir; }
	int getScore() { return playerScore; }
	bool getWin() { return win; }
	void update(float time)//функция обновления, зависящая от времени
	{
		switch (dir)//смена скорости,в зависимости от направления
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}
		x += dx * time;
		y += dy * time;

		speed = 0;
		interactionWithMap();
		sprite.setPosition(x, y);//перемещение спрайта на экране
	}

	float getPlayerCoordinateX() { return x; }
	float getPlayerCoordinateY() { return y; }
	void SetPlayerCoordX(int _X) { x = _X; };
	void SetPlayerCoordY(int _Y) { y = _Y; };

	void interactionWithMap()//взаимодействие с картой
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if (dy > 0)
					{
						y = i * 32 - h;
					}
					if (dy < 0)
					{
						y = i * 32 + 32;
					}
					if (dx > 0)
					{
						x = j * 32 - w;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}
				}//проверка в каком направлении двигался, чтобы не дать пройти дальше
				if (TileMap[i][j] == 'd' && playerScore < 1)
				{
					if (dy > 0) { y = i * 32 - h; }
					if (dy < 0) { y = i * 32 + 32; }
					if (dx > 0) { x = j * 32 - w; }
					if (dx < 0) { x = j * 32 + 32; }
				}
				if (TileMap[i][j] == 'e') {
					playerScore++;
					TileMap[i][j] = 'g';
				}
				if (TileMap[i][j] == 'p' && playerScore < 2)
				{
					if (dy > 0) { y = i * 32 - h; }
					if (dy < 0) { y = i * 32 + 32; }
					if (dx > 0) { x = j * 32 - w; }
					if (dx < 0) { x = j * 32 + 32; }
				}
				if (TileMap[i][j] == 'l' && playerScore < 3)
				{
					if (dy > 0) { y = i * 32 - h; }
					if (dy < 0) { y = i * 32 + 32; }
					if (dx > 0) { x = j * 32 - w; }
					if (dx < 0) { x = j * 32 + 32; }
				}
				if (TileMap[i][j] == 'k') {
					playerScore++;
					TileMap[i][j] = ' ';
				}
				if (TileMap[i][j] == 'r')
				{
					win = true;
				}

			}
	}
	void MovingG(float& time) {
		if ((Keyboard::isKeyPressed(Keyboard::A))) {
			setDir(1); setSpeed(0.1);
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			sprite.setTextureRect(IntRect(12 + (64 * int(CurrentFrame)), 65, 44, 64));

		}

		if ((Keyboard::isKeyPressed(Keyboard::D))) {
			setDir(0); setSpeed(0.1);
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			sprite.setTextureRect(IntRect(12 + (64 * int(CurrentFrame)), 130, 44, 64));

		}

		if ((Keyboard::isKeyPressed(Keyboard::W))) {
			setDir(3); setSpeed(0.1);
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			sprite.setTextureRect(IntRect(12 + (64 * int(CurrentFrame)), 193, 44, 64));

		}

		if ((Keyboard::isKeyPressed(Keyboard::S))) {
			setDir(2); setSpeed(0.1);
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
			sprite.setTextureRect(IntRect(12 + (64 * int(CurrentFrame)), 2, 44, 64));

		}
	}
};