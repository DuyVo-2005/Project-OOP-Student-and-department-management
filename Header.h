#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#define Max 100
using namespace std;
class Khoa
{
public:
    string ten;
    int namTL;
    Khoa() {
        this->ten = "";
        this->namTL = 0;
    }
    Khoa(string newTen, int newNamTL) {
        this->namTL = newNamTL;
        this->ten = newTen;
    }
    void nhap() {
        cout << "\nNhap nam thanh lap: ";
        cin >> this->namTL;
        cout << "\nNhap ten khoa: ";
        cin.ignore();
        getline(cin, this->ten);
    }
    void xuat() {
        cout << "\nTen khoa: " << this->ten << "\nNam thanh lap: " << this->namTL;
    }
};
void ChonKhoa(Khoa *&khoa);
class SVVB2
{
public:
    int maSo;
    string hoTen;
    float dtb;
    float diemLT;
    float diemTH;
    Khoa* khoa;// quan he aggregation(ko sv, khoa van con)
    SVVB2() {
        this->maSo = 0;
        this->hoTen = "";
        this->dtb = 0;
        this->diemLT = 0;
        this->diemTH = 0;
        this->khoa = nullptr;
    }
    void nhap() {
        cout << "\nNhap ma so sinh vien: ";
        cin >> this->maSo;
        cout << "\nNhap ho ten: ";
        cin.ignore();
        getline(cin, this->hoTen);
        cout << "\nNhap diem trung binh: ";
        cin >> this->dtb;
        cout << "\nNhap diem li thuyet: ";
        cin >> this->diemLT;
        cout << "\nNhap diem thuc hanh: ";
        cin >> this->diemTH;
        this->khoa = new Khoa;
        ChonKhoa(this->khoa);
        //this->khoa.nhap();
    }
    float TinhDTN() {
        return this->dtb * 0.4 + this->diemLT * 0.3 + this->diemTH * 0.3;
    }
    void xuat() {
        cout << "\nMa so: " << this->maSo << "\nHo ten: " << this->hoTen << "\nDiem trung binh: " << this->dtb << "\nDiem ly thuyet: " << this->diemLT << "\nDiem thuc hanh: "<<this->diemTH;
        cout << "\nDiem tot nghiep: " << this->TinhDTN();
        this->khoa->xuat();
    }
};
class SVCQ
{
public:
    int maSo;
    string hoTen;
    float dtb;
    float diemKL;
    Khoa *khoa;//dung aggregation nen *khoa
    SVCQ() {
        this->maSo = 0;
        this->hoTen = "";
        this->dtb = 0;
        this->diemKL = 0;
        this->khoa = nullptr;
    }
    void nhap() {
        cout << "\nNhap ma so sinh vien: ";
        cin >> this->maSo;
        cout << "\nNhap ho ten: ";
        cin.ignore();
        getline(cin, this->hoTen);
        cout << "\nNhap diem trung binh: ";
        cin >> this->dtb;
        cout << "\nNhap diem khoa luan:";
        cin >> this->diemKL;
        this->khoa = new Khoa;
        ChonKhoa(this->khoa);
        //this->khoa.nhap();
        //toi uu nho ram nen dua lua chon tu ds khoa co san -> tranh trung lap
    }
    float tinhDTN() {
        return this->dtb * 0.8 + this->diemKL * 0.2;
    }
    void xuat() {
        cout << "\nMa so: " << this->maSo << "\nHo ten: " << this->hoTen << "\nDiem trung binh: " << this->dtb << "\nDiem khoa luan: " << this->diemKL;
        cout << "\nDiem tot nghiep: " << this->tinhDTN();
        this->khoa->xuat();
    }
};
class Program
{
public:
    vector<SVCQ> DSSVCQ;
    vector<SVVB2> DSSVVB2;
    static vector<Khoa*> DSKhoa;
    /*SVCQ DSSVCQ[Max];
    SVVB2 DSSVVB2[Max];
    Khoa DSKhoa[Max];*/
    void nhap() {
        int nKhoa, nSVCQ, nSVVB2;
        cout << "\nNhap so khoa: ";
        cin >> nKhoa;
        for (int i = 0; i < nKhoa; i++) {
            Khoa *tmp = new Khoa;
            tmp->nhap();
            DSKhoa.push_back(tmp);
        }
            
        cout << "\nNhap so luong sinh vien chinh quy: ";
        cin >> nSVCQ;
        for (int i = 0; i < nSVCQ; i++) {
            SVCQ tmp;
            tmp.nhap();
            DSSVCQ.push_back(tmp);
        }
        cout << "\nNhap so luong sinh vien van bang 2: ";
        cin >> nSVVB2;
        for (int i = 0; i < nSVVB2; i++) {
            SVVB2 tmp;
            tmp.nhap();
            DSSVVB2.push_back(tmp);
        }           
    }
    void xuat() {
        cout << "\nDanh sach khoa: ";
        for (int i = 0; i < DSKhoa.size(); i++)  DSKhoa[i]->xuat();
        cout << "\nDanh sach sinh vien chinh quy: ";
        for (int i = 0; i < DSSVCQ.size(); i++) DSSVCQ[i].xuat();
        cout << "\nDanh sach sinh vien van bang 2: ";
        for (int i = 0; i < DSSVVB2.size(); i++)   DSSVVB2[i].xuat();
        
    }
};
vector<Khoa*> Program::DSKhoa;
void ChonKhoa(Khoa *&khoa) {//
    cout << "\nDanh sach cac khoa cua truong: ";
    while (true) {
        for (int i = 0; i < Program::DSKhoa.size(); i++) {
            cout << "\nSTT " << i + 1;
            Program::DSKhoa[i]->xuat();
        }
        cout << "\nChon khoa (so nguyen): ";
        int tmp;
        cin >> tmp;
        if (tmp >= 1 && tmp <= Program::DSKhoa.size()) {
            khoa->namTL = Program::DSKhoa[tmp - 1]->namTL;
            khoa->ten = Program::DSKhoa[tmp - 1]->ten;
            break;
        }
        else    cout << "\nKhoa vua chon khong hop le! Chon lai!";
    }
}