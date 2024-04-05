#include "Option.hpp"
#include "Menu.hpp"
#include "Display.hpp"
#include "Config.hpp"

constexpr uint8_t AMOUNT_OPTIONS = 32 , i = 0;
unsigned long prev_tick = 0;

Menu menu;
Display display;

void setup(void)
{
	display.init();

	menu.addOption(Option("Tools"));
	menu.addOption(Option("Setting"));
	menu.addOption(Option("About"));
}

void loop(void)
{
	float dt = static_cast<float>(millis() - (prev_tick)) / 1000.f;
	prev_tick = millis();

  display.firstPage(); do {
		display.getU8g().drawStr(0, FONT_HEIGHT * 5, ("FPS: " + String(1.f / dt)).c_str());
		display.draw(menu);

	} while (display.nextPage());
}
