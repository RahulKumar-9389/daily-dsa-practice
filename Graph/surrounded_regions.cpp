#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board);

private:
    void DFS(vector<vector<char>> &board, int i, int j, int m, int n);
};

void Solution::DFS(vector<vector<char>> &board, int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
        return;
    board[i][j] = '#';
    DFS(board, i - 1, j, m, n);
    DFS(board, i + 1, j, m, n);
    DFS(board, i, j - 1, m, n);
    DFS(board, i, j + 1, m, n);
}

void Solution::solve(vector<vector<char>> &board)
{
    int m = board.size();
    if (m == 0)
        return;
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
            DFS(board, i, 0, m, n);
        if (board[i][n - 1] == 'O')
            DFS(board, i, n - 1, m, n);
    }

    for (int j = 0; j < n; j++)
    {
        if (board[0][j] == 'O')
            DFS(board, 0, j, m, n);
        if (board[m - 1][j] == 'O')
            DFS(board, m - 1, j, m, n);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}

void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    cout << "Before solving:\n";
    printBoard(board);

    Solution sol;
    sol.solve(board);

    cout << "After solving:\n";
    printBoard(board);

    return 0;
}
