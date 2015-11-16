#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED

///Classe m�re : one bloc to rule them all...
class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons cr�er

public:
    //constructeur
    Bloc(int posX, int posY, char type);
    //destructeur
    ~Bloc();
    //getters
    int getPosX()const;
    int getPosY()const;
    char getType()const;
    //setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setType(char type);
};

///----------------------------------------------------------------
///Bloc que Snoopy pourra casser
class Cassable : public Bloc
{
private :
    bool m_estPiege;
public:
    //constructeur surcharg�
    Cassable(int posX, int posY, char type,bool estPiege);
    //destructeur
    ~Cassable();
    //getters
    bool getEstPiege()const;
    //setters
    void setEstPiege(bool estPiege);
};

///----------------------------------------------------------------
///Bloc que Snoopy pourra pousser
class Poussable : public Bloc
{
private:
    bool m_estPoussable;
public:
    //constructeur surcharg�
    Poussable(int posX, int posY, char type, bool estPoussable);
    //destructeur
    ~Poussable();
    //getters
    bool getEstPoussable()const;
    //setters
    void setEstPoussable(bool estPoussable);
    //m�thodes (Snoopy ?)
    //void bougerBlocPoussable(int posX, int posY);
};

///----------------------------------------------------------------
///Bloc Snoopy
class Snoopy : public Bloc
{
private :
    int m_vies;
    int m_score;
    int m_oiseaux;

public :
    //Constructeurs
    Snoopy(int posX, int posY, char type,int vies,int score,int oiseaux);
    //Destructeur
    ~Snoopy();
    //getters
    int getVies()const;
    int getScore()const;
    int getOiseaux()const;
//setters
    void setVies(int vies);
    void setScore(int score);
    void setOiseaux(int oiseaux);
    /* //M�thodes
       void moveSnoopy();
       void breakbloc(Bloc &bloc); ///
       void saveGame();
       void loadGame();*/
};

///-----------------------------------------------------
///Classe Balle
class Balle : public Bloc
{
public :
    //Constructeur surcharg�
    Balle(int posX, int posY, char type);
    //Destructeur
    //~Balle();
    //M�thodes
    void bougerBalle();
};

#endif // BLOC_H_INCLUDED
