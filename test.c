#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialisation de la graine pour la génération de nombres aléatoires
    srand(time(NULL));

    // Génération d'un nombre aléatoire entre 0 et RAND_MAX
    int random_number = rand();

    printf("RAND_MAX: %d\n", RAND_MAX);
    printf("Random number between 0 and RAND_MAX: %d\n", random_number);

    return 0;
}