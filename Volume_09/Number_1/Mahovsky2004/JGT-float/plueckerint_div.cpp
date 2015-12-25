/******************************************************************************

This source code accompanies the Journal of Graphics Tools paper:

"Fast Ray-Axis Aligned Bounding Box Overlap Tests With Pluecker Coordinates" by
Jeffrey Mahovsky and Brian Wyvill
Department of Computer Science, University of Calgary

This source code is public domain, but please mention us if you use it.

******************************************************************************/

#include "plueckerint_div.h"


bool plueckerint_div(ray *r, aabox *b, float *t)
{
	if(r->i < 0) 
	{
		if(r->j < 0) 
		{
			if(r->k < 0)
			{
				// case MMM: side(R,HD) < 0 or side(R,FB) > 0 or side(R,EF) > 0 or side(R,DC) < 0 or side(R,CB) < 0 or side(R,HE) > 0 to miss

				if ((r->x < b->x0) || (r->y < b->y0) || (r->z < b->z0))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * ya - r->j * xb < 0) ||
					(r->i * yb - r->j * xa > 0) ||
					(r->i * zb - r->k * xa > 0) ||
					(r->i * za - r->k * xb < 0) ||
					(r->j * za - r->k * yb < 0) ||
					(r->j * zb - r->k * ya > 0))
					return false;

				// compute the intersection distance

				*t = xb / r->i;
				float t1 = yb / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = zb / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
			else
			{
				// case MMP: side(R,HD) < 0 or side(R,FB) > 0 or side(R,HG) > 0 or side(R,AB) < 0 or side(R,DA) < 0 or side(R,GF) > 0 to miss

				if ((r->x < b->x0) || (r->y < b->y0) || (r->z > b->z1))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * ya - r->j * xb < 0) ||
					(r->i * yb - r->j * xa > 0) ||
					(r->i * zb - r->k * xb > 0) ||
					(r->i * za - r->k * xa < 0) ||
					(r->j * za - r->k * ya < 0) ||
					(r->j * zb - r->k * yb > 0))
					return false;

				*t = xb / r->i;
				float t1 = yb / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = za / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
		} 
		else 
		{
			if(r->k < 0)
			{
				// case MPM: side(R,EA) < 0 or side(R,GC) > 0 or side(R,EF) > 0 or side(R,DC) < 0 or side(R,GF) < 0 or side(R,DA) > 0 to miss

				if ((r->x < b->x0) || (r->y > b->y1) || (r->z < b->z0))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * ya - r->j * xa < 0) ||
					(r->i * yb - r->j * xb > 0) ||
					(r->i * zb - r->k * xa > 0) ||
					(r->i * za - r->k * xb < 0) ||
					(r->j * zb - r->k * yb < 0) ||
					(r->j * za - r->k * ya > 0))
					return false;

				*t = xb / r->i;
				float t1 = ya / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = zb / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
			else
			{
				// case MPP: side(R,EA) < 0 or side(R,GC) > 0 or side(R,HG) > 0 or side(R,AB) < 0 or side(R,HE) < 0 or side(R,CB) > 0 to miss

				if ((r->x < b->x0) || (r->y > b->y1) || (r->z > b->z1))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * ya - r->j * xa < 0) ||
					(r->i * yb - r->j * xb > 0) ||
					(r->i * zb - r->k * xb > 0) ||
					(r->i * za - r->k * xa < 0) ||
					(r->j * zb - r->k * ya < 0) ||
					(r->j * za - r->k * yb > 0))
					return false;

				*t = xb / r->i;
				float t1 = ya / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = za / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
		}
	}
	else 
	{
		if(r->j < 0) 
		{
			if(r->k < 0)
			{
				// case PMM: side(R,GC) < 0 or side(R,EA) > 0 or side(R,AB) > 0 or side(R,HG) < 0 or side(R,CB) < 0 or side(R,HE) > 0 to miss

				if ((r->x > b->x1) || (r->y < b->y0) || (r->z < b->z0))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * yb - r->j * xb < 0) ||
					(r->i * ya - r->j * xa > 0) ||
					(r->i * za - r->k * xa > 0) ||
					(r->i * zb - r->k * xb < 0) ||
					(r->j * za - r->k * yb < 0) ||
					(r->j * zb - r->k * ya > 0))
					return false;

				*t = xa / r->i;
				float t1 = yb / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = zb / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
			else
			{
				// case PMP: side(R,GC) < 0 or side(R,EA) > 0 or side(R,DC) > 0 or side(R,EF) < 0 or side(R,DA) < 0 or side(R,GF) > 0 to miss

				if ((r->x > b->x1) || (r->y < b->y0) || (r->z > b->z1))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * yb - r->j * xb < 0) ||
					(r->i * ya - r->j * xa > 0) ||
					(r->i * za - r->k * xb > 0) ||
					(r->i * zb - r->k * xa < 0) ||
					(r->j * za - r->k * ya < 0) ||
					(r->j * zb - r->k * yb > 0))
					return false;

				*t = xa / r->i;
				float t1 = yb / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = za / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
		}
		else 
		{
			if(r->k < 0)
			{
				// case PPM: side(R,FB) < 0 or side(R,HD) > 0 or side(R,AB) > 0 or side(R,HG) < 0 or side(R,GF) < 0 or side(R,DA) > 0 to miss

				if ((r->x > b->x1) || (r->y > b->y1) || (r->z < b->z0))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * yb - r->j * xa < 0) ||
					(r->i * ya - r->j * xb > 0) ||
					(r->i * za - r->k * xa > 0) ||
					(r->i * zb - r->k * xb < 0) ||
					(r->j * zb - r->k * yb < 0) ||
					(r->j * za - r->k * ya > 0))
					return false;

				*t = xa / r->i;
				float t1 = ya / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = zb / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
			else
			{
				// case PPP: side(R,FB) < 0 or side(R,HD) > 0 or side(R,DC) > 0 or side(R,EF) < 0 or side(R,HE) < 0 or side(R,CB) > 0 to miss

				if ((r->x > b->x1) || (r->y > b->y1) || (r->z > b->z1))
					return false;

				float xa = b->x0 - r->x; 
				float ya = b->y0 - r->y; 
				float za = b->z0 - r->z; 
				float xb = b->x1 - r->x;
				float yb = b->y1 - r->y;
				float zb = b->z1 - r->z;

				if(	(r->i * yb - r->j * xa < 0) ||
					(r->i * ya - r->j * xb > 0) ||
					(r->i * za - r->k * xb > 0) ||
					(r->i * zb - r->k * xa < 0) ||
					(r->j * zb - r->k * ya < 0) ||
					(r->j * za - r->k * yb > 0))
					return false;

				*t = xa / r->i;
				float t1 = ya / r->j;
				if(t1 > *t)
					*t = t1;
				float t2 = za / r->k;
				if(t2 > *t)
					*t = t2;

				return true;
			}
		}
	}

	return false;
}
