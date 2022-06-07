/*
 *	Game Tree ADT Implementation
 *	Author: Vinh Nguyen (#470821)
 *	Version: May 2019
 *	
 *	This file holds the game_tree ADT which is a
 *	general game tree.  The game_tree is built using
 *	t_node ADTs.  A game_tree variable consists of a
 *	"root" field which refers to a t_node variable
 *	which has a "data" field and "child" and
 *	"sibling" references, and a "level" value.
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_node.h"
#include "game_state.h"
#include "game_tree.h"
#include "assig_three119.h"


// types
struct game_tree_int
{
	t_node root;			// the node at the top of the tree
};


// global variable
int thought = 0;	// to show 'thinking' -- i.e. that the program hasn't crashed


/*
	*	init_game_tree
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: if the parameter value (e) is true then the 
	*					game_tree variable's "root" field is set to NULL
	*					otherwise the game_tree variable's "root" field
	*					refers to a new t_node variable containing the
	*					parameter value (o) of level with parameter 
	*					value (l) with a NULL child, and a NULL sibling
	*	Informally: creates either an empty tree or a leaf node as
	*				required
*/
void init_game_tree(game_tree *tp,bool e,void *o,int l)
{
	trace("game_tree: initialiser starts");

	t_node n; // new t_node
	*tp=(game_tree)malloc(sizeof(struct game_tree_int));
	if (e)
	{
		(*tp)->root = NULL; 
	}
	else
	{
		init_t_node(&n, o, l);
		(*tp)->root = n;
	}
		
	trace("init_game_tree: init_game_tree ends");
}
	
	
/*
	*	is_empty_game_tree
	*	Emptiness test.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: true is returned if the game_tree variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the game_tree contains no nodes
	*
	*	return boolean whether or not the game tree is empty
*/
bool is_empty_game_tree(game_tree t)
{
	//COMPLETE ME!
	trace("is_empty_game_tree: is_empty_game_tree starts and ends");
	
	if (t == NULL)
	{
		fprintf(stderr, "is_empty_game_tree: game tree is null\n");
		exit(1);
	}
	
	return (t->root == NULL);

}


/**
	*	get_data
	*	Get function for "root" instance variable's data value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field is returned
	*	Informally: return the value within the root node
	*
	*	return void * the data item of the root node
*/
void *get_data(game_tree t)
{
	trace("get_data: get_data starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr,"get_data: empty game tree");
		exit(1);
	}

	trace("get_data: get_data ends");
	return get_t_node_data(t->root);
}
	
	
/*
	*	get_level
	*	Get function for "root" instance variable's level value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field's level is returned
	*	Informally: return the level value within the root node
	*
	*	return int the level number of the root node
*/
int get_level(game_tree t)
{
	//COMPLETE ME!
	trace("get_level: get_level starts");

	// Because there is no pre-condition, exit when t is null or empty.
	if (t == NULL || is_empty_game_tree(t))
	{
		fprintf(stderr, "get_level: game tree is empty or null\n");
		exit(1);
	}

	trace("get_level: get_level ends");

	return get_t_node_level(t->root);

}
	

/*
*	get_child
*	Get function for "root" instance variable's child value.
*	Pre - condition: the game_tree variable is defined and valid
*	Post - condition : the value of the game_tree variable's child
*					field is returned in a newly
*					constructed game_tree variable
*	Informally : return the game_tree variable's child
*
*	return game_tree the eldest child of the current node
*/
game_tree get_child(game_tree t)
{
	game_tree c;

	trace("get_child: get_child starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_child: empty game tree");
		exit(1);
	}

	init_game_tree(&c, true, NULL, -1);
	c->root = get_t_node_child(t->root);

	trace("get_child: get_child ends");
	return c;
}


/*
	* 	get_sibling
	*	Get function for "root" instance variable's sibling value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's sibling
	*					field is returned in a newly constructed 
	*					game_tree variable
	*	Informally: return the game_tree variable's sibling
	*
	*	return game_tree the next sibling of the current node
*/
game_tree get_sibling(game_tree t) 
{
	//COMPLETE ME!
	game_tree s;	// The new tree containing t's sibling. 
	trace("get_sibling: get_sibling starts");

	if (t == NULL || is_empty_game_tree(t))
	{
		fprintf(stderr, "get_sibling: game tree is empty or null\n");
		exit(1);
	}

	
	init_game_tree(&s, true, NULL, -1);
	s->root = get_t_node_sibling(t->root);

	trace("get_sibling: get_sibling ends");

	return s ;


}


