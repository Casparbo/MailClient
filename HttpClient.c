#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

int createConnection(char *host)
{
	int sockfd;
	
	struct addrinfo hints = {0};
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = 0;
	hints.ai_flags = 0;

	struct addrinfo *info = NULL;

	int lookup_result = getaddrinfo(host, NULL, &hints, &info);

	if(lookup_result < 0)
	{
		printf("ERROR: %s\n", gai_strerror(lookup_result));
	}


	for(struct addrinfo *iter = info; iter != NULL; iter = iter->ai_next)
	{
		printf("ADDRESS: %s\n", info->ai_addr->sa_data);
		printf("FAMILY: %d\n", info->ai_addr->sa_family);
		printf("SIZE CHECK: %ld\n", sizeof(info->ai_addr));


		sockfd = socket(iter->ai_family, iter->ai_socktype, iter->ai_protocol);
		printf("SOCKET: %d\n", sockfd);
		if(sockfd < 0)
		{
			continue;
		}

		int connectionResult = connect(sockfd, iter->ai_addr, iter->ai_addrlen);
		
		if(connectionResult == 0)
		{
			break;
		}

		int error_code = errno;
		printf("CONNECTION ERROR: %d\n", error_code);
	}
	
	close(sockfd);

	return sockfd;
}

int main()
{
	createConnection("www.google.com");

	return 0;
}
