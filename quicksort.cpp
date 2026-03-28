#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int partition(vector<int>& a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
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
    quickSort(a, 0, a.size() - 1);
    clock_t end = clock();

    cout << "Quick Sort\n";
    cout << "Execution Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
