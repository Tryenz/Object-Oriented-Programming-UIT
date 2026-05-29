#include "CMatrix.h"

void CMatrix::allocateMemory() {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    }
}

void CMatrix::freeMemory() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    if (rows < 1) rows = 1;
    if (cols < 1) cols = 1;
    allocateMemory();
}

CMatrix::~CMatrix() {
    freeMemory();
}

CMatrix::CMatrix(const CMatrix& other) : rows(other.rows), cols(other.cols) {
    allocateMemory();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        freeMemory();
        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

double& CMatrix::operator()(int r, int c) {
    return data[r][c];
}

double CMatrix::operator()(int r, int c) const {
    return data[r][c];
}

CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[Loi] Khong the cong 2 ma tran khac kich thuoc!\n";
        return CMatrix(rows, cols);
    }
    CMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[Loi] Khong the tru 2 ma tran khac kich thuoc!\n";
        return CMatrix(rows, cols);
    }
    CMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) {
        cout << "[Loi] So cot ma tran 1 phai bang so hang ma tran 2 de nhan!\n";
        return CMatrix(rows, other.cols);
    }
    CMatrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

CVector CMatrix::operator*(const CVector& v) const {
    if (cols != v.getSize()) {
        cout << "[Loi] So cot ma tran phai bang so chieu cua vector!\n";
        return CVector(rows);
    }
    CVector result(rows);
    for (int i = 0; i < rows; ++i) {
        double sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += data[i][j] * v[j];
        }
        result[i] = sum;
    }
    return result;
}

ostream& operator<<(ostream& os, const CMatrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        os << "| ";
        for (int j = 0; j < m.cols; ++j) {
            os << setw(6) << m.data[i][j] << " ";
        }
        os << "|\n";
    }
    return os;
}

istream& operator>>(istream& is, CMatrix& m) {
    int r, c;
    cout << "Nhap so hang: "; is >> r;
    cout << "Nhap so cot: "; is >> c;

    if (r != m.rows || c != m.cols) {
        m.freeMemory();
        m.rows = r;
        m.cols = c;
        m.allocateMemory();
    }

    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            is >> m.data[i][j];
        }
    }
    return is;
}
