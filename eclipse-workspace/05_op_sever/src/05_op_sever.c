#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define OPSZ 4
void error_handling(char *message);
int calculate(int opnum, int opnds[], char oprator);

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	char opinfo[BUF_SIZE];
	int result, opnd_cnt, i;
	int recv_cnt, recv_len;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock==-1)
		error_handling("socket() error");

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	clnt_adr_sz=sizeof(clnt_adr);

	for(i=0; i<5; i++)
	{		//클라이언트 올때까지 대기
		opnd_cnt=0;
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		//1바이트를 읽는다.
		read(clnt_sock, &opnd_cnt, 1);


		recv_len=0;
		while((opnd_cnt*OPSZ+1)>recv_len)
		//opnd_cnt*OPSZ+1=13이상이 되면 와일문을 빠져나간다.
		{
			recv_cnt=read(clnt_sock, &opinfo[recv_len], BUF_SIZE-1);
			recv_len+=recv_cnt;
		}
		//하나 읽있고 왔으니가 하나를 빼주고 calculate 함수에 넣눈다,
		result=calculate(opnd_cnt, (int*)opinfo, opinfo[recv_len-1]);
		write(clnt_sock, (char*)&result, sizeof(result));

		close(clnt_sock);
	}
	close(serv_sock);
	return 0;
}

int calculate(int opnum, int opnds[], char op)
{
	int result=opnds[0], i;

	switch(op)
	{
	case '+':
		for(i=1; i<opnum; i++) result+=opnds[i];
		break;
	case '-':
		for(i=1; i<opnum; i++) result-=opnds[i];
		break;
	case '*':
		for(i=1; i<opnum; i++) result*=opnds[i];
		break;
	}
	return result;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
