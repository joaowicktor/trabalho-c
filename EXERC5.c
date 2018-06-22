// Exercício 5
// Trabalho Final: Laboratório de Informática
// Curso: Engenharia de Software (ES11)

struct poltronas {
    int inteira;
    int vazia;
    int meia;
};

struct poltronas reg;

#include <stdio.h>
#include <locale.h>

int main ()  {
    setlocale(LC_ALL,"Portuguese");
    int vet[15][10], l, c;
    float soma = 0, valort = 0;

    reg.inteira = 0;
    reg.vazia = 0;
    reg.meia = 0;

    printf("  <~~~~~~~~~~~~~~~~~~~~>  CINEMA  <~~~~~~~~~~~~~~~~~~~~~~>\n\n");
    for(l = 0; l < 15; l++){
        for(c = 0; c < 10; c++){
            vet[l][c] = rand()%3;
        }
    }
    printf(" ______________________|   EXIT   |_______________________\n");
    printf("|                                                         |\n");

    for(l = 0; l < 15; l++){
        for(c = 0; c < 10; c++){
            if (vet[l][c] == 0){
                printf("(   ) ");
                reg.vazia = reg.vazia + 1;
            } else{
                if(vet[l][c] == 1){
                    printf("( X ) ");
                    reg.inteira = reg.inteira + 1;
                    valort = valort + 12;
                } else{
                    printf("( X ) ");
                    reg.meia = reg.meia + 1;
                    valort = valort + 6;
                }
            }
        }
        printf("\n");
    }

    // Quantidade total de poltronas
    soma = reg.inteira + reg.vazia + reg.meia;

    printf("|                                                         |\n");
    printf("|______|------------------ TELA ------------------|_______|\n");

    printf("\n\nInformações da sessão:\n");
    printf("-----------------------\n");
    printf("Quantidade de poltronas vazias = %d poltronas.\n", reg.vazia);
    printf("Quantidade de poltronas inteiras ocupadas = %d poltronas.\n", reg.inteira);
    printf("Quantidade de poltronas meia entrada ocupadas = %d poltronas.\n", reg.meia);
    printf("-----------------------\n");

    // Porcentagem de cada tipo de poltrona

    printf("Porcentagem de poltronas vazias = %.2f%%\n", (reg.inteira/soma)*100);
    printf("Porcentagem de poltronas inteiras ocupadas = %.2f%%\n", (reg.meia/soma)*100);
    printf("Porcentagem de poltronas meia entrada ocupadas = %.2f%%\n", (reg.vazia/soma)*100);
    printf("-----------------------\n");
    printf("Valor total apurado = %.2f reais.\n", valort);

    return 0;
}
