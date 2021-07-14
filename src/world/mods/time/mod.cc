#include <otp/mods/time.h>
#include <any>
using namespace world::mod;

void time::Mod::update() {
	this->_tick += 1;
}

void time::Mod::on_start() {
	this->_tick = 0;
}

std::any time::Mod::get_state() const {
	return std::make_any<time::State>(this->_tick);
}

