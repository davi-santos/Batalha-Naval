#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

#define TAM 10
#define LETRA_MINUSCULA(x) (x >= 'a' && x <= 'j')
#define LETRA_MAIUSCULA(x) (x >= 'A' && x <= 'J')
#define CONFERE_LETRA(x) (LETRA_MINUSCULA(x) || LETRA_MAIUSCULA(x))

	void LimparTabuleiro (int **t){
		int i, j;
		for (i=0; i<TAM; i++)
			for (j=0; j<TAM; j++)
				t[i][j] = 0;
	}

	void LimparTela(){
		printf("\e[H\e[2J");
		printf("\n");
	}

	void ImprimirTabuleirosJogadas(int **t1, int **t2){

		int i, j;

		printf("\t  A    B    C    D    E    F    G    H    I    J  \t\t     A    B    C    D    E    F    G    H    I    J\n");
		printf("        --------------------------------------------------\t\t    --------------------------------------------------");

		for (i=0; i<TAM; i++){
			if (i!=9)
				printf("\n      %d|",i+1);
			else
				printf("\n     %d|",i+1);

			for (j=0; j<TAM; j++){

				if (t1[i][j]==0 || t1[i][j] == -1){
					printf("    |");
				}else if (t1[i][j] == 50){
						printf("  P |");
					}else if (t1[i][j] == 40){
							printf("  G |");
						}else if (t1[i][j] == 30){
								printf("  C |");
							}else if (t1[i][j] == 31){
									printf("  S |");
								}else if(t1[i][j] == 20){
										printf("  D |");
									}else if(t1[i][j] == -2){
											printf("  X |");
										}else if(t1[i][j] == -3){
											printf("  * |");
										}
			}

			printf("\t\t");

			if (i!=9)
				printf("  %d|",i+1);
			else
				printf(" %d|",i+1);

			for (j=0; j<TAM; j++){

				if (t2[i][j] == -1){
					printf("  O |");
				}else if (t2[i][j] == -2){
						printf("  X |");
					}else if (t2[i][j] == -3){
							printf("  * |");
						}else{
							printf("    |");
						}
				}

				printf("\n        --------------------------------------------------                  -------------------------------------------------- ");
			}
	}

	void legenda (){
		printf("\n\t\tLegenda: \n\t\t P - Porta Avioes\t\t\t O - Agua\n\t\t G - Navio de Guerra\t\t\t X - Fogo\n\t\t C - Cruzador\t\t\t\t * - Afundou Navio\n\t\t S - Submarino\n\t\t D - Destruidor\n");
	}

	void ImprimirTabuleiro (int **t){
		int i=0, j=0;

		printf("\t\t\t\t\t\t    A    B    C    D    E    F    G    H    I    J\n");
		printf("\t\t\t\t\t\t  --------------------------------------------------  ");

		for (i=0; i<TAM; i++){
			if (i!=9)
				printf("\n\t\t\t\t\t        %d|",i+1);
			else
				printf("\n\t\t\t\t\t       %d|",i+1);

			for (j=0; j<TAM; j++){

				if (t[i][j]==0){
					printf("    |");
				}else if (t[i][j] == 50){
						printf("  P |");
					}else if (t[i][j] == 40){
							printf("  G |");
						}else if (t[i][j] == 30){
								printf("  C |");
							}else if (t[i][j] == 31){
									printf("  S |");
								}else if(t[i][j] == 20)
										printf("  D |");

			}
				if (i==2)
					printf("\t\tLegenda:");
				else
					if (i==3)
						printf("\t\t P - Porta Avioes");
					else if (i==4)
							printf("\t\t G - Navio de Guerra");
						else if (i==5)
								printf("\t\t C - Cruzador");
							else if (i==6)
									printf("\t\t S - Submarino");
								else if(i==7)
										printf("\t\t D - Destruidor");

				printf("\n\t\t\t\t\t\t  --------------------------------------------------");
		}
	}

	void Instrucoes (){
		LimparTela();
		printf("\n\n\n\t\t\t\t\t ************************* BATALHA NAVAL*************************\n\n\n\n\t Preparacao do jogo: \n\n\t   * Cada jogador deve distribuir seus navios pelo campo de batalha. Sao cinco tipos de navios: \n\n\t\t [1]Porta avioes (tamanho 5)\t\t[2]Navio de Guerra (tamanho 4) \n\t\t [3]Cruzador (tamanho 3)\t\t[4]Submarino (tamanho 3)\n\t\t [5]Destruidor (tamanho2)\n\n\t  * Os navios podem ser colocados horizontalmente ou verticalmente\n\n\t\t horizontal - da posicao escolhida (linha e coluna) para a direita\n\t\t vertical - da posicao escolhida (linha e coluna) para baixo \n\n\n\t  * Voce pode escolher apenas um de cada tipo de navio para colocar no seu tabuleiro.\n\n\n\t O jogo: \n\n\t\t O primeiro jogador ira dar as coordenadas 3 (tres) tiros fornecendo o numero e letra equivalentes ao quadrado que atirou; No  tabuleiro JOGO DO ADVERSARIO sera marcado: \n\n\t\t O - Agua\n\t\t X - Fogo\n\t\t * - Afundou\n\n\t\t Apos os 3 tiros, e a vez do segundo jogador dar as 3 (tres) coordenadas (tiro). \n\n\t\t O jogo termina quando um dos jogadores afundar todos os navios do seu oponente.\n");
		printf("   <--- Aperte ENTER para voltar\n\t\t\t");
		getchar();
		getchar();
	}

	void ImprimirNomeNavio(int tipo){

			if (tipo == 50) printf("Porta Avioes (tamanho 5)");
				else
	 				if (tipo == 40) printf("Navio de Guerra (tamanho 4)");
						else
							if (tipo == 30) printf("Cruzador (tamanho 3)");
								else
									if (tipo == 31) printf("Submarino (tamanho 2)");
										else
											if (tipo == 20) printf("Destruidor (tamanho 1)");

											printf("\n");
	}

	void ImprmirNavios (int *n){
		int i;
		printf("\n");
		for (i=0; i<5; i++){

				if (n[i] == 50) printf("\t\t\t[1] - Porta avioes (tamanho 5)\n");
					else
						if (n[i] == 40)	printf("\t\t\t[2] - Navio de guerra (tamanho 4)\n");
							else
								if (n[i] == 30)	printf("\t\t\t[3] - Cruzador (tamanho 3)\n");
									else
										if (n[i] == 31)	printf("\t\t\t[4] - Submarino (tamanho 3)\n");
											else
												if (n[i] == 20)	printf("\t\t\t[5] - Destruidor (tamanho 2)\n");

		}
	}

	int CabeNavioTabuleiro (int x, int y, int direcao, int tamanho){
		int retorno=0;

		if (direcao == 1 && x+tamanho<=TAM) retorno = 1;
			else
				if (direcao == 2 && y+tamanho<=TAM) retorno = 1;
						else
							retorno = 0;

		return retorno;
	}

	int TipoNavio (int tipo){
		int retorno=0;

			if (tipo == 50) retorno = 5;
				else
					if (tipo == 40) retorno = 4;
						else
							if (tipo == 30 || tipo == 31) retorno = 3;
								else
									if (tipo == 20) retorno = 2;

		return retorno;
	}

	int PosicionarNavio (int **m, int x, int y, int direcao, int tamanho, int tipo){
		int retorno=1, i, j;
		i = x;
		j = y;

		if (direcao == 1){
			for (i=x; i<x+tamanho; i++){
				if (m[i][j] != 0){
					retorno = 0;
					i = 20;
				}
			}
		}else{
			for (j=y; j<y+tamanho; j++){
				if (m[i][j] != 0){
					retorno = 0;
					j = 20;
				}
			}
		}

		if (retorno == 1){
			if (direcao == 1){
				for (i=x; i<x+tamanho; i++){
					m[i][j] = tipo;
				}
			}else{
				for (j=y; j<y+tamanho; j++){
					m[i][j] = tipo;
				}
			}
		}

		return retorno;
	}

	int EntradaValidaLinha (){
		int a;

		scanf("%d",&a);
		while (a>10 || a<1){
			printf("Valor invalido! Digite outro valor: ");
			scanf("%d",&a);
		}
		a--;
		return a;
	}

	int EntradaValidaColuna (){
		char coluna;
		int y;
		scanf("%c",&coluna);

		while (!CONFERE_LETRA(coluna)){
			setbuf(stdin,NULL);
			scanf("%c",&coluna);
		}

		if(LETRA_MINUSCULA(coluna))
			coluna -= ('a' - 'A');

			y = coluna - 'A';

		return y;
	}

	int VerificaDirecao (){
		int direcao;

		scanf("%d",&direcao);

		while (direcao!=1 && direcao!=2){
			printf("\n\t\t\t\t\t\tOpcao invalida! Digite novamente\n");
			scanf("%d",&direcao);
		}

		return direcao;
	}

	int VerificarOpcao (int navios[]){
		int flag = 0, opcao;

  		while (flag == 0){
			scanf("%d",&opcao);

			while (!(opcao>=1 && opcao<=5)){
				printf("\n\t\tDigite uma opcao valida!\n");
				scanf("%d",&opcao);
			}
			opcao--;

			if (navios[opcao] != 0)
				flag = 1;
			else
				printf("\n\t\tNavio Ja esta em uso!\n");
		}
	 return opcao;
	}

	int VerificarOpcaoComputador (int navios[]){
		int flag = 0, opcao;

  		while (flag == 0){
  			srand( (unsigned)time(NULL) );
  			opcao = 1 + (rand() % 5);

			opcao--;

			if (navios[opcao] != 0)
				flag = 1;
			
		}
	 return opcao;
	}


	void ComputadorInsereNavios(int **m,int **n){

		int x, y, direcao, navios[5], opcao, cabe, vazio, tamanho, i, flag=0;

		navios[0] = 50;
		navios[1] = 40;
		navios[2] = 30;
		navios[3] = 31;
		navios[4] = 20;

		for (i=0; i<5; i++){

			opcao = VerificarOpcaoComputador(navios);

			flag = 0;
			srand( (unsigned)time(NULL) );
			do{
				x = 1 + (rand() % 10);
				x--;

				y = 1 + (rand() % 10);
				y--;

				direcao = 1 + (rand() % 2);

				tamanho = TipoNavio(navios[opcao]);

				cabe = CabeNavioTabuleiro(x,y,direcao,tamanho);

				if (cabe == 1){
					vazio = PosicionarNavio(m,x,y,direcao,TipoNavio(navios[opcao]),navios[opcao]);

					if (vazio == 1)
						flag = 1;

				}

			}while (flag == 0);

			n[i][0] = x;
			n[i][1] = y;
			n[i][2] = direcao;
			n[i][3] = tamanho;
			n[i][4] = navios[opcao];
			navios[opcao] = 0;
		}
		LimparTela();
		printf("\t\t\tJogador: Computador\n");
		ImprimirTabuleiro(m);
		printf("\n\t\t    Aperte ENTER para continuar --->\n\t\t\t");
		getchar();
		getchar();
		LimparTela();
	}

	void InserirNaviosJogador (int **m, char *jogador, int **n){

		int x, y, direcao, navios[5], opcao, cabe, vazio, tamanho, i, flag=0;

		navios[0] = 50;
		navios[1] = 40;
		navios[2] = 30;
		navios[3] = 31;
		navios[4] = 20;

		LimparTela();
		for (i=0; i<5; i++){
			printf("\n\n\n\t\t\t\t\t ************************* BATALHA NAVAL*************************\n\n\n\t\t\tJogador: %s\n",jogador);

			ImprimirTabuleiro(m);
			printf("\n\t\t\tEscolha seu barco\n");
			ImprmirNavios(navios);

			printf("\n\t\topcao: ");
			opcao = VerificarOpcao(navios);

			//POSICIONAR BARCO
			flag = 0;
			LimparTela();
			printf("\n\n\n\t\t\t\t\t ************************* BATALHA NAVAL*************************\n\n\t\t\tJogador: %s\n\n\t\t\tPosicione o ",jogador);
            ImprimirNomeNavio(navios[opcao]);
            ImprimirTabuleiro(m);
			do{
				printf("\n\n\t\t\tDigite linha (1 - 10): ");
				x = EntradaValidaLinha();

				printf("\n\t\t\tDigite coluna (A - J): ");
				y = EntradaValidaColuna();

				printf("\n\t\t\t\t[1] vertical    [2]horizontal\n\t\t\tDirecao: ");
				direcao = VerificaDirecao();

				tamanho = TipoNavio(navios[opcao]);

				cabe = CabeNavioTabuleiro(x,y,direcao,tamanho);

				if (cabe == 1){
					vazio = PosicionarNavio(m,x,y,direcao,TipoNavio(navios[opcao]),navios[opcao]);

					if (vazio == 1)
						flag = 1;
					else
							printf("\n\t\tJa tem barco nesta posicao! Escolha outra coordenada\n");

				}else
					printf("\n\t\t\t\t\t\t\t*************Navio nao cabe aqui ****************\n");

			}while (flag == 0);

			n[i][0] = x;
			n[i][1] = y;
			n[i][2] = direcao;
			n[i][3] = tamanho;
			n[i][4] = navios[opcao];
			navios[opcao] = 0;
			LimparTela();
		}

		LimparTela();
		printf("\t\t\tJogador: %s",jogador);
		ImprimirTabuleiro(m);
		printf("\n\t\t    Aperte ENTER para continuar --->\n\t\t\t");
		getchar();
		getchar();
		LimparTela();
	}

	int Afundar (int **tabuleiro, int **navios){

		int i, j, k, l, direcao, tamanho, cont=0, cont2=0, tipo, flag = 0;

		for (i=0; i<5; i++){

			k = navios[i][0];
			l = navios[i][1];
			direcao = navios[i][2];
			tamanho = navios[i][3];
			tipo = navios[i][4];
			cont=0;

			if (direcao == 1){
				for (k = navios[i][0]; k<navios[i][0]+tamanho; k++){
					if (tabuleiro[k][l] == tipo){
						cont++;
					}
				}
			}else{
				for (l = navios[i][1]; l<navios[i][1]+tamanho; l++){
					if (tabuleiro[k][l] == tipo){
						cont++;
					}
				}
			}

			if (cont==0){
				if (direcao == 1){
					for (k=navios[i][0]; k<navios[i][0]+tamanho; k++){
						tabuleiro[k][l] = -3;
					}
				}else{
					for (l=navios[i][1]; l<navios[i][1]+tamanho; l++){
						tabuleiro[k][l] = -3;
					}
				}
			}

			k = navios[i][0];
			l = navios[i][1];

			if (tabuleiro[k][l] == -3)
				cont2++;

		}

		return cont2;
	}

	void TelaJogadas(char nome[],int **t1, int **t2, int boat, int i){
		LimparTela();
		printf("\n\tTabuleiro %s\t\t\t\t\t\t\t\t\tJogadas\n",nome);
		ImprimirTabuleirosJogadas(t1,t2);
		legenda();
		printf("\n\t\tVoce ja afundou %d barco(s)\n\t\t\tTiro %d",boat,i+1);
	}

	void TelaJogadasComputador(int **t1, int **t2, int boat, int i){
		LimparTela();
		printf("\n\tTabuleiro Computador\t\t\t\t\t\t\t\t\tJogadas\n");
		ImprimirTabuleirosJogadas(t1,t2);
		legenda();
		printf("\n\t\tVoce ja afundou %d barco(s)\n\t\t\tTiro %d",boat,i+1);
	}

	void TiroComputador (int **m){
			int flag=0, x, y;

  			srand( (unsigned)time(NULL) );
			do{
				x = 1 + (rand() % 10);
				x--;

				y = 1 + (rand() % 10);
				y--;

				//variavel c recebe o valor da posicao do tiro
				int c = m[x][y];

				if (c!=-1 && c!=-2 && c!=-3){
					flag = 1;
					if (c == 0)
						m[x][y] = -1;
					else
						m[x][y] = -2;
				}

			}while (flag == 0);
	}

	void Tiro (int **m){
			int flag=0, x, y;

			do{
				printf("\n\t\t\tDigite a linha (1-10): ");
				x = EntradaValidaLinha();

				printf("\n\t\t\tDigite a coluna (A-J): ");
				y = EntradaValidaColuna();

				//variavel c recebe o valor da posicao do tiro
				int c = m[x][y];

				if (c==-1 || c==-2 || c==-3)
					printf("\n\t\tVoce ja atirou aqui\n");
				else{
					flag = 1;
					if (c == 0)
						m[x][y] = -1;
					else
						m[x][y] = -2;
				}
			}while (flag == 0);
	}

	int Jogadas (int **t1, int **t2, int **navios,char *nome){

		int afundar, flagFim=0, i;

		for (i=0; i<3; i++){

					afundar = Afundar(t2,navios);

					TelaJogadas(nome,t1,t2,afundar,i);
					Tiro(t2);

					afundar = Afundar(t2,navios);

					if (afundar == 5){
						i = 5;
						flagFim = 1;
					}
			}

		if (flagFim == 0){
				LimparTela();
				printf("\n\tTabuleiro %s\t\t\t\t\t\t\t\t\tJogadas\n",nome);
				ImprimirTabuleirosJogadas(t1,t2);
				printf("\n\t\t INDO PARA O PROXIMO JOGADOR");
				getchar();
				getchar();
		}else{
				printf("\n\tTabuleiro %s\n",nome);
				ImprimirTabuleirosJogadas(t1,t2);
		}

			return flagFim;
	}

	void JogoFuncionando (int **tabuleiro1, int **tabuleiro2, int **navios1, int **navios2, char *nome1){

		int flagFim = 0, ganhar1=0, ganhar2=0, afundar, i;

		while (flagFim == 0){

			ganhar1 = Jogadas(tabuleiro1,tabuleiro2,navios2,nome1);

			if (ganhar1 == 1){
				flagFim = 1;
				break;
			}

			//Computador Jogando: 

			for (i=0; i<3; i++){

				afundar = Afundar(tabuleiro1,navios1);

				TelaJogadasComputador(tabuleiro2,tabuleiro1,afundar,i);
				TiroComputador(tabuleiro1);

				afundar = Afundar(tabuleiro1,navios1);

				if (afundar == 5){
					i = 5;
					ganhar2 = 1;
				}
				printf("\n\t\tPRESSIONE ENTER\n");
				getchar();
			}

			if (ganhar2 == 0){
				LimparTela();
				printf("\n\tTabuleiro Computador\t\t\t\t\t\t\t\t\tJogadas\n");
				ImprimirTabuleirosJogadas(tabuleiro2,tabuleiro1);
				printf("\n\t\t INDO PARA O PROXIMO JOGADOR");
				getchar();
			}

			if (ganhar2 == 1){
				flagFim = 2;
				break;
			}


		}

		LimparTela();

		if(flagFim == 1)
			printf("\nJogador %s - Você venceu!!!\n",nome1);
		else
			printf("\nJogador Computador - Você venceu!!!\n");

		sleep(5);
		printf("\nPressione enter para voltar ao menu\n");
		getchar();
	}

	int main() {

		int **tabuleiro1, **tabuleiro2, **navios1, **navios2, i, flag=0, opcao;
		char nome1[20], nome2[20];

		tabuleiro1 = (int**)malloc(TAM * sizeof(int*));
		tabuleiro2 = (int**)malloc(TAM * sizeof(int*));

		navios1 = (int**)malloc(5 * sizeof(int*));
		navios2 = (int**)malloc(5 * sizeof(int*));

		for (i=0; i<TAM; i++){
			tabuleiro1[i] = (int*)malloc(TAM * sizeof(int));
			tabuleiro2[i] = (int*)malloc(TAM * sizeof(int));

			navios1[i] = (int*)malloc(5 * sizeof(int));
			navios2[i] = (int*)malloc(5 * sizeof(int));
		}

		while (flag == 0){
			LimparTela();
			LimparTabuleiro(tabuleiro1);
			LimparTabuleiro(tabuleiro2);

			printf("\n\n\n\t\t\t\t\t ************************* BATALHA NAVAL*************************\n\n");
			ImprimirTabuleiro(tabuleiro1);

			printf("\n\t\t\t    [1] Comecar o jogo\n\t\t\t    [2] Instrucoes\n\t\t\t    [3] Sobre o jogo\n\t\t\t    [4] Sair\n\n\t\t  opcao: ");
			scanf("%d",&opcao);

			switch (opcao){

				case 1:
					LimparTela();
					printf("\n\n\n\t\t\t\t\t ************************* BATALHA NAVAL*************************\n\n\n\n\t\t\t\tNome Jogador 1: ");
					setbuf(stdin,NULL);
					fgets(nome1,20,stdin);
					LimparTela();
					printf("\n\n\n\t\t\t\t\t\t\t************************************\n\t\t\t\t\t\t\t************VAMOS COMECAR***********\n\t\t\t\t\t\t\t************************************\n");
					sleep(2);
					InserirNaviosJogador(tabuleiro1,nome1,navios1);
					printf("\n Computador inserindo seus dados\n");
					ComputadorInsereNavios(tabuleiro2,navios2);
					JogoFuncionando(tabuleiro1,tabuleiro2,navios1,navios2,nome1);
					break;
				case 2:
					Instrucoes();
					break;
				case 3:
					LimparTela();
					printf("\n\t  Batalha naval é um jogo de tabuleiro de dois jogadores, no qual os jogadores têm de adivinhar em que quadrados estão os navios do oponente. Tradicionalmente, este é jogado em um tabuleiro de papel, porem com o surgimento da computacao o mesmo pode ser jogado no computador\n\n\n\n <---  Aperte ENTER para voltar\n\t\t\t");
					getchar();
					getchar();
					break;
				case 4:
					flag = 1;
					break;

				default:
					LimparTela();
			}
		}
		return 0;
	}
