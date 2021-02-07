#include "libETdecla.h"
#include "PossibleCase.h"
void hori_possible(matrice M,int l, int k,char car1,char car2) {
  int i;
  if (M[l][k]==car2) {
      if (M[l][k+1]== car1) {
        for(i=k+2;i<8;i++) {
          if (M[l][i]==' ' || M[l][i]=='O') {
             M[l][i]='O';
             break;
           }
          if (M[l][i]==car2)
             break;
          }
       }
      if (M[l][k-1]==car1) {
        for(i=k-2;i>-1;i--) {
          if (M[l][i]==' ' || M[l][i]=='O') {
             M[l][i]='O';
             break;
           }
          if (M[l][i]== car2)
             break;
        }
      }
    }
}
void verti_possible(matrice M,int l, int k,char car1,char car2) {
  int i;
  if (M[l][k]==car2) {
      if (M[l+1][k]==car1) {
        for(i=l+2;i<8;i++) {
          if (M[i][k]==' ' || M[i][k]=='O') {
             M[i][k]='O';
             break;
           }
          if (M[i][k]==car2)
             break;
          }
      }
      if (M[l-1][k]==car1) {
        for(i=l-2;i>-1;i--) {
          if (M[i][k]==' ' || M[i][k]=='O') {
             M[i][k]='O';
             break;
           }
          if (M[i][k]== car2)
             break;
       }
    }
  }
}
void diag_possible(matrice M, int l, int k,char car1,char car2) {
  int i,j;
  if (M[l][k]==car2) {
      if (M[l+1][k+1]==car1){
        i=l+2;
        j=k+2;
        while (i<8 && j<8) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car2) {
            break;
          }
          i++;
          j++;
        }
      }
      if (M[l-1][k-1]==car1) {
        i=l-2;
        j=k-2;
        while (i>-1 && j>-1) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car2) {
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
  if (M[l][k]==car2) {
      if (M[l-1][k+1]==car1){
        i=l-2;
        j=k+2;
        while (i>-1 && j<8) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car2) {
            break; }
        i--;
        j++;
        }
      }
     if (M[l+1][k-1]==car1) {
        i=l+2;
        j=k-2;
        while (i<8 && j>-1) {
          if(M[i][j]==' ' || M[i][j]=='O') {
            M[i][j]='O';
            break;
          }
          if (M[i][j]==car2) {
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
