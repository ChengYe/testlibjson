// testlibjson.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdlib.h>
#include "TestLibjson.h"
#include "JSONParser.h"
#include "libjson.h"
#include <fstream>
#include <iostream>
using namespace std;

#define CHARLENGTH 64

void Print(const char *chr)
{
	printf("%s\n", chr);
}

void encode(json_char* des, json_char* jchr)
{
	json_char* dotpos = wcschr(jchr, L'.');
	size_t len = wcslen(jchr);
	wcsncpy(des, jchr,dotpos - jchr);
	des[dotpos - jchr] = '\0';
	wcscat(des, ++dotpos);
}

int sizeoffile(wifstream& jsonfile)
{
	jsonfile.seekg(0, ios::end);
	int filesize = jsonfile.tellg();
	jsonfile.seekg(0, ios::beg);

	return filesize;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "chs");

	////TestLibjson example
	//json_char *json = L"{\"RootA\":\"Value in parent node\",\"ChildNode\":{\"ChildA\":\"String Value\",\"ChildB\":42},\"testnode\":[\"testvalue1\",\"testvalue2\"]}";
	//JSONNODE *n = json_parse(json);  
	//TestLibjson t = TestLibjson();  
	//t.ParseJSON(n);  
	//json_delete(n);

	////wchar_t to char conversion
	//json_char *wchr = L"\u5e7d\u7075\u5c0f\u5df4";
	//size_t converted;
	//char chr[CHARLENGTH];
	//wcstombs_s(&converted, chr, CHARLENGTH, wchr, _TRUNCATE);
	////char *chr = "whatthe福彩看";
	//Print(chr);

	////JSONParser test example
	//wifstream jsonfile("test.json");
	//if (jsonfile == NULL)
	//	cout<<"failed to read json file"<<endl;
	//int filesize = sizeoffile(jsonfile);
	//json_char *pJSON = new json_char[filesize+1];
	//jsonfile.read(pJSON, filesize);
	//pJSON[filesize]='\0';
	//wcout<<pJSON<<endl;
	//JSONNODE *file_n = json_parse(pJSON);
	//JSONParser file_t = JSONParser();
	//file_t.Parse(file_n);
	//json_delete(file_n);
	//delete pJSON;

	////JSONParser example
	//wifstream jsonfile("p2.json");
	//if (jsonfile == NULL)
	//	cout<<"failed to read json file"<<endl;
	//int filesize = sizeoffile(jsonfile);
	//json_char *pJSON = new json_char[filesize+1];
	//jsonfile.read(pJSON, filesize);
	//pJSON[filesize]='\0';
	////wcout<<pJSON<<endl;
	//JSONNODE *file_n = json_parse(pJSON);
	//JSONParser file_t = JSONParser();
	//file_t.Parse(file_n);
	//json_delete(file_n);
	//delete pJSON;

	json_char* jchr = L"wtf.png";
	//json_char des[CHARLENGTH];
	json_char des[CHARLENGTH];
	encode(des, jchr);
	wcout<<des<<wcslen(des)<<endl;

	return 0;
}
