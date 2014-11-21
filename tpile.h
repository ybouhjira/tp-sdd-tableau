#ifndef TPILE_H
#define TPILE_H

#include <assert.h>
#include "tliste.h"


typedef TListe TPile;

int tpile_depiler(TPile *p)
{
  assert(p->taille > 0);

  int n = p->valeurs[p->taille - 1];
  p->taille--;
  return n;
}


void tpile_empiler(TPile *p, int val)
{
  tliste_inserer(p, val, p->taille);
}

void tpile_afficher(TPile *p)
{
  TPile q = {{0}, 0};

  while(p->taille > 0)
    {
      int n = tpile_depiler(p);
      printf("%d ", n);
      tpile_empiler(&q, n);
    }
  printf("\n");

  while(q.taille > 0)
      tpile_empiler(p, tpile_depiler(&q));
}

#endif // TPILE_H
