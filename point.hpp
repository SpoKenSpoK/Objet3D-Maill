#ifndef POINT_HPP
#define POINT_HPP

class Point{
    private:
        double point_one;
        double point_two;
        double point_three;

    public:
    ///Constructeur & Desctructeur
        Point();
        ~Point();

    ///Getters & Setters
        double getP_one() const;
        double getP_two() const;
        double getP_three() const;

        void setP_one(const double&);
        void setP_two(const double&);
        void setP_three(const double&);

    ///Calcul longueur entre les points
        double calc_length();


};

#endif // POINT_HPP
