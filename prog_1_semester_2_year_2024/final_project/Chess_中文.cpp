// 程式設計2西洋棋遊戲

#include <cmath> // 用於數學計算
// #include <csignal>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 教學課程
// 輸入位置編號+目的地編號
// 例如：a2a3 => 將白棋移動 1 格

// 終端文字顏色的 ANSI 轉義碼
#define RESET "\033[0m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

// ChessPiece 的Base class
class ChessPiece {
public:
  virtual char
  getSymbol() const = 0; // 純虛函數取得棋子的符號
  virtual bool isWhite() const = 0; // 確定這件作品是白色還是黑色

  // Vector<vector<ChessPiece *>> 代表桌遊
  // 此方法用於輕鬆存取棋子位置
  virtual bool isValidMove(
      int startRow, int startCol, int endRow, int endCol,
      const vector<vector<ChessPiece *>> &board) = 0; // 虛擬移動驗證
  virtual ~ChessPiece() {}
};

// 每個片段的衍生類別
// 棋兵 
class Pawn : public ChessPiece {
  bool white;

public:
  Pawn(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'P' : 'p'; }
  bool isWhite() const override { return white; }

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {
    // 白棋兵向上移動到棋盤 (+1)，而黑棋兵向下移動到
    // 棋盤 (-1)
    int direction = white ? 1 : -1;

    // 情況 1: 騎兵向前移動一格
    // 確保列不會改變並且中間的目標方格是空的
    if (startCol == endCol && startRow + direction == endRow &&
        !board[endRow][endCol]) {
      return true;
    }

    // 情況 2: 騎兵第一步可以是兩個方格
    // 確保列不會改變並且中間的目標方格是空的
    if (startCol == endCol && startRow + 2 * direction == endRow &&
        !board[startRow + direction][startCol] && !board[endRow][endCol]) {
      return true;
    }

    // 無效移動
    return false;
  }
};

// 車 
class Rook : public ChessPiece {
  bool white;

public:
  Rook(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'R' : 'r'; }
  bool isWhite() const override { return white; }

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // 只允許沿直線（行或列）移動
    if (startRow != endRow && startCol != endCol)
      return false;

    // 情況1：車垂直移動
    // 檢查路徑是否暢通（行）
    if (startRow == endRow) {
      int i;
      for (i = min(startCol, endCol) + 1; i < max(startCol, endCol); i++) {
        if (board[startRow][i])
          return false; // 被擋住了路
      }
    }

    // 狀況2：車水平移動
    // 檢查路徑是否暢通（列）
    if (startCol == endCol) {
      int i;
      for (i = min(startRow, endRow) + 1; i < max(startRow, endRow); ++i) {
        if (board[i][startCol])
          return false; 
      }
    }

    // 有效移動 
    return true;
  }
};

// 騎士 
class Knight : public ChessPiece {
  bool white;

public:
  Knight(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'N' : 'n'; }
  bool isWhite() const override { return white; }

  /*
  騎士以“L”形移動：
      - 一個方向（行或列）的兩個正方形和一個正方形垂直。
      - 這會導致有效移動的兩個可能條件：
      1.移動2行1列
      2. 移動2列1行
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // 情況1：2行+1列
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 1)
      return true;

    // 情況2：2列+1行
    if (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 2)
      return true;

    // 無效移動
    return false;
  }
};

// 主教 
class Bishop : public ChessPiece {
  bool white;

public:
  Bishop(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'B' : 'b'; }
  bool isWhite() const override { return white; }

  /*
    主教向任意方向對角移動。
      - 行變化和列變化之間的絕對差必須是平等的。
      - 另外，起始方格和目標方格之間的路必須清楚。
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // 檢查移動是否為對角線
    if (abs(startRow - endRow) != abs(startCol - endCol))
      return false;

    // 確定行和列的移動方向
    // (+1) 向下，(-1) 向上
    int rowDirection = (endRow > startRow) ? 1 : -1;
    // (+1) 向右，(-1) 向左
    int colDirection = (endCol > startCol) ? 1 : -1;

    // 從移動方向的第一個方格開始
    int row = startRow + rowDirection;
    int col = startCol + colDirection;

    // 穿過路徑到達目標方格
    while (row != endRow && col != endCol) {
      if (board[row][col])
        return false;      // 被擋住了路
      row += rowDirection; // 沿"行"方向移動到下一個方格
      col += colDirection; // 沿"列"方向移動到下一個方格
    }

    // 有效移動 
    return true;
  }
};

// 皇后 
class Queen : public ChessPiece {
  bool white;

public:
  Queen(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'Q' : 'q'; }
  bool isWhite() const override { return white; }

  /*
    皇后可以像車和主教一樣移動：
      - 它可以水平、垂直或移動任意數量的方塊對角線。
      - 為了避免程式碼重複，從車重複使用 isValidMove 邏輯和主教classes。
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // 建立臨時 車 和 主教 物件以重複使用它們的行動邏輯
    Rook rook(white);     // 車的移動（直線）
    Bishop bishop(white); // 主教的移動（對角線）

    // 如果對車或主教都有效，則該移動有效
    return rook.isValidMove(startRow, startCol, endRow, endCol, board) ||
           bishop.isValidMove(startRow, startCol, endRow, endCol, board);
  }
};

// 國王 
class King : public ChessPiece {
  bool white;

public:
  King(bool isWhite) : white(isWhite) {}
  char getSymbol() const override { return white ? 'K' : 'k'; }
  bool isWhite() const override { return white; }

  /*
    國王可以向任意方向移動一格：
      - 水平、垂直或對角線。
      - 這意味著起始位置和結束位置之間的差異（行和列）最多只能為 1。
  */

