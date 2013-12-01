#include "GRN.h"
#include "Genome.h"

GRN::GRN(Genome* genome)
{
  _genome=genome;
}

GRN::~GRN()
{
  delete _genome;
}
