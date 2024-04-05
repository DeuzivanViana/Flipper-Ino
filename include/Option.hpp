#pragma once

#include <Arduino.h>

class Option
{
	public:
		Option(const String& = "<label>", const uint8_t* = NULL) noexcept;

		void setLabel(const String&) noexcept;
		const String &getLabel() const noexcept;
		void setIcon(const uint8_t*) noexcept;
		const uint8_t *getIcon() const noexcept;

		~Option() noexcept;
	private:
		String __label;
		uint8_t *__icon;
};
