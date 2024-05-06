#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <memory>
#include "textdisplay.h"
#include "observer.h"
#include "piece.h"
#include "pawn.h"
class Board;
class Cell
{
  bool isOn = false;
  bool empty;
  std::string cellColor;
  std::unique_ptr<Piece> curPiece;
  std::vector<Observer *> observers;
  int r, c;

  // Add other private members if necessary

public:
  friend class Board;
  Cell(); // Default constructor
  Cell(const Cell &other);
  Cell &operator=(const Cell &other);
  Cell(Cell &&other);
  Cell &operator=(Cell &&other);
  bool getState() const; // Returns the value of isOn.
  int getRow() const;    // Returns the value of r.
  int getCol() const;    // Returns the value of c.
  bool isEmpty() const;
  char getPieceName() const;
  std::string getPieceColour() const;
  std::unique_ptr<Piece> getPiece();
  void setCoords(int r, int c); // Tells me my row and column number.
  void setCellColor(std::string color);
  void setPiece(std::unique_ptr<Piece> piece);
  void removePiece();
  bool checkMove(Cell &dest, Board &b);
  bool isAttackingMove(Cell &dest, Board &b);
  char getTextDisplay();
  bool isEnPassant();

  void attach(Observer *o);

  void notifyAllObservers(); // Alert observers whose subType is All
                             // Tell the display my new state.
};
#endif
