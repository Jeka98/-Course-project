#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Fruit.h"
#include "main.h"
#include "Utilities.h"
#include <fstream>
#include "Resources.h"
//---------------------------

class Controller // 2) Game
{
public:
	Controller();
	void run();
	void input(); //  private?
	void logic(); // private?
	void draw(); // private?
	void updateScore(int); // private?
	void clean(); // private ?
	void initText(sf::Text &, std::string &, unsigned int); // private?

private:
	sf::RenderWindow m_window;
	sf::Sprite m_sprite;
	sf::Sprite m_spriteReset;
	sf::Sprite m_spritePower;
	sf::Text m_text;
	Snake m_snake;
	Fruit m_fruit;
	Menu m_menu;
	eDirection m_direction = STOP;
	bool m_gameOver = false;
	int m_score = 0;
	int m_highScore;
	std::fstream m_file; // remove?
	//*****************************************************************
	//sound in game
	sf::SoundBuffer m_soundBuffer1;
	sf::Sound m_gameSound; // move to Resources.
};

// предлагаю завести отдельный класс ScoreDataService и сгрузить туда 2 метода по получению и записи скора, а имя файла константой сделать.