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
    // Para usar acentua��o
    setlocale(LC_ALL,"Portuguese");

    // Menu
    printf("======================================= VIA��O CORN�LIO =======================================\n\n");
    cadastrarOnibus();
    exibirInfo();
    for(int a = 0; a < 40; a++) {
        printf("=");
    }

    return 0;
}

// Exibe as informa��es gerais do �nibus
void exibirInfo() {
    printf("======================================= VIA��O CORN�LIO =======================================\n\n");
    printf(" �nibus n� #%d\t\t", rand() % 1000);
    printf("Origem: %s\t\t", bus.origem);
    printf("Destino: %s\n", bus.destino);
}

// Fun��o de cadastro do �nibus
void cadastrarOnibus() {
    printf("Origem: ");
    fflush(stdin);
    fgets(bus.origem, 29, stdin);
    printf("Destino: ");
    fflush(stdin);
    fgets(bus.destino, 29, stdin);
    system("cls");
}

// Gera o n�mero da passagem automaticamente com base no ano
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
