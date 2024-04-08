#include <stdio.h>

// Fonction pour échanger deux entiers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    int *ptr_x = &x; // Pointeur vers x
    int *ptr_y = &y; // Pointeur vers y
    int **ptr_ptr_x = &ptr_x; // Pointeur de pointeur vers ptr_x

    printf("1 Valeur de x : %d\n", x); // Affiche la valeur de x
    printf("2 Adresse de x : %p\n", (void *)&x); // Affiche l'adresse de x
    printf("3 Valeur de y : %d\n", y); // Affiche la valeur de y
    printf("4 Adresse de y : %p\n", (void *)&y); // Affiche l'adresse de y
	printf("5 valeur de ptr_x : %p\n", ptr_x);
	printf("6 valeur de *ptr_x : %d\n", *ptr_x);
	printf("7 **ptr_ptr_x :%d\n", **ptr_ptr_x);
	printf("7 *ptr_ptr_x :%p\n", *ptr_ptr_x);
    // Utilisation de pointeurs pour échanger les valeurs de x et y
    swap(ptr_x, ptr_y);

    printf("\nAprès l'échange :\n");
    printf("7 Valeur de x : %d\n", x); // Affiche la nouvelle valeur de x après l'échange
    printf("8 Valeur de y : %d\n", y); // Affiche la nouvelle valeur de y après l'échange

    // Utilisation de pointeurs de pointeurs pour afficher l'adresse de x
    printf("\n9 Adresse de x via ptr_ptr_x : %p\n", (void *)ptr_x);
    printf("10 Adresse de x via &x : %p\n", (void *)&x);

    return 0;
}

