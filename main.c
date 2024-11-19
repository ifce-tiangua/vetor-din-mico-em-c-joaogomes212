#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;

    // Leia as dimensões da matriz
    // printf("Digite as dimensões da matriz (linhas e colunas): ");
    if (scanf("%d %d", &linhas, &colunas) != 2 || linhas <= 0 || colunas <= 0)
    {
        // printf("[matriz vazia]\n");
        return 0;
    }

    // Alocar memória para a matriz
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        // printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL)
        {
            // printf("Erro ao alocar memória.\n");
            //  Libera memória já alocada em caso de falha
            for (int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
    }

    // Leia os dados da matriz
    // printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (scanf("%d", &matriz[i][j]) != 1)
            {
                // printf("Entrada inválida.\n");
                // Libera memória e encerra
                for (int k = 0; k < linhas; k++)
                {
                    free(matriz[k]);
                }
                free(matriz);
                return 1;
            }
        }
    }

    // Imprime a matriz no formato esperado pelo teste
    printf("[");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (i == linhas - 1 && j == colunas - 1)
            {
                printf("%d", matriz[i][j]); // Último elemento sem vírgula
            }
            else
            {
                printf("%d, ", matriz[i][j]); // Elementos com vírgula
            }
        }
    }
    printf("]\n");

    // Libera a memória alocada
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
