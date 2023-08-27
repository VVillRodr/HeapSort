#include <stdio.h>

int pai (int i) {
   return (i - 1)/2;
}
int Esquerda(int i){
    return (i*2)+1;
}
int Direita(int i){
    return (i*2)+2;
}
void trocar (int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void max_heapify (int V[], int size, int i) {
    int e = Esquerda(i);
    int d = Direita(i);
    int maior;
    if(e < size && V[e]>V[i])
        maior = e;
    else
        maior = i;

    if(d<size && V[d]>V[maior])
        maior = d;

    if(maior != i){
        trocar(V,i,maior);
        max_heapify(V,size,maior);

    }
}

void build_max_heap (int V[], int size) {
   for(int i = (size/2)-1 ;i >= 0;i--){
        max_heapify(V,size,i);
   }
}

void heap_sort (int V[], int size) {
   build_max_heap(V,size);
   for(int i = (size-1); i>0 ;i--){
        trocar(V,0,i);
        size = i; // ja esta decrementando
        max_heapify(V,size,0);
   }
}

int main () {

   int i;

   int size = 41;

   int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7,54,67,53,34,23,1,4,5,6,7,3,4,56,67,3,3,6,4456,456,45,456,456,456,234,3456,4567,78,345,456,78,234,53456};

   printf("Vetor inicial : ");

   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");

   heap_sort (V, size);

   printf("Vetor ordenado: ");


   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");


   return 0;

}
