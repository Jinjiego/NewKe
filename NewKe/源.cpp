
#include "stdafx.h"
#include<iostream>
using namespace std;
typedef char DataType;

class treeNode{
	DataType ch;
	treeNode *lchild;
	treeNode *rchild;

};

class Tree{
protected:
	treeNode*root;
	Tree(){
		root = NULL;
	};

	void insert(){};

};
