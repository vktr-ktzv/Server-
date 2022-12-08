CFLAGS = -std=c99 
LDFLAGS = -W -Wall -Werror
COMPILERFLAG = gcc

server: server.c errorprocesing.c
	$(COMPILERFLAG)	$(CFLAGS) 	-o server	server.c errorprocesing.c 	$(LDFLAGS)

client: client.c errorprocesing.c
	$(COMPILERFLAG) 	$(CFLAGS) 	-o client 	client.c errorprocesing.c 	$(LDFLAGS) 

.PHONY: startserver	startClient 	clean

startServer: server
	./server

startClient: client
	./client

clean:
	rm	-f	client server