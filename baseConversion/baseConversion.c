/*
输入一个长整型数
将其转换为十六进制，以字符串形式输出
（提示：可以定义char s[]="0123456789ABCDEF"以帮助输出十六进制字符）
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define RAGE16 "0123456789ABCDEF"
#define RAGE8 "01234567"
#define RAGE2 "01"
int showMenu(int *num);
void baseChange(int base);
int main(){
	int base,i=1;
	char choice[32];
	base = showMenu(&i);
	while(base!=0){
		switch(base){
			case 2:
				baseChange(base);
				break;
			case 8:
				baseChange(base);
				break;
			case 16:
				baseChange(base);
				break;
			default:
				printf("*--无该种换算方式，请按选项重新输入！--*\n");
				break;
		}
		base = showMenu(&i);
	}
	system("pause");
return 0;
}
int showMenu(int *num){
	int base;
	printf("\n\n");
	printf("历史记录：这是第%d次查询\n\n",(*num)++);
	printf("用户须知：本进制转换器暂时只支持输入10进制结构转换！\n\n");
	printf("     --- 》---  Base Conversion  ---《 ---     \n\n");
	printf("---请在下面的进制转换中做出自己的选择：---\n\n");
	printf("       10->2       10->8      10->16       \n\n");
	printf("==========================================\n\n");
	printf("Please input your choice：\n");
	scanf("%d",&base);
	printf("\n");
	return base;
}
void baseChange(int base){
	int i=0,j;
	long int num;
	char temp[32];
	char array[32];
	char s[32];
	if(base==2){
		strcpy(s,RAGE2);
	}else if(base==8){
		strcpy(s,RAGE8);
	}else{
		strcpy(s,RAGE16);
	}

	printf("Please input what you want to be conversed：");
	scanf("%d",&num);
	while(num!=0){
		temp[i++] = s[num%base];//字符从第一个开始加，直到最后一个以'\0'结尾，不要在不确定长度时倒着加。
		num/=base;

	}
	for(j = 0;j<i;j++){
		array[j]=temp[i-j-1];
	}
	array[j] = '\0';//只是给字符串加结尾不用strcat函数，strcat内部是两个字符串拼接，且已经有了'\0'的结尾处理。
	printf("ANSWER FOR YOU：%s\n",array);
}