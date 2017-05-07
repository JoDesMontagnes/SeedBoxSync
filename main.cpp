#include <iostream>
#include "Sync.h"
#include "Global.h"

using namespace std;

int main(void){
    Sync worker;

    

    cout << "Connexion au serveur distant ... ";
    if(worker.Connect() == STATUS_OK){
        cout << "OK" << endl;
    }else{
        cout << "NOK" << endl;
    }

    worker.Close();
    return(0);
}