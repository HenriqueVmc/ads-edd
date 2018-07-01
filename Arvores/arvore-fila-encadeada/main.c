#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{

    No* A = criar_arvore('A');
    No* B = criar_arvore('B');
    No* C = criar_arvore('C');
    No* D = criar_arvore('D');
    No* E = criar_arvore('E');
    No* F = criar_arvore('F');
    No* G = criar_arvore('G');
    No* H = criar_arvore('H');
    No* I = criar_arvore('I');
/*
.........................A....................
......................./...\..................
....................../.....\.................
...................../.......\................
..................../.........\...............
.................../...........\..............
................../.............\.............
................./...............\............
.................B................C...........
.............../..\............../..\.........
............../....\............/....\........
............./.....NULL......../......\.......
............/................./........\......
...........D..................E.........F.....
........../.\................/.\......./.\....
........./...\............../...\...../...\...
...... ./....NULL........../.....\..NULL.NULL.
......./................../.......\...........
......G..................H.........I..........
...../.\................/.\......./.\.........
..../...\............../...\...../...\........
..NULL.NULL..........NULL.NULL.NULL.NULL......
..............................................
..............................................
*/

    inserir(A, B, C);//B e C são filhos de A
    inserir(B, D, NULL);// D e NULL são filhos de 
    inserir(D, G, NULL);

    inserir(C, E, F);
    inserir(E, H, I);
  
    printf("\nPré-Ordem");
    imprimir_preordem(A);
    
    printf("\n\nSimétrica");
    imprimir_simetrica(A);
    
    printf("\n\nPós-Ordem");
    imprimir_posordem(A);
    
    printf("\n\nPor Largura");
    imprimir_largura(A);
    
    printf("\n\nPor Largura(Metodo com fila local)");
    imprimirLarguraComFilaLocal(A);
    
    return 0;
}