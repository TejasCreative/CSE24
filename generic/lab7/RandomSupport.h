//
// A small library for sampling random numbers from a uniform distribution
//
#ifndef RandomSupport_h
#define RandomSupport_h

#include <random>

typedef std::uniform_int_distribution<int> uniform_distribution;
typedef std::mt19937 randomizer;

struct RNG{
private:
	randomizer new_randomizer(){
		randomizer rng;
		rng.seed(std::random_device()());
		return rng;
	}

	uniform_distribution new_distribution(int start, int end){
		uniform_distribution dist(start, end);
		return dist;
	}

	int sample(uniform_distribution& dist, randomizer& r){
		return dist(r);
	}

	randomizer r;
	uniform_distribution u;
	int lower;
	int upper;

public:

	RNG(){
		lower = 0;
		upper = 9;
		r = new_randomizer();
		u = new_distribution(lower, upper);
	}

	RNG(int lower, int upper){
		this->lower = lower;
		this->upper = upper;

		r = new_randomizer();
		u = new_distribution(lower, upper);
	}

	int get(){
		return sample(u, r);
	}

	void setLimits(int lower, int upper){
		u = new_distribution(lower, upper);
	}

};

#endif