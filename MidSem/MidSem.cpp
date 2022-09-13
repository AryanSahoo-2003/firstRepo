#include <bits/stdc++.h>
#define inArr(a,n) {for(int i = 0;i<n;i++){cin>>a[i];}}
#define outArr(a,n) {for(int i = 0;i<n;i++){cout<<a[i];}}
using namespace std;
//for printing the elements of equal arrays if possible
void showArr(vector<int> list1, vector<int> list2);
//for getting the desired two equal array set
bool equalArr(int arr[], int n, vector<int>& list1,
   vector<int>& list2, int sum1, int sum2,
   int pos);

bool partition (int arr[], int n);

int main()
{ 
 int n;
 cin>>n;
 int arr[n];
 int sum=0;
 inArr(arr,n);
 if (n>100){
 cout<<"Sorry but you have exceeded the limit of number of elements"<<endl;}
 int mssg=0;
 for(int i=0;i<n;i++){sum+=arr[i];
 if(arr[i]>20){cout<<"The element value "<<arr[i]<<" has exceeded 20(number limit)"<<endl;
    mssg++;}
 }
 if(mssg==0&&n<=100){
    vector<int> list1, list2;
	if (partition(arr, n) == true){
		cout << "Such distribution is possible. One such possible distribution is as follows"<<endl;
		equalArr(arr, n, list1, list2, 0, 0, 0);}
	else{
		cout << "No such distribution is possible";}
 }
 return 0;
}

void showArr(vector<int> list1, vector<int> list2)
{
 cout<<"List1 :";
 for (vector<int>::iterator it = list1.begin() ; it != list1.end(); ++it)
    cout << " " << *it;

cout<<endl;

cout<<"List2 :";
 for (vector<int>::iterator it = list2.begin() ; it != list2.end(); ++it)
    cout << " " << *it;

 
}

bool equalArr(int arr[], int n, vector<int>& list1,
   vector<int>& list2, int sum1, int sum2,
   int pos)
{

 /// If entire array is traversed, compare both the sums.
 if (pos == n) {

  /// If sums are equal print both sets and return
  /// true to show sets are found.
  if (sum1 == sum2) {
   showArr(list1, list2);
   return true;
  }

  /// If sums are not equal then return sets are not
  /// found.
  else
   return false;
 }

 /// Add current element to set 1.
 list1.push_back(arr[pos]);

 /// Recursive call after adding current element to
 /// set 1.
 bool res = equalArr(arr, n, list1, list2, sum1 + arr[pos],
      sum2, pos + 1);

 /// If this inclusion results in equal sum sets
 /// partition then return true to show desired sets are
 /// found.
 if (res)
  return res;

 /// If not then backtrack by removing current element
 /// from list1 and include it in set 2.
 list1.pop_back();
 list2.push_back(arr[pos]);

 /// Recursive call after including current element to
 /// set 2.
 res = equalArr(arr, n, list1, list2, sum1,
    sum2 + arr[pos], pos + 1);
 if (res == false)
  list2.pop_back();

 return res;
}

bool partition (int arr[], int n)
{
	int sum = 0;
	int i, j;

	for (i = 0; i < n; i++)
	sum += arr[i];

	if (sum % 2 != 0)
	return false;

	bool part[n + 1][sum / 2 + 1];

	// initialize top row as false
	for (i = 0; i <= sum/2; i++)
        part[0][i] = false;

	// initialize leftmost column as true
	for (i = 0; i <= n; i++)
	part[i][0] = true;

	// Fill the partition table in botton up manner
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= sum/2; j++)
		{
			part[i][j] = part[i-1][j];
			if (j >= arr[i - 1])
			part[i][j]  |= 
						part[i - 1][j - arr[i -1]];

		}
	}

	return part[n][sum/2];
}


	
