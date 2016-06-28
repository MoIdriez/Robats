#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CSVHover {
public:
	static void run() {
		vector<vector<double> > values;
		vector<double> valueline;
		ifstream fin("in.csv");
		string item;
		for (string line; getline(fin, line); )
		{
			istringstream in(line);

			while (getline(in, item, ','))
			{
				valueline.push_back(atof(item.c_str()));
			}

			values.push_back(valueline);
			valueline.clear();
		}

	}
};
