#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <fmt/core.h>
#include <string>
#include <codecvt>
#include <locale>

std::wstring to_wstring(const std::string &x) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(x);
}

std::string to_string(const std::wstring &x) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.to_bytes(x);
}

int main() {
	using namespace ftxui;
	using namespace std;
 
	// Define the document
	Element document =
		hbox({
			text(to_wstring(fmt::format("{}", "left")))   | border,
			text(to_wstring(fmt::format("{}", "middle"))) | border | flex,
			text(to_wstring(fmt::format("{}", "right")))  | border,
		});
 
	auto screen = Screen::Create(
		Dimension::Full(),       // Width
		Dimension::Fit(document) // Height
	);
	Render(screen, document);
	screen.Print();
 
	return 0; 
}
