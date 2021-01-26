int reload(char partID){
    int cur;
    FILE *fic=fopen("gamepart.txt","r+");
    if(fic==NULL) {
      printf("\nError!!\n");
      exit(EXIT_FAILURE);
    }
    while(!feof(fich)) {
      if(strcmp(name,partID)==0){
          cur=ftell(fic);
          break;
      }
    fclose(fic);
    return cur;
}