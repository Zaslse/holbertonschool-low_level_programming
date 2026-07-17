#include <stdio.h>
#include <time.h>
#define DATASET_SIZE 50000
#define SEED_VALUE 42u
static int dataset[DATASET_SIZE];
static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}
static void build_dataset(void)
{
    unsigned int state = SEED_VALUE;
    int i;
    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}
static void process_dataset(void)
{
    int i, v;
    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0) v = -v;
        dataset[i] = v;
    }
}
static unsigned long reduce_checksum(void)
{
    unsigned long sum = 0;
    int i;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];
    return sum;
}
int main(void)
{
    unsigned long checksum;
    clock_t start_total, start_build, start_process, start_reduce;
    clock_t end_total, end_build, end_process, end_reduce;
    double elapsed_total, elapsed_build, elapsed_process, elapsed_reduce;
    start_total = clock();
    start_build = clock();
    build_dataset();
    end_build = clock();
    start_process = clock();
    process_dataset();
    end_process = clock();
    start_reduce = clock();
    checksum = reduce_checksum();
    end_reduce = clock();
    end_total = clock();
    if (checksum == 0ul) printf("impossible\n");
    elapsed_total = (double)(end_total - start_total) / (double)CLOCKS_PER_SEC;
    elapsed_build = (double)(end_build - start_build) / (double)CLOCKS_PER_SEC;
    elapsed_process = (double)(end_process - start_process) / (double)CLOCKS_PER_SEC;
    elapsed_reduce = (double)(end_reduce - start_reduce) / (double)CLOCKS_PER_SEC;
    printf("TOTAL seconds: %.6f\n", elapsed_total);
    printf("BUILD_DATA seconds: %.6f\n", elapsed_build);
    printf("PROCESS seconds: %.6f\n", elapsed_process);
    printf("REDUCE seconds: %.6f\n", elapsed_reduce);
    return 0;
}
