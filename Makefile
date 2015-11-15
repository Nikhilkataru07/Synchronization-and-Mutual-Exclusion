CC = gcc
CFLAGS =-g -Wall -Wno-unused-value

all: caltrain

caltrain:caltrain-runner.c caltrain.c caltrain.h
	$(CC) $(CFLAGS) -o caltrain caltrain-runner.c  -lpthread

clean:
	rm caltrain
