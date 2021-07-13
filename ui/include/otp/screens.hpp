#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

using namespace ftxui;

namespace ui {

class AboutMenu {
private:
	ScreenInteractive screen = ScreenInteractive::Fullscreen();

public:
	void show() {
		auto button_option = ButtonOption();
		button_option.border = false;
		auto buttons = Container::Horizontal({
			Button("[ OK ]", screen.ExitLoopClosure(), button_option),
		});

		const auto main_renderer = Renderer(buttons, [&] {
			return vbox({
				text(L"Over the Prompt") | bold | hcenter,
				text(L"This game is made by SLC & ZTL.") | hcenter,
				text(L"Thanks for playing!") | hcenter,
				text(L"") | hcenter,
				buttons->Render() | hcenter,
			}) | border;
		});

		screen.Loop(main_renderer);
	}
};
AboutMenu about_screen;

class GameMenu {
private:
	ScreenInteractive screen = ScreenInteractive::Fullscreen();

	void jump(int selection) {
		switch (selection) {
			case 3:
			{
				about_screen.show();
				break;
			}
			case 4:
			{
				break;
			}
		}
	}

public:
	void show() {
		auto button_option = ButtonOption();
		button_option.border = false;
		auto buttons = Container::Vertical({
			Button("[ Resume   ]", screen.ExitLoopClosure(), button_option),
			Button("[ New Game ]", screen.ExitLoopClosure(), button_option),
			Button("[ Settings ]", screen.ExitLoopClosure(), button_option),
			Button("[ About    ]", [&]() { jump(3); }, button_option),
			Button("[ Quit     ]", screen.ExitLoopClosure(), button_option),
		});

		const auto main_renderer = Renderer(buttons, [&] {
			return vbox({
				text(L"Over the Prompt") | bold | hcenter,
				text(L"") | hcenter,
				buttons->Render() | hcenter,
			}) | border;
		});

		screen.Loop(main_renderer);
	}
};
GameMenu menu_screen;

} // namespace ui