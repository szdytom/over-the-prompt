#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <fmt/core.h>
 
int main() {
	using namespace ftxui;
 
	// Define the document
	Element document =
		hbox({
			text(fmt::format("{}", "left"))   | border,
			text(fmt::format("{}", "middle")) | border | flex,
			text(fmt::format("{}", "right"))  | border,
		});
 
	auto screen = Screen::Create(
		Dimension::Full(),       // Width
		Dimension::Fit(document) // Height
	);
	Render(screen, document);
	screen.Print();
 
	return 0; 
}
