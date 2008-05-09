/*
 * Copyright (c) 2004-2008 Hypertriton, Inc. <http://hypertriton.com/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Line entity.
 */

#include <core/limits.h>
#include <core/core.h>

#include <gui/widget.h>
#include <gui/primitive.h>

#include "vg.h"
#include "vg_view.h"
#include "icons.h"

static void
Init(void *p)
{
	VG_Line *vl = p;

	vl->p1 = NULL;
	vl->p2 = NULL;
	vl->endPt = VG_LINE_SQUARE;
	vl->stipple = 0xffff;
	vl->miterLen = 0;
	vl->thickness = 1;
}

static int
Load(void *p, AG_DataSource *ds, const AG_Version *ver)
{
	VG_Line *vl = p;

	if ((vl->p1 = VG_ReadRef(ds, vl, "Point")) == NULL) {
		return (-1);
	}
	if ((vl->p2 = VG_ReadRef(ds, vl, "Point")) == NULL) {
		return (-1);
	}
	vl->endPt = (enum vg_line_endpoint)AG_ReadUint8(ds);
	vl->stipple = AG_ReadUint16(ds);
	vl->miterLen = AG_ReadUint8(ds);
	vl->thickness = AG_ReadUint8(ds);
	return (0);
}

static void
Save(void *p, AG_DataSource *ds)
{
	VG_Line *vl = p;

	VG_WriteRef(ds, vl->p1);
	VG_WriteRef(ds, vl->p2);
	AG_WriteUint8(ds, (Uint8)vl->endPt);
	AG_WriteUint16(ds, vl->stipple);
	AG_WriteUint8(ds, vl->miterLen);
	AG_WriteUint8(ds, vl->thickness);
}

static void
Draw(void *p, VG_View *vv)
{
	VG_Line *vl = p;
	Uint32 c32 = VG_MapColorRGB(VGNODE(vl)->color);
	int x1, y1, x2, y2;

	VG_GetViewCoords(vv, VG_Pos(vl->p1), &x1, &y1);
	VG_GetViewCoords(vv, VG_Pos(vl->p2), &x2, &y2);

	/* XXX TODO: endpoint style */
	AG_DrawLine(vv, x1,y1, x2,y2, c32);
}

static void
Extent(void *p, VG_View *vv, VG_Rect *r)
{
	VG_Line *vl = p;
	VG_Vector p1, p2;

	p1 = VG_Pos(vl->p1);
	p2 = VG_Pos(vl->p2);

	r->x = MIN(p1.x, p2.x);
	r->y = MIN(p1.y, p2.y);
	r->w = MAX(p1.x, p2.x) - r->x;
	r->h = MAX(p1.y, p2.y) - r->y;
}

static float
PointProximity(void *p, VG_View *vv, VG_Vector *vPt)
{
	VG_Line *vl = p;
	VG_Vector v1 = VG_Pos(vl->p1);
	VG_Vector v2 = VG_Pos(vl->p2);

	return VG_PointLineDistance(v1, v2, vPt);
}

static void
Delete(void *p)
{
	VG_Line *vl = p;

	if (VG_DelRef(vl, vl->p1) == 0) { VG_Delete(vl->p1); }
	if (VG_DelRef(vl, vl->p2) == 0) { VG_Delete(vl->p2); }
}

static void
Move(void *p, VG_Vector vCurs, VG_Vector vRel)
{
	/* TODO */
}

const VG_NodeOps vgLineOps = {
	N_("Line"),
	&vgIconLine,
	sizeof(VG_Line),
	Init,
	NULL,			/* destroy */
	Load,
	Save,
	Draw,
	Extent,
	PointProximity,
	NULL,			/* lineProximity */
	Delete,
	Move
};
