/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:18:17 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:22 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <time.h>
# include <stdlib.h>

class Base
{
	private:
	public:
		virtual ~Base();
};

class A: public Base
{
	private:
	public:
};

class B: public Base
{
	private:
	public:
};

class C: public Base
{
	private:
	public:
};

#endif

