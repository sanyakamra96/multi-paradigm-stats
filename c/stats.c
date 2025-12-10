#include <stdio.h>
#include <stdlib.h>

void print_array(const int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

double calculate_mean(const int *arr, int n) {
    if (n == 0) return 0.0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

double calculate_median(int *arr, int n) {
    if (n == 0) return 0.0;

    // sort in-place
    bubble_sort(arr, n);

    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        int mid1 = arr[n / 2 - 1];
        int mid2 = arr[n / 2];
        return (mid1 + mid2) / 2.0;
    }
}

int calculate_mode(const int *arr, int n, int *mode_value) {
    if (n == 0) return 0;

    int max_count = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            *mode_value = arr[i];
        }
    }

    return max_count; // frequency of the mode
}

int main(void) {
    int data[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Input data: ");
    print_array(data, n);

    // Copy for median so we don’t mess up original order (optional)
    int data_for_median[8];
    for (int i = 0; i < n; i++) data_for_median[i] = data[i];

    double mean = calculate_mean(data, n);
    double median = calculate_median(data_for_median, n);

    int mode_val = 0;
    int mode_freq = calculate_mode(data, n, &mode_val);

    printf("Mean:   %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode:   %d (frequency %d)\n", mode_val, mode_freq);

    return 0;
}
