#define TRUE 1
#define FALSE 0
struct board
{
    int dimension;
    int** boardArr;
};

struct moveValue
{
    int row;
    int col;
    int expVal;
};


enum tile{empty,X,O};

void draw(struct board board);
void play(struct board board);
int checkGameOver(char player, struct board board);
void freeBoard(struct board* board);
struct moveValue minimax(struct board board, char player);