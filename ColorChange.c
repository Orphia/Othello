#include "libETdecla.h"
#include "ColorChange.h"
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
