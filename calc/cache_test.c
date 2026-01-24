#include <stdio.h>
#include <sys/time.h>

#define N 128*1024*1024
#define TIMES 100

int x[N];
long long int y = 0;

/* initialize array x[] */
void init()
{
  int i;

  for (i = 0; i < N; i+=16)
    x[i] = 1; 
}

/* accessing array from x[0] to x[n], repeating r times */
void vec_acc(int n, int r)
{
  int i, t;

  for (t = 0; t < r; t++) {
    for (i = 0; i < n; i+=16) {
      y += x[i]; 
    }
  }
}

int main()
{
  long long int s, size, repeat;
  struct timeval start_time, end_time;
  float time;

  init();

  gettimeofday(&start_time, NULL);

  for (s = 4 * 1024; s < N; s = s*2) { // base access size from 2KiB to N 
    for (size = s; size < s*2; size += s/2) { // finely increasing access size

      gettimeofday(&start_time, NULL);

      vec_acc(size, TIMES); 

      gettimeofday(&end_time, NULL);

      time = (end_time.tv_sec - start_time.tv_sec) +
             (float)(end_time.tv_usec - start_time.tv_usec) / 1000000;

      time = time * 1000000 / (size/16 * TIMES);
      printf("%8d K: , time = %f\n", size/1024, time);
    }
  }

}
