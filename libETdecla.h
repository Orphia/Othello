#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef char matrice[8][8];
typedef struct { int Wh; int Bl;} couple;
typedef struct { char username[30]; int score;} playerID;
typedef struct {int x ; int y ; int cur; } cordonnee;
typedef struct _joueur{ playerID *info; struct _joueur *next;} joueur;
typedef joueur *joueurliste;