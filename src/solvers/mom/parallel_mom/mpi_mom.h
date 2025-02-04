#ifndef MPI_MOM_H
#define MPI_MOM_H

#include <complex>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <mpi.h>

#include "mpi_fill_vrhs.h"
#include "mpi_fill_zmn.h"
#include "mpi_fill_ilhs.h"
#include "../../../data_structures/node.h"
#include "../../../data_structures/edge.h"
#include "../../../data_structures/triangle.h"

extern "C"
{
  	void Cblacs_pinfo(int*, int*); 
    void Cblacs_get(int , int, int*);
    void Cblacs_gridinit(int*, const char*, int, int);
    void Cblacs_gridinfo(int, int*, int*, int*,int*);


	
	 int numroc_(int*, int*, int*, int*, int*);
}
void mpiPerformMoM(std::map<std::string, std::string> &const_map,
                   std::map<int, Label> &label_map,
                   std::vector<Triangle> &triangles,
                   std::vector<Edge> &edges,
                   std::vector<Node<double>> &nodes,
                   std::vector<Excitation> &excitations,
                   std::complex<double> *ilhs);

#endif
