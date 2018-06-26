// Exercício 2 do trabalho final

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int quantReg = 0;

// Função principal
int main() {
    int op, i = 0, x;
    do {
        printf("==================== SECRETARIA DE TRANSPORTES ====================\n\n");
        printf("[1] Cadastrar Veiculo\n");
        printf("[2] Listar\n");
        printf("[3] Sair\n");
        printf("Opcao: ");
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
    } while((op != 3) && (i < 20));

    return 0;
}

// Função para cadastrar veículos
void cadastrarVeiculo(int i) {
    int op, x;
    system("cls");
    printf("==================== SECRETARIA DE TRANSPORTES ====================\n\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\n CADASTRO DE VEICULOS\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\nProprietario: ");
    fflush(stdin);
    fgets(reg[i].proprietario, 29, stdin);
    printf("Combustivel: \n");
    printf("[1] Alcool\n");
    printf("[2] Gasolina\n");
    printf("[3] Diesel\n");
    printf("Opcao: ");
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
        reg[i].placa.letras[x] = getche();
    }
    printf("-");
    fflush(stdin);
    scanf("%d", &reg[i].placa.numeros);
    system("cls");
}

// Função para listar veículos e proprietarios
void listarVeiculos() {
    int op, i = 0, x, regEnc = 0;
    system("cls");
    printf("==================== SECRETARIA DE TRANSPORTES ====================\n\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\n LISTAGEM\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\n[1] Proprietarios com carros a Diesel (1980 ou posterior)\n");
    printf("[2] Proprietarios com carros Flex (2000 ou posterior)\n");
    printf("[3] Veiculos com placas que iniciam com A e finalizam com numero par\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%d", &op);
    printf("\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    switch(op) {
        case 1:
            for(i = 0; i < quantReg; i++) {
                if((strcmp(reg[i].combustivel, "Diesel") == 0) && (reg[i].ano >= 1980)) {
                    exibirProprietarios(i);
                    regEnc++;
                }
            }
            if(regEnc == 0) {
                printf("\n NENHUM REGISTRO ENCONTRADO!\n");
            }
            printf("\nPressione qualquer tecla para continuar...");
            getch();
            system("cls");
            break;
        case 2:
            for(i = 0; i < quantReg; i++) {
                if((strcmp(reg[i].combustivel, "Alcool") == 0) || (strcmp(reg[i].combustivel, "Gasolina") == 0) && (reg[i].ano >= 2000)) {
                    exibirProprietarios(i);
                    regEnc++;
                }
            }
            if(regEnc == 0) {
                printf("\n NENHUM REGISTRO ENCONTRADO!\n");
            }
            printf("\nPressione qualquer tecla para continuar...");
            getch();
            system("cls");
            break;
        case 3:
            for(i = 0; i < quantReg; i++) {
                if((reg[i].placa.letras[0] == 'A') || (reg[i].placa.letras[0] == 'a') && (reg[i].placa.numeros % 2 == 0)) {
                    exibirProprietarios(i);
                    regEnc++;
                }
            }
            if(regEnc == 0) {
                printf("\n NENHUM REGISTRO ENCONTRADO!\n");
            }
            printf("\nPressione qualquer tecla para continuar...");
            getch();
            system("cls");
            break;
        default:
            system("cls");
            break;
    }
}

// Lista todos os proprietarios com base na opção do listarVeiculos()
void exibirProprietarios(int i) {
    int x;
    printf("\n Proprietario: %s", reg[i].proprietario);
    printf(" Combustivel: %s\n", reg[i].combustivel);
    printf(" Modelo: %s", reg[i].modelo);
    printf(" Cor: %s", reg[i].cor);
    printf(" Numero de Chassi: %d\n", reg[i].chassi);
    printf(" Ano: %d\n", reg[i].ano);
    printf(" Placa: %s-%d\n", reg[i].placa.letras, reg[i].placa.numeros);
    for(x = 0; x < 40; x++) {
            printf("=");
    }
}
