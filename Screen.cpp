#include "Screen.h"
#include "Game.h"

Screen::Screen()
{
	this->font.loadFromFile("PixellettersFull.ttf");
	this->text.setFont(this->font);
	this->text.setOutlineThickness(2.f);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setString("\n\n\n\n\n\n\n\n\nPress [SPACE] to play"
		"\n\nPress [ESC] to quit");

	sf::FloatRect textBounds = this->text.getLocalBounds();
	this->text.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	this->text.setPosition(Game::Width / 2.f, Game::Height / 2.f);
}

Screen::~Screen()
{
}