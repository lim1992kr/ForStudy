#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100

void error_handling(char *message);

char rev_msg[BUF_SIZE];

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	int str_len=0;

	if(argc!=2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind() error");

	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if(clnt_sock==-1)
		error_handling("accept() error");

	// read, write
	while(1)
	{
		memset(rev_msg, 0, sizeof(rev_msg));
		str_len = read(clnt_sock, rev_msg, sizeof(rev_msg)-1);
		if(str_len==-1)
			error_handling("read() error!");

		if(str_len==0)
		{
			printf("client 종료\n");
			break;
		}
		//strcmp 스트링 컴페어, 두값을 비교해서 같으면 0
		if(!strcmp(rev_msg, "LED0_ON\n"))
			printf("Message from server : %s", rev_msg);

		else if(!strcmp(rev_msg, "LED0_OFF\n"))
			printf("Message from server : %s", rev_msg);


//	printf("%s는명령어가 아닙니다.",rev_msg);를 쓰면 \n도같이 들어가서 이상하게 나온다,

	}

	close(clnt_sock);
	close(serv_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}


