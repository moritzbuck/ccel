#ifndef _GA_H_
#define _GA_H_

#include "Genome.h"

struct ga_params
{
int ncs_length;
int cds_length;
int pop_size;
struct_mutagen mutation;
}

class GA
{
Genome** _population;
ga_params _params;
double* _fitness;
double _best;

void generate_fits();
void update_population();

public :

GA(ga_params params);
~GA();

void evolve();
void print();
void load(string filen);
void save(string filen);


};

#endif