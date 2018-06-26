// Exercício 3 do trabalho final

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POLT 40

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
    struct poltrona polt[MAX_POLT];
};

int quantPolt = 0;
struct onibus bus;

// Calcula a porcentagem de poltronas ocupadas
float calcularPoltOcupacao() {
    float ocup;
    float fquantPolt = quantPolt;
    ocup = (fquantPolt / MAX_POLT) * 100;
    return ocup;
}

// Calcula a porcentagem de poltronas livres
float calcularPoltLivres() {
    float livres;
    float fquantPolt = quantPolt;
    livres = (1 - (fquantPolt / MAX_POLT)) * 100;
    return livres;
}

// Calcula a porcentagem de passageiros do sexo masculino
float calcularPassagMasc() {
    int i, pMasc = 0;
    float porcentMasc, fquantPolt = quantPolt;
    for(i = 0; i < quantPolt; i++) {
        if((bus.polt[i].sexo == 'M') || (bus.polt[i].sexo == 'm')) {
            pMasc++;
        }
    }
    porcentMasc = (pMasc / fquantPolt) * 100;
    return porcentMasc;
}

// Calcula a porcentagem de passageiros do sexo feminino
float calcularPassagFem() {
    int i, pFem = 0;
    float porcentFem, fquantPolt = quantPolt;
    for(i = 0; i < quantPolt; i++) {
        if((bus.polt[i].sexo == 'F') || (bus.polt[i].sexo == 'f')) {
            pFem++;
        }
    }
    porcentFem = (pFem / fquantPolt) * 100;
    return porcentFem;
}

// Função para estimar horário de chegada
void estimarHorario() {
    int horas = 0, minutos = 0, segundos = 0;

    // Convertendo horário de partida em segundos
    segundos = bus.hr.horas * 3600;
    segundos += (bus.hr.minutos * 60);
    segundos += bus.hr.segundos;

    // Convertendo tempo do deslocamento em segundos
    segundos += ((bus.distancia / 80) * 3600);

    // Convertendo segundos para horas e minutos
    horas = segundos / 3600;
    minutos = (segundos % 3600) / 60;

    printf("%d:%d\n", horas, minutos);
}

// Exibe as informações gerais do ônibus
void exibirInfo() {
    int x;
    system("cls");
    printf("==================== VIACAO CORNELIO ====================\n\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\n ONIBUS N%c #%d\n", 167, rand() % 1000);
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\n\n Origem: %s", bus.origem);
    printf(" Destino: %s\n", bus.destino);
    printf(" Data: %d/%d/%d\n", bus.dat.dia, bus.dat.mes, bus.dat.ano);
    printf(" Hora: %d:%d:%d\n", bus.hr.horas, bus.hr.minutos, bus.hr.segundos);
    printf(" Horario estimado para chegada: ");
    estimarHorario();
    printf(" Duracao da viagem: %.0f minutos\n", (bus.distancia / 80) * 60);
    printf(" Poltronas ocupadas: %.1f%%\n", calcularPoltOcupacao());
    printf(" Poltronas livres: %.1f%%\n", calcularPoltLivres());
    printf(" Passageiros do sexo masculino: %.1f%%\n", calcularPassagMasc());
    printf(" Passageiros do sexo feminino: %.1f%%\n\n", calcularPassagFem());
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    listarPassageiros();
    printf("\n");
}

// Lista todos os passageiros
void listarPassageiros() {
    int i, x;
    printf("\n PASSAGEIROS\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    for(i = 0; i < quantPolt; i++) {
        printf("\n N%c da Passagem: %d\n", 167, bus.polt[i].numPassagem);
        printf(" Nome: %s", bus.polt[i].nomePassag);
        printf(" Sexo: %c\n", toupper(bus.polt[i].sexo));
        for(x = 0; x < 40; x++) {
            printf("=");
        }
    }
}

// Função de cadastro do ônibus
void cadastrarOnibus() {
    int x;
    printf("==================== VIACAO CORNELIO ====================\n\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\n CADASTRO DE ONIBUS\n");
    for(x = 0; x < 40; x++) {
        printf("=");
    }
    printf("\nOrigem: ");
    fflush(stdin);
    fgets(bus.origem, 29, stdin);
    printf("Destino: ");
    fflush(stdin);
    fgets(bus.destino, 29, stdin);
    printf("Distancia (em km): ");
    scanf("%f", &bus.distancia);
    printf("Data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &bus.dat.dia, &bus.dat.mes, &bus.dat.ano);
    printf("Hora (hh:mm:ss): ");
    scanf("%d:%d:%d", &bus.hr.horas, &bus.hr.minutos, &bus.hr.segundos);
    cadastrarPoltronas();
}

// Função de cadastro de poltronas
void cadastrarPoltronas() {
    int i = 0, x;
    char opc;

    do {
        system("cls");
        printf("==================== VIACAO CORNELIO ====================\n\n");
        for(x = 0; x < 40; x++) {
            printf("=");
        }
        printf("\n CADASTRO DE POLTRONAS\n");
        for(x = 0; x < 40; x++) {
            printf("=");
        }
        printf("\nPoltrona %d\n", 1 + i);
        bus.polt[i].numPassagem = gerarNumPassagem();
        printf("N%c da Passagem: %d\n", 167, bus.polt[i].numPassagem);
        printf("Nome do passageiro: ");
        fflush(stdin);
        fgets(bus.polt[i].nomePassag, 39, stdin);
        printf("Sexo (M/F): ");
        scanf(" %c", &bus.polt[i].sexo);
        i++;
        quantPolt++;
        printf("Continuar cadastrando (S/N)? ");
        scanf(" %c", &opc);
    } while(((opc == 'S') || (opc == 's')) && (i < MAX_POLT));
}

// Gera o número da passagem automaticamente com base no ano
int gerarNumPassagem() {
    int numPassagem = 0, numRand = 0;
    char strRand[10];
    char strPassagem[10];

    strcpy(strPassagem, "2018");
    numRand = rand() % 1000;
    if(numRand < 100) {
        strcat(strPassagem, "00");
    }
    else {
        strcat(strPassagem, "0");
    }
    strcat(strPassagem, itoa(numRand, strRand, 10));
    numPassagem = atoi(strPassagem);

    return numPassagem;
}

// Função principal
int main() {
    cadastrarOnibus();
    exibirInfo();
    printf("\nPressione qualquer tecla para finalizar");
    getch(); //Aguardar finalização
    return 0;
}
