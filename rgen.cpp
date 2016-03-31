#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>
#include "generators.h"
# define M_PI           3.14159265358979323846

using namespace std;

UniformSimulator::UniformSimulator() {

}
vector<double> UniformSimulator::simulate(int n)
{
	double a = 16807;
	double m = pow(2, 31) - 1;
	double q = floor(m / a); double r = int(m) % int(a);
	double x = 1;
	double h = 1 / double(m);
	vector<double> rns;
	rns.push_back(x);
	for (int i = 0; i < n; i++)
	{
		int k = x / q;
		x = a* (x - k*q) - k*r;
		if (x < 0) x = x + m;
		rns.push_back(x*h);
	}
	return rns;
}
ExponentialSimulator::ExponentialSimulator()
{

}
vector<double> ExponentialSimulator::simulate(int n, double lambda)
{
	vector<double> rns = uni.simulate(n);
	vector<double> rnsexp;
	rnsexp.resize(rns.size());
	transform(rns.begin(), rns.end(), rnsexp.begin(), [&](double u) {return -1 / lambda*log(u); });
	return rnsexp;
}

NormalSimulator::NormalSimulator()
{

}
vector<double> NormalSimulator::simulate(int n, double mean, double stddev)
{
	vector<double> rns = uni.simulate(n);
	vector<double> rnsnorm;
	for (int i = 0; i < rns.size() / 2; i++)
	{
		double u1 = rns[i * 2]; double u2 = rns[i * 2 + 1];
		double R = -2 * log(u1); double V = 2 * M_PI*u2;
		double z1 = pow(R, 0.5)*cos(V); double z2 = pow(R, 0.5)*sin(V);
		rnsnorm.push_back(z1*stddev + mean); rnsnorm.push_back(z2*stddev + mean);
	}
	return rnsnorm;
}