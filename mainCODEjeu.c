#include "libETdecla.h"
#include "PossibleCase.h"
#include "ColorChange.h"
#include "others.h"
void main() {
  int iter=0;
  int tab[64][2];
  int i,j,k,l,code,save,S=0;
  char car1, car2, car3, player='N',partID[30];
  couple pawn;
  matrice M;
  playerID player1,player2;
  printf("\nPLAYER 1: tapez votre nom\n");
  scanf("%s",player1.username);
  printf("\nPLAYER 2: tapez votre nom\n");
  scanf("%s",player2.username);
  printf("PLAYER 1 the owner of the black pawns and PLAYER 2 the owner of the white ones.\n");
  printf("\nNow let the game begins!!\n");
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++)
      M[i][j]=' ';
  }
  M[3][3]='B';
  M[4][4]='B';
  M[3][4]='N';
  M[4][3]='N';
  do {
     if(S==2) {
       afficher_plat(M);
       pawn_calculator(M);
       break; }
     if (iter%2==0) {
        player='N';
        car1='B';
        car2='N';
      }
      else {
        player='B';
        car1='N';
        car2='B';
      }
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          hori_possible(M,i,j,car1,car2);
          verti_possible(M,i,j,car1,car2);
          diag_possible(M,i,j,car1,car2);
          anti_diag_possible(M,i,j,car1,car2);
        }
      }
      if(!possible_case(M)) {
        S++;
        continue;
      }
      afficher_plat(M);
      pawn=pawn_calculator(M);
      printf("_______________________________________________________________________\n");
      printf("%c , it's your turn!!",player);
     do {
      printf("\nChose a case:\n");
      scanf("%d",&k);
      scanf("%d",&l);
      if(M[k][l]!='O') {
         printf(" ASH KATRWEN! MABANT LEK GHA HADIK !!!!!!!!!!!!!!!!!! \n");
      }
    } while(M[k][l]!='O');
    if (iter%2==0) M[k][l]='N';
    else M[k][l]='B';
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (M[i][j]=='O')
          M[i][j]=' ';
      }
    }
    hori_color_change(M,k,l,car1,car2);
    verti_color_change(M,k,l,car1,car2);
    diag_color_change(M,k,l,car1,car2);
    anti_diag_color_change(M,k,l,car1,car2);
    iter++;
  } while(!plein(M));
  if(pawn.Bl<pawn.Wh) printf("White is the winner!! Congrats!!\n Black, Try next time!!");
  else if(pawn.Wh<pawn.Bl) printf("Black is the winner!! Congrats!!\n White, Try next time!!");
  else printf("it's a draw!! you both are winners and losers!!");
  player1.score=pawn.Bl;
  player2.score=pawn.Wh;
}
