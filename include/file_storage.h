﻿/* ***************************************************************************
 * file_storage.h -- File related operating interface, based on file storage
 * service.
 *
 * Copyright (C) 2016-2017 by Liu Chao <lc-soft@live.cn>
 *
 * This file is part of the LC-Finder project, and may only be used, modified,
 * and distributed under the terms of the GPLv2.
 *
 * By continuing to use, modify, or distribute this file you indicate that you
 * have read the license and understand and accept it fully.
 *
 * The LC-Finder project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GPL v2 for more details.
 *
 * You should have received a copy of the GPLv2 along with this file. It is
 * usually in the LICENSE.TXT file, If not, see <http://www.gnu.org/licenses/>.
 * ****************************************************************************/

/* ****************************************************************************
 * file_storage.h -- 基于文件存储服务而实现的文件相关操作接口
 *
 * 版权所有 (C) 2016-2017 归属于 刘超 <lc-soft@live.cn>
 *
 * 这个文件是 LC-Finder 项目的一部分，并且只可以根据GPLv2许可协议来使用、更改和
 * 发布。
 *
 * 继续使用、修改或发布本文件，表明您已经阅读并完全理解和接受这个许可协议。
 *
 * LC-Finder 项目是基于使用目的而加以散布的，但不负任何担保责任，甚至没有适销
 * 性或特定用途的隐含担保，详情请参照GPLv2许可协议。
 *
 * 您应已收到附随于本文件的GPLv2许可协议的副本，它通常在 LICENSE 文件中，如果
 * 没有，请查看：<http://www.gnu.org/licenses/>.
 * ****************************************************************************/

#ifndef LCFINDER_FILE_STORAGE_H
#define LCFINDER_FILE_STORAGE_H

#include "file_service.h"

typedef void( *HandlerOnGetImage )(LCUI_Graph*, void*);
typedef void( *HandlerOnGetStatus )(FileStatus*, void*);
typedef void( *HandlerOnGetFile )(FileStatus*, FileStream, void*);
typedef void( *HandlerOnGetThumbnail )(FileStatus*, LCUI_Graph*, void*);

void FileStorage_Init( void );

int FileStorage_Connect( void );

void FileStorage_Close( int id );

void FileStorage_Exit( void );

static void OnResponse( FileResponse *response, void *data );

int FileStorage_GetFile( int conn_id, const wchar_t *filename,
			 HandlerOnGetFile callback, void *data );

int FileStorage_GetFiles( int conn_id, const wchar_t *filename,
			  HandlerOnGetFile callback, void *data );

int FileStorage_GetFolders( int conn_id, const wchar_t *filename,
			    HandlerOnGetFile callback, void *data );

int FileStorage_GetImage( int conn_id, const wchar_t *filename,
			  HandlerOnGetImage callback, void *data );

int FileStorage_GetThumbnail( int conn_id, const wchar_t *filename,
			      int width, int height,
			      HandlerOnGetThumbnail callback, void *data );

int FileStorage_GetStatus( int conn_id, const wchar_t *filename,
			   LCUI_BOOL with_extra,
			   HandlerOnGetStatus callback, void *data );

#endif
