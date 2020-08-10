#!make -f

CXX=clang++-9
CXXFLAGS=-std=c++2a

HEADERS=picture.hpp
OBJECTS=
# NOTE: there are no objects -- all code is in the header files, since this is template code!

all: test demo

test: TestRunner.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) Test.cpp TestRunner.cpp -o test

Test.o: Test.cpp TestRunner.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile Test.cpp TestRunner.cpp

demo: demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) demo.o -o demo

demo.o: demo.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile demo.cpp

clean:
	rm -f *.o test demo