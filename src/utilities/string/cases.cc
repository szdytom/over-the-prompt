#include <string>
#include <otp/utility.h>
using namespace std;

namespace {

bool is_upper_letter(char x) {
	return 'A' <= x && x <= 'Z';
}

bool is_lower_letter(char x) {
	return 'a' <= x && x < 'z';
}

} // namespace unnamed

std::string utility::string::to_uppercase(const std::string &x) {
	std::string res = x;
	for (size_t i = 0; i < x.size(); ++i) {
		if (is_lower_letter(x[i])) {
			res[i] = res[i] - 'a' + 'A';
		}
	}
	return res;
}

std::string utility::string::to_lowercase(const std::string &x) {
	std::string res = x;
	for (size_t i = 0; i < x.size(); ++i) {
		if (is_upper_letter(x[i])) {
			res[i] = res[i] - 'A' + 'a';
		}
	}
	return res;
}
