# PROG.1

#include <stdio.h>
#include <math.h>

typedef struct cidade{
	int x;
	int y;
}cidade;

int distancia(cidade *a, cidade *b){
	int d=pow(pow(*a.x-*b.x,2)+pow(*a.x-*b.x,2),1/2);
}

int main(int narg, char *agrv[]){
	int num=1;
	while(num!=0){
		scanf("%d",&num);
		cidade *estados=(cidade*)malloc(num*sizeof(cidade))/[G]
		for(int i=0;i<num;i++){
			float x,y;
			scanf("%f %f", &x , &y);
			estados[i].x=x;
			estados[i].y=y;
		}
	}	
	return 0;
}
