#include <stdio.h>

// Declaraciones de las funciones
double scale_num(double num, double min, double max, double new_max);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

int main()
{
    // Conjunto de valores de prueba
    double nums[] = {0.0, 1.0, 2.5, 5.0, 7.5, 10.0, -1.0, 15.0, 20.0, 100.0};
    double min = 0.0;
    double max = 10.0;
    double new_min = -2.0;
    double new_max = 2.0;

    int num_tests = sizeof(nums) / sizeof(nums[0]);
    int passed_tests = 0;

    for (int i = 0; i < num_tests; i++)
    {
        double num = nums[i];
        double result_scale_num = scale_num(num, min, max, new_max);
        double result_map = map(num, new_min, new_max, min, max);

        printf("Test %d:\n", i + 1);
        printf("scale_num(%f, %f, %f, %f) = %f\n", num, min, max, new_max, result_scale_num);
        printf("map(%f, %f, %f, %f, %f) = %f\n", num, new_min, new_max, min, max, result_map);

        if (result_scale_num == result_map)
        {
            printf("Resultado: PASSED\n\n");
            passed_tests++;
        }
        else
        {
            printf("Resultado: FAILED\n\n");
        }
    }

    printf("Total de pruebas pasadas: %d/%d\n", passed_tests, num_tests);

    return 0;
}

// Implementaciones de las funciones
double scale_num(double unscaled_num, double new_min, double new_max, double old_max)
{
    return (new_max - new_min) * unscaled_num / old_max + new_min;
}
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}
