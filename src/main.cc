#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <fmt/core.h>
#include <codecvt>
#include <string>
#include <locale>

#include "../ui/include/otp/screens.hpp"

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

	ui::menu_screen.show();
	return 0; 
}
