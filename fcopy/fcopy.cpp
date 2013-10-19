// Fun project to implement copy for training purposes

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int copyFile(_TCHAR *fi1, _TCHAR *fi2){
	if(fi1 == NULL || fi2 == NULL){
		cout << "An error has occurred, please check your syntax";
		return 1;
	}

	FILE *f1,*f2;

	//fopen_s returns error number errno_t
	errno_t err1 = _tfopen_s(&f1, fi1, _TEXT("r"));

	//If file to copy does not exist error message is displayed and program halted
	if(err1 != 0){
		cout << "An error has occurred, please check your filepath and filename";
		return 1;
	}

	//fopen_s returns error number errno_t
	errno_t err2 = _tfopen_s(&f2, fi2, _TEXT("w"));

	if(err2 != 0){
		cout << "An error has occurred, please check your filepath and filename";
		return 1;
	}

	char c;

	while((c = fgetc(f1))!=EOF){
		fputc(c,f2);
	}

	fclose(f1);
	fclose(f2);

	return 0;
}

int _tmain(int argc, _TCHAR* argv[]){

	char *syntaxWarning = "Correct syntax for use is: fcopy file1 file2\n";

	if(argc == 1){
		cout << syntaxWarning;
		return 1;
	} else if(argc < 3){
		cout << "Invalid amount of parameters: " << (argc-1) << "\n" << syntaxWarning;
		return 1;
	} else if(argc >3){
		cout << "Excess amount of parameters which will be ignored\n" << syntaxWarning;
	}

	char input;
	_TCHAR *file1,*file2;

	file1 = argv[1];
	file2 = argv[2];

	copyFile(file1,file2);

	return 0;
}

