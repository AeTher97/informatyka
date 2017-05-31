cos.out : main.o classes.o
	g++ -o cos -Wall main.o classes.o
main.o : main.cpp classes.h classes.cpp
	g++ -c -Wall main.cpp
classes.o : classes.cpp classes.h
	g++ -c -Wall classes.cpp classes.h
