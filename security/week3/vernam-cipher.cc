#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char key[100000];
int key_size = 0;

void encrypt(){
  srand(time(0));
  key_size = 0;
  fstream out, in;
  string infile, outfile;
  cout<<"ENTER FILE TO ENCRYPT: ";
  cin>>infile;
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
  cin>>outfile;
  out.open(outfile);
  if(!out){
    out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  }
  char c;
  int k;
  in >> std::noskipws;
  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else{
      k = key[key_size++] = std::rand();
      out<<char( (c ^ k));
    }
  }
  in.close();
  out.close();
  //save key
  out.open("key-otp.txt");
  if(!out){
    out.open("key-otp.txt", fstream::in | fstream::out | fstream::trunc);
  }
  for (int i = 0; i < key_size; i++) {
    out<<(key[i]);
  }
  cout<<endl;
  out.close();
}
void decrypt(){
  fstream out, in, key;
  string infile, outfile;
  cout<<"ENTER FILE TO DECRYPT: ";
  cin>>infile;
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  //key
  key.open("key-otp.txt");
  if(!key){
    cout<<"ERROR: key does not exists!\n";
    return;
  }

  cout<<"ENTER FILE TO SAVE OUTPUT TO: ";
  cin>>outfile;
  out.open(outfile);
  if(!out){
    out.open(outfile, fstream::in | fstream::out | fstream::trunc);
  }
  char c,k;
  // in.unsetf(std::ios_base::skipws);
  in >> std::noskipws;
  int i = 0;
  while(in.get(c)){
    if(c == '\n' || c == '\r')
      out<<'\n';
    else if(c == ' ')
      out<<' ';
    else{
      key.get(k);
      out<<char( (c ^ k));
    }
  }
  in.close();
  out.close();
}
void read_key(){
  fstream in;
  string infile;
  cout<<"ENTER FILE WHERE KEYS ARE STORED: ";
  cin>>infile;
  in.open(infile);
  if(!in){
    cout<<"ERROR: File does not exists!\n";
    return;
  }
  char c;
  int i = 0;
  in >> std::noskipws;
  while(in.get(c)){
    key[key_size++] = c;
  }
}
void show_key(){
  cout<<"KEY: ";
  for (int i = 0; i < key_size; i++) {
    cout<<key[i];
  }
  cout<<endl;
}
int main(int argc, char const *argv[]){
  while(1){
    cout<<"\n\n************* MENU *******************"<<endl;
    cout<<"(1) ENCRYPT FILE\n(2) DERYPT FILE\n(3) READ KEY \n(4) SHOW KEY\n\nchoice: ";
    int choice;
    cin>>choice;
    if(choice == 1)
      encrypt();
    else if(choice == 2)
      decrypt();
    else if(choice == 3)
      read_key();
    else if(choice == 4)
      show_key();
    else{
    cout<<"WRONG INPUT!!\n";break;
    }
  }
  return 0;
}
