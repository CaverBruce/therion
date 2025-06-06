/**
 * @file thexporter.h
 * Exporter class.
 */
  
/* Copyright (C) 2000 Stacho Mudrak
 * 
 * $Date: $
 * $RCSfile: $
 * $Revision: $
 *
 * -------------------------------------------------------------------- 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 * --------------------------------------------------------------------
 */
 
#ifndef thexporter_h
#define thexporter_h


#include "thexport.h"
#include "thstok.h"
#include <stdio.h>
#include <list>
#include <memory>


/**
 * Export types.
 */

enum {
  TT_EXP_UNKNOWN = 0,  ///< Not match.
  TT_EXP_MODEL,  ///< 3D model.
  TT_EXP_MAP, ///< 2D map.
  TT_EXP_ATLAS,  ///< 2D atlas.
  TT_EXP_DATABASE,  ///< Database export.
  TT_EXP_CONTLIST,  ///< Table with specified data.
  TT_EXP_SURVEYLIST,  ///< Table with specified data.
  TT_EXP_CAVELIST,  ///< Export entrance list.
};


/**
 * Export token table.
 */
 
static const thstok thtt_exporter[] = {
  {"atlas", TT_EXP_ATLAS},
  {"cave-list", TT_EXP_CAVELIST},
  {"continuation-list", TT_EXP_CONTLIST},
  {"database", TT_EXP_DATABASE},
  {"map", TT_EXP_MAP},
  {"model", TT_EXP_MODEL},
  {"survey-list", TT_EXP_SURVEYLIST},
  {NULL, TT_EXP_UNKNOWN}
};


/**
 * Export list.
 */
 
using thexporter_list = std::list<std::unique_ptr<thexport>>;


/**
 * Data exporter class.
 */
 
class thexporter {

  class thconfig * cfgptr;  ///< Current config pointer.
  
  thexporter_list xlist;  ///< Export list.

  public:
  
  thexporter();  ///< Default constructor.
  
  void assign_config(class thconfig * cptr);  ///< ??
  
  /**
   * Parse export option.
   */
   
  void parse_export(int nargs, char ** args);
  
  /**
   * Parse export option.
   */
   
  void parse_system(char * system_cmd);
  
  /**
   * Export database.
   */
   
  void export_db(class thdatabase * dp);
  
  
  /**
   * Dump export into file.
   */
   
  void dump_export(FILE * xf);
    
};

/**
 * Quick map export indicator.
 */
 
extern bool thexporter_quick_map_export;

#endif


