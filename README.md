# ProjetC++

## Description
Ce projet implémente une application de gestion bancaire simple en C++. Il permet de gérer des enregistrements bancaires (comptes) en offrant des fonctionnalités pour ajouter, afficher, modifier, supprimer et rechercher des enregistrements. Les données sont stockées dans un fichier texte, `bank_records.txt`.

### Fonctionnalités
- Ajouter un enregistrement bancaire
- Afficher tous les enregistrements bancaires
- Modifier un enregistrement bancaire
- Supprimer un enregistrement bancaire
- Rechercher un enregistrement bancaire par numéro de compte

## Prérequis
- C++20 ou supérieur
- CMake (version 3.29 ou plus récente)
- Un compilateur compatible C++20 (par exemple, GCC, Clang, ou MinGW sous Windows)

## Installation

### Étape 1 : 

###  Étape 2 : Configurer le projet avec CMake

Si vous utilisez un IDE comme CLion, vous pouvez directement ouvrir le projet. 
Sinon, vous pouvez configurer le projet à l'aide de CMake en ligne de commande :

```bash
mkdir build
cd build
cmake .. 
```

### Étape 3 : Compiler le projet

Après avoir configuré le projet avec CMake, compilez-le :
```bash
cmake --build .
```

### Étape 4 : Exécuter le programme

Une fois la compilation terminée, vous pouvez exécuter le programme :
```bash
./ProjetC__
```

### Structure du projet

```bash
ProjetC++
│
├── CMakeLists.txt       # Fichier de configuration CMake
├── header/              # Dossier contenant les fichiers d'en-tête
│   └── Bank.h           # Déclaration de la classe Bank
│   └── Account.h        # Déclaration de la classe Account
│
├── source/              # Dossier contenant les fichiers source
│   └── Bank.cpp         # Définition de la classe Bank
│   └── Account.cpp      # Définition de la classe Account
│
└── Menu.cpp             # Code principal de l'application
└── bank_records.txt     # Fichier de données (créé automatiquement si inexistant)

```

### Détails techniques
## Classe Bank

La classe Bank gère les opérations sur les enregistrements bancaires. Elle offre des méthodes pour :

    Charger les enregistrements depuis un fichier (loadRecords)
    Sauvegarder les enregistrements dans un fichier (saveRecords)
    Ajouter, afficher, modifier, supprimer et rechercher des enregistrements.

Les enregistrements sont stockés dans un vecteur de la classe Account.
## Classe Account

La classe Account représente un compte bancaire. Elle contient des informations comme le numéro de compte, le prénom, le nom, le numéro de téléphone et le solde. Elle offre des méthodes pour manipuler ces informations et pour convertir un compte en une chaîne de caractères et vice versa.
Fichier bank_records.txt

Les enregistrements bancaires sont stockés dans le fichier bank_records.txt. Si le fichier n'existe pas, il est créé automatiquement lors de l'exécution du programme.

### Auteurs
SATKUNARAJAH Sarusman, SASIKUMAR Sahkana & SOLANKI Priyank