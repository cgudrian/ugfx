/*
    ChibiOS/GFX - Copyright (C) 2012
                 Joel Bodenmann aka Tectu <joel@unormal.org>

    This file is part of ChibiOS/GFX.

    ChibiOS/GFX is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/GFX is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file	include/console.h
 * @brief	CONSOLE header file.
 *
 * @addtogroup CONSOLE
 * @{
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#ifndef GFX_USE_CONSOLE
	#define GFX_USE_CONSOLE FALSE
#endif

#if GFX_USE_CONSOLE

#include "gdisp.h"

 /**
 * @extends BaseAsynchronousChannelVMT
 *
 * @brief   @p GConsole virtual methods table.
 */
struct GConsoleVMT {
	_base_asynchronous_channel_methods
};

/**
 * @extends BaseAsynchronousChannel
 *
 * @brief   GConsole class.
 * @details This class extends @p BaseAsynchronousChannel by adding physical
 *          I/O queues.
 */
typedef struct _GConsole {
	/** @brief Virtual Methods Table.*/
	const struct GConsoleVMT *vmt;
	_base_asynchronous_channel_data
	/* WARNING: Do not add any data to this struct above this comment, only below */
	/* font */
	font_t font;
	/* lcd area to use */
	coord_t x0,y0;
	/* current cursor position, in pixels */
	coord_t cx,cy;
	/* console size in pixels */
	coord_t sx,sy;
	/* foreground and background colour */
	color_t bkcolor, color;
	/* font size in pixels */
	uint8_t fy;
	/* font inter-character padding in pixels */
	uint8_t fp;
} GConsole; 

#ifdef __cplusplus
extern "C" {
#endif

msg_t gfxConsoleInit(GConsole *console, coord_t x0, coord_t y0, coord_t width, coord_t height, font_t font, pixel_t bkcolor, pixel_t color);
msg_t gfxConsolePut(GConsole *console, char c);
msg_t gfxConsoleWrite(GConsole *console, const uint8_t *bp, size_t n);

#ifdef __cplusplus
}
#endif

#endif /* GFX_USE_CONSOLE */

#endif /* CONSOLE_H */
/** @} */

