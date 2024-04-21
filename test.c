#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    int ch;
    MEVENT event;
    while (1 == 1) {
        ch = getch();
        
        if (ch == KEY_MOUSE && getmouse(&event) == OK) {
            if (event.bstate & BUTTON1_CLICKED) {
                clear();  // Effacer l'écran avant d'imprimer
                mvprintw(0, 0, "Clic détecté aux coordonnées : %d, %d", event.y, event.x);
                refresh();
            }
        }
    }

    endwin();
    return 0;
}
