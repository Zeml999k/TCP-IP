#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "FOO.h"




int main()
{
	const int port = 31552;
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port);
	Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
	Connect(fd, (struct sockaddr *) &adr, sizeof adr);
	write(fd, "Hello!", 6);
	char buf[256];
	ssize_t Read;
	Read = read(fd, buf, 256);
	if(Read == -1) { perror("Error Read"); exit(EXIT_FAILURE); }
	if(Read == 0) { std::cout << "EOF file" << std::endl; }
	write(STDOUT_FILENO, buf, Read);
	sleep(20);
	close(fd);
	return 0;


}
