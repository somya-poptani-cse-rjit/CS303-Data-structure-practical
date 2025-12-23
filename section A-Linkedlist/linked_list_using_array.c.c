#include <stdio.h>
#define MAX 10

int data[MAX], next[MAX], head = -1, freeIndex = 0;

void initialize(){
    for(int i=0;i<MAX-1;i++) next[i]=i+1;
    next[MAX-1]=-1;
}

void insertatfirst(int val){
    if(freeIndex==-1) return;
    int n=freeIndex; freeIndex=next[n];
    data[n]=val; next[n]=head; head=n;
}

void insertatend(int val){
    if(freeIndex==-1) return;
    int n=freeIndex; freeIndex=next[n];
    data[n]=val; next[n]=-1;
    if(head==-1){ head=n; return; }
    int t=head; while(next[t]!=-1) t=next[t];
    next[t]=n;
}

void deleteatfirst(){
    if(head==-1) return;
    int t=head; head=next[head];
    next[t]=freeIndex; freeIndex=t;
}

void deletebyvalue(int val){
    if(head==-1) return;
    if(data[head]==val){ deleteatfirst(); return; }
    int p=head, c=next[head];
    while(c!=-1 && data[c]!=val){ p=c; c=next[c]; }
    if(c==-1) return;
    next[p]=next[c]; next[c]=freeIndex; freeIndex=c;
}

void traverse(){
    for(int t=head;t!=-1;t=next[t])
        printf("%d -> ",data[t]);
    printf("NULL\n");
}

int main(){
    initialize();
    insertatfirst(10);
    insertatfirst(20);
    insertatend(30);
    insertatend(40);
    traverse();
    deleteatfirst();
    traverse();
    deletebyvalue(30);
    traverse();
    return 0;
}
