#include <iostream>
#include <thread>

using namespace std;

int main()
{
    const int n = 12;
    int* arr = new int[n];
    double ans = 0;
    const int processor_count = thread::hardware_concurrency();
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10;
    }
#pragma omp parallel num_threads(processor_count) reduction(+:ans)
    {
#pragma omp for
        for (int i = 0; i < n; i++){
            ans += arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}
