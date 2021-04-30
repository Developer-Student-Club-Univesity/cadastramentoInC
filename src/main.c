#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX 100

typedef int integer;

// Variável Global Estática
integer static respIdades;

typedef struct Data
{

    integer dia;
    integer mes;
    integer ano;

    struct Data *proximo;

} Data;

typedef struct Endereco
{

    char *nomeRua;
    char *numeroCasa;
    char *bairro;
    char *cidade;
    char *cep;

    struct Endereco *proximo;
} Endereco;

typedef struct Alunos
{

    char *name;
    char *cpf;
    char *endereco;

    integer notas;

    integer dia;
    integer mes;
    integer ano;
    integer idadeAluno;

    char *nomeRua;
    char *numeroCasa;
    char *bairro;
    char *cidade;
    char *cep;

    Data *d1;
    Endereco *ed1;

    struct Alunos *proximo;

} Alunos;

// Variável Global
char nomeReserva[MAX];
char CPFReserva[MAX];
char enderecoReserva[MAX];
char nomeRuaReserva[100];
char numeroCasaReserva[100];
char bairroReserva[100];
char cidadeReserva[100];
char cepReserva[100];
char vetorAlunosConceitoFinal[150];

float mediaIdades;
float mediaDeNotasSomadas;

integer totAlunos = 0;
integer indiceDatas = 1;
integer somaDeNotas = 0;
integer totDataAlunos = 0;
integer totEnderecoAlunos = 0;
integer totNotasContadora = 1;
integer totNotasIndice = 1;
integer totIdades = 1;
integer somaIdades = 0;
integer acumuladorDeNotas;
integer indiceDatasAlunosCadastrados = 0;
integer indiceEnderecoAlunosCadastrados = 0;
integer indiceDatasDiaAlunosCadastrados = 0;
integer indiceDatasMesAlunosCadastrados = 0;
integer indiceDatasAnoAlunosCadastrados = 0;
integer indiceEnderecoNomeRuaAlunosCadastrados = 0;
integer indiceEnderecoNumeroCasaAlunosCadastrados = 0;
integer indiceEnderecoNomeBairroAlunosCadastrados = 0;
integer indiceEnderecoNomeCidadeAlunosCadastrados = 0;
integer indiceEnderecoCEPAlunosCadastrados = 0;
integer AlunosCadastradosTemp = 1;

void programaIncial();
void menu();
void menuData();
void menuEndereco();
void menuAluno();
void menuCadastramentoDeAlunos();
void menuAlunoMaisInterno();
void menuDadosCompletosDeTodosOsAlunos();
void menuPrincipal(); // Menusinho para mostar ao iniciar o programa
void adicionarDia(Alunos *alunosEnderecos);
void adicionarMes(Alunos *alunosEnderecos);
void adicionarAno(Alunos *alunosEnderecos);
void imprimeData(Alunos *alunosEnderecos);
void retornaDia(Alunos *alunosEnderecos);
void retornaMes(Alunos *alunosEnderecos);
void retornaAno(Alunos *alunosEnderecos);
void retornaNomeRua(Alunos *alunosEndereco);
void retornaNumeroCasa(Alunos *alunosEndereco);
void retornaNomeBairro(Alunos *alunosEndereco);
void retornaNomeCidade(Alunos *alunosEndereco);
void retornaCEP(Alunos *alunosEndereco);
void imprimeEnderecoCompleto(Alunos *alunosEndereco);
void listarDataCompleta(Alunos *numeroAtual);
void listarEnderecoCompleto(Alunos *numeroAtual);
void inserirDadosNasDatas(Data **d1);            // Veja que o parametro e' um ponteiro duplo ...
void inserirDadosAoAlunos(Alunos **restaurante); // Insere um restaurante na lista
void listar(Alunos *alunos);                     // Apresenta todos os restaurantes na tela ou em um
void inserirDadosOriginais(Alunos *novono);
void consultarDadosOriginais(Alunos *numeroAtual);
void listar_comida(Alunos *numeroAtual, char *valor);
void consultarNomesAlunos(Alunos *alunos);
void listarNomeAluno(Alunos *numeroAtual);
void consultarCPFAlunos(Alunos *alunos);
void listarCPFAluno(Alunos *numeroAtual);
void consultarIdadeAlunos(Alunos *alunos);
void listarIdadeAluno(Alunos *numeroAtual);
void listarDia(Alunos *alunos);
void listarMes(Alunos *alunos);
void listarAno(Alunos *alunos);
void listarNomeRua(Alunos *alunos);
void listarNumeroCasa(Alunos *alunos);
void listarNomeBairro(Alunos *alunos);
void listarNomeCidade(Alunos *alunos);
void listarCEP(Alunos *alunos);
void adicionarNotas();
void calculoDeNotasDosAlunos(integer totNotas);

