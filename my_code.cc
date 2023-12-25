#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void CreateAndFill(char *a);
void Read(char *a);
void FindPunctual(char *a);

int main(int argc, char *argv[]){
	if (argc != 2){
		cerr << "ERROR" << endl;
		exit(0);
	}
	
	Read(argv[1]);
	FindPunctual(argv[1]);
}

void CreateAndFill(char *a){
	string text;
	ofstream file(a);

	if (file.is_open()){
		cout << "File that you want to open is not exist, so lets create. Write a text in your file: ";
		getline(cin, text);
		file << text;
	}
	else{
		cerr << "ERROR" << endl;
	}
	file.close();
}

void Read(char *a){
	ifstream file(a);
	string text = "";
	string text1;

	if (!file.is_open()){

		CreateAndFill(a);

		ifstream file(a);

		getline(file, text);

		file.close();

		if (text.empty()){
			cout << "File is empty." << text;
		}
		cout << "Text in file: " << text;
		return;
	}

	while (!file.eof()){
		getline(file, text1);
		text += text1;
		text += " ";
	}

	if (text1.empty()){
		cout << "File is empty." << text << endl;
	} else {
		cout << "Text in file: " << text<<endl;
	}

	file.close();
}

void FindPunctual(char *a){

	ifstream file(a);
	char ch;
	int PunctuationCounter[13] = {0};
	int LengthOfText = 0;
	char punctuation[] = "!?.,()[]\":;- ";
	int existMark = 0;

	while (true){
		file >> noskipws >> ch; // noskipws використовується для того, щоб врахувати всі пробіли

		if (file.eof()){
			break;
		}

		LengthOfText++;

		for (size_t i = 0; i < sizeof(punctuation) - 1; i++){
			if (ch == punctuation[i])
			{
				existMark = 1;
				PunctuationCounter[i]++;
			}
		}
	}

	if(existMark == 0){
		cout << "Your file doesn't contain any punctuation marks." << endl;
	}else {
		cout << "\nHere a frequance of punctuatoin marks ->" << endl;
	}

	for (size_t i = 0; i < sizeof(PunctuationCounter) / sizeof(int); i++){
		if(PunctuationCounter[i] == 0) continue;
		existMark = 1;
		cout << punctuation[i] << ": " << PunctuationCounter[i] << " (" <<fixed<<setprecision(2)<< ((double)PunctuationCounter[i] / LengthOfText) * 100 << "%)" << endl;
	}

}