#ifndef AREEQUAL_H
#define	AREEQUAL_H

const double EPSILON_FOR_DOUBLE_COMPARISON = 0.00001;

bool areAlmostEqual(const double operand1, 
                    const double operand2, 
                    const double epsilon = EPSILON_FOR_DOUBLE_COMPARISON);

#endif	/* AREEQUAL_H */