integer main()
{
    programaIncial();
}

void programaIncial()
{
    setlocale(LC_ALL, "portuguese");

    Alunos *alunos = NULL; // Ponteiro para a restaurante da lista
    char q;                // Caractere para receber a opcao do usuario
    char nota[5];          // nota para comparacao vai ser lida como char
    integer respMenuPrincipal;

    do
    {
        menuCadastramentoDeAlunos();

        printf("\nDigite a sua Opcao: ");
        scanf("%d", &respMenuPrincipal);

        if (respMenuPrincipal <= 0 || respMenuPrincipal > 2)
        {
            printf("Nao foi possivel acessar essa opcao, por favor digite outra opcao\n");
        }

        else
        {
            if (respMenuPrincipal == 1)
            {
                do
                {
                    menuPrincipal();

                    fflush(stdin);   // Limpa o buffer de entrada
                    scanf("%c", &q); // Le a opcao do usuario
                    fflush(stdin);   // Limpa o buffer de entrada

                    if (q == 'i')
                    {
                        if (totAlunos < 150)
                            inserirDadosAoAlunos(&alunos);
                        else
                            printf("\nNao podera mais cadastrar alunos\nTente outro Dia\n");
                    }

                    else if (q == 'c')
                    {
                        int respConsultarAlunos;
                        do
                        {

                            menuAluno();

                            printf("\nDigite sua Opcao: ");
                            scanf("%d", &respConsultarAlunos);

                            if (respConsultarAlunos <= 0 || respConsultarAlunos > 7)
                                printf("Opcao Errada, tente Outra\n");

                            else
                            {

                                if (respConsultarAlunos == 1)
                                    listar(alunos);

                                else if (respConsultarAlunos == 2)
                                {
                                    if (AlunosCadastradosTemp > 0)
                                    {

                                        if (AlunosCadastradosTemp > 1)
                                        {
                                            printf("\n----------------------------- ** Dados da Turma ** -----------------------------\n");
                                            printf("Foram %d Alunos cadastrados no sistema", AlunosCadastradosTemp);
                                            listarNomeAluno(alunos);
                                            printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                        }

                                        else
                                        {
                                            printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                            printf("Foi um Aluno cadastrado no sistema");
                                            printf("\nAluno Cadastrado: %s", alunos->name);
                                            printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                        }
                                    }

                                    else
                                        printf("Nao foi nenhum aluno cadastrado no sistema");
                                }
                                else if (respConsultarAlunos == 3)
                                {
                                    printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                    printf("\nSoma Das %d Notas dos Aluno: %d", acumuladorDeNotas, somaDeNotas);
                                    printf("\nMedia Das %d Notas dos Aluno: %2.lf", acumuladorDeNotas, mediaDeNotasSomadas);
                                    printf("\nSituacao dos Alunos: %s\n", vetorAlunosConceitoFinal);
                                    printf("\n----------------------------- ** Dados da Turma ** -----------------------------\n");
                                }

                                else if (respConsultarAlunos == 4)
                                {
                                    printf("\n----------------------------- ** Dados da Turma ** -----------------------------\n");
                                    listarNomeAluno(alunos);
                                    printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                }

                                else if (respConsultarAlunos == 5)
                                {
                                    printf("\n----------------------------- ** Dados da Turma ** -----------------------------\n");
                                    listarCPFAluno(alunos);
                                    printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                }

                                else if (respConsultarAlunos == 6)
                                {
                                    printf("\n----------------------------- ** Dados da Turma ** -----------------------------\n");
                                    listarIdadeAluno(alunos);
                                    printf("----------------------------- ** Dados da Turma ** -----------------------------\n");
                                }
                            }

                        } while (respConsultarAlunos != 7);
                    }

                    else if (q == 'l')
                    {
                        // Listar no video a lista de Alunos
                        listar(alunos);
                        fflush(stdin);
                    }

                    else if (q == 'd')
                    {
                        integer respMenuData;

                        do
                        {
                            menuData();

                            printf("\nDigite sua Opcao: ");
                            scanf("%d", &respMenuData);
                            fflush(stdin);
                            printf("\n");

                            if (respMenuData <= 0 || respMenuData > 5)
                                printf("Por favor, digite uma outra opcao\n");
                            else
                            {
                                if (respMenuData == 1)
                                {
                                    listarDataCompleta(alunos);
                                    printf("\n");
                                }
                                else if (respMenuData == 2)
                                    listarDia(alunos);

                                else if (respMenuData == 3)
                                    listarMes(alunos);

                                else if (respMenuData == 4)
                                    listarAno(alunos);
                            }
                        } while (respMenuData != 5);
                    }

                    else if (q == 'e')
                    {

                        integer respMenuEndereco;
                        do
                        {
                            menuEndereco();

                            printf("\nDigite sua Opcao: ");
                            scanf("%d", &respMenuEndereco);
                            fflush(stdin);
                            printf("\n");

                            if (respMenuEndereco <= 0 || respMenuEndereco > 2)
                                printf("Por favor, digite uma outra opcao\n");

                            else
                            {
                                if (respMenuEndereco == 1)
                                {
                                    listarEnderecoCompleto(alunos);
                                    printf("\n");
                                }
                            }

                        } while (respMenuEndereco != 2);
                    }

                    else if (q == 'f')
                    {

                        if (totAlunos > 0)
                        {
                            if (totAlunos > 1)
                                printf("\nForam %d Alunos cadastrados no sistema", totAlunos);

                            else
                                printf("\nFoi um Aluno cadastrado no sistema");
                        }
                        else
                            printf("Nao foi cadastrado o total de alunos no sistema\n");

                        printf("");

                        if (totDataAlunos > 0)
                        {
                            if (totDataAlunos > 1)
                                printf("\nForam %d Datas cadastrados no sistema", totDataAlunos);

                            else
                                printf("\nFoi uma Data cadastrado no sistema");
                        }

                        else
                            printf("Nao foi cadastrado nenhuma Data no sistema\n");

                        printf("");

                        if (totDataAlunos > 0)
                        {
                            if (somaIdades > 1)
                                printf("\nA soma da idades cadastrados no sistema foi: %d", somaIdades);
                        }

                        else
                            printf("Nao foi cadastrado nenhuma Data Somada no sistema\n");

                        printf("");

                        if (totDataAlunos > 0)
                        {
                            if (mediaIdades > 1)
                                printf("\nA media da idades cadastrados no sistema foi: %2.lf", mediaIdades);
                        }

                        else
                            printf("Nao foi cadastrado nenhuma Media das Data no sistema\n");

                        printf("");

                        if (totEnderecoAlunos > 0)
                        {
                            if (totEnderecoAlunos > 1)
                                printf("\nForam %d Enderecos cadastrados no sistema\n\n", totEnderecoAlunos);
                            else
                                printf("\nFoi um Edereco cadastrado no sistema\n\n");
                        }

                        else
                            printf("Nao foi cadastrado nenhum Endereco no sistema\n\n");

                        printf("");
                    }
                } while (q != 's');
            }
        }
    } while (respMenuPrincipal != 2);
}

