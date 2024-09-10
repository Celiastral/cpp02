/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:02 by eandre            #+#    #+#             */
/*   Updated: 2024/09/10 17:36:09 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public :
		Fixed(void);
		Fixed(const Fixed &other_Fixed);
		~Fixed();
		Fixed	&operator = (const Fixed &other_Fixed);
		int			getRawBits(void) const;
		void		setRawBits(const int raw);
	private :
		int	raw_bits;
		static const int bits = 8;
};

#endif