#include <otp/state.h>
#include <fmt/core.h>
#include <exception>
#include <any>
#include <string>
#include <map>
using namespace std;
using namespace world;

State::State() {
	this->_player = make_shared<Player>();
}

shared_ptr<Player> State::player() const {
	return this->_player;
}

void State::update() {
	for (size_t i = 0; i < this->_mods.size(); ++i) {
		this->_mods[i]->update();
	}
}

void State::install_mod(shared_ptr<mod::AbstructMod> mod) {
	this->_mods.push_back(mod);
	this->_mods.back()->on_start();
}

map<string, any> State::get_states() const {
	map<string, any> res;
	for (size_t i = 0; i < this->_mods.size(); ++i) {
		res.insert({this->_mods[i]->uid(), this->_mods[i]->get_state()});
	}
	return res;
}

any State::get_state(const string &id) const {
	for (size_t i = 0; i < this->_mods.size(); ++i) {
		if (this->_mods[i]->uid() == id) {
			return this->_mods[i]->get_state();
		}
	}

	throw invalid_argument(fmt::format("mod {} not found", id));
}

