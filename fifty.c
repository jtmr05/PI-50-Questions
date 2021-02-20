#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "aux.h"

//1
void maior(){
    int n, m = 0;
    do{
        printf("Introduza um número inteiro: ");
        scanf("%d",&n);
        if (n>m) m=n;
    } while (n);
    printf("%d é o maior número introduzido\n", m);
}

//2
void media(){
    double r=0;
    int i=0, n;
    do{
        printf("Introduza um número inteiro: ");
        scanf("%d",&n);
        r += n;
        i++;
    } while (n);
    r = r/i;
    printf("%lf é a média\n", r);
}

//3
void smaior(){
    int n, m=0, sm=0, flag=1;
    do {
        printf("Introduza um número inteiro: ");
        scanf("%d", &n);
        switch (flag) {
            case 1:
                m = n;
                flag++;
                break;

            case 2:
                if (m > n) sm = n;
                else {
                    sm = m;
                    m = n;
                }
                flag++;
                break;

            default:
            if (n > m) {
            sm = m;
            m = n;
        } else if (n > sm) sm = n;
    }
    } while (n);
    if (flag==2)
        printf("Apenas um número introduzido!\n");
    else
        printf("%d é o segundo maior número introduzido\n", sm);
}

//4
int bitsUm (unsigned int n){
    int i=0;
    unsigned int n0=n;
    while(n){
        if (n%2) i++;
        n=n/2;
    }
    printf("Usado(s) %d bit(s) com valor 1 para representar %d\n",i,n0);
    return i;
}

//5
int trailingZ (unsigned int n){
    int i=0;
    unsigned int n0=n;
    //i = (n==0) ? 32 : 0; //assume-se um valor máximo de 32 bits para representar 0??
    while(n){
        if (!n%2) i++;
        else break;
        n=n/2;
    }
    printf("Usado(s) %d bit(s) final(is) com valor 0 para representar %d\n",i,n0);
    return i;
}

//6
int qDig (unsigned int n){
    int i=1;
    unsigned int n0 = n;
    if (n)
        i += (int) log10(n);
    printf("Usado(s) %d dígito(s) para representar %d\n",i, n0);
    return i;
}

//7
char *mystrcat (char s1[], const char s2[]){
    int i;
    const size_t n1 = strlen(s1);
    for (i=0; *(s2+i) ;i++)
        *(s1+n1+i) = *(s2 + i);
    *(s1+n1+i) = '\0';
    printf("'%s'\n", s1);
    return s1;
}

//8
char *mystrcpy (char *dest, const char *source){
    int i;
    for(i=0; *(source+i); i++)
        *(dest+i) = *(source+i);
    *(dest+i) = '\0';
    printf("'%s'\n", dest);
    return dest;
}

//9
int mystrcmp (const char s1[], const char s2[]){
    int i=0, r;
    while(*(s1+i) && *(s2+i) && *(s1+i)==*(s2+i))
        i++;
    r = *(s1+i) - *(s2+i);
    if (r!=0)
        r = (r>0) ? 1 : -1;
    switch (r){
        case 0:
            printf("São iguais!\n");
            break;

        case 1:
            printf("'%s' é maior\n",s1);
            break;

        default:
            printf("'%s' é maior\n",s2);
            break;
    }
    return r;
}

//10
char *mystrstr (char mainstr[], const char substr[]){
   // if (!(*(substr))) return mainstr; se substr=="", então devia retornar ""
   int h=0, i;
   while(1) {
       for (i = h; *(mainstr + i) && *(mainstr + i) != *(substr); i++);
       if (!*(mainstr + i)){
           printf("NULL!\n");
           return NULL;
       }
       h=i;
       for (i = 0; *(mainstr + i + h) && *(substr + i) && *(mainstr + i + h) == *(substr + i); i++);
       if (!*(substr + i)){
           printf("Substring inicia-se neste ponto: '%s'\n",(mainstr+h));
           return (mainstr + h);
       }
       h+=i;
       }
}

