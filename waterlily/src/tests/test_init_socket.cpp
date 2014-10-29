#include <iostream>
#include "net/NetHandler.h"
#include "class/RequestQueue.h"
#include "cfg/Config.h"
using namespace std;
Config config;
int main()
{
    config.setBacklog(10);
    config.setAddress("192.168.1.118");
    config.setListenPort(2048);
    config.readCfgFile("/home/jay2014/waterlily/src/cfg/waterlily.cfg");
    RequestQueue * req;
    NetHandler nethandler(req);
    //nethandler.test();
    nethandler.run();
    return 0;
}
