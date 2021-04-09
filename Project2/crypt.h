#pragma once
#ifndef CRYPT_H_
#define CRYPT_H_
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include <WinSDKVer.h>
#include <stdlib.h>
#include <time.h>
#include "loadcpu.h"
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include <msclr\marshal_windows.h>
#include <msclr\marshal_atl.h>

using namespace std;
using namespace System;
using namespace msclr::interop;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;

public ref class Crypting
{
public:
	CPULoad ^CPUinfo = gcnew CPULoad;
	String ^infiletxt;
	String ^keytxt;
	int numofChar;
public:
	Crypting()
	{
		infiletxt = L"";
		keytxt = L"";
	}
	void SetInfile(String ^txt)
	{
		this->infiletxt = txt;
	}
	void SetKey(String ^txt)
	{
		this->keytxt = txt;
	}
	String^ GetInfile()
	{
		return infiletxt;
	}
	String^ GetKey()
	{
		return keytxt;
	}

	void FileLenght()
	{
		string line;
		int numChar = 0;
		ifstream inData;
		string str2 = marshal_as<string>(GetInfile());
		inData.open(str2);

		while (!inData.eof())
		{
			getline(inData, line);
			int numofChars = line.length();
			numofChar = numChar + numofChars;
		}
	}

	void Encrypt(ProgressBar ^bar)
	{
		ifstream infile;
		ofstream key;
		ofstream outfile;
		string str;
		string str1 = marshal_as<string>(GetKey());
		string str2 = marshal_as<string>(GetInfile());

		bar->Minimum = 0;
		bar->Maximum = numofChar;
		bar->Increment(1);
		bar->Increment(1);
		bar->Increment(1);
		key.open(str1);
		infile.open(str2);
		outfile.open("temp.txt");
		while (!infile.eof())
		{
			getline(infile, str);
			for (int i = 0; i < str.length(); i++)
			{
				int random = CPUinfo->GetCPULoad() * 100;
				Sleep(100);
				key << random << " ";
				str[i] += random;
				outfile << str[i];
				bar->Increment(1);
			}
		}
		infile.close();
		bar->Increment(1);
		key.close();
		bar->Increment(1);
		outfile.close();
		bar->Increment(1);
		remove(str2.c_str());
		bar->Increment(1);
		rename("temp.txt", str2.c_str());
		bar->Increment(1);

	}
	void Decrypt(ProgressBar ^bar)
	{
		string str;
		ifstream infile;
		ifstream key;
		ofstream outfile;
		int current_key;
		string str1 = marshal_as<string>(GetKey());
		string str2 = marshal_as<string>(GetInfile());

		bar->Minimum = 0;
		bar->Maximum = numofChar;
		infile.open(str2);
		key.open(str1);
		outfile.open("temp.txt");
		while (!infile.eof())
		{
			getline(infile, str);
			for (int i = 0; i < str.length(); i++)
			{
				key >> current_key;
				str[i] -= current_key;
				outfile << str[i];
				bar->Increment(1);
			}
		}
		infile.close();
		key.close();
		outfile.close();
		remove(str1.c_str());
		remove(str2.c_str());
		rename("temp.txt", str2.c_str());
	}
};
#endif