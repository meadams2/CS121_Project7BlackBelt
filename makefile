heap: main.o address.o date.o student.o
	g++ -g date.o address.o student.o main.o -o heap

main.o: date.h address.h student.h main.cpp
	g++ -c -g main.cpp

date.o: date.h date.cpp
	g++ -c -g date.cpp

address.o: address.h address.cpp
	g++ -c -g address.cpp

student.o: address.h date.h student.h student.cpp
	g++ -c -g student.cpp

clean: 
	rm *.o
	rm heap

run: heap
	./heap

debug: heap
	gdb heap

valgrind: heap
	valgrind ./heap

git: 
	git status
	git add .
