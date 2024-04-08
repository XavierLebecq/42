#include <stdio.h>
#include <stdlib.h>

// Structure d'un élément de liste
typedef struct s_node {
    int data;           // Donnée de l'élément
    struct s_node *next;  // Pointeur vers le prochain élément
} t_node;

// Fonction pour ajouter un élément à la fin de la liste
void ft_lstaddback(t_node **head, int data) {
    // Allouer de la mémoire pour le nouvel élément
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Remplir les champs de l'élément avec les données fournies
    new_node->data = data;
    new_node->next = NULL;  // Le prochain élément est NULL car il sera ajouté à la fin

    // Si la liste est vide, le nouvel élément devient la tête de la liste
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Sinon, trouver le dernier élément de la liste
    t_node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Ajouter le nouvel élément à la fin de la liste
    last->next = new_node;
}

// Fonction pour afficher les éléments de la liste
void printList(t_node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialisation de la liste
    t_node *head = NULL;

    // Ajout de quelques éléments à la liste
    ft_lstaddback(&head, 10);
    ft_lstaddback(&head, 20);
    ft_lstaddback(&head, 30);

    // Affichage de la liste
    printf("Liste après l'ajout d'éléments : ");
    printList(head);

    return 0;
}

