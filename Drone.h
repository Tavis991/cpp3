#ifndef DRONE_H
#define DRONE_H
#include "Speed.h"
#include "Location.h"
//maybe global best and target be here ??
//Drone * glob_best;
//Location target;


class Drone
{
    public:
        friend class Forest;
        Drone();
        ~Drone();
        Drone(const Drone& other);
        Drone(Location loc, Speed sped);
        Drone& operator=(const Drone& other);
        void iterate();   //here drone will fly, randomize speed, update per_best etc
        Location getLoc()   const   {   return loc;}    /// will this ruin the project ?? const added 13:52 hamishi
        void setLoc(Location& n_loc)      {     loc = n_loc;}
        Speed getSp()  const    {   return sped;}
        void setSp(Speed& n_sped)      {     sped = n_sped;}
        double  euclid_to_gol (const Location& curr);
        friend   ostream& operator <<(ostream & os, const Drone& ref);
    protected:

    private:
        static Location target;
        static Drone* glob_best;
        Location per_best;
        Location loc;
        Speed sped;
};

inline ostream& operator <<(ostream & os, const Drone& ref)
{

    os << ref.getLoc() << endl;

    return os;
}

#endif // DRONE_H
