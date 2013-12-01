#include "Protein.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

Protein::Protein()
{
  _length=0;
  _sequence=0x0;
}


Protein::Protein(int len)
{
  _length=len;
  _sequence=new int[_length];
  for(int i=0;i<_length;i++)
    _sequence[i]=rand() % 2;
}


Protein::Protein(const string &seq, )
{
  _length=seq.size();
  _sequence=new int[_length];
  for(int i=0;i<_length;i++)
    {
      _sequence[i]=seq[i]-48;
    }


}

Protein::Protein(int* seq,int len)
{
  _length=len;
  _sequence=new int[_length];
  for(int i=0;i<_length;i++)
    {      
      _sequence[i]=seq[i];
    }
}



Protein::Protein(const Protein &mum, struct_mutagen mutation)
{
  _length=mum._length;
  _sequence=new int[_length];
 
  for(int i=0;i<_length;i++)
    {
    if (rand()/MAX_RAND > mutation.cds_point_mutation_rate)
    _sequence[i]=mum._sequence[i];
    else
    _sequence[i]=!mum._sequence[i];
    }
}

Protein::~Protein()
{
  delete[] _sequence;
}

void Protein::print()const
{
  for(int i=0; i< _length; i++)
    cout << _sequence[i];
}

void Protein::dprint()const
{
  int out =_sequence[_length-1];
  for(int i=0; i< _length-1; i++)
    out += _sequence[i]<<(_length-i);
  cout << out;
}

