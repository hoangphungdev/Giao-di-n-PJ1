// Phung Manh Hoang 20215385
// Problem: Sum Array
#include <iostream>

using namespace std;

int main()
{
    int n_85;
    int a_85[100000];
    int sum_85 = 0;
    cin >> n_85; // Nhap n

    for (int i = 0; i < n_85; i++)
    {
        cin >> a_85[i];
        sum_85 += a_85[i]; // Tinh tong tung phan tu cua mang
    }
    cout << sum_85; // In tong phan tu cua mang
}