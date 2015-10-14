#ifndef FACE_HPP
#define FACE_HPP

#include "point.hpp"

class Face{
    private:
        long unsigned int summit_one;
        long unsigned int summit_two;
        long unsigned int summit_three;

    public:
    ///Constructeur & Destructeur
        Face();
        ~Face();

    ///Getter & Setter
        long unsigned getS_one() const;
        long unsigned getS_two() const;
        long unsigned getS_three() const;

        void setS_one(const long unsigned& );
        void setS_two(const long unsigned& );
        void setS_three(const long unsigned& );

    ///Calcul de l'aire du triangle en fonction des calculs de distance entre les points (classe Point)
        double calc_area(); ///Formule de Héron
};

#endif // FACE_HPP