// Lista todos os elementos presentes na lista encadeada
void listar(Alunos *numeroAtual)
{
    while (numeroAtual != NULL) // Enquanto nao chega no fim da lista
    {
        consultarDadosOriginais(numeroAtual); // Imprime o no atual
        numeroAtual = numeroAtual->proximo;   // Faz numeroAtual apontar para o proximo no
    }
}

// Imprime um no da lista no  especificado
void consultarDadosOriginais(Alunos *alunos)
{
    printf("----------------------------- ** Dados ** -----------------------------\n");
    printf("Nome do(a) Aluno(a)    : %s", alunos->name);
    printf("CPF do(a) Aluno(a)    : %s", alunos->cpf);
    printf("Nome Da Rua do(a) Aluno(a): %s", alunos->nomeRua);
    printf("Numero da Casa do(a) Aluno(a): %s", alunos->numeroCasa);
    printf("Bairro do(a) Aluno(a): %s", alunos->bairro);
    printf("CEP do(a) Aluno(a): %s", alunos->cep);
    printf("Cidade do(a) Aluno(a): %s", alunos->cidade);
    printf("Dia de Nascimento    : %d", alunos->dia);
    printf("\nMes de Nascimento    : %d", alunos->mes);
    printf("\nAno de Nascimento    : %d", alunos->ano);
    printf("\nIdade    : %d\n\n\n", alunos->idadeAluno);
    printf("\n----------------------------- ** Dados ** -----------------------------\n\n");
}

