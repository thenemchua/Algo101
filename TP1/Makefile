CXX            = g++
CFLAGS         = -Wall -Wextra -std=c++0x

SOURCES        = $(wildcard *.cpp)
EXECS          = $(SOURCES:%.cpp=%.bin)

PROFILE_CFLAGS = -O -pg
DEBUG_CFLAGS   = -O -g
RELEASE_CFLAGS = -O2

all: debug

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(EXECS)

profile: CFLAGS += $(PROFILE_CFLAGS)

%.bin: %.cpp
	$(CXX) $(CFLAGS) $< -o $@
