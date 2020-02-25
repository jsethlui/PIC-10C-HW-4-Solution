//Jeremy Louie
//PIC 10C
//Falcon
//No collaborators
//"I pledge that I have neither given nor received unauthorized assistance on this assignment."

#ifndef LESS_H
#define LESS_H

template<typename T>
class less {
	public:
		bool operator() (const T& x, const T& y) const {
			return x < y;
		}
};

#endif
