#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

/* Port local du serveur */
#define PORT 9600
#define BUFF_SIZE 100

int main(int argc, char *argv[]) {

    char *message = "Hello Client!";
    char buf[BUFF_SIZE];

    //on créé un socket qui une porte entre protocole de transport et l'application
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    //on décrive l'adresse et le port de notre application
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &s_addr.sin_addr);
    s_addr.sin_port = htons(PORT);


    //on fait notre serveur écouter sur l'adresse et le porte donné
    int bind_res = bind(sockfd, (struct sockaddr*)&s_addr, sizeof(s_addr));

    //on crée un structure et la taille pour que quand on récoive un message on souvegarde ici l'adresse et le porte du client
    struct sockaddr_in c_addr;
    int c_addr_len = sizeof(c_addr);
    printf("The server has been started on port: %d\n", PORT);
    while(1){
        //on reçoit un message du client
        int res_form = recvfrom(sockfd, buf, BUFF_SIZE, MSG_PEEK, (struct sockaddr*)&c_addr, (socklen_t*)&c_addr_len);
        //si un erreur on l'affiche
        if(res_form == -1)
        {
            printf("error while getting mess");
            return 0;
        }
        //si le message est vide on l'affiche
        else if(res_form == 0){
            printf("empty message");
            return 0;
        }
        else{
            //sinon, alors on affiche le contenue du message et envoie au client qu'on a réçu le message
            printf("Mess: %s\n", buf);
            char* mess_back = "I got your message, thanks!";
            int send_back = sendto(sockfd, mess_back, BUFF_SIZE, 0, (struct sockaddr*)&c_addr, sizeof(c_addr));
            return 0;
        }

    }

    return 0;
}
