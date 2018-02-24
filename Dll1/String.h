#pragma once
class String {
	union {
		char* dataP;
		char dataA[16];
	};
	int length;
};

