#include<iostream>
using namespace std;
int main(){
	
	int num, sum, floor, curr_floor;
	while( cin >> num, num )
	{
		floor = curr_floor = 0;
		while( num-- )
		{
			cin >> curr_floor;
			sum += ( curr_floor > floor ) ? 6 * ( curr_floor-floor ) : 4 * ( floor - curr_floor );
			sum += 5;
			floor = curr_floor;
		}
		cout << sum << endl;
	}
	return 1;
}