joueurliste inorder_insert(joueurliste liste,joueur *newplayer){
  joueurliste following=liste;
  while((following->next!=NULL) && (following->next->info->score<newplayer->info->score)
    following=following->next;
  newplayer->next=following->next;
  following->next=newplayer;
  return following;
}

void topten(){
  joueurliste liste=NULL;
  playerID player;
  int i=0;
  FILE *data=fopen("BaseDeDonnees.txt","r+");
  while(!feof(data)){
   fscanf(data,"%s\t%d\n",player.username,&player.score);
   joueur *newplayer=(joueur *)malloc(sizeof(joueur));
   strcpy((*newplayer).info.username,player.username);
   (*newplayer).info.score=player.score;
   (*newplayer).next=NULL;
   liste=inorder_insert(liste,newplayer);
   nbplayer++;
 }
 fclose(data);
 printf("the TOP 10 scores are : \n");
 while(i<10 && liste!=NULL){
   printf("%s\t%d\n",liste->info->username,liste->info->score);
   liste=liste->next;
   i++
  }
  if(i!=10) printf("Not Enough Players!!\n");
}