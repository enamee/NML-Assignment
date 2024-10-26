CXXFLAGS = -g -Wall -mconsole -IC:\Tools\python\include -Iinclude
LDFLAGS = -LC:\Tools\python\libs -lpython312
SOURCES = src/main.cpp src/utils.cpp 
HEADERS = include/utils.h include/luFactorization.h
TARGET = program
CLEANUP = rm -f *.o

all: $(TARGET)

$(TARGET): build/main.o build/utils.o build/luFactorization.o
	g++ build/main.o build/utils.o build/luFactorization.o -o program $(CXXFLAGS) $(LDFLAGS)

build/main.o: $(SOURCES) $(HEADERS)
	g++ -c src/main.cpp $(CXXFLAGS) -o build/main.o

build/utils.o: $(SOURCES) $(HEADERS)
	g++ -c src/utils.cpp $(CXXFLAGS) -o build/utils.o

build/luFactorization.o: src/utils/luFactorization.cpp $(HEADERS)
	g++ -c src/utils/luFactorization.cpp $(CXXFLAGS) -o build/luFactorization.o

clean:
	$(CLEANUP)