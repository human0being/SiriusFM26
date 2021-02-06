#include <iostream>
#include "DiffusionGBM.h"
#include "DiffusionCEV.h"
#include "DiffusionOU.h"
#include "DiffusionLipton.h"
#include "DiffusionSIR.h"

using namespace SiriusFM;
using namespace std;

int main(){
	double mu = 10, sigma = 5, sigma1 = 5, sigma2= 3, sigma3 = 4;
	double beta = 0.4;
	double St = 3, t = 2;
	double kappa = 0.9, theta = 12;
	
	DiffusionGBM GBM(mu, sigma);
	DiffusionCEV CEV(mu, sigma, beta);
	DiffusionOU OU(kappa, sigma, theta);
	DiffusionLipton Lipton(mu, sigma1, sigma2, sigma3);
	DiffusionSIR SIR(kappa, sigma, theta);

	cout << GBM.mu(St, t) << " " << GBM.sigma(St, t) << "\n";
	cout << CEV.mu(St, t) << " " << CEV.sigma(St, t) << "\n";
	cout << OU.mu(St, t) << " " << OU.sigma(St, t) << "\n";
	cout << Lipton.mu(St, t) << " " << Lipton.sigma(St, t) << "\n";
	cout << SIR.mu(St, t) << " " << SIR.sigma(St, t) << "\n";


	return 0;
}
