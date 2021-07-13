#ifndef _INCLUDE_OTP_PLAYER_H
#define _INCLUDE_OTP_PLAYER_H

#include <otp/utility.h>

namespace world {

class Player {
public:
	Player();
	
	int get_x() const;
	int get_y() const;
	int get_chunk_x() const;
	int get_chunk_y() const;
	utility::math::Vec2 get_position() const;
	utility::math::Vec2 get_chunk_position() const;

	void apply_move(const utility::math::Vec2 &v);

private:
	utility::math::Vec2 _position;
};

} // namespace world

#endif // _INCLUDE_OTP_PLAYER_H

