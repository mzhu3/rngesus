main.o: main.c main.h
	gcc main.c main.h -o main.o 

run: main.o
	./main.o

clean: 
	rm main.o