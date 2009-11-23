/***************************************************************************
 *   Copyright (C) 2009 by Simon Qian <SimonQian@SimonQian.com>            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef __FILELIST_H_INCLUDED__
#define __FILELIST_H_INCLUDED__

#include "list.h"

typedef struct FILELIST
{
	char *path;
	FILE *file;
	uint32_t seg_offset;
	uint32_t addr_offset;
	struct SLLIST list;
}filelist;

#define FILELIST_GetNext(fl)						\
						sllist_get_container(fl->list.next, filelist, list)

RESULT FILELIST_Add(filelist **fl, char *path, uint32_t seg_offset, 
					uint32_t addr_offset, char *attr);
void FILELIST_Free(filelist **fl);

#endif /* __FILELIST_H_INCLUDED__ */
