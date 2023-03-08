/* PRENDE IN INPUT UN ARRAY E LO ORDINA DAL NUMERO PIÙ PICCOLO AL PIÙ GRANDE
 * USANDO L'ALGORITMO: INSERTION SORT
 */

#include <stdio.h>

#define MAX 50

void insArray(int *arr, int l);
void ordinaArray(int *arr, int l);
void scambiaIndici(int *x, int *y);
void stampaArrayOrdinato(int *arr, int l);

int main(int argc, char const *argv[]) {
  int a[MAX];
  int lung;

  printf("Inserire la lunghezza massima della riga di numeri: ");
  scanf("%d",&lung);

  printf("\nInserire i numeri all'interno della lista  \n");
  insArray(a,lung);

  ordinaArray(a,lung);

  printf("\nl'array è stato ordinato: \n");
  stampaArrayOrdinato(a,lung);

  printf("\n\n");
  return 0;
}

void insArray(int *arr, int l){

  for(int i=0; i<l; i++){
    printf("%d° numero: ",i+1);
    scanf("%d",&arr[i]);
  }
}
void scambiaIndici(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/* INSERTION SORT */
void ordinaArray(int *arr, int l){

int i;
int j=1;
int max;

while(j<l){
  max=arr[j];
  i=j-1;
  while((i>=0)&&(arr[i]>=max)){
    scambiaIndici(&arr[i+1], &arr[i]);
    i=i-1;
  }
  arr[i+1]=max;
  j++;
}
}

void stampaArrayOrdinato(int *arr, int l){
  for(int i=0; i<l; i++){
    printf("%d ",arr[i]);
  }
}
