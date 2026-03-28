#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (a[i] < a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= right) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
    {
        a[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& a, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
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
    mergeSort(a, 0, a.size() - 1);
    clock_t end = clock();

    cout << "Merge Sort\n";
    cout << "Execution Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
