#ifndef POINT_HPP
#define POINT_HPP
/** La classe Point représente les points ou sommets(composés de 3 coordonnées) des triangles Face composant l'objet Mesh.
    Chaque sommet du triangle a donc trois points dans l'espace (coordonnées). \n
    Il s'agit donc ici de récupérer les coordonnées se trouvant dans le fichier .OFF .
    Ces coordonnées sont alors placées respectueusement dans les attributs point_one, point_two, point_three de type \b double \n
    */

class Point{
    private:
        double point_one;   /**< Coordonnées \f$ x\f$ du sommet */
        double point_two;   /**< Coordonnées \f$ y\f$ du sommet */
        double point_three; /**< Coordonnées \f$ z\f$ du sommet */

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
        Par le calcul on obtient la longueur d'un côté obtenu grâce à des coordonnées réelles. Le résultat obtenu sera donc double.
        \param p1 un entier positif nous donnant la ligne où se situe les coordonnées du sommet p1 avec lesquels travailler
        \param p2 un entier positif nous donnant la ligne où se situe les coordonnées du sommet p2 avec lesquels travailler
        \return la longueur AB (BC ou encore CA), un réel double */
        double calc_length(unsigned int p1, unsigned int p2);
};

#endif // POINT_HPP
