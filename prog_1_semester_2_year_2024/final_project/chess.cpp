// Programming 2 western chess game

#include <cmath> // for math calculation
// #include <csignal>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Tutorials
// Input position number + destination number
// ex: a2a3 => moving white pawn by 1 square

// ANSI escape codes for terminal text colors
#define RESET "\033[0m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

// Base class for ChessPiece
class ChessPiece {
public:
  virtual char
  getSymbol() const = 0; // Pure virtual function to get the piece's symbol
  virtual bool isWhite() const = 0; // Determine if the piece is white or black
  virtual bool isValidMove(
      int startRow, int startCol, int endRow, int endCol,
      const vector<vector<ChessPiece *>> &board) = 0; // Virtual move validation
  virtual ~ChessPiece() {}
};

// Derived classses for each pieces
// Pawn pieces
class Pawn : public ChessPiece {
  bool white;

public:
  Pawn(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'P' : 'p'; }
  bool isWhite() const override { return white; }

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {
    // White pawns move up to the board (+1), whereas Black pawns move down to
    // the board (-1)
    int direction = white ? 1 : -1;

    // Case 1: Pawn moves forward one square
    // Ensure the column doesn't change and the target square in between is
    // empty
    if (startCol == endCol && startRow + direction == endRow &&
        !board[endRow][endCol]) {
      return true;
    }

    // Case 2: Pawn first move can be two squares
    // Ensure the column doesn't change and the target square in between is
    // empty
    if (startCol == endCol && startRow + 2 * direction == endRow &&
        !board[startRow + direction][startCol] && !board[endRow][endCol]) {
      return true;
    }

    // Invalid move
    return false;
  }
};

// Rook pieces
class Rook : public ChessPiece {
  bool white;

public:
  Rook(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'R' : 'r'; }
  bool isWhite() const override { return white; }

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // Only allowed to move in a straight line (row or column)
    if (startRow != endRow && startCol != endCol)
      return false;

    // Case 1: Rook moves vertically
    // Check if path is clear (row)
    if (startRow == endRow) {
      int i;
      for (i = min(startCol, endCol) + 1; i < max(startCol, endCol); i++) {
        if (board[startRow][i])
          return false; // There is a piece in the way
      }
    }

    // Case 2: Rook moves horizontally
    // Check if path is clear (column)
    if (startCol == endCol) {
      int i;
      for (i = min(startRow, endRow) + 1; i < max(startRow, endRow); ++i) {
        if (board[i][startCol])
          return false; // There is a piece in the way
      }
    }

    // The move is valid
    return true;
  }
};

// Knight pieces
class Knight : public ChessPiece {
  bool white;

public:
  Knight(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'N' : 'n'; }
  bool isWhite() const override { return white; }

