#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "FOO.h"


int main()
{
	const int port = 31552;
	int server = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET ;
	adr.sin_port = htons(port);
	Bind(server, (struct sockaddr*) &adr, sizeof(adr) );
	Listen(server, 5);
	socklen_t adrlen = sizeof(adr);
	int fd = Accept(server, (struct sockaddr*) &adr, &adrlen);
	
	ssize_t Read;
	char buf[256];
	Read = read(fd, buf, 256); 
	
	if(Read == -1){ perror("Error read()"); exit(EXIT_FAILURE); }
	else { std::cout << "End of file" << std::endl; }
	
	write(STDOUT_FILENO, buf, Read);
	write(fd, buf, Read);
	
	sleep(15);
	
	close(fd);
	close(server);
return 0;
}
