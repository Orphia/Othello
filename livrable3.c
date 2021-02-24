#include "libETdecla.h"
#include "PossibleCase.h"
#include "ColorChange.h"
#include "others.h"
#include "livrable1.h"
#include "livrable2.h"
#include "livrable3.h"


void login(playerID player) {
  int i,checked=false,trouve=false; // on vérifie avec "trouvé" l'existence du non du username dans le fichier et avec "checked" le fait que son mot de passe est valide
  char username[30],password[30],entered_password[30];
  FILE *fichier=fopen("password.txt","a+");
  while(!feof(fichier) && checked==false) {
    fscanf(fichier,"%s\t%s\n",username,password);
    if(strcmp(username,player.username)==0) {
       trouve=true;
       for(i=0;i<3;i++) {
         printf("Type ur password\n");
         scanf("%s",entered_password);
         if(strcmp(entered_password,password)==0) {
            checked=true;
            break;
          }
         printf("Wrong password!");
       }
       break;
      }
    }
  if(trouve==false || checked==false){ // checked a resté "false" après les 3 essais
    printf("Seems like you aren't registred yet!\n");
    fclose(fichier);
    return main();
  }
  fclose(fichier);
}
void signup(playerID player1) {
  int trouve=false; // vérifie l'unicité du username dans notre base de données
  char username[30],password[30],entered_password[30],confirmed_password[30];
  FILE *fichier=fopen("password.txt","a+");
  while(!feof(fichier)) {
    fscanf(fichier,"%s\t%s\n",username,password);
    if(strcmp(username,player1.username)==0) {
       trouve=true;
       printf("Already exists ");
       fclose(fichier);
       return main();
      }
    }
  if(trouve==false){
    do { printf("Create your password\nPS1: Your password must contain only charcters and numbers\n");
        scanf("%s",entered_password);
        printf("Confirm password!!\n");
        scanf("%s",confirmed_password);
        if(strcmp(confirmed_password,entered_password)==0)
           fprintf(fichier,"%s\t%s\n",player1.username,entered_password);
        else printf("passwords do not match!!\n");
    }while(strcmp(confirmed_password,entered_password)!=0); } // on n'a pas précisé la taille de cette boucle, car s'il ne peut pas confirmer son mot de passe il peut créer un autre et le confirmer
  fclose(fichier);
}
