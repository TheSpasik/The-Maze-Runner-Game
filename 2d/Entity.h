#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Entity {//����� ���������
protected:
	float x, y, w, h, dx, dy, speed;
	String file;
	Image image;
	Texture texture;
public:
	Sprite sprite;
	Entity(String F, int X, int Y, float W, float H)//����������� � �����������
	{
		speed = 0;
		file = F;
		w = W;
		h = H;
		x = X;
		y = Y;
		image.loadFromFile("C:/game/" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
	void setSpeed(float _speed) { speed = _speed; }//������ �������� ������������
	FloatRect GetRect()// ����� �������� � ��������� �������� �����
	{
		return FloatRect(x, y, w, h);
	}
	virtual void update(float time) = 0;
};