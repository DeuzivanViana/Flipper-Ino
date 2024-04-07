#include "Option.hpp"
#include "Menu.hpp"
#include "Display.hpp"
#include "Config.hpp"

constexpr uint8_t AMOUNT_OPTIONS = 8, i = 0;
unsigned long prev_tick = 0;

Menu menu;
Display display;

void setup(void)
{
	display.init();
	// Dump overflow when i try create 32 options... '-'
	for(uint8_t i = 0; i < AMOUNT_OPTIONS; i++)
		menu.addOption(Option("Tools"));
}

void loop(void)
{
	float dt = static_cast<float>(millis() - (prev_tick)) / 1000.f;
	prev_tick = millis();

	display.clear();

	display.getSsd().setCursor(0, 0);
	display.getSsd().println(("memuse<Menu>: ~" + String(sizeof(Option) * menu.getSize() + sizeof(menu)) + "kb").c_str());
	display.getSsd().println(("FPS: " + String(1.f / dt)).c_str());
	//display.draw(menu);
	
	display.render();
	delay(1);
}
