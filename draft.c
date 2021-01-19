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