#include <iostream>
#include "string"
using namespace std;

class Student;
bool SortByCondition(Student stu[],const int &len,const char &conditon);//排序
void SaveToFile(Student stu[],int num);
void ReadFromFile(Student stu[],int num);
int GetNumberFromFile();
char Menu();
char SortMenu();

class Score
{
public:
    Score(){ english = 0, math = 0; computer = 0; }
    Score(float eng, float mat, float com) :english(eng), math(mat), computer(com){}
    void InputScore()
    {
        cout << "enter english  score:";
        cin>> english;
        cout << "enter math     score:";
        cin >> math;
        cout << "enter computer score:";
        cin >> computer;
    }
    void outputScore()
    {
        cout << english << "\t" << math << "\t" << computer << "\t";
    }
    float ScoreSum()
    {
        return (math + english + computer);
    }
    void swapScore(Score &scor)//对象交换数据
    {
        float ftmp = english;
        english = scor.english;
        scor.english = ftmp;

        ftmp = math;
        math = scor.math;
        scor.math = ftmp;

        ftmp = computer;
        computer = scor.computer;
        scor.computer = ftmp;
    }
private:
    float english;
    float math;
    float computer;
};

class Birthday
{
public:
    Birthday(){ year = 0; month = 0; day = 0; }
    Birthday(int ye, int mon, int da) :year(ye), month(mon), day(da){}
    void inputBirthday()
    {
        cout << "enter birthday like \"2014 05 01\":" << endl;
        cin >> year >> month >> day;
    }
    void outputBirthday()
    {
        cout << year << "\-" << month << "\-" << day << "\t";
    }
    void swapBirthday(Birthday &bir)//对象交换数据
    {
        int itmp = year;
        year = bir.year;
        bir.year = itmp;

        itmp = month;
        month = bir.month;
        bir.month = itmp;

        itmp = day;
        day = bir.day;
        bir.day = itmp;
    }
private:
    int year;
    int month;
    int day;
};


class Student
{
public:
    Student() :score(), birthday(){}
    ~Student(){}
    void InputInfo();
    void OutPutInfo();
    void ShowInfo();
    bool CreditManage();

    char *getNum(){ return num; }
    char *getName(){ return name; }
    bool getSex(){ return sex; }
    float GetCredit(){ return credit; }
    void swapStudent(Student &stu);//对象交换数据

    void put_out()
    {
        cout<<"sex : "<<sex<<endl;
    }
private:
    char  num[10];
    char name[20];
    bool sex;
    Score score;
    Birthday birthday;
    float credit;
    bool isChanged;
};

