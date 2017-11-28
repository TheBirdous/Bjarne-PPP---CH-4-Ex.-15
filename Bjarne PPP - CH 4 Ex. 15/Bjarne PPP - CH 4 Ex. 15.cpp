//This is a correction of a rather unwieldy interpretation of the Sieve of Erathostenes, done via the reccomended algorithm.

#include "../../std_lib_facilities.h"

int main()
{
	vector<int> is_prime = { 0, 0 };
	int num_primes = 0;
	int tracker = 0;
	bool stop = false;
	int check = 0;
	
	cout << "Enter how many primes you would like to print out: ";
	cin >> num_primes;
	
	for (int n = 0; stop == false; n++)
	{
		is_prime.push_back(1);
		tracker = 0;

		for (int i = 2; i < sqrt(is_prime.size()); i++)
		{
			if (is_prime[i] == 1)
				for (int j = i; j < is_prime.size(); j += i)
				{
					if (j > i)
					is_prime[j] = 0;
				}
		}
		for (int x : is_prime)
		{
			if (x == 1)
			{
				++tracker;
			}
		}

		if (tracker > num_primes)
		{
			stop = true;
		}

	}

	for (int i = 0; i < is_prime.size() - 1; i++)
	{
		if (is_prime[i] == 1)
		{
			check++;
			cout << i << '\n';
		}
			
	}
	cout << "Total number of primes: " << check << '\n';
	keep_window_open();

}