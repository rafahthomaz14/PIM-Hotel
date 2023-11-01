

#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int selecione, x, menu, tentativa = 0;

double preco_atualizado = 0, faturamento;
double *precoP, *fatP;

// Defini��o da struct para representar um quarto
struct Quarto {
  bool disponivel;
  int andar, numero;
  double preco;
  char nome_cliente[100], cpf_cliente[15], nomeF[30];
  char data_checkin[11], data_checkout[11];
  double faturamento;
  char email[50], contato[20], senha[7];
} quartos[5][10][3]; // Inicializa��o dos quartos em uma array de structs;

void limpar_Tela() {
  system("cls || clear");
  // Limpa a tela no Windows e linux deixa a visualiza��o da tela mais fu�da
}

// A cima do main est�o variaves e fun��es globais

int main() {
  setlocale(LC_ALL, "Portuguese");

  // Vari�veis para login do funcion�rio, ponteiro e endere�o
  char *nomeP, nomeF[30];
  nomeP = &nomeF[0];

  // fun��es sendo declaradas, seus codes est�o no final do programa

  void valores(); // Valores iniciais dos quartos
  valores();      // precisa ser inicializado em primeiro, se n�o ele reseta as
                  // reservas quando o menu retorna a tela inicial

  void desenhoM(); // Desenho de tela inicial
INICIO:            // Label para retornar a tela inicial
  desenhoM();      // chamada de fun��o

  // Fun��o para o primeiro menu
  int menu1();
  // Fun��o para o menu secundario
  int menu2(int hotel, char *nomeP);
  int menu3(int hotel);
  int senha1(); // Fun��o para senha de acesso ao menu secundario

  int termosDeUso(); // LGPD

  // Menu inicial
  limpar_Tela();
  x = 0;
  tentativa = 0;
  do {
    limpar_Tela();

    printf("|-/--/--/-----------------------\\--\\--\\-|\n");
    printf("\n\tBem vindo ao Confort Haven!\n\n");
    printf("|-/--/--/-----------------------\\--\\--\\-|\n");

    printf(
        "\n\n\t1- Entrar como h�spede.\n\n\t2- Entrar como funcion�rio.\n\n");
    printf("_________________________________________\n");

    printf("\n3- Sair.\n");
    printf("_________________________________________\n\n");

    printf("Escolha uma op��o para prosseguir: ");
    scanf("%d", &x);

    switch (x) {
    case 1:
      termosDeUso();
      limpar_Tela();
      if (x == 1)
        goto INICIO;

      do {

        limpar_Tela();
        x = 0;
        tentativa = 0;

        menu1();
        switch (menu) {
        case 1:
          menu3(menu);
          if (x == 1)
            limpar_Tela();
          goto INICIO;
          break;
        case 2:
          menu3(menu);
          if (x == 1)
            limpar_Tela();
          goto INICIO;
          break;
        case 3:
          menu3(menu);
          if (x == 1)
            limpar_Tela();
          goto INICIO;
          break;
        case 4:
          limpar_Tela();
          goto INICIO;
        default:
          printf("\n\nOp��o inv�lida. Tente novamente.\n\n");
          printf("\nPressione Enter para continuar...");
          getchar();
          break;
        }
        while (getchar() != '\n')
          ;
      } while (menu < 1 || menu > 3);
      break;

    case 2:
      do {

        x = 0;
        tentativa = 0;

      REFAZ:     // r�tulo de salto para retornar ao menu hot�is (label)
        menu1(); // chamada de fun��o, primeiro menu

        switch (menu) {
        case 1:
          limpar_Tela();
          x = 0;
          tentativa = 0;
          printf("|-/--/--/-----------------------\\--\\--\\-|\n\n");
          printf("Voc� selecionou o Hotel S�o Paulo\n\n");

          printf("\tLogin de funcion�rio\n\n");
          printf("\nDigite o nome do funcion�rio: ");
          scanf(" %29[^\n]", nomeF);

          senha1(); // chamada de fun��o, senha
          limpar_Tela();
          if (x == 1)
            goto REFAZ;

          // chamada de fun��o, menu secundario
          menu2(menu, &nomeF[0]);
          if (x == 1)
            goto REFAZ; // volta para o menu inicial

          break;
        case 2:
          limpar_Tela();
          x = 0;
          tentativa = 0;
          printf("|-/--/--/-----------------------\\--\\--\\-|\n\n");
          printf("Voc� selecionou o Hotel Rio de janeiro\n\n");

          printf("\tLogin de funcion�rio\n\n");
          printf("\nDigite o nome do funcion�rio: ");
          scanf(" %29[^\n]", nomeF);

          senha1();
          limpar_Tela();
          if (x == 1)
            goto REFAZ;

          menu2(menu, &nomeF[0]);
          if (x == 1)
            goto REFAZ;

          break;
        case 3:
          limpar_Tela();
          x = 0;
          tentativa = 0;
          printf("|-/--/--/-----------------------\\--\\--\\-|\n\n");
          printf("Voc� selecionou o Hotel Salvador\n\n");

          printf("\tLogin de funcion�rio\n\n");
          printf("\nDigite o nome do funcion�rio: ");
          scanf(" %29[^\n]", nomeF);

          senha1();
          limpar_Tela();
          if (x == 1)
            goto REFAZ;

          menu2(menu, &nomeF[0]);
          if (x == 1)
            goto REFAZ;

          break;
        case 4:
          limpar_Tela();
          goto INICIO;
        default:
          printf("\n\nOp��o inv�lida. Tente novamente.\n\n");
          printf("\nPressione Enter para continuar...");
          getchar();
          break;
        }

        // Limpar o menu de entrada
        while (getchar() != '\n')
          ;

        // Se o usu�rio n�o selecionou um hotel v�lido, continue pedindo a
        // sele��o do hotel
      } while (menu < 1 || menu > 3);
      break;
    case 3:
      printf("\nSaindo do programa!\n\n");
      return 0; // Encerra o programa imediatamente
    default:
      printf("\n\nOp��o inv�lida. Tente novamente.\n\n");
      printf("\nPressione Enter para continuar...");
      getchar();
      break;
    }
    while (getchar() != '\n')
      ;
  } while (menu < 1 || menu > 3);
}

