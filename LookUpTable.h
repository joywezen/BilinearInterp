#ifndef BILINEARINTERP_LOOKUPTABLE_H
#define BILINEARINTERP_LOOKUPTABLE_H

#include <string>
#include <vector>

/**
 * This is an example to show how you could read the file into data structures in memory.
 *
 * @param filename file containing look up table data
 * @param x output parameter
 * @param y output parameter
 * @param z output parameter
 */
void exampleReadData(std::string filename, std::vector<double>& x, std::vector<double>& y, std::vector<double>& z);

#endif // BILINEARINTERP_LOOKUPTABLE_H
