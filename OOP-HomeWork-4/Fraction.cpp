#include "Fraction.hpp"

Fraction::Fraction(long long num, long long den) : numerator_{ num }, denominator_{ den } {
	if (den == 0) { throw std::exception("message"); }
	SetModNum();
	SetModDen();
	SetPos();
}

Fraction::Fraction(const Fraction& obj) : numerator_(obj.numerator_), denominator_(obj.denominator_){
	SetModNum();
	SetModDen();
	SetPos();
}

bool Fraction::CorrectFraction() {
	SetModNum();
	SetModDen();
	if (modul_num > modul_den)
		return true;
	else
		return false;
}

void Fraction::showFraction(Fraction fr) {
	SetModNum();
	SetModDen();
	SetPos();
	if (positive_ == true)
		std::cout << modul_num << " / " << modul_den << '\n';
	else
		std::cout << "-(" << modul_num << " / " << modul_den << ')' << '\n';
}

void Fraction::showRealNum(Fraction fr) {
	SetModNum();
	SetModDen();
	SetPos();
	long double result = (double)modul_num / modul_den;
	if (modul_num == 0 && positive_ == true)
		std::cout << '1' << '\n';
	else if (modul_num == 0 && positive_ == false)
		std::cout << "-1" << '\n';
	else if (positive_ == true)
		std::cout << round(result * 100) / 100 << '\n';	// округление до двух знаков после запятой
	else
		std::cout << round(-result * 100) / 100 << '\n';
}

const Fraction Fraction::operator-(){
	if (Positive() == true) {
		if (Numerator() >= 0) {
			Numerator(-Numerator());
		}
		if (Denominator() < 0) {
			Denominator(-Denominator());
		}		
		SetPos();
	}
	return *(this);
}

const Fraction Fraction::operator+(){
	if (Positive() == false) {
		if (Numerator() < 0) {
			Numerator(-Numerator());
		}
		if (Denominator() < 0) {
			Denominator(-Denominator());
		}		
		SetPos();
	}
	return *(this);
}

Fraction& Fraction::operator++(){
	++numerator_;
	++denominator_;
	return *this;	
}

Fraction& Fraction::operator--(){
	--numerator_;
	--denominator_;
	return *this;
}

const Fraction Fraction::operator++(int){
	Fraction tmp{ *this };
	++(*this);	
	return tmp;
}

const Fraction Fraction::operator--(int){
	Fraction tmp{ *this };
	--(*this);
	return tmp;
}

bool Fraction::isIntegerFr()const{
	if (numerator_ % denominator_ == 0) {
		return true;
	}
	else
		return false;
}

Fraction Fraction::InverseFr(){
	std::swap(numerator_, denominator_);
	SetModNum();
	SetModDen();
	SetPos();
	return *this;
}
int Fraction::makeIntegerFr()const{
	if (numerator_ < denominator_) {
		return 0;
	}
	else {
		return numerator_ / denominator_;
	}
}

const Fraction Fraction::makeNonIntegerFr(){
	if (numerator_ < denominator_) {
		return *this;
	}	
	Fraction tmp = *this - makeIntegerFr();
	return tmp;
}

void Fraction::SetPos() {
	if ((numerator_ >= 0 && denominator_ >= 0) || (numerator_ < 0 && denominator_ < 0))
		positive_ = true;
	else
		positive_ = false;
}

Fraction Fraction::Sum(Fraction fr1, Fraction fr2) {
	Fraction fr_tmp;
	long long nom_tmp{};		// числитель
	long long minCommonDen{};	// наименьший общий знаменатель (НОК)
	// нахождение НОК:
	if (fr1.Denominator() == fr2.Denominator()) {
		minCommonDen = fr1.Denominator();
	}
	else if (fr1.Denominator() % fr2.Denominator() == 0 || fr2.Denominator() % fr1.Denominator() == 0) {
		if (fr1.Denominator() > fr2.Denominator()) {
			minCommonDen = fr1.Denominator();
			fr2.Numerator(fr2.Numerator() * fr1.Denominator() / fr2.Denominator());
		}
		else if (fr2.Denominator() > fr1.Denominator()) {
			minCommonDen = fr2.Denominator();
			fr1.Numerator(fr1.Numerator() * fr2.Denominator() / fr1.Denominator());
		}
	}
	else if (fr1.Denominator() > fr2.Denominator())
		for (int i = 2; i < fr2.Denominator(); i++) {
			if ((fr1.Denominator() * i) % fr2.Denominator() == 0) {
				minCommonDen = fr1.Denominator() * i;
				fr1.Numerator(fr1.Numerator() * i);
				fr2.Numerator(fr2.Numerator() * minCommonDen / fr2.Denominator());
				break;
			}
		}
	else {
		for (int i = 2; i < fr1.Denominator(); i++) {
			if ((fr2.Denominator() * i) % fr1.Denominator() == 0) {
				minCommonDen = fr2.Denominator() * i;
				fr2.Numerator(fr2.Numerator() * i);
				fr1.Numerator(fr1.Numerator() * minCommonDen / fr1.Denominator());
				break;
			}
		}
	}
	fr_tmp.Denominator(minCommonDen);
	// сложение числителей:
	if (fr1.Positive() == true && fr2.Positive() == true) {
		nom_tmp = fr1.Numerator() + fr2.Numerator();
	}
	else if (fr1.Positive() == false && fr2.Positive() == true) {
		nom_tmp = fr2.Numerator() - fr1.Numerator();
		if (fr1.Numerator() > fr2.Numerator()) {
			fr_tmp.Positive(false);
		}
		else { fr_tmp.Positive(true); }
	}
	else if (fr1.Positive() == true && fr2.Positive() == false) {
		nom_tmp = fr1.Numerator() - fr2.Numerator();
		if (fr2.Numerator() > fr1.Numerator()) {
			fr_tmp.Positive(false);
		}
		else { fr_tmp.Positive(true); }
	}
	else {
		nom_tmp = fr1.Numerator() + fr2.Numerator();
	}
	fr_tmp.Numerator(nom_tmp);
	fr_tmp.SetPos();
	fr_tmp = fr_tmp.ShortenFr(fr_tmp);	// сокращаем дробь
	return fr_tmp;
}

