#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>

struct Dados{
	char nome[50]; //armazena os nomes dos alunos
	char matricula[17]; //armazena as matriculas dos alunos
	char endereco[50]; //armazena os enderecos dos alunos
	float nota[15][3]; //armazena as notas dos alunos
};

int main(){
	setlocale(LC_ALL,"Portuguese");
	struct Dados aluno[15];
	static int r=0, i=0, j=0, vazio=0;
	int indice, x, menu;
	float media;
	int cont;
	do{
		system("cls");
		printf("--------------------------------- GERENCIAMENTO DE ALUNOS ----------------------------------\n");
		printf("[1] INCLUIR ALUNO | [2] EXCLUIR ALUNO | [3] LISTAR ALUNOS | [4] APRESENTAR MÉDIAS | [0] SAIR\n");
		printf("--------------------------------------------------------------------------------------------\n>> ");
		scanf("%d",&menu);
		fflush(stdin);
		switch(menu){
			case 1:{ //OPÇÃO PARA INCLUIR NOVOS ALUNOS
				do{
					system("cls");
					printf("**** INCLUIR ALUNO ****\n");
					
					printf("Digite o nome do aluno %d: ",i);
					fgets(aluno[i].nome, 50, stdin);
					fflush(stdin);
					
					printf("Digite a matrícula do aluno: ");
					fgets(aluno[i].matricula, 17, stdin);
					fflush(stdin);
					
					printf("Digite o endereço do aluno: ");
					fgets(aluno[i].endereco, 50, stdin);
					fflush(stdin);
					
					printf("Digite a 1ª nota: ");
					scanf("%f",&aluno[i].nota[i][0]);
					fflush(stdin);
					
					printf("Digite a 2ª nota: ");
					scanf("%f",&aluno[i].nota[i][1]);
					fflush(stdin);
					
					printf("Digite a 3ª nota: ");
					scanf("%f",&aluno[i].nota[i][2]);
					fflush(stdin);
					i++;
					r=1;
					break;
				}while(i<=15);
				printf("LIMITE DE 15 ALUNOS PREENCHIDOS! FAÇA A EXCLUSÃO PARA PODER INCLUIR NOVOS ALUNOS.");
				break;
			}
			case 2:{
				system("cls");
				printf("****** EXCLUIR ALUNO *******\n");
				if(i==0){
					printf("VAZIO! ADICIONE DADOS PRIMEIRO!");
					sleep(2);
					r=1;
					break;	
				}else{
					char Mat_valor[17];
					printf("Digite matricula do aluno que deseja excluir: ");
					fgets(Mat_valor, 17, stdin);
					fflush(stdin);
					for(cont=0;cont<i;cont++){
						if(strcmp(Mat_valor,aluno[cont].matricula)==0){
							//memset(&aluno[cont].matricula,0,17);
							//memset(&aluno[cont].endereco,0,17);
							//memset(&aluno[cont].nome,0,17);
							//memset(&aluno[cont].nota,0,17);
							strcpy(aluno[cont].matricula, aluno[cont+1].matricula);
							strcpy(aluno[cont].nome, aluno[cont+1].nome);
							strcpy(aluno[cont].endereco, aluno[cont+1].endereco);
							i--;
							vazio=0;
						}else{
							printf("MATRICULA NÃO ENCONTRADA! TENTE NOVAMENTE!");
							sleep(2);
							r=1;  
						}
					}
					break;	
				}
			}
			case 3:{ //OPÇAO PARA LISTAR TODOS OS ALUNOS REGISTRADOS
				system("cls");
				printf("****** LISTAR ALUNOS *******\n");
				for(j=0;j<i;j++){
					if(strlen(aluno[j].nome)!=0){ //VERIFICA SE TEM ESPAÇOS VAZIOS NO CADASTRO, SE NÃO TIVER, EXIBE OS DADOS
						printf("Aluno %d\n",j);
						printf("Nome: %sMatrícula: %sEndereço: %s\n",aluno[j].nome, aluno[j].matricula, aluno[j].endereco);
						vazio=1; //INFORMA QUE O VETOR TEM DADOS
					}
				}
				if(vazio==0){ //AQUI EXIBE UMA MENSAGEM DE QUE O VETOR ESTÁ VAZIO
					printf("VAZIO! ADICIONE DADOS PRIMEIRO!");
					sleep(3);
					r=1;
					break;
				}
				printf("Deseja retornar ao menu inicial?\n[1] Sim | [2] Não\n>> ");
				scanf("%d",&menu);
				switch(menu){
					case 1:
						r=1;
						break;
					case 2:
						printf("Programa encerrado!");
						exit(0);
				}
				break;
			}
			case 4:{ //OPÇAO QUE CALCULA AS MÉDIAS DOS ALUNOS
				system("cls");
				printf("******* MÉDIAS *******\n");
				for(j=0;j<i;j++){
					if(strlen(aluno[j].matricula)!=0){ //VERIFICA SE TEM ESPAÇOS VAZIOS NO CADASTRO, SE NÃO TIVER, EXIBE OS DADOS
						printf("Nome: %sMatrícula: %s",aluno[j].nome, aluno[j].matricula);
						printf("1ª Nota: %.2f\n2ª Nota: %.2f\n3ª Nota: %.2f\n",aluno[j].nota[j][0], aluno[j].nota[j][1], aluno[j].nota[j][2]);
						media = (aluno[j].nota[j][0] + aluno[j].nota[j][1] + aluno[j].nota[j][2])/3;
						printf("A média das notas é: %.2f\n\n",media);
						vazio=1; //INFORMA QUE O VETOR TEM DADOS
					}
				}
				if(vazio==0){ //AQUI EXIBE UMA MENSAGEM DE QUE O VETOR ESTÁ VAZIO
					printf("VAZIO! ADICIONE DADOS PRIMEIRO!");
					sleep(3);
					r=1;
					break;
				}
				printf("Deseja retornar ao menu inicial?\n[1] Sim | [2] Não\n>> ");
				scanf("%d",&menu);
				switch(menu){
					case 1:
						r=1;
						break;
					case 2:
						exit(0);
				}
				break;
			}
			case 0:{
				printf("Programa encerrado!");
				exit(0);
				break;
			}
			default:{
				printf("Opção inválida! Digite uma opção do menu acima.");
				r=1;
				sleep(3);
				break;
			}
		}
	}while(r==1);
	
	system("pause");
	return 0;
}
