#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void CreateBoard();
void prntBoard();
int Valid(int N,char Board[N][N][4],int choice,char player);
int WinCheck(int N,char Board[N][N][4],char player);
int GridVal();

int main(){
	printf("<=========MENU=========>\n\n");
	printf(" 1) Player Vs Computer \n");
	printf(" 2) Player Vs player \n");
	printf(" 3) 3 Player Mode \n\n");

	int Mode;
	printf("Choose mode(Enter Mode Number): \n");
	scanf("%d",&Mode);

	int Gridsize = GridVal();
	char Board[Gridsize][Gridsize][4];
	CreateBoard(Gridsize,Board);
	prntBoard(Gridsize,Board);

	int choice,moves;
	char player = 'X';


	switch(Mode){ //to select modes
		case 1: //player vs Computer
		while (1) {
                if (player == 'X') { // Human
                    printf("Player %c, Enter Cell index: ", player);
                    scanf("%d", &choice);
                } else { 
                    choice = (rand()%(Gridsize*Gridsize)) + 1;
                    printf("Computer chooses: %d\n", choice);
                }

                if (choice == 0) break;
                if (Valid(Gridsize, Board, choice, player)) {
                    prntBoard(Gridsize, Board);
                    moves++;

		    if (WinCheck(Gridsize, Board, player) == 1) {
                        printf("Player %c Wins!!\n", player);
                        break;
                    }
                    if (moves == Gridsize * Gridsize) {
                        printf("It's a Draw!\n");
                        break;
                    }

                    player = (player == 'X') ? 'O' : 'X';
                }
            }
            break;

		case 2: //player vs player 
		while(1){
                printf("player %c, Enter Cell index: ",player);
                scanf("%d",&choice);

                if(choice==0)
                        break;
                if(Valid(Gridsize,Board,choice,player)){
                        prntBoard(Gridsize,Board);

                        if (WinCheck(Gridsize,Board,player)==1){
                                printf("Player %c Wins!!\n",player);
                                break;
                        }
                        player = (player == 'X')?'O':'X';
                }else{
                        printf("invalid move try again\n");
                }
		}break;

		case 3: // 3player mode
		while (1) {
                printf("Player %c, Enter Cell index: ", player);
                scanf("%d", &choice);
                if (choice == 0) break;

                if (Valid(Gridsize, Board, choice, player)) {
                    prntBoard(Gridsize, Board);

                    if (WinCheck(Gridsize, Board, player) == 1) {
                        printf("Player %c Wins!!\n", player);
                        break;
                    }

                    // cycle between X,O and Z
                    if (player == 'X') player = 'O';
                    else if (player == 'O') player = 'Z';
                    else player = 'X';

                } else {
                    printf("Invalid move! Try again\n");
                }
            }
            break;
	}
}
// funtion to get grid size
int GridVal(){
	int Gridsize;
        printf("Enter the Grid size (3<Grid size<9): ");
        scanf("%d",&Gridsize);
        if (Gridsize>=10){
                printf("Invalid Grid Size\n");
                return 0;
	}
	return Gridsize;
}
//funtion to validate input
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
//function to Create the board
void CreateBoard(int N,char Board[N][N][4]){
	int place = 1;
	for (int i = 0;i<N;i++){
		for(int j=0;j<N;j++){
			sprintf(Board[i][j],"%d",place);
			place++;
		}
	}
}
//function to Print the board
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
//Funtion to check Win status 
int WinCheck(int N,char Board[N][N][4],char player){
	char sign[2];
	sprintf(sign,"%c",player);
        
	for (int i = 0;i<N;i++){ //to check rows
		int win = 1;
		for (int j = 0;j<N;j++){
			if (strcmp(Board[i][j],sign) != 0){
				win = 0;
			        break;	
			}
		}
		if (win == 1){
			return 1;
		}
	}

	for  (int j = 0;j<N;j++){ //to check Columns
                int win = 1;
                for (int i = 0;i<N;i++){
                        if (strcmp(Board[i][j],sign) != 0){
                                win = 0;
                                break;
                        }
                }
		if (win == 1){
                        return 1;
                }

        }

	int win = 1; // to check Diagonal(right - left)
	for  (int i = 0;i<N;i++){
                if (strcmp(Board[i][i],sign) != 0){
		       	win = 0;
                        break;
		}
	}
	 if (win == 1){
                        return 1;
                }

	win = 1; // to check diagonal(left - right)
	for(int i = 0;i<N;i++){
		if (strcmp(Board[i][N-1-i],sign) != 0){
			win = 0;
			break;
		}
	}
	if (win == 1){
                        return 1;
                }
}
