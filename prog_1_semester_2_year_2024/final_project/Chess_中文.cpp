// �{���]�p2��v�ѹC��

#include <cmath> // �Ω�ƾǭp��
// #include <csignal>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �оǽҵ{
// ��J��m�s��+�ت��a�s��
// �Ҧp�Ga2a3 => �N�մѲ��� 1 ��

// �׺ݤ�r�C�⪺ ANSI ��q�X
#define RESET "\033[0m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

// ChessPiece ��Base class
class ChessPiece {
public:
  virtual char
  getSymbol() const = 0; // �µ��ƨ��o�Ѥl���Ÿ�
  virtual bool isWhite() const = 0; // �T�w�o��@�~�O�զ��٬O�¦�

  // Vector<vector<ChessPiece *>> �N���C
  // ����k�Ω��P�s���Ѥl��m
  virtual bool isValidMove(
      int startRow, int startCol, int endRow, int endCol,
      const vector<vector<ChessPiece *>> &board) = 0; // ������������
  virtual ~ChessPiece() {}
};

// �C�Ӥ��q���l�����O
// �ѧL 
class Pawn : public ChessPiece {
  bool white;

public:
  Pawn(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'P' : 'p'; }
  bool isWhite() const override { return white; }

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {
    // �մѧL�V�W���ʨ�ѽL (+1)�A�Ӷ´ѧL�V�U���ʨ�
    // �ѽL (-1)
    int direction = white ? 1 : -1;

    // ���p 1: �M�L�V�e���ʤ@��
    // �T�O�C���|���ܨåB�������ؼФ��O�Ū�
    if (startCol == endCol && startRow + direction == endRow &&
        !board[endRow][endCol]) {
      return true;
    }

    // ���p 2: �M�L�Ĥ@�B�i�H�O��Ӥ��
    // �T�O�C���|���ܨåB�������ؼФ��O�Ū�
    if (startCol == endCol && startRow + 2 * direction == endRow &&
        !board[startRow + direction][startCol] && !board[endRow][endCol]) {
      return true;
    }

    // �L�Ĳ���
    return false;
  }
};

// �� 
class Rook : public ChessPiece {
  bool white;

public:
  Rook(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'R' : 'r'; }
  bool isWhite() const override { return white; }

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // �u���\�u���u�]��ΦC�^����
    if (startRow != endRow && startCol != endCol)
      return false;

    // ���p1�G����������
    // �ˬd���|�O�_�Z�q�]��^
    if (startRow == endRow) {
      int i;
      for (i = min(startCol, endCol) + 1; i < max(startCol, endCol); i++) {
        if (board[startRow][i])
          return false; // �Q�צ�F��
      }
    }

    // ���p2�G����������
    // �ˬd���|�O�_�Z�q�]�C�^
    if (startCol == endCol) {
      int i;
      for (i = min(startRow, endRow) + 1; i < max(startRow, endRow); ++i) {
        if (board[i][startCol])
          return false; 
      }
    }

    // ���Ĳ��� 
    return true;
  }
};

// �M�h 
class Knight : public ChessPiece {
  bool white;

public:
  Knight(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'N' : 'n'; }
  bool isWhite() const override { return white; }