//11
void mystrrev (char s[]){
    int i;
    const size_t N = strlen(s);
    const size_t N2 = N/2;
    char temp;
    for(i=0;i<N2;i++){
        temp = s[i];
        s[i] = s[N-i-1];
        s[N-i-1] = temp;
    }
    printf("'%s' é a string invertida\n",s);
}

//12
void mystrnoV (char s[]){
    int i=0, j;
    while(*(s+i))
        if (isVowel(*(s+i)))
            for(j=i;*(s+j);j++)
                *(s+j) = *(s+j+1);
        else i++;
    printf("strng sm vgs: '%s'\n",s);
}

//13
void truncW (char t[], int fator){
    fator = (fator<0) ? 0 : fator;
    int i=0, cont=0, j, h=0;
    while (*(t+i)){
        for (i=h; *(t+i)!=' ' && cont<fator; i++){
            cont++;
            h++;
        }
        if (cont==fator)
            while(*(t+i)!=' ' && *(t+i))
                for(j=i;*(t+j);j++)
                    *(t+j) = *(t+j+1);
        cont=0;
        while(*(t+i)==' ' && *(t+i)){
            i++;
            h++;
        }
    }
    printf("string truncada: '%s'\n",t);
}

//14
char charMaisfreq (const char s[]){
    int i, pos, *freq, mais=0;
    char c = '\0';
    freq = calloc(256,sizeof(int));
    for(i=0;*(s+i);i++){
        pos = (int) *(s+i);
        freq[pos]++;
        if (freq[pos]>mais){
            mais = freq[pos];
            c = *(s+i);
        }
    }
    free(freq);
    printf("char mais frequente: '%c'\n",c);
    return c;
}

//15
int iguaisConsecutivos (const char s[]){
    int i=0, cont=0, temp=0, h=1;
    char c = *s;
    while(*(s+i)){
        for (i=h;*(s + i) && *(s + i) == c;i++)
            c = *(s + i);
        temp = (i - h == 0) ? 0 : i - h + 1;
        cont = (temp > cont) ? temp : cont;
        while (*(s + i) && *(s + i) != c) {
            c = *(s + i);
            i++;
        }
        h=i;
    }
    printf("maior número de iguais consectutivos: %d\n",cont);
    return cont;
}

//16
int difConsecutivos (const char s[]){
    int i=0, cont=0, temp=0, h=1;
    char c = *s;
    while(*(s+i)){
        for (i=h;*(s + i) && *(s + i) != c;i++)
            c = *(s + i);
        temp = (i - h == 0) ? 0 : i - h + 1;
        cont = (temp > cont) ? temp : cont;
        while (*(s + i) && *(s + i) == c) {
            c = *(s + i);
            i++;
        }
        h=i;
    }
    printf("maior número de diferentes consectutivos: %d\n",cont);
    return cont;
}

//17
int maiorPrefixo (const char s1 [], const char s2 []){
    int i=0;
    while(*(s1+i) && *(s2+i) && *(s1+i)==*(s2+i))
        i++;
    printf("maior prefixo tem comprimento %d\n",i);
    return i;
}

//18
int maiorSufixo (const char s1 [], const char s2 []){
    int i=0;
    const size_t N1 = strlen(s1);
    const size_t N2 = strlen(s2);
    while(i<N1 && i<N2 && *(s1+N1-i-1)==*(s2+N2-i-1))
        i++;
    printf("maior sufixo tem comprimento %d\n",i);
    return i;
}

//19
int sufPref (const char sufix[], const char prefix[]) {
    int i, h=0;
    while (1) {
        for (i=h;*(sufix + i) != *prefix && *(sufix + i);i++);
        if (!*(sufix + i)) {
            printf("Não há!\n");
            return 0;
        }
        h = i;
        for (i = 0; *(sufix + h + i) == *(prefix + i) && *(sufix + h + i) && *(prefix + i); i++);
        if (!*(sufix+h+i)){
            printf("Últimos %d chars de '%s' são prefixos de '%s'\n",i,sufix,prefix);
            return i;
        }
        else if (!*(prefix+i)){
            printf("Não há!\n");
            return 0;
        }
        h+=i;
    }
}

