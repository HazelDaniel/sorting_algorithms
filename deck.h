#ifndef ___DECK_
#define ___DECK_
#include <stdio.h>

/**
 * enum kind_e - Playing card names
 * @SPADE: spade card
 * @HEART: heart card
 * @CLUB: club card
 * @DIAMOND: diamond card
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
int convert_card(char *name);
void sort_deck(deck_node_t **deck);

/* UTILS */
int is_letter(char a);
int is_digit(char a);
#endif/*___DECK_*/
