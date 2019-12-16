OBJS = Main.c Engine/log.c/src/log.c 
DEP = linkedlist
BUILD = build/LinkedList.o

all: $(OBJS) $(DEP)
	gcc $(OBJS) $(BUILD) -o a -IC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\include -LC:\Dev\SDL2-2.0.10\x86_64-w64-mingw32\lib -w -lmingw32 -lSDL2main -lSDL2 -DLOG_USE_COLOR

linkedlist: Engine/DataStructures/LinkedList.c Engine/DataStructures/LinkedList.h
	gcc -c Engine/DataStructures/LinkedList.c -o build/LinkedList.o