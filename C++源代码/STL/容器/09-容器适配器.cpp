// 容器适配器是为了满足某一特定的使用场景进行设计的。
// 这特定的场景也就和适配器的名字一样 stack--实现栈操作 queue--实现队列操作
// 注意： 1.容器适配器没有内置迭代器，因此要对容器适配器进行遍历就必须移除一个元素后进行下一个元素的输出
// 2. 容器适配器是由 序列容器 进行再封装的。所以构建容器适配器的对象一定是一个序列容器
// 3. 在容器适配器中使用的容器必须是满足一定条件的(不列举)。
// 因此需要知道 stack 只能由vector、deque、list进行构建， queue 只能由 deque、list进行构建 priority_queue只能由deque、vector进行构建

#include<iostream>
#include<stack>
#include<deque>
#include<list>
using namespace std;

int main(int argc, char const *argv[])
{
    //stack的初始化
    stack<int> stl_stack_1;

    deque<int> temp_deque_1 {1, 2, 3, 4, 5, 6};
    stack<int> stl_stack_2 (temp_deque_1);

    //指定stack的构建类型
    list<int> temp_list_1 {1, 2, 3, 4};
    stack<int, list<int>> stl_stack_3(temp_list_1);

    //当容器适配器中的元素类型，以及构建容器适配器的序列容器类型相同，可由一个容器适配器构建另一个
    stack<int, list<int>> stl_stack_4(stl_stack_3);

    //容器适配器中的方法很简单，为空(empty)、大小(size)、入(push)、出(pop)、顶/底(top、队列中是 front 和 back)
    //容器适配器的遍历必须先移除

    stl_stack_1.push(1);
    stl_stack_1.push(2);
    stl_stack_1.push(3);
    stl_stack_1.push(4);
    stl_stack_1.push(5);
    stl_stack_1.push(6);

    while (!stl_stack_1.empty())
    {
        cout << stl_stack_1.top() << " ";
        stl_stack_1.pop();
    }
    cout << endl;

    // 队列也就是一个入队，出队操作。想要遍历也必须先移除出去
    // 排序队列知道，队列内的元素是怎么进的，怎么出的就好
    //priority_queue的入队顺序： 3,1,2,6,4,5
    // 首先: 3入队, 1，2入队比3小，所以1，2排在3后边(只找最大的，所以1，2不排序)  
    //3  1  2
    // 然后：6入队比3大，所以6排在对列头   
    //6 3 1 2
    // 之后：4，5都没6大排在队列尾
    //6 3 1 2 4 5
    //出队： 最大的出队后剩余选出最大的放在队列头
    //5 3 1 2 4
    //4 3 1 2

    return 0;
}