Fraction Fraction::SumWithNum(Fraction fr1, long long num) {
	Fraction fr_tmp;
	Fraction fr2;
	fr2.Numerator(fr1.Denominator() * num);
	fr2.Denominator(fr1.Denominator());
	if (num < 0) { fr_tmp.Positive(false); }

	fr_tmp = fr_tmp.Sum(fr1, fr2);
	return fr_tmp;
}

Fraction Fraction::Sub(Fraction fr1, Fraction fr2) {
	Fraction fr_tmp;
	long long nom_tmp{};		// числитель	
	// нахождение наименьшего общего знаменателя (НОК):
	if (fr1.Denominator() == fr2.Denominator()) {
		fr_tmp.Denominator(fr1.Denominator());
	}
	else if (fr1.Denominator() % fr2.Denominator() == 0 || fr2.Denominator() % fr1.Denominator() == 0) {
		if (fr1.Denominator() > fr2.Denominator()) {
			fr_tmp.Denominator(fr1.Denominator());
			fr2.Numerator(fr2.Numerator() * fr1.Denominator() / fr2.Denominator());
		}
		else if (fr2.Denominator() > fr1.Denominator()) {
			fr_tmp.Denominator(fr2.Denominator());
			fr1.Numerator(fr1.Numerator() * fr2.Denominator() / fr1.Denominator());
		}
	}
	else if (fr1.Denominator() > fr2.Denominator()) {
		for (int i = 2; i <= fr2.Denominator(); i++) {
			if ((fr1.Denominator() * i) % fr2.Denominator() == 0) {
				fr_tmp.Denominator(fr1.Denominator() * i);
				fr1.Numerator(fr1.Numerator() * i);
				fr2.Numerator(fr2.Numerator() * fr_tmp.Denominator() / fr2.Denominator());
				break;
			}
		}
	}
	else {
		for (int i = 2; i <= fr1.Denominator(); i++) {
			if ((fr2.Denominator() * i) % fr1.Denominator() == 0) {
				fr_tmp.Denominator(fr2.Denominator() * i);
				fr2.Numerator(fr2.Numerator() * i);
				fr1.Numerator(fr1.Numerator() * fr_tmp.Denominator() / fr1.Denominator());
				break;
			}
		}
	}
	// вычитание числителей:
	if (fr1.Positive() == true && fr2.Positive() == true) {
		nom_tmp = fr1.Numerator() - fr2.Numerator();
	}
	else if (fr1.Positive() == false && fr2.Positive() == true) {
		nom_tmp = fr1.Numerator() - fr2.Numerator();
	}
	else if (fr1.Positive() == true && fr2.Positive() == false) {
		nom_tmp = fr1.Numerator() + fr2.Numerator();
	}
	else {
		nom_tmp = fr1.Numerator() - fr2.Numerator();
	}
	fr_tmp.Numerator(nom_tmp);
	fr_tmp.SetPos();
	return fr_tmp;
}

Fraction Fraction::SubWithNum(Fraction fr1, long long num) {
	Fraction fr_tmp;
	Fraction fr2;
	fr2.Numerator(fr1.Denominator() * num);
	fr2.Denominator(fr1.Denominator());
	if (num < 0) { fr2.Positive(false); }
	fr_tmp = fr_tmp.Sub(fr1, fr2);
	return fr_tmp;
}

