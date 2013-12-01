#ifndef _CCEL_H_
#define _CCEL_H_

class Genome;
class Chemspace;
class Protein;


class Ccel
{
 protected:
  Genome* _genome;
  Chemspace* _chemspace;
  
 public:
  Ccel(Genome *);
  ~Ccel();
  void update();
  void print()const;
};

#endif
