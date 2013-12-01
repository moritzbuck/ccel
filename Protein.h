#ifndef _PROTEIN_H_
#define _PROTEIN_H_
#include <string>
#include "Genome.h"


class Protein
{
  int _length;
  int* _sequence;
  int _linked;
  Protein* _previous;
  Protein* _next;

 public:

  Protein(int len);
  Protein();

  Protein(const Protein &mum, struct_mutagen mutation);
  Protein(int* seq, int len);
  Protein(const std::string& seq);

  ~Protein();
  int get_length() const {return _length;};
  int get_aa(int i) const{return _sequence[i];};
  void print() const;
  void dprint() const;
  Protein* next (){return _next;};
   Protein* previous(){return _previous;};
};

#endif