//20
int contaPal (const char s[]){
    int i=0, cont=0;
    while(1){
        while(*(s+i) && *(s+i)==' ')
            i++;
        if(*(s+i)) cont++;
        else break;
        while(*(s+i) && *(s+i)!=' ')
            i++;
        if(!*(s+i)) break;
        }
    printf("%d palavra(s) em '%s'\n",cont,s);
    return cont;

}

//21
int contaVogais (const char s[]){
    int i=0, cont=0;
    while(*(s+i)){
       if (isVowel(*(s+i))) cont++;
       i++;
    }
    printf("%d vogais em '%s'\n",cont,s);
    return cont;
}

//22
int contida (const char a[], const char b[]){
    int i, pos, *freq;
    freq = calloc(256,sizeof(int));
    for(i=0;b[i];i++){
        pos = (int) b[i];
        freq[pos]=1;
    }
    for(i=0;a[i];i++){
        pos = (int) a[i];
        if (!freq[pos]){
            free(freq);
            printf("'%s' não está contida em '%s'\n",a,b);
            return 0;
        }
    }
    free(freq);
    printf("'%s' está contida em '%s'\n",a,b);
    return 1;
}

//23
int palindorome (const char s[]){
    int i;
    const size_t N = strlen(s);
    const size_t N2 = N/2;
    for(i=0; i<N2 && *(s+i)==*(s+N-1-i);i++);
    if(i==N2)
        printf("'%s' é palíndroma\n",s);
    else
        printf("'%s' não é palíndroma\n",s);

    return (i==N2);
}

//24
int remRep (char x[]){
    int i=1, j;
    char c = *x;
    if(!c) i=0;
    while(c){
        while(*(x+i) && *(x+i)!=c){
            c=*(x+i);
            i++;
        }
        if(!*(x+i)) break;
        while(*(x+i) && *(x+i)==c)
            for(j=i;*(x+j);j++)
                *(x+j) = *(x+j+1);
        if(!*(x+i)) break;
    }
    printf("'%s', agora com comprimento %d\n",x,i);
    return i;
}

//25
int limpaEspacos (char t[]){
    char c = ' ';
    int i=0, j;
    while(*(t+i)){
        while(*(t+i) && *(t+i)!=c)
            i++;
        while(*(t+i+1)==c)
            for(j=i;*(t+j);j++)
                *(t+j)=*(t+j+1);
        if(*(t+i)) i++;
    }
    printf("'%s', agora com comprimento %d\n",t,i);
    return i;
}

//26
void insere (int v[], int N, int x){
    int i, j;
    for(i=0;i<N;i++){
        if(x<=v[i]){
            for(j=N;j>i;j--)
                v[j] = v[j-1];
            v[i]=x;
            break;
        }
    }
    if(i==N) v[N] = x;
    printf("[");
    for(i=0;i<=N;i++) {
        printf("%d", *(v + i));
        if(i<N) printf(", ");
    }
    printf("]\n");
}

//27
void merge (int r [], const int a[], const int b[], int na, int nb){
    int ia = 0, ib = 0, i;
    while(ia<na && ib<nb)
        if(*(a+ia) < *(b+ib)){
            *(r+ia+ib) = *(a+ia);
            ia++; 
        }
        else{
            *(r+ia+ib) = *(b+ib);
            ib++; 
        }
    if (ia==na) 
        for(i=ib;i<nb;i++)
            *(r+ia+i) = *(b+i);

    if (ib==nb) 
        for(i=ia;i<na;i++)
            *(r+ib+i) = *(a+i);

    printf("[");
    for(i=0;i<na+nb;i++) {
        printf("%d", *(r + i));
        if(i<na+nb-1) printf(", ");
    }
    printf("]\n");
}

