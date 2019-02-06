/* ------------------------------------------------------------
name: "FilDeSoi1SoundProcess8LS"
Code generated with Faust 2.14.3 (https://faust.grame.fr)
Compilation options: -double -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************

    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2004-2028 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

    MAX MSP SDK : in order to compile a MaxMSP external with this
    architecture file you will need the official MaxMSP SDK from
    cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

#define FAUSTFLOAT double

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        void pushLabel(const std::string& label) { fControlsLevel.push_back(label); }
        void popLabel() { fControlsLevel.pop_back(); }
    
};

#endif  // FAUST_PATHBUILDER_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fDSPSize;           // In bytes
        std::map<std::string, int> fPathTable;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        // Add escape (that is  '\') for internal strings
        std::string flatten(const std::string& src)
        {
            bool in_string = false;
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    case ' ':
                        if (in_string) dst << src[i];
                        break;
                    case '"':
                        dst << "\\" << '"';
                        in_string = !in_string;
                        break;
                    case '\\':
                        dst << '\\' << '\\';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        std::string getAddressIndex(const std::string& path)
        {
            if (fPathTable.find(path) != fPathTable.end()) {
                std::stringstream num; num << fPathTable[path];
                return num.str();
            } else {
                return "-1";
            }
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), "", std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), "", std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), "", std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            fTab = 1;
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\"";
            }
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            tab(fTab, fJSON); fJSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, fJSON); fJSON << "\"version\": \"" << fVersion << "\","; }
            if (fCompileOptions != "") { tab(fTab, fJSON); fJSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
            if (fLibraryList.size() > 0) {
                tab(fTab, fJSON);
                fJSON << "\"library_list\": [";
                for (size_t i = 0; i < fLibraryList.size(); i++) {
                    fJSON << "\"" << fLibraryList[i] << "\"";
                    if (i < (fLibraryList.size() - 1)) fJSON << ",";
                }
                fJSON << "],";
            }
            if (fIncludePathnames.size() > 0) {
                tab(fTab, fJSON);
                fJSON << "\"include_pathnames\": [";
                for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                    fJSON << "\"" << fIncludePathnames[i] << "\"";
                    if (i < (fIncludePathnames.size() - 1)) fJSON << ",";
                }
                fJSON << "],";
            }
            if (fDSPSize != "") { tab(fTab, fJSON); fJSON << "\"size\": \"" << fDSPSize << "\","; }
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}";
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& compile_options,
               const std::vector<std::string>& library_list,
               const std::vector<std::string>& include_pathnames,
               const std::string& size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sha_key, dsp_code,
                              version, compile_options,
                              library_list, include_pathnames,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sstream>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string url;
    std::string address;
    std::string index;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

/*
// Menu {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values);
static bool parseMenuItem(const char*& p, std::string& name, double& value);

// Menu {'foo.wav'; 'bar.wav'}
static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug = false);
static bool parseMenuItem2(const char*& p, std::string& name);

static void skipBlank(const char*& p);
static bool parseChar(const char*& p, char x);
static bool parseWord(const char*& p, const char* w);
static bool parseString(const char*& p, char quote, std::string& s);
static bool parseSQString(const char*& p, std::string& s);
static bool parseDQString(const char*& p, std::string& s);
static bool parseDouble(const char*& p, double& x);
static bool parseList(const char*& p, std::vector<std::string>& items);
*/

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    
    bool valid = false;    // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p; // to restore position if we fail
    
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { std::cerr << "parseMenuList2 : (" << saved << ") is not a valid list !\n"; }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items));
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->url = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->index = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas1, std::map<std::string, std::vector<std::string> >& metadatas2, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, metadatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metadatas2[key] = items;
                    items.clear();
                } else {
                    metadatas1[key] = value;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

static FAUSTFLOAT STR2REAL(const std::string& s) { return FAUSTFLOAT(std::strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

struct Soundfile;

typedef std::map<std::string, std::pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas;
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    Soundfile** fSoundfiles;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems, fSoundfileItems;
    
    std::string fVersion;
    std::string fCompileOptions;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]

    bool isInput(const std::string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::vector<std::string> > meta_datas;
        parseJson(p, fMetadatas, meta_datas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
        
        if (fMetadatas.find("filename") != fMetadatas.end()) {
            fFileName = fMetadatas["filename"];
            fMetadatas.erase("filename");
        } else {
            fName = "";
        }
     
        if (fMetadatas.find("version") != fMetadatas.end()) {
            fVersion = fMetadatas["version"];
            fMetadatas.erase("version");
        } else {
            fVersion = "";
        }
        
        if (fMetadatas.find("compile_options") != fMetadatas.end()) {
            fCompileOptions = fMetadatas["compile_options"];
            fMetadatas.erase("compile_options");
        } else {
            fCompileOptions = "";
        }
        
        if (meta_datas.find("library_list") != meta_datas.end()) {
            fLibraryList = meta_datas["library_list"];
            meta_datas.erase("library_list");
        }
        
        if (meta_datas.find("include_pathnames") != meta_datas.end()) {
            fIncludePathnames = meta_datas["include_pathnames"];
            meta_datas.erase("include_pathnames");
        }
  
        if (fMetadatas.find("size") != fMetadatas.end()) {
            fDSPSize = std::atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = std::atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = std::atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
       
        fInputItems = 0;
        fOutputItems = 0;
        fSoundfileItems = 0;
        
        std::vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            std::string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            } else if (isSoundfile(type)) {
                fSoundfileItems++;
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        fSoundfiles = new Soundfile*[fSoundfileItems];
        
        int counterIn = 0;
        int counterOut = 0;
        
        // Prepare the fPathTable and init zone
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            std::string type = (*it)->type;
            // Meta data declaration for input items
            if (isInput(type)) {
                if ((*it)->address != "") {
                    fPathInputTable[(*it)->address] = std::make_pair(std::atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = std::make_pair(std::atoi((*it)->index.c_str()), &fOutControl[counterOut]);
                }
                fOutControl[counterOut] = FAUSTFLOAT(0);
                counterOut++;
            }
        }
    }
    
    virtual ~JSONUIDecoder() 
    {
        std::vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
        delete [] fSoundfiles;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        std::vector<itemInfo*>::iterator it;
        int item = 0;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            if (isInput((*it)->type)) {
                fInControl[item++] = STR2REAL((*it)->init);
            }
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        int counterSound = 0;
        std::vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            std::string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                fInControl[counterIn] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                fOutControl[counterOut] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "soundfile") {
                ui->addSoundfile((*it)->label.c_str(), (*it)->url.c_str(), &fSoundfiles[counterSound]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
            
            if (isInput(type)) {
                counterIn++;
            } else if (isOutput(type)) {
                counterOut++;
            } else if (isSoundfile(type)) {
                counterSound++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

// Base class and common code for binary combiners

class dsp_binary_combiner : public dsp {
    
    protected:
        
        dsp* fDSP1;
        dsp* fDSP2;
        
     public:
        
        dsp_binary_combiner(dsp* dsp1, dsp* dsp2):fDSP1(dsp1), fDSP2(dsp2)
        {}
        
        virtual ~dsp_binary_combiner()
        {
            delete fDSP1;
            delete fDSP2;
        }
    
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
        
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
        
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
        
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
        
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
        
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
};

// Combine two 'compatible' DSP in sequence

class dsp_sequencer : public dsp_binary_combiner {
    
    private:
    
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
    
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
    
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp_binary_combiner {
    
    private:
        
        FAUSTFLOAT** fInputsDSP2;
        FAUSTFLOAT** fOutputsDSP2;
    
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fInputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fOutputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }
        
        virtual ~dsp_parallelizer()
        {
            delete [] fInputsDSP2;
            delete [] fOutputsDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
    
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fInputsDSP2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fOutputsDSP2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, fInputsDSP2, fOutputsDSP2);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
    
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <cstdlib>
#include <string.h>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

static int lsr(int x, int n) { return int(((unsigned int)x) >> n); }

static int int2pow2(int x) { int r = 0; while ((1<<r) < x) r++; return r; }

static long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

static bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// Always included
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

/*
   Copyright (C) 2011 Grame - Lyon
   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted.
*/

#ifndef __OSCUI__
#define __OSCUI__

#include <vector>
#include <string>

/*

  Faust Project

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __OSCControler__
#define __OSCControler__

#include <string>
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustFactory__
#define __FaustFactory__

#include <stack>
#include <string>
#include <sstream>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustNode__
#define __FaustNode__

#include <string>
#include <vector>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageDriven__
#define __MessageDriven__

#include <string>
#include <vector>

/*

  Copyright (C) 2010  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageProcessor__
#define __MessageProcessor__

namespace oscfaust
{

class Message;
//--------------------------------------------------------------------------
/*!
	\brief an abstract class for objects able to process OSC messages	
*/
class MessageProcessor
{
	public:
		virtual		~MessageProcessor() {}
		virtual void processMessage( const Message* msg ) = 0;
};

} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __smartpointer__
#define __smartpointer__

#include <cassert>

namespace oscfaust
{

/*!
\brief the base class for smart pointers implementation

	Any object that want to support smart pointers should
	inherit from the smartable class which provides reference counting
	and automatic delete when the reference count drops to zero.
*/
class smartable {
	private:
		unsigned 	refCount;		
	public:
		//! gives the reference count of the object
		unsigned refs() const         { return refCount; }
		//! addReference increments the ref count and checks for refCount overflow
		void addReference()           { refCount++; assert(refCount != 0); }
		//! removeReference delete the object when refCount is zero		
		void removeReference()		  { if (--refCount == 0) delete this; }
		
	protected:
		smartable() : refCount(0) {}
		smartable(const smartable&): refCount(0) {}
		//! destructor checks for non-zero refCount
		virtual ~smartable()    
        { 
            /* 
                See "Static SFaustNode create (const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui)" comment.
                assert (refCount == 0); 
            */
        }
		smartable& operator=(const smartable&) { return *this; }
};

/*!
\brief the smart pointer implementation

	A smart pointer is in charge of maintaining the objects reference count 
	by the way of pointers operators overloading. It supports class 
	inheritance and conversion whenever possible.
\n	Instances of the SMARTP class are supposed to use \e smartable types (or at least
	objects that implements the \e addReference and \e removeReference
	methods in a consistent way).
*/
template<class T> class SMARTP {
	private:
		//! the actual pointer to the class
		T* fSmartPtr;

	public:
		//! an empty constructor - points to null
		SMARTP()	: fSmartPtr(0) {}
		//! build a smart pointer from a class pointer
		SMARTP(T* rawptr) : fSmartPtr(rawptr)              { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from an convertible class reference
		template<class T2> 
		SMARTP(const SMARTP<T2>& ptr) : fSmartPtr((T*)ptr) { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from another smart pointer reference
		SMARTP(const SMARTP& ptr) : fSmartPtr((T*)ptr)     { if (fSmartPtr) fSmartPtr->addReference(); }

		//! the smart pointer destructor: simply removes one reference count
		~SMARTP()  { if (fSmartPtr) fSmartPtr->removeReference(); }
		
		//! cast operator to retrieve the actual class pointer
		operator T*() const  { return fSmartPtr;	}

		//! '*' operator to access the actual class pointer
		T& operator*() const {
			// checks for null dereference
			assert (fSmartPtr != 0);
			return *fSmartPtr;
		}

		//! operator -> overloading to access the actual class pointer
		T* operator->() const	{ 
			// checks for null dereference
			assert (fSmartPtr != 0);
			return fSmartPtr;
		}

		//! operator = that moves the actual class pointer
		template <class T2>
		SMARTP& operator=(T2 p1_)	{ *this=(T*)p1_; return *this; }

		//! operator = that moves the actual class pointer
		SMARTP& operator=(T* p_)	{
			// check first that pointers differ
			if (fSmartPtr != p_) {
				// increments the ref count of the new pointer if not null
				if (p_ != 0) p_->addReference();
				// decrements the ref count of the old pointer if not null
				if (fSmartPtr != 0) fSmartPtr->removeReference();
				// and finally stores the new actual pointer
				fSmartPtr = p_;
			}
			return *this;
		}
		//! operator < to support SMARTP map with Visual C++
		bool operator<(const SMARTP<T>& p_)	const			  { return fSmartPtr < ((T *) p_); }
		//! operator = to support inherited class reference
		SMARTP& operator=(const SMARTP<T>& p_)                { return operator=((T *) p_); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(T2* p_)               { return operator=(dynamic_cast<T*>(p_)); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(const SMARTP<T2>& p_) { return operator=(dynamic_cast<T*>(p_)); }
};

}

#endif

namespace oscfaust
{

class Message;
class OSCRegexp;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a base class for objects accepting OSC messages
	
	Message driven objects are hierarchically organized in a tree.
	They provides the necessary to dispatch an OSC message to its destination
	node, according to the message OSC address. 
	
	The principle of the dispatch is the following:
	- first the processMessage() method should be called on the top level node
	- next processMessage call propose 
*/
class MessageDriven : public MessageProcessor, public smartable
{
	std::string						fName;			///< the node name
	std::string						fOSCPrefix;		///< the node OSC address prefix (OSCAddress = fOSCPrefix + '/' + fName)
	std::vector<SMessageDriven>		fSubNodes;		///< the subnodes of the current node

	protected:
				 MessageDriven(const char *name, const char *oscprefix) : fName (name), fOSCPrefix(oscprefix) {}
		virtual ~MessageDriven() {}

	public:
		static SMessageDriven create(const char* name, const char *oscprefix)	{ return new MessageDriven(name, oscprefix); }

		/*!
			\brief OSC message processing method.
			\param msg the osc message to be processed
			The method should be called on the top level node.
		*/
		virtual void	processMessage(const Message* msg);

		/*!
			\brief propose an OSc message at a given hierarchy level.
			\param msg the osc message currently processed
			\param regexp a regular expression based on the osc address head
			\param addrTail the osc address tail
			
			The method first tries to match the regular expression with the object name. 
			When it matches:
			- it calls \c accept when \c addrTail is empty 
			- or it \c propose the message to its subnodes when \c addrTail is not empty. 
			  In this case a new \c regexp is computed with the head of \c addrTail and a new \c addrTail as well.
		*/
		virtual void	propose(const Message* msg, const OSCRegexp* regexp, const std::string addrTail);

		/*!
			\brief accept an OSC message. 
			\param msg the osc message currently processed
			\return true when the message is processed by the node
			
			The method is called only for the destination nodes. The real message acceptance is the node 
			responsability and may depend on the message content.
		*/
		virtual bool	accept(const Message* msg);

		/*!
			\brief handler for the \c 'get' message
			\param ipdest the output message destination IP
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get(unsigned long ipdest) const;

		/*!
			\brief handler for the \c 'get' 'attribute' message
			\param ipdest the output message destination IP
			\param what the requested attribute
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get (unsigned long ipdest, const std::string & what) const {}

		void			add(SMessageDriven node)	{ fSubNodes.push_back (node); }
		const char*		getName() const				{ return fName.c_str(); }
		std::string		getOSCAddress() const;
		int				size() const				{ return (int)fSubNodes.size (); }
		
		const std::string&	name() const			{ return fName; }
		SMessageDriven	subnode(int i)              { return fSubNodes[i]; }
};

} // end namespoace

#endif
/*

  Copyright (C) 2011  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/


#ifndef __Message__
#define __Message__

#include <string>
#include <vector>

namespace oscfaust
{

class OSCStream;
template <typename T> class MsgParam;
class baseparam;
typedef SMARTP<baseparam>	Sbaseparam;

//--------------------------------------------------------------------------
/*!
	\brief base class of a message parameters
*/
class baseparam : public smartable
{
	public:
		virtual ~baseparam() {}

		/*!
		 \brief utility for parameter type checking
		*/
		template<typename X> bool isType() const { return dynamic_cast<const MsgParam<X>*> (this) != 0; }
		/*!
		 \brief utility for parameter convertion
		 \param errvalue the returned value when no conversion applies
		 \return the parameter value when the type matches
		*/
		template<typename X> X	value(X errvalue) const 
			{ const MsgParam<X>* o = dynamic_cast<const MsgParam<X>*> (this); return o ? o->getValue() : errvalue; }
		/*!
		 \brief utility for parameter comparison
		*/
		template<typename X> bool	equal(const baseparam& p) const 
			{ 
				const MsgParam<X>* a = dynamic_cast<const MsgParam<X>*> (this); 
				const MsgParam<X>* b = dynamic_cast<const MsgParam<X>*> (&p);
				return a && b && (a->getValue() == b->getValue());
			}
		/*!
		 \brief utility for parameter comparison
		*/
		bool operator==(const baseparam& p) const 
			{ 
				return equal<float>(p) || equal<int>(p) || equal<std::string>(p);
			}
		bool operator!=(const baseparam& p) const
			{ 
				return !equal<float>(p) && !equal<int>(p) && !equal<std::string>(p);
			}
			
		virtual SMARTP<baseparam> copy() const = 0;
};

//--------------------------------------------------------------------------
/*!
	\brief template for a message parameter
*/
template <typename T> class MsgParam : public baseparam
{
	T fParam;
	public:
				 MsgParam(T val) : fParam(val)	{}
		virtual ~MsgParam() {}
		
		T getValue() const { return fParam; }
		
		virtual Sbaseparam copy() const { return new MsgParam<T>(fParam); }
};

//--------------------------------------------------------------------------
/*!
	\brief a message description
	
	A message is composed of an address (actually an OSC address),
	a message string that may be viewed as a method name
	and a list of message parameters.
*/
class Message
{
    public:
        typedef SMARTP<baseparam>		argPtr;		///< a message argument ptr type
        typedef std::vector<argPtr>		argslist;	///< args list type

    private:
        unsigned long	fSrcIP;			///< the message source IP number
        std::string	fAddress;			///< the message osc destination address
        std::string	fAlias;             ///< the message alias osc destination address
        argslist	fArguments;			///< the message arguments

    public:
            /*!
                \brief an empty message constructor
            */
             Message() {}
            /*!
                \brief a message constructor
                \param address the message destination address
            */
            Message(const std::string& address) : fAddress(address), fAlias("") {}
             
            Message(const std::string& address, const std::string& alias) : fAddress(address), fAlias(alias) {}
            /*!
                \brief a message constructor
                \param address the message destination address
                \param args the message parameters
            */
            Message(const std::string& address, const argslist& args) 
                : fAddress(address), fArguments(args) {}
            /*!
                \brief a message constructor
                \param msg a message
            */
             Message(const Message& msg);
    virtual ~Message() {} //{ freed++; std::cout << "running messages: " << (allocated - freed) << std::endl; }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    template <typename T> void add(T val)	{ fArguments.push_back(new MsgParam<T>(val)); }
    /*!
        \brief adds a float parameter to the message
        \param val the parameter value
    */
    void	add(float val)					{ add<float>(val); }
    /*!
        \brief adds an int parameter to the message
        \param val the parameter value
    */
    void	add(int val)					{ add<int>(val); }
    /*!
        \brief adds a string parameter to the message
        \param val the parameter value
    */
    void	add(const std::string& val)		{ add<std::string>(val); }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    void	add(argPtr val)                 { fArguments.push_back( val ); }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setSrcIP(unsigned long addr)		{ fSrcIP = addr; }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setAddress(const std::string& addr)		{ fAddress = addr; }
    /*!
        \brief print the message
        \param out the output stream
    */
    void				print(std::ostream& out) const;
    /*!
        \brief send the message to OSC
        \param out the OSC output stream
    */
    void				print(OSCStream& out) const;
    /*!
        \brief print message arguments
        \param out the OSC output stream
    */
    void				printArgs(OSCStream& out) const;

    /// \brief gives the message address
    const std::string&	address() const		{ return fAddress; }
    /// \brief gives the message alias
    const std::string&	alias() const		{ return fAlias; }
    /// \brief gives the message parameters list
    const argslist&		params() const		{ return fArguments; }
    /// \brief gives the message parameters list
    argslist&			params()			{ return fArguments; }
    /// \brief gives the message source IP 
    unsigned long		src() const			{ return fSrcIP; }
    /// \brief gives the message parameters count
    int					size() const		{ return (int)fArguments.size(); }

    bool operator == (const Message& other) const;	

    /*!
        \brief gives a message float parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, float& val) const		{ val = params()[i]->value<float>(val); return params()[i]->isType<float>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, unsigned int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
        \note a boolean value is handled as integer
    */
    bool	param(int i, bool& val) const		{ int ival = 0; ival = params()[i]->value<int>(ival); val = ival!=0; return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, long int& val) const	{ val = long(params()[i]->value<int>(val)); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message string parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, std::string& val) const { val = params()[i]->value<std::string>(val); return params()[i]->isType<std::string>(); }
};


} // end namespoace

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <iostream>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
# pragma warning (disable: 4334)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

static void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

static int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

static size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

static size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

static size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone) {}
    
    virtual ~uiItemBase()
    {}
    
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    virtual void modifyZone(double date, FAUSTFLOAT v) {}
    virtual double cache() = 0;
    virtual void reflectZone() = 0;
};


static void deleteClist(clist* cl);

struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
        
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            zmap::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                delete (*it).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
 
        void updateAllZones()
        {
            for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
                FAUSTFLOAT* z = m->first;
                clist*	l = m->second;
                if (z) {
                    FAUSTFLOAT v = *z;
                    for (clist::iterator c = l->begin(); c != l->end(); c++) {
                        if ((*c)->cache() != v) (*c)->reflectZone();
                    }
                }
            }
        }
        
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* l = fZoneMap[z];
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
    
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        virtual void show() {};	
        virtual bool run() { return false; };

        static void runAllGuis() {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->run();
            }
        }
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

template <typename REAL>
class uiTypedItem : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItem(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItem()
        {}
    
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
    
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItem<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItem<FAUSTFLOAT>(ui, zone)
        {}

    public:

        virtual ~uiItem() 
        {}

		void modifyZone(FAUSTFLOAT v)
		{
			fCache = v;
			if (*fZone != v) {
				*fZone = v;
				fGUI->updateZone(fZone);
			}
		}

};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
        uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
        : uiItem(ui, zone), fCallback(foo), fData(data) {}
        
        virtual void reflectZone() 
        {		
            FAUSTFLOAT v = *fZone;
            fCache = v; 
            fCallback(v, fData);	
        }
};

/**
 *  For timestamped control
 */

struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items
 */

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        using uiItem::modifyZone;
        
    public:
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

// Can not be defined as method in the classes

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    std::list<uiItemBase*>::iterator it;
    for (it = cl->begin(); it != cl->end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __RootNode__
#define __RootNode__

#include <map>
#include <string>
#include <vector>


namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;

/**
 * an alias target includes a map to rescale input values to output values
 * and a target osc address. The input values can be given in reversed order
 * to reverse the control
 */
struct aliastarget
{
	float       fMinIn;
	float       fMaxIn;
	float       fMinOut;
	float       fMaxOut;
	std::string fTarget;	// the real osc address

	aliastarget(const char* address, float imin, float imax, float omin, float omax)
		: fMinIn(imin), fMaxIn(imax), fMinOut(omin), fMaxOut(omax), fTarget(address) {}

	aliastarget(const aliastarget& t)
		: fMinIn(t.fMinIn), fMaxIn(t.fMaxIn), fMinOut(t.fMinOut), fMaxOut(t.fMaxOut), fTarget(t.fTarget) {}

	float scale(float x) const 
    {
        if (fMinIn < fMaxIn) {
            // increasing control
            float z = (x < fMinIn) ? fMinIn : (x > fMaxIn) ? fMaxIn : x;
            return fMinOut + (z-fMinIn)*(fMaxOut-fMinOut)/(fMaxIn-fMinIn);
            
        } else if (fMinIn > fMaxIn) {
            // reversed control
            float z = (x < fMaxIn) ? fMaxIn : (x > fMinIn) ? fMinIn : x;
            return fMinOut + (fMinIn-z)*(fMaxOut-fMinOut)/(fMinIn-fMaxIn);
            
        } else {
            // no control !
            return (fMinOut+fMaxOut)/2.0f;
        }
    }
    
    float invscale(float x) const
    {
        if (fMinOut < fMaxOut) {
            // increasing control
            float z = (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x;
            return fMinIn + (z-fMinOut)*(fMaxIn-fMinIn)/(fMaxOut-fMinOut);
            
        } else if (fMinOut > fMaxOut) {
            // reversed control
            float z = (x < fMaxOut) ? fMaxOut : (x > fMinOut) ? fMinOut : x;
            return fMinIn + (fMinOut-z)*(fMaxIn-fMinIn)/(fMinOut-fMaxOut);
            
        } else {
            // no control !
            return (fMinIn+fMaxIn)/2.0f;
        }
    }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust root node

	A Faust root node handles the \c 'hello' message and provides support
	for incoming osc signal data. 
*/
class RootNode : public MessageDriven
{
	int *fUPDIn, *fUDPOut, *fUDPErr;	// the osc port numbers (required by the hello method)
	OSCIO* fIO;                         // an OSC IO controler
	
	typedef std::map<std::string, std::vector<aliastarget> > TAliasMap;
	TAliasMap fAliases;

	void processAlias(const std::string& address, float val);
	void eraseAliases(const std::string& target);
	void eraseAlias  (const std::string& target, const std::string& alias);
	bool aliasError  (const Message* msg);

	protected:
				 RootNode(const char *name, OSCIO* io = 0) : MessageDriven(name, ""), fUPDIn(0), fUDPOut(0), fUDPErr(0), fIO(io) {}
		virtual ~RootNode() {}

	public:
		static SRootNode create(const char* name, OSCIO* io = 0) { return new RootNode(name, io); }

		virtual void processMessage(const Message* msg);
		virtual bool accept(const Message* msg);
		virtual void get(unsigned long ipdest) const;
		virtual void get(unsigned long ipdest, const std::string& what) const;

        bool aliasMsg(const Message* msg, float omin, float omax);
        void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
        bool acceptSignal(const Message* msg);				///< handler for signal data
        void hello(unsigned long ipdest) const;				///< handler for the 'hello' message
        void setPorts(int* in, int* out, int* err);
        
        std::vector<std::pair<std::string, double> > getAliases(const std::string& address, double value);
};

} // end namespoace

#endif

class GUI;

namespace oscfaust
{

/**
 * map (rescale) input values to output values
 */
template <typename C> struct mapping
{
	const C fMinOut;
	const C fMaxOut;
	mapping(C omin, C omax) : fMinOut(omin), fMaxOut(omax) {}
	C clip (C x) { return (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x; }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust node is a terminal node and represents a faust parameter controler
*/
template <typename C> class FaustNode : public MessageDriven, public uiTypedItem<C>
{
	mapping<C>	fMapping;
    RootNode* fRoot;
    bool fInput;  // true for input nodes (slider, button...)
	
	//---------------------------------------------------------------------
	// Warning !!!
	// The cast (C *)fZone is necessary because the real size allocated is
	// only known at execution time. When the library is compiled, fZone is
	// uniquely defined by FAUSTFLOAT.
	//---------------------------------------------------------------------
	bool	store(C val) { *(C *)this->fZone = fMapping.clip(val); return true; }
	void	sendOSC() const;

	protected:
		FaustNode(RootNode* root, const char *name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input) 
			: MessageDriven(name, prefix), uiTypedItem<C>(ui, zone), fMapping(min, max), fRoot(root), fInput(input)
			{
                if (initZone) {
                    *zone = init; 
                }
            }
			
		virtual ~FaustNode() {}

	public:
		typedef SMARTP<FaustNode<C> > SFaustNode;
		static SFaustNode create(RootNode* root, const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input)	
        { 
            SFaustNode node = new FaustNode(root, name, zone, init, min, max, prefix, ui, initZone, input); 
            /*
                Since FaustNode is a subclass of uiItem, the pointer will also be kept in the GUI class, and it's desallocation will be done there.
                So we don't want to have smartpointer logic desallocate it and we increment the refcount.
            */
            node->addReference();
            return node; 
        }
    
		bool accept(const Message* msg);
		void get(unsigned long ipdest) const;		///< handler for the 'get' message
		virtual void reflectZone() { sendOSC(); this->fCache = *this->fZone; }
};

} // end namespace

#endif

class GUI;
namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a factory to build a OSC UI hierarchy
	
	Actually, makes use of a stack to build the UI hierarchy.
	It includes a pointer to a OSCIO controler, but just to give it to the root node.
*/
class FaustFactory
{
	std::stack<SMessageDriven>	fNodes;		///< maintains the current hierarchy level
	SRootNode					fRoot;		///< keep track of the root node
	OSCIO*                      fIO;		///< hack to support audio IO via OSC, actually the field is given to the root node
	GUI*						fGUI;		///< a GUI pointer to support updateAllGuis(), required for bi-directionnal OSC

	private:
		std::string addressFirst(const std::string& address) const;
		std::string addressTail(const std::string& address) const;

	public:
				 FaustFactory(GUI* ui, OSCIO * io = 0); 
		virtual ~FaustFactory(); 

		template <typename C> void addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input);
		template <typename C> void addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label);
        
		void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
		void opengroup(const char* label);
		void closegroup();

		SRootNode root() const; 
};

/**
 * Add a node to the OSC UI tree in the current group at the top of the stack 
 */
template <typename C> void FaustFactory::addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input) 
{
	SMessageDriven top;
	if (fNodes.size()) top = fNodes.top();
	if (top) {
		std::string prefix = top->getOSCAddress();
		top->add(FaustNode<C>::create(root(), label, zone, init, min, max, prefix.c_str(), fGUI, initZone, input));
	}
}

/**
 * Add an alias (actually stored and handled at root node level
 */
template <typename C> void FaustFactory::addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label)
{
	std::istringstream 	ss(fullpath);
	std::string 		realpath; 
 
	ss >> realpath >> imin >> imax;
	SMessageDriven top = fNodes.top();
	if (top) {
		std::string target = top->getOSCAddress() + "/" + label;
		addAlias(realpath.c_str(), target.c_str(), float(imin), float(imax), float(min), float(max));
	}
}

} // end namespoace

#endif

class GUI;

typedef void (*ErrorCallback)(void*);  

namespace oscfaust
{

class OSCIO;
class OSCSetup;
class OSCRegexp;
    
//--------------------------------------------------------------------------
/*!
	\brief the main Faust OSC Lib API
	
	The OSCControler is essentially a glue between the memory representation (in charge of the FaustFactory),
	and the network services (in charge of OSCSetup).
*/
class OSCControler
{
	int fUDPPort,   fUDPOut, fUPDErr;	// the udp ports numbers
	std::string     fDestAddress;		// the osc messages destination address, used at initialization only
										// to collect the address from the command line
	std::string     fBindAddress;		// when non empty, the address used to bind the socket for listening
	OSCSetup*		fOsc;				// the network manager (handles the udp sockets)
	OSCIO*			fIO;				// hack for OSC IO support (actually only relayed to the factory)
	FaustFactory*	fFactory;			// a factory to build the memory represetnatin

    bool            fInit;
    
	public:
		/*
			base udp port is chosen in an unassigned range from IANA PORT NUMBERS (last updated 2011-01-24)
			see at http://www.iana.org/assignments/port-numbers
			5507-5552  Unassigned
		*/
		enum { kUDPBasePort = 5510};
            
        OSCControler(int argc, char *argv[], GUI* ui, OSCIO* io = 0, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true);

        virtual ~OSCControler();
	
		//--------------------------------------------------------------------------
		// addnode, opengroup and closegroup are simply relayed to the factory
		//--------------------------------------------------------------------------
		// Add a node in the current group (top of the group stack)
		template <typename T> void addnode(const char* label, T* zone, T init, T min, T max, bool input = true)
							{ fFactory->addnode(label, zone, init, min, max, fInit, input); }
		
		//--------------------------------------------------------------------------
		// This method is used for alias messages. The arguments imin and imax allow
		// to map incomming values from the alias input range to the actual range 
		template <typename T> void addAlias(const std::string& fullpath, T* zone, T imin, T imax, T init, T min, T max, const char* label)
							{ fFactory->addAlias(fullpath, zone, imin, imax, init, min, max, label); }

		void opengroup(const char* label)		{ fFactory->opengroup(label); }
		void closegroup()						{ fFactory->closegroup(); }
	   
		//--------------------------------------------------------------------------
		void run();				// starts the network services
		void endBundle();		// when bundle mode is on, close and send the current bundle (if any)
		void stop();			// stop the network services
		std::string getInfos() const; // gives information about the current environment (version, port numbers,...)

		int	getUDPPort() const			{ return fUDPPort; }
		int	getUDPOut()	const			{ return fUDPOut; }
		int	getUDPErr()	const			{ return fUPDErr; }
		const char*	getDestAddress() const { return fDestAddress.c_str(); }
		const char*	getRootName() const;	// probably useless, introduced for UI extension experiments
    
        void setUDPPort(int port) { fUDPPort = port; }
        void setUDPOut(int port) { fUDPOut = port; }
        void setUDPErr(int port) { fUPDErr = port; }
        void setDestAddress(const char* address) { fDestAddress = address; }

        // By default, an osc interface emits all parameters. You can filter specific params dynamically.
        static std::vector<OSCRegexp*>     fFilteredPaths; // filtered paths will not be emitted
        static void addFilteredPath(std::string path);
        static bool isPathFiltered(std::string path);
        static void resetFilteredPaths();
    
		static float version();				// the Faust OSC library version number
		static const char* versionstr();	// the Faust OSC library version number as a string
		static int gXmit;                   // a static variable to control the transmission of values
                                            // i.e. the use of the interface as a controler
		static int gBundle;                 // a static variable to control the osc bundle mode
};

#define kNoXmit     0
#define kAll        1
#define kAlias      2

}

#endif

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

/******************************************************************************
*******************************************************************************

					OSC (Open Sound Control) USER INTERFACE

*******************************************************************************
*******************************************************************************/
/*

Note about the OSC addresses and the Faust UI names:
----------------------------------------------------
There are potential conflicts between the Faust UI objects naming scheme and 
the OSC address space. An OSC symbolic names is an ASCII string consisting of
printable characters other than the following:
	space 
#	number sign
*	asterisk
,	comma
/	forward
?	question mark
[	open bracket
]	close bracket
{	open curly brace
}	close curly brace

a simple solution to address the problem consists in replacing 
space or tabulation with '_' (underscore)
all the other osc excluded characters with '-' (hyphen)

This solution is implemented in the proposed OSC UI;
*/

class OSCUI : public GUI 
{
     
	oscfaust::OSCControler*	fCtrl;
	std::vector<const char*> fAlias;
	
    const char* tr(const char* label) const
    {
        static char buffer[1024];
        char * ptr = buffer; int n=1;
        while (*label && (n++ < 1024)) {
            switch (*label) {
                case ' ': case '	':
                    *ptr++ = '_';
                    break;
                case '#': case '*': case ',': case '/': case '?':
                case '[': case ']': case '{': case '}': case '(': case ')':
                    *ptr++ = '_';
                    break;
                default: 
                    *ptr++ = *label;
            }
            label++;
        }
        *ptr = 0;
        return buffer;
    }
	
	// add all accumulated alias
	void addalias(FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, const char* label)
	{
		for (unsigned int i = 0; i < fAlias.size(); i++) {
			fCtrl->addAlias(fAlias[i], zone, FAUSTFLOAT(0), FAUSTFLOAT(1), init, min, max, label);
		}
		fAlias.clear();
	}
	
 public:

    OSCUI(const char* /*applicationname*/, int argc, char *argv[], oscfaust::OSCIO* io = 0, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true) : GUI() 
    { 
		fCtrl = new oscfaust::OSCControler(argc, argv, this, io, errCallback, arg, init); 
        //		fCtrl->opengroup(applicationname);
	}
    
	virtual ~OSCUI() { delete fCtrl; }
    
    // -- widget's layouts
    
  	virtual void openTabBox(const char* label)          { fCtrl->opengroup(tr(label)); }
	virtual void openHorizontalBox(const char* label)   { fCtrl->opengroup(tr(label)); }
	virtual void openVerticalBox(const char* label)     { fCtrl->opengroup(tr(label)); }
	virtual void closeBox()                             { fCtrl->closegroup(); }
	
	// -- active widgets
	virtual void addButton(const char* label, FAUSTFLOAT* zone) 		{ const char* l = tr(label); addalias(zone, 0, 0, 1, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1)); }
	virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) 	{ const char* l = tr(label); addalias(zone, 0, 0, 1, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1)); }
	virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /*step*/)
																		{ const char* l = tr(label); addalias(zone, init, min, max, l); fCtrl->addnode(l, zone, init, min, max); }
	virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /*step*/)
																		{ const char* l = tr(label); addalias(zone, init, min, max, l); fCtrl->addnode(l, zone, init, min, max); }
	virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /*step*/)
																		{ const char* l = tr(label); addalias(zone, init, min, max, l); fCtrl->addnode(l, zone, init, min, max); }
	
	// -- passive widgets
	
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
    {
        const char* l = tr(label); addalias(zone, 0, min, max, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
    {
        const char* l = tr(label); addalias(zone, 0, min, max, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
    }
  		
	// -- metadata declarations
    
	virtual void declare(FAUSTFLOAT*, const char* key, const char* alias)
	{ 
		if (strcasecmp(key, "OSC") == 0) fAlias.push_back(alias);
	}

	virtual void show() {}

    bool run()
    {
        fCtrl->run();
        return true;
    }
	
    void stop()			{ fCtrl->stop(); }
    void endBundle() 	{ fCtrl->endBundle(); }
    
    std::string getInfos()          { return fCtrl->getInfos(); }

    const char* getRootName()		{ return fCtrl->getRootName(); }
    int getUDPPort()                { return fCtrl->getUDPPort(); }
    int getUDPOut()                 { return fCtrl->getUDPOut(); }
    int getUDPErr()                 { return fCtrl->getUDPErr(); }
    const char* getDestAddress()    { return fCtrl->getDestAddress(); }

    void setUDPPort(int port)       { fCtrl->setUDPPort(port); }
    void setUDPOut(int port)        { fCtrl->setUDPOut(port); }
    void setUDPErr(int port)        { fCtrl->setUDPErr(port); }
    void setDestAddress(const char* address)    { return fCtrl->setDestAddress(address); }

};

#endif // __OSCUI__

#ifdef POLY2
#include "effect.h"
#endif

#if SOUNDFILE
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

#endif

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __Soundfile__
#define __Soundfile__

#include <iostream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 fLength, fOffset and fSampleRate field are filled accordingly by repeating 
 the actual parts if needed.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    FAUSTFLOAT** fBuffers;
    int fLength[MAX_SOUNDFILE_PARTS];      // length of each part
    int fSampleRate[MAX_SOUNDFILE_PARTS];  // sample rate of each part
    int fOffset[MAX_SOUNDFILE_PARTS];      // offset of each part in the global buffer
    int fChannels;                         // max number of channels of all concatenated files

    Soundfile()
    {
        fBuffers  = NULL;
        fChannels = -1;
    }

    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete[] fBuffers;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    void emptyFile(Soundfile* soundfile, int part, int& offset, int max_chan)
    {
        soundfile->fLength[part] = BUFFER_SIZE;
        soundfile->fSampleRate[part] = SAMPLE_RATE;
        soundfile->fOffset[part] = offset;
        // Update offset
        offset += soundfile->fLength[part];
    }

    Soundfile* createSoundfile(int cur_chan, int length, int max_chan)
    {
        Soundfile* soundfile = new Soundfile();
        if (!soundfile) {
            throw std::bad_alloc();
        }
        
        soundfile->fBuffers = new FAUSTFLOAT*[max_chan];
        if (!soundfile->fBuffers) {
            throw std::bad_alloc();
        }
        
        for (int chan = 0; chan < cur_chan; chan++) {
            soundfile->fBuffers[chan] = new FAUSTFLOAT[length];
            if (!soundfile->fBuffers[chan]) {
                throw std::bad_alloc();
            }
            memset(soundfile->fBuffers[chan], 0, sizeof(FAUSTFLOAT) * length);
        }
        
        soundfile->fChannels = cur_chan;
        return soundfile;
    }

    void getBuffersOffset(Soundfile* soundfile, FAUSTFLOAT** buffers, int offset)
    {
        for (int chan = 0; chan < soundfile->fChannels; chan++) {
            buffers[chan] = &soundfile->fBuffers[chan][offset];
        }
    }
    
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (int i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }

    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;

    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;

  public:
    
    virtual ~SoundfileReader() {}

    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan)
    {
        try {
            int cur_chan = 1; // At least one buffer
            int total_length = 0;
            
            // Compute total length and chan max of all files
            for (int i = 0; i < path_name_list.size(); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
            
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = createSoundfile(cur_chan, total_length, max_chan);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < path_name_list.size(); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    emptyFile(soundfile, i, offset, max_chan);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = path_name_list.size(); i < MAX_SOUNDFILE_PARTS; i++) {
                emptyFile(soundfile, i, offset, max_chan);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = cur_chan; chan < max_chan; chan++) {
                soundfile->fBuffers[chan] = soundfile->fBuffers[chan % cur_chan];
            }
            
            return soundfile;
            
        } catch (...) {
            return NULL;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (int i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>


struct JuceReader : public SoundfileReader {
    
    AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    
    bool checkFile(const std::string& path_name)
    {
        File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        assert(formatReader);
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        
        int channels = std::min<int>(max_chan, int(formatReader->numChannels));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSampleRate[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        FAUSTFLOAT* buffers[soundfile->fChannels];
        getBuffersOffset(soundfile, buffers, offset);
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly concert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    FAUSTFLOAT* buffer = &soundfile->fBuffers[chan][soundfile->fOffset[part]];
                    FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer), 1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
JuceReader reader;
#else
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>


struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
	
    bool checkFile(const std::string& path_name)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }
	
    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        assert(snd_file);
        channels = int(snd_info.channels);
        length = int(snd_info.frames);
        sf_close(snd_file);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        assert(snd_file);
		
        int channels = std::min<int>(max_chan, snd_info.channels);
		
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSampleRate[part] = snd_info.samplerate;
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
		FAUSTFLOAT* buffer = (FAUSTFLOAT*)alloca(BUFFER_SIZE * sizeof(FAUSTFLOAT) * snd_info.channels);
		sample_read reader;
		
        if (sizeof(FAUSTFLOAT) == 4) {
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        } else {
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        }
        do {
            nbf = reader(snd_file, buffer, BUFFER_SIZE);
            for (int sample = 0; sample < nbf; sample++) {
                for (int chan = 0; chan < channels; chan++) {
                    soundfile->fBuffers[chan][offset + sample] = buffer[sample * snd_info.channels + chan];
                }
            }
            // Update offset
            offset += nbf;
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    }

};

#endif
LibsndfileReader reader;
#endif

// To be used by dsp code if no SoundUI is used
std::vector<std::string> path_name_list;
Soundfile* defaultsound = reader.createSoundfile(path_name_list, MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;             // The soundfile directories
        std::map<std::string, Soundfile*> fSoundfileMap;    // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_directory = "")
        {
            fSoundfileDir.push_back(sound_directory);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories):fSoundfileDir(sound_directories)
        {}
    
        virtual ~SoundUI()
        {   
            // Delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSoundfileMap.begin(); it != fSoundfileMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            if (fSoundfileMap.find(saved_url) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = reader.checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = reader.createSoundfile(path_name_list, MAX_CHAN);
                if (sound_file) {
                    fSoundfileMap[saved_url] = sound_file;
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile
            *sf_zone = fSoundfileMap[saved_url];
        }
    
        static std::string getBinaryPath(std::string folder = "")
        {
            std::string bundle_path_str;
        #ifdef __APPLE__
            CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
            if (bundle_ref) {
                UInt8 bundle_path[512];
                if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                    bundle_path_str = std::string((char*)bundle_path) + folder;
                }
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
        
        static std::string getBinaryPathFrom(const std::string& path)
        {
            std::string bundle_path_str;
        #ifdef __APPLE__
            CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
            CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
            if (bundle_ref) {
                UInt8 bundle_path[512];
                if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                    bundle_path_str = std::string((char*)bundle_path);
                }
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
#endif

using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>


class mydspSIG0 {
	
  private:
	
	int iRec17[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
		
	}
	int getNumOutputsmydspSIG0() {
		return 1;
		
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec17[l1] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, double* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec17[0] = (iRec17[1] + 1);
			output[i] = std::sin((9.5873799242852573e-05 * double((iRec17[0] + -1))));
			iRec17[1] = iRec17[0];
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static double ftbl0mydspSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSamplingFreq;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider1;
	double fRec0[2];
	FAUSTFLOAT fHslider2;
	double fConst2;
	double fRec18[2];
	double fVec0[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider3;
	double fRec19[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider5;
	double fRec20[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fHslider7;
	double fRec21[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider9;
	double fRec22[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fHslider11;
	double fRec23[2];
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fHslider13;
	double fRec24[2];
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fHslider15;
	double fRec25[2];
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fHslider17;
	double fRec26[2];
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fHslider19;
	double fRec27[2];
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fHslider21;
	double fRec28[2];
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fCheckbox10;
	FAUSTFLOAT fHslider23;
	double fRec29[2];
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fCheckbox11;
	FAUSTFLOAT fHslider25;
	double fRec30[2];
	FAUSTFLOAT fHslider26;
	FAUSTFLOAT fCheckbox12;
	FAUSTFLOAT fHslider27;
	double fRec31[2];
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fCheckbox13;
	FAUSTFLOAT fHslider29;
	double fRec32[2];
	FAUSTFLOAT fHslider30;
	FAUSTFLOAT fCheckbox14;
	FAUSTFLOAT fHslider31;
	double fRec33[2];
	FAUSTFLOAT fHslider32;
	FAUSTFLOAT fCheckbox15;
	FAUSTFLOAT fHslider33;
	double fRec34[2];
	FAUSTFLOAT fHslider34;
	double fRec35[2];
	FAUSTFLOAT fHslider35;
	double fRec36[2];
	double fRec37[2];
	int IOTA;
	double fVec1[2097152];
	double fConst3;
	FAUSTFLOAT fHslider36;
	FAUSTFLOAT fHslider37;
	int iRec38[2];
	double fVec2[2];
	int iRec39[2];
	double fVec3[524288];
	double fConst4;
	FAUSTFLOAT fHslider38;
	FAUSTFLOAT fHslider39;
	FAUSTFLOAT fHslider40;
	double fVec4[2];
	double fConst5;
	double fRec42[2];
	double fRec43[2];
	double fRec41[2];
	double fVec5[2];
	double fRec40[2];
	double fVec6[2];
	double fRec44[2];
	double fVec7[2];
	double fRec45[2];
	double fVec8[2];
	double fRec46[2];
	double fRec1[2];
	FAUSTFLOAT fCheckbox16;
	FAUSTFLOAT fCheckbox17;
	FAUSTFLOAT fCheckbox18;
	FAUSTFLOAT fCheckbox19;
	FAUSTFLOAT fCheckbox20;
	FAUSTFLOAT fCheckbox21;
	FAUSTFLOAT fCheckbox22;
	FAUSTFLOAT fCheckbox23;
	FAUSTFLOAT fCheckbox24;
	FAUSTFLOAT fCheckbox25;
	FAUSTFLOAT fCheckbox26;
	FAUSTFLOAT fCheckbox27;
	FAUSTFLOAT fCheckbox28;
	FAUSTFLOAT fCheckbox29;
	FAUSTFLOAT fCheckbox30;
	FAUSTFLOAT fCheckbox31;
	FAUSTFLOAT fHslider41;
	double fRec47[2];
	double fVec9[2097152];
	FAUSTFLOAT fHslider42;
	int iRec48[2];
	int iRec49[2];
	double fVec10[524288];
	FAUSTFLOAT fHslider43;
	double fRec51[2];
	double fVec11[2];
	double fRec50[2];
	double fVec12[2];
	double fRec52[2];
	double fVec13[2];
	double fRec53[2];
	double fVec14[2];
	double fRec54[2];
	double fRec2[2];
	FAUSTFLOAT fCheckbox32;
	FAUSTFLOAT fCheckbox33;
	FAUSTFLOAT fCheckbox34;
	FAUSTFLOAT fCheckbox35;
	FAUSTFLOAT fCheckbox36;
	FAUSTFLOAT fCheckbox37;
	FAUSTFLOAT fCheckbox38;
	FAUSTFLOAT fCheckbox39;
	FAUSTFLOAT fCheckbox40;
	FAUSTFLOAT fCheckbox41;
	FAUSTFLOAT fCheckbox42;
	FAUSTFLOAT fCheckbox43;
	FAUSTFLOAT fCheckbox44;
	FAUSTFLOAT fCheckbox45;
	FAUSTFLOAT fCheckbox46;
	FAUSTFLOAT fCheckbox47;
	FAUSTFLOAT fHslider44;
	double fRec55[2];
	double fVec15[2097152];
	FAUSTFLOAT fHslider45;
	int iRec56[2];
	int iRec57[2];
	double fVec16[524288];
	FAUSTFLOAT fHslider46;
	double fRec59[2];
	double fVec17[2];
	double fRec58[2];
	double fVec18[2];
	double fRec60[2];
	double fVec19[2];
	double fRec61[2];
	double fVec20[2];
	double fRec62[2];
	double fRec3[2];
	FAUSTFLOAT fCheckbox48;
	FAUSTFLOAT fCheckbox49;
	FAUSTFLOAT fCheckbox50;
	FAUSTFLOAT fCheckbox51;
	FAUSTFLOAT fCheckbox52;
	FAUSTFLOAT fCheckbox53;
	FAUSTFLOAT fCheckbox54;
	FAUSTFLOAT fCheckbox55;
	FAUSTFLOAT fCheckbox56;
	FAUSTFLOAT fCheckbox57;
	FAUSTFLOAT fCheckbox58;
	FAUSTFLOAT fCheckbox59;
	FAUSTFLOAT fCheckbox60;
	FAUSTFLOAT fCheckbox61;
	FAUSTFLOAT fCheckbox62;
	FAUSTFLOAT fCheckbox63;
	FAUSTFLOAT fHslider47;
	double fRec63[2];
	double fVec21[2097152];
	FAUSTFLOAT fHslider48;
	int iRec64[2];
	int iRec65[2];
	double fVec22[524288];
	FAUSTFLOAT fHslider49;
	double fRec67[2];
	double fVec23[2];
	double fRec66[2];
	double fVec24[2];
	double fRec68[2];
	double fVec25[2];
	double fRec69[2];
	double fVec26[2];
	double fRec70[2];
	double fRec4[2];
	FAUSTFLOAT fCheckbox64;
	FAUSTFLOAT fCheckbox65;
	FAUSTFLOAT fCheckbox66;
	FAUSTFLOAT fCheckbox67;
	FAUSTFLOAT fCheckbox68;
	FAUSTFLOAT fCheckbox69;
	FAUSTFLOAT fCheckbox70;
	FAUSTFLOAT fCheckbox71;
	FAUSTFLOAT fCheckbox72;
	FAUSTFLOAT fCheckbox73;
	FAUSTFLOAT fCheckbox74;
	FAUSTFLOAT fCheckbox75;
	FAUSTFLOAT fCheckbox76;
	FAUSTFLOAT fCheckbox77;
	FAUSTFLOAT fCheckbox78;
	FAUSTFLOAT fCheckbox79;
	FAUSTFLOAT fHslider50;
	double fRec71[2];
	double fVec27[2097152];
	FAUSTFLOAT fHslider51;
	int iRec72[2];
	int iRec73[2];
	double fVec28[524288];
	FAUSTFLOAT fHslider52;
	double fRec75[2];
	double fVec29[2];
	double fRec74[2];
	double fVec30[2];
	double fRec76[2];
	double fVec31[2];
	double fRec77[2];
	double fVec32[2];
	double fRec78[2];
	double fRec5[2];
	FAUSTFLOAT fCheckbox80;
	FAUSTFLOAT fCheckbox81;
	FAUSTFLOAT fCheckbox82;
	FAUSTFLOAT fCheckbox83;
	FAUSTFLOAT fCheckbox84;
	FAUSTFLOAT fCheckbox85;
	FAUSTFLOAT fCheckbox86;
	FAUSTFLOAT fCheckbox87;
	FAUSTFLOAT fCheckbox88;
	FAUSTFLOAT fCheckbox89;
	FAUSTFLOAT fCheckbox90;
	FAUSTFLOAT fCheckbox91;
	FAUSTFLOAT fCheckbox92;
	FAUSTFLOAT fCheckbox93;
	FAUSTFLOAT fCheckbox94;
	FAUSTFLOAT fCheckbox95;
	FAUSTFLOAT fHslider53;
	double fRec79[2];
	double fVec33[2097152];
	FAUSTFLOAT fHslider54;
	int iRec80[2];
	int iRec81[2];
	double fVec34[524288];
	FAUSTFLOAT fHslider55;
	double fRec83[2];
	double fVec35[2];
	double fRec82[2];
	double fVec36[2];
	double fRec84[2];
	double fVec37[2];
	double fRec85[2];
	double fVec38[2];
	double fRec86[2];
	double fRec6[2];
	FAUSTFLOAT fCheckbox96;
	FAUSTFLOAT fCheckbox97;
	FAUSTFLOAT fCheckbox98;
	FAUSTFLOAT fCheckbox99;
	FAUSTFLOAT fCheckbox100;
	FAUSTFLOAT fCheckbox101;
	FAUSTFLOAT fCheckbox102;
	FAUSTFLOAT fCheckbox103;
	FAUSTFLOAT fCheckbox104;
	FAUSTFLOAT fCheckbox105;
	FAUSTFLOAT fCheckbox106;
	FAUSTFLOAT fCheckbox107;
	FAUSTFLOAT fCheckbox108;
	FAUSTFLOAT fCheckbox109;
	FAUSTFLOAT fCheckbox110;
	FAUSTFLOAT fCheckbox111;
	FAUSTFLOAT fHslider56;
	double fRec87[2];
	double fVec39[2097152];
	FAUSTFLOAT fHslider57;
	int iRec88[2];
	int iRec89[2];
	double fVec40[524288];
	FAUSTFLOAT fHslider58;
	double fRec91[2];
	double fVec41[2];
	double fRec90[2];
	double fVec42[2];
	double fRec92[2];
	double fVec43[2];
	double fRec93[2];
	double fVec44[2];
	double fRec94[2];
	double fRec7[2];
	FAUSTFLOAT fCheckbox112;
	FAUSTFLOAT fCheckbox113;
	FAUSTFLOAT fCheckbox114;
	FAUSTFLOAT fCheckbox115;
	FAUSTFLOAT fCheckbox116;
	FAUSTFLOAT fCheckbox117;
	FAUSTFLOAT fCheckbox118;
	FAUSTFLOAT fCheckbox119;
	FAUSTFLOAT fCheckbox120;
	FAUSTFLOAT fCheckbox121;
	FAUSTFLOAT fCheckbox122;
	FAUSTFLOAT fCheckbox123;
	FAUSTFLOAT fCheckbox124;
	FAUSTFLOAT fCheckbox125;
	FAUSTFLOAT fCheckbox126;
	FAUSTFLOAT fCheckbox127;
	FAUSTFLOAT fHslider59;
	double fRec95[2];
	double fVec45[2097152];
	FAUSTFLOAT fHslider60;
	int iRec96[2];
	int iRec97[2];
	double fVec46[524288];
	FAUSTFLOAT fHslider61;
	double fRec99[2];
	double fVec47[2];
	double fRec98[2];
	double fVec48[2];
	double fRec100[2];
	double fVec49[2];
	double fRec101[2];
	double fVec50[2];
	double fRec102[2];
	double fRec8[2];
	FAUSTFLOAT fCheckbox128;
	FAUSTFLOAT fCheckbox129;
	FAUSTFLOAT fCheckbox130;
	FAUSTFLOAT fCheckbox131;
	FAUSTFLOAT fCheckbox132;
	FAUSTFLOAT fCheckbox133;
	FAUSTFLOAT fCheckbox134;
	FAUSTFLOAT fCheckbox135;
	FAUSTFLOAT fCheckbox136;
	FAUSTFLOAT fCheckbox137;
	FAUSTFLOAT fCheckbox138;
	FAUSTFLOAT fCheckbox139;
	FAUSTFLOAT fCheckbox140;
	FAUSTFLOAT fCheckbox141;
	FAUSTFLOAT fCheckbox142;
	FAUSTFLOAT fCheckbox143;
	FAUSTFLOAT fHslider62;
	double fRec103[2];
	double fVec51[2097152];
	FAUSTFLOAT fHslider63;
	int iRec104[2];
	int iRec105[2];
	double fVec52[524288];
	FAUSTFLOAT fHslider64;
	double fRec107[2];
	double fVec53[2];
	double fRec106[2];
	double fVec54[2];
	double fRec108[2];
	double fVec55[2];
	double fRec109[2];
	double fVec56[2];
	double fRec110[2];
	double fRec9[2];
	FAUSTFLOAT fCheckbox144;
	FAUSTFLOAT fCheckbox145;
	FAUSTFLOAT fCheckbox146;
	FAUSTFLOAT fCheckbox147;
	FAUSTFLOAT fCheckbox148;
	FAUSTFLOAT fCheckbox149;
	FAUSTFLOAT fCheckbox150;
	FAUSTFLOAT fCheckbox151;
	FAUSTFLOAT fCheckbox152;
	FAUSTFLOAT fCheckbox153;
	FAUSTFLOAT fCheckbox154;
	FAUSTFLOAT fCheckbox155;
	FAUSTFLOAT fCheckbox156;
	FAUSTFLOAT fCheckbox157;
	FAUSTFLOAT fCheckbox158;
	FAUSTFLOAT fCheckbox159;
	FAUSTFLOAT fHslider65;
	double fRec111[2];
	double fVec57[2097152];
	FAUSTFLOAT fHslider66;
	int iRec112[2];
	int iRec113[2];
	double fVec58[524288];
	FAUSTFLOAT fHslider67;
	double fRec115[2];
	double fVec59[2];
	double fRec114[2];
	double fVec60[2];
	double fRec116[2];
	double fVec61[2];
	double fRec117[2];
	double fVec62[2];
	double fRec118[2];
	double fRec10[2];
	FAUSTFLOAT fCheckbox160;
	FAUSTFLOAT fCheckbox161;
	FAUSTFLOAT fCheckbox162;
	FAUSTFLOAT fCheckbox163;
	FAUSTFLOAT fCheckbox164;
	FAUSTFLOAT fCheckbox165;
	FAUSTFLOAT fCheckbox166;
	FAUSTFLOAT fCheckbox167;
	FAUSTFLOAT fCheckbox168;
	FAUSTFLOAT fCheckbox169;
	FAUSTFLOAT fCheckbox170;
	FAUSTFLOAT fCheckbox171;
	FAUSTFLOAT fCheckbox172;
	FAUSTFLOAT fCheckbox173;
	FAUSTFLOAT fCheckbox174;
	FAUSTFLOAT fCheckbox175;
	FAUSTFLOAT fHslider68;
	double fRec119[2];
	double fVec63[2097152];
	FAUSTFLOAT fHslider69;
	int iRec120[2];
	int iRec121[2];
	double fVec64[524288];
	FAUSTFLOAT fHslider70;
	double fRec123[2];
	double fVec65[2];
	double fRec122[2];
	double fVec66[2];
	double fRec124[2];
	double fVec67[2];
	double fRec125[2];
	double fVec68[2];
	double fRec126[2];
	double fRec11[2];
	FAUSTFLOAT fCheckbox176;
	FAUSTFLOAT fCheckbox177;
	FAUSTFLOAT fCheckbox178;
	FAUSTFLOAT fCheckbox179;
	FAUSTFLOAT fCheckbox180;
	FAUSTFLOAT fCheckbox181;
	FAUSTFLOAT fCheckbox182;
	FAUSTFLOAT fCheckbox183;
	FAUSTFLOAT fCheckbox184;
	FAUSTFLOAT fCheckbox185;
	FAUSTFLOAT fCheckbox186;
	FAUSTFLOAT fCheckbox187;
	FAUSTFLOAT fCheckbox188;
	FAUSTFLOAT fCheckbox189;
	FAUSTFLOAT fCheckbox190;
	FAUSTFLOAT fCheckbox191;
	FAUSTFLOAT fHslider71;
	double fRec127[2];
	double fVec69[2097152];
	FAUSTFLOAT fHslider72;
	int iRec128[2];
	int iRec129[2];
	double fVec70[524288];
	FAUSTFLOAT fHslider73;
	double fRec131[2];
	double fVec71[2];
	double fRec130[2];
	double fVec72[2];
	double fRec132[2];
	double fVec73[2];
	double fRec133[2];
	double fVec74[2];
	double fRec134[2];
	double fRec12[2];
	FAUSTFLOAT fCheckbox192;
	FAUSTFLOAT fCheckbox193;
	FAUSTFLOAT fCheckbox194;
	FAUSTFLOAT fCheckbox195;
	FAUSTFLOAT fCheckbox196;
	FAUSTFLOAT fCheckbox197;
	FAUSTFLOAT fCheckbox198;
	FAUSTFLOAT fCheckbox199;
	FAUSTFLOAT fCheckbox200;
	FAUSTFLOAT fCheckbox201;
	FAUSTFLOAT fCheckbox202;
	FAUSTFLOAT fCheckbox203;
	FAUSTFLOAT fCheckbox204;
	FAUSTFLOAT fCheckbox205;
	FAUSTFLOAT fCheckbox206;
	FAUSTFLOAT fCheckbox207;
	FAUSTFLOAT fHslider74;
	double fRec135[2];
	double fVec75[2097152];
	FAUSTFLOAT fHslider75;
	int iRec136[2];
	int iRec137[2];
	double fVec76[524288];
	FAUSTFLOAT fHslider76;
	double fRec139[2];
	double fVec77[2];
	double fRec138[2];
	double fVec78[2];
	double fRec140[2];
	double fVec79[2];
	double fRec141[2];
	double fVec80[2];
	double fRec142[2];
	double fRec13[2];
	FAUSTFLOAT fCheckbox208;
	FAUSTFLOAT fCheckbox209;
	FAUSTFLOAT fCheckbox210;
	FAUSTFLOAT fCheckbox211;
	FAUSTFLOAT fCheckbox212;
	FAUSTFLOAT fCheckbox213;
	FAUSTFLOAT fCheckbox214;
	FAUSTFLOAT fCheckbox215;
	FAUSTFLOAT fCheckbox216;
	FAUSTFLOAT fCheckbox217;
	FAUSTFLOAT fCheckbox218;
	FAUSTFLOAT fCheckbox219;
	FAUSTFLOAT fCheckbox220;
	FAUSTFLOAT fCheckbox221;
	FAUSTFLOAT fCheckbox222;
	FAUSTFLOAT fCheckbox223;
	FAUSTFLOAT fHslider77;
	double fRec143[2];
	double fVec81[2097152];
	FAUSTFLOAT fHslider78;
	int iRec144[2];
	int iRec145[2];
	double fVec82[524288];
	FAUSTFLOAT fHslider79;
	double fRec147[2];
	double fVec83[2];
	double fRec146[2];
	double fVec84[2];
	double fRec148[2];
	double fVec85[2];
	double fRec149[2];
	double fVec86[2];
	double fRec150[2];
	double fRec14[2];
	FAUSTFLOAT fCheckbox224;
	FAUSTFLOAT fCheckbox225;
	FAUSTFLOAT fCheckbox226;
	FAUSTFLOAT fCheckbox227;
	FAUSTFLOAT fCheckbox228;
	FAUSTFLOAT fCheckbox229;
	FAUSTFLOAT fCheckbox230;
	FAUSTFLOAT fCheckbox231;
	FAUSTFLOAT fCheckbox232;
	FAUSTFLOAT fCheckbox233;
	FAUSTFLOAT fCheckbox234;
	FAUSTFLOAT fCheckbox235;
	FAUSTFLOAT fCheckbox236;
	FAUSTFLOAT fCheckbox237;
	FAUSTFLOAT fCheckbox238;
	FAUSTFLOAT fCheckbox239;
	FAUSTFLOAT fHslider80;
	double fRec151[2];
	double fVec87[2097152];
	FAUSTFLOAT fHslider81;
	int iRec152[2];
	int iRec153[2];
	double fVec88[524288];
	FAUSTFLOAT fHslider82;
	double fRec155[2];
	double fVec89[2];
	double fRec154[2];
	double fVec90[2];
	double fRec156[2];
	double fVec91[2];
	double fRec157[2];
	double fVec92[2];
	double fRec158[2];
	double fRec15[2];
	FAUSTFLOAT fCheckbox240;
	FAUSTFLOAT fCheckbox241;
	FAUSTFLOAT fCheckbox242;
	FAUSTFLOAT fCheckbox243;
	FAUSTFLOAT fCheckbox244;
	FAUSTFLOAT fCheckbox245;
	FAUSTFLOAT fCheckbox246;
	FAUSTFLOAT fCheckbox247;
	FAUSTFLOAT fCheckbox248;
	FAUSTFLOAT fCheckbox249;
	FAUSTFLOAT fCheckbox250;
	FAUSTFLOAT fCheckbox251;
	FAUSTFLOAT fCheckbox252;
	FAUSTFLOAT fCheckbox253;
	FAUSTFLOAT fCheckbox254;
	FAUSTFLOAT fCheckbox255;
	FAUSTFLOAT fHslider83;
	double fRec159[2];
	double fVec93[2097152];
	FAUSTFLOAT fHslider84;
	int iRec160[2];
	int iRec161[2];
	double fVec94[524288];
	FAUSTFLOAT fHslider85;
	double fRec163[2];
	double fVec95[2];
	double fRec162[2];
	double fVec96[2];
	double fRec164[2];
	double fVec97[2];
	double fRec165[2];
	double fVec98[2];
	double fRec166[2];
	double fRec16[2];
	FAUSTFLOAT fHslider86;
	double fRec167[2];
	double fConst6;
	double fConst7;
	FAUSTFLOAT fCheckbox256;
	double fRec168[2];
	FAUSTFLOAT fCheckbox257;
	double fRec169[2];
	FAUSTFLOAT fCheckbox258;
	double fRec170[2];
	FAUSTFLOAT fCheckbox259;
	double fRec171[2];
	FAUSTFLOAT fCheckbox260;
	double fRec172[2];
	FAUSTFLOAT fHslider87;
	double fRec173[2];
	FAUSTFLOAT fCheckbox261;
	double fRec174[2];
	FAUSTFLOAT fCheckbox262;
	double fRec175[2];
	FAUSTFLOAT fCheckbox263;
	double fRec176[2];
	FAUSTFLOAT fCheckbox264;
	double fRec177[2];
	FAUSTFLOAT fCheckbox265;
	double fRec178[2];
	FAUSTFLOAT fHslider88;
	double fRec179[2];
	FAUSTFLOAT fCheckbox266;
	double fRec180[2];
	FAUSTFLOAT fCheckbox267;
	double fRec181[2];
	FAUSTFLOAT fCheckbox268;
	double fRec182[2];
	FAUSTFLOAT fCheckbox269;
	double fRec183[2];
	FAUSTFLOAT fCheckbox270;
	double fRec184[2];
	FAUSTFLOAT fHslider89;
	double fRec185[2];
	FAUSTFLOAT fCheckbox271;
	double fRec186[2];
	FAUSTFLOAT fCheckbox272;
	double fRec187[2];
	FAUSTFLOAT fCheckbox273;
	double fRec188[2];
	FAUSTFLOAT fCheckbox274;
	double fRec189[2];
	FAUSTFLOAT fCheckbox275;
	double fRec190[2];
	FAUSTFLOAT fHslider90;
	double fRec191[2];
	FAUSTFLOAT fCheckbox276;
	double fRec192[2];
	FAUSTFLOAT fCheckbox277;
	double fRec193[2];
	FAUSTFLOAT fCheckbox278;
	double fRec194[2];
	FAUSTFLOAT fCheckbox279;
	double fRec195[2];
	FAUSTFLOAT fCheckbox280;
	double fRec196[2];
	FAUSTFLOAT fHslider91;
	double fRec197[2];
	FAUSTFLOAT fCheckbox281;
	double fRec198[2];
	FAUSTFLOAT fCheckbox282;
	double fRec199[2];
	FAUSTFLOAT fCheckbox283;
	double fRec200[2];
	FAUSTFLOAT fCheckbox284;
	double fRec201[2];
	FAUSTFLOAT fCheckbox285;
	double fRec202[2];
	FAUSTFLOAT fHslider92;
	double fRec203[2];
	FAUSTFLOAT fCheckbox286;
	double fRec204[2];
	FAUSTFLOAT fCheckbox287;
	double fRec205[2];
	FAUSTFLOAT fCheckbox288;
	double fRec206[2];
	FAUSTFLOAT fCheckbox289;
	double fRec207[2];
	FAUSTFLOAT fCheckbox290;
	double fRec208[2];
	FAUSTFLOAT fHslider93;
	double fRec209[2];
	FAUSTFLOAT fCheckbox291;
	double fRec210[2];
	FAUSTFLOAT fCheckbox292;
	double fRec211[2];
	FAUSTFLOAT fCheckbox293;
	double fRec212[2];
	FAUSTFLOAT fCheckbox294;
	double fRec213[2];
	FAUSTFLOAT fCheckbox295;
	double fRec214[2];
	FAUSTFLOAT fHslider94;
	double fRec215[2];
	FAUSTFLOAT fCheckbox296;
	double fRec216[2];
	FAUSTFLOAT fCheckbox297;
	double fRec217[2];
	FAUSTFLOAT fCheckbox298;
	double fRec218[2];
	FAUSTFLOAT fCheckbox299;
	double fRec219[2];
	FAUSTFLOAT fCheckbox300;
	double fRec220[2];
	FAUSTFLOAT fHslider95;
	double fRec221[2];
	FAUSTFLOAT fCheckbox301;
	double fRec222[2];
	FAUSTFLOAT fCheckbox302;
	double fRec223[2];
	FAUSTFLOAT fCheckbox303;
	double fRec224[2];
	FAUSTFLOAT fCheckbox304;
	double fRec225[2];
	FAUSTFLOAT fCheckbox305;
	double fRec226[2];
	FAUSTFLOAT fHslider96;
	double fRec227[2];
	FAUSTFLOAT fCheckbox306;
	double fRec228[2];
	FAUSTFLOAT fCheckbox307;
	double fRec229[2];
	FAUSTFLOAT fCheckbox308;
	double fRec230[2];
	FAUSTFLOAT fCheckbox309;
	double fRec231[2];
	FAUSTFLOAT fCheckbox310;
	double fRec232[2];
	FAUSTFLOAT fHslider97;
	double fRec233[2];
	FAUSTFLOAT fCheckbox311;
	double fRec234[2];
	FAUSTFLOAT fCheckbox312;
	double fRec235[2];
	FAUSTFLOAT fCheckbox313;
	double fRec236[2];
	FAUSTFLOAT fCheckbox314;
	double fRec237[2];
	FAUSTFLOAT fCheckbox315;
	double fRec238[2];
	FAUSTFLOAT fHslider98;
	double fRec239[2];
	FAUSTFLOAT fCheckbox316;
	double fRec240[2];
	FAUSTFLOAT fCheckbox317;
	double fRec241[2];
	FAUSTFLOAT fCheckbox318;
	double fRec242[2];
	FAUSTFLOAT fCheckbox319;
	double fRec243[2];
	FAUSTFLOAT fCheckbox320;
	double fRec244[2];
	FAUSTFLOAT fHslider99;
	double fRec245[2];
	FAUSTFLOAT fCheckbox321;
	double fRec246[2];
	FAUSTFLOAT fCheckbox322;
	double fRec247[2];
	FAUSTFLOAT fCheckbox323;
	double fRec248[2];
	FAUSTFLOAT fCheckbox324;
	double fRec249[2];
	FAUSTFLOAT fCheckbox325;
	double fRec250[2];
	FAUSTFLOAT fHslider100;
	double fRec251[2];
	FAUSTFLOAT fCheckbox326;
	double fRec252[2];
	FAUSTFLOAT fCheckbox327;
	double fRec253[2];
	FAUSTFLOAT fCheckbox328;
	double fRec254[2];
	FAUSTFLOAT fCheckbox329;
	double fRec255[2];
	FAUSTFLOAT fCheckbox330;
	double fRec256[2];
	FAUSTFLOAT fHslider101;
	double fRec257[2];
	FAUSTFLOAT fCheckbox331;
	double fRec258[2];
	FAUSTFLOAT fCheckbox332;
	double fRec259[2];
	FAUSTFLOAT fCheckbox333;
	double fRec260[2];
	FAUSTFLOAT fCheckbox334;
	double fRec261[2];
	FAUSTFLOAT fCheckbox335;
	double fRec262[2];
	FAUSTFLOAT fHslider102;
	double fRec263[2];
	FAUSTFLOAT fCheckbox336;
	double fRec264[2];
	FAUSTFLOAT fCheckbox337;
	double fRec265[2];
	FAUSTFLOAT fCheckbox338;
	double fRec266[2];
	FAUSTFLOAT fCheckbox339;
	double fRec267[2];
	FAUSTFLOAT fCheckbox340;
	double fRec268[2];
	FAUSTFLOAT fCheckbox341;
	FAUSTFLOAT fHslider103;
	FAUSTFLOAT fHslider104;
	FAUSTFLOAT fCheckbox342;
	double fRec269[2];
	FAUSTFLOAT fHslider105;
	double fRec270[2];
	FAUSTFLOAT fEntry0;
	double fRec272[2];
	int iRec273[2];
	FAUSTFLOAT fHslider106;
	int iRec271[2];
	FAUSTFLOAT fHslider107;
	FAUSTFLOAT fHslider108;
	double fRec279[2];
	FAUSTFLOAT fHslider109;
	FAUSTFLOAT fHslider110;
	double fRec280[2];
	FAUSTFLOAT fHslider111;
	FAUSTFLOAT fHslider112;
	double fRec281[2];
	FAUSTFLOAT fCheckbox343;
	double fRec282[2];
	FAUSTFLOAT fCheckbox344;
	double fRec283[2];
	FAUSTFLOAT fCheckbox345;
	double fRec284[2];
	FAUSTFLOAT fCheckbox346;
	double fRec285[2];
	FAUSTFLOAT fCheckbox347;
	double fRec286[2];
	FAUSTFLOAT fCheckbox348;
	double fRec287[2];
	FAUSTFLOAT fCheckbox349;
	double fRec288[2];
	FAUSTFLOAT fCheckbox350;
	double fRec289[2];
	FAUSTFLOAT fCheckbox351;
	double fRec290[2];
	FAUSTFLOAT fCheckbox352;
	double fRec291[2];
	FAUSTFLOAT fCheckbox353;
	double fRec292[2];
	FAUSTFLOAT fCheckbox354;
	double fRec293[2];
	FAUSTFLOAT fCheckbox355;
	double fRec294[2];
	FAUSTFLOAT fCheckbox356;
	double fRec295[2];
	FAUSTFLOAT fCheckbox357;
	double fRec296[2];
	FAUSTFLOAT fCheckbox358;
	double fRec297[2];
	FAUSTFLOAT fHslider113;
	FAUSTFLOAT fHslider114;
	double fRec298[2];
	FAUSTFLOAT fCheckbox359;
	double fRec299[2];
	int iRec300[2];
	FAUSTFLOAT fCheckbox360;
	double fRec301[2];
	FAUSTFLOAT fCheckbox361;
	double fRec302[2];
	FAUSTFLOAT fCheckbox362;
	double fRec303[2];
	FAUSTFLOAT fCheckbox363;
	double fRec304[2];
	FAUSTFLOAT fCheckbox364;
	double fRec305[2];
	FAUSTFLOAT fCheckbox365;
	double fRec306[2];
	FAUSTFLOAT fCheckbox366;
	double fRec307[2];
	FAUSTFLOAT fCheckbox367;
	double fRec308[2];
	FAUSTFLOAT fCheckbox368;
	double fRec309[2];
	FAUSTFLOAT fCheckbox369;
	double fRec310[2];
	FAUSTFLOAT fCheckbox370;
	double fRec311[2];
	FAUSTFLOAT fCheckbox371;
	double fRec312[2];
	FAUSTFLOAT fCheckbox372;
	double fRec313[2];
	FAUSTFLOAT fCheckbox373;
	double fRec314[2];
	FAUSTFLOAT fCheckbox374;
	double fRec315[2];
	FAUSTFLOAT fCheckbox375;
	double fRec316[2];
	FAUSTFLOAT fCheckbox376;
	double fRec317[2];
	int iRec318[2];
	FAUSTFLOAT fCheckbox377;
	double fRec319[2];
	FAUSTFLOAT fCheckbox378;
	double fRec320[2];
	FAUSTFLOAT fCheckbox379;
	double fRec321[2];
	FAUSTFLOAT fCheckbox380;
	double fRec322[2];
	FAUSTFLOAT fCheckbox381;
	double fRec323[2];
	FAUSTFLOAT fCheckbox382;
	double fRec324[2];
	FAUSTFLOAT fCheckbox383;
	double fRec325[2];
	FAUSTFLOAT fCheckbox384;
	double fRec326[2];
	FAUSTFLOAT fCheckbox385;
	double fRec327[2];
	FAUSTFLOAT fCheckbox386;
	double fRec328[2];
	FAUSTFLOAT fCheckbox387;
	double fRec329[2];
	FAUSTFLOAT fCheckbox388;
	double fRec330[2];
	FAUSTFLOAT fCheckbox389;
	double fRec331[2];
	FAUSTFLOAT fCheckbox390;
	double fRec332[2];
	FAUSTFLOAT fCheckbox391;
	double fRec333[2];
	FAUSTFLOAT fCheckbox392;
	double fRec334[2];
	FAUSTFLOAT fCheckbox393;
	double fRec335[2];
	int iRec336[2];
	FAUSTFLOAT fCheckbox394;
	double fRec337[2];
	FAUSTFLOAT fCheckbox395;
	double fRec338[2];
	FAUSTFLOAT fCheckbox396;
	double fRec339[2];
	FAUSTFLOAT fCheckbox397;
	double fRec340[2];
	FAUSTFLOAT fCheckbox398;
	double fRec341[2];
	FAUSTFLOAT fCheckbox399;
	double fRec342[2];
	FAUSTFLOAT fCheckbox400;
	double fRec343[2];
	FAUSTFLOAT fCheckbox401;
	double fRec344[2];
	FAUSTFLOAT fCheckbox402;
	double fRec345[2];
	FAUSTFLOAT fCheckbox403;
	double fRec346[2];
	FAUSTFLOAT fCheckbox404;
	double fRec347[2];
	FAUSTFLOAT fCheckbox405;
	double fRec348[2];
	FAUSTFLOAT fCheckbox406;
	double fRec349[2];
	FAUSTFLOAT fCheckbox407;
	double fRec350[2];
	FAUSTFLOAT fCheckbox408;
	double fRec351[2];
	FAUSTFLOAT fCheckbox409;
	double fRec352[2];
	FAUSTFLOAT fCheckbox410;
	double fRec353[2];
	int iRec354[2];
	FAUSTFLOAT fCheckbox411;
	double fRec355[2];
	FAUSTFLOAT fCheckbox412;
	double fRec356[2];
	FAUSTFLOAT fCheckbox413;
	double fRec357[2];
	FAUSTFLOAT fCheckbox414;
	double fRec358[2];
	FAUSTFLOAT fCheckbox415;
	double fRec359[2];
	FAUSTFLOAT fCheckbox416;
	double fRec360[2];
	FAUSTFLOAT fCheckbox417;
	double fRec361[2];
	FAUSTFLOAT fCheckbox418;
	double fRec362[2];
	FAUSTFLOAT fCheckbox419;
	double fRec363[2];
	FAUSTFLOAT fCheckbox420;
	double fRec364[2];
	FAUSTFLOAT fCheckbox421;
	double fRec365[2];
	FAUSTFLOAT fCheckbox422;
	double fRec366[2];
	FAUSTFLOAT fCheckbox423;
	double fRec367[2];
	FAUSTFLOAT fCheckbox424;
	double fRec368[2];
	FAUSTFLOAT fCheckbox425;
	double fRec369[2];
	FAUSTFLOAT fCheckbox426;
	double fRec370[2];
	FAUSTFLOAT fCheckbox427;
	double fRec371[2];
	int iRec372[2];
	FAUSTFLOAT fCheckbox428;
	double fRec373[2];
	FAUSTFLOAT fCheckbox429;
	double fRec374[2];
	FAUSTFLOAT fCheckbox430;
	double fRec375[2];
	FAUSTFLOAT fCheckbox431;
	double fRec376[2];
	FAUSTFLOAT fCheckbox432;
	double fRec377[2];
	FAUSTFLOAT fCheckbox433;
	double fRec378[2];
	FAUSTFLOAT fCheckbox434;
	double fRec379[2];
	FAUSTFLOAT fCheckbox435;
	double fRec380[2];
	FAUSTFLOAT fCheckbox436;
	double fRec381[2];
	FAUSTFLOAT fCheckbox437;
	double fRec382[2];
	FAUSTFLOAT fCheckbox438;
	double fRec383[2];
	FAUSTFLOAT fCheckbox439;
	double fRec384[2];
	FAUSTFLOAT fCheckbox440;
	double fRec385[2];
	FAUSTFLOAT fCheckbox441;
	double fRec386[2];
	FAUSTFLOAT fCheckbox442;
	double fRec387[2];
	FAUSTFLOAT fCheckbox443;
	double fRec388[2];
	FAUSTFLOAT fHslider115;
	FAUSTFLOAT fHslider116;
	FAUSTFLOAT fHslider117;
	FAUSTFLOAT fHslider118;
	FAUSTFLOAT fHslider119;
	FAUSTFLOAT fHslider120;
	FAUSTFLOAT fHslider121;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.0");
		m->declare("filename", "FilDeSoi1SoundProcess8LS");
		m->declare("hoa.lib/author", "Pierre Guillot");
		m->declare("hoa.lib/copyright", "2012-2013 Guillot, Paris, Colafrancesco, CICM labex art H2H, U. Paris 8");
		m->declare("hoa.lib/name", "High Order Ambisonics library");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "FilDeSoi1SoundProcess8LS");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 1;
		
	}
	virtual int getNumOutputs() {
		return 8;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
		fConst1 = (1000.0 / fConst0);
		fConst2 = (30.0 / fConst0);
		fConst3 = (0.001 * fConst0);
		fConst4 = (1.0 / fConst0);
		fConst5 = (0.029999999999999999 * fConst0);
		fConst6 = std::exp((0.0 - (5.0 / fConst0)));
		fConst7 = (1.0 - fConst6);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0);
		fHslider1 = FAUSTFLOAT(20.0);
		fHslider2 = FAUSTFLOAT(1.0);
		fCheckbox0 = FAUSTFLOAT(0.0);
		fHslider3 = FAUSTFLOAT(0.0);
		fHslider4 = FAUSTFLOAT(1.0);
		fCheckbox1 = FAUSTFLOAT(0.0);
		fHslider5 = FAUSTFLOAT(0.0);
		fHslider6 = FAUSTFLOAT(1.0);
		fCheckbox2 = FAUSTFLOAT(0.0);
		fHslider7 = FAUSTFLOAT(0.0);
		fHslider8 = FAUSTFLOAT(1.0);
		fCheckbox3 = FAUSTFLOAT(0.0);
		fHslider9 = FAUSTFLOAT(0.0);
		fHslider10 = FAUSTFLOAT(1.0);
		fCheckbox4 = FAUSTFLOAT(0.0);
		fHslider11 = FAUSTFLOAT(0.0);
		fHslider12 = FAUSTFLOAT(1.0);
		fCheckbox5 = FAUSTFLOAT(0.0);
		fHslider13 = FAUSTFLOAT(0.0);
		fHslider14 = FAUSTFLOAT(1.0);
		fCheckbox6 = FAUSTFLOAT(0.0);
		fHslider15 = FAUSTFLOAT(0.0);
		fHslider16 = FAUSTFLOAT(1.0);
		fCheckbox7 = FAUSTFLOAT(0.0);
		fHslider17 = FAUSTFLOAT(0.0);
		fHslider18 = FAUSTFLOAT(1.0);
		fCheckbox8 = FAUSTFLOAT(0.0);
		fHslider19 = FAUSTFLOAT(0.0);
		fHslider20 = FAUSTFLOAT(1.0);
		fCheckbox9 = FAUSTFLOAT(0.0);
		fHslider21 = FAUSTFLOAT(0.0);
		fHslider22 = FAUSTFLOAT(1.0);
		fCheckbox10 = FAUSTFLOAT(0.0);
		fHslider23 = FAUSTFLOAT(0.0);
		fHslider24 = FAUSTFLOAT(1.0);
		fCheckbox11 = FAUSTFLOAT(0.0);
		fHslider25 = FAUSTFLOAT(0.0);
		fHslider26 = FAUSTFLOAT(1.0);
		fCheckbox12 = FAUSTFLOAT(0.0);
		fHslider27 = FAUSTFLOAT(0.0);
		fHslider28 = FAUSTFLOAT(1.0);
		fCheckbox13 = FAUSTFLOAT(0.0);
		fHslider29 = FAUSTFLOAT(0.0);
		fHslider30 = FAUSTFLOAT(1.0);
		fCheckbox14 = FAUSTFLOAT(0.0);
		fHslider31 = FAUSTFLOAT(0.0);
		fHslider32 = FAUSTFLOAT(1.0);
		fCheckbox15 = FAUSTFLOAT(0.0);
		fHslider33 = FAUSTFLOAT(0.0);
		fHslider34 = FAUSTFLOAT(1.0);
		fHslider35 = FAUSTFLOAT(0.0);
		fHslider36 = FAUSTFLOAT(1.0);
		fHslider37 = FAUSTFLOAT(100.0);
		fHslider38 = FAUSTFLOAT(1.0);
		fHslider39 = FAUSTFLOAT(0.0);
		fHslider40 = FAUSTFLOAT(64.0);
		fCheckbox16 = FAUSTFLOAT(0.0);
		fCheckbox17 = FAUSTFLOAT(0.0);
		fCheckbox18 = FAUSTFLOAT(0.0);
		fCheckbox19 = FAUSTFLOAT(0.0);
		fCheckbox20 = FAUSTFLOAT(0.0);
		fCheckbox21 = FAUSTFLOAT(0.0);
		fCheckbox22 = FAUSTFLOAT(0.0);
		fCheckbox23 = FAUSTFLOAT(0.0);
		fCheckbox24 = FAUSTFLOAT(0.0);
		fCheckbox25 = FAUSTFLOAT(0.0);
		fCheckbox26 = FAUSTFLOAT(0.0);
		fCheckbox27 = FAUSTFLOAT(0.0);
		fCheckbox28 = FAUSTFLOAT(0.0);
		fCheckbox29 = FAUSTFLOAT(0.0);
		fCheckbox30 = FAUSTFLOAT(0.0);
		fCheckbox31 = FAUSTFLOAT(0.0);
		fHslider41 = FAUSTFLOAT(1.0);
		fHslider42 = FAUSTFLOAT(200.0);
		fHslider43 = FAUSTFLOAT(0.0);
		fCheckbox32 = FAUSTFLOAT(0.0);
		fCheckbox33 = FAUSTFLOAT(0.0);
		fCheckbox34 = FAUSTFLOAT(0.0);
		fCheckbox35 = FAUSTFLOAT(0.0);
		fCheckbox36 = FAUSTFLOAT(0.0);
		fCheckbox37 = FAUSTFLOAT(0.0);
		fCheckbox38 = FAUSTFLOAT(0.0);
		fCheckbox39 = FAUSTFLOAT(0.0);
		fCheckbox40 = FAUSTFLOAT(0.0);
		fCheckbox41 = FAUSTFLOAT(0.0);
		fCheckbox42 = FAUSTFLOAT(0.0);
		fCheckbox43 = FAUSTFLOAT(0.0);
		fCheckbox44 = FAUSTFLOAT(0.0);
		fCheckbox45 = FAUSTFLOAT(0.0);
		fCheckbox46 = FAUSTFLOAT(0.0);
		fCheckbox47 = FAUSTFLOAT(0.0);
		fHslider44 = FAUSTFLOAT(1.0);
		fHslider45 = FAUSTFLOAT(300.0);
		fHslider46 = FAUSTFLOAT(0.0);
		fCheckbox48 = FAUSTFLOAT(0.0);
		fCheckbox49 = FAUSTFLOAT(0.0);
		fCheckbox50 = FAUSTFLOAT(0.0);
		fCheckbox51 = FAUSTFLOAT(0.0);
		fCheckbox52 = FAUSTFLOAT(0.0);
		fCheckbox53 = FAUSTFLOAT(0.0);
		fCheckbox54 = FAUSTFLOAT(0.0);
		fCheckbox55 = FAUSTFLOAT(0.0);
		fCheckbox56 = FAUSTFLOAT(0.0);
		fCheckbox57 = FAUSTFLOAT(0.0);
		fCheckbox58 = FAUSTFLOAT(0.0);
		fCheckbox59 = FAUSTFLOAT(0.0);
		fCheckbox60 = FAUSTFLOAT(0.0);
		fCheckbox61 = FAUSTFLOAT(0.0);
		fCheckbox62 = FAUSTFLOAT(0.0);
		fCheckbox63 = FAUSTFLOAT(0.0);
		fHslider47 = FAUSTFLOAT(1.0);
		fHslider48 = FAUSTFLOAT(400.0);
		fHslider49 = FAUSTFLOAT(0.0);
		fCheckbox64 = FAUSTFLOAT(0.0);
		fCheckbox65 = FAUSTFLOAT(0.0);
		fCheckbox66 = FAUSTFLOAT(0.0);
		fCheckbox67 = FAUSTFLOAT(0.0);
		fCheckbox68 = FAUSTFLOAT(0.0);
		fCheckbox69 = FAUSTFLOAT(0.0);
		fCheckbox70 = FAUSTFLOAT(0.0);
		fCheckbox71 = FAUSTFLOAT(0.0);
		fCheckbox72 = FAUSTFLOAT(0.0);
		fCheckbox73 = FAUSTFLOAT(0.0);
		fCheckbox74 = FAUSTFLOAT(0.0);
		fCheckbox75 = FAUSTFLOAT(0.0);
		fCheckbox76 = FAUSTFLOAT(0.0);
		fCheckbox77 = FAUSTFLOAT(0.0);
		fCheckbox78 = FAUSTFLOAT(0.0);
		fCheckbox79 = FAUSTFLOAT(0.0);
		fHslider50 = FAUSTFLOAT(1.0);
		fHslider51 = FAUSTFLOAT(500.0);
		fHslider52 = FAUSTFLOAT(0.0);
		fCheckbox80 = FAUSTFLOAT(0.0);
		fCheckbox81 = FAUSTFLOAT(0.0);
		fCheckbox82 = FAUSTFLOAT(0.0);
		fCheckbox83 = FAUSTFLOAT(0.0);
		fCheckbox84 = FAUSTFLOAT(0.0);
		fCheckbox85 = FAUSTFLOAT(0.0);
		fCheckbox86 = FAUSTFLOAT(0.0);
		fCheckbox87 = FAUSTFLOAT(0.0);
		fCheckbox88 = FAUSTFLOAT(0.0);
		fCheckbox89 = FAUSTFLOAT(0.0);
		fCheckbox90 = FAUSTFLOAT(0.0);
		fCheckbox91 = FAUSTFLOAT(0.0);
		fCheckbox92 = FAUSTFLOAT(0.0);
		fCheckbox93 = FAUSTFLOAT(0.0);
		fCheckbox94 = FAUSTFLOAT(0.0);
		fCheckbox95 = FAUSTFLOAT(0.0);
		fHslider53 = FAUSTFLOAT(1.0);
		fHslider54 = FAUSTFLOAT(600.0);
		fHslider55 = FAUSTFLOAT(0.0);
		fCheckbox96 = FAUSTFLOAT(0.0);
		fCheckbox97 = FAUSTFLOAT(0.0);
		fCheckbox98 = FAUSTFLOAT(0.0);
		fCheckbox99 = FAUSTFLOAT(0.0);
		fCheckbox100 = FAUSTFLOAT(0.0);
		fCheckbox101 = FAUSTFLOAT(0.0);
		fCheckbox102 = FAUSTFLOAT(0.0);
		fCheckbox103 = FAUSTFLOAT(0.0);
		fCheckbox104 = FAUSTFLOAT(0.0);
		fCheckbox105 = FAUSTFLOAT(0.0);
		fCheckbox106 = FAUSTFLOAT(0.0);
		fCheckbox107 = FAUSTFLOAT(0.0);
		fCheckbox108 = FAUSTFLOAT(0.0);
		fCheckbox109 = FAUSTFLOAT(0.0);
		fCheckbox110 = FAUSTFLOAT(0.0);
		fCheckbox111 = FAUSTFLOAT(0.0);
		fHslider56 = FAUSTFLOAT(1.0);
		fHslider57 = FAUSTFLOAT(700.0);
		fHslider58 = FAUSTFLOAT(0.0);
		fCheckbox112 = FAUSTFLOAT(0.0);
		fCheckbox113 = FAUSTFLOAT(0.0);
		fCheckbox114 = FAUSTFLOAT(0.0);
		fCheckbox115 = FAUSTFLOAT(0.0);
		fCheckbox116 = FAUSTFLOAT(0.0);
		fCheckbox117 = FAUSTFLOAT(0.0);
		fCheckbox118 = FAUSTFLOAT(0.0);
		fCheckbox119 = FAUSTFLOAT(0.0);
		fCheckbox120 = FAUSTFLOAT(0.0);
		fCheckbox121 = FAUSTFLOAT(0.0);
		fCheckbox122 = FAUSTFLOAT(0.0);
		fCheckbox123 = FAUSTFLOAT(0.0);
		fCheckbox124 = FAUSTFLOAT(0.0);
		fCheckbox125 = FAUSTFLOAT(0.0);
		fCheckbox126 = FAUSTFLOAT(0.0);
		fCheckbox127 = FAUSTFLOAT(0.0);
		fHslider59 = FAUSTFLOAT(1.0);
		fHslider60 = FAUSTFLOAT(800.0);
		fHslider61 = FAUSTFLOAT(0.0);
		fCheckbox128 = FAUSTFLOAT(0.0);
		fCheckbox129 = FAUSTFLOAT(0.0);
		fCheckbox130 = FAUSTFLOAT(0.0);
		fCheckbox131 = FAUSTFLOAT(0.0);
		fCheckbox132 = FAUSTFLOAT(0.0);
		fCheckbox133 = FAUSTFLOAT(0.0);
		fCheckbox134 = FAUSTFLOAT(0.0);
		fCheckbox135 = FAUSTFLOAT(0.0);
		fCheckbox136 = FAUSTFLOAT(0.0);
		fCheckbox137 = FAUSTFLOAT(0.0);
		fCheckbox138 = FAUSTFLOAT(0.0);
		fCheckbox139 = FAUSTFLOAT(0.0);
		fCheckbox140 = FAUSTFLOAT(0.0);
		fCheckbox141 = FAUSTFLOAT(0.0);
		fCheckbox142 = FAUSTFLOAT(0.0);
		fCheckbox143 = FAUSTFLOAT(0.0);
		fHslider62 = FAUSTFLOAT(1.0);
		fHslider63 = FAUSTFLOAT(900.0);
		fHslider64 = FAUSTFLOAT(0.0);
		fCheckbox144 = FAUSTFLOAT(0.0);
		fCheckbox145 = FAUSTFLOAT(0.0);
		fCheckbox146 = FAUSTFLOAT(0.0);
		fCheckbox147 = FAUSTFLOAT(0.0);
		fCheckbox148 = FAUSTFLOAT(0.0);
		fCheckbox149 = FAUSTFLOAT(0.0);
		fCheckbox150 = FAUSTFLOAT(0.0);
		fCheckbox151 = FAUSTFLOAT(0.0);
		fCheckbox152 = FAUSTFLOAT(0.0);
		fCheckbox153 = FAUSTFLOAT(0.0);
		fCheckbox154 = FAUSTFLOAT(0.0);
		fCheckbox155 = FAUSTFLOAT(0.0);
		fCheckbox156 = FAUSTFLOAT(0.0);
		fCheckbox157 = FAUSTFLOAT(0.0);
		fCheckbox158 = FAUSTFLOAT(0.0);
		fCheckbox159 = FAUSTFLOAT(0.0);
		fHslider65 = FAUSTFLOAT(1.0);
		fHslider66 = FAUSTFLOAT(1000.0);
		fHslider67 = FAUSTFLOAT(0.0);
		fCheckbox160 = FAUSTFLOAT(0.0);
		fCheckbox161 = FAUSTFLOAT(0.0);
		fCheckbox162 = FAUSTFLOAT(0.0);
		fCheckbox163 = FAUSTFLOAT(0.0);
		fCheckbox164 = FAUSTFLOAT(0.0);
		fCheckbox165 = FAUSTFLOAT(0.0);
		fCheckbox166 = FAUSTFLOAT(0.0);
		fCheckbox167 = FAUSTFLOAT(0.0);
		fCheckbox168 = FAUSTFLOAT(0.0);
		fCheckbox169 = FAUSTFLOAT(0.0);
		fCheckbox170 = FAUSTFLOAT(0.0);
		fCheckbox171 = FAUSTFLOAT(0.0);
		fCheckbox172 = FAUSTFLOAT(0.0);
		fCheckbox173 = FAUSTFLOAT(0.0);
		fCheckbox174 = FAUSTFLOAT(0.0);
		fCheckbox175 = FAUSTFLOAT(0.0);
		fHslider68 = FAUSTFLOAT(1.0);
		fHslider69 = FAUSTFLOAT(1100.0);
		fHslider70 = FAUSTFLOAT(0.0);
		fCheckbox176 = FAUSTFLOAT(0.0);
		fCheckbox177 = FAUSTFLOAT(0.0);
		fCheckbox178 = FAUSTFLOAT(0.0);
		fCheckbox179 = FAUSTFLOAT(0.0);
		fCheckbox180 = FAUSTFLOAT(0.0);
		fCheckbox181 = FAUSTFLOAT(0.0);
		fCheckbox182 = FAUSTFLOAT(0.0);
		fCheckbox183 = FAUSTFLOAT(0.0);
		fCheckbox184 = FAUSTFLOAT(0.0);
		fCheckbox185 = FAUSTFLOAT(0.0);
		fCheckbox186 = FAUSTFLOAT(0.0);
		fCheckbox187 = FAUSTFLOAT(0.0);
		fCheckbox188 = FAUSTFLOAT(0.0);
		fCheckbox189 = FAUSTFLOAT(0.0);
		fCheckbox190 = FAUSTFLOAT(0.0);
		fCheckbox191 = FAUSTFLOAT(0.0);
		fHslider71 = FAUSTFLOAT(1.0);
		fHslider72 = FAUSTFLOAT(1200.0);
		fHslider73 = FAUSTFLOAT(0.0);
		fCheckbox192 = FAUSTFLOAT(0.0);
		fCheckbox193 = FAUSTFLOAT(0.0);
		fCheckbox194 = FAUSTFLOAT(0.0);
		fCheckbox195 = FAUSTFLOAT(0.0);
		fCheckbox196 = FAUSTFLOAT(0.0);
		fCheckbox197 = FAUSTFLOAT(0.0);
		fCheckbox198 = FAUSTFLOAT(0.0);
		fCheckbox199 = FAUSTFLOAT(0.0);
		fCheckbox200 = FAUSTFLOAT(0.0);
		fCheckbox201 = FAUSTFLOAT(0.0);
		fCheckbox202 = FAUSTFLOAT(0.0);
		fCheckbox203 = FAUSTFLOAT(0.0);
		fCheckbox204 = FAUSTFLOAT(0.0);
		fCheckbox205 = FAUSTFLOAT(0.0);
		fCheckbox206 = FAUSTFLOAT(0.0);
		fCheckbox207 = FAUSTFLOAT(0.0);
		fHslider74 = FAUSTFLOAT(1.0);
		fHslider75 = FAUSTFLOAT(1300.0);
		fHslider76 = FAUSTFLOAT(0.0);
		fCheckbox208 = FAUSTFLOAT(0.0);
		fCheckbox209 = FAUSTFLOAT(0.0);
		fCheckbox210 = FAUSTFLOAT(0.0);
		fCheckbox211 = FAUSTFLOAT(0.0);
		fCheckbox212 = FAUSTFLOAT(0.0);
		fCheckbox213 = FAUSTFLOAT(0.0);
		fCheckbox214 = FAUSTFLOAT(0.0);
		fCheckbox215 = FAUSTFLOAT(0.0);
		fCheckbox216 = FAUSTFLOAT(0.0);
		fCheckbox217 = FAUSTFLOAT(0.0);
		fCheckbox218 = FAUSTFLOAT(0.0);
		fCheckbox219 = FAUSTFLOAT(0.0);
		fCheckbox220 = FAUSTFLOAT(0.0);
		fCheckbox221 = FAUSTFLOAT(0.0);
		fCheckbox222 = FAUSTFLOAT(0.0);
		fCheckbox223 = FAUSTFLOAT(0.0);
		fHslider77 = FAUSTFLOAT(1.0);
		fHslider78 = FAUSTFLOAT(1400.0);
		fHslider79 = FAUSTFLOAT(0.0);
		fCheckbox224 = FAUSTFLOAT(0.0);
		fCheckbox225 = FAUSTFLOAT(0.0);
		fCheckbox226 = FAUSTFLOAT(0.0);
		fCheckbox227 = FAUSTFLOAT(0.0);
		fCheckbox228 = FAUSTFLOAT(0.0);
		fCheckbox229 = FAUSTFLOAT(0.0);
		fCheckbox230 = FAUSTFLOAT(0.0);
		fCheckbox231 = FAUSTFLOAT(0.0);
		fCheckbox232 = FAUSTFLOAT(0.0);
		fCheckbox233 = FAUSTFLOAT(0.0);
		fCheckbox234 = FAUSTFLOAT(0.0);
		fCheckbox235 = FAUSTFLOAT(0.0);
		fCheckbox236 = FAUSTFLOAT(0.0);
		fCheckbox237 = FAUSTFLOAT(0.0);
		fCheckbox238 = FAUSTFLOAT(0.0);
		fCheckbox239 = FAUSTFLOAT(0.0);
		fHslider80 = FAUSTFLOAT(1.0);
		fHslider81 = FAUSTFLOAT(1500.0);
		fHslider82 = FAUSTFLOAT(0.0);
		fCheckbox240 = FAUSTFLOAT(0.0);
		fCheckbox241 = FAUSTFLOAT(0.0);
		fCheckbox242 = FAUSTFLOAT(0.0);
		fCheckbox243 = FAUSTFLOAT(0.0);
		fCheckbox244 = FAUSTFLOAT(0.0);
		fCheckbox245 = FAUSTFLOAT(0.0);
		fCheckbox246 = FAUSTFLOAT(0.0);
		fCheckbox247 = FAUSTFLOAT(0.0);
		fCheckbox248 = FAUSTFLOAT(0.0);
		fCheckbox249 = FAUSTFLOAT(0.0);
		fCheckbox250 = FAUSTFLOAT(0.0);
		fCheckbox251 = FAUSTFLOAT(0.0);
		fCheckbox252 = FAUSTFLOAT(0.0);
		fCheckbox253 = FAUSTFLOAT(0.0);
		fCheckbox254 = FAUSTFLOAT(0.0);
		fCheckbox255 = FAUSTFLOAT(0.0);
		fHslider83 = FAUSTFLOAT(1.0);
		fHslider84 = FAUSTFLOAT(1600.0);
		fHslider85 = FAUSTFLOAT(0.0);
		fHslider86 = FAUSTFLOAT(1.0);
		fCheckbox256 = FAUSTFLOAT(0.0);
		fCheckbox257 = FAUSTFLOAT(0.0);
		fCheckbox258 = FAUSTFLOAT(0.0);
		fCheckbox259 = FAUSTFLOAT(0.0);
		fCheckbox260 = FAUSTFLOAT(0.0);
		fHslider87 = FAUSTFLOAT(1.0);
		fCheckbox261 = FAUSTFLOAT(0.0);
		fCheckbox262 = FAUSTFLOAT(0.0);
		fCheckbox263 = FAUSTFLOAT(0.0);
		fCheckbox264 = FAUSTFLOAT(0.0);
		fCheckbox265 = FAUSTFLOAT(0.0);
		fHslider88 = FAUSTFLOAT(1.0);
		fCheckbox266 = FAUSTFLOAT(0.0);
		fCheckbox267 = FAUSTFLOAT(0.0);
		fCheckbox268 = FAUSTFLOAT(0.0);
		fCheckbox269 = FAUSTFLOAT(0.0);
		fCheckbox270 = FAUSTFLOAT(0.0);
		fHslider89 = FAUSTFLOAT(1.0);
		fCheckbox271 = FAUSTFLOAT(0.0);
		fCheckbox272 = FAUSTFLOAT(0.0);
		fCheckbox273 = FAUSTFLOAT(0.0);
		fCheckbox274 = FAUSTFLOAT(0.0);
		fCheckbox275 = FAUSTFLOAT(0.0);
		fHslider90 = FAUSTFLOAT(1.0);
		fCheckbox276 = FAUSTFLOAT(0.0);
		fCheckbox277 = FAUSTFLOAT(0.0);
		fCheckbox278 = FAUSTFLOAT(0.0);
		fCheckbox279 = FAUSTFLOAT(0.0);
		fCheckbox280 = FAUSTFLOAT(0.0);
		fHslider91 = FAUSTFLOAT(1.0);
		fCheckbox281 = FAUSTFLOAT(0.0);
		fCheckbox282 = FAUSTFLOAT(0.0);
		fCheckbox283 = FAUSTFLOAT(0.0);
		fCheckbox284 = FAUSTFLOAT(0.0);
		fCheckbox285 = FAUSTFLOAT(0.0);
		fHslider92 = FAUSTFLOAT(1.0);
		fCheckbox286 = FAUSTFLOAT(0.0);
		fCheckbox287 = FAUSTFLOAT(0.0);
		fCheckbox288 = FAUSTFLOAT(0.0);
		fCheckbox289 = FAUSTFLOAT(0.0);
		fCheckbox290 = FAUSTFLOAT(0.0);
		fHslider93 = FAUSTFLOAT(1.0);
		fCheckbox291 = FAUSTFLOAT(0.0);
		fCheckbox292 = FAUSTFLOAT(0.0);
		fCheckbox293 = FAUSTFLOAT(0.0);
		fCheckbox294 = FAUSTFLOAT(0.0);
		fCheckbox295 = FAUSTFLOAT(0.0);
		fHslider94 = FAUSTFLOAT(1.0);
		fCheckbox296 = FAUSTFLOAT(0.0);
		fCheckbox297 = FAUSTFLOAT(0.0);
		fCheckbox298 = FAUSTFLOAT(0.0);
		fCheckbox299 = FAUSTFLOAT(0.0);
		fCheckbox300 = FAUSTFLOAT(0.0);
		fHslider95 = FAUSTFLOAT(1.0);
		fCheckbox301 = FAUSTFLOAT(0.0);
		fCheckbox302 = FAUSTFLOAT(0.0);
		fCheckbox303 = FAUSTFLOAT(0.0);
		fCheckbox304 = FAUSTFLOAT(0.0);
		fCheckbox305 = FAUSTFLOAT(0.0);
		fHslider96 = FAUSTFLOAT(1.0);
		fCheckbox306 = FAUSTFLOAT(0.0);
		fCheckbox307 = FAUSTFLOAT(0.0);
		fCheckbox308 = FAUSTFLOAT(0.0);
		fCheckbox309 = FAUSTFLOAT(0.0);
		fCheckbox310 = FAUSTFLOAT(0.0);
		fHslider97 = FAUSTFLOAT(1.0);
		fCheckbox311 = FAUSTFLOAT(0.0);
		fCheckbox312 = FAUSTFLOAT(0.0);
		fCheckbox313 = FAUSTFLOAT(0.0);
		fCheckbox314 = FAUSTFLOAT(0.0);
		fCheckbox315 = FAUSTFLOAT(0.0);
		fHslider98 = FAUSTFLOAT(1.0);
		fCheckbox316 = FAUSTFLOAT(0.0);
		fCheckbox317 = FAUSTFLOAT(0.0);
		fCheckbox318 = FAUSTFLOAT(0.0);
		fCheckbox319 = FAUSTFLOAT(0.0);
		fCheckbox320 = FAUSTFLOAT(0.0);
		fHslider99 = FAUSTFLOAT(1.0);
		fCheckbox321 = FAUSTFLOAT(0.0);
		fCheckbox322 = FAUSTFLOAT(0.0);
		fCheckbox323 = FAUSTFLOAT(0.0);
		fCheckbox324 = FAUSTFLOAT(0.0);
		fCheckbox325 = FAUSTFLOAT(0.0);
		fHslider100 = FAUSTFLOAT(1.0);
		fCheckbox326 = FAUSTFLOAT(0.0);
		fCheckbox327 = FAUSTFLOAT(0.0);
		fCheckbox328 = FAUSTFLOAT(0.0);
		fCheckbox329 = FAUSTFLOAT(0.0);
		fCheckbox330 = FAUSTFLOAT(0.0);
		fHslider101 = FAUSTFLOAT(-34.0);
		fCheckbox331 = FAUSTFLOAT(0.0);
		fCheckbox332 = FAUSTFLOAT(0.0);
		fCheckbox333 = FAUSTFLOAT(0.0);
		fCheckbox334 = FAUSTFLOAT(0.0);
		fCheckbox335 = FAUSTFLOAT(0.0);
		fHslider102 = FAUSTFLOAT(1.0);
		fCheckbox336 = FAUSTFLOAT(0.0);
		fCheckbox337 = FAUSTFLOAT(0.0);
		fCheckbox338 = FAUSTFLOAT(0.0);
		fCheckbox339 = FAUSTFLOAT(0.0);
		fCheckbox340 = FAUSTFLOAT(0.0);
		fCheckbox341 = FAUSTFLOAT(0.0);
		fHslider103 = FAUSTFLOAT(0.0);
		fHslider104 = FAUSTFLOAT(0.0);
		fCheckbox342 = FAUSTFLOAT(0.0);
		fHslider105 = FAUSTFLOAT(0.0);
		fEntry0 = FAUSTFLOAT(10.0);
		fHslider106 = FAUSTFLOAT(0.5);
		fHslider107 = FAUSTFLOAT(0.10000000000000001);
		fHslider108 = FAUSTFLOAT(0.0);
		fHslider109 = FAUSTFLOAT(0.10000000000000001);
		fHslider110 = FAUSTFLOAT(0.0);
		fHslider111 = FAUSTFLOAT(0.10000000000000001);
		fHslider112 = FAUSTFLOAT(0.0);
		fCheckbox343 = FAUSTFLOAT(0.0);
		fCheckbox344 = FAUSTFLOAT(0.0);
		fCheckbox345 = FAUSTFLOAT(0.0);
		fCheckbox346 = FAUSTFLOAT(0.0);
		fCheckbox347 = FAUSTFLOAT(0.0);
		fCheckbox348 = FAUSTFLOAT(0.0);
		fCheckbox349 = FAUSTFLOAT(0.0);
		fCheckbox350 = FAUSTFLOAT(0.0);
		fCheckbox351 = FAUSTFLOAT(0.0);
		fCheckbox352 = FAUSTFLOAT(0.0);
		fCheckbox353 = FAUSTFLOAT(0.0);
		fCheckbox354 = FAUSTFLOAT(0.0);
		fCheckbox355 = FAUSTFLOAT(0.0);
		fCheckbox356 = FAUSTFLOAT(0.0);
		fCheckbox357 = FAUSTFLOAT(0.0);
		fCheckbox358 = FAUSTFLOAT(0.0);
		fHslider113 = FAUSTFLOAT(0.10000000000000001);
		fHslider114 = FAUSTFLOAT(0.0);
		fCheckbox359 = FAUSTFLOAT(0.0);
		fCheckbox360 = FAUSTFLOAT(0.0);
		fCheckbox361 = FAUSTFLOAT(0.0);
		fCheckbox362 = FAUSTFLOAT(0.0);
		fCheckbox363 = FAUSTFLOAT(0.0);
		fCheckbox364 = FAUSTFLOAT(0.0);
		fCheckbox365 = FAUSTFLOAT(0.0);
		fCheckbox366 = FAUSTFLOAT(0.0);
		fCheckbox367 = FAUSTFLOAT(0.0);
		fCheckbox368 = FAUSTFLOAT(0.0);
		fCheckbox369 = FAUSTFLOAT(0.0);
		fCheckbox370 = FAUSTFLOAT(0.0);
		fCheckbox371 = FAUSTFLOAT(0.0);
		fCheckbox372 = FAUSTFLOAT(0.0);
		fCheckbox373 = FAUSTFLOAT(0.0);
		fCheckbox374 = FAUSTFLOAT(0.0);
		fCheckbox375 = FAUSTFLOAT(0.0);
		fCheckbox376 = FAUSTFLOAT(0.0);
		fCheckbox377 = FAUSTFLOAT(0.0);
		fCheckbox378 = FAUSTFLOAT(0.0);
		fCheckbox379 = FAUSTFLOAT(0.0);
		fCheckbox380 = FAUSTFLOAT(0.0);
		fCheckbox381 = FAUSTFLOAT(0.0);
		fCheckbox382 = FAUSTFLOAT(0.0);
		fCheckbox383 = FAUSTFLOAT(0.0);
		fCheckbox384 = FAUSTFLOAT(0.0);
		fCheckbox385 = FAUSTFLOAT(0.0);
		fCheckbox386 = FAUSTFLOAT(0.0);
		fCheckbox387 = FAUSTFLOAT(0.0);
		fCheckbox388 = FAUSTFLOAT(0.0);
		fCheckbox389 = FAUSTFLOAT(0.0);
		fCheckbox390 = FAUSTFLOAT(0.0);
		fCheckbox391 = FAUSTFLOAT(0.0);
		fCheckbox392 = FAUSTFLOAT(0.0);
		fCheckbox393 = FAUSTFLOAT(0.0);
		fCheckbox394 = FAUSTFLOAT(0.0);
		fCheckbox395 = FAUSTFLOAT(0.0);
		fCheckbox396 = FAUSTFLOAT(0.0);
		fCheckbox397 = FAUSTFLOAT(0.0);
		fCheckbox398 = FAUSTFLOAT(0.0);
		fCheckbox399 = FAUSTFLOAT(0.0);
		fCheckbox400 = FAUSTFLOAT(0.0);
		fCheckbox401 = FAUSTFLOAT(0.0);
		fCheckbox402 = FAUSTFLOAT(0.0);
		fCheckbox403 = FAUSTFLOAT(0.0);
		fCheckbox404 = FAUSTFLOAT(0.0);
		fCheckbox405 = FAUSTFLOAT(0.0);
		fCheckbox406 = FAUSTFLOAT(0.0);
		fCheckbox407 = FAUSTFLOAT(0.0);
		fCheckbox408 = FAUSTFLOAT(0.0);
		fCheckbox409 = FAUSTFLOAT(0.0);
		fCheckbox410 = FAUSTFLOAT(0.0);
		fCheckbox411 = FAUSTFLOAT(0.0);
		fCheckbox412 = FAUSTFLOAT(0.0);
		fCheckbox413 = FAUSTFLOAT(0.0);
		fCheckbox414 = FAUSTFLOAT(0.0);
		fCheckbox415 = FAUSTFLOAT(0.0);
		fCheckbox416 = FAUSTFLOAT(0.0);
		fCheckbox417 = FAUSTFLOAT(0.0);
		fCheckbox418 = FAUSTFLOAT(0.0);
		fCheckbox419 = FAUSTFLOAT(0.0);
		fCheckbox420 = FAUSTFLOAT(0.0);
		fCheckbox421 = FAUSTFLOAT(0.0);
		fCheckbox422 = FAUSTFLOAT(0.0);
		fCheckbox423 = FAUSTFLOAT(0.0);
		fCheckbox424 = FAUSTFLOAT(0.0);
		fCheckbox425 = FAUSTFLOAT(0.0);
		fCheckbox426 = FAUSTFLOAT(0.0);
		fCheckbox427 = FAUSTFLOAT(0.0);
		fCheckbox428 = FAUSTFLOAT(0.0);
		fCheckbox429 = FAUSTFLOAT(0.0);
		fCheckbox430 = FAUSTFLOAT(0.0);
		fCheckbox431 = FAUSTFLOAT(0.0);
		fCheckbox432 = FAUSTFLOAT(0.0);
		fCheckbox433 = FAUSTFLOAT(0.0);
		fCheckbox434 = FAUSTFLOAT(0.0);
		fCheckbox435 = FAUSTFLOAT(0.0);
		fCheckbox436 = FAUSTFLOAT(0.0);
		fCheckbox437 = FAUSTFLOAT(0.0);
		fCheckbox438 = FAUSTFLOAT(0.0);
		fCheckbox439 = FAUSTFLOAT(0.0);
		fCheckbox440 = FAUSTFLOAT(0.0);
		fCheckbox441 = FAUSTFLOAT(0.0);
		fCheckbox442 = FAUSTFLOAT(0.0);
		fCheckbox443 = FAUSTFLOAT(0.0);
		fHslider115 = FAUSTFLOAT(45.0);
		fHslider116 = FAUSTFLOAT(90.0);
		fHslider117 = FAUSTFLOAT(135.0);
		fHslider118 = FAUSTFLOAT(180.0);
		fHslider119 = FAUSTFLOAT(225.0);
		fHslider120 = FAUSTFLOAT(270.0);
		fHslider121 = FAUSTFLOAT(315.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec18[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec0[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec19[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec20[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec21[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec22[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec23[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec24[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec25[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec26[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec27[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec28[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec29[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec30[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec31[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec32[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec33[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec34[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec35[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec36[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec37[l22] = 0.0;
			
		}
		IOTA = 0;
		for (int l23 = 0; (l23 < 2097152); l23 = (l23 + 1)) {
			fVec1[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			iRec38[l24] = 0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fVec2[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			iRec39[l26] = 0;
			
		}
		for (int l27 = 0; (l27 < 524288); l27 = (l27 + 1)) {
			fVec3[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fVec4[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec42[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec43[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec41[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fVec5[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec40[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fVec6[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec44[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fVec7[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec45[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fVec8[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec46[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec1[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec47[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2097152); l42 = (l42 + 1)) {
			fVec9[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			iRec48[l43] = 0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			iRec49[l44] = 0;
			
		}
		for (int l45 = 0; (l45 < 524288); l45 = (l45 + 1)) {
			fVec10[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec51[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fVec11[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec50[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fVec12[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec52[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fVec13[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec53[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fVec14[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec54[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec2[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec55[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2097152); l57 = (l57 + 1)) {
			fVec15[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			iRec56[l58] = 0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			iRec57[l59] = 0;
			
		}
		for (int l60 = 0; (l60 < 524288); l60 = (l60 + 1)) {
			fVec16[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec59[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fVec17[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec58[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fVec18[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec60[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fVec19[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec61[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fVec20[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec62[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec3[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec63[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2097152); l72 = (l72 + 1)) {
			fVec21[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			iRec64[l73] = 0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			iRec65[l74] = 0;
			
		}
		for (int l75 = 0; (l75 < 524288); l75 = (l75 + 1)) {
			fVec22[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec67[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fVec23[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec66[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fVec24[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec68[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fVec25[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec69[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fVec26[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec70[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec4[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec71[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2097152); l87 = (l87 + 1)) {
			fVec27[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			iRec72[l88] = 0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			iRec73[l89] = 0;
			
		}
		for (int l90 = 0; (l90 < 524288); l90 = (l90 + 1)) {
			fVec28[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec75[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fVec29[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec74[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fVec30[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec76[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fVec31[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec77[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fVec32[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec78[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec5[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec79[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2097152); l102 = (l102 + 1)) {
			fVec33[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			iRec80[l103] = 0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			iRec81[l104] = 0;
			
		}
		for (int l105 = 0; (l105 < 524288); l105 = (l105 + 1)) {
			fVec34[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec83[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fVec35[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec82[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fVec36[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec84[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fVec37[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec85[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fVec38[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec86[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec6[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec87[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2097152); l117 = (l117 + 1)) {
			fVec39[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			iRec88[l118] = 0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			iRec89[l119] = 0;
			
		}
		for (int l120 = 0; (l120 < 524288); l120 = (l120 + 1)) {
			fVec40[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec91[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fVec41[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec90[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fVec42[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec92[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fVec43[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec93[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fVec44[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec94[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec7[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec95[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2097152); l132 = (l132 + 1)) {
			fVec45[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			iRec96[l133] = 0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			iRec97[l134] = 0;
			
		}
		for (int l135 = 0; (l135 < 524288); l135 = (l135 + 1)) {
			fVec46[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec99[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fVec47[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec98[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fVec48[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec100[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fVec49[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec101[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fVec50[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec102[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec8[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec103[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2097152); l147 = (l147 + 1)) {
			fVec51[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			iRec104[l148] = 0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			iRec105[l149] = 0;
			
		}
		for (int l150 = 0; (l150 < 524288); l150 = (l150 + 1)) {
			fVec52[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec107[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fVec53[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec106[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fVec54[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec108[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fVec55[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec109[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fVec56[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec110[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec9[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec111[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2097152); l162 = (l162 + 1)) {
			fVec57[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			iRec112[l163] = 0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			iRec113[l164] = 0;
			
		}
		for (int l165 = 0; (l165 < 524288); l165 = (l165 + 1)) {
			fVec58[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec115[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fVec59[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec114[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fVec60[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec116[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fVec61[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec117[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fVec62[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec118[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec10[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec119[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2097152); l177 = (l177 + 1)) {
			fVec63[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			iRec120[l178] = 0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			iRec121[l179] = 0;
			
		}
		for (int l180 = 0; (l180 < 524288); l180 = (l180 + 1)) {
			fVec64[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec123[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fVec65[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec122[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fVec66[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec124[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fVec67[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec125[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fVec68[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec126[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec11[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec127[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2097152); l192 = (l192 + 1)) {
			fVec69[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			iRec128[l193] = 0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			iRec129[l194] = 0;
			
		}
		for (int l195 = 0; (l195 < 524288); l195 = (l195 + 1)) {
			fVec70[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec131[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fVec71[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec130[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fVec72[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec132[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fVec73[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec133[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fVec74[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec134[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec12[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec135[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2097152); l207 = (l207 + 1)) {
			fVec75[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			iRec136[l208] = 0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			iRec137[l209] = 0;
			
		}
		for (int l210 = 0; (l210 < 524288); l210 = (l210 + 1)) {
			fVec76[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec139[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fVec77[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec138[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fVec78[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec140[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fVec79[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec141[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fVec80[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec142[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec13[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec143[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2097152); l222 = (l222 + 1)) {
			fVec81[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			iRec144[l223] = 0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			iRec145[l224] = 0;
			
		}
		for (int l225 = 0; (l225 < 524288); l225 = (l225 + 1)) {
			fVec82[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec147[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fVec83[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec146[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fVec84[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec148[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fVec85[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec149[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fVec86[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec150[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec14[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec151[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2097152); l237 = (l237 + 1)) {
			fVec87[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			iRec152[l238] = 0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			iRec153[l239] = 0;
			
		}
		for (int l240 = 0; (l240 < 524288); l240 = (l240 + 1)) {
			fVec88[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec155[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fVec89[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec154[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fVec90[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec156[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fVec91[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec157[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fVec92[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec158[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec15[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec159[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2097152); l252 = (l252 + 1)) {
			fVec93[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			iRec160[l253] = 0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			iRec161[l254] = 0;
			
		}
		for (int l255 = 0; (l255 < 524288); l255 = (l255 + 1)) {
			fVec94[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec163[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fVec95[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec162[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fVec96[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec164[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fVec97[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec165[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fVec98[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec166[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec16[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec167[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec168[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec169[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec170[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec171[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec172[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec173[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec174[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec175[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec176[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec177[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec178[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec179[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec180[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec181[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec182[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec183[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec184[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec185[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec186[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec187[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec188[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec189[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec190[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec191[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec192[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec193[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec194[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec195[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec196[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec197[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec198[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec199[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec200[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec201[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec202[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec203[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec204[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec205[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec206[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec207[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec208[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec209[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec210[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec211[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec212[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec213[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec214[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec215[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec216[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec217[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec218[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec219[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec220[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec221[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec222[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec223[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec224[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec225[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec226[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec227[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec228[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec229[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec230[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec231[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec232[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec233[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec234[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec235[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec236[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec237[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec238[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec239[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec240[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec241[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec242[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec243[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec244[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec245[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec246[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec247[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec248[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec249[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec250[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec251[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec252[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec253[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec254[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec255[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec256[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec257[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec258[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec259[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec260[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec261[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec262[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec263[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec264[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec265[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec266[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec267[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec268[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec269[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec270[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec272[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			iRec273[l371] = 0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			iRec271[l372] = 0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec279[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec280[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec281[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec282[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec283[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec284[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec285[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec286[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec287[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec288[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec289[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec290[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec291[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec292[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec293[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec294[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec295[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec296[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec297[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec298[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec299[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			iRec300[l394] = 0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec301[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec302[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec303[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec304[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec305[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec306[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec307[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec308[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec309[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec310[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec311[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec312[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec313[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec314[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec315[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec316[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec317[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			iRec318[l412] = 0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec319[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec320[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec321[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec322[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec323[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec324[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec325[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec326[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec327[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec328[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec329[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec330[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec331[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec332[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec333[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec334[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec335[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			iRec336[l430] = 0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec337[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec338[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec339[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec340[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec341[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec342[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec343[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec344[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec345[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec346[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec347[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec348[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec349[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec350[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec351[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec352[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec353[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			iRec354[l448] = 0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec355[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec356[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec357[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec358[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec359[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec360[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec361[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec362[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec363[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec364[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec365[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec366[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec367[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec368[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec369[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec370[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec371[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			iRec372[l466] = 0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec373[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec374[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec375[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec376[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec377[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec378[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec379[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec380[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec381[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec382[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec383[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec384[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec385[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec386[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec387[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec388[l482] = 0.0;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FilDeSoi1SoundProcess8LS");
		ui_interface->openHorizontalBox("Encoders");
		ui_interface->addHorizontalSlider("rotfreq0", &fHslider113, 0.10000000000000001, -10.0, 10.0, 0.01);
		ui_interface->addHorizontalSlider("rotfreq1", &fHslider111, 0.10000000000000001, -10.0, 10.0, 0.01);
		ui_interface->addHorizontalSlider("rotfreq2", &fHslider109, 0.10000000000000001, -10.0, 10.0, 0.01);
		ui_interface->addHorizontalSlider("rotfreq3", &fHslider107, 0.10000000000000001, -10.0, 10.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase0", &fHslider114, 0.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase1", &fHslider112, 0.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase2", &fHslider110, 0.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase3", &fHslider108, 0.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Global_Parameters");
		ui_interface->declare(&fHslider36, "7", "");
		ui_interface->addHorizontalSlider("dStretch", &fHslider36, 1.0, 0.01, 10.0, 0.01);
		ui_interface->declare(&fHslider35, "7", "");
		ui_interface->addHorizontalSlider("delharmoGain", &fHslider35, 0.0, -127.0, 18.0, 0.01);
		ui_interface->declare(&fHslider0, "7", "");
		ui_interface->addHorizontalSlider("generalGain", &fHslider0, 0.0, -127.0, 18.0, 0.01);
		ui_interface->declare(&fHslider101, "7", "");
		ui_interface->addHorizontalSlider("guitarGain", &fHslider101, -34.0, -127.0, 18.0, 0.01);
		ui_interface->declare(&fHslider38, "7", "");
		ui_interface->addHorizontalSlider("hStretch", &fHslider38, 1.0, -10.0, 10.0, 0.01);
		ui_interface->addHorizontalSlider("hWin", &fHslider40, 64.0, 1.0, 127.0, 0.01);
		ui_interface->addHorizontalSlider("smoothDuration", &fHslider1, 20.0, 10.0, 5000.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lines");
		ui_interface->openVerticalBox("Del_Durations");
		ui_interface->addHorizontalSlider("d 0", &fHslider37, 100.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 1", &fHslider42, 200.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 2", &fHslider45, 300.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 3", &fHslider48, 400.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 4", &fHslider51, 500.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 5", &fHslider54, 600.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 6", &fHslider57, 700.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 7", &fHslider60, 800.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 8", &fHslider63, 900.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d 9", &fHslider66, 1000.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d10", &fHslider69, 1100.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d11", &fHslider72, 1200.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d12", &fHslider75, 1300.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d13", &fHslider78, 1400.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d14", &fHslider81, 1500.0, 0.0, 21000.0, 1.0);
		ui_interface->addHorizontalSlider("d15", &fHslider84, 1600.0, 0.0, 21000.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del_Feedbacks");
		ui_interface->addHorizontalSlider("fd 0", &fHslider3, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 1", &fHslider5, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 2", &fHslider7, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 3", &fHslider9, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 4", &fHslider11, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 5", &fHslider13, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 6", &fHslider15, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 7", &fHslider17, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 8", &fHslider19, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 9", &fHslider21, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd10", &fHslider23, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd11", &fHslider25, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd12", &fHslider27, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd13", &fHslider29, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd14", &fHslider31, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd15", &fHslider33, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("EffeX_vs_Del");
		ui_interface->addHorizontalSlider("xvd 0", &fHslider2, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 1", &fHslider4, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 2", &fHslider6, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 3", &fHslider8, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 4", &fHslider10, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 5", &fHslider12, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 6", &fHslider14, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 7", &fHslider16, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 8", &fHslider18, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 9", &fHslider20, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd10", &fHslider22, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd11", &fHslider24, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd12", &fHslider26, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd13", &fHslider28, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd14", &fHslider30, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd15", &fHslider32, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Harmo_Transpositions");
		ui_interface->addHorizontalSlider("tr 0", &fHslider39, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 1", &fHslider43, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 2", &fHslider46, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 3", &fHslider49, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 4", &fHslider52, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 5", &fHslider55, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 6", &fHslider58, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 7", &fHslider61, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 8", &fHslider64, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 9", &fHslider67, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr10", &fHslider70, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr11", &fHslider73, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr12", &fHslider76, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr13", &fHslider79, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr14", &fHslider82, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr15", &fHslider85, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_input");
		ui_interface->declare(&fHslider34, "5", "");
		ui_interface->addHorizontalSlider("inp 0", &fHslider34, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider41, "5", "");
		ui_interface->addHorizontalSlider("inp 1", &fHslider41, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider44, "5", "");
		ui_interface->addHorizontalSlider("inp 2", &fHslider44, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider47, "5", "");
		ui_interface->addHorizontalSlider("inp 3", &fHslider47, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider50, "5", "");
		ui_interface->addHorizontalSlider("inp 4", &fHslider50, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider53, "5", "");
		ui_interface->addHorizontalSlider("inp 5", &fHslider53, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider56, "5", "");
		ui_interface->addHorizontalSlider("inp 6", &fHslider56, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider59, "5", "");
		ui_interface->addHorizontalSlider("inp 7", &fHslider59, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider62, "5", "");
		ui_interface->addHorizontalSlider("inp 8", &fHslider62, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider65, "5", "");
		ui_interface->addHorizontalSlider("inp 9", &fHslider65, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider68, "5", "");
		ui_interface->addHorizontalSlider("inp10", &fHslider68, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider71, "5", "");
		ui_interface->addHorizontalSlider("inp11", &fHslider71, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider74, "5", "");
		ui_interface->addHorizontalSlider("inp12", &fHslider74, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider77, "5", "");
		ui_interface->addHorizontalSlider("inp13", &fHslider77, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider80, "5", "");
		ui_interface->addHorizontalSlider("inp14", &fHslider80, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider83, "5", "");
		ui_interface->addHorizontalSlider("inp15", &fHslider83, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_output");
		ui_interface->declare(&fHslider102, "6", "");
		ui_interface->addHorizontalSlider("out 0", &fHslider102, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider100, "6", "");
		ui_interface->addHorizontalSlider("out 1", &fHslider100, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider99, "6", "");
		ui_interface->addHorizontalSlider("out 2", &fHslider99, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider98, "6", "");
		ui_interface->addHorizontalSlider("out 3", &fHslider98, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider97, "6", "");
		ui_interface->addHorizontalSlider("out 4", &fHslider97, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider96, "6", "");
		ui_interface->addHorizontalSlider("out 5", &fHslider96, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider95, "6", "");
		ui_interface->addHorizontalSlider("out 6", &fHslider95, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider94, "6", "");
		ui_interface->addHorizontalSlider("out 7", &fHslider94, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider93, "6", "");
		ui_interface->addHorizontalSlider("out 8", &fHslider93, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider92, "6", "");
		ui_interface->addHorizontalSlider("out 9", &fHslider92, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider91, "6", "");
		ui_interface->addHorizontalSlider("out10", &fHslider91, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider90, "6", "");
		ui_interface->addHorizontalSlider("out11", &fHslider90, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider89, "6", "");
		ui_interface->addHorizontalSlider("out12", &fHslider89, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider88, "6", "");
		ui_interface->addHorizontalSlider("out13", &fHslider88, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider87, "6", "");
		ui_interface->addHorizontalSlider("out14", &fHslider87, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider86, "6", "");
		ui_interface->addHorizontalSlider("out15", &fHslider86, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Reinjection_Matrix");
		ui_interface->openVerticalBox("Del 0-->");
		ui_interface->addCheckButton("r  0", &fCheckbox0);
		ui_interface->addCheckButton("r 16", &fCheckbox16);
		ui_interface->addCheckButton("r 32", &fCheckbox32);
		ui_interface->addCheckButton("r 48", &fCheckbox48);
		ui_interface->addCheckButton("r 64", &fCheckbox64);
		ui_interface->addCheckButton("r 80", &fCheckbox80);
		ui_interface->addCheckButton("r 96", &fCheckbox96);
		ui_interface->addCheckButton("r112", &fCheckbox112);
		ui_interface->addCheckButton("r128", &fCheckbox130);
		ui_interface->addCheckButton("r144", &fCheckbox144);
		ui_interface->addCheckButton("r160", &fCheckbox160);
		ui_interface->addCheckButton("r176", &fCheckbox176);
		ui_interface->addCheckButton("r192", &fCheckbox192);
		ui_interface->addCheckButton("r208", &fCheckbox208);
		ui_interface->addCheckButton("r224", &fCheckbox224);
		ui_interface->addCheckButton("r240", &fCheckbox241);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 1-->");
		ui_interface->addCheckButton("r  1", &fCheckbox1);
		ui_interface->addCheckButton("r 17", &fCheckbox17);
		ui_interface->addCheckButton("r 33", &fCheckbox33);
		ui_interface->addCheckButton("r 49", &fCheckbox49);
		ui_interface->addCheckButton("r 65", &fCheckbox65);
		ui_interface->addCheckButton("r 81", &fCheckbox81);
		ui_interface->addCheckButton("r 97", &fCheckbox97);
		ui_interface->addCheckButton("r113", &fCheckbox113);
		ui_interface->addCheckButton("r129", &fCheckbox131);
		ui_interface->addCheckButton("r145", &fCheckbox145);
		ui_interface->addCheckButton("r161", &fCheckbox161);
		ui_interface->addCheckButton("r177", &fCheckbox177);
		ui_interface->addCheckButton("r193", &fCheckbox193);
		ui_interface->addCheckButton("r209", &fCheckbox209);
		ui_interface->addCheckButton("r225", &fCheckbox225);
		ui_interface->addCheckButton("r241", &fCheckbox242);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 2-->");
		ui_interface->addCheckButton("r  2", &fCheckbox2);
		ui_interface->addCheckButton("r 18", &fCheckbox18);
		ui_interface->addCheckButton("r 34", &fCheckbox34);
		ui_interface->addCheckButton("r 50", &fCheckbox50);
		ui_interface->addCheckButton("r 66", &fCheckbox66);
		ui_interface->addCheckButton("r 82", &fCheckbox82);
		ui_interface->addCheckButton("r 98", &fCheckbox98);
		ui_interface->addCheckButton("r114", &fCheckbox114);
		ui_interface->addCheckButton("r130", &fCheckbox132);
		ui_interface->addCheckButton("r146", &fCheckbox146);
		ui_interface->addCheckButton("r162", &fCheckbox162);
		ui_interface->addCheckButton("r178", &fCheckbox178);
		ui_interface->addCheckButton("r194", &fCheckbox194);
		ui_interface->addCheckButton("r210", &fCheckbox210);
		ui_interface->addCheckButton("r226", &fCheckbox226);
		ui_interface->addCheckButton("r242", &fCheckbox243);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 3-->");
		ui_interface->addCheckButton("r  3", &fCheckbox3);
		ui_interface->addCheckButton("r 19", &fCheckbox19);
		ui_interface->addCheckButton("r 35", &fCheckbox35);
		ui_interface->addCheckButton("r 51", &fCheckbox51);
		ui_interface->addCheckButton("r 67", &fCheckbox67);
		ui_interface->addCheckButton("r 83", &fCheckbox83);
		ui_interface->addCheckButton("r 99", &fCheckbox99);
		ui_interface->addCheckButton("r115", &fCheckbox115);
		ui_interface->addCheckButton("r131", &fCheckbox133);
		ui_interface->addCheckButton("r147", &fCheckbox147);
		ui_interface->addCheckButton("r163", &fCheckbox163);
		ui_interface->addCheckButton("r179", &fCheckbox179);
		ui_interface->addCheckButton("r195", &fCheckbox195);
		ui_interface->addCheckButton("r211", &fCheckbox211);
		ui_interface->addCheckButton("r227", &fCheckbox227);
		ui_interface->addCheckButton("r243", &fCheckbox244);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 4-->");
		ui_interface->addCheckButton("r  4", &fCheckbox4);
		ui_interface->addCheckButton("r 20", &fCheckbox20);
		ui_interface->addCheckButton("r 36", &fCheckbox36);
		ui_interface->addCheckButton("r 52", &fCheckbox52);
		ui_interface->addCheckButton("r 68", &fCheckbox68);
		ui_interface->addCheckButton("r 84", &fCheckbox84);
		ui_interface->addCheckButton("r100", &fCheckbox100);
		ui_interface->addCheckButton("r116", &fCheckbox116);
		ui_interface->addCheckButton("r132", &fCheckbox134);
		ui_interface->addCheckButton("r148", &fCheckbox148);
		ui_interface->addCheckButton("r164", &fCheckbox164);
		ui_interface->addCheckButton("r180", &fCheckbox180);
		ui_interface->addCheckButton("r196", &fCheckbox196);
		ui_interface->addCheckButton("r212", &fCheckbox212);
		ui_interface->addCheckButton("r228", &fCheckbox228);
		ui_interface->addCheckButton("r244", &fCheckbox245);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 5-->");
		ui_interface->addCheckButton("r  5", &fCheckbox5);
		ui_interface->addCheckButton("r 21", &fCheckbox21);
		ui_interface->addCheckButton("r 37", &fCheckbox37);
		ui_interface->addCheckButton("r 53", &fCheckbox53);
		ui_interface->addCheckButton("r 69", &fCheckbox69);
		ui_interface->addCheckButton("r 85", &fCheckbox85);
		ui_interface->addCheckButton("r101", &fCheckbox101);
		ui_interface->addCheckButton("r117", &fCheckbox117);
		ui_interface->addCheckButton("r133", &fCheckbox135);
		ui_interface->addCheckButton("r149", &fCheckbox149);
		ui_interface->addCheckButton("r165", &fCheckbox165);
		ui_interface->addCheckButton("r181", &fCheckbox181);
		ui_interface->addCheckButton("r197", &fCheckbox197);
		ui_interface->addCheckButton("r213", &fCheckbox213);
		ui_interface->addCheckButton("r229", &fCheckbox229);
		ui_interface->addCheckButton("r245", &fCheckbox246);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 6-->");
		ui_interface->addCheckButton("r  6", &fCheckbox6);
		ui_interface->addCheckButton("r 22", &fCheckbox22);
		ui_interface->addCheckButton("r 38", &fCheckbox38);
		ui_interface->addCheckButton("r 54", &fCheckbox54);
		ui_interface->addCheckButton("r 70", &fCheckbox70);
		ui_interface->addCheckButton("r 86", &fCheckbox86);
		ui_interface->addCheckButton("r102", &fCheckbox102);
		ui_interface->addCheckButton("r118", &fCheckbox118);
		ui_interface->addCheckButton("r134", &fCheckbox136);
		ui_interface->addCheckButton("r150", &fCheckbox150);
		ui_interface->addCheckButton("r166", &fCheckbox166);
		ui_interface->addCheckButton("r182", &fCheckbox182);
		ui_interface->addCheckButton("r198", &fCheckbox198);
		ui_interface->addCheckButton("r214", &fCheckbox214);
		ui_interface->addCheckButton("r230", &fCheckbox230);
		ui_interface->addCheckButton("r246", &fCheckbox247);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 7-->");
		ui_interface->addCheckButton("r  7", &fCheckbox7);
		ui_interface->addCheckButton("r 23", &fCheckbox23);
		ui_interface->addCheckButton("r 39", &fCheckbox39);
		ui_interface->addCheckButton("r 55", &fCheckbox55);
		ui_interface->addCheckButton("r 71", &fCheckbox71);
		ui_interface->addCheckButton("r 87", &fCheckbox87);
		ui_interface->addCheckButton("r103", &fCheckbox103);
		ui_interface->addCheckButton("r119", &fCheckbox119);
		ui_interface->addCheckButton("r135", &fCheckbox137);
		ui_interface->addCheckButton("r151", &fCheckbox151);
		ui_interface->addCheckButton("r167", &fCheckbox167);
		ui_interface->addCheckButton("r183", &fCheckbox183);
		ui_interface->addCheckButton("r199", &fCheckbox199);
		ui_interface->addCheckButton("r215", &fCheckbox215);
		ui_interface->addCheckButton("r231", &fCheckbox231);
		ui_interface->addCheckButton("r247", &fCheckbox248);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 8-->");
		ui_interface->addCheckButton("r  8", &fCheckbox8);
		ui_interface->addCheckButton("r 24", &fCheckbox24);
		ui_interface->addCheckButton("r 40", &fCheckbox40);
		ui_interface->addCheckButton("r 56", &fCheckbox56);
		ui_interface->addCheckButton("r 72", &fCheckbox72);
		ui_interface->addCheckButton("r 88", &fCheckbox88);
		ui_interface->addCheckButton("r104", &fCheckbox104);
		ui_interface->addCheckButton("r120", &fCheckbox120);
		ui_interface->addCheckButton("r136", &fCheckbox138);
		ui_interface->addCheckButton("r152", &fCheckbox152);
		ui_interface->addCheckButton("r168", &fCheckbox168);
		ui_interface->addCheckButton("r184", &fCheckbox184);
		ui_interface->addCheckButton("r200", &fCheckbox200);
		ui_interface->addCheckButton("r216", &fCheckbox216);
		ui_interface->addCheckButton("r232", &fCheckbox232);
		ui_interface->addCheckButton("r248", &fCheckbox249);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 9-->");
		ui_interface->addCheckButton("r  9", &fCheckbox9);
		ui_interface->addCheckButton("r 25", &fCheckbox25);
		ui_interface->addCheckButton("r 41", &fCheckbox41);
		ui_interface->addCheckButton("r 57", &fCheckbox57);
		ui_interface->addCheckButton("r 73", &fCheckbox73);
		ui_interface->addCheckButton("r 89", &fCheckbox89);
		ui_interface->addCheckButton("r105", &fCheckbox105);
		ui_interface->addCheckButton("r121", &fCheckbox121);
		ui_interface->addCheckButton("r137", &fCheckbox139);
		ui_interface->addCheckButton("r153", &fCheckbox153);
		ui_interface->addCheckButton("r169", &fCheckbox169);
		ui_interface->addCheckButton("r185", &fCheckbox185);
		ui_interface->addCheckButton("r201", &fCheckbox201);
		ui_interface->addCheckButton("r217", &fCheckbox217);
		ui_interface->addCheckButton("r233", &fCheckbox233);
		ui_interface->addCheckButton("r249", &fCheckbox250);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del10-->");
		ui_interface->addCheckButton("r 10", &fCheckbox10);
		ui_interface->addCheckButton("r 26", &fCheckbox26);
		ui_interface->addCheckButton("r 42", &fCheckbox42);
		ui_interface->addCheckButton("r 58", &fCheckbox58);
		ui_interface->addCheckButton("r 74", &fCheckbox74);
		ui_interface->addCheckButton("r 90", &fCheckbox90);
		ui_interface->addCheckButton("r106", &fCheckbox106);
		ui_interface->addCheckButton("r122", &fCheckbox122);
		ui_interface->addCheckButton("r138", &fCheckbox140);
		ui_interface->addCheckButton("r154", &fCheckbox154);
		ui_interface->addCheckButton("r170", &fCheckbox170);
		ui_interface->addCheckButton("r186", &fCheckbox186);
		ui_interface->addCheckButton("r202", &fCheckbox202);
		ui_interface->addCheckButton("r218", &fCheckbox218);
		ui_interface->addCheckButton("r234", &fCheckbox234);
		ui_interface->addCheckButton("r250", &fCheckbox251);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del11-->");
		ui_interface->addCheckButton("r 11", &fCheckbox11);
		ui_interface->addCheckButton("r 27", &fCheckbox27);
		ui_interface->addCheckButton("r 43", &fCheckbox43);
		ui_interface->addCheckButton("r 59", &fCheckbox59);
		ui_interface->addCheckButton("r 75", &fCheckbox75);
		ui_interface->addCheckButton("r 91", &fCheckbox91);
		ui_interface->addCheckButton("r107", &fCheckbox107);
		ui_interface->addCheckButton("r123", &fCheckbox123);
		ui_interface->addCheckButton("r139", &fCheckbox129);
		ui_interface->addCheckButton("r155", &fCheckbox155);
		ui_interface->addCheckButton("r171", &fCheckbox171);
		ui_interface->addCheckButton("r187", &fCheckbox187);
		ui_interface->addCheckButton("r203", &fCheckbox203);
		ui_interface->addCheckButton("r219", &fCheckbox219);
		ui_interface->addCheckButton("r235", &fCheckbox235);
		ui_interface->addCheckButton("r251", &fCheckbox252);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del12-->");
		ui_interface->addCheckButton("r 12", &fCheckbox12);
		ui_interface->addCheckButton("r 28", &fCheckbox28);
		ui_interface->addCheckButton("r 44", &fCheckbox44);
		ui_interface->addCheckButton("r 60", &fCheckbox60);
		ui_interface->addCheckButton("r 76", &fCheckbox76);
		ui_interface->addCheckButton("r 92", &fCheckbox92);
		ui_interface->addCheckButton("r108", &fCheckbox108);
		ui_interface->addCheckButton("r124", &fCheckbox124);
		ui_interface->addCheckButton("r140", &fCheckbox128);
		ui_interface->addCheckButton("r156", &fCheckbox156);
		ui_interface->addCheckButton("r172", &fCheckbox172);
		ui_interface->addCheckButton("r188", &fCheckbox188);
		ui_interface->addCheckButton("r204", &fCheckbox204);
		ui_interface->addCheckButton("r220", &fCheckbox220);
		ui_interface->addCheckButton("r236", &fCheckbox236);
		ui_interface->addCheckButton("r252", &fCheckbox253);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del13-->");
		ui_interface->addCheckButton("r 13", &fCheckbox13);
		ui_interface->addCheckButton("r 29", &fCheckbox29);
		ui_interface->addCheckButton("r 45", &fCheckbox45);
		ui_interface->addCheckButton("r 61", &fCheckbox61);
		ui_interface->addCheckButton("r 77", &fCheckbox77);
		ui_interface->addCheckButton("r 93", &fCheckbox93);
		ui_interface->addCheckButton("r109", &fCheckbox109);
		ui_interface->addCheckButton("r125", &fCheckbox125);
		ui_interface->addCheckButton("r141", &fCheckbox141);
		ui_interface->addCheckButton("r157", &fCheckbox157);
		ui_interface->addCheckButton("r173", &fCheckbox173);
		ui_interface->addCheckButton("r189", &fCheckbox189);
		ui_interface->addCheckButton("r205", &fCheckbox205);
		ui_interface->addCheckButton("r221", &fCheckbox221);
		ui_interface->addCheckButton("r237", &fCheckbox237);
		ui_interface->addCheckButton("r253", &fCheckbox254);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del14-->");
		ui_interface->addCheckButton("r 14", &fCheckbox14);
		ui_interface->addCheckButton("r 30", &fCheckbox30);
		ui_interface->addCheckButton("r 46", &fCheckbox46);
		ui_interface->addCheckButton("r 62", &fCheckbox62);
		ui_interface->addCheckButton("r 78", &fCheckbox78);
		ui_interface->addCheckButton("r 94", &fCheckbox94);
		ui_interface->addCheckButton("r110", &fCheckbox110);
		ui_interface->addCheckButton("r126", &fCheckbox126);
		ui_interface->addCheckButton("r142", &fCheckbox142);
		ui_interface->addCheckButton("r158", &fCheckbox158);
		ui_interface->addCheckButton("r174", &fCheckbox174);
		ui_interface->addCheckButton("r190", &fCheckbox190);
		ui_interface->addCheckButton("r206", &fCheckbox206);
		ui_interface->addCheckButton("r222", &fCheckbox222);
		ui_interface->addCheckButton("r238", &fCheckbox238);
		ui_interface->addCheckButton("r254", &fCheckbox255);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del15-->");
		ui_interface->addCheckButton("r 15", &fCheckbox15);
		ui_interface->addCheckButton("r 31", &fCheckbox31);
		ui_interface->addCheckButton("r 47", &fCheckbox47);
		ui_interface->addCheckButton("r 63", &fCheckbox63);
		ui_interface->addCheckButton("r 79", &fCheckbox79);
		ui_interface->addCheckButton("r 95", &fCheckbox95);
		ui_interface->addCheckButton("r111", &fCheckbox111);
		ui_interface->addCheckButton("r127", &fCheckbox127);
		ui_interface->addCheckButton("r143", &fCheckbox143);
		ui_interface->addCheckButton("r159", &fCheckbox159);
		ui_interface->addCheckButton("r175", &fCheckbox175);
		ui_interface->addCheckButton("r191", &fCheckbox191);
		ui_interface->addCheckButton("r207", &fCheckbox207);
		ui_interface->addCheckButton("r223", &fCheckbox223);
		ui_interface->addCheckButton("r239", &fCheckbox239);
		ui_interface->addCheckButton("r255", &fCheckbox240);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("SpatializationMatrix");
		ui_interface->openVerticalBox("Sig 0-->");
		ui_interface->addCheckButton("sp  0", &fCheckbox336);
		ui_interface->addCheckButton("sp 17", &fCheckbox343);
		ui_interface->addCheckButton("sp 34", &fCheckbox360);
		ui_interface->addCheckButton("sp 51", &fCheckbox377);
		ui_interface->addCheckButton("sp 68", &fCheckbox394);
		ui_interface->addCheckButton("sp 85", &fCheckbox411);
		ui_interface->addCheckButton("sp102", &fCheckbox428);
		ui_interface->addCheckButton("sp119", &fCheckbox339);
		ui_interface->addCheckButton("sp136", &fCheckbox340);
		ui_interface->addCheckButton("sp153", &fCheckbox338);
		ui_interface->addCheckButton("sp170", &fCheckbox337);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 1-->");
		ui_interface->addCheckButton("sp  1", &fCheckbox326);
		ui_interface->addCheckButton("sp 18", &fCheckbox344);
		ui_interface->addCheckButton("sp 35", &fCheckbox361);
		ui_interface->addCheckButton("sp 52", &fCheckbox378);
		ui_interface->addCheckButton("sp 69", &fCheckbox395);
		ui_interface->addCheckButton("sp 86", &fCheckbox412);
		ui_interface->addCheckButton("sp103", &fCheckbox429);
		ui_interface->addCheckButton("sp120", &fCheckbox329);
		ui_interface->addCheckButton("sp137", &fCheckbox330);
		ui_interface->addCheckButton("sp154", &fCheckbox328);
		ui_interface->addCheckButton("sp171", &fCheckbox327);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 2-->");
		ui_interface->addCheckButton("sp  2", &fCheckbox321);
		ui_interface->addCheckButton("sp 19", &fCheckbox345);
		ui_interface->addCheckButton("sp 36", &fCheckbox362);
		ui_interface->addCheckButton("sp 53", &fCheckbox379);
		ui_interface->addCheckButton("sp 70", &fCheckbox396);
		ui_interface->addCheckButton("sp 87", &fCheckbox413);
		ui_interface->addCheckButton("sp104", &fCheckbox430);
		ui_interface->addCheckButton("sp121", &fCheckbox324);
		ui_interface->addCheckButton("sp138", &fCheckbox325);
		ui_interface->addCheckButton("sp155", &fCheckbox323);
		ui_interface->addCheckButton("sp172", &fCheckbox322);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 3-->");
		ui_interface->addCheckButton("sp  3", &fCheckbox316);
		ui_interface->addCheckButton("sp 20", &fCheckbox346);
		ui_interface->addCheckButton("sp 37", &fCheckbox363);
		ui_interface->addCheckButton("sp 54", &fCheckbox380);
		ui_interface->addCheckButton("sp 71", &fCheckbox397);
		ui_interface->addCheckButton("sp 88", &fCheckbox414);
		ui_interface->addCheckButton("sp105", &fCheckbox431);
		ui_interface->addCheckButton("sp122", &fCheckbox319);
		ui_interface->addCheckButton("sp139", &fCheckbox320);
		ui_interface->addCheckButton("sp156", &fCheckbox318);
		ui_interface->addCheckButton("sp173", &fCheckbox317);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 4-->");
		ui_interface->addCheckButton("sp  4", &fCheckbox311);
		ui_interface->addCheckButton("sp 21", &fCheckbox347);
		ui_interface->addCheckButton("sp 38", &fCheckbox364);
		ui_interface->addCheckButton("sp 55", &fCheckbox381);
		ui_interface->addCheckButton("sp 72", &fCheckbox398);
		ui_interface->addCheckButton("sp 89", &fCheckbox415);
		ui_interface->addCheckButton("sp106", &fCheckbox432);
		ui_interface->addCheckButton("sp123", &fCheckbox314);
		ui_interface->addCheckButton("sp140", &fCheckbox315);
		ui_interface->addCheckButton("sp157", &fCheckbox313);
		ui_interface->addCheckButton("sp174", &fCheckbox312);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 5-->");
		ui_interface->addCheckButton("sp  5", &fCheckbox306);
		ui_interface->addCheckButton("sp 22", &fCheckbox348);
		ui_interface->addCheckButton("sp 39", &fCheckbox365);
		ui_interface->addCheckButton("sp 56", &fCheckbox382);
		ui_interface->addCheckButton("sp 73", &fCheckbox399);
		ui_interface->addCheckButton("sp 90", &fCheckbox416);
		ui_interface->addCheckButton("sp107", &fCheckbox433);
		ui_interface->addCheckButton("sp124", &fCheckbox309);
		ui_interface->addCheckButton("sp141", &fCheckbox310);
		ui_interface->addCheckButton("sp158", &fCheckbox308);
		ui_interface->addCheckButton("sp175", &fCheckbox307);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 6-->");
		ui_interface->addCheckButton("sp  6", &fCheckbox301);
		ui_interface->addCheckButton("sp 23", &fCheckbox349);
		ui_interface->addCheckButton("sp 40", &fCheckbox366);
		ui_interface->addCheckButton("sp 57", &fCheckbox383);
		ui_interface->addCheckButton("sp 74", &fCheckbox400);
		ui_interface->addCheckButton("sp 91", &fCheckbox417);
		ui_interface->addCheckButton("sp108", &fCheckbox434);
		ui_interface->addCheckButton("sp125", &fCheckbox304);
		ui_interface->addCheckButton("sp142", &fCheckbox305);
		ui_interface->addCheckButton("sp159", &fCheckbox303);
		ui_interface->addCheckButton("sp176", &fCheckbox302);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 7-->");
		ui_interface->addCheckButton("sp  7", &fCheckbox296);
		ui_interface->addCheckButton("sp 24", &fCheckbox350);
		ui_interface->addCheckButton("sp 41", &fCheckbox367);
		ui_interface->addCheckButton("sp 58", &fCheckbox384);
		ui_interface->addCheckButton("sp 75", &fCheckbox401);
		ui_interface->addCheckButton("sp 92", &fCheckbox418);
		ui_interface->addCheckButton("sp109", &fCheckbox435);
		ui_interface->addCheckButton("sp126", &fCheckbox299);
		ui_interface->addCheckButton("sp143", &fCheckbox300);
		ui_interface->addCheckButton("sp160", &fCheckbox298);
		ui_interface->addCheckButton("sp177", &fCheckbox297);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 8-->");
		ui_interface->addCheckButton("sp  8", &fCheckbox291);
		ui_interface->addCheckButton("sp 25", &fCheckbox351);
		ui_interface->addCheckButton("sp 42", &fCheckbox368);
		ui_interface->addCheckButton("sp 59", &fCheckbox385);
		ui_interface->addCheckButton("sp 76", &fCheckbox402);
		ui_interface->addCheckButton("sp 93", &fCheckbox419);
		ui_interface->addCheckButton("sp110", &fCheckbox436);
		ui_interface->addCheckButton("sp127", &fCheckbox294);
		ui_interface->addCheckButton("sp144", &fCheckbox295);
		ui_interface->addCheckButton("sp161", &fCheckbox293);
		ui_interface->addCheckButton("sp178", &fCheckbox292);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 9-->");
		ui_interface->addCheckButton("sp  9", &fCheckbox286);
		ui_interface->addCheckButton("sp 26", &fCheckbox352);
		ui_interface->addCheckButton("sp 43", &fCheckbox369);
		ui_interface->addCheckButton("sp 60", &fCheckbox386);
		ui_interface->addCheckButton("sp 77", &fCheckbox403);
		ui_interface->addCheckButton("sp 94", &fCheckbox420);
		ui_interface->addCheckButton("sp111", &fCheckbox437);
		ui_interface->addCheckButton("sp128", &fCheckbox289);
		ui_interface->addCheckButton("sp145", &fCheckbox290);
		ui_interface->addCheckButton("sp162", &fCheckbox288);
		ui_interface->addCheckButton("sp179", &fCheckbox287);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig10-->");
		ui_interface->addCheckButton("sp 10", &fCheckbox281);
		ui_interface->addCheckButton("sp 27", &fCheckbox353);
		ui_interface->addCheckButton("sp 44", &fCheckbox370);
		ui_interface->addCheckButton("sp 61", &fCheckbox387);
		ui_interface->addCheckButton("sp 78", &fCheckbox404);
		ui_interface->addCheckButton("sp 95", &fCheckbox421);
		ui_interface->addCheckButton("sp112", &fCheckbox438);
		ui_interface->addCheckButton("sp129", &fCheckbox284);
		ui_interface->addCheckButton("sp146", &fCheckbox285);
		ui_interface->addCheckButton("sp163", &fCheckbox283);
		ui_interface->addCheckButton("sp180", &fCheckbox282);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig11-->");
		ui_interface->addCheckButton("sp 11", &fCheckbox276);
		ui_interface->addCheckButton("sp 28", &fCheckbox354);
		ui_interface->addCheckButton("sp 45", &fCheckbox371);
		ui_interface->addCheckButton("sp 62", &fCheckbox388);
		ui_interface->addCheckButton("sp 79", &fCheckbox405);
		ui_interface->addCheckButton("sp 96", &fCheckbox422);
		ui_interface->addCheckButton("sp113", &fCheckbox439);
		ui_interface->addCheckButton("sp130", &fCheckbox279);
		ui_interface->addCheckButton("sp147", &fCheckbox280);
		ui_interface->addCheckButton("sp164", &fCheckbox278);
		ui_interface->addCheckButton("sp181", &fCheckbox277);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig12-->");
		ui_interface->addCheckButton("sp 12", &fCheckbox271);
		ui_interface->addCheckButton("sp 29", &fCheckbox355);
		ui_interface->addCheckButton("sp 46", &fCheckbox372);
		ui_interface->addCheckButton("sp 63", &fCheckbox389);
		ui_interface->addCheckButton("sp 80", &fCheckbox406);
		ui_interface->addCheckButton("sp 97", &fCheckbox423);
		ui_interface->addCheckButton("sp114", &fCheckbox440);
		ui_interface->addCheckButton("sp131", &fCheckbox274);
		ui_interface->addCheckButton("sp148", &fCheckbox275);
		ui_interface->addCheckButton("sp165", &fCheckbox273);
		ui_interface->addCheckButton("sp182", &fCheckbox272);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig13-->");
		ui_interface->addCheckButton("sp 13", &fCheckbox266);
		ui_interface->addCheckButton("sp 30", &fCheckbox356);
		ui_interface->addCheckButton("sp 47", &fCheckbox373);
		ui_interface->addCheckButton("sp 64", &fCheckbox390);
		ui_interface->addCheckButton("sp 81", &fCheckbox407);
		ui_interface->addCheckButton("sp 98", &fCheckbox424);
		ui_interface->addCheckButton("sp115", &fCheckbox441);
		ui_interface->addCheckButton("sp132", &fCheckbox269);
		ui_interface->addCheckButton("sp149", &fCheckbox270);
		ui_interface->addCheckButton("sp166", &fCheckbox268);
		ui_interface->addCheckButton("sp183", &fCheckbox267);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig14-->");
		ui_interface->addCheckButton("sp 14", &fCheckbox261);
		ui_interface->addCheckButton("sp 31", &fCheckbox357);
		ui_interface->addCheckButton("sp 48", &fCheckbox374);
		ui_interface->addCheckButton("sp 65", &fCheckbox391);
		ui_interface->addCheckButton("sp 82", &fCheckbox408);
		ui_interface->addCheckButton("sp 99", &fCheckbox425);
		ui_interface->addCheckButton("sp116", &fCheckbox442);
		ui_interface->addCheckButton("sp133", &fCheckbox264);
		ui_interface->addCheckButton("sp150", &fCheckbox265);
		ui_interface->addCheckButton("sp167", &fCheckbox263);
		ui_interface->addCheckButton("sp184", &fCheckbox262);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig15-->");
		ui_interface->addCheckButton("sp 15", &fCheckbox256);
		ui_interface->addCheckButton("sp 32", &fCheckbox358);
		ui_interface->addCheckButton("sp 49", &fCheckbox375);
		ui_interface->addCheckButton("sp 66", &fCheckbox392);
		ui_interface->addCheckButton("sp 83", &fCheckbox409);
		ui_interface->addCheckButton("sp100", &fCheckbox426);
		ui_interface->addCheckButton("sp117", &fCheckbox443);
		ui_interface->addCheckButton("sp134", &fCheckbox259);
		ui_interface->addCheckButton("sp151", &fCheckbox260);
		ui_interface->addCheckButton("sp168", &fCheckbox258);
		ui_interface->addCheckButton("sp185", &fCheckbox257);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig16-->");
		ui_interface->addCheckButton("sp 16", &fCheckbox331);
		ui_interface->addCheckButton("sp 33", &fCheckbox342);
		ui_interface->addCheckButton("sp 50", &fCheckbox359);
		ui_interface->addCheckButton("sp 67", &fCheckbox376);
		ui_interface->addCheckButton("sp 84", &fCheckbox393);
		ui_interface->addCheckButton("sp101", &fCheckbox410);
		ui_interface->addCheckButton("sp118", &fCheckbox427);
		ui_interface->addCheckButton("sp135", &fCheckbox334);
		ui_interface->addCheckButton("sp152", &fCheckbox335);
		ui_interface->addCheckButton("sp169", &fCheckbox333);
		ui_interface->addCheckButton("sp186", &fCheckbox332);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("RandomEnv");
		ui_interface->addNumEntry("renv_freq", &fEntry0, 10.0, 0.01, 100.0, 0.01);
		ui_interface->addHorizontalSlider("renv_short", &fHslider106, 0.5, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("renv_trim", &fHslider105, 0.0, -127.0, 18.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("decoder");
		ui_interface->openVerticalBox("angles");
		ui_interface->declare(&fHslider104, "unit", "deg");
		ui_interface->addHorizontalSlider("a0", &fHslider104, 0.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider115, "unit", "deg");
		ui_interface->addHorizontalSlider("a1", &fHslider115, 45.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider116, "unit", "deg");
		ui_interface->addHorizontalSlider("a2", &fHslider116, 90.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider117, "unit", "deg");
		ui_interface->addHorizontalSlider("a3", &fHslider117, 135.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider118, "unit", "deg");
		ui_interface->addHorizontalSlider("a4", &fHslider118, 180.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider119, "unit", "deg");
		ui_interface->addHorizontalSlider("a5", &fHslider119, 225.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider120, "unit", "deg");
		ui_interface->addHorizontalSlider("a6", &fHslider120, 270.0, -360.0, 360.0, 1.0);
		ui_interface->declare(&fHslider121, "unit", "deg");
		ui_interface->addHorizontalSlider("a7", &fHslider121, 315.0, -360.0, 360.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("global");
		ui_interface->declare(&fHslider103, "unit", "deg");
		ui_interface->addHorizontalSlider("angularoffset", &fHslider103, 0.0, -180.0, 180.0, 1.0);
		ui_interface->addCheckButton("directangles", &fCheckbox341);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		double fSlow0 = std::exp((0.0 - (fConst1 / double(fHslider1))));
		double fSlow1 = (1.0 - fSlow0);
		double fSlow2 = (double(fHslider0) * fSlow1);
		double fSlow3 = double(fHslider2);
		double fSlow4 = (1.0 - (0.75 * fSlow3));
		double fSlow5 = (fSlow4 * double(fCheckbox0));
		double fSlow6 = (double(fHslider3) * fSlow1);
		double fSlow7 = double(fHslider4);
		double fSlow8 = (1.0 - (0.75 * fSlow7));
		double fSlow9 = (fSlow8 * double(fCheckbox1));
		double fSlow10 = (double(fHslider5) * fSlow1);
		double fSlow11 = double(fHslider6);
		double fSlow12 = (1.0 - (0.75 * fSlow11));
		double fSlow13 = (fSlow12 * double(fCheckbox2));
		double fSlow14 = (double(fHslider7) * fSlow1);
		double fSlow15 = double(fHslider8);
		double fSlow16 = (1.0 - (0.75 * fSlow15));
		double fSlow17 = (fSlow16 * double(fCheckbox3));
		double fSlow18 = (double(fHslider9) * fSlow1);
		double fSlow19 = double(fHslider10);
		double fSlow20 = (1.0 - (0.75 * fSlow19));
		double fSlow21 = (fSlow20 * double(fCheckbox4));
		double fSlow22 = (double(fHslider11) * fSlow1);
		double fSlow23 = double(fHslider12);
		double fSlow24 = (1.0 - (0.75 * fSlow23));
		double fSlow25 = (fSlow24 * double(fCheckbox5));
		double fSlow26 = (double(fHslider13) * fSlow1);
		double fSlow27 = double(fHslider14);
		double fSlow28 = (1.0 - (0.75 * fSlow27));
		double fSlow29 = (fSlow28 * double(fCheckbox6));
		double fSlow30 = (double(fHslider15) * fSlow1);
		double fSlow31 = double(fHslider16);
		double fSlow32 = (1.0 - (0.75 * fSlow31));
		double fSlow33 = (fSlow32 * double(fCheckbox7));
		double fSlow34 = (double(fHslider17) * fSlow1);
		double fSlow35 = double(fHslider18);
		double fSlow36 = (1.0 - (0.75 * fSlow35));
		double fSlow37 = (fSlow36 * double(fCheckbox8));
		double fSlow38 = (double(fHslider19) * fSlow1);
		double fSlow39 = double(fHslider20);
		double fSlow40 = (1.0 - (0.75 * fSlow39));
		double fSlow41 = (fSlow40 * double(fCheckbox9));
		double fSlow42 = (double(fHslider21) * fSlow1);
		double fSlow43 = double(fHslider22);
		double fSlow44 = (1.0 - (0.75 * fSlow43));
		double fSlow45 = (fSlow44 * double(fCheckbox10));
		double fSlow46 = (double(fHslider23) * fSlow1);
		double fSlow47 = double(fHslider24);
		double fSlow48 = (1.0 - (0.75 * fSlow47));
		double fSlow49 = (fSlow48 * double(fCheckbox11));
		double fSlow50 = (double(fHslider25) * fSlow1);
		double fSlow51 = double(fHslider26);
		double fSlow52 = (1.0 - (0.75 * fSlow51));
		double fSlow53 = (fSlow52 * double(fCheckbox12));
		double fSlow54 = (double(fHslider27) * fSlow1);
		double fSlow55 = double(fHslider28);
		double fSlow56 = (1.0 - (0.75 * fSlow55));
		double fSlow57 = (fSlow56 * double(fCheckbox13));
		double fSlow58 = (double(fHslider29) * fSlow1);
		double fSlow59 = double(fHslider30);
		double fSlow60 = (1.0 - (0.75 * fSlow59));
		double fSlow61 = (fSlow60 * double(fCheckbox14));
		double fSlow62 = (double(fHslider31) * fSlow1);
		double fSlow63 = double(fHslider32);
		double fSlow64 = (1.0 - (0.75 * fSlow63));
		double fSlow65 = (fSlow64 * double(fCheckbox15));
		double fSlow66 = (double(fHslider33) * fSlow1);
		double fSlow67 = (double(fHslider34) * fSlow1);
		double fSlow68 = (double(fHslider35) * fSlow1);
		double fSlow69 = double(fHslider36);
		int iSlow70 = int((fConst3 * (fSlow69 * double(fHslider37))));
		double fSlow71 = double(fHslider38);
		double fSlow72 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider39)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow73 = double(fHslider40);
		double fSlow74 = ((fSlow73 < 127.0)?fSlow73:127.0);
		double fSlow75 = ((fSlow74 < 1.0)?0.0:(4096.0 * std::pow(1.0717699999999999, (fSlow74 + -127.0))));
		double fSlow76 = (1.0 - fSlow3);
		double fSlow77 = (fSlow4 * double(fCheckbox16));
		double fSlow78 = (fSlow8 * double(fCheckbox17));
		double fSlow79 = (fSlow12 * double(fCheckbox18));
		double fSlow80 = (fSlow16 * double(fCheckbox19));
		double fSlow81 = (fSlow20 * double(fCheckbox20));
		double fSlow82 = (fSlow24 * double(fCheckbox21));
		double fSlow83 = (fSlow28 * double(fCheckbox22));
		double fSlow84 = (fSlow32 * double(fCheckbox23));
		double fSlow85 = (fSlow36 * double(fCheckbox24));
		double fSlow86 = (fSlow40 * double(fCheckbox25));
		double fSlow87 = (fSlow44 * double(fCheckbox26));
		double fSlow88 = (fSlow48 * double(fCheckbox27));
		double fSlow89 = (fSlow52 * double(fCheckbox28));
		double fSlow90 = (fSlow56 * double(fCheckbox29));
		double fSlow91 = (fSlow60 * double(fCheckbox30));
		double fSlow92 = (fSlow64 * double(fCheckbox31));
		double fSlow93 = (double(fHslider41) * fSlow1);
		int iSlow94 = int((fConst3 * (fSlow69 * double(fHslider42))));
		double fSlow95 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider43)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow96 = (1.0 - fSlow7);
		double fSlow97 = (fSlow4 * double(fCheckbox32));
		double fSlow98 = (fSlow8 * double(fCheckbox33));
		double fSlow99 = (fSlow12 * double(fCheckbox34));
		double fSlow100 = (fSlow16 * double(fCheckbox35));
		double fSlow101 = (fSlow20 * double(fCheckbox36));
		double fSlow102 = (fSlow24 * double(fCheckbox37));
		double fSlow103 = (fSlow28 * double(fCheckbox38));
		double fSlow104 = (fSlow32 * double(fCheckbox39));
		double fSlow105 = (fSlow36 * double(fCheckbox40));
		double fSlow106 = (fSlow40 * double(fCheckbox41));
		double fSlow107 = (fSlow44 * double(fCheckbox42));
		double fSlow108 = (fSlow48 * double(fCheckbox43));
		double fSlow109 = (fSlow52 * double(fCheckbox44));
		double fSlow110 = (fSlow56 * double(fCheckbox45));
		double fSlow111 = (fSlow60 * double(fCheckbox46));
		double fSlow112 = (fSlow64 * double(fCheckbox47));
		double fSlow113 = (double(fHslider44) * fSlow1);
		int iSlow114 = int((fConst3 * (fSlow69 * double(fHslider45))));
		double fSlow115 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider46)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow116 = (1.0 - fSlow11);
		double fSlow117 = (fSlow4 * double(fCheckbox48));
		double fSlow118 = (fSlow8 * double(fCheckbox49));
		double fSlow119 = (fSlow12 * double(fCheckbox50));
		double fSlow120 = (fSlow16 * double(fCheckbox51));
		double fSlow121 = (fSlow20 * double(fCheckbox52));
		double fSlow122 = (fSlow24 * double(fCheckbox53));
		double fSlow123 = (fSlow28 * double(fCheckbox54));
		double fSlow124 = (fSlow32 * double(fCheckbox55));
		double fSlow125 = (fSlow36 * double(fCheckbox56));
		double fSlow126 = (fSlow40 * double(fCheckbox57));
		double fSlow127 = (fSlow44 * double(fCheckbox58));
		double fSlow128 = (fSlow48 * double(fCheckbox59));
		double fSlow129 = (fSlow52 * double(fCheckbox60));
		double fSlow130 = (fSlow56 * double(fCheckbox61));
		double fSlow131 = (fSlow60 * double(fCheckbox62));
		double fSlow132 = (fSlow64 * double(fCheckbox63));
		double fSlow133 = (double(fHslider47) * fSlow1);
		int iSlow134 = int((fConst3 * (fSlow69 * double(fHslider48))));
		double fSlow135 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider49)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow136 = (1.0 - fSlow15);
		double fSlow137 = (fSlow4 * double(fCheckbox64));
		double fSlow138 = (fSlow8 * double(fCheckbox65));
		double fSlow139 = (fSlow12 * double(fCheckbox66));
		double fSlow140 = (fSlow16 * double(fCheckbox67));
		double fSlow141 = (fSlow20 * double(fCheckbox68));
		double fSlow142 = (fSlow24 * double(fCheckbox69));
		double fSlow143 = (fSlow28 * double(fCheckbox70));
		double fSlow144 = (fSlow32 * double(fCheckbox71));
		double fSlow145 = (fSlow36 * double(fCheckbox72));
		double fSlow146 = (fSlow40 * double(fCheckbox73));
		double fSlow147 = (fSlow44 * double(fCheckbox74));
		double fSlow148 = (fSlow48 * double(fCheckbox75));
		double fSlow149 = (fSlow52 * double(fCheckbox76));
		double fSlow150 = (fSlow56 * double(fCheckbox77));
		double fSlow151 = (fSlow60 * double(fCheckbox78));
		double fSlow152 = (fSlow64 * double(fCheckbox79));
		double fSlow153 = (double(fHslider50) * fSlow1);
		int iSlow154 = int((fConst3 * (fSlow69 * double(fHslider51))));
		double fSlow155 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider52)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow156 = (1.0 - fSlow19);
		double fSlow157 = (fSlow4 * double(fCheckbox80));
		double fSlow158 = (fSlow8 * double(fCheckbox81));
		double fSlow159 = (fSlow12 * double(fCheckbox82));
		double fSlow160 = (fSlow16 * double(fCheckbox83));
		double fSlow161 = (fSlow20 * double(fCheckbox84));
		double fSlow162 = (fSlow24 * double(fCheckbox85));
		double fSlow163 = (fSlow28 * double(fCheckbox86));
		double fSlow164 = (fSlow32 * double(fCheckbox87));
		double fSlow165 = (fSlow36 * double(fCheckbox88));
		double fSlow166 = (fSlow40 * double(fCheckbox89));
		double fSlow167 = (fSlow44 * double(fCheckbox90));
		double fSlow168 = (fSlow48 * double(fCheckbox91));
		double fSlow169 = (fSlow52 * double(fCheckbox92));
		double fSlow170 = (fSlow56 * double(fCheckbox93));
		double fSlow171 = (fSlow60 * double(fCheckbox94));
		double fSlow172 = (fSlow64 * double(fCheckbox95));
		double fSlow173 = (double(fHslider53) * fSlow1);
		int iSlow174 = int((fConst3 * (fSlow69 * double(fHslider54))));
		double fSlow175 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider55)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow176 = (1.0 - fSlow23);
		double fSlow177 = (fSlow4 * double(fCheckbox96));
		double fSlow178 = (fSlow8 * double(fCheckbox97));
		double fSlow179 = (fSlow12 * double(fCheckbox98));
		double fSlow180 = (fSlow16 * double(fCheckbox99));
		double fSlow181 = (fSlow20 * double(fCheckbox100));
		double fSlow182 = (fSlow24 * double(fCheckbox101));
		double fSlow183 = (fSlow28 * double(fCheckbox102));
		double fSlow184 = (fSlow32 * double(fCheckbox103));
		double fSlow185 = (fSlow36 * double(fCheckbox104));
		double fSlow186 = (fSlow40 * double(fCheckbox105));
		double fSlow187 = (fSlow44 * double(fCheckbox106));
		double fSlow188 = (fSlow48 * double(fCheckbox107));
		double fSlow189 = (fSlow52 * double(fCheckbox108));
		double fSlow190 = (fSlow56 * double(fCheckbox109));
		double fSlow191 = (fSlow60 * double(fCheckbox110));
		double fSlow192 = (fSlow64 * double(fCheckbox111));
		double fSlow193 = (double(fHslider56) * fSlow1);
		int iSlow194 = int((fConst3 * (fSlow69 * double(fHslider57))));
		double fSlow195 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider58)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow196 = (1.0 - fSlow27);
		double fSlow197 = (fSlow4 * double(fCheckbox112));
		double fSlow198 = (fSlow8 * double(fCheckbox113));
		double fSlow199 = (fSlow12 * double(fCheckbox114));
		double fSlow200 = (fSlow16 * double(fCheckbox115));
		double fSlow201 = (fSlow20 * double(fCheckbox116));
		double fSlow202 = (fSlow24 * double(fCheckbox117));
		double fSlow203 = (fSlow28 * double(fCheckbox118));
		double fSlow204 = (fSlow32 * double(fCheckbox119));
		double fSlow205 = (fSlow36 * double(fCheckbox120));
		double fSlow206 = (fSlow40 * double(fCheckbox121));
		double fSlow207 = (fSlow44 * double(fCheckbox122));
		double fSlow208 = (fSlow48 * double(fCheckbox123));
		double fSlow209 = (fSlow52 * double(fCheckbox124));
		double fSlow210 = (fSlow56 * double(fCheckbox125));
		double fSlow211 = (fSlow60 * double(fCheckbox126));
		double fSlow212 = (fSlow64 * double(fCheckbox127));
		double fSlow213 = (double(fHslider59) * fSlow1);
		int iSlow214 = int((fConst3 * (fSlow69 * double(fHslider60))));
		double fSlow215 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider61)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow216 = (1.0 - fSlow31);
		double fSlow217 = (fSlow52 * double(fCheckbox128));
		double fSlow218 = (fSlow48 * double(fCheckbox129));
		double fSlow219 = (fSlow4 * double(fCheckbox130));
		double fSlow220 = (fSlow8 * double(fCheckbox131));
		double fSlow221 = (fSlow12 * double(fCheckbox132));
		double fSlow222 = (fSlow16 * double(fCheckbox133));
		double fSlow223 = (fSlow20 * double(fCheckbox134));
		double fSlow224 = (fSlow24 * double(fCheckbox135));
		double fSlow225 = (fSlow28 * double(fCheckbox136));
		double fSlow226 = (fSlow32 * double(fCheckbox137));
		double fSlow227 = (fSlow36 * double(fCheckbox138));
		double fSlow228 = (fSlow40 * double(fCheckbox139));
		double fSlow229 = (fSlow44 * double(fCheckbox140));
		double fSlow230 = (fSlow56 * double(fCheckbox141));
		double fSlow231 = (fSlow60 * double(fCheckbox142));
		double fSlow232 = (fSlow64 * double(fCheckbox143));
		double fSlow233 = (double(fHslider62) * fSlow1);
		int iSlow234 = int((fConst3 * (fSlow69 * double(fHslider63))));
		double fSlow235 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider64)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow236 = (1.0 - fSlow35);
		double fSlow237 = (fSlow4 * double(fCheckbox144));
		double fSlow238 = (fSlow8 * double(fCheckbox145));
		double fSlow239 = (fSlow12 * double(fCheckbox146));
		double fSlow240 = (fSlow16 * double(fCheckbox147));
		double fSlow241 = (fSlow20 * double(fCheckbox148));
		double fSlow242 = (fSlow24 * double(fCheckbox149));
		double fSlow243 = (fSlow28 * double(fCheckbox150));
		double fSlow244 = (fSlow32 * double(fCheckbox151));
		double fSlow245 = (fSlow36 * double(fCheckbox152));
		double fSlow246 = (fSlow40 * double(fCheckbox153));
		double fSlow247 = (fSlow44 * double(fCheckbox154));
		double fSlow248 = (fSlow48 * double(fCheckbox155));
		double fSlow249 = (fSlow52 * double(fCheckbox156));
		double fSlow250 = (fSlow56 * double(fCheckbox157));
		double fSlow251 = (fSlow60 * double(fCheckbox158));
		double fSlow252 = (fSlow64 * double(fCheckbox159));
		double fSlow253 = (double(fHslider65) * fSlow1);
		int iSlow254 = int((fConst3 * (fSlow69 * double(fHslider66))));
		double fSlow255 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider67)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow256 = (1.0 - fSlow39);
		double fSlow257 = (fSlow4 * double(fCheckbox160));
		double fSlow258 = (fSlow8 * double(fCheckbox161));
		double fSlow259 = (fSlow12 * double(fCheckbox162));
		double fSlow260 = (fSlow16 * double(fCheckbox163));
		double fSlow261 = (fSlow20 * double(fCheckbox164));
		double fSlow262 = (fSlow24 * double(fCheckbox165));
		double fSlow263 = (fSlow28 * double(fCheckbox166));
		double fSlow264 = (fSlow32 * double(fCheckbox167));
		double fSlow265 = (fSlow36 * double(fCheckbox168));
		double fSlow266 = (fSlow40 * double(fCheckbox169));
		double fSlow267 = (fSlow44 * double(fCheckbox170));
		double fSlow268 = (fSlow48 * double(fCheckbox171));
		double fSlow269 = (fSlow52 * double(fCheckbox172));
		double fSlow270 = (fSlow56 * double(fCheckbox173));
		double fSlow271 = (fSlow60 * double(fCheckbox174));
		double fSlow272 = (fSlow64 * double(fCheckbox175));
		double fSlow273 = (double(fHslider68) * fSlow1);
		int iSlow274 = int((fConst3 * (fSlow69 * double(fHslider69))));
		double fSlow275 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider70)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow276 = (1.0 - fSlow43);
		double fSlow277 = (fSlow4 * double(fCheckbox176));
		double fSlow278 = (fSlow8 * double(fCheckbox177));
		double fSlow279 = (fSlow12 * double(fCheckbox178));
		double fSlow280 = (fSlow16 * double(fCheckbox179));
		double fSlow281 = (fSlow20 * double(fCheckbox180));
		double fSlow282 = (fSlow24 * double(fCheckbox181));
		double fSlow283 = (fSlow28 * double(fCheckbox182));
		double fSlow284 = (fSlow32 * double(fCheckbox183));
		double fSlow285 = (fSlow36 * double(fCheckbox184));
		double fSlow286 = (fSlow40 * double(fCheckbox185));
		double fSlow287 = (fSlow44 * double(fCheckbox186));
		double fSlow288 = (fSlow48 * double(fCheckbox187));
		double fSlow289 = (fSlow52 * double(fCheckbox188));
		double fSlow290 = (fSlow56 * double(fCheckbox189));
		double fSlow291 = (fSlow60 * double(fCheckbox190));
		double fSlow292 = (fSlow64 * double(fCheckbox191));
		double fSlow293 = (double(fHslider71) * fSlow1);
		int iSlow294 = int((fConst3 * (fSlow69 * double(fHslider72))));
		double fSlow295 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider73)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow296 = (1.0 - fSlow47);
		double fSlow297 = (fSlow4 * double(fCheckbox192));
		double fSlow298 = (fSlow8 * double(fCheckbox193));
		double fSlow299 = (fSlow12 * double(fCheckbox194));
		double fSlow300 = (fSlow16 * double(fCheckbox195));
		double fSlow301 = (fSlow20 * double(fCheckbox196));
		double fSlow302 = (fSlow24 * double(fCheckbox197));
		double fSlow303 = (fSlow28 * double(fCheckbox198));
		double fSlow304 = (fSlow32 * double(fCheckbox199));
		double fSlow305 = (fSlow36 * double(fCheckbox200));
		double fSlow306 = (fSlow40 * double(fCheckbox201));
		double fSlow307 = (fSlow44 * double(fCheckbox202));
		double fSlow308 = (fSlow48 * double(fCheckbox203));
		double fSlow309 = (fSlow52 * double(fCheckbox204));
		double fSlow310 = (fSlow56 * double(fCheckbox205));
		double fSlow311 = (fSlow60 * double(fCheckbox206));
		double fSlow312 = (fSlow64 * double(fCheckbox207));
		double fSlow313 = (double(fHslider74) * fSlow1);
		int iSlow314 = int((fConst3 * (fSlow69 * double(fHslider75))));
		double fSlow315 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider76)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow316 = (1.0 - fSlow51);
		double fSlow317 = (fSlow4 * double(fCheckbox208));
		double fSlow318 = (fSlow8 * double(fCheckbox209));
		double fSlow319 = (fSlow12 * double(fCheckbox210));
		double fSlow320 = (fSlow16 * double(fCheckbox211));
		double fSlow321 = (fSlow20 * double(fCheckbox212));
		double fSlow322 = (fSlow24 * double(fCheckbox213));
		double fSlow323 = (fSlow28 * double(fCheckbox214));
		double fSlow324 = (fSlow32 * double(fCheckbox215));
		double fSlow325 = (fSlow36 * double(fCheckbox216));
		double fSlow326 = (fSlow40 * double(fCheckbox217));
		double fSlow327 = (fSlow44 * double(fCheckbox218));
		double fSlow328 = (fSlow48 * double(fCheckbox219));
		double fSlow329 = (fSlow52 * double(fCheckbox220));
		double fSlow330 = (fSlow56 * double(fCheckbox221));
		double fSlow331 = (fSlow60 * double(fCheckbox222));
		double fSlow332 = (fSlow64 * double(fCheckbox223));
		double fSlow333 = (double(fHslider77) * fSlow1);
		int iSlow334 = int((fConst3 * (fSlow69 * double(fHslider78))));
		double fSlow335 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider79)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow336 = (1.0 - fSlow55);
		double fSlow337 = (fSlow4 * double(fCheckbox224));
		double fSlow338 = (fSlow8 * double(fCheckbox225));
		double fSlow339 = (fSlow12 * double(fCheckbox226));
		double fSlow340 = (fSlow16 * double(fCheckbox227));
		double fSlow341 = (fSlow20 * double(fCheckbox228));
		double fSlow342 = (fSlow24 * double(fCheckbox229));
		double fSlow343 = (fSlow28 * double(fCheckbox230));
		double fSlow344 = (fSlow32 * double(fCheckbox231));
		double fSlow345 = (fSlow36 * double(fCheckbox232));
		double fSlow346 = (fSlow40 * double(fCheckbox233));
		double fSlow347 = (fSlow44 * double(fCheckbox234));
		double fSlow348 = (fSlow48 * double(fCheckbox235));
		double fSlow349 = (fSlow52 * double(fCheckbox236));
		double fSlow350 = (fSlow56 * double(fCheckbox237));
		double fSlow351 = (fSlow60 * double(fCheckbox238));
		double fSlow352 = (fSlow64 * double(fCheckbox239));
		double fSlow353 = (double(fHslider80) * fSlow1);
		int iSlow354 = int((fConst3 * (fSlow69 * double(fHslider81))));
		double fSlow355 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider82)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow356 = (1.0 - fSlow59);
		double fSlow357 = (fSlow64 * double(fCheckbox240));
		double fSlow358 = (fSlow4 * double(fCheckbox241));
		double fSlow359 = (fSlow8 * double(fCheckbox242));
		double fSlow360 = (fSlow12 * double(fCheckbox243));
		double fSlow361 = (fSlow16 * double(fCheckbox244));
		double fSlow362 = (fSlow20 * double(fCheckbox245));
		double fSlow363 = (fSlow24 * double(fCheckbox246));
		double fSlow364 = (fSlow28 * double(fCheckbox247));
		double fSlow365 = (fSlow32 * double(fCheckbox248));
		double fSlow366 = (fSlow36 * double(fCheckbox249));
		double fSlow367 = (fSlow40 * double(fCheckbox250));
		double fSlow368 = (fSlow44 * double(fCheckbox251));
		double fSlow369 = (fSlow48 * double(fCheckbox252));
		double fSlow370 = (fSlow52 * double(fCheckbox253));
		double fSlow371 = (fSlow56 * double(fCheckbox254));
		double fSlow372 = (fSlow60 * double(fCheckbox255));
		double fSlow373 = (double(fHslider83) * fSlow1);
		int iSlow374 = int((fConst3 * (fSlow69 * double(fHslider84))));
		double fSlow375 = (fConst4 * (0.0 - (3.8224 * ((440.0 * std::pow(2.0, (0.083333333333333329 * ((0.01 * ((fSlow71 * double(fHslider85)) + 6000.0)) + -69.0)))) + -261.62597699999998))));
		double fSlow376 = (1.0 - fSlow63);
		double fSlow377 = (double(fHslider86) * fSlow1);
		double fSlow378 = (fConst7 * double(fCheckbox256));
		double fSlow379 = (fConst7 * double(fCheckbox257));
		double fSlow380 = (fConst7 * double(fCheckbox258));
		double fSlow381 = (fConst7 * double(fCheckbox259));
		double fSlow382 = (fConst7 * double(fCheckbox260));
		double fSlow383 = (double(fHslider87) * fSlow1);
		double fSlow384 = (fConst7 * double(fCheckbox261));
		double fSlow385 = (fConst7 * double(fCheckbox262));
		double fSlow386 = (fConst7 * double(fCheckbox263));
		double fSlow387 = (fConst7 * double(fCheckbox264));
		double fSlow388 = (fConst7 * double(fCheckbox265));
		double fSlow389 = (double(fHslider88) * fSlow1);
		double fSlow390 = (fConst7 * double(fCheckbox266));
		double fSlow391 = (fConst7 * double(fCheckbox267));
		double fSlow392 = (fConst7 * double(fCheckbox268));
		double fSlow393 = (fConst7 * double(fCheckbox269));
		double fSlow394 = (fConst7 * double(fCheckbox270));
		double fSlow395 = (double(fHslider89) * fSlow1);
		double fSlow396 = (fConst7 * double(fCheckbox271));
		double fSlow397 = (fConst7 * double(fCheckbox272));
		double fSlow398 = (fConst7 * double(fCheckbox273));
		double fSlow399 = (fConst7 * double(fCheckbox274));
		double fSlow400 = (fConst7 * double(fCheckbox275));
		double fSlow401 = (double(fHslider90) * fSlow1);
		double fSlow402 = (fConst7 * double(fCheckbox276));
		double fSlow403 = (fConst7 * double(fCheckbox277));
		double fSlow404 = (fConst7 * double(fCheckbox278));
		double fSlow405 = (fConst7 * double(fCheckbox279));
		double fSlow406 = (fConst7 * double(fCheckbox280));
		double fSlow407 = (double(fHslider91) * fSlow1);
		double fSlow408 = (fConst7 * double(fCheckbox281));
		double fSlow409 = (fConst7 * double(fCheckbox282));
		double fSlow410 = (fConst7 * double(fCheckbox283));
		double fSlow411 = (fConst7 * double(fCheckbox284));
		double fSlow412 = (fConst7 * double(fCheckbox285));
		double fSlow413 = (double(fHslider92) * fSlow1);
		double fSlow414 = (fConst7 * double(fCheckbox286));
		double fSlow415 = (fConst7 * double(fCheckbox287));
		double fSlow416 = (fConst7 * double(fCheckbox288));
		double fSlow417 = (fConst7 * double(fCheckbox289));
		double fSlow418 = (fConst7 * double(fCheckbox290));
		double fSlow419 = (double(fHslider93) * fSlow1);
		double fSlow420 = (fConst7 * double(fCheckbox291));
		double fSlow421 = (fConst7 * double(fCheckbox292));
		double fSlow422 = (fConst7 * double(fCheckbox293));
		double fSlow423 = (fConst7 * double(fCheckbox294));
		double fSlow424 = (fConst7 * double(fCheckbox295));
		double fSlow425 = (double(fHslider94) * fSlow1);
		double fSlow426 = (fConst7 * double(fCheckbox296));
		double fSlow427 = (fConst7 * double(fCheckbox297));
		double fSlow428 = (fConst7 * double(fCheckbox298));
		double fSlow429 = (fConst7 * double(fCheckbox299));
		double fSlow430 = (fConst7 * double(fCheckbox300));
		double fSlow431 = (double(fHslider95) * fSlow1);
		double fSlow432 = (fConst7 * double(fCheckbox301));
		double fSlow433 = (fConst7 * double(fCheckbox302));
		double fSlow434 = (fConst7 * double(fCheckbox303));
		double fSlow435 = (fConst7 * double(fCheckbox304));
		double fSlow436 = (fConst7 * double(fCheckbox305));
		double fSlow437 = (double(fHslider96) * fSlow1);
		double fSlow438 = (fConst7 * double(fCheckbox306));
		double fSlow439 = (fConst7 * double(fCheckbox307));
		double fSlow440 = (fConst7 * double(fCheckbox308));
		double fSlow441 = (fConst7 * double(fCheckbox309));
		double fSlow442 = (fConst7 * double(fCheckbox310));
		double fSlow443 = (double(fHslider97) * fSlow1);
		double fSlow444 = (fConst7 * double(fCheckbox311));
		double fSlow445 = (fConst7 * double(fCheckbox312));
		double fSlow446 = (fConst7 * double(fCheckbox313));
		double fSlow447 = (fConst7 * double(fCheckbox314));
		double fSlow448 = (fConst7 * double(fCheckbox315));
		double fSlow449 = (double(fHslider98) * fSlow1);
		double fSlow450 = (fConst7 * double(fCheckbox316));
		double fSlow451 = (fConst7 * double(fCheckbox317));
		double fSlow452 = (fConst7 * double(fCheckbox318));
		double fSlow453 = (fConst7 * double(fCheckbox319));
		double fSlow454 = (fConst7 * double(fCheckbox320));
		double fSlow455 = (double(fHslider99) * fSlow1);
		double fSlow456 = (fConst7 * double(fCheckbox321));
		double fSlow457 = (fConst7 * double(fCheckbox322));
		double fSlow458 = (fConst7 * double(fCheckbox323));
		double fSlow459 = (fConst7 * double(fCheckbox324));
		double fSlow460 = (fConst7 * double(fCheckbox325));
		double fSlow461 = (double(fHslider100) * fSlow1);
		double fSlow462 = (fConst7 * double(fCheckbox326));
		double fSlow463 = (fConst7 * double(fCheckbox327));
		double fSlow464 = (fConst7 * double(fCheckbox328));
		double fSlow465 = (fConst7 * double(fCheckbox329));
		double fSlow466 = (fConst7 * double(fCheckbox330));
		double fSlow467 = (double(fHslider101) * fSlow1);
		double fSlow468 = (fConst7 * double(fCheckbox331));
		double fSlow469 = (fConst7 * double(fCheckbox332));
		double fSlow470 = (fConst7 * double(fCheckbox333));
		double fSlow471 = (fConst7 * double(fCheckbox334));
		double fSlow472 = (fConst7 * double(fCheckbox335));
		double fSlow473 = (double(fHslider102) * fSlow1);
		double fSlow474 = (fConst7 * double(fCheckbox336));
		double fSlow475 = (fConst7 * double(fCheckbox337));
		double fSlow476 = (fConst7 * double(fCheckbox338));
		double fSlow477 = (fConst7 * double(fCheckbox339));
		double fSlow478 = (fConst7 * double(fCheckbox340));
		double fSlow479 = ((2.0 * double(fCheckbox341)) + -1.0);
		double fSlow480 = (fSlow479 * double(fHslider103));
		double fSlow481 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider104)))));
		double fSlow482 = (0.2857142857142857 * std::sin(fSlow481));
		double fSlow483 = (fConst7 * double(fCheckbox342));
		double fSlow484 = (double(fHslider105) * fSlow1);
		double fSlow485 = (fConst4 * double(fEntry0));
		double fSlow486 = ((2.0 * double(fHslider106)) + -1.0);
		double fSlow487 = double(fHslider107);
		int iSlow488 = (fSlow487 == 0.0);
		double fSlow489 = double(fHslider108);
		double fSlow490 = (double(iSlow488) * fSlow489);
		double fSlow491 = double((1 - iSlow488));
		double fSlow492 = (fConst4 * fSlow487);
		double fSlow493 = double(fHslider109);
		int iSlow494 = (fSlow493 == 0.0);
		double fSlow495 = double(fHslider110);
		double fSlow496 = (double(iSlow494) * fSlow495);
		double fSlow497 = double((1 - iSlow494));
		double fSlow498 = (fConst4 * fSlow493);
		double fSlow499 = double(fHslider111);
		int iSlow500 = (fSlow499 == 0.0);
		double fSlow501 = double(fHslider112);
		double fSlow502 = (double(iSlow500) * fSlow501);
		double fSlow503 = double((1 - iSlow500));
		double fSlow504 = (fConst4 * fSlow499);
		double fSlow505 = (fConst7 * double(fCheckbox343));
		double fSlow506 = (fConst7 * double(fCheckbox344));
		double fSlow507 = (fConst7 * double(fCheckbox345));
		double fSlow508 = (fConst7 * double(fCheckbox346));
		double fSlow509 = (fConst7 * double(fCheckbox347));
		double fSlow510 = (fConst7 * double(fCheckbox348));
		double fSlow511 = (fConst7 * double(fCheckbox349));
		double fSlow512 = (fConst7 * double(fCheckbox350));
		double fSlow513 = (fConst7 * double(fCheckbox351));
		double fSlow514 = (fConst7 * double(fCheckbox352));
		double fSlow515 = (fConst7 * double(fCheckbox353));
		double fSlow516 = (fConst7 * double(fCheckbox354));
		double fSlow517 = (fConst7 * double(fCheckbox355));
		double fSlow518 = (fConst7 * double(fCheckbox356));
		double fSlow519 = (fConst7 * double(fCheckbox357));
		double fSlow520 = (fConst7 * double(fCheckbox358));
		double fSlow521 = double(fHslider113);
		int iSlow522 = (fSlow521 == 0.0);
		double fSlow523 = double(fHslider114);
		double fSlow524 = (double(iSlow522) * fSlow523);
		double fSlow525 = double((1 - iSlow522));
		double fSlow526 = (fConst4 * fSlow521);
		double fSlow527 = (0.2857142857142857 * std::cos(fSlow481));
		double fSlow528 = (fConst7 * double(fCheckbox359));
		double fSlow529 = (fConst7 * double(fCheckbox360));
		double fSlow530 = (fConst7 * double(fCheckbox361));
		double fSlow531 = (fConst7 * double(fCheckbox362));
		double fSlow532 = (fConst7 * double(fCheckbox363));
		double fSlow533 = (fConst7 * double(fCheckbox364));
		double fSlow534 = (fConst7 * double(fCheckbox365));
		double fSlow535 = (fConst7 * double(fCheckbox366));
		double fSlow536 = (fConst7 * double(fCheckbox367));
		double fSlow537 = (fConst7 * double(fCheckbox368));
		double fSlow538 = (fConst7 * double(fCheckbox369));
		double fSlow539 = (fConst7 * double(fCheckbox370));
		double fSlow540 = (fConst7 * double(fCheckbox371));
		double fSlow541 = (fConst7 * double(fCheckbox372));
		double fSlow542 = (fConst7 * double(fCheckbox373));
		double fSlow543 = (fConst7 * double(fCheckbox374));
		double fSlow544 = (fConst7 * double(fCheckbox375));
		double fSlow545 = (2.0 * fSlow481);
		double fSlow546 = (0.2857142857142857 * std::sin(fSlow545));
		double fSlow547 = (fConst7 * double(fCheckbox376));
		double fSlow548 = (fConst7 * double(fCheckbox377));
		double fSlow549 = (fConst7 * double(fCheckbox378));
		double fSlow550 = (fConst7 * double(fCheckbox379));
		double fSlow551 = (fConst7 * double(fCheckbox380));
		double fSlow552 = (fConst7 * double(fCheckbox381));
		double fSlow553 = (fConst7 * double(fCheckbox382));
		double fSlow554 = (fConst7 * double(fCheckbox383));
		double fSlow555 = (fConst7 * double(fCheckbox384));
		double fSlow556 = (fConst7 * double(fCheckbox385));
		double fSlow557 = (fConst7 * double(fCheckbox386));
		double fSlow558 = (fConst7 * double(fCheckbox387));
		double fSlow559 = (fConst7 * double(fCheckbox388));
		double fSlow560 = (fConst7 * double(fCheckbox389));
		double fSlow561 = (fConst7 * double(fCheckbox390));
		double fSlow562 = (fConst7 * double(fCheckbox391));
		double fSlow563 = (fConst7 * double(fCheckbox392));
		double fSlow564 = (0.2857142857142857 * std::cos(fSlow545));
		double fSlow565 = (fConst7 * double(fCheckbox393));
		double fSlow566 = (fConst7 * double(fCheckbox394));
		double fSlow567 = (fConst7 * double(fCheckbox395));
		double fSlow568 = (fConst7 * double(fCheckbox396));
		double fSlow569 = (fConst7 * double(fCheckbox397));
		double fSlow570 = (fConst7 * double(fCheckbox398));
		double fSlow571 = (fConst7 * double(fCheckbox399));
		double fSlow572 = (fConst7 * double(fCheckbox400));
		double fSlow573 = (fConst7 * double(fCheckbox401));
		double fSlow574 = (fConst7 * double(fCheckbox402));
		double fSlow575 = (fConst7 * double(fCheckbox403));
		double fSlow576 = (fConst7 * double(fCheckbox404));
		double fSlow577 = (fConst7 * double(fCheckbox405));
		double fSlow578 = (fConst7 * double(fCheckbox406));
		double fSlow579 = (fConst7 * double(fCheckbox407));
		double fSlow580 = (fConst7 * double(fCheckbox408));
		double fSlow581 = (fConst7 * double(fCheckbox409));
		double fSlow582 = (3.0 * fSlow481);
		double fSlow583 = (0.2857142857142857 * std::sin(fSlow582));
		double fSlow584 = (fConst7 * double(fCheckbox410));
		double fSlow585 = (fConst7 * double(fCheckbox411));
		double fSlow586 = (fConst7 * double(fCheckbox412));
		double fSlow587 = (fConst7 * double(fCheckbox413));
		double fSlow588 = (fConst7 * double(fCheckbox414));
		double fSlow589 = (fConst7 * double(fCheckbox415));
		double fSlow590 = (fConst7 * double(fCheckbox416));
		double fSlow591 = (fConst7 * double(fCheckbox417));
		double fSlow592 = (fConst7 * double(fCheckbox418));
		double fSlow593 = (fConst7 * double(fCheckbox419));
		double fSlow594 = (fConst7 * double(fCheckbox420));
		double fSlow595 = (fConst7 * double(fCheckbox421));
		double fSlow596 = (fConst7 * double(fCheckbox422));
		double fSlow597 = (fConst7 * double(fCheckbox423));
		double fSlow598 = (fConst7 * double(fCheckbox424));
		double fSlow599 = (fConst7 * double(fCheckbox425));
		double fSlow600 = (fConst7 * double(fCheckbox426));
		double fSlow601 = (0.2857142857142857 * std::cos(fSlow582));
		double fSlow602 = (fConst7 * double(fCheckbox427));
		double fSlow603 = (fConst7 * double(fCheckbox428));
		double fSlow604 = (fConst7 * double(fCheckbox429));
		double fSlow605 = (fConst7 * double(fCheckbox430));
		double fSlow606 = (fConst7 * double(fCheckbox431));
		double fSlow607 = (fConst7 * double(fCheckbox432));
		double fSlow608 = (fConst7 * double(fCheckbox433));
		double fSlow609 = (fConst7 * double(fCheckbox434));
		double fSlow610 = (fConst7 * double(fCheckbox435));
		double fSlow611 = (fConst7 * double(fCheckbox436));
		double fSlow612 = (fConst7 * double(fCheckbox437));
		double fSlow613 = (fConst7 * double(fCheckbox438));
		double fSlow614 = (fConst7 * double(fCheckbox439));
		double fSlow615 = (fConst7 * double(fCheckbox440));
		double fSlow616 = (fConst7 * double(fCheckbox441));
		double fSlow617 = (fConst7 * double(fCheckbox442));
		double fSlow618 = (fConst7 * double(fCheckbox443));
		double fSlow619 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider115)))));
		double fSlow620 = (0.2857142857142857 * std::sin(fSlow619));
		double fSlow621 = (0.2857142857142857 * std::cos(fSlow619));
		double fSlow622 = (2.0 * fSlow619);
		double fSlow623 = (0.2857142857142857 * std::sin(fSlow622));
		double fSlow624 = (0.2857142857142857 * std::cos(fSlow622));
		double fSlow625 = (3.0 * fSlow619);
		double fSlow626 = (0.2857142857142857 * std::sin(fSlow625));
		double fSlow627 = (0.2857142857142857 * std::cos(fSlow625));
		double fSlow628 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider116)))));
		double fSlow629 = (0.2857142857142857 * std::sin(fSlow628));
		double fSlow630 = (0.2857142857142857 * std::cos(fSlow628));
		double fSlow631 = (2.0 * fSlow628);
		double fSlow632 = (0.2857142857142857 * std::sin(fSlow631));
		double fSlow633 = (0.2857142857142857 * std::cos(fSlow631));
		double fSlow634 = (3.0 * fSlow628);
		double fSlow635 = (0.2857142857142857 * std::sin(fSlow634));
		double fSlow636 = (0.2857142857142857 * std::cos(fSlow634));
		double fSlow637 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider117)))));
		double fSlow638 = (0.2857142857142857 * std::sin(fSlow637));
		double fSlow639 = (0.2857142857142857 * std::cos(fSlow637));
		double fSlow640 = (2.0 * fSlow637);
		double fSlow641 = (0.2857142857142857 * std::sin(fSlow640));
		double fSlow642 = (0.2857142857142857 * std::cos(fSlow640));
		double fSlow643 = (3.0 * fSlow637);
		double fSlow644 = (0.2857142857142857 * std::sin(fSlow643));
		double fSlow645 = (0.2857142857142857 * std::cos(fSlow643));
		double fSlow646 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider118)))));
		double fSlow647 = (0.2857142857142857 * std::sin(fSlow646));
		double fSlow648 = (0.2857142857142857 * std::cos(fSlow646));
		double fSlow649 = (2.0 * fSlow646);
		double fSlow650 = (0.2857142857142857 * std::sin(fSlow649));
		double fSlow651 = (0.2857142857142857 * std::cos(fSlow649));
		double fSlow652 = (3.0 * fSlow646);
		double fSlow653 = (0.2857142857142857 * std::sin(fSlow652));
		double fSlow654 = (0.2857142857142857 * std::cos(fSlow652));
		double fSlow655 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider119)))));
		double fSlow656 = (0.2857142857142857 * std::sin(fSlow655));
		double fSlow657 = (0.2857142857142857 * std::cos(fSlow655));
		double fSlow658 = (2.0 * fSlow655);
		double fSlow659 = (0.2857142857142857 * std::sin(fSlow658));
		double fSlow660 = (0.2857142857142857 * std::cos(fSlow658));
		double fSlow661 = (3.0 * fSlow655);
		double fSlow662 = (0.2857142857142857 * std::sin(fSlow661));
		double fSlow663 = (0.2857142857142857 * std::cos(fSlow661));
		double fSlow664 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider120)))));
		double fSlow665 = (0.2857142857142857 * std::sin(fSlow664));
		double fSlow666 = (0.2857142857142857 * std::cos(fSlow664));
		double fSlow667 = (2.0 * fSlow664);
		double fSlow668 = (0.2857142857142857 * std::sin(fSlow667));
		double fSlow669 = (0.2857142857142857 * std::cos(fSlow667));
		double fSlow670 = (3.0 * fSlow664);
		double fSlow671 = (0.2857142857142857 * std::sin(fSlow670));
		double fSlow672 = (0.2857142857142857 * std::cos(fSlow670));
		double fSlow673 = (fSlow479 * (0.0 - (0.017453292519943295 * (fSlow480 - double(fHslider121)))));
		double fSlow674 = (0.2857142857142857 * std::sin(fSlow673));
		double fSlow675 = (0.2857142857142857 * std::cos(fSlow673));
		double fSlow676 = (2.0 * fSlow673);
		double fSlow677 = (0.2857142857142857 * std::sin(fSlow676));
		double fSlow678 = (0.2857142857142857 * std::cos(fSlow676));
		double fSlow679 = (3.0 * fSlow673);
		double fSlow680 = (0.2857142857142857 * std::sin(fSlow679));
		double fSlow681 = (0.2857142857142857 * std::cos(fSlow679));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow2 + (fSlow0 * fRec0[1]));
			double fTemp0 = (double((fRec0[0] > -127.0)) * std::pow(10.0, (0.050000000000000003 * fRec0[0])));
			fRec18[0] = (fConst2 + (fRec18[1] - std::floor((fConst2 + fRec18[1]))));
			double fTemp1 = (65536.0 * (fRec18[0] - std::floor(fRec18[0])));
			int iTemp2 = int(fTemp1);
			double fTemp3 = ftbl0mydspSIG0[iTemp2];
			double fTemp4 = ((fTemp3 + ((fTemp1 - std::floor(fTemp1)) * (ftbl0mydspSIG0[((iTemp2 + 1) % 65536)] - fTemp3))) + 1.0);
			fVec0[0] = fTemp4;
			fRec19[0] = (fSlow6 + (fSlow0 * fRec19[1]));
			double fTemp5 = (fRec19[0] * fRec1[1]);
			fRec20[0] = (fSlow10 + (fSlow0 * fRec20[1]));
			double fTemp6 = (fRec20[0] * fRec2[1]);
			fRec21[0] = (fSlow14 + (fSlow0 * fRec21[1]));
			double fTemp7 = (fRec21[0] * fRec3[1]);
			fRec22[0] = (fSlow18 + (fSlow0 * fRec22[1]));
			double fTemp8 = (fRec22[0] * fRec4[1]);
			fRec23[0] = (fSlow22 + (fSlow0 * fRec23[1]));
			double fTemp9 = (fRec23[0] * fRec5[1]);
			fRec24[0] = (fSlow26 + (fSlow0 * fRec24[1]));
			double fTemp10 = (fRec24[0] * fRec6[1]);
			fRec25[0] = (fSlow30 + (fSlow0 * fRec25[1]));
			double fTemp11 = (fRec25[0] * fRec7[1]);
			fRec26[0] = (fSlow34 + (fSlow0 * fRec26[1]));
			double fTemp12 = (fRec26[0] * fRec8[1]);
			fRec27[0] = (fSlow38 + (fSlow0 * fRec27[1]));
			double fTemp13 = (fRec27[0] * fRec9[1]);
			fRec28[0] = (fSlow42 + (fSlow0 * fRec28[1]));
			double fTemp14 = (fRec28[0] * fRec10[1]);
			fRec29[0] = (fSlow46 + (fSlow0 * fRec29[1]));
			double fTemp15 = (fRec29[0] * fRec11[1]);
			fRec30[0] = (fSlow50 + (fSlow0 * fRec30[1]));
			double fTemp16 = (fRec30[0] * fRec12[1]);
			fRec31[0] = (fSlow54 + (fSlow0 * fRec31[1]));
			double fTemp17 = (fRec31[0] * fRec13[1]);
			fRec32[0] = (fSlow58 + (fSlow0 * fRec32[1]));
			double fTemp18 = (fRec32[0] * fRec14[1]);
			fRec33[0] = (fSlow62 + (fSlow0 * fRec33[1]));
			double fTemp19 = (fRec33[0] * fRec15[1]);
			fRec34[0] = (fSlow66 + (fSlow0 * fRec34[1]));
			double fTemp20 = (fRec34[0] * fRec16[1]);
			fRec35[0] = (fSlow67 + (fSlow0 * fRec35[1]));
			fRec36[0] = (fSlow68 + (fSlow0 * fRec36[1]));
			double fTemp21 = double((fRec36[0] > -127.0));
			fRec37[0] = ((0.999 * fRec37[1]) + double(input0[i]));
			double fTemp22 = (fRec37[0] - fRec37[1]);
			double fTemp23 = std::pow(10.0, (0.050000000000000003 * fRec36[0]));
			double fTemp24 = (((((((((((((((((fSlow5 * fTemp5) + (fSlow9 * fTemp6)) + (fSlow13 * fTemp7)) + (fSlow17 * fTemp8)) + (fSlow21 * fTemp9)) + (fSlow25 * fTemp10)) + (fSlow29 * fTemp11)) + (fSlow33 * fTemp12)) + (fSlow37 * fTemp13)) + (fSlow41 * fTemp14)) + (fSlow45 * fTemp15)) + (fSlow49 * fTemp16)) + (fSlow53 * fTemp17)) + (fSlow57 * fTemp18)) + (fSlow61 * fTemp19)) + (fSlow65 * fTemp20)) + (((fRec35[0] * fTemp21) * fTemp22) * fTemp23));
			fVec1[(IOTA & 2097151)] = fTemp24;
			double fTemp25 = (0.5 * fTemp4);
			int iTemp26 = ((fTemp25 > 0.001) * ((0.5 * fVec0[1]) <= 0.001));
			iRec38[0] = (iTemp26?iSlow70:iRec38[1]);
			double fTemp27 = (1.0 - fTemp25);
			fVec2[0] = fTemp27;
			int iTemp28 = ((fTemp27 > 0.001) * (fVec2[1] <= 0.001));
			iRec39[0] = (iTemp28?iSlow70:iRec39[1]);
			double fTemp29 = ((0.5 * (fTemp4 * fVec1[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec38[0]))) & 2097151)])) + (fTemp27 * fVec1[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec39[0]))) & 2097151)]));
			int iTemp30 = (fTemp29 > 1.0);
			int iTemp31 = (fTemp29 < -1.0);
			double fTemp32 = (double((iTemp30 - iTemp31)) + (fTemp29 * double(((1 - iTemp31) * (1 - iTemp30)))));
			double fTemp33 = (fSlow3 * fTemp32);
			fVec3[(IOTA & 524287)] = fTemp33;
			fVec4[0] = fSlow75;
			double fTemp34 = ((fSlow75 != fVec4[1])?fConst5:(fRec42[1] + -1.0));
			fRec42[0] = fTemp34;
			fRec43[0] = ((fTemp34 <= 0.0)?fSlow75:(fRec43[1] + ((fSlow75 - fRec43[1]) / fTemp34)));
			double fTemp35 = (fRec41[1] + (fSlow72 / fRec43[0]));
			fRec41[0] = (fTemp35 - std::floor(fTemp35));
			double fTemp36 = (fRec41[0] - std::floor(fRec41[0]));
			fVec5[0] = fTemp36;
			fRec40[0] = (((fTemp36 > 0.001) * (fVec5[1] <= 0.001))?fRec43[0]:fRec40[1]);
			double fTemp37 = (fConst3 * (fRec40[0] * fTemp36));
			int iTemp38 = int(fTemp37);
			double fTemp39 = std::floor(fTemp37);
			double fTemp40 = (0.5 * fTemp36);
			double fTemp41 = (65536.0 * (fTemp40 - std::floor(fTemp40)));
			int iTemp42 = int(fTemp41);
			double fTemp43 = ftbl0mydspSIG0[iTemp42];
			double fTemp44 = (fRec41[0] + (0.25 - std::floor((fRec41[0] + 0.25))));
			fVec6[0] = fTemp44;
			fRec44[0] = (((fTemp44 > 0.001) * (fVec6[1] <= 0.001))?fRec43[0]:fRec44[1]);
			double fTemp45 = (fConst3 * (fRec44[0] * fTemp44));
			int iTemp46 = int(fTemp45);
			double fTemp47 = std::floor(fTemp45);
			double fTemp48 = (0.5 * fTemp44);
			double fTemp49 = (65536.0 * (fTemp48 - std::floor(fTemp48)));
			int iTemp50 = int(fTemp49);
			double fTemp51 = ftbl0mydspSIG0[iTemp50];
			double fTemp52 = (fRec41[0] + (0.5 - std::floor((fRec41[0] + 0.5))));
			fVec7[0] = fTemp52;
			fRec45[0] = (((fTemp52 > 0.001) * (fVec7[1] <= 0.001))?fRec43[0]:fRec45[1]);
			double fTemp53 = (fConst3 * (fRec45[0] * fTemp52));
			int iTemp54 = int(fTemp53);
			double fTemp55 = std::floor(fTemp53);
			double fTemp56 = (0.5 * fTemp52);
			double fTemp57 = (65536.0 * (fTemp56 - std::floor(fTemp56)));
			int iTemp58 = int(fTemp57);
			double fTemp59 = ftbl0mydspSIG0[iTemp58];
			double fTemp60 = (fRec41[0] + (0.75 - std::floor((fRec41[0] + 0.75))));
			fVec8[0] = fTemp60;
			fRec46[0] = (((fTemp60 > 0.001) * (fVec8[1] <= 0.001))?fRec43[0]:fRec46[1]);
			double fTemp61 = (fConst3 * (fRec46[0] * fTemp60));
			int iTemp62 = int(fTemp61);
			double fTemp63 = std::floor(fTemp61);
			double fTemp64 = (0.5 * fTemp60);
			double fTemp65 = (65536.0 * (fTemp64 - std::floor(fTemp64)));
			int iTemp66 = int(fTemp65);
			double fTemp67 = ftbl0mydspSIG0[iTemp66];
			fRec1[0] = (((((((fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp38))) & 524287)] * (fTemp39 + (1.0 - fTemp37))) + ((fTemp37 - fTemp39) * fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp38 + 1)))) & 524287)])) * (fTemp43 + ((fTemp41 - std::floor(fTemp41)) * (ftbl0mydspSIG0[((iTemp42 + 1) % 65536)] - fTemp43)))) + (((fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp46))) & 524287)] * (fTemp47 + (1.0 - fTemp45))) + ((fTemp45 - fTemp47) * fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp46 + 1)))) & 524287)])) * (fTemp51 + ((fTemp49 - std::floor(fTemp49)) * (ftbl0mydspSIG0[((iTemp50 + 1) % 65536)] - fTemp51))))) + (((fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp54))) & 524287)] * (fTemp55 + (1.0 - fTemp53))) + ((fTemp53 - fTemp55) * fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp54 + 1)))) & 524287)])) * (fTemp59 + ((fTemp57 - std::floor(fTemp57)) * (ftbl0mydspSIG0[((iTemp58 + 1) % 65536)] - fTemp59))))) + (((fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp62))) & 524287)] * (fTemp63 + (1.0 - fTemp61))) + ((fTemp61 - fTemp63) * fVec3[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp62 + 1)))) & 524287)])) * (fTemp67 + ((fTemp65 - std::floor(fTemp65)) * (ftbl0mydspSIG0[((iTemp66 + 1) % 65536)] - fTemp67))))) + (fSlow76 * fTemp32));
			fRec47[0] = (fSlow93 + (fSlow0 * fRec47[1]));
			double fTemp68 = (((((((((((((((((fSlow77 * fTemp5) + (fSlow78 * fTemp6)) + (fSlow79 * fTemp7)) + (fSlow80 * fTemp8)) + (fSlow81 * fTemp9)) + (fSlow82 * fTemp10)) + (fSlow83 * fTemp11)) + (fSlow84 * fTemp12)) + (fSlow85 * fTemp13)) + (fSlow86 * fTemp14)) + (fSlow87 * fTemp15)) + (fSlow88 * fTemp16)) + (fSlow89 * fTemp17)) + (fSlow90 * fTemp18)) + (fSlow91 * fTemp19)) + (fSlow92 * fTemp20)) + (((fRec47[0] * fTemp21) * fTemp22) * fTemp23));
			fVec9[(IOTA & 2097151)] = fTemp68;
			iRec48[0] = (iTemp26?iSlow94:iRec48[1]);
			iRec49[0] = (iTemp28?iSlow94:iRec49[1]);
			double fTemp69 = ((0.5 * (fTemp4 * fVec9[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec48[0]))) & 2097151)])) + (fTemp27 * fVec9[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec49[0]))) & 2097151)]));
			int iTemp70 = (fTemp69 > 1.0);
			int iTemp71 = (fTemp69 < -1.0);
			double fTemp72 = (double((iTemp70 - iTemp71)) + (fTemp69 * double(((1 - iTemp71) * (1 - iTemp70)))));
			double fTemp73 = (fSlow7 * fTemp72);
			fVec10[(IOTA & 524287)] = fTemp73;
			double fTemp74 = (fRec51[1] + (fSlow95 / fRec43[0]));
			fRec51[0] = (fTemp74 - std::floor(fTemp74));
			double fTemp75 = (fRec51[0] - std::floor(fRec51[0]));
			fVec11[0] = fTemp75;
			fRec50[0] = (((fTemp75 > 0.001) * (fVec11[1] <= 0.001))?fRec43[0]:fRec50[1]);
			double fTemp76 = (fConst3 * (fRec50[0] * fTemp75));
			int iTemp77 = int(fTemp76);
			double fTemp78 = std::floor(fTemp76);
			double fTemp79 = (0.5 * fTemp75);
			double fTemp80 = (65536.0 * (fTemp79 - std::floor(fTemp79)));
			int iTemp81 = int(fTemp80);
			double fTemp82 = ftbl0mydspSIG0[iTemp81];
			double fTemp83 = (fRec51[0] + (0.25 - std::floor((fRec51[0] + 0.25))));
			fVec12[0] = fTemp83;
			fRec52[0] = (((fTemp83 > 0.001) * (fVec12[1] <= 0.001))?fRec43[0]:fRec52[1]);
			double fTemp84 = (fConst3 * (fRec52[0] * fTemp83));
			int iTemp85 = int(fTemp84);
			double fTemp86 = std::floor(fTemp84);
			double fTemp87 = (0.5 * fTemp83);
			double fTemp88 = (65536.0 * (fTemp87 - std::floor(fTemp87)));
			int iTemp89 = int(fTemp88);
			double fTemp90 = ftbl0mydspSIG0[iTemp89];
			double fTemp91 = (fRec51[0] + (0.5 - std::floor((fRec51[0] + 0.5))));
			fVec13[0] = fTemp91;
			fRec53[0] = (((fTemp91 > 0.001) * (fVec13[1] <= 0.001))?fRec43[0]:fRec53[1]);
			double fTemp92 = (fConst3 * (fRec53[0] * fTemp91));
			int iTemp93 = int(fTemp92);
			double fTemp94 = std::floor(fTemp92);
			double fTemp95 = (0.5 * fTemp91);
			double fTemp96 = (65536.0 * (fTemp95 - std::floor(fTemp95)));
			int iTemp97 = int(fTemp96);
			double fTemp98 = ftbl0mydspSIG0[iTemp97];
			double fTemp99 = (fRec51[0] + (0.75 - std::floor((fRec51[0] + 0.75))));
			fVec14[0] = fTemp99;
			fRec54[0] = (((fTemp99 > 0.001) * (fVec14[1] <= 0.001))?fRec43[0]:fRec54[1]);
			double fTemp100 = (fConst3 * (fRec54[0] * fTemp99));
			int iTemp101 = int(fTemp100);
			double fTemp102 = std::floor(fTemp100);
			double fTemp103 = (0.5 * fTemp99);
			double fTemp104 = (65536.0 * (fTemp103 - std::floor(fTemp103)));
			int iTemp105 = int(fTemp104);
			double fTemp106 = ftbl0mydspSIG0[iTemp105];
			fRec2[0] = (((((((fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp77))) & 524287)] * (fTemp78 + (1.0 - fTemp76))) + ((fTemp76 - fTemp78) * fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp77 + 1)))) & 524287)])) * (fTemp82 + ((fTemp80 - std::floor(fTemp80)) * (ftbl0mydspSIG0[((iTemp81 + 1) % 65536)] - fTemp82)))) + (((fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp85))) & 524287)] * (fTemp86 + (1.0 - fTemp84))) + ((fTemp84 - fTemp86) * fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp85 + 1)))) & 524287)])) * (fTemp90 + ((fTemp88 - std::floor(fTemp88)) * (ftbl0mydspSIG0[((iTemp89 + 1) % 65536)] - fTemp90))))) + (((fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp93))) & 524287)] * (fTemp94 + (1.0 - fTemp92))) + ((fTemp92 - fTemp94) * fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp93 + 1)))) & 524287)])) * (fTemp98 + ((fTemp96 - std::floor(fTemp96)) * (ftbl0mydspSIG0[((iTemp97 + 1) % 65536)] - fTemp98))))) + (((fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp101))) & 524287)] * (fTemp102 + (1.0 - fTemp100))) + ((fTemp100 - fTemp102) * fVec10[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp101 + 1)))) & 524287)])) * (fTemp106 + ((fTemp104 - std::floor(fTemp104)) * (ftbl0mydspSIG0[((iTemp105 + 1) % 65536)] - fTemp106))))) + (fSlow96 * fTemp72));
			fRec55[0] = (fSlow113 + (fSlow0 * fRec55[1]));
			double fTemp107 = (((((((((((((((((fSlow97 * fTemp5) + (fSlow98 * fTemp6)) + (fSlow99 * fTemp7)) + (fSlow100 * fTemp8)) + (fSlow101 * fTemp9)) + (fSlow102 * fTemp10)) + (fSlow103 * fTemp11)) + (fSlow104 * fTemp12)) + (fSlow105 * fTemp13)) + (fSlow106 * fTemp14)) + (fSlow107 * fTemp15)) + (fSlow108 * fTemp16)) + (fSlow109 * fTemp17)) + (fSlow110 * fTemp18)) + (fSlow111 * fTemp19)) + (fSlow112 * fTemp20)) + (((fRec55[0] * fTemp21) * fTemp22) * fTemp23));
			fVec15[(IOTA & 2097151)] = fTemp107;
			iRec56[0] = (iTemp26?iSlow114:iRec56[1]);
			iRec57[0] = (iTemp28?iSlow114:iRec57[1]);
			double fTemp108 = ((0.5 * (fTemp4 * fVec15[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec56[0]))) & 2097151)])) + (fTemp27 * fVec15[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec57[0]))) & 2097151)]));
			int iTemp109 = (fTemp108 > 1.0);
			int iTemp110 = (fTemp108 < -1.0);
			double fTemp111 = ((double(((1 - iTemp109) * (1 - iTemp110))) * fTemp108) + double((iTemp109 - iTemp110)));
			double fTemp112 = (fSlow11 * fTemp111);
			fVec16[(IOTA & 524287)] = fTemp112;
			double fTemp113 = (fRec59[1] + (fSlow115 / fRec43[0]));
			fRec59[0] = (fTemp113 - std::floor(fTemp113));
			double fTemp114 = (fRec59[0] - std::floor(fRec59[0]));
			fVec17[0] = fTemp114;
			fRec58[0] = (((fTemp114 > 0.001) * (fVec17[1] <= 0.001))?fRec43[0]:fRec58[1]);
			double fTemp115 = (fConst3 * (fRec58[0] * fTemp114));
			int iTemp116 = int(fTemp115);
			double fTemp117 = std::floor(fTemp115);
			double fTemp118 = (0.5 * fTemp114);
			double fTemp119 = (65536.0 * (fTemp118 - std::floor(fTemp118)));
			int iTemp120 = int(fTemp119);
			double fTemp121 = ftbl0mydspSIG0[iTemp120];
			double fTemp122 = (fRec59[0] + (0.25 - std::floor((fRec59[0] + 0.25))));
			fVec18[0] = fTemp122;
			fRec60[0] = (((fTemp122 > 0.001) * (fVec18[1] <= 0.001))?fRec43[0]:fRec60[1]);
			double fTemp123 = (fConst3 * (fRec60[0] * fTemp122));
			int iTemp124 = int(fTemp123);
			double fTemp125 = std::floor(fTemp123);
			double fTemp126 = (0.5 * fTemp122);
			double fTemp127 = (65536.0 * (fTemp126 - std::floor(fTemp126)));
			int iTemp128 = int(fTemp127);
			double fTemp129 = ftbl0mydspSIG0[iTemp128];
			double fTemp130 = (fRec59[0] + (0.5 - std::floor((fRec59[0] + 0.5))));
			fVec19[0] = fTemp130;
			fRec61[0] = (((fTemp130 > 0.001) * (fVec19[1] <= 0.001))?fRec43[0]:fRec61[1]);
			double fTemp131 = (fConst3 * (fRec61[0] * fTemp130));
			int iTemp132 = int(fTemp131);
			double fTemp133 = std::floor(fTemp131);
			double fTemp134 = (0.5 * fTemp130);
			double fTemp135 = (65536.0 * (fTemp134 - std::floor(fTemp134)));
			int iTemp136 = int(fTemp135);
			double fTemp137 = ftbl0mydspSIG0[iTemp136];
			double fTemp138 = (fRec59[0] + (0.75 - std::floor((fRec59[0] + 0.75))));
			fVec20[0] = fTemp138;
			fRec62[0] = (((fTemp138 > 0.001) * (fVec20[1] <= 0.001))?fRec43[0]:fRec62[1]);
			double fTemp139 = (fConst3 * (fRec62[0] * fTemp138));
			int iTemp140 = int(fTemp139);
			double fTemp141 = std::floor(fTemp139);
			double fTemp142 = (0.5 * fTemp138);
			double fTemp143 = (65536.0 * (fTemp142 - std::floor(fTemp142)));
			int iTemp144 = int(fTemp143);
			double fTemp145 = ftbl0mydspSIG0[iTemp144];
			fRec3[0] = (((((((fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp116))) & 524287)] * (fTemp117 + (1.0 - fTemp115))) + ((fTemp115 - fTemp117) * fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp116 + 1)))) & 524287)])) * (fTemp121 + ((fTemp119 - std::floor(fTemp119)) * (ftbl0mydspSIG0[((iTemp120 + 1) % 65536)] - fTemp121)))) + (((fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp124))) & 524287)] * (fTemp125 + (1.0 - fTemp123))) + ((fTemp123 - fTemp125) * fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp124 + 1)))) & 524287)])) * (fTemp129 + ((fTemp127 - std::floor(fTemp127)) * (ftbl0mydspSIG0[((iTemp128 + 1) % 65536)] - fTemp129))))) + (((fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp132))) & 524287)] * (fTemp133 + (1.0 - fTemp131))) + ((fTemp131 - fTemp133) * fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp132 + 1)))) & 524287)])) * (fTemp137 + ((fTemp135 - std::floor(fTemp135)) * (ftbl0mydspSIG0[((iTemp136 + 1) % 65536)] - fTemp137))))) + (((fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp140))) & 524287)] * (fTemp141 + (1.0 - fTemp139))) + ((fTemp139 - fTemp141) * fVec16[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp140 + 1)))) & 524287)])) * (fTemp145 + ((fTemp143 - std::floor(fTemp143)) * (ftbl0mydspSIG0[((iTemp144 + 1) % 65536)] - fTemp145))))) + (fSlow116 * fTemp111));
			fRec63[0] = (fSlow133 + (fSlow0 * fRec63[1]));
			double fTemp146 = (((((((((((((((((fSlow117 * fTemp5) + (fSlow118 * fTemp6)) + (fSlow119 * fTemp7)) + (fSlow120 * fTemp8)) + (fSlow121 * fTemp9)) + (fSlow122 * fTemp10)) + (fSlow123 * fTemp11)) + (fSlow124 * fTemp12)) + (fSlow125 * fTemp13)) + (fSlow126 * fTemp14)) + (fSlow127 * fTemp15)) + (fSlow128 * fTemp16)) + (fSlow129 * fTemp17)) + (fSlow130 * fTemp18)) + (fSlow131 * fTemp19)) + (fSlow132 * fTemp20)) + (((fRec63[0] * fTemp21) * fTemp22) * fTemp23));
			fVec21[(IOTA & 2097151)] = fTemp146;
			iRec64[0] = (iTemp26?iSlow134:iRec64[1]);
			iRec65[0] = (iTemp28?iSlow134:iRec65[1]);
			double fTemp147 = ((0.5 * (fTemp4 * fVec21[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec64[0]))) & 2097151)])) + (fTemp27 * fVec21[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec65[0]))) & 2097151)]));
			int iTemp148 = (fTemp147 > 1.0);
			int iTemp149 = (fTemp147 < -1.0);
			double fTemp150 = (double((iTemp148 - iTemp149)) + (fTemp147 * double(((1 - iTemp149) * (1 - iTemp148)))));
			double fTemp151 = (fSlow15 * fTemp150);
			fVec22[(IOTA & 524287)] = fTemp151;
			double fTemp152 = (fRec67[1] + (fSlow135 / fRec43[0]));
			fRec67[0] = (fTemp152 - std::floor(fTemp152));
			double fTemp153 = (fRec67[0] - std::floor(fRec67[0]));
			fVec23[0] = fTemp153;
			fRec66[0] = (((fTemp153 > 0.001) * (fVec23[1] <= 0.001))?fRec43[0]:fRec66[1]);
			double fTemp154 = (fConst3 * (fRec66[0] * fTemp153));
			int iTemp155 = int(fTemp154);
			double fTemp156 = std::floor(fTemp154);
			double fTemp157 = (0.5 * fTemp153);
			double fTemp158 = (65536.0 * (fTemp157 - std::floor(fTemp157)));
			int iTemp159 = int(fTemp158);
			double fTemp160 = ftbl0mydspSIG0[iTemp159];
			double fTemp161 = (fRec67[0] + (0.25 - std::floor((fRec67[0] + 0.25))));
			fVec24[0] = fTemp161;
			fRec68[0] = (((fTemp161 > 0.001) * (fVec24[1] <= 0.001))?fRec43[0]:fRec68[1]);
			double fTemp162 = (fConst3 * (fRec68[0] * fTemp161));
			int iTemp163 = int(fTemp162);
			double fTemp164 = std::floor(fTemp162);
			double fTemp165 = (0.5 * fTemp161);
			double fTemp166 = (65536.0 * (fTemp165 - std::floor(fTemp165)));
			int iTemp167 = int(fTemp166);
			double fTemp168 = ftbl0mydspSIG0[iTemp167];
			double fTemp169 = (fRec67[0] + (0.5 - std::floor((fRec67[0] + 0.5))));
			fVec25[0] = fTemp169;
			fRec69[0] = (((fTemp169 > 0.001) * (fVec25[1] <= 0.001))?fRec43[0]:fRec69[1]);
			double fTemp170 = (fConst3 * (fRec69[0] * fTemp169));
			int iTemp171 = int(fTemp170);
			double fTemp172 = std::floor(fTemp170);
			double fTemp173 = (0.5 * fTemp169);
			double fTemp174 = (65536.0 * (fTemp173 - std::floor(fTemp173)));
			int iTemp175 = int(fTemp174);
			double fTemp176 = ftbl0mydspSIG0[iTemp175];
			double fTemp177 = (fRec67[0] + (0.75 - std::floor((fRec67[0] + 0.75))));
			fVec26[0] = fTemp177;
			fRec70[0] = (((fTemp177 > 0.001) * (fVec26[1] <= 0.001))?fRec43[0]:fRec70[1]);
			double fTemp178 = (fConst3 * (fRec70[0] * fTemp177));
			int iTemp179 = int(fTemp178);
			double fTemp180 = std::floor(fTemp178);
			double fTemp181 = (0.5 * fTemp177);
			double fTemp182 = (65536.0 * (fTemp181 - std::floor(fTemp181)));
			int iTemp183 = int(fTemp182);
			double fTemp184 = ftbl0mydspSIG0[iTemp183];
			fRec4[0] = (((((((fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp155))) & 524287)] * (fTemp156 + (1.0 - fTemp154))) + ((fTemp154 - fTemp156) * fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp155 + 1)))) & 524287)])) * (fTemp160 + ((fTemp158 - std::floor(fTemp158)) * (ftbl0mydspSIG0[((iTemp159 + 1) % 65536)] - fTemp160)))) + (((fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp163))) & 524287)] * (fTemp164 + (1.0 - fTemp162))) + ((fTemp162 - fTemp164) * fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp163 + 1)))) & 524287)])) * (fTemp168 + ((fTemp166 - std::floor(fTemp166)) * (ftbl0mydspSIG0[((iTemp167 + 1) % 65536)] - fTemp168))))) + (((fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp171))) & 524287)] * (fTemp172 + (1.0 - fTemp170))) + ((fTemp170 - fTemp172) * fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp171 + 1)))) & 524287)])) * (fTemp176 + ((fTemp174 - std::floor(fTemp174)) * (ftbl0mydspSIG0[((iTemp175 + 1) % 65536)] - fTemp176))))) + (((fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp179))) & 524287)] * (fTemp180 + (1.0 - fTemp178))) + ((fTemp178 - fTemp180) * fVec22[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp179 + 1)))) & 524287)])) * (fTemp184 + ((fTemp182 - std::floor(fTemp182)) * (ftbl0mydspSIG0[((iTemp183 + 1) % 65536)] - fTemp184))))) + (fSlow136 * fTemp150));
			fRec71[0] = (fSlow153 + (fSlow0 * fRec71[1]));
			double fTemp185 = (((((((((((((((((fSlow137 * fTemp5) + (fSlow138 * fTemp6)) + (fSlow139 * fTemp7)) + (fSlow140 * fTemp8)) + (fSlow141 * fTemp9)) + (fSlow142 * fTemp10)) + (fSlow143 * fTemp11)) + (fSlow144 * fTemp12)) + (fSlow145 * fTemp13)) + (fSlow146 * fTemp14)) + (fSlow147 * fTemp15)) + (fSlow148 * fTemp16)) + (fSlow149 * fTemp17)) + (fSlow150 * fTemp18)) + (fSlow151 * fTemp19)) + (fSlow152 * fTemp20)) + (((fRec71[0] * fTemp21) * fTemp22) * fTemp23));
			fVec27[(IOTA & 2097151)] = fTemp185;
			iRec72[0] = (iTemp26?iSlow154:iRec72[1]);
			iRec73[0] = (iTemp28?iSlow154:iRec73[1]);
			double fTemp186 = ((0.5 * (fTemp4 * fVec27[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec72[0]))) & 2097151)])) + (fTemp27 * fVec27[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec73[0]))) & 2097151)]));
			int iTemp187 = (fTemp186 > 1.0);
			int iTemp188 = (fTemp186 < -1.0);
			double fTemp189 = (double((iTemp187 - iTemp188)) + (fTemp186 * double(((1 - iTemp188) * (1 - iTemp187)))));
			double fTemp190 = (fSlow19 * fTemp189);
			fVec28[(IOTA & 524287)] = fTemp190;
			double fTemp191 = (fRec75[1] + (fSlow155 / fRec43[0]));
			fRec75[0] = (fTemp191 - std::floor(fTemp191));
			double fTemp192 = (fRec75[0] - std::floor(fRec75[0]));
			fVec29[0] = fTemp192;
			fRec74[0] = (((fTemp192 > 0.001) * (fVec29[1] <= 0.001))?fRec43[0]:fRec74[1]);
			double fTemp193 = (fConst3 * (fRec74[0] * fTemp192));
			int iTemp194 = int(fTemp193);
			double fTemp195 = std::floor(fTemp193);
			double fTemp196 = (0.5 * fTemp192);
			double fTemp197 = (65536.0 * (fTemp196 - std::floor(fTemp196)));
			int iTemp198 = int(fTemp197);
			double fTemp199 = ftbl0mydspSIG0[iTemp198];
			double fTemp200 = (fRec75[0] + (0.25 - std::floor((fRec75[0] + 0.25))));
			fVec30[0] = fTemp200;
			fRec76[0] = (((fTemp200 > 0.001) * (fVec30[1] <= 0.001))?fRec43[0]:fRec76[1]);
			double fTemp201 = (fConst3 * (fRec76[0] * fTemp200));
			int iTemp202 = int(fTemp201);
			double fTemp203 = std::floor(fTemp201);
			double fTemp204 = (0.5 * fTemp200);
			double fTemp205 = (65536.0 * (fTemp204 - std::floor(fTemp204)));
			int iTemp206 = int(fTemp205);
			double fTemp207 = ftbl0mydspSIG0[iTemp206];
			double fTemp208 = (fRec75[0] + (0.5 - std::floor((fRec75[0] + 0.5))));
			fVec31[0] = fTemp208;
			fRec77[0] = (((fTemp208 > 0.001) * (fVec31[1] <= 0.001))?fRec43[0]:fRec77[1]);
			double fTemp209 = (fConst3 * (fRec77[0] * fTemp208));
			int iTemp210 = int(fTemp209);
			double fTemp211 = std::floor(fTemp209);
			double fTemp212 = (0.5 * fTemp208);
			double fTemp213 = (65536.0 * (fTemp212 - std::floor(fTemp212)));
			int iTemp214 = int(fTemp213);
			double fTemp215 = ftbl0mydspSIG0[iTemp214];
			double fTemp216 = (fRec75[0] + (0.75 - std::floor((fRec75[0] + 0.75))));
			fVec32[0] = fTemp216;
			fRec78[0] = (((fTemp216 > 0.001) * (fVec32[1] <= 0.001))?fRec43[0]:fRec78[1]);
			double fTemp217 = (fConst3 * (fRec78[0] * fTemp216));
			int iTemp218 = int(fTemp217);
			double fTemp219 = std::floor(fTemp217);
			double fTemp220 = (0.5 * fTemp216);
			double fTemp221 = (65536.0 * (fTemp220 - std::floor(fTemp220)));
			int iTemp222 = int(fTemp221);
			double fTemp223 = ftbl0mydspSIG0[iTemp222];
			fRec5[0] = (((((((fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp194))) & 524287)] * (fTemp195 + (1.0 - fTemp193))) + ((fTemp193 - fTemp195) * fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp194 + 1)))) & 524287)])) * (fTemp199 + ((fTemp197 - std::floor(fTemp197)) * (ftbl0mydspSIG0[((iTemp198 + 1) % 65536)] - fTemp199)))) + (((fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp202))) & 524287)] * (fTemp203 + (1.0 - fTemp201))) + ((fTemp201 - fTemp203) * fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp202 + 1)))) & 524287)])) * (fTemp207 + ((fTemp205 - std::floor(fTemp205)) * (ftbl0mydspSIG0[((iTemp206 + 1) % 65536)] - fTemp207))))) + (((fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp210))) & 524287)] * (fTemp211 + (1.0 - fTemp209))) + ((fTemp209 - fTemp211) * fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp210 + 1)))) & 524287)])) * (fTemp215 + ((fTemp213 - std::floor(fTemp213)) * (ftbl0mydspSIG0[((iTemp214 + 1) % 65536)] - fTemp215))))) + (((fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp218))) & 524287)] * (fTemp219 + (1.0 - fTemp217))) + ((fTemp217 - fTemp219) * fVec28[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp218 + 1)))) & 524287)])) * (fTemp223 + ((fTemp221 - std::floor(fTemp221)) * (ftbl0mydspSIG0[((iTemp222 + 1) % 65536)] - fTemp223))))) + (fSlow156 * fTemp189));
			fRec79[0] = (fSlow173 + (fSlow0 * fRec79[1]));
			double fTemp224 = (((((((((((((((((fSlow157 * fTemp5) + (fSlow158 * fTemp6)) + (fSlow159 * fTemp7)) + (fSlow160 * fTemp8)) + (fSlow161 * fTemp9)) + (fSlow162 * fTemp10)) + (fSlow163 * fTemp11)) + (fSlow164 * fTemp12)) + (fSlow165 * fTemp13)) + (fSlow166 * fTemp14)) + (fSlow167 * fTemp15)) + (fSlow168 * fTemp16)) + (fSlow169 * fTemp17)) + (fSlow170 * fTemp18)) + (fSlow171 * fTemp19)) + (fSlow172 * fTemp20)) + (((fRec79[0] * fTemp21) * fTemp22) * fTemp23));
			fVec33[(IOTA & 2097151)] = fTemp224;
			iRec80[0] = (iTemp26?iSlow174:iRec80[1]);
			iRec81[0] = (iTemp28?iSlow174:iRec81[1]);
			double fTemp225 = ((0.5 * (fTemp4 * fVec33[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec80[0]))) & 2097151)])) + (fTemp27 * fVec33[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec81[0]))) & 2097151)]));
			int iTemp226 = (fTemp225 > 1.0);
			int iTemp227 = (fTemp225 < -1.0);
			double fTemp228 = (double((iTemp226 - iTemp227)) + (fTemp225 * double(((1 - iTemp227) * (1 - iTemp226)))));
			double fTemp229 = (fSlow23 * fTemp228);
			fVec34[(IOTA & 524287)] = fTemp229;
			double fTemp230 = (fRec83[1] + (fSlow175 / fRec43[0]));
			fRec83[0] = (fTemp230 - std::floor(fTemp230));
			double fTemp231 = (fRec83[0] - std::floor(fRec83[0]));
			fVec35[0] = fTemp231;
			fRec82[0] = (((fTemp231 > 0.001) * (fVec35[1] <= 0.001))?fRec43[0]:fRec82[1]);
			double fTemp232 = (fConst3 * (fRec82[0] * fTemp231));
			int iTemp233 = int(fTemp232);
			double fTemp234 = std::floor(fTemp232);
			double fTemp235 = (0.5 * fTemp231);
			double fTemp236 = (65536.0 * (fTemp235 - std::floor(fTemp235)));
			int iTemp237 = int(fTemp236);
			double fTemp238 = ftbl0mydspSIG0[iTemp237];
			double fTemp239 = (fRec83[0] + (0.25 - std::floor((fRec83[0] + 0.25))));
			fVec36[0] = fTemp239;
			fRec84[0] = (((fTemp239 > 0.001) * (fVec36[1] <= 0.001))?fRec43[0]:fRec84[1]);
			double fTemp240 = (fConst3 * (fRec84[0] * fTemp239));
			int iTemp241 = int(fTemp240);
			double fTemp242 = std::floor(fTemp240);
			double fTemp243 = (0.5 * fTemp239);
			double fTemp244 = (65536.0 * (fTemp243 - std::floor(fTemp243)));
			int iTemp245 = int(fTemp244);
			double fTemp246 = ftbl0mydspSIG0[iTemp245];
			double fTemp247 = (fRec83[0] + (0.5 - std::floor((fRec83[0] + 0.5))));
			fVec37[0] = fTemp247;
			fRec85[0] = (((fTemp247 > 0.001) * (fVec37[1] <= 0.001))?fRec43[0]:fRec85[1]);
			double fTemp248 = (fConst3 * (fRec85[0] * fTemp247));
			int iTemp249 = int(fTemp248);
			double fTemp250 = std::floor(fTemp248);
			double fTemp251 = (0.5 * fTemp247);
			double fTemp252 = (65536.0 * (fTemp251 - std::floor(fTemp251)));
			int iTemp253 = int(fTemp252);
			double fTemp254 = ftbl0mydspSIG0[iTemp253];
			double fTemp255 = (fRec83[0] + (0.75 - std::floor((fRec83[0] + 0.75))));
			fVec38[0] = fTemp255;
			fRec86[0] = (((fTemp255 > 0.001) * (fVec38[1] <= 0.001))?fRec43[0]:fRec86[1]);
			double fTemp256 = (fConst3 * (fRec86[0] * fTemp255));
			int iTemp257 = int(fTemp256);
			double fTemp258 = std::floor(fTemp256);
			double fTemp259 = (0.5 * fTemp255);
			double fTemp260 = (65536.0 * (fTemp259 - std::floor(fTemp259)));
			int iTemp261 = int(fTemp260);
			double fTemp262 = ftbl0mydspSIG0[iTemp261];
			fRec6[0] = (((((((fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp233))) & 524287)] * (fTemp234 + (1.0 - fTemp232))) + ((fTemp232 - fTemp234) * fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp233 + 1)))) & 524287)])) * (fTemp238 + ((fTemp236 - std::floor(fTemp236)) * (ftbl0mydspSIG0[((iTemp237 + 1) % 65536)] - fTemp238)))) + (((fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp241))) & 524287)] * (fTemp242 + (1.0 - fTemp240))) + ((fTemp240 - fTemp242) * fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp241 + 1)))) & 524287)])) * (fTemp246 + ((fTemp244 - std::floor(fTemp244)) * (ftbl0mydspSIG0[((iTemp245 + 1) % 65536)] - fTemp246))))) + (((fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp249))) & 524287)] * (fTemp250 + (1.0 - fTemp248))) + ((fTemp248 - fTemp250) * fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp249 + 1)))) & 524287)])) * (fTemp254 + ((fTemp252 - std::floor(fTemp252)) * (ftbl0mydspSIG0[((iTemp253 + 1) % 65536)] - fTemp254))))) + (((fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp257))) & 524287)] * (fTemp258 + (1.0 - fTemp256))) + ((fTemp256 - fTemp258) * fVec34[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp257 + 1)))) & 524287)])) * (fTemp262 + ((fTemp260 - std::floor(fTemp260)) * (ftbl0mydspSIG0[((iTemp261 + 1) % 65536)] - fTemp262))))) + (fSlow176 * fTemp228));
			fRec87[0] = (fSlow193 + (fSlow0 * fRec87[1]));
			double fTemp263 = (((((((((((((((((fSlow177 * fTemp5) + (fSlow178 * fTemp6)) + (fSlow179 * fTemp7)) + (fSlow180 * fTemp8)) + (fSlow181 * fTemp9)) + (fSlow182 * fTemp10)) + (fSlow183 * fTemp11)) + (fSlow184 * fTemp12)) + (fSlow185 * fTemp13)) + (fSlow186 * fTemp14)) + (fSlow187 * fTemp15)) + (fSlow188 * fTemp16)) + (fSlow189 * fTemp17)) + (fSlow190 * fTemp18)) + (fSlow191 * fTemp19)) + (fSlow192 * fTemp20)) + (((fRec87[0] * fTemp21) * fTemp22) * fTemp23));
			fVec39[(IOTA & 2097151)] = fTemp263;
			iRec88[0] = (iTemp26?iSlow194:iRec88[1]);
			iRec89[0] = (iTemp28?iSlow194:iRec89[1]);
			double fTemp264 = ((0.5 * (fTemp4 * fVec39[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec88[0]))) & 2097151)])) + (fTemp27 * fVec39[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec89[0]))) & 2097151)]));
			int iTemp265 = (fTemp264 > 1.0);
			int iTemp266 = (fTemp264 < -1.0);
			double fTemp267 = (double((iTemp265 - iTemp266)) + (fTemp264 * double(((1 - iTemp266) * (1 - iTemp265)))));
			double fTemp268 = (fSlow27 * fTemp267);
			fVec40[(IOTA & 524287)] = fTemp268;
			double fTemp269 = (fRec91[1] + (fSlow195 / fRec43[0]));
			fRec91[0] = (fTemp269 - std::floor(fTemp269));
			double fTemp270 = (fRec91[0] - std::floor(fRec91[0]));
			fVec41[0] = fTemp270;
			fRec90[0] = (((fTemp270 > 0.001) * (fVec41[1] <= 0.001))?fRec43[0]:fRec90[1]);
			double fTemp271 = (fConst3 * (fRec90[0] * fTemp270));
			int iTemp272 = int(fTemp271);
			double fTemp273 = std::floor(fTemp271);
			double fTemp274 = (0.5 * fTemp270);
			double fTemp275 = (65536.0 * (fTemp274 - std::floor(fTemp274)));
			int iTemp276 = int(fTemp275);
			double fTemp277 = ftbl0mydspSIG0[iTemp276];
			double fTemp278 = (fRec91[0] + (0.25 - std::floor((fRec91[0] + 0.25))));
			fVec42[0] = fTemp278;
			fRec92[0] = (((fTemp278 > 0.001) * (fVec42[1] <= 0.001))?fRec43[0]:fRec92[1]);
			double fTemp279 = (fConst3 * (fRec92[0] * fTemp278));
			int iTemp280 = int(fTemp279);
			double fTemp281 = std::floor(fTemp279);
			double fTemp282 = (0.5 * fTemp278);
			double fTemp283 = (65536.0 * (fTemp282 - std::floor(fTemp282)));
			int iTemp284 = int(fTemp283);
			double fTemp285 = ftbl0mydspSIG0[iTemp284];
			double fTemp286 = (fRec91[0] + (0.5 - std::floor((fRec91[0] + 0.5))));
			fVec43[0] = fTemp286;
			fRec93[0] = (((fTemp286 > 0.001) * (fVec43[1] <= 0.001))?fRec43[0]:fRec93[1]);
			double fTemp287 = (fConst3 * (fRec93[0] * fTemp286));
			int iTemp288 = int(fTemp287);
			double fTemp289 = std::floor(fTemp287);
			double fTemp290 = (0.5 * fTemp286);
			double fTemp291 = (65536.0 * (fTemp290 - std::floor(fTemp290)));
			int iTemp292 = int(fTemp291);
			double fTemp293 = ftbl0mydspSIG0[iTemp292];
			double fTemp294 = (fRec91[0] + (0.75 - std::floor((fRec91[0] + 0.75))));
			fVec44[0] = fTemp294;
			fRec94[0] = (((fTemp294 > 0.001) * (fVec44[1] <= 0.001))?fRec43[0]:fRec94[1]);
			double fTemp295 = (fConst3 * (fRec94[0] * fTemp294));
			int iTemp296 = int(fTemp295);
			double fTemp297 = std::floor(fTemp295);
			double fTemp298 = (0.5 * fTemp294);
			double fTemp299 = (65536.0 * (fTemp298 - std::floor(fTemp298)));
			int iTemp300 = int(fTemp299);
			double fTemp301 = ftbl0mydspSIG0[iTemp300];
			fRec7[0] = (((((((fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp272))) & 524287)] * (fTemp273 + (1.0 - fTemp271))) + ((fTemp271 - fTemp273) * fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp272 + 1)))) & 524287)])) * (fTemp277 + ((fTemp275 - std::floor(fTemp275)) * (ftbl0mydspSIG0[((iTemp276 + 1) % 65536)] - fTemp277)))) + (((fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp280))) & 524287)] * (fTemp281 + (1.0 - fTemp279))) + ((fTemp279 - fTemp281) * fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp280 + 1)))) & 524287)])) * (fTemp285 + ((fTemp283 - std::floor(fTemp283)) * (ftbl0mydspSIG0[((iTemp284 + 1) % 65536)] - fTemp285))))) + (((fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp288))) & 524287)] * (fTemp289 + (1.0 - fTemp287))) + ((fTemp287 - fTemp289) * fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp288 + 1)))) & 524287)])) * (fTemp293 + ((fTemp291 - std::floor(fTemp291)) * (ftbl0mydspSIG0[((iTemp292 + 1) % 65536)] - fTemp293))))) + (((fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp296))) & 524287)] * (fTemp297 + (1.0 - fTemp295))) + ((fTemp295 - fTemp297) * fVec40[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp296 + 1)))) & 524287)])) * (fTemp301 + ((fTemp299 - std::floor(fTemp299)) * (ftbl0mydspSIG0[((iTemp300 + 1) % 65536)] - fTemp301))))) + (fSlow196 * fTemp267));
			fRec95[0] = (fSlow213 + (fSlow0 * fRec95[1]));
			double fTemp302 = (((((((((((((((((fSlow197 * fTemp5) + (fSlow198 * fTemp6)) + (fSlow199 * fTemp7)) + (fSlow200 * fTemp8)) + (fSlow201 * fTemp9)) + (fSlow202 * fTemp10)) + (fSlow203 * fTemp11)) + (fSlow204 * fTemp12)) + (fSlow205 * fTemp13)) + (fSlow206 * fTemp14)) + (fSlow207 * fTemp15)) + (fSlow208 * fTemp16)) + (fSlow209 * fTemp17)) + (fSlow210 * fTemp18)) + (fSlow211 * fTemp19)) + (fSlow212 * fTemp20)) + (((fRec95[0] * fTemp21) * fTemp22) * fTemp23));
			fVec45[(IOTA & 2097151)] = fTemp302;
			iRec96[0] = (iTemp26?iSlow214:iRec96[1]);
			iRec97[0] = (iTemp28?iSlow214:iRec97[1]);
			double fTemp303 = ((0.5 * (fTemp4 * fVec45[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec96[0]))) & 2097151)])) + (fTemp27 * fVec45[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec97[0]))) & 2097151)]));
			int iTemp304 = (fTemp303 > 1.0);
			int iTemp305 = (fTemp303 < -1.0);
			double fTemp306 = (double((iTemp304 - iTemp305)) + (fTemp303 * double(((1 - iTemp305) * (1 - iTemp304)))));
			double fTemp307 = (fSlow31 * fTemp306);
			fVec46[(IOTA & 524287)] = fTemp307;
			double fTemp308 = (fRec99[1] + (fSlow215 / fRec43[0]));
			fRec99[0] = (fTemp308 - std::floor(fTemp308));
			double fTemp309 = (fRec99[0] - std::floor(fRec99[0]));
			fVec47[0] = fTemp309;
			fRec98[0] = (((fTemp309 > 0.001) * (fVec47[1] <= 0.001))?fRec43[0]:fRec98[1]);
			double fTemp310 = (fConst3 * (fRec98[0] * fTemp309));
			int iTemp311 = int(fTemp310);
			double fTemp312 = std::floor(fTemp310);
			double fTemp313 = (0.5 * fTemp309);
			double fTemp314 = (65536.0 * (fTemp313 - std::floor(fTemp313)));
			int iTemp315 = int(fTemp314);
			double fTemp316 = ftbl0mydspSIG0[iTemp315];
			double fTemp317 = (fRec99[0] + (0.25 - std::floor((fRec99[0] + 0.25))));
			fVec48[0] = fTemp317;
			fRec100[0] = (((fTemp317 > 0.001) * (fVec48[1] <= 0.001))?fRec43[0]:fRec100[1]);
			double fTemp318 = (fConst3 * (fRec100[0] * fTemp317));
			int iTemp319 = int(fTemp318);
			double fTemp320 = std::floor(fTemp318);
			double fTemp321 = (0.5 * fTemp317);
			double fTemp322 = (65536.0 * (fTemp321 - std::floor(fTemp321)));
			int iTemp323 = int(fTemp322);
			double fTemp324 = ftbl0mydspSIG0[iTemp323];
			double fTemp325 = (fRec99[0] + (0.5 - std::floor((fRec99[0] + 0.5))));
			fVec49[0] = fTemp325;
			fRec101[0] = (((fTemp325 > 0.001) * (fVec49[1] <= 0.001))?fRec43[0]:fRec101[1]);
			double fTemp326 = (fConst3 * (fRec101[0] * fTemp325));
			int iTemp327 = int(fTemp326);
			double fTemp328 = std::floor(fTemp326);
			double fTemp329 = (0.5 * fTemp325);
			double fTemp330 = (65536.0 * (fTemp329 - std::floor(fTemp329)));
			int iTemp331 = int(fTemp330);
			double fTemp332 = ftbl0mydspSIG0[iTemp331];
			double fTemp333 = (fRec99[0] + (0.75 - std::floor((fRec99[0] + 0.75))));
			fVec50[0] = fTemp333;
			fRec102[0] = (((fTemp333 > 0.001) * (fVec50[1] <= 0.001))?fRec43[0]:fRec102[1]);
			double fTemp334 = (fConst3 * (fRec102[0] * fTemp333));
			int iTemp335 = int(fTemp334);
			double fTemp336 = std::floor(fTemp334);
			double fTemp337 = (0.5 * fTemp333);
			double fTemp338 = (65536.0 * (fTemp337 - std::floor(fTemp337)));
			int iTemp339 = int(fTemp338);
			double fTemp340 = ftbl0mydspSIG0[iTemp339];
			fRec8[0] = (((((((fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp311))) & 524287)] * (fTemp312 + (1.0 - fTemp310))) + ((fTemp310 - fTemp312) * fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp311 + 1)))) & 524287)])) * (fTemp316 + ((fTemp314 - std::floor(fTemp314)) * (ftbl0mydspSIG0[((iTemp315 + 1) % 65536)] - fTemp316)))) + (((fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp319))) & 524287)] * (fTemp320 + (1.0 - fTemp318))) + ((fTemp318 - fTemp320) * fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp319 + 1)))) & 524287)])) * (fTemp324 + ((fTemp322 - std::floor(fTemp322)) * (ftbl0mydspSIG0[((iTemp323 + 1) % 65536)] - fTemp324))))) + (((fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp327))) & 524287)] * (fTemp328 + (1.0 - fTemp326))) + ((fTemp326 - fTemp328) * fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp327 + 1)))) & 524287)])) * (fTemp332 + ((fTemp330 - std::floor(fTemp330)) * (ftbl0mydspSIG0[((iTemp331 + 1) % 65536)] - fTemp332))))) + (((fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp335))) & 524287)] * (fTemp336 + (1.0 - fTemp334))) + ((fTemp334 - fTemp336) * fVec46[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp335 + 1)))) & 524287)])) * (fTemp340 + ((fTemp338 - std::floor(fTemp338)) * (ftbl0mydspSIG0[((iTemp339 + 1) % 65536)] - fTemp340))))) + (fSlow216 * fTemp306));
			fRec103[0] = (fSlow233 + (fSlow0 * fRec103[1]));
			double fTemp341 = (((((fSlow217 * fTemp17) + ((fSlow218 * fTemp16) + ((((((((((((fSlow219 * fTemp5) + (fSlow220 * fTemp6)) + (fSlow221 * fTemp7)) + (fSlow222 * fTemp8)) + (fSlow223 * fTemp9)) + (fSlow224 * fTemp10)) + (fSlow225 * fTemp11)) + (fSlow226 * fTemp12)) + (fSlow227 * fTemp13)) + (fSlow228 * fTemp14)) + (fSlow229 * fTemp15)) + (fSlow230 * fTemp18)))) + (fSlow231 * fTemp19)) + (fSlow232 * fTemp20)) + (((fRec103[0] * fTemp21) * fTemp22) * fTemp23));
			fVec51[(IOTA & 2097151)] = fTemp341;
			iRec104[0] = (iTemp26?iSlow234:iRec104[1]);
			iRec105[0] = (iTemp28?iSlow234:iRec105[1]);
			double fTemp342 = ((0.5 * (fTemp4 * fVec51[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec104[0]))) & 2097151)])) + (fTemp27 * fVec51[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec105[0]))) & 2097151)]));
			int iTemp343 = (fTemp342 > 1.0);
			int iTemp344 = (fTemp342 < -1.0);
			double fTemp345 = (double((iTemp343 - iTemp344)) + (fTemp342 * double(((1 - iTemp344) * (1 - iTemp343)))));
			double fTemp346 = (fSlow35 * fTemp345);
			fVec52[(IOTA & 524287)] = fTemp346;
			double fTemp347 = (fRec107[1] + (fSlow235 / fRec43[0]));
			fRec107[0] = (fTemp347 - std::floor(fTemp347));
			double fTemp348 = (fRec107[0] - std::floor(fRec107[0]));
			fVec53[0] = fTemp348;
			fRec106[0] = (((fTemp348 > 0.001) * (fVec53[1] <= 0.001))?fRec43[0]:fRec106[1]);
			double fTemp349 = (fConst3 * (fRec106[0] * fTemp348));
			int iTemp350 = int(fTemp349);
			double fTemp351 = std::floor(fTemp349);
			double fTemp352 = (0.5 * fTemp348);
			double fTemp353 = (65536.0 * (fTemp352 - std::floor(fTemp352)));
			int iTemp354 = int(fTemp353);
			double fTemp355 = ftbl0mydspSIG0[iTemp354];
			double fTemp356 = (fRec107[0] + (0.25 - std::floor((fRec107[0] + 0.25))));
			fVec54[0] = fTemp356;
			fRec108[0] = (((fTemp356 > 0.001) * (fVec54[1] <= 0.001))?fRec43[0]:fRec108[1]);
			double fTemp357 = (fConst3 * (fRec108[0] * fTemp356));
			int iTemp358 = int(fTemp357);
			double fTemp359 = std::floor(fTemp357);
			double fTemp360 = (0.5 * fTemp356);
			double fTemp361 = (65536.0 * (fTemp360 - std::floor(fTemp360)));
			int iTemp362 = int(fTemp361);
			double fTemp363 = ftbl0mydspSIG0[iTemp362];
			double fTemp364 = (fRec107[0] + (0.5 - std::floor((fRec107[0] + 0.5))));
			fVec55[0] = fTemp364;
			fRec109[0] = (((fTemp364 > 0.001) * (fVec55[1] <= 0.001))?fRec43[0]:fRec109[1]);
			double fTemp365 = (fConst3 * (fRec109[0] * fTemp364));
			int iTemp366 = int(fTemp365);
			double fTemp367 = std::floor(fTemp365);
			double fTemp368 = (0.5 * fTemp364);
			double fTemp369 = (65536.0 * (fTemp368 - std::floor(fTemp368)));
			int iTemp370 = int(fTemp369);
			double fTemp371 = ftbl0mydspSIG0[iTemp370];
			double fTemp372 = (fRec107[0] + (0.75 - std::floor((fRec107[0] + 0.75))));
			fVec56[0] = fTemp372;
			fRec110[0] = (((fTemp372 > 0.001) * (fVec56[1] <= 0.001))?fRec43[0]:fRec110[1]);
			double fTemp373 = (fConst3 * (fRec110[0] * fTemp372));
			int iTemp374 = int(fTemp373);
			double fTemp375 = std::floor(fTemp373);
			double fTemp376 = (0.5 * fTemp372);
			double fTemp377 = (65536.0 * (fTemp376 - std::floor(fTemp376)));
			int iTemp378 = int(fTemp377);
			double fTemp379 = ftbl0mydspSIG0[iTemp378];
			fRec9[0] = (((((((fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp350))) & 524287)] * (fTemp351 + (1.0 - fTemp349))) + ((fTemp349 - fTemp351) * fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp350 + 1)))) & 524287)])) * (fTemp355 + ((fTemp353 - std::floor(fTemp353)) * (ftbl0mydspSIG0[((iTemp354 + 1) % 65536)] - fTemp355)))) + (((fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp358))) & 524287)] * (fTemp359 + (1.0 - fTemp357))) + ((fTemp357 - fTemp359) * fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp358 + 1)))) & 524287)])) * (fTemp363 + ((fTemp361 - std::floor(fTemp361)) * (ftbl0mydspSIG0[((iTemp362 + 1) % 65536)] - fTemp363))))) + (((fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp366))) & 524287)] * (fTemp367 + (1.0 - fTemp365))) + ((fTemp365 - fTemp367) * fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp366 + 1)))) & 524287)])) * (fTemp371 + ((fTemp369 - std::floor(fTemp369)) * (ftbl0mydspSIG0[((iTemp370 + 1) % 65536)] - fTemp371))))) + (((fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp374))) & 524287)] * (fTemp375 + (1.0 - fTemp373))) + ((fTemp373 - fTemp375) * fVec52[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp374 + 1)))) & 524287)])) * (fTemp379 + ((fTemp377 - std::floor(fTemp377)) * (ftbl0mydspSIG0[((iTemp378 + 1) % 65536)] - fTemp379))))) + (fSlow236 * fTemp345));
			fRec111[0] = (fSlow253 + (fSlow0 * fRec111[1]));
			double fTemp380 = (((((((((((((((((fSlow237 * fTemp5) + (fSlow238 * fTemp6)) + (fSlow239 * fTemp7)) + (fSlow240 * fTemp8)) + (fSlow241 * fTemp9)) + (fSlow242 * fTemp10)) + (fSlow243 * fTemp11)) + (fSlow244 * fTemp12)) + (fSlow245 * fTemp13)) + (fSlow246 * fTemp14)) + (fSlow247 * fTemp15)) + (fSlow248 * fTemp16)) + (fSlow249 * fTemp17)) + (fSlow250 * fTemp18)) + (fSlow251 * fTemp19)) + (fSlow252 * fTemp20)) + (((fRec111[0] * fTemp21) * fTemp22) * fTemp23));
			fVec57[(IOTA & 2097151)] = fTemp380;
			iRec112[0] = (iTemp26?iSlow254:iRec112[1]);
			iRec113[0] = (iTemp28?iSlow254:iRec113[1]);
			double fTemp381 = ((0.5 * (fTemp4 * fVec57[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec112[0]))) & 2097151)])) + (fTemp27 * fVec57[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec113[0]))) & 2097151)]));
			int iTemp382 = (fTemp381 > 1.0);
			int iTemp383 = (fTemp381 < -1.0);
			double fTemp384 = (double((iTemp382 - iTemp383)) + (fTemp381 * double(((1 - iTemp383) * (1 - iTemp382)))));
			double fTemp385 = (fSlow39 * fTemp384);
			fVec58[(IOTA & 524287)] = fTemp385;
			double fTemp386 = (fRec115[1] + (fSlow255 / fRec43[0]));
			fRec115[0] = (fTemp386 - std::floor(fTemp386));
			double fTemp387 = (fRec115[0] - std::floor(fRec115[0]));
			fVec59[0] = fTemp387;
			fRec114[0] = (((fTemp387 > 0.001) * (fVec59[1] <= 0.001))?fRec43[0]:fRec114[1]);
			double fTemp388 = (fConst3 * (fRec114[0] * fTemp387));
			int iTemp389 = int(fTemp388);
			double fTemp390 = std::floor(fTemp388);
			double fTemp391 = (0.5 * fTemp387);
			double fTemp392 = (65536.0 * (fTemp391 - std::floor(fTemp391)));
			int iTemp393 = int(fTemp392);
			double fTemp394 = ftbl0mydspSIG0[iTemp393];
			double fTemp395 = (fRec115[0] + (0.25 - std::floor((fRec115[0] + 0.25))));
			fVec60[0] = fTemp395;
			fRec116[0] = (((fTemp395 > 0.001) * (fVec60[1] <= 0.001))?fRec43[0]:fRec116[1]);
			double fTemp396 = (fConst3 * (fRec116[0] * fTemp395));
			int iTemp397 = int(fTemp396);
			double fTemp398 = std::floor(fTemp396);
			double fTemp399 = (0.5 * fTemp395);
			double fTemp400 = (65536.0 * (fTemp399 - std::floor(fTemp399)));
			int iTemp401 = int(fTemp400);
			double fTemp402 = ftbl0mydspSIG0[iTemp401];
			double fTemp403 = (fRec115[0] + (0.5 - std::floor((fRec115[0] + 0.5))));
			fVec61[0] = fTemp403;
			fRec117[0] = (((fTemp403 > 0.001) * (fVec61[1] <= 0.001))?fRec43[0]:fRec117[1]);
			double fTemp404 = (fConst3 * (fRec117[0] * fTemp403));
			int iTemp405 = int(fTemp404);
			double fTemp406 = std::floor(fTemp404);
			double fTemp407 = (0.5 * fTemp403);
			double fTemp408 = (65536.0 * (fTemp407 - std::floor(fTemp407)));
			int iTemp409 = int(fTemp408);
			double fTemp410 = ftbl0mydspSIG0[iTemp409];
			double fTemp411 = (fRec115[0] + (0.75 - std::floor((fRec115[0] + 0.75))));
			fVec62[0] = fTemp411;
			fRec118[0] = (((fTemp411 > 0.001) * (fVec62[1] <= 0.001))?fRec43[0]:fRec118[1]);
			double fTemp412 = (fConst3 * (fRec118[0] * fTemp411));
			int iTemp413 = int(fTemp412);
			double fTemp414 = std::floor(fTemp412);
			double fTemp415 = (0.5 * fTemp411);
			double fTemp416 = (65536.0 * (fTemp415 - std::floor(fTemp415)));
			int iTemp417 = int(fTemp416);
			double fTemp418 = ftbl0mydspSIG0[iTemp417];
			fRec10[0] = (((((((fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp389))) & 524287)] * (fTemp390 + (1.0 - fTemp388))) + ((fTemp388 - fTemp390) * fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp389 + 1)))) & 524287)])) * (fTemp394 + ((fTemp392 - std::floor(fTemp392)) * (ftbl0mydspSIG0[((iTemp393 + 1) % 65536)] - fTemp394)))) + (((fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp397))) & 524287)] * (fTemp398 + (1.0 - fTemp396))) + ((fTemp396 - fTemp398) * fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp397 + 1)))) & 524287)])) * (fTemp402 + ((fTemp400 - std::floor(fTemp400)) * (ftbl0mydspSIG0[((iTemp401 + 1) % 65536)] - fTemp402))))) + (((fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp405))) & 524287)] * (fTemp406 + (1.0 - fTemp404))) + ((fTemp404 - fTemp406) * fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp405 + 1)))) & 524287)])) * (fTemp410 + ((fTemp408 - std::floor(fTemp408)) * (ftbl0mydspSIG0[((iTemp409 + 1) % 65536)] - fTemp410))))) + (((fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp413))) & 524287)] * (fTemp414 + (1.0 - fTemp412))) + ((fTemp412 - fTemp414) * fVec58[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp413 + 1)))) & 524287)])) * (fTemp418 + ((fTemp416 - std::floor(fTemp416)) * (ftbl0mydspSIG0[((iTemp417 + 1) % 65536)] - fTemp418))))) + (fSlow256 * fTemp384));
			fRec119[0] = (fSlow273 + (fSlow0 * fRec119[1]));
			double fTemp419 = (((((((((((((((((fSlow257 * fTemp5) + (fSlow258 * fTemp6)) + (fSlow259 * fTemp7)) + (fSlow260 * fTemp8)) + (fSlow261 * fTemp9)) + (fSlow262 * fTemp10)) + (fSlow263 * fTemp11)) + (fSlow264 * fTemp12)) + (fSlow265 * fTemp13)) + (fSlow266 * fTemp14)) + (fSlow267 * fTemp15)) + (fSlow268 * fTemp16)) + (fSlow269 * fTemp17)) + (fSlow270 * fTemp18)) + (fSlow271 * fTemp19)) + (fSlow272 * fTemp20)) + (((fRec119[0] * fTemp21) * fTemp22) * fTemp23));
			fVec63[(IOTA & 2097151)] = fTemp419;
			iRec120[0] = (iTemp26?iSlow274:iRec120[1]);
			iRec121[0] = (iTemp28?iSlow274:iRec121[1]);
			double fTemp420 = ((0.5 * (fTemp4 * fVec63[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec120[0]))) & 2097151)])) + (fTemp27 * fVec63[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec121[0]))) & 2097151)]));
			int iTemp421 = (fTemp420 > 1.0);
			int iTemp422 = (fTemp420 < -1.0);
			double fTemp423 = (double((iTemp421 - iTemp422)) + (fTemp420 * double(((1 - iTemp422) * (1 - iTemp421)))));
			double fTemp424 = (fSlow43 * fTemp423);
			fVec64[(IOTA & 524287)] = fTemp424;
			double fTemp425 = (fRec123[1] + (fSlow275 / fRec43[0]));
			fRec123[0] = (fTemp425 - std::floor(fTemp425));
			double fTemp426 = (fRec123[0] - std::floor(fRec123[0]));
			fVec65[0] = fTemp426;
			fRec122[0] = (((fTemp426 > 0.001) * (fVec65[1] <= 0.001))?fRec43[0]:fRec122[1]);
			double fTemp427 = (fConst3 * (fRec122[0] * fTemp426));
			int iTemp428 = int(fTemp427);
			double fTemp429 = std::floor(fTemp427);
			double fTemp430 = (0.5 * fTemp426);
			double fTemp431 = (65536.0 * (fTemp430 - std::floor(fTemp430)));
			int iTemp432 = int(fTemp431);
			double fTemp433 = ftbl0mydspSIG0[iTemp432];
			double fTemp434 = (fRec123[0] + (0.25 - std::floor((fRec123[0] + 0.25))));
			fVec66[0] = fTemp434;
			fRec124[0] = (((fTemp434 > 0.001) * (fVec66[1] <= 0.001))?fRec43[0]:fRec124[1]);
			double fTemp435 = (fConst3 * (fRec124[0] * fTemp434));
			int iTemp436 = int(fTemp435);
			double fTemp437 = std::floor(fTemp435);
			double fTemp438 = (0.5 * fTemp434);
			double fTemp439 = (65536.0 * (fTemp438 - std::floor(fTemp438)));
			int iTemp440 = int(fTemp439);
			double fTemp441 = ftbl0mydspSIG0[iTemp440];
			double fTemp442 = (fRec123[0] + (0.5 - std::floor((fRec123[0] + 0.5))));
			fVec67[0] = fTemp442;
			fRec125[0] = (((fTemp442 > 0.001) * (fVec67[1] <= 0.001))?fRec43[0]:fRec125[1]);
			double fTemp443 = (fConst3 * (fRec125[0] * fTemp442));
			int iTemp444 = int(fTemp443);
			double fTemp445 = std::floor(fTemp443);
			double fTemp446 = (0.5 * fTemp442);
			double fTemp447 = (65536.0 * (fTemp446 - std::floor(fTemp446)));
			int iTemp448 = int(fTemp447);
			double fTemp449 = ftbl0mydspSIG0[iTemp448];
			double fTemp450 = (fRec123[0] + (0.75 - std::floor((fRec123[0] + 0.75))));
			fVec68[0] = fTemp450;
			fRec126[0] = (((fTemp450 > 0.001) * (fVec68[1] <= 0.001))?fRec43[0]:fRec126[1]);
			double fTemp451 = (fConst3 * (fRec126[0] * fTemp450));
			int iTemp452 = int(fTemp451);
			double fTemp453 = std::floor(fTemp451);
			double fTemp454 = (0.5 * fTemp450);
			double fTemp455 = (65536.0 * (fTemp454 - std::floor(fTemp454)));
			int iTemp456 = int(fTemp455);
			double fTemp457 = ftbl0mydspSIG0[iTemp456];
			fRec11[0] = (((((((fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp428))) & 524287)] * (fTemp429 + (1.0 - fTemp427))) + ((fTemp427 - fTemp429) * fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp428 + 1)))) & 524287)])) * (fTemp433 + ((fTemp431 - std::floor(fTemp431)) * (ftbl0mydspSIG0[((iTemp432 + 1) % 65536)] - fTemp433)))) + (((fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp436))) & 524287)] * (fTemp437 + (1.0 - fTemp435))) + ((fTemp435 - fTemp437) * fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp436 + 1)))) & 524287)])) * (fTemp441 + ((fTemp439 - std::floor(fTemp439)) * (ftbl0mydspSIG0[((iTemp440 + 1) % 65536)] - fTemp441))))) + (((fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp444))) & 524287)] * (fTemp445 + (1.0 - fTemp443))) + ((fTemp443 - fTemp445) * fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp444 + 1)))) & 524287)])) * (fTemp449 + ((fTemp447 - std::floor(fTemp447)) * (ftbl0mydspSIG0[((iTemp448 + 1) % 65536)] - fTemp449))))) + (((fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp452))) & 524287)] * (fTemp453 + (1.0 - fTemp451))) + ((fTemp451 - fTemp453) * fVec64[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp452 + 1)))) & 524287)])) * (fTemp457 + ((fTemp455 - std::floor(fTemp455)) * (ftbl0mydspSIG0[((iTemp456 + 1) % 65536)] - fTemp457))))) + (fSlow276 * fTemp423));
			fRec127[0] = (fSlow293 + (fSlow0 * fRec127[1]));
			double fTemp458 = (((((((((((((((((fSlow277 * fTemp5) + (fSlow278 * fTemp6)) + (fSlow279 * fTemp7)) + (fSlow280 * fTemp8)) + (fSlow281 * fTemp9)) + (fSlow282 * fTemp10)) + (fSlow283 * fTemp11)) + (fSlow284 * fTemp12)) + (fSlow285 * fTemp13)) + (fSlow286 * fTemp14)) + (fSlow287 * fTemp15)) + (fSlow288 * fTemp16)) + (fSlow289 * fTemp17)) + (fSlow290 * fTemp18)) + (fSlow291 * fTemp19)) + (fSlow292 * fTemp20)) + (((fRec127[0] * fTemp21) * fTemp22) * fTemp23));
			fVec69[(IOTA & 2097151)] = fTemp458;
			iRec128[0] = (iTemp26?iSlow294:iRec128[1]);
			iRec129[0] = (iTemp28?iSlow294:iRec129[1]);
			double fTemp459 = ((0.5 * (fTemp4 * fVec69[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec128[0]))) & 2097151)])) + (fTemp27 * fVec69[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec129[0]))) & 2097151)]));
			int iTemp460 = (fTemp459 > 1.0);
			int iTemp461 = (fTemp459 < -1.0);
			double fTemp462 = (double((iTemp460 - iTemp461)) + (fTemp459 * double(((1 - iTemp461) * (1 - iTemp460)))));
			double fTemp463 = (fSlow47 * fTemp462);
			fVec70[(IOTA & 524287)] = fTemp463;
			double fTemp464 = (fRec131[1] + (fSlow295 / fRec43[0]));
			fRec131[0] = (fTemp464 - std::floor(fTemp464));
			double fTemp465 = (fRec131[0] - std::floor(fRec131[0]));
			fVec71[0] = fTemp465;
			fRec130[0] = (((fTemp465 > 0.001) * (fVec71[1] <= 0.001))?fRec43[0]:fRec130[1]);
			double fTemp466 = (fConst3 * (fRec130[0] * fTemp465));
			int iTemp467 = int(fTemp466);
			double fTemp468 = std::floor(fTemp466);
			double fTemp469 = (0.5 * fTemp465);
			double fTemp470 = (65536.0 * (fTemp469 - std::floor(fTemp469)));
			int iTemp471 = int(fTemp470);
			double fTemp472 = ftbl0mydspSIG0[iTemp471];
			double fTemp473 = (fRec131[0] + (0.25 - std::floor((fRec131[0] + 0.25))));
			fVec72[0] = fTemp473;
			fRec132[0] = (((fTemp473 > 0.001) * (fVec72[1] <= 0.001))?fRec43[0]:fRec132[1]);
			double fTemp474 = (fConst3 * (fRec132[0] * fTemp473));
			int iTemp475 = int(fTemp474);
			double fTemp476 = std::floor(fTemp474);
			double fTemp477 = (0.5 * fTemp473);
			double fTemp478 = (65536.0 * (fTemp477 - std::floor(fTemp477)));
			int iTemp479 = int(fTemp478);
			double fTemp480 = ftbl0mydspSIG0[iTemp479];
			double fTemp481 = (fRec131[0] + (0.5 - std::floor((fRec131[0] + 0.5))));
			fVec73[0] = fTemp481;
			fRec133[0] = (((fTemp481 > 0.001) * (fVec73[1] <= 0.001))?fRec43[0]:fRec133[1]);
			double fTemp482 = (fConst3 * (fRec133[0] * fTemp481));
			int iTemp483 = int(fTemp482);
			double fTemp484 = std::floor(fTemp482);
			double fTemp485 = (0.5 * fTemp481);
			double fTemp486 = (65536.0 * (fTemp485 - std::floor(fTemp485)));
			int iTemp487 = int(fTemp486);
			double fTemp488 = ftbl0mydspSIG0[iTemp487];
			double fTemp489 = (fRec131[0] + (0.75 - std::floor((fRec131[0] + 0.75))));
			fVec74[0] = fTemp489;
			fRec134[0] = (((fTemp489 > 0.001) * (fVec74[1] <= 0.001))?fRec43[0]:fRec134[1]);
			double fTemp490 = (fConst3 * (fRec134[0] * fTemp489));
			int iTemp491 = int(fTemp490);
			double fTemp492 = std::floor(fTemp490);
			double fTemp493 = (0.5 * fTemp489);
			double fTemp494 = (65536.0 * (fTemp493 - std::floor(fTemp493)));
			int iTemp495 = int(fTemp494);
			double fTemp496 = ftbl0mydspSIG0[iTemp495];
			fRec12[0] = (((((((fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp467))) & 524287)] * (fTemp468 + (1.0 - fTemp466))) + ((fTemp466 - fTemp468) * fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp467 + 1)))) & 524287)])) * (fTemp472 + ((fTemp470 - std::floor(fTemp470)) * (ftbl0mydspSIG0[((iTemp471 + 1) % 65536)] - fTemp472)))) + (((fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp475))) & 524287)] * (fTemp476 + (1.0 - fTemp474))) + ((fTemp474 - fTemp476) * fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp475 + 1)))) & 524287)])) * (fTemp480 + ((fTemp478 - std::floor(fTemp478)) * (ftbl0mydspSIG0[((iTemp479 + 1) % 65536)] - fTemp480))))) + (((fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp483))) & 524287)] * (fTemp484 + (1.0 - fTemp482))) + ((fTemp482 - fTemp484) * fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp483 + 1)))) & 524287)])) * (fTemp488 + ((fTemp486 - std::floor(fTemp486)) * (ftbl0mydspSIG0[((iTemp487 + 1) % 65536)] - fTemp488))))) + (((fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp491))) & 524287)] * (fTemp492 + (1.0 - fTemp490))) + ((fTemp490 - fTemp492) * fVec70[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp491 + 1)))) & 524287)])) * (fTemp496 + ((fTemp494 - std::floor(fTemp494)) * (ftbl0mydspSIG0[((iTemp495 + 1) % 65536)] - fTemp496))))) + (fSlow296 * fTemp462));
			fRec135[0] = (fSlow313 + (fSlow0 * fRec135[1]));
			double fTemp497 = (((((((((((((((((fSlow297 * fTemp5) + (fSlow298 * fTemp6)) + (fSlow299 * fTemp7)) + (fSlow300 * fTemp8)) + (fSlow301 * fTemp9)) + (fSlow302 * fTemp10)) + (fSlow303 * fTemp11)) + (fSlow304 * fTemp12)) + (fSlow305 * fTemp13)) + (fSlow306 * fTemp14)) + (fSlow307 * fTemp15)) + (fSlow308 * fTemp16)) + (fSlow309 * fTemp17)) + (fSlow310 * fTemp18)) + (fSlow311 * fTemp19)) + (fSlow312 * fTemp20)) + (((fRec135[0] * fTemp21) * fTemp22) * fTemp23));
			fVec75[(IOTA & 2097151)] = fTemp497;
			iRec136[0] = (iTemp26?iSlow314:iRec136[1]);
			iRec137[0] = (iTemp28?iSlow314:iRec137[1]);
			double fTemp498 = ((0.5 * (fTemp4 * fVec75[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec136[0]))) & 2097151)])) + (fTemp27 * fVec75[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec137[0]))) & 2097151)]));
			int iTemp499 = (fTemp498 > 1.0);
			int iTemp500 = (fTemp498 < -1.0);
			double fTemp501 = (double((iTemp499 - iTemp500)) + (fTemp498 * double(((1 - iTemp500) * (1 - iTemp499)))));
			double fTemp502 = (fSlow51 * fTemp501);
			fVec76[(IOTA & 524287)] = fTemp502;
			double fTemp503 = (fRec139[1] + (fSlow315 / fRec43[0]));
			fRec139[0] = (fTemp503 - std::floor(fTemp503));
			double fTemp504 = (fRec139[0] - std::floor(fRec139[0]));
			fVec77[0] = fTemp504;
			fRec138[0] = (((fTemp504 > 0.001) * (fVec77[1] <= 0.001))?fRec43[0]:fRec138[1]);
			double fTemp505 = (fConst3 * (fRec138[0] * fTemp504));
			int iTemp506 = int(fTemp505);
			double fTemp507 = std::floor(fTemp505);
			double fTemp508 = (0.5 * fTemp504);
			double fTemp509 = (65536.0 * (fTemp508 - std::floor(fTemp508)));
			int iTemp510 = int(fTemp509);
			double fTemp511 = ftbl0mydspSIG0[iTemp510];
			double fTemp512 = (fRec139[0] + (0.25 - std::floor((fRec139[0] + 0.25))));
			fVec78[0] = fTemp512;
			fRec140[0] = (((fTemp512 > 0.001) * (fVec78[1] <= 0.001))?fRec43[0]:fRec140[1]);
			double fTemp513 = (fConst3 * (fRec140[0] * fTemp512));
			int iTemp514 = int(fTemp513);
			double fTemp515 = std::floor(fTemp513);
			double fTemp516 = (0.5 * fTemp512);
			double fTemp517 = (65536.0 * (fTemp516 - std::floor(fTemp516)));
			int iTemp518 = int(fTemp517);
			double fTemp519 = ftbl0mydspSIG0[iTemp518];
			double fTemp520 = (fRec139[0] + (0.5 - std::floor((fRec139[0] + 0.5))));
			fVec79[0] = fTemp520;
			fRec141[0] = (((fTemp520 > 0.001) * (fVec79[1] <= 0.001))?fRec43[0]:fRec141[1]);
			double fTemp521 = (fConst3 * (fRec141[0] * fTemp520));
			int iTemp522 = int(fTemp521);
			double fTemp523 = std::floor(fTemp521);
			double fTemp524 = (0.5 * fTemp520);
			double fTemp525 = (65536.0 * (fTemp524 - std::floor(fTemp524)));
			int iTemp526 = int(fTemp525);
			double fTemp527 = ftbl0mydspSIG0[iTemp526];
			double fTemp528 = (fRec139[0] + (0.75 - std::floor((fRec139[0] + 0.75))));
			fVec80[0] = fTemp528;
			fRec142[0] = (((fTemp528 > 0.001) * (fVec80[1] <= 0.001))?fRec43[0]:fRec142[1]);
			double fTemp529 = (fConst3 * (fRec142[0] * fTemp528));
			int iTemp530 = int(fTemp529);
			double fTemp531 = std::floor(fTemp529);
			double fTemp532 = (0.5 * fTemp528);
			double fTemp533 = (65536.0 * (fTemp532 - std::floor(fTemp532)));
			int iTemp534 = int(fTemp533);
			double fTemp535 = ftbl0mydspSIG0[iTemp534];
			fRec13[0] = (((((((fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp506))) & 524287)] * (fTemp507 + (1.0 - fTemp505))) + ((fTemp505 - fTemp507) * fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp506 + 1)))) & 524287)])) * (fTemp511 + ((fTemp509 - std::floor(fTemp509)) * (ftbl0mydspSIG0[((iTemp510 + 1) % 65536)] - fTemp511)))) + (((fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp514))) & 524287)] * (fTemp515 + (1.0 - fTemp513))) + ((fTemp513 - fTemp515) * fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp514 + 1)))) & 524287)])) * (fTemp519 + ((fTemp517 - std::floor(fTemp517)) * (ftbl0mydspSIG0[((iTemp518 + 1) % 65536)] - fTemp519))))) + (((fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp522))) & 524287)] * (fTemp523 + (1.0 - fTemp521))) + ((fTemp521 - fTemp523) * fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp522 + 1)))) & 524287)])) * (fTemp527 + ((fTemp525 - std::floor(fTemp525)) * (ftbl0mydspSIG0[((iTemp526 + 1) % 65536)] - fTemp527))))) + (((fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp530))) & 524287)] * (fTemp531 + (1.0 - fTemp529))) + ((fTemp529 - fTemp531) * fVec76[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp530 + 1)))) & 524287)])) * (fTemp535 + ((fTemp533 - std::floor(fTemp533)) * (ftbl0mydspSIG0[((iTemp534 + 1) % 65536)] - fTemp535))))) + (fSlow316 * fTemp501));
			fRec143[0] = (fSlow333 + (fSlow0 * fRec143[1]));
			double fTemp536 = (((((((((((((((((fSlow317 * fTemp5) + (fSlow318 * fTemp6)) + (fSlow319 * fTemp7)) + (fSlow320 * fTemp8)) + (fSlow321 * fTemp9)) + (fSlow322 * fTemp10)) + (fSlow323 * fTemp11)) + (fSlow324 * fTemp12)) + (fSlow325 * fTemp13)) + (fSlow326 * fTemp14)) + (fSlow327 * fTemp15)) + (fSlow328 * fTemp16)) + (fSlow329 * fTemp17)) + (fSlow330 * fTemp18)) + (fSlow331 * fTemp19)) + (fSlow332 * fTemp20)) + (((fRec143[0] * fTemp21) * fTemp22) * fTemp23));
			fVec81[(IOTA & 2097151)] = fTemp536;
			iRec144[0] = (iTemp26?iSlow334:iRec144[1]);
			iRec145[0] = (iTemp28?iSlow334:iRec145[1]);
			double fTemp537 = ((0.5 * (fTemp4 * fVec81[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec144[0]))) & 2097151)])) + (fTemp27 * fVec81[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec145[0]))) & 2097151)]));
			int iTemp538 = (fTemp537 > 1.0);
			int iTemp539 = (fTemp537 < -1.0);
			double fTemp540 = (double((iTemp538 - iTemp539)) + (fTemp537 * double(((1 - iTemp539) * (1 - iTemp538)))));
			double fTemp541 = (fSlow55 * fTemp540);
			fVec82[(IOTA & 524287)] = fTemp541;
			double fTemp542 = (fRec147[1] + (fSlow335 / fRec43[0]));
			fRec147[0] = (fTemp542 - std::floor(fTemp542));
			double fTemp543 = (fRec147[0] - std::floor(fRec147[0]));
			fVec83[0] = fTemp543;
			fRec146[0] = (((fTemp543 > 0.001) * (fVec83[1] <= 0.001))?fRec43[0]:fRec146[1]);
			double fTemp544 = (fConst3 * (fRec146[0] * fTemp543));
			int iTemp545 = int(fTemp544);
			double fTemp546 = std::floor(fTemp544);
			double fTemp547 = (0.5 * fTemp543);
			double fTemp548 = (65536.0 * (fTemp547 - std::floor(fTemp547)));
			int iTemp549 = int(fTemp548);
			double fTemp550 = ftbl0mydspSIG0[iTemp549];
			double fTemp551 = (fRec147[0] + (0.25 - std::floor((fRec147[0] + 0.25))));
			fVec84[0] = fTemp551;
			fRec148[0] = (((fTemp551 > 0.001) * (fVec84[1] <= 0.001))?fRec43[0]:fRec148[1]);
			double fTemp552 = (fConst3 * (fRec148[0] * fTemp551));
			int iTemp553 = int(fTemp552);
			double fTemp554 = std::floor(fTemp552);
			double fTemp555 = (0.5 * fTemp551);
			double fTemp556 = (65536.0 * (fTemp555 - std::floor(fTemp555)));
			int iTemp557 = int(fTemp556);
			double fTemp558 = ftbl0mydspSIG0[iTemp557];
			double fTemp559 = (fRec147[0] + (0.5 - std::floor((fRec147[0] + 0.5))));
			fVec85[0] = fTemp559;
			fRec149[0] = (((fTemp559 > 0.001) * (fVec85[1] <= 0.001))?fRec43[0]:fRec149[1]);
			double fTemp560 = (fConst3 * (fRec149[0] * fTemp559));
			int iTemp561 = int(fTemp560);
			double fTemp562 = std::floor(fTemp560);
			double fTemp563 = (0.5 * fTemp559);
			double fTemp564 = (65536.0 * (fTemp563 - std::floor(fTemp563)));
			int iTemp565 = int(fTemp564);
			double fTemp566 = ftbl0mydspSIG0[iTemp565];
			double fTemp567 = (fRec147[0] + (0.75 - std::floor((fRec147[0] + 0.75))));
			fVec86[0] = fTemp567;
			fRec150[0] = (((fTemp567 > 0.001) * (fVec86[1] <= 0.001))?fRec43[0]:fRec150[1]);
			double fTemp568 = (fConst3 * (fRec150[0] * fTemp567));
			int iTemp569 = int(fTemp568);
			double fTemp570 = std::floor(fTemp568);
			double fTemp571 = (0.5 * fTemp567);
			double fTemp572 = (65536.0 * (fTemp571 - std::floor(fTemp571)));
			int iTemp573 = int(fTemp572);
			double fTemp574 = ftbl0mydspSIG0[iTemp573];
			fRec14[0] = (((((((fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp545))) & 524287)] * (fTemp546 + (1.0 - fTemp544))) + ((fTemp544 - fTemp546) * fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp545 + 1)))) & 524287)])) * (fTemp550 + ((fTemp548 - std::floor(fTemp548)) * (ftbl0mydspSIG0[((iTemp549 + 1) % 65536)] - fTemp550)))) + (((fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp553))) & 524287)] * (fTemp554 + (1.0 - fTemp552))) + ((fTemp552 - fTemp554) * fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp553 + 1)))) & 524287)])) * (fTemp558 + ((fTemp556 - std::floor(fTemp556)) * (ftbl0mydspSIG0[((iTemp557 + 1) % 65536)] - fTemp558))))) + (((fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp561))) & 524287)] * (fTemp562 + (1.0 - fTemp560))) + ((fTemp560 - fTemp562) * fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp561 + 1)))) & 524287)])) * (fTemp566 + ((fTemp564 - std::floor(fTemp564)) * (ftbl0mydspSIG0[((iTemp565 + 1) % 65536)] - fTemp566))))) + (((fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp569))) & 524287)] * (fTemp570 + (1.0 - fTemp568))) + ((fTemp568 - fTemp570) * fVec82[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp569 + 1)))) & 524287)])) * (fTemp574 + ((fTemp572 - std::floor(fTemp572)) * (ftbl0mydspSIG0[((iTemp573 + 1) % 65536)] - fTemp574))))) + (fSlow336 * fTemp540));
			fRec151[0] = (fSlow353 + (fSlow0 * fRec151[1]));
			double fTemp575 = (((((((((((((((((fSlow337 * fTemp5) + (fSlow338 * fTemp6)) + (fSlow339 * fTemp7)) + (fSlow340 * fTemp8)) + (fSlow341 * fTemp9)) + (fSlow342 * fTemp10)) + (fSlow343 * fTemp11)) + (fSlow344 * fTemp12)) + (fSlow345 * fTemp13)) + (fSlow346 * fTemp14)) + (fSlow347 * fTemp15)) + (fSlow348 * fTemp16)) + (fSlow349 * fTemp17)) + (fSlow350 * fTemp18)) + (fSlow351 * fTemp19)) + (fSlow352 * fTemp20)) + (((fRec151[0] * fTemp21) * fTemp22) * fTemp23));
			fVec87[(IOTA & 2097151)] = fTemp575;
			iRec152[0] = (iTemp26?iSlow354:iRec152[1]);
			iRec153[0] = (iTemp28?iSlow354:iRec153[1]);
			double fTemp576 = ((0.5 * (fTemp4 * fVec87[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec152[0]))) & 2097151)])) + (fTemp27 * fVec87[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec153[0]))) & 2097151)]));
			int iTemp577 = (fTemp576 > 1.0);
			int iTemp578 = (fTemp576 < -1.0);
			double fTemp579 = (double((iTemp577 - iTemp578)) + (fTemp576 * double(((1 - iTemp578) * (1 - iTemp577)))));
			double fTemp580 = (fSlow59 * fTemp579);
			fVec88[(IOTA & 524287)] = fTemp580;
			double fTemp581 = (fRec155[1] + (fSlow355 / fRec43[0]));
			fRec155[0] = (fTemp581 - std::floor(fTemp581));
			double fTemp582 = (fRec155[0] - std::floor(fRec155[0]));
			fVec89[0] = fTemp582;
			fRec154[0] = (((fTemp582 > 0.001) * (fVec89[1] <= 0.001))?fRec43[0]:fRec154[1]);
			double fTemp583 = (fConst3 * (fRec154[0] * fTemp582));
			int iTemp584 = int(fTemp583);
			double fTemp585 = std::floor(fTemp583);
			double fTemp586 = (0.5 * fTemp582);
			double fTemp587 = (65536.0 * (fTemp586 - std::floor(fTemp586)));
			int iTemp588 = int(fTemp587);
			double fTemp589 = ftbl0mydspSIG0[iTemp588];
			double fTemp590 = (fRec155[0] + (0.25 - std::floor((fRec155[0] + 0.25))));
			fVec90[0] = fTemp590;
			fRec156[0] = (((fTemp590 > 0.001) * (fVec90[1] <= 0.001))?fRec43[0]:fRec156[1]);
			double fTemp591 = (fConst3 * (fRec156[0] * fTemp590));
			int iTemp592 = int(fTemp591);
			double fTemp593 = std::floor(fTemp591);
			double fTemp594 = (0.5 * fTemp590);
			double fTemp595 = (65536.0 * (fTemp594 - std::floor(fTemp594)));
			int iTemp596 = int(fTemp595);
			double fTemp597 = ftbl0mydspSIG0[iTemp596];
			double fTemp598 = (fRec155[0] + (0.5 - std::floor((fRec155[0] + 0.5))));
			fVec91[0] = fTemp598;
			fRec157[0] = (((fTemp598 > 0.001) * (fVec91[1] <= 0.001))?fRec43[0]:fRec157[1]);
			double fTemp599 = (fConst3 * (fRec157[0] * fTemp598));
			int iTemp600 = int(fTemp599);
			double fTemp601 = std::floor(fTemp599);
			double fTemp602 = (0.5 * fTemp598);
			double fTemp603 = (65536.0 * (fTemp602 - std::floor(fTemp602)));
			int iTemp604 = int(fTemp603);
			double fTemp605 = ftbl0mydspSIG0[iTemp604];
			double fTemp606 = (fRec155[0] + (0.75 - std::floor((fRec155[0] + 0.75))));
			fVec92[0] = fTemp606;
			fRec158[0] = (((fTemp606 > 0.001) * (fVec92[1] <= 0.001))?fRec43[0]:fRec158[1]);
			double fTemp607 = (fConst3 * (fRec158[0] * fTemp606));
			int iTemp608 = int(fTemp607);
			double fTemp609 = std::floor(fTemp607);
			double fTemp610 = (0.5 * fTemp606);
			double fTemp611 = (65536.0 * (fTemp610 - std::floor(fTemp610)));
			int iTemp612 = int(fTemp611);
			double fTemp613 = ftbl0mydspSIG0[iTemp612];
			fRec15[0] = (((((((fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp584))) & 524287)] * (fTemp585 + (1.0 - fTemp583))) + ((fTemp583 - fTemp585) * fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp584 + 1)))) & 524287)])) * (fTemp589 + ((fTemp587 - std::floor(fTemp587)) * (ftbl0mydspSIG0[((iTemp588 + 1) % 65536)] - fTemp589)))) + (((fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp592))) & 524287)] * (fTemp593 + (1.0 - fTemp591))) + ((fTemp591 - fTemp593) * fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp592 + 1)))) & 524287)])) * (fTemp597 + ((fTemp595 - std::floor(fTemp595)) * (ftbl0mydspSIG0[((iTemp596 + 1) % 65536)] - fTemp597))))) + (((fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp600))) & 524287)] * (fTemp601 + (1.0 - fTemp599))) + ((fTemp599 - fTemp601) * fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp600 + 1)))) & 524287)])) * (fTemp605 + ((fTemp603 - std::floor(fTemp603)) * (ftbl0mydspSIG0[((iTemp604 + 1) % 65536)] - fTemp605))))) + (((fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp608))) & 524287)] * (fTemp609 + (1.0 - fTemp607))) + ((fTemp607 - fTemp609) * fVec88[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp608 + 1)))) & 524287)])) * (fTemp613 + ((fTemp611 - std::floor(fTemp611)) * (ftbl0mydspSIG0[((iTemp612 + 1) % 65536)] - fTemp613))))) + (fSlow356 * fTemp579));
			fRec159[0] = (fSlow373 + (fSlow0 * fRec159[1]));
			double fTemp614 = ((fSlow357 * fTemp20) + ((((((((((((((((fSlow358 * fTemp5) + (fSlow359 * fTemp6)) + (fSlow360 * fTemp7)) + (fSlow361 * fTemp8)) + (fSlow362 * fTemp9)) + (fSlow363 * fTemp10)) + (fSlow364 * fTemp11)) + (fSlow365 * fTemp12)) + (fSlow366 * fTemp13)) + (fSlow367 * fTemp14)) + (fSlow368 * fTemp15)) + (fSlow369 * fTemp16)) + (fSlow370 * fTemp17)) + (fSlow371 * fTemp18)) + (fSlow372 * fTemp19)) + (((fRec159[0] * fTemp21) * fTemp22) * fTemp23)));
			fVec93[(IOTA & 2097151)] = fTemp614;
			iRec160[0] = (iTemp26?iSlow374:iRec160[1]);
			iRec161[0] = (iTemp28?iSlow374:iRec161[1]);
			double fTemp615 = ((0.5 * (fTemp4 * fVec93[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec160[0]))) & 2097151)])) + (fTemp27 * fVec93[((IOTA - std::min<int>(1048576, std::max<int>(0, iRec161[0]))) & 2097151)]));
			int iTemp616 = (fTemp615 > 1.0);
			int iTemp617 = (fTemp615 < -1.0);
			double fTemp618 = (double((iTemp616 - iTemp617)) + (fTemp615 * double(((1 - iTemp617) * (1 - iTemp616)))));
			double fTemp619 = (fSlow63 * fTemp618);
			fVec94[(IOTA & 524287)] = fTemp619;
			double fTemp620 = (fRec163[1] + (fSlow375 / fRec43[0]));
			fRec163[0] = (fTemp620 - std::floor(fTemp620));
			double fTemp621 = (fRec163[0] - std::floor(fRec163[0]));
			fVec95[0] = fTemp621;
			fRec162[0] = (((fTemp621 > 0.001) * (fVec95[1] <= 0.001))?fRec43[0]:fRec162[1]);
			double fTemp622 = (fConst3 * (fRec162[0] * fTemp621));
			int iTemp623 = int(fTemp622);
			double fTemp624 = std::floor(fTemp622);
			double fTemp625 = (0.5 * fTemp621);
			double fTemp626 = (65536.0 * (fTemp625 - std::floor(fTemp625)));
			int iTemp627 = int(fTemp626);
			double fTemp628 = ftbl0mydspSIG0[iTemp627];
			double fTemp629 = (fRec163[0] + (0.25 - std::floor((fRec163[0] + 0.25))));
			fVec96[0] = fTemp629;
			fRec164[0] = (((fTemp629 > 0.001) * (fVec96[1] <= 0.001))?fRec43[0]:fRec164[1]);
			double fTemp630 = (fConst3 * (fRec164[0] * fTemp629));
			int iTemp631 = int(fTemp630);
			double fTemp632 = std::floor(fTemp630);
			double fTemp633 = (0.5 * fTemp629);
			double fTemp634 = (65536.0 * (fTemp633 - std::floor(fTemp633)));
			int iTemp635 = int(fTemp634);
			double fTemp636 = ftbl0mydspSIG0[iTemp635];
			double fTemp637 = (fRec163[0] + (0.5 - std::floor((fRec163[0] + 0.5))));
			fVec97[0] = fTemp637;
			fRec165[0] = (((fTemp637 > 0.001) * (fVec97[1] <= 0.001))?fRec43[0]:fRec165[1]);
			double fTemp638 = (fConst3 * (fRec165[0] * fTemp637));
			int iTemp639 = int(fTemp638);
			double fTemp640 = std::floor(fTemp638);
			double fTemp641 = (0.5 * fTemp637);
			double fTemp642 = (65536.0 * (fTemp641 - std::floor(fTemp641)));
			int iTemp643 = int(fTemp642);
			double fTemp644 = ftbl0mydspSIG0[iTemp643];
			double fTemp645 = (fRec163[0] + (0.75 - std::floor((fRec163[0] + 0.75))));
			fVec98[0] = fTemp645;
			fRec166[0] = (((fTemp645 > 0.001) * (fVec98[1] <= 0.001))?fRec43[0]:fRec166[1]);
			double fTemp646 = (fConst3 * (fRec166[0] * fTemp645));
			int iTemp647 = int(fTemp646);
			double fTemp648 = std::floor(fTemp646);
			double fTemp649 = (0.5 * fTemp645);
			double fTemp650 = (65536.0 * (fTemp649 - std::floor(fTemp649)));
			int iTemp651 = int(fTemp650);
			double fTemp652 = ftbl0mydspSIG0[iTemp651];
			fRec16[0] = (((((((fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp623))) & 524287)] * (fTemp624 + (1.0 - fTemp622))) + ((fTemp622 - fTemp624) * fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp623 + 1)))) & 524287)])) * (fTemp628 + ((fTemp626 - std::floor(fTemp626)) * (ftbl0mydspSIG0[((iTemp627 + 1) % 65536)] - fTemp628)))) + (((fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp631))) & 524287)] * (fTemp632 + (1.0 - fTemp630))) + ((fTemp630 - fTemp632) * fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp631 + 1)))) & 524287)])) * (fTemp636 + ((fTemp634 - std::floor(fTemp634)) * (ftbl0mydspSIG0[((iTemp635 + 1) % 65536)] - fTemp636))))) + (((fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp639))) & 524287)] * (fTemp640 + (1.0 - fTemp638))) + ((fTemp638 - fTemp640) * fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp639 + 1)))) & 524287)])) * (fTemp644 + ((fTemp642 - std::floor(fTemp642)) * (ftbl0mydspSIG0[((iTemp643 + 1) % 65536)] - fTemp644))))) + (((fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, iTemp647))) & 524287)] * (fTemp648 + (1.0 - fTemp646))) + ((fTemp646 - fTemp648) * fVec94[((IOTA - std::min<int>(262145, std::max<int>(0, (iTemp647 + 1)))) & 524287)])) * (fTemp652 + ((fTemp650 - std::floor(fTemp650)) * (ftbl0mydspSIG0[((iTemp651 + 1) % 65536)] - fTemp652))))) + (fSlow376 * fTemp618));
			fRec167[0] = (fSlow377 + (fSlow0 * fRec167[1]));
			double fTemp653 = (fRec16[0] * fRec167[0]);
			fRec168[0] = (fSlow378 + (fConst6 * fRec168[1]));
			fRec169[0] = (fSlow379 + (fConst6 * fRec169[1]));
			fRec170[0] = (fSlow380 + (fConst6 * fRec170[1]));
			fRec171[0] = (fSlow381 + (fConst6 * fRec171[1]));
			fRec172[0] = (fSlow382 + (fConst6 * fRec172[1]));
			fRec173[0] = (fSlow383 + (fSlow0 * fRec173[1]));
			double fTemp654 = (fRec15[0] * fRec173[0]);
			fRec174[0] = (fSlow384 + (fConst6 * fRec174[1]));
			fRec175[0] = (fSlow385 + (fConst6 * fRec175[1]));
			fRec176[0] = (fSlow386 + (fConst6 * fRec176[1]));
			fRec177[0] = (fSlow387 + (fConst6 * fRec177[1]));
			fRec178[0] = (fSlow388 + (fConst6 * fRec178[1]));
			fRec179[0] = (fSlow389 + (fSlow0 * fRec179[1]));
			double fTemp655 = (fRec14[0] * fRec179[0]);
			fRec180[0] = (fSlow390 + (fConst6 * fRec180[1]));
			fRec181[0] = (fSlow391 + (fConst6 * fRec181[1]));
			fRec182[0] = (fSlow392 + (fConst6 * fRec182[1]));
			fRec183[0] = (fSlow393 + (fConst6 * fRec183[1]));
			fRec184[0] = (fSlow394 + (fConst6 * fRec184[1]));
			fRec185[0] = (fSlow395 + (fSlow0 * fRec185[1]));
			double fTemp656 = (fRec13[0] * fRec185[0]);
			fRec186[0] = (fSlow396 + (fConst6 * fRec186[1]));
			fRec187[0] = (fSlow397 + (fConst6 * fRec187[1]));
			fRec188[0] = (fSlow398 + (fConst6 * fRec188[1]));
			fRec189[0] = (fSlow399 + (fConst6 * fRec189[1]));
			fRec190[0] = (fSlow400 + (fConst6 * fRec190[1]));
			fRec191[0] = (fSlow401 + (fSlow0 * fRec191[1]));
			double fTemp657 = (fRec12[0] * fRec191[0]);
			fRec192[0] = (fSlow402 + (fConst6 * fRec192[1]));
			fRec193[0] = (fSlow403 + (fConst6 * fRec193[1]));
			fRec194[0] = (fSlow404 + (fConst6 * fRec194[1]));
			fRec195[0] = (fSlow405 + (fConst6 * fRec195[1]));
			fRec196[0] = (fSlow406 + (fConst6 * fRec196[1]));
			fRec197[0] = (fSlow407 + (fSlow0 * fRec197[1]));
			double fTemp658 = (fRec11[0] * fRec197[0]);
			fRec198[0] = (fSlow408 + (fConst6 * fRec198[1]));
			fRec199[0] = (fSlow409 + (fConst6 * fRec199[1]));
			fRec200[0] = (fSlow410 + (fConst6 * fRec200[1]));
			fRec201[0] = (fSlow411 + (fConst6 * fRec201[1]));
			fRec202[0] = (fSlow412 + (fConst6 * fRec202[1]));
			fRec203[0] = (fSlow413 + (fSlow0 * fRec203[1]));
			double fTemp659 = (fRec10[0] * fRec203[0]);
			fRec204[0] = (fSlow414 + (fConst6 * fRec204[1]));
			fRec205[0] = (fSlow415 + (fConst6 * fRec205[1]));
			fRec206[0] = (fSlow416 + (fConst6 * fRec206[1]));
			fRec207[0] = (fSlow417 + (fConst6 * fRec207[1]));
			fRec208[0] = (fSlow418 + (fConst6 * fRec208[1]));
			fRec209[0] = (fSlow419 + (fSlow0 * fRec209[1]));
			double fTemp660 = (fRec9[0] * fRec209[0]);
			fRec210[0] = (fSlow420 + (fConst6 * fRec210[1]));
			fRec211[0] = (fSlow421 + (fConst6 * fRec211[1]));
			fRec212[0] = (fSlow422 + (fConst6 * fRec212[1]));
			fRec213[0] = (fSlow423 + (fConst6 * fRec213[1]));
			fRec214[0] = (fSlow424 + (fConst6 * fRec214[1]));
			fRec215[0] = (fSlow425 + (fSlow0 * fRec215[1]));
			double fTemp661 = (fRec8[0] * fRec215[0]);
			fRec216[0] = (fSlow426 + (fConst6 * fRec216[1]));
			fRec217[0] = (fSlow427 + (fConst6 * fRec217[1]));
			fRec218[0] = (fSlow428 + (fConst6 * fRec218[1]));
			fRec219[0] = (fSlow429 + (fConst6 * fRec219[1]));
			fRec220[0] = (fSlow430 + (fConst6 * fRec220[1]));
			fRec221[0] = (fSlow431 + (fSlow0 * fRec221[1]));
			double fTemp662 = (fRec7[0] * fRec221[0]);
			fRec222[0] = (fSlow432 + (fConst6 * fRec222[1]));
			fRec223[0] = (fSlow433 + (fConst6 * fRec223[1]));
			fRec224[0] = (fSlow434 + (fConst6 * fRec224[1]));
			fRec225[0] = (fSlow435 + (fConst6 * fRec225[1]));
			fRec226[0] = (fSlow436 + (fConst6 * fRec226[1]));
			fRec227[0] = (fSlow437 + (fSlow0 * fRec227[1]));
			double fTemp663 = (fRec6[0] * fRec227[0]);
			fRec228[0] = (fSlow438 + (fConst6 * fRec228[1]));
			fRec229[0] = (fSlow439 + (fConst6 * fRec229[1]));
			fRec230[0] = (fSlow440 + (fConst6 * fRec230[1]));
			fRec231[0] = (fSlow441 + (fConst6 * fRec231[1]));
			fRec232[0] = (fSlow442 + (fConst6 * fRec232[1]));
			fRec233[0] = (fSlow443 + (fSlow0 * fRec233[1]));
			double fTemp664 = (fRec5[0] * fRec233[0]);
			fRec234[0] = (fSlow444 + (fConst6 * fRec234[1]));
			fRec235[0] = (fSlow445 + (fConst6 * fRec235[1]));
			fRec236[0] = (fSlow446 + (fConst6 * fRec236[1]));
			fRec237[0] = (fSlow447 + (fConst6 * fRec237[1]));
			fRec238[0] = (fSlow448 + (fConst6 * fRec238[1]));
			fRec239[0] = (fSlow449 + (fSlow0 * fRec239[1]));
			double fTemp665 = (fRec4[0] * fRec239[0]);
			fRec240[0] = (fSlow450 + (fConst6 * fRec240[1]));
			fRec241[0] = (fSlow451 + (fConst6 * fRec241[1]));
			fRec242[0] = (fSlow452 + (fConst6 * fRec242[1]));
			fRec243[0] = (fSlow453 + (fConst6 * fRec243[1]));
			fRec244[0] = (fSlow454 + (fConst6 * fRec244[1]));
			fRec245[0] = (fSlow455 + (fSlow0 * fRec245[1]));
			double fTemp666 = (fRec3[0] * fRec245[0]);
			fRec246[0] = (fSlow456 + (fConst6 * fRec246[1]));
			fRec247[0] = (fSlow457 + (fConst6 * fRec247[1]));
			fRec248[0] = (fSlow458 + (fConst6 * fRec248[1]));
			fRec249[0] = (fSlow459 + (fConst6 * fRec249[1]));
			fRec250[0] = (fSlow460 + (fConst6 * fRec250[1]));
			fRec251[0] = (fSlow461 + (fSlow0 * fRec251[1]));
			double fTemp667 = (fRec2[0] * fRec251[0]);
			fRec252[0] = (fSlow462 + (fConst6 * fRec252[1]));
			fRec253[0] = (fSlow463 + (fConst6 * fRec253[1]));
			fRec254[0] = (fSlow464 + (fConst6 * fRec254[1]));
			fRec255[0] = (fSlow465 + (fConst6 * fRec255[1]));
			fRec256[0] = (fSlow466 + (fConst6 * fRec256[1]));
			fRec257[0] = (fSlow467 + (fSlow0 * fRec257[1]));
			double fTemp668 = double((fRec257[0] > -127.0));
			double fTemp669 = std::pow(10.0, (0.050000000000000003 * fRec257[0]));
			fRec258[0] = (fSlow468 + (fConst6 * fRec258[1]));
			fRec259[0] = (fSlow469 + (fConst6 * fRec259[1]));
			fRec260[0] = (fSlow470 + (fConst6 * fRec260[1]));
			fRec261[0] = (fSlow471 + (fConst6 * fRec261[1]));
			fRec262[0] = (fSlow472 + (fConst6 * fRec262[1]));
			fRec263[0] = (fSlow473 + (fSlow0 * fRec263[1]));
			double fTemp670 = (fRec1[0] * fRec263[0]);
			fRec264[0] = (fSlow474 + (fConst6 * fRec264[1]));
			fRec265[0] = (fSlow475 + (fConst6 * fRec265[1]));
			fRec266[0] = (fSlow476 + (fConst6 * fRec266[1]));
			fRec267[0] = (fSlow477 + (fConst6 * fRec267[1]));
			fRec268[0] = (fSlow478 + (fConst6 * fRec268[1]));
			double fTemp671 = (0.14285714285714285 * ((fTemp653 * (fRec168[0] + (fRec169[0] + (fRec170[0] + (fRec171[0] + fRec172[0]))))) + ((fTemp654 * (fRec174[0] + (fRec175[0] + (fRec176[0] + (fRec177[0] + fRec178[0]))))) + ((fTemp655 * (fRec180[0] + (fRec181[0] + (fRec182[0] + (fRec183[0] + fRec184[0]))))) + ((fTemp656 * (fRec186[0] + (fRec187[0] + (fRec188[0] + (fRec189[0] + fRec190[0]))))) + ((fTemp657 * (fRec192[0] + (fRec193[0] + (fRec194[0] + (fRec195[0] + fRec196[0]))))) + ((fTemp658 * (fRec198[0] + (fRec199[0] + (fRec200[0] + (fRec201[0] + fRec202[0]))))) + ((fTemp659 * (fRec204[0] + (fRec205[0] + (fRec206[0] + (fRec207[0] + fRec208[0]))))) + ((fTemp660 * (fRec210[0] + (fRec211[0] + (fRec212[0] + (fRec213[0] + fRec214[0]))))) + ((fTemp661 * (fRec216[0] + (fRec217[0] + (fRec218[0] + (fRec219[0] + fRec220[0]))))) + ((fTemp662 * (fRec222[0] + (fRec223[0] + (fRec224[0] + (fRec225[0] + fRec226[0]))))) + ((fTemp663 * (fRec228[0] + (fRec229[0] + (fRec230[0] + (fRec231[0] + fRec232[0]))))) + ((fTemp664 * (fRec234[0] + (fRec235[0] + (fRec236[0] + (fRec237[0] + fRec238[0]))))) + ((fTemp665 * (fRec240[0] + (fRec241[0] + (fRec242[0] + (fRec243[0] + fRec244[0]))))) + ((fTemp666 * (fRec246[0] + (fRec247[0] + (fRec248[0] + (fRec249[0] + fRec250[0]))))) + ((fTemp667 * (fRec252[0] + (fRec253[0] + (fRec254[0] + (fRec255[0] + fRec256[0]))))) + ((((fTemp668 * fTemp22) * fTemp669) * (fRec258[0] + (fRec259[0] + (fRec260[0] + (fRec261[0] + fRec262[0]))))) + (fTemp670 * (fRec264[0] + (fRec265[0] + (fRec266[0] + (fRec267[0] + fRec268[0]))))))))))))))))))))));
			fRec269[0] = (fSlow483 + (fConst6 * fRec269[1]));
			fRec270[0] = (fSlow484 + (fSlow0 * fRec270[1]));
			double fTemp672 = double((fRec270[0] > -127.0));
			fRec272[0] = (fSlow485 + (fRec272[1] - std::floor((fSlow485 + fRec272[1]))));
			int iTemp673 = ((fRec272[0] > 0.001) * (fRec272[1] <= 0.001));
			int iTemp674 = (1103515245 * (iRec273[1] + 12345));
			int iTemp675 = (1103515245 * (iTemp674 + 12345));
			int iTemp676 = (1103515245 * (iTemp675 + 12345));
			int iTemp677 = (1103515245 * (iTemp676 + 12345));
			int iTemp678 = (1103515245 * (iTemp677 + 12345));
			iRec273[0] = (1103515245 * (iTemp678 + 12345));
			int iRec274 = iTemp678;
			int iRec275 = iTemp677;
			int iRec276 = iTemp676;
			int iRec277 = iTemp675;
			int iRec278 = iTemp674;
			iRec271[0] = (iTemp673?((4.6566128752457969e-10 * double(iRec273[0])) > fSlow486):iRec271[1]);
			double fTemp679 = std::pow(10.0, (0.050000000000000003 * fRec270[0]));
			double fTemp680 = (0.5 * fRec272[0]);
			double fTemp681 = (65536.0 * (fTemp680 - std::floor(fTemp680)));
			int iTemp682 = int(fTemp681);
			double fTemp683 = ftbl0mydspSIG0[iTemp682];
			double fTemp684 = (fTemp683 + ((fTemp681 - std::floor(fTemp681)) * (ftbl0mydspSIG0[((iTemp682 + 1) % 65536)] - fTemp683)));
			double fTemp685 = (((((((((((((((((fTemp670 * fRec265[0]) + (fTemp667 * fRec253[0])) + (fTemp666 * fRec247[0])) + (fTemp665 * fRec241[0])) + (fTemp664 * fRec235[0])) + (fTemp663 * fRec229[0])) + (fTemp662 * fRec223[0])) + (fTemp661 * fRec217[0])) + (fTemp660 * fRec211[0])) + (fTemp659 * fRec205[0])) + (fTemp658 * fRec199[0])) + (fTemp657 * fRec193[0])) + (fTemp656 * fRec187[0])) + (fTemp655 * fRec181[0])) + (fTemp654 * fRec175[0])) + (fTemp653 * fRec169[0])) + (((fRec259[0] * fTemp668) * fTemp22) * fTemp669));
			fRec279[0] = (fSlow492 + (fRec279[1] - std::floor((fSlow492 + fRec279[1]))));
			double fTemp686 = (fSlow490 + (fSlow491 * std::fmod((fSlow489 + fRec279[0]), 1.0)));
			double fTemp687 = (6.2831853071795862 * fTemp686);
			double fTemp688 = (((((((((((((((((fTemp670 * fRec266[0]) + (fTemp667 * fRec254[0])) + (fTemp666 * fRec248[0])) + (fTemp665 * fRec242[0])) + (fTemp664 * fRec236[0])) + (fTemp663 * fRec230[0])) + (fTemp662 * fRec224[0])) + (fTemp661 * fRec218[0])) + (fTemp660 * fRec212[0])) + (fTemp659 * fRec206[0])) + (fTemp658 * fRec200[0])) + (fTemp657 * fRec194[0])) + (fTemp656 * fRec188[0])) + (fTemp655 * fRec182[0])) + (fTemp654 * fRec176[0])) + (fTemp653 * fRec170[0])) + (((fRec260[0] * fTemp668) * fTemp22) * fTemp669));
			fRec280[0] = (fSlow498 + (fRec280[1] - std::floor((fSlow498 + fRec280[1]))));
			double fTemp689 = (fSlow496 + (fSlow497 * std::fmod((fSlow495 + fRec280[0]), 1.0)));
			double fTemp690 = (6.2831853071795862 * fTemp689);
			double fTemp691 = (((((((((((((((((fTemp670 * fRec268[0]) + (fTemp667 * fRec256[0])) + (fTemp666 * fRec250[0])) + (fTemp665 * fRec244[0])) + (fTemp664 * fRec238[0])) + (fTemp663 * fRec232[0])) + (fTemp662 * fRec226[0])) + (fTemp661 * fRec220[0])) + (fTemp660 * fRec214[0])) + (fTemp659 * fRec208[0])) + (fTemp658 * fRec202[0])) + (fTemp657 * fRec196[0])) + (fTemp656 * fRec190[0])) + (fTemp655 * fRec184[0])) + (fTemp654 * fRec178[0])) + (fTemp653 * fRec172[0])) + (((fRec262[0] * fTemp668) * fTemp22) * fTemp669));
			fRec281[0] = (fSlow504 + (fRec281[1] - std::floor((fSlow504 + fRec281[1]))));
			double fTemp692 = (fSlow502 + (fSlow503 * std::fmod((fSlow501 + fRec281[0]), 1.0)));
			double fTemp693 = (6.2831853071795862 * fTemp692);
			fRec282[0] = (fSlow505 + (fConst6 * fRec282[1]));
			fRec283[0] = (fSlow506 + (fConst6 * fRec283[1]));
			fRec284[0] = (fSlow507 + (fConst6 * fRec284[1]));
			fRec285[0] = (fSlow508 + (fConst6 * fRec285[1]));
			fRec286[0] = (fSlow509 + (fConst6 * fRec286[1]));
			fRec287[0] = (fSlow510 + (fConst6 * fRec287[1]));
			fRec288[0] = (fSlow511 + (fConst6 * fRec288[1]));
			fRec289[0] = (fSlow512 + (fConst6 * fRec289[1]));
			fRec290[0] = (fSlow513 + (fConst6 * fRec290[1]));
			fRec291[0] = (fSlow514 + (fConst6 * fRec291[1]));
			fRec292[0] = (fSlow515 + (fConst6 * fRec292[1]));
			fRec293[0] = (fSlow516 + (fConst6 * fRec293[1]));
			fRec294[0] = (fSlow517 + (fConst6 * fRec294[1]));
			fRec295[0] = (fSlow518 + (fConst6 * fRec295[1]));
			fRec296[0] = (fSlow519 + (fConst6 * fRec296[1]));
			fRec297[0] = (fSlow520 + (fConst6 * fRec297[1]));
			double fTemp694 = (((((((((((((((((fTemp670 * fRec267[0]) + (fTemp667 * fRec255[0])) + (fTemp666 * fRec249[0])) + (fTemp665 * fRec243[0])) + (fTemp664 * fRec237[0])) + (fTemp663 * fRec231[0])) + (fTemp662 * fRec225[0])) + (fTemp661 * fRec219[0])) + (fTemp660 * fRec213[0])) + (fTemp659 * fRec207[0])) + (fTemp658 * fRec201[0])) + (fTemp657 * fRec195[0])) + (fTemp656 * fRec189[0])) + (fTemp655 * fRec183[0])) + (fTemp654 * fRec177[0])) + (fTemp653 * fRec171[0])) + (((fRec261[0] * fTemp668) * fTemp22) * fTemp669));
			fRec298[0] = (fSlow526 + (fRec298[1] - std::floor((fSlow526 + fRec298[1]))));
			double fTemp695 = (fSlow524 + (fSlow525 * std::fmod((fSlow523 + fRec298[0]), 1.0)));
			double fTemp696 = (6.2831853071795862 * fTemp695);
			double fTemp697 = ((fTemp22 * (((fRec269[0] * fTemp668) * fTemp669) + (((fTemp672 * double(iRec271[0])) * fTemp679) * fTemp684))) + ((fTemp685 * std::sin(fTemp687)) + ((fTemp688 * std::sin(fTemp690)) + ((fTemp691 * std::sin(fTemp693)) + (((((((((((((((((fTemp670 * fRec282[0]) + (fTemp667 * fRec283[0])) + (fTemp666 * fRec284[0])) + (fTemp665 * fRec285[0])) + (fTemp664 * fRec286[0])) + (fTemp663 * fRec287[0])) + (fTemp662 * fRec288[0])) + (fTemp661 * fRec289[0])) + (fTemp660 * fRec290[0])) + (fTemp659 * fRec291[0])) + (fTemp658 * fRec292[0])) + (fTemp657 * fRec293[0])) + (fTemp656 * fRec294[0])) + (fTemp655 * fRec295[0])) + (fTemp654 * fRec296[0])) + (fTemp653 * fRec297[0])) + (fTemp694 * std::sin(fTemp696)))))));
			fRec299[0] = (fSlow528 + (fConst6 * fRec299[1]));
			iRec300[0] = (iTemp673?((4.6566128752457969e-10 * double(iRec274)) > fSlow486):iRec300[1]);
			fRec301[0] = (fSlow529 + (fConst6 * fRec301[1]));
			fRec302[0] = (fSlow530 + (fConst6 * fRec302[1]));
			fRec303[0] = (fSlow531 + (fConst6 * fRec303[1]));
			fRec304[0] = (fSlow532 + (fConst6 * fRec304[1]));
			fRec305[0] = (fSlow533 + (fConst6 * fRec305[1]));
			fRec306[0] = (fSlow534 + (fConst6 * fRec306[1]));
			fRec307[0] = (fSlow535 + (fConst6 * fRec307[1]));
			fRec308[0] = (fSlow536 + (fConst6 * fRec308[1]));
			fRec309[0] = (fSlow537 + (fConst6 * fRec309[1]));
			fRec310[0] = (fSlow538 + (fConst6 * fRec310[1]));
			fRec311[0] = (fSlow539 + (fConst6 * fRec311[1]));
			fRec312[0] = (fSlow540 + (fConst6 * fRec312[1]));
			fRec313[0] = (fSlow541 + (fConst6 * fRec313[1]));
			fRec314[0] = (fSlow542 + (fConst6 * fRec314[1]));
			fRec315[0] = (fSlow543 + (fConst6 * fRec315[1]));
			fRec316[0] = (fSlow544 + (fConst6 * fRec316[1]));
			double fTemp698 = ((fTemp22 * (((fRec299[0] * fTemp668) * fTemp669) + (((fTemp672 * double(iRec300[0])) * fTemp679) * fTemp684))) + ((fTemp685 * std::cos(fTemp687)) + ((fTemp688 * std::cos(fTemp690)) + ((fTemp691 * std::cos(fTemp693)) + (((((((((((((((((fTemp670 * fRec301[0]) + (fTemp667 * fRec302[0])) + (fTemp666 * fRec303[0])) + (fTemp665 * fRec304[0])) + (fTemp664 * fRec305[0])) + (fTemp663 * fRec306[0])) + (fTemp662 * fRec307[0])) + (fTemp661 * fRec308[0])) + (fTemp660 * fRec309[0])) + (fTemp659 * fRec310[0])) + (fTemp658 * fRec311[0])) + (fTemp657 * fRec312[0])) + (fTemp656 * fRec313[0])) + (fTemp655 * fRec314[0])) + (fTemp654 * fRec315[0])) + (fTemp653 * fRec316[0])) + (fTemp694 * std::cos(fTemp696)))))));
			fRec317[0] = (fSlow547 + (fConst6 * fRec317[1]));
			iRec318[0] = (iTemp673?((4.6566128752457969e-10 * double(iRec275)) > fSlow486):iRec318[1]);
			double fTemp699 = (12.566370614359172 * fTemp686);
			double fTemp700 = (12.566370614359172 * fTemp689);
			double fTemp701 = (12.566370614359172 * fTemp692);
			fRec319[0] = (fSlow548 + (fConst6 * fRec319[1]));
			fRec320[0] = (fSlow549 + (fConst6 * fRec320[1]));
			fRec321[0] = (fSlow550 + (fConst6 * fRec321[1]));
			fRec322[0] = (fSlow551 + (fConst6 * fRec322[1]));
			fRec323[0] = (fSlow552 + (fConst6 * fRec323[1]));
			fRec324[0] = (fSlow553 + (fConst6 * fRec324[1]));
			fRec325[0] = (fSlow554 + (fConst6 * fRec325[1]));
			fRec326[0] = (fSlow555 + (fConst6 * fRec326[1]));
			fRec327[0] = (fSlow556 + (fConst6 * fRec327[1]));
			fRec328[0] = (fSlow557 + (fConst6 * fRec328[1]));
			fRec329[0] = (fSlow558 + (fConst6 * fRec329[1]));
			fRec330[0] = (fSlow559 + (fConst6 * fRec330[1]));
			fRec331[0] = (fSlow560 + (fConst6 * fRec331[1]));
			fRec332[0] = (fSlow561 + (fConst6 * fRec332[1]));
			fRec333[0] = (fSlow562 + (fConst6 * fRec333[1]));
			fRec334[0] = (fSlow563 + (fConst6 * fRec334[1]));
			double fTemp702 = (12.566370614359172 * fTemp695);
			double fTemp703 = ((fTemp22 * (((fRec317[0] * fTemp668) * fTemp669) + (((fTemp672 * double(iRec318[0])) * fTemp679) * fTemp684))) + ((fTemp685 * std::sin(fTemp699)) + ((fTemp688 * std::sin(fTemp700)) + ((fTemp691 * std::sin(fTemp701)) + (((((((((((((((((fTemp670 * fRec319[0]) + (fTemp667 * fRec320[0])) + (fTemp666 * fRec321[0])) + (fTemp665 * fRec322[0])) + (fTemp664 * fRec323[0])) + (fTemp663 * fRec324[0])) + (fTemp662 * fRec325[0])) + (fTemp661 * fRec326[0])) + (fTemp660 * fRec327[0])) + (fTemp659 * fRec328[0])) + (fTemp658 * fRec329[0])) + (fTemp657 * fRec330[0])) + (fTemp656 * fRec331[0])) + (fTemp655 * fRec332[0])) + (fTemp654 * fRec333[0])) + (fTemp653 * fRec334[0])) + (fTemp694 * std::sin(fTemp702)))))));
			fRec335[0] = (fSlow565 + (fConst6 * fRec335[1]));
			iRec336[0] = (iTemp673?((4.6566128752457969e-10 * double(iRec276)) > fSlow486):iRec336[1]);
			fRec337[0] = (fSlow566 + (fConst6 * fRec337[1]));
			fRec338[0] = (fSlow567 + (fConst6 * fRec338[1]));
			fRec339[0] = (fSlow568 + (fConst6 * fRec339[1]));
			fRec340[0] = (fSlow569 + (fConst6 * fRec340[1]));
			fRec341[0] = (fSlow570 + (fConst6 * fRec341[1]));
			fRec342[0] = (fSlow571 + (fConst6 * fRec342[1]));
			fRec343[0] = (fSlow572 + (fConst6 * fRec343[1]));
			fRec344[0] = (fSlow573 + (fConst6 * fRec344[1]));
			fRec345[0] = (fSlow574 + (fConst6 * fRec345[1]));
			fRec346[0] = (fSlow575 + (fConst6 * fRec346[1]));
			fRec347[0] = (fSlow576 + (fConst6 * fRec347[1]));
			fRec348[0] = (fSlow577 + (fConst6 * fRec348[1]));
			fRec349[0] = (fSlow578 + (fConst6 * fRec349[1]));
			fRec350[0] = (fSlow579 + (fConst6 * fRec350[1]));
			fRec351[0] = (fSlow580 + (fConst6 * fRec351[1]));
			fRec352[0] = (fSlow581 + (fConst6 * fRec352[1]));
			double fTemp704 = ((fTemp22 * (((fRec335[0] * fTemp668) * fTemp669) + (((fTemp672 * double(iRec336[0])) * fTemp679) * fTemp684))) + ((fTemp685 * std::cos(fTemp699)) + ((fTemp688 * std::cos(fTemp700)) + ((fTemp691 * std::cos(fTemp701)) + (((((((((((((((((fTemp670 * fRec337[0]) + (fTemp667 * fRec338[0])) + (fTemp666 * fRec339[0])) + (fTemp665 * fRec340[0])) + (fTemp664 * fRec341[0])) + (fTemp663 * fRec342[0])) + (fTemp662 * fRec343[0])) + (fTemp661 * fRec344[0])) + (fTemp660 * fRec345[0])) + (fTemp659 * fRec346[0])) + (fTemp658 * fRec347[0])) + (fTemp657 * fRec348[0])) + (fTemp656 * fRec349[0])) + (fTemp655 * fRec350[0])) + (fTemp654 * fRec351[0])) + (fTemp653 * fRec352[0])) + (fTemp694 * std::cos(fTemp702)))))));
			fRec353[0] = (fSlow584 + (fConst6 * fRec353[1]));
			iRec354[0] = (iTemp673?((4.6566128752457969e-10 * double(iRec277)) > fSlow486):iRec354[1]);
			double fTemp705 = (18.849555921538759 * fTemp686);
			double fTemp706 = (18.849555921538759 * fTemp689);
			double fTemp707 = (18.849555921538759 * fTemp692);
			fRec355[0] = (fSlow585 + (fConst6 * fRec355[1]));
			fRec356[0] = (fSlow586 + (fConst6 * fRec356[1]));
			fRec357[0] = (fSlow587 + (fConst6 * fRec357[1]));
			fRec358[0] = (fSlow588 + (fConst6 * fRec358[1]));
			fRec359[0] = (fSlow589 + (fConst6 * fRec359[1]));
			fRec360[0] = (fSlow590 + (fConst6 * fRec360[1]));
			fRec361[0] = (fSlow591 + (fConst6 * fRec361[1]));
			fRec362[0] = (fSlow592 + (fConst6 * fRec362[1]));
			fRec363[0] = (fSlow593 + (fConst6 * fRec363[1]));
			fRec364[0] = (fSlow594 + (fConst6 * fRec364[1]));
			fRec365[0] = (fSlow595 + (fConst6 * fRec365[1]));
			fRec366[0] = (fSlow596 + (fConst6 * fRec366[1]));
			fRec367[0] = (fSlow597 + (fConst6 * fRec367[1]));
			fRec368[0] = (fSlow598 + (fConst6 * fRec368[1]));
			fRec369[0] = (fSlow599 + (fConst6 * fRec369[1]));
			fRec370[0] = (fSlow600 + (fConst6 * fRec370[1]));
			double fTemp708 = (18.849555921538759 * fTemp695);
			double fTemp709 = ((fTemp22 * (((fRec353[0] * fTemp668) * fTemp669) + (((fTemp672 * double(iRec354[0])) * fTemp679) * fTemp684))) + ((fTemp685 * std::sin(fTemp705)) + ((fTemp688 * std::sin(fTemp706)) + ((fTemp691 * std::sin(fTemp707)) + (((((((((((((((((fTemp670 * fRec355[0]) + (fTemp667 * fRec356[0])) + (fTemp666 * fRec357[0])) + (fTemp665 * fRec358[0])) + (fTemp664 * fRec359[0])) + (fTemp663 * fRec360[0])) + (fTemp662 * fRec361[0])) + (fTemp661 * fRec362[0])) + (fTemp660 * fRec363[0])) + (fTemp659 * fRec364[0])) + (fTemp658 * fRec365[0])) + (fTemp657 * fRec366[0])) + (fTemp656 * fRec367[0])) + (fTemp655 * fRec368[0])) + (fTemp654 * fRec369[0])) + (fTemp653 * fRec370[0])) + (fTemp694 * std::sin(fTemp708)))))));
			fRec371[0] = (fSlow602 + (fConst6 * fRec371[1]));
			iRec372[0] = (iTemp673?((4.6566128752457969e-10 * double(iRec278)) > fSlow486):iRec372[1]);
			fRec373[0] = (fSlow603 + (fConst6 * fRec373[1]));
			fRec374[0] = (fSlow604 + (fConst6 * fRec374[1]));
			fRec375[0] = (fSlow605 + (fConst6 * fRec375[1]));
			fRec376[0] = (fSlow606 + (fConst6 * fRec376[1]));
			fRec377[0] = (fSlow607 + (fConst6 * fRec377[1]));
			fRec378[0] = (fSlow608 + (fConst6 * fRec378[1]));
			fRec379[0] = (fSlow609 + (fConst6 * fRec379[1]));
			fRec380[0] = (fSlow610 + (fConst6 * fRec380[1]));
			fRec381[0] = (fSlow611 + (fConst6 * fRec381[1]));
			fRec382[0] = (fSlow612 + (fConst6 * fRec382[1]));
			fRec383[0] = (fSlow613 + (fConst6 * fRec383[1]));
			fRec384[0] = (fSlow614 + (fConst6 * fRec384[1]));
			fRec385[0] = (fSlow615 + (fConst6 * fRec385[1]));
			fRec386[0] = (fSlow616 + (fConst6 * fRec386[1]));
			fRec387[0] = (fSlow617 + (fConst6 * fRec387[1]));
			fRec388[0] = (fSlow618 + (fConst6 * fRec388[1]));
			double fTemp710 = ((fTemp22 * (((fRec371[0] * fTemp668) * fTemp669) + (((double(iRec372[0]) * fTemp672) * fTemp679) * fTemp684))) + ((fTemp685 * std::cos(fTemp705)) + ((fTemp688 * std::cos(fTemp706)) + ((fTemp691 * std::cos(fTemp707)) + (((((((((((((((((fTemp670 * fRec373[0]) + (fTemp667 * fRec374[0])) + (fTemp666 * fRec375[0])) + (fTemp665 * fRec376[0])) + (fTemp664 * fRec377[0])) + (fTemp663 * fRec378[0])) + (fTemp662 * fRec379[0])) + (fTemp661 * fRec380[0])) + (fTemp660 * fRec381[0])) + (fTemp659 * fRec382[0])) + (fTemp658 * fRec383[0])) + (fTemp657 * fRec384[0])) + (fTemp656 * fRec385[0])) + (fTemp655 * fRec386[0])) + (fTemp654 * fRec387[0])) + (fTemp653 * fRec388[0])) + (fTemp694 * std::cos(fTemp708)))))));
			output0[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow482 * fTemp697)) + (fSlow527 * fTemp698)) + (fSlow546 * fTemp703)) + (fSlow564 * fTemp704)) + (fSlow583 * fTemp709)) + (fSlow601 * fTemp710))));
			output1[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow620 * fTemp697)) + (fSlow621 * fTemp698)) + (fSlow623 * fTemp703)) + (fSlow624 * fTemp704)) + (fSlow626 * fTemp709)) + (fSlow627 * fTemp710))));
			output2[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow629 * fTemp697)) + (fSlow630 * fTemp698)) + (fSlow632 * fTemp703)) + (fSlow633 * fTemp704)) + (fSlow635 * fTemp709)) + (fSlow636 * fTemp710))));
			output3[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow638 * fTemp697)) + (fSlow639 * fTemp698)) + (fSlow641 * fTemp703)) + (fSlow642 * fTemp704)) + (fSlow644 * fTemp709)) + (fSlow645 * fTemp710))));
			output4[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow647 * fTemp697)) + (fSlow648 * fTemp698)) + (fSlow650 * fTemp703)) + (fSlow651 * fTemp704)) + (fSlow653 * fTemp709)) + (fSlow654 * fTemp710))));
			output5[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow656 * fTemp697)) + (fSlow657 * fTemp698)) + (fSlow659 * fTemp703)) + (fSlow660 * fTemp704)) + (fSlow662 * fTemp709)) + (fSlow663 * fTemp710))));
			output6[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow665 * fTemp697)) + (fSlow666 * fTemp698)) + (fSlow668 * fTemp703)) + (fSlow669 * fTemp704)) + (fSlow671 * fTemp709)) + (fSlow672 * fTemp710))));
			output7[i] = FAUSTFLOAT((fTemp0 * ((((((fTemp671 + (fSlow674 * fTemp697)) + (fSlow675 * fTemp698)) + (fSlow677 * fTemp703)) + (fSlow678 * fTemp704)) + (fSlow680 * fTemp709)) + (fSlow681 * fTemp710))));
			fRec0[1] = fRec0[0];
			fRec18[1] = fRec18[0];
			fVec0[1] = fVec0[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			IOTA = (IOTA + 1);
			iRec38[1] = iRec38[0];
			fVec2[1] = fVec2[0];
			iRec39[1] = iRec39[0];
			fVec4[1] = fVec4[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fVec5[1] = fVec5[0];
			fRec40[1] = fRec40[0];
			fVec6[1] = fVec6[0];
			fRec44[1] = fRec44[0];
			fVec7[1] = fVec7[0];
			fRec45[1] = fRec45[0];
			fVec8[1] = fVec8[0];
			fRec46[1] = fRec46[0];
			fRec1[1] = fRec1[0];
			fRec47[1] = fRec47[0];
			iRec48[1] = iRec48[0];
			iRec49[1] = iRec49[0];
			fRec51[1] = fRec51[0];
			fVec11[1] = fVec11[0];
			fRec50[1] = fRec50[0];
			fVec12[1] = fVec12[0];
			fRec52[1] = fRec52[0];
			fVec13[1] = fVec13[0];
			fRec53[1] = fRec53[0];
			fVec14[1] = fVec14[0];
			fRec54[1] = fRec54[0];
			fRec2[1] = fRec2[0];
			fRec55[1] = fRec55[0];
			iRec56[1] = iRec56[0];
			iRec57[1] = iRec57[0];
			fRec59[1] = fRec59[0];
			fVec17[1] = fVec17[0];
			fRec58[1] = fRec58[0];
			fVec18[1] = fVec18[0];
			fRec60[1] = fRec60[0];
			fVec19[1] = fVec19[0];
			fRec61[1] = fRec61[0];
			fVec20[1] = fVec20[0];
			fRec62[1] = fRec62[0];
			fRec3[1] = fRec3[0];
			fRec63[1] = fRec63[0];
			iRec64[1] = iRec64[0];
			iRec65[1] = iRec65[0];
			fRec67[1] = fRec67[0];
			fVec23[1] = fVec23[0];
			fRec66[1] = fRec66[0];
			fVec24[1] = fVec24[0];
			fRec68[1] = fRec68[0];
			fVec25[1] = fVec25[0];
			fRec69[1] = fRec69[0];
			fVec26[1] = fVec26[0];
			fRec70[1] = fRec70[0];
			fRec4[1] = fRec4[0];
			fRec71[1] = fRec71[0];
			iRec72[1] = iRec72[0];
			iRec73[1] = iRec73[0];
			fRec75[1] = fRec75[0];
			fVec29[1] = fVec29[0];
			fRec74[1] = fRec74[0];
			fVec30[1] = fVec30[0];
			fRec76[1] = fRec76[0];
			fVec31[1] = fVec31[0];
			fRec77[1] = fRec77[0];
			fVec32[1] = fVec32[0];
			fRec78[1] = fRec78[0];
			fRec5[1] = fRec5[0];
			fRec79[1] = fRec79[0];
			iRec80[1] = iRec80[0];
			iRec81[1] = iRec81[0];
			fRec83[1] = fRec83[0];
			fVec35[1] = fVec35[0];
			fRec82[1] = fRec82[0];
			fVec36[1] = fVec36[0];
			fRec84[1] = fRec84[0];
			fVec37[1] = fVec37[0];
			fRec85[1] = fRec85[0];
			fVec38[1] = fVec38[0];
			fRec86[1] = fRec86[0];
			fRec6[1] = fRec6[0];
			fRec87[1] = fRec87[0];
			iRec88[1] = iRec88[0];
			iRec89[1] = iRec89[0];
			fRec91[1] = fRec91[0];
			fVec41[1] = fVec41[0];
			fRec90[1] = fRec90[0];
			fVec42[1] = fVec42[0];
			fRec92[1] = fRec92[0];
			fVec43[1] = fVec43[0];
			fRec93[1] = fRec93[0];
			fVec44[1] = fVec44[0];
			fRec94[1] = fRec94[0];
			fRec7[1] = fRec7[0];
			fRec95[1] = fRec95[0];
			iRec96[1] = iRec96[0];
			iRec97[1] = iRec97[0];
			fRec99[1] = fRec99[0];
			fVec47[1] = fVec47[0];
			fRec98[1] = fRec98[0];
			fVec48[1] = fVec48[0];
			fRec100[1] = fRec100[0];
			fVec49[1] = fVec49[0];
			fRec101[1] = fRec101[0];
			fVec50[1] = fVec50[0];
			fRec102[1] = fRec102[0];
			fRec8[1] = fRec8[0];
			fRec103[1] = fRec103[0];
			iRec104[1] = iRec104[0];
			iRec105[1] = iRec105[0];
			fRec107[1] = fRec107[0];
			fVec53[1] = fVec53[0];
			fRec106[1] = fRec106[0];
			fVec54[1] = fVec54[0];
			fRec108[1] = fRec108[0];
			fVec55[1] = fVec55[0];
			fRec109[1] = fRec109[0];
			fVec56[1] = fVec56[0];
			fRec110[1] = fRec110[0];
			fRec9[1] = fRec9[0];
			fRec111[1] = fRec111[0];
			iRec112[1] = iRec112[0];
			iRec113[1] = iRec113[0];
			fRec115[1] = fRec115[0];
			fVec59[1] = fVec59[0];
			fRec114[1] = fRec114[0];
			fVec60[1] = fVec60[0];
			fRec116[1] = fRec116[0];
			fVec61[1] = fVec61[0];
			fRec117[1] = fRec117[0];
			fVec62[1] = fVec62[0];
			fRec118[1] = fRec118[0];
			fRec10[1] = fRec10[0];
			fRec119[1] = fRec119[0];
			iRec120[1] = iRec120[0];
			iRec121[1] = iRec121[0];
			fRec123[1] = fRec123[0];
			fVec65[1] = fVec65[0];
			fRec122[1] = fRec122[0];
			fVec66[1] = fVec66[0];
			fRec124[1] = fRec124[0];
			fVec67[1] = fVec67[0];
			fRec125[1] = fRec125[0];
			fVec68[1] = fVec68[0];
			fRec126[1] = fRec126[0];
			fRec11[1] = fRec11[0];
			fRec127[1] = fRec127[0];
			iRec128[1] = iRec128[0];
			iRec129[1] = iRec129[0];
			fRec131[1] = fRec131[0];
			fVec71[1] = fVec71[0];
			fRec130[1] = fRec130[0];
			fVec72[1] = fVec72[0];
			fRec132[1] = fRec132[0];
			fVec73[1] = fVec73[0];
			fRec133[1] = fRec133[0];
			fVec74[1] = fVec74[0];
			fRec134[1] = fRec134[0];
			fRec12[1] = fRec12[0];
			fRec135[1] = fRec135[0];
			iRec136[1] = iRec136[0];
			iRec137[1] = iRec137[0];
			fRec139[1] = fRec139[0];
			fVec77[1] = fVec77[0];
			fRec138[1] = fRec138[0];
			fVec78[1] = fVec78[0];
			fRec140[1] = fRec140[0];
			fVec79[1] = fVec79[0];
			fRec141[1] = fRec141[0];
			fVec80[1] = fVec80[0];
			fRec142[1] = fRec142[0];
			fRec13[1] = fRec13[0];
			fRec143[1] = fRec143[0];
			iRec144[1] = iRec144[0];
			iRec145[1] = iRec145[0];
			fRec147[1] = fRec147[0];
			fVec83[1] = fVec83[0];
			fRec146[1] = fRec146[0];
			fVec84[1] = fVec84[0];
			fRec148[1] = fRec148[0];
			fVec85[1] = fVec85[0];
			fRec149[1] = fRec149[0];
			fVec86[1] = fVec86[0];
			fRec150[1] = fRec150[0];
			fRec14[1] = fRec14[0];
			fRec151[1] = fRec151[0];
			iRec152[1] = iRec152[0];
			iRec153[1] = iRec153[0];
			fRec155[1] = fRec155[0];
			fVec89[1] = fVec89[0];
			fRec154[1] = fRec154[0];
			fVec90[1] = fVec90[0];
			fRec156[1] = fRec156[0];
			fVec91[1] = fVec91[0];
			fRec157[1] = fRec157[0];
			fVec92[1] = fVec92[0];
			fRec158[1] = fRec158[0];
			fRec15[1] = fRec15[0];
			fRec159[1] = fRec159[0];
			iRec160[1] = iRec160[0];
			iRec161[1] = iRec161[0];
			fRec163[1] = fRec163[0];
			fVec95[1] = fVec95[0];
			fRec162[1] = fRec162[0];
			fVec96[1] = fVec96[0];
			fRec164[1] = fRec164[0];
			fVec97[1] = fVec97[0];
			fRec165[1] = fRec165[0];
			fVec98[1] = fVec98[0];
			fRec166[1] = fRec166[0];
			fRec16[1] = fRec16[0];
			fRec167[1] = fRec167[0];
			fRec168[1] = fRec168[0];
			fRec169[1] = fRec169[0];
			fRec170[1] = fRec170[0];
			fRec171[1] = fRec171[0];
			fRec172[1] = fRec172[0];
			fRec173[1] = fRec173[0];
			fRec174[1] = fRec174[0];
			fRec175[1] = fRec175[0];
			fRec176[1] = fRec176[0];
			fRec177[1] = fRec177[0];
			fRec178[1] = fRec178[0];
			fRec179[1] = fRec179[0];
			fRec180[1] = fRec180[0];
			fRec181[1] = fRec181[0];
			fRec182[1] = fRec182[0];
			fRec183[1] = fRec183[0];
			fRec184[1] = fRec184[0];
			fRec185[1] = fRec185[0];
			fRec186[1] = fRec186[0];
			fRec187[1] = fRec187[0];
			fRec188[1] = fRec188[0];
			fRec189[1] = fRec189[0];
			fRec190[1] = fRec190[0];
			fRec191[1] = fRec191[0];
			fRec192[1] = fRec192[0];
			fRec193[1] = fRec193[0];
			fRec194[1] = fRec194[0];
			fRec195[1] = fRec195[0];
			fRec196[1] = fRec196[0];
			fRec197[1] = fRec197[0];
			fRec198[1] = fRec198[0];
			fRec199[1] = fRec199[0];
			fRec200[1] = fRec200[0];
			fRec201[1] = fRec201[0];
			fRec202[1] = fRec202[0];
			fRec203[1] = fRec203[0];
			fRec204[1] = fRec204[0];
			fRec205[1] = fRec205[0];
			fRec206[1] = fRec206[0];
			fRec207[1] = fRec207[0];
			fRec208[1] = fRec208[0];
			fRec209[1] = fRec209[0];
			fRec210[1] = fRec210[0];
			fRec211[1] = fRec211[0];
			fRec212[1] = fRec212[0];
			fRec213[1] = fRec213[0];
			fRec214[1] = fRec214[0];
			fRec215[1] = fRec215[0];
			fRec216[1] = fRec216[0];
			fRec217[1] = fRec217[0];
			fRec218[1] = fRec218[0];
			fRec219[1] = fRec219[0];
			fRec220[1] = fRec220[0];
			fRec221[1] = fRec221[0];
			fRec222[1] = fRec222[0];
			fRec223[1] = fRec223[0];
			fRec224[1] = fRec224[0];
			fRec225[1] = fRec225[0];
			fRec226[1] = fRec226[0];
			fRec227[1] = fRec227[0];
			fRec228[1] = fRec228[0];
			fRec229[1] = fRec229[0];
			fRec230[1] = fRec230[0];
			fRec231[1] = fRec231[0];
			fRec232[1] = fRec232[0];
			fRec233[1] = fRec233[0];
			fRec234[1] = fRec234[0];
			fRec235[1] = fRec235[0];
			fRec236[1] = fRec236[0];
			fRec237[1] = fRec237[0];
			fRec238[1] = fRec238[0];
			fRec239[1] = fRec239[0];
			fRec240[1] = fRec240[0];
			fRec241[1] = fRec241[0];
			fRec242[1] = fRec242[0];
			fRec243[1] = fRec243[0];
			fRec244[1] = fRec244[0];
			fRec245[1] = fRec245[0];
			fRec246[1] = fRec246[0];
			fRec247[1] = fRec247[0];
			fRec248[1] = fRec248[0];
			fRec249[1] = fRec249[0];
			fRec250[1] = fRec250[0];
			fRec251[1] = fRec251[0];
			fRec252[1] = fRec252[0];
			fRec253[1] = fRec253[0];
			fRec254[1] = fRec254[0];
			fRec255[1] = fRec255[0];
			fRec256[1] = fRec256[0];
			fRec257[1] = fRec257[0];
			fRec258[1] = fRec258[0];
			fRec259[1] = fRec259[0];
			fRec260[1] = fRec260[0];
			fRec261[1] = fRec261[0];
			fRec262[1] = fRec262[0];
			fRec263[1] = fRec263[0];
			fRec264[1] = fRec264[0];
			fRec265[1] = fRec265[0];
			fRec266[1] = fRec266[0];
			fRec267[1] = fRec267[0];
			fRec268[1] = fRec268[0];
			fRec269[1] = fRec269[0];
			fRec270[1] = fRec270[0];
			fRec272[1] = fRec272[0];
			iRec273[1] = iRec273[0];
			iRec271[1] = iRec271[0];
			fRec279[1] = fRec279[0];
			fRec280[1] = fRec280[0];
			fRec281[1] = fRec281[0];
			fRec282[1] = fRec282[0];
			fRec283[1] = fRec283[0];
			fRec284[1] = fRec284[0];
			fRec285[1] = fRec285[0];
			fRec286[1] = fRec286[0];
			fRec287[1] = fRec287[0];
			fRec288[1] = fRec288[0];
			fRec289[1] = fRec289[0];
			fRec290[1] = fRec290[0];
			fRec291[1] = fRec291[0];
			fRec292[1] = fRec292[0];
			fRec293[1] = fRec293[0];
			fRec294[1] = fRec294[0];
			fRec295[1] = fRec295[0];
			fRec296[1] = fRec296[0];
			fRec297[1] = fRec297[0];
			fRec298[1] = fRec298[0];
			fRec299[1] = fRec299[0];
			iRec300[1] = iRec300[0];
			fRec301[1] = fRec301[0];
			fRec302[1] = fRec302[0];
			fRec303[1] = fRec303[0];
			fRec304[1] = fRec304[0];
			fRec305[1] = fRec305[0];
			fRec306[1] = fRec306[0];
			fRec307[1] = fRec307[0];
			fRec308[1] = fRec308[0];
			fRec309[1] = fRec309[0];
			fRec310[1] = fRec310[0];
			fRec311[1] = fRec311[0];
			fRec312[1] = fRec312[0];
			fRec313[1] = fRec313[0];
			fRec314[1] = fRec314[0];
			fRec315[1] = fRec315[0];
			fRec316[1] = fRec316[0];
			fRec317[1] = fRec317[0];
			iRec318[1] = iRec318[0];
			fRec319[1] = fRec319[0];
			fRec320[1] = fRec320[0];
			fRec321[1] = fRec321[0];
			fRec322[1] = fRec322[0];
			fRec323[1] = fRec323[0];
			fRec324[1] = fRec324[0];
			fRec325[1] = fRec325[0];
			fRec326[1] = fRec326[0];
			fRec327[1] = fRec327[0];
			fRec328[1] = fRec328[0];
			fRec329[1] = fRec329[0];
			fRec330[1] = fRec330[0];
			fRec331[1] = fRec331[0];
			fRec332[1] = fRec332[0];
			fRec333[1] = fRec333[0];
			fRec334[1] = fRec334[0];
			fRec335[1] = fRec335[0];
			iRec336[1] = iRec336[0];
			fRec337[1] = fRec337[0];
			fRec338[1] = fRec338[0];
			fRec339[1] = fRec339[0];
			fRec340[1] = fRec340[0];
			fRec341[1] = fRec341[0];
			fRec342[1] = fRec342[0];
			fRec343[1] = fRec343[0];
			fRec344[1] = fRec344[0];
			fRec345[1] = fRec345[0];
			fRec346[1] = fRec346[0];
			fRec347[1] = fRec347[0];
			fRec348[1] = fRec348[0];
			fRec349[1] = fRec349[0];
			fRec350[1] = fRec350[0];
			fRec351[1] = fRec351[0];
			fRec352[1] = fRec352[0];
			fRec353[1] = fRec353[0];
			iRec354[1] = iRec354[0];
			fRec355[1] = fRec355[0];
			fRec356[1] = fRec356[0];
			fRec357[1] = fRec357[0];
			fRec358[1] = fRec358[0];
			fRec359[1] = fRec359[0];
			fRec360[1] = fRec360[0];
			fRec361[1] = fRec361[0];
			fRec362[1] = fRec362[0];
			fRec363[1] = fRec363[0];
			fRec364[1] = fRec364[0];
			fRec365[1] = fRec365[0];
			fRec366[1] = fRec366[0];
			fRec367[1] = fRec367[0];
			fRec368[1] = fRec368[0];
			fRec369[1] = fRec369[0];
			fRec370[1] = fRec370[0];
			fRec371[1] = fRec371[0];
			iRec372[1] = iRec372[0];
			fRec373[1] = fRec373[0];
			fRec374[1] = fRec374[0];
			fRec375[1] = fRec375[0];
			fRec376[1] = fRec376[0];
			fRec377[1] = fRec377[0];
			fRec378[1] = fRec378[0];
			fRec379[1] = fRec379[0];
			fRec380[1] = fRec380[0];
			fRec381[1] = fRec381[0];
			fRec382[1] = fRec382[0];
			fRec383[1] = fRec383[0];
			fRec384[1] = fRec384[0];
			fRec385[1] = fRec385[0];
			fRec386[1] = fRec386[0];
			fRec387[1] = fRec387[0];
			fRec388[1] = fRec388[0];
			
		}
		
	}

	
};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  	/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2	/* should be defined somewhere ?? */

#define EXTERNAL_VERSION    "0.67"
#define STR_SIZE            512

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <cmath>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class MapUI;

/*******************************************************************************
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 *******************************************************************************/

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}
        virtual void sysEx(std::vector<unsigned char>& message)         {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 ****************************************************/

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->startSync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stopSync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->sysEx(time, message);
                }
            }
        }

};

//-------------------------------
// For timestamped MIDI messages
//-------------------------------

struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

#endif // __midi__
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
        LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = std::atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data is handled.
 ******************************************************************************/

class uiMidi {
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        
    public:
        
        uiMidi(midi* midi_out, bool input):fMidiOut(midi_out), fInputCtrl(input)
        {}
        virtual ~uiMidi()
        {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items
 ******************************************************************************/

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items with timestamp support
 ******************************************************************************/

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

//-------------
// MIDI sync
//-------------

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stopSync(0);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                //uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
                uiItem::modifyZone(FAUSTFLOAT(fState));//uiMidiTimedItem
            }
        }

};

//----------------------
// Standard MIDI events
//----------------------

class uiMidiProgChange : public uiMidiItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return std::pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*std::log(v)/std::log(2.0)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};


class uiMidiKeyPress : public uiMidiItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (fMetaAux[i].second == "pitchwheel" || fMetaAux[i].second == "pitchbend") {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (fMetaAux[i].second == "start") {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "stop") {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "clock") {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(0);
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>
#include <assert.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>


//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingRate)
        {
            instanceInit(samplingRate);
        }
        virtual void instanceInit(int samplingRate)
        {
            instanceConstants(samplingRate);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static double midiToFreq(double note)
{
    return 440.0 * std::pow(2.0, (note-69.0)/12.0);
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;                          // Playing note actual pitch
    int fDate;                          // KeyOn date
    FAUSTFLOAT fLevel;                  // Last audio block level
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain' control
    std::vector<std::string> fFreqPath; // Paths of 'freq' control
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }
    virtual ~dsp_voice()
    {}

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                gain.push_back(path);
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity, bool trigger)
    {
        keyOn(pitch, float(velocity)/127.f, trigger);
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity, bool trigger)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], midiToFreq(pitch));
        }
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fNote = kFreeVoice;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for MIDI controllable DSP.
 */

class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
    
        // Group API
        virtual void setGroup(bool group) = 0;
        virtual bool getGroup() = 0;

};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = int(i);
                    goto result;
                }
            }

            {
                // Otherwise steal one
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = int(i);
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = int(i);
                        }
                    }
                }
            
                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    voice = voice_release;
                    goto result;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    voice = voice_playing;
                    goto result;
                } else {
                    assert(false);
                    return kNoVoice;
                }
            }
            
        result:
            // So that envelop is always re-initialized
            fVoiceTable[voice]->instanceClear();
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *                setGroup/getGroup methods can be used to set/get the group state.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp) // dsp parameter is deallocated by ~dsp_poly
        {
            fDate = 0;

            // Create voices
            assert(nvoices > 0);
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            decorator_dsp::init(samplingRate);
            fVoiceGroup->init(samplingRate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int samplingRate)
        {
            decorator_dsp::instanceConstants(samplingRate);
            fVoiceGroup->instanceConstants(samplingRate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->compute(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }
    
        void setGroup(bool group) { fGroupControl = group; }
        bool getGroup() { return fGroupControl; }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, true);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

};

static std::string pathToContent(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = int(file.tellg());
    file.seekg(0, file.beg);
    
    // And allocate buffer to that a single line can be read...
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    
    // Terminate the string
    buffer[size] = 0;
    std::string result = buffer;
    file.close();
    delete [] buffer;
    return result;
}

/**
 * Polyphonic DSP with an integrated effect. fPolyDSP will respond to MIDI messages.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
        
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* dsp1, dsp* dsp2)
        :dsp_poly(dsp2), fPolyDSP(dsp1)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
        
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
        
        // Group API
        void setGroup(bool group)
        {
            fPolyDSP->setGroup(group);
        }
        bool getGroup()
        {
            return fPolyDSP->getGroup();
        }
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */

struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    dsp_poly_factory(dsp_factory* process_factory = NULL,
                     dsp_factory* effect_factory = NULL):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}
    
    virtual ~dsp_poly_factory()
    {}
    
    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    virtual std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    virtual std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    virtual std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }
    
    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }
    
    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group)
    {
        dsp_poly* dsp_poly = new mydsp_poly(fProcessFactory->createDSPInstance(), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, fEffectFactory->createDSPInstance()));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }
    
    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }
    
};

#endif // __poly_dsp__

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

struct Max_Meta3 : Meta
{
    string fName;
    void declare(const char* key, const char* value)
    {
        if ((strcmp("filename", key) == 0)) {
            fName = "com.grame." + string(value) + "~";
        }
    }
};

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector <t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    midi_handler* m_midiHandler;
#endif
#ifdef SOUNDFILE
    SoundUI* m_soundInterface;
#endif
#ifdef OSCCTRL
    OSCUI* m_oscInterface;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(FAUSTFLOAT f) { *fZone = range(0.0,1.0,f); }
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() { return fLabel; }
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "Button(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

        void toString(char* buffer)
        {
            stringstream str;
            str << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }

		void setValue(FAUSTFLOAT f) { *fZone = range(fMin,fMax,f); }
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
    
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/

#define MULTI_SIZE  256

class mspUI : public UI
{
	private:

        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
       
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string, mspUIObject*>::iterator iterator;

		mspUI() 
        {
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
		virtual ~mspUI()
		{
            clear();
   		}
      
		void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
		}
        
        bool isMulti() { return fMultiControl > 0; }
    
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
		FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }

        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
    
        void displayControls()
        {
            iterator it;
            post((char*)"------- labels and ranges ----------");
            for (it = fUITable1.begin(); it != fUITable1.end(); it++) {
                char param[STR_SIZE];
                it->second->toString(param);
                post(param);
            }
            post((char*)"------- complete paths ----------");
            for (it = fUITable2.begin(); it != fUITable2.end(); it++) {
                post(it->first.c_str());
            }
            post((char*)"---------------------------------");
        }
    
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { return true; }
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { count++; }
    }
    return count;
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        float off = 0.0f;
        float on = 1.0f;
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: 
                    value = (float)ap[0].a_w.w_long;
                    break;
                
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val; num_val << num + i;
            stringstream param_name; param_name << prefix;
            for (int i = 0; i < ndigit - count_digit(num_val.str()); i++) {
                param_name << ' ';
            }
            param_name << num_val.str();
              
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name.str(), value);
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->m_dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(x->m_mutex) == MAX_ERR_NONE) {
    #ifdef MIDICTRL
        mydsp_poly* poly = dynamic_cast<mydsp_poly*>(x->m_dsp);
        if (poly) {
            x->m_midiHandler->removeMidiIn(poly);
        }
    #endif
        // Delete old
        delete x->m_dsp;
        x->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            x->m_dsp = dsp_poly;
        #endif
        } else {
            x->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        x->m_dsp->buildUserInterface(x->m_dspUI);
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        x->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(x);
        
        // Send JSON to JS script
        faust_create_jsui(x);
        
        systhread_mutex_unlock(x->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* x, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            x->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            x->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            x->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, vector<t_object*> >::iterator it1;
    vector<t_object*>::iterator it2;
    for (it1 = x->m_output_table.begin(); it1 != x->m_output_table.end(); it1++) {
        FAUSTFLOAT value = x->m_dspUI->getOutputValue((*it1).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
                object_method_typed((*it2), gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 0) {
        post("polyphonic DSP voices = %d", nvoices);
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
    #else
        x->m_dsp = dsp_poly;
    #endif
        
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
    } else {
        post("monophonic DSP");
        x->m_dsp = new mydsp();
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    // Prepare JSON
    faust_make_json(x);
    
    int num_input;
    
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different

#ifdef SOUNDFILE
    Max_Meta3 meta3;
    x->m_dsp->metadata(&meta3);
    string bundle_path_str = SoundUI::getBinaryPathFrom(meta3.fName);
    if (bundle_path_str == "") {
        post("Bundle_path cannot be found!");
    }
    x->m_soundInterface = new SoundUI(bundle_path_str);
    // SoundUI has to be dispatched on all internal voices
    if (dsp_poly) dsp_poly->setGroup(false);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
    if (dsp_poly) dsp_poly->setGroup(true);
#endif
    
#ifdef OSCCTRL
    x->m_oscInterface = NULL;
#endif
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

#ifdef OSCCTRL
// osc 'IP inport outport xmit bundle'
void faust_osc(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    if (ac == 5) {
        if (systhread_mutex_lock(x->m_mutex) == MAX_ERR_NONE) {
            
            delete x->m_oscInterface;
            
            const char* argv1[32];
            int argc1 = 0;
            
            argv1[argc1++] = "Faust";
            
            argv1[argc1++]  = "-desthost";
            argv1[argc1++]  = atom_getsym(&av[0])->s_name;
            
            char inport[32];
            snprintf(inport, 32, "%ld", long(av[1].a_w.w_long));
            argv1[argc1++] = "-port";
            argv1[argc1++] = inport;
            
            char outport[32];
            snprintf(outport, 32, "%ld", long(av[2].a_w.w_long));
            argv1[argc1++] = "-outport";
            argv1[argc1++] = outport;
            
            char xmit[32];
            snprintf(xmit, 32, "%ld", long(av[3].a_w.w_long));
            argv1[argc1++] = "-xmit";
            argv1[argc1++] = xmit;
            
            char bundle[32];
            snprintf(bundle, 32, "%ld", long(av[4].a_w.w_long));
            argv1[argc1++] = "-bundle";
            argv1[argc1++] = bundle;
            
            x->m_oscInterface = new OSCUI("Faust", argc1, (char**)argv1);
            x->m_dsp->buildUserInterface(x->m_oscInterface);
            x->m_oscInterface->run();
            
            post(x->m_oscInterface->getInfos().c_str());
            systhread_mutex_unlock(x->m_mutex);
        } else {
            post("Mutex lock cannot be taken...");
        }
    } else {
        post("Should be : osc 'IP inport outport xmit(0|1|2) bundle(0|1)'");
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    x->m_dspUI->displayControls();
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher, so we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	delete x->m_dsp;
	delete x->m_dspUI;
	if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    // m_midiUI *must* be deleted before m_midiHandler
    delete x->m_midiUI;
    delete x->m_midiHandler;
#endif
#ifdef SOUNDFILE
    delete x->m_soundInterface;
#endif
#ifdef OSCCTRL
    delete x->m_oscInterface;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(ins[0], sampleframes);
                x->m_dsp->compute(sampleframes, ++ins, outs);
            } else {
                x->m_dsp->compute(sampleframes, ins, outs);
            }
        #ifdef OSCCTRL
            if (x->m_oscInterface) x->m_oscInterface->endBundle();
        #endif
            faust_update_outputs(x);
        }
    #if defined(MIDICTRL) || defined(OSCCTRL)
        GUI::updateAllGuis();
    #endif
        systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

    dsp* tmp_dsp = new mydsp();
    mspUI m_dspUI;
    tmp_dsp->buildUserInterface(&m_dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef OSCCTRL
    addmess((method)faust_osc, (char*)"osc", A_GIMME, 0);
#endif
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2019 Grame");
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/


#endif
