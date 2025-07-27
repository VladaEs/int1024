#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>



class int_1024 {
	int size = 32;
	const int64_t BASE = 1'000'000'000;
	std::vector<std::int32_t> digits;
	bool isNegative = false; // true — number is negative, false — > 0
	const size_t numLength = 9; //max amount is 10 but for 'for' loops we will need 9
public:

	int_1024(const std::string &num) {
		digits.resize(size, 0);

		int block = 0; 
		int power = 1; 
		int digitCounter = 0; 
		int blockCounter = 0; 


		for (int i = num.length() - 1; i >= 0; i--) {
			char c = num[i];
			if (this->isNum(c) == true) {
				block += (c - '0')*power;
				power = power * 10;
				digitCounter = digitCounter + 1; 
				if (digitCounter == numLength) {
					digits[blockCounter] = block;
					blockCounter++; 
					block = 0;
					power = 1; 
					digitCounter = 0;
				}
			}

		}
		if (digitCounter > 0) {
			digits[blockCounter++] = block;
		}

	}
	void showNumbers() {
		for (int i = digits.size()-1; i >=0 ; i--) {
			if (isNegative) std::cout << "-";
			std::cout << digits[i];
		}
	}
	int_1024() {
		digits.resize(size, 0);
	}
	bool isNum(const char &number) {
		if (number > 47 && number < 58) {
			return true;
		}
		return false;
	}
	int_1024 &setDigit(int32_t num, int i) {
		if (i >= 0 && i < digits.size()) {
		}
		digits[i] = num;
		return *this;
	}
	int32_t getDigit(int i)const {
		if (i >= 0 && i < digits.size()) {
			return digits[i];
		}
		else {
			return 0;
		}
	}
	int_1024 operator+(const int_1024 &other) {
		int_1024 result;
		int carry = 0;
		for (int i = digits.size() - 1; i >= 0; i--) {
			int64_t sum = (int64_t)digits[i] + other.getDigit(i) + carry;

			carry = sum / BASE;
			result.setDigit(sum % BASE, i);
		}
		if (carry > 0) {
			
			std::cout << "Final carry (не обработан): " << carry << "\n";
		}

		return result;
	}
	bool operator >(const int_1024 &other) {
		bool res = false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == other.getDigit(i)) continue; 
			if (digits[i] > other.getDigit(i)) {
				res = true;
				break;
			}
			else if (digits[i] < other.getDigit(i)) {
				res = false;
				break;
			}
		}
		return res;
	}
	bool operator <(const int_1024 &other) {
		bool res = false;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == other.getDigit(i)) continue;
			if (digits[i] < other.getDigit(i)) {
				res = true;
				break;
			}
			else if (digits[i] > other.getDigit(i)) {
				res = false;
				break;
			}
		}
		return res;
	}
	bool operator ==(const int_1024 &other) {
		bool res = true;
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == other.getDigit(i)) continue;
			if (digits[i] != other.getDigit(i)) {
				res = false; 
				break;
			}
		}
		return res; 
	}

	int_1024 operator -(const int_1024 &other) {
		int_1024 result;
		int carry = 0;
		int64_t difference = 0;
		bool thisIsSmaller = *this < other; // false if 'this' > other
		bool negative = false;
		
		int64_t a = 0;
		int64_t b = 0 ;
		for (int i = digits.size() - 1; i >= 0; i--) {
			
			if (thisIsSmaller) {
				a = other.getDigit(i);
				b = digits[i];
			}
			else {
				a = digits[i];
				b = other.getDigit(i);
			}
			difference = a - b - carry;
			if (difference < 0) {
				difference = difference + BASE;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result.setDigit(difference, i);
		}
		result.isNegative = thisIsSmaller;
		return result;
	}

};

int main(){
	int_1024 test("123456745738095743895743992");
	int_1024 test2("12345674573809574389574389");

	//std::cout << log10(100)+ 1;
	//system("pause");
	int_1024 res = test + test2;
	test.showNumbers();
	std::cout << "\n";
	test2.showNumbers();
	std::cout << "\n";
	res.showNumbers();
	std::cout << "\n\n\n\n\n";

	int_1024 res2 = test2 - test;
	test.showNumbers();
	std::cout << "\n";
	test2.showNumbers();
	std::cout << "\n";
	res2.showNumbers();
	std::cout << "\n";

	

	int a = 0;
	std::cout << "aaa";
}