  bool isValidMove(int startRow, int startCol, int endRow, int endCol,
                   const vector<vector<ChessPiece *>> &board) override {

    // 確保各個方向的移動都在一格內
    return (abs(startRow - endRow) <= 1 && abs(startCol - endCol) <= 1);
  }
};

// Board 類別來管理棋盤
class Board {
  vector<vector<ChessPiece *>> board;

public:
  Board() {
    // nullptr => 空方塊
    board.resize(8, vector<ChessPiece *>(8, nullptr));
    initializeBoard();
  }

  ~Board() {
    int i, j;
    for (i = 0; i < 8; ++i) {
      for (j = 0; j < 8; ++j) {
        delete board[i][j]; // 清理動態分配的記憶體
      }
    }
  }

  void initializeBoard() {
    int i;

    // 初始化白色棋子
    for (i = 0; i < 8; i++) {
      board[1][i] = new Pawn(true);
    }

    board[0][0] = board[0][7] = new Rook(true);
    board[0][1] = board[0][6] = new Knight(true);
    board[0][2] = board[0][5] = new Bishop(true);
    board[0][3] = new Queen(true);
    board[0][4] = new King(true);

    // 初始化黑色棋子
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
                 << RESET; // 白棋子
          } else {
            cout << CYAN << board[i][j]->getSymbol() << " "
                 << RESET; // 黑棋子
          }
        } else {
          cout << ". "; // 空方塊
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

  // 檢查一個棋子是否可以捕獲另一個棋子的函數
  bool canCapture(int startRow, int startCol, int endRow, int endCol) {
    ChessPiece *attacker = board[startRow][startCol];
    ChessPiece *target = board[endRow][endCol];

    // 確保攻擊者存在
    if (!attacker)
      return false;

    // 確保目標存在且顏色相反
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
      return false; // 如果偵測到友軍火力，則阻止移動
    }

    delete board[endRow][endCol];        // 移除目標區塊（如果存在）
    board[endRow][endCol] = piece;       // 將棋子移動到目標
    board[startRow][startCol] = nullptr; // 清除起始方塊
    return true;
  }

  bool isKingInCheck(bool isWhite) {
    int kingRow = -1, kingCol = -1;

    //找到國王的位置
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];

        // 動態強制轉換可準確檢查指標是否實際指向國王
		//否則回傳 nullptr
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

    // 檢查是否有任何對手棋子可以移動到國王的位置
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

  // 檢查移動是否有效
  bool hasValidMoves(bool isWhite) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ChessPiece *piece = board[i][j];
        if (piece && piece->isWhite() == isWhite) {
          for (int endRow = 0; endRow < 8; ++endRow) {
            for (int endCol = 0; endCol < 8; ++endCol) {
              if (piece->isValidMove(i, j, endRow, endCol, board)) {
                // 暫時行動一下
                ChessPiece *temp = board[endRow][endCol];
                board[endRow][endCol] = piece;
                board[i][j] = nullptr;

                bool stillInCheck = isKingInCheck(isWhite);

                //撤銷移動
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

// 管理遊戲邏輯的遊戲類
class Game {
  Board board; 
  bool isWhiteTurn =
      true; // 用於追蹤輪到誰的標記：true 表示白方，false 表示黑方

public:
  // 開始遊戲循環

  void start() {
    board.printBoard();
    string move;

    cout << "How to play: position + destination, ex: a2a3" << endl;
    cout << "ctrl + c -> exit the program" << endl;
    cout << "Good luck!" << endl;
    cout << endl;
    while (true) { // 無限循環直到用戶退出
      // 顯示目前玩家的回合
      cout << (isWhiteTurn ? "White's turn: " : "Black's turn: ");
      cin >> move;

      // 退出遊戲指令
      if (move == "quit")
        break;

      // 驗證輸入移動格式
      if (move.length() != 4) {
        cout << "Invalid move format, Try again!" << endl;
        continue; // 請求新的輸入
      }

      // 提取移動詳細資訊：開始位置和結束位置
      char startFile = move[0],
           startRank = move[1];                  // 起始方塊：歸檔和排名
      char endFile = move[2], endRank = move[3]; // 結束方塊：文件和等級

      // 將文件（字母）和排名（數字）轉換為板索引
      int startRow = startRank - '1'; // 將排名轉換為從零開始的行索引
      int startCol = startFile - 'a'; // 將檔案轉換為從零開始的列索引
      int endRow = endRank - '1';     // 將排名轉換為從零開始的行索引
      int endCol = endFile - 'a';     // 將檔案轉換為從零開始的列索引

      // 將棋子拿到起始位置
      ChessPiece *piece = board.getPiece(startRow, startCol);

      // 檢查起始位置是否沒有棋子
      if (piece == nullptr) {
        cout << "No piece at the starting position!" << endl;
        continue; // 請求新動作
      }

      // 檢查該棋子是否屬於當前玩家
      if ((isWhiteTurn && piece->isWhite()) ||
          (!isWhiteTurn && !piece->isWhite())) {
        // 嘗試移動工件
        if (board.movePiece(startRow, startCol, endRow, endCol)) {
          board.printBoard(); // 列印更新後的板狀態

          // 檢查對方玩家是否將死
          if (board.isCheckmate(!isWhiteTurn)) {
            cout << (isWhiteTurn ? "White" : "Black") << " wins by checkmate!"
                 << endl;
            break; // 結束遊戲
          }

          isWhiteTurn = !isWhiteTurn; // 切換到其他玩家
        }
      } else {
        // 錯誤處理程序
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
