#include "Option.hpp"

Option::Option(const String &label, const uint8_t *icon) noexcept
{
	this->setLabel(label);
	this->setIcon(icon);
}

void Option::setLabel(const String &label) noexcept
{
	this->__label = String(label);
}
const String &Option::getLabel() const noexcept
{
	return this->__label;
}
void Option::setIcon(const uint8_t *icon) noexcept
{
	this->__icon = icon;
}
const uint8_t *Option::getIcon() const noexcept
{
	return this->__icon;
}

Option::~Option()
{
}
