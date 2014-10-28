#include <iostream>
#include "net/NetHandler.h"
#include "cfg/Config.h"
using namespace std;
Config config;
int main()
{
    config.setBacklog(10);
    NetHandler nethandler;
    nethandler.test();
    return 0;
}
