#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Labyrinth
{
private:
	String LabyrinthFile;
	Image LabyrinthImage;//������� ������ ������
	Texture LabyrinthTexture;
public:
	Sprite LabyrinthSprite;
	Labyrinth(String F)//����������� ������� ��������� �������� � ������ �� ��� ������
	{
		LabyrinthFile = F;
		LabyrinthImage.loadFromFile("C:/game/" + LabyrinthFile);
		LabyrinthTexture.loadFromImage(LabyrinthImage);
		LabyrinthSprite.setTexture(LabyrinthTexture);
	}
};