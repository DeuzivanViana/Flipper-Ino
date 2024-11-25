#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <Adafruit_SSD1306.h>

class Drawable
{
	public:
		Drawable() noexcept = default;

		friend class Display;
	private:
		virtual void __draw(Adafruit_SSD1306&) const noexcept = 0;
};

#endif