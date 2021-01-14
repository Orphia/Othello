do{
      for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          hori_possible(M,i,j,car1,car2);
          verti_possible(M,i,j,car1,car2);
          diag_possible(M,i,j,car1,car2);
          anti_diag_possible(M,i,j,car1,car2);
        }
      }
      if (possible_case==false) {
        s++;
        car3=car1;
        car1=car2;
        car2=car3;
      }
      else {
        afficher_plat(M);
        pawn=pawn_calculator(M);
        break;}
    }while(s==1);
    if(s==2){
        break;
    }
int canplay(matrice M,int iter){
  int i,j,s=0;
  for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          hori_possible(M,i,j,car1,car2);
          verti_possible(M,i,j,car1,car2);
          diag_possible(M,i,j,car1,car2);
          anti_diag_possible(M,i,j,car1,car2);
        }
      }
  if (possible_case) return true;
  return false;
}