/*
	*	set_data
	*	Set function for "root" instance variable's data field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's data field is altered to
	*					hold the given (o) value
	*	Informally: store the given value in the root node of the
	*				game_tree variable
	*
	*	param o void * to install as data for root node
*/
void set_data(game_tree t,void *o)
{
	trace("set_data: set_data starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr,"set_data: empty game tree");
		exit(1);
	}
		
	set_t_node_data(t->root,o);
		
	trace("set_data: set_data ends");
}
		
	
/*
	*	set_level
	*	Set function for "root" instance variable's level field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's level field is altered
	*					to hold the given (l) value
	*	Informally: assign the given value as the level of the
	*				game_tree variable
	*
	*	param l level number for root of current game tree
*/
void set_level(game_tree t,int l)
{
	//COMPLETE ME!
	trace("set_level: set_level starts");

	if (t == NULL || is_empty_game_tree(t))
	{
		fprintf(stderr, "set_level: game tree is empty or null\n");
		exit(1);
	}

	set_t_node_level(t->root, l);

	trace("set_level: set_level ends");

}
	
	
/*
	*	set_child
	*	Set function for "root" instance variable's child field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's child field is altered
	*					to hold the given (c) value
	*	Informally: assign the given value as the child of the
	*				game_tree variable
	*
	*	param c game_tree to be set as eldest child of current game tree
*/
void set_child(game_tree t, game_tree c)
{
	//COMPLETE ME!
	trace("set_child: set_child starts");

	if (t == NULL || is_empty_game_tree(t))
	{
		fprintf(stderr, "set_child: game tree is empty or null\n");
		exit(1);
	}

	set_t_node_child(t->root, c->root);

	trace("set_child: set_child ends");

}


/*
	*	set_sibling
	*	Set function for "root" instance variable's sibling field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's sibling field is altered
	*					to hold the given (s) value
	*	Informally: assign the given value as the sibling of the
	*				game_tree variable
	*
	*	param s game_tree to be set as next sibling of current game tree
*/
void set_sibling(game_tree t,game_tree s)
{
	//COMPLETE ME!
	trace("set_sibling: set_sibling starts");

	if (t == NULL || is_empty_game_tree(t))
	{
		fprintf(stderr, "set_sibling: game tree is empty or null\n");
		exit(1);
	}

	set_t_node_sibling(t->root, s->root);

	trace("set_sibling: set_sibling ends");

}
	
	
/*  
*	generate_levelBF
*	Generate the next level of the tree in a breadth-first manner
*	Pre-condition: the given tree is defined, the given queue
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the queue.
*	Informally: generate the next level of the game tree
*
*	param q Queue of reachable but unexpanded game trees
*/
void generate_levelBF(game_tree t, queue q)
{
	//COMPLETE ME!
	
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves

	
	/*
	const int HORIZ_MOVES[] = { -1, 0, +1, 0 };	// moves left/right
	const int VERT_MOVES[] = { 0, -1, 0, 1 };	// moves up/down
	const int MOVE_COUNT = 4; // number of potential moves
	*/
	const int START_OF_ARRAY = 0;	//first element of an array

	int cur_r, cur_c;	//current row and current column
	int new_r, new_c;	//updated to new row and column possibilities
	int test_move;	//used in for loop to step through possible moves

	game_tree *current_gameTree;
	game_tree previous_gameTree;
	game_tree parent_gameState, current_gameState;
	bool no_siblings = true;
	int new_level;	//updated to be the level of children generated relative to root of tree

	trace("generate_levelBF: generate_levelBF starts");	//for debug purposes only. 

	//fetch game state to generate children out of gameTree passed in and generate the level of children
	parent_gameState = (game_tree)(get_data(t));
	new_level = get_level(t);
	new_level++;

	//update current row & col to location of Queen
	cur_r = get_row(parent_gameState); 
	cur_c = get_column(parent_gameState); 

	trace("generate_levelBF:showing parent_gameState:");	//for debug purposes only. 

	//loop though every possible move
	for (test_move = START_OF_ARRAY; test_move < MOVE_COUNT; test_move++)
	{
		//update new location to where knight could theoretically move (before considering its validity)
		new_r = cur_r + VERT_MOVES[test_move];
		new_c = cur_c + HORIZ_MOVES[test_move];
		
		//test to see if new location is legal & valid
		if (valid(parent_gameState, new_r, new_c))
		{
			//play is on the board
			trace("generateLevelBF: new location on board");	//for debug purposes only.
			if (!taken(parent_gameState, new_r, new_c) && clash(parent_gameState, new_r, new_c))
			{
				//the Queen has not visited this location before, thus move is valid and legal

				//clone the new game state based on the gameTree passed in.
				current_gameState = clone(parent_gameState);

				//create a game tree containing the new game state
				current_gameTree = malloc(sizeof(game_tree));	//creates new space in memory for pointer
				init_game_tree(current_gameTree, false, current_gameState, new_level);

				// sibling & children

				//the new game tree just created parent will always be the game tree passed if
				//setParent(*current_gameTree, t);

				//if this is the first child generated from this parent it is unsure if it will have siblings
				//given the way this tree works the left most child is the the only child referred to in parents child data field
				if (no_siblings)
				{
					//first child generated

					//set the parents child
					set_child(t, *current_gameTree);

					no_siblings = false;	//stops future loops from entering this section of code
				}
				else
				{
					//not the first child generated

					//previous tree generated sibling is the current tree, update to represent this
					set_sibling(previous_gameTree, *current_gameTree);
				}


				//add game tree to queue to be processed in the future
				add(q, *current_gameTree);

				//change name of current game tree to previous game tree for future loops
				previous_gameTree = *current_gameTree;

				trace("generate_levelBF:showing new_gameState:");	//for debug purposes only. 
			}
		}
	}

	trace("generate_levelBF: generate_levelBF ends");	//for debug purposes only. 
}


