# WestWorldWithMessaging

Travail effectué par Erwann Large (LARE02029506), Jean Milsonneau (MILJ13109509), Yannick Loussouarn (LOUY04019500).

## Travail réalisé :
  - Modification des machines à états
  - Ajout d'une IHM
  - Architecture multithread des agents

###  Modification des machines à états :

Nous avons modifié la SM de Bob en lui permettant d'aller au bar lorsqu'il a soif. Nous avons ajouté le personnage Jean (Drunkard) qui passe ses journées à boire/dormir/se battre.

Lorsque Jean et Bob se retrouve au bar et que Jean est ivre. Un combat se lance grâce à une communication par message.

### Ajout d'une IHM :

A l'aide de la lib SFML-2.3.2, nous avons généré une IHM qui permet de :

  - Play/Pause les machines à états au clic gauche sur le bouton
  - Changer d'états au clic gauche sur un état (à tout moment) /!\
  - L'Update de l'IHM est lancé dans un thread crée dans (GUI.h/cpp)
  - L'envoie de message est représenté par l'apparition d'une enveloppe.

### Architecture multithread des agents

Les agents ont maintenant leur propre thread lancé depuis le main.cpp L'écriture des messages dans la console est maintenant verrouillée par un mutex.

### Execution

L'executable WestWorldWithMessaging.exe se trouve dans le dossier executable, son execution ouvre un terminal et une fenetre graphique qui permet de visualiser et de modifier les états des machines à états.

### Compilation

Dans le dossier source se trouve toute les librairies utilisé avec les sources et le fichier WestWorldWithMessaging.sln pour visual studio 10.
