#include <stdio.h>
#include "tpile.h"

int main(void)
{

  TPile p = {{0}, 0};
  tpile_empiler(&p, 1);
  tpile_empiler(&p, 2);
  tpile_empiler(&p, 3);
  tpile_empiler(&p, 4);

  tpile_afficher(&p);
  return 0;
}

