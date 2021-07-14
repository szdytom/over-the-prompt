#ifndef _INCLUDE_OTP_MOD_TIME_H
#define _INCLUDE_OTP_MOD_TIME_H

#include <otp/mod.h>
#include <string>
#include <any>

namespace world {
namespace mod {
namespace time {

const int DAY_LENGTH = 600;
const int SUNRISE    = 120;
const int NOON       = 300;
const int SUNSET     = 460;
const int MIDNIGHT   = 0;

class State {
public:
	int tick;

	State();
	State(int tick);

	int day_count()       const;
	int day_time()        const;
	bool is_day()         const;
	bool is_night()       const;
	bool is_late_night()  const;
	bool is_morning()     const;
	bool is_afternoon()   const;
	bool is_evening()     const;
};

class Mod : public AbstructMod {
public:
	void update() override;
	void on_start() override;

	std::string uid() const override;
	std::any get_state() const override;

private:
	int _tick;
};

} // namespace time
} // namespace mod
} // namespace world

#endif // _INCLUDE_OTP_MOD_TIME_H

