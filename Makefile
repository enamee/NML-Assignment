CXX = g++
CXXFLAGS = -g -Wall -IC:\Tools\python\include
LDFLAGS = -LC:\Tools\python\libs -lpython312
SOURCES = src/main.cpp src/app.cpp src/utils.cpp
HEADERS = src/app.h src/utils.h
TARGET = app
CLEANUP = rm -f *.o

all: $(TARGET)

$(TARGET): app.o
	g++ app.o -o app $(CXXFLAGS) $(LDFLAGS)

app.o: $(SOURCES)