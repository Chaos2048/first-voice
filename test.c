#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char rec(char*arr) {
	int len = strlen(arr);//11
	//字符串首地址
	char* p = arr;

	//字符串最后一个有效字符的地址
	char* p1 =&arr[len-1];//下标要减一
	while (p<p1)
	{
		char temp = *p;
		*p = *p1;
		*p1 = temp;
		p++;
		p1--;
	}
}

int main(void){
	char arr[] = "hello world";
	rec(arr);
	printf("%s\n", arr);
    system("pause");
	return EXIT_SUCCESS;
}
