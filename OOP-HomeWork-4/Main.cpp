#include<iostream>
#include<cmath>
#include"Fraction.hpp"


int main() {
	setlocale(LC_ALL, "RU");
	int x;
	std::cout << "====================\nСложение двух дробей с помощью оператора +:\n";
	Fraction fr1(3, 15);
	fr1.showFraction(fr1);
	Fraction fr2(4, 18);
	fr2.showFraction(fr2);
	Fraction fr3 = fr1 + fr2;	
	fr3.showFraction(fr3);
	fr3.showRealNum(fr3);

	std::cout << "====================\nРазность двух дробей с помощью оператора -:\n";
	Fraction fr4(2, 3);
	fr4.showFraction(fr4);
	Fraction fr5(1, 4);
	fr5.showFraction(fr5);
	Fraction fr6 = fr4 - fr5;	
	fr6.showFraction(fr6);

	std::cout << "====================\nУмножение двух дробей с помощью оператора *:\n";
	Fraction fr7(24, 35);
	fr7.showFraction(fr7);
	Fraction fr8(25, 36);
	fr8.showFraction(fr8);
	Fraction fr9 = fr7 * fr8;	
	fr9.showFraction(fr9);

	std::cout << "====================\nДеление двух дробей с помощью оператора /:\n";
	Fraction fr10(4, 7);
	fr10.showFraction(fr10);
	Fraction fr11(2, 5);
	fr11.showFraction(fr11);
	Fraction fr12 = fr10 / fr11;	
	fr12.showFraction(fr12);

	std::cout << "====================\nСложение дроби и целого числа с помощью оператора +:\n";
	Fraction fr13(1, 3);
	fr13.showFraction(fr13);
	x = 3;
	std::cout << "x = " << x << '\n';
	Fraction fr14 = fr13 + x;	
	fr14.showFraction(fr14);

	std::cout << "====================\nВычитание из дроби целого числа с помощью оператора -:\n";
	Fraction fr15(10, 3);
	fr15.showFraction(fr15);
	x = 3;
	std::cout << "x = " << x << '\n';
	Fraction fr20 = fr15 - x;	
	fr20.showFraction(fr20);

	std::cout << "====================\nУмножение дроби и целого числа с помощью оператора *:\n";
	Fraction fr16(3, 8);
	fr16.showFraction(fr16);
	x = 5;
	std::cout << "x = " << x << '\n';
	Fraction fr17 = fr16 * x;	
	fr17.showFraction(fr17);

	std::cout << "====================\nДеление дроби на целое число с помощью оператора /:\n";
	Fraction fr18(5, 9);
	fr8.showFraction(fr18);
	x = 2;
	std::cout << "x = " << x << '\n';
	Fraction fr19 = fr18 / x;	
	fr19.showFraction(fr19);
	
	std::cout << "====================\nУнарный минус дроби с помощью оператора -:\n";
	Fraction fr21(5, 9);
	fr21.showFraction(fr21);
	fr21 = -fr21;
	fr21.showFraction(fr21);

	std::cout << "====================\nУнарный плюс дроби с помощью оператора +:\n";
	Fraction fr22(5, -9);
	fr22.showFraction(fr22);
	fr22 = +fr22;
	fr22.showFraction(fr22);

	std::cout << "====================\nПрефиксный инкремент дроби с помощью оператора ++:\n";	
	fr22.showFraction(fr22);
	fr22 = ++fr22;
	fr22.showFraction(fr22);

	std::cout << "====================\nПрефиксный декремент дроби с помощью оператора --:\n";
	fr22.showFraction(fr22);
	fr22 = --fr22;
	fr22.showFraction(fr22);

	std::cout << "====================\nПостфиксный инкремент дроби с помощью оператора ++:\n";
	fr22.showFraction(fr22);
	Fraction fr23 = fr22++;
	fr23.showFraction(fr23);
	fr22.showFraction(fr22);

	std::cout << "====================\nПостфиксный декремент дроби с помощью оператора ++:\n";
	fr22.showFraction(fr22);
	Fraction fr24 = fr22--;
	fr24.showFraction(fr24);
	fr22.showFraction(fr22);

	std::cout << "====================\nВывод дроби с помощью оператора <<:\n";
	std::cout << "fr22 = " << fr22 << '\n';

	std::cout << "====================\nВвод дроби с помощью оператора >>:\n";
	std::cin >> fr22;
	std::cout << "fr22 = " << fr22 << '\n';

	std::cout << "====================\n";
	std::cout << "Дробь fr22 = " << fr22 << " является ";
	if (fr22.CorrectFraction() == false) {
		std::cout << "правильной.\n";
	}
	else {
		std::cout << "неправильной.\n";
	}

	std::cout << "====================\nВведите значение дроби fr22:\n";
	std::cin >> fr22;
	std::cout << "Дробь fr22 = " << fr22 << " является ";
	if (fr22.isIntegerFr() == true) {
		std::cout << "целым числом и равна ";		
		std::cout << fr22.Numerator() / fr22.Denominator() << '\n';		
	}
	else {
		std::cout << "не целым числом.\n";
	}

	std::cout << "====================\n";
	Fraction fr25(5, 19);
	std::cout << "Дробь fr25 = " << fr25 
		<< " c помощью метода InverseFr() преобразуется в обратную дробь и будет равна "
		<< fr25.InverseFr() << ".\n";

	std::cout << "====================\nПолучим целую часть дроби fr25 = "
		<< fr25 << ", которая равна " << fr25.makeIntegerFr() << ".\n";

	std::cout << "====================\nПолучим нецелую часть дроби fr25 = "
		<< fr25 << ", которая равна " << fr25.makeNonIntegerFr() << ".\n";




	return 0;
}