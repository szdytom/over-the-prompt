#ifndef _INCLUDE_OTP_STATE_H
#define _INCLUDE_OTP_STATE_H

#include <memory>
#include <vector>
#include <any>
#include <map>
#include <string>
#include <otp/player.h>
#include <otp/mod.h>

namespace world {

namespace time {

} // namespace time

class State {
public:
	State();

	std::shared_ptr<Player> player() const;

	void update();
	
	std::map<std::string, std::any> get_states() const;
	std::any get_state(const std::string &id) const;
	
	void install_mod(std::shared_ptr<mod::AbstructMod> mod);
private:
	std::shared_ptr<Player> _player;
	std::vector<std::shared_ptr<mod::AbstructMod>> _mods;
};

} // namespace world

#endif // _INCLUDE_OTP_STATE_H