/*
*	build_gameBF
*	Generate the game tree in a breadth-first manner
*	Pre-condition: the given queue and game tree are defined, and
*				   the given int value represents the desired depth
*				   of the tree
*	Post-condition: If the given tree isn't already deep enough, an
*					additional level of possible moves is added to
*					the given game tree and each tree node of the
*					new level also is added to the queue.
*					Finally, the next tree is determined by removing
*					the front of the queue and the process continues
*					until the queue is empty
*	Informally: generate the game tree from the current point
*				in a breadth-first manner until it is "d" levels
*				deep
*
*	param q Queue of reachable but unexpanded game trees
*	param d desired depth (number of queens) that game tree should be built to
*	return	the game tree with the first found solution, or an empty game
*			tree if there is no solution
*/
game_tree build_gameBF(game_tree t, queue q, int d)
{
	//COMPLETE ME!
	game_tree c;	//updated through loop to current gameTree to be worked on

	trace("build_gameBF: build_gameBF starts");	//for debug purposes only.
	init_game_tree(&c, true, NULL, -1);	//allocate enough memory for c to hold a game tree

	c = t;	//initially work on the game tree passed in

	//so that we dont rear an empty queue add the first tree the queue
	add(q, t);

	//generate children from the gameTree at the ends of the queue then add those children to the queue
	//continue to do this until either:
	//			the queue is empty (meaning no more children can be generated (likely no solution can be found))
	//			enough moves have been generated to find a solution.
	while ((!(is_empty_queue(q))) && (get_level(c) < DIMENSION))
	{

		//remove last gameTree from top of queue
		rear(q);




		//generate children and add them to queue
		generate_levelBF(c, q);

		//update c to equal the front of the queue
		if (!(is_empty_queue(q)))
		{
			c = (game_tree)(front(q));
		}
	}

	//check if a solution has been found.
	if (get_level(c) < DIMENSION)
	{
		//no solution found so update c to have a NULL data field
		init_game_tree(&c, true, NULL, -1);
	}

	trace("build_gameBF: build_gameBF ends");	//for debug purposes only. 

	//returns leaf node of tree containing full solution or NULL value if no solution (of type gameTree)
	return c;

}


/*
*	generate_levelDF
*	Generate the next level of the tree in a depth-first manner
*	Pre-condition: the given tree is defined, the given stack
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the stack.
*	Informally: generate the next level of the game tree
*
*	param q Stack of reachable but unexpanded game trees
*/
void generate_levelDF(game_tree t, stack s)
{
	//COMPLETE ME!
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves

	const int START_OF_ARRAY = 0;	//first element of an array

	int cur_r, cur_c;	//current row and current column
	int new_r, new_c;	//updated to new row and column possiblities
	int test_move;	//used in for loop to step through possible moves
	int step;
	step = 0;
	game_tree *current_gameTree;
	game_tree previous_gameTree;
	game_state parent_gameState, current_gameState;
	bool no_siblings = true;
	int new_level;	//updated to be the level of children generated relative to root of tree

	trace("generate_levelDF: generate_levelDF starts");	//for debug purposes only.

	//fetch game state to generate children out of gameTree passed in and generate the level of children
	parent_gameState = (game_state)(get_data(t));
	new_level = get_level(t);
	new_level++;

	//update current row & col to location of Queen
	cur_r = get_row(parent_gameState);
	cur_c = get_column(parent_gameState);

	trace("generate_levelDF:showing parent_gameState:");	//for debug purposes only. 

	//loop though every possible move
	for (test_move = START_OF_ARRAY; test_move < MOVE_COUNT; test_move++)
	{
		//update new location to where Queen could theoretically move (before considering its validity)
		new_r = cur_r + VERT_MOVES[test_move];
		new_c = cur_c + HORIZ_MOVES[test_move];

		//test to see if new location is legal & valid
		if (valid(parent_gameState, new_r, new_c))
		{
			//play is on the board
			trace("generateLevelDF: new location on board");	//for debug purposes only. 
			if (!taken(parent_gameState, new_r, new_c))
			{
				//the Queen has not visited this location before, thus move is valid and legal

				//clone the new game state based on the gameTree passed in.
				current_gameState = clone(parent_gameState);

				//create a game tree containing the new gamestate
				current_gameTree = malloc(sizeof(game_tree));	//creates new space in memory for pointer
				init_game_tree(current_gameTree, false, current_gameState, new_level);

				//set sibling & children

				//the new game tree just created parent will always be the game tree passsed if
				//setParent(*current_gameTree, t);

				//if this is the first child generated from this parent it is unsure if it will have siblings
				//given the way this tree works the left most child is the the only child reffered to in parents child data field
				if (no_siblings)
				{
					//first child generated

					//set the parents child
					set_child(t, *current_gameTree);

					no_siblings = false;	//stops future loops from entering this section of code
				}
				else
				{
					//not the first child generated

					//previous tree generated sibling is the current tree, update to represent this
					set_sibling(previous_gameTree, *current_gameTree);
				}
				//add game tree to stack to be processed in the future
				push(s, *current_gameTree);

				//change name of current game tree to previous game tree for future loops
				previous_gameTree = *current_gameTree;

				trace("generateLevelDF:showing new_gameState:");	//for debug purposes only. function in assig_three115.c
			}
		}
	}

	trace("generate_levelDF: generate_levelDF ends");	//for debug purposes only. 

}


