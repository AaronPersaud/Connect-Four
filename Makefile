connect: connect.o main.o easy.o
	g++ -o connect connect.o main.o easy.o
connect.o: connect.cc connect.h
	g++ -c connect.cc
main.o: main.cc 
	g++ -c main.cc
easy.o: easy.cc easy.h
	g++ -c easy.cc
clean:
	rm connect *.o