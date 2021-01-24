void print_moves(int k, int l, int iter){
      int tab=(int **)malloc(64*sizeof(int**));
      int i;
      for(i=0;i<64;i++){
          *tab+i=(int*)malloc(2*sizeof(int*));
      }
      tab[iter][0]=k;
      tab[iter][1]=l;
      printf("\n until now the moves played were:\n")
      for(i=0;i<iter+1;i++){
        printf("(%d,%d)",tab[i][0],tab[i][1]);
        if(iter%2==0) printf("\t");
        else printf("\n");
      }

iter %2==0{
   we change to black and look for white
}