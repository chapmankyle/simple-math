# C++ Makefile

COMPILER ?= $(GCC_PATH)g++

FLAGS ?= -std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -pedantic-errors
INCLUDE_DIRS = -I.

LDFLAGS ?= -g

EXECUTABLE = main

SRCS=$(wildcard test/*.cpp)
OBJS=$(SRCS:test/%.cpp=bin/%.o)

all: release

release: $(OBJS)
	$(COMPILER) $(LDFLAGS) -o $(EXECUTABLE) $(OBJS)

bin/%.o: test/%.cpp
	$(COMPILER) $(INCLUDE_DIRS) $(FLAGS) -o $@ -c $<

clean:
	rm -f bin/*.o
	rm ${EXECUTABLE} 
