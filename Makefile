#       MAKEFILE
CFLAGS = -g -w -Wall -Wshadow -o
GCC = g++ $(CFLAGS)

all: comp

comp:     main.cpp node.cpp parser.cpp scanner.cpp checkSem.cpp semantics.cpp
	$(GCC) $(CFLAGS) comp main.cpp node.cpp parser.cpp scanner.cpp checkSem.cpp semantics.cpp -std=c++11

clean:
	rm -f *.o a.out *.asm comp
