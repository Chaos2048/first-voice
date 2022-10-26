#include <stdio.h>
#define MAX_

typedef struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
typedef struct Node* Linklist;

void CreateListHead (Linklist *L,int n)
    //第一个关键点，用*L还是L，这里使用*L，即L指向结构体指针，*L即为结构体指针
    //判断依据：如果指针本身也在改变，用二重指针传递；反之用一重指针即可
    //这里可参考函数传递中形参，实参的内容，必须把地址传到函数里，再读取索引改变参数，反之只改变形参
{
    Linklist p;
    int i;
    *L = (Linklist)malloc(sizeof(Node)); //一定要为L分配内存
    (*L)->next = NULL;
    for(i=1;i<n;i++)
    {
         p=(Linklist)malloc(sizeof(Node)); //表指针p分配空间
         p->data=i;               //存入该随机数
         p->next=(*L)->next;                      //将p的下一个结点赋为表L的下一结点,第一次为NULL,第二次为p1，第二次为p2......依此类推
         (*L)->next=p;                               //表L下一结点指向p所指结点数据
    }
}

//链表的遍历输出
void TraverseList(Linklist *L){
    Linklist p, q;
    p = *L;//将头指针赋值给p
    while(p->next != NULL){
        q = p->next;
        printf("%d", q->data);
        p = p->next;
    }
}


int main()
{
    Linklist L;
    CreateListHead(&L, 5);
    TraverseList(&L);
    return 0;
}
