#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void insertionSort(vector<int>& a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

vector<int> makeData(int n)
{
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100000;
    }
    return a;
}

int main()
{
    cout << "Name:Susmoy Chakraborty" <<endl<<"ID:C243245"<<endl;
    srand(time(0));
    int n;
    cin>>n;
    cout <<"When N="<<n<<endl;
    vector<int> a = makeData(n);

    clock_t start = clock();
    insertionSort(a);
    clock_t end = clock();

    cout << "Insertion Sort\n";
    cout << "Execution Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
