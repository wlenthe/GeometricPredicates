/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                 *
 * Copyright (c) 2016, William C. Lenthe                                           *
 * All rights reserved.                                                            *
 *                                                                                 *
 * Redistribution and use in source and binary forms, with or without              *
 * modification, are permitted provided that the following conditions are met:     *
 *                                                                                 *
 * 1. Redistributions of source code must retain the above copyright notice, this  *
 *    list of conditions and the following disclaimer.                             *
 *                                                                                 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,    *
 *    this list of conditions and the following disclaimer in the documentation    *
 *    and/or other materials provided with the distribution.                       *
 *                                                                                 *
 * 3. Neither the name of the copyright holder nor the names of its                *
 *    contributors may be used to endorse or promote products derived from         *
 *    this software without specific prior written permission.                     *
 *                                                                                 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"     *
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE       *
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  *
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE    *
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL      *
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR      *
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   *
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.            *
 *                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <random>
#include <vector>

#include "predicates.h"

int main() {
	std::random_device device;
	size_t seed = device();
	std::mt19937 engine(seed);
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	std::vector<double> points(15);
	for(size_t i = 0; i < points.size(); i++) points[i] = dist(engine);

	double x = predicates::adaptive::orient2d<double>(&points[0], &points[2], &points[4]);
	std::cout << "(" << points[4] << " " << points[5];
	if(x < 0.0) std::cout << ") is below the line defined by:\n";
	else if(x > 0.0) std::cout << ") is above the line defined by:\n";
	else std::cout << ") is on the line defined by:\n";
	std::cout << "\t(" << points[0] << " " << points[1] << ")\n";
	std::cout << "\t(" << points[2] << " " << points[3] << ")\n\n";

	x = predicates::adaptive::incircle<double>(&points[0], &points[2], &points[4], &points[8]);
	std::cout << "(" << points[6] << " " << points[7];
	if(x < 0.0) std::cout << ") is outside the circle defined by:\n";
	else if(x > 0.0) std::cout << ") is inside the circle defined by:\n";
	else std::cout << ") is on the circle defined by:\n";
	std::cout << "\t(" << points[0] << " " << points[1] << ")\n";
	std::cout << "\t(" << points[2] << " " << points[3] << ")\n";
	std::cout << "\t(" << points[4] << " " << points[5] << ")\n\n";

	x = predicates::adaptive::orient3d<double>(&points[0], &points[3], &points[6], &points[9]);
	std::cout << "(" << points[9] << " " << points[10] << " " << points[11];
	if(x < 0.0) std::cout << ") is below the plane defined by:\n";
	else if(x > 0.0) std::cout << ") is above the plane defined by:\n";
	else std::cout << ") is on the plane defined by:\n";
	std::cout << "\t(" << points[0] << " " << points[1]  << " " << points[2] << ")\n";
	std::cout << "\t(" << points[3] << " " << points[4]  << " " << points[5] << ")\n";
	std::cout << "\t(" << points[6] << " " << points[7]  << " " << points[8] << ")\n\n";

	x = predicates::adaptive::insphere<double>(&points[0], &points[3], &points[6], &points[9], &points[12]);
	std::cout << "(" << points[12] << " " << points[13] << " " << points[14];
	if(x < 0.0) std::cout << ") is outside the sphere defined by:\n";
	else if(x > 0.0) std::cout << ") is inside the sphere defined by:\n";
	else std::cout << ") is on the sphere defined by:\n";
	std::cout << "\t(" << points[0] << " " << points[ 1]  << " " << points[ 2] << ")\n";
	std::cout << "\t(" << points[3] << " " << points[ 4]  << " " << points[ 5] << ")\n";
	std::cout << "\t(" << points[6] << " " << points[ 7]  << " " << points[ 8] << ")\n";
	std::cout << "\t(" << points[9] << " " << points[10]  << " " << points[11] << ")\n";
	return 0;	
}
