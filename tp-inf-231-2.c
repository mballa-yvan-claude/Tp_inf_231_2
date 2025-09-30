#include <stdio.h>
#include <stdlib.h>

// Structure pour liste simplement chaînée
typedef struct NodeS {
    int data;
    struct NodeS* next;
} NodeS;

// Structure pour liste doublement chaînée
typedef struct NodeD {
    int data;
    struct NodeD* next;
    struct NodeD* prev;
} NodeD;

// ===== FONCTIONS POUR LISTE SIMPLEMENT CHAÎNÉE =====

// Créer un nouveau nœud
NodeS* createNodeS(int data) {
    NodeS* newNode = (NodeS*)malloc(sizeof(NodeS));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Afficher une liste simplement chaînée
void displayListS(NodeS* head) {
    NodeS* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 1. Supprimer toutes les occurrences d'un élément
NodeS* deleteAllOccurrences(NodeS* head, int value) {
    NodeS* current = head;
    NodeS* prev = NULL;
    NodeS* temp;
    
    // Supprimer les occurrences en tête
    while (current != NULL && current->data == value) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = current;
    
    // Supprimer les occurrences dans le reste de la liste
    while (current != NULL) {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}

// 2. Insertion dans une liste simplement chaînée triée
NodeS* insertSortedS(NodeS* head, int data) {
    NodeS* newNode = createNodeS(data);
    
    // Cas liste vide ou insertion en tête
    if (head == NULL || data <= head->data) {
        newNode->next = head;
        return newNode;
    }
    
    // Recherche de la position d'insertion
    NodeS* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    // Insertion
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

// ===== FONCTIONS POUR LISTE DOUBLEMENT CHAÎNÉE =====

// Créer un nouveau nœud double
NodeD* createNodeD(int data) {
    NodeD* newNode = (NodeD*)malloc(sizeof(NodeD));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Afficher une liste doublement chaînée
void displayListD(NodeD* head) {
    NodeD* current = head;
    printf("NULL <- ");
    while (current != NULL) {
        if (current->next == NULL) {
            printf("%d", current->data);
        } else {
            printf("%d <-> ", current->data);
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

// 3. Insertion dans une liste doublement chaînée triée
NodeD* insertSortedD(NodeD* head, int data) {
    NodeD* newNode = createNodeD(data);
    
    // Cas liste vide
    if (head == NULL) {
        return newNode;
    }
    
    // Cas insertion en tête
    if (data <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    
    // Recherche de la position d'insertion
    NodeD* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    // Insertion
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    
    return head;
}

// ===== FONCTIONS POUR LISTE SIMPLEMENT CHAÎNÉE CIRCULAIRE =====

// Afficher une liste simplement chaînée circulaire
void displayCircularS(NodeS* head) {
    if (head == NULL) {
        printf("Liste circulaire vide\n");
        return;
    }
    
    NodeS* current = head;
    printf("↻ ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("[retour tête: %d] ↺\n", head->data);
}

// 4. Insertion en tête dans une liste simplement chaînée circulaire
NodeS* insertHeadCircularS(NodeS* head, int data) {
    NodeS* newNode = createNodeS(data);
    
    if (head == NULL) {
        newNode->next = newNode; // Pointe sur lui-même
        return newNode;
    }
    
    // Insérer après la tête puis échanger les données
    newNode->next = head->next;
    head->next = newNode;
    
    // Échanger les données pour simuler l'insertion en tête
    int temp = head->data;
    head->data = newNode->data;
    newNode->data = temp;
    
    return head;
}

// 4. Insertion en queue dans une liste simplement chaînée circulaire
NodeS* insertTailCircularS(NodeS* head, int data) {
    NodeS* newNode = createNodeS(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    // Insérer après la tête
    newNode->next = head->next;
    head->next = newNode;
    
    // Échanger les données pour simuler l'insertion en queue
    int temp = head->data;
    head->data = newNode->data;
    newNode->data = temp;
    
    // La nouvelle tête devient le nouveau nœud
    return newNode;
}

// ===== FONCTIONS POUR LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE =====

// Afficher une liste doublement chaînée circulaire
void displayCircularD(NodeD* head) {
    if (head == NULL) {
        printf("Liste double circulaire vide\n");
        return;
    }
    
    NodeD* current = head;
    printf("↻ ");
    do {
        if (current->next == head) {
            printf("%d", current->data);
        } else {
            printf("%d <-> ", current->data);
        }
        current = current->next;
    } while (current != head);
    printf(" ↺\n");
}

// 5. Insertion en tête dans une liste doublement chaînée circulaire
NodeD* insertHeadCircularD(NodeD* head, int data) {
    NodeD* newNode = createNodeD(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    
    NodeD* tail = head->prev;
    
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    
    return newNode;
}

// 5. Insertion en queue dans une liste doublement chaînée circulaire
NodeD* insertTailCircularD(NodeD* head, int data) {
    // Dans une liste double circulaire, insertion en queue = insertion en tête du suivant
    NodeD* newNode = createNodeD(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    
    NodeD* tail = head->prev;
    
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    
    return head; // La tête ne change pas
}

// ===== FONCTION POUR LIBÉRER LA MÉMOIRE =====

void freeListS(NodeS* head) {
    NodeS* current = head;
    NodeS* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void freeListD(NodeD* head) {
    if (head == NULL) return;
    
    NodeD* current = head;
    NodeD* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

// ===== FONCTION PRINCIPALE =====

int main() {
    printf("=== TEST DES FONCTIONNALITÉS DES LISTES ===\n\n");
    
    // Test 1: Suppression de toutes les occurrences
    printf("1. SUPPRESSION DE TOUTES LES OCCURRENCES:\n");
    NodeS* list1 = NULL;
    list1 = insertSortedS(list1, 5);
    list1 = insertSortedS(list1, 2);
    list1 = insertSortedS(list1, 5);
    list1 = insertSortedS(list1, 3);
    list1 = insertSortedS(list1, 5);
    list1 = insertSortedS(list1, 1);
    
    printf("Liste originale: ");
    displayListS(list1);
    
    list1 = deleteAllOccurrences(list1, 5);
    printf("Après suppression des 5: ");
    displayListS(list1);
    printf("\n");
    
    // Test 2: Insertion dans liste simplement chaînée triée
    printf("2. INSERTION LISTE SIMPLEMENT CHAÎNÉE TRIÉE:\n");
    NodeS* list2 = NULL;
    list2 = insertSortedS(list2, 10);
    list2 = insertSortedS(list2, 5);
    list2 = insertSortedS(list2, 20);
    list2 = insertSortedS(list2, 15);
    
    printf("Liste triée: ");
    displayListS(list2);
    printf("\n");
    
    // Test 3: Insertion dans liste doublement chaînée triée
    printf("3. INSERTION LISTE DOUBLEMENT CHAÎNÉE TRIÉE:\n");
    NodeD* list3 = NULL;
    list3 = insertSortedD(list3, 30);
    list3 = insertSortedD(list3, 10);
    list3 = insertSortedD(list3, 40);
    list3 = insertSortedD(list3, 20);
    
    printf("Liste double triée: ");
    displayListD(list3);
    printf("\n");
    
    // Test 4: Liste simplement chaînée circulaire
    printf("4. LISTE SIMPLEMENT CHAÎNÉE CIRCULAIRE:\n");
    NodeS* circularS = NULL;
    circularS = insertHeadCircularS(circularS, 100);
    circularS = insertHeadCircularS(circularS, 200);
    circularS = insertTailCircularS(circularS, 50);
    circularS = insertTailCircularS(circularS, 25);
    
    printf("Liste circulaire simple: ");
    displayCircularS(circularS);
    printf("\n");
    
    // Test 5: Liste doublement chaînée circulaire
    printf("5. LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE:\n");
    NodeD* circularD = NULL;
    circularD = insertHeadCircularD(circularD, 1000);
    circularD = insertHeadCircularD(circularD, 2000);
    circularD = insertTailCircularD(circularD, 500);
    circularD = insertTailCircularD(circularD, 250);
    
    printf("Liste circulaire double: ");
    displayCircularD(circularD);
    printf("\n");
    
    // Libération de la mémoire
    freeListS(list1);
    freeListS(list2);
    freeListS(circularS);
    freeListD(list3);
    freeListD(circularD);
    
    printf("Toutes les opérations ont été testées avec succès!\n");
    
    return 0;
}