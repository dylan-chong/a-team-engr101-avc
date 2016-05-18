#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int init(int x);

int main() {
    init_hardware();
    printf("\nTEST\n\n"); // TODO currently just for testing the sleep functions

//    int r = read_analog();

    return 0;

}