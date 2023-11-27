#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;

long gettime()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec*1000000+start.tv_usec;
}

int main() 
{
    long start = gettime();
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<vector<int> > matrix(n, vector<int>(n));
    vector<int> ascendingOrder(n);
    vector<int> descendingOrder(n);
    for(int i = 0; i < n; i++) 
    {
        int pos = 0;
        for(int j = 0; j < n; j++) 
        {
            matrix[i][j] = arr[i] - arr[j];
            if(matrix[i][j] > 0) 
            {
                pos++;
            }
        }
        ascendingOrder[i] = (pos);
        descendingOrder[i] = (n - pos - 1);
    }
    cout<<"The matrix is as follows : "<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Count values > 0 of each number for arranging in ASCENDING ORDER : "<<endl;
    for(int i = 0; i < n; i++) 
    {
        cout<<ascendingOrder[i]<<" ";
    }
    cout<<endl;
    cout<<"Count values < 0 of each number for arranging in DESCENDING ORDER : "<<endl;
    for(int i = 0; i < n; i++) 
    {
        cout<<descendingOrder[i]<<" ";
    }
    cout<<endl;
    vector<int> sorting(n);
    priority_queue<int, vector<int>, greater<int> > pqKey;
    priority_queue<int, vector<int>, greater<int> > pqValue;
    for(int i = 0; i < n; i++) 
    {
        pqKey.push(ascendingOrder[i]);
        pqValue.push(arr[i]);
    }
    int prev = -1;
    while(!pqKey.empty()) 
    {
        if(pqKey.top() <= prev) 
        {
            ++prev;
            sorting[prev] = pqValue.top();
        }
        else 
        {
            sorting[pqKey.top()] = pqValue.top();
            prev = pqKey.top();
        }
        pqKey.pop();
        pqValue.pop();
    }
    cout<<"Sorted Order : "<<endl;
    for(int i = 0; i < n; i++) 
    {
        cout<<sorting[i]<<" ";
    }
    cout<<endl;
    vector<int> reverseSorting(n);
    priority_queue<int> RpqKey;
    priority_queue<int> RpqValue;
    for(int i = 0; i < n; i++) 
    {
        RpqKey.push(descendingOrder[i]);
        RpqValue.push(arr[i]);
    }
    prev = n;
    while(!RpqKey.empty()) 
    {
        if(RpqKey.top() >= prev) 
        {
            --prev;
            reverseSorting[prev] = RpqValue.top();
        }
        else 
        {
            reverseSorting[RpqKey.top()] = RpqValue.top();
            prev = RpqKey.top();
        }
        RpqKey.pop();
        RpqValue.pop();
    }
    cout<<"Reverse Sorted Order : "<<endl;
    for(int i = n - 1; i >= 0; i--) 
    {
        cout<<reverseSorting[i]<<" ";
    }
    cout<<endl;
    long end = gettime();
    cout << endl;
    cout << "Seek time = " << start - end;

}