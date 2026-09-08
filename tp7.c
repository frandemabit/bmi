// URL del repositorio: https://github.com/frandemabit/bmi.git
#include <stdio.h>

#define TAM 5

int main()
{
    int codigos[TAM];
    float precios[TAM];
    int i;
    int codigo;
    float precio;
    float mayor;
    float menor;
    int codigoMayor;
    int codigoMenor;

    printf("Ingrese %d productos, se solicitara el codigo y precio:\n\n", TAM);
    for (i = 0; i < TAM; i++)
    {
        printf("Ingrese el codigo de barras (1-999999999): ");
        scanf("%d", &codigo);

        while (codigo < 1 || codigo > 999999999)
        {
            printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
            printf("Ingrese el codigo de barras (1-999999999): ");
            scanf("%d", &codigo);
        }
        codigos[i] = codigo;
        printf("Ingrese el precio: ");
        scanf("%f", &precio);
        while (precio < 0)
        {
            printf("Error. El precio no puede ser negativo\n");
            printf("Ingrese el precio: ");
            scanf("%f", &precio);
        }
        precios[i] = precio;
        printf("\n");
    }
    printf("Codigo\t\tPrecio\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%d\t\t%.2f\n", codigos[i], precios[i]);
    }
    mayor = precios[0];
    codigoMayor = codigos[0];
    menor = precios[0];
    codigoMenor = codigos[0];
    for (i = 1; i < TAM; i++)
    {
        if (precios[i] > mayor)
        {
            mayor = precios[i];
            codigoMayor = codigos[i];
        }

        if (precios[i] < menor)
        {
            menor = precios[i];
            codigoMenor = codigos[i];
        }
    }
    printf("\nMas caro: [%d] %.2f\n", codigoMayor, mayor);
    printf("Mas barato: [%d] %.2f\n", codigoMenor, menor);

    return 0;
}