test 可用于检测文件类型或进行整数的比较，**test返回0为真**
test  1 -eq 1; test $?  
输出0
bash -x filename  调试程序

Shell中的运算符和C语言有很大的区别
| 运算符 |   含义   |
|:--:|:--:|
| -eq  |  等于 |
| -gt |  大于 |
|-lt| 小于 |
|-ge|大于或等于 |
| -le | 小于或等于 |
| -ne | 不等于 |


字符串比较运算 
\==    !=    >      <      >=      <=   
-n  长度不为0时为真    -z   长度为0时为真
注意点：使用 -n 或 -z 比较时，$var要加双引号或中括号，即："\$var " 或 [-n $var\]

逻辑运算符、赋值运算符 同其他语言

test 判断文件
|选项|含义|
|:--: | :--: |
| -d | 检查文件是否存在且为目录 |
| -e | 检查文件是否存在 |
| -f | 检查文件是否存在且为文件 |
|-r | 检查文件是否存在且可读 |
|-s | 检查文件是否存在且不为空 |
|-w  | 检查文件是否存在且可写 |
|-x  | 检查文件是否存在且可执行 |
| -o  | 检查文件是否存在并且被当前用户拥有 |
|  -G  |  检查文件是否存在并且默认组为当前用户组 |
| -nt |  file1 -nt file2 file1是否比file2新|
| -ot |  file1 -ot file2 file1是否比file2旧|


if 语法：
if语句以 fi 为结尾
```shell
if [ condition1 ]
	then
		commands1
elif[ condition2 ]
	then
		commands3
else 
	commands2
fi
```

if 的高级应用：
1.  条件符号使用双圆括号，可以在条件中植入数学表达式
举例如下：
```
if( (100 % 3 + 1 > 2) ); then
	echo "yes"
else 
	echo "no"
fi
```
2.  **双中括号中，可以使用通配符**
```
for var in ax  bx  rx rcx
	do
		if[ [ "$var" == r* ] ]
			then
				echo "$var"
		fi
done
```


for 循环语句：
```
for var in value1  value2 ......
	do
		commands
done
```
关于 for 的循环条件：
1. 可使用seq命令(seq是一个计数命令。`seq 1 9` 就是从1 到 9. `seq 9 -3 1`, 每次减3从9数到1)
	for    i    in    \`seq   1    9\`  (从1到9，并将结果赋值给 i)
2. for 循环的循环条件可以使用C语言的语法
	`for ( (a=0,b=9; a<10; a++,b--) )  do  echo $a  $b  done`
3. 使用 break 可以跳出
	break 可以搭配数字使用，表示跳出第几层循环。