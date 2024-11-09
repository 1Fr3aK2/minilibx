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
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);  
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
 
    while (1) {
        mlx_pixel_put(mlx, win, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
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
    int x3 = LARGURA / 4, y3 = ALTURA - 100;
    draw_line(mlx, win, x1, y1, x2, y2, BLUE);
    draw_line(mlx, win, x2, y2, x3, y3, BLUE);
    draw_line(mlx, win, x3, y3, x1, y1, BLUE);
    mlx_loop(mlx);
}