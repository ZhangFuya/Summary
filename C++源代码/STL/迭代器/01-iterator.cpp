#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main(int argc, char const *argv[]) {
    list<int> base_list_1 = {1, 2, 3, 4, 5, 6};
    reverse_iterator<list<int>::iterator> stl_iterator_1 = base_list_1.rend();

    //就这一句话我决定，非必要不用迭代器类

    return 0;
}
