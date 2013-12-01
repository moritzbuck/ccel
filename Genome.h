#ifndef _GENOME_H_
#define _GENOME_H_

class Gene;
class Protein;
class Chemspace;
struct struct_mutagen
{
double  cds_point_mutation_rate;
double  ncs_point_mutation_rate;
double  cds_indel_rate;
double ncs_indel_rate;
};


class Genome
{
  int  _gene_count;
  Gene** _gene;

 public:

  Genome();
  Genome(int gene_count, int len, int prot_len);
  Genome(const Genome&, struct_mutagen mutation);
  ~Genome();
  int  get_gene_count() const{return _gene_count;};
  void bind(const Protein& prot);
  void clear();
  Chemspace* refresh_content(Chemspace*);
  void print() const;
};

#endif
