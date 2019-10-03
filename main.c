	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "EstruturaVetores.h"

	int menu();

	//COLOCAR RETORNO NOS CASOS listar casos

	int menu(){
	    int op;
	    printf("Digite as opcao desejada\n");
	    printf("0 - Sair\n");
	    printf("1 - Inserir\n");
	    printf("2 - Excluir Numero Do Final da Estrutura\n");
	    printf("3 - Excluir Numero da Estrutura\n");
	    printf("4 - Listar\n");
	    printf("5 - Listar Ordenado\n");
	    printf("6 - Listar Todos os numeros\n");
	    printf("7 - Listar Todos os numeros Ordenado\n");
	    printf("8 - Dobrar numero\n");
	    printf("9 - Criar Estrutura Auxiliar\n");
	    printf("10 - Aumentar o Tamanho Da Estrutura Auxiliar\n");
	    printf("11- lista");
	    scanf("%d", &op);
	    return op;
	}

	int main(){
	    //int *vetorPrincipal[TAM];
	    int op;
	    int sair = 0;
	    int ret;
	    int num;
	    int posicaoestrutura;
	    int tamanhoestrutura;
	    int i, j;
	    No* lista;
	    inicializar();
	    while (!sair){
	        op = menu();
	        switch (op){
	            case 0:{
	                finalizar();
	                sair =1;
	                break;
	            }
	            case 1:{ //inserir
	                //TODO
	                printf("Digite o valor para ser inserido\n");
	                scanf("%d", &i);
	                printf("Digite a posicao pra ser inserida\n");
	                scanf("%d", &j);
	                ret = inserirNumeroEmEstrutura(i, j);
	                if (ret == SUCESSO){
	                	printf("Inserido com sucesso");
	                }else if (ret == SEM_ESPACO){
	                	printf("Sem Espaço");
	                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
	                	printf("Sem estrutura Auxiliar");
	                }
	                else if (ret == POSICAO_INVALIDA)
	                	printf("POSICAO INVALIDA\n");
	                break;
	            }

	            case 2:{
	                printf("digite qual estrutura auxiliar deseja tirar o ultimo numero\n");
	                scanf("%d", &i);
	                ret = excluirNumeroDoFinaldaEstrutura(i);
	                if(ret == SUCESSO)
	                    printf("SUCESSO");
	                else if(ret == ESTRUTURA_AUXILIAR_VAZIA)
	                    printf("ESTRUTURA AUXILIAR VAZIA\n");
	                else if(ret == SEM_ESTRUTURA_AUXILIAR)
	                    printf("SEM ESTRUTURA AUXILIAR\n");
	                else if(ret == POSICAO_INVALIDA)
	                    printf("POSICAO INVALIDA\n");
	                break;
	            }

	            case 3:{
	                printf("digite qual o valor deseja retirar\n");
	                scanf("%d", &i);
	                printf("digite qual estrutura auxiliar deseja tirar o numero\n");
	                scanf("%d", &j);
	                ret = excluirNumeroEspecificoDeEstrutura(i, j);
	                if(ret == SUCESSO)
	                    printf("SUCESSO");
	                else if(ret == ESTRUTURA_AUXILIAR_VAZIA)
	                    printf("ESTRUTURA AUXILIAR VAZIA\n");
	                else if(ret == SEM_ESTRUTURA_AUXILIAR)
	                    printf("SEM ESTRUTURA AUXILIAR\n");
	                else if(ret == POSICAO_INVALIDA)
	                    printf("POSICAO INVALIDA\n");
	                else if(ret == NUMERO_INEXISTENTE)
	                    printf("NUMERO INEXISTENTE\n");
	                break;
	            }
	            case 4:{
	                printf("Qual a estrutura a ser listada (1..10)?");
	                scanf("%d", &i);

	                int qtd =  getQuantidadeElementosEstruturaAuxiliar(i);
                    if(qtd == SEM_ESTRUTURA_AUXILIAR){
	                    printf("SEM ESTRUTURA AUXILIAR\n");
                        break;
                    }
                    else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
                        printf("ESTRUTURA_AUXILIAR_VAZIA");
                        break;
                    }
                    else if(qtd == POSICAO_INVALIDA){
                        printf("POSICAO_INVALIDA");
                        break;
                    }
	                int vetorAux[qtd];
	                ret = getDadosEstruturaAuxiliar(i, vetorAux);

	                if(ret == SUCESSO)
	                    for(j = 0; j < qtd; j++)
	                        printf(" [%d] \n", vetorAux[j]);
	                break;
	            }
	            case 5:{
	                printf("Qual a estrutura a ser listada (1..10)?");
	                scanf("%d", &i);

	                
                    int qtd =  getQuantidadeElementosEstruturaAuxiliar(i);
                    if(qtd == SEM_ESTRUTURA_AUXILIAR){
                        printf("SEM ESTRUTURA AUXILIAR\n");
                        break;
                    }
                    else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
                        printf("ESTRUTURA_AUXILIAR_VAZIA");
                        break;
                    }
                    else if(qtd == POSICAO_INVALIDA){
                        printf("POSICAO_INVALIDA");
                        break;
                    }
                    int vetorAux[qtd];
                    ret = getDadosOrdenadosEstruturaAuxiliar(i, vetorAux);
                    
                    if(ret == SUCESSO){
                        for(j = 0; j < qtd; j++)
                            printf(" [%d] \n", vetorAux[j]);
		                }
		                
	                break;
	            }
	            case 6:{
	            	int qtd = getQuantidadeElementosTodos();
	            	if(qtd == 0)
	            		printf("SEM ESTRUTURA AUXILIAR\n");
	            	else if(qtd != 0){ 
	            		int vetorAux[qtd];
	            		ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
	            		for(j = 0; j < qtd; j++)
		                    	printf(" [%d] \n", vetorAux[j]);
	            	}
	            	break;
	            }
	            case 7:{
	            	int qtd = getQuantidadeElementosTodos();
	            	if(qtd == 0)
	            		printf("SEM ESTRUTURA AUXILIAR\n");
	            	else if(qtd != 0){ 
	            		int vetorAux[qtd];
	            		ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
	            		for(j = 0; j < qtd; j++)
		                    	printf(" [%d] \n", vetorAux[j]);
	            	}
	            	break;
	            }
	            case 8:{ //TODO
	                printf("insira um numero:");
	                scanf("%d", &num);
	                dobrar(&num);
	                printf("o dobro do seu numero e: %d\n",num);

	                break;
	            }
	            case 9:{
	            	printf("digite a posicao em que se deseja criar a Estrutura Auxiliar\n");
	            	scanf("%d", &posicaoestrutura);
	            	printf("digite o tamanho da estrutura\n");
	            	scanf("%d", &tamanhoestrutura);
	            	ret = criarEstruturaAuxiliar(tamanhoestrutura, posicaoestrutura);
	            	if (ret == SUCESSO){
	                	printf("Inserido com sucesso\n");
	                }
	                else if(ret == TAMANHO_INVALIDO){
	                	printf("tamanho invalido\n");
	                }
	                else if(ret == SEM_ESPACO_DE_MEMORIA){
	                	printf("sem espaço de memoria\n");
	                }
	                else if(ret == POSICAO_INVALIDA){
						printf("posicao invalida\n");
	                }
	                else if(ret == JA_TEM_ESTRUTURA_AUXILIAR){
	                	printf("ja tem estrutura auxiliar\n");
	                }
	      		}
	                break;
	            case 10:{
	            	printf("digite a posicao em que se deseja Alterar o Tamanho  da Estrutura Auxiliar\n");
	            	scanf("%d", &posicaoestrutura);
	            	printf("Digite o Novo Tamanho Desejado\n");
	            	scanf("%d", &i);
	            	ret = modificarTamanhoEstruturaAuxiliar(posicaoestrutura, i);
	            	if (ret == SUCESSO)
	                	printf("Modificado com sucesso\n");
	                else if(ret == POSICAO_INVALIDA)
						printf("posicao invalida\n");
					else if (ret == NOVO_TAMANHO_INVALIDO)
						printf("Novo Tamanho Invalido");
					else if(ret == SEM_ESTRUTURA_AUXILIAR)
		                    printf("SEM ESTRUTURA AUXILIAR\n");
		            else if(ret == SEM_ESPACO_DE_MEMORIA)
	                	printf("sem espaço de memoria\n");
		        	break;
	            }
	            case 11:{

	            		lista= montarListaEncadeadaComCabecote();
	            		ret=getQuantidadeElementosTodos();
	            		int vetorAux[ret];
	            		getDadosListaEncadeadaComCabecote(lista, vetorAux);
	            		for(i=0;i<ret;i++)
	            			printf("[%d]", vetorAux[i]);
	            		destruirListaEncadeadaComCabecote(lista);

	            	break;
	            }
	            default:{
	                printf("opcao inválida\n");
	            }


	        }


	    }

	    return 0;

	}
