// Copyright 2021 Uskova
#include "postfix.h"

int prioritet(char sym) {
	int pri = -1;
	if ((sym == '*') || (sym == '/')) {
		pri = 3;
	} else {
		if ((sym == '+') || (sym == '-')) {
			pri = 2;
		} else {
			if (sym == ')') {
				pri = 1;
			} else {
				if (sym == '(') {
					pri = 0;
				}
			}
		}
	}
	return pri;
}


std::string infix2postfix(std::string input) {
    std::string output;
	MyStack<char> stack(1000);
	int pr_cur, pr = 0;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			if ((input[i] >= '0' && input[i] <= '9') || (input[i] == '.')) {
				output.push_back(input[i]);
				if (input[i] != '.' && input[i+1] != '.') {
					output.push_back(' ');
				}
			}
			else {
				pr_cur = prioritet(input[i]);
				if (pr_cur == -1)
					exit(-1);
				if (pr_cur == 1) {
					while (!stack.isEmpty()) {
						if (stack.get() != '(') {
							output.push_back(stack.pop());
							output.push_back(' ');
						}
						else {
							stack.pop();
						}
					}
				}
				else {
					if (!stack.isEmpty()) {
						pr = prioritet(stack.get());
						if (pr_cur == 0 || pr_cur > pr) {
							stack.push(input[i]);
						}
						else {
							while (!stack.isEmpty() && pr_cur <= pr) {
								output.push_back(stack.pop());
								output.push_back(' ');
								pr = prioritet(stack.get());
							}
							stack.push(input[i]);
						}
					}
					else {
						stack.push(input[i]);
					}
				}

			}
		}
	}
	while (!stack.isEmpty()) {
		output.push_back(stack.pop());
		output.push_back(' ');
	}
	output.erase(output.length());
	return output;
}