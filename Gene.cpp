#include "Gene.h"
#include "Protein.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

Gene::Gene(int length,int prot_len)
{
  _length=length;
  _sequence= new int[_length];
  _occupation= new int[_length];
  _product=new Protein(prot_len);

  for(int i=0; i<_length; i++)
    {
      _sequence[i] =  rand() % 2;
      _occupation[i] = 0;
    }
}



Gene::Gene(const Gene &mum, struct_mutagen mutation)
{
  _length=mum._length;
  _sequence= new int[_length];
  _occupation= new int[_length];
  _product=new Protein(*mum._product, mutation);

  for(int i=0; i<_length; i++)
    {
    if (rand()/MAX_RAND > mutation.ncs_point_mutation_rate)
      _sequence[i] =  mum._sequence[i];
      else _sequence[i] =  !mum._sequence[i];
      _occupation[i] = 0;
    }
 
}

Gene::Gene(const std::string& seq, const std::string& prot)
{
  _length=seq.size();
  _sequence= new int[_length];
  _occupation= new int[_length];
  _product=new Protein(prot);

  for(int i=0; i<_length; i++)
    {
       _sequence[i] =  seq[i]-48;
      _occupation[i] = 0;
    }
}


Gene::~Gene()
{
  delete[] _sequence;
  delete[] _occupation;
}


void Gene::bind(const Protein &prot)
{
  for(int dna=0; dna< _length; dna++)
    {
      for(int i=0;i < _product->get_length();i++)
	{
	  if(prot.get_aa(i)!=_sequence[dna+i])
	    break;

	  if(i+1==prot.get_length())
	    for(int o=0;o< prot.get_length();o++)
	      {
		_occupation[dna+o]=!_occupation[dna+o];
	      }
	}
    }
}

void Gene::clear()
{
  for(int i=0; i<_length; i++)
    _occupation[i] =0;

}

void Gene::print() const
{
  for(int i=0; i< _length ; i++)
    cout << (_sequence[i]);
  cout << endl;
  
  for(int i=0; i< _length ; i++)
    cout << (int)_occupation[i];
  if(is_active())
    cout << " > "  ;
  else 
    cout << " X "  ;
  _product->print();
  cout << " : ";
  _product->dprint();
  cout << endl;
}

Protein Gene::get_product() const
{
  return *_product;
}


int Gene::is_active() const
{
  int outp=0;
  for(int i=0; i< _length; i++)
    if(!_occupation[i])
      if(_sequence[i])
	outp++;
  return outp % 2;

}
