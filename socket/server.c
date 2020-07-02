#include <stdio.h>
#include <unistd.h> //유닉스에서 제공되는 system call을 쓴다.
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>
#include <pthread.h>

pthread_mutex_t mutex;

int dataSockets[1024];
int count; 


void *handleClient(void *arg)
{
	int dataSocket = *(int *)arg;
	
	int nread;
	char msg[1024];
	while ( ( nread = read(dataSocket, msg, 1024)) != 0 ) {
pthread_mutex_lock(&mutex);
		for (int i = 0; i < count; ++i)
			write(dataSockets[i], msg, nread);
pthread_mutex_unlock(&mutex);
	//읽은데이터의 갯수  1024가 최대 읽을수 있는 데이타 크기,반환되는값 = 읽어오는데이터의 값
	//제대로 실행안되면 -1, 끝을만나면 0 제데로 읽었는지 리턴값을 보고 확인,
		//write all client
	}
	// EOF 
	close(dataSocket);
	return NULL;
	
	//for () {
	//read(dataSocket, ...)
	//write msg to all clients
	//}
}

int main (void)
{
	pthread_mutex_init(&mutex, NULL);
	int servSocket= socket(AF_INET, SOCK_STREAM, 0); //저장되는값은  file descriptor값
	//file descriptor. 소캣생성하면 3이 생기고 4,5,6 올라간다. open하면 file descriptor값이 올라간다.
	//배열의 인덱스다.  0, 1, 2번은 먼저 열려있는것이 사용한다. 
	assert(servSocket != -1);
	
	int option;
	socklen_t optionLen = sizeof(option);
	option = 1;
	setsockopt(servSocket, SOL_SOCKET, SO_REUSEADDR,(void*)&option, optionLen );
	
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //빅엔디언으로 넣어라.
	servAddr.sin_port = htons(7779);
	
	assert( bind(servSocket, (struct sockaddr *) &servAddr, sizeof(struct sockaddr_in)) != -1);
	assert( listen(servSocket, 5) != -1);
	
	listen(servSocket,5);

	for (;;){
		struct sockaddr_in clientAddr;
		int len;
		
		int dataSocket;
		assert((dataSocket = accept(servSocket, (struct sockaddr *)&clientAddr, &len)) != -1);
		printf("client IP : %s\n",inet_ntoa(clientAddr.sin_addr));
		// inet_ntoa 문자열로 바꿔주는 함수.
		// atomic 쪼개지지 않는
pthread_mutex_lock(&mutex);		
		dataSockets[count] = dataSocket;
		++count;
pthread_mutex_unlock(&mutex);	
			
		//create thread for read()/write()
		pthread_t pid;
		pthread_create(&pid, NULL, handleClient, &dataSocket); //p는 포직스
		pthread_detach(pid);	//좀비 쓰레드 방지.
		
	}
	close(servSocket);
	return 0;
}
/*
systme call
유닉스 운영체제에서 제공되는 함수.

API함수 
윈도우즈 환경에서 제공되는 함수.
udp 스트리밍서비스
tcp 일반적.
*/
