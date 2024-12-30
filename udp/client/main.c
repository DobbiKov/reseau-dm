#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 100
#define MAX 1000
#define PORT 9600

void read_char(char** res, int* res_size){
    int size = 0;
    *res = (char*)malloc(MAX * sizeof(char));
    memset(*res, 0, MAX);
    char c = ' ';
    do{
        c = getchar();
        size++;
        if(size > MAX){
            printf("The message has to be of size 100 chars or less");
            exit(0);
        }
        ( *res )[size-1] = c;
    }while(c != '\n');
    *res_size = size-1;
}

int main(int argc, char *argv[]) {
    char *message = "Hello server!";
    char buf[SIZE];

    //on créé un socket du client qui est une porte (ou api) entre l'application et le protocole de transport
    int sockfd = socket(PF_INET, SOCK_DGRAM, 0);

    //on décrive l'adresse et le port du serveur auquel on veut envoyer un paquet
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &s_addr.sin_addr);
    s_addr.sin_port = htons(PORT);

    //on lit un message du terminal et obtient la longueur du message
    int mess_size = 0;
    printf("Please, write your message:\n");
    read_char(&message, &mess_size);

    //on envoie un message et affiche dans le terminal le nombre de bytes envoyé
    int send_res = sendto(sockfd, message, mess_size, 0, (struct sockaddr*)&s_addr, sizeof(s_addr));
    printf("Bytes sent: %d\n\n", send_res);
    
    //une variable de la longeur de l'addresse de serveur pour souvegarder quand on reçoit une réponse
    unsigned long s_addr_len;
    //on attend une réponse du serveur
    int res_form = recvfrom(sockfd, buf, MAX, MSG_PEEK, (struct sockaddr*)&s_addr, (socklen_t*)&s_addr_len);
    //si l'erreur on le dit
    if(res_form == -1)
    {
        printf("error while getting answer");
    }
    //si le message est vide on le dit
    else if(res_form == 0){
        printf("empty answer");
    }
    //sinon on affiche le message et on finit le programme
    else{
        printf("Answer from server: %s\n", buf);
        printf("Got an answer, finishing the program\n");
    }

    return 0;
}
