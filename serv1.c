// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024
#define MSG_CONFIRM 0 // workaround for compile error not finding the flag

// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Message Received.";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	unsigned int len;
	unsigned int n;
	len = sizeof(cliaddr); //len is value/resuslt

	/*
	 * recvfrom(int socket_description,
	 * 					char * ptr_buffer,
	 * 					int max_line,
	 * 					int flag,
	 * 					struct sockaddr * addr_of_sender,
	 * 					int * ptr_len_of_packet_received)
	 */
	while (1) {
			n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					MSG_WAITALL, ( struct sockaddr *) &cliaddr,
					&len);
			buffer[n] = '\0';
			printf("server_2 : %s\n", buffer);
			sendto(sockfd, (const char *)hello, strlen(hello),
				MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
					len);
	}
	
	return 0;
}
