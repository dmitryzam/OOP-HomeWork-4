#pragma once
#include<iostream>
class Fraction {
public:
	// геттеры:
	long long Numerator()const { return numerator_; }
	long long Denominator()const { return denominator_; }
	bool Positive()const { return positive_; }
	// сеттеры:
	void Numerator(long long num) { numerator_ = num; }
	void Denominator(long long den) { denominator_ = den; }
	void Positive(long long pos) { positive_ = pos; }
	// конструктор по умолчанию:
	Fraction() : numerator_{ 0 }, denominator_{ 1 }, positive_{ true }
	{ };
	// конструктор с параметрами:
	Fraction(long long num, long long den);
	// конструктор копирования:
	Fraction(const Fraction& obj);
	// метод, возвращающий состояние правильности дроби:
	bool CorrectFraction();
	// метод вывода дроби:
	void showFraction(Fraction fr);
	// метод вывода дроби в виде действительного числа:
	void showRealNum(Fraction fr);
	// метод сложения двух дробей:
	Fraction Sum(Fraction fr1, Fraction fr2);
	// метод сложения дроби и целого числа:
	Fraction SumWithNum(Fraction fr1, long long num);
	// метод вычитания двух дробей:
	Fraction Sub(Fraction fr1, Fraction fr2);
	// метод вычитания из дроби целого числа:
	Fraction SubWithNum(Fraction fr1, long long num);
	// метод умножения двух дробей:
	Fraction Multi(Fraction fr1, Fraction fr2);
	// метод умножения дроби и целого числа:
	Fraction MultiWithNum(Fraction fr1, long long num);
	// метод деления двух дробей:
	Fraction Divide(Fraction fr1, Fraction fr2);
	// метод деления дроби на целое число:
	Fraction DivideWithNum(Fraction fr1, long long num);
	// определение простых чисел:
	bool simpleNum(long long num);
	// сокращение дроби:
	Fraction ShortenFr(Fraction fr);
	// оператор сложения:
	friend Fraction operator+(const Fraction& fr1, const Fraction& fr2);
	// оператор сложения дроби с числом:
	friend Fraction operator+(const Fraction& fr1, long long num);
	// оператор вычитания:
	friend Fraction operator-(const Fraction& fr1, const Fraction& fr2);
	// оператор вычитания дроби с числом:
	friend Fraction operator-(const Fraction& fr1, long long num);
	// оператор умножения:
	friend Fraction operator*(const Fraction& fr1, const Fraction& fr2);
	// оператор умножения дроби с числом:
	friend Fraction operator*(const Fraction& fr1, long long num);
	// оператор деления:
	friend Fraction operator/(const Fraction& fr1, const Fraction& fr2);
	// оператор деления дроби с числом:
	friend Fraction operator/(const Fraction& fr1, long long num);
	// оператор унарный минус для дроби:
	const Fraction operator-();
	// оператор унарный плюс для дроби:
	const Fraction operator+();
	// оператор префиксной перегрузки для дроби (инкремент):
	Fraction& operator++();
	// оператор префиксной перегрузки для дроби (декремент):
	Fraction& operator--();
	// оператор постфиксной перегрузки для дроби (инкремент):
	const Fraction operator++(int);
	// оператор постфиксной перегрузки для дроби (декремент):
	const Fraction operator--(int);
	// оператор перегрузки вывода:
	friend std::ostream& operator<< (std::ostream& out, const Fraction& obj);
	// оператор перегрузки ввода:
	friend std::istream& operator>> (std::istream& inp, Fraction& obj);
	// метод определяющий целую дробь:
	bool isIntegerFr()const;
	// метод преобразования в обратную дробь:
	Fraction InverseFr();
	// метод предоставляющий целую часть дроби:
	int makeIntegerFr()const;
	// метод предоставляющий нецелую часть дроби:
	const Fraction makeNonIntegerFr();

private:
	long long numerator_;	// числитель	
	long long denominator_;	// знаменатель
	bool positive_;			// знак перед дробью (true - положительный / false - отрицательный)
	long long modul_num;	// модуль числителя
	long long modul_den;	// модуль знаменателя	
	void SetModNum() { numerator_ < 0 ? modul_num = -numerator_ : modul_num = numerator_; }			// заполнение модуля числителя
	void SetModDen() { denominator_ < 0 ? modul_den = -denominator_ : modul_den = denominator_; }	// заполнение модуля знаменателя
	void SetPos();			// установка знака дроби
};