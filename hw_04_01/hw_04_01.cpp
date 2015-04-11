#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#define NUM_STOCKS 30
#define NUM_DATES 300

using namespace std;
using namespace Eigen;


int main()
{
	// Read csv data into matrix M_price
	MatrixXd M_price(NUM_STOCKS,NUM_DATES);
	ifstream ifs_price("djprices2014.csv");
	if (!ifs_price.is_open()) {
		cout << "The csv file does not exist." << endl;
		exit(1);
	}
	string s_stocks[NUM_STOCKS], s_date;
	char c_comma;
	ifs_price >> c_comma;
	for (int i = 0; i < NUM_STOCKS-1; i++)
		getline(ifs_price, s_stocks[i], ',');
	getline(ifs_price, s_stocks[NUM_STOCKS-1], '\n');
	while (!ifs_price.eof()) {
		for (int i = 0; i < NUM_DATES; i++) {
			getline(ifs_price, s_date, ',');
			for (int j = 0; j < NUM_STOCKS; j++)
				ifs_price >> M_price(j, i) >> c_comma;
		}
	}

	// Construct matrix of daily return
	MatrixXd M_return(NUM_STOCKS, NUM_DATES-1);
	for (int i = 0; i < NUM_STOCKS; i++) 
		for (int j = 0; j < NUM_DATES-1; j++)
			M_return(i, j) = M_price(i, j+1) / M_price(i, j) - 1;

	// Calculate sample mean vector m and sample covariance S
	MatrixXd M_1(NUM_DATES-1, 1);
	M_1.fill(1);
	MatrixXd M_I(NUM_DATES-1, NUM_DATES-1);
	M_I.setIdentity();
	MatrixXd M_mean = 1.0/(NUM_DATES-1) * M_return * M_1;
	MatrixXd M_cov = 1.0/(NUM_DATES-1) * M_return * (M_I-1.0/(NUM_DATES-1)*M_1*M_1.transpose()) * M_return.transpose();

	// Calculate the value of A
	MatrixXd M_11(NUM_STOCKS, 1);
	M_11.fill(1);
	MatrixXd M_A(1,1); 
	M_A = M_11.transpose() * M_cov.inverse() * M_11;

	// Calculate the portfolio weights for the global minimum variance portfolio
	MatrixXd M_weight(NUM_STOCKS, 1);
	M_weight = M_cov.inverse() * M_11 / M_A(0,0);

	// Print out results
	for (int i = 0; i < NUM_STOCKS; i++) 
		cout << s_stocks[i] << "," << M_weight(i,0)*100 << "%" << endl; 
	return 0;
}
