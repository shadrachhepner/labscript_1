#include "threevector.h"
#include "threematrix.h"
#include <iostream>

using namespace std;

// Skeleton for 
ThreeVec Evaluate_B(double x = 0, double y = 0, double z = 0, double t = 0);
ThreeVec Evaluate_E(double x = 0, double y = 0, double z = 0, double t = 0);

const ThreeVec B_0(0, 0, 1); // Reference magnetic field
const ThreeVec E_0(0, 1.01, 0); // Reference electric field

int main()
{
  //Say that I'm running
  cout << "I'm running, you did it!"<<endl;
  //Define constants
  const ThreeVec V_0(1, 0, 0);
  const double FINAL_TIME = 62.8;
  const ThreeVec R_0(0, 0, 0);

  //Define variables
  ThreeVec v = ThreeVec(V_0);
  ThreeVec v_last = ThreeVec(); // the -1 velocity for leapfrog
  ThreeVec v_next = ThreeVec(); // the "+1" velocity for leapfrog
  ThreeVec r = ThreeVec(R_0);
  double dt = .01; // constant timestep
  double current_time = 0; // keep track  of how much time has passed
  bool finished = false;
  ofstream outfile;
  outfile.open("data.txt");
      // Find v_(-1) with a backwards Euler step
  v_last = v - ((Evaluate_E() + (v^Evaluate_B()))*dt);
    while(!finished)
    {
      v_next = ((Evaluate_E() + (v^Evaluate_B()))*2*dt) + v_last;
      v_last = ThreeVec(v);
      v = ThreeVec(v_next);
      
      current_time += dt;
      outfile << current_time << "\t" << r.getX() << "\t" << r.getY() << "\t" << r.getZ() << "\t" << v.getX() << "\t" << v.getY() << "\t" << v.getZ() << endl;
      if(current_time > FINAL_TIME){
	finished = true;
      }
    }
  outfile.close();
  return(0);
}

  // Evaluate the B field as a function of space and time
ThreeVec Evaluate_B(double x, double y, double z, double t)
{
  return B_0;
}

  // Evaluate the B field as a function of space and time
ThreeVec Evaluate_E(double x, double y, double z, double t)
{
  return E_0;
}
