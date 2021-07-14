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
	AboutMenu() { }
	~AboutMenu() { }

public:
	static AboutMenu& GetInstance(){
		static AboutMenu instance;
		return instance;
	}

	void Show() {
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

class GameMenu {
private:
	ScreenInteractive screen = ScreenInteractive::Fullscreen();
	GameMenu() { }
	~GameMenu() { }

	void Jump(int selection) {
		switch (selection) {
			case 3: {
				AboutMenu::GetInstance().Show();
				break;
			}
			case 4: {
				break;
			}
		}
	}

public:
	static GameMenu& GetInstance(){
		static GameMenu instance;
		return instance;
	}

	void Show() {
		auto button_option = ButtonOption();
		button_option.border = false;
		auto buttons = Container::Vertical({
			Button("[ Resume   ]", screen.ExitLoopClosure(), button_option),
			Button("[ New Game ]", screen.ExitLoopClosure(), button_option),
			Button("[ Settings ]", screen.ExitLoopClosure(), button_option),
			Button("[ About    ]", [&]() { Jump(3); }, button_option),
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

} // namespace ui