  /*
  �M�h�H��L���β��ʡG
      - �@�Ӥ�V�]��ΦC�^����ӥ���ΩM�@�ӥ���Ϋ����C
      - �o�|�ɭP���Ĳ��ʪ���ӥi�����G
      1.����2��1�C
      2. ����2�C1��
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // ���p1�G2��+1�C
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 1)
      return true;

    // ���p2�G2�C+1��
    if (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 2)
      return true;

    // �L�Ĳ���
    return false;
  }
};

// �D�� 
class Bishop : public ChessPiece {
  bool white;

public:
  Bishop(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'B' : 'b'; }
  bool isWhite() const override { return white; }

  /*
    �D�ЦV���N��V�﨤���ʡC
      - ���ܤƩM�C�ܤƤ���������t�����O�������C
      - �t�~�A�_�l���M�ؼФ�椧�����������M���C
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // �ˬd���ʬO�_���﨤�u
    if (abs(startRow - endRow) != abs(startCol - endCol))
      return false;

    // �T�w��M�C�����ʤ�V
    // (+1) �V�U�A(-1) �V�W
    int rowDirection = (endRow > startRow) ? 1 : -1;
    // (+1) �V�k�A(-1) �V��
    int colDirection = (endCol > startCol) ? 1 : -1;

    // �q���ʤ�V���Ĥ@�Ӥ��}�l
    int row = startRow + rowDirection;
    int col = startCol + colDirection;

    // ��L���|��F�ؼФ��
    while (row != endRow && col != endCol) {
      if (board[row][col])
        return false;      // �Q�צ�F��
      row += rowDirection; // �u"��"��V���ʨ�U�@�Ӥ��
      col += colDirection; // �u"�C"��V���ʨ�U�@�Ӥ��
    }

    // ���Ĳ��� 
    return true;
  }
};

// �ӦZ 
class Queen : public ChessPiece {
  bool white;

public:
  Queen(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'Q' : 'q'; }
  bool isWhite() const override { return white; }

  /*
    �ӦZ�i�H�����M�D�Ф@�˲��ʡG
      - ���i�H�����B�����β��ʥ��N�ƶq������﨤�u�C
      - ���F�קK�{���X���ơA�q�����ƨϥ� isValidMove �޿�M�D��classes�C
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // �إ��{�� �� �M �D�� ����H���ƨϥΥ��̪�����޿�
    Rook rook(white);     // �������ʡ]���u�^
    Bishop bishop(white); // �D�Ъ����ʡ]�﨤�u�^

    // �p�G�郞�ΥD�г����ġA�h�Ӳ��ʦ���
    return rook.isValidMove(startRow, startCol, endRow, endCol, board) ||
           bishop.isValidMove(startRow, startCol, endRow, endCol, board);
  }
};

// ��� 
class King : public ChessPiece {
  bool white;

public:
  King(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'K' : 'k'; }
  bool isWhite() const override { return white; }

  /*
    ����i�H�V���N��V���ʤ@��G
      - �����B�����ι﨤�u�C
      - �o�N���۰_�l��m�M������m�������t���]��M�C�^�̦h�u�ର 1�C
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // �T�O�U�Ӥ�V�����ʳ��b�@�椺
    return (abs(startRow - endRow) <= 1 && abs(startCol - endCol) <= 1);
  }
};

// Board ���O�Ӻ޲z�ѽL
class Board {
  vector<vector<ChessPiece *>> board;

public:
  Board() {
    // nullptr => �Ť��
    board.resize(8, vector<ChessPiece *>(8, nullptr));
    initializeBoard();
  }

  ~Board() {
    int i, j;
    for (i = 0; i < 8; ++i) {
      for (j = 0; j < 8; ++j) {
        delete board[i][j]; // �M�z�ʺA���t���O����
      }
    }
  }

  void initializeBoard() {
    int i;

    // ��l�ƥզ�Ѥl
    for (i = 0; i < 8; i++) {
      board[1][i] = new Pawn(true);
    }

    board[0][0] = board[0][7] = new Rook(true);
    board[0][1] = board[0][6] = new Knight(true);
    board[0][2] = board[0][5] = new Bishop(true);
    board[0][3] = new Queen(true);
    board[0][4] = new King(true);

    // ��l�ƶ¦�Ѥl
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
                 << RESET; // �մѤl
          } else {
            cout << CYAN << board[i][j]->getSymbol() << " "
                 << RESET; // �´Ѥl
          }
        } else {
          cout << ". "; // �Ť��
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

  // �ˬd�@�ӴѤl�O�_�i�H����t�@�ӴѤl�����
  bool canCapture(int startRow, int startCol, int endRow, int endCol) {
    ChessPiece *attacker = board[startRow][startCol];
    ChessPiece *target = board[endRow][endCol];

    // �T�O�����̦s�b
    if (!attacker)
      return false;

    // �T�O�ؼЦs�b�B�C��ۤ�
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
      return false; // �p�G������ͭx���O�A�h�����
    }

    delete board[endRow][endCol];        // �����ؼа϶��]�p�G�s�b�^
    board[endRow][endCol] = piece;       // �N�Ѥl���ʨ�ؼ�
    board[startRow][startCol] = nullptr; // �M���_�l���
    return true;
  }

  bool isKingInCheck(bool isWhite) {
    int kingRow = -1, kingCol = -1;

    //���������m
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];

        // �ʺA�j���ഫ�i�ǽT�ˬd���ЬO�_��ګ��V���
		//�_�h�^�� nullptr
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

    // �ˬd�O�_��������Ѥl�i�H���ʨ�������m
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

  // �ˬd���ʬO�_����
  bool hasValidMoves(bool isWhite) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];
        if (piece && piece->isWhite() == isWhite) {
          for (int endRow = 0; endRow < 8; ++endRow) {
            for (int endCol = 0; endCol < 8; ++endCol) {
              if (piece->isValidMove(i, j, endRow, endCol, board)) {
                // �Ȯɦ�ʤ@�U
                ChessPiece *temp = board[endRow][endCol];
                board[endRow][endCol] = piece;
                board[i][j] = nullptr;

                bool stillInCheck = isKingInCheck(isWhite);

                //�M�P����
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

// �޲z�C���޿誺�C����
class Game {
  Board board; 
  bool isWhiteTurn =
      true; // �Ω�l�ܽ���֪��аO�Gtrue ��ܥդ�Afalse ��ܶ¤�

public:
  // �}�l�C���`��

  void start() {
    board.printBoard();
    string move;

    cout << "How to play: position + destination, ex: a2a3" << endl;
    cout << "ctrl + c -> exit the program" << endl;
    cout << "Good luck!" << endl;
    cout << endl;
    while (true) { // �L���`������Τ�h�X
      // ��ܥثe���a���^�X
      cout << (isWhiteTurn ? "White's turn: " : "Black's turn: ");
      cin >> move;

      // �h�X�C�����O
      if (move == "quit")
        break;

      // ���ҿ�J���ʮ榡
      if (move.length() != 4) {
        cout << "Invalid move format, Try again!" << endl;
        continue; // �ШD�s����J
      }

      // �������ʸԲӸ�T�G�}�l��m�M������m
      char startFile = move[0],
           startRank = move[1];                  // �_�l����G�k�ɩM�ƦW
      char endFile = move[2], endRank = move[3]; // ��������G���M����

      // �N���]�r���^�M�ƦW�]�Ʀr�^�ഫ���O����
      int startRow = startRank - '1'; // �N�ƦW�ഫ���q�s�}�l�������
      int startCol = startFile - 'a'; // �N�ɮ��ഫ���q�s�}�l���C����
      int endRow = endRank - '1';     // �N�ƦW�ഫ���q�s�}�l�������
      int endCol = endFile - 'a';     // �N�ɮ��ഫ���q�s�}�l���C����

      // �N�Ѥl����_�l��m
      ChessPiece *piece = board.getPiece(startRow, startCol);

      // �ˬd�_�l��m�O�_�S���Ѥl
      if (piece == nullptr) {
        cout << "No piece at the starting position!" << endl;
        continue; // �ШD�s�ʧ@
      }

      // �ˬd�ӴѤl�O�_�ݩ��e���a
      if ((isWhiteTurn && piece->isWhite()) ||
          (!isWhiteTurn && !piece->isWhite())) {
        // ���ղ��ʤu��
        if (board.movePiece(startRow, startCol, endRow, endCol)) {
          board.printBoard(); // �C�L��s�᪺�O���A

          // �ˬd��誱�a�O�_�N��
          if (board.isCheckmate(!isWhiteTurn)) {
            cout << (isWhiteTurn ? "White" : "Black") << " wins by checkmate!"
                 << endl;
            break; // �����C��
          }

          isWhiteTurn = !isWhiteTurn; // �������L���a
        }
      } else {
        // ���~�B�z�{��
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
