#include <stdio.h>

void *criar_matriz(int tamanho_x,int tamanho_y){
	double **vet=(double**)malloc((1+tamanho_x)*sizeof(double*));
	double *ini=(double*)malloc(sizeof(double));
	*ini=(double)tamanho_y;
	vet[0]=ini;
//	printf("%f\n",*vet[0]);
	for (int i = 1; i <= tamanho_x; i++)
	{
		vet[i]=(double*)malloc(tamanho_y*sizeof(double));
	}
	return (void*)vet;
}

double obter_matriz(void *mem,int x,int y){
	double r= ((double**)mem)[x+1][y];
	//printf("%f\n",r);
	return r;
}

void atribuir_matriz(void *mem,int x,int y,double valor){
	((double**)mem)[x+1][y]=valor;
}

void liberar_matriz(void *mem){
	for (int i = 0; i < *((int**)mem)[0]; i++)
		free(((double**)mem)[i]);
	free(mem);
}

int main(int narg, char*argv[]){
	void *v=criar_matriz(3,2);
	atribuir_matriz(v,0,0,1.00);
	atribuir_matriz(v,0,1,2.00);
	atribuir_matriz(v,1,0,3.00);
	atribuir_matriz(v,1,1,4.00);
	atribuir_matriz(v,2,0,5.00);
	atribuir_matriz(v,2,1,6.00);
	printf("\n\n| %f  %f |\n",obter_matriz(v,0,0),obter_matriz(v,0,1));
	printf("| %f  %f |\n",obter_matriz(v,1,0),obter_matriz(v,1,1));
	printf("| %f  %f |\n\n",obter_matriz(v,2,0),obter_matriz(v,2,1));

	liberar_matriz(v);

	return 0;
}