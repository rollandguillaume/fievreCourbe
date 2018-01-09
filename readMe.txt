# fievreCourbe

# Installation du projet

Plateforme : QtCreator
  -> Open Project
  -> choisir le fichier fievrecourbe.pro
  
# Pour lancer le projet
  -> utiliser le bouton run (fleche verte en bas à gauche de QtCreator)
  
# Architecture

- main              lancement de l'application
- config            configuration du jeu

- mainwindow        classe concernant la fenetre du jeu
- gamewindow        classe concernant le terrain de jeu
- startwindow       classe concernant l'affichage du récapitulatif de la liste des joueurs
- scoreboard        classe concernant l'affichage des resultats des joueurs

- dialog_help       pop-up d'aide affichant le manuel d'utilisation du jeu
- dialog_key        pop-up pour entrer une touche d'un joueur

- snake             classe represantant un joueur
- corpssnake        classe composant le corp d'un joueur
- wall              classe representant les bordures du terrain de jeu

- bonus             super classe des bonus
- bonus_closepath   classe du bonus supprimant les trace de tous les serpents
- bonus_ghost       classe du bonus permettant au serpent d'être invinsible pour un temps
- bonus_reverse     classe du bonus permettant d'inverser les touches des joueurs
