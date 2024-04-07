#include "Display.hpp"

#include "Config.hpp"

Display::Display() noexcept
{
	this->__oled = new Adafruit_SSD1306(
			OLED_WIDTH, OLED_HEIGHT, &Wire, -1);
}

void Display::init() noexcept
{
	this->__oled->begin(SSD1306_SWITCHCAPVCC, 0x3C);
	this->__oled->setTextSize(1);
  this->__oled->setTextColor(WHITE);

}
const Adafruit_SSD1306 &Display::getSsd() const noexcept
{
	return *this->__oled;
}
void Display::draw(const Drawable &drawable) const noexcept
{
	drawable.__draw(this->getSsd());
}
void Display::clear() const noexcept
{
	this->__oled->clearDisplay();
}
void Display::render() const noexcept
{
	this->__oled->display();
}

Display::~Display() noexcept
{
	delete this->__oled;
}
