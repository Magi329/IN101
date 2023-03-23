#ifndef __STATION_H__
#define __STATION_H__

#include <stdbool.h>

/** Noeud du graphe. Repr�sente une station. */
struct station_t {
  char *name ;  /** Nom de la station. */
  /** Liste des stations voisines imm�diates. */
  struct stations_list_t *neighbours ;
  /** Marqueur permettant de signaler que l'on a d�j� vu ce noeud lors d'un
      parcours. */
  bool seen ;
  struct station_t *prev_in_path ;
};

/** Liste cha�n�e de stations (de noeud du graphe). */
struct stations_list_t {
  struct station_t *station ;     /** Station de la cellule. */
  struct stations_list_t *next ;  /** �l�ment suivant de la liste. */
};

#endif
