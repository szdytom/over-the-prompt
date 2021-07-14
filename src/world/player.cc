#include <otp/player.h>
#include <otp/map.h>
#include <otp/utility.h>
using namespace world;
using namespace utility;

Player::Player(): _position(math::Vec2::zero()) {}

int Player::get_x() const {
	return this->_position.x;
}

int Player::get_y() const {
	return this->_position.y;
}

int Player::get_chunk_x() const {
	return this->get_x() / CHUNK_SIZE;
}

int Player::get_chunk_y() const {
	return this->get_y() / CHUNK_SIZE;
}

math::Vec2 Player::get_position() const {
	return this->_position;
}

math::Vec2 Player::get_chunk_position() const {
	return this->_position / CHUNK_SIZE;
}

void Player::apply_move(const math::Vec2 &v) {
	this->_position += v;
}

