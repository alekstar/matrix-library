#ifndef MATRICESCANTBEMULTIPLIED_H
#define	MATRICESCANTBEMULTIPLIED_H
#include <stdexcept>

class MatricesCantBeMultiplied: public std::logic_error {
public:
    MatricesCantBeMultiplied();
private:

};

#endif	/* MATRICESCANTBEMULTIPLIED_H */
