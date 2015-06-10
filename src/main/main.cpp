/*
 * main.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: caolan
 */

#include "../jumpdrive/commondefs.h"
#include "../jumpdrive/jumpdrivedefs.h"
#include "commondef.h"
#include "CTeslaApp.h"

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

//#include <QtGui/QApplication>
//#include <QtGui/QLabel>

using namespace std;

int main(int argc, char **argv) {
//	CTeslaApp App;
//	App.run();
//
//	QApplication myApp(argc, argv);
//	QLabel *plabel = new QLabel("Hello Qt");
//	plabel -> show();
//	myApp.exec();

	while (1) {
		string strEquation;
		cout << "Please enter your equation or \'q\' to exit:";
		getline(cin, strEquation);
		cout << endl;

		if (strEquation[0] == 'Q' || strEquation[0] == 'q')
			break;
		vector<string> fields;
		vector<double> vals;
		split(fields, strEquation, is_any_of(","));
		ExpressionBuilder builder(fields[0]);
		for (vector<string>::iterator iter = fields.begin() + 1; iter != fields.end(); iter++) {
			double val;
			vector<string> tmp;

			// Split the variable from it's value
			split(tmp, trim(*iter), is_any_of("="));
			builder.withVariable(trim(tmp[0]), val = atof(trim(tmp[1]).c_str()));
			vals.push_back(val);
		}
		double result = builder.build().calculate(vals);
		cout << "Expression Builder Test:" << endl;
		cout << strEquation << endl;
		cout << "Result = " << result << endl;
	}

//	string strEquation = "x * y - 2, x = 1.2, y = 2.2";
//	vector<string> fields;
//	vector<double> vals;
//	split(fields, strEquation, is_any_of(","));
//	ExpressionBuilder builder(fields[0]);
//	for (vector<string>::iterator iter = fields.begin() + 1; iter != fields.end(); iter++) {
//		string str = ltrim(*iter);
//		double val;
//
//		// Split the variable from it's value
//		vector<string> tmp;
//		split(tmp, str, is_any_of("="));
//		builder.withVariable(ltrim(rtrim(tmp[0])), val = atof(ltrim(rtrim(tmp[1])).c_str()));
//		vals.push_back(val);
//	}
//	double result = builder.build().calculate(vals);
//	cout << "Expression Builder Test:" << endl;
//	cout << strEquation << endl;
//	cout << "Result = " << result << endl;
	return 0;
}
