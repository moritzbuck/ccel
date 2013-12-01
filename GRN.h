#ifndef _GRN_H_
#define _GRN_H

class Genome;
class Protein;

class GRN
{

  Genome* _genome;
  Protein** _state;
  int _nb_protein;

 protected:

 public:

  GRN(Genome*);
  ~GRN();
  void update();

};

#endif
