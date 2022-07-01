` sqlite3_exec(db, sql, callback, para, errmsg)`

```
sqlite3* db, /* An open database */   

const char* sql, /* SQL to be evaluated */ 

(int*)callback(void* para,int columnCount,char** columnValue,char** columnName), 
/* Callback function */ 

void* para, /* 1st argument to callback */  

char** errmsg /* Error msg written here */
```
其他的参数没什么好说的，主要就是说一下 callback 这个回调函数
先清楚回调函数的作用：
回调函数主要用于：对查询到的结果进行处理。因此非select语句不用调用回调函数，直接写为NULL。
再说回调函数的使用：
回调函数callback的参数：
- para  一个void类型的参数，主要作用就是显示字段名(列名),如果不需要显示列名，可直接设置为NULL
- columnCount  一个int类型，用于表示列数
- cloumnValue   得到的列值
- cloumnName  列名
你可能会奇怪：select查询到的结果都给columnValue，那要怎么取出来呢？？
在这之前要清楚一个问题：回调函数的调用。
回调函数得到一行调用一次(当然这一行可能为空)。每次传给回调函数的值类似于 key1=Columndata1, key2=Columndata2......。每次得到的值都是这种字段名=字段值的格式，因此想要字段名只输出一次，就需要使用一定的标识。因此每次得到一行callback就会调用一次。所以这个标识，一定不能随着callback每次调用而初始化。因此对这个标识我们一般采用这两种做法：1.在callback中定义一个静态变量，  2. 使用sqlite3_exec中的para给callback传递一个参数，在地址传递过程中para的值就会发生改变。
```
示例代码：
int callback(void* para, int columnCount, char** columnValue, char** columnName){
	int* data = (int *)para;
	if(*data == 1){
		*data = 0;      //对para进行修改，保证下次调用para时不再执行本段代码
		for(int i = 0; i < columnCount; i++){
			printf("%s | ",columnName[i]);     //输出字段名
		}
		printf("\n");
	}

	for(int i = 0; i < columnCount; i++){
		printf("%s | ",columnValue[i]);    //输出列值	
	}
	printf("\n");

	//因为para已经发生改变，所以第二次输出时不会输出字段名
}

sqlite3_exec(db,sql,callback,(void*)data,&errmsg);
//(void *)data  是为了保证数据的一致性(callback定义的时候需要将)
```