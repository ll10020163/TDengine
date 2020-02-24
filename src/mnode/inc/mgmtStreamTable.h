/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TBASE_MNODE_STREAM_TABLE_H
#define TBASE_MNODE_STREAM_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "mnode.h"

int32_t mgmtInitStreamTables();
void    mgmtCleanUpStreamTables();

void *  mgmtGetStreamTable(char *tableId);

int32_t mgmtCreateStreamTable(SDbObj *pDb, SCreateTableMsg *pCreate, SVgObj *pVgroup, int32_t sid);
int32_t mgmtDropStreamTable(SDbObj *pDb, SStreamTableObj *pTable);
int32_t mgmtAlterStreamTable(SDbObj *pDb, SAlterTableMsg *pAlter);
int8_t *mgmtBuildCreateStreamTableMsg(SStreamTableObj *pTable, SVgObj *pVgroup);

int32_t mgmtGetStreamTableMeta(SDbObj *pDb, SStreamTableObj *pTable, SMeterMeta *pMeta, bool usePublicIp);

#ifdef __cplusplus
}
#endif

#endif
