#include <algorithm>
#include <vector>
#include <chrono>

#include "sort.h"

typedef std::chrono::high_resolution_clock hrc;

namespace {
	class Timer {
	public:
		Timer() {}

		void start() {
			begin = hrc::now();
		}

		double getTime() {
			return std::chrono::duration<double>(hrc::now() - begin).count();
		}

	private:
		hrc::time_point begin;
	};
}

std::vector<int> gen_random_array(int size) {
	std::vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand() % size;
	}
	return result;
}

void measure(int size) {
	std::vector<int> array = gen_random_array(size);
	std::vector<int> array2(array);

	Timer t;
	t.start();

	bubbleSort(array);
	double lin_time = t.getTime();

	t.start();
	std::sort(array2.begin(), array2.end());
	
	double set_time = t.getTime();
	printf("N: %d, My bubbleSort time: %.5f sec, std::sort time: %.5f\n",
		   size, lin_time, set_time);
}

/*void main() {
	for (int i = 1; i < 6; i++) {
		measure(pow(10, i));
	}
}*/