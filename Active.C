// Eight houses represented as cells, are arranged in a straight line. Each day every cell competes with its adjacent cells (neighbours). 
//  An Integer value of 1 represents an active cell and a value of 0 represents an inactive cell.
// If the neighbours on both the sides of a cell are active or inactive, the cell becomes inactive on the next day, otherwise the cell becomes active 
// The two cells on each end have a single adjacent cell, so assume that the unoccupied space on the opposite side is an inactive cell.
// Even after updating all the cell states, consider its previous state when updating the state of other cells.
// The state information of all cells should be updated simultaneously.
// Write an algorithm to output the state of the cells after the given number of days.
#include <iostream>
#include <iomanip>
// We need to find the state of cells after number of days
using namespace std;
int main()
{
	int days  = 0;
	cin >> days;
	// There are 8 cells
	
	int n = 0;
	cin >> n;
	n +=2;
	// Assume all the cells are active on first day
	int a[n];
	a[0] = 0;
	a[n-1] = 0;
	int i = 0;
	for(i = 1; i < n-1; ++i)
	{
		cin >> a[i]; 
	}
	int b[n] ;
	for(i = 0; i < n; ++i)
	{
		b[i] = a[i];
	}
	for(int  j = 0; j < days; ++j)
	{
		for(i = 1; i < n-1; ++i)
		{
			if( (a[i-1] == 0 && a[i+1] == 0) || ( a[i-1] == 1 && a[i+1] == 1 ) ) // both adjacent cells are either active or inactive
			{
				b[i] = 0;
			}
			else
			{
				b[i] = 1;
			}
		}
		for(i = 1; i < n-1; ++i)
		{
			a[i] = b[i];
		}
	}
	for(i = 1; i < n-1; ++i)
	{
		cout << a[i] << setw(3); 
	}
	cout << endl;
	return 0;
}