Fraction Fraction::Multi(Fraction fr1, Fraction fr2) {
	Fraction fr_tmp;
	long long nom_tmp{};	// числитель
	long long den_tmp{};	// знаменатель
	nom_tmp = fr1.Numerator() * fr2.Numerator();
	den_tmp = fr1.Denominator() * fr2.Denominator();
	fr_tmp.Numerator(nom_tmp);
	fr_tmp.Denominator(den_tmp);
	if (nom_tmp == 0) { return fr_tmp; }
	fr_tmp = fr_tmp.ShortenFr(fr_tmp);	// сокращаем дробь
	return fr_tmp;
}

Fraction Fraction::MultiWithNum(Fraction fr1, long long num) {
	Fraction fr_tmp;
	fr_tmp.Numerator(fr1.Numerator() * num);
	fr_tmp.Denominator(fr1.Denominator());
	SetPos();
	fr_tmp = fr_tmp.ShortenFr(fr_tmp);	// сокращаем дробь
	return fr_tmp;
}

Fraction Fraction::Divide(Fraction fr1, Fraction fr2) {
	Fraction fr_tmp;
	Fraction fr2_tmp = fr2;
	fr2_tmp.Numerator(fr2.Denominator());
	fr2_tmp.Denominator(fr2.Numerator());
	fr_tmp = fr_tmp.Multi(fr1, fr2_tmp);
	if (fr_tmp.Denominator() == 0) { throw std::exception("message"); }
	return fr_tmp;
}

Fraction Fraction::DivideWithNum(Fraction fr1, long long num) {
	Fraction fr_tmp;
	Fraction fr2;
	fr2.Numerator(num);
	fr2.Denominator(1);
	if (num < 0) { fr2.Positive(false); }
	fr_tmp = fr_tmp.Divide(fr1, fr2);
	return fr_tmp;
}

bool Fraction::simpleNum(long long num) {
	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	return false;
}

Fraction Fraction::ShortenFr(Fraction fr) {
	bool simple_nom = fr.simpleNum(fr.Numerator());		// статус числителя (false - непростое число, true - простое число)
	bool simple_den = fr.simpleNum(fr.Denominator());	// статус знаменателя
	if (simple_nom == true && simple_den == true) { return fr; }
	if (simple_nom == true) {
		if (fr.Denominator() % fr.Numerator() == 0) {
			fr.Denominator(fr.Denominator() / fr.Numerator());
			fr.Numerator(fr.Numerator() / fr.Numerator());
			return fr;
		}
	}
	if (simple_den == true) {
		if (fr.Numerator() % fr.Denominator() == 0) {
			fr.Numerator(fr.Numerator() / fr.Denominator());
			fr.Denominator(fr.Denominator() / fr.Denominator());
			return fr;
		}
	}
	for (int i = 2; i <= 9; i++) {
		if (i == 4 || i == 6 || i == 8) { continue; }
		if (fr.Numerator() % i == 0 && fr.Denominator() % i == 0) {
			fr.Numerator(fr.Numerator() / i);
			fr.Denominator(fr.Denominator() / i);
			i = 1;
			continue;
		}
	}
	return fr;
}


Fraction operator+(const Fraction& fr1, const Fraction& fr2)
{
	Fraction fr3;
	fr3 = fr3.Sum(fr1, fr2);
	return fr3;
}

Fraction operator+(const Fraction& fr1, long long num)
{
	Fraction fr3;
	fr3 = fr3.SumWithNum(fr1, num);
	return fr3;
}

Fraction operator-(const Fraction& fr1, const Fraction& fr2)
{
	Fraction fr3;
	fr3 = fr3.Sub(fr1, fr2);
	return fr3;
}

Fraction operator-(const Fraction& fr1, long long num)
{
	Fraction fr3;
	fr3 = fr3.SubWithNum(fr1, num);
	return fr3;
}

Fraction operator*(const Fraction& fr1, const Fraction& fr2){
	Fraction fr3;
	fr3 = fr3.Multi(fr1, fr2);
	return fr3;
}

Fraction operator*(const Fraction& fr1, long long num){
	Fraction fr3;
	fr3 = fr3.MultiWithNum(fr1, num);
	return fr3;
}

Fraction operator/(const Fraction& fr1, const Fraction& fr2){
	Fraction fr3;
	fr3 = fr3.Divide(fr1, fr2);
	return fr3;
}

Fraction operator/(const Fraction& fr1, long long num){
	Fraction fr3;
	fr3 = fr3.DivideWithNum(fr1, num);
	return fr3;
}

std::ostream& operator<<(std::ostream& out, const Fraction& obj){
	out << '(' << obj.numerator_ << '/' << obj.denominator_ << ')';
	return out;	
}

std::istream& operator>>(std::istream& inp, Fraction& obj){
	std::cout << "Введите числитель -> ";
	inp >> obj.numerator_;
	std::cout << "Введите знаменатель -> ";
	inp.ignore(1);
	inp >> obj.denominator_;
	return inp;	
}
