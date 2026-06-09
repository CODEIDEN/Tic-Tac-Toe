#include <iostream>

using namespace std;

char board[3][3];

void initializeBoard()
{
    char position = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }
}

void displayBoard()
{
    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        cout << " ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << "\n";

        if (i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool makeMove(int position, char symbol)
{
    if (position < 1 || position > 9)
        return false;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = symbol;
    return true;
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void playGame()
{
    initializeBoard();

    int currentPlayer = 1;
    int move;

    while (true)
    {
        displayBoard();

        char symbol;

        if (currentPlayer == 1)
            symbol = 'X';
        else
            symbol = 'O';

        cout << "Player "
             << currentPlayer
             << " (" << symbol << ")"
             << ", enter position (1-9): ";

        cin >> move;

        if (!makeMove(move, symbol))
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (checkWin())
        {
            displayBoard();

            cout << "Player "
                 << currentPlayer
                 << " wins!\n";

            break;
        }

        if (checkDraw())
        {
            displayBoard();

            cout << "Match Drawn!\n";
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int main()
{
    char choice;

    do
    {
        cout << "\n===== TIC TAC TOE =====\n";

        playGame();

        cout << "\nPlay Again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}