// Funcao para inserir um novo no, ao final da lista
void inserirDadosAoAlunos(Alunos **alunos) // Veja que o parametro e' um ponteiro duplo ...
{
    Alunos *numeroAtual, *novono;
    if (*alunos == NULL) // Se ainda nao existe nenhum Alunos na lista
    {
        // cria o no(a) Aluno(a)s
        *alunos = (Alunos *)malloc(sizeof(Alunos));
        novono = *alunos;
    }

    else
    {
        // Se ja existem elementos na lista, deve percorre-la ate o seu final e inserir o novo elemento
        numeroAtual = *alunos;
        while (numeroAtual->proximo != NULL)
            numeroAtual = numeroAtual->proximo;    // Ao final do while, numeroAtual aponta para o ultimo no
        novono = (Alunos *)malloc(sizeof(Alunos)); // Aloca memoria para o novo no
        numeroAtual->proximo = novono;             // Faz o ultimo no apontar para o novo no
    }

    // No final da função, chama outra função para ler os dados
    inserirDadosOriginais(novono);
}

// Entra com os dados via teclado e armazena no no da lista
void inserirDadosOriginais(Alunos *res)
{
    integer respNotas;
    integer totNotasAluno;
    integer static totAlunosLocal = 0;

    char pressEnter[100];

    printf("---------------------------- ** Dados do %d Aluno ** ----------------------------\n", totAlunosLocal + 1);

    fgets(pressEnter, sizeof(pressEnter), stdin);

    printf("\nNome: ");
    fgets(nomeReserva, sizeof(nomeReserva), stdin);
    res->name = (char *)malloc((strlen(nomeReserva) + 1) * sizeof(char));
    strcpy(res->name, nomeReserva); // Copia o valor do vetor String ("nomeReserva") para o atributo ("res->name")

    printf("CPF: ");
    fgets(CPFReserva, sizeof(CPFReserva), stdin);
    res->cpf = (char *)malloc((strlen(CPFReserva) + 1) * sizeof(char));
    strcpy(res->cpf, CPFReserva); // Copia o valor do vetor String ("CPFReserva") para o atributo ("res->cpf")

    printf("Rua: ");
    fgets(nomeRuaReserva, sizeof(nomeRuaReserva), stdin);
    res->nomeRua = (char *)malloc((strlen(nomeRuaReserva) + 1) * sizeof(char));
    strcpy(res->nomeRua, nomeRuaReserva); // Copia o valor do vetor String ("enderecoReserva") para o atributo ("res->endereco")

    printf("Numero da casa: ");
    fgets(numeroCasaReserva, sizeof(numeroCasaReserva), stdin);
    res->numeroCasa = (char *)malloc((strlen(numeroCasaReserva) + 1) * sizeof(char));
    strcpy(res->numeroCasa, numeroCasaReserva); // Copia o valor do vetor String ("enderecoReserva") para o atributo ("res->endereco")

    printf("CEP: ");
    fgets(cepReserva, sizeof(cepReserva), stdin);
    res->cep = (char *)malloc((strlen(cepReserva) + 1) * sizeof(char));
    strcpy(res->cep, cepReserva); // Copia o valor do vetor String ("enderecoReserva") para o atributo ("res->endereco")

    printf("Bairro: ");
    fgets(bairroReserva, sizeof(bairroReserva), stdin);
    res->bairro = (char *)malloc((strlen(bairroReserva) + 1) * sizeof(char));
    strcpy(res->bairro, bairroReserva); // Copia o valor do vetor String ("enderecoReserva") para o atributo ("res->endereco")

    printf("Cidade: ");
    fgets(cidadeReserva, sizeof(cidadeReserva), stdin);
    res->cidade = (char *)malloc((strlen(cidadeReserva) + 1) * sizeof(char));
    strcpy(res->cidade, cidadeReserva); // Copia o valor do vetor String ("enderecoReserva") para o atributo ("res->endereco")

    printf("Dia de Nascimento do(a) aluno(a): ");
    scanf("%d", &(res->dia));

    printf("Mes de Nascimento do(a) aluno(a): ");
    scanf("%d", &(res->mes));

    printf("Ano de Nascimento do(a) aluno(a): ");
    scanf("%d", &(res->ano));

    AlunosCadastradosTemp += totAlunosLocal; // Totaliza o número de Alunos Cadastrados no sistema

    totAlunos++;
    totDataAlunos++;
    totEnderecoAlunos++;

    res->idadeAluno = 2021 - res->ano;
    somaIdades += res->idadeAluno;
    mediaIdades = somaIdades / totIdades;
    totIdades++;

    printf("Deseja Somar as Suas Notas: [1] - Sim [0] - Nao: ");
    scanf("%d", &respNotas);

    if (respNotas == 1)
    {
        printf("Serao 7 o total de Notas:\n");
        totNotasAluno = 7;
        calculoDeNotasDosAlunos(totNotasAluno);
    }

    else
    {
        printf("Opps... Eu acho que voce digitou errado");
        printf("\nPor Favor, digite novamente");
        printf("\nMas realmente deseja nao digitar as suas notas? [1] - Sim [0] - Nao: ");
        scanf("%d", &respNotas);

        if (respNotas == 0)
        {
            printf("Digite o total de Notas: ");
            scanf("%d", &totNotasAluno);
            calculoDeNotasDosAlunos(totNotasAluno);
        }
    }

    res->proximo = NULL;

    printf("---------------------------- ** Dados do %d Aluno ** ----------------------------\n", totAlunosLocal + 1);
    totAlunosLocal++;
}

