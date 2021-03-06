**我认为STL(标准模板库)就是对常见数据结构和算法的再封装，以便开发者能更加灵活的使用数据结构和常用算法**            
通常认为，STL由容器、算法、迭代器、函数对象、适配器、内存分配器 这 6 部分构成           
   
## 容器           
简单理解**容器，他就是封装数据结构的模板类**            
STL中的容器分为三大类，分别是：序列容器、关联容器(排序容器) 以及 无序关联式容器(哈希容器)              
注意两点： 1. 容器的分类直接决定了容器内元素的存储方式。序列容器中的元素顺序由数据进入容器的位置决定；排序容器中元素的位置由元素键值的大小决定；而哈希容器元素的位置是由元素的哈希值决定。            
2.因容器的存储方式不同，所以使用不同的容器进行相同的操作，所需要的开销完全不同，因此在使用容器之前应当对使用何类型的容器进行充分考虑             

#### 序列容器           
序列容器主要包括：array数组容器、 vector向量容器、list列表容器、deque双端队列容器 以及 forward_list 列表容器             
在五个序列容器中，array容器 和 vector容器 是以数组实现的。不同的是 array 是对普通数组进行的封装，而 vector 是对动态数组进行的封装。这就导致了 array 是不可变长，而 vector 是可变内存长度的数组。           
list容器 和 forward_list容器 是以链表的形式实现的。不同的是 list 是双链链表实现，而 forward_list 是单链链表实现的。因此在选用时应优先选择 forward_list列表容器              
deque双端队列容器，可以理解为双向队列，能快速的在队列两端进行添加、删除操作。因此当需要频繁在数列前后添加或删除元素时优先考虑 deque 容器。        
```c++
序列容器主要供选择就两个 vector 以及 list。array勉强算是吧
说一下 list 与 vecto 的不同
1. list 可以使用 sort 对容器内的元素进行排序。而 vector 默认不支持排序
2. list 没有 at 函数，也未重载操作符 []
3. list的内置迭代器无法进行 + 运算。 stl_list.begin() + 3 是错的
vector 与 list 的选取一般情况下相差并不大，但需要进行排序操作时选择list，对空间要求比较高时选择vector
```

#### 关联容器
排序容器 | 关联式容器 以键值对的形式保存数据。因此关联式容器在查找、访问、插入和删除指定元素的效率会高一些。            
哈希容器 | 无序关联式容器 也是以键值对的形式保存数据。但哈希容器不会以键值对容器内的元素进行排序，也因此无序关联式容器在查找指定元素时会有更高的效率，遍历却极为不足。           
造成关联式容器 和 无序容器 差异的原因是两者在底层的实现。关联容器底层采用红黑树结构进行存储，而无序容器底层采用的是哈希表的存储结构。由此也就导致了无序容器具有更高的查找效率。           
STL中关联式容器主要包括： map、multimap、set 以及 multiset 这4种。           
关于这四个关联式容器其实很好理解：            
因为关联式容器是以键值对的形式存储数据，所以 键 和 值 的关系就直接决定了这四个容器的构造。 是否允许创建 相同的 “键”， 允许使用 multixxx ，不允许不使用 multi。键值是否保持一致，**键值保持一致使用set容器，键值不必保持一致就使用 map容器**               
无序关联式容器，在所有的关联式容器的基础上加上 `unorder_` 前缀，就构成了无序关联式容器。所以无序关联容器在使用上和关联式容器只有细微的差别。在选择上如果如果涉及大量遍历操作优先使用无序关联容器即可。           



## (容器)适配器
**所谓的容器适配器就是在容器的基础上进行的再封装，以使其满足某些特定场景的需求**          
STL中容器适配器有三个,分别是：stack、queue 和 priority_queue。            
stack    --    栈    --    先进后出           
queue  --   队列  --    先进先出           
priority_queue   --    排序队列  --    权重大的先出           

容器适配器必须要清楚以下几点：        
1. 容器适配器是为了满足某一特定的场景进行设计的。          
这特定的场景也就和适配器的名字一样 stack--实现栈操作 queue--实现队列操作             
2. 容器适配器没有内置迭代器，因此要对容器适配器进行遍历就需要逐个移除              
3. 容器适配器是由 序列容器 进行再封装的，因此构建容器适配器的对象一定是一个序列容器        
4. 在容器适配器中使用的容器必须是满足一定条件的(实现相应方法的实现，不必探究)只需要知道stack 只能由vector、deque、list进行构建， queue 只能由 deque、list进行构建 priority_queue只能由deque、vector进行构建。        

