#pragma once

#include <Adafruit_SSD1306.h>

class Drawable
{
	public:
		Drawable() noexcept = default;

		friend class Display;
	private:
		virtual void __draw(const Adafruit_SSD1306&) const noexcept = 0;
};
