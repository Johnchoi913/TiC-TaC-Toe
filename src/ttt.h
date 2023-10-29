#define TRUE 1
#define FALSE 0
struct board
{
    int dimension;
    int** boardArr;
};

enum tile{empty,X,O};

void draw(struct board board);
void play(struct board board);
