all: TestOSLL

TestOSLL: TestOSLL.o
	g++ -Wall -o TestOSLL TestOSLL.o  

TestOSLL.o: testOSLL.cpp OSLL.h 
	g++ -Wall -o TestOSLL.o -c testOSLL.cpp 

clean:
	rm -f TestOSLL *.o
