/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program;
 * If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef __CGM_METAFILE_WRITER_H__
#define __CGM_METAFILE_WRITER_H__

#include "cgm/Metafile.h"
#include "cgm/TextElement.h"
#include "cgm/PolygonElement.h"
#include "cgm/PolyLineElement.h"
#include "cgm/PolySetElement.h"
#include "cgm/RectangleElement.h"
#include "cgm/CircleElement.h"
#include "cgm/EllipseElement.h"
#include "cgm/CircularArcElement.h"
#include "cgm/CircularArcCloseElement.h"
#include "cgm/EllipticalArcElement.h"
#include "cgm/EllipticalArcCloseElement.h"

NITF_CXX_GUARD


typedef NITF_BOOL (*CGM_PACK)(cgm_Element* element, nitf_IOHandle io);



typedef struct _cgm_ElementWriter
{
    int type;
    CGM_PACK pack;
} cgm_ElementWriter;

typedef struct _cgm_MetafileWriter
{
    cgm_ElementWriter* packer;
} cgm_MetafileWriter;

NITFAPI(cgm_MetafileWriter*) 
cgm_MetafileWriter_construct(nitf_Error* error);

NITFAPI(void) 
cgm_MetafileWriter_destruct(cgm_MetafileWriter** writer);

NITFAPI(NITF_BOOL) cgm_MetafileWriter_writeFile(cgm_MetafileWriter* writer,
                                                cgm_Metafile* mf,
                                                nitf_IOHandle io,
                                                nitf_Error* error);
                   
NITF_CXX_ENDGUARD

#endif
