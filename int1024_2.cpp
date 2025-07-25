#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class int_1024 {
	int size = 32;
	std::vector<std::int32_t> digits;
	bool  sign;
	const int32_t max = ((1 << 30) - 1) * 2 + 1;
	const int32_t min = -((1 << 30) - 1) * 2 - 2;
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

};

int main()
{
	int_1024 test("1234567457380 9 57438 9574389");
	test.showNumbers();


	int a = 0;
	std::cout << "aaa";
}

