#pragma once
#include <stdexcept>
//#include <stdlib.h>

namespace SiriusFM{

	class DiffusionSIR{
	private:
		double const m_sigma;
		double const m_theta;
		double const m_kappa;
	public:
		DiffusionSIR(double a_kappa, double a_sigma, double a_theta)
		: m_kappa(a_kappa), m_sigma(a_sigma), m_theta(a_theta){
			if (m_sigma <= 0 or m_kappa <= 0) throw std::invalid_argument("Invalid values");
		}
		double mu(double a_St, double a_t) const{
			return (a_St < 0) ? 0 : m_kappa*(m_theta - a_St); 
		}
		double sigma(double a_St, double a_t) const{
			return (a_St < 0) ? 0 : m_sigma*pow(a_St, 0.5);
		}
	};
}
