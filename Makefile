
CXXFLAGS = -g2 -O2 -DNDEBUG -std=c++11 -pipe
LDFLAGS = -g2 -O2 -DNDEBUG -std=c++11 -pipe


all: main.exe

clean :
	rm -f $(wildcard *.o *.exe)

main.exe : main.o
	g++ $(LDFLAGS) -o main.exe main.o cryptopp/libcryptopp.a

main.o : main.cpp
	g++ $(CXXFLAGS) -Icryptopp -c main.cpp

