OBJS = Main.cpp
BINS = $(GameData) $(ENGINE)
GAMEDATA = build\GameData.o
ENGINE =  build\Engine.o
COMPILER = g++ -std=c++14
LIB = -IC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\include -LC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\lib -w -lmingw32 -lSDL2main -lSDL2 -DLOG_USE_COLOR


all: $(OBJS)
	mingw32-make.exe build
	$(COMPILER) $(OBJS) $(BINS) -o a -IC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\include -LC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\lib -w -lmingw32 -lSDL2main -lSDL2 -DLOG_USE_COLOR

build: $(GAMEDATA) $(ENGINE)
	mingw32-make.exe $(GAMEDATA)
	mingw32-make.exe $(ENGINE)

$(ENGINE): Engine_CPP\Engine.cpp Engine_CPP\Engine.hpp
	$(COMPILER) Engine_CPP\Engine.cpp -c -o build\Engine.o $(LIB)

$(GAMEDATA): Engine_CPP\GameData.cpp Engine_CPP\GameData.hpp
	$(COMPILER) Engine_CPP\GameData.cpp -c -o $(GAMEDATA) $(LIB)

clean:
	rm build\*
