#ifndef _INCLUDE_OTP_MOD_H
#define _INCLUDE_OTP_MOD_H

#include <string>
#include <any>

namespace world {
namespace mod {

class AbstructMod {
public:
	virtual void update() = 0;
	virtual void on_start() = 0;

	virtual std::string uid() const = 0;
	virtual std::any get_state() const = 0;
};
	

} // namespace mod
} // namespace world

#endif // _INCLUDE_OTP_MOD_H

