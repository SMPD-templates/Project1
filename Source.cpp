#include"Header.h"
#include<stack>
using std::stack;
int main() {

	Stack<int>a;
	a.push(6);
	a = a;
	cout << a.top() << '\n';




}