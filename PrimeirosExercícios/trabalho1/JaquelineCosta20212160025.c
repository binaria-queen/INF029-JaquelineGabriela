// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Jaqueline Gabriela Santos Costa  
//  email: jackgabriela2009@hotmail.com  
//  Matrícula: 20212160025
//  Semestre: 2º semestre (2022.1)

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 

// #################################################

#include <stdio.h>
#include "TRABALHO1_JAQUELINECOSTA20212160025_H" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*questão 1*/

int q1(char data[])
{
    //quebrar a string data em strings sDia, sMes, sAno

  //DataQuebrada dataQuebrada = quebraData(data);
  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);
  
    int datavalida = 1;

    DataQuebrada dq;

    dq = quebraData(data);

    if (dq.iAno >= 0 && dq.iAno < 10000)
    {
        if (dq.iMes >= 1 && dq.iMes <=12) 
        {
            if ( (dq.iDia >= 1 &&  dq.iDia <=31 && dq.iMes == 1)
              || dq.iMes == 3 || dq.iMes == 5 || dq.iMes == 7 ||
              dq.iMes == 8 || dq.iMes == 10 || dq.iMes == 12){
                datavalida = 1;
            }else if ((dq.iDia >= 1 && dq.iDia < 31) && dq.iMes == 4) ||
                      (dq.iMes == 6) || (dq.iMes == 9) || (dq.iMes == 11))
            {
                datavalida = 1;
            }
            else if (dq.iDia >= 1 && dq.iDia < 29 && dq.iMes == 2)
            {
                datavalida = 1;
            }
            else if ((dq.iDia == 29 && dq.iMes == 2) && 
              (dq.iAno % 4 == 0 && dq.iAno % 100 != 0)|| 
              dq.iAno % 400 == 0)
            {
                datavalida = 1;
            }
            else
            {
                datavalida = 0;
            }                    
        }
        else
        {
            datavalida = 0;
        }
    }

    if (datavalida)
        return 1;
    else
        return 0;


}



