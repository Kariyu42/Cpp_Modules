/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:08:27 by kquetat-          #+#    #+#             */
/*   Updated: 2024/02/11 18:16:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base() {};
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