//28
int crescente (const int l[], int a, int z){
    int i, j;
    for(i=a; i<z && l[i]<=l[i+1]; i++);

    printf("[");
    for(j=a;j<=z;j++) {
        printf("%d", *(l + j));
        if(j<z) printf(", ");
    }
    printf("] ");

    if(i!=z) printf("não ");
    printf("está ordenado\n");
    return (i==z);
}

//29
int retiraNeg (int v[], int N){
    int i=0, j;
    while(i<N)
        if (*(v+i)<0) {
            for (j = i; j < N; j++)
                *(v + j) = *(v + j + 1);
            N--;
        }
        else i++;

    printf("[");
    for(j=0;j<N;j++) {
        printf("%d", *(v + j));
        if(j<N-1) printf(", ");
    }
    printf("], agora com %d elementos\n",N);

    return N;
}

//30
int menosFreq (const int v[], int N){
    int i=0, contr=N, temp=0, r=*v, vaux=*v;
    while(1) {
        while (i < N && *(v + i) == vaux){
            i++;
            temp++;
        }
        if (temp < contr){
            contr = temp;
            r = vaux;
        }
        temp=0;
        if (i==N) break;
        vaux=*(v+i);
    }
    printf("%d é o menos frequente\n",r);
    return r;
}

//31
int maisFreq (const int v[], int N){
    int i=0, contr=0, temp=0, r=*v, vaux=*v;
    while(1) {
        while (i < N && *(v + i) == vaux){
            i++;
            temp++;
        }
        if (temp > contr){
            contr = temp;
            r = vaux;
        }
        temp=0;
        if (contr>=N-i || i==N) break;
        vaux=*(v+i);
    }
    printf("%d é o mais frequente\n",r);
    return r;
}

//32
int maxCresc (const int v[], int N){
    int i=0, temp=1, cont=0;
    while(1) {
        while (i < N - 1 && *(v + i) <= *(v + i + 1)) {
            i++;
            temp++;
        }
        if (temp > cont) cont = temp;
        for (; i < N - 1 && *(v + i) > *(v + i + 1); i++);
        if (i == N - 1) break;
        temp = 1;
    }
    printf("a maior sequência tem comprimento %d\n",cont);
    return cont;
}

//33
int elimRep (int v[], int N){
    int i, aux, j, k;
    for(i=0; i<N; i++){
        aux=*(v+i);
        j=i+1;
        while(j<N)
            if (*(v+j)==aux){
                for (k=j; k<N-1; k++)
                    *(v+k) = *(v+k+1);
                N--;
            }
            else j++;
    }

    printf("[");
    for(j=0;j<N;j++) {
        printf("%d", *(v + j));
        if(j<N-1) printf(", ");
    }
    printf("], agora com %d elemento(s)\n",N);

    return N;
}

//34
int elimRepOrd (int v[], int N){
    int i, aux, j, k;
    for(i=0; i<N; i++){
        aux=*(v+i);
        j=i+1;
        while(j<N)
            if (*(v+j)==aux){
                for (k=j; k<N-1; k++)
                    *(v+k) = *(v+k+1);
                N--;
            }
            else break;
    }

    printf("[");
    for(j=0;j<N;j++) {
        printf("%d", *(v + j));
        if(j<N-1) printf(", ");
    }
    printf("], agora com %d elemento(s)\n",N);

    return N;
}

//35
int comunsOrd(const int a[], int na, const int b[], int nb){
    int ia=0, ib=0, cont=0;
    while(ia<na && ib<nb)
        if (*(a+ia)>*(b+ib)) ib++;
        else if (*(a+ia)<*(b+ib)) ia++;
        else {
            cont++;
            ia++;
            ib++;
        }

    printf("%d elementos em comum\n", cont);
    return cont;
}

