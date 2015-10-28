#ifndef FACE_HPP
#define FACE_HPP

/** Une face compose un objet 3D, où plutôt un objet 3D est composé d'une multitude de faces.
    Celle-ci peut-être décomposée en trois sommets, ainsi que trois segments (il s'agit ici de faces triangulaires).
    Par suite de calcul(via les coordonnées de chaques sommets dans l'espace - x, y, z - soit 3*3 = 9 coordonnées pour chaque face)
    on obtient la longueur des segments composant la face et donc son périmètre.
    Nous pouvons alors effectuer le calcul d' \b Héron pour trouver l'aire d'une face triangulaire.
    \n \n
    Choix des types pour les attributs : \n
    Chaque sommet indique une ligne de lecture pour les coordonnées d'un sommet. Il y a donc 3 coordonnées x, y et z ici de type \b double.
    Sachant qu'il peut y avoir beaucoup de coordonnées nous préférons partir sur un type \b unsigned \b long \b int pour la valeur des sommets. */


class Face{
    private:
        long unsigned int summit_one;   /**< Place (ligne du fichier .OFF) où se situe les coordonnées du premier sommet de la Face */
        long unsigned int summit_two;   /**< Place (ligne du fichier .OFF) où se situe les coordonnées du second sommet de la Face */
        long unsigned int summit_three; /**< Place (ligne du fichier .OFF) où se situe les coordonnées du troisième sommet de la Face */
        double segment_one; /**< Longueur du segment entre le premier et le second sommets de la Face */
        double segment_two; /**< Longueur du segment entre le second et le troisième sommets de la Face */
        double segment_three;   /**< Longueur du segment entre le troisième et le premier sommets de la Face */
        double perimeter;   /**< Périmètre de la Face */
        double area;    /**< Aire de la Face */

    public:
    /// Constructeur
        Face();
    /// Destructeur
        ~Face();

    /// Accesseur du sommet 1
    /** Retourne la valeur du sommet 1 \return summit_one un entier positif long */
        long unsigned getS_one() const;

    /// Accesseur du sommet 2
    /** Retourne la valeur du sommet 2 \return summit_two un entier positif long */
        long unsigned getS_two() const;

    /// Accesseur du sommet 3
    /** Retourne la valeur du sommet 3 \return summit_three un entier positif long */
        long unsigned getS_three() const;

    /// Accesseur du segment 1
    /** Retourne la valeur du segment 1  \return segment_one un réel double */
        double getSeg_one() const;

    /// Accesseur du segment 2
    /** Retourne la valeur du segment 2 \return segment_two un réel double */
        double getSeg_two() const;

    /// Accesseur du segment 3
    /** Retourne la valeur du segment 3 \return segment_three un réel double */
        double getSeg_three() const;

    /// Accesseur du périmètre
    /** Retourne la valeur du périmètre \return perimeter un réel double */
        double getPerimeter() const;

    /// Accesseur de l'aire
    /** Retourne la valeur de l'aire \return area un double réel */
        double getArea() const;

    /// Mutateur du sommet 1
    /** Modifie la valeur du sommet 1 \param one un entier positif long constant passé par référence */
        void setS_one(const long unsigned& one);

    /// Mutateur du sommet 2
    /** Modifie la valeur du sommet 2 \param two un entier positif long constant passé par référence */
        void setS_two(const long unsigned& two);

    /// Mutateur du sommet 3
    /** Modifie la valeur du sommet 3 \param three un entier positif long constant passé par référence */
        void setS_three(const long unsigned& three);

    /// Mutateur du segment 1
    /** Modifie la valeur du segment 1 \param o un réel double constant passé par référence */
        void setSeg_one(const double& o);

    /// Mutateur du segment 2
    /** Modifie la valeur du segment 2 \param t un réel double constant passé par référence */
        void setSeg_two(const double& t);

    /// Mutateur du segment 3
    /** Modifie la valeur du segment 3 \param th un réel double constant passé par référence */
        void setSeg_three(const double& th);

    /// Mutateur du périmètre
    /** Modifie la valeur du périmètre \param p un réel double constant passé par référence */
        void setPerimeter(const double& p);

    /// Mutateur de l'aire
    /** Modifie la valeur de l'aire \param a un réel double constant passé par référence */
        void setArea(const double& a);

    /// Calcul de l'aire du Triangle(Face) via la Forume d'Héron
    /** \b Forume \b d' \b Héron : \n
          En géométrie euclidienne, la formule de Héron, du nom de Héron d'Alexandrie, permet de calculer l'aire d'un triangle quelconque en ne connaissant
          que les longueurs des trois côtés du triangle : \n

          Soit trois côtés : \f$ a\f$ , \f$ b\f$ et \f$ c\f$ \n
          On a donc :  \f$\sqrt{(p-a)+(p-b)+(p-c)}\f$ Avec \f$ p\f$ = \f$ 1/2 *(a+b+c)\f$

        \param a un réel double
        \param b un réel double
        \param c un réel double
        \return un réel double valant l'aire de la Face */
        double calc_area(double a, double b, double c);
};

#endif // FACE_HPP
