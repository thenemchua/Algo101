CXX            = g++
CFLAGS         = -Wall -Wextra -std=c++0x

EXOS           = $(dir $(wildcard **/main.cpp))
EXECS          = $(EXOS:%/=%.bin)

PROFILE_CFLAGS = -O -pg
DEBUG_CFLAGS   = -O -g
RELEASE_CFLAGS = -O2

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: all

profile: CFLAGS += $(PROFILE_CFLAGS)
profile: all

release: CFLAGS += $(RELEASE_CFLAGS)
release: all

all: $(EXECS)

%.bin: %/*.cpp
	$(CXX) $(CFLAGS) $^ -o $@
