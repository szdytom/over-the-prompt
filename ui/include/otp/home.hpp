#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

namespace ui {

class GameMenu {
private:

public:
	void show() {
		using namespace ftxui;
		auto screen = ScreenInteractive::Fullscreen();

		std::vector<std::wstring> entries = {
			L"Resume",
			L"New Game",
			L"About",
			L"Quit",
		};
		int selected = 0;

		MenuOption option;
		option.on_enter = screen.ExitLoopClosure();
		auto menu = Menu(&entries, &selected, &option);

		auto main_renderer = Renderer(menu, [&] {
			return vbox({
				text(L"Over the Prompt") | bold | hcenter,
				text(L" ") | hcenter,
				menu->Render() | hcenter,
			}) | border;
		});

		screen.Loop(main_renderer);
	}
};

GameMenu menu_screen;

} // namespace ui