// Declara��o de fun��es semi-globais, subordinadas de outras fun��es

int precoF(struct Quarto *quarto, int hotel,
           const char *nome_hotel); // Fun��o dos aumentos nos valores

void textoP(); // pol�tica de privacidade
void textoT(); // termos de uso

// fun��es escritas abaixo do main, para evitar polui��o visual

int termosDeUso() {

POL:
  limpar_Tela();

  printf("__________________________________________\n");
  printf("\n\t1- Ler Pol�tica de Privacidade.\n\t2- Ler termos de uso.\n");
  printf("__________________________________________\n");
  printf("\n\t3- Prosseguir para sele��o de hot�is.\n");
  printf("__________________________________________\n\n");
  printf("Escolha uma op��o para prosseguir: ");
  scanf("%d", &x);

  switch (x) {

  case 1:
    textoP();
    goto POL;
    break;
  case 2:
    textoT();
    goto POL;
    break;
  case 3:
  CONF:
    x = 0;

    char senha[7];
    char senha_correta = false;

    do {
      limpar_Tela();
      printf("Voc� aceita os Termos e Condi��es de uso? \n(aceito/recuso): ");
      scanf("%s", senha);
      if (strcmp(senha, "aceito") == 0 || strcmp(senha, "Aceito") == 0) {

        senha_correta = true;
      } else {
        printf(
            "\n\nN�o � poss�vel prosseguir sem aceitar os Termos e Condi��es "
            "de uso.\n\n");

        printf("\nPressione Enter para continuar...");
        getchar();
        while (getchar() != '\n')
          ;

        do {
          limpar_Tela();
          printf("\n1- Voltar � tela inicial.\n2- Voltar � tela anterior.\n\n");
          printf("Escolha uma op��o para prosseguir: ");
          scanf("%d", &x);

          switch (x) {
          case 1:
            limpar_Tela();
            goto INICIO;
            break;
          case 2:
            goto CONF;
            break;
          default:
            printf("\n\n>> Op��o inv�lida, tente novamente. \n");

            printf("\nPressione Enter para continuar...");
            getchar();
            while (getchar() != '\n')
              ;
          }
        } while (x != 1 || x != 2);
      }
    } while (!senha_correta);
    break;
  default:
    printf("\n\n>> Op��o inv�lida, tente novamente. \n");

    printf("\nPressione Enter para continuar...");
    getchar();
    while (getchar() != '\n')
      ;
  }

  if (x == 0)
    return x;

INICIO:
  x = 1;

  return x;
}

int menu1() {

  limpar_Tela();
  printf("|-/--/--/-----------------------\\--\\--\\-|\n\n");
  printf("Qual hotel gostaria de consultar?\n\n");
  printf("1- Hotel S�o Paulo\n");
  printf("2- Hotel Rio de janeiro\n");
  printf("3- Hotel Salvador\n");
  printf("4- Voltar � tela inicial\n");

  printf("\nDigite uma op��o para continuar: ");
  scanf("%d", &menu);

  return menu;
}

int senha1() {

  int senha;
  int senha_correta = false;

  tentativa = 0;

  do {

    printf("Digite sua senha de acesso:");
    scanf("%d", &senha);
    tentativa++;

    if (senha == 123 || tentativa == 3) {
      senha_correta = true;
    } else {

      printf("\n Senha incorreta !\n\n");
      getchar();
    }

    if (tentativa == 3)
      x = 1;
    if (tentativa >= 3 && senha == 123)
      x = 0;

  } while (!senha_correta);

  printf("\nPressione Enter para continuar...\n\n");
  getchar();

  return x;
}

