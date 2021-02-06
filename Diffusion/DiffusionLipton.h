#pragma once
#include <stdexcept>
//#include <stdlib.h>

namespace SiriusFM{

	class DiffusionLipton{
	private:
		double const m_mu;
		double const m_sigma_1, m_sigma_2, m_sigma_3;
	public:
		// DiffusionGBM() = delete;
		DiffusionLipton(double a_mu, double a_sigma_1, double a_sigma_2, double a_sigma_3)
		: m_mu(a_mu), m_sigma_1(a_sigma_1), m_sigma_2(a_sigma_2), m_sigma_3(a_sigma_3){
			if ( m_sigma_2*m_sigma_2 - 4*m_sigma_1*m_sigma_3 >= 0) throw std::invalid_argument("Invalid values");
		}
		double mu(double a_St, double a_t){
			return (a_St < 0) ? 0 : m_mu*a_St; 
		}
		double sigma(double a_St, double a_t){
			return (a_St < 0) ? 0 : m_sigma_1 + m_sigma_2*a_St + m_sigma_3*a_St*a_St;
		}
	};
}
