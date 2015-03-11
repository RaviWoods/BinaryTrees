#include <iostream>
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

// Generate an instance of the structure
void constructStructure(CPPtr &hdTree);

int main(int argc, char ** argv)
{

	// Declare a pointer to the head of the tree
	CPPtr hdTree  = NULL;
	
	// Construct a tree structure. 
	constructStructure(hdTree);

	// =================================
	// Your functions should go here
    
    
        
    // =================================
    
    // Just to freeze the console window (not always necessary)
    // getchar();
     
    return 0;
}



// The function generates an instance of the structure (the same as in the description of the assignement document). The SP pointer
// points to the head of the tree
void constructStructure(CPPtr &SP){
    // Declare a structure with 5 nodes
    
    
    CPPtr SP0 = NULL;
    CPPtr SP1 = NULL;
    CPPtr SP2 = NULL;
    CPPtr SP3 = NULL;
    CPPtr SP4 = NULL;
    
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