int menu2(int hotel, char *nomeP) {

  // Nome dos hot�is para consulta de reserva, n�o alterar a ordem
  char *nome[] = {"Hotel Salvador", "Hotel S�o Paulo", "Hotel Rio de janeiro"};

  do {
    limpar_Tela();
    printf("|-/--/--/-----------------------\\--\\--\\-|\n\n");
    printf("Menu de Op��es:\n\n");
    printf("1 - Quartos Dispon�veis\n");
    printf("2 - Reservar um Quarto\n");
    printf("3 - Cancelar a Reserva\n");
    printf("4 - Consultar a Reserva\n");
    printf("5 - Gerar Cobran�a\n");
    printf("6 - Gerar Relat�rios\n");
    printf("7 - Voltar para a sele��o de hot�is\n\n");
    printf("Escolha uma op��o para prosseguir: ");
    scanf("%d", &selecione);

    switch (selecione) {
    case 1:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 1 - Quartos Dispon�veis\n\n");

      int andar;
      printf("Selecione o andar (1�, 2�, 3�, 4�, 5�): ");
      scanf("%d", &andar);

      if (andar >= 1 && andar <= 5) {
        printf("\nQuartos dispon�veis no %d� andar:\n\n", andar);

        for (int quarto = 0; quarto < 10; quarto++) {
          if (quartos[andar - 1][quarto][hotel].disponivel) {
            printf("Quarto %d\n", quartos[andar - 1][quarto][hotel].numero);
            printf("Dispon�vel\n");
            printf("Pre�o: R$ %.2lf\n",
                   quartos[andar - 1][quarto][hotel].preco);
          } else {
            printf("Quarto %d\n", quartos[andar - 1][quarto][hotel].numero);
            printf("Indispon�vel\n");
          }
          printf("\n");
        }
      } else {
        printf("\nAndar inv�lido!\n");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;

    case 2:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      // printf("Voc� selecionou a Op��o 2 - Reservar um Quarto\n\n");

      char nome_cliente[100];
      char cpf_cliente[15];
      char email[50], contato[20], senha[7];
      // checar se o cpf possu� a quantidade correta de car�ter
      char cpf_if[] = "123.456.789-00";

      printf("Digite o nome do cliente: ");
      scanf(" %99[^\n]", nome_cliente);

      printf("Digite o email do cliente (contato@email.com): ");
      scanf(" %49[^\n]", email);

      printf("Digite o telefone de contato [(00) 90000-0000]: ");
      scanf(" %19[^\n]", contato);

      printf("Digite o CPF do cliente (000.000.000-00): ");
      scanf(" %14s", cpf_cliente);

      if (strlen(cpf_cliente) == strlen(cpf_if)) {

        printf("Digite uma senha de no max. 6 d�gitos: ");
        scanf(" %6[^\n]", senha);

        limpar_Tela();
        int andar_reserva, quarto_reserva;
        printf("\nSelecione o andar (1�, 2�, 3�, 4�, 5�): ");
        scanf("%d", &andar_reserva);

        if (andar_reserva >= 1 && andar_reserva <= 5) {
          printf("\nQuartos dispon�veis no %d� andar:\n\n", andar_reserva);
          bool quartos_disponiveis_reserva = false;

          for (int quarto = 0; quarto < 10; quarto++) {
            if (quartos[andar_reserva - 1][quarto][hotel].disponivel) {
              quartos_disponiveis_reserva = true;
              printf("Quarto %d\n",
                     quartos[andar_reserva - 1][quarto][hotel].numero);
              printf("Pre�o: R$ %.2lf\n",
                     quartos[andar_reserva - 1][quarto][hotel].preco);
              printf("Dispon�vel\n\n");
            }
          }

          if (quartos_disponiveis_reserva) {
            printf("Escolha o n�mero do quarto desejado: ");
            scanf("%d", &quarto_reserva);

            if (quarto_reserva >= 1 && quarto_reserva <= 10 &&
                quartos[andar_reserva - 1][quarto_reserva - 1][hotel]
                    .disponivel) {
              quartos[andar_reserva - 1][quarto_reserva - 1][hotel].disponivel =
                  false;
              strcpy(quartos[andar_reserva - 1][quarto_reserva - 1][hotel]
                         .nome_cliente,
                     nome_cliente);
              strcpy(quartos[andar_reserva - 1][quarto_reserva - 1][hotel]
                         .cpf_cliente,
                     cpf_cliente);
              strcpy(
                  quartos[andar_reserva - 1][quarto_reserva - 1][hotel].nomeF,
                  nomeP);
              strcpy(
                  quartos[andar_reserva - 1][quarto_reserva - 1][hotel].contato,
                  contato);
              strcpy(
                  quartos[andar_reserva - 1][quarto_reserva - 1][hotel].email,
                  email);
              strcpy(
                  quartos[andar_reserva - 1][quarto_reserva - 1][hotel].senha,
                  senha);

              // Solicite a data de check-in
              printf("\nDigite a data de check-in (dd/mm/yyyy): ");
              scanf("%10s",
                    quartos[andar_reserva - 1][quarto_reserva - 1][hotel]
                        .data_checkin);

              // Solicite a data de check-out
              printf("\nDigite a data de check-out (dd/mm/yyyy): ");
              scanf("%10s",
                    quartos[andar_reserva - 1][quarto_reserva - 1][hotel]
                        .data_checkout);

              while (getchar() != '\n')
                ;

            } else {
              printf(
                  "\nQuarto selecionado n�o est� dispon�vel ou � inv�lido.\n");
            }
          } else {
            printf("\nNenhum quarto dispon�vel neste andar para reserva.\n");
          }
        } else {
          printf("\nAndar inv�lido!\n");
        }
      } else {
        printf("\nCPF inv�lido!");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;

    case 3:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 3 - Cancelar a Reserva\n\n");

      char cpf_cliente_cancelar[15];

      printf("Digite o CPF do cliente para cancelar a reserva: ");
      scanf(" %14s", cpf_cliente_cancelar);

      bool reserva_encontrada = false;

      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 3; k++) {
            if (!quartos[i][j][k].disponivel &&
                strcmp(quartos[i][j][k].cpf_cliente, cpf_cliente_cancelar) ==
                    0) {
              quartos[i][j][k].disponivel = true;
              strcpy(quartos[i][j][k].nome_cliente, "");
              strcpy(quartos[i][j][k].cpf_cliente, "");
              strcpy(quartos[i][j][k].email, "");
              strcpy(quartos[i][j][k].contato, "");
              strcpy(quartos[i][j][k].nomeF, "");
              strcpy(quartos[i][j][k].senha, "");
              reserva_encontrada = true;
            }
          }
        }
      }

      if (reserva_encontrada) {
        printf("\nReserva cancelada com sucesso.\n\n");
      } else {
        printf("\n\nCPF inv�lido. N�o foi poss�vel encontrar a reserva.\n");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;

    case 4:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 4 - Consultar a Reserva\n\n");

      char cpf_consulta[15];
      printf("Digite o CPF do cliente para consultar a reserva: ");
      scanf(" %14s", cpf_consulta);

      bool reserva_encontrada_consulta = false;

      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 3; k++) {
            if (!quartos[i][j][k].disponivel &&
                strcmp(quartos[i][j][k].cpf_cliente, cpf_consulta) == 0) {
              printf("\nReserva encontrada: ");
              printf("%s\n", nome[k]);
              printf("Realiza por: %s\n", quartos[i][j][k].nomeF);
              printf("\n");
              printf("Andar: %d\n", quartos[i][j][k].andar);
              printf("N�mero do Quarto: %d\n", quartos[i][j][k].numero);
              printf("Nome do Cliente: %s\n", quartos[i][j][k].nome_cliente);
              printf("CPF do Cliente: %s\n", quartos[i][j][k].cpf_cliente);
              printf("Email do Cliente: %s\n", quartos[i][j][k].email);
              printf("Telefone de contato do Cliente: %s\n",
                     quartos[i][j][k].contato);
              printf("Data de Check-in: %s\n", quartos[i][j][k].data_checkin);
              printf("Data de Check-out: %s\n", quartos[i][j][k].data_checkout);
              // Chame a fun��o precoF para exibir o pre�o atualizado
              precoF(&quartos[i][j][k], menu, nome[hotel - 1]);
              printf("\n");
              reserva_encontrada_consulta = true;
            }
          }
        }
      }

      if (!reserva_encontrada_consulta) {
        printf("\n\nCPF inv�lido. N�o foi poss�vel encontrar a reserva.\n");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;

    case 5:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 5 - Gerar Cobran�a\n\n");

      int andar_cobranca;
      printf("Digite o andar para gerar a cobran�a (1�, 2�, 3�, 4�, 5�): ");
      scanf("%d", &andar_cobranca);

      if (andar_cobranca >= 1 && andar_cobranca <= 5) {
        // Vari�vel para rastrear se h� pelo menos um quarto ocupado no andar
        bool quarto_ocupado = false;
        int quarto_pago = -1;

        printf("\nQuartos ocupados no %d� andar:\n\n", andar_cobranca);
        for (int quarto = 0; quarto < 10; quarto++) {
          if (!quartos[andar_cobranca - 1][quarto][hotel].disponivel) {
            printf("Quarto %d\n",
                   quartos[andar_cobranca - 1][quarto][hotel].numero);

            printf("\n");
            quarto_ocupado = true;
          }
        }

        if (quarto_ocupado) {
          int quarto_cobranca;
          printf("Escolha o n�mero do quarto para gerar a cobran�a: ");
          scanf("%d", &quarto_cobranca);

          if (quarto_cobranca >= 1 && quarto_cobranca <= 10 &&
              !quartos[andar_cobranca - 1][quarto_cobranca - 1][hotel]
                   .disponivel) {
            quarto_pago = quarto_cobranca - 1;

            // Exibir informa��es detalhadas da reserva
            printf("Reserva realiza por: %s\n",
                   quartos[andar_cobranca - 1][quarto_pago][hotel].nomeF);
            printf("\n");
            printf(
                "Nome do Cliente: %s\n",
                quartos[andar_cobranca - 1][quarto_pago][hotel].nome_cliente);
            printf("CPF do Cliente: %s\n",
                   quartos[andar_cobranca - 1][quarto_pago][hotel].cpf_cliente);
            printf("Email do Cliente: %s\n",
                   quartos[andar_cobranca - 1][quarto_pago][hotel].email);
            printf("Telefone de contato do Cliente: %s\n",
                   quartos[andar_cobranca - 1][quarto_pago][hotel].contato);

            // Chamando precoF para atualizar o pre�o
            precoF(&quartos[andar_cobranca - 1][quarto_pago][hotel], hotel,
                   nome[hotel]);

            printf(
                "Data de Check-in: %s\n",
                quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkin);
            printf(
                "Data de Check-out: %s\n",
                quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkout);
            printf("\n");

            int pagamento_confirmado;
            printf("Quarto %d pago? (1 para sim, 0 para n�o): ",
                   quarto_cobranca);
            scanf("%d", &pagamento_confirmado);

            if (pagamento_confirmado == 1) {

              // Calcular faturamento
              precoF(&quartos[andar_cobranca - 1][quarto_pago][hotel], hotel,
                     nome[hotel]);

              fatP = &faturamento;
              precoP = &preco_atualizado;

              double result = (*fatP) + (*precoP);

              faturamento += result;

              quartos[andar_cobranca - 1][quarto_pago][hotel].faturamento =
                  *fatP;

              // Marcar o quarto como dispon�vel novamente
              quartos[andar_cobranca - 1][quarto_pago][hotel].disponivel = true;
              strcpy(
                  quartos[andar_cobranca - 1][quarto_pago][hotel].nome_cliente,
                  "");
              strcpy(
                  quartos[andar_cobranca - 1][quarto_pago][hotel].cpf_cliente,
                  "");
              strcpy(
                  quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkin,
                  "");
              strcpy(
                  quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkout,
                  "");
              strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].nomeF, "");
              strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].email, "");
              strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].contato,
                     "");
              strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].senha, "");
            }
          } else {
            printf("\nQuarto selecionado n�o est� ocupado ou � inv�lido.\n");
          }
        } else {
          printf("\nNenhum quarto ocupado neste andar para gerar cobran�a.\n");
        }
      } else {
        printf("\nAndar inv�lido!\n");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar(); // Limpa o buffer do teclado
      break;

    case 6:
      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 6 - Gerar Relat�rios\n\n");

      int andar_relatorio;

      printf("\n1- Relat�rio dos andares.\n2- Faturamento.\n\nEscolha uma das "
             "op��es: ");
      scanf("%d", &x);

      switch (x) {

      case 1:
        limpar_Tela();
        printf("Digite o andar para gerar o relat�rio (1�, 2�, 3�, 4�, 5�): ");
        scanf("%d", &andar_relatorio);

        if (andar_relatorio >= 1 && andar_relatorio <= 5) {
          // Loop para percorrer os quartos do andar especificado e mostra na
          // tela apenas
          printf("Relat�rio de Quartos no %d� andar:\n\n", andar_relatorio);
          for (int quarto = 0; quarto < 10; quarto++) {
            printf("Andar: %d\n",
                   quartos[andar_relatorio - 1][quarto][hotel].andar);
            printf("N�mero do Quarto: %d\n",
                   quartos[andar_relatorio - 1][quarto][hotel].numero);
            printf("Disponibilidade: %s\n",
                   quartos[andar_relatorio - 1][quarto][hotel].disponivel
                       ? "Dispon�vel"
                       : "Indispon�vel");

            precoF(&quartos[andar_relatorio - 1][quarto][hotel], hotel,
                   nome[hotel]);

            if (!quartos[andar_relatorio - 1][quarto][hotel].disponivel) {
              printf("Nome do Cliente: %s\n",
                     quartos[andar_relatorio - 1][quarto][hotel].nome_cliente);
              printf("CPF do Cliente: %s\n",
                     quartos[andar_relatorio - 1][quarto][hotel].cpf_cliente);
              printf("Email do Cliente: %s\n",
                     quartos[andar_relatorio - 1][quarto][hotel].email);
              printf("Telefone de contato do Cliente: %s\n",
                     quartos[andar_relatorio - 1][quarto][hotel].contato);
              printf("Reserva realiza por: %s\n",
                     quartos[andar_relatorio - 1][quarto][hotel].nomeF);
              printf("Reserva realiza por: %s\n",
                     quartos[andar_relatorio - 1][quarto][hotel].senha);
            }
            printf("\n");
          }
        } else {
          printf("Andar inv�lido!\n");
        }
        break;
      case 2:
        limpar_Tela();
        printf("Digite o andar para gerar o relat�rio (1�, 2�, 3�, 4�, 5�): ");
        scanf("%d", &andar_relatorio);

        if (andar_relatorio >= 1 && andar_relatorio <= 5) {
          // Loop para percorrer os quartos do andar especificado e mostra na
          // tela apenas
          printf("Relat�rio de Quartos no %d� andar:\n\n", andar_relatorio);
          for (int quarto = 0; quarto < 10; quarto++) {
            printf("Andar: %d\n",
                   quartos[andar_relatorio - 1][quarto][hotel].andar);
            printf("N�mero do Quarto: %d\n",
                   quartos[andar_relatorio - 1][quarto][hotel].numero);
            printf("Faturamento total do quarto: %.2lf\n\n",
                   quartos[andar_relatorio - 1][quarto][hotel].faturamento);
          }
          printf("\n");

        } else {
          printf("Andar inv�lido!\n");
        }
        break;
      default:
        limpar_Tela();
        printf("\nOp��o inv�lida. Tente novamente.\n\n");
        printf("\nPressione Enter para continuar...");
        getchar();
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;

    case 7:
      goto REFAZ; // volta para onde a palavra estiver, usar a variavel com
                  // modera��o!!!
      break;

    default:
      limpar_Tela();
      printf("\nOp��o inv�lida. Tente novamente.\n\n");
      printf("\nPressione Enter para continuar...");
      getchar();
    }

    // Limpar o menu de entrada
    while (getchar() != '\n')
      ;
  } while (selecione != 7);

  if (x == 0)
    return x;

