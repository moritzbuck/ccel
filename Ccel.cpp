#include "Ccel.h"
#include "Genome.h"
#include "Chemspace.h"
#include "Protein.h"
#include <cstdlib>
#include <iostream>
using namespace std;


Ccel::~Ccel()
{
  if(_genome) delete _genome;
}

void Ccel::update()
{
  _genome->clear();

  for(int i=0; i<_chemspace->size();i++)
    {
      _genome->bind(_chemspace->get(i));
    }
  _chemspace=_genome->refresh_content(_chemspace);
}

Ccel::Ccel(Genome* genome)
{
_genome= genome;
_chemspace= new Chemspace(0);
}

void Ccel::print() const
{
  //
  baby->update();

  cout << endl << "======updated==========" << endl << endl;

  baby->print();
  _genome -> print();
  //  cout << "============= Chemspace ==============" << endl;
  _chemspace->print();
}
