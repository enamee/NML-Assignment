CXX = g++
CXXFLAGS = -g -Wall -IC:\Tools\python\include
LDFLAGS = -LC:\Tools\python\libs -lpython312
SOURCES = src/main.cpp src/app.cpp src/utils.cpp
HEADERS = src/app.h src/utils.h
TARGET = app
CLEANUP = rm -f *.o

all: $(TARGET)

$(TARGET): main.o
	g++ main.o -o app $(CXXFLAGS) $(LDFLAGS)

main.o: $(SOURCES) $(HEADERS)
	g++ -c $(SOURCES) $(CXXFLAGS)

clean:
	$(CLEANUP)