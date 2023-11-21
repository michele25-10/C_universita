#include <stdio.h>

int main()
{
    int dim1, dim2;
    do
    {
        printf("\nInserisci dimensione primo array: \n");
        scanf("%d", &dim1);
    } while (dim1 <= 0);

    int array1[dim1];

    do
    {
        printf("\nInserisci dimensione secondo array: \n");
        scanf("%d", &dim2);
    } while (dim2 <= 0);

    int array2[dim2];

    printf("\nELEMENTI PRIMO ARRAY\n");

    for (int i = 0; i < dim1; i++)
    {
        do
        {
            printf("\n%d posizione: ", i + 1);
            scanf("%d", &array1[i]);
        } while (i > 0 && array1[i] < array1[i - 1]);
    }

    printf("\nELEMENTI SECONDO ARRAY\n");

    for (int i = 0; i < dim2; i++)
    {
        do
        {
            printf("\n%d posizione: ", i + 1);
            scanf("%d", &array2[i]);
        } while (i > 0 && array2[i] < array2[i - 1]);
    }

    int merge[dim1 + dim2];

    int l = 0;
    int count = 0;
    int n_ins = 0;
    for (int k = 0; k < dim1; k++)
    {
        for (int j = count; j < dim2; j++)
        {
            if (array2[j] < array1[k])
            {
                merge[l] = array2[j];
                l++;
                n_ins++;
            }
        }
        count += n_ins;
        n_ins = 0;
        merge[l] = array1[k];
        l++;

        if (k == dim1 - 1)
        {
            for (int j = count; j < dim2; j++)
            {
                if(array2[j] > array1[k]){
                    merge[l] = array2[j]; 
                    l++;
                }
            }
        }
    }

    printf("\nMERGE\n");

    for (int i = 0; i < dim1 + dim2; i++)
    {
        printf("%d\t", merge[i]);
    }

    return 0;
}