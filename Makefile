build: CartPoint MoveTransition Table Piece King Queen Bishop Knight Rook Pawn NoPiece Player BPlayer WPlayer BoardEvaluator XboardInterface Main Game 
	g++ -g Main.o Piece.o CartPoint.o MoveTransition.o Table.o King.o Queen.o Bishop.o Knight.o Rook.o Pawn.o NoPiece.o Player.o BlackPlayer.o WhitePlayer.o BoardEvaluator.o XboardInterface.o Game.o -o engineEtapa3

CartPoint: CartPoint.cpp
	g++ -c CartPoint.cpp
MoveTransition: MoveTransition.cpp
	g++ -c MoveTransition.cpp
BoardEvaluator: BoardEvaluator.cpp
	g++ -c BoardEvaluator.cpp
Table: Table.cpp
	g++ -c Table.cpp
Piece: Pieces/Piece.cpp
	g++ -c Pieces/Piece.cpp
King: Pieces/King.cpp
	g++ -c Pieces/King.cpp
Queen: Pieces/Queen.cpp
	g++ -c Pieces/Queen.cpp
Bishop: Pieces/Bishop.cpp
	g++ -c Pieces/Bishop.cpp
Knight: Pieces/Knight.cpp
	g++ -c Pieces/Knight.cpp
Rook: Pieces/Rook.cpp
	g++ -c Pieces/Rook.cpp
Pawn: Pieces/Pawn.cpp
	g++ -c Pieces/Pawn.cpp
NoPiece: Pieces/NoPiece.cpp
	g++ -c Pieces/NoPiece.cpp
Player: Player.cpp
	g++ -c Player.cpp
WPlayer: WhitePlayer.cpp
	g++ -c WhitePlayer.cpp
BPlayer: BlackPlayer.cpp
	g++ -c BlackPlayer.cpp
XboardInterface: XboardInterface.cpp
	g++ -c XboardInterface.cpp
Game: Game.cpp
	g++ -c Game.cpp
Main: Main.cpp
	g++ -c Main.cpp

run:
	./engineEtapa3

clean:
	rm *.o engineEtapa3
