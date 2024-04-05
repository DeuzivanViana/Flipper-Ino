#pragma once

#include "Drawable.hpp"
#include "Option.hpp"

class Menu : public Drawable
{
	public:
		Menu() noexcept;
		
		void addOption(const Option option) noexcept;

		~Menu() noexcept;

	protected:
		void _resize() noexcept;

	private:
		Option *__options;
		uint8_t __index, __size;

		void __draw(const U8GLIB_SSD1306_128X64&) const noexcept override;
};
