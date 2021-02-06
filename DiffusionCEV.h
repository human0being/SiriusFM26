#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM{

	class DiffusionCEV{
	private:
		double const m_mu;
		double const m_sigma;
		double const m_beta;
	public:
		DiffusionCEV(double a_mu, double a_sigma, double a_beta)
		: m_mu(a_mu), m_sigma(a_sigma), m_beta(a_beta){
			if (m_sigma <= 0 or m_beta <= 0) throw std::invalid_argument("Invalid values");
		}
		double mu(double a_St, double a_t){
			return (a_St < 0) ? 0 : m_mu*a_St; 
		}
		double sigma(double a_St, double a_t){
			return (a_St < 0) ? 0 : m_sigma*pow(a_St, m_beta);
		}
	};
}
