/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:36:49 by thchau            #+#    #+#             */
/*   Updated: 2025/10/18 15:34:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Area=(1/2)​∣x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)∣
static Fixed area(Point const &a, Point const &b, Point const &c)
{
	return Fixed(
		abs(
			(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
		)
	);
}

/**
 * If Area(ABC) == Area(PAB) + Area(PBC) + Area(PCA)
 * → P is inside the triangle.
*/
bool bsp(Point const &a, Point const &b, Point const &c, Point const &p)
{
	Fixed areaABC = area(a, b, c);
	Fixed areaAPB = area(a, p, b);
	Fixed areaAPC = area(a, p, c);
	Fixed areaBPC = area(b, p, c);
	
	if (areaAPB == Fixed(0) || areaAPC == Fixed(0) || areaBPC == Fixed(0))
		return false;
	if(areaABC == (areaAPB + areaAPC + areaBPC))
		return true;
	return false;
}
