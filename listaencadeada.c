#include <stdio.h>

struct registro{
	char nome[101];
	char tipo[2];
	long long int matricula;
	long long int telefone;
	int ddd;
	struct registro* prox;
};
typedef struct registro Registro;

void inicializar(struct registro **agenda){
	(*agenda)=(struct regsitro*)malloc(sizeof(struct registro));
	(*agenda).ddd=0;
	prox.(*agenda)=NULL;
}

void inserirlista1(struct registro **agenda){
	struct registro novo;
	inicializar(&novo);
	
	printf("entre com o nome:\n");
	scanf("%s",novo.nome);
	printf("entre com a matricula:\n");			
	scanf("%lld", &novo.matricula);
	printf("entre com o telefone:\n");
	scanf("%lld",&novo.telefone);
	printf("entre com o ddd:\n");
	scanf("%d",&novo.ddd);
	printf("entre com o tipo do telefone:\n");
	scanf("%s",novo.tipo);
	struct registro *i=*agenda;	
	while((int)(i).nome<=(int)novo.nome && (i)!=NULL){
		(i)=(i).prox;
	}
	prox.novo=prox.(i);
	if((i)==NULL) (i) = novo;
	if(prox.(i)!=NULL) prox.(i)=novo;	
}

void inserirlista2(struct registro **agenda,struct registro novo){
	struct registro *i=*agenda;
	while((int)(i).nome<=(int)novo.nome && (i)!=NULL){
		(i)=(i).prox;
	}
	prox.novo=prox.(i);
	if((i)==NULL) (i) = novo;
	if(prox.(i)!=NULL) prox.(i)=novo;	
}

void percorrer(struct registro **agenda){
	struct registro *i=*agenda;
	while ((i)!=NULL){
		printf("nome:%s\nmatricula:%lld\nddd:%d\ntelefone:%lld\ntipo de telefone:%s\n", (i).nome, (i).matricula,(i).ddd,(i).telefone, (i).tipo);
		(i)=(i).prox;
	}
}

void carregar(struct registro **agenda,FILE **arq){
	*arq=fopen(argv[1],"rt");
	char *c,linha[101];
	if (arq==NULL){
		printf ("erro\n");
		return 1;
	}
	struct registro aux;
	for (i=1; c=fgets(linha,101,*arq);++i){
		switch(i%5){
			case 0: str.cpy(aux.tipo,linha);incluirlista2((*agenda),aux) break;
			case 1: inicializar(&aux);aux.matricula=atoi(linha); break;
			case 2: strcpy(aux.nome,linha); break;
			case 3: aux.ddd=atoi(linha); break;
			case 4:	aux.telefone=atoi(linha); break;
		}
	}
	fclose(arq);
}
void salvar(struct registro **agenda,FILE **arq){
	*arq=fopen(argv[1],"rt");
	if (arq==NULL){
		printf ("erro\n");
		return 1;
	}
	char *c,linha[101];
	struct 
	while(i
		switch(i%5){
			case 0: fprintf(*arq,(*agenda).tipo)//str.cpy(aux.tipo,linha);incluirlista2(*agenda,aux) break;
			case 1: fprintf(*arq,(*agenda).matricula)//	inicializar(&aux);aux.matricula=atoi(linha); break;
			case 2: fprintf(*arq,(*agenda).nome)//	strcpy(aux.nome,linha); break;
			case 3: fprintf(*arq,(*agenda).ddd)//	aux.ddd=atoi(linha); break;
			case 4:	fprintf(*arq,(*agenda).telefone)//	aux.telefone=atoi(linha); break;
		}
		i++;
	}
	
	
	
}
