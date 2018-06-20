
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string>
#include <sstream>
#include <pthread.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "glog/logging.h"
using namespace std;

ofstream outfile;
int main(int argc,char* argv[])
{

    using uint16 = uint16_t;
    time_t t = time(0);
    char ch[32];

    strftime(ch, sizeof(ch), "%Y_%m_%d %H_%M_%S", localtime(&t));

    std::vector<uint16> cells_(200);
    string v_name;
    v_name=ch;
    v_name="/home/wxl/ros_slam/ctakin_ws/src/cartographer_ros/my_package/src/"+v_name+".txt";
    outfile.open(v_name);
    for(auto i=0;i<10;i++)
       {
           cells_.at(i)=i;
           outfile<<cells_.at(i)<<" ";
       }

       outfile.close();

    return 0;
}
















