#include <SFML/Graphics.hpp>
#include "Full.h"
using namespace sf;
using namespace std;


int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "The Maze Runner");//сделали размеры экрана
	menu(window);
	Full FullHD;//создали обьект класса фулл
	FullHD.full(window);//передали в фуллхд обьект окно

	return 0;
}