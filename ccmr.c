#define false 0;
#define true 1;
#include <stdio.h>
#include <string.h>
struct names
{
    char nome[20];
};

int alphacmp(char str1[20], char str2[20]);
int partition(struct names arr[], int low, int high);
void quickSort(struct names arr[], int low, int high);
void troca();
void printar_array(struct names arr[100], int len);
int main()
{
    int N;
    int bom;
    int mau;
    char str[20];
    char state[2];
    char b[] = "+";
    char m[] = "-";
    struct names array[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {

        scanf("%s%s", state, str);
        if ((strcmp(state, b)) == 0)
        {
            bom = bom + 1;
        }
        if ((strcmp(state, m)) == 0)
        {
            mau = mau + 1;
        }

        strcpy(array[i].nome, str);
    }
    quickSort(array, 0, N - 1);
    printar_array(array, N);
    printf("Se comportaram: %d | Nao se comportaram: %d\n", bom, (N - bom));
}
int partition(struct names arr[], int low, int high)
{
    char *pivot = arr[high].nome; // pivot
    int i = (low - 1);            // Index of smaller element
    struct names um;
    struct names dois;

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        strcpy(um.nome, arr[j].nome);
        if (strcmp(arr[j].nome, pivot)<0)
        {
            i++; // increment index of smaller element
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(struct names arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
		at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void troca(struct names *a, struct names *b)
{
    struct names t = *a;
    *a = *b;
    *b = t;
}
int alphacmp(char str1[20], char str2[20])
{
    char um;
    char dois;
    if (strlen(str1) > strlen(str2))
    {
        for (int i = 0; i <= strlen(str2); i++)
        {
            um = str1[i];
            dois = str2[i];
            printf("\n%c->%c", um, dois);
            if (strcmp(&um, &dois) == 0)
            {
                printf(" aa ");
                continue;
            }
            else if (strcmp(&um, &dois) < 0)
            {
                printf("  true\n");
                return true;
            }
            else if (strcmp(&um, &dois) > 0)
            {
                printf("  false\n");
                return false;
            }
        }
    }
}
void printar_array(struct names arr[100], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", arr[i].nome);
    }
}
