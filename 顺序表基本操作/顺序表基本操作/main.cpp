//
//  main.cpp
//  顺序表基本操作
//
//  Created by linxiang on 2017/9/14.
//  Copyright © 2017年 minxing. All rights reserved.
//

#include <iostream>

//#include <malloc.h>

using namespace std;

#define MAXSIZE 100    // 顺序表的最大存储容量
typedef char ElemType; // 顺序表存储的数据类型
//结构体
typedef struct{
    ElemType elem[MAXSIZE]; //用数组存放表结点
    int length;        // 线性表当前长度
}SqList;


//初始化
void InitList(SqList *&L)
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}
//释放顺序表
void DestroyList(SqList *L)
{
    free(L);
}
//判断是否为空
int ListEmpty(SqList *L)
{
    return(L->length==0);
}
//获取长度
int ListLength(SqList *L)
{
    return(L->length);
}
//输出顺序表
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0;i<L->length;i++)
        printf("%c",L->elem[i]);
    printf("\n");
}

//获取第i个位置上的元素返回给e
int GetElem(SqList *L,int i,ElemType &e)
{
    if (i<1 || i>L->length)
        return 0;
    e=L->elem[i-1];
    return 1;
}
//返回元素e的位置
int LocateElem(SqList *L, ElemType e)
{
    int i=0;
    while (i<L->length && L->elem[i]!=e) i++;
    if (i>=L->length)
        return 0;
    else
        return i+1;
}
//把元素e插入到位置i
int ListInsert(SqList *&L,int i,ElemType e)
{
    int j;
    if (i<1 || i>L->length+1)
        return 0;
    i--;        /*将顺序表位序转化为elem下标*/
    for (j=L->length;j>i;j--)   /*将elem[i]及后面元素后移一个位置*/
        L->elem[j]=L->elem[j-1];
    L->elem[i]=e;
    L->length++;      /*顺序表长度增1*/
    return 1;
}
//删除位置i上的元素
int ListDelete(SqList *&L,int i,ElemType &e)
{
    int j;
    if (i<1 || i>L->length)
        return 0;
    i--;        /*将顺序表位序转化为elem下标*/
    e=L->elem[i];
    for (j=i;j<L->length-1;j++)
        L->elem[j]=L->elem[j+1];
    L->length--;
    return 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    SqList *L;
    ElemType e;
    printf("(1)初始化顺序表L\n");
    InitList(L);
    printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("(3)输出顺序表L:");
    DispList(L);
    printf("(4)顺序表L长度=%d\n",ListLength(L));
    printf("(5)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));
    GetElem(L,4,e);
    printf("(6)顺序表L的第4个元素=%c\n",e);
    printf("(7)元素a的位置=%d\n",LocateElem(L,'a'));
    printf("(8)在第3个元素位置上插入f元素\n");
    ListInsert(L,3,'f');
    printf("(9)输出顺序表L:");
    DispList(L);
    printf("(10)删除L的第4个元素\n");
    ListDelete(L,4,e);
    printf("(11)输出顺序表L:");
    DispList(L);
    printf("(12)释放顺序表L\n");
    DestroyList(L);
    
    return 0;
}
