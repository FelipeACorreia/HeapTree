#include <stdio.h>
#define TAM 10


void swapValues(int *tree, int x, int y){
    int aux = tree[x];
    tree[x] = tree[y];
    tree[y] = aux;
}

int searchParent(int i){
    i = (i-1)/2;
    return i;
}

int searchLeftChild(int i){
    i = (2*i)+1;
    return i;
}

int searchRightChild(int i){
    i = (2*i)+2;
    return i;
}

void insert(int *tree, int value, int *size){
    if(*size == TAM){
        printf("Tree is already full");
    }else{
        tree[*size] = value;
        int i = *size;
        while(i !=0 && tree[searchParent(i)] > tree[i]){
            swapValues(tree, searchParent(i), i);
            i = searchParent(i);
        }
        *size = *size +1;
    }
}

void minHeapify(int *tree, int i, int size){
    int left = searchLeftChild(i);
    int right = searchRightChild(i);
    int smallest = i;

    if(left < size && tree[left] < tree[smallest]){
        smallest = left;
    }
    if(right < size && tree[right] < tree[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swapValues(tree, i, smallest);
        minHeapify(tree, smallest, size);
    }

}

void removeSmallest(int *tree, int *size){
    if(*size == 0){
        printf("Tree is already empty");
    }else if(*size == 1){
        *size = *size-1;
    }else{
        *size = *size-1;
        swapValues(tree, 0, *size);
        minHeapify(tree, 0, *size);
    }
}

void showTree(int *tree, int size){

    for(int i = 0; i < size; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main(){
    int tree[TAM];
    int size = 0;

    insert(tree, 10, size);
    insert(tree, 7, &size);    
    insert(tree, 3, &size);
    insert(tree, 1, &size);
    insert(tree, 10, &size);
    insert(tree, 6, &size);
    insert(tree, 4, &size);

    showTree(tree, size);

    removeSmallest(tree, &size);

    showTree(tree, size);

    return 0;
}