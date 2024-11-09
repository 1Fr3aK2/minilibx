/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_color_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:00:32 by rafael            #+#    #+#             */
/*   Updated: 2024/11/09 05:30:40 by rafael           ###   ########.fr       */
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

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    int     x, y;

    // Inicializa a conexão com a API MinilibX
    mlx = mlx_init();

    // Cria uma nova janela com tamanho 500x500
    mlx_win = mlx_new_window(mlx, LARGURA, ALTURA, "Quadrado");

    // Desenha um quadrado com 50x50 pixels
    for (y = 0; y < ALTURA; ++y)
    {
        for (x = 0; x < LARGURA; ++x)
        {
            // Desenha o quadrado na posição (x, y) com a cor RED
            mlx_pixel_put(mlx, mlx_win, x, y, 0x0AA00AA); // O quadrado será desenhado a partir de (200, 200)
        }
    }
    // Inicia o loop para manter a janela aberta
    mlx_loop(mlx);

    return 0;
}