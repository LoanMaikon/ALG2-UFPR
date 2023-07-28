#include <stdio.h>
#include <stdlib.h>

void ler_vetores (int n, int *val_sent, int *peso)
{
    int i;

    i = 0;
    while (i < n)
    {
        scanf("%d %d", &val_sent[i], &peso[i]);
        i++;
    }
}

int verificar_peso (int v[], int n, int *peso)
{
    int resultado = 0;
    int i = 0;

    while (i < n)
    {
        if (v[i] == 1)
            resultado += peso[i];
        i++;
    }

    return resultado;
}

int verificar_valor_sentimental (int v[], int n, int *val_sent)
{
    int resultado = 0;
    int i = 0;

    while (i < n)
    {
        if (v[i] == 1)
            resultado += val_sent[i];
        i++;
    }

    return resultado;
}

void copia_vetor (int *vetor_certo, int *v, int n)
{
    int i = 0;

    while (i < n)
    {
        vetor_certo[i] = v[i];
        i++;
    }
}

int gerar_subcjt (int v[], int n, int i, int *vetor_certo, int *val_sent, int *peso, int p_max)
{
    if (i == n)
    {
        int kg = verificar_peso(v,n,peso);
        int sentimental = verificar_valor_sentimental(v,n,val_sent);

        if (kg <= p_max)
        {
            if (verificar_valor_sentimental(vetor_certo,n,val_sent) < sentimental)
            {
                copia_vetor(vetor_certo,v,n);
            }
        }
        return 1;
    }

    v[i] = 0;
    gerar_subcjt(v,n,i+1,vetor_certo,val_sent,peso,p_max);
    v[i] = 1;
    gerar_subcjt(v,n,i+1,vetor_certo,val_sent,peso,p_max);

    return 1;
}

void impressao_final(int *vetor_certo, int *val_sent, int n)
{
    int i = 0;

    while (i < n)
    {
        if (vetor_certo[i] == 1)
        {
            printf("%d", i+1);
            if (i <= n - 2)
                printf(" ");
        }
        i++;
    }
    printf("\n");

    printf("Valor sentimental total: %d\n", verificar_valor_sentimental(vetor_certo,n,val_sent));
}

int main ()
{
    int i = 0;
    int j = 0;
    int n, p_max;
    int *val_sent, *peso, *v, *vetor_certo;

    scanf("%d %d", &n, &p_max);

    if (!(val_sent = malloc(n * sizeof(int))))
        return 1;
    
    if (!(peso = malloc(n * sizeof(int))))
        return 1;

    if (!(v = malloc(n * sizeof(int))))
        return 1;

    if (!(vetor_certo = malloc(n * sizeof(int))))
        return 1;

    ler_vetores(n,val_sent,peso);

    /*ajusta o vetor sentinela*/
    while (j < n)
    {
        vetor_certo[j] = 0;
        j++;
    }

    gerar_subcjt(v,n,i,vetor_certo,val_sent,peso,p_max);

    impressao_final(vetor_certo,val_sent,n);

    free(val_sent);
    free(peso);
    free(v);
    free(vetor_certo);

    return 0;
}