#include <ncurses.h>

int main() {
    
    // Initialisation de NCurses
    initscr();
    cbreak();
    noecho();

    // Calcul de la position pour centrer le texte
    int y, x;
    getmaxyx(stdscr, y, x);


    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j+=2)
        {
            mvprintw(i, j, "X");
        }
        
    }
    

    // Mise à jour de l'affichage
    refresh();

    // Attente d'une entrée de l'utilisateur avant de quitter
    getch();

    // Fin de NCurses
    endwin();

    return 0;
}