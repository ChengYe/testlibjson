#include "libjson.h"
#include <fstream>
using namespace std;

class JSONParser
{
public:
	JSONParser();
	~JSONParser();
	void Parse(JSONNODE *n);
	void PageParse(JSONNODE *n_page);

protected:
	void soundParse(JSONNODE *n_sound);
	void animationParse(JSONNODE *n_animation);
	void animateParse(JSONNODE *n_animate);

private:
	wofstream output;
	int pageindex;
	int soundindex;
	int animationindex;
	int animateindex;
};