#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

///Classe mère : one block to rule them all...
class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons créer

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

///Bloc que Snoopy pourra casser
class Cassable : public Bloc
{
public:
    //constructeur surchargé
    Cassable(int posX, int posY, char type);
    //destructeur
    ~Cassable();
};

///Bloc que Snoopy pourra pousser
class Poussable : public Bloc
{
private:
    bool m_estPoussable;
public:
    //constructeur surchargé
    Poussable(int posX, int posY, char type, bool estPoussable);
    //destructeur
    ~Poussable();
    //getters
    bool getEstPoussable()const;
    //setters
    void setEstPoussable(bool estPoussable);
    //méthodes (Snoopy ?)
    //void bougerBlocPoussable(int posX, int posY);
};

///Bloc vide qui tapisse la matrice
class Vide : public Bloc
{
public :
    //constructeur surchargé
    Vide(int posX, int posY, char type);
    //destructeur
    ~Vide();
};

#endif // BLOCK_H_INCLUDED
