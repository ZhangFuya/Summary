#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MaxCount 10

/***********************************************************************************
* 行输入输出
* fgets(str, MaxCount, fp)
******fgets读数据最后一位是\0，因此它实际读回的最大数据长度为 MaxCount - 1
* fputs(str, fp)
*************************************************************************************/
//int main(int argc, char const *argv[]) {
//	FILE* fp = fopen("./test.txt", "w");
//	//两种不同的类型导致写入文件的数据不同
//	//const char* buff[10] = {'a', 'b', 'c'};
//	char* buff = "abcdefg\n";
//	fputs(buff, fp);
//	fputs(buff, fp);
//	fclose(fp);
//	fp = NULL;
//
//	char str[MaxCount];
//	//char* str = "";
//	FILE* fp1 = fopen("./test1.txt", "r");
//	if (fp1 == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fgets(str, MaxCount, fp1);
//	printf("%s", str);
//	fclose(fp1);
//	fp1 = NULL;
//
//	getchar();
//	return 0;
//}


/***********************************************************************************
* 行输入输出与 stdin、stdout
* stdin标准输入、stdout标准输出作为特殊文件，读写方式却未发生改变。
*************************************************************************************/
//int main(int argc, char const *argv[]) {
//	char buff[MaxCount];
//	fgets(buff, MaxCount, stdin);
//	char* str = (char*)buff;
//	fputs(str, stdout);
//	//getchar(); //getchar暂停失效，因为程序中有多余的字符
//	system("pause");
//	return 0;
//}

/***********************************************************************************
* 格式化输入输出
* fscanf(fp, format)
* fprintf(fp, format)
*************************************************************************************/
//int main(int argc, char const *argv[]) {
//	struct S {
//		char arr[MaxCount];
//		int num;
//		double dou;
//	};
//
//	//struct S s = { "abcdef", 10, 5.5 };
//	//FILE* fp = fopen("./test.txt", "w");
//	//fprintf(fp, "%s\t%d\t%lf", s.arr, s.num, s.dou);
//	//fclose(fp);
//	//fp = NULL;
//
//	struct S s1 = { 0 };
//	FILE* fp = fopen("./test.txt", "r");
//	if (fp == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fscanf(fp, "%s%d%lf", s1.arr, &(s1.num), &(s1.dou));
//	printf("%s\t%d\t%lf", s1.arr, s1.num, s1.dou);
//	fclose(fp);
//	fp = NULL;
//
//	getchar();
//	return;
//}

/***********************************************************************************
* 格式化输入输出与stdin、stdout
* fprintf(stdout, "%s\t%d\t%lf", s.arr, s.num, s.dou); 引出C语言中非常重要的一个函数 print
* fscanf(stdin, "%s%d%lf", s.arr, &(s.num), &(s.dou)); 引出C语言中另一个非常重要的函数 scanf
*************************************************************************************/
//int main(int argc, char const *argv[]) {
//	struct S {
//		char arr[MaxCount];
//		int num;
//		double dou;
//	};
//
//	struct S s = { "abcdef", 10, 5.5 };
//	//fprintf(stdout, "%s\t%d\t%lf", s.arr, s.num, s.dou);
//	fscanf(stdin, "%s%d%lf", s.arr, &(s.num), &(s.dou));
//	printf("%s\t%d\t%lf", s.arr, s.num, s.dou);
//	system("pause");
//	return;
//}


/***********************************************************************************
* 二进制形式读写文件
* fread(*desBuff, size_t elementSize, size_t elementCount, fp)
* fwrite(*srcBuff, size_t elementSize, size_t elementCount, fp)
*************************************************************************************/
//int main(int argc, char const *argv[]) {
//	struct S {
//		//char arr[MaxCount];
//		char* arr;
//		int num;
//		double dou;
//	};
//
//	struct S s = { "abcdef", 10, 5.5 };
//
//	char buff[MaxCount * 10];
//	FILE* fp = fopen("./test.txt", "wb");
//	fwrite((void*)(&s), sizeof(struct S), 1, fp);
//	fclose(fp);
//
//	fp = fopen("./test.txt", "rb");
//	if (fp == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fread((void*)(&s), sizeof(struct S), 1, fp);
//	printf("%s\t%d\t%f\n", s.arr, s.num, s.dou);
//	fp = NULL;
//
//
//	system("pause");
//	return;
//}

/***********************************************************************************
* 对比 scanf、fscanf、sscanf
* printf、fprintf、sprintf
* scanf---针对标准输入的格式化输入语句
* fscanf--针对所有输入流的格式化输入语句
* sscanf--从字符串中读一个格式化的数据(提取)
* sprintf-将格式化的数据写到一个字符串中(拼串)
* printf--针对标准输出的格式化输出语句
* fprintf-针对所有输出流的格式化输出语句
*************************************************************************************/

/***********************************************************************************
* 指定位置的文件读写
* fseek(fp, offset, SEEK_SET)
* ftell(fp)
*************************************************************************************/
//int main(int argc, char const *argv[]) {
//	FILE* fp = fopen("./test.txt", "r");
//	if (!fp) {
//		perror("fopen");
//		return -1;
//	}
//	int ch = fgetc(fp);
//	printf("%c  ", ch);
//	ch = fgetc(fp);
//	printf("%c  ", ch);
//
//	//使用getc/fputc每次只能顺序向后读/写一个字符，使用fseek可以打破读写位置
//	fseek(fp, 1, SEEK_CUR);
//	char buff[MaxCount] = { 0 };
//	fgets(buff, MaxCount, fp);
//	printf("%s  ", buff);
//	fseek(fp, 0, SEEK_SET);
//	fgets(buff, MaxCount, fp);
//	printf("%s  ", buff);
//
//	fclose(fp);
//	fp = NULL; 
//	system("pause");
//	return 0;
//}