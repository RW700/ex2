/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int choice = 0;
	int run = 1;

	while (run == 1) {
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("\n%d", &choice);
		if (choice == 1) {
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/

			char eyeChar, noseChar, mouthChar;
			int faceSize = 0;
			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf("\n%c %c %c", &eyeChar, &noseChar, &mouthChar);
			printf("Enter face size:\n");
			scanf("\n%d", &faceSize);
			while ((faceSize <= 0) || (faceSize % 2 != 1)) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%*[^\n]");
				scanf("\n%d", &faceSize);
			}
			printf("%c", eyeChar);
			for (int i = 0; i < faceSize; i++) {
				printf(" ");
			}
			printf("%c\n", eyeChar);
			for (int i = 0; i < ((faceSize+1)/2); i++) {
				printf(" ");
			}
			printf("%c\n", noseChar);
			printf("\\");
			for (int i = 0; i < faceSize; i++) {
				printf("%c", mouthChar);
			}
			printf("/\n");
		}
		else if (choice == 2) {
			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
				/* Examples:
				Balanced: 1533, 450810, 99
				Not blanced: 1552, 34
				Please notice: the number has to be bigger than 0.
				*/
			int harmonyNum = 0;
			printf("Enter a number:\n");
			scanf("\n%d", &harmonyNum);
			while (harmonyNum <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%*[^\n]");
				scanf("\n%d", &harmonyNum);
			}
			int harmonyNumDupl = harmonyNum;
			int length = 0;
			while (harmonyNumDupl > 0) {
				length++;
				harmonyNumDupl /= 10;
			}
			int powerOfTen = 1;
			int firstHalf, secondHalf, firstHalfSum, secondHalfSum;
			if (length % 2 == 1) {
				for (int i = 0; i <= length / 2; i++) {
					powerOfTen *= 10;
				}
				firstHalf = harmonyNum / powerOfTen;
				firstHalfSum = 0;
				int firstHalfPow = powerOfTen / 10;
				for (int i = length / 2; i >= 0; i--) {
					firstHalfSum += firstHalf / firstHalfPow;
					firstHalf %= firstHalfPow;
					firstHalfPow /= 10;
				}
				secondHalf = harmonyNum % (powerOfTen / 10);
				secondHalfSum = 0;
				int secondHalfPow = powerOfTen / 10;
				for (int i = length / 2; i >= 0; i--) {
					secondHalfSum += secondHalf / secondHalfPow;
					secondHalf %= secondHalfPow;
					secondHalfPow /= 10;
				}
			} else {
				for (int i = 0; i < length / 2; i++) {
					powerOfTen *= 10;
				}
				firstHalf = harmonyNum / powerOfTen;
				secondHalf = harmonyNum % powerOfTen;
				firstHalfSum = 0;
				int firstHalfPow = powerOfTen / 10;
				for (int i = length / 2; i > 0; i--) {
					firstHalfSum += firstHalf / firstHalfPow;
					firstHalf %= firstHalfPow;
					firstHalfPow /= 10;
				}
				secondHalfSum = 0;
				int secondHalfPow = powerOfTen / 10;
				for (int i = length / 2; i > 0; i--) {
					secondHalfSum += secondHalf / secondHalfPow;
					secondHalf %= secondHalfPow;
					secondHalfPow /= 10;
				}
			}
			if (firstHalfSum == secondHalfSum) {
				printf("This number is balanced and brings harmony!\n");
			} else {
				printf("This number isn't balanced and destroys harmony.\n");
			}
		}
		else if (choice == 3) {
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
			int generousNum = 0;
			printf("Enter a number:\n");
			scanf("\n%d", &generousNum);
			while (generousNum <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%*[^\n]");
				scanf("\n%d", &generousNum);
			}
			int sumOfDivisors = 0;
			for (int i = 1; i < generousNum; i++) {
				if (generousNum % i == 0) {
					sumOfDivisors += i;
				}
			}
			if (sumOfDivisors > generousNum) {
				printf("This number is generous!\n");
			} else {
				printf("This number does not share.\n");
			}
		}
		else if (choice == 4) {
			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			int primeNum = 0;
			printf("Enter a number:\n");
			scanf("\n%d", &primeNum);
			while (primeNum <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%*[^\n]");
				scanf("\n%d", &primeNum);
			}
			int isPrime = 1;
			if (primeNum == 1) {
				isPrime = 0;
			}

			for (int i = 2; i < primeNum; i++) {
				if (primeNum % i == 0) {
					isPrime = 0;
					break;
				}
			}
			if (isPrime == 1) {
				printf("This number completes the circle of joy!\n");
			} else {
				printf("The circle remains incomplete.\n");
			}
		}
		else if (choice == 5) {
			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			int happyNum = 0;
			printf("Enter a number:\n");
			scanf("\n%d", &happyNum);
			while (happyNum <= 0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%*[^\n]");
				scanf("\n%d", &happyNum);
			}
			printf("Between 1 and %d only these numbers bring happiness: ", happyNum);
			if (happyNum == 1) {
				printf("1\n");
				break;
			}
			for (int i = 1; i < happyNum; i++) {
				int holder = i;
				int seenNumbers[10000] = {0};
				int solved = 1;
				while (solved == 1) {
					int sum = 0;
					while (holder > 0) {
						sum += (holder % 10) * (holder % 10);
						holder /= 10;
					}
					if (sum == 1)
					{
						printf("%d ", i);
						solved = 0;
					}
					if (seenNumbers[sum] == 1) {
						solved = 0;
					}
					seenNumbers[sum] = 1;
					holder = sum;
				}
			}
			printf("\n");

		}
		else if (choice == 6) {
			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			int smileNum = 0, cheerNum = 0, maximumNum = 0;
			int loopHolder = 1;
			printf("Enter a smile and cheer number:\n");

			while (loopHolder != 0) {
				if (scanf("\nsmile: %d, cheer: %d", &smileNum, &cheerNum)) {
					if (cheerNum > 0 && smileNum > 0 && cheerNum != smileNum) {
						loopHolder = 0; // Exit the loop
					} else {
						printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					}
				} else {
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					// char buffer[100];
					// while (scanf("%c", buffer) == 1 );
					scanf("%*[^\n]");
				}
			}
			scanf("%*[^\n]");

			printf("Enter maximum number for the festival:\n");
			scanf("\n%d", &maximumNum);
			while (maximumNum <= 0) {
				printf("Only positive maximum number is allowed, please try again:\n");
				scanf("%*[^\n]");
				scanf("\n%d", &maximumNum);
			}
			for (int i = 1; i < maximumNum; i++) {
				if ( (i % smileNum == 0) && (i % cheerNum == 0) ) {
					printf("Festival!\n");
				} else if ( i % cheerNum == 0 ) {
					printf("Cheer!\n");
				} else if ( i % smileNum == 0 ) {
					printf("Smile!\n");
				} else {
					printf("%d\n", i);
				}
			}


		}
		else if (choice == 7) {
			printf("Thank you for your journey through Numeria!\n");
			run = 0;
		}
		else {
			printf("This option is not available, please try again.\n");
		}
		choice = 0;
		scanf("%*[^\n]");
	}

	return 0;
}
