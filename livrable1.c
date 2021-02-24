#include "libETdecla.h"
#include "livrable1.h"

void stocker(playerID player) {
  int S=false;
  char car;
  int old_score,new_score;
  char nom[30];
  FILE *old_file=fopen("BaseDeDonnees.txt","a+");
  FILE *new_file=fopen("bdd.txt","a+");
  while(!feof(old_file)) {
      fscanf(old_file,"%s\t\t\t%d\n",nom,&old_score);
      if(strcmp(nom,player.username)!=0)
         fprintf(new_file,"%s\t\t\t%d\n",nom,old_score);
      else {
         new_score=old_score+player.score;
         fprintf(new_file,"%s\t\t\t%d\n",nom,new_score);
         S=true;
     }
  }
  if(S==false) fprintf(new_file,"%s\t\t\t%d\n",player.username,player.score);
  fclose(old_file);
  fclose(new_file);
  remove("BaseDeDonnees.txt");
  rename("bdd.txt","BaseDeDonnees.txt");
}

void print_moves(int tab[64][2], int iter){
      int i;
      printf("\n until now the moves played were:\n");
      for(i=0;i<iter+1;i++){
        printf("(%d,%d)",tab[i][0],tab[i][1]);
        if(i%2==0) printf("\t");
        else printf("\n");
   }
}

void upload(int tab[64][2],int iter) {
  int exist,i;
  char partID[30],name[30];
  FILE *fich=fopen("gamepart.txt","a+");
  printf("to store the game, name it:\n");
  do {
      exist=false;
      scanf("%s",partID);
      while(!feof(fich)) {
        fscanf(fich,"%s\n",name);
        if(strcmp(name,partID)==0) {
            printf("exists already!! change it !!\n");
            exist=true;
            rewind(fich);
            break; }
          }
     }while(exist);
    fprintf(fich,"%s ",partID);
    for(i=0;i<iter;i++)                 // hna madernash iter + 1 f7al printmoves 7it mazal ma3merna l case dial iter
      fprintf(fich,"%d %d ",tab[i][0],tab[i][1]);
    fprintf(fich,"9 9");
    fprintf(fich,"\n");
    fclose(fich);
}

cordonnee reload(cordonnee cord, char partID[30]){
    char name[30];
    FILE *fic=fopen("gamepart.txt","r+");
    if(fic==NULL) {
      printf("\nError!!\n");
      exit(EXIT_FAILURE);
    }
    while(!feof(fic)) {
      fscanf(fic,"%s \n",name);
      if(strcmp(name,partID)==0){
        if(cord.cur==0){
          fscanf(fic,"%d %d ",&cord.x,&cord.y);
          cord.cur=ftell(fic);
        }
        else {
          fseek(fic,cord.cur,SEEK_SET);
          fscanf(fic,"%d %d ",&cord.x,&cord.y);
          cord.cur=ftell(fic);
        }
        break;
      }
    }
    fclose(fic);
    return cord;
}

void inorder_insert(joueurliste liste,joueur *newplayer){
  joueurliste current;
  if(liste==NULL || liste->info->score<=newplayer->info->score){
    newplayer->next=liste;
    liste=newplayer;
  }
  else{
    current=liste;
    while(current->next!=NULL && current->next->info->score > newplayer->info->score){
      current=current->next;
    }
    newplayer->next=current->next;
    current->next=newplayer;
  }
}

void topten(){
  joueurliste liste=NULL;
  playerID player;
  int i=0;
  FILE *data=fopen("BaseDeDonnees.txt","r+");
  joueur *newplayer=(joueur *)malloc(sizeof(joueur));
  newplayer->info= (playerID*)malloc(sizeof(playerID));
  fscanf(data,"%s\t\t\t%d\n",player.username,&player.score);
  strcpy(newplayer->info->username,player.username);
  newplayer->info->score=player.score;
  newplayer->next=NULL;
  liste=newplayer;
  while(!feof(data)){
   fscanf(data,"%s\t\t\t%d\n",player.username,&player.score);
   joueur *newplayer=(joueur *)malloc(sizeof(joueur));
   newplayer->info= (playerID*)malloc(sizeof(playerID));
   strcpy(newplayer->info->username,player.username);
   newplayer->info->score=player.score;
   newplayer->next=NULL;
   inorder_insert(liste,newplayer);
 }
 fclose(data);
 printf("the TOP 10 scores are : \n");
 while(i<10 && liste!=NULL){
   printf("%s\t%d\n",liste->info->username,liste->info->score);
   liste=liste->next;
   i++;
  }
  if(i!=10) printf("Not Enough Players!!\n");
}
