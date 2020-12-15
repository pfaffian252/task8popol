#include <stdio.h>
#include <stdlib.h>
int const n=6;
void QuickSort ( int A[], int from, int to, int *s, int *p )
{
 int x, i, j, temp;
 if ( from >= to ) return; // условие окончания рекурсии
 i = from; // рассматриваем элементы с A[from] до A[to]
 j = to;
 x = A[(from+to)/2]; // выбрали средний элемент
 while ( i <= j ) {
 while ( A[i] < x ) {i ++; *s=*s+1;} // ищем пару для перестановки
 while ( A[j] > x ) {j --; *s=*s+1;}
 if ( i <= j ) {
 temp = A[i]; A[i] = A[j]; A[j] = temp; // перестановка
 i ++; // двигаемся дальше
 j --;
 *p=*p+1;
 }
 }
QuickSort ( A, from, j, s, p); // сортируем левую часть
QuickSort ( A, i, to, s, p); // сортируем правую часть
}
int main()
{
    int A[n], i, k, s=0, p=0;
    printf("Enter an array of %d elements\n", n);
    for ( i=0; i<n; i++) scanf ("%d",&A[i]);
    QuickSort ( A, 0, n-1, &s, &p);
    for ( i=0; i<n; i++) printf ("%d ",A[i]);
    printf("\n Number of comparisons %d. Number of permutations %d.", s, p);
    return 0;
}
