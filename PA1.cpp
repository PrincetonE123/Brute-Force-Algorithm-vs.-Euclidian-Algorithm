/****************************************
PA-1-Source.cpp

Princeton Epeagba, J00701287
****************************************/

#include <iostream>
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
#include <chrono>     // Better time teller
#include <fstream>    // Imported library that allows for reading and writting files
#include <algorithm>  // Needed for sort function in median calculation

using namespace std;


void print(int pairs[][2], int gcd[], int time[], int size);
void printCSV(int pairs[][2], int gcd[], int time[], int size, const char* filename);
void printStatsCSV(double maxTime, double minTime, double avgTime, double medianTime, const char* filename);
int getRandomNumber(const int);
void bruteForceAlgV1(int pairs[][2], int gcd[], int time[]);
void bruteForceAlgV2(int pairs[][2], int gcd[], int time[]);
void EuclidAlgV1(int pairs[][2], int gcd[], int time[]);
void EuclidAlgV2(int pairs[][2], int gcd[], int time[]);
int calcGCDUp(int a, int b);
int calcGCDDown(int a, int b);
int euclidGCD(int a, int b);
int euclidGCDV2(int a, int b);
double calcMaxTime(int time[], int size);
double calcMinTime(int time[], int size);
double calcAverageTime(int time[], int size);
double calcMedianTime(int time[], int size);

int main() {
    srand(time(NULL));  // Random number (seed) generator
    const int NUM_PAIRS = 1000;  // Size of array. Changed manually
    int pairs[NUM_PAIRS][2]; // creates 2d array of size 1000
    int gcd[NUM_PAIRS];  // creates gcd array of size 1000
    int time[NUM_PAIRS];

    // Initialize with 1,000 random pairs of integers
    for (int i = 0; i < NUM_PAIRS; i++) {
        pairs[i][0] = getRandomNumber(1000);
        pairs[i][1] = getRandomNumber(1000);
    }

    auto start = chrono::high_resolution_clock::now();

    // Remove the comment block ("/* */") to use each algorithm

    // Brute Force Algorithm Version 1 
    
    bruteForceAlgV1(pairs, gcd, time);
    print(pairs, gcd, time, NUM_PAIRS);
    printCSV(pairs, gcd, time, NUM_PAIRS, "C:\\Users\\Princ\\Downloads\\bf_v1_results.csv");  // Manual save to location on PC. Must change for yours
    double maxTime = calcMaxTime(time, NUM_PAIRS);
    double minTime = calcMinTime(time, NUM_PAIRS);
    double avgTime = calcAverageTime(time, NUM_PAIRS);
    double medianTime = calcMedianTime(time, NUM_PAIRS);
    printStatsCSV(maxTime, minTime, avgTime, medianTime, "C:\\Users\\Princ\\Downloads\\bf_v1_statistics.csv");
    

    // Brute Force Algorithm Version 2
    /*
    bruteForceAlgV2(pairs, gcd, time);
    print(pairs, gcd, time, NUM_PAIRS);
    printCSV(pairs, gcd, time, NUM_PAIRS, "C:\\Users\\Princ\\Downloads\\bf_v2_results.csv");  // Manual save to location on PC. Must change for yours
    double maxTime = calcMaxTime(time, NUM_PAIRS);
    double minTime = calcMinTime(time, NUM_PAIRS);
    double avgTime = calcAverageTime(time, NUM_PAIRS);
    double medianTime = calcMedianTime(time, NUM_PAIRS);
    printStatsCSV(maxTime, minTime, avgTime, medianTime, "C:\\Users\\Princ\\Downloads\\bf_v2_statistics.csv");
    */

    // Euclid's Algorithm Version 1
    /*
    EuclidAlgV1(pairs, gcd, time);
    print(pairs, gcd, time, NUM_PAIRS);
    printCSV(pairs, gcd, time, NUM_PAIRS, "C:\\Users\\Princ\\Downloads\\oe_results.csv");  // Manual save to location on PC. Must change for yours
    double maxTime = calcMaxTime(time, NUM_PAIRS);
    double minTime = calcMinTime(time, NUM_PAIRS);
    double avgTime = calcAverageTime(time, NUM_PAIRS);
    double medianTime = calcMedianTime(time, NUM_PAIRS);
    printStatsCSV(maxTime, minTime, avgTime, medianTime, "C:\\Users\\Princ\\Downloads\\oe_statistics.csv");
    */

    // Euclid's Algorithm Version 2
    /*
    EuclidAlgV2(pairs, gcd, time);
    print(pairs, gcd, time, NUM_PAIRS);
    printCSV(pairs, gcd, time, NUM_PAIRS, "C:\\Users\\Princ\\Downloads\\se_results.csv");  // Manual save to location on PC. Must change for yours
    double maxTime = calcMaxTime(time, NUM_PAIRS);
    double minTime = calcMinTime(time, NUM_PAIRS);
    double avgTime = calcAverageTime(time, NUM_PAIRS);
    double medianTime = calcMedianTime(time, NUM_PAIRS);
    printStatsCSV(maxTime, minTime, avgTime, medianTime, "C:\\Users\\Princ\\Downloads\\se_statistics.csv");
    */

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Total Time: " << duration.count() << " nanoseconds" << endl;

    system("pause");

    return 0;
}

