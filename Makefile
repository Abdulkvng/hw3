CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable

#-----------------------------------------------------
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o $@ llrec-test.o llrec.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp -o $@

llrec.o: llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o $@

clean:
	rm -f *.o llrec-test *~

.PHONY: clean