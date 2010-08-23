/*
 *  danceBattle.cpp
 *  
 *
 *  Created by Suprita Pagad on 8/22/10.
 *  Copyright 2010 UCSD. All rights reserved.
 *
 */

#include <iostream>
#include <fstream>
#include "danceBattle.h"

using namespace std;

void main (int argc, char *argv[]) {
	ArrayType movesArray;
	Node* rootNode;
	ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		cout << "Unable to open file" << endl;
		return;
	}
	
	//Read input file
	string line;
	getline (inoutFile, line);
	int numOfMoves = atoi(line);
	getline (inputFile, line);
	int movesOver = atoi(line);
	
	for(int i=0; i<movesOver-1; i++) {
		getline(inputFile, line);
		int firstMove = atoi(line);
		strtok(line, " \t");
		line = strtok(NULL, " \t");
		int secondMove = atoi(line);
		cout << "First move=" << firstMove << " Second move=" << secondMove << endl;
		movesArray.markMoveUsed(firstMove, secondMove);
	}
	
	getline(inputFile, line);
	firstMove = atoi(line);
	strtok(line, " \t");
	line = strtok(NULL, " \t");
	secondMove = atoi(line);
	cout << "First move=" << firstMove << " Second move=" << secondMove << endl;	
	rootNode = creteTree(movesArray, firstMove, secondMove);
}


Node* createTree(ArrayType& availableMoves, unsigned int firstMove, unsigned int secondMove) {
	Node* newNode = new Node(firstMove, secondMove);
	availableMoves.markMoveUsed(firstMove, secondMove);
	for(int i=0; i<columns_; i++) {
		if(availableMoves(node->secondMove, i) == 1) {
			node->childNodes.push_back(createTree(availableMoves, node->secondMove, i));
		}
	}
	availableMoves.unmarkMove(firstMove, secondMove);
	return newNode;	
}


