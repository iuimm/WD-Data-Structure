#include<iostream>
#define ELEMTYPE int
#define MAXSIZE 50
#define END 9999
#define NOP -1
using namespace std;
typedef struct BiNode{
    ELEMTYPE data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
typedef struct ListNode{
    int lchild;
    int rchild;
    ELEMTYPE data;
}List;

void fun_start(BiTree &T);
void fun(BiTree &T){
    if(T){
        fun(T->lchild);
        fun(T->rchild);
        BiTree tmp;
        tmp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=tmp;
    }
}






//不使用第一项
void InitList(List L[]){
    int x=0,y=0,n=0;
    ELEMTYPE d;
    L[0]={0,0,0};
    cout<<"input numbers of tree node:"<<endl;
    cin>>n;
    for(int i=1;n<MAXSIZE&&i<=n;i++){
        cin>>x>>y>>d;
        L[i].lchild=x;
        L[i].rchild=y;
        L[i].data=d;
    }
}
void InitTreeWithList(BiTree &T,List L[],int index){
    if(index!=NOP){
        BiTree nd=(BiTree)malloc(sizeof(BiNode));
        nd->data=L[index].data;
        T=nd;
        InitTreeWithList(T->lchild,L,L[index].lchild);
        InitTreeWithList(T->rchild,L,L[index].rchild);
    }else{
        T=NULL;
    }
}
// 1 for PreOrder,2 for InOrder,3 for PostOrder
void PrintTree(BiTree T,int x){
    if(T){
        if(x==1){
            cout<<T->data<<" ";
        }
        PrintTree(T->lchild,x);
        if(x==2){
            cout<<T->data<<" ";
        }
        PrintTree(T->rchild,x);
        if(x==3){
            cout<<T->data<<" ";
        }
        free(T);
    }
}
void fun_start(BiTree &T){
    //以下是一个预置的初始化数组
    //不使用第一项
    List L0[10]={{0,0,0},{2,3,11},{4,5,12},{6,NOP,13},{NOP,7,14},{NOP,8,15},{NOP,NOP,16},{9,NOP,17},{NOP,NOP,18},{NOP,NOP,19}};
    List L[MAXSIZE];
    //InitList(L);
    InitTreeWithList(T,L0,1);
    fun(T);
    PrintTree(T,1);
}



int main(){
    BiTree T;
    fun_start(T);
    cout<<endl;
    return 0;
}
