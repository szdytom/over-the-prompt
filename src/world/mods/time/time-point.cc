#include <otp/mods/time.h>
using namespace world::mod::time;

bool State::is_day() const {
	return this->day_time() >= SUNRISE && this->day_time() < SUNSET;
}

bool State::is_night() const {
	return !this->is_day();
}

bool State::is_late_night() const {
	return this->day_time() >= MIDNIGHT && this->day_time() < SUNRISE;
}

bool State::is_morning() const {
	return this->day_time() >= SUNRISE && this->day_time() < NOON;
}

bool State::is_afternoon() const {
	return this->day_time() > NOON && this->day_time() < SUNSET;
}

bool State::is_evening() const {
	return this->day_time() >= SUNSET;
}

