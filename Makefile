OBJS = Main.cpp 

all: $(OBJS)
	g++ $(OBJS) -o a -IC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\include -LC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\lib -w -lmingw32 -lSDL2main -lSDL2 -DLOG_USE_COLOR
