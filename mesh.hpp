#ifndef MESH_HPP
#define MESH_HPP
/** La classe Mesh représente l'objet maillé 3D.
    Ce dernier contient un certain nombre de points ainsi que de faces */

class Mesh{
    private:
        long unsigned int numberof_point;   /**< Attribut représentant le nombre total de points dans l'objet maillé. */
        long unsigned int numberof_face;    /**< Attribut représentant le nombre total de faces dans l'objet maillé. */

    public:
    /// Constructeur
    /** Constructeur prennant en paramètre le nombre de points et de faces présents dans l'objet maillé. */
        Mesh(long unsigned, long unsigned);
    /// Destructeur
    /** Destructeur de l'objet Mesh */
        ~Mesh();

    /// Getter du nombre de point
    /** Retourne la valeur de l'attribut "numberof_point" qui est un entier long */
        long unsigned getNumberof_p() const;
    /// Setter du nombre de point
    /** Modifie la valeur de l'attribut "numberof_point" en passant en paramètre un entier long constant par référence  */
        void setNumberof_p(const long unsigned&);

    /// Getter du nombre de face
    /** Retourne la valeur de l'attribut "numberof_face" qui est un entier long */
        long unsigned getNumberof_f() const;
    /// Setter du nombre de face
    /** Modifie la valeur de l'attribut "numberof_face" en passant en paramètre un entier long constant par référence  */
        void setNumberof_f(const long unsigned&);

};

#endif // MESH_HPP
