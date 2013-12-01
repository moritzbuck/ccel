#ifndef _CHEMSPACE_H_
#define _CHEMSPACE_H_


class Protein;

class Chemspace
{
  
  Protein**  _content;
  int  _nb_prots;
  
 public:
  
 
  Chemspace(int len);
  ~Chemspace();
  int size();
  Protein get(int idx);
  void set(int idx, Protein chem);
  void print();
};

#endif
