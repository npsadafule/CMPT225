all: Test 

Test: Test.o
	g++ -Wall -o Test Test.o  

Test.o: Test.cpp OSLL.h 
	g++ -Wall -o Test.o -c TesT.cpp 

clean:
	rm -f Test  *.o
