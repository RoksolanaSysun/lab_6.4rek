#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Create(int* a, const int n, const int Low, const int High, int index = 0) {
    if (index < n) {
        a[index] = Low + rand() * (High - Low) / RAND_MAX;
        Create(a, n, Low, High, index + 1);
    }
}

void Print(int* a, const int n, int index = 0) {
    if (index < n) {
        cout << setw(5) << a[index];
        Print(a, n, index + 1);
    }
    else {
        cout << endl;
    }
}

int CountInRange(int* a, const int n, const int A, const int B, int index = 0) {
    if (index >= n) {
        return 0;
    }
    int count = (a[index] >= A && a[index] <= B) ? 1 : 0;
    return count + CountInRange(a, n, A, B, index + 1);
}

double SumAfterMaxHelper(int* a, const int n, int& maxIndex, int currentIndex = 0) {
    if (currentIndex < n) {
        if (a[currentIndex] > a[maxIndex]) {
            maxIndex = currentIndex;
        }
        return SumAfterMaxHelper(a, n, maxIndex, currentIndex + 1);
    }
    return maxIndex;
}

double SumAfterMaxAfterIndex(int* a, const int n, int currentIndex) {
    if (currentIndex >= n) return 0;
    return a[currentIndex] + SumAfterMaxAfterIndex(a, n, currentIndex + 1);
}

double SumAfterMax(int* a, const int n) {
    if (n == 0) return 0;

    int maxIndex = 0;
    maxIndex = SumAfterMaxHelper(a, n, maxIndex);

    if (maxIndex == n - 1) {
        return 0;
    }

    return SumAfterMaxAfterIndex(a, n, maxIndex + 1);
}

void SortEvenDescending(int* a, int n, int i = 0, int j = 0) {
    if (i >= n - 1) return;
    if (a[i] % 2 == 0 && j < n) {
        if (a[j] % 2 == 0 && abs(a[j]) > abs(a[i])) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        SortEvenDescending(a, n, i, j + 1);
    }
    else {
        SortEvenDescending(a, n, i + 1, i + 2);
    }
}


int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    int A, B;
    cout << " A = ";
    cin >> A;
    cout << " B = ";
    cin >> B;

    auto* a = new int[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    Print(a, n);

    int count = CountInRange(a, n, A, B);
    cout << " [A, B] = " << count << endl;

    double sum = SumAfterMax(a, n);
    cout << "Sum after max element: " << sum << endl;

    SortEvenDescending(a, n);
    cout << "Array after sorting: " << endl;
    Print(a, n);

    delete[] a;
    return 0;
}