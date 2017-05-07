#include "Sync.h"
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <iostream>

Sync::Sync(){

}

StatusTypeDef Sync::Connect(){
    StatusTypeDef res;
    struct protoent  *protocol;
    struct sockaddr_in serverInfo;
    
    //Obtient le numéro identifiant le protocol TCP
    protocol = getprotobyname("TCP");
    //Creation de la socket en mode connecté
    socketId = socket(AF_INET,SOCK_STREAM, protocol->p_proto);
    
    if(socketId == -1 ){
        res = STATUS_ERROR;
    }else{
        serverInfo.sin_port = htons(3002);
        serverInfo.sin_family = AF_INET;
        
        if(inet_aton("127.0.0.1", &(serverInfo.sin_addr)) == 0){
            cout << "Adresse IP fausse" << endl;
            return STATUS_ERROR;
        }
       

        if(connect(socketId, (struct sockaddr *)(&serverInfo), sizeof(sockaddr)) == -1){
            res = STATUS_ERROR;
        }else{
            res = STATUS_OK;
        }
    }

    return(res);
}

void Sync::Close(){
    shutdown(socketId, SHUT_RDWR);
    
}

void Sync::Process(){

}