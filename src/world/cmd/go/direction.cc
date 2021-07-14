#include <otp/cmd/go.h>
#include <otp/utility.h>
#include <exception>
#include <fmt/core.h>
using namespace world;
using namespace cmd::go;
using namespace utility;

Direction cmd::go::parse_direction(const std::string &x) {
	std::string lx = string::to_lowercase(x);
	
	if (x == "S" || lx == "south") {
		return Direction::south;
	} else if (x == "N" || lx == "north") {
		return Direction::north;
	} else if (x == "E" || lx == "east") {
		return Direction::east;
	} else if (x == "W" || lx == "west") {
		return Direction::west;
	}

	throw std::invalid_argument(fmt::format("unknown direction name: {}", x));
}

math::Vec2 cmd::go::direction_vector(const Direction &x) {
	if (x == Direction::north) {
		return {1, 0};
	} else if (x == Direction::south) {
		return {-1, 0};
	} else if (x == Direction::east) {
		return {0, 1};
	} else {
		return {0, -1};
	}
}