void menuPrincipal() // Menusinho para mostar ao iniciar o programa
{
    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ---------------- \
    \n[i] Inserir novo(a) Aluno(a)s: \
        \n[c] Consultar Turma: \
        \n[l] Listar todos Alunos:  \
        \n[d] Consultar Data Completa: \
        \n[e] Consultar Endereco Completo: \
        \n[f] Dados Extra: \
        \n[s] Sair: \
        \n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ---------------- \
        \n\nDigite sua Opcao: ");
}

void menu()
{

    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
    printf("[1] Cadastrar Data de Nascimento de Alunos: \
    \n[2] Cadastrar Residencia de Alunos: \
    \n[3] Cadastrar Dados Pessoais de Alunos: \
    \n[4] Consultar Dados Gerais dos Alunos: \
    \n[5] Sair: ");
    printf("\n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}

void menuData()
{
    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
    printf("\n[1] Consultar Data Completa: \
    \n[2] Consultar Dia do Nascimento de Alunos: \
    \n[3] Consultar Mes do Nascimento de Alunos: \
    \n[4] Consultar Ano do Nascimento de Alunos: \
    \n[5] Sair");
    printf("\n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}
void menuEndereco()
{
    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
    printf("\n[1] Consultar Endereco Completo: \
    \n[2] Sair \
    ");
    printf("\n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}
void menuAluno()
{

    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
    printf("\n[1] Consultar Lista de Alunos Completo: \
    \n[2] Consultar o Total de Alunos Cadastrados: \
    \n[3] Consultar a Turma (Situacao, soma das Notas, Media das Notas Somadas) \
    \n[4] Consultar Nome dos Alunos cadastrados: \
    \n[5] Consultar CPF de Cada Aluno: \
    \n[6] Consultar a Idade de cada Aluno: \
    \n[7] Sair");
    printf("\n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}

void menuAlunoMaisInterno()
{

    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
    printf("\n[1] Cadastramento de dados do(a) Aluno(a): \
    \n[2] Inserir Notas Do(a) aluno(a): \
    \n[3] Sair: ");
    printf("\n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}

void menuDadosCompletosDeTodosOsAlunos()
{
    printf("\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
    printf("[1] Consultar dados completos de todos os Alunos: \
    \n[2] Consultar dados envonvendo Conceito Final, notas e medias: \
    \n[3] Cadastrar Dados Pessoais de Alunos: \
    \n[4] Consultar Dados Gerais dos Alunos: \
    \n[5] Sair: ");
    printf("\n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}

void menuCadastramentoDeAlunos()
{
    printf("---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n \
    \n[1] Cadastrar Aluno \
    \n[2] Sair: \
    \n\n---------------- ** Cadastro de Alunos(Alunas) do [IFSC] ** ----------------\n");
}

void adicionarDia(Alunos *alunosDataLocal)
{

    printf("Dia de Nascimento do(a) aluno(a): ");
    scanf("%d", &(alunosDataLocal->d1->dia));
}

void adicionarMes(Alunos *alunosDataLocal)
{

    printf("Mes de Nascimento do(a) aluno(a): ");
    scanf("%d", &(alunosDataLocal->d1->mes));
}

void adicionarAno(Alunos *alunosDataLocal)
{

    printf("Ano de Nascimento do(a) aluno(a): ");
    scanf("%d", &(alunosDataLocal->d1->ano));
}

void imprimeData(Alunos *alunosDataLocal)
{
    indiceDatasAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasAlunosCadastrados);
    printf("Data Do(a) Aluno(a) %s", alunosDataLocal->name);
    printf("%d/", alunosDataLocal->dia);
    printf("%d/", alunosDataLocal->mes);
    printf("%d", alunosDataLocal->ano);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasAlunosCadastrados);
}

void retornaDia(Alunos *alunosData)
{
    indiceDatasDiaAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasDiaAlunosCadastrados);
    printf("O(a) Aluno(a) %s nasceu no Dia ", alunosData->name);
    printf("%d", alunosData->dia);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasDiaAlunosCadastrados);
}

void retornaMes(Alunos *alunosData)
{
    indiceDatasMesAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasMesAlunosCadastrados);
    printf("O(a) Aluno(a) %s nasceu no Mes ", alunosData->name);
    printf("%d", alunosData->mes);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasMesAlunosCadastrados);
}

void retornaAno(Alunos *alunosData)
{
    indiceDatasAnoAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasAnoAlunosCadastrados);
    printf("O(a) Aluno(a) %s nasceu no Ano de ", alunosData->name);
    printf("%d", alunosData->ano);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceDatasAnoAlunosCadastrados);
}

void retornaNomeRua(Alunos *alunosEndereco)
{
    indiceEnderecoNomeRuaAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNomeRuaAlunosCadastrados);
    printf("\nNome Da Rua do(a) Aluno(a): %s", alunosEndereco->nomeRua);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNomeRuaAlunosCadastrados);
}

void retornaNumeroCasa(Alunos *alunosEndereco)
{
    indiceEnderecoNumeroCasaAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNumeroCasaAlunosCadastrados);
    printf("\nNumero da Casa do(a) Aluno(a): %s", alunosEndereco->numeroCasa);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNumeroCasaAlunosCadastrados);
}

void retornaNomeBairro(Alunos *alunosEndereco)
{
    indiceEnderecoNomeBairroAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNomeBairroAlunosCadastrados);
    printf("\nBairro do(a) Aluno(a): %s", alunosEndereco->bairro);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNomeBairroAlunosCadastrados);
}

