// Exercício 2 do trabalho final

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quantReg = 0;

struct placaCarro {
    char letras[4];
    int numeros;
};

struct veiculos {
    char proprietario[30];
    char combustivel[10];
    char modelo[15];
    char cor[10];
    int chassi;
    int ano;
    struct placaCarro placa;
};

struct veiculos reg[20];

int main() {
    int op = 0;
    int i = 0;
    do {
        printf("MENU:\n");
        printf("[1] Cadastrar Veiculo\n");
        printf("[2] Listar\n");
        printf("[3] Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                cadastrarVeiculo(i);
                i++;
                quantReg++;
                break;
            case 2:
                listarVeiculos(quantReg);
                break;
            default:
                break;
        }
    } while(op != 3);

    return 0;
}

void cadastrarVeiculo(int i) {
    int op, x;
    system("cls");
    printf("CADASTRAR:\n");
    printf("Proprietario: ");
    fflush(stdin);
    fgets(reg[i].proprietario, 29, stdin);
    printf("Combustivel: \n");
    printf("[1] Alcool\n");
    printf("[2] Gasolina\n");
    printf("[3] Diesel\n");
    scanf("%d", &op);
    switch(op) {
        case 1:
            strcpy(reg[i].combustivel, "Alcool");
            break;
        case 2:
            strcpy(reg[i].combustivel, "Gasolina");
            break;
        case 3:
            strcpy(reg[i].combustivel, "Diesel");
            break;
        default:
            printf("OPÇÃO INVÁLIDA!");
            break;
    }
    printf("Modelo: ");
    fflush(stdin);
    fgets(reg[i].modelo, 14, stdin);
    printf("Cor: ");
    fflush(stdin);
    fgets(reg[i].cor, 9, stdin);
    printf("Numero de chassi: ");
    fflush(stdin);
    scanf("%d", &reg[i].chassi);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &reg[i].ano);
    printf("Placa: ");
    for(x = 0; x < 3; x++) {
        fflush(stdin);
        reg[i].placa.letras[x] = getch();
        printf("%c", reg[i].placa.letras[x]);
    }
    printf("-");
    fflush(stdin);
    scanf("%d", &reg[i].placa.numeros);
    exibirProprietarios(i);
}

void listarVeiculos() {
    int op, i = 0;
    system("cls");
    printf("LISTAGEM: \n");
    printf("[1] Proprietarios com carros a Diesel (1980 ou posterior)\n");
    printf("[2] Proprietarios com carros Flex (2000 ou posterior)\n");
    printf("[3] Veiculos com placas que iniciam com A e finalizam com numero par\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%d", &op);

    switch(op) {
        case 1:
            for(i = 0; i < quantReg; i++) {
                if(!(strcmp(reg[i].combustivel, "Diesel")) && (reg[i].ano >= 1980)) {
                    exibirProprietarios(i);
                }
            }
            break;
        case 2:
            for(i = 0; i < quantReg; i++) {
                if(!(strcmp(reg[i].combustivel, "Alcool")) || (strcmp(reg[i].combustivel, "Gasolina")) && (reg[i].ano >= 2000)) {
                    exibirProprietarios(i);
                }
            }
            break;
        case 3:
            for(i = 0; i < quantReg; i++) {
                if((reg[i].placa.letras[0] == 'A') || (reg[i].placa.letras[0] == 'a') && (reg[i].placa.numeros % 2 == 0)) {
                    exibirProprietarios(i);
                }
            }
            break;
        default:
            break;
    }
}

void exibirProprietarios(int i) {
    printf("Proprietario: %s\n", reg[i].proprietario);
    printf("Combustivel: %s\n", reg[i].combustivel);
    printf("Modelo: %s\tCor: %s\n", reg[i].modelo, reg[i].cor);
    printf("Numero de Chassi: %d\n", reg[i].chassi);
    printf("Ano: %d\n", reg[i].ano);
    printf("Placa: %s-%d\n", reg[i].placa.letras, reg[i].placa.numeros);
    printf("-----------------------------------------------------------\n");
}
