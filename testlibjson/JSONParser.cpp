#include "stdafx.h"
#include "JSONParser.h"
#include "libjson.h"
#include <iostream>
using namespace std;

JSONParser::JSONParser()
{
	output.open("output.txt");
	if (output == NULL)
		wcout<<L"failed to create output"<<endl;
}

JSONParser::~JSONParser()
{
	output.close();
}

void JSONParser::Parse(JSONNODE *n)
{
	if (n == NULL){
		wcout<<L"Invalid JSON Node from parse"<<endl;
		return;
	}

	pageindex = 0;
	JSONNODE_ITERATOR i = json_begin(n);
	while (i != json_end(n)){
		if (*i == NULL){
			wcout<<L"Invalid JSON Node from parse"<<endl;
			return;
		}

		if (json_type(*i) == JSON_NODE)
			pageindex++;
			PageParse(*i);
		++i;
	}
}

void JSONParser::PageParse(JSONNODE *n_page)
{
	if (n_page == NULL){
		wcout<<L"Invalid JSON Node from pageparse"<<endl;
		return;
	}

	JSONNODE_ITERATOR i_page = json_begin(n_page);
	while (i_page != json_end(n_page)){
		if (*i_page == NULL){
			wcout<<L"Invalid JSON Node from pageparse"<<endl;
			return;
		}

		json_char *node_name = json_name(*i_page);
		if (wcscmp(node_name, L"sound") == 0){
			wcout<<L"page["<<pageindex<<L"]------"<<L"sound node found"<<endl;
			output<<L"------page["<<pageindex<<L"]------"<<endl;
			soundindex = 0;
			soundParse(*i_page);
		}
		else if (wcscmp(node_name, L"animation") == 0){
			wcout<<L"page["<<pageindex<<L"]------"<<L"animation node found"<<endl;
			output<<L"------page["<<pageindex<<L"]------"<<endl;
			animationindex = 0;
			animationParse(*i_page);
		}
		else if (wcscmp(node_name, L"length") == 0){
			wcout<<L"page["<<pageindex<<L"]------"<<L"length node found"<<endl;
			output<<L"------page["<<pageindex<<L"]------"<<endl;
			output<<"length: "<<json_as_float(*i_page)<<endl;
		}
		else if (wcscmp(node_name, L"bgcolor") == 0){
			wcout<<L"page["<<pageindex<<L"]------"<<L"bgcolor node found"<<endl;
			output<<L"------page["<<pageindex<<L"]------"<<endl;
			output<<"bgcolor: "<<json_as_int(*i_page)<<endl;
		}

		// cleanup and increment the iterator
		json_free(node_name);
		++i_page;
	}
}

void JSONParser::soundParse(JSONNODE *n_sound)
{
	if (n_sound == NULL){
		wcout<<L"Invalid JSON Node from soundparse"<<endl;
		return;
	}

	JSONNODE_ITERATOR i_sound = json_begin(n_sound);
	while (i_sound != json_end(n_sound)){
		if (*i_sound == NULL){
			wcout<<L"Invalid JSON Node from soundparse"<<endl;
			return;
		}

		if (json_type(*i_sound) == JSON_NODE){
			soundindex++;
			soundParse(*i_sound);
		}

		json_char *node_name = json_name(*i_sound);
		if (wcscmp(node_name, L"length") == 0)
			output<<L"["<<soundindex<<L"] "<<L"length: "<<json_as_float(*i_sound)<<endl;
		else if (wcscmp(node_name, L"isoff") == 0)
			output<<L"["<<soundindex<<L"] "<<L"isoff: "<<json_as_bool(*i_sound)<<endl;
		//wchar_t to char conversion later
		else if (wcscmp(node_name, L"title") == 0)
			output<<L"["<<soundindex<<L"] "<<L"title: "<<json_as_string(*i_sound)<<endl;
		else if (wcscmp(node_name, L"type") == 0)
			output<<L"["<<soundindex<<L"] "<<L"type: "<<json_as_string(*i_sound)<<endl;
		else if (wcscmp(node_name, L"filename") == 0)
			output<<L"["<<soundindex<<L"] "<<L"filename: "<<json_as_string(*i_sound)<<endl;
		else if (wcscmp(node_name, L"start") == 0)
			output<<L"["<<soundindex<<L"] "<<L"start: "<<json_as_float(*i_sound)<<endl;
		else if (wcscmp(node_name, L"loop") == 0)
			output<<L"["<<soundindex<<L"] "<<L"loop: "<<json_as_bool(*i_sound)<<endl;
		else if (wcscmp(node_name, L"soundLength") == 0)
			output<<L"["<<soundindex<<L"] "<<L"soundLength: "<<json_as_float(*i_sound)<<endl;
		json_free(node_name);

		++i_sound;
	}
}

