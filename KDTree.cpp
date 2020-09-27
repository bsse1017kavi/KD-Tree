#include<bits/stdc++.h>
using namespace std;

const int dimension = 2;

struct Node
{
    int coords[dimension];
    Node *left, *right;
};

struct Node* newNode(int *arr)
{
    struct Node* temp = new Node;

    for (int i=0; i<dimension; i++)
       temp->coords[i] = arr[i];

    temp->left = temp->right = NULL;
    return temp;
};

Node *insertRec(Node *root, int coords[], unsigned depth)
{
    if (root == NULL)
       return newNode(coords);

    unsigned cd = depth % dimension;

    if (coords[cd] < (root->coords[cd]))
        root->left  = insertRec(root->left, coords, depth + 1);
    else
        root->right = insertRec(root->right, coords, depth + 1);

    return root;
}

Node* insert(Node *root, int coords[])
{
    return insertRec(root, coords, 0);
}

void printNode(Node *node)
{
    cout << "(";

    for(int i=0;i<dimension;i++)
    {
        if(i>0)
            cout << ",";

        cout << node->coords[i];
    }

    cout << ") ";
}

bool compareCoords(int coords1[], int coords2[])
{
    for(int i=0;i<dimension;i++)
    {
        if(coords1[i]!=coords2[i])
            return false;
    }

    return true;
}

bool searchRec(Node* root, int coords[], unsigned depth)
{
    if(root == NULL)
    {
        return false;
    }

    if(compareCoords(root->coords, coords))
    {
        return true;
    }

    unsigned cd = depth % dimension;

    if(coords[cd] < root->coords[cd])
    {
        return searchRec(root->left, coords, depth+1);
    }

    return searchRec(root->right, coords, depth+1);

}

bool search(Node *root, int coords[])
{
    return searchRec(root, coords, 0);
}

void traverse(Node *node)
{
    if(node!=NULL)
    {
        printNode(node);
        traverse(node->left);
        traverse(node->right);
    }
}

int main(void)
{
    struct Node *root = NULL;
    int points[][dimension] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};

    int n = sizeof(points)/sizeof(points[0]);

    for (int i=0; i<n; i++)
       root = insert(root, points[i]);

    traverse(root);

    cout << endl;

    int point1[] = {10, 19};
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n";

    int point2[] = {12, 19};
    (search(root, point2))? cout << "Found\n": cout << "Not Found\n";

    return 0;
}
