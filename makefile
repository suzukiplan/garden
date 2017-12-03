all:
	gcc -o main main.c status.c rand.c
	./main
	rm main

