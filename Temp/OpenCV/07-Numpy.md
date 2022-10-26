NumCPP是一个经高度优化的数值库。       
图形的处理就是矩阵的处理。
注意一点：NumCPP依赖于Boost，因此要使用NumCPP必须具有Boost库。并且在VS中引入NumCPP必须包含boost的include路径。
NumCPP所在的命令空间为nc，其主要数据结构是 NdArray。

## 使用NumCpp创建矩阵
创建矩阵常用的方式有:        
- 创建数组 NdArray()          
一维数组如： `NdArray<int> nd = {1, 2, 3}`     
二维数组如： `NdArray<int> nd = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };`
大多数情况下创建的多为二位矩阵。    

- 创建全0数组 zeros() / ones      

- 创建全值数组 full()          
- 创建单位数组 identity() / eye()       

## 检索与赋值
## 获取子数组