//les fcts possibles
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef char matrice[8][8];
typedef struct { int Wh; int Bl;} couple;
typedef struct { char username[30]; int score;} playerID;
typedef struct { int curseur1; int curseur2;} curseur;

void hori_possible(matrice M,int l, int k,char car1,char car2) {
  int i;
  if (M[l][k]==car1) {
      if (M[l][k+1]== car2) {
        for(i=k+2;i<8;i++) {
          if (M[l][i]==' ' || M[l][i]=='O') {
             M[l][i]='O';
             break;
           }
          if (M[l][i]==car1)
             break;
          }
       }
      if (M[l][k-1]==car2) {
        for(i=k-2;i>-1;i--) {
          if (M[l][i]==' ' || M[l][i]=='O') {
             M[l][i]='O';
             break;
           }
          if (M[l][i]== car1)
             break;
        }
      }
    }
}
void verti_possible(matrice M,int l, int k,char car1,char car2) {
  int i;
  if (M[l][k]==car1) {
      if (M[l+1][k]==car2) {
        for(i=l+2;i<8;i++) {
          if (M[i][k]==' ' || M[i][k]=='O') {
             M[i][k]='O';
             break;
           }
          if (M[i][k]==car1)
             break;
          }
      }
      if (M[l-1][k]==car2) {
        for(i=l-2;i>-1;i--) {
          if (M[i][k]==' ' || M[i][k]=='O') {
             M[i][k]='O';
             break;
           }
          if (M[i][k]== car1)
             break;
       }
    }
  }
}
void diag_possible(matrice M, int l, int k,char car1,char car2) {
  int i,j;
  if (M[l][k]==car1) {
      if (M[l+1][k+1]==car2){
        i=l+2;
        j=k+2;
        while (i<8 && j<8) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car1) {
            break;
          }
          i++;
          j++;
        }
      }
      if (M[l-1][k-1]==car2) {
        i=l-2;
        j=k-2;
        while (i>-1 && j>-1) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car1) {
            break;
          }
          i--;
          j--;
        }
      }
    }
}
void anti_diag_possible(matrice M, int l, int k,char car1,char car2) {
  int i, j;
  if (M[l][k]==car1) {
      if (M[l-1][k+1]==car2){
        i=l-2;
        j=k+2;
        while (i>-1 && j<8) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car1) {
            break; }
        i--;
        j++;
        }
      }
     if (M[l+1][k-1]==car2) {
        i=l+2;
        j=k-2;
        while (i<8 && j>-1) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car1) {
            break;
          }
          i++;
          j--;
        }
      }
    }
}
int possible_case(matrice M) {
  int i,j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (M[i][j]=='O')
         return true;
    }
  }
  return false;
}

