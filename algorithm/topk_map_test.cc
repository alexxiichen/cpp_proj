#include <unistd.h>
#include <cstdio>
#include <iostream>

int WriteDataFile() {
    const int MAX_ID = 999999;
    const int MAX_LINES = 2000000;
    FILE *fp = fopen("test.data", "w");
    if (fp == NULL) {
        perror("fopen test.data");
        return -1;
    }
    srand(time(NULL));
    for (int i = 0; i < MAX_LINES; ++i) {
        fprintf(fp, "%ld\n", random() * random() % MAX_ID);
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    WriteDataFile();
    return 0;
}