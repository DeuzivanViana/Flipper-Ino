#pragma once

#include <U8glib.h>
#include "Drawable.hpp"

class Display
{
	public:
		Display() noexcept;

		void init() noexcept;
		void firstPage() const noexcept;
		int nextPage() const noexcept;
		const U8GLIB_SSD1306_128X64 &getU8g() const noexcept;
		void draw(const Drawable&) const noexcept;

		~Display() noexcept;
	private:
		U8GLIB_SSD1306_128X64 *__u8g;
};