void hori_color_change(matrice M, int k, int l, char car1,char car2) {
    int i, s=0,r=0,j,p;
    int T[6]={0,0,0,0,0,0};
    for(i=l+1;i<8;i++) { //ghadi ichanger le noir
            if (M[k][i]==car1) {
                s++;
                T[s-1]=i;}
            else if (M[k][i]==car2){
                if (s==0) break;
                else {
                    for(j=0;j<s;j++) {
                       p=T[j];
                       M[k][p]=car2; }
                    break; } }
            else break; }
        for(i=l-1;i>-1;i--) {
            if (M[k][i]==car1) {
                r++;
                T[r-1]=i; }
            else if (M[k][i]==car2){
                if (r==0) break;
                else {
                    for(j=0;j<r;j++) {
                       p=T[j];
                       M[k][p]=car2;}
                    break; } }
            else break; }
}
void verti_color_change(matrice M, int k, int l, char car1,char car2) {
    int i, s=0,r=0,j,p;
    int T[6]={0,0,0,0,0,0};
    for(i=k+1;i<8;i++) {
            if (M[i][l]==car1) {
                s++;
                T[s-1]=i;}
            else if (M[i][l]==car2){
                if (s==0) break;
                else {
                    for(j=0;j<s;j++) {
                       p=T[j];
                       M[p][l]=car2; }
                    break; } }
            else break; }
        for(i=k-1;i>-1;i--) {
            if (M[i][l]==car1) {
                r++;
                T[r-1]=i; }
            else if (M[i][l]==car2){
                if (r==0) break;
                else {
                    for(j=0;j<r;j++) {
                       p=T[j];
                       M[p][l]=car2;}
                    break; } }
            else break; }
}
void diag_color_change(matrice M, int k, int l, char car1,char car2) {
    int i, s=0,t=0,r,j,p,q;
    int T[6][2]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    i=k+1;
    j=l+1;
    while(i<8 && j<8){ //ghadi ichanger le noir
        if (M[i][j]==car1) {
                s++;
                T[s-1][0]=i;
                T[s-1][1]=j;}
            else if (M[i][j]==car2){
                if (s==0) break;
                else {
                    for(r=0;r<s;r++) {
                       p=T[r][0];
                       q=T[r][1];
                       M[p][q]=car2; }
                    break; } }
            else break;
        i++;
        j++; }
    i=k-1;
    j=l-1;
    while(i>-1 && j>-1){
        if (M[i][j]==car1) {
                t++;
                T[t-1][0]=i;
                T[t-1][1]=j; }
        else if (M[i][j]==car2){
                if (t==0) break;
                else {
                    for(r=0;r<t;r++) {
                       p=T[r][0];
                       q=T[r][1];
                       M[p][q]=car2;}
                    break; } }
            else break;
        i--;
        j--;}
}
void anti_diag_color_change(matrice M, int k, int l, char car1,char car2) {
    int i, s=0,t=0,r,j,p,q;
    int T[6][2]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    i=k-1;
    j=l+1;
    while(i>-1 && j<8){ //ghadi ichanger le noir
        if (M[i][j]==car1) {
                s++;
                T[s-1][0]=i;
                T[s-1][1]=j;}
            else if (M[i][j]==car2){
                if (s==0) break;
                else {
                    for(r=0;r<s;r++) {
                       p=T[r][0];
                       q=T[r][1];
                       M[p][q]=car2; }
                    break; } }
            else break;
        i--;
        j++; }
    i=k+1;
    j=l-1;
    while(i<8 && j>-1){
        if (M[i][j]==car1) {
                t++;
                T[t-1][0]=i;
                T[t-1][1]=j; }
        else if (M[i][j]==car2){
                if (t==0) break;
                else {
                    for(r=0;r<t;r++) {
                       p=T[r][0];
                       q=T[r][1];
                       M[p][q]=car2;}
                    break; } }
            else break;
        i++;
        j--;}
}

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

