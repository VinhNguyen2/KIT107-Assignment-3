/*
 *	Tree Node ADT
 *	Author: Vinh Nguyen (#470821)
 *	Version: May 2019
 *	
 *	This file holds the Tree Node ADT which represents
 *	the nodes in a doubly-linked general tree.  Tree
 *	nodes consist of a "data" field, a level number
 *	("level"), and two references to other nodes 
 *	(these being the child node ("child") and the
 *	next eldest sibling node ("sibling").
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "assig_three119.h"
#include "t_node.h"


//types
struct t_node_int
{
	void *data;		// the value stored in the node
	int level;		// the level of the current node
	t_node child;	// the eldest child node of the current node
	t_node sibling;	// the next eldest node of the current node
};


/*
	*	init_t_node
	*	Initialiser function
	*	Pre-condition: none
	*	Post-condition: the t_node variable holds the parameter value
	*					(o) within its "data" field, the parameter
	*					value (l) within its "level" field, and its
	*					"child", "sibling", and "parent" fields are
	*					null
	*	Informally: intialises the fields of the newly
	*				created t_node variable to hold the given parameters
	*				and to terminate the "child", "sibling", and
	*				"parent" fields
	*
	*	param o the value to store in the data field of the node
	*	param l the level number of the created node
*/
void init_t_node(t_node *tp, void *o, int l)
{
	//COMPLETE ME!
	trace("t_node: Initialiser begins");

	*tp = (t_node)malloc(sizeof(struct t_node_int));

	(*tp)->data = o;
	(*tp)->level = l;
	(*tp)->sibling = NULL;
	(*tp)->child = NULL;

	//set_t_node_data(*tp, o);
	//set_t_node_level(*tp, l);
	//set_t_node_child(*tp, NULL);
	//set_t_node_sibling(*tp, NULL);

	trace("t_node: Initialiser ends");

}


/*
	*	set_t_node_data
	*	Set function for "data" field.
	*	Pre-condition: none
	*	Post-condition: the t_node varable's data field is altered to
	*					hold the given (o) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "data" field
	*
	*	param o the variable to store in the data field of the node
*/
void set_t_node_data(t_node t, void *o)
{
	//COMPLETE ME!
	trace("set_t_node_data: set_t_node_data begins");

	t->data = o;

	trace("set_t_node_data: set_t_node_data ends");

}
	
	
/*
	*	set_t_node_level
	*	Set function for "level" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's level field is altered to
	*					hold the given (l) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "level" field
	*
	*	param l the level number of the node
*/
void set_t_node_level(t_node t, int l)
{
	//COMPLETE ME!
	trace("set_t_node_level: set_t_node_level begins");

	t->level = l;

	trace("set_t_node_level: set_t_node_level ends");

}
	
	
/*
	*	set_t_node_child
	*	Set function for "child" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's child field is altered
	*					to hold the given (n) value
	*	Informally: assign the value of the parameter to the t_node
	*				variable's "child" field
	*
	*	param n the node to set as the child of the current node
*/
void set_t_node_child(t_node t, t_node n)
{
	//COMPLETE ME!
	trace("set_t_node_child: set_t_node_child begins");

	t->child = n;

	trace("set_t_node_child: set_t_node_child ends");

}
	
	
/*
*	set_t_node_sibling
*	Set function for "sibling" field.
*	Pre-condition: none
*	Post-condition: the t_node variable's sibling field is altered
*					to hold the given (n) value
*	Informally: assign the value of the parameter to the t_node
*				variable's "sibling" field
*
*	param n the node to set as the sibling of the current node
*/
void set_t_node_sibling(t_node t, t_node n)
{
	//COMPLETE ME!
	trace("set_t_node_sibling: set_t_node_sibling begins");

	t->sibling = n;

	trace("set_t_node_sibling: set_t_node_sibling ends");

}


/*
	*	get_t_node_data
	*	Get function for "data" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's data field is returned
	*	Informally: examine the t_node variable's "data" instance
	*				variable returning its value
	*
	*	return variable the item in the node
*/
void *get_t_node_data(t_node t)
{
	//COMPLETE ME!
	trace("get_t_node_data: get_t_node_data begins and ends");

	return t->data;

}
	
	
/*
	*	get_t_node_level
	*	Get function for "level" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's level field is
	*				returned
	*	Informally: examine the t_node variable's "level" instance
	*				variable returning its value
	*
	*	return int the level number of the current node
*/
int get_t_node_level(t_node t)
{
	//COMPLETE ME!
	trace("get_t_node_level: get_t_node_level begins and ends");

	return t->level;

}
	
	
/*
	*	get_t_node_child
	*	Get function for "child" field.
	*	Pre-condition: none
	*	Post-condition: the t_node variable's child field is
	*					returned
	*	Informally: examine the t_node variable's "child"
	*				field returning its value
	*
	*	return t_node the child of the current node
*/
t_node get_t_node_child(t_node t)
{
	//COMPLETE ME!
	trace("get_t_node_child: get_t_node_child begins and ends");

	return t->child;
}
	
	
/*
*	get_t_node_sibling
*	Get function for "sibling" field.
*	Pre-condition: none
*	Post-condition: the t_node variable's sibling field is
*					returned
*	Informally: examine the t_node variable's "sibling"
*				field returning its value
*
*	return t_node the sibling of the current node
*/
t_node get_t_node_sibling(t_node t)
{
	//COMPLETE ME!
	trace("get_t_node_sibling: get_t_node_sibling begins and ends");

	return t->sibling;

}
