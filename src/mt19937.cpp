
// mersenne_twister_engine constructor
#include <iostream>
#include <chrono>
#include <random>
#include <string>
 #include <typeinfo>
 #include <fstream>
using namespace std;
class my_class{


public :
        my_class(int a);



private :

    int x;
};

my_class::my_class(int a)
        {
            x=a;
        };
int main()
{
    my_class & num;
    my_class ob(1);
	return 0;
}

