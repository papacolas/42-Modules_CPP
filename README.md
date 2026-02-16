# C++ Modules (42 Curriculum)

Ce dépôt regroupe l'ensemble de mes solutions pour le cursus C++ de l'école 42.  
Ce projet de longue haleine a pour but d'explorer en profondeur les mécanismes du **C++98**, de la gestion manuelle de la mémoire à la programmation générique avancée, en passant par une conception orientée objet rigoureuse.

## Objectifs & Compétences Acquises

La réalisation de ces 10 modules m'a permis de développer une expertise solide sur les fondamentaux du C++ et la conception logicielle :

*   **Programmation Orientée Objet (POO)** : Encapsulation, Héritage (simple, multiple, virtuel), et Polymorphisme (ad-hoc et sous-type).
*   **Gestion Mémoire Avancée** : Allocation manuelle (`new`/`delete`), compréhension profonde du *heap* vs *stack*, et prévention des fuites de mémoire (Memory Leaks).
*   **Conception Robuste** : Utilisation stricte de la **Forme Canonique Orthodoxe** (Coplien form) et gestion des exceptions pour garantir la stabilité du code.
*   **Programmation Générique** : Création de templates de fonctions et de classes pour un code réutilisable et type-safe.
*   **Standard Template Library (STL)** : Maîtrise des conteneurs (`vector`, `map`, `stack`, `deque`) et des algorithmes pour résoudre des problèmes complexes.
*   **Algorithmique** : Implémentation d'algorithmes de tri avancés (Ford-Johnson) et de structures de données.

---

## 📂 Détail des Modules

### [Module 00: Transition vers le C++](./cpp00)
*Introduction aux namespaces, classes, et flux d'entrée/sortie.*
*   **Challenge :** Quitter les habitudes du C pour adopter le paradigme objet.
*   **Réalisation :** Implémentation d'un annuaire téléphonique (`PhoneBook`) gérant l'interaction utilisateur et le formatage dynamique des données via `iostream` et `iomanip`.

### [Module 01: Allocation & Références](./cpp01)
*Gestion de la mémoire et manipulation des pointeurs.*
*   **Challenge :** Comprendre la différence fondamentale entre référence et pointeur, et gérer le cycle de vie des objets.
*   **Réalisation :**
    *   Conception d'une "Horde de Zombies" allouée dynamiquement.
    *   Implémentation d'un système de remplacement de texte (type `sed`) optimisé en C++.
    *   Utilisation de **pointeurs sur fonctions membres** pour éliminer les structures conditionnelles complexes (switch/if forest).

### [Module 02: Polymorphisme Ad-hoc](./cpp02)
*Surcharge d'opérateurs et Forme Canonique.*
*   **Challenge :** Représenter des nombres à virgule fixe (`Fixed Point`) sans utiliser les types flottants standards pour comprendre la représentation binaire.
*   **Réalisation :**
    *   Implémentation complète d'une classe `Fixed` respectant la **Forme Canonique Orthodoxe**.
    *   Surcharge de tous les opérateurs arithmétiques et de comparaison.
    *   Utilisation dans un algorithme de partitionnement spatial (BSP) pour tester l'inclusion d'un point dans un triangle.

### [Module 03: Héritage & Architecture](./cpp03)
*Héritage simple, multiple et virtuel.*
*   **Challenge :** Résoudre le **problème du diamant** lors d'un héritage multiple (Virtual Inheritance).
*   **Réalisation :** Création d'une hiérarchie de robots (`ClapTrap`, `ScavTrap`, `FragTrap`) aboutissant au `DiamondTrap`, nécessitant l'utilisation de l'héritage virtuel pour assurer l'unicité des attributs de la classe de base.

### [Module 04: Polymorphisme de Sous-type](./cpp04)
*Classes abstraites et Interfaces.*
*   **Challenge :** Garantir la **copie profonde** (Deep Copy) d'objets complexes contenant des pointeurs.
*   **Réalisation :**
    *   Architecture d'un système de RPG avec Interfaces (`IMateriaSource`, `ICharacter`).
    *   Gestion polymorphique des objets via des classes abstraites, permettant de manipuler des collections d'objets hétérogènes (`Animal*` pointant vers `Dog` ou `Cat`) sans fuite de mémoire.

### [Module 05: Exceptions & Robustesse](./cpp05)
*Gestion d'erreurs et blocs try/catch.*
*   **Challenge :** Rendre le code résilient aux erreurs d'exécution sans crash.
*   **Réalisation :** Simulation d'un système bureaucratique complexe où chaque action (signature de formulaire, avancement de grade) est sécurisée par des exceptions personnalisées héritant de `std::exception`.

### [Module 06: Conversion de Types (Casting)](./cpp06)
*Dangers et utilité des casts en C++.*
*   **Challenge :** Identifier et utiliser le bon type de cast pour chaque situation (`static`, `dynamic`, `reinterpret`, `const`).
*   **Réalisation :**
    *   Programme de conversion scalaire capable de détecter et traiter les pseudo-littéraux (`nan`, `inf`).
    *   Utilisation de `dynamic_cast` pour l'identification de type à l'exécution (RTTI).
    *   Manipulation de données brutes via la sérialisation (`reinterpret_cast`).

### [Module 07: Templates](./cpp07)
*Programmation générique.*
*   **Challenge :** Écrire des algorithmes agnostiques du type de donnée.
*   **Réalisation :**
    *   Implémentation d'une classe `Array<T>` générique gérant sa propre mémoire et les accès hors bornes.
    *   Création de fonctions utilitaires (`swap`, `min`, `max`, `iter`) fonctionnant sur tout type de donnée comparable.

### [Module 08: Conteneurs & Algorithmes STL](./cpp08)
*Introduction à la Standard Template Library.*
*   **Challenge :** Utiliser efficacement les conteneurs (`vector`, `list`, `deque`) et itérateurs standards.
*   **Réalisation :**
    *   `EasyFind` : Recherche générique dans n'importe quel conteneur séquentiel.
    *   `Span` : Classe calculant efficacement les écarts statistiques sur de grands jeux de données (10 000+ éléments) en utilisant `std::vector` et `std::sort`.

### [Module 09: STL Avancée](./cpp09)
*Résolution de problèmes algorithmiques complexes.*
*   **Challenge :** Interdiction d'utiliser autre chose que les conteneurs STL pour résoudre des problèmes spécifiques.
*   **Réalisation :**
    *   **PmergeMe** : Implémentation du complexe **algorithme de tri Ford-Johnson** (Merge-Insertion Sort) pour trier des séquences numériques, optimisé pour `std::vector` et `std::deque`. Comparaison précise des temps d'exécution.
    *   **RPN** : Création d'une calculatrice pour la Notation Polonaise Inverse utilisant `std::stack`.
    *   **Bitcoin Exchange** : Analyse de données financières historiques via `std::map` et recherche par borne inférieure (`lower_bound`).

---

## 🛠 Environnement Technique
*   **Langage :** C++98
*   **Compilateur :** c++ (clang++ / g++)
*   **Flags :** `-Wall -Wextra -Werror -std=c++98`
*   **OS :** Linux / Unix
