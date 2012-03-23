CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= main.cpp city.cpp game.cpp getPlayerNumbers.cpp turn.cpp visitCity.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=The-Empire-Game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o The-Empire-Game
