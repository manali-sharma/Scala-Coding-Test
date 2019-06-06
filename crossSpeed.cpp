#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
 * crossingSpeeds - vector that stores speed with which people cross the bridge
 * totalPeople - the total number of people given as input
 *
 * crossingSpeeds is declared inside the heap memory instead of the stack memory to avoid
 * stackOverflow in case the input size is too large
 *
 * totalPeople is declared globally to make it accessible to all the modular functions
 * declared to solve the problem
 */
vector<int> crossingSpeeds;
int totalPeople;

/*
 * Method Name: minimum_time
 * Return type: void
 * Arguments: none
 * Description: to determine the minimum time require to cross a bridge by all of totalPeople
 */
void minimum_time() {
	int total_time_taken, i, bias;
	/*
	 * sort - an inbuilt function that sorts the input vector
	 * Sorting algorithm used by sort: quick sort
	 * Time complexity: O(nlogn)
	 */
	sort(crossingSpeeds.begin(),crossingSpeeds.end());
	cout << "Calculating answer...\n";
	/*
	 * Commercial code always have the constant term in the left of the comparison operator
	 * This is done in order to avoid semantic bugs in large codes
	 */
	if (0 == totalPeople) {
		/*
		 *  Corner case when the totalPeople=0
		 */
		cout << "Answer is : 0\n";
	} else if (1 == totalPeople || 2 == totalPeople) {
		/*
		 * Corner case when the totalPeople are only 2
		 */
		cout << "Answer is : " << crossingSpeeds[totalPeople - 1] << endl;
	} else {
		/*
		 * inline declaration in CPP used
		 * mintotal refers to the total calculated in scenario 1
		 * accumulate is an inbuilt CPP function which sums up all the elements from the given
		 * start and end point to a vector.
		 */
		total_time_taken = (totalPeople - 3) * crossingSpeeds[0] + accumulate(crossingSpeeds.begin(), crossingSpeeds.end(), 0);
		i = totalPeople;
		/*
		 * bias defined as the crossingSpeeds of the pair of fastest and second fastest +
		 * crossingSpeeds of the fastest to return +
		 * crossingSpeeds of the second fastest to return
		 */
		bias = 2 * crossingSpeeds[1] - crossingSpeeds[0];
		/*
		 * use approach 2 only if bias is smaller than the crossingSpeeds of the pair
		 */
		while (crossingSpeeds[i - 2] > bias) {
			/*
			 * subtract the faster time as the crossingSpeed of the pair would be the slower time
			 * of the two of the pair crossing together.
			 * Add the bias
			 * jump over every alternate node
			 */
			total_time_taken -= crossingSpeeds[i - 2] - bias;
			i = i - 2;
		}
		cout << "Answer is : " << total_time_taken << endl;
	}
}
/*
 * Method Name: main
 * Return type: int
 * Arguments: none
 * Description: entry point to any CPP program
 */
int main() {
	/*
	 * input file stream object creation to read from test.yaml file
	 */
	ifstream input("test.yaml");

	int tmp, i;
	/*
	 * input the value of the total number of people waiting to cross the bridge
	 */
	input>>totalPeople;
	i = totalPeople;
	crossingSpeeds.clear();
	while(i--) {
		/*
		 * input the value for the time required by each one of the people to cross the bridge
		 */
		input>>tmp;
		crossingSpeeds.push_back(tmp);
	}
	/*
	 * call to the function which calculates the minimum time required by all to cross the bridge
	 */
	minimum_time();
	return 0;
}

