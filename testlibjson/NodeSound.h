#include "libjson.h"

class NodeSound
{
public:
	void Setlength(json_number length);
	json_number Getlength();

	void Setisoff(json_bool_t isoff);
	json_bool_t Getisoff();

	void Settitle(json_char* title);
	json_char* Gettitle();

	void Settype(json_char* type);
	json_char* Gettype();

	void Setfilename(json_char* filename);
	json_char* Getfilename();

	void Setstart(json_number start);
	json_number Getstart();

	void Setloop(json_bool_t loop);
	json_bool_t Getloop();

	void Setsoundlength(json_number soundlength);
	json_number Getsoundlength();

private:
	json_number length;
	json_bool_t isoff;
	json_char title[32];
	json_char type[32];
	json_char filename[32];
	json_number start;
	json_bool_t loop;
	json_number soundlength;
};