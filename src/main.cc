#include <cstdio>
#include <any>
#include <cstdlib>
#include <fmt/core.h>
#include <thread>
#include <chrono>
#include <memory>
#include <otp/command.h>
#include <otp/state.h>
#include <otp/mods/time.h>
using namespace std;

string D[] = {"S", "N", "W", "E"};

int main() {
	auto s = make_shared<world::State>();
	s->install_mod(make_shared<world::mod::time::Mod>());

	while (true) {
		s->update();

		auto time_state = any_cast<world::mod::time::State>(s->get_state("day-cycle"));
		if (time_state.day_time() == world::mod::time::SUNRISE) {
			fmt::print("Sunrise\n");
		} else if (time_state.day_time() == world::mod::time::SUNSET) {
			fmt::print("Sunset\n");
		}

		if (rand() % 20 == 0) {
			string d_name = D[rand() % 4];
			auto d = world::cmd::go::parse_direction(d_name);
			int dis = rand() % 10;

			fmt::print("Moveing {} {}\n", d_name, dis);

			world::cmd::go::run(s, d, dis);
			fmt::print("player @ ({}, {})\n", s->player()->get_x(), s->player()->get_y());
		}

		this_thread::sleep_for(chrono::milliseconds(100));
	}		
	return 0;
}
