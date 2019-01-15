/**
  Write a routine to determine if a board has a winner.
  Encode Xs as 0x01 and Os as 0x10 on the board. The board
  itself is encoded as a vector of 3 uint32_t.
*/

#include <iostream>

using namespace std;

const uint8_t X = 'X';
const uint8_t O = 'O';
const uint8_t Nil = '/';

typedef uint32_t Board[3];

uint8_t Winner(const Board& board)
{
  if (board[0] == 0x01010100 ||
      board[1] == 0x01010100 ||
      board[2] == 0x01010100)
    return X;

  if (board[0] == 0x10101000 ||
      board[1] == 0x10101000 ||
      board[2] == 0x10101000)
    return O;

  const uint32_t sum = board[0] + board[1] + board[2];
  const uint8_t c0 = sum >> 24;
  const uint8_t c1 = sum >> 16;
  const uint8_t c2 = sum >> 8;

  if (c0 == 0x03 || c1 == 0x03 || c2 == 0x03)
    return X;

  if (c0 == 0x30 || c1 == 0x30 || c2 == 0x30)
    return O;

  const uint8_t d0 = (board[0] >> 24) + (board[1] >> 16) + (board[2] >> 8);
  if (d0 == 0x03)
    return X;
  if (d0 == 0x30)
    return O;

  const uint8_t d1 = (board[0] >> 8) + (board[1] >> 16) + (board[2] >> 24);
  if (d1 == 0x03)
    return X;
  if (d1 == 0x30)
    return O;

  return Nil;
}

int main()
{
  Board b;
  
  b[0] = 0x01010100;
  b[1] = 0x00000000;
  b[2] = 0x10101000;
  cout << Winner(b) << endl;

  b[0] = 0x01100100; 
  b[1] = 0x01000000;
  b[2] = 0x01000000;
  cout << Winner(b) << endl;

  b[0] = 0x01011000;
  b[1] = 0x00011000;
  b[2] = 0x00101000;
  cout << Winner(b) << endl;

  b[0] = 0x10100100;
  b[1] = 0x10100100;
  b[2] = 0x01011000;
  cout << Winner(b) << endl;

  b[1] = 0x10010100;
  b[2] = 0x01100000;
  cout << Winner(b) << endl;

  return 0;
}