REFAZ:
  x = 1;

  return x;
}

int menu3(int hotel) {

  char *nome[] = {"Hotel Salvador", "Hotel S�o Paulo", "Hotel Rio de janeiro"};

  do {
    limpar_Tela();
    printf("|-/--/--/-----------------------\\--\\--\\-|\n\n");
    printf("Menu de Op��es:\n\n");
    printf("1 - Quartos Dispon�veis\n");
    printf("2 - Consultar a Reserva\n");
    printf("3 - Voltar para a sele��o de hot�is\n\n");
    printf("Escolha uma op��o para prosseguir: ");
    scanf("%d", &selecione);

    switch (selecione) {
    case 1:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 1 - Quartos Dispon�veis\n\n");

      printf("_________________________________________________________________"
             "\n");
      printf("\nOBSERVA��O!\n\nA cada 7 dias as reservas sofrem um aumento "
             "10%% no valor inicial.\n\n");
      printf("Quartos do 1� andar s�o Standard.\nQuartos do 2� e 3� andar s�o "
             "Master.\nQuartos do 4� e 5� andar s�o Deluxe.\n");
      printf("_________________________________________________________________"
             "\n\n\n");

      int andar;
      printf("Selecione o andar (1�, 2�, 3�, 4�, 5�): ");
      scanf("%d", &andar);

      if (andar >= 1 && andar <= 5) {
        printf("\nQuartos dispon�veis no %d� andar:\n\n", andar);

        for (int quarto = 0; quarto < 10; quarto++) {
          if (quartos[andar - 1][quarto][hotel].disponivel) {
            printf("Quarto %d\n", quartos[andar - 1][quarto][hotel].numero);
            printf("Dispon�vel\n");
            printf("Pre�o: R$ %.2lf\n",
                   quartos[andar - 1][quarto][hotel].preco);
          } else {
            printf("Quarto %d\n", quartos[andar - 1][quarto][hotel].numero);
            printf("Indispon�vel\n");
          }
          printf("\n");
        }
      } else {
        printf("\nAndar inv�lido!\n");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;
    case 2:

      limpar_Tela();
      printf("|-/--/--/-------------------------------------------------\n\n");
      printf("Voc� selecionou a Op��o 2 - Consultar a Reserva\n\n");

      char cpf_consulta[15], senha_consulta[7];
      printf("Digite o CPF do cliente para consultar a reserva: ");
      scanf(" %14s", cpf_consulta);

      printf("Digite a senha do cliente para consultar a reserva: ");
      scanf(" %6[^\n]", senha_consulta);

      bool reserva_encontrada_consulta = false;

      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 3; k++) {
            if (!quartos[i][j][k].disponivel &&
                strcmp(quartos[i][j][k].cpf_cliente, cpf_consulta) == 0 &&
                strcmp(quartos[i][j][k].senha, senha_consulta) == 0) {
              printf("\nReserva encontrada: ");
              printf("%s\n", nome[k]);
              printf("Realiza por: %s\n", quartos[i][j][k].nomeF);
              printf("\n");
              printf("Andar: %d\n", quartos[i][j][k].andar);
              printf("N�mero do Quarto: %d\n", quartos[i][j][k].numero);
              printf("Nome do Cliente: %s\n", quartos[i][j][k].nome_cliente);
              printf("Data de Check-in: %s\n", quartos[i][j][k].data_checkin);
              printf("Data de Check-out: %s\n", quartos[i][j][k].data_checkout);
              // Chame a fun��o precoF para exibir o pre�o atualizado
              precoF(&quartos[i][j][k], menu, nome[hotel - 1]);
              printf("\n");
              reserva_encontrada_consulta = true;
            }
          }
        }
      }

      if (!reserva_encontrada_consulta) {
        printf("\n\nCPF ou senha inv�lido. N�o foi poss�vel encontrar a "
               "reserva.\n");
      }

      printf("\nPressione Enter para voltar ao menu...");
      getchar();
      break;
    case 3:
      goto REFAZ; // volta para onde a palavra estiver, usar a variavel com
                  // modera��o!!!
      break;

    default:
      limpar_Tela();
      printf("Op��o inv�lida. Tente novamente.\n\n");
      printf("\nPressione Enter para continuar...");
      getchar();
    }

    // Limpar o menu de entrada
    while (getchar() != '\n')
      ;

  } while (selecione != 3);

  if (x == 0)
    return x;

