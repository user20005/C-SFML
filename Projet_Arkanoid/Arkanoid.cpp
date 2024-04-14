#include <SFML/Graphics.hpp>
#include <conio.h>
#include <time.h>
//#include "Mur_1.hpp"

using namespace sf;

bool isCollide(Sprite s1, Sprite s2)
{
    return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

int main()
{
    srand(time(0));
    RenderWindow app(VideoMode(1000,600), "Jeux Arkanoid !"); /* dimensions et nom de la fenêtre du jeu */
    app.setFramerateLimit(60);

    /* déclaration des variables qui prendront comme texture l'une des images souhaitée pour le jeu ; ces images sont enregistrées dans
    /* 2 répertoires différents.
    /* ces 2 répertoires sont :
    /*  -le répertoire nommé "images" rangé dans le répertoire où est situé le .cbp (pour faire tourner le jeu à partir de CodeBlock)
    /*  -le répertoire bin où figure le .exe (pour faire tourner le jeu à partir de n'importe quel poste) */

    Texture Brique_bleue, Brique_grise, Brique_jaune, Brique_orange, Brique_rouge, Brique_turquoise, Brique_verte, Brique_violette, Fond, Bille, Paddle;
    /* Texture est un type définit dans la bibliothèque SFML */

    Brique_bleue.loadFromFile("images/Brique-bleue.png"); /* la variable Brique_bleue, de type Texture, elle est composée d'un champ */
                                                          /* 'loadFromFile ayant comme paramètre le chemin de l'image à utiliser     */
                                                          /* en tant que texture ; ce chemin est relatif                             */
    Brique_grise.loadFromFile("images/Brique-grise.png");
    Brique_jaune.loadFromFile("images/Brique-jaune.png");
    Brique_orange.loadFromFile("images/Brique-orange.png");
    Brique_rouge.loadFromFile("images/Brique-rouge.png");
    Brique_turquoise.loadFromFile("images/Brique-turquoise.png");
    Brique_verte.loadFromFile("images/Brique-verte.png");
    Brique_violette.loadFromFile("images/Brique-violette.png");

    Bille.loadFromFile("images/Ball-rouge2-redim.png");

    Fond.loadFromFile("images/Fond_neige2.jpg");

    Paddle.loadFromFile("images/Paddle_redim.png");

    Sprite sBackground(Fond), sBall(Bille), sPaddle(Paddle); /* Sprite est un type définit dans la bibliothèque SFML : */
                                                             /* c'est un rectangle texturé                             */
    sPaddle.setPosition(400,550); /* initialise la position du curseur dans la fenêtre de jeu aux coordonnées précisées*/
                                  /*(x=400 et y = 550 ici) */
    sBall.setPosition(420,540);

    /* Début du dessin d'un mur de brique */
    Sprite block[350]; /* déclaration d'un tableau de 500 'Sprite' : ici 500 rectangles texturés (remplis donc avec les images */
                       /* des briques colorées) qui vont constituer le mur de briques à détruire */

    bool occupation[23][15]; /* tableau de booléens (rempli de 'vrai' ou 'faux' donc) :                        */
                             /* -vrai si une brique colorée occupe la position actuelle dans la fenêtre du jeu */
                             /* -faux  si aucune brique colorée n'occupe cette position dans la fenêtre du jeu */

    int n=0, colonne=0, ligne=0, position_colonne=0, position_ligne=0;

//
//    /* initialisation de l'état d'occupation des briques */
//    for (position_ligne=1;position_ligne<=14;position_ligne++)
//    {
//        for (position_colonne=1;position_colonne<=22;position_colonne++)
//        {
//            occupation[position_colonne][position_ligne]=false;
//        }
//    }
//
    /* dessin du S de S.N. */
    /* dessin de 5 briques horizontales vertes sur 2 lignes à partir de la ligne 3 et de la colonne 3 */
    position_ligne=3;
    position_colonne=3;
    ligne=position_ligne;
    while (ligne<=position_ligne+1)
    {
        colonne=position_colonne;
        while (colonne<=position_colonne+4)
        {
            block[n].setTexture(Brique_verte);
            block[n].setPosition(colonne*41,ligne*21);
            occupation[colonne][ligne]=true; /* une brique (verte ici) occupe cette position */
            n++;
            colonne++;
        }
        ligne++;
    }

    /* dessin de 2 briques vertes verticales dans la colonne 3 */
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;

    /* dessin de 5 briques horizontales vertes sur 2 lignes à partir de la ligne 7 et de la colonne 3 */
    position_ligne=7;
    position_colonne=3;
    ligne=7;
    while (ligne<=position_ligne+1)
    {
        colonne=position_colonne;
        while (colonne<=position_colonne+4)
        {
            block[n].setTexture(Brique_verte);
            block[n].setPosition(colonne*41,ligne*21);
            occupation[colonne][ligne]=true;
            n++;
            colonne++;
        }
        ligne++;
    }

    /* dessin de 2 briques vertes verticales dans la colonne 7 */
    colonne=7;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(colonne*41,ligne*21);
    occupation[colonne][ligne]=true;
    n++;
    ligne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(colonne*41,ligne*21);
    occupation[colonne][ligne]=true;
    n++;
    ligne++;

    /* dessin de 5 briques horizontales vertes sur 2 lignes à partir de la ligne 11 et de la colonne 3 */
    position_ligne=11;
    position_colonne=3;
    ligne=11;
    while (ligne<=position_ligne+1)
    {
        colonne=position_colonne;
        while (colonne<=position_colonne+4)
        {
            block[n].setTexture(Brique_verte);
            block[n].setPosition(colonne*41,ligne*21);
            occupation[colonne][ligne]=true;
            n++;
            colonne++;
        }
        ligne++;
    }
    /* fin du dessin du S de S.N. */

    /* dessin du N de S.N. */
    /* dessin de 10 briques verticales vertes sur 1 colonne (colonne 12) à partir de la ligne 3 */
    position_ligne=3;
    position_colonne=12;
    ligne=position_ligne;
    while (ligne<=position_ligne+9)
    {
        block[n].setTexture(Brique_verte);
        block[n].setPosition(position_colonne*41,ligne*21);
        occupation[position_colonne][ligne]=true;
        n++;
        ligne++;
    }

    /* dessin de 2 briques vertes verticales dans la colonne 18 */
    position_colonne++;
    ligne=4;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;

     /* dessin de 2 briques vertes verticales dans la colonne 19 */
    position_colonne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;

    /* dessin de 2 briques vertes verticales dans la colonne 20 */
    position_colonne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;

    /* dessin de 2 briques vertes verticales dans la colonne 21 */
    position_colonne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;
    block[n].setTexture(Brique_verte);
    block[n].setPosition(position_colonne*41,ligne*21);
    occupation[position_colonne][ligne]=true;
    n++;
    ligne++;

     /* dessin de 10 briques verticales vertes sur 1 colonne (colonne 17) à partir de la ligne 3 */
    position_ligne=3;
    position_colonne=17;
    ligne=position_ligne;
    while (ligne<=position_ligne+9)
    {
        block[n].setTexture(Brique_verte);
        block[n].setPosition(position_colonne*41,ligne*21);
        occupation[position_colonne][ligne]=true;
        n++;
        ligne++;
    }
    /* fin du dessin du N de S.N. */

    /* dessin de 4 briques vertes dans les colonnes 9 et 11 */
    position_colonne=9;
    position_ligne=11;
    colonne=position_colonne;
    while (colonne<=position_colonne+1)
    {
        ligne=position_ligne;
        while (ligne<=position_ligne+1)
        {
            block[n].setTexture(Brique_verte);
            block[n].setPosition(colonne*41,ligne*21);
            occupation[colonne][ligne]=true;
            n++;
            ligne++;
        }
        colonne++;
    }

    /* dessin de 4 briques vertes dans les colonnes 19 et 20 */
    position_colonne=19;
    position_ligne=11;
    colonne=position_colonne;
    while (colonne<=position_colonne+1)
    {
        ligne=position_ligne;
        while (ligne<=position_ligne+1)
        {
            block[n].setTexture(Brique_verte);
            block[n].setPosition(colonne*41,ligne*21);
            occupation[colonne][ligne]=true;
            n++;
            ligne++;
        }
        colonne++;
    }

    /* Dessin du fond en briques jaunes */
    for (position_ligne=1;position_ligne<=14;position_ligne++)
    {
        for (position_colonne=1;position_colonne<=22;position_colonne++)
        {
            if (occupation[position_colonne][position_ligne]==false)
            {
                block[n].setTexture(Brique_jaune);
                block[n].setPosition(position_colonne*41,position_ligne*21);
                occupation[position_colonne][position_ligne]=true;
                n++;
            }
        }
    }
//    Mur_SN();
    float dx=6, dy=5;
    bool lancement;
    Event e, Depart;
    while(app.isOpen())
    {
        while(app.pollEvent(e))
        {
            if (e.type==Event::Closed)
            {
                app.close();
            }
        }

        Vector2f position_bille;
        Vector2f position_paddle;

        /* Premier affichage du fond, des briques, du paddle et de la bille avant lancement du jeu */
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);

        for (int i=0;i<n;i++)
        {
            app.draw(block[i]);
        }
        app.display();
        /* Fin du premier affichage du fond, des briques, du paddle et de la bille */ // Ensuite, réaffichage complet de l'écran pour chaque changement de l'image

        while(app.pollEvent(Depart))
        {
            if (Keyboard::isKeyPressed(Keyboard::Space))    /* test pour lancer le jeu en appuyant sur la barre espace */
            lancement=true;
            if(lancement)
            {
                while (position_bille.y<600)                /* tant que la bille ne sort pas par le bas de l'écran ... */
                {
                    sBall.move(dx,0);                       /* déplacement horizontal de la bille (suivant les x) */
                    for (int i=0;i<n;i++)
                    {
                        if (isCollide(sBall,block[i]))      /* test de collision avec une brique */
                        {
                            block[i].setPosition(-100,0);   /* si oui alors la brique frappée est redessinée en x=-100 et y=0, en dehors de la fenêtre d'affichage donc */
                            dx=-dx;
                        }
                    }
                    sBall.move(0,dy);                       /* déplacement vertical de la bille (suivant les y) */
                    for (int i=0;i<n;i++)
                    {
                        if (isCollide(sBall,block[i]))      /* test de collision avec une brique */
                        {
                            block[i].setPosition(-100,0);   /* si oui alors la brique frappée est redessinée en x=-100 et y=0, en dehors de la fenêtre d'affichage donc */
                            dy=-dy;
                        }
                    }

                    position_bille=sBall.getPosition();
                    position_paddle=sPaddle.getPosition();

                    if (position_bille.x<0 || position_bille.x>985) dx=-dx; /* test de la position de la bille, si elle sort de la fenêtre d'affichage */
                    if (position_bille.y<0) dy=-dy;                         /* alors on inverse son déplacement (rebond de la bille donc)              */

                    if (Keyboard::isKeyPressed(Keyboard::Right))            /* contrôle du mouvment du paddle vers la droite */
                    {
                        if (position_paddle.x<920)                          /* test si le paddle ne sort pas de la fenêtre d'affichage par la droite... */
                        {
                            sPaddle.move(10,0);                             /* alors mouvement de 10 vers la droite... */
                        }
                        else sPaddle.setPosition(930,550);                  /* sinon le paddle reste où il est (on le dessine à cette position fixe */
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Left))             /* contrôle du mouvment du paddle vers la gauche */
                    {
                        if (position_paddle.x>15)                           /* test si le paddle ne sort pas de la fenêtre d'affichage par la gauche... */
                        {
                            sPaddle.move(-10,0);                            /* alors mouvement de 10 vers la gauche... */
                        }
                        else sPaddle.setPosition(5,550);                    /* sinon le paddle reste où il est (on le dessine à cette position fixe */
                    }
                    if (isCollide(sPaddle,sBall)) dy=-(rand()%5+2);

                    app.clear();
                    app.draw(sBackground);
                    app.draw(sBall);
                    app.draw(sPaddle);

                    for (int i=0;i<n;i++)
                    {
                    app.draw(block[i]);
                    }
                    app.display();
                }
                if (position_bille.y>600) /* test si la bille est sortie par le bas de la fenêtre d'affichage */
                {
                    sBall.setPosition(position_paddle.x+20,position_paddle.y-10); /* si oui alors replace la bille sur le paddle et... */
                    app.draw(sBall);    /* ... dessine la bille à l'emplacement actuel du paddle */
                }
            }
        }
    }
    return 0;
}

