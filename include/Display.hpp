#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Drawable.hpp"

class Display
{
	public:
		Display() noexcept;

		void init() noexcept;
		const Adafruit_SSD1306 &getSsd() const noexcept;
		void draw(const Drawable&) const noexcept;
		void clear() const noexcept;
		void render() const noexcept;

		~Display() noexcept;
	private:
		Adafruit_SSD1306 *__oled;
};
