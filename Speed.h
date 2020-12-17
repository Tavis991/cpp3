#ifndef SPEED_H
#define SPEED_H


class Speed
{
    public:
        friend class Drone;
        Speed();
        Speed(double x, double y);
        ~Speed();
        Speed(const Speed& other);
        //Speed(const Location& other);   // not legal ? how to overcom
        Speed& operator=(const Speed& other);
        Speed& operator * (double scal);
        Speed& operator + (const Speed& rhs);
        //void randomize (double per_best, double glob_best); ///iteration should thin kabout this more
        double getY () const { return y;}
        double getX () const { return x;}
    protected:

    private:
        double x;
        double y;
};

#endif // SPEED_H