  /*
  The knight moves in an "L" shape:
      - Two squares in one direction (row or column) and one square
  perpendicular.
      - This results in two possible conditions for a valid move:
      1. Move 2 rows and 1 column
      2. Move 2 columns and 1 row
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // Case 1: 2 rows + 1 column
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 1)
      return true;

    // Case 2: 2 columns + 1 row
    if (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 2)
      return true;

    // Invalid move
    return false;
  }
};

// Bishop pieces
class Bishop : public ChessPiece {
  bool white;

public:
  Bishop(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'B' : 'b'; }
  bool isWhite() const override { return white; }

  /*
    The bishop moves diagonally in any direction.
      - The absolute difference between the row change and column change must be
    equal.
      - Additionally, the path between the starting square and the target square
    must be clear.
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // Check if the move is diagonal
    if (abs(startRow - endRow) != abs(startCol - endCol))
      return false;

    // Determine the direction of movement for both rows and columns
    // (+1) for downward, (-1) for upward
    int rowDirection = (endRow > startRow) ? 1 : -1;
    // (+1) for rightward, (-1) for leftward
    int colDirection = (endCol > startCol) ? 1 : -1;

    // Start at the first squre in the direction of movement
    int row = startRow + rowDirection;
    int col = startCol + colDirection;

    // Traverse the path to the target square
    while (row != endRow && col != endCol) {
      if (board[row][col])
        return false;      // There is a piece in the way
      row += rowDirection; // Move to the next square in the row direction
      col += colDirection; // Move to the next square in the column direction
    }

    // Valid move
    return true;
  }
};

// Queen pieces
class Queen : public ChessPiece {
  bool white;

public:
  Queen(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'Q' : 'q'; }
  bool isWhite() const override { return white; }

  /*
    The queen can move like both a rook and a bishop:
      - It can move any number of squares horizontally, vertically, or
    diagonally.
      - To avoid code duplication, the isValidMove logic is reused from the Rook
    and Bishop classes.
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // Create temporary Rook and Bishop objects to reuse their movement logic
    Rook rook(white);     // Rook movesets (straight lines)
    Bishop bishop(white); // Bishop movesets (diagonally)

    // The move is valid it it is valid for either the Rook or the Bishop
    return rook.isValidMove(startRow, startCol, endRow, endCol, board) ||
           bishop.isValidMove(startRow, startCol, endRow, endCol, board);
  }
};

// King pieces
class King : public ChessPiece {
  bool white;

public:
  King(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'K' : 'k'; }
  bool isWhite() const override { return white; }

  /*
    The king can move exactly one square in any direction:
      - Horizontally, vertically, or diagonally.
      - This means the difference between the starting and ending positions
        (row and column) must be at most 1.
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // Ensure the move is within one square in all directions
    return (abs(startRow - endRow) <= 1 && abs(startCol - endCol) <= 1);
  }
};

// Board class to manafe chessboard
class Board {
  vector<vector<ChessPiece *>> board;

public:
  Board() {
    // nullptr => empty square
    board.resize(8, vector<ChessPiece *>(8, nullptr));
    initializeBoard();
  }

  ~Board() {
    int i, j;
    for (i = 0; i < 8; ++i) {
      for (j = 0; j < 8; ++j) {
        delete board[i][j]; // Clean up dynamically allocated memory
      }
    }
  }

  void initializeBoard() {
    int i;

    // initalize White pieces
    for (i = 0; i < 8; i++) {
      board[1][i] = new Pawn(true);
    }

    board[0][0] = board[0][7] = new Rook(true);
    board[0][1] = board[0][6] = new Knight(true);
    board[0][2] = board[0][5] = new Bishop(true);
    board[0][3] = new Queen(true);
    board[0][4] = new King(true);

    // Initalize Black pieces
    for (i = 0; i < 8; i++) {
      board[6][i] = new Pawn(false);
    }

    board[7][0] = board[7][7] = new Rook(false);
    board[7][1] = board[7][6] = new Knight(false);
    board[7][2] = board[7][5] = new Bishop(false);
    board[7][3] = new Queen(false);
    board[7][4] = new King(false);
  }

  void printBoard() {
    cout << "\n        " << CYAN << "Black" << RESET << "     \n";
    cout << "\n   " << YELLOW << "a b c d e f g h" << RESET << "\n";
    cout << "  " << GREEN << "+-----------------" << RESET << "\n";
    for (int i = 7; i >= 0; i--) {
      cout << YELLOW << i + 1 << RESET << " " << GREEN << "|" << RESET;
      for (int j = 0; j < 8; j++) {
        if (board[i][j]) {
          if (isupper(board[i][j]->getSymbol())) {
            cout << WHITE << board[i][j]->getSymbol() << " "
                 << RESET; // White pieces
          } else {
            cout << CYAN << board[i][j]->getSymbol() << " "
                 << RESET; // Black pieces
          }
        } else {
          cout << ". "; // Empty square
        }
      }
      cout << GREEN << "|" << RESET << " " << YELLOW << i + 1 << RESET << endl;
    }
    cout << "  " << GREEN << "+-----------------" << RESET << "\n";
    cout << "   " << YELLOW << "a b c d e f g h" << RESET << "\n";
    cout << "\n        " << WHITE << "White" << RESET << "     \n";
    cout << endl;
  }

  ChessPiece *getPiece(int row, int col) {
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return nullptr;
    return board[row][col];
  }

  // Function to check if a piece can capture another
  bool canCapture(int startRow, int startCol, int endRow, int endCol) {
    ChessPiece *attacker = board[startRow][startCol];
    ChessPiece *target = board[endRow][endCol];

    // Ensure attacker exists
    if (!attacker)
      return false;

    // Ensure target exists and is of opposite color
    if (target && attacker->isWhite() == target->isWhite()) {
      cout << "Can't capture piece with the same color!" << endl;
      return false;
    }

    return true;
  }

  bool movePiece(int startRow, int startCol, int endRow, int endCol) {
    ChessPiece *piece = board[startRow][startCol];

    if (!piece) {
      cout << "No piece at the starting position!" << endl;
      return false;
    }

    if (!piece->isValidMove(startRow, startCol, endRow, endCol, board)) {
      cout << "Invalid move for this piece!" << endl;
      return false;
    }

    if (!canCapture(startRow, startCol, endRow, endCol)) {
      return false; // Prevent move if friendly fire is detected
    }

    delete board[endRow][endCol];        // Remove the target piece if present
    board[endRow][endCol] = piece;       // Move the piece to the target
    board[startRow][startCol] = nullptr; // Clear the starting square
    return true;
  }

  bool isKingInCheck(bool isWhite) {
    int kingRow = -1, kingCol = -1;

    // Find the king's position
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];
        if (piece && piece->isWhite() == isWhite &&
            dynamic_cast<King *>(piece)) {
          kingRow = i;
          kingCol = j;
          break;
        }
      }
    }

    if (kingRow == -1 || kingCol == -1) {
      cerr << "Error: King not found on the board!" << endl;
      return false;
    }

    // Check if any opposing piece can move to the king's position
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];
        if (piece && piece->isWhite() != isWhite) {
          if (piece->isValidMove(i, j, kingRow, kingCol, board)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool hasValidMoves(bool isWhite) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];
        if (piece && piece->isWhite() == isWhite) {
          for (int endRow = 0; endRow < 8; ++endRow) {
            for (int endCol = 0; endCol < 8; ++endCol) {
              if (piece->isValidMove(i, j, endRow, endCol, board)) {
                // Temporarily make the move
                ChessPiece *temp = board[endRow][endCol];
                board[endRow][endCol] = piece;
                board[i][j] = nullptr;

                bool stillInCheck = isKingInCheck(isWhite);

                // Undo the move
                board[i][j] = piece;
                board[endRow][endCol] = temp;

                if (!stillInCheck) {
                  return true;
                }
              }
            }
          }
        }
      }
    }

    return false;
  }

  bool isCheckmate(bool isWhite) {
    return isKingInCheck(isWhite) && !hasValidMoves(isWhite);
  }
};

// Game class to manage game logic
class Game {
  Board board; // The game board containing the pieces
  bool isWhiteTurn =
      true; // Flag to track whose turn it is: true for White, false for Black

public:
  // Start the game loop

  void start() {
    board.printBoard();
    string move;

    while (true) { // Infinite loop until the user quits
      // Display the current player's turn
      cout << (isWhiteTurn ? "White's turn: " : "Black's turn: ");
      cin >> move;

      // Command to exit the game
      if (move == "quit")
        break;

      // Validate the input move format
      if (move.length() != 4) {
        cout << "Invalid move format, Try again!" << endl;
        continue; // Ask for a new input
      }

      // Extract move details: start and end positions
      char startFile = move[0],
           startRank = move[1];                  // Start square: file and rank
      char endFile = move[2], endRank = move[3]; // End square: file and rank

      // Convert files (letters) and ranks (numbers) to board indices
      int startRow = startRank - '1'; // Convert rank to zero-based row index
      int startCol = startFile - 'a'; // Convert file to zero-based column index
      int endRow = endRank - '1';     // Convert rank to zero-based row index
      int endCol = endFile - 'a';     // Convert file to zero-based column index

      // Get the chess piece at the starting position
      ChessPiece *piece = board.getPiece(startRow, startCol);

      // Check if there is no piece at the starting position
      if (piece == nullptr) {
        cout << "No piece at the starting position!" << endl;
        continue; // Ask for a new move
      }

      // Check if the piece belongs to the current player
      if ((isWhiteTurn && piece->isWhite()) ||
          (!isWhiteTurn && !piece->isWhite())) {
        // Attempt to move the piece
        if (board.movePiece(startRow, startCol, endRow, endCol)) {
          board.printBoard(); // Print the updated board state

          // Check if the opposing player is in checkmate
          if (board.isCheckmate(!isWhiteTurn)) {
            cout << (isWhiteTurn ? "White" : "Black") << " wins by checkmate!"
                 << endl;
            break; // End the game
          }

          isWhiteTurn = !isWhiteTurn; // Switch turn to the other player
        }
      } else {
        // Error handler
        cout << "It's " << (isWhiteTurn ? "White's" : "Black's") << " turn!"
             << endl;
      }
    }
  }
};

int main() {
  Game game;
  game.start();

  return 0;
}
