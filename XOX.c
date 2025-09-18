#include<stdio.h>

void CreateBoard();
void prntBoard();
int main(){
	int Gridsize;
	printf("Enter the Grid size: ");
	scanf("%d",&Gridsize);
	char Board[Gridsize][Gridsize];
	CreateBoard(Gridsize,Board);
	prntBoard(Gridsize,Board);

}
void CreateBoard(int N,char Board[N][N]){
	for (int i = 0;i<N;i++){
		for(int j=0;j<N;j++){
			Board[i][j] = ' ';
		}
	}
}
void prntBoard(int N,char Board[N][N]){
	for (int i=0;i<N;i++){
		printf("|");
		for (int j = 0;j<N;j++){
		       printf("%c",Board[i][j]);
	       if (j<N-1){
	               printf("|");
	       }else{
		       printf("|\n");
	       }
		}
	}
}	
