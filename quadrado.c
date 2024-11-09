/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrado.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:31:04 by rafael            #+#    #+#             */
/*   Updated: 2024/11/09 05:45:49 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

#define ALTURA 500
#define LARGURA 800
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF
#define BLACK 0x00000000

int main()
{
    int x;
    int y;
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, LARGURA, ALTURA, "QUADRADO");
    y = ALTURA * 0.1;
    while (y < ALTURA * 0.9)
    {
        x = LARGURA * 0.1;
        while (x < LARGURA * 0.9)
        {
            mlx_pixel_put(mlx, win, x, y, BLUE);
            x++;
        }
        y++;
    }
    mlx_loop(mlx);
}

/* int main()
{
    int x;
    int y;
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, LARGURA, ALTURA, "QUADRADO");  // Corrigido para LARGURA, ALTURA
    x = LARGURA * 0.1;  // Inicia em 10% da largura
    y = ALTURA * 0.1;   // Inicia em 10% da altura

    // Preenche um quadrado, indo até 90% da altura e largura
    while (y < ALTURA * 0.9)  // Começa de 10% até 90% da altura
    {
        x = LARGURA * 0.1;  // Reinicia x para 10% da largura a cada linha
        while (x < LARGURA * 0.9)  // Começa de 10% até 90% da largura
        {
            mlx_pixel_put(mlx, win, x, y, BLUE);  // Coloca o pixel na tela
            x++;  // Incrementa x para o próximo pixel
        }
        y++;  // Incrementa y para a próxima linha
    }

    mlx_loop(mlx);  // Inicia o loop de eventos da janela
} */