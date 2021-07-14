#include <otp/cmd/go.h>
using namespace world;
using namespace cmd::go;

void cmd::go::run(std::shared_ptr<State> s, const Direction &d, int distance) {
	auto p = s->player();
	p->apply_move(direction_vector(d) * distance);
}
