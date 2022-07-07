#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Labyrinth
{
private:
	String LabyrinthFile;
	Image LabyrinthImage;//создали обьект имейдж
	Texture LabyrinthTexture;
public:
	Sprite LabyrinthSprite;
	Labyrinth(String F)//конструктор который загружает каритнку и делает из нее спрайт
	{
		LabyrinthFile = F;
		LabyrinthImage.loadFromFile("C:/game/" + LabyrinthFile);
		LabyrinthTexture.loadFromImage(LabyrinthImage);
		LabyrinthSprite.setTexture(LabyrinthTexture);
	}
};