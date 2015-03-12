/*
	EE1-08 Software Engineering 1: Algorithms and data structures 
	Assignment 2 - Binary Trees
	
	Name: Ravi Woods
	Email: rbw14@ic.ac.uk
	Login: rbw14
	CID: 00939309 
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

// Declare the data structure
struct CP {
	int id;			// id of the node
	int data;		// data of the node
	CP * left;		// pointer to the left subtree
	CP * right;		// pointer to the right subtree
};

typedef CP * CPPtr;

// Function prototypes
int CountNodes(CPPtr hdTree);
int CountOddNodes(CPPtr hdTree);
CPPtr FindMinNode(CPPtr hdTree);
int FindSumOfNodes(CPPtr hdTree);
int FindDepthofID(CPPtr hdTree, int id, int depth, bool& found);
bool CheckBalance(CPPtr hdTree);
int FindHeight(CPPtr hdTree);

// Generate an instance of the structure
void constructStructure(CPPtr &hdTree);

int main(int argc, char ** argv){

	// Declare a pointer to the head of the tree
	CPPtr hdTree  = NULL;

	// Construct a tree structure.
	constructStructure(hdTree);

	// ====================== TESTING FUNCTIONS ======================
	// 1) Print number of nodes
    int nodesum = CountNodes(hdTree);
    cout << "There are " << nodesum << " nodes in the tree." << endl;

    // 2) Print number of nodes with an odd data field
    int oddnodesum = CountOddNodes(hdTree);
    cout << "There are " << oddnodesum << " nodes in the tree with an odd data field." << endl;

    // 3) Print id and data fields of node with minimum data value
	CPPtr outPtr = FindMinNode(hdTree);
	if(outPtr == NULL) {
	    cout << "Tree empty, therefore no minimum." << endl;
	}
	else {
		cout << "For the node with minimum data value, " << "id = " << outPtr->id << " and data = " << outPtr->data << "." << endl;
	}

	// 4) Print sum of all data in the tree
	int datasum = FindSumOfNodes(hdTree);
	cout << "Sum of all data fields is " << datasum << "." << endl;

	// 5) Takes in id as a command line argument, and prints the depth of that id (or an error if id is not found).
	int id = argc;
	int depth = 0;
	bool found = false;
	int iddepth = FindDepthofID(hdTree, id, depth, found);
	if(found) {
		cout << "Depth of node with id = " << id << " is " << iddepth << "." <<  endl;
	}
	else {
		cout << "No node with id = " << id << "." << endl;
	}

	// 6) Prints message, saying whether tree is balanced or not.
	bool balanced = CheckBalance(hdTree);
	if(balanced) {
		cout << "Tree is balanced." << endl;
	}
	else {
		cout << "Tree isn't balanced." << endl;
	}

    // ============================================================

    // Just to freeze the console window (not always necessary)
    // getchar();

    return 0;
}

//Function returns the number of nodes in the tree.
int CountNodes(CPPtr hdTree) {
	
	//Base case: If node is NULL, not in final count so return zero.
    if(hdTree == NULL) {
        return 0;
    }
	//General case: If node not NULL, add one to the count, plus add the counts of each subtree.
    else {
        return (1 + CountNodes(hdTree->left) + CountNodes(hdTree->right));
    }
}

//Function returns the number of nodes in the tree with an odd data field.
int CountOddNodes(CPPtr hdTree) {

	//Base case: If tree is NULL, not in final count so return zero.
    if(hdTree == NULL) {
        return 0;
    }
	//If node is odd, add one to the count, plus add the counts of each subtree.
    else if((hdTree->data)%2 == 1){
        return (1 + CountOddNodes(hdTree->left) + CountOddNodes(hdTree->right));
    }
	//If node is even, just add the counts of each subtree.
    else {
        return (CountOddNodes(hdTree->left) + CountOddNodes(hdTree->right));
    }
}

//Function returns a pointer to a node with the lowest data field.
CPPtr FindMinNode(CPPtr hdTree) {

	//Exception: If tree is NULL, return NULL pointer.
    if(hdTree == NULL) {
        return NULL;
	}
	//General Case: If left subtree is not empty, return the minimum of the left subtree. 
    if(hdTree->left != NULL) {
        return FindMinNode(hdTree->left);
	}
	
	//Base Case: Once empty left subtree has been found, return this pointer. 
	//This gives the bottom left element of the tree - the minimum as the tree is ordered.
    return hdTree;
}

//Function returns the sum of the data fields of the tree.
int FindSumOfNodes(CPPtr hdTree) {

	//Base case: If tree is NULL, no data field - so return zero.
    if(hdTree == NULL) {
        return 0;
    }
	//General case: If node not NULL, add data field of current node, plus add the counts of each subtree.
    else {
        return (hdTree->data + FindSumOfNodes(hdTree->left) + FindSumOfNodes(hdTree->right));
    }
}

//Function returns the depth of a node with a given id.
int FindDepthofID(CPPtr hdTree, int id, int depth, bool& found) {
	//Exception: If tree is empty, depth is -1 by convention.
    if (hdTree == NULL) {
        return -1;
    }
	
	//Base Case: Once correct node found, note this and return depth.
    if (hdTree->id == id) {
		found = true;
        return depth;
    }
	//General Case: If correct node not found, increment depth and return the maximum depth of the two subtrees.
	//Since one will be -1, and the other will be the correct depth, it will always return  the correct depth.
    else {
		depth++;
		return (max(FindDepthofID(hdTree->left, id, depth, found), FindDepthofID(hdTree->right, id, depth, found)));
	}
}

//Function returns a boolean, denoting whether the tree is balanced or not.
bool CheckBalance(CPPtr hdTree) {
	//Base Case: Return true once end of tree reached.
	if(hdTree == NULL) {
		return true;
	}
	//General Case: 
	//First, find whether difference in height of two subtrees is less than or equal to 1.
	//Return true if and only if this is the case, and both subtrees are also balanced.
	else {
		bool heightdifference = false;
		if(abs(FindHeight(hdTree->left)-FindHeight(hdTree->right)) <= 1) {
			heightdifference = true; 
		}
		return(CheckBalance(hdTree->left) && CheckBalance(hdTree->right) && heightdifference);
	}
}

//Function returns the height of a tree.
int FindHeight(CPPtr hdTree) {
	//Base Case: If tree is NULL, depth is -1 by convention.
	if(hdTree == NULL) {
		return -1;
	}
	//General Case: Return the maximum height of the two subtrees, plus one.
	else {
		return (1 + max(FindHeight(hdTree->left), FindHeight(hdTree->right)));
	}

}

//The function generates an instance of the structure (the same as in the description of the assignement document). 
//The SP pointer points to the head of the tree
void constructStructure(CPPtr &SP){
    
    // Declare a structure with 5 nodes
    CPPtr SP0 = NULL;
    CPPtr SP1 = NULL;
    CPPtr SP2 = NULL;
    CPPtr SP3 = NULL;
    CPPtr SP4 = NULL;
    CPPtr SP5 = NULL;
    
    // build the structure tree
    // State 0
    SP0 = new CP;
    SP0->id = 1;
    SP0->data = 10;
    SP0->left = NULL;
    SP0->right = NULL;
    
    // State 1
    SP1 = new CP;
    SP1->id = 4;
    SP1->data = 5;
    SP1->left = NULL;
    SP1->right = NULL;
    
    // State 2
    SP2 = new CP;
    SP2->id = 8;
    SP2->data = 3;
    SP2->left = NULL;
    SP2->right = NULL;
    
    // State 3
    SP3 = new CP;
    SP3->id = 6;
    SP3->data = 7;
    SP3->left = NULL;
    SP3->right = NULL;
    
    // State 4
    SP4 = new CP;
    SP4->id = 5;
    SP4->data = 10;
    SP4->left = NULL;
    SP4->right = NULL;


    // Make the connections
    SP0->left = SP1;
    SP0->right = SP4;
    SP1->left = SP2;
    SP1->right = SP3;
    
    // Make the head pointer to point to the head of the tree
    SP = SP0;
}
