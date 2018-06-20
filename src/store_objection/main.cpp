#include "student.h"
#include "fstream"
#include "string"

int main()
{
    Student stu1,stu2;
    stu1.InputInfo();
    fstream outfile("/home/wxl/ros_slam/ctakin_ws/src/cartographer_ros/my_package/src/store_objection/student.txt", ios::app | ios::binary);

    if (!outfile)
            {
                cerr << "open file error!";
            }
    outfile.write((char*)&stu1, sizeof(stu1));
    outfile.close();


    ifstream infile("/home/wxl/ros_slam/ctakin_ws/src/cartographer_ros/my_package/src/store_objection/student.txt", ios::in | ios::binary);


    if (!infile)
              {
                  cout<<"open file error!"<<endl;
                  getchar();
                  //exit(0);
              }
     Student *stu = new Student[0];

     infile.read((char*)&stu[0], sizeof(stu[0]));


     stu->put_out();
    stu->OutPutInfo();
     infile.close();

    getchar();
    return 0;
}


