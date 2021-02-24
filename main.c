#include "libETdecla.h"
#include "PossibleCase.h"
#include "ColorChange.h"
#include "others.h"
#include "livrable1.h"

void main();

void play_human(playerID player1, playerID player2, int load,char partID[30],int up) {
  int iter=0;
  int tab[64][2];
  int i,j,k,l,code,save,S=0,R=true;
  char car1, car2, player='N';
  couple pawn;
  matrice M;
  cordonnee cord;
  cord.cur=0;
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
       pawn=pawn_calculator(M);
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
      if(R==true) { // R=true pour donner la main au joueur de terminer une partie chargée
        printf("_______________________________________________________________________\n");
        printf("%c , it's your turn!!\n",player);
        afficher_plat(M);
        pawn=pawn_calculator(M);
      }
      if (load==false){  // load vérifie si on est au cours de loading d'une partie
        R=true;
        up=true; //up vérifie la possibilité d'uploader une partie
        if(iter>=1) {
          printf("\ntap 9 to restart!! And any other number to continue!!\n");
          scanf("%d",&code);
          if(code==9) {
            printf("tap 1 to save it!!\n");
            scanf("%d",&save);
            if(save==1)
              upload(tab,iter);
            return main();
          }
        }
        do {
          printf("\nChose a case:\n");
          scanf("%d",&k);
          scanf("%d",&l);
          if(M[k][l]!='O' || k<0 || k>=8 || l<0 || l>=8) {
            printf(" ASH KATRWEN! MABANT LEK GHA HADIK !!!!!!!!!!!!!!!!!! \n");
          }
        } while(M[k][l]!='O' || k<0 || k>=8 || l<0 || l>=8);
      } else { //le programme joue automatiquement chaque mouvement lu d'après le fichier de sauvegarde
           if (reload(cord,partID).x != 9 && reload(cord,partID).y != 9) {
              k=reload(cord,partID).x;
              l=reload(cord,partID).y;
              cord.cur=reload(cord,partID).cur;
           } else {
              load=false;
              R=false;
              for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                  if (M[i][j]=='O')
                    M[i][j]=' ';
                }
              }
              continue;
           }
       }
    tab[iter][0]=k;
    tab[iter][1]=l;
    print_moves(tab,iter); // afficher l'historique
    printf("\n");
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
  if(up==true) upload(tab,iter); // on a ajouté la variable up pour éviter le cas de demande de chargement d'une partie complète
  if(pawn.Bl<pawn.Wh) printf("White is the winner!! Congrats!!\nBlack, Try next time!!");
  else if(pawn.Wh<pawn.Bl) printf("Black is the winner!! Congrats!!\nWhite, Try next time!!\n");
  else printf("it's a draw!! you both are winners and losers!!\n");
  printf("_______________________________\n");
  player1.score=pawn.Bl;
  player2.score=pawn.Wh;
  stocker(player1);
  stocker(player2);
  topten();
}

void main(){
  playerID player1,player2;
  int choice1,load,ex=false, up=false;
  char partID[30];
  printf("\nPLAYER 1: tapez votre nom\n");
  scanf("%s",player1.username);
  printf("\nPLAYER 2: tapez votre nom\n");
  scanf("%s",player2.username);
  do {
    printf("__________________________Menu1__________________________\n");
    printf("1.Play\n2.Load an existing game\n3.Exit\nMake your choice:\n");
    scanf("%d",&choice1);
    switch(choice1){
      case 1: { load=false;
                up=true;
          play_human(player1, player2, load,partID,up);
          break; }
      case 2:{ load=true;
               up=false;
           printf("tap the name of the desired part!!\n");
           scanf("%s",partID);
           play_human(player1, player2, load,partID,up);
          break; }
      case 3: { ex=true;
        break; }
      default: { printf("looks like you made a wrong choice my friend!!\n"); }
     }
  }while(ex==false); // réafficher le menu
  if(ex==true) exit(EXIT_FAILURE);
}
