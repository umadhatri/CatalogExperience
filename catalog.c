#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/workspaces/CatalogExperience/input.json"

long long lagrangeInterpolation(long long x[], long long y[], int n) {
    long long result =zz 0.0;

    for (int i = 0; i < n; i++) {
        long long term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (0 - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main() {
    // Read input from JSON file
    FILE *file = fopen("/path/to/input.json", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Parse JSON data
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_data = (char *)malloc(file_size + 1);
    fread(json_data, 1, file_size, file);
    json_data[file_size] = '\0';

    fclose(file);

    // Parse JSON object
    struct json_object *root = json_tokener_parse(json_data);
    free(json_data);

    // Extract x and y arrays from JSON object
    struct json_object *x_array, *y_array;
    json_object_object_get_ex(root, "x", &x_array);
    json_object_object_get_ex(root, "y", &y_array);

    int n = json_object_array_length(x_array);
    long long x[n], y[n];

    for (int i = 0; i < n; i++) {
        struct json_object *x_value = json_object_array_get_idx(x_array, i);
        struct json_object *y_value = json_object_array_get_idx(y_array, i);

        x[i] = json_object_get_int64(x_value);
        y[i] = json_object_get_int64(y_value);
    }

    // Calculate the value of Lagrange's interpolation at f=0
    long long result = lagrangeInterpolation(x, y, n);

    printf("Lagrange's interpolation at f=0: %lld\n", result);

    return 0;
}