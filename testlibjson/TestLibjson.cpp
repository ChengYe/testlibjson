#include "stdafx.h"
#include "TestLibjson.h"
#include "libjson.h"
#include <iostream>
using namespace std;

TestLibjson::TestLibjson()//构造函数
{
}

void TestLibjson::ParseJSON(JSONNODE *n){//解析json文件
    if (n == NULL){
        cout<<"Invalid JSON Node"<<endl;
        return;
    }

    JSONNODE_ITERATOR i = json_begin(n);
    while (i != json_end(n)){
        if (*i == NULL){
            cout<<"Invalid JSON Node"<<endl;
            return;
        }

        // get the node name and value as a string
        json_char *node_name = json_name(*i);

        // find out where to store the values
        if (wcscmp(node_name, L"RootA") == 0){
            json_char *node_value = json_as_string(*i);
			wcout<<L"RootA: "<<node_value<<endl;
            //wprintf(L"rootA: %s\n", node_value);
            json_free(node_value);
        }
        else if (wcscmp(node_name, L"ChildA") == 0){
            json_char *node_value = json_as_string(*i);
            wcout<<L"ChildA: "<<node_value<<endl;
			//wprintf(L"ChildA: %s\n", node_value);
            json_free(node_value);
        }
        else if (wcscmp(node_name, L"ChildB") == 0)
            wcout<<L"ChildB: "<<json_as_int(*i)<<endl;
			//wprintf(L"ChildB: %d\n", json_as_int(*i));

		else if (wcscmp(node_name, L"ChildNode") == 0)
			cout<<"ChildNode"<<endl;

		// recursively call ourselves to dig deeper into the tree
        if (json_type(*i) == JSON_ARRAY || json_type(*i) == JSON_NODE){
            ParseJSON(*i);
        }

        // cleanup and increment the iterator
        json_free(node_name);
        ++i;
    }
    //system("pause");
}