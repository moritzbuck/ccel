#include "Genome.h"
#include "Gene.h"
#include "Protein.h"
#include "Chemspace.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


Genome::Genome(int gene_count,int length,int plen)
{
  _gene_count=gene_count;
  _gene=new Gene*[_gene_count];
  for(int i=0;i<_gene_count;i++)
    _gene[i]=new Gene(length,plen);

}

Genome::Genome(const Genome &mum, struct_mutagen mutation)
{
  _gene_count=mum._gene_count;

  _gene= new Gene*[_gene_count];
  for(int i=0; i<_gene_count ; i++)
    _gene[i]=new Gene(*(mum._gene[i]), mutation);
}

Genome::~Genome()
{
  for(int i=0;i<_gene_count;i++)
    delete _gene[i];
  delete[] _gene;
}


void Genome::clear()
{
  for(int i=0; i<_gene_count;i++)
    {
      _gene[i]->clear();
    }

}

void Genome::bind( const  Protein& prot)
{
  for(int i=0; i<_gene_count;i++)
    {
      _gene[i]->bind(prot);
    }
}

Chemspace* Genome::refresh_content(Chemspace* chemspace)
{


  delete chemspace;
  int nb_chems=0;
  for(int i=0;i<_gene_count;i++)
    if(_gene[i]->is_active()) nb_chems++;
  chemspace=new Chemspace(nb_chems);

  for(int i=0;i<_gene_count;i++)
  if(_gene[i]->is_active())
    {
      chemspace->set(--nb_chems,_gene[i]->get_product());
    }
  return chemspace;
}

void Genome::print() const
{

  for(int i=0; i<_gene_count; i++)
    {
      cout << "============= Gene: "<< i <<  " ==============" << endl;
      _gene[i]->print();
    }

}


