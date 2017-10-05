#include <stdio.h>
#include <stdlib.h>


int f(char* s){
	switch(*s){
		case '0':
			printf(" ");
			break;
		case '1':
			printf("e um");
			break;
		case '2':
			printf("e dois");
			break;
		case '3':
			printf("e tres");
			break;
		case '4':
			printf("e quatro");
			break;
		case '5':
			printf("e cinco");
			break;
		case '6':
			printf("e seis");
			break;
		case '7':
			printf("e sete");
			break;
		case '8':
			printf("e oito");
			break;
		case '9':
			printf("e nove");
			break;
	}
}


int str_tamanho(char*s){
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}

void str_copi(char *s,char *d){
	int tamanho=str_tamanho(s);
	d=(char*)malloc(tamanho*sizeof(char));
	for(int i=0;i<tamanho;i++)
		d[i]=s[i];
	printf("%s\n", d);
}

void str_concatena(char *s, char *d){
	int a=str_tamanho(s);
	int b=str_tamanho(d);
	char *v=(char*)malloc((a+b)*sizeof(char));
	for(int i=0;i<a;i++)
		v[i]=s[i];
	for(int i=0;i<b;i++)
		v[(a+i)]=d[i];
	//printf("%s\n",v);
	str_copi(v,d);
}

int main(int narg, char *argv[]){


	char *s=(char*)malloc(4*sizeof(char));
	char *d=(char*)malloc(6*sizeof(char));
	s="sou ";
	d="dahora";
	//str_concatena(s,d);
	str_copi(s,d);
	printf("%s\n",d);
	return 0;
}