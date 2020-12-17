#include <iostream>
#include <fstream>
#include "Forest.h"

bool forest_reader(fstream& confi, fstream& init, Location& target, int& counter);

using namespace std;
int main(int argc, char *argv[]) {
//    if (argc != 4) {
//     cerr <<"Error; invalid input";
//     return 1;
//    }
//    fstream confi(argv[1]);
//    if (!confi){
//     cerr <<"Error; invalid input";
//     return 1;
//    }
//    fstream init(argv[2]);
//    if (!init){
//     cerr <<"Error; invalid input";
//     return 1;
//    }
//     fstream finale(argv[3]);
//    if (!finale){
//     cerr <<"Error; invalid input";
//     return 1;
//    }
    Location target(10,22);
    int counter(800);
//    if (!forest_reader(confi, init, target, counter))
//    {
//    cerr <<"Error; invalid input";
//     return 1;
//    }
    Drone sumo (Location(10.5,5),Speed(1,1));
    List drone_list;
    sumo.setSp(sumo.getSp()*0.35);
    drone_list.insert(sumo);
     fstream finale;
    finale.open ("final.dat");
    Forest frost(target, counter, drone_list, finale); //euclid to gol wokrs
     cout << drone_list;
    for (int i=0; i <5; i++){
        frost.iterate();              ///iteration rolls back in main but forest is fine is it ok or disaster
    }

    //cout << frost.glob_best->getLoc() <<endl;

    return 0;
}

bool forest_reader(fstream& confi, fstream& init, Location& target, int& counter)
{

//    getline (input, roadZ[0]);
//    double tempX



}
