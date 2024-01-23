/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:40 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/23 15:05:49 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

# ifndef DEBUG_MSG
#  define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# endif

# ifndef INFO_MSG
#  define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# endif

# ifndef WARNING_MSG
#  define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# endif

# ifndef ERROR_MSG
#  define ERROR_MSG "This is unacceptable, I want to speak to the manager now."
# endif

class Harl
{
	public:
		enum Level {
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			NONE
		};

		Harl();
		~Harl();

		void	complain( std::string level );
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
