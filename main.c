#include <ncurses.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HAUTEUR 100
#define LARGEUR 250

struct Figure
{
    int largeur;
    int hauteur;
    int *grille;
};

struct Regle
{
    int voisinMin;
    int voisinMax;
    int naissance;
};

int getCase(int *grille, int x, int y)
{
    return grille[y * LARGEUR + x];
}

void setCase(int *grille, int x, int y, int valeur)
{
    grille[y * LARGEUR + x] = valeur;
}

int compterVoisin(int *grille, int x, int y)
{
    int compteur = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int voisinX = x + i;
            int voisinY = y + j;
            if (voisinX >= 0 && voisinX < LARGEUR && voisinY >= 0 && voisinY < HAUTEUR && getCase(grille, voisinX, voisinY) != 0)
                compteur++;
        }
    }
    return compteur;
}

void updateGrilleVoisin(int *grille, int *grilleVoisin)
{
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            setCase(grilleVoisin, j, i, compterVoisin(grille, j, i));
        }
    }
}

void updateGrille(struct Regle regle, int *grille, int *grilleVoisin)
{
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            int voisin = getCase(grilleVoisin, j, i);
            if (getCase(grille, j, i) == 1)
            {
                if (voisin < regle.voisinMin) // meurt de solitude
                    setCase(grille, j, i, 0);
                else if (voisin <= regle.voisinMax) // continue à vivre
                    setCase(grille, j, i, 1);
                else // meurt de surpopulation
                    setCase(grille, j, i, 0);
            }
            else if (voisin == regle.naissance) // devient vivant
                setCase(grille, j, i, 1);
        }
    }
}

void dessinerSymbole(struct Figure symbole, int *grille, int x, int y)
{
    for (int i = 0; i < symbole.hauteur; i++)
    {
        for (int j = 0; j < symbole.largeur; j++)
        {
            setCase(grille, x + j, y + i, symbole.grille[i * symbole.largeur + j]);
        }
    }
}

void afficherGrille(int *grille)
{
    int x = 0, y = 0;
    for (int i = (int)HAUTEUR / 3; i < HAUTEUR - (int)HAUTEUR / 3; i++)
    {
        for (int j = (int)LARGEUR / 3; j < LARGEUR - (int)LARGEUR / 3; j++)
        {
            if (getCase(grille, j, i) > 0)
            {
                attron(COLOR_PAIR(2));
                mvprintw(y, x, "X");
                attroff(COLOR_PAIR(2));
            }
            else
            {
                attron(COLOR_PAIR(1));
                mvprintw(y, x, " ");
                attroff(COLOR_PAIR(1));
            }
            x += 2;
        }
        y++;
        x = 0;
    }
    refresh();
}

int main(int argc, char *argv[])
{
    float speed = 1;
    int autoplay = 1;
    if (argc > 1) speed = atof(argv[1]);
    if (argc > 2 ) autoplay = atoi(argv[2]);

    int *grille = calloc(HAUTEUR * LARGEUR, sizeof(int));
    int *grilleVoisin = calloc(HAUTEUR * LARGEUR, sizeof(int));

    // min max naissance
    struct Regle maze = {1, 5, 3};
    struct Regle conway = {2, 3, 3};
    struct Regle test = {2, 4, 2};

    int g[] = {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1};
    struct Figure laby = {5, 5, g};
    dessinerSymbole(laby, grille, (int)LARGEUR / 2 - 5, (int)HAUTEUR / 2 - 5);

    int g2[] = {
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1};
    struct Figure line = {10, 1, g2};
    dessinerSymbole(line, grille, (int)LARGEUR / 2 - 5, (int)HAUTEUR / 2 - 5);

    int run = 1;
    int play = 1;

    initscr();
    cbreak();
    noecho();
    start_color();
    nodelay(stdscr, autoplay);

    init_pair(1, COLOR_BLACK, COLOR_BLACK); 
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    while (run == 1)
    {
        int ch = getch();
        if (ch == ' ' && autoplay != 0) play = !play;
        else if (ch == 'q') run = 0;
        else if (ch == 'p') {
            autoplay = !autoplay;
            nodelay(stdscr, autoplay);
        }

        if (play)
        {
            afficherGrille(grille);
            updateGrilleVoisin(grille, grilleVoisin);
            updateGrille(maze, grille, grilleVoisin);
            if(autoplay != 0) usleep(1000 * 1000 * speed);
        }
    }

    free(grille);
    free(grilleVoisin);

    endwin();

    return 0;
}