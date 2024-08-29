void Union(List &La, List Lb)
{
    La_len = Listlength(La);
    Lb_len = Listlength(Lb);
    for (int i = 0, i < Lb_len, i++){
        GetElem(Lb, i, e) //取Lb中第i个元素赋给e
        if (! LocateElem(La, e, equal))
        ListInsert(La, ++La_len, e)
    }
}

//用递归法定义加法
int addint(int a, int b)
{
    if (a>b) {
       return add(a, b);
    }
}
int add(int a, int b) 
{
    if (a==0) {
        return b;
    } else {
        return (add(prior(a), next(b)));
    }
}

//dynamic array 动态数组
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef struct {
    ElemType* lem;
    int length;
    int listsize;
} SqList L;

//动态创建个空顺序表的算法
Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType* )malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit (OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//This is soooo lame and tiring !!! I mean the first online lesson
// now I've ran into a MUCH better one to start with!