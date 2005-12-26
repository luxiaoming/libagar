/*	$Csoft: typesw.c,v 1.24 2005/09/20 13:46:29 vedge Exp $	*/

/*
 * Copyright (c) 2003, 2004, 2005 CubeSoft Communications, Inc.
 * <http://www.csoft.org>
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

#include <core/core.h>
#include <core/typesw.h>

#include <string.h>

extern const AG_ObjectOps agObjectOps;
AG_ObjectType *agTypes = NULL;
int agnTypes = 0;

/* Initialize the type switch and register the built-in types. */
void
AG_InitTypeSw(void)
{
	agTypes = Malloc(sizeof(AG_ObjectType), M_TYPESW);
	agnTypes = 0;
	AG_RegisterType("object", sizeof(AG_Object), &agObjectOps, OBJ_ICON);
}

void
AG_DestroyTypeSw(void)
{
	Free(agTypes, M_TYPESW);
}

void
AG_RegisterType(const char *type, size_t size, const AG_ObjectOps *ops,
    int icon)
{
	AG_ObjectType *ntype;

	agTypes = Realloc(agTypes, (agnTypes+1)*sizeof(AG_ObjectType));
	ntype = &agTypes[agnTypes++];
	strlcpy(ntype->type, type, sizeof(ntype->type));
	ntype->size = size;
	ntype->ops = ops != NULL ? ops : &agObjectOps;
	ntype->icon = icon;
}

AG_ObjectType *
AG_FindType(const char *type)
{
	int i;

	for (i = 0; i < agnTypes; i++) {
		if (strcmp(agTypes[i].type, type) == 0)
			return (&agTypes[i]);
	}
	return (NULL);
}
