CXX = gcc
CXXFLAGS = -g
MD = mkdir

all: bin \
	measure

bin:
	$(MD) -p bin

mesurement:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

remove:
	rm -rf bin/*.dSYM

clean:
	rm -rf bin
