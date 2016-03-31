#pragma once
#include <vector>
using namespace std;

class UniformSimulator
{
public:
	UniformSimulator();
	vector<double> simulate(int n);
};

class DistributionSimulator //uses uniform/Inverse transformation
{
public:
	DistributionSimulator() {};
	virtual vector<double> simulate(int n) {
		return vector<double>();
	};
protected:
	UniformSimulator uni;
};

class ExponentialSimulator:public DistributionSimulator //uses uniform/Inverse transformation
{
public:
	ExponentialSimulator();
	vector<double> simulate(int n, double lambda);
};

class NormalSimulator :public DistributionSimulator //uses uniform/Inverse transformation
{
public:
	NormalSimulator();
	vector<double> simulate(int n, double mean, double stddev);
};