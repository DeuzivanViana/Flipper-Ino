#include "Menu.hpp"

#include "Config.hpp"

Menu::Menu() noexcept
	: __index{0}, __size{1}
{
}

void Menu::addOption(const Option option) noexcept
{
	this->_resize();
	this->__options[this->__size - 1] = option;
}
void Menu::_resize() noexcept
{
	Option buffer[this->__size];
	for(uint8_t i = 0; i < this->__size; i++)
		buffer[i] = this->__options[i];

	delete[] this->__options;
	this->__options = new Option[this->__size + 1];

	for(uint8_t i = 0; i < this->__size; i++)
		this->__options[i] = buffer[i];

	this->__size++;
}

void Menu::__draw(const U8GLIB_SSD1306_128X64 &u8g) const noexcept 
{
	for(uint8_t i = 0; i < this->__size; i++)
		u8g.drawStr(0, FONT_HEIGHT * i, this->__options[i].getLabel().c_str());
}

Menu::~Menu()
{
	delete[] this->__options;
}
