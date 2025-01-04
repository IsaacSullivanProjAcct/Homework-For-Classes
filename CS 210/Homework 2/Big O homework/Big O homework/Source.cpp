#include <iostream>
#include <fstream>
#include "Timer.h"

using namespace std;
void o_n(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += i;
	}
}
void n_logn(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j *= 2) {
			int x = i * j;
		}
	}
}
void n_squared(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = i * j;
		}
	}
}
void n_cubed(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int x = i * j * k;
			}
		}
	}
}
int main() 
{
    const int n_test = 7;
    int test_values[n_test] = { 1, 10, 50, 100, 200, 500, 1000 };

    // Creates the output file for writing timings and returns error if it is not created
    ofstream outFile("times.txt");
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return -1;
    }

    outFile << "N value lowest, O(N) time, O(N*log(N)) time, O(N^2) time, O(N^3) time" << endl;

    for (int i = 0; i < n_test; ++i) 
    {
        int N = test_values[i];

        Timer timerON;
        o_n(N);
        double timeON = timerON.get_elapsed();

        Timer timerNLogN;
        n_logn(N);
        double timeNLogN = timerNLogN.get_elapsed();

        Timer timerNSquared;
        n_squared(N);
        double timeNSquared = timerNSquared.get_elapsed();

        Timer timerNCubed;
        n_cubed(N);
        double timeNCubed = timerNCubed.get_elapsed();

        outFile << N << ", " << timeON << ", " << timeNLogN << ", " << timeNSquared << ", " << timeNCubed << endl;
    }

    outFile << "N value highest, O(N) time, O(N*log(N)) time, O(N^2) time, O(N^3) time" << endl;

    outFile.close();
    cout << "Time saved to times.txt" << endl;

    return 0;
}