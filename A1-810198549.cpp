#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void write_file_encrypting(vector<int>&file);
void read_file_encrypting(vector<char>&file);
void write_file_decrypting(vector<char>&file);
void read_file_decrypting(vector<int>&file);
int choosing_option(void);
int simple_encrypt(void);
int simple_decrypt(void);
int complicated_encrypt(void);
int complicated_decrypt(void);
int convert_key_to_vector(vector<char>&key);
int main (){
	int choice=choosing_option();
	if(choice== 1 || 2){
		if(choice==1){
			int choice=choosing_option();
			if(choice==3)
			simple_encrypt();
			if(choice==4)
			complicated_encrypt();
		}
		if(choice==2){
			int choice=choosing_option();
			if(choice==3)
			simple_decrypt();
			if(choice==4)
			complicated_decrypt();
		}
	}
	return 0;
}
int choosing_option(void){
 string choice;
 cin>>choice;
 if(choice=="encrypt") return 1;
 else if(choice=="decrypt") return 2;
 else if(choice=="simple") return 3;
 else if(choice=="complicated") return 4;
 return 0;
}
void read_file_decrypting(vector<int>&file){
	int temp;
	string file_address;
	cin>>file_address;
	ifstream myfile;
	myfile.open(file_address);
	if (myfile.is_open()){
	while(!myfile.eof()){
	myfile>>temp;
	file.push_back(temp);
}
file.pop_back();
}
myfile.close();
}
void read_file_encrypting(vector<char>&file){
	char temp;
	string file_address;
	cin>>file_address;
	ifstream myfile;
	myfile.open(file_address);
	if (myfile.is_open()){
	while(!myfile.eof()){
	myfile.get(temp);
	file.push_back(temp);
}
file.pop_back();
}
myfile.close();
}
void write_file_encrypting(vector<int>&file){
	string file_address;
		cin>>file_address;
	ofstream myfile(file_address);
	if (myfile.is_open()){
 for(int i=0;i<file.size();i++){

	 myfile<<file[i]<<endl;
 }
 myfile<<endl;
}
myfile.close();
}
void write_file_decrypting(vector<char>&file){
	string file_address;
		cin>>file_address;
	ofstream myfile(file_address);
	if (myfile.is_open()){
 for(int i=0;i<file.size();i++){
	 myfile<<file[i];
 }
}
myfile.close();
}
int simple_encrypt(void){
  int i=0,j=0,h=0,temp;
	string key;
	cin>>key;
	i=key.size();
	vector<char>file;
	vector<int>encrypted;
read_file_encrypting(file);
for(;j<file.size();j++){
	if(h<i){
		temp=(int)key[h];
		temp+=(int)file[j];
	encrypted.push_back(temp);
	h++;
 if(h==i){
	 h=0;
 }
}
}
write_file_encrypting(encrypted);
file.clear();
key.clear();
encrypted.clear();
return 1;
}
int simple_decrypt(void){
	int i=0,h=0,j=0;
	char temp;
	string key;
	vector<int>file;
	vector<char>decrypted;
	cin>>key;
	i=key.size();
read_file_decrypting(file);
for(;j<file.size();j++){
	if(h<i){
		temp=file[j]-(int)key[h];
	decrypted.push_back(temp);
	h++;
}
 if(h==i){
	 h=0;
 }
}
write_file_decrypting(decrypted);
file.clear();
key.clear();
decrypted.clear();
return 1;
}
int complicated_encrypt(void){
	int i=0,h=0,p=0,sum=0;
	string key;
	vector<char>file;
	vector<int>encrypted;
	cin>>key;
	i=key.size();
	read_file_encrypting(file);
  for(;h<i;h++){
		sum+=(int)key[h];
	}
srand(sum);
for(;p<file.size();p++){
	sum=(int)file[p];
	sum+=rand()%11;
	encrypted.push_back(sum);
}
write_file_encrypting(encrypted);
file.clear();
key.clear();
encrypted.clear();
return 1;
}
int complicated_decrypt(void){
	int i=0,h=0,p=0,sum=0;
	string key;
	vector<int>file;
	vector<char>decrypted;
	cin>>key;
	i=key.size();
 	read_file_decrypting(file);
	for(;h<i;h++){
		sum+=(int)key[h];
	}
srand(sum);
for(;p<file.size();p++){
	sum=file[p];
	sum-=rand()%11;
	decrypted.push_back(sum);
}
write_file_decrypting(decrypted);
file.clear();
key.clear();
decrypted.clear();
return 1;
}
