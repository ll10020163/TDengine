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

#ifndef TBASE_MNODE_SUPER_TABLE_H
#define TBASE_MNODE_SUPER_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "taosdef.h"
#include "mnode.h"

int32_t mgmtInitSuperTables();
void    mgmtCleanUpSuperTables();

void *  mgmtGetSuperTable(char *tableId);
int32_t mgmtGetShowSuperTableMeta(SMeterMeta *pMeta, SShowObj *pShow, void *pConn);
int32_t mgmtRetrieveShowSuperTables(SShowObj *pShow, char *data, int32_t rows, void *pConn);

int32_t mgmtCreateSuperTable(SDbObj *pDb, SCreateTableMsg *pCreate);
int32_t mgmtDropSuperTable(SDbObj *pDb, SSuperTableObj *pTable);
int32_t mgmtAddSuperTableTag(SSuperTableObj *pTable, SSchema schema[], int32_t ntags);
int32_t mgmtDropSuperTableTag(SSuperTableObj *pTable, char *tagName);
int32_t mgmtModifySuperTableTagNameByName(SSuperTableObj *pTable, char *oldTagName, char *newTagName);
int32_t mgmtAddSuperTableColumn(SSuperTableObj *pTable, SSchema schema[], int32_t ncols);
int32_t mgmtDropSuperTableColumnByName(SSuperTableObj *pTable, char *colName);

int32_t mgmtGetSuperTableMeta(SDbObj *pDb, SSuperTableObj *pTable, SMeterMeta *pMeta, bool usePublicIp);

int32_t mgmtFindSuperTableTagIndex(SSuperTableObj *pTable, const char *tagName);
int32_t mgmtSetSchemaFromSuperTable(SSchema *pSchema, SSuperTableObj *pTable);
int32_t mgmtGetTagsLength(SSuperTableObj *pSuperTable, int32_t col);

#ifdef __cplusplus
}
#endif

#endif
