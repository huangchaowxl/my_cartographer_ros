#include <iostream>
#include <list>

using namespace std;
#define MAX 3

const int CAP=30;//最大容量
const int box[MAX]={10,15,20};//三个箱子
int main()
{
    int temp=0,level=-1,best=0;
    int curVal=0,parentVal=0,expectVal=0;
    list<int> queue;
    queue.push_back(-1);//-1表示一层
    queue.push_back(parentVal);
    do
    {
        parentVal=queue.front(); //first in first out
        cout<<"parentVal : "<<parentVal<<endl;
        queue.pop_front(); //按照FIFO取出第一个元素，并且删除
        if(parentVal!=-1)
        {
            //left child
            curVal=parentVal+box[level]; //提高效率的一方面
            if(curVal>best&&curVal<=CAP)//边界条件 记录一个最大值 并且条件限定在CAP之内， 不满足条件的剪枝
            {
                best=curVal;
                std::cout<<"bestvalue : "<<best<<endl;
                //最后一层节点不加入队列
                if(level<MAX-1)
                {
                    queue.push_back(curVal);
                }
            }

            //right child
            temp = 0;
            curVal=parentVal;
            cout<<"curval : "<<curVal<<"level : "<<level<<endl;
            for(int i=level+1;i<MAX;i++)
            {
                temp+=box[i];
            }
            expectVal=curVal+temp; //期望值为不加上当前level的值， 剩下的可能最大的值，提高效率的第二个方面
           std::cout<<"expect : "<<expectVal<<endl;
            //预计最大值若大于目前最佳值，则加入队列；否则不加入，即剪枝
            if(expectVal>best&&level<MAX-1)
            {
                queue.push_back(curVal);
            }
            for(list<int>::iterator ite = queue.begin(); ite != queue.end(); ite++)
                {
                    std::cout<<" "<<*ite<<endl;
                }

        }
        else//处理层次问题，加入层结束标志，进入下一层
        {
            if(level<MAX-1)
            {
                queue.push_back(-1);
            }
            level++;
        }

    }while(level!=MAX&&queue.empty()!=true);//到最后一层或者是队列为空结束

    std::cout<<"final_best : "<<best<<endl;
    //system("pause");
    return 0;
}
