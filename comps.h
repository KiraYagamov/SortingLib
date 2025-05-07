int compInt(void *a1, void *a2) {
    int* x = (int*) a1;
    int* y = (int*) a2;
    if (*x < *y) return -1;
    else if (*x == *y) return 0;
    return 1;
}

int compFloat(void *a1, void *a2) {
    float *x = (float*) a1;
    float *y = (float*) a2;
    if (*x < *y) return -1;
    else if (*x == *y) return 0;
    return 1;
}

int compDouble(void *a1, void *a2) {
    double *x = (double*) a1;
    double *y = (double*) a2;
    if (*x < *y) return -1;
    else if (*x == *y) return 0;
    return 1;
}

int compLong(void *a1, void *a2) {
    long *x = (long*) a1;
    long *y = (long*) a2;
    if (*x < *y) return -1;
    else if (*x == *y) return 0;
    return 1;
}

int compChar(void *a1, void *a2) {
    char *x = (char*) a1;
    char *y = (char*) a2;
    if (*x < *y) return -1;
    else if (*x == *y) return 0;
    return 1;
}
