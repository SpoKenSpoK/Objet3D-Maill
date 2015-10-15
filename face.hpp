#ifndef FACE_HPP
#define FACE_HPP

#include "point.hpp"

class Face{
    private:
        long unsigned int summit_one;
        long unsigned int summit_two;
        long unsigned int summit_three;
        double perimeter;
        double area;

    public:
    ///Constructeur & Destructeur
        Face();
        ~Face();

    ///Getter & Setter
        long unsigned getS_one() const;
        long unsigned getS_two() const;
        long unsigned getS_three() const;
        double getPerimeter() const;
        double getArea() const;

        void setS_one(const long unsigned& );
        void setS_two(const long unsigned& );
        void setS_three(const long unsigned& );
        void setPerimeter(const double&);
        void setArea(const double&);

    ///Calcul de l'aire du triangle en fonction des calculs de distance entre les points (classe Point)
        double calc_area(double&, double&, double&); ///Formule de Héront
};

#endif // FACE_HPP
