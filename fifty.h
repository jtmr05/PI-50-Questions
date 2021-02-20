#ifndef PI_FIFTY_H
#define PI_FIFTY_H
#include "aux.h"

void maior();
void media();
void smaior();
int bitsUm (unsigned int n);
int trailingZ (unsigned int n);
int qDig (unsigned int n);
char *mystrcat (char s1[], const char s2[]);
char *mystrcpy (char *dest, const char *source);
int mystrcmp (const char s1[], const char s2[]);
char *mystrstr (char mainstr[], const char substr[]);
void mystrrev (char s[]);
void mystrnoV (char s[]);
void truncW (char t[], int fator);
char charMaisfreq (const char s[]);
int iguaisConsecutivos (const char s[]);
int difConsecutivos (const char s[]);
int maiorPrefixo (const char s1 [], const char s2 []);
int maiorSufixo (const char s1 [], const char s2 []);
int sufPref (const char sufix[], const char prefix[]);
int contaPal (const char s[]);
int contaVogais (const char s[]);
int contida (const char a[], const char b[]);
int palindorome (const char s[]);
int remRep (char x[]);
int limpaEspacos (char t[]);
void insere (int v[], int N, int x);
void merge (int r [], const int a[], const int b[], int na, int nb);
int crescente (const int l[], int a, int z);
int retiraNeg (int v[], int N);
int menosFreq (const int v[], int N);
int maisFreq (const int v[], int N);
int maxCresc (const int v[], int N);
int elimRep (int v[], int N);
int elimRepOrd (int v[], int N);
int comunsOrd(const int a[], int na, const int b[], int nb);
int comuns(const int a[], int na, const int b[], int nb);
int minInd (const int v[], int N);
void somasAc (const int v[], int Ac [], int N);
int triSup (int N, float m[N][N]);
void transposta (int N, float m [N][N]);
void addTo (int N, int M, int a [N][M], int b[N][M]);
int unionSet (int N, const int v1[N], const int v2[N], int r[N]);
int intersectSet (int N, const int v1[N], const int v2[N], int r[N]);
int intersectMSet (int N, const int v1[N], const int v2[N], int r[N]);
int unionMSet (int N, const int v1[N], const int v2[N], int r[N]);
int cardinalMSet (int N, const int v[N]);
Posicao posFinal (Posicao inicial, const Movimento mov[], int N); //47
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N);
int maisCentral (Posicao pos[], int N);
int vizinhos (Posicao p, Posicao pos[], int N);

#endif //PI_FIFTY_H