//36
int comuns(const int a[], int na, const int b[], int nb){
    int ia, ib, cont=0, *baux, N=nb, i;
    baux = malloc(N*sizeof(int));

    for(ib=0;ib<N;ib++)
        *(baux+ib)=*(b+ib);

    for(ia=0;ia<na;ia++) {
        if (N==0) break;
        ib = 0;
        while (ib < N)
            if (*(a + ia) == *(baux + ib)) {
                cont++;
                for (i = ib; i < N - 1; i++)
                    *(baux + i) = *(baux + i + 1);
                N--;
                break;
            } else ib++;
    }
    free(baux);
    printf("%d elementos em comum\n", cont);
    return cont;
}

//37
int minInd (const int v[], int N){
    int i, temp=*v, I=0;
    I = (N>0) ? 0 : -1;

    for(i=1; i<N; i++){
        if(*(v+i)<temp){
            I=i;
            temp=*(v+i);
        }
    }
    printf("%d é o menor elemento (índice %d)\n",*(v+I),I);
    return I;
}

//38
void somasAc (const int v[], int Ac [], int N){
    int i;
    *Ac=*v;
    for(i=1;i<N;i++)
        *(Ac+i) = *(v+i) + *(Ac+i-1);

    printf("[");
    for(i=0;i<N;i++) {
        printf("%d", *(v + i));
        if(i<N-1) printf(", ");
    }
    printf("]\n");

    printf("[");
    for(i=0;i<N;i++) {
        printf("%d", *(Ac + i));
        if(i<N-1) printf(", ");
    }
    printf("]\n");
}

//39
int triSup (int N, float m[N][N]){
    int i, j;
    for (i = 1; i<N; i++)
        for (j = 0; j<N; j++)
            if (i > j)
                if (m[i][j] != 0){
                    printf("Não é triangular superior\n");
                    return 0;
                }
    printf("É triangular superior\n");
    return 1;
}

