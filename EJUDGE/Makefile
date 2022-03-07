COMPILER = g++
FLAGS = -O2 -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wmissing-field-initializers -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Weffc++ -std=gnu++20 -g -lm

SRCS=$(wildcard t*.cpp)

OBJS=$(SRCS:.cpp=)

all: $(OBJS)

test: $(SRC)
	$(COMPILER) -o $@ $^ $(FLAGS)

clean:
	rm -f test
