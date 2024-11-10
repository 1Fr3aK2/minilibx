#include "minilibx-linux/mlx.h"
#include <stdlib.h>

#define ALTURA 500
#define LARGURA 800
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF
#define BLACK 0x00000000

void draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int color)
{
    int dx = (x2 - x1);
    if (dx < 0)
        dx = -dx;
    int dy = (y2 - y1);  
    if (dy < 0)
        dy = -dy;
    int sx, sy;
    if (x1 < x2)
        sx = 1;
    else 
        sx = -1;

    if (y1 < y2) 
        sy = 1;
    else 
        sy = -1;
    int err = dx - dy;
 
    while (1) 
    {
        mlx_pixel_put(mlx, win, x1, y1, color);
        if (x1 == x2 && y1 == y2) 
            break;
        int e2 = err * 2;
        if (e2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) 
        {
            err += dx;
            y1 += sy;
        }
    }
}

void fill_triangle(void *mlx, void *win, int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    int startY = y1;
    if (y2 < startY)
        startY = y2;
    if (y3 < startY)
        startY = y3;

    int endY = y1;
    if (y2 > endY)
        endY = y2;
    if (y3 > endY)
        endY = y3;

    for (int y = startY; y <= endY; y++)
    {
        int minX = LARGURA;
        int maxX = 0;

        if (y >= y1 && y <= y2 && (y2 - y1) != 0) {
            int edgeX = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
            if (edgeX < minX)
                minX = edgeX;
            if (edgeX > maxX)
                maxX = edgeX;
        }
        
        if (y >= y1 && y <= y3 && (y3 - y1) != 0) {
            int edgeX = x1 + (x3 - x1) * (y - y1) / (y3 - y1);
            if (edgeX < minX)
                minX = edgeX;
            if (edgeX > maxX)
                maxX = edgeX;
        }
        
        if (y >= y2 && y <= y3 && (y3 - y2) != 0) {
            int edgeX = x2 + (x3 - x2) * (y - y2) / (y3 - y2);
            if (edgeX < minX)
                minX = edgeX;
            if (edgeX > maxX)
                maxX = edgeX;
        }

        for (int x = minX; x <= maxX; x++) {
            mlx_pixel_put(mlx, win, x, y, color);
        }
    }
}

int main()
{
    void *win;
    void *mlx;

    mlx = mlx_init();
    win = mlx_new_window(mlx, LARGURA, ALTURA, "Triângulo");
    
    int x1 = LARGURA / 2,  y1 = 100;
    int x2 = LARGURA / 4, y2 = ALTURA - 100;
    int x3 = 3 * LARGURA / 4, y3 = ALTURA - 100;

    draw_line(mlx, win, x1, y1, x2, y2, BLUE);
    draw_line(mlx, win, x2, y2, x3, y3, BLUE);
    draw_line(mlx, win, x3, y3, x1, y1, BLUE);
    fill_triangle(mlx, win, x1, y1, x2, y2, x3, y3, GREEN);
    
    mlx_loop(mlx);
}

/* x1->ponto medio, y1-> distancia(pixeis) a partir do topo da janela -> ponto superior central
x2-> vertice inf esquerdo(), y2-> distancia da base(altura = 500)->ponto inferior esquerdo 
x3->                    ->ponto inferior direito */


O valor de x3 é calculado como 3 * LARGURA / 4, ou seja, três quartos da largura total da janela. Esse valor coloca x3 à direita de x2, criando um triângulo isósceles.

y3 é definido como ALTURA - 100, colocando y3 à mesma altura que y2 na base inferior do triângulo.