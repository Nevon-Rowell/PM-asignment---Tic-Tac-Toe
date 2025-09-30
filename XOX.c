#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void CreateBoard();
void prntBoard();
int Valid(int N,char Board[N][N][4],int choice,char player);

int main(){
	int Gridsize;
	printf("Enter the Grid size (3<Grid size<9): ");
	scanf("%d",&Gridsize);

	char Board[Gridsize][Gridsize][4];
	CreateBoard(Gridsize,Board);
	prntBoard(Gridsize,Board);

	int choice;
	char player = 'X';

	while(1){
		printf("player %c, Enter Cell index: ",player);
		scanf("%d",&choice);

		if(choice==0)
			break;
		if(Valid(Gridsize,Board,choice,player)){
			prntBoard(Gridsize,Board);

			player = (player == 'X')?'O':'X';
		}else{
			printf("invalid move try again\n");
		}
	}
}

int Valid(int N,char Board[N][N][4],int choice,char player){
	int num = 1;
	for (int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			if (atoi(Board[i][j])==choice){
				sprintf(Board[i][j],"%c",player);
				return 1;
			}
		}
	}
}

void CreateBoard(int N,char Board[N][N][4]){
	int place = 1;
	for (int i = 0;i<N;i++){
		for(int j=0;j<N;j++){
			sprintf(Board[i][j],"%d",place);
			place++;
		}
	}
}
void prntBoard(int N,char Board[N][N][4]){
	for (int i=0;i<N;i++){
		printf("|");
		for (int j = 0;j<N;j++){
		       printf("%3s",Board[i][j]);
	       if (j<N-1){
	               printf("  |");
	       }else{
		       printf("  |\n");
	       } 
	}
		if (i<N-1){
			for(int j=0;j<N;j++){
				 printf("------");
			}
				printf("-\n");
			}
		}
	}
