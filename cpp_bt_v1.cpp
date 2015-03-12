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
int NoOfOddNodes(CPPtr hdTree);
int NoOfNodes(CPPtr hdTree);
int SumOfNodes(CPPtr hdTree);
CPPtr FindMin(CPPtr hdTree);
int idDepth(CPPtr hdTree, int id);
// Generate an instance of the structure
void constructStructure(CPPtr &hdTree);

int main(int argc, char ** argv)
{

	// Declare a pointer to the head of the tree
	CPPtr hdTree  = NULL;

	// Construct a tree structure.
	constructStructure(hdTree);

	// =================================
	// 1) Print number of nodes
    int nodenum = NoOfNodes(hdTree);
    cout << nodenum << endl;

    // 2) Print number of nodes with an odd data field
    int oddnodenum = NoOfOddNodes(hdTree);
    cout << oddnodenum << endl;

    // 3) Print id and data fields of node with minimum data value
	CPPtr outPtr = FindMin(hdTree);
	if(outPtr == NULL) {
	    cout << "Tree empty, therefore no minimum." << endl;
	}
	else {
        cout << "id: " << outPtr->id << "\t data: " << outPtr->data << endl;
	}

	// 4) Print sum of all data in the tree
	int datasum = SumOfNodes(hdTree);
	cout << datasum << endl;
    // =================================

	int id = 8;
	int iddepth = idDepth(hdTree, id);
	cout << iddepth << endl;
    // Just to freeze the console window (not always necessary)
    // getchar();

    return 0;
}

int SumOfNodes(CPPtr hdTree) {
    if(hdTree == NULL) {
        return 0;
    }
    else {
        return (hdTree->data + SumOfNodes(hdTree->left) + SumOfNodes(hdTree->right));
    }
}

int NoOfNodes(CPPtr hdTree) {
    if(hdTree == NULL) {
        return 0;
    }
    else {
        return (1 + NoOfNodes(hdTree->left) + NoOfNodes(hdTree->right));
    }
}

int NoOfOddNodes(CPPtr hdTree) {
    if(hdTree == NULL) {
        return 0;
    }
    else if((hdTree->data)%2 == 1){
        return (1 + NoOfOddNodes(hdTree->left) + NoOfOddNodes(hdTree->right));
    }
    else {
        return (NoOfOddNodes(hdTree->left) + NoOfOddNodes(hdTree->right));
    }
}

CPPtr FindMin(CPPtr hdTree) {
    if(hdTree == NULL) {
        return NULL;
	}
    if(hdTree->left) {
        return FindMin(hdTree->left);
	}
    return hdTree;
}

int idDepth(CPPtr hdTree, int id)
{
    if(hdTree->id == id) {
        return 1;
	}
    else if(hdTree != NULL) {
		idDepth(hdTree->left, id);
		idDepth(hdTree->right, id);
	}
    return 0;

}


bool balanceCheck(CPPtr hdTree) {

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
