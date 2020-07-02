#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char opmsg[BUF_SIZE];
	int result, opnd_cnt, i;
	struct sockaddr_in serv_adr;
	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock=socket(PF_INET, SOCK_STREAM, 0);
	if(sock==-1)
		error_handling("socket() error");

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");

	fputs("Operand count: ", stdout);
	scanf("%d", &opnd_cnt);
	//1바이트 짜리 값을 넣어줌
	opmsg[0]=(char)opnd_cnt;

	//오퍼렌드로 들어온 값만큼 for문을 돌려준다.
	for(i=0; i<opnd_cnt; i++)
	{
		printf("Operand %d: ", i+1);
		scanf("%d", (int*)&opmsg[i*OPSZ+1]);
	}
	fgetc(stdin);
	fputs("Operator: ", stdout);
	scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);
	//피연산자 수와 피연산자 연산자를 받음.

	write(sock, opmsg, opnd_cnt*OPSZ+2);
	//14개를 보냄

	read(sock, &result, RLT_SIZE);

	printf("Operation result: %d \n", result);
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
