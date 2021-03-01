#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "fifty.h"
#include "aux.h"

int main(int argc, char *argv[]){
    if (argc==1){
        printf("Nenhum argumento!\n");
        return 1;
    }
    char *func = argv[1];
	int i, f;
	f = atoi(func);
/*	const size_t N=strlen(func);
/*	for(i=0; i<N; i++) {
        f += (*(func + i) - 48) * (int) pow(10, (double) N - i - 1);
        if (*(func+i) < 48 || *(func+i) > 57){
            printf("Argumento inválido!\n");
            return 1;
        }
    } */

	int n, fator, *array, tam, x, tam1, *array1, tam2, *array2, *r, a, b, ll, cc;
    char *s1, *s2, c, *dest, *source;

	switch (f) {

        case 1: {
            maior();
            break;
        }

        case 2: {
            media();
            break;
        }

        case 3: {
            smaior();
            break;
        }

        case 4: {
            printf("Introduza um inteiro positivo: ");
            scanf("%d", &n);
            while (n < 0) {
                printf("Tente de novo: ");
                scanf("%d", &n);
            }
            bitsUm((unsigned int) n);
            break;
        }

        case 5: {
            printf("Introduza um inteiro positivo: ");
            scanf("%d", &n);
            while (n < 0) {
                printf("Tente de novo: ");
                scanf("%d", &n);
            }
            trailingZ((unsigned int) n);
            break;
        }

        case 6: {
            printf("Introduza um inteiro positivo: ");
            scanf("%d", &n);
            while (n < 0) {
                printf("Tente de novo: ");
                scanf("%d", &n);
            }
            qDig((unsigned int) n);
            break;
        }

	    case 7: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza outra string (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            mystrcat(s1, s2);
            free(s1);
            free(s2);
            break;
        }

	    case 8: {
            printf("Introduza uma string (50 char max): ");
            source = malloc(sizeof(char) * 50);
            scanf("%[^\n]", source);
            dest = malloc(sizeof(char) * 50);
            mystrcpy(dest, source);
            free(source);
            free(dest);
            break;
        }

        case 9: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza outra string (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            mystrcmp(s1, s2);
            free(s1);
            free(s2);
            break;
        }

        case 10: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza uma substring (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            mystrstr(s1, s2);
            free(s1);
            free(s2);
            break;
        }

        case 11: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            mystrrev(s1);
            free(s1);
            break;
        }

        case 12: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            mystrnoV(s1);
            free(s1);
            break;
        }

        case 13: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1); //para conseguir input de uma string com espaços
            printf("Introduza o fator de truncação: ");
            scanf("%d", &fator);
            truncW(s1, fator);
            free(s1);
            break;
        }

        case 14: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            charMaisfreq(s1);
            free(s1);
            break;
        }

        case 15: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1); //para conseguir input de uma string com espaços
            iguaisConsecutivos(s1);
            free(s1);
            break;
        }

        case 16: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            difConsecutivos(s1);
            free(s1);
            break;
        }

        case 17: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza outra string (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            maiorPrefixo(s1, s2);
            free(s1);
            free(s2);
            break;
        }

        case 18: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza outra string (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            maiorSufixo(s1, s2);
            free(s1);
            free(s2);
            break;
        }

        case 19: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza outra string (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            sufPref(s1, s2);
            free(s1);
            free(s2);
            break;
        }

        case 20: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            contaPal(s1);
            free(s1);
            break;
        }

        case 21: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            contaVogais(s1);
            free(s1);
            break;
        }

        case 22: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            printf("Introduza outra string (50 char max): ");
            scanf("%[\n]", &c);
            s2 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s2);
            contida(s1, s2);
            free(s1);
            free(s2);
            break;
        }

        case 23: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            palindorome(s1);
            free(s1);
            break;
        }

        case 24: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            remRep(s1);
            free(s1);
            break;
        }

        case 25: {
            printf("Introduza uma string (50 char max): ");
            s1 = malloc(sizeof(char) * 50);
            scanf("%[^\n]", s1);
            limpaEspacos(s1);
            free(s1);
            break;
        }

        case 26: {
            printf("Introduza o tamanho do array (10 max): ");
            scanf("%d", &tam);
            while (tam > 10) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * (tam + 1));
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            printf("Introduza o elemento a inserir no array: ");
            scanf("%d", &x);
            insere(array, tam, x);
            free(array);
            break;
        }

        case 27: {
            printf("Introduza o tamanho do 1º array (10 max): ");
            scanf("%d", &tam1);
            while (tam1 > 10) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Introduza o elemento %d do 1º array: ", ind);
                scanf("%d", array1 + ind);
            }
            printf("Introduza o tamanho do 2º array (10 max): ");
            scanf("%d", &tam2);
            while (tam2 > 10) {
                printf("Tente de novo: ");
                scanf("%d", &tam2);
            }
            array2 = malloc(sizeof(int) * tam2);
            for (int ind = 0; ind < tam2; ind++) {
                printf("Introduza o elemento %d do 2º array: ", ind);
                scanf("%d", array2 + ind);
            }
            r = malloc(sizeof(int) * (tam1 + tam2));
            merge(r, array1, array2, tam1, tam2);
            free(r);
            free(array1);
            free(array2);
            break;
        }

        case 28: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            printf("Introduza a posição inicial a procurar: ");
            scanf("%d", &a);
            printf("Introduza a posição final a procurar: ");
            scanf("%d", &b);
            crescente(array, a, b);
            free(array);
            break;
        }

        case 29: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            retiraNeg(array, tam);
            free(array);
            break;
        }

        case 30: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            menosFreq(array, tam);
            free(array);
            break;
        }

        case 31: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            maisFreq(array, tam);
            free(array);
            break;
        }

        case 32: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            maxCresc(array, tam);
            free(array);
            break;
        }

        case 33: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            elimRep(array, tam);
            free(array);
            break;
        }

        case 34: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            elimRepOrd(array, tam);
            free(array);
            break;
        }

        case 35: {
            printf("Introduza o tamanho do 1º array (15 max): ");
            scanf("%d", &tam1);
            while (tam1 > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Introduza o elemento %d do 1º array: ", ind);
                scanf("%d", array1 + ind);
            }
            printf("Introduza o tamanho do 2º array (15 max): ");
            scanf("%d", &tam2);
            while (tam2 > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam2);
            }
            array2 = malloc(sizeof(int) * tam2);
            for (int ind = 0; ind < tam2; ind++) {
                printf("Introduza o elemento %d do 2º array: ", ind);
                scanf("%d", array2 + ind);
            }
            comunsOrd(array1, tam1, array2, tam2);
            free(array1);
            free(array2);
            break;
        }

        case 36: {
            printf("Introduza o tamanho do 1º array (15 max): ");
            scanf("%d", &tam1);
            while (tam1 > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Introduza o elemento %d do 1º array: ", ind);
                scanf("%d", array1 + ind);
            }
            printf("Introduza o tamanho do 2º array (15 max): ");
            scanf("%d", &tam2);
            while (tam2 > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam2);
            }
            array2 = malloc(sizeof(int) * tam2);
            for (int ind = 0; ind < tam2; ind++) {
                printf("Introduza o elemento %d do 2º array: ", ind);
                scanf("%d", array2 + ind);
            }
            comuns(array1, tam1, array2, tam2);
            free(array1);
            free(array2);
            break;
        }

        case 37: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array + ind);
            }
            minInd(array, tam);
            free(array);
            break;
        }

        case 38: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            array1 = malloc(sizeof(int) * tam);
            for (int ind = 0; ind < tam; ind++) {
                printf("Introduza o elemento %d do array: ", ind);
                scanf("%d", array1 + ind);
            }
            array2 = malloc(sizeof(int) * tam);
            somasAc(array1, array2, tam);
            free(array1);
            free(array2);
            break;
        }

        case 39: {
            printf("Introduza o tamanho da matriz (7 max): ");
            scanf("%d", &tam);
            while (tam > 7) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }

            float matrix[tam][tam];
            for (int l = 0; l < tam; l++)
                for (int j = 0; j < tam; j++) {
                    printf("Introduza o elemento %d,%d da matriz: ", l, j);
                    scanf("%f", &(matrix[l][j]));
                }
            triSup(tam, matrix);
            break;
        }

        case 40: {
            printf("Introduza o tamanho da matriz (7 max): ");
            scanf("%d", &tam);
            while (tam > 7) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            float matrix[tam][tam];
            for (int l = 0; l < tam; l++)
                for (int j = 0; j < tam; j++) {
                    printf("Introduza o elemento %d,%d da matriz: ", l, j);
                    scanf("%f", &(matrix[l][j]));
                }
            transposta(tam, matrix);
            break;
        }

        case 41: {
            printf("Introduza o nº de linhas das matrizes (7 max): ");
            scanf("%d", &ll);
            while (ll > 7) {
                printf("Tente de novo: ");
                scanf("%d", &ll);
            }
            printf("Introduza o nº de colunas das matrizes (7 max): ");
            scanf("%d", &cc);
            while (cc > 7) {
                printf("Tente de novo: ");
                scanf("%d", &cc);
            }
            int ma[ll][cc], mb[ll][cc];
            for (int l = 0; l < ll; l++)
                for (int j = 0; j < cc; j++) {
                    printf("Introduza o elemento %d,%d da matriz a: ", l, j);
                    scanf("%d", &ma[l][j]);
                }
            for (int l = 0; l < ll; l++)
                for (int j = 0; j < cc; j++) {
                    printf("Introduza o elemento %d,%d da matriz b: ", l, j);
                    scanf("%d", &mb[l][j]);
                }
            addTo(ll,cc,ma,mb);
            break;
        }

        case 42: {
            printf("Introduza o tamanho dos arrays (20 max): ");
            scanf("%d", &tam1);
            while (tam1 > 20) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("%d pertence ao 1º array? ", ind);
                scanf("%d",&n);
                array1[ind] = n ? 1 : 0;
            }
            array2 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("%d pertence ao 2º array? ", ind);
                scanf("%d",&n);
                array2[ind] = n ? 1 : 0;
            }
            r = calloc(sizeof(int), tam1);
            unionSet(tam1, array1, array2, r);
            free(array1);
            free(array2);
            free(r);
            break;
        }

        case 43: {
            printf("Introduza o tamanho dos arrays (20 max): ");
            scanf("%d", &tam1);
            while (tam1 > 20) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("%d pertence ao 1º array? ", ind);
                scanf("%d",&n);
                array1[ind] = n ? 1 : 0;
            }
            array2 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("%d pertence ao 2º array? ", ind);
                scanf("%d",&n);
                array2[ind] = n ? 1 : 0;
            }
            r = calloc(sizeof(int), tam1);
            intersectSet(tam1, array1, array2, r);
            free(array1);
            free(array2);
            free(r);
            break;
        }

        case 44: {
            printf("Introduza o tamanho dos arrays (20 max): ");
            scanf("%d", &tam1);
            while (tam1 > 20) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Quantas ocorrênicas de %d no 1º array? ", ind);
                scanf("%d",&array1[ind]);
            }
            array2 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Quantas ocorrênicas de %d no 2º array? ", ind);
                scanf("%d",&array2[ind]);
            }
            r = calloc(sizeof(int), tam1);
            intersectMSet(tam1, array1, array2, r);
            free(array1);
            free(array2);
            free(r);
            break;
        }

        case 45: {
            printf("Introduza o tamanho dos arrays (20 max): ");
            scanf("%d", &tam1);
            while (tam1 > 20) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Quantas ocorrênicas de %d no 1º array? ", ind);
                scanf("%d",&array1[ind]);
            }
            array2 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Quantas ocorrênicas de %d no 2º array? ", ind);
                scanf("%d",&array2[ind]);
            }
            r = calloc(sizeof(int), tam1);
            unionMSet(tam1, array1, array2, r);
            free(array1);
            free(array2);
            free(r);
            break;
        }

        case 46: {
            printf("Introduza o tamanho do array (20 max): ");
            scanf("%d", &tam1);
            while (tam1 > 20) {
                printf("Tente de novo: ");
                scanf("%d", &tam1);
            }
            array1 = malloc(sizeof(int) * tam1);
            for (int ind = 0; ind < tam1; ind++) {
                printf("Quantas ocorrênicas de %d no array? ", ind);
                scanf("%d",&array1[ind]);
            }
            cardinalMSet(tam1, array1);
            free(array1);
            break;
        }

        case 47: {
            Posicao coord;
            printf("Introduza as coordenadas do robot (x,y): ");
            scanf("%d %d", &coord.x,&coord.y);
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            Movimento mov[tam];
            s1 = malloc(sizeof(char)*10);
            n=0;
            while (n < tam){
                printf("Introduza um Movimento: ");
                scanf("%s", s1);
                if(!strcmp(s1,"Norte")){ mov[n] = Norte; n++;}
                else if(!strcmp(s1,"Sul")){ mov[n] = Sul; n++;}
                else if(!strcmp(s1,"Este")){ mov[n] = Este; n++;}
                else if(!strcmp(s1,"Oeste")){ mov[n] = Oeste; n++;}
                else printf("Tente de novo\n");
                }
            posFinal(coord,mov,tam);
            free(s1);
            break;
        }

        case 48: {
            Posicao inicio, fim;
            printf("Introduza as coordenadas iniciais do robot (x,y): ");
            scanf("%d %d", &inicio.x,&inicio.y);
            printf("Introduza as coordenadas finais do robot (x,y): ");
            scanf("%d %d", &fim.x,&fim.y);
            printf("Introduza o número máximo de movimentos (20 max): ");
            scanf("%d", &n);
            while (n > 20) {
                printf("Tente de novo: ");
                scanf("%d", &n);
            }
            Movimento mov[n];
            caminho(inicio,fim,mov,n);
            break;
        }

        case 49: {
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            Posicao p[tam];
            for(int l=0; l<tam; l++) {
                printf("Introduza as coordenadas da posição %d (x,y): ", l);
                scanf("%d %d", &p[l].x, &p[l].y);
            }
            maisCentral(p,tam);
            break;
        }

        case 50: {
            Posicao p0;
            printf("Introduza as coordenadas da posição p0 (x,y): ");
            scanf("%d %d", &p0.x, &p0.y);
            printf("Introduza o tamanho do array (15 max): ");
            scanf("%d", &tam);
            while (tam > 15) {
                printf("Tente de novo: ");
                scanf("%d", &tam);
            }
            Posicao p[tam];
            for(int l=0; l<tam; l++) {
                printf("Introduza as coordenadas da posição %d (x,y): ", l);
                scanf("%d %d", &p[l].x, &p[l].y);
            }
            vizinhos(p0,p,tam);
            break;
        }

        default:
		    printf("Função não existe!\n");

	}
    return 0;
}

