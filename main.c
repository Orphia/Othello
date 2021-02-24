#include "libETdecla.h"
#include "PossibleCase.h"
#include "ColorChange.h"
#include "others.h"
#include "livrable1.h"
#include "livrable2.h"
#include "livrable3.h"
void main(){
  printf("_________________Welcome to the game!!__________________\n");
  int first_time; // signifie la première visite de l'utilisateur
  playerID player1;
  do { printf("1: login\n2: sign up\n3: Exit\n Make your choice:\n");
    scanf("%d",&first_time);
    switch (first_time) {
      case 1: { printf("Type ur username\n");
          scanf("%s",player1.username);
          login(player1);
          break; }
      case 2: { printf("Type ur username\n");
          scanf("%s",player1.username);
          signup(player1);
          break; }
      case 3: exit(EXIT_FAILURE);
    }
  } while(first_time!= 1 && first_time!=2 && first_time!=3);
  menu0(player1);
}
