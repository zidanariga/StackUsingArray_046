#include <iostream>
#include <string>
using namespace std;

class program {
private:
	string stack_array[5];
	int top;

public:
	program() {
		top = -1;
	}

	string push(string element) {
		if (top == 4) {
			cout << "Stack Full" << endl;
			return "";
		}

		top++;
		stack_array[top] = element;

		cout << endl;
		cout << element << " Ditambahkan (pushed)." << endl;

		return element;

	}

	bool empty() {
		return (top == -1);
	}

	void pop() {
		if (empty()) {
			cout << "\nStack is empty. Cannot pop." << endl;
			return;
		}

		cout << "\nThe popped element is : " << stack_array[top] << endl;
		top--;
	}

	void display() {
		if (empty()) {
			cout << "\nStack is empty." << endl;
		}
		else {
			for (int tmp = top; tmp >= 0; tmp--) {
				cout << stack_array[tmp] << endl;
			}
		}
	}

};

int main() {
	program s;

	while (true) {
		cout << endl;
		cout << "\n***Stack Menu***" << endl;
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Display\n";
		cout << "4. Exit\n";
		cout << "\nEnter your choice (1-4) : ";
		string input;
		getline(cin, input);
		char ch = (input.empty() ? '0' : input[0]);
		switch (ch)
		{
		case '1': {
			cout << "Enter an Element : ";
			string element;
			getline(cin, element);
			s.push(element);
			break;
		}
		case '2': {
			if (s.empty()) {
				cout << "\nStack is empty." << endl;
				break;
			}
			s.pop();
			break;
		}
		case '3':
			s.display();
			break;
		case '4':
			return 0;
		default:
			cout << "\nInvalid option" << endl;
			break;
		}
	}
}