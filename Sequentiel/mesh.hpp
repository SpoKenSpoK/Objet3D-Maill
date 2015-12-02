#ifndef MESH_HPP
#define MESH_HPP

/** La classe Mesh représente l'objet maillé 3D.
    Ce dernier contient un certain nombre de points et faces entiers. \n
    Nous utilisons donc ici les types \b unsigned \b int pour les attributs. */

class Mesh{
    private:
        unsigned int numberof_point;    /**< Nombre total de sommets dans l'objet maillé */
        unsigned int numberof_face;     /**< Nombre total de faces dans l'objet maillé */
        double FULL_AREA;               /**< Aire totale de la forme */

    public:
    /// Constructeur
    /** Constructeur prennant en paramètre le nombre de Point et de Face présents dans l'objet maillé
        \param p un entier positif
        \param f un entier positif */
        Mesh(unsigned int p, unsigned int f, double area =0);
    /// Destructeur
        ~Mesh();

    /// Accesseur du nombre de points
    /** Retourne la valeur du nombres de points \return numberof_point un entier positif */
        unsigned int getNumberof_p() const;

    /// Accesseur du nombre de faces
    /** Retourne la valeur du nombre de faces \return numberof_face un entier positif */
        unsigned int getNumberof_f() const;

    /// Accesseur de la valeur totale de l'aire
    /** Retourne la valeur totale de l'aire \return FULL_AREA un réel double */
        double getFull() const;

    /// Mutateur du nombre de points
    /** Modifie la valeur du nombre de points \param p un entier positif constant passé par référence */
        void setNumberof_p(const unsigned int& p);

    /// Mutateur du nombre de faces
    /** Modifie la valeur du nombre de faces \param f un entier positif constant passé par référence */
        void setNumberof_f(const unsigned int& f);

    /// Mutateur de la valeur totale de l'aire
    /** Modifie la valeur totale de l'aire \param a un réel double constant passé par référence */
        void setFull(const double& a);
};

#endif // MESH_HPP