void JSONParser::animationParse(JSONNODE *n_animation)
{
	if (n_animation == NULL){
		wcout<<L"Invalid JSON Node from animationparse"<<endl;
		return;
	}

	JSONNODE_ITERATOR i_animation = json_begin(n_animation);
	while (i_animation != json_end(n_animation)){
		if (*i_animation == NULL){
			wcout<<L"Invalid JSON Node from animationparse"<<endl;
			return;
		}

		json_char *node_name = json_name(*i_animation);
		if (json_type(*i_animation) == JSON_NODE){
			animationindex++;
			animationParse(*i_animation);
		}

		if (wcscmp(node_name, L"x") == 0)
			output<<L"["<<animationindex<<L"] "<<L"x: "<<json_as_float(*i_animation)<<endl;
		else if (wcscmp(node_name, L"length") == 0)
			output<<L"["<<animationindex<<L"] "<<L"length: "<<json_as_float(*i_animation)<<endl;
		else if (wcscmp(node_name, L"a") == 0)
			output<<L"["<<animationindex<<L"] "<<L"a: "<<json_as_float(*i_animation)<<endl;
		else if (wcscmp(node_name, L"y") == 0)
			output<<L"["<<animationindex<<L"] "<<L"y: "<<json_as_float(*i_animation)<<endl;
		else if (wcscmp(node_name, L"type") == 0)
			output<<L"["<<animationindex<<L"] "<<L"type: "<<json_as_string(*i_animation)<<endl;
		//wchar_t to char conversion later
		else if (wcscmp(node_name, L"name") == 0)
			output<<L"["<<animationindex<<L"] "<<L"name: "<<json_as_string(*i_animation)<<endl;
		else if (wcscmp(node_name, L"start") == 0)
			output<<L"["<<animationindex<<L"] "<<L"start: "<<json_as_float(*i_animation)<<endl;
		//------------
		//spelling error "resouce--->resource"
		//------------
		else if (wcscmp(node_name, L"resouce_type") == 0)
			output<<L"["<<animationindex<<L"] "<<L"resource_type: "<<json_as_string(*i_animation)<<endl;
		else if (wcscmp(node_name, L"pic") == 0)
			output<<L"["<<animationindex<<L"] "<<L"pic: "<<json_as_string(*i_animation)<<endl;
		else if (wcscmp(node_name, L"scalex") == 0)
			output<<L"["<<animationindex<<L"] "<<L"scalex: "<<json_as_float(*i_animation)<<endl;
		else if (wcscmp(node_name, L"scaley") == 0)
			output<<L"["<<animationindex<<L"] "<<L"scaley: "<<json_as_float(*i_animation)<<endl;
		//------------
		//modification later
		else if (wcscmp(node_name, L"shock") == 0)
			output<<L"["<<animationindex<<L"] "<<L"shock: "<<json_as_string(*i_animation)<<endl;
		else if (wcscmp(node_name, L"event") == 0)
			output<<L"["<<animationindex<<L"] "<<L"event: "<<json_as_string(*i_animation)<<endl;
		//------------
		else if (wcscmp(node_name, L"zindex") == 0)
			output<<L"["<<animationindex<<L"] "<<L"zindex: "<<json_as_int(*i_animation)<<endl;
		else if (wcscmp(node_name, L"animate") == 0){
			output<<L"animate: "<<endl;
			animateindex = 0;
			if (json_type(*i_animation) == JSON_ARRAY)
				animateParse(*i_animation);
			output<<L"\\animate: "<<endl;
		}
		json_free(node_name);

		++i_animation;
	}
}

void JSONParser::animateParse(JSONNODE *n_animate)
{
	if (n_animate == NULL){
		wcout<<L"Invalid JSON Node from animateparse"<<endl;
		return;
	}

	JSONNODE_ITERATOR i_animate = json_begin(n_animate);
	while (i_animate != json_end(n_animate)){
		if (*i_animate == NULL){
			wcout<<L"Invalid JSON Node from animateparse"<<endl;
			return;
		}

		if (json_type(*i_animate) == JSON_NODE){
			animateindex++;
			animateParse(*i_animate);
		}

		json_char *node_name = json_name(*i_animate);
		if (wcscmp(node_name, L"x") == 0)
			output<<L"["<<animateindex<<L"] "<<L"x: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"a") == 0)
			output<<L"["<<animateindex<<L"] "<<L"a: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"y") == 0)
			output<<L"["<<animateindex<<L"] "<<L"y: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"hd") == 0)
			output<<L"["<<animateindex<<L"] "<<L"hd: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"scalex") == 0)
			output<<L"["<<animateindex<<L"] "<<L"scalex: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"scaley") == 0)
			output<<L"["<<animateindex<<L"] "<<L"scaley: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"len") == 0)
			output<<L"["<<animateindex<<L"] "<<L"len: "<<json_as_float(*i_animate)<<endl;
		else if (wcscmp(node_name, L"spEftid") == 0)
			output<<L"["<<animateindex<<L"] "<<L"spEftid: "<<json_as_bool(*i_animate)<<endl;
		else if (wcscmp(node_name, L"id") == 0)
			output<<L"["<<animateindex<<L"] "<<L"id: "<<json_as_int(*i_animate)<<endl;
		json_free(node_name);

		++i_animate;
	}
}