void retornaNomeCidade(Alunos *alunosEndereco)
{
    indiceEnderecoNomeCidadeAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNomeCidadeAlunosCadastrados);
    printf("\nCidade do(a) Aluno(a): %s", alunosEndereco->cidade);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoNomeCidadeAlunosCadastrados);
}

void retornaCEP(Alunos *alunosEndereco)
{
    indiceEnderecoCEPAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoCEPAlunosCadastrados);
    printf("\nCEP do(a) Aluno(a): %s", alunosEndereco->cep);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoCEPAlunosCadastrados);
}

void imprimeEnderecoCompleto(Alunos *alunosEndereco)
{
    indiceEnderecoAlunosCadastrados++;
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoAlunosCadastrados);
    printf("\nNome Do(a) Aluno(a): %s", alunosEndereco->name);
    printf("\nNome Da Rua do(a) Aluno(a): %s", alunosEndereco->nomeRua);
    printf("\nNumero da Casa do(a) Aluno(a): %s", alunosEndereco->numeroCasa);
    printf("\nBairro do(a) Aluno(a): %s", alunosEndereco->bairro);
    printf("\nCEP do(a) Aluno(a): %s", alunosEndereco->cep);
    printf("\nCidade do(a) Aluno(a): %s", alunosEndereco->cidade);
    printf("\n--------------------------- ** Grupo %d ** ---------------------------\n", indiceEnderecoAlunosCadastrados);
}

