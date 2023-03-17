#include<stdio.h>

#include<stdlib.h>
#include<string.h>


char* GetMemory(char* p)///指针传值，在函数内部只对指针进行修改，是没有意义的，实参指针内容并不会改变。因为在函数内部只是对形参指针的指向做了改变，
						///这并不会影响实参指针的指向，实参指针str还是指向NULL
{
	p = (char*)malloc(100);
	return p;
}
//快捷键：shift+alt+->  扩大选择的内容
//void main()
//{
//	/*char* str =NULL;
//	str=GetMemory(str);
//	strcpy_s(str,20,"helloworld");
//	printf(str);*/
//
//	printf("Hello World!\n");
//
//	return 0;
//}