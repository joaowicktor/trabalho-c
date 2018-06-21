// Exercício 1 do Trabalho Final

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

    struct data {
        int dia, mes, ano;
    };

    struct pessoa {
        char nome[40], cpf[15];
        struct data dat;
    };

int main () {
    int idade, i, z;

    struct pessoa reg;

    printf("\n-------------CADASTRO DE PESSOA--------------\n");
     //*
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(reg.nome, 40, stdin);
    //*
    printf("\nInforme a data de nascimento\n");
    printf("Dia: ");
    scanf("%d/%d/%d", &reg.dat.dia, &reg.dat.mes, &reg.dat.ano);
    fflush(stdin);
    //*
    system("cls");

    //*
    printf("\n-------------CADASTRO DE PESSOA FISICA--------------\n");
    do {
    printf("Digite o CPF: ");
    fflush(stdin);
    fgets(reg.cpf, 15, stdin);

    if ((reg.cpf[3] == '.') && (reg.cpf[7] == '.') && (reg.cpf[11] == '-')) {
        /// Continua o programa
        z = 1;
    } else {
         z = 0;
         printf("CPF Invalido\n\n");
    }
    } while(z == 0);

    //*
    system("cls");
    //*
    printf("\n------------- INFORMACOES DO USUARIO --------------\n");
    // CALCULO IDADE
    idade = dataAtual() - reg.dat.ano;
    //*
    printf("Senhor(a) %s de %d anos\nCPF: %s", reg.nome, idade, reg.cpf);

    return 0;
}

int dataAtual() {
    time_t anoAtual;
    anoAtual = time(NULL);
    struct tm tm = *localtime(&anoAtual);
    return (tm.tm_year + 1900);
}

/*void teste() {
    int i, aux;
    for(i = 0; i < 2; i++) {
        scanf("%d")
    }
}*/
