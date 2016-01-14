#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
       fprintf(stderr, "Usage: nosse <integer>\n");
       return 1;
    }

    double *a = (double *)malloc(2 * sizeof(double));
    a[0] = a[1] = 1.0;
    double *b = (double *)malloc(2 * sizeof(double));
    b[0] = b[1] = 1.0;
    double *c = (double *)malloc(2 * sizeof(double));

    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);

   for (int i = 0; i < 1000000; ++i)  {
       for (int j = 0; j < atoi(argv[1]); ++j) {
           c[j] = a[j] + b[j];
       }
    }

    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("%f %f\n", c[0], c[1]);
    printf("computation took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    free(a); free(b); free(c);
}
