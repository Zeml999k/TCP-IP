#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "FOO.h"


int Socket(int domain, int type, int protocol) //проверка на создание сокета
{
	int res = socket(domain, type, protocol);
	if(res == -1){ perror("Error Socket"); exit(EXIT_FAILURE); }
	else { return res; }
}

void Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen) //проверка на привязку адреса 
{
	int res = bind(sockfd, addr, addrlen);
	if(res == -1) { perror("Error Bind"); exit(EXIT_FAILURE); }

}

void Listen(int sockfd, int backlog) //проверка на прослушивание входящего соединения 
{
	int res = listen(sockfd, backlog);
	if(res == -1) { perror("Error Listen"); exit(EXIT_FAILURE); }

}

int Accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) //проверка на принятие соединения 
{	
	int res = accept(sockfd, addr, addrlen);
	if(res == -1) { perror("Error Accept"); exit(EXIT_FAILURE); }
	return res;
}

void Connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
{
	int res = connect(sockfd, addr, addrlen);
	if(res == -1){ perror("Error Connect"); exit(EXIT_FAILURE); }
}

void Inet_pton(int af, const char* src, void* dst)
{
	int res = inet_pton(af, src, dst);
	if(res == 0) {   printf("inet_pton failed: src does not contain a character"
            " string representing a valid network address in the specified"
            " address family\n"); exit(EXIT_FAILURE); }
	if(res == -1){ perror("Error Inet_pton"); exit(EXIT_FAILURE); }

}
