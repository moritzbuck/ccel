#include "Genome.h"
#include "Ccel.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(void)
{
  Genome* fuuu = new Genome(50,1000,5);
  Ccel* baby=new Ccel(fuuu);
  baby->print();

  for(int i=0; i< 100000; i++)
    {
      baby->update();
      baby->print();
    }

  delete baby;
  return 1;
}
