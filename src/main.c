#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
    void *mlx;
    void *win;
} t_data;

int	close_window(t_data *dati)
{
    if (dati->mlx && dati->win)
    {
    printf("Closing window..\n");
	mlx_destroy_window(dati->mlx, dati->win);
    mlx_destroy_display(dati->mlx);
    //dati->win = NULL;
    free(dati->mlx);
    //free(win);
	// Puoi anche chiamare free(mlx) se necessario
    }
    //exit(0);
     printf("Stopping mlx loop...\n");
    //mlx_loop_end(mlx);// Esce dal loop senza terminare brutalmente
	exit(EXIT_SUCCESS);
}

int main()
{
    t_data dati;

    // Inizializza MiniLibX
    dati.mlx = mlx_init();
    if (!dati.mlx)
        return (1);

    // Crea una finestra di 800x600 pixel
    dati.win = mlx_new_window(dati.mlx, 800, 600, "So Long");
    if (!dati.win)
        return (1);

      // Registra l'evento per chiudere la finestra premendo la "X"
      // 17 è il valore corrispondente all'evento DestroyNotify, che viene inviato quando l'utente clicca sulla "X" della finestra, 0 è la mask associata, che in questo caso non è necessaria per DestroyNotify.
    mlx_hook(dati.win, 17, 0, close_window, &dati); 
        // Avvia il loop della finestra (necessario per mantenere la finestra aperta)
    mlx_loop(dati.mlx);
    
    return (0);
}
