#include <otp/mods/time.h>
using namespace world::mod;

time::State::State(): tick(0) {}
time::State::State(int tick): tick(tick) {}

int time::State::day_count() const {
	return this->tick / time::DAY_LENGTH;
}

int time::State::day_time() const {
	return this->tick % time::DAY_LENGTH;
}

