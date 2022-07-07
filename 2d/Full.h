#pragma once
#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "menu.h"
#include "mission.h"
#include <vector>
#include <list>
#include <time.h>
#include "Gamer.h"
#include "Boom.h"
#include "Labyrinth.h"
using namespace std;
class Full {

public:
	void full(RenderWindow& window) {
		view.reset(sf::FloatRect(0, 0, 640, 480));//��������� ������
		Labyrinth quest("svitok.png");
		Labyrinth endgame("endgame.jpg");
		Labyrinth background("background.png");
		quest.LabyrinthSprite.setTextureRect(IntRect(0, 0, 340, 510));
		quest.LabyrinthSprite.setScale(0.6f, 0.6f);//������ ������
		Font font;//�����
		font.loadFromFile("C:/game/2d/shrift.ttf");
		Text text("", font, 10);//������ ������ � �������������
		text.setFillColor(Color::Black);
		text.setStyle(Text::Bold);//������ �����

		Gamer p("mainhero.png", 50, 50, 64.0, 64.0);//������� �����

		std::list<Entity*> entities;//������� ������ �������
		std::list<Entity*>::iterator it;//�������� ��� ������

		for (int i = 0; i < 3; i++)
		{
			entities.push_back(new Boom("boom.png", 992 + (-130 * i), rand() % 65 + 96, 24.0, 24.0));
		}//��������� ����������
		bool showMissionText = true;//��������� ������

		Clock clock;//���������� �������

		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();//����� � �������������
			clock.restart();//��������� ����
			time = time / 400;//� ������������ �� ����� �������� �������� �����
			Event event;//������ ����
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == Event::KeyPressed)//������� ������� �������
					if (event.key.code == Keyboard::Q) {//���� ������� Q


						switch (showMissionText) {//�������������, ����������� �� ���������� ���������� showMissionText

						case true: {//����� ������ � ����������� ������
							std::ostringstream task;
							task << getTextMission(getCurrentMission(p.getScore()));
							text.setString("\n" + task.str());
							text.setPosition(view.getCenter().x, view.getCenter().y);
							quest.LabyrinthSprite.setPosition(view.getCenter().x, view.getCenter().y);
							showMissionText = false;
							break;
						}
						case false: {//�������� ������
							text.setString("");
							showMissionText = true;
							break;
						}

						}
					}
			}
			p.MovingG(time);
			getplayercoordinateforview(p.getPlayerCoordinateX(), p.getPlayerCoordinateY());
			p.update(time);//������� ��� �������������� � ������
			for (it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->update(time);
			}

			window.setView(view);//������
			window.clear();
			for (it = entities.begin(); it != entities.end(); it++)
			{
				if ((*it)->GetRect().intersects(p.GetRect()))
				{
					p.SetPlayerCoordX(50);//���������� ����� � ������
					p.SetPlayerCoordY(50);
				}
			}

			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ') background.LabyrinthSprite.setTextureRect(IntRect(0, 0, 32, 32));//���
					if (TileMap[i][j] == 'k') background.LabyrinthSprite.setTextureRect(IntRect(32, 0, 32, 32));//����
					if (TileMap[i][j] == '0') background.LabyrinthSprite.setTextureRect(IntRect(64, 0, 32, 32));//�����
					if (TileMap[i][j] == 'f') background.LabyrinthSprite.setTextureRect(IntRect(96, 0, 32, 32));//�����
					if (TileMap[i][j] == 'b') background.LabyrinthSprite.setTextureRect(IntRect(128, 0, 32, 32));//�����
					if (TileMap[i][j] == 'd') background.LabyrinthSprite.setTextureRect(IntRect(160, 0, 32, 32));//�����
					if (TileMap[i][j] == 'r') background.LabyrinthSprite.setTextureRect(IntRect(192, 0, 32, 32));//����������
					if (TileMap[i][j] == 'c') background.LabyrinthSprite.setTextureRect(IntRect(224, 0, 32, 32));//������
					if (TileMap[i][j] == 'e') background.LabyrinthSprite.setTextureRect(IntRect(256, 0, 32, 32));//�������
					if (TileMap[i][j] == 'g') background.LabyrinthSprite.setTextureRect(IntRect(288, 0, 32, 32));//�����
					if (TileMap[i][j] == 'h') background.LabyrinthSprite.setTextureRect(IntRect(320, 0, 32, 32));//������
					if (TileMap[i][j] == 'o') background.LabyrinthSprite.setTextureRect(IntRect(352, 0, 32, 32));//�����
					if (TileMap[i][j] == 'p') background.LabyrinthSprite.setTextureRect(IntRect(384, 0, 32, 32));//�����
					if (TileMap[i][j] == 'l') background.LabyrinthSprite.setTextureRect(IntRect(416, 0, 32, 32));//�����
					if (TileMap[i][j] == 'n') background.LabyrinthSprite.setTextureRect(IntRect(448, 0, 32, 32));//�������

					background.LabyrinthSprite.setPosition(j * 32, i * 32);
					window.draw(background.LabyrinthSprite);
				}
			if (!showMissionText)//��������� ������
			{
				text.setPosition(view.getCenter().x + 181, view.getCenter().y + 60);
				quest.LabyrinthSprite.setPosition(view.getCenter().x + 160, view.getCenter().y + 40);
				window.draw(quest.LabyrinthSprite);
				window.draw(text);
			}
			window.draw(p.sprite);//������ ������
			for (it = entities.begin(); it != entities.end(); it++)
			{
				window.draw((*it)->sprite);
			}

			if (p.getWin())//�������� ����������� ����
			{
				endgame.LabyrinthSprite.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
				window.draw(endgame.LabyrinthSprite);
			}

			window.display();
		}


	}
};