REFAZ:
  x = 1;

  return x;
}

int precoF(struct Quarto *quarto, int hotel, const char *nome_hotel) {
  // Verificar se o quarto est� reservado
  if (!quarto->disponivel) {
    // Obtenha a data atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char data_atual[11];
    sprintf(data_atual, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1,
            tm.tm_mday);

    // Converter datas para o formato ano-m�s-dia (yyyy-mm-dd) para
    // facilitar a compara��o
    int ano_checkin, mes_checkin, dia_checkin;
    int ano_checkout, mes_checkout, dia_checkout;
    int ano_atual, mes_atual, dia_atual;

    sscanf(quarto->data_checkin, "%d/%d/%d", &dia_checkin, &mes_checkin,
           &ano_checkin);
    sscanf(quarto->data_checkout, "%d/%d/%d", &dia_checkout, &mes_checkout,
           &ano_checkout);
    sscanf(data_atual, "%d-%d-%d", &ano_atual, &mes_atual, &dia_atual);

    // Calcule a diferen�a de dias
    int dias_restantes = (ano_checkout - ano_atual) * 365 +
                         (mes_checkout - mes_atual) * 30 +
                         (dia_checkout - dia_atual);

    // Calcule o pre�o com base nas semanas adicionais (ap�s a primeira
    // semana)
    preco_atualizado = quarto->preco;

    if (dias_restantes > 7) {
      int dias_excedentes = dias_restantes - 7;
      int semanas_adicionais =
          (dias_excedentes + 5) / 6; // Arredondamento para cima

      preco_atualizado +=
          semanas_adicionais *
          (0.10 * quarto->preco); // 10% a mais por semana adicional
    }

    // Exibir o pre�o atualizado apenas para quartos reservados
    printf("Pre�o:R$ %.2lf\n", preco_atualizado);
  }

  return preco_atualizado;
}

