#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXNOME 101
#define MAXREGISTRO 1001
struct registro{
	char nome[101];
	char tipo[2];
	long long int matricula;
	long long int telefone;
	int ddd;
};
typedef struct registro Registro;

void inserir(struct registro **agenda){
	int i;
	int terminou = 0;
	for(i=0;i<1001 && !terminou;i++){
		if ((*agenda)[i].ddd==0){
			printf("entre com o nome:\n");
			scanf("%s",(*agenda)[i].nome);
			printf("entre com a matricula:\n");			
			scanf("%lld", &(*agenda)[i].matricula);
			printf("entre com o telefone:\n");
			scanf("%lld",&(*agenda)[i].telefone);
			printf("entre com o ddd:\n");
			scanf("%d",&(*agenda)[i].ddd);
			printf("entre com o tipo do telefone:\n");
			scanf("%s",(*agenda)[i].tipo);
			terminou=1;
		}
	}
}

void apagar(struct registro **agenda, char *nome){
	int i;
	int achou=0;
	char zero[1]="0";
	for (i=0; i<1001 && achou==0 ; i++){
		if (strcmp ((*agenda)[i].nome,nome)==0){
			strcpy((*agenda)[i].nome,zero);
			strcpy((*agenda)[i].tipo,zero);
			(*agenda)[i].matricula=0;
			(*agenda)[i].telefone=0;
			(*agenda)[i].ddd=0;
			achou=1;
			//return (void)1;
		}
	}
	if(!achou) printf("nao esta na agenda!\n");

}

void buscar(struct registro **agenda, char *nome){
	int i;
	int achou=0;
	for (i=0; i<1001 && achou==0 ; i++){
		if (strcmp ((*agenda)[i].nome,nome)==0){
			printf("%s - (%d)%lld\n",(*agenda)[i].nome, (*agenda)[i].ddd, (*agenda)[i].telefone);
			achou=1;
			//return (void)1;
		}
	}
	if(!achou) printf("nao esta na agenda!\n");
}
void lista(struct registro **agenda){
	int i;
	int terminou=0;
	for(i=0;i<1001 && !terminou;i++){
		if ((*agenda)[i].ddd!=0){
			printf("%s\n",(*agenda)[i].nome);
		}
		
	}
}

void escolha(char c, struct registro** agenda){
	
	switch(c){

			case 'A':
				printf("nome que deseja apagar:\n");
				char nome1[101];
				scanf("%s", nome1);
				apagar(agenda,nome1);	
				break;
			case 'I':
				inserir(agenda);
				break;
			case 'L':
				printf("lista:\n");
				lista(agenda);
				break;
			case 'B':
				printf("nome que deseja buscar:\n");
				char nome2[101];
				scanf("%s", nome2);
				buscar(agenda,nome2);
				break;
			case 'a':
				printf("nome que deseja apagar:\n");
				char nome3[101];
				scanf("%s", nome3);
				apagar(agenda,nome3);	
				break;
			case 'i':
				inserir(agenda);
				break;
			case 'l':
				printf("lista:\n");
				lista(agenda);
				break;
			case 'b':
				printf("nome que deseja buscar:\n");
				char nome4[101];
				scanf("%s", nome4);
				buscar(agenda,nome4);
				break;
		}
}

int main(int narg, char *argv[]){


	struct registro* agenda=(struct registro *)malloc(1001*sizeof(struct registro));
	int i;
	for (i = 0; i < 1001; i++)
	{
		agenda[i].ddd=0;	
	}
	if(narg!=1){
		FILE *arq=fopen(argv[1],"rt");
		char *c,linha[101];
		if (arq==NULL){
			printf ("erro\n");
			return 1;
		}
		int j=0;
		for (i=1; c=fgets(linha,101,arq);++i){
			switch(i%5){
				case 0: linha[strlen(linha)-1]='\0';strcpy(agenda[j].tipo,linha);j+=1; break;
				case 1: agenda[j].matricula=atoi(linha); break;
				case 2:	linha[strlen(linha)-1]='\0';strcpy(agenda[j].nome,linha); break;
				case 3: agenda[j].ddd=atoi(linha); break;
				case 4:	agenda[j].telefone=atoi(linha); break;
			}
		}
	}
	int continua=0;
	printf("'S' OU 's' PARA SAIR!\n");
	while(continua==0){
		char c[1];
		printf("\n");
		printf("DIGITE SUA ESCOLHA:\n");
		scanf("%s",c);
		escolha(*c,&agenda);
		if (*c=='s' || *c=='S') continua =1;
		
	}
	return 0;
}
