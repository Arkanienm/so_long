# So Long 🐬 - 42 Project

![So Long Banner](https://img.shields.io/badge/42-So_Long-blue)
![Score](https://img.shields.io/badge/Score-125%2F100-success)
![Language](https://img.shields.io/badge/Language-C-orange)

**So Long** est un petit jeu vidéo en 2D vue de dessus, développé en C à l'aide de la bibliothèque graphique **MiniLibX**. Le but est de contrôler un personnage, ramasser tous les objets collectables et s'échapper par la sortie en évitant les ennemis, le tout avec le moins de mouvements possible.

Ce projet se concentre sur la gestion des fenêtres, des événements (clavier/souris), le chargement de textures et l'algorithme de vérification de chemin (Flood Fill).

---

## 🎮 Fonctionnalités

### Partie Obligatoire (Mandatory)
* **Moteur Graphique** : Utilisation de la MiniLibX pour le rendu.
* **Parsing de Carte** : Lecture de fichiers `.ber` avec vérifications strictes (mur fermé, rectangle, charactères valides).
* **Pathfinding** : Vérification de la validité de la carte via un algorithme de **Flood Fill** (garantit que le joueur peut atteindre tous les items et la sortie).
* **Gameplay** : Déplacements fluides (WASD), collision avec les murs.

### Partie Bonus (Features Supplémentaires) 🌟
Le jeu inclut toutes les fonctionnalités bonus demandées :
* **HUD à l'écran** : Le compteur de mouvements est affiché directement dans la fenêtre (plus propre que dans le terminal).
* **Ennemis (Patrouilles)** : Ajout de l'entité `N` (Nasty). Toucher un ennemi provoque un **GAME OVER** immédiat.
* **Animation des Sprites** : Les objets collectables (pièces/clés) sont animés (boucle d'animation fluide).
* **Direction du Joueur** : Le sprite du personnage change selon la direction du mouvement (Haut, Bas, Gauche, Droite).

---

## 🛠️ Installation et Lancement

### Prérequis (Linux)
Ce projet utilise la MiniLibX pour Linux. Assurez-vous d'avoir les dépendances nécessaires :
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
### Compilation
Clonez le dépôt et compilez le jeu :

* **Pour la version standard :**
```bash
make
```
* **Pour la version complète (Avec Bonus) :**
```bash
make bonus
```
---

## 🎮 Exécution

* **Lancez le jeu en fournissant une carte en argument :**
```bash
./so_long_bonus maps/map1.ber
```
### **Touche,Action**
* W / ⬆️,Déplacer vers le Haut
* A / ⬅️,Déplacer vers la Gauche
* S / ⬇️,Déplacer vers le Bas
* D / ➡️,Déplacer vers la Droite
* ESC,Quitter le jeu
* Croix Rouge,Quitter le jeu

---

## **🗺️ Format de la car(.ber)t :**

### **Le jeu accepte des cartes au format .ber. Elles doivent être rectangulaires et entourées de murs.**

## **Légende :**

* 0 : Sol (Vide)

* 1 : Mur

* C : Collectable (Doit tous être ramassés)

* E : Sortie (S'ouvre quand tout est ramassé)

* P : Position de départ du Joueur

* N : Ennemi (Bonus uniquement - Game Over au contact)

Exemple de carte valide :
```plaintext
1111111111111
10010000000C1
10000N1111001
1P0011E000001
1111111111111
```
---
## 📸 Aperçu

![Aperçu du jeu]()
---

## Algorthme de Validation (Flood Fill)**
### **Avant de lancer le jeu, le programme vérifie si la carte est "finissable".**
* Il crée une copie de la carte en mémoire.
* Il inonde la carte depuis la position du joueur (P).
* Il vérifie si l'inondation a touché tous les collectibles (C) et la sortie (E).
* Si un élément reste inaccessible, le jeu refuse de se lancer et affiche Error.

---
## Développé par [Anojx] - 42 Angoulême
