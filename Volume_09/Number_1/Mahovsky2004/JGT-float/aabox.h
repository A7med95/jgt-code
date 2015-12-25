/******************************************************************************

  This source code accompanies the Journal of Graphics Tools paper:

  "Fast Ray-Axis Aligned Bounding Box Overlap Tests With Pluecker Coordinates" by
  Jeffrey Mahovsky and Brian Wyvill
  Department of Computer Science, University of Calgary

  This source code is public domain, but please mention us if you use it.

 ******************************************************************************/

#ifndef _AABOX_H
#define _AABOX_H

// axis-aligned bounding box structure

struct aabox
{
	float x0, y0, z0, x1, y1, z1;
};

void make_aabox(float x0, float y0, float z0, float x1, float y1, float z1, aabox *a);

#endif
