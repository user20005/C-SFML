#include <SFML/Graphics.hpp>
#include <conio.h>
#include <time.h>
#include "Mur_1.hpp"

using namespace sf;

void Mur_SN()
{
    srand(time(0));
//    RenderWindow app(VideoMode(1000,600), "Jeux Arkanoid !");
//    app.setFramerateLimit(60);

    Texture Brique_bleue, Brique_grise, Brique_jaune, Brique_orange, Brique_rouge, Brique_turquoise, Brique_verte, Brique_violette, Fond, Bille, Paddle;

    Brique_bleue.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-bleue.png");
    Brique_grise.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-grise.png");
    Brique_jaune.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-jaune.png");
    Brique_orange.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-orange.png");
    Brique_rouge.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-rouge.png");
    Brique_turquoise.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-turquoise.png");
    Brique_verte.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-verte.png");
    Brique_violette.loadFromFile("E:/C++ Arkanoid-multi-niveau/Brique-violette.png");
    Fond.loadFromFile("E:/C++ Arkanoid-multi-niveau/Fond_plage2b.jpg");
    Bille.loadFromFile("E:/C++ Arkanoid-multi-niveau/Ball-rouge2-redim.png");
    Paddle.loadFromFile("E:/C++ Arkanoid-multi-niveau/Paddle_redim.png");

    Sprite sBackground(Fond), sBall(Bille), sPaddle(Paddle);
    sPaddle.setPosition(400,550);
    sBall.setPosition(420,540);

    Sprite block[500];
    bool occupation[23][15];

    int n=0, colonne=0, ligne=0, position_colonne=0, position_ligne=0;

    /* initialisation de l'état d'occupation des briques */
    for (position_ligne=1;position_ligne<=14;position_ligne++)
    {
        for (position_colonne=1;position_colonne<=22;position_colonne++)
        {
            occupation[position_colonne][position_ligne]=false;
        }
    }

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
                block[n].setTexture(Brique_bleue);
                block[n].setPosition(position_colonne*41,position_ligne*21);
                occupation[position_colonne][position_ligne]=true;
                n++;
            }
        }
    }
}