//40
void transposta (int N, float m [N][N]){
    int i, j;
    float temp;

    printf("m=\n");
    for(i=0;i<N;i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf("%f", m[i][j]);
            if (j < N - 1) printf(", ");
        }
        printf("]");
        printf("\n");
    }
    printf("\n");

    for (i = 0; i<N; i++)
        for (j = 0; j<i; j++){
                temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }

    printf("mT=\n");
    for(i=0;i<N;i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf("%f", m[i][j]);
            if (j < N - 1) printf(", ");
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

//41
void addTo (int N, int M, int a [N][M], int b[N][M]){
    int i, j;
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            a[i][j] += b[i][j];

    for(i=0;i<N;i++) {
        printf("[");
        for (j = 0; j < M; j++) {
            printf("%d", a[i][j]);
            if (j < M - 1) printf(", ");
        }
        printf("]");
        printf("\n");
    }
}

//42
int unionSet (int N, const int v1[N], const int v2[N], int r[N]){
    int i, acc=0;
    for (i=0; i<N; i++)
        if(v1[i] || v2[i]) {
            r[i] = 1;
            acc++;
        }

    printf("[");
    for(i=0;i<N;i++) {
            if (r[i]) {
                printf("%d", i);
                if (i < acc - 1) printf(", ");
            }
        }
    printf("]\n");

    return 0;
} 

//43
int intersectSet (int N, const int v1[N], const int v2[N], int r[N]){
    int i, acc=0;
    for (i=0; i<N; i++)
        if(v1[i] && v2[i]) {
            r[i] = 1;
            acc++;
        }

    printf("[");
    for(i=0;i<N;i++) {
        if (r[i]) {
            printf("%d", i);
            if (i < acc - 1) printf(", ");
        }
    }
    printf("]\n");

    return 0;
} 

//44
int intersectMSet (int N, const int v1[N], const int v2[N], int r[N]){
    int i, min, acc=0;
    for (i=0; i<N; i++){
        min = (*(v1+i) > *(v2+i)) ? *(v2+i) : *(v1+i);
        r[i] = min;
        acc+=min;
    }

    printf("[");
    for(i=0;i<N;i++) {
        for (int j= 0; j<r[i]; j++){
            printf("%d",i);
            if (1 < acc) printf(", ");
            acc--;
        }
    }
    printf("]\n");

    return 0;
} 

//45
 int unionMSet (int N, const int v1[N], const int v2[N], int r[N]){
    int i, max, acc=0;
    for (i=0; i<N; i++){
        max = (*(v1+i) < *(v2+i)) ? *(v2+i) : *(v1+i);
        r[i] = max;
        acc+=max;
    }

    printf("[");
    for(i=0;i<N;i++) {
        for (int j= 0; j<r[i]; j++){
            printf("%d",i);
            if (1 < acc) printf(", ");
            acc--;
        }
    }
    printf("]\n");

    return 0;
}

//46
int cardinalMSet (int N, const int v[N]){
    int i, c=0;
    for(i=0; i<N; i++)
        c += v[i];

    printf("%d elementos\n",c);
    return c;
}

// 47
Posicao posFinal (Posicao inicial, const Movimento mov[], int N){
    int i;
    printf("Posição inical: (%d,%d)\n",inicial.x,inicial.y);
    for(i=0; i<N; i++){
        switch(mov[i]){
            case Norte:
                inicial.y++;
                break;
            case Sul:
                inicial.y--;
                break;
            case Oeste:
                inicial.x--;
                break;
            case Este:
                inicial.x++;
                break;
        }
    }
    printf("Posição final: (%d,%d)\n",inicial.x,inicial.y);
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int x, y, i=0;
    x= final.x - inicial.x;
    y= final.y - inicial.y;
    while(y!=0 && i<N){
        if (y>0){
            mov[i] = Norte;
            y--;
        }
        else{
            mov[i] = Sul;
            y++;
        }
        i++;
    }
    while(x!=0 && i<N){
        if (x>0){
            mov[i] = Este;
            x--;
        }
        else{
            mov[i] = Oeste;
            x++;
        }
        i++;
    }
    i = (x!=0 || y!=0) ? -1 : i;
    if(i==-1)
        printf("O robot não consegue atingir a posição final!\n");
    else{
        printf("O robot faz os seguintes movimentos:\n");
        for(int l =0; l<i;l++)
            switch(mov[l]){
                case Norte:
                    printf("->Norte\n");
                    break;
                case Sul:
                    printf("->Sul\n");
                    break;
                case Oeste:
                    printf("->Oeste\n");
                    break;
                case Este:
                    printf("->Este\n");
                    break;
            }
    }
    return i;
}

//49
int maisCentral (Posicao pos[], int N){
    int i, ind=0;
    double dist, acc=0;
    for(i=0; i<N; i++)
        if (i==0){
            ind=0;
            acc = sqrt((pos[i].y)*(pos[i].y)+(pos[i].x)*(pos[i].x));
        }
        else{
            dist = sqrt((pos[i].y)*(pos[i].y)+(pos[i].x)*(pos[i].x));
            if (dist<acc){
                ind = i;
                acc = dist;
            }
        }
    if(N<=0) ind=-1;

    if (ind==-1)
        printf("Não há posições!\n");
    else
        printf("Posição mais próxima da origem: (%d,%d)\n", pos[ind].x, pos[ind].y);
    return ind;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N){
    int i, cont=0, xp, yp;

    printf("Vizinhos:\n");

    for(i=0; i<N; i++){
        xp = pos[i].x;
        yp = pos[i].y;
        if (abs(p.x-xp)<=1 && abs(p.y-yp)<=1 && p.x!=xp && p.y!=yp){
            cont++;
            printf("Nº%d: (%d,%d)\n",cont,xp,yp);
        }
    }

    if (!cont)
        printf("Não há vizinhos!\n");


    return cont;
}