void listarDia(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaDia(alunos);       // Imprime o no atual
        alunos = alunos->proximo; // Faz alunos apontar para o proximo no
    }
}

void listarMes(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaMes(alunos);       // Imprime o no atual
        alunos = alunos->proximo; // Faz alunos apontar para o proximo no
    }
}

void listarAno(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaAno(alunos);       // Imprime o no atual
        alunos = alunos->proximo; // Faz alunos apontar para o proximo no
    }
}

void listarNomeRua(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaNomeRua(alunos);   // Imprime o no atual
        alunos = alunos->proximo; // Faz alunos apontar para o proximo no
    }
}

void listarNumeroCasa(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaNumeroCasa(alunos); // Imprime o no atual
        alunos = alunos->proximo;  // Faz alunos apontar para o proximo no
    }
}

void listarNomeBairro(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaNomeBairro(alunos); // Imprime o no atual
        alunos = alunos->proximo;  // Faz alunos apontar para o proximo no
    }
}

void listarNomeCidade(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaNomeCidade(alunos); // Imprime o no atual
        alunos = alunos->proximo;  // Faz alunos apontar para o proximo no
    }
}

void listarCEP(Alunos *alunos)
{
    while (alunos != NULL) // Enquanto nao chega no fim da lista
    {
        retornaCEP(alunos);       // Imprime o no atual
        alunos = alunos->proximo; // Faz alunos apontar para o proximo no
    }
}

void adicionarNotas()
{
    integer notas;

    printf("Digite a %d Nota do(a) Aluno(a): ", totNotasContadora);
    scanf("%d", &notas);

    somaDeNotas += notas;
    mediaDeNotasSomadas = somaDeNotas / totNotasIndice;
    totNotasContadora++;
    totNotasIndice++;
    indiceDatas++;
    notas++;
}

