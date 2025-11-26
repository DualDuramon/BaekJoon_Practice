#include<iostream>
#include<set>
#include<map>

using namespace std;

enum OrderType {
	add,
	rem,
	check,
	toggle,
	all,
	empty
};

void SetOrders(map<string,OrderType>& map) {
	map["add"] = OrderType::add;
	map["remove"] = OrderType::rem;
	map["check"] = OrderType::check;
	map["toggle"] = OrderType::toggle;
	map["all"] = OrderType::all;
	map["empty"] = OrderType::empty;
}

void SwapSet(set<int>& set1, bool isGong ){
	if (isGong) {
		set1.clear();
	}
	else {
		set1.insert({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });
	}
}

void Solve(const map<string,OrderType>& orderMap, set<int>& mySet, const string& order) {
	int num = 0;

	switch (orderMap.at(order)) {
	case OrderType::add:
		cin >> num;
		mySet.insert(num);
		break;
	case OrderType::rem:
		cin >> num;

		if (mySet.find(num) != mySet.end()) mySet.extract(num);
		break;
	case OrderType::check:
		cin >> num;
		if (mySet.find(num) != mySet.end()) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
		break;
	case OrderType::toggle:
		cin >> num;

		if (mySet.find(num) != mySet.end()) {
			mySet.extract(num);
		}
		else {
			mySet.insert(num);
		}
		break;
	case OrderType::all:
		SwapSet(mySet, false);
		break;

	case OrderType::empty:
		SwapSet(mySet, true);
		break;

	default:
		break;
	}

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n{ 0 };
	cin >> n;

	set<int> mySet;
	map<string, OrderType> orderMap;
	SetOrders(orderMap);


	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		Solve(orderMap, mySet, str);
	}


	return 0;
}