#ifndef _GENE_H_
#define _GENE_H_
#include <string>

class Protein;
class Gene
{
  
  int* _sequence;
  int* _occupation;
  int _length; 
  Protein* _product;
  struct struct_mutagen;
  
 public:
  
  Gene();
  ~Gene();
  Gene(const Gene & gene, struct_mutagen mutation);
  Gene(const std::string &seq, const std::string &prot);
  Gene(int length, int prot_len);
  void bind(const Protein & prot);
  void clear();
  void print() const;
  Protein get_product() const;  
  int is_active() const;
};

#endif