void calculoDeNotasDosAlunos(integer totNotas)
{
    for (integer i = 0; i < totNotas; i++)
    {
        adicionarNotas();
    }

    if (mediaDeNotasSomadas <= 0 || mediaDeNotasSomadas > 10)
    {
        printf("Media invalida\n");
    }

    else
    {
        if (mediaDeNotasSomadas < 5)
        {
            strcpy(vetorAlunosConceitoFinal, "Reprovado");
        }
        else if (mediaDeNotasSomadas >= 5 && mediaDeNotasSomadas < 7)
        {
            strcpy(vetorAlunosConceitoFinal, "Em Recuperacao");
        }
        else if (mediaDeNotasSomadas >= 7 && mediaDeNotasSomadas <= 10)
        {
            strcpy(vetorAlunosConceitoFinal, "Aprovado");
        }
    }

    acumuladorDeNotas += totNotas;

    totNotasContadora = 1; // Quando terminar de Calcular o acumulo de notas na função acima, a variável retorna para o mesmo valor de antes
}

// Funcao para inserir um novo no, ao final da lista
void inserirDadosNasDatas(Data **d1) // Veja que o parametro e' um ponteiro duplo ...
{
    Data *numeroAtual, *novono;
    if (*d1 == NULL) // Se ainda nao existe nenhum Data na lista
    {
        // cria o no Data
        *d1 = (Data *)malloc(sizeof(Data));
        novono = *d1;
    }

    else
    {
        // Se ja existem elementos na lista, deve percorre-la ate o seu final e inserir o novo elemento
        numeroAtual = *d1;
        while (numeroAtual->proximo != NULL)
            numeroAtual = numeroAtual->proximo; // Ao final do while, numeroAtual aponta para o ultimo no
        novono = (Data *)malloc(sizeof(Data));  // Aloca memoria para o novo no
        numeroAtual->proximo = novono;          // Faz o ultimo no apontar para o novo no
    }
}

void listarDataCompleta(Alunos *numeroAtual)
{
    while (numeroAtual != NULL) // Enquanto nao chega no fim da lista
    {
        imprimeData(numeroAtual);           // Imprime o no atual
        numeroAtual = numeroAtual->proximo; // Faz numeroAtual apontar para o proximo no
    }
}

void listarEnderecoCompleto(Alunos *numeroAtual)
{
    while (numeroAtual != NULL) // Enquanto nao chega no fim da lista
    {
        imprimeEnderecoCompleto(numeroAtual); // Imprime o no atual
        numeroAtual = numeroAtual->proximo;   // Faz numeroAtual apontar para o proximo no
    }
}

// Imprime um no da lista no especificado
void consultarNomesAlunos(Alunos *alunos)
{
    printf("%s", alunos->name);
}

// Lista todos os elementos presentes na lista encadeada
void listarNomeAluno(Alunos *numeroAtual)
{
    while (numeroAtual != NULL) // Enquanto nao chega no fim da lista
    {
        consultarNomesAlunos(numeroAtual);  // Imprime o no atual
        numeroAtual = numeroAtual->proximo; // Faz numeroAtual apontar para o proximo no
    }
}

// Imprime um no da lista no  especificado
void consultarCPFAlunos(Alunos *alunos)
{
    printf("Aluno %s\n", alunos->name);
    printf("CPF Cadastrado: %s\n", alunos->cpf);
    // indice--;
}

// Lista todos os elementos presentes na lista encadeada
void listarCPFAluno(Alunos *numeroAtual)
{
    while (numeroAtual != NULL) // Enquanto nao chega no fim da lista
    {
        consultarCPFAlunos(numeroAtual);    // Imprime o no atual
        numeroAtual = numeroAtual->proximo; // Faz numeroAtual apontar para o proximo no
    }
}

// Imprime um no da lista no  especificado
void consultarIdadeAlunos(Alunos *alunos)
{
    printf("Nome Cadastrado: %s", alunos->name);
    printf("Idade Cadastrada: %d\n", alunos->idadeAluno);
}

// Lista todos os elementos presentes na lista encadeada
void listarIdadeAluno(Alunos *numeroAtual)
{
    while (numeroAtual != NULL) // Enquanto nao chega no fim da lista
    {
        consultarIdadeAlunos(numeroAtual);  // Imprime o no atual
        numeroAtual = numeroAtual->proximo; // Faz numeroAtual apontar para o proximo no
    }
}
