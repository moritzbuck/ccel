#include "Chemspace.h"
#include "Protein.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

Chemspace::Chemspace(int len)
{
  _nb_prots = len;
  _content = new Protein*[_nb_prots];
}

Chemspace::~Chemspace()
{
 
  if(_content)
    {
      for(int i=0; i< _nb_prots; delete _content[i++]);
      delete[] _content;
    }
}

int Chemspace::size()
{
  return _nb_prots;
}

Protein Chemspace::get(int idx)
{
  if(idx < _nb_prots)
    return *_content[idx];
  else 
    return Protein(0x0);
}

void Chemspace::set(int idx, Protein chem)
{
  if(idx<_nb_prots)
    _content[idx]=new Protein(chem);
  else
    cout << "fuck you, this is no place for a protein" <<endl;
}

void Chemspace::print ()
{
  for (int i=0; i < _nb_prots; i++)
    {
      _content [i]-> dprint ();
      cout << "; ";
    }
  cout <<endl;
}
