/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:19:54 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/27 19:21:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_value;
		static const int	_bits = 8;
};

#endif
