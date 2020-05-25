#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
    public:

        Matrix(){
            rows = 0;
            cols = 0;
        }

        Matrix(int num_rows, int num_cols){
            Reset(num_rows, num_cols);
        }

        void    Reset(int num_rows, int num_cols){
            Check(num_rows, num_cols);
            if (num_cols == 0 || num_rows == 0){
                num_cols = num_rows = 0;
            }
            rows = num_rows;
            cols = num_cols;
            matrix.resize(num_rows);
            for (int i = 0; i < num_rows; i++){
                matrix[i].resize(0);
                matrix[i].resize(num_cols);
            }
        }

        int     At(const int &r, const int &c) const {
            CheckRowsAndCols(r, c);
            return (matrix.at(r).at(c));
        }

        int     &At(const int &r, const int &c) {
            CheckRowsAndCols(r, c);
            return (matrix.at(r).at(c));
        }

        int     GetNumRows() const {
            return(rows);
        }

        int     GetNumColumns() const {
            return(cols);
        }

    private:
        void    Check(int r, int c) const {
            if (r < 0)
                throw out_of_range("count rows < 0");
            if (c < 0)
                throw out_of_range("count cols < 0");
        }

        void    CheckRowsAndCols(int r, int c) const {
            try{
                if (r > rows || c > cols)
                    throw out_of_range("");
            } catch (out_of_range& e){

            }
        }

        vector<vector<int>> matrix;
        int rows;
        int cols;
};

ostream& operator<<(ostream& stream, const Matrix &m){
    int i, j;
    i = m.GetNumRows();
    j = m.GetNumColumns();
    stream << i << " " << j << endl;
    for (int k = 0; k < i; k++){
        for (int t = 0; t < j; t++){
            stream << m.At(k, t);
            if ((t + 1) < j)
                stream << " ";
        }
        stream << "\n";
    }
    return (stream);
};

istream& operator>>(istream& stream, Matrix &m){
    int i, j;
    stream >> i >> j;
    m.Reset(i, j);
    for (int k = 0; k < i; k++){
        for (int t = 0; t < j; t++){
            stream >> m.At(k, t);
        }
    }
    return (stream);
};

bool    operator==(const Matrix &m1, const Matrix &m2){
    if (m1.GetNumRows() == m2.GetNumRows() && m1.GetNumColumns() == m2.GetNumColumns()){
        int i = m1.GetNumRows();
        int j = m1.GetNumColumns();
        for (int k = 0; k < i; k++)
            for (int t = 0; t < j; t++){
                if (m1.At(k,t) != m2.At(k,t))
                    return false;
            }
        return true;
    }
    return false;
};

Matrix  operator+(const Matrix& m1, const Matrix& m2){
    if (m1.GetNumRows() != m2.GetNumRows())
        throw invalid_argument("Mismatched number of rows");
    if (m1.GetNumColumns() != m2.GetNumColumns())
        throw invalid_argument("Mismatched number of cols");
    int i = m1.GetNumRows();
    int j = m1.GetNumColumns();
    Matrix sum_m(i, j);
    for (int k = 0; k < i; k++)
        for (int t = 0; t < j; t++){
            sum_m.At(k, t) = m1.At(k, t) + m2.At(k, t);
        }
    return sum_m;
};

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}