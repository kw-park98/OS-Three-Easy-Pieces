CXX = gcc
CXXFLAGS = -g
MD = mkdir

all: bin \
	p1 p2 p3 p4 p5 \
	p6 p7 p8 \

bin:
	$(MD) -p bin

p1:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

p2:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

p3:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

p4:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

p5:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c 

p6:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

p7:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

p8:
	$(CXX) $(CXXFLAGS) -o bin/$@ src/$@.c

remove:
	rm -rf bin/*.dSYM

clean:
	rm -rf bin