```c++
priority_queue队列默认的入队顺序          
priority_queue 队列创建时，默认指定std::less<T>入队(最大的元素排在队列头,其他元素位置与插入顺序有关。)            
入队元素：3,1,2,6,4,5，priority_queue的入队顺序是               
首先: 3入队, 1，2入队比3小，所以1，2排在3后边(只找最大的，所以1，2不排序)              
3  1  2         
然后：6入队比3大，所以6排在对列头       
6 3 1 2
之后：4，5都没6大排在队列尾
6 3 1 2 4 5
出队： 最大的出队后剩余选出最大的放在队列头
5 3 1 2 4
4 3 1 2
```

```c++
说一下 再封装 这个事情。
为什么要进行再封装，究其原因主要是一点：方便。
为什么会有人感觉再封装的类(事物)使用起来极为不顺手，严重影响使用体验呢？
我们以 unsigned int 为例，来说明这个问题。
typedef unsigned int uint;
当你要使用一个整型数据时，你用 int 和 unsigned int 有差别吗？
肯定是有的，但要说非极端条件下，如一个人的年龄，班级人数等条件下 两者是不是都可以使用。
虽然两者都可以使用，但使用 unsigned int 所表现的信息较之 int 更加丰富，也更加利于我们理解一个变量。
如果我们每次都写 unsigned int，这对于程序开发人员简直是灾难性的。因为 unsigned int 是两个单词(这极易导致书写时候心态的波动)，所以绝大多数程序开发人员会使用 uint 代替 unsigned int 。虽然两者一摸一样。
言归正传，我们说到的再封装也是这个思想。在原有的类上进行多次封装，不仅能很好的使用已有的类型，还可以根据特定的场景对功能进行拓展。因此再封装应该是每位开发人员应该具备的能力。
```





#### 迭代器

迭代器实质上就是指针            
基础的迭代器可以分为5类：          
输入、输出迭代器           
正向迭代器(只能进行 ++、 \*、 == 以及 != 运算)          
双向迭代器(可以进行 -- 运算)           
随机访问迭代器(可以进行 +i、 -i、 \[ \] 运算)          

**迭代器适配器可以理解为基础迭代器的“升级版”**。              
常见的迭代器适配器可以分为：反向迭代器(reverse_iterator)、插入型迭代器(insert_iterator)、流迭代器/缓冲区迭代器、移动迭代器(move_iterator)      
反向迭代器：通常用于遍历          
插入型迭代器：通常用于插入元素           
移动迭代器：可以将一块区域中的元素移动到另一块区域             
 
使用迭代器的注意事项：        
1. 迭代器适配器决定了声明的迭代器具有什么功能，而不关心迭代器适配器内部的基础迭代器是随机访问迭代器还是双向迭代器         
2. 迭代器创建时<T>的写法，决定了迭代器类型`reverse_iterator<vector<int>::iterator> my_reiter; //基础迭代器是指向int类型vector容器的随机访问迭代器`         
- 反向迭代器         
    1. 反向迭代器可以实现除forward_list之外任意容器的随机访问迭代器           
    2. 正常的迭代器开始位置是第一个元素结束位置是最后一个元素后边。反向迭代器的开始位置是最后一个元素，结束位置是第一个元素前边         
- 插入迭代器          
    插入迭代器可以选择 back_insert_xxx、 front_insert_xxx、 insert_xxx 但是必须要保证迭代器作用的的容器有对应的 push_front、push_back 或者insert方法。           

对于迭代器适配器，STL还提供了几个辅助函数：           
- advace(iterator, n)              
将迭代器向前或向后移动n个位置(n可以为正，也可以为负)。advance不做越界处理，因此n的值过大很可能导致程序崩溃         
- distance(first, last)           
计算两个迭代器之间的距离          
- begin(container)      
返回指向容器第一个元素的迭代器          
- end(container)          
返回指向容器最后一个元素之后的迭代器          
- prev(iterator)               
返回指向迭代器前一个位置的迭代器，prev的参数至少是一个双向迭代器            
- next(iterator)             
返回指向迭代器下一个位置的迭代器，next的参数至少是一个前向迭代器            