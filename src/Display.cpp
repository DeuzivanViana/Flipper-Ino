#include "Display.hpp"

Display::Display() noexcept
{
}

void Display::init() noexcept
{
	this->__u8g = new U8GLIB_SSD1306_128X64(
			U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

	this->__u8g->setColorIndex(1);
	this->__u8g->setFont(u8g_font_6x12);
}
void Display::firstPage() const noexcept
{
	this->__u8g->firstPage();
}
int Display::nextPage() const noexcept
{
	return this->__u8g->nextPage();
}
const U8GLIB_SSD1306_128X64 &Display::getU8g() const noexcept
{
	return *this->__u8g;
}
void Display::draw(const Drawable &drawable) const noexcept
{
	drawable.__draw(this->getU8g());
}

Display::~Display() noexcept
{
	delete this->__u8g;
}
