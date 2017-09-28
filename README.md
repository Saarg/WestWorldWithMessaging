# WestWorldWithMessaging

//////////////////////////////////////////////////////////////////////////////
    Travail effectu� par Erwann Large, Jean Milsonneau, Yannick Loussouarn.
//////////////////////////////////////////////////////////////////////////////

Travail r�alis� :
  - Modification des machines � �tats
  - Ajout d'une IHM
  - Architecture multithread des agents
 
//////////////////////////////////////////////////////////////////////////////////////////////////
 
-> Modification des machines � �tats :


Nous avons modifi� la SM de Bob en lui permettant d'aller au bar lorsqu'il a soif.
Nous avons ajout� le personnage Jean (Drunkard) qui passe ses journ�es � boire/dormir/se battre.

Lorsque Jean et Bob se retrouve au bar et que Jean est ivre.
Un combat se lance gr�ce � une communication par message.

//////////////////////////////////////////////////////////////////////////////////////////////////

-> Ajout d'une IHM :

A l'aide de la lib SFML-2.3.2, nous avons g�n�r� une IHM qui permet de :
  - Play/Pause les machines � �tats au clic gauche sur le bouton
  - Changer d'�tats au clic gauche sur un �tat (� tout moment)      /!\
  - L'Update de l'IHM est lanc� dans un thread cr�e dans (GUI.h/cpp)
  - L'envoie de message est repr�sent� par l'apparition d'une enveloppe.

//////////////////////////////////////////////////////////////////////////////////////////////////
 
-> Architecture multithread des agents

Les agents ont maintenant leur propre thread lanc� depuis le main.cpp
L'�criture des messages dans la console est maintenant verrouill�e par un mutex.

//////////////////////////////////////////////////////////////////////////////////////////////////