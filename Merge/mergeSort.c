/* PRENDE IN INPUT UN ARRAY E LO ORDINA DAL NUMERO PIÙ PICCOLO AL PIÙ GRANDE
 * USANDO L'ALGORITMO: MERGE SORT
 */

#include <stdio.h>

#define MAX 50



void insArray(int *arr, int l);
void ordinaArray(int *arr, int l);
void merge(int *a, int sx, int m, int dx);
void mergeSort(int *array, int sx, int dx);
void stampaArrayOrdinato(int *arr, int l);

int main(int argc, char const *argv[]) {
  int a[MAX];
  int lung;

  printf("Inserire la lunghezza massima della riga di numeri: ");
  scanf("%d",&lung);

  printf("\nInserire i numeri all'interno della lista  \n");
  insArray(a,lung);

  int i = 0;
  int f = lung-1;

  mergeSort(a, i, f);

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

/* MERGE */
void merge(int *a, int sx, int m, int dx) {
  int i, j, k=0, b[MAX];
  i = sx;
  j = m+1;

  while (i<=m && j<=dx) {
    if (a[i]<a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while (i <= m) {
    b[k] = a[i];
    i++;
    k++;
  }
  while (j <= dx) {
    b[k] = a[j];
    j++;
    k++;
  }
  for (k=sx; k<=dx; k++)
    a[k] = b[k-sx];
}

/* MERGE SORT */
void mergeSort(int *array, int sx, int dx){
  int m;
  if(sx < dx) {
    m = (sx+dx)/2;
    mergeSort(array, sx, m);
    mergeSort(array, m+1, dx);
    merge(array, sx, m, dx);
  }
}

void stampaArrayOrdinato(int *arr, int l){
  for(int i=0; i<l; i++){
    printf("%d ",arr[i]);
  }
}
