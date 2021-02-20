#ifndef PI_AUX_H
#define PI_AUX_H


int isVowel(char c);

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

#endif //PI_AUX_H
