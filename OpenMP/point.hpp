#ifndef POINT_HPP
#define POINT_HPP
/** La classe Point représente les points ou sommets(composés de coordonnées) des triangles Face composant l'objet Mesh.
    Chaque sommet du triangle a donc trois points dans l'espace(coordonnées). \n
    Il s'agit donc ici de récupérer les coordonnées se trouvant dans le fichier .OFF .
    Ces coordonnées sont alors placées respectueusement dans les attributs point_one, point_two, point_three de type \b double \n
    */

class Point{
    private:
        double point_one;   /**< Coordonnées du premier point dans l'espace(x)*/
        double point_two;   /**< Coordonnées du deuxième point dans l'espace(y)*/
        double point_three; /**< Coordonnées du troisième point dans l'espace(z)*/

    public:
    /// Constructeur
        Point();
    /// Destructeur
        ~Point();

    /// Accesseur du point 1
    /** Retourne la coordonnée du premier point \return point_one un réel double */
        double getP_one() const;

    /// Accesseur du point 2
    /** Retourne la coordonnée du deuxième point \return point_two un réel double */
        double getP_two() const;

    /// Accesseur du point 3
    /** Retourne la coordonnée du troisième point \return point_three un réel double */
        double getP_three() const;

    /// Mutateur du point 1
    /** Modifie la coordonnée du premier point \param o un réel double constant passé par référence */
        void setP_one(const double& o);

    /// Mutateur du point 2
    /** Modifie la coordonnée du deuxième point \param t un réel double constant passé par référence */
        void setP_two(const double& t);

    /// Mutateur du point 3
    /** Modifie la coordonnée du troisième point \param th un réel double constant passé par référence */
        void setP_three(const double& th);

    /// Calcul de la longueur d'un côté
    /** Soit la formule suivant : \f$\sqrt{(x2-x1)^2+(y2-y1)^2+(z2-z1)^2}\f$ \n
        \param p1 un entier positif
        \param p2 un entier positif
        \return la longueur d'un segement entre deux points donnés en paramètres, calculé via leurs coordonnées qui sont des réels doubles. Nous retournons donc un double */
        double calc_length(unsigned int p1, unsigned int p2);
};

#endif // POINT_HPP