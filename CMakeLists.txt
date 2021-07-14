CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

INCLUDE(FetchContent)

SET(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

# Install ftxui
FETCHCONTENT_DECLARE(ftxui
	GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
	GIT_TAG fe290e7fed7086abe4fc3b3b21bcc71a07b89d47
)
FETCHCONTENT_MAKEAVAILABLE(ftxui)

# Install {fmt}
FETCHCONTENT_DECLARE(fmt
	GIT_REPOSITORY https://github.com/fmtlib/fmt
	GIT_TAG 8.0.1
)
FETCHCONTENT_MAKEAVAILABLE(fmt)

PROJECT(over-the-prompt
	VERSION 0.1.0
)

ADD_EXECUTABLE(over-the-promote
	src/main.cc
	src/utilities/math/vector.cc
	src/utilities/string/cases.cc
	src/world/cmd/go/direction.cc
	src/world/cmd/go/run.cc
	src/world/mods/time/id.cc
	src/world/mods/time/mod.cc
	src/world/mods/time/state.cc
	src/world/mods/time/time-point.cc
	src/world/player.cc
	src/world/state.cc
)
TARGET_INCLUDE_DIRECTORIES(over-the-promote PRIVATE include)
TARGET_LINK_LIBRARIES(over-the-promote
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
	PRIVATE fmt
)

SET_TARGET_PROPERTIES(over-the-promote PROPERTIES CXX_STANDARD 17)

