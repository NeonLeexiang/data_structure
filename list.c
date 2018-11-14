#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>

//typedef before using
typedef int Status;
typedef int ElemType;

//

typedef struct {
    ElemType *elem; // Memory space base address
    int length;
    int listSize;
}SqList;


//
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//

//
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10







//

/*
Status InitList_Sq(SqList *L) {
//
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE* sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}
*/



/*
//
void createList(SqList *L,int length){
    printf("we use InitList_Sq function to create a Sq_list\n");
    L->length = length;


    for(int i = 0;i < L->length;i++){
        printf("please enter L[%d]\n",i);
        scanf("%d",&L->elem[i]);
    }
}

//
void display_SqList(SqList *L){
    printf("the elem of SqList\n");
    for(int i = 0;i < L->length;i++){
        printf("%4d",L->elem[i]);
    }
    printf("\n");
}

 */
/* SqList creation*/




/*
//
Status ListInsert_Sq(SqList *L, int i, ElemType e){
    //
    if(i < 1 || i > L->length+1) return ERROR;
    //
    if(L->length >= L->listSize){
        //
        int* newBase = (ElemType *)realloc(L->elem,
                              (L->listSize + LISTINCREMENT)* sizeof(ElemType));
    if(!newBase) exit(OVERFLOW);
    L->elem = newBase;
    L->listSize += LISTINCREMENT;
    }
    int* q = &(L->elem[i-1]);
    //
    for (int *p = &(L->elem[L->length - 1]); p >= q; --p) *(p+1) = *p;
    *q = e;
    ++L->length;
    return OK;
}

//
Status ListDelete_Sq(SqList *L, int i, ElemType *e){
    //
    if(i < 1 || i > L->length) exit(OVERFLOW);
    int* p = &(L->elem[i-1]);
    // e = p; define global value to store e
    int* q = L->elem + L->length - 1;
    for(++p; p <= q; ++p) *(p-1) = *p;
    --L->length;
    return OK;
}

//
int LocateElem_Sq(SqList *L, ElemType e,
                  Status (*compare)(ElemType, ElemType)){
    //
    int i = 1;
    int* p = L->elem;
    while(i < L->length && !(*compare)(*p++, e)) ++i;
    if(i <= L->length) return i;
    else return OK;
}

*/ /* SqList function*/
















//Fail Init function
void Init_LNode(LinkList L){
    if (!L) exit(ERROR);
    L->data = 0;
    L->next = NULL;
}

void create_LNode(LinkList L, int n){
    //
    // use pointer return header
    //LinkList Head; // define a LinkList pointer point to list's head
    LinkList p; // use to point the LNode

    //L = (LinkList)malloc(sizeof(LNode)); // create a LNode
    // Head = L; // record the address of head
    //L->next = NULL;
    for (int i = n; i >0 ; --i) {
        p = (LinkList)malloc(sizeof(LNode)); // create a LNode
        scanf("%d",&(p->data));
        p->next = L->next;L->next = p;
    }
}






//
LinkList CreateList_L(LinkList L, int n){
    //
    // use pointer return header
    //LinkList Head; // define a LinkList pointer point to list's head
    LinkList p; // use to point the LNode

    L = (LinkList)malloc(sizeof(LNode)); // create a LNode
    // Head = L; // record the address of head
    L->next = NULL;
    for (int i = n; i >0 ; --i) {
        p = (LinkList)malloc(sizeof(LNode)); // create a LNode
        scanf("%d",&(p->data));
        p->next = L->next;L->next = p;
    }
    return L; // the function type is LinkList type
}


void display_LinkList(LinkList L){
    printf("the elem of LinkList\n");
    LinkList p;
    p = L->next;

    while (p != NULL){
        printf("%4d",p->data);
        p = p->next;
    }
    printf("\n");
}



// main function
int main() {


    /*
    SqList List;
    InitList_Sq(&List);
    createList(&List,3);
    display_SqList(&List);
    printf("%d",List.listSize);

    SqList List4test;
    InitList_Sq(&List4test);
    createList(&List4test,4);
    display_SqList(&List4test);
    printf("%d",List4test.elem[4]);
    return OK;
    */



    LNode L4test;
    Init_LNode(&L4test);
    create_LNode(&L4test, 5);
    display_LinkList(&L4test);
    printf("%4d",L4test.next->data);
    return OK;

    /*
    LNode L;
    LinkList List;
    List = CreateList_L(&L,3);
    display_LinkList(List);
    printf("%d",List->data);
    return OK;
    */

    /*
    LNode List;
    List.next = NULL;
    //LinkList L;
    create_LNode(&List,3);
    display_LinkList(&List);
    printf("%d",List.data);
    return OK;
    */

}