/*
*	build_gameDF
*	Generate the game tree in a depth-first manner
*	Pre-condition: the given stack and game tree are defined, and
*				   the given int value represents the desired depth
*				   of the tree
*	Post-condition: If the given tree isn't already deep enough, an
*					additional level of possible moves is added to
*					the given game tree and each tree node of the
*					new level also is pushed onto the stack.
*					Finally, the next tree is determined by removing
*					the top of the stack and the process continues
*					until the stack is empty
*	Informally: generate the game tree from the current point
*				in a depth-first manner until it is "d" levels
*				deep
*
*	param s Stack of reachable but unexpanded game trees
*	param d desired depth (number of queens) that game tree should be built to
*	return	the game tree with the first found solution, or an empty game
*			tree if there is no solution
*/
game_tree build_gameDF(game_tree t, stack s, int d)
{
	//COMPLETE ME!

	game_tree c;	//updated through loop to current gameTree to be worked on

	trace("build_gameDF: build_gameDF starts");	//for debug purposes only. 

	init_game_tree(&c, true, NULL, -1);	//allocate enough memory for c to hold a game tree

	c = t;	//initialy work on the game tree passed in

	//so that we dont pop an empty stack add the first tree the stack
	push(s, t);

	//generate children from the gameTree at the top of the stack then add those children to the stack
	//continue to do this until either:
	//			the stack is empty (meaning no more children can be generated (likely no solution can be found))
	//			enought moves have been generated to find a solution.
	while ((!(is_empty_stack(s))) && (get_level(c) < DIMENSION))
	{
		//remove last gameTree from top of stack
		pop(s);

		//generate children and add them to stack
		generate_levelDF(c, s);

		//update c to the top of the stack
		if (!(is_empty_stack(s)))
		{
			c = (game_tree)(top(s));
		}
	}

	//check if a solution has been found.
	if (get_level(c) < DIMENSION)
	{
		//no solution found so update c to have a NULL data field
		init_game_tree(&c, true, NULL, -1);
	}

	trace("buildGameDF: buildGameDF ends");	//for debug purposes only. 

	//returns leaf node of tree containing full solution or NULL value if no solutuon (of type gameTree)
	return c;

}


/*
	*	to_string_game_tree
	*	String conversion for tree
	*	Pre-condition: none
	*	Post-condition: a string variable is returned consisting of the
	*				string representation of all items in the game_tree,
	*				from top to bottom in depth-first order, separated by
	*				" " and contained within "<" and ">"
	*	Informally: produce a string representation of the game tree
	*
	*	return (char *) printable contents of game tree
*/
char *to_string_game_tree(game_tree t)
{
	game_tree c;
	char *s;

	trace("to_string_game_tree: to_string_game_tree starts");
		
	if (is_empty_game_tree(t))
	{
		trace("to_string_game_tree: to_string_game_tree ends");
		return "<>";
	}
	else
	{
		s=(char *)malloc(200*5*sizeof(char));

		sprintf(s,"%s (%d,%d) ",s,get_row(get_data(t)),get_column(get_data(t)));
		c=get_child(t);
		if (! is_empty_game_tree(c))
		{
			sprintf(s,"%s %s ",s,to_string_game_tree(c));
		}
		c=get_sibling(t);
		if (! is_empty_game_tree(c))
		{
			sprintf(s,"%s %s ",s,to_string_game_tree(c));
		}
	}

	trace("to_string_game_tree: to_string_game_tree ends");

	return s;
}

