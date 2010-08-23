/*
 *  danceBattle.h
 *  
 *
 *  Created by Suprita Pagad on 8/22/10.
 *  Copyright 2010 UCSD. All rights reserved.
 *
 */
//==============================================================================

class ArrayType {
public:	
	ArrayType(unsigned int moves);
	virtual ~ArrayType();
	ArrayType(const ArrayType& o);
	unsigned int* getArrayPointer() {return arrayPointer_;}
	void markMoveUsed(unsigned int move1, unsigned int move2);
	void unmarkMove(unsigned int move1, unsigned int move2);
	unsigned  operator() (unsigned  row, unsigned col);
	unsigned& operator() (unsigned row, unsigned col);
private:
	unsigned int  moves_;
	unsigned int* arrayPointer_;
};

ArrayType::ArrayType(unsigned int moves): moves_(moves) {
	arrayPointer_ = new unsigned int[moves_ * moves_];
	for(int i=0; i<moves_; i++) {
		for(int j=0; j<moves_; j++) {
			arrayPointer_[i*moves_ + j]=1;
		}
	}
}

ArrayType::ArrayType(const ArrayType& o) {
	for(int i=0; i<moves_; i++) {
		for(int j=0; j<moves_; j++) {
			arrayPointer_[i*moves_ + j] = o.getArrayPointer[i*moves_ + j];
		}
	}
}

ArrayType::~ArrayType() {
	delete [] arrayPointer_;
}

void
ArrayType::markMoveUsed(unsigned int move1, unsigned int move2) {
	arrayPointer_[move1* moves_ + move2] = 0;
	arrayPointer_[move2*moves_ + move1] = 0;
}

void
ArrayType::unmarkMove(unsigned int move1, unsigned int move2) {
	arrayPointer_[move1*moves_+move2] = 1;
	arrayPointer_[move2*moves_+move1] = 1;
}

unsigned int
ArrayType::operator()(unsigned int row, unsigned int col) {
	return arrayPointer_[row*moves_+col];
}

unsigned int&
ArrayType::operator()(unsigned int row, unsigned int col) {
	return arrayPointer_[row*moves_+col];
}

	
//==============================================================================

class Node {
public:
	Node(unsigned int firstMove, unsigned int secondMove);
	virtual ~Node() {;}
	vector<Node*> childNodes;	
	unsigned int getFirstMove() {return firstMove_;}
	unsigned int setSecondMove() {return secondMove_;}
private:
	firstMove_;
	secondMove_;
}

Node::Node(unsigned int fM, unsigned int sM):firstMove_(fM), secondMove_(sM) {
}

//==============================================================================

