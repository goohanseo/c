#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 100

void queens(int row, int* cols);
bool promising(int* cols, int row, int col);
int count;
int N = 0;
int main() {
   scanf("%d", &N);
   int cols[MAX];
   queens(0, cols);
   printf("%d",count);

}

void queens(int row, int* cols) {
   if (row >= N) {
      for (int i = 0; i < N; i++) {
         printf("(%d, %d)\n", i, cols[i]);
      }
      printf("\n");
      count++;
      
      return;
   }

   for (int col = 0; col < N; col++) {
      cols[row] = col;
      if (promising(cols, row, col)) {
        if (row = N){
            count++;
            break;
        }
         queens(row + 1, cols);
      }
   }
}

bool promising(int* cols, int row, int col) {
   for (int i = 0; i < row; i++) {
      if (cols[i] == col) {
         return false;
      }
      else if ((row - i) == abs(col - cols[i])) {
         return false;
      }
   }
   return true;
}