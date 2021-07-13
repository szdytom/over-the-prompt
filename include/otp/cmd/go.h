#ifndef _INCLUDE_OTP_CMD_GO_H
#define _INCLUDE_OTP_CMD_GO_H

#include <string>
#include <memory>
#include <otp/utility.h>
#include <otp/state.h>

namespace world {
namespace cmd {
namespace go {

enum class Direction {
	north,
	south,
	east,
	west,
};
Direction parse_direction(const std::string &direction_name);
utility::math::Vec2 direction_vector(const Direction &direction);

void run(std::shared_ptr<world::State> world_state, const Direction &d, int distance = 1);

} // namespace go
} // namespace cmd
} // namespace world

#endif // _INCLUDE_OTP_CMD_GO_H

