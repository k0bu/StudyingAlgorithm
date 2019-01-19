#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "HashDictionary.h"

#define L 14


void Hash() {
	int cmdNumber;
	char cmd[9], str[L];
	HashDictionary dictionary = HashDictionary();

	scanf_s("%d", &cmdNumber);

	for (int i = 0; i < cmdNumber; i++) {
		scanf_s("%s %s", cmd, 9, str, L);

		if (cmd[0] == 'i') {
			dictionary.Insert(str);
		}
		else {
			if (dictionary.FindFromHash(str)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
	

	return;
}