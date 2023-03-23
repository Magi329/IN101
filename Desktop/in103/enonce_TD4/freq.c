#include <stdio.h>
#include <stdlib.h>



/** \brief Calcul du nombre d'occurrences par caract�res dans le contenu d'un
    fichier. La table obtenue est de taille 256, avec une entr�e par caract�re,
    et index�e sur le code ASCII des caract�res.
    \param fname : Nom du fichier � analyser.
    \return Table du nombre d'occurrence ce chaque caract�re dans le fichier
    analys� ou NULL si une erreur s'est produite. La lib�ration de cette table
    est � faire par appel � un simple free de la stdlib C. */
unsigned int* get_occs_table (char *fname)
{
  unsigned int *tbl ;
  int c ;

  FILE *in = fopen (fname, "rb") ;
  if (in == NULL) {
    printf ("Error. Unable to open file '%s'.\n", fname) ;
    return (NULL) ;
  }

  /* Allocation avec mise � z�ro de chaque octet directement. Ca �vite d'�crire
     soit m�me la boucle qui s'en charge. */
  tbl = calloc (256, sizeof (unsigned int)) ;
  if (tbl == NULL) {
    fclose (in) ;
    return (NULL) ;
  }

  c = fgetc (in) ; //return ascii
  while (c != EOF) {
    tbl[c]++ ;
    c = fgetc (in) ;
  }

//Soit un octet à correctement été lu, et dans ce cas sa valeur vous est retournée (entre 0 et 255), soit une erreur c'est produite et dans ce cas la valeur EOF vous sera retournée. Cela donne 257 valeurs différentes pouvant être renvoyées : cela explique que le type de retour soit int plutôt que unsigned char.

  fclose (in) ;
  return (tbl) ;
}
