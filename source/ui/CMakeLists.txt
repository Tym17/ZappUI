cmake_minimum_required (VERSION 3.0)

project (zappy_ui)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -g3 -W -Wall -Werror -Wextra")

set(UI-DIR "${CMAKE_SOURCE_DIR}/source/ui/")

set(UI-SRC
	"${UI-DIR}/main.cpp"
	"${UI-DIR}/Log.cpp"
	"${UI-DIR}/App.cpp"
	"${UI-DIR}/CNet.cpp"
	"${UI-DIR}/NetEvent.cpp"
	"${UI-DIR}/PlayerEvent.cpp"
	"${UI-DIR}/MapEvent.cpp"
	"${UI-DIR}/GreetEvent.cpp"
	"${UI-DIR}/CircularBuffer.cpp"
	"${UI-DIR}/Game.cpp"
	"${UI-DIR}/Tile.cpp"
	"${UI-DIR}/Player.cpp"
	"${UI-DIR}/Egg.cpp"
	"${UI-DIR}/Media.cpp"
	)

link_directories("${CMAKE_SOURCE_DIR}/lib/SFML")

add_executable(zappy_ui ${UI-SRC})

target_link_libraries(zappy_ui
			sfml-system
			sfml-window
			sfml-graphics)
