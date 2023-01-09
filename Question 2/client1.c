#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

int main() {
	
	char request[256] = "Hello here is client chat!";
	char buf[200];
	
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	
	for(int i = 0; i < 1;){
	printf("Enter string: ");
    	scanf("%s", request);
	send(sock, request, sizeof(request), 0);
	recv(sock, &buf, sizeof(buf), 0);
	if(strcmp(buf,"exit") == 0){
	printf("\n%s \n", "Quitting the program");
	break;
	}
	printf("\n%s \n", buf);
	
	}
	close(sock);

	return 0;
}

