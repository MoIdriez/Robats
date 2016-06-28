#include <vector>

#ifndef INCLUDE_RUNAVERAGE_H_
#define INCLUDE_RUNAVERAGE_H_

class RunAverage {
public:
	static std::vector<double> run(std::vector<double> values, int meansize) {
		std::vector<double> runAvg;

		// for all the sections
		for (int i = 0; i < (values/meansize); i++) {
			double sum = 0;
			// get all items in section
			for (int j = i*meansize; j < i*meansize + meansize; j++) {
				sum += values.at(j);
			}
			double avg = sum / meansize;
			for (int j = 0; j < meansize; j++) {
				runAvg.push_back(avg);
			}
		}
		return runAvg;
	}
};



#endif /* INCLUDE_RUNAVERAGE_H_ */
