#ifndef TLISTE_H
#define TLISTE_H

#include <assert.h>

#define MAX 100
typedef struct TListe {
  int valeurs[MAX];
  int taille;
}TListe;

/*
 * Entrées
 *  l : tableau
 *  val : valeur
 *  pos : pos
 * Description
 *  Insere la valeur val dans la position pos
 */
void tliste_inserer(TListe *l, int val, int pos)
{
  assert(!((pos < 0) || (pos > l->taille)));
  assert(l->taille < MAX);

  // Decalage
  int i;
  for (i = l->taille; i > pos ; --i)
    l->valeurs[i] = l->valeurs[i - 1];

  l->valeurs[pos] = val;
  l->taille++;
}

/*
 * Entrees
 *  l : tableau
 *  pos : La position de suppression
 * Description
 *  Supprime la valeur dans la position pos
 */
void tliste_supprimer(TListe *l, int pos)
{
  assert(!((pos < 0) || (pos > l->taille - 1)));

  // Decalage
  int i;
  for (i = pos; i < l->taille - 1 ; ++i)
    l->valeurs[i] = l->valeurs[i + 1];

  l->taille--;

}

/*
 * Entrées:
 *    t : tableau
 *    val : valeur à rechercher
 * Decription:
 *    Retourne la premier position dans laquelle se trouve la valeur ou -1 si
 * elle n'est pas trouvée.
 */
int tliste_recherche(TListe t, int val)
{
  int i;
  for (i = 0; i < t.taille; ++i)
      if(t.valeurs[i] == val) return i;
  return -1;
}

/*
 * Affiche un tableau
 */
void tliste_afficher(TListe l)
{
  int i;
  printf("[");
  for (i = 0; i < l.taille; ++i)
    {
      printf("%d", l.valeurs[i]);
      if(i != l.taille - 1) printf(", ");
    }
  printf("]\n");
}
#endif // TLISTE_H
