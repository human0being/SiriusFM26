#pragma once
#include <stdexcept>
//#include <stdlib.h>

namespace SiriusFM{

	class DiffusionGBM{
	private:
		double const m_mu;
		double const m_sigma;
	public:
		// DiffusionGBM() = delete;
		DiffusionGBM(double a_mu, double a_sigma)
		: m_mu(a_mu), m_sigma(a_sigma){
			if (m_sigma <= 0) throw std::invalid_argument("Invalid values");
		}
		double mu(double a_St, double a_t){
			return (a_St < 0) ? 0 : m_mu*a_St; 
		}
		double sigma(double a_St, double a_t){
			return (a_St < 0) ? 0 : m_sigma*a_St;
		}
	};
}
