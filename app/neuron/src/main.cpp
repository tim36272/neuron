#include "ionlib\log.h"
#include "ionlib\net.h"
#include "ionlib\matrix.h"
#include <iostream>
#include <fstream>

void test(std::ostream& bios)
{
	bios << "test" << std::endl;
}
int main(int argc, char* argv[])
{
	ion::InitSockets();
	ion::LogInit("neuron");

	ion::Matrix<double> mat(2, 3, 2);
	for (uint32_t row = 0; row < mat.rows(); ++row)
	{
		for(uint32_t col = 0; col < mat.cols(); ++col) {
			for (uint32_t page = 0; page < mat.pages(); ++page)
			{
				mat.Set(row * mat.cols()*mat.pages() + col*mat.pages() + page, row, col, page);
			}
		}
	}

	std::cout << mat <<std::endl;

	mat.Reshape(12, 1, 1);

	std::cout << mat << std::endl;

	return 0;
}