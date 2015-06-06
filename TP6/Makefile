CXX            = g++
CFLAGS         = -Wall -Wextra -std=c++11 -Wsuggest-attribute=pure -Wsuggest-attribute=const

EXECS          = main.bin
SOURCES        = $(wildcard **/*.cpp)
HEADERS        = $(wildcard **/*.hpp)
OBJECTS        = $(SOURCES:%.cpp=%.o)

PROFILE_CFLAGS = -Og -pg
DEBUG_CFLAGS   = -Og -g
RELEASE_CFLAGS = -O2

.PHONY: debug profile release clean all

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: all

profile: CFLAGS += $(PROFILE_CFLAGS)
profile: all

release: CFLAGS += $(RELEASE_CFLAGS)
release: all

clean:
	$(RM) $(EXECS) $(OBJECTS)

all: $(EXECS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

main.bin: $(OBJECTS) $(HEADERS)
	$(CXX) $(CFLAGS) $(OBJECTS) -o $@
