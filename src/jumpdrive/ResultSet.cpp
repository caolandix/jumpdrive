/*
 * ResultSet.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: caolan
 */

#include "ResultSet.h"

ResultSet::ResultSet(const vector<double> &results) {
	m_resultSet = results;
}

std::ostream &operator<<(std::ostream &os, ResultSet const &obj) {
	for (vector<double>::iterator iter = obj.m_resultSet.begin(); iter != obj.m_resultSet.end(); iter++) {
		os << *iter;
		if (iter + 1 != obj.m_resultSet.end())
			os << ", ";
	}
    return os;
}
