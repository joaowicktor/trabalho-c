// Exercício 4 do trabalho final

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

typedef struct{
    int cod;
    char obra[30];
    char autor[30];
    char editora[30];
    int npag;
    int doado;
}livro;

int main () {
    livro exatas[MAX],humanas[MAX],biomedicas[MAX];
    int o, p, i, c, l, cod, x, in, ex, hu, bio;

    printf("Bibioteca Municipal\n");
    printf("----------------------------------\n");

    do {
        printf("MENU PRINCIPAL\n");
        printf("1-Cadastro de obras\n");
        printf("2-Consulta\n");
        printf("3-Listagens\n");
        printf("4-Alteracoes\n");
        printf("5-SAIR\n");
        printf("Digite a opcao:\n");
        scanf("%d", &o);

        system("cls");

            switch (o) {
                case 1:
                    do {
                        printf("MENU CADASTRO\n");
                        printf("1-Obras de Ciencias Exatas\n");
                        printf("2-Obras de Ciencias Humanas\n");
                        printf("3-Obras de Ciencias Biomedicas\n");
                        printf("4-SAIR\n");
                        printf("Digite a opcao:\n");
                        scanf("%d", &p);

                        system("cls");

                            switch (p) {
                                case 1:
                                    printf("CADASTRO OBRAS DE CIENCIAS EXATAS\n");
                                    printf("Digite a quantidade de vezes que deseja repetir o cadastro:\n ");
                                    scanf("%d", &x);

                                        for(ex=0;ex<x;ex++){
                                                printf("\nCodigo de catalogacao:");
                                                scanf("%d", &exatas[ex].cod);
                                                printf("Nome da obra:");
                                                fflush(stdin);
                                                fgets(exatas[ex].obra,30, stdin);
                                                printf("Nome do autor:");
                                                fgets(exatas[ex].autor,30, stdin);
                                                printf("Editora:");
                                                fgets(exatas[ex].editora,30,stdin);
                                                printf("Numero de paginas:");
                                                scanf("%d", &exatas[ex].npag);
                                                do{
                                                    printf("Doado (1=SIM e 0=NAO):");
                                                    scanf("%d", &exatas[ex].doado);
                                                }while(exatas[ex].doado > 1 || exatas[ex].doado < 0);
                                            }
                                system("cls");
                                break;

                                case 2:
                                    printf("CADASTRO OBRAS DE CIENCIAS HUMANAS\n");
                                    printf("Digite a quantidade de vezes que deseja repetir o cadastro:\n ");
                                    scanf("%d", &x);

                                        for(hu=0;hu<x;hu++){
                                                printf("\nCodigo de catalogacao:");
                                                scanf("%d", &humanas[hu].cod);
                                                printf("Nome da obra:");
                                                fflush(stdin);
                                                fgets(humanas[hu].obra,30, stdin);
                                                printf("Nome do autor:");
                                                fgets(humanas[hu].autor,30, stdin);
                                                printf("Editora:");
                                                fgets(humanas[hu].editora,30,stdin);
                                                printf("Numero de paginas:");
                                                scanf("%d", &humanas[hu].npag);
                                                do{
                                                    printf("Doado (1=SIM e 0=NAO):");
                                                    scanf("%d", &humanas[hu].doado);
                                                }while(humanas[hu].doado > 1 || humanas[hu].doado < 0);
                                            }
                                system("cls");
                                break;

                                case 3:
                                    printf("CADASTRO OBRAS DE CIENCIAS BIOMEDICAS\n");
                                    printf("Digite a quantidade de vezes que deseja repetir o cadastro:\n ");
                                    scanf("%d", &x);

                                        for(bio=0;bio<x;bio++){
                                                printf("\nCodigo de catalogacao:");
                                                scanf("%d", &biomedicas[bio].cod);
                                                printf("Nome da obra:");
                                                fflush(stdin);
                                                fgets(biomedicas[bio].obra,30, stdin);
                                                printf("Nome do autor:");
                                                fgets(biomedicas[bio].autor,30, stdin);
                                                printf("Editora:");
                                                fgets(biomedicas[bio].editora,30,stdin);
                                                printf("Numero de paginas:");
                                                scanf("%d", &biomedicas[bio].npag);
                                                do{
                                                    printf("Doado (1=SIM e 0=NAO):");
                                                    scanf("%d", &biomedicas[bio].doado);
                                                }while(biomedicas[bio].doado > 1 || biomedicas[bio].doado < 0);
                                            }
                                system("cls");
                                break;
                            }
                    } while (p!=4);

                system("cls");
                break;

                ///resolução do item "a".
                case 2:
                    printf("CONSULTA \n");
                    printf("---------\n");
                    do {
                        printf("AREAS\n");
                        printf("1-Ciencias Exatas\n");
                        printf("2-Ciencias Humanas\n");
                        printf("3-Ciencias Biomedicas\n");
                        printf("4-SAIR\n");
                        printf("Digite qual deseja consultar:\n");
                        scanf("%d", &c);

                        system("cls");

                        if (c==1) {
                            printf("Digite o codigo de catalogacao:");
                            scanf("%d", &cod);
                                for(in=0;in<ex;in++) {
                                    if (cod==exatas[in].cod){
                                        printf("A obra existe no catalogo\n");
                                        break;
                                    } else {
                                        printf("A obra nao existe no catalogo\n");
                                        break;
                                    }
                                }
                        } else if (c==2) {
                            printf("Digite o codigo de catalogacao:");
                            scanf("%d", &cod);
                              for(in=0;in<hu;in++) {
                                    if (cod==humanas[in].cod){
                                        printf("A obra existe no catalogo\n");
                                        break;
                                    } else {
                                        printf("A obra nao existe no catalogo\n");
                                        break;
                                    }
                                }
                        } else if (c==3) {
                            printf("Digite o codigo de catalogacao:");
                            scanf("%d", &cod);
                                for(in=0;in<bio;in++) {
                                    if (cod==biomedicas[in].cod){
                                        printf("A obra existe no catalogo\n");
                                        break;
                                    } else {
                                        printf("A obra nao existe no catalogo\n");
                                        break;
                                    }
                                }
                        } else {
                            printf("Opcao invalida\n");
                        }
                    } while(c!=4);
                system("cls");
                break;

                ///Resolução do item "b" e "c".
                case 3:
                    printf("LISTAGEM\n");
                    printf("--------\n");
                    do {
                        printf("LISTAS\n");
                        printf("1-Livros doados\n");
                        printf("2-Livros comprados\n");
                        printf("3-SAIR\n");
                        printf("Digite qual deseja consultar:\n");
                        scanf("%d", &l);

                        system("cls");
                        if (l==1) {
                            printf("LIVROS DOADOS\n");
                                for(ex=0;ex<x;ex++){
                                    if (exatas[ex].doado==1) {
                                        printf("Ciencias Exatas\n");
                                        printf("%s\n", exatas[ex].obra);
                                    }
                                }
                                for(hu=0;hu<x;hu++){
                                    if (humanas[hu].doado==1) {
                                        printf("Ciencias Humanas\n");
                                        printf("%s\n", humanas[hu].obra);
                                    }
                                }
                                for(bio=0;bio<x;bio++){
                                    if (biomedicas[bio].doado==1) {
                                        printf("Ciencias Biomedicas\n ");
                                        printf("%s\n", biomedicas[bio].obra);
                                    }
                                }
                        } else if (l==2) {
                            printf("LIVROS COMPRADOS E COM PAGINAS ENTRE 100 E 300\n");
                                for(ex=0;ex<x;ex++){
                                    if (exatas[ex].doado==0 && exatas[ex].npag>100 && exatas[ex].npag<300) {
                                    printf("%s\n", exatas[ex].obra);
                                    }
                                }
                                for(hu=0;hu<x;hu++){
                                    if (humanas[hu].doado==0 && humanas[hu].npag>100 && humanas[hu].npag<300) {
                                    printf("%s\n", humanas[hu].obra);
                                    }
                                }
                                for(bio=0;bio<x;bio++){
                                    if (biomedicas[bio].doado==0 && biomedicas[bio].npag>100 && biomedicas[bio].npag<300) {
                                    printf("%s\n", biomedicas[bio].obra);
                                    }
                                }
                            }
                    } while (l!=3);
                system("cls");
                break;

                ///resolução intem "d".
                case 4:
                    printf("ALTERACOES\n");
                    printf("------------\n");
                    do {
                        printf("AREAS\n");
                        printf("1-Ciencias Exatas\n");
                        printf("2-Ciencias Humanas\n");
                        printf("3-Ciencias Biomedicas\n");
                        printf("4-SAIR\n");
                        printf("Digite qual deseja alterar:\n");
                        scanf("%d", &c);

                        system("cls");
                        if (c==1) {
                            printf("Digite o codigo de catalogacao:");
                            scanf("%d", &cod);
                                for(i=0;i<ex;i++) {
                                    if (cod==exatas[i].cod){
                                        printf("\nCodigo de catalogacao:");
                                        scanf("%d", &exatas[i].cod);
                                        printf("Nome da obra:");
                                        fflush(stdin);
                                        fgets(exatas[i].obra,30, stdin);
                                        printf("Nome do autor:");
                                        fgets(exatas[i].autor,30, stdin);
                                        printf("Editora:");
                                        fgets(exatas[i].editora,30,stdin);
                                        printf("Numero de paginas:");
                                        scanf("%d", &exatas[i].npag);
                                        do{
                                            printf("Doado (1=SIM e 0=NAO):");
                                            scanf("%d", &exatas[i].doado);
                                        }while(exatas[i].doado > 1 || exatas[i].doado < 0);

                                    } else {
                                        printf("A obra nao existe no catalogo\n");
                                    }
                                }
                            }else if(c==2){
                                printf("Digite o codigo de catalogacao:");
                                scanf("%d", &cod);
                                    for(i=0;i<hu;i++) {
                                        if (cod==humanas[i].cod){
                                            printf("\nCodigo de catalogacao:");
                                            scanf("%d", &humanas[i].cod);
                                            printf("Nome da obra:");
                                            fflush(stdin);
                                            fgets(humanas[i].obra,30, stdin);
                                            printf("Nome do autor:");
                                            fgets(humanas[i].autor,30, stdin);
                                            printf("Editora:");
                                            fgets(humanas[i].editora,30,stdin);
                                            printf("Numero de paginas:");
                                            scanf("%d", &humanas[i].npag);
                                            do{
                                               printf("Doado (1=SIM e 0=NAO):");
                                               scanf("%d", &humanas[i].doado);
                                            }while(humanas[i].doado > 1 || humanas[i].doado < 0);
                                        } else {
                                            printf("A obra nao existe no catalogo\n");
                                        }
                                    }

                            }else if(c==3){

                            printf("Digite o codigo de catalogacao:");
                                scanf("%d", &cod);
                                    for(i=0;i<hu;i++) {
                                        if (cod==biomedicas[i].cod){
                                            printf("\nCodigo de catalogacao:");
                                            scanf("%d", &biomedicas[i].cod);
                                            printf("Nome da obra:");
                                            fflush(stdin);
                                            fgets(biomedicas[i].obra,30, stdin);
                                            printf("Nome do autor:");
                                            fgets(biomedicas[i].autor,30, stdin);
                                            printf("Editora:");
                                            fgets(biomedicas[i].editora,30,stdin);
                                            printf("Numero de paginas:");
                                            scanf("%d", &biomedicas[i].npag);
                                            do{
                                               printf("Doado (1=SIM e 0=NAO):");
                                               scanf("%d", &biomedicas[i].doado);
                                            }while(biomedicas[i].doado > 1 || biomedicas[i].doado < 0);
                                        } else {
                                            printf("A obra nao existe no catalogo\n");
                                        }
                                    }

                            }else{
                                printf("Opcao invalida\n");
                            }
                    } while (c!=4);
                system("cls");
                break;

            }


    } while (o!=5);



    return 0;
}