curseur username_base() {
  playerID player1,player2;
  FILE *data;
  char name[30];
  int exist,score, f, first_visit;
  curseur cursor;
  data = fopen("database.txt","a+");
  if(data==NULL) {
    printf("\nError!!\n");
    exit(EXIT_FAILURE);
  }
  printf("______________Welcome to the game!!_______________\n\n\nPLAYER 1 :Type 1 if this is your first visit and 0 otherwise :\n");
  scanf("%d",&first_visit);
  printf("Please enter your username!!\n\n");
  if(first_visit==true){
    player1.score=0;
    do {
      exist=false;
      scanf("%s",player1.username);
      while(!feof(data)) {
        fscanf(data,"%s\t%d\n",name,&score);
        if(strcmp(name,player1.username)==0) {
            printf("exists already!! change it !!\n");
            exist=true;
            rewind(data);
            break; }
          }
     }while(exist);
    fprintf(data,"\n%s\t",player1.username);
    cursor.curseur1=ftell(data);
    fprintf(data,"%d",player1.score);
    fclose(data);
  }
  else{
    data = fopen("database.txt","a+");
   if(data==NULL) {
    printf("\nError!!\n");
    exit(EXIT_FAILURE);
    }
      scanf("%s",player1.username);
      while(!feof(data)) {
        fscanf(data,"%s\t%d\n",name,&score);
        if(strcmp(name,player1.username)==0) {
            cursor.curseur1=ftell(data);
            f=1;
            break; }
          }  
      if(f!=1) {
        player1.score=0;
        printf("looks like this is your first time with us!!\n");
        fprintf(data,"\n%s\t%d",player1.username,player1.score);
        cursor.curseur1=ftell(data);
      }
    fclose(data);
  }
  data = fopen("database.txt","a+");
  if(data==NULL) {
    printf("\nError!!\n");
    exit(EXIT_FAILURE);
  }
  printf("______________Welcome to the game!!_______________\n\n\nPLAYER 2 :Type 1 if this is your first visit and 0 otherwise :\n");
  scanf("%d",&first_visit);
  printf("Please enter your username!!\n\n");
  if(first_visit==true){
    do {
      player2.score=0;
      exist=false;
      scanf("%s",player2.username);
      while(!feof(data)) {
        fscanf(data,"%s\t%d\n",name,&score);
        if(strcmp(name,player2.username)==0) {
            printf("exists already!! change it !!\n");
            exist=true;
            rewind(data);
            break; }
          }
     }while(exist);
    fprintf(data,"\n%s\t%d",player2.username,player2.score);
    cursor.curseur2=ftell(data);
    fclose(data);
  }
  else{
    data = fopen("database.txt","a+");
   if(data==NULL) {
    printf("\nError!!\n");
    exit(EXIT_FAILURE);
    }
      scanf("%s",player2.username);
      while(!feof(data)) {
        fscanf(data,"%s\t%d\n",name,&score);
        if(strcmp(name,player2.username)==0) {
            cursor.curseur2=ftell(data);
            f=1;
            break; }
          }  
      if(f!=1) {
        player2.score=0;
        printf("looks like this is your first time with us!!\n");
        fprintf(data,"\n%s\t%d",player2.username,player2.score);
        cursor.curseur2=ftell(data);
      }
    fclose(data);
  }
  return cursor;
}

void score_update(curseur cursor,){
  playerID player1, player2;
  FILE *data;
  data = fopen("database.txt","a+");
  if(data==NULL) {
    printf("\nError!!\n");
    exit(EXIT_FAILURE);
  }
  fseek(data,cursor.curseur1,SEEK_CUR);
  
}

int main() {
  int iter=0,s;
  int i,j,k,l,code;
  char car1, car2, car3, player='N';
  couple pawn;
  matrice M;
  curseur cursor;
  cursor=username_base();
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
  M[3][2]='O';
  M[4][5]='O';
  M[2][3]='O';
  M[5][4]='O';
  afficher_plat(M);
  printf("\nLe nombre des pions Blancs est:\t 2\n");
  printf("Le nombre des pions noirs est:\t 2\n");
  do {
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
      printf("%c , it's your turn!!",player);
      if(iter>=1) {
        printf("\ntap 1 to restart!! And any oher key to continue!!\n");
        scanf("%d",&code);
        if(code==1) return main();
      }
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
    s=0;
    while(s<2) {
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          hori_possible(M,i,j,car1,car2);
          verti_possible(M,i,j,car1,car2);
          diag_possible(M,i,j,car1,car2);
          anti_diag_possible(M,i,j,car1,car2);
        }
      }
      if (!possible_case) {
        s++;
        iter++;
        car3=car1;
        car1=car2;
        car2=car3;
      }
      else {
        afficher_plat(M);
        pawn=pawn_calculator(M);
        break;}
    }
    if(s==2) break;
    iter++;
  } while(!plein(M));

  if(pawn.Bl<pawn.Wh) printf("White is the winner!! Congrats!!\n Black, Try next time!!");
  else if(pawn.Wh<pawn.Bl) printf("Black is the winner!! Congrats!!\n White, Try next time!!");
  else printf("it's a draw!! you both are winners and losers!!");
  return 0;
}