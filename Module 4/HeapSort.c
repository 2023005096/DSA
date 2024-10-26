#include <stdio.h>
#define max 100
int heap[max];
int size = 0;
void insert(int element){
    if (size >= max){
        printf("heap is full\n");
        return;
    }
    heap[size] = element;
    int current = size;
    size++;
    while(current >0){
        int parent = (current - 1)/2;
        if(heap[current]>heap[parent]){
            int temp = heap[current];
            heap[current] = heap[parent];
            heap[parent] = temp;
            current = parent;
        }else{
            break;
        }
    }
}
void printheap(){
    for(int i = 0; i<size; i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
int main(){
    insert(30);
    insert(40);
    insert(25);
    insert(26);
    insert(21);
    insert(28);
    insert(27);
    printf("Max heap : ");
    printheap();
    return 0;
}