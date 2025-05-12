#include <stdio.h>

#define tamanho 10

void exibicao_Tabuleiro(int tabuleiro[tamanho][tamanho])
{

    printf("    A B C D E F G H I J\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d| ", i);

        for (int j = 0; j < tamanho; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }

        printf("\n");
    }
}

void navio_Horizontal(int tabuleiro[tamanho][tamanho], int linha, int coluna)
{

    if (coluna + 2 < tamanho)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[linha][coluna + i] == 3)
            {
                printf("Navio na Horizontal não pode ser posicionar em (%d, %d) por ja estar ocupado por um outro\n", linha, coluna);

                return;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
    else
    {

        printf("O navio da Horizontal não pode ser posicionado aqui por ultrapassar o limite do tabuleiro!\n");

        return;
    }
}

void navio_Vertical(int tabulerio[tamanho][tamanho], int linha, int coluna)
{

    if (linha + 2 < tamanho)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabulerio[linha + i][coluna] == 3)
            {
                printf("Navio na Vertical não pode ser posicionar em (%d, %d) por ja estar ocupado por um outro\n", linha, coluna);

                return;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            tabulerio[linha + i][coluna] = 3;
        }
    }
    else
    {
        printf("O navio da Vertical não pode ser posicionado aqui por ultrapassar o limite do tabuleiro!\n");

        return;
    }
}

void navio_Diagonal1(int tabulerio[tamanho][tamanho], int linha, int coluna)
{

    if ((linha + 2 < tamanho) && (coluna + 2 < tamanho))
    {
        for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
        {
            if (tabulerio[linha + j][coluna + i] == 3)
            {
                printf("O navio da Diagonal 1 não pode ser posicionado em (%d, %d) por ja estar ocupado por um outro!\n", linha, coluna);

                return;
            }
        }

        for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
        {
            tabulerio[linha + j][coluna + i] = 3;
        }
    }
    else
    {

        printf("O navio da Diagonal 1 não pode ser posicionado aqui por ultrapassar o limite do tabuleiro!\n");

        return;
    }
}

void navio_Diagona2(int tabulerio[tamanho][tamanho], int linha, int coluna)
{

    if ((linha + 2 < tamanho) && (coluna - 2 >= 0))
    {
        for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
        {
            if (tabulerio[linha + j][coluna + i] == 3)
            {
                printf("O navio da Diagonal 2 não pode ser posicionado em (%d, %d) por ja estar ocupado por um outro!\n", linha, coluna);

                return;
            }
        }

        for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
        {
            tabulerio[linha + j][coluna + i] = 3;
        }
    }
    else
    {

        printf("O navio da Diagonal 2 não pode ser posicionado aqui por ultrapassar o limite do tabuleiro!\n");

        return;
    }
}

void habilidade_Cone(int tabuleiro[tamanho][tamanho], int origemi, int origemj)
{

    if ((origemi + 2 >= tamanho) || (origemj + 2 >= tamanho) || (origemj - 2 < 0))
    {
        printf("A habilidade cone utrapassa os limites do tabuleiro!\n");

        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int ei = origemi + i;
            int ej = origemj + j;

            if (ei < tamanho && ej >= 0 && ej < tamanho)
            {
                if (tabuleiro[ei][ej] == 3)
                {
                    tabuleiro[ei][ej] = 5;
                }
            }
            else
            {
                tabuleiro[ei][ej] = 1;
            }
        }
    }
}

void habilidade_Cruz(int tabuleiro[tamanho][tamanho], int origemi, int origemj)
{

    if ((origemi + 1 >= tamanho) || (origemi - 1 < 0) || (origemj + 2 >= tamanho) || (origemj - 2 < 0))
    {
        printf("A habilidade cruz ultrapassa os limites do tabuleiro!\n");

        return;
    }

    for (int i = -1; i < 2; i++)
    {
        int ei = origemi + i;

        if (ei >= 0 && ei < tamanho)
        {
            if (tabuleiro[ei][origemj] == 3)
            {
                tabuleiro[ei][origemj] = 5;
            }
            else
            {
                tabuleiro[ei][origemj] = 1;
            }
        }
    }
    for (int j = 0; j < -2; j++)
    {
        int ej = origemj + j;

        if (ej >= 0 && ej < tamanho)
        {
            if (tabuleiro[origemi][ej] == 3)
            {
                tabuleiro[origemi][ej] = 5;
            }
            else
            {
                tabuleiro[origemi][ej] = 1;
            }
        }
    }
}

void habilidade_Octaedro(int tabuleiro[tamanho][tamanho], int origemi, int origemj)
{

    if ((origemi + 1 >= tamanho) || (origemi - 1 < 0) || (origemj + 1 >= tamanho) || (origemj - 1 < 0))
    {
        printf("A habilidade octaedro ultrapassa os limites do tabuleiro!\n");

        return;
    }

    for (int i = -1; i < 2; i++)
    {
        int ei = origemi + i;

        if (ei >= 0 && ei < tamanho)
        {
            if (tabuleiro[ei][origemj] == 3)
            {
                tabuleiro[ei][origemj] = 1;
            }
        }
    }

    for (int j = -1; j < 2; j++)
    {
        int ej = origemj + j;

        if (ej >= 0 && ej < tamanho)
        {
            if (tabuleiro[origemi][ej] == 3)
            {
                tabuleiro[origemi][ej] = 5;
            }
            else
            {
                tabuleiro[origemi][ej] = 1;
            }
        }
    }
}

int main()
{
    int tabuleiro[tamanho][tamanho] = {0};

    navio_Horizontal(tabuleiro, 2, 2);

    navio_Vertical(tabuleiro, 6, 6);

    navio_Diagonal1(tabuleiro, 1, 7);

    navio_Diagona2(tabuleiro, 4, 3);

    habilidade_Cone(tabuleiro, 7, 2);

    habilidade_Cruz(tabuleiro, 1, 2);

    habilidade_Octaedro(tabuleiro, 7, 6);

    exibicao_Tabuleiro(tabuleiro);

    return 0;
}