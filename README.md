# Trabalho de Laboratório de Informática (ES31C / ES11)
Repositório com os arquivos .c dos trabalhos de Laboratório de Informática do curso de Engenharia de Software da UTFPR-CP.

## Trabalho 1
Considere o seguinte modelo de registro que representa uma pessoa:

* Nome (string) 
* Data de nascimento (registro do tipo 'Data' – possui dia, mês e ano) 
* CPF (string – contêm dígitos numéricos, pontos e tracinho)

a) Crie um registro do tipo acima. Os campos nome e CPF são do tipo caracter. A data de nascimento é um outro registro do tipo Data (dia, mês e ano) a ser definido também.

b) Crie um algoritmo para calcular a idade da pessoa de acordo com sua data de nascimento.

c) Crie um algoritmo para validar o CPF da pessoa (um CPF válido neste caso deve ter nove número; três pontos; e, um tracinho. Cada um no seu devido lugar).

---

## Trabalho 2

Para o controle de veículos que circulam em uma determinada cidade, a Secretaria dos Transportes criou um registro padrão de veículos com as seguintes informações:

* Proprietário (string - indicando o nome) 
* Combustível (string - álcool, diesel ou gasolina) 
* Modelo (string) 
* Cor (string) 
* Número de chassi (inteiro) 
* Ano (inteiro) 
* Placa (3 primeiros valores alfabéticos e os 4 restantes números)

Construa um algoritmo que leia uma quantidade arbitrária de veículos, limitado a 20. Em seguida:

a) Liste todos os proprietários cujos carros são do ano de 1980 ou posterior e que sejam movidos a diesel.

b) Liste todos os proprietários cujos carros são movidos a álcool ou a gasolina e que sejam do ano de 2000 para cima.

c) Liste todos os veículos cujas placas comecem com a letra 'A' e que o último dígito da placa seja um número par.

> Sugestão: considere a informação da placa como um outro registro

---

## Trabalho 3

Defina um registro denonimado 'Onibus' que representa um um ônibus, que reúne as seguintes informações:

* Cidade de origem (string) 
* Cidade de destino (string) 
* Data (registro do tipo Data – possui dia, mês e ano) 
* Hora (registro do tipo Hora – possui horas, minutos e segundos) 
* Distância (real)
* Poltronas – vetor de registro do tipo 'Poltrona' de tamanho máximo 40 com as seguintes informações:
  * Número da passagem (inteiro) 
  * Nome do passageiro (string) 
  * Sexo (caracter – M ou F)

Crie uma variável do tipo 'Onibus' e alimente seus dados (inclusive as poltronas, que pode inicialmente ser testado com um número pequeno). Em seguida construa algoritmos para as seguintes situações:

a) Defina um algoritmo para estimar o horário de chegada do ônibus e a duração da viagem em minutos, considerando que o ônibus viaje em uma velocidade média de 80km/h.

b) Defina um algoritmo para calcular a porcentagem de ocupação e de poltronas livres do ônibus.

c) Defina um algoritmo para calcular a porcentagem de passageiros do sexo masculino e do sexo feminino do ônibus.

d) Defina um algoritmo para imprimir de modo organizado as informações do ônibus e as informações de seus respectivos passageiros.

---

## Trabalho 4

Uma determinada biblioteca possui obras de ciências exatas, humanas e biomédicas, totalizando no máximo 1500 volumes, com no máximo 500 de cada área. O proprietário resolveu informatizá-la e para tal agrupou as informações sobre cada livro no seguinte formato:

* Código de catalogação
* Nome da obra (string) 
* Nome do autor (string) 
* Editora (string) 
* Número de páginas (inteiro) 
* Doado ("booleano" – representa sim ou não)

Defina um registro que reúna todas as informações de todas as obras em vetores distintos para cada área. Para facilitar, o usuário pode testar com um número pequeno de livros para cada área, podendo ser definido pelo usuário. Em seguida:

a) Elabore um algoritmo que realize consulta de informações assumindo que um certo número de obras já foi inserido em uma determinada área. O usuário deve fornecer o código da obra e sua área e mostrar uma mensagem dizendo se aquela obra existe ou não no catálogo.

b) Escreva um algoritmo que liste todas as obras de cada área que representem livros doados.

c) Escreva um algoritmo que liste todos os livros que sejam comprados e o número de páginas se encontre entre 100 e 300.

d) Elabore um trecho de algoritmo que faça a alteração de um registro.

Para tal, o usuário fornece o código de busca e a área. Lembre-se que somente pode ser alterado um livro existente.

---

## Trabalho 5

Escreva um algoritmo que simule a venda de ingressos para uma sessão de cinema. Sabe-se que o cinema possui 150 poltronas, dispostas em 15 filas de 10 poltronas cada.

Cada poltrona pode ser representada por:

0 - poltrona vazia

1 - pagante inteira

2 - pagante meia

Faça um preenchimento aleatório e apresente:

a) Ocupação das poltronas;

b) Quantidade de cada tipo;  

c) Valor apurado na sessão, sabendo que o ingresso (inteiro) custa R$ 12,00.

> Use struct para armazenar os dados e tente apresentar a sala de cinema visualmente (com caracteres mesmo).
