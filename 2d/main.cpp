#include <SFML/Graphics.hpp>
#include "Full.h"
using namespace sf;
using namespace std;


int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "The Maze Runner");//������� ������� ������
	menu(window);
	Full FullHD;//������� ������ ������ ����
	FullHD.full(window);//�������� � ������ ������ ����

	return 0;
}