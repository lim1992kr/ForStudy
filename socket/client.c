#include <stdio.h>
#include <string.h>
#include <unistd.h> //유닉스에서 제공되는 system call을 쓴다.
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <assert.h>

void *recvMsg(void *arg)
{
	int clientSocket = *(int *)arg;
	
	for(;;){
		char msg[1024];
		int nread = read(clientSocket, msg, 1024);
		msg[nread] = '\0';
		fputs(msg, stdout);
		//실제로 읽은 데이터의 갯수를 체크.
	}
	return NULL;
}

int main (void)
{
	int clientSocket = socket(AF_INET, SOCK_STREAM,0);
	assert(clientSocket != -1);
	
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(7779);
	
	assert( connect(clientSocket, (struct sockaddr*)&servAddr, sizeof(struct sockaddr_in))!= -1);

	//creadte thread for--> print!
	pthread_t tid;
	void *result;
	pthread_create(&tid, NULL, recvMsg, &clientSocket);	
	//pthread_join(tid, &result);	
			
	for(;;) {
		char msg[1024];
		fgets(msg, 1024, stdin); //'\n' 0까지 들어간다.
		if (strcmp(msg,"/q\n")==0||strcmp(msg,"/q\n")==0)
			break;
		write(clientSocket, msg, strlen(msg));		
		}
	
	close(clientSocket);
	return 0;
}
