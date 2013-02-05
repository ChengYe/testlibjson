#include <stdafx.h>
#include "NodeSound.h"
#include <stdlib.h>

//length
void NodeSound::Setlength(json_number length)
{
	this->length = length;
}

json_number NodeSound::Getlength()
{
	return this->length;
}

//isoff
void NodeSound::Setisoff(json_bool_t isoff)
{
	this->isoff = isoff;
}

json_bool_t NodeSound::Getisoff()
{
	return this->isoff;
}

//title
void NodeSound::Settitle(json_char* title)
{
	if (title)
		wcscpy(this->title, title);
	else
		return;
}

json_char* NodeSound::Gettitle()
{
	return this->title;
}

//type
void NodeSound::Settype(json_char* type)
{
	if (type)
		wcscpy(this->type, type);
	else
		return;
}

json_char* NodeSound::Gettype()
{
	return this->type;
}

//filename
void NodeSound::Setfilename(json_char* filename)
{
	if (filename)
		wcscpy(this->filename, filename);
	else
		return;
}

json_char* NodeSound::Getfilename()
{
	return this->filename;
}

//start
void NodeSound::Setstart(json_number start)
{
	this->start = start;
}

json_number NodeSound::Getstart()
{
	return this->start;
}

//loop
void NodeSound::Setloop(json_bool_t loop)
{
	this->loop = loop;
}

json_bool_t NodeSound::Getloop()
{
	return this->loop;
}

//soundlength
void NodeSound::Setsoundlength(json_number soundlength)
{
	this->soundlength = soundlength;
}

json_number NodeSound::Getsoundlength()
{
	return this->soundlength;
}
