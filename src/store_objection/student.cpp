#include "student.h"
#include "iostream"
#include "fstream"
#include <string.h>
using namespace std;


void Student::InputInfo()
{
    cout << "enter number(字符串)";
    cin >> num;
    cout << "enter name(字符串)";
    cin >> name;
    cout << "enter sex(0表示女，1表示男)";
    cin >> sex;
    score.InputScore();
    birthday.inputBirthday();
    credit = score.ScoreSum() / 10;//计算得出学分
}

void Student::OutPutInfo()
{
    cout << num << "\t" << name << "\t" << sex << "\t";
    //score.outputScore();
    birthday.outputBirthday();
    cout << credit << endl;
}

char Menu()
{
    //system("cls");
    cout << "******************************************" << endl;
    cout << "***welcome to student management system***" << endl;
    cout << "******************************************" << endl;
    cout << "please choose the number below:" << endl;
    cout << "1--成绩录入" << endl;
    cout << "2--成绩显示" << endl;
    cout << "3--排序管理" << endl;
    cout << "4--学分管理" << endl;
    cout << "0--退出" << endl;
    char ch = getchar();
    return ch;
}

void Student::swapStudent(Student &stu)
{
  /*  char tmp[10];
    strcpy_s(tmp, num);
    strcpy_s(num, stu.num);
    strcpy_s(stu.num, tmp);

    char nam[20];
    strcpy_s(nam, name);
    strcpy_s(name, stu.name);
    strcpy_s(stu.name, nam);

    bool btmp = sex;
    sex = stu.sex;
    stu.sex = btmp;

    score.swapScore(stu.score);
    birthday.swapBirthday(stu.birthday);

    float ftmp = credit;
    credit = stu.credit;
    stu.credit = ftmp;

    btmp = isChanged;
    isChanged = stu.isChanged;
    stu.isChanged = btmp;*/

}

char SortMenu()
{
    cout << "选择要进行排序的方式：";
    cout << "1--学号" << endl;
    cout << "2--姓名" << endl;
    cout << "3--性别" << endl;
    cout << "4--学分" << endl;
    cout << "5--返回上一级" << endl;
    getchar();
    char ch = getchar();
    return ch;
}

bool SortByCondition(Student stu[], const int &len, const char &conditon)//排序
{
    char tmp = conditon;
    int length = len;
    switch (tmp)
    {
    case '1'://学号
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length-i-1; j++)
            {
                if (strcmp((stu[j].getNum()), stu[j + 1].getNum()) > 0)
                //if (stu[j].getName().compare(stu[j+1].getName()) > 0)
                {
                    //compare(stu[j].getName(),stu[j+1].getName());
                    //stu[j].getName().compare(stu[j+1].getName());
                    stu[j].swapStudent(stu[j + 1]);
                }
            }
        }
        cout << "学号降序排列" << endl;
        for (int i = 0; i < length; i++)
        {
            stu[i].OutPutInfo();
//             if (i % 10 == 0)
//             {
//                 cout << "按下任意键继续显示" << endl;
//                 getchar();
//             }
        }
        getchar();
    }
        break;
    case '2'://姓名
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - i - 1; j++)
            {
                if (strcmp(stu[j].getName(), stu[j + 1].getName()) < 0)
                //if (stu[j].getNum().compare(stu[j+1].getNum()) > 0)
                {
                    stu[j].swapStudent(stu[j + 1]);
                }
            }
        }
        cout << "姓名降序排列" << endl;

        for (int i = 0; i < length; i++)
        {
            stu[i].OutPutInfo();
//             if (i % 10 == 0)
//             {
//                 cout << "按下任意键继续显示" << endl;
//                 getchar();
//             }
        }
        getchar();
    }
        break;
    case '3'://性别
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - i - 1; j++)
            {
                if (stu[j].getSex() < stu[j + 1].getSex())
                {
                    stu[j].swapStudent(stu[j + 1]);
                }
            }
        }
            cout << "性别降序排列" << endl;
        for (int i = 0; i < length; i++)
        {
            stu[i].OutPutInfo();
//             if (i % 10 == 0)
//             {
//                 cout << "按下任意键继续显示" << endl;
//                 getchar();
//             }
        }
        getchar();
    }
        break;

    case '4'://学分
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - i - 1; j++)
            {
                if (stu[j].GetCredit() < stu[j + 1].GetCredit())
                {
                    stu[j].swapStudent(stu[j + 1]);
                }
            }
        }
        cout << "学分降序排列" << endl;
        for (int i = 0; i < length; i++)
        {
            stu[i].OutPutInfo();
//             if (i % 10 == 0)
//             {
//                 cout << "按下任意键继续显示" << endl;
//                 getchar();
//             }
        }
        getchar();
    }
        break;
    default:
        break;
    }
    return true;
}

int GetNumberFromFile()
{
    int count = 0;//对象个数，即学生人数
    fstream infile("e:\\student.txt",ios::in | ios::binary);
    if (!infile)
    {
        cout<<"open file error!"<<endl;
        getchar();
        exit(0);
    }
    Student stu;
    while (infile.read((char*)&stu,sizeof(stu)))
    {
        count++;
    }
    infile.close();
    return count;
}


