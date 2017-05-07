

#ifndef _SYNC_H
#define _SYNC_H
#include "Global.h"

using namespace std;

class Sync{
    public:
        Sync();
        void Process();
        StatusTypeDef Connect();
        void Close();
    private:
        int socketId;

};
#endif