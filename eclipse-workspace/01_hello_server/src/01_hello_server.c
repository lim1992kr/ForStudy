#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main (int argc, char *argv[])   //argc 는 뒤에오는 거 갯수 *argv 뒤에 오는 자료.
{

	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";

	if(argc != 2)
	{
			printf("usage : %s <port>\n", argv[0]);
			exit(1);
	}
	//뒤에 오는거 갯수가 두개가 아니면 포트번호 쓰라고 알려준다.

	serv_sock = socket(PF_INET, SOCK_STREAM, 0); //소캣을 생성한다.
	if(serv_sock == -1)  //잘못실행되면 보통 -1값 대부분의 마이너스값은 에러코드
			error_handling("socket() error");
	//파일을 열면 파일의 디스크립터 값을 가지고 가서 오픈한다.


	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//INADDR_ANY는 허용하는 IP, 모든 아이피를 허용. 여기를 바꾸면 특정아이피만 들어올수있게 허락할수있다.
	//htonl host to network long 아이피 주소니까 롱형으로 보낸다. 빅엔디언으로 바꺼주는 함수
	serv_addr.sin_port = htons(atoi(argv[1]));
	//a to i 는 문자열을 숫자로 바꾸고 host to network short로 한다. 포트번호.

	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
		error_handling("bind() error");
	//bind = ip와 포트번호를 할당한다.

	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if(clnt_sock== -1)
		error_handling("accept() error");
	//여기 윗부분은 변하지 않는다.

	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);
	close(serv_sock);

	return 0;

}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}
