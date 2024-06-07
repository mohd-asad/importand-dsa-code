#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

class Compare {
public:
	bool operator()(PII below, PII above)
	{
		if (below.first > above.first) {
			return true;
		}
		else if (below.first == above.first
				&& below.second < above.second) {
			return true;
		}

		return false;
	}
};

int main()
{
	priority_queue<PII, vector<PII>, Compare> ds;
	ds.push({ 100, 11 });
	ds.push({ 100, 41 });
	ds.push({ 100, 21 });
	ds.push({ 300, 1 });
	ds.push({ 300, 2 });
	ds.push({ 1, 1 });
	ds.push({ 1, 2 });
	ds.push({ 1, 20 });

	cout << "The priority queue is : \n";
	while (!ds.empty()) {
		cout << ds.top().first << " " << ds.top().second
			<< "\n";
		ds.pop(); 
	}

	return 0;
}

// 1 20
// 1 2
// 1 1
// 100 41
// 100 21
// 100 11
// 300 2
// 300 1
