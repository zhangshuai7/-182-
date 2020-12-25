
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <stack.h>
using namespace std;

typedef long  LL;
const int SIZE = 1010;
char str[SIZE];
stack<char> OPERATOR;  // ������
stack<LL> OPERAND;     // ������

inline int get_priority(char ch) {
    switch (ch) {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case ')':
        return 3;
    }
}

inline LL calc() {
    LL b = OPERAND.top(); OPERAND.pop();
    LL a = OPERAND.top(); OPERAND.pop();
    char ch = OPERATOR.top(); OPERATOR.pop();

    switch (ch) {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
}

int main() {
    cin >> str;
    int priority_top, priority_cur;
    LL number;
    int i = 0, len = strlen(str)-1;
    while (i < len) {
        if (isdigit(str[i])) {
        	// ���������
            number = 0;
            while (i < len && isdigit(str[i])) {
            	// ��ȫ����
                number = number * 10 + (str[i] - '0');
                i++;
            }
            OPERAND.push(number);
        } else {
            if (OPERATOR.empty()) {
                OPERATOR.push(str[i]);
                i++;
                continue;
            }
            priority_top = get_priority(OPERATOR.top());
            priority_cur = get_priority(str[i]);
            if (priority_cur == 0) {
            	// ����������� (
                OPERATOR.push(str[i]);
                i++;
            } else if (priority_cur == 3) {
            	// ����������� )�����㵽��һ�������� ( �ڵı��ʽ��ֵ
                while (OPERATOR.top() != '(') {
                    number=calc();
                    OPERAND.push(number);
                }
                // ���������� )
                OPERATOR.pop();
                i++;
            } else {
                while (!OPERATOR.empty() && priority_cur <= priority_top) {
                	// ������в����������ҵ�ǰ���ŵ����ȼ��ϵ�
					// ��ô�����ȼ���ջ�����
                    number=calc();
                    OPERAND.push(number);
                    // ������в���������ȡ�����ȼ�
                    if (!OPERATOR.empty()) priority_top = get_priority(OPERATOR.top());
                }
                OPERATOR.push(str[i]);
                i++;
            }
        }
    }

    while (!OPERATOR.empty()) {
        number = calc();
        OPERAND.push(number);
    }

    cout << OPERAND.top() << endl;

    return 0;
}