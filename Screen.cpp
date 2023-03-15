#include "Screen.h"

#include "Game.h"

Screen::Screen() {
  this->font.loadFromFile("PixellettersFull.ttf");
  this->text.setFont(this->font);
  this->text.setOutlineThickness(2.f);
  this->text.setOutlineColor(sf::Color::Black);
  this->text.setCharacterSize(40);
}

Screen::~Screen() {}

bool Screen::isOver() { return over; }
