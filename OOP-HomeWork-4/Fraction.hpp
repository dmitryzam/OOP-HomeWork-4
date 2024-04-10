#pragma once
#include<iostream>
class Fraction {
public:
	// �������:
	long long Numerator()const { return numerator_; }
	long long Denominator()const { return denominator_; }
	bool Positive()const { return positive_; }
	// �������:
	void Numerator(long long num) { numerator_ = num; }
	void Denominator(long long den) { denominator_ = den; }
	void Positive(long long pos) { positive_ = pos; }
	// ����������� �� ���������:
	Fraction() : numerator_{ 0 }, denominator_{ 1 }, positive_{ true }
	{ };
	// ����������� � �����������:
	Fraction(long long num, long long den);
	// ����������� �����������:
	Fraction(const Fraction& obj);
	// �����, ������������ ��������� ������������ �����:
	bool CorrectFraction();
	// ����� ������ �����:
	void showFraction(Fraction fr);
	// ����� ������ ����� � ���� ��������������� �����:
	void showRealNum(Fraction fr);
	// ����� �������� ���� ������:
	Fraction Sum(Fraction fr1, Fraction fr2);
	// ����� �������� ����� � ������ �����:
	Fraction SumWithNum(Fraction fr1, long long num);
	// ����� ��������� ���� ������:
	Fraction Sub(Fraction fr1, Fraction fr2);
	// ����� ��������� �� ����� ������ �����:
	Fraction SubWithNum(Fraction fr1, long long num);
	// ����� ��������� ���� ������:
	Fraction Multi(Fraction fr1, Fraction fr2);
	// ����� ��������� ����� � ������ �����:
	Fraction MultiWithNum(Fraction fr1, long long num);
	// ����� ������� ���� ������:
	Fraction Divide(Fraction fr1, Fraction fr2);
	// ����� ������� ����� �� ����� �����:
	Fraction DivideWithNum(Fraction fr1, long long num);
	// ����������� ������� �����:
	bool simpleNum(long long num);
	// ���������� �����:
	Fraction ShortenFr(Fraction fr);
	// �������� ��������:
	friend Fraction operator+(const Fraction& fr1, const Fraction& fr2);
	// �������� �������� ����� � ������:
	friend Fraction operator+(const Fraction& fr1, long long num);
	// �������� ���������:
	friend Fraction operator-(const Fraction& fr1, const Fraction& fr2);
	// �������� ��������� ����� � ������:
	friend Fraction operator-(const Fraction& fr1, long long num);
	// �������� ���������:
	friend Fraction operator*(const Fraction& fr1, const Fraction& fr2);
	// �������� ��������� ����� � ������:
	friend Fraction operator*(const Fraction& fr1, long long num);
	// �������� �������:
	friend Fraction operator/(const Fraction& fr1, const Fraction& fr2);
	// �������� ������� ����� � ������:
	friend Fraction operator/(const Fraction& fr1, long long num);
	// �������� ������� ����� ��� �����:
	const Fraction operator-();
	// �������� ������� ���� ��� �����:
	const Fraction operator+();
	// �������� ���������� ���������� ��� ����� (���������):
	Fraction& operator++();
	// �������� ���������� ���������� ��� ����� (���������):
	Fraction& operator--();
	// �������� ����������� ���������� ��� ����� (���������):
	const Fraction operator++(int);
	// �������� ����������� ���������� ��� ����� (���������):
	const Fraction operator--(int);
	// �������� ���������� ������:
	friend std::ostream& operator<< (std::ostream& out, const Fraction& obj);
	// �������� ���������� �����:
	friend std::istream& operator>> (std::istream& inp, Fraction& obj);
	// ����� ������������ ����� �����:
	bool isIntegerFr()const;
	// ����� �������������� � �������� �����:
	Fraction InverseFr();
	// ����� ��������������� ����� ����� �����:
	int makeIntegerFr()const;
	// ����� ��������������� ������� ����� �����:
	const Fraction makeNonIntegerFr();

private:
	long long numerator_;	// ���������	
	long long denominator_;	// �����������
	bool positive_;			// ���� ����� ������ (true - ������������� / false - �������������)
	long long modul_num;	// ������ ���������
	long long modul_den;	// ������ �����������	
	void SetModNum() { numerator_ < 0 ? modul_num = -numerator_ : modul_num = numerator_; }			// ���������� ������ ���������
	void SetModDen() { denominator_ < 0 ? modul_den = -denominator_ : modul_den = denominator_; }	// ���������� ������ �����������
	void SetPos();			// ��������� ����� �����
};