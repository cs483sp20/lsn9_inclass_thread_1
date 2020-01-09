#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <pthread.h>

long long sum;

// thread will begin control in this function
void *runner(void *param) {
    long long i;
    long long upper = atoll(param);
    sum = 0;
    for (i = 1; i <= upper; i++) {
        sum += i;
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t tid;  // thread ID
    pthread_attr_t attr;    // thread attributes

    pthread_attr_init(&attr);   // get default attributes

    pthread_create(&tid, &attr, runner, argv[1]);   // create the thread

    pthread_join(tid, NULL);    // wait for it to finish

    setlocale(LC_NUMERIC, "");   // allow for commas in output

    printf("sum = %'lld\n", sum);
    return 0;
}