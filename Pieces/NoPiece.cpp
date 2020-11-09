#include "Headers/NoPiece.h"
#include "../Table.h"

NoPiece::NoPiece(){}
NoPiece::NoPiece(string name, string color, int x, int y, Table *table)
        :Piece(name, color, x, y, 0, table){}
void NoPiece::setRange(){}  