#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int createConnection(int port, char *host)
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("%d\n", sockfd);

	struct hostent *server = gethostbyname(host);
	if(server == NULL)
	{
		printf("ERROR: %s\n", hstrerror(h_errno));
	}

	printf("ADDRESS: %s\n", server->h_addr);
	printf("INT_ADDRESS: %d\n", atoi(server->h_addr));

	struct sockaddr_in serv_addr = (struct sockaddr_in) {.sin_family = AF_INET,
		.sin_port = htons(port),
		.sin_addr.s_addr = atoi(server->h_addr)};
	
	printf("COPIED ADDRESS: %d\n", serv_addr.sin_addr.s_addr);

	int connectionResult = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	printf("CONNECTION SUCCESS: %d\n", connectionResult);
	
	close(sockfd);

	return sockfd;
}

int main()
{
	createConnection(80, "catfact.ninja");

	return 0;
}