void bruteForceAlgV1(int pairs[][2], int gcd[], int time[]) {  // Starts at 1 and counts to min for GCD
    for (int i = 0; i < 1000; i++) {
        auto start = chrono::high_resolution_clock::now();

        int a = pairs[i][0];
        int b = pairs[i][1];
        gcd[i] = calcGCDUp(a, b);


        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        time[i] = duration.count();
    }
}

void bruteForceAlgV2(int pairs[][2], int gcd[], int time[]) {  // Counts down from min
    for (int i = 0; i < 1000; i++) {
        auto start = chrono::high_resolution_clock::now();

        int a = pairs[i][0];
        int b = pairs[i][1];
        gcd[i] = calcGCDDown(a, b);

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        time[i] = duration.count();
    }
}

void EuclidAlgV1(int pairs[][2], int gcd[], int time[]) {  // Euclid's Algorithm V1
    for (int i = 0; i < 1000; i++) {
        auto start = chrono::high_resolution_clock::now();

        int a = pairs[i][0];
        int b = pairs[i][1];
        gcd[i] = euclidGCD(a, b);

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        time[i] = duration.count();
    }
}

void EuclidAlgV2(int pairs[][2], int gcd[], int time[]) {  // Euclid's Algorithm V2
    for (int i = 0; i < 1000; i++) {
        auto start = chrono::high_resolution_clock::now();

        int a = pairs[i][0];
        int b = pairs[i][1];
        gcd[i] = euclidGCDV2(a, b);

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        time[i] = duration.count();
    }
}

int calcGCDUp(int a, int b) {
    int gcd = 1;

    for (int i = 1; i <= a && i <= b; ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int calcGCDDown(int a, int b) {
    int gcd = 1;
    int min = a;

    if (b < a) {
        min = b;
    }

    for (int i = min; i >= 1; --i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }

    return gcd;
}

int euclidGCD(int a, int b) {  // Greatest common demonitor for Euclid's Algorithm V1
    int remainder = 1;
    int quotient;

    if (a < 0) {
        a = a * -1;
    }

    if (b < 0) {
        b = b * -1;
    }

    while (0 != remainder) {
        quotient = (a / b);
        remainder = a - quotient * b;
        a = b;
        b = remainder;
    }

    return a;
}

int euclidGCDV2(int a, int b) {  // Greatest common denominator for Euclid's Algorithm V2
    int remainder = 1;
    int quotient;

    if (a < 0) {
        a = a * -1;
    }

    if (b < 0) {
        b = b * -1;
    }

    if (b >= a) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (0 != remainder) {
        remainder = a - b;

        if (remainder >= b) {
            remainder = remainder - b;
        }

        if (remainder >= b) {
            remainder = remainder - b;
        }

        if (remainder >= b) {
            remainder = a - b * (a / b);
        }

        a = b;
        b = remainder;
    }

    return a;
}

double calcMaxTime(int time[], int size) {
    int maxTime = time[0];

    for (int i = 1; i < size; i++) {
        if (time[i] > maxTime) {
            maxTime = time[i];
        }
    }

    return maxTime;
}

double calcMinTime(int time[], int size) {
    int minTime = time[0];

    for (int i = 1; i < size; i++) {
        if (time[i] < minTime) {
            minTime = time[i];
        }
    }

    return minTime;
}

double calcAverageTime(int time[], int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += time[i];
    }

    return sum / size;
}

double calcMedianTime(int time[], int size) {
    sort(time, time + size);

    if (size % 2 == 0) {
        return (time[size / 2 - 1] + time[size / 2]) / 2.0;
    }
    else {
        return time[size / 2];
    }
}

// Utilities
void print(int pairs[][2], int gcd[], int time[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Pairs:" << pairs[i][0] << "," << pairs[i][1] << " GCD:" << gcd[i] << " Time:" << time[i] << " nanoseconds" << "\n";
        cout << endl;
    }
}

void printCSV(int pairs[][2], int gcd[], int time[], int size, const char* filename) {
    ofstream csvFile(filename);

    if (!csvFile.is_open()) {
        cerr << "Error opening output file." << filename << endl;  // Checks for errors
        return;
    }

    // Excel headers
    csvFile << "Number One,Number Two,Their GCD,Time Spent (Nanoseconds)\n";

    // Written data
    for (int i = 0; i < size; i++) {
        csvFile << pairs[i][0] << "," << pairs[i][1] << "," << gcd[i] << "," << time[i] << "\n";
    }

    cout << "CSV file created: " << filename << endl;
    csvFile.close();
}

void printStatsCSV(double maxTime, double minTime, double avgTime, double medianTime, const char* filename) {
    ofstream csvStatsFile(filename);

    if (!csvStatsFile.is_open()) {
        cerr << "Error opening output file " << filename << endl;  // Checks for errors
        return;
    }

    // Excel headers
    csvStatsFile << "Statistic,Nanoseconds\n";
    csvStatsFile << "Maximum Time," << maxTime << "\n";
    csvStatsFile << "Minimum Time," << minTime << "\n";
    csvStatsFile << "Average Time," << avgTime << "\n";
    csvStatsFile << "Median Time," << medianTime << "\n";

    cout << "CSV file created for statistics: " << filename << endl;
    csvStatsFile.close();
}

int getRandomNumber(const int MY_RANGE) {
    int randNum = ((rand() % MY_RANGE) + 1);  // Generates a value between 1 and MY_RANGE
    return randNum;
}