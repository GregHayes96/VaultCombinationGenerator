// vault combination generator, it takes two numbers form the user input and gives the total amount of permutations or combinations upon request

#include <iostream>

int factorial(int a) {
	for (int I = (a - 1); I > 0; --I) a *= I;
	return a;
}

//this takes two integers and calculates the amount of permutations for a safe combination that can be generated.
int permutations(int a, int b) {
	//precondition errors, numbers above 12 too large, below 1 too small
	if (a > 12) throw"Predcondition - number entered too large, too many combinations\n";
	if (a < 1 || b < 1) throw "Precondition - numbered entered too small, no combinations possible\n";

	int temp1 = factorial(a);
	if (a == b) { return temp1; } // solves the issue of division by 0 exception, stop a - b when they are the same value
	int temp2 = factorial((a - b));
	return (temp1 / temp2);
}

//this takes two integer values and calculates the amount of combinations that can be created from the two values
int combinations(int a, int b) {

	int temp1 = permutations(a, b);
	int temp2 = factorial(b);
	return (temp1 / temp2);
}

//simple print function
void print(int a,char b) {

	switch (b) {
	case 'P':
		std::cout<< "Total number of permutations: " << a << std::endl;
		break;
	case 'C':
		std::cout << "Total number of combinations: " << a << std::endl;
		break;
	default:
		throw "choice of permutations or combinations not recognised.";
	}
}

int main() {

	int num1{ 0 };
	int num2{ 0 };
	char Perm_or_comb;

	std::cout << "please give two integers and state either P or C(permutation or combination)\n";
	try {
		while (std::cin >> num1 >> num2 >> Perm_or_comb) {
			
			switch (Perm_or_comb) {
				case 'P':
					num1 = permutations(num1, num2);
				break;
				case 'C':
					num1 = combinations(num1, num2);
				break;
				default: throw "bad token - must enter P or C";
			}
			print(num1, Perm_or_comb);
		}
		throw"Error, incorrect input. must be two numbers and both whole numbers entered.";
	}
	catch (const char* txtException) {
		std::cerr << "Exception: " << txtException;
		return 1;
	}
	catch (...) {
		std::cerr << "Exception: unknown error";
		return 2;
	}
}