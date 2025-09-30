# Tp_inf_231_2
Ceci est le deuxième tp de l'UE inf231
# Gestion des Listes Chaînées en C

Ce projet implémente différentes opérations sur les **listes chaînées** en langage C.  
Il couvre plusieurs variantes : liste simplement chaînée, liste doublement chaînée, et leurs versions circulaires.  


## Fonctionnalités

### 1. Suppression de toutes les occurrences d’un élément dans une liste simplement chaînée
- Lecture d’un élément donné.
- Suppression **de toutes ses occurrences** dans la liste.
- Maintien de l’intégrité des pointeurs après suppression.

### 2. Insertion dans une liste simplement chaînée triée
- Insertion d’un nouvel élément tout en maintenant l’ordre croissant.
- Cas gérés :
  - Liste vide.
  - Insertion en tête.
  - Insertion au milieu ou en queue.

### 3. Insertion dans une liste doublement chaînée triée
- Insertion dans une **liste doublement chaînée triée**.
- Gestion des pointeurs `next` et `prev`.
- Conservation de l’ordre croissant des éléments.

### 4. Insertion dans une liste simplement chaînée circulaire
- **Insertion en tête** : ajout d’un élément au début.
- **Insertion en queue** : ajout d’un élément à la fin.
- Utilisation de techniques d’échange de valeurs pour gérer la circularité.

### 5. Insertion dans une liste doublement chaînée circulaire
- **Insertion en tête** : ajout d’un élément avant le premier.
- **Insertion en queue** : ajout d’un élément après le dernier.
- Gestion complète des pointeurs circulaires `next` et `prev`.


## Compilation et Exécution

### Compilation
Utilisez `gcc` pour compiler :
```bash
gcc listes.c -o listes

Exécution

./listes


Exemple d’Exécution

=== TEST DES FONCTIONNALITÉS DES LISTES ===

1. SUPPRESSION DE TOUTES LES OCCURRENCES:
Liste originale: 1 -> 2 -> 3 -> 5 -> 5 -> 5 -> NULL
Après suppression des 5: 1 -> 2 -> 3 -> NULL

2. INSERTION LISTE SIMPLEMENT CHAÎNÉE TRIÉE:
Liste triée: 5 -> 10 -> 15 -> 20 -> NULL

3. INSERTION LISTE DOUBLEMENT CHAÎNÉE TRIÉE:
Liste double triée: NULL <- 10 <-> 20 <-> 30 <-> 40 -> NULL

4. LISTE SIMPLEMENT CHAÎNÉE CIRCULAIRE:
↻ 200 -> 100 -> 25 -> 50 -> [retour tête: 200] ↺

5. LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE:
↻ 2000 <-> 1000 <-> 500 <-> 250 ↺

Toutes les opérations ont été testées avec succès!

 Structure du Code

Structures principales :

NodeS → nœud pour liste simplement chaînée.

NodeD → nœud pour liste doublement chaînée.


Fonctions principales :

deleteAllOccurrences() : suppression des occurrences.

insertSortedS() : insertion triée simple.

insertSortedD() : insertion triée double.

insertHeadCircularS() et insertTailCircularS() : insertion circulaire simple.

insertHeadCircularD() et insertTailCircularD() : insertion circulaire double.

Fonctions display* pour afficher les listes.

Fonctions freeList* pour libérer la mémoire.


Gestion d’insertion par position.

Création d’un menu interactif pour tester toutes les fonctionnalités en mode utilisateur.