void valores() {

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 3; k++) {
        quartos[i][j][k].disponivel = true;
        quartos[i][j][k].andar = i + 1;
        quartos[i][j][k].numero = j + 1;

        switch (i + 1) { // pre�os por andar
        case 1:
          quartos[i][j][k].preco = 500.00;
          break;
        case 2:
          quartos[i][j][k].preco = 700.00;
          break;
        case 3:
          quartos[i][j][k].preco = 900.00;
          break;
        case 4:
          quartos[i][j][k].preco = 1100.00;
          break;
        case 5:
          quartos[i][j][k].preco = 1300.00;
          break;
        }
      }
    }
  }
}

void desenhoM() {

  printf("              ________________\n");
  printf("             //        / /    \\ \n");
  printf("            //        / /      \\ \n");
  printf("           //________/ /        \\ \n");
  printf("          //        / /          \\ \n");
  printf("         //        / /            \\ \n");
  printf("        //________/ /              \\ \n");
  printf("       //        / /                \\ \n");
  printf("      //        / /                  \\ \n");
  printf("     //________/ /                    \\ \n");
  printf("    //        / /______________________\\ \n");
  printf("   //        / /      _________         \\ \n");
  printf("  //        / /      /       / \\         \\ \n");
  printf(" //________/ /______/_______/___\\_________\\ \n");
  printf("   | |    | |       _____________      | |    \n");
  printf("   | |    | |       |____   ____|      | | \n");
  printf("   | |    | |  _______   | |   ______  | | \n");
  printf("   | |____| | |  ___  |  | |  |   ___| | | \n");
  printf("   |  ____  | | |   | |  | |  |  |___  | | \n");
  printf("   | |    | | | |   | |  | |  |   ___| | | \n");
  printf("   | |    | | | |___| |  | |  |  |___  | |______\n");
  printf("   |_|    |_| |_______|  |_|  |______| |________|\n\n");

  // Desenho que vai aparecer na tela inicial antes de iniciar o projeto
  printf("Pressione Enter para continuar...");
  getchar();

  while (getchar() != '\n')
    ;
}

void textoP() {
  limpar_Tela();

  printf("\n\tPol�tica de Privacidade de Dados:\n");

  printf("\n\t  N�s, da Confort Haven, respeitamos a sua privacidade e nos "
         "comprometemos a proteger os seus dados pessoais. Esta pol�tica de "
         "privacidade tem como objetivo informar voc� sobre como tratamos os "
         "seus "
         "dados pessoais quando voc� utiliza os nossos servi�os, seja atrav�s "
         "do "
         "nosso site, aplicativo, telefone ou presencialmente.\n\n  Dados "
         "pessoais s�o todas as informa��es que se referem a uma pessoa "
         "natural "
         "identificada ou identific�vel, como nome, CPF, e-mail, telefone, "
         "endere�o, dados de pagamento, prefer�ncias de hospedagem, entre "
         "outros.\n\n  Ao utilizar os nossos servi�os, voc� nos fornece "
         "alguns "
         "dados pessoais que s�o necess�rios para a presta��o dos servi�os "
         "contratados, tais como:\n\n  - Dados de identifica��o: nome "
         "completo, "
         "CPF, RG, data de nascimento, nacionalidade, estado civil;\n\n  - "
         "Dados "
         "de contato: e-mail, telefone, endere�o;\n\n- Dados de pagamento: "
         "n�mero "
         "do cart�o de cr�dito, c�digo de seguran�a, data de validade;\n\n- "
         "Dados "
         "de hospedagem: data de entrada e sa�da, n�mero de h�spedes, tipo de "
         "quarto, servi�os adicionais solicitados;\n\n- Dados de "
         "prefer�ncias: "
         "prefer�ncias de quarto, alimenta��o, lazer, entretenimento;\n\nN�s "
         "tratamos os seus dados pessoais com base no seu consentimento, que "
         "� "
         "manifestado quando voc� aceita esta pol�tica de privacidade. Voc� "
         "pode "
         "retirar o seu consentimento a qualquer momento, entrando em contato "
         "conosco pelos canais indicados ao final desta pol�tica. A retirada "
         "do "
         "consentimento n�o afeta a legalidade do tratamento realizado com "
         "base "
         "no consentimento anterior.\n\nN�s utilizamos os seus dados pessoais "
         "para as seguintes finalidades:\n\n- Prestar os servi�os contratados "
         "por "
         "voc�;\n\n- Enviar confirma��es e lembretes sobre a sua "
         "reserva;\n\n- "
         "Enviar ofertas e promo��es personalizadas sobre os nossos "
         "servi�os;\n\n- Realizar pesquisas de satisfa��o e melhorar a "
         "qualidade "
         "dos nossos servi�os;\n\n- Cumprir obriga��es legais e "
         "regulat�rias;\n\nN�s compartilhamos os seus dados pessoais com os "
         "seguintes destinat�rios:\n\n- Parceiros comerciais que nos auxiliam "
         "na "
         "presta��o dos servi�os contratados por voc�, como empresas de "
         "transporte, alimenta��o e lazer;\n\n- Fornecedores de servi�os "
         "tecnol�gicos que nos apoiam na opera��o e seguran�a dos nossos "
         "sistemas;\n\n- Autoridades p�blicas competentes que nos solicitam "
         "os "
         "seus dados pessoais por motivos legais ou regulat�rios;\n\nN�s "
         "armazenamos os seus dados pessoais pelo tempo necess�rio para "
         "cumprir "
         "as finalidades para as quais foram coletados, respeitando os prazos "
         "legais e regulat�rios aplic�veis.\n\nN�s adotamos medidas t�cnicas "
         "e "
         "administrativas adequadas para proteger os seus dados pessoais "
         "contra "
         "perdas, danos, acessos n�o autorizados, altera��es indevidas ou "
         "divulga��o indevida.\n\nVoc� tem os seguintes direitos em rela��o "
         "aos "
         "seus dados pessoais:\n\n- Acessar os seus dados pessoais que est�o "
         "sob "
         "o nosso controle;\n\n- Corrigir ou atualizar os seus dados pessoais "
         "que "
         "estejam incompletos ou incorretos;\n\n- Solicitar a exclus�o dos "
         "seus "
         "dados pessoais que n�o sejam mais necess�rios para as finalidades "
         "para "
         "as quais foram coletados;\n\n- Solicitar a portabilidade dos seus "
         "dados "
         "pessoais para outro fornecedor de servi�os similares aos "
         "nossos;\n\n- "
         "Solicitar a limita��o ou a oposi��o ao tratamento dos seus dados "
         "pessoais em determinadas situa��es;\n\nPara exercer os seus "
         "direitos ou "
         "tirar d�vidas sobre esta pol�tica de privacidade, voc� pode entrar "
         "em "
         "contato conosco pelos seguintes canais:\n\n- E-mail: "
         "contato@Confort "
         "Haven.com.br\n- Telefone: (11) 1234-5678\n- Endere�o: Rua das "
         "Capitais, "
         "123 - Centro - S�o Paulo - SP\n\nEsta pol�tica de privacidade pode "
         "ser "
         "alterada periodicamente para refletir as mudan�as na nossa forma de "
         "tratar os seus dados pessoais. N�s recomendamos que voc� consulte "
         "esta "
         "pol�tica regularmente para se manter informado sobre as nossas "
         "pr�ticas.\n\nEsta pol�tica de privacidade foi atualizada em "
         "25/10/2023.\n");

  getchar();
  while (getchar() != '\n')
    ;
}
void textoT() {
  limpar_Tela();

  printf("\n\n\tTermos de uso:\n");

  printf("\n\t  Este termo de uso estabelece as condi��es gerais para a "
         "utiliza��o "
         "dos servi�os oferecidos pela Confort Haven, seja atrav�s do nosso "
         "site, "
         "aplicativo, telefone ou presencialmente.\n\n  Ao utilizar os nossos "
         "servi�os, voc� declara que leu, compreendeu e aceitou este termo de "
         "uso, bem como a nossa pol�tica de privacidade, que faz parte "
         "integrante "
         "deste termo.\n\n  Voc� tamb�m declara que � maior de 18 anos e tem "
         "plena "
         "capacidade para contratar os nossos servi�os.\n\n  Os nossos "
         "servi�os "
         "consistem em oferecer acomoda��es confort�veis e de qualidade, com "
         "diversas op��es de quarto, alimenta��o, lazer e entretenimento.\n\n "
         " "
         "Para "
         "contratar os nossos servi�os, voc� precisa fornecer alguns dados "
         "pessoais, conforme descrito na nossa pol�tica de privacidade. Voc� "
         "� "
         "respons�vel pela veracidade e atualiza��o dos seus dados "
         "pessoais.\n\n  Voc� pode realizar a sua reserva pelo nosso "
         "aplicativo "
         "ou "
         "entrando em contato com hotel, escolhendo o tipo de quarto, a data "
         "de "
         "entrada e sa�da, o n�mero de h�spedes e os servi�os adicionais que "
         "desejar.\n\n  Voc� pode pagar pela sua reserva com cart�o de "
         "cr�dito ou "
         "d�bito, ou ainda no momento do check-in.\n\n  Voc� pode cancelar ou "
         "alterar a sua reserva at� 24 horas antes da data prevista para o "
         "check-in, sem custo adicional. Caso contr�rio, ser� cobrada uma "
         "multa "
         "equivalente ao valor fixo do quarto.\n\n  Voc� deve respeitar as "
         "normas "
         "internas da Confort Haven durante a sua hospedagem, tais como:\n\n  "
         "  - "
         "N�o fumar nas depend�ncias internas do hotel;\n\n    - N�o "
         "perturbar o "
         "sossego dos demais h�spedes;\n\n    - N�o danificar ou subtrair os "
         "bens "
         "do hotel;\n\n    - N�o levar animais de estima��o sem autoriza��o "
         "pr�via;\n\n  A Confort Haven se reserva o direito de recusar ou "
         "encerrar "
         "a hospedagem de qualquer h�spede que descumprir as normas internas "
         "ou "
         "causar transtornos aos demais h�spedes ou funcion�rios.\n\n  A "
         "Confort "
         "Haven n�o se responsabiliza por objetos deixados ou esquecidos nas "
         "depend�ncias do hotel. Recomendamos que voc� utilize o cofre do seu "
         "quarto para guardar os seus objetos de valor.\n\n  A Confort Haven "
         "pode "
         "alterar este termo de uso a qualquer momento, sem aviso pr�vio. As "
         "altera��es entrar�o em vigor na data da sua publica��o no nosso "
         "site ou "
         "aplicativo. Recomendamos que voc� consulte este termo regularmente "
         "para "
         "se manter informado sobre as nossas condi��es de uso.\n\n  Este "
         "termo "
         "de "
         "uso � regido pelas leis brasileiras. Qualquer controv�rsia "
         "decorrente "
         "deste termo ser� submetida ao foro da comarca de S�o Paulo - "
         "SP.\n\n  Este termo de uso foi atualizado em 25/10/2023.\n");

  getchar();
  while (getchar() != '\n')
    ;
}
