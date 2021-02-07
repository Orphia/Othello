#include "libETdecla.h"
#include "others.h"
void afficher_plat(matrice M) {
  int i,j;
  printf("    0     1     2     3     4     5     6     7  \n");
  printf("  _______________________________________________\n");
  for (i = 0; i < 8; i++) {
    printf(" |     |     |     |     |     |     |     |     |\n");
    printf("%d|",i);
    for (j = 0;j < 8;j++)
      printf("  %c  |",M[i][j]);
    printf("\n");
    printf(" |_____|_____|_____|_____|_____|_____|_____|_____|\n");
  }
}

couple pawn_calculator(matrice M) {
  int i,j;
  couple pawn;
  pawn.Wh=0;
  pawn.Bl=0; // Wh= le nbre de pions blancs et Bl=le nbre de pions noirs
  for(i=0;i<8;i++) {
    for(j=0;j<8;j++) {
       if (M[i][j]=='N') pawn.Bl++;
       else if (M[i][j]=='B') pawn.Wh++;
    }
  }
  printf("\nLe nombre des pions Blancs est:\t %d\n",pawn.Wh);
  printf("Le nombre des pions noirs est:\t %d\n",pawn.Bl);
  return pawn;
}

int plein(matrice M) {
  int i,j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (M[i][j]==' ' || M[i][j]=='O')
         return false;
    }
  }
  return true;
}
