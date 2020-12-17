#include "Forest.h"

Forest::Forest(Location target_percise, int counter, List& lil, fstream& finale):
target(GridSquare(target_percise)), counter(counter), lil(lil), finale(finale), iterations(0)
{
    Drone::target = target_percise;  //drone class has  percise location

    for (int i=0; i<x_max; i++){
        for (int j=0; j<y_max; j++){
        GridArr[i][j] = GridSquare(i,j);
        }
    }


    glob_best = &lil[0];
    double mini = euclid_to_gol(lil[0].getLoc()); //loop does two things, inizialtion glob_best

    GridSquare temp_sqr = GridSquare(lil[0].getLoc()); //and inizialtion drone count on GRIDARR
    GridArr[temp_sqr.getX()][temp_sqr.getY()]++;

    for (int i=1; i<lil.size(); i++){

        temp_sqr = GridSquare(lil[i].getLoc());
        GridArr[temp_sqr.getX()][temp_sqr.getY()]++; //dronecount

        double temp = euclid_to_gol(lil[i].getLoc()); //glob_best
        if (temp < mini) {
        mini = temp;
        glob_best = &lil[i];
        }
    }

    Drone::glob_best = glob_best;

}

Forest::~Forest()
{

}

//Forest::Forest(const Forest& other)
//{
//    copy ctor
//}

Forest& Forest::operator=(const Forest& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

double Forest::euclid_to_gol (const Location& curr){

    double dist = pow((pow((curr.getX() - Drone::target.getX()), 2) + pow((curr.getY() - Drone::target.getY()), 2)), 0.5);
    return dist;
}


void Forest::fresh_glob()
{

    for (int i=1; i<lil.size(); i++){
        if (euclid_to_gol(lil[i].getLoc()) < euclid_to_gol(glob_best->getLoc()))
        {
            glob_best = &lil[i];
        }
    }

}

 void Forest::iterate()
{

    GridSquare temp;


                                //itrerate all the drones speeds etc

    for (int i=0; i<lil.size(); i++){

        temp = lil[i].getLoc();
        GridArr [temp.getX()][temp.getY()]--; //drone left sqr

        lil[i].setLoc(lil[i].getLoc() + lil[i].getSp());
        temp = lil[i].getLoc();

        GridArr [temp.getX()][temp.getY()]++; //drone entered sqr
        //
        //lil[i].getSp().randomize();  //should think about this more
    }

    for (int i=0; i<lil.size(); i++){  /// testing iterations
        cout << iterations << "iterations" << endl;
        cout <<  lil[i].getLoc();

    }

    fresh_glob(); //set new glob
    iterations++;

    if (GridSquare(glob_best->getLoc()) == target ) {   return simu_finish();}
    if (iterations == counter)  {   return simu_finish();}
                          //end program print to file yadayda
 }


 int Forest::operator() (int x, int y) const
 {
    if ((x > x_max) || (y > y_max) || (x < 0) || (y < 0) ) return 0; //out of bounds

    return (GridArr[x][y]).getCount();

 }


 // bool Forest::forest_reader(fstream& confi, fstream& init, fstream& finale);


  void Forest::simu_finish(){
  cout << iterations << endl;

   for (int i=0; i<lil.size(); i++){
   cout << lil[i].getLoc();
   } // print to file drone locations and such

  exit(0);
  }
