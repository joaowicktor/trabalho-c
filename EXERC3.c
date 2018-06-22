#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct data {
    int dia;
    int mes;
    int ano;
};

struct hora {
    int horas;
    int minutos;
    int segundos;
};

struct poltrona {
    int numPassagem;
    char nomePassag[40];
    char sexo;
};

struct onibus {
    char origem[30];
    char destino[30];
    struct data dat;
    struct hora hr;
    float distancia;
    struct poltrona polt[40];
};

int quantPolt = 0;
struct onibus bus;

int main() {
    // Para usar acentuação
    setlocale(LC_ALL,"Portuguese");

    // Menu
    printf("======================================= VIAÇÃO CORNÉLIO =======================================\n\n");
    cadastrarOnibus();
    exibirInfo();
    for(int a = 0; a < 40; a++) {
        printf("=");
    }

    return 0;
}

// Exibe as informações gerais do ônibus
void exibirInfo() {
    printf("======================================= VIAÇÃO CORNÉLIO =======================================\n\n");
    printf(" Ônibus nº #%d\t\t", rand() % 1000);
    printf("Origem: %s\t\t", bus.origem);
    printf("Destino: %s\n", bus.destino);
}

// Função de cadastro do ônibus
void cadastrarOnibus() {
    printf("Origem: ");
    fflush(stdin);
    fgets(bus.origem, 29, stdin);
    printf("Destino: ");
    fflush(stdin);
    fgets(bus.destino, 29, stdin);
    system("cls");
}

// Gera o número da passagem automaticamente com base no ano
int gerarPassagem() {
    int numPassagem = 0, randi = 0;
    char random[10];
    char strPassagem[10];
    strcpy(strPassagem, "2018");
    randi = rand() % 1000;
    if(randi < 100) {
        strcat(strPassagem, "00");
    }
    else {
        strcat(strPassagem, "0");
    }
    strcat(strPassagem, itoa(randi, random, 10));
    numPassagem = atoi(strPassagem);

    return numPassagem;
}
