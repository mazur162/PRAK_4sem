COMPILER = g++
FLAGS = -O2 -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wmissing-field-initializers -Wctor-dtor-privacy -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Weffc++ -g -fno-inline -lm

SRCS=$(wildcard t*.cpp)

OBJS=$(SRCS:.cpp=)

all: $(OBJS)

test: $(SRC)
	$(COMPILER) -o $@ $^ $(FLAGS)

clean:
	rm -f test
