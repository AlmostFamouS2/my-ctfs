#include <arpa/inet.h> 
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 


int main(int argc, char* argv[]) 
{
	char number[] = "GET /\n";
    int sock;
    struct sockaddr_in server;
    int buf[1024];

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        fprintf(stderr,"ERRO AO CRIAR O SOCKET\n\n");
        return 1;
    }

    puts("SOCKET CRIADO! \n\n");

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if(argc == 2)
		 server.sin_addr.s_addr = inet_addr(argv[1]);
 	else
	   server.sin_addr.s_addr = inet_addr("172.217.29.110");

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        fprintf(stderr,"ERRO NA CONEXAO COM A PORT 80 ! \n\n");
        close(sock);
        return 1;
    }

    puts("\x1b[32mCONEXAO COM A PORTA 80 ESTABELECIDA ! \n\x1b[0m");

    if(send(sock, &number, sizeof(number), 0) < 0){
        fprintf(stderr,"ERRO NO ENVIO DE DADOS ! \n\n");
        close(sock);
        return 1;
    }

    if(recv(sock, &buf, 1024, 0) < 0){
        fprintf(stderr,"ERRO NO RECEBIMENTO DE PACOTES ! \n\n");
        close(sock);
        return 1;
    }

close(sock);
printf("%s\n\n\n",buf);
return 0;
}