/* questão 2*/
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*questão 3*/
int q3(char *texto, char c, int isCaseSensitive){
  
    int qtdOcorrencias = -1, tamanho = 0;

    tamanho = strlen(texto);

    if (isCaseSensitive == 1){
    	for (int i = 0; i < tamanho; i++){
	    	if (texto[i] == c){
	    		qtdOcorrencias++;
	    	}else{
        for (int i = 0; i < tamanho; ++i){
          if (texto[i] == c || texto[i] == c -32){
            qtdOcorrencias++;
          }
        }
      }
	    return qtdOcorrencias;
}

/*questão 4*/
int q4(char *strTexto, char *strBusca,int posicoes[30]){
  
  int posicao = 0, x, acento = 0, aux = 0;
  
  for(int i = 0; i < strlen(strTexto) ; i++){
      x = 1;
      if(strTexto[i] == -61){
          acento ++;
      }
      if(strTexto[i] == strBusca[0]){
          for(int j = 1 ; strBusca[j] !='\0' && x; j++ ){
              if(strTexto[i+j] != strBusca[j]){
                  x = 0;
              }
          }
          if(x){
              posicoes[posicao] = i+1-acento;
              posicao++;
              posicoes[posicao] = i+strlen(strBusca)-acento;
              posicao++;
              i += strlen(strBusca) -1;
          }
      }
  }
  return posicao/2;
}
/*questão 5*/
int q5(int num){
    int invertido = 0;
    int mi, cm, dm, m, c, d, u;

    if(num >= 1000000 && num <= 9999999){

        mi = num / 1000000;
        cm = ((num % 1000000) / 100000) * 10;
        dm = ((num % 100000) / 10000) * 100;
        m = ((num % 10000) / 1000) * 1000;
        c = ((num % 1000) / 100) * 10000;
        d = ((num % 100) / 10) * 100000;
        u = (num % 10) * 1000000;

        invertido = mi + cm + dm + m + c + d + u;
    }
    else if(num >= 100000 && num <= 999999){

        cm = num / 100000;
        dm = ((num % 100000) / 10000) * 10;
        m = ((num % 10000) / 1000) * 100;
        c = ((num % 1000) / 100) * 1000;
        d = ((num % 100) / 10) * 10000;
        u = (num % 10) * 100000;

        invertido = cm + dm + m + c + d + u;
    }
    else if(num >= 10000 && num <= 99999){

        dm = num / 10000;
        m = ((num % 10000)/ 1000)* 10;
        c = ((num % 1000) / 100) * 100;
        d = ((num % 100) / 10) * 1000;
        u = (num % 10)* 10000;

        invertido = dm + m + c + d + u;
    }
    else if(num >= 1000 && num <= 9999){

        m = num / 1000;
        c = ((num % 100) * 10);
        d = ((num % 100) / 10) * 100;
        u = (num % 10) * 1000;

        invertido = m + c + d + u;
    }
    else if(num >= 100 && num <= 999){

        c = num / 100;
        d = ( (num % 100) / 10) * 10;
        u = (num % 10) * 100;

        invertido = c + d + u;
    }
    else if(num >= 10 && num <= 99){

        d = num / 10;
        u = (num % 10) * 10;

        invertido = d + u;
    }
    else if(num >= 0 && num <= 9){

        invertido = num;
    }
    return invertido;
}


/*questão 6*/

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;
    int base[100];
    int busca[100];
    int contador_base = 0, i= 0, j = 0, teste = 0, contador_busca = 0;

	while(numerobase >= 0){
		if(numerobase < 10 && numerobase >= 0 ){
			base[contador_base] = numerobase;
			break;
		}else{
			base[contador_base] = numerobase % 10;
			numerobase = numerobase / 10;
			contador_base++;
		}
	}
  
	while(numerobusca >= 0){
		if(numerobusca < 10 && numerobase >= 0){
			busca[contador_busca] = numerobusca;
			break;
		}else{
			busca[contador_busca] = numerobusca % 10;
			numerobusca = numerobusca / 10;
			contador_busca++;
		}
	}
  
	for (i = 0; i <= contbase; i++){
		if(contador_busca == 0){
			if (busca[0] == base[i]){
				qtdOcorrencias++;
			}
		}else{
			if(busca[j] == base[i]){
				teste = 1;
				j++;
			}else if (busca[j] != base[i]){
				teste = 0;
				j = 0;
			}
			if(controle == 1 && j == contador_busca){
				teste = 0;
				j = 0;
				qtdOcorrencias++;
			}
		}
	}
    return qtdOcorrencias;
}








/*QUESTÃO 7
#include <stdio.h>
#include <stdlib.h>

int main(){
  
  // estrutura de dados
  int linha, coluna, l, c, jogador, ganhou, qtdjogadas, opcao;
  char jogo[3][3];

  do{
    jogador = 1;
    ganhou = 0;
    qtdjogadas = 0;
      //como inicializar a estrutura de dados
      for (linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna ++){
          jogo[linha][coluna]= ' ';      
        }
      }
        do{
            //imprimir jogo
            printf("\n\n\t 0  1  2 \n\n");
            for(linha = 0; linha < 3; linha++){
              for(coluna = 0; coluna < 3; coluna++){
                if(coluna == 0)
                printf("\t");
                printf(" %c ", jogo[linha][coluna]);
                if(coluna < 2)
                  printf("|");
                if(coluna == 2)
                  printf("\t\t%d", linha);
                
              }
              if(linha < 2)
                printf("\n\t------------");
                printf("\n");
            } 
          //ler coordenadas
          do{
            printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
            scanf("%d %d", &l, &c);
            }while(l < 0 || l > 2 || c < 0 || c > 2 || jogo[l][c] != ' ');
          
          //salvar coordenadas
          if (jogador == 1){
            jogo[l][c] = '0';
            jogador ++;
          }else{
            jogo[l][c] = 'X';
            jogador = 1;
          }
          qtdjogadas ++;
          //alguém ganhou por linha
          if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
             jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
             jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
              printf("\nO jogador 1 venceu por linha! Parabéns!\n");
            ganhou = 1; }
          
          if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
             jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
             jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
              printf("\nO jogador 2 venceu venceu por linha!  Parabéns!\n");
                ganhou = 1;
             }
          
          //alguem ganhou por coluna 
          if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
             jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
             jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0' ){
                printf("\nO jogador 1 venceu por coluna! Parabéns!\n");
            ganhou = 1;}
          
          if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
             jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
             jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X' ){
                printf("\nO jogador 2 venceu por coluna! Parabéns!\n");
            ganhou = 1;
            }
            
          //alguem ganhou por diagonal principal 
          if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
              printf("\nO jogador 1 venceu por coluna! Parabéns!\n");
            ganhou = 1;}
            
          if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
              printf("\nO jogador 2 venceu por coluna! Parabéns!\n");
            ganhou = 1;}
          //alguem ganhou por diagonal secundaria 
            
          if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
              printf("\nO jogador 1 venceu por coluna! Parabéns!\n");
            ganhou = 1;}
          if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
              printf("\nO jogador 2 venceu por coluna! Parabéns!\n");
            ganhou = 1;}
      }while(ganhou == 0 && qtdjogadas < 9);

    if(ganhou == 0)
      printf("\nJogo finalizado sem ganhadores\n");

    printf("\n Deseja jogar de novo? Digite 1 para começar \n");
    scanf("%d", &opcao);

    }while(opcao == 1);
    

  
return 0;
  
}

*/












