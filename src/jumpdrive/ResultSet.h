/*
 * ResultSet.h
 *
 *  Created on: Jun 11, 2015
 *      Author: caolan
 */

#ifndef RESULTSET_H_
#define RESULTSET_H_

#include "commondefs.h"

class ResultSet {
public:
	ResultSet() {};
	ResultSet(const vector<double> &);
	virtual ~ResultSet() {};

	friend ostream &operator<<(ostream &, ResultSet const &);

private:
	vector<double> &m_resultSet;
};

#endif /* RESULTSET_H_ */
