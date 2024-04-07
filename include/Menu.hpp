#pragma once

#include "Drawable.hpp"
#include "Option.hpp"

class Menu : public Drawable
{
	public:
		Menu() noexcept;
		
		void addOption(const Option option) noexcept;
		const size_t getSize() const noexcept;
		
		~Menu() noexcept;

	protected:
		void _resize() noexcept;
	
	private:
		Option *__options;
		uint8_t __index, __size;

		void __draw(const Adafruit_SSD1306&) const noexcept override;
};
