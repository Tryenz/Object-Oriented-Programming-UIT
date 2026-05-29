#ifndef CARRAY_H
#define CARRAY_H
#include <iostream>

class cArray {
private:
    int* a;
    int n;

    bool laSNT(int x);

public:
    cArray();
    cArray(const cArray&);

    ~cArray();

    int getN();

    void tao_mang();
    void xuat() const;

    int so_lan_xuat_hien(int x);
    bool ktra_tang_dan();

    int tim_le_nho_nhat();
    int tim_snt_max();

    void sap_xep_tang_dan();
    void sap_xep_giam_dan();
};

#endif
