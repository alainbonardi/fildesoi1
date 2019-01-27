//----------------------------------------------------------
// author: "Alain Bonardi"
// name: "mTDelHarmoMG16"
//
// Code generated with Faust 0.9.73 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
/************************************************************************

    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2004-2011 GRAME, Centre National de Creation Musicale
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
#include <math.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
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
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
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


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

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

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

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

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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


 ************************************************************************
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
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

class JSONUI : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fName;
        std::string fExpandedCode;
        std::string fSHAKey;
    
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
        
        void init(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            fTab = 1;
            
            // Start Meta generation
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
        }
        
        inline std::string flatten(const std::string& src)
        {
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        dst << ' ';
                        break;
                    case '"':
                        dst << "\\" << '"';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
      
     public:
     
        JSONUI(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            init(name, inputs, outputs, sha_key, dsp_code);
        }

        JSONUI(const std::string& name, int inputs, int outputs)
        {
            init(name, inputs, outputs, "", "");
        }

        JSONUI(int inputs, int outputs)
        {
            init("", inputs, outputs, "", "");
        }
        
        JSONUI()
        {
            init("", -1, -1, "", "");
        }
 
        virtual ~JSONUI() {}

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
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
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
            tab(fTab, fJSON); fJSON << "}" << std::endl;
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;

//----------------------------------------------------------------
//  Signal processor definition
//----------------------------------------------------------------

class dsp {

    protected:

        int fSamplingFreq;

    public:

        dsp() {}
        virtual ~dsp() {}

        virtual int getNumInputs() = 0;
        virtual int getNumOutputs() = 0;
        virtual void buildUserInterface(UI* ui_interface) = 0;
        virtual void init(int samplingRate) = 0;
        virtual void instanceInit(int samplingRate) = 0;
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

//----------------------------------------------------------------
// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
//----------------------------------------------------------------

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
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

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


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		int 	iRec17[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec17[i] = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				iRec17[0] = (1 + iRec17[1]);
				output[i] = sin((9.587379924285257e-05 * double((iRec17[0] - 1))));
				// post processing
				iRec17[1] = iRec17[0];
			}
		}
	};


	FAUSTFLOAT 	fslider0;
	int 	iConst0;
	double 	fConst1;
	FAUSTFLOAT 	fslider1;
	double 	fRec0[2];
	static double 	ftbl0[65536];
	double 	fConst2;
	FAUSTFLOAT 	fslider2;
	double 	fVec0[2];
	double 	fRec20[2];
	double 	fRec21[2];
	double 	fRec19[2];
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	double 	fRec22[2];
	double 	fConst3;
	double 	fConst4;
	double 	fRec18[2];
	double 	fVec1[2];
	FAUSTFLOAT 	fslider5;
	double 	fRec23[2];
	FAUSTFLOAT 	fcheckbox0;
	double 	fRec24[2];
	FAUSTFLOAT 	fslider6;
	double 	fRec25[2];
	FAUSTFLOAT 	fslider7;
	double 	fRec26[2];
	FAUSTFLOAT 	fslider8;
	double 	fRec27[2];
	FAUSTFLOAT 	fcheckbox1;
	double 	fRec28[2];
	FAUSTFLOAT 	fslider9;
	double 	fRec29[2];
	FAUSTFLOAT 	fslider10;
	double 	fRec30[2];
	FAUSTFLOAT 	fcheckbox2;
	double 	fRec31[2];
	FAUSTFLOAT 	fslider11;
	double 	fRec32[2];
	FAUSTFLOAT 	fslider12;
	double 	fRec33[2];
	FAUSTFLOAT 	fcheckbox3;
	double 	fRec34[2];
	FAUSTFLOAT 	fslider13;
	double 	fRec35[2];
	FAUSTFLOAT 	fslider14;
	double 	fRec36[2];
	FAUSTFLOAT 	fcheckbox4;
	double 	fRec37[2];
	FAUSTFLOAT 	fslider15;
	double 	fRec38[2];
	FAUSTFLOAT 	fslider16;
	double 	fRec39[2];
	FAUSTFLOAT 	fcheckbox5;
	double 	fRec40[2];
	FAUSTFLOAT 	fslider17;
	double 	fRec41[2];
	FAUSTFLOAT 	fslider18;
	double 	fRec42[2];
	FAUSTFLOAT 	fcheckbox6;
	double 	fRec43[2];
	FAUSTFLOAT 	fslider19;
	double 	fRec44[2];
	FAUSTFLOAT 	fslider20;
	double 	fRec45[2];
	FAUSTFLOAT 	fcheckbox7;
	double 	fRec46[2];
	FAUSTFLOAT 	fslider21;
	double 	fRec47[2];
	FAUSTFLOAT 	fslider22;
	double 	fRec48[2];
	FAUSTFLOAT 	fcheckbox8;
	double 	fRec49[2];
	FAUSTFLOAT 	fslider23;
	double 	fRec50[2];
	FAUSTFLOAT 	fslider24;
	double 	fRec51[2];
	FAUSTFLOAT 	fcheckbox9;
	double 	fRec52[2];
	FAUSTFLOAT 	fslider25;
	double 	fRec53[2];
	FAUSTFLOAT 	fslider26;
	double 	fRec54[2];
	FAUSTFLOAT 	fcheckbox10;
	double 	fRec55[2];
	FAUSTFLOAT 	fslider27;
	double 	fRec56[2];
	FAUSTFLOAT 	fslider28;
	double 	fRec57[2];
	FAUSTFLOAT 	fcheckbox11;
	double 	fRec58[2];
	FAUSTFLOAT 	fslider29;
	double 	fRec59[2];
	FAUSTFLOAT 	fslider30;
	double 	fRec60[2];
	FAUSTFLOAT 	fcheckbox12;
	double 	fRec61[2];
	FAUSTFLOAT 	fslider31;
	double 	fRec62[2];
	FAUSTFLOAT 	fslider32;
	double 	fRec63[2];
	FAUSTFLOAT 	fcheckbox13;
	double 	fRec64[2];
	FAUSTFLOAT 	fslider33;
	double 	fRec65[2];
	FAUSTFLOAT 	fslider34;
	double 	fRec66[2];
	FAUSTFLOAT 	fcheckbox14;
	double 	fRec67[2];
	FAUSTFLOAT 	fslider35;
	double 	fRec68[2];
	FAUSTFLOAT 	fslider36;
	double 	fRec69[2];
	FAUSTFLOAT 	fcheckbox15;
	double 	fRec70[2];
	FAUSTFLOAT 	fslider37;
	double 	fRec71[2];
	int 	IOTA;
	double 	fVec2[2097152];
	double 	fConst5;
	double 	fRec73[2];
	double 	fVec3[2];
	double 	fVec4[2];
	FAUSTFLOAT 	fslider38;
	FAUSTFLOAT 	fslider39;
	double 	fConst6;
	double 	fRec74[2];
	double 	fRec72[2];
	double 	fRec75[2];
	double 	fVec5[262144];
	double 	fRec76[2];
	double 	fVec6[2];
	double 	fRec77[2];
	double 	fVec7[2];
	double 	fRec78[2];
	double 	fVec8[2];
	double 	fRec79[2];
	double 	fRec1[2];
	FAUSTFLOAT 	fslider40;
	double 	fRec81[2];
	double 	fRec80[2];
	double 	fVec9[2];
	FAUSTFLOAT 	fcheckbox16;
	double 	fRec82[2];
	FAUSTFLOAT 	fslider41;
	double 	fRec83[2];
	FAUSTFLOAT 	fcheckbox17;
	double 	fRec84[2];
	FAUSTFLOAT 	fcheckbox18;
	double 	fRec85[2];
	FAUSTFLOAT 	fcheckbox19;
	double 	fRec86[2];
	FAUSTFLOAT 	fcheckbox20;
	double 	fRec87[2];
	FAUSTFLOAT 	fcheckbox21;
	double 	fRec88[2];
	FAUSTFLOAT 	fcheckbox22;
	double 	fRec89[2];
	FAUSTFLOAT 	fcheckbox23;
	double 	fRec90[2];
	FAUSTFLOAT 	fcheckbox24;
	double 	fRec91[2];
	FAUSTFLOAT 	fcheckbox25;
	double 	fRec92[2];
	FAUSTFLOAT 	fcheckbox26;
	double 	fRec93[2];
	FAUSTFLOAT 	fcheckbox27;
	double 	fRec94[2];
	FAUSTFLOAT 	fcheckbox28;
	double 	fRec95[2];
	FAUSTFLOAT 	fcheckbox29;
	double 	fRec96[2];
	FAUSTFLOAT 	fcheckbox30;
	double 	fRec97[2];
	FAUSTFLOAT 	fcheckbox31;
	double 	fRec98[2];
	double 	fVec10[2097152];
	FAUSTFLOAT 	fslider42;
	double 	fRec100[2];
	double 	fRec99[2];
	double 	fRec101[2];
	double 	fVec11[262144];
	double 	fRec102[2];
	double 	fVec12[2];
	double 	fRec103[2];
	double 	fVec13[2];
	double 	fRec104[2];
	double 	fVec14[2];
	double 	fRec105[2];
	double 	fRec2[2];
	FAUSTFLOAT 	fslider43;
	double 	fRec107[2];
	double 	fRec106[2];
	double 	fVec15[2];
	FAUSTFLOAT 	fcheckbox32;
	double 	fRec108[2];
	FAUSTFLOAT 	fslider44;
	double 	fRec109[2];
	FAUSTFLOAT 	fcheckbox33;
	double 	fRec110[2];
	FAUSTFLOAT 	fcheckbox34;
	double 	fRec111[2];
	FAUSTFLOAT 	fcheckbox35;
	double 	fRec112[2];
	FAUSTFLOAT 	fcheckbox36;
	double 	fRec113[2];
	FAUSTFLOAT 	fcheckbox37;
	double 	fRec114[2];
	FAUSTFLOAT 	fcheckbox38;
	double 	fRec115[2];
	FAUSTFLOAT 	fcheckbox39;
	double 	fRec116[2];
	FAUSTFLOAT 	fcheckbox40;
	double 	fRec117[2];
	FAUSTFLOAT 	fcheckbox41;
	double 	fRec118[2];
	FAUSTFLOAT 	fcheckbox42;
	double 	fRec119[2];
	FAUSTFLOAT 	fcheckbox43;
	double 	fRec120[2];
	FAUSTFLOAT 	fcheckbox44;
	double 	fRec121[2];
	FAUSTFLOAT 	fcheckbox45;
	double 	fRec122[2];
	FAUSTFLOAT 	fcheckbox46;
	double 	fRec123[2];
	FAUSTFLOAT 	fcheckbox47;
	double 	fRec124[2];
	double 	fVec16[2097152];
	FAUSTFLOAT 	fslider45;
	double 	fRec126[2];
	double 	fRec125[2];
	double 	fRec127[2];
	double 	fVec17[262144];
	double 	fRec128[2];
	double 	fVec18[2];
	double 	fRec129[2];
	double 	fVec19[2];
	double 	fRec130[2];
	double 	fVec20[2];
	double 	fRec131[2];
	double 	fRec3[2];
	FAUSTFLOAT 	fslider46;
	double 	fRec133[2];
	double 	fRec132[2];
	double 	fVec21[2];
	FAUSTFLOAT 	fcheckbox48;
	double 	fRec134[2];
	FAUSTFLOAT 	fslider47;
	double 	fRec135[2];
	FAUSTFLOAT 	fcheckbox49;
	double 	fRec136[2];
	FAUSTFLOAT 	fcheckbox50;
	double 	fRec137[2];
	FAUSTFLOAT 	fcheckbox51;
	double 	fRec138[2];
	FAUSTFLOAT 	fcheckbox52;
	double 	fRec139[2];
	FAUSTFLOAT 	fcheckbox53;
	double 	fRec140[2];
	FAUSTFLOAT 	fcheckbox54;
	double 	fRec141[2];
	FAUSTFLOAT 	fcheckbox55;
	double 	fRec142[2];
	FAUSTFLOAT 	fcheckbox56;
	double 	fRec143[2];
	FAUSTFLOAT 	fcheckbox57;
	double 	fRec144[2];
	FAUSTFLOAT 	fcheckbox58;
	double 	fRec145[2];
	FAUSTFLOAT 	fcheckbox59;
	double 	fRec146[2];
	FAUSTFLOAT 	fcheckbox60;
	double 	fRec147[2];
	FAUSTFLOAT 	fcheckbox61;
	double 	fRec148[2];
	FAUSTFLOAT 	fcheckbox62;
	double 	fRec149[2];
	FAUSTFLOAT 	fcheckbox63;
	double 	fRec150[2];
	double 	fVec22[2097152];
	FAUSTFLOAT 	fslider48;
	double 	fRec152[2];
	double 	fRec151[2];
	double 	fRec153[2];
	double 	fVec23[262144];
	double 	fRec154[2];
	double 	fVec24[2];
	double 	fRec155[2];
	double 	fVec25[2];
	double 	fRec156[2];
	double 	fVec26[2];
	double 	fRec157[2];
	double 	fRec4[2];
	FAUSTFLOAT 	fslider49;
	double 	fRec159[2];
	double 	fRec158[2];
	double 	fVec27[2];
	FAUSTFLOAT 	fcheckbox64;
	double 	fRec160[2];
	FAUSTFLOAT 	fslider50;
	double 	fRec161[2];
	FAUSTFLOAT 	fcheckbox65;
	double 	fRec162[2];
	FAUSTFLOAT 	fcheckbox66;
	double 	fRec163[2];
	FAUSTFLOAT 	fcheckbox67;
	double 	fRec164[2];
	FAUSTFLOAT 	fcheckbox68;
	double 	fRec165[2];
	FAUSTFLOAT 	fcheckbox69;
	double 	fRec166[2];
	FAUSTFLOAT 	fcheckbox70;
	double 	fRec167[2];
	FAUSTFLOAT 	fcheckbox71;
	double 	fRec168[2];
	FAUSTFLOAT 	fcheckbox72;
	double 	fRec169[2];
	FAUSTFLOAT 	fcheckbox73;
	double 	fRec170[2];
	FAUSTFLOAT 	fcheckbox74;
	double 	fRec171[2];
	FAUSTFLOAT 	fcheckbox75;
	double 	fRec172[2];
	FAUSTFLOAT 	fcheckbox76;
	double 	fRec173[2];
	FAUSTFLOAT 	fcheckbox77;
	double 	fRec174[2];
	FAUSTFLOAT 	fcheckbox78;
	double 	fRec175[2];
	FAUSTFLOAT 	fcheckbox79;
	double 	fRec176[2];
	double 	fVec28[2097152];
	FAUSTFLOAT 	fslider51;
	double 	fRec178[2];
	double 	fRec177[2];
	double 	fRec179[2];
	double 	fVec29[262144];
	double 	fRec180[2];
	double 	fVec30[2];
	double 	fRec181[2];
	double 	fVec31[2];
	double 	fRec182[2];
	double 	fVec32[2];
	double 	fRec183[2];
	double 	fRec5[2];
	FAUSTFLOAT 	fslider52;
	double 	fRec185[2];
	double 	fRec184[2];
	double 	fVec33[2];
	FAUSTFLOAT 	fcheckbox80;
	double 	fRec186[2];
	FAUSTFLOAT 	fslider53;
	double 	fRec187[2];
	FAUSTFLOAT 	fcheckbox81;
	double 	fRec188[2];
	FAUSTFLOAT 	fcheckbox82;
	double 	fRec189[2];
	FAUSTFLOAT 	fcheckbox83;
	double 	fRec190[2];
	FAUSTFLOAT 	fcheckbox84;
	double 	fRec191[2];
	FAUSTFLOAT 	fcheckbox85;
	double 	fRec192[2];
	FAUSTFLOAT 	fcheckbox86;
	double 	fRec193[2];
	FAUSTFLOAT 	fcheckbox87;
	double 	fRec194[2];
	FAUSTFLOAT 	fcheckbox88;
	double 	fRec195[2];
	FAUSTFLOAT 	fcheckbox89;
	double 	fRec196[2];
	FAUSTFLOAT 	fcheckbox90;
	double 	fRec197[2];
	FAUSTFLOAT 	fcheckbox91;
	double 	fRec198[2];
	FAUSTFLOAT 	fcheckbox92;
	double 	fRec199[2];
	FAUSTFLOAT 	fcheckbox93;
	double 	fRec200[2];
	FAUSTFLOAT 	fcheckbox94;
	double 	fRec201[2];
	FAUSTFLOAT 	fcheckbox95;
	double 	fRec202[2];
	double 	fVec34[2097152];
	FAUSTFLOAT 	fslider54;
	double 	fRec204[2];
	double 	fRec203[2];
	double 	fRec205[2];
	double 	fVec35[262144];
	double 	fRec206[2];
	double 	fVec36[2];
	double 	fRec207[2];
	double 	fVec37[2];
	double 	fRec208[2];
	double 	fVec38[2];
	double 	fRec209[2];
	double 	fRec6[2];
	FAUSTFLOAT 	fslider55;
	double 	fRec211[2];
	double 	fRec210[2];
	double 	fVec39[2];
	FAUSTFLOAT 	fcheckbox96;
	double 	fRec212[2];
	FAUSTFLOAT 	fslider56;
	double 	fRec213[2];
	FAUSTFLOAT 	fcheckbox97;
	double 	fRec214[2];
	FAUSTFLOAT 	fcheckbox98;
	double 	fRec215[2];
	FAUSTFLOAT 	fcheckbox99;
	double 	fRec216[2];
	FAUSTFLOAT 	fcheckbox100;
	double 	fRec217[2];
	FAUSTFLOAT 	fcheckbox101;
	double 	fRec218[2];
	FAUSTFLOAT 	fcheckbox102;
	double 	fRec219[2];
	FAUSTFLOAT 	fcheckbox103;
	double 	fRec220[2];
	FAUSTFLOAT 	fcheckbox104;
	double 	fRec221[2];
	FAUSTFLOAT 	fcheckbox105;
	double 	fRec222[2];
	FAUSTFLOAT 	fcheckbox106;
	double 	fRec223[2];
	FAUSTFLOAT 	fcheckbox107;
	double 	fRec224[2];
	FAUSTFLOAT 	fcheckbox108;
	double 	fRec225[2];
	FAUSTFLOAT 	fcheckbox109;
	double 	fRec226[2];
	FAUSTFLOAT 	fcheckbox110;
	double 	fRec227[2];
	FAUSTFLOAT 	fcheckbox111;
	double 	fRec228[2];
	double 	fVec40[2097152];
	FAUSTFLOAT 	fslider57;
	double 	fRec230[2];
	double 	fRec229[2];
	double 	fRec231[2];
	double 	fVec41[262144];
	double 	fRec232[2];
	double 	fVec42[2];
	double 	fRec233[2];
	double 	fVec43[2];
	double 	fRec234[2];
	double 	fVec44[2];
	double 	fRec235[2];
	double 	fRec7[2];
	FAUSTFLOAT 	fslider58;
	double 	fRec237[2];
	double 	fRec236[2];
	double 	fVec45[2];
	FAUSTFLOAT 	fcheckbox112;
	double 	fRec238[2];
	FAUSTFLOAT 	fslider59;
	double 	fRec239[2];
	FAUSTFLOAT 	fcheckbox113;
	double 	fRec240[2];
	FAUSTFLOAT 	fcheckbox114;
	double 	fRec241[2];
	FAUSTFLOAT 	fcheckbox115;
	double 	fRec242[2];
	FAUSTFLOAT 	fcheckbox116;
	double 	fRec243[2];
	FAUSTFLOAT 	fcheckbox117;
	double 	fRec244[2];
	FAUSTFLOAT 	fcheckbox118;
	double 	fRec245[2];
	FAUSTFLOAT 	fcheckbox119;
	double 	fRec246[2];
	FAUSTFLOAT 	fcheckbox120;
	double 	fRec247[2];
	FAUSTFLOAT 	fcheckbox121;
	double 	fRec248[2];
	FAUSTFLOAT 	fcheckbox122;
	double 	fRec249[2];
	FAUSTFLOAT 	fcheckbox123;
	double 	fRec250[2];
	FAUSTFLOAT 	fcheckbox124;
	double 	fRec251[2];
	FAUSTFLOAT 	fcheckbox125;
	double 	fRec252[2];
	FAUSTFLOAT 	fcheckbox126;
	double 	fRec253[2];
	FAUSTFLOAT 	fcheckbox127;
	double 	fRec254[2];
	double 	fVec46[2097152];
	FAUSTFLOAT 	fslider60;
	double 	fRec256[2];
	double 	fRec255[2];
	double 	fRec257[2];
	double 	fVec47[262144];
	double 	fRec258[2];
	double 	fVec48[2];
	double 	fRec259[2];
	double 	fVec49[2];
	double 	fRec260[2];
	double 	fVec50[2];
	double 	fRec261[2];
	double 	fRec8[2];
	FAUSTFLOAT 	fslider61;
	double 	fRec263[2];
	double 	fRec262[2];
	double 	fVec51[2];
	FAUSTFLOAT 	fcheckbox128;
	double 	fRec264[2];
	FAUSTFLOAT 	fslider62;
	double 	fRec265[2];
	FAUSTFLOAT 	fcheckbox129;
	double 	fRec266[2];
	FAUSTFLOAT 	fcheckbox130;
	double 	fRec267[2];
	FAUSTFLOAT 	fcheckbox131;
	double 	fRec268[2];
	FAUSTFLOAT 	fcheckbox132;
	double 	fRec269[2];
	FAUSTFLOAT 	fcheckbox133;
	double 	fRec270[2];
	FAUSTFLOAT 	fcheckbox134;
	double 	fRec271[2];
	FAUSTFLOAT 	fcheckbox135;
	double 	fRec272[2];
	FAUSTFLOAT 	fcheckbox136;
	double 	fRec273[2];
	FAUSTFLOAT 	fcheckbox137;
	double 	fRec274[2];
	FAUSTFLOAT 	fcheckbox138;
	double 	fRec275[2];
	FAUSTFLOAT 	fcheckbox139;
	double 	fRec276[2];
	FAUSTFLOAT 	fcheckbox140;
	double 	fRec277[2];
	FAUSTFLOAT 	fcheckbox141;
	double 	fRec278[2];
	FAUSTFLOAT 	fcheckbox142;
	double 	fRec279[2];
	FAUSTFLOAT 	fcheckbox143;
	double 	fRec280[2];
	double 	fVec52[2097152];
	FAUSTFLOAT 	fslider63;
	double 	fRec282[2];
	double 	fRec281[2];
	double 	fRec283[2];
	double 	fVec53[262144];
	double 	fRec284[2];
	double 	fVec54[2];
	double 	fRec285[2];
	double 	fVec55[2];
	double 	fRec286[2];
	double 	fVec56[2];
	double 	fRec287[2];
	double 	fRec9[2];
	FAUSTFLOAT 	fslider64;
	double 	fRec289[2];
	double 	fRec288[2];
	double 	fVec57[2];
	FAUSTFLOAT 	fcheckbox144;
	double 	fRec290[2];
	FAUSTFLOAT 	fslider65;
	double 	fRec291[2];
	FAUSTFLOAT 	fcheckbox145;
	double 	fRec292[2];
	FAUSTFLOAT 	fcheckbox146;
	double 	fRec293[2];
	FAUSTFLOAT 	fcheckbox147;
	double 	fRec294[2];
	FAUSTFLOAT 	fcheckbox148;
	double 	fRec295[2];
	FAUSTFLOAT 	fcheckbox149;
	double 	fRec296[2];
	FAUSTFLOAT 	fcheckbox150;
	double 	fRec297[2];
	FAUSTFLOAT 	fcheckbox151;
	double 	fRec298[2];
	FAUSTFLOAT 	fcheckbox152;
	double 	fRec299[2];
	FAUSTFLOAT 	fcheckbox153;
	double 	fRec300[2];
	FAUSTFLOAT 	fcheckbox154;
	double 	fRec301[2];
	FAUSTFLOAT 	fcheckbox155;
	double 	fRec302[2];
	FAUSTFLOAT 	fcheckbox156;
	double 	fRec303[2];
	FAUSTFLOAT 	fcheckbox157;
	double 	fRec304[2];
	FAUSTFLOAT 	fcheckbox158;
	double 	fRec305[2];
	FAUSTFLOAT 	fcheckbox159;
	double 	fRec306[2];
	double 	fVec58[2097152];
	FAUSTFLOAT 	fslider66;
	double 	fRec308[2];
	double 	fRec307[2];
	double 	fRec309[2];
	double 	fVec59[262144];
	double 	fRec310[2];
	double 	fVec60[2];
	double 	fRec311[2];
	double 	fVec61[2];
	double 	fRec312[2];
	double 	fVec62[2];
	double 	fRec313[2];
	double 	fRec10[2];
	FAUSTFLOAT 	fslider67;
	double 	fRec315[2];
	double 	fRec314[2];
	double 	fVec63[2];
	FAUSTFLOAT 	fcheckbox160;
	double 	fRec316[2];
	FAUSTFLOAT 	fslider68;
	double 	fRec317[2];
	FAUSTFLOAT 	fcheckbox161;
	double 	fRec318[2];
	FAUSTFLOAT 	fcheckbox162;
	double 	fRec319[2];
	FAUSTFLOAT 	fcheckbox163;
	double 	fRec320[2];
	FAUSTFLOAT 	fcheckbox164;
	double 	fRec321[2];
	FAUSTFLOAT 	fcheckbox165;
	double 	fRec322[2];
	FAUSTFLOAT 	fcheckbox166;
	double 	fRec323[2];
	FAUSTFLOAT 	fcheckbox167;
	double 	fRec324[2];
	FAUSTFLOAT 	fcheckbox168;
	double 	fRec325[2];
	FAUSTFLOAT 	fcheckbox169;
	double 	fRec326[2];
	FAUSTFLOAT 	fcheckbox170;
	double 	fRec327[2];
	FAUSTFLOAT 	fcheckbox171;
	double 	fRec328[2];
	FAUSTFLOAT 	fcheckbox172;
	double 	fRec329[2];
	FAUSTFLOAT 	fcheckbox173;
	double 	fRec330[2];
	FAUSTFLOAT 	fcheckbox174;
	double 	fRec331[2];
	FAUSTFLOAT 	fcheckbox175;
	double 	fRec332[2];
	double 	fVec64[2097152];
	FAUSTFLOAT 	fslider69;
	double 	fRec334[2];
	double 	fRec333[2];
	double 	fRec335[2];
	double 	fVec65[262144];
	double 	fRec336[2];
	double 	fVec66[2];
	double 	fRec337[2];
	double 	fVec67[2];
	double 	fRec338[2];
	double 	fVec68[2];
	double 	fRec339[2];
	double 	fRec11[2];
	FAUSTFLOAT 	fslider70;
	double 	fRec341[2];
	double 	fRec340[2];
	double 	fVec69[2];
	FAUSTFLOAT 	fcheckbox176;
	double 	fRec342[2];
	FAUSTFLOAT 	fslider71;
	double 	fRec343[2];
	FAUSTFLOAT 	fcheckbox177;
	double 	fRec344[2];
	FAUSTFLOAT 	fcheckbox178;
	double 	fRec345[2];
	FAUSTFLOAT 	fcheckbox179;
	double 	fRec346[2];
	FAUSTFLOAT 	fcheckbox180;
	double 	fRec347[2];
	FAUSTFLOAT 	fcheckbox181;
	double 	fRec348[2];
	FAUSTFLOAT 	fcheckbox182;
	double 	fRec349[2];
	FAUSTFLOAT 	fcheckbox183;
	double 	fRec350[2];
	FAUSTFLOAT 	fcheckbox184;
	double 	fRec351[2];
	FAUSTFLOAT 	fcheckbox185;
	double 	fRec352[2];
	FAUSTFLOAT 	fcheckbox186;
	double 	fRec353[2];
	FAUSTFLOAT 	fcheckbox187;
	double 	fRec354[2];
	FAUSTFLOAT 	fcheckbox188;
	double 	fRec355[2];
	FAUSTFLOAT 	fcheckbox189;
	double 	fRec356[2];
	FAUSTFLOAT 	fcheckbox190;
	double 	fRec357[2];
	FAUSTFLOAT 	fcheckbox191;
	double 	fRec358[2];
	double 	fVec70[2097152];
	FAUSTFLOAT 	fslider72;
	double 	fRec360[2];
	double 	fRec359[2];
	double 	fRec361[2];
	double 	fVec71[262144];
	double 	fRec362[2];
	double 	fVec72[2];
	double 	fRec363[2];
	double 	fVec73[2];
	double 	fRec364[2];
	double 	fVec74[2];
	double 	fRec365[2];
	double 	fRec12[2];
	FAUSTFLOAT 	fslider73;
	double 	fRec367[2];
	double 	fRec366[2];
	double 	fVec75[2];
	FAUSTFLOAT 	fcheckbox192;
	double 	fRec368[2];
	FAUSTFLOAT 	fslider74;
	double 	fRec369[2];
	FAUSTFLOAT 	fcheckbox193;
	double 	fRec370[2];
	FAUSTFLOAT 	fcheckbox194;
	double 	fRec371[2];
	FAUSTFLOAT 	fcheckbox195;
	double 	fRec372[2];
	FAUSTFLOAT 	fcheckbox196;
	double 	fRec373[2];
	FAUSTFLOAT 	fcheckbox197;
	double 	fRec374[2];
	FAUSTFLOAT 	fcheckbox198;
	double 	fRec375[2];
	FAUSTFLOAT 	fcheckbox199;
	double 	fRec376[2];
	FAUSTFLOAT 	fcheckbox200;
	double 	fRec377[2];
	FAUSTFLOAT 	fcheckbox201;
	double 	fRec378[2];
	FAUSTFLOAT 	fcheckbox202;
	double 	fRec379[2];
	FAUSTFLOAT 	fcheckbox203;
	double 	fRec380[2];
	FAUSTFLOAT 	fcheckbox204;
	double 	fRec381[2];
	FAUSTFLOAT 	fcheckbox205;
	double 	fRec382[2];
	FAUSTFLOAT 	fcheckbox206;
	double 	fRec383[2];
	FAUSTFLOAT 	fcheckbox207;
	double 	fRec384[2];
	double 	fVec76[2097152];
	FAUSTFLOAT 	fslider75;
	double 	fRec386[2];
	double 	fRec385[2];
	double 	fRec387[2];
	double 	fVec77[262144];
	double 	fRec388[2];
	double 	fVec78[2];
	double 	fRec389[2];
	double 	fVec79[2];
	double 	fRec390[2];
	double 	fVec80[2];
	double 	fRec391[2];
	double 	fRec13[2];
	FAUSTFLOAT 	fslider76;
	double 	fRec393[2];
	double 	fRec392[2];
	double 	fVec81[2];
	FAUSTFLOAT 	fcheckbox208;
	double 	fRec394[2];
	FAUSTFLOAT 	fslider77;
	double 	fRec395[2];
	FAUSTFLOAT 	fcheckbox209;
	double 	fRec396[2];
	FAUSTFLOAT 	fcheckbox210;
	double 	fRec397[2];
	FAUSTFLOAT 	fcheckbox211;
	double 	fRec398[2];
	FAUSTFLOAT 	fcheckbox212;
	double 	fRec399[2];
	FAUSTFLOAT 	fcheckbox213;
	double 	fRec400[2];
	FAUSTFLOAT 	fcheckbox214;
	double 	fRec401[2];
	FAUSTFLOAT 	fcheckbox215;
	double 	fRec402[2];
	FAUSTFLOAT 	fcheckbox216;
	double 	fRec403[2];
	FAUSTFLOAT 	fcheckbox217;
	double 	fRec404[2];
	FAUSTFLOAT 	fcheckbox218;
	double 	fRec405[2];
	FAUSTFLOAT 	fcheckbox219;
	double 	fRec406[2];
	FAUSTFLOAT 	fcheckbox220;
	double 	fRec407[2];
	FAUSTFLOAT 	fcheckbox221;
	double 	fRec408[2];
	FAUSTFLOAT 	fcheckbox222;
	double 	fRec409[2];
	FAUSTFLOAT 	fcheckbox223;
	double 	fRec410[2];
	double 	fVec82[2097152];
	FAUSTFLOAT 	fslider78;
	double 	fRec412[2];
	double 	fRec411[2];
	double 	fRec413[2];
	double 	fVec83[262144];
	double 	fRec414[2];
	double 	fVec84[2];
	double 	fRec415[2];
	double 	fVec85[2];
	double 	fRec416[2];
	double 	fVec86[2];
	double 	fRec417[2];
	double 	fRec14[2];
	FAUSTFLOAT 	fslider79;
	double 	fRec419[2];
	double 	fRec418[2];
	double 	fVec87[2];
	FAUSTFLOAT 	fcheckbox224;
	double 	fRec420[2];
	FAUSTFLOAT 	fslider80;
	double 	fRec421[2];
	FAUSTFLOAT 	fcheckbox225;
	double 	fRec422[2];
	FAUSTFLOAT 	fcheckbox226;
	double 	fRec423[2];
	FAUSTFLOAT 	fcheckbox227;
	double 	fRec424[2];
	FAUSTFLOAT 	fcheckbox228;
	double 	fRec425[2];
	FAUSTFLOAT 	fcheckbox229;
	double 	fRec426[2];
	FAUSTFLOAT 	fcheckbox230;
	double 	fRec427[2];
	FAUSTFLOAT 	fcheckbox231;
	double 	fRec428[2];
	FAUSTFLOAT 	fcheckbox232;
	double 	fRec429[2];
	FAUSTFLOAT 	fcheckbox233;
	double 	fRec430[2];
	FAUSTFLOAT 	fcheckbox234;
	double 	fRec431[2];
	FAUSTFLOAT 	fcheckbox235;
	double 	fRec432[2];
	FAUSTFLOAT 	fcheckbox236;
	double 	fRec433[2];
	FAUSTFLOAT 	fcheckbox237;
	double 	fRec434[2];
	FAUSTFLOAT 	fcheckbox238;
	double 	fRec435[2];
	FAUSTFLOAT 	fcheckbox239;
	double 	fRec436[2];
	double 	fVec88[2097152];
	FAUSTFLOAT 	fslider81;
	double 	fRec438[2];
	double 	fRec437[2];
	double 	fRec439[2];
	double 	fVec89[262144];
	double 	fRec440[2];
	double 	fVec90[2];
	double 	fRec441[2];
	double 	fVec91[2];
	double 	fRec442[2];
	double 	fVec92[2];
	double 	fRec443[2];
	double 	fRec15[2];
	FAUSTFLOAT 	fslider82;
	double 	fRec445[2];
	double 	fRec444[2];
	double 	fVec93[2];
	FAUSTFLOAT 	fcheckbox240;
	double 	fRec446[2];
	FAUSTFLOAT 	fslider83;
	double 	fRec447[2];
	FAUSTFLOAT 	fcheckbox241;
	double 	fRec448[2];
	FAUSTFLOAT 	fcheckbox242;
	double 	fRec449[2];
	FAUSTFLOAT 	fcheckbox243;
	double 	fRec450[2];
	FAUSTFLOAT 	fcheckbox244;
	double 	fRec451[2];
	FAUSTFLOAT 	fcheckbox245;
	double 	fRec452[2];
	FAUSTFLOAT 	fcheckbox246;
	double 	fRec453[2];
	FAUSTFLOAT 	fcheckbox247;
	double 	fRec454[2];
	FAUSTFLOAT 	fcheckbox248;
	double 	fRec455[2];
	FAUSTFLOAT 	fcheckbox249;
	double 	fRec456[2];
	FAUSTFLOAT 	fcheckbox250;
	double 	fRec457[2];
	FAUSTFLOAT 	fcheckbox251;
	double 	fRec458[2];
	FAUSTFLOAT 	fcheckbox252;
	double 	fRec459[2];
	FAUSTFLOAT 	fcheckbox253;
	double 	fRec460[2];
	FAUSTFLOAT 	fcheckbox254;
	double 	fRec461[2];
	FAUSTFLOAT 	fcheckbox255;
	double 	fRec462[2];
	double 	fVec94[2097152];
	FAUSTFLOAT 	fslider84;
	double 	fRec464[2];
	double 	fRec463[2];
	double 	fRec465[2];
	double 	fVec95[262144];
	double 	fRec466[2];
	double 	fVec96[2];
	double 	fRec467[2];
	double 	fVec97[2];
	double 	fRec468[2];
	double 	fVec98[2];
	double 	fRec469[2];
	double 	fRec16[2];
	FAUSTFLOAT 	fslider85;
	double 	fRec470[2];
	FAUSTFLOAT 	fslider86;
	double 	fRec471[2];
	FAUSTFLOAT 	fslider87;
	double 	fRec472[2];
	FAUSTFLOAT 	fslider88;
	double 	fRec473[2];
	FAUSTFLOAT 	fslider89;
	double 	fRec474[2];
	FAUSTFLOAT 	fslider90;
	double 	fRec475[2];
	FAUSTFLOAT 	fslider91;
	double 	fRec476[2];
	FAUSTFLOAT 	fslider92;
	double 	fRec477[2];
	FAUSTFLOAT 	fslider93;
	double 	fRec478[2];
	FAUSTFLOAT 	fslider94;
	double 	fRec479[2];
	FAUSTFLOAT 	fslider95;
	double 	fRec480[2];
	FAUSTFLOAT 	fslider96;
	double 	fRec481[2];
	FAUSTFLOAT 	fslider97;
	double 	fRec482[2];
	FAUSTFLOAT 	fslider98;
	double 	fRec483[2];
	FAUSTFLOAT 	fslider99;
	double 	fRec484[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("library_path", "mTDelHarmoHWin1MG16");
		m->declare("compilation_options", "-single -scal");
		m->declare("author", "Alain Bonardi");
		m->declare("filter_lib_Allpass", "An allpass filter has gain 1 at every frequency, but variable phase. Ladder/lattice allpass filters are specified by reflection coefficients. They are defined here as nested allpass filters, hence the names allpassn*.  USAGE:  _ : allpassn(N,sv) : _ **N  = allpass order (number of ladder or lattice sections) **sv = (s1,s2,...,sN) = reflection coefficients (between -1 and 1).  NOTE: For allpassnn only, sv is replaced by tv, where sv(i) = sin(tv(i)), where tv(i) may range between -PI and PI.  REFERENCES: https://ccrma.stanford.edu/~jos/pasp/Conventional_Ladder_Filters.html https://ccrma.stanford.edu/~jos/pasp/Nested_Allpass_Filters.html  QUICK GUIDE  allpassn   - two-multiply lattice - each section is two multiply-adds  allpassnn  - normalized form - four multiplies and two adds per section, but coefficients can be time varying and nonlinear without parametric amplification (modulation of signal energy).  allpassnkl - Kelly-Lochbaum form - four multiplies and two adds per section, but all signals have an immediate physical interpretation as traveling pressure waves, etc.  allpassn1m - One-multiply form - one multiply and three adds per section.     Normally the most efficient in special-purpose hardware.");
		m->declare("filter_lib_Blockrat", "USAGE: dcblockerat(fb); **fb = break frequency in Hz, i.e., -3 dB gain frequency.  NOTE: The amplitude response is substantially flat above fb and sloped at about +6 dB/octave below fb.  Reference: https://ccrma.stanford.edu/~jos/pasp/Bilinear_Transformation.html");
		m->declare("filter_lib_ButterworthBand", "Order 2*Nh Butterworth bandpass filter made using the transformation s <- s + wc^2/s on lowpass(Nh), where wc is the desired bandpass center  frequency.  The lowpass(Nh) cutoff w1 is half the desired bandpass width. A notch-like bandstop filter is similarly made from highpass(Nh).  USAGE:  _ : bandpass(Nh,fl,fu) : _ OR _ : bandstop(Nh,fl,fu) : _ **Nh = HALF the desired bandpass/bandstop order (which is therefore even) **fl = lower -3dB frequency in Hz **fu = upper -3dB frequency in Hz  NOTE: Thus, the passband (stopband) width is fu-fl,  and its center frequency is (fl+fu)/2.  REFERENCE:  http://cnx.org/content/m16913/latest");
		m->declare("filter_lib_ButterworthLow", "Nth-order Butterworth lowpass or highpass filters  USAGE:  _ : lowpass(N,fc) : _ OR _ : highpass(N,fc) : _  **N = filter order (number of poles) [nonnegative constant integer] **fc = desired cut-off frequency (-3dB frequency) in Hz  REFERENCE:  https://ccrma.stanford.edu/~jos/filters/Butterworth_Lowpass_Design.html");
		m->declare("filter_lib_CombBack", "Feed-Back Comb Filter  USAGE:  _ : fb_comb(maxdel,intdel,b0,aN) : _ OR _ : fb_fcomb(maxdel,del,b0,aN) : _ OR _ : rev1(maxdel,del,-aN) : _ **maxdel = maximum delay (a power of 2) **intdel = current (integer) comb-filter delay between 0 and maxdel **del = current (float) comb-filter delay between 0 and maxdel **b0 = gain applied to delay-line input and forwarded to output **aN = minus the gain applied to delay-line output before summing with the input and feeding to the delay line  Reference:  https://ccrma.stanford.edu/~jos/pasp/Feedback_Comb_Filters.html");
		m->declare("filter_lib_CombForward", "Feed-Forward Comb Filter  USAGE: _ : ff_comb(maxdel,intdel,b0,bM) : _ OR _ : ff_fcomb(maxdel,del,b0,bM) : _ **maxdel = maximum delay (a power of 2) **intdel = current (integer) comb-filter delay between 0 and maxdel **del = current (float) comb-filter delay between 0 and maxdel **b0 = gain applied to delay-line input **bM = gain applied to delay-line output and then summed with input  NOTE: ff_comb requires integer delays  (uses delay()  internally) while ff_fcomb takes floating-point delays (uses fdelay() internally).  REFERENCE: https://ccrma.stanford.edu/~jos/pasp/Feedforward_Comb_Filters.html");
		m->declare("filter_lib_CombSchroeder", "Schroeder Allpass Comb Filter  USAGE:  _ : allpass_comb (maxdel,intdel,aN) : _ OR _ : allpass_fcomb(maxdel,del,aN) : _ OR _ : rev2(maxdel,del,-aN) : _ **maxdel = maximum delay (a power of 2) **intdel = current (integer) comb-filter delay between 0 and maxdel **del = current (float) comb-filter delay between 0 and maxdel **aN = minus the feedback gain  NOTE: allpass_comb(maxlen,len,aN) =   ff_comb(maxlen,len,aN,1) :   fb_comb(maxlen,len-1,1,aN); which is a direct-form-1 implementation, requiring two delay lines. The implementation here is direct-form-2 requiring only one delay line.   REFERENCES: https://ccrma.stanford.edu/~jos/pasp/Allpass_Two_Combs.html https://ccrma.stanford.edu/~jos/pasp/Schroeder_Allpass_Sections.html https://ccrma.stanford.edu/~jos/filters/Four_Direct_Forms.html");
		m->declare("filter_lib_Convolution", "Convolution of input signal with given coefficients  USAGE: _ : conv((k1,k2,k3,...,kN)) : _; // Argument = one signal bank OR _ : convN(N,(k1,k2,k3,...)) : _; // Useful when N < count((k1,...))");
		m->declare("filter_lib_FFilterDF", "First-order direct-form digital filter, specified by ANALOG transfer-function polynomials B(s)/A(s), and a frequency-scaling parameter.  USAGE:  tf1s(b1,b0,a0,w1), where          b1 s + b0 H(s) = ----------          s + a0  ** w1 is the desired digital frequency (in radians/second) corresponding to analog frequency 1 rad/sec (i.e., s = j).  METHOD:  Bilinear transform scaled for exact mapping of w1.  REFERENCE:  https://ccrma.stanford.edu/~jos/pasp/Bilinear_Transformation.html");
		m->declare("filter_lib_FIR", "FIR filter (convolution of FIR filter coefficients with a signal)  USAGE:  _ : fir(bv) : _ **bv = b0,b1,...,bn is a parallel bank of coefficient signals.  NOTE:  bv is processed using pattern-matching at compile time, so it must have this normal form (parallel signals).");
		m->declare("filter_lib_FilterBanks", "Arbritary-Crossover Filter-Banks and Spectrum Analyzers  These are similar to the Mth-octave filter-banks above, except that the band-split frequencies are passed explicitly as arguments.   USAGE: _ : filterbank (O,freqs) : par(i,N,_); // Butterworth band-splits OR _ : filterbanki(O,freqs) : par(i,N,_); // Inverted-dc version  **O     = band-split filter order (ODD integer required for filterbank[i]) **freqs = (fc1,fc2,...,fcNs) [in numerically ascending order], where **Ns=N-1 is the number of octave band-splits");
		m->declare("filter_lib_HighShelf", "First-order high shelf filter (gain boost|cut above some frequency)  USAGE:  _ : highshelf(N,Lpi,fx) : _ **N = filter order 1, 3, 5, ... (odd only). **Lpi = desired level (dB) between fx and SR/2 (boost Lpi>0 or cut Lpi<0) **fx = -3dB frequency of highpass band (L0>0) or lower band (L0<0)");
		m->declare("filter_lib_IIR", "Nth-order Infinite-Impulse-Response (IIR) digital filter, implemented in terms of the Transfer-Function (TF) coefficients.  USAGE: _ : iir(bcoeffs,acoeffs) : _ **order = filter order (int) = max(#poles,#zeros) **bcoeffs = (b0,b1,...,b_order) = TF numerator coefficients **acoeffs =    (a1,...,a_order) = TF denominator coeffs (a0=1)  REFERENCE: https://ccrma.stanford.edu/~jos/filters/Four_Direct_Forms.html");
		m->declare("filter_lib_Lagrange", "Delay lines interpolated using Lagrange interpolation  USAGE:  _ : fdelayN(maxdelay, delay, inputsignal) : _ **N=1,2,3, or 4 is the order of the Lagrange interpolation polynomial.  NOTE:  requested delay should not be less than (N-1)/2. While the implementations below appear to use multiple delay lines, they in fact use only one thanks to optimization by the Faust compiler.");
		m->declare("filter_lib_Latch", "Latch input on positive-going transition of clock (sample-and-hold)  USAGE: _ : latch(clocksig) : _");
		m->declare("filter_lib_Lattice", "Compute lattice tap coefficients from transfer-function coefficients  USAGE: nuv = bvav2nuv(bv,av) **av = parallel signal bank    a1,...,aN **bv = parallel signal bank b0,b1,...,aN **nuv = parallel signal bank   nu1,...,nuN **nui is the i'th tap coefficient, **bi is the coefficient of z^(-i) in the filter numerator, **ai is the coefficient of z^(-i) in the filter denominator");
		m->declare("filter_lib_LowPass", "USAGE:  _ : lowpass3e(fc) : _ OR _ : lowpass6e(fc) : _ **fc = -3dB frequency in Hz  REFERENCES: http://en.wikipedia.org/wiki/Elliptic_filter");
		m->declare("filter_lib_LowShelf", "First-order low shelf filter (gain boost|cut between dc and some frequency)  USAGE:  _ : lowshelf(N,L0,fx) : _ **N = filter order 1, 3, 5, ... (odd only). **L0 = desired level (dB) between dc and fx (boost L0>0 or cut L0<0) **fx = -3dB frequency of lowpass band (L0>0) or upper band (L0<0)");
		m->declare("filter_lib_Notch", "USAGE: notchw(width,freq) OR notch(freq) **width = notch width in Hz (approximate) **freq  = notch frequency in Hz  Reference: https://ccrma.stanford.edu/~jos/pasp/Phasing_2nd_Order_Allpass_Filters.html");
		m->declare("filter_lib_OctaveAnalyzer", "mth_octave_analyzer  USAGE  _ : mth_octave_analyzer(O,M,ftop,N) : par(i,N,_); // Oth-order Butterworth OR _ : mth_octave_analyzer6e(M,ftop,N) : par(i,N,_); // 6th-order elliptic **O = order of filter used to split each frequency band into two **M = number of band-slices per octave **N = total number of bands (including dc and Nyquist)");
		m->declare("filter_lib_OctaveSpectral", "Mth-Octave Spectral Level : Display (in bar graphs) the average signal level in each spectral band.  USAGE: _ : mth_octave_spectral_level(M,ftop,NBands,tau,dB_offset); **M = bands per octave **ftop = lower edge frequency of top band **NBands = number of passbands (including highpass and dc bands), **tau = spectral display averaging-time (time constant) in seconds, **dB_offset = constant dB offset in all band level meters.");
		m->declare("filter_lib_Pole", "Leaky Integrator  USAGE: pole(p) **p = pole location = feedback coefficient  Difference equation:  y(n) = x(n) + p * y(n-1)  Reference:  https://ccrma.stanford.edu/~jos/filters/One_Pole.html");
		m->declare("filter_lib_QPeakingEqualizer", "Constant-Q second order peaking equalizer section   USAGE:  _ : peak_eq_cq(Lfx,fx,Q) : _; **Lfx = level (dB) at fx **fx = boost or cut frequency (Hz) **Q = Quality factor = fx/B where B = bandwidth of peak in Hz");
		m->declare("filter_lib_RMPeakingEqualizer", "Regalia-Mitra second order peaking equalizer section  USAGE:  _ : peak_eq_rm(Lfx,fx,tanPiBT) : _; **Lfx = level (dB) at fx **fx = boost or cut frequency (Hz) **tanPiBT = tan(PI*B/SR), where B = -3dB bandwidth (Hz) when 10^(Lfx/20) = 0 ** ~ PI*B/SR for narrow bandwidths B  REFERENCE:  P.A. Regalia, S.K. Mitra, and P.P. Vaidyanathan, The Digital All-Pass Filter: A Versatile Signal Processing Building Block Proceedings of the IEEE, 76(1):19-37, Jan. 1988.  (See pp. 29-30.)");
		m->declare("filter_lib_Reflection", "Compute reflection coefficients sv from transfer-function denominator av  USAGE: sv = av2sv(av) **av = parallel signal bank a1,...,aN **sv = parallel signal bank s1,...,sN **si = ith reflection coefficient, and **ai = coefficient of z^(-i) in the filter transfer-function denominator A(z).  REFERENCE: https://ccrma.stanford.edu/~jos/filters/Step_Down_Procedure.html");
		m->declare("filter_lib_SFilterDF", "Second-order direct-form digital filter, specified by ANALOG transfer-function polynomials B(s)/A(s), and a frequency-scaling parameter.  Digitization via the bilinear transform is built in.  USAGE: tf2s(b2,b1,b0,a1,a0,w1), where            b2 s^2 + b1 s + b0 H(s) = --------------------            s^2 + a1 s + a0 **w1 = the desired digital frequency (in radians/second) corresponding to analog frequency 1 rad/sec (i.e., s = j).  METHOD:  Bilinear transform scaled for exact mapping of w1.  REFERENCE:  https://ccrma.stanford.edu/~jos/pasp/Bilinear_Transformation.html");
		m->declare("filter_lib_SPeakingEqualizer", "Second order peaking equalizer section (gain boost or cut near some frequency)  USAGE:  _ : peak_eq(Lfx,fx,B) : _; **Lfx = level (dB) at fx (boost Lfx>0 or cut Lfx<0) **fx = peak frequency (Hz) **B = bandwidth (B) of peak in Hz");
		m->declare("filter_lib_Smooth", "Exponential smoothing by a unity-dc-gain one-pole lowpass  USAGE:  smooth(tau2pole(tau)) **tau = desired smoothing time constant in seconds, OR smooth(s) **s = smoothness between 0 and 1.  NOTE: s>1 is unstable, and s=1 yields the zero signal for all inputs. The exponential time-constant is approximately  1/(1-s) samples, when s is close to (but less than) 1.  Reference:  https://ccrma.stanford.edu/~jos/mdft/Convolution_Example_2_ADSR.html");
		m->declare("filter_lib_Thiran", "Delay lines interpolated using Thiran allpass interpolation  USAGE:  fdelayNa(maxdelay, delay, inputsignal)  **N=1,2,3, or 4 is the order of the Thiran interpolation filter, and the delay argument is at least N - 1/2.  NOTE:  The interpolated delay should not be less than N - 1/2.  (The allpass delay ranges from N - 1/2 to N + 1/2.)  This constraint can be alleviated by altering the code,  but be aware that allpass filters approach zero delay  by means of pole-zero cancellations.  The delay range [N-1/2,N+1/2] is not optimal. What is?  NOTE:  Delay arguments too small will produce an UNSTABLE allpass!  NOTE:  Because allpass interpolation is recursive, it is not as robust as Lagrange interpolation under time-varying conditions. (You may hear clicks when changing the delay rapidly.)  Reference: https://ccrma.stanford.edu/~jos/pasp/Thiran_Allpass_Interpolators.html");
		m->declare("filter_lib_Waveguide", "Second order normalized digital waveguide resonator USAGE:  _ : nlf2(f,r) : _ **f = resonance frequency (Hz) r = loss factor for exponential decay (set to 1 to make a sinusoidal oscillator)  REFERENCE: https://ccrma.stanford.edu/~jos/pasp/Power_Normalized_Waveguide_Filters.html");
		m->declare("filter_lib_WaveguideT", "Second-order transformer-normalized digital waveguide resonator  USAGE:  _ : wgr(f,r) : _ **f = resonance frequency (Hz) **r = loss factor for exponential decay (set to 1 to make a numerically stable oscillator)  REFERENCES: https://ccrma.stanford.edu/~jos/pasp/Power_Normalized_Waveguide_Filters.html https://ccrma.stanford.edu/~jos/pasp/Digital_Waveguide_Oscillator.html");
		m->declare("filter_lib_Zero", "USAGE: zero(z); **z = location of zero along real axis in z-plane  Difference equation:  y(n) = x(n) - z * x(n-1)  Reference:  https://ccrma.stanford.edu/~jos/filters/One_Zero.html");
		m->declare("filter_lib_author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter_lib_copyright", "Julius O. Smith III");
		m->declare("filter_lib_license", "STK-4.3");
		m->declare("filter_lib_name", "Faust Filter Library");
		m->declare("filter_lib_reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter_lib_version", "1.29");
		m->declare("licence", "GPLv3");
		m->declare("math_lib_author", "GRAME");
		m->declare("math_lib_copyright", "GRAME");
		m->declare("math_lib_license", "LGPL with exception");
		m->declare("math_lib_name", "Math Library");
		m->declare("math_lib_version", "1.0");
		m->declare("maxmsp_lib_author", "GRAME");
		m->declare("maxmsp_lib_copyright", "GRAME");
		m->declare("maxmsp_lib_license", "LGPL");
		m->declare("maxmsp_lib_name", "MaxMSP compatibility Library");
		m->declare("maxmsp_lib_version", "1.1");
		m->declare("music_lib_ADSREnvelop", "ADSR envelop  USAGE: adsr(a,d,s,r,t); **a = attack (sec) **d = decay (sec) **s = sustain (percentage of t) **r = release (sec) **t = trigger signal ( >0 for attack, then release is when t back to 0)");
		m->declare("music_lib_Automat", "Record and replay to the values the input signal in a loop  USAGE:  hslider(...) : automat(360, 15, 0.0)");
		m->declare("music_lib_BSmooth", "bsmooth : (block smooth) linear interpolation during a block of samples  USAGE:  hslider(...) : bsmooth");
		m->declare("music_lib_BreakPoints", "bpf is an environment (a group of related definitions) that can be used to  create break-point functions. It contains three functions :   USAGE: start(x,y) to start a break-point function end(x,y) to end a break-point function point(x,y) to add intermediate points to a break-point function");
		m->declare("music_lib_Cheby", "USAGE:  _ : chebychev(n) : _ **n = transformation order  REFERENCE: http://en.wikipedia.org/wiki/Chebyshev_polynomial");
		m->declare("music_lib_ChebyPoly", "linear combination of the first Chebyshev polynomials  USAGE: _ :  chebychevpoly((c0,c1,...,cn)) : _  REFERENCE: http://www.csounds.com/manual/html/chebyshevpoly.html ");
		m->declare("music_lib_DbConversions", "USAGE:  db2linear(x);  OR linear2db(x); ");
		m->declare("music_lib_MultipleNoise", "Generates multiple decorrelated noises in parallel.  USAGE: multinoise(n)");
		m->declare("music_lib_MultipleRandom", "Generates multiple decorrelated random numbers in parallel.  USAGE: multirandom(n)");
		m->declare("music_lib_Noise", "Noise generator  USAGE: noise: ... ; ");
		m->declare("music_lib_Primitives", "USAGE: tempo(t); **tempo(t) -> samples  period(p) **signal en dent de scie de periode p  pulse(t); **pulse (10000...) de periode p  pulsen(n,t); **pulse (1110000...) de taille n et de periode p  beat(t) **pulse au tempo t");
		m->declare("music_lib_Recursivize", "Create a stereo recursion from two arbitrary processors p and q");
		m->declare("music_lib_SPAT", "GMEM SPAT  USAGE: spat(n,a,d); **n = number of outputs **r = rotation (between 0 et 1) **d = distance of the source (between 0 et 1)");
		m->declare("music_lib_SmoothDelay", "s(mooth)delay : a mono delay that doesn't click and doesn't transpose when the delay time is changed. It takes 4 input signals and produces a delayed output signal  USAGE :  ... : sdelay(N,it,dt) : ... **<N>  = maximal delay in samples (must be a constant power of 2, for example 65536) **<it> = interpolation time (in samples) for example 1024 **<dt> = delay time (in samples) **<  > = input signal we want to delay");
		m->declare("music_lib_Stereoize", "Transform an arbitrary processor p into a stereo processor with 2 inputs and 2 outputs.");
		m->declare("music_lib_author", "GRAME");
		m->declare("music_lib_copyright", "GRAME");
		m->declare("music_lib_license", "LGPL with exception");
		m->declare("music_lib_name", "Music Library");
		m->declare("music_lib_version", "1.0");
		m->declare("name", "mTDelHarmoMG16");
	}

	virtual int getNumInputs() 	{ return 16; }
	virtual int getNumOutputs() 	{ return 16; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 2e+01;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = (1e+03 / double(iConst0));
		fslider1 = 1.0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		fConst2 = (0.03 * iConst0);
		fslider2 = 64.0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		fslider3 = 0.0;
		fslider4 = 1.0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		fConst3 = double(iConst0);
		fConst4 = (1.0 / fConst3);
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		fslider5 = 1.0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		fcheckbox0 = 0.0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		fslider6 = 0.0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		fslider7 = 1.0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		fslider8 = 1.0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		fcheckbox1 = 0.0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		fslider9 = 0.0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		fslider10 = 1.0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		fcheckbox2 = 0.0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		fslider11 = 0.0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		fslider12 = 1.0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		fcheckbox3 = 0.0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		fslider13 = 0.0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		fslider14 = 1.0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		fcheckbox4 = 0.0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		fslider15 = 0.0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		fslider16 = 1.0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		fcheckbox5 = 0.0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		fslider17 = 0.0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		fslider18 = 1.0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		fcheckbox6 = 0.0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		fslider19 = 0.0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		fslider20 = 1.0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		fcheckbox7 = 0.0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		fslider21 = 0.0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		fslider22 = 1.0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		fcheckbox8 = 0.0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		fslider23 = 0.0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		fslider24 = 1.0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		fcheckbox9 = 0.0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		fslider25 = 0.0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		fslider26 = 1.0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		fcheckbox10 = 0.0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		fslider27 = 0.0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		fslider28 = 1.0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		fcheckbox11 = 0.0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		fslider29 = 0.0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		fslider30 = 1.0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		fcheckbox12 = 0.0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		fslider31 = 0.0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		fslider32 = 1.0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		fcheckbox13 = 0.0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		fslider33 = 0.0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		fslider34 = 1.0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		fcheckbox14 = 0.0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		fslider35 = 0.0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		fslider36 = 1.0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		fcheckbox15 = 0.0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		fslider37 = 0.0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		IOTA = 0;
		for (int i=0; i<2097152; i++) fVec2[i] = 0;
		fConst5 = (3e+01 / fConst3);
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		fslider38 = 1e+02;
		fslider39 = 1.0;
		fConst6 = (0.001 * iConst0);
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<262144; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		fslider40 = 0.0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		fcheckbox16 = 0.0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		fslider41 = 1.0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		fcheckbox17 = 0.0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		fcheckbox18 = 0.0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		fcheckbox19 = 0.0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		fcheckbox20 = 0.0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		fcheckbox21 = 0.0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		fcheckbox22 = 0.0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		fcheckbox23 = 0.0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		fcheckbox24 = 0.0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		fcheckbox25 = 0.0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		fcheckbox26 = 0.0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		fcheckbox27 = 0.0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		fcheckbox28 = 0.0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		fcheckbox29 = 0.0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		fcheckbox30 = 0.0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		fcheckbox31 = 0.0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2097152; i++) fVec10[i] = 0;
		fslider42 = 2e+02;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<262144; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fslider43 = 0.0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		fcheckbox32 = 0.0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		fslider44 = 1.0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		fcheckbox33 = 0.0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		fcheckbox34 = 0.0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		fcheckbox35 = 0.0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		fcheckbox36 = 0.0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		fcheckbox37 = 0.0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		fcheckbox38 = 0.0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		fcheckbox39 = 0.0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		fcheckbox40 = 0.0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		fcheckbox41 = 0.0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		fcheckbox42 = 0.0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		fcheckbox43 = 0.0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		fcheckbox44 = 0.0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		fcheckbox45 = 0.0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		fcheckbox46 = 0.0;
		for (int i=0; i<2; i++) fRec123[i] = 0;
		fcheckbox47 = 0.0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<2097152; i++) fVec16[i] = 0;
		fslider45 = 3e+02;
		for (int i=0; i<2; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
		for (int i=0; i<2; i++) fRec127[i] = 0;
		for (int i=0; i<262144; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec129[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec130[i] = 0;
		for (int i=0; i<2; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) fRec131[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		fslider46 = 0.0;
		for (int i=0; i<2; i++) fRec133[i] = 0;
		for (int i=0; i<2; i++) fRec132[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		fcheckbox48 = 0.0;
		for (int i=0; i<2; i++) fRec134[i] = 0;
		fslider47 = 1.0;
		for (int i=0; i<2; i++) fRec135[i] = 0;
		fcheckbox49 = 0.0;
		for (int i=0; i<2; i++) fRec136[i] = 0;
		fcheckbox50 = 0.0;
		for (int i=0; i<2; i++) fRec137[i] = 0;
		fcheckbox51 = 0.0;
		for (int i=0; i<2; i++) fRec138[i] = 0;
		fcheckbox52 = 0.0;
		for (int i=0; i<2; i++) fRec139[i] = 0;
		fcheckbox53 = 0.0;
		for (int i=0; i<2; i++) fRec140[i] = 0;
		fcheckbox54 = 0.0;
		for (int i=0; i<2; i++) fRec141[i] = 0;
		fcheckbox55 = 0.0;
		for (int i=0; i<2; i++) fRec142[i] = 0;
		fcheckbox56 = 0.0;
		for (int i=0; i<2; i++) fRec143[i] = 0;
		fcheckbox57 = 0.0;
		for (int i=0; i<2; i++) fRec144[i] = 0;
		fcheckbox58 = 0.0;
		for (int i=0; i<2; i++) fRec145[i] = 0;
		fcheckbox59 = 0.0;
		for (int i=0; i<2; i++) fRec146[i] = 0;
		fcheckbox60 = 0.0;
		for (int i=0; i<2; i++) fRec147[i] = 0;
		fcheckbox61 = 0.0;
		for (int i=0; i<2; i++) fRec148[i] = 0;
		fcheckbox62 = 0.0;
		for (int i=0; i<2; i++) fRec149[i] = 0;
		fcheckbox63 = 0.0;
		for (int i=0; i<2; i++) fRec150[i] = 0;
		for (int i=0; i<2097152; i++) fVec22[i] = 0;
		fslider48 = 4e+02;
		for (int i=0; i<2; i++) fRec152[i] = 0;
		for (int i=0; i<2; i++) fRec151[i] = 0;
		for (int i=0; i<2; i++) fRec153[i] = 0;
		for (int i=0; i<262144; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec154[i] = 0;
		for (int i=0; i<2; i++) fVec24[i] = 0;
		for (int i=0; i<2; i++) fRec155[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec156[i] = 0;
		for (int i=0; i<2; i++) fVec26[i] = 0;
		for (int i=0; i<2; i++) fRec157[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fslider49 = 0.0;
		for (int i=0; i<2; i++) fRec159[i] = 0;
		for (int i=0; i<2; i++) fRec158[i] = 0;
		for (int i=0; i<2; i++) fVec27[i] = 0;
		fcheckbox64 = 0.0;
		for (int i=0; i<2; i++) fRec160[i] = 0;
		fslider50 = 1.0;
		for (int i=0; i<2; i++) fRec161[i] = 0;
		fcheckbox65 = 0.0;
		for (int i=0; i<2; i++) fRec162[i] = 0;
		fcheckbox66 = 0.0;
		for (int i=0; i<2; i++) fRec163[i] = 0;
		fcheckbox67 = 0.0;
		for (int i=0; i<2; i++) fRec164[i] = 0;
		fcheckbox68 = 0.0;
		for (int i=0; i<2; i++) fRec165[i] = 0;
		fcheckbox69 = 0.0;
		for (int i=0; i<2; i++) fRec166[i] = 0;
		fcheckbox70 = 0.0;
		for (int i=0; i<2; i++) fRec167[i] = 0;
		fcheckbox71 = 0.0;
		for (int i=0; i<2; i++) fRec168[i] = 0;
		fcheckbox72 = 0.0;
		for (int i=0; i<2; i++) fRec169[i] = 0;
		fcheckbox73 = 0.0;
		for (int i=0; i<2; i++) fRec170[i] = 0;
		fcheckbox74 = 0.0;
		for (int i=0; i<2; i++) fRec171[i] = 0;
		fcheckbox75 = 0.0;
		for (int i=0; i<2; i++) fRec172[i] = 0;
		fcheckbox76 = 0.0;
		for (int i=0; i<2; i++) fRec173[i] = 0;
		fcheckbox77 = 0.0;
		for (int i=0; i<2; i++) fRec174[i] = 0;
		fcheckbox78 = 0.0;
		for (int i=0; i<2; i++) fRec175[i] = 0;
		fcheckbox79 = 0.0;
		for (int i=0; i<2; i++) fRec176[i] = 0;
		for (int i=0; i<2097152; i++) fVec28[i] = 0;
		fslider51 = 5e+02;
		for (int i=0; i<2; i++) fRec178[i] = 0;
		for (int i=0; i<2; i++) fRec177[i] = 0;
		for (int i=0; i<2; i++) fRec179[i] = 0;
		for (int i=0; i<262144; i++) fVec29[i] = 0;
		for (int i=0; i<2; i++) fRec180[i] = 0;
		for (int i=0; i<2; i++) fVec30[i] = 0;
		for (int i=0; i<2; i++) fRec181[i] = 0;
		for (int i=0; i<2; i++) fVec31[i] = 0;
		for (int i=0; i<2; i++) fRec182[i] = 0;
		for (int i=0; i<2; i++) fVec32[i] = 0;
		for (int i=0; i<2; i++) fRec183[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		fslider52 = 0.0;
		for (int i=0; i<2; i++) fRec185[i] = 0;
		for (int i=0; i<2; i++) fRec184[i] = 0;
		for (int i=0; i<2; i++) fVec33[i] = 0;
		fcheckbox80 = 0.0;
		for (int i=0; i<2; i++) fRec186[i] = 0;
		fslider53 = 1.0;
		for (int i=0; i<2; i++) fRec187[i] = 0;
		fcheckbox81 = 0.0;
		for (int i=0; i<2; i++) fRec188[i] = 0;
		fcheckbox82 = 0.0;
		for (int i=0; i<2; i++) fRec189[i] = 0;
		fcheckbox83 = 0.0;
		for (int i=0; i<2; i++) fRec190[i] = 0;
		fcheckbox84 = 0.0;
		for (int i=0; i<2; i++) fRec191[i] = 0;
		fcheckbox85 = 0.0;
		for (int i=0; i<2; i++) fRec192[i] = 0;
		fcheckbox86 = 0.0;
		for (int i=0; i<2; i++) fRec193[i] = 0;
		fcheckbox87 = 0.0;
		for (int i=0; i<2; i++) fRec194[i] = 0;
		fcheckbox88 = 0.0;
		for (int i=0; i<2; i++) fRec195[i] = 0;
		fcheckbox89 = 0.0;
		for (int i=0; i<2; i++) fRec196[i] = 0;
		fcheckbox90 = 0.0;
		for (int i=0; i<2; i++) fRec197[i] = 0;
		fcheckbox91 = 0.0;
		for (int i=0; i<2; i++) fRec198[i] = 0;
		fcheckbox92 = 0.0;
		for (int i=0; i<2; i++) fRec199[i] = 0;
		fcheckbox93 = 0.0;
		for (int i=0; i<2; i++) fRec200[i] = 0;
		fcheckbox94 = 0.0;
		for (int i=0; i<2; i++) fRec201[i] = 0;
		fcheckbox95 = 0.0;
		for (int i=0; i<2; i++) fRec202[i] = 0;
		for (int i=0; i<2097152; i++) fVec34[i] = 0;
		fslider54 = 6e+02;
		for (int i=0; i<2; i++) fRec204[i] = 0;
		for (int i=0; i<2; i++) fRec203[i] = 0;
		for (int i=0; i<2; i++) fRec205[i] = 0;
		for (int i=0; i<262144; i++) fVec35[i] = 0;
		for (int i=0; i<2; i++) fRec206[i] = 0;
		for (int i=0; i<2; i++) fVec36[i] = 0;
		for (int i=0; i<2; i++) fRec207[i] = 0;
		for (int i=0; i<2; i++) fVec37[i] = 0;
		for (int i=0; i<2; i++) fRec208[i] = 0;
		for (int i=0; i<2; i++) fVec38[i] = 0;
		for (int i=0; i<2; i++) fRec209[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		fslider55 = 0.0;
		for (int i=0; i<2; i++) fRec211[i] = 0;
		for (int i=0; i<2; i++) fRec210[i] = 0;
		for (int i=0; i<2; i++) fVec39[i] = 0;
		fcheckbox96 = 0.0;
		for (int i=0; i<2; i++) fRec212[i] = 0;
		fslider56 = 1.0;
		for (int i=0; i<2; i++) fRec213[i] = 0;
		fcheckbox97 = 0.0;
		for (int i=0; i<2; i++) fRec214[i] = 0;
		fcheckbox98 = 0.0;
		for (int i=0; i<2; i++) fRec215[i] = 0;
		fcheckbox99 = 0.0;
		for (int i=0; i<2; i++) fRec216[i] = 0;
		fcheckbox100 = 0.0;
		for (int i=0; i<2; i++) fRec217[i] = 0;
		fcheckbox101 = 0.0;
		for (int i=0; i<2; i++) fRec218[i] = 0;
		fcheckbox102 = 0.0;
		for (int i=0; i<2; i++) fRec219[i] = 0;
		fcheckbox103 = 0.0;
		for (int i=0; i<2; i++) fRec220[i] = 0;
		fcheckbox104 = 0.0;
		for (int i=0; i<2; i++) fRec221[i] = 0;
		fcheckbox105 = 0.0;
		for (int i=0; i<2; i++) fRec222[i] = 0;
		fcheckbox106 = 0.0;
		for (int i=0; i<2; i++) fRec223[i] = 0;
		fcheckbox107 = 0.0;
		for (int i=0; i<2; i++) fRec224[i] = 0;
		fcheckbox108 = 0.0;
		for (int i=0; i<2; i++) fRec225[i] = 0;
		fcheckbox109 = 0.0;
		for (int i=0; i<2; i++) fRec226[i] = 0;
		fcheckbox110 = 0.0;
		for (int i=0; i<2; i++) fRec227[i] = 0;
		fcheckbox111 = 0.0;
		for (int i=0; i<2; i++) fRec228[i] = 0;
		for (int i=0; i<2097152; i++) fVec40[i] = 0;
		fslider57 = 7e+02;
		for (int i=0; i<2; i++) fRec230[i] = 0;
		for (int i=0; i<2; i++) fRec229[i] = 0;
		for (int i=0; i<2; i++) fRec231[i] = 0;
		for (int i=0; i<262144; i++) fVec41[i] = 0;
		for (int i=0; i<2; i++) fRec232[i] = 0;
		for (int i=0; i<2; i++) fVec42[i] = 0;
		for (int i=0; i<2; i++) fRec233[i] = 0;
		for (int i=0; i<2; i++) fVec43[i] = 0;
		for (int i=0; i<2; i++) fRec234[i] = 0;
		for (int i=0; i<2; i++) fVec44[i] = 0;
		for (int i=0; i<2; i++) fRec235[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		fslider58 = 0.0;
		for (int i=0; i<2; i++) fRec237[i] = 0;
		for (int i=0; i<2; i++) fRec236[i] = 0;
		for (int i=0; i<2; i++) fVec45[i] = 0;
		fcheckbox112 = 0.0;
		for (int i=0; i<2; i++) fRec238[i] = 0;
		fslider59 = 1.0;
		for (int i=0; i<2; i++) fRec239[i] = 0;
		fcheckbox113 = 0.0;
		for (int i=0; i<2; i++) fRec240[i] = 0;
		fcheckbox114 = 0.0;
		for (int i=0; i<2; i++) fRec241[i] = 0;
		fcheckbox115 = 0.0;
		for (int i=0; i<2; i++) fRec242[i] = 0;
		fcheckbox116 = 0.0;
		for (int i=0; i<2; i++) fRec243[i] = 0;
		fcheckbox117 = 0.0;
		for (int i=0; i<2; i++) fRec244[i] = 0;
		fcheckbox118 = 0.0;
		for (int i=0; i<2; i++) fRec245[i] = 0;
		fcheckbox119 = 0.0;
		for (int i=0; i<2; i++) fRec246[i] = 0;
		fcheckbox120 = 0.0;
		for (int i=0; i<2; i++) fRec247[i] = 0;
		fcheckbox121 = 0.0;
		for (int i=0; i<2; i++) fRec248[i] = 0;
		fcheckbox122 = 0.0;
		for (int i=0; i<2; i++) fRec249[i] = 0;
		fcheckbox123 = 0.0;
		for (int i=0; i<2; i++) fRec250[i] = 0;
		fcheckbox124 = 0.0;
		for (int i=0; i<2; i++) fRec251[i] = 0;
		fcheckbox125 = 0.0;
		for (int i=0; i<2; i++) fRec252[i] = 0;
		fcheckbox126 = 0.0;
		for (int i=0; i<2; i++) fRec253[i] = 0;
		fcheckbox127 = 0.0;
		for (int i=0; i<2; i++) fRec254[i] = 0;
		for (int i=0; i<2097152; i++) fVec46[i] = 0;
		fslider60 = 8e+02;
		for (int i=0; i<2; i++) fRec256[i] = 0;
		for (int i=0; i<2; i++) fRec255[i] = 0;
		for (int i=0; i<2; i++) fRec257[i] = 0;
		for (int i=0; i<262144; i++) fVec47[i] = 0;
		for (int i=0; i<2; i++) fRec258[i] = 0;
		for (int i=0; i<2; i++) fVec48[i] = 0;
		for (int i=0; i<2; i++) fRec259[i] = 0;
		for (int i=0; i<2; i++) fVec49[i] = 0;
		for (int i=0; i<2; i++) fRec260[i] = 0;
		for (int i=0; i<2; i++) fVec50[i] = 0;
		for (int i=0; i<2; i++) fRec261[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		fslider61 = 0.0;
		for (int i=0; i<2; i++) fRec263[i] = 0;
		for (int i=0; i<2; i++) fRec262[i] = 0;
		for (int i=0; i<2; i++) fVec51[i] = 0;
		fcheckbox128 = 0.0;
		for (int i=0; i<2; i++) fRec264[i] = 0;
		fslider62 = 1.0;
		for (int i=0; i<2; i++) fRec265[i] = 0;
		fcheckbox129 = 0.0;
		for (int i=0; i<2; i++) fRec266[i] = 0;
		fcheckbox130 = 0.0;
		for (int i=0; i<2; i++) fRec267[i] = 0;
		fcheckbox131 = 0.0;
		for (int i=0; i<2; i++) fRec268[i] = 0;
		fcheckbox132 = 0.0;
		for (int i=0; i<2; i++) fRec269[i] = 0;
		fcheckbox133 = 0.0;
		for (int i=0; i<2; i++) fRec270[i] = 0;
		fcheckbox134 = 0.0;
		for (int i=0; i<2; i++) fRec271[i] = 0;
		fcheckbox135 = 0.0;
		for (int i=0; i<2; i++) fRec272[i] = 0;
		fcheckbox136 = 0.0;
		for (int i=0; i<2; i++) fRec273[i] = 0;
		fcheckbox137 = 0.0;
		for (int i=0; i<2; i++) fRec274[i] = 0;
		fcheckbox138 = 0.0;
		for (int i=0; i<2; i++) fRec275[i] = 0;
		fcheckbox139 = 0.0;
		for (int i=0; i<2; i++) fRec276[i] = 0;
		fcheckbox140 = 0.0;
		for (int i=0; i<2; i++) fRec277[i] = 0;
		fcheckbox141 = 0.0;
		for (int i=0; i<2; i++) fRec278[i] = 0;
		fcheckbox142 = 0.0;
		for (int i=0; i<2; i++) fRec279[i] = 0;
		fcheckbox143 = 0.0;
		for (int i=0; i<2; i++) fRec280[i] = 0;
		for (int i=0; i<2097152; i++) fVec52[i] = 0;
		fslider63 = 9e+02;
		for (int i=0; i<2; i++) fRec282[i] = 0;
		for (int i=0; i<2; i++) fRec281[i] = 0;
		for (int i=0; i<2; i++) fRec283[i] = 0;
		for (int i=0; i<262144; i++) fVec53[i] = 0;
		for (int i=0; i<2; i++) fRec284[i] = 0;
		for (int i=0; i<2; i++) fVec54[i] = 0;
		for (int i=0; i<2; i++) fRec285[i] = 0;
		for (int i=0; i<2; i++) fVec55[i] = 0;
		for (int i=0; i<2; i++) fRec286[i] = 0;
		for (int i=0; i<2; i++) fVec56[i] = 0;
		for (int i=0; i<2; i++) fRec287[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		fslider64 = 0.0;
		for (int i=0; i<2; i++) fRec289[i] = 0;
		for (int i=0; i<2; i++) fRec288[i] = 0;
		for (int i=0; i<2; i++) fVec57[i] = 0;
		fcheckbox144 = 0.0;
		for (int i=0; i<2; i++) fRec290[i] = 0;
		fslider65 = 1.0;
		for (int i=0; i<2; i++) fRec291[i] = 0;
		fcheckbox145 = 0.0;
		for (int i=0; i<2; i++) fRec292[i] = 0;
		fcheckbox146 = 0.0;
		for (int i=0; i<2; i++) fRec293[i] = 0;
		fcheckbox147 = 0.0;
		for (int i=0; i<2; i++) fRec294[i] = 0;
		fcheckbox148 = 0.0;
		for (int i=0; i<2; i++) fRec295[i] = 0;
		fcheckbox149 = 0.0;
		for (int i=0; i<2; i++) fRec296[i] = 0;
		fcheckbox150 = 0.0;
		for (int i=0; i<2; i++) fRec297[i] = 0;
		fcheckbox151 = 0.0;
		for (int i=0; i<2; i++) fRec298[i] = 0;
		fcheckbox152 = 0.0;
		for (int i=0; i<2; i++) fRec299[i] = 0;
		fcheckbox153 = 0.0;
		for (int i=0; i<2; i++) fRec300[i] = 0;
		fcheckbox154 = 0.0;
		for (int i=0; i<2; i++) fRec301[i] = 0;
		fcheckbox155 = 0.0;
		for (int i=0; i<2; i++) fRec302[i] = 0;
		fcheckbox156 = 0.0;
		for (int i=0; i<2; i++) fRec303[i] = 0;
		fcheckbox157 = 0.0;
		for (int i=0; i<2; i++) fRec304[i] = 0;
		fcheckbox158 = 0.0;
		for (int i=0; i<2; i++) fRec305[i] = 0;
		fcheckbox159 = 0.0;
		for (int i=0; i<2; i++) fRec306[i] = 0;
		for (int i=0; i<2097152; i++) fVec58[i] = 0;
		fslider66 = 1e+03;
		for (int i=0; i<2; i++) fRec308[i] = 0;
		for (int i=0; i<2; i++) fRec307[i] = 0;
		for (int i=0; i<2; i++) fRec309[i] = 0;
		for (int i=0; i<262144; i++) fVec59[i] = 0;
		for (int i=0; i<2; i++) fRec310[i] = 0;
		for (int i=0; i<2; i++) fVec60[i] = 0;
		for (int i=0; i<2; i++) fRec311[i] = 0;
		for (int i=0; i<2; i++) fVec61[i] = 0;
		for (int i=0; i<2; i++) fRec312[i] = 0;
		for (int i=0; i<2; i++) fVec62[i] = 0;
		for (int i=0; i<2; i++) fRec313[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		fslider67 = 0.0;
		for (int i=0; i<2; i++) fRec315[i] = 0;
		for (int i=0; i<2; i++) fRec314[i] = 0;
		for (int i=0; i<2; i++) fVec63[i] = 0;
		fcheckbox160 = 0.0;
		for (int i=0; i<2; i++) fRec316[i] = 0;
		fslider68 = 1.0;
		for (int i=0; i<2; i++) fRec317[i] = 0;
		fcheckbox161 = 0.0;
		for (int i=0; i<2; i++) fRec318[i] = 0;
		fcheckbox162 = 0.0;
		for (int i=0; i<2; i++) fRec319[i] = 0;
		fcheckbox163 = 0.0;
		for (int i=0; i<2; i++) fRec320[i] = 0;
		fcheckbox164 = 0.0;
		for (int i=0; i<2; i++) fRec321[i] = 0;
		fcheckbox165 = 0.0;
		for (int i=0; i<2; i++) fRec322[i] = 0;
		fcheckbox166 = 0.0;
		for (int i=0; i<2; i++) fRec323[i] = 0;
		fcheckbox167 = 0.0;
		for (int i=0; i<2; i++) fRec324[i] = 0;
		fcheckbox168 = 0.0;
		for (int i=0; i<2; i++) fRec325[i] = 0;
		fcheckbox169 = 0.0;
		for (int i=0; i<2; i++) fRec326[i] = 0;
		fcheckbox170 = 0.0;
		for (int i=0; i<2; i++) fRec327[i] = 0;
		fcheckbox171 = 0.0;
		for (int i=0; i<2; i++) fRec328[i] = 0;
		fcheckbox172 = 0.0;
		for (int i=0; i<2; i++) fRec329[i] = 0;
		fcheckbox173 = 0.0;
		for (int i=0; i<2; i++) fRec330[i] = 0;
		fcheckbox174 = 0.0;
		for (int i=0; i<2; i++) fRec331[i] = 0;
		fcheckbox175 = 0.0;
		for (int i=0; i<2; i++) fRec332[i] = 0;
		for (int i=0; i<2097152; i++) fVec64[i] = 0;
		fslider69 = 1.1e+03;
		for (int i=0; i<2; i++) fRec334[i] = 0;
		for (int i=0; i<2; i++) fRec333[i] = 0;
		for (int i=0; i<2; i++) fRec335[i] = 0;
		for (int i=0; i<262144; i++) fVec65[i] = 0;
		for (int i=0; i<2; i++) fRec336[i] = 0;
		for (int i=0; i<2; i++) fVec66[i] = 0;
		for (int i=0; i<2; i++) fRec337[i] = 0;
		for (int i=0; i<2; i++) fVec67[i] = 0;
		for (int i=0; i<2; i++) fRec338[i] = 0;
		for (int i=0; i<2; i++) fVec68[i] = 0;
		for (int i=0; i<2; i++) fRec339[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		fslider70 = 0.0;
		for (int i=0; i<2; i++) fRec341[i] = 0;
		for (int i=0; i<2; i++) fRec340[i] = 0;
		for (int i=0; i<2; i++) fVec69[i] = 0;
		fcheckbox176 = 0.0;
		for (int i=0; i<2; i++) fRec342[i] = 0;
		fslider71 = 1.0;
		for (int i=0; i<2; i++) fRec343[i] = 0;
		fcheckbox177 = 0.0;
		for (int i=0; i<2; i++) fRec344[i] = 0;
		fcheckbox178 = 0.0;
		for (int i=0; i<2; i++) fRec345[i] = 0;
		fcheckbox179 = 0.0;
		for (int i=0; i<2; i++) fRec346[i] = 0;
		fcheckbox180 = 0.0;
		for (int i=0; i<2; i++) fRec347[i] = 0;
		fcheckbox181 = 0.0;
		for (int i=0; i<2; i++) fRec348[i] = 0;
		fcheckbox182 = 0.0;
		for (int i=0; i<2; i++) fRec349[i] = 0;
		fcheckbox183 = 0.0;
		for (int i=0; i<2; i++) fRec350[i] = 0;
		fcheckbox184 = 0.0;
		for (int i=0; i<2; i++) fRec351[i] = 0;
		fcheckbox185 = 0.0;
		for (int i=0; i<2; i++) fRec352[i] = 0;
		fcheckbox186 = 0.0;
		for (int i=0; i<2; i++) fRec353[i] = 0;
		fcheckbox187 = 0.0;
		for (int i=0; i<2; i++) fRec354[i] = 0;
		fcheckbox188 = 0.0;
		for (int i=0; i<2; i++) fRec355[i] = 0;
		fcheckbox189 = 0.0;
		for (int i=0; i<2; i++) fRec356[i] = 0;
		fcheckbox190 = 0.0;
		for (int i=0; i<2; i++) fRec357[i] = 0;
		fcheckbox191 = 0.0;
		for (int i=0; i<2; i++) fRec358[i] = 0;
		for (int i=0; i<2097152; i++) fVec70[i] = 0;
		fslider72 = 1.2e+03;
		for (int i=0; i<2; i++) fRec360[i] = 0;
		for (int i=0; i<2; i++) fRec359[i] = 0;
		for (int i=0; i<2; i++) fRec361[i] = 0;
		for (int i=0; i<262144; i++) fVec71[i] = 0;
		for (int i=0; i<2; i++) fRec362[i] = 0;
		for (int i=0; i<2; i++) fVec72[i] = 0;
		for (int i=0; i<2; i++) fRec363[i] = 0;
		for (int i=0; i<2; i++) fVec73[i] = 0;
		for (int i=0; i<2; i++) fRec364[i] = 0;
		for (int i=0; i<2; i++) fVec74[i] = 0;
		for (int i=0; i<2; i++) fRec365[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		fslider73 = 0.0;
		for (int i=0; i<2; i++) fRec367[i] = 0;
		for (int i=0; i<2; i++) fRec366[i] = 0;
		for (int i=0; i<2; i++) fVec75[i] = 0;
		fcheckbox192 = 0.0;
		for (int i=0; i<2; i++) fRec368[i] = 0;
		fslider74 = 1.0;
		for (int i=0; i<2; i++) fRec369[i] = 0;
		fcheckbox193 = 0.0;
		for (int i=0; i<2; i++) fRec370[i] = 0;
		fcheckbox194 = 0.0;
		for (int i=0; i<2; i++) fRec371[i] = 0;
		fcheckbox195 = 0.0;
		for (int i=0; i<2; i++) fRec372[i] = 0;
		fcheckbox196 = 0.0;
		for (int i=0; i<2; i++) fRec373[i] = 0;
		fcheckbox197 = 0.0;
		for (int i=0; i<2; i++) fRec374[i] = 0;
		fcheckbox198 = 0.0;
		for (int i=0; i<2; i++) fRec375[i] = 0;
		fcheckbox199 = 0.0;
		for (int i=0; i<2; i++) fRec376[i] = 0;
		fcheckbox200 = 0.0;
		for (int i=0; i<2; i++) fRec377[i] = 0;
		fcheckbox201 = 0.0;
		for (int i=0; i<2; i++) fRec378[i] = 0;
		fcheckbox202 = 0.0;
		for (int i=0; i<2; i++) fRec379[i] = 0;
		fcheckbox203 = 0.0;
		for (int i=0; i<2; i++) fRec380[i] = 0;
		fcheckbox204 = 0.0;
		for (int i=0; i<2; i++) fRec381[i] = 0;
		fcheckbox205 = 0.0;
		for (int i=0; i<2; i++) fRec382[i] = 0;
		fcheckbox206 = 0.0;
		for (int i=0; i<2; i++) fRec383[i] = 0;
		fcheckbox207 = 0.0;
		for (int i=0; i<2; i++) fRec384[i] = 0;
		for (int i=0; i<2097152; i++) fVec76[i] = 0;
		fslider75 = 1.3e+03;
		for (int i=0; i<2; i++) fRec386[i] = 0;
		for (int i=0; i<2; i++) fRec385[i] = 0;
		for (int i=0; i<2; i++) fRec387[i] = 0;
		for (int i=0; i<262144; i++) fVec77[i] = 0;
		for (int i=0; i<2; i++) fRec388[i] = 0;
		for (int i=0; i<2; i++) fVec78[i] = 0;
		for (int i=0; i<2; i++) fRec389[i] = 0;
		for (int i=0; i<2; i++) fVec79[i] = 0;
		for (int i=0; i<2; i++) fRec390[i] = 0;
		for (int i=0; i<2; i++) fVec80[i] = 0;
		for (int i=0; i<2; i++) fRec391[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		fslider76 = 0.0;
		for (int i=0; i<2; i++) fRec393[i] = 0;
		for (int i=0; i<2; i++) fRec392[i] = 0;
		for (int i=0; i<2; i++) fVec81[i] = 0;
		fcheckbox208 = 0.0;
		for (int i=0; i<2; i++) fRec394[i] = 0;
		fslider77 = 1.0;
		for (int i=0; i<2; i++) fRec395[i] = 0;
		fcheckbox209 = 0.0;
		for (int i=0; i<2; i++) fRec396[i] = 0;
		fcheckbox210 = 0.0;
		for (int i=0; i<2; i++) fRec397[i] = 0;
		fcheckbox211 = 0.0;
		for (int i=0; i<2; i++) fRec398[i] = 0;
		fcheckbox212 = 0.0;
		for (int i=0; i<2; i++) fRec399[i] = 0;
		fcheckbox213 = 0.0;
		for (int i=0; i<2; i++) fRec400[i] = 0;
		fcheckbox214 = 0.0;
		for (int i=0; i<2; i++) fRec401[i] = 0;
		fcheckbox215 = 0.0;
		for (int i=0; i<2; i++) fRec402[i] = 0;
		fcheckbox216 = 0.0;
		for (int i=0; i<2; i++) fRec403[i] = 0;
		fcheckbox217 = 0.0;
		for (int i=0; i<2; i++) fRec404[i] = 0;
		fcheckbox218 = 0.0;
		for (int i=0; i<2; i++) fRec405[i] = 0;
		fcheckbox219 = 0.0;
		for (int i=0; i<2; i++) fRec406[i] = 0;
		fcheckbox220 = 0.0;
		for (int i=0; i<2; i++) fRec407[i] = 0;
		fcheckbox221 = 0.0;
		for (int i=0; i<2; i++) fRec408[i] = 0;
		fcheckbox222 = 0.0;
		for (int i=0; i<2; i++) fRec409[i] = 0;
		fcheckbox223 = 0.0;
		for (int i=0; i<2; i++) fRec410[i] = 0;
		for (int i=0; i<2097152; i++) fVec82[i] = 0;
		fslider78 = 1.4e+03;
		for (int i=0; i<2; i++) fRec412[i] = 0;
		for (int i=0; i<2; i++) fRec411[i] = 0;
		for (int i=0; i<2; i++) fRec413[i] = 0;
		for (int i=0; i<262144; i++) fVec83[i] = 0;
		for (int i=0; i<2; i++) fRec414[i] = 0;
		for (int i=0; i<2; i++) fVec84[i] = 0;
		for (int i=0; i<2; i++) fRec415[i] = 0;
		for (int i=0; i<2; i++) fVec85[i] = 0;
		for (int i=0; i<2; i++) fRec416[i] = 0;
		for (int i=0; i<2; i++) fVec86[i] = 0;
		for (int i=0; i<2; i++) fRec417[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		fslider79 = 0.0;
		for (int i=0; i<2; i++) fRec419[i] = 0;
		for (int i=0; i<2; i++) fRec418[i] = 0;
		for (int i=0; i<2; i++) fVec87[i] = 0;
		fcheckbox224 = 0.0;
		for (int i=0; i<2; i++) fRec420[i] = 0;
		fslider80 = 1.0;
		for (int i=0; i<2; i++) fRec421[i] = 0;
		fcheckbox225 = 0.0;
		for (int i=0; i<2; i++) fRec422[i] = 0;
		fcheckbox226 = 0.0;
		for (int i=0; i<2; i++) fRec423[i] = 0;
		fcheckbox227 = 0.0;
		for (int i=0; i<2; i++) fRec424[i] = 0;
		fcheckbox228 = 0.0;
		for (int i=0; i<2; i++) fRec425[i] = 0;
		fcheckbox229 = 0.0;
		for (int i=0; i<2; i++) fRec426[i] = 0;
		fcheckbox230 = 0.0;
		for (int i=0; i<2; i++) fRec427[i] = 0;
		fcheckbox231 = 0.0;
		for (int i=0; i<2; i++) fRec428[i] = 0;
		fcheckbox232 = 0.0;
		for (int i=0; i<2; i++) fRec429[i] = 0;
		fcheckbox233 = 0.0;
		for (int i=0; i<2; i++) fRec430[i] = 0;
		fcheckbox234 = 0.0;
		for (int i=0; i<2; i++) fRec431[i] = 0;
		fcheckbox235 = 0.0;
		for (int i=0; i<2; i++) fRec432[i] = 0;
		fcheckbox236 = 0.0;
		for (int i=0; i<2; i++) fRec433[i] = 0;
		fcheckbox237 = 0.0;
		for (int i=0; i<2; i++) fRec434[i] = 0;
		fcheckbox238 = 0.0;
		for (int i=0; i<2; i++) fRec435[i] = 0;
		fcheckbox239 = 0.0;
		for (int i=0; i<2; i++) fRec436[i] = 0;
		for (int i=0; i<2097152; i++) fVec88[i] = 0;
		fslider81 = 1.5e+03;
		for (int i=0; i<2; i++) fRec438[i] = 0;
		for (int i=0; i<2; i++) fRec437[i] = 0;
		for (int i=0; i<2; i++) fRec439[i] = 0;
		for (int i=0; i<262144; i++) fVec89[i] = 0;
		for (int i=0; i<2; i++) fRec440[i] = 0;
		for (int i=0; i<2; i++) fVec90[i] = 0;
		for (int i=0; i<2; i++) fRec441[i] = 0;
		for (int i=0; i<2; i++) fVec91[i] = 0;
		for (int i=0; i<2; i++) fRec442[i] = 0;
		for (int i=0; i<2; i++) fVec92[i] = 0;
		for (int i=0; i<2; i++) fRec443[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		fslider82 = 0.0;
		for (int i=0; i<2; i++) fRec445[i] = 0;
		for (int i=0; i<2; i++) fRec444[i] = 0;
		for (int i=0; i<2; i++) fVec93[i] = 0;
		fcheckbox240 = 0.0;
		for (int i=0; i<2; i++) fRec446[i] = 0;
		fslider83 = 1.0;
		for (int i=0; i<2; i++) fRec447[i] = 0;
		fcheckbox241 = 0.0;
		for (int i=0; i<2; i++) fRec448[i] = 0;
		fcheckbox242 = 0.0;
		for (int i=0; i<2; i++) fRec449[i] = 0;
		fcheckbox243 = 0.0;
		for (int i=0; i<2; i++) fRec450[i] = 0;
		fcheckbox244 = 0.0;
		for (int i=0; i<2; i++) fRec451[i] = 0;
		fcheckbox245 = 0.0;
		for (int i=0; i<2; i++) fRec452[i] = 0;
		fcheckbox246 = 0.0;
		for (int i=0; i<2; i++) fRec453[i] = 0;
		fcheckbox247 = 0.0;
		for (int i=0; i<2; i++) fRec454[i] = 0;
		fcheckbox248 = 0.0;
		for (int i=0; i<2; i++) fRec455[i] = 0;
		fcheckbox249 = 0.0;
		for (int i=0; i<2; i++) fRec456[i] = 0;
		fcheckbox250 = 0.0;
		for (int i=0; i<2; i++) fRec457[i] = 0;
		fcheckbox251 = 0.0;
		for (int i=0; i<2; i++) fRec458[i] = 0;
		fcheckbox252 = 0.0;
		for (int i=0; i<2; i++) fRec459[i] = 0;
		fcheckbox253 = 0.0;
		for (int i=0; i<2; i++) fRec460[i] = 0;
		fcheckbox254 = 0.0;
		for (int i=0; i<2; i++) fRec461[i] = 0;
		fcheckbox255 = 0.0;
		for (int i=0; i<2; i++) fRec462[i] = 0;
		for (int i=0; i<2097152; i++) fVec94[i] = 0;
		fslider84 = 1.6e+03;
		for (int i=0; i<2; i++) fRec464[i] = 0;
		for (int i=0; i<2; i++) fRec463[i] = 0;
		for (int i=0; i<2; i++) fRec465[i] = 0;
		for (int i=0; i<262144; i++) fVec95[i] = 0;
		for (int i=0; i<2; i++) fRec466[i] = 0;
		for (int i=0; i<2; i++) fVec96[i] = 0;
		for (int i=0; i<2; i++) fRec467[i] = 0;
		for (int i=0; i<2; i++) fVec97[i] = 0;
		for (int i=0; i<2; i++) fRec468[i] = 0;
		for (int i=0; i<2; i++) fVec98[i] = 0;
		for (int i=0; i<2; i++) fRec469[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		fslider85 = 1.0;
		for (int i=0; i<2; i++) fRec470[i] = 0;
		fslider86 = 1.0;
		for (int i=0; i<2; i++) fRec471[i] = 0;
		fslider87 = 1.0;
		for (int i=0; i<2; i++) fRec472[i] = 0;
		fslider88 = 1.0;
		for (int i=0; i<2; i++) fRec473[i] = 0;
		fslider89 = 1.0;
		for (int i=0; i<2; i++) fRec474[i] = 0;
		fslider90 = 1.0;
		for (int i=0; i<2; i++) fRec475[i] = 0;
		fslider91 = 1.0;
		for (int i=0; i<2; i++) fRec476[i] = 0;
		fslider92 = 1.0;
		for (int i=0; i<2; i++) fRec477[i] = 0;
		fslider93 = 1.0;
		for (int i=0; i<2; i++) fRec478[i] = 0;
		fslider94 = 1.0;
		for (int i=0; i<2; i++) fRec479[i] = 0;
		fslider95 = 1.0;
		for (int i=0; i<2; i++) fRec480[i] = 0;
		fslider96 = 1.0;
		for (int i=0; i<2; i++) fRec481[i] = 0;
		fslider97 = 1.0;
		for (int i=0; i<2; i++) fRec482[i] = 0;
		fslider98 = 1.0;
		for (int i=0; i<2; i++) fRec483[i] = 0;
		fslider99 = 1.0;
		for (int i=0; i<2; i++) fRec484[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->openHorizontalBox("Global_Parameters");
		interface->declare(&fslider39, "7", "");
		interface->addHorizontalSlider("dStretch", &fslider39, 1.0, 0.01, 1e+01, 0.01);
		interface->declare(&fslider4, "7", "");
		interface->addHorizontalSlider("hStretch", &fslider4, 1.0, -1e+01, 1e+01, 0.01);
		interface->addHorizontalSlider("hWin", &fslider2, 64.0, 1.0, 127.0, 0.01);
		interface->addHorizontalSlider("smoothDuration", &fslider0, 2e+01, 1e+01, 5e+03, 1.0);
		interface->closeBox();
		interface->openHorizontalBox("Lines");
		interface->openVerticalBox("Del_Durations");
		interface->addHorizontalSlider("d 0", &fslider38, 1e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 1", &fslider42, 2e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 2", &fslider45, 3e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 3", &fslider48, 4e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 4", &fslider51, 5e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 5", &fslider54, 6e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 6", &fslider57, 7e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 7", &fslider60, 8e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 8", &fslider63, 9e+02, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d 9", &fslider66, 1e+03, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d10", &fslider69, 1.1e+03, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d11", &fslider72, 1.2e+03, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d12", &fslider75, 1.3e+03, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d13", &fslider78, 1.4e+03, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d14", &fslider81, 1.5e+03, 0.0, 4.3e+04, 1.0);
		interface->addHorizontalSlider("d15", &fslider84, 1.6e+03, 0.0, 4.3e+04, 1.0);
		interface->closeBox();
		interface->openVerticalBox("Del_Feedbacks");
		interface->addHorizontalSlider("fd 0", &fslider6, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 1", &fslider9, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 2", &fslider11, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 3", &fslider13, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 4", &fslider15, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 5", &fslider17, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 6", &fslider19, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 7", &fslider21, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 8", &fslider23, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd 9", &fslider25, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd10", &fslider27, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd11", &fslider29, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd12", &fslider31, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd13", &fslider33, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd14", &fslider35, 0.0, 0.0, 0.99, 0.01);
		interface->addHorizontalSlider("fd15", &fslider37, 0.0, 0.0, 0.99, 0.01);
		interface->closeBox();
		interface->openVerticalBox("EffeX_vs_Del");
		interface->addHorizontalSlider("xvd 0", &fslider5, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 1", &fslider8, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 2", &fslider10, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 3", &fslider12, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 4", &fslider14, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 5", &fslider16, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 6", &fslider18, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 7", &fslider20, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 8", &fslider22, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd 9", &fslider24, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd10", &fslider26, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd11", &fslider28, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd12", &fslider30, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd13", &fslider32, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd14", &fslider34, 1.0, 0.0, 1.0, 0.01);
		interface->addHorizontalSlider("xvd15", &fslider36, 1.0, 0.0, 1.0, 0.01);
		interface->closeBox();
		interface->openVerticalBox("Harmo_Transpositions");
		interface->addHorizontalSlider("tr 0", &fslider3, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 1", &fslider40, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 2", &fslider43, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 3", &fslider46, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 4", &fslider49, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 5", &fslider52, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 6", &fslider55, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 7", &fslider58, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 8", &fslider61, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr 9", &fslider64, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr10", &fslider67, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr11", &fslider70, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr12", &fslider73, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr13", &fslider76, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr14", &fslider79, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->addHorizontalSlider("tr15", &fslider82, 0.0, -2.4e+03, 2.4e+03, 1.0);
		interface->closeBox();
		interface->openVerticalBox("Line_input");
		interface->declare(&fslider7, "5", "");
		interface->addHorizontalSlider("inp 0", &fslider7, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider41, "5", "");
		interface->addHorizontalSlider("inp 1", &fslider41, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider44, "5", "");
		interface->addHorizontalSlider("inp 2", &fslider44, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider47, "5", "");
		interface->addHorizontalSlider("inp 3", &fslider47, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider50, "5", "");
		interface->addHorizontalSlider("inp 4", &fslider50, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider53, "5", "");
		interface->addHorizontalSlider("inp 5", &fslider53, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider56, "5", "");
		interface->addHorizontalSlider("inp 6", &fslider56, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider59, "5", "");
		interface->addHorizontalSlider("inp 7", &fslider59, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider62, "5", "");
		interface->addHorizontalSlider("inp 8", &fslider62, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider65, "5", "");
		interface->addHorizontalSlider("inp 9", &fslider65, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider68, "5", "");
		interface->addHorizontalSlider("inp10", &fslider68, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider71, "5", "");
		interface->addHorizontalSlider("inp11", &fslider71, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider74, "5", "");
		interface->addHorizontalSlider("inp12", &fslider74, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider77, "5", "");
		interface->addHorizontalSlider("inp13", &fslider77, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider80, "5", "");
		interface->addHorizontalSlider("inp14", &fslider80, 1.0, 0.0, 1.0, 0.01);
		interface->declare(&fslider83, "5", "");
		interface->addHorizontalSlider("inp15", &fslider83, 1.0, 0.0, 1.0, 0.01);
		interface->closeBox();
		interface->openVerticalBox("Line_output");
		interface->declare(&fslider1, "6", "");
		interface->addHorizontalSlider("out 0", &fslider1, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider85, "6", "");
		interface->addHorizontalSlider("out 1", &fslider85, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider86, "6", "");
		interface->addHorizontalSlider("out 2", &fslider86, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider87, "6", "");
		interface->addHorizontalSlider("out 3", &fslider87, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider88, "6", "");
		interface->addHorizontalSlider("out 4", &fslider88, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider89, "6", "");
		interface->addHorizontalSlider("out 5", &fslider89, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider90, "6", "");
		interface->addHorizontalSlider("out 6", &fslider90, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider91, "6", "");
		interface->addHorizontalSlider("out 7", &fslider91, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider92, "6", "");
		interface->addHorizontalSlider("out 8", &fslider92, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider93, "6", "");
		interface->addHorizontalSlider("out 9", &fslider93, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider94, "6", "");
		interface->addHorizontalSlider("out10", &fslider94, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider95, "6", "");
		interface->addHorizontalSlider("out11", &fslider95, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider96, "6", "");
		interface->addHorizontalSlider("out12", &fslider96, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider97, "6", "");
		interface->addHorizontalSlider("out13", &fslider97, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider98, "6", "");
		interface->addHorizontalSlider("out14", &fslider98, 1.0, 0.0, 4.0, 0.01);
		interface->declare(&fslider99, "6", "");
		interface->addHorizontalSlider("out15", &fslider99, 1.0, 0.0, 4.0, 0.01);
		interface->closeBox();
		interface->openHorizontalBox("Reinjection_Matrix");
		interface->openVerticalBox("Del 0-->");
		interface->addCheckButton("r  0", &fcheckbox0);
		interface->addCheckButton("r 16", &fcheckbox16);
		interface->addCheckButton("r 32", &fcheckbox32);
		interface->addCheckButton("r 48", &fcheckbox48);
		interface->addCheckButton("r 64", &fcheckbox64);
		interface->addCheckButton("r 80", &fcheckbox80);
		interface->addCheckButton("r 96", &fcheckbox96);
		interface->addCheckButton("r112", &fcheckbox112);
		interface->addCheckButton("r128", &fcheckbox128);
		interface->addCheckButton("r144", &fcheckbox144);
		interface->addCheckButton("r160", &fcheckbox160);
		interface->addCheckButton("r176", &fcheckbox176);
		interface->addCheckButton("r192", &fcheckbox192);
		interface->addCheckButton("r208", &fcheckbox208);
		interface->addCheckButton("r224", &fcheckbox224);
		interface->addCheckButton("r240", &fcheckbox240);
		interface->closeBox();
		interface->openVerticalBox("Del 1-->");
		interface->addCheckButton("r  1", &fcheckbox1);
		interface->addCheckButton("r 17", &fcheckbox17);
		interface->addCheckButton("r 33", &fcheckbox33);
		interface->addCheckButton("r 49", &fcheckbox49);
		interface->addCheckButton("r 65", &fcheckbox65);
		interface->addCheckButton("r 81", &fcheckbox81);
		interface->addCheckButton("r 97", &fcheckbox97);
		interface->addCheckButton("r113", &fcheckbox113);
		interface->addCheckButton("r129", &fcheckbox129);
		interface->addCheckButton("r145", &fcheckbox145);
		interface->addCheckButton("r161", &fcheckbox161);
		interface->addCheckButton("r177", &fcheckbox177);
		interface->addCheckButton("r193", &fcheckbox193);
		interface->addCheckButton("r209", &fcheckbox209);
		interface->addCheckButton("r225", &fcheckbox225);
		interface->addCheckButton("r241", &fcheckbox241);
		interface->closeBox();
		interface->openVerticalBox("Del 2-->");
		interface->addCheckButton("r  2", &fcheckbox2);
		interface->addCheckButton("r 18", &fcheckbox18);
		interface->addCheckButton("r 34", &fcheckbox34);
		interface->addCheckButton("r 50", &fcheckbox50);
		interface->addCheckButton("r 66", &fcheckbox66);
		interface->addCheckButton("r 82", &fcheckbox82);
		interface->addCheckButton("r 98", &fcheckbox98);
		interface->addCheckButton("r114", &fcheckbox114);
		interface->addCheckButton("r130", &fcheckbox130);
		interface->addCheckButton("r146", &fcheckbox146);
		interface->addCheckButton("r162", &fcheckbox162);
		interface->addCheckButton("r178", &fcheckbox178);
		interface->addCheckButton("r194", &fcheckbox194);
		interface->addCheckButton("r210", &fcheckbox210);
		interface->addCheckButton("r226", &fcheckbox226);
		interface->addCheckButton("r242", &fcheckbox242);
		interface->closeBox();
		interface->openVerticalBox("Del 3-->");
		interface->addCheckButton("r  3", &fcheckbox3);
		interface->addCheckButton("r 19", &fcheckbox19);
		interface->addCheckButton("r 35", &fcheckbox35);
		interface->addCheckButton("r 51", &fcheckbox51);
		interface->addCheckButton("r 67", &fcheckbox67);
		interface->addCheckButton("r 83", &fcheckbox83);
		interface->addCheckButton("r 99", &fcheckbox99);
		interface->addCheckButton("r115", &fcheckbox115);
		interface->addCheckButton("r131", &fcheckbox131);
		interface->addCheckButton("r147", &fcheckbox147);
		interface->addCheckButton("r163", &fcheckbox163);
		interface->addCheckButton("r179", &fcheckbox179);
		interface->addCheckButton("r195", &fcheckbox195);
		interface->addCheckButton("r211", &fcheckbox211);
		interface->addCheckButton("r227", &fcheckbox227);
		interface->addCheckButton("r243", &fcheckbox243);
		interface->closeBox();
		interface->openVerticalBox("Del 4-->");
		interface->addCheckButton("r  4", &fcheckbox4);
		interface->addCheckButton("r 20", &fcheckbox20);
		interface->addCheckButton("r 36", &fcheckbox36);
		interface->addCheckButton("r 52", &fcheckbox52);
		interface->addCheckButton("r 68", &fcheckbox68);
		interface->addCheckButton("r 84", &fcheckbox84);
		interface->addCheckButton("r100", &fcheckbox100);
		interface->addCheckButton("r116", &fcheckbox116);
		interface->addCheckButton("r132", &fcheckbox132);
		interface->addCheckButton("r148", &fcheckbox148);
		interface->addCheckButton("r164", &fcheckbox164);
		interface->addCheckButton("r180", &fcheckbox180);
		interface->addCheckButton("r196", &fcheckbox196);
		interface->addCheckButton("r212", &fcheckbox212);
		interface->addCheckButton("r228", &fcheckbox228);
		interface->addCheckButton("r244", &fcheckbox244);
		interface->closeBox();
		interface->openVerticalBox("Del 5-->");
		interface->addCheckButton("r  5", &fcheckbox5);
		interface->addCheckButton("r 21", &fcheckbox21);
		interface->addCheckButton("r 37", &fcheckbox37);
		interface->addCheckButton("r 53", &fcheckbox53);
		interface->addCheckButton("r 69", &fcheckbox69);
		interface->addCheckButton("r 85", &fcheckbox85);
		interface->addCheckButton("r101", &fcheckbox101);
		interface->addCheckButton("r117", &fcheckbox117);
		interface->addCheckButton("r133", &fcheckbox133);
		interface->addCheckButton("r149", &fcheckbox149);
		interface->addCheckButton("r165", &fcheckbox165);
		interface->addCheckButton("r181", &fcheckbox181);
		interface->addCheckButton("r197", &fcheckbox197);
		interface->addCheckButton("r213", &fcheckbox213);
		interface->addCheckButton("r229", &fcheckbox229);
		interface->addCheckButton("r245", &fcheckbox245);
		interface->closeBox();
		interface->openVerticalBox("Del 6-->");
		interface->addCheckButton("r  6", &fcheckbox6);
		interface->addCheckButton("r 22", &fcheckbox22);
		interface->addCheckButton("r 38", &fcheckbox38);
		interface->addCheckButton("r 54", &fcheckbox54);
		interface->addCheckButton("r 70", &fcheckbox70);
		interface->addCheckButton("r 86", &fcheckbox86);
		interface->addCheckButton("r102", &fcheckbox102);
		interface->addCheckButton("r118", &fcheckbox118);
		interface->addCheckButton("r134", &fcheckbox134);
		interface->addCheckButton("r150", &fcheckbox150);
		interface->addCheckButton("r166", &fcheckbox166);
		interface->addCheckButton("r182", &fcheckbox182);
		interface->addCheckButton("r198", &fcheckbox198);
		interface->addCheckButton("r214", &fcheckbox214);
		interface->addCheckButton("r230", &fcheckbox230);
		interface->addCheckButton("r246", &fcheckbox246);
		interface->closeBox();
		interface->openVerticalBox("Del 7-->");
		interface->addCheckButton("r  7", &fcheckbox7);
		interface->addCheckButton("r 23", &fcheckbox23);
		interface->addCheckButton("r 39", &fcheckbox39);
		interface->addCheckButton("r 55", &fcheckbox55);
		interface->addCheckButton("r 71", &fcheckbox71);
		interface->addCheckButton("r 87", &fcheckbox87);
		interface->addCheckButton("r103", &fcheckbox103);
		interface->addCheckButton("r119", &fcheckbox119);
		interface->addCheckButton("r135", &fcheckbox135);
		interface->addCheckButton("r151", &fcheckbox151);
		interface->addCheckButton("r167", &fcheckbox167);
		interface->addCheckButton("r183", &fcheckbox183);
		interface->addCheckButton("r199", &fcheckbox199);
		interface->addCheckButton("r215", &fcheckbox215);
		interface->addCheckButton("r231", &fcheckbox231);
		interface->addCheckButton("r247", &fcheckbox247);
		interface->closeBox();
		interface->openVerticalBox("Del 8-->");
		interface->addCheckButton("r  8", &fcheckbox8);
		interface->addCheckButton("r 24", &fcheckbox24);
		interface->addCheckButton("r 40", &fcheckbox40);
		interface->addCheckButton("r 56", &fcheckbox56);
		interface->addCheckButton("r 72", &fcheckbox72);
		interface->addCheckButton("r 88", &fcheckbox88);
		interface->addCheckButton("r104", &fcheckbox104);
		interface->addCheckButton("r120", &fcheckbox120);
		interface->addCheckButton("r136", &fcheckbox136);
		interface->addCheckButton("r152", &fcheckbox152);
		interface->addCheckButton("r168", &fcheckbox168);
		interface->addCheckButton("r184", &fcheckbox184);
		interface->addCheckButton("r200", &fcheckbox200);
		interface->addCheckButton("r216", &fcheckbox216);
		interface->addCheckButton("r232", &fcheckbox232);
		interface->addCheckButton("r248", &fcheckbox248);
		interface->closeBox();
		interface->openVerticalBox("Del 9-->");
		interface->addCheckButton("r  9", &fcheckbox9);
		interface->addCheckButton("r 25", &fcheckbox25);
		interface->addCheckButton("r 41", &fcheckbox41);
		interface->addCheckButton("r 57", &fcheckbox57);
		interface->addCheckButton("r 73", &fcheckbox73);
		interface->addCheckButton("r 89", &fcheckbox89);
		interface->addCheckButton("r105", &fcheckbox105);
		interface->addCheckButton("r121", &fcheckbox121);
		interface->addCheckButton("r137", &fcheckbox137);
		interface->addCheckButton("r153", &fcheckbox153);
		interface->addCheckButton("r169", &fcheckbox169);
		interface->addCheckButton("r185", &fcheckbox185);
		interface->addCheckButton("r201", &fcheckbox201);
		interface->addCheckButton("r217", &fcheckbox217);
		interface->addCheckButton("r233", &fcheckbox233);
		interface->addCheckButton("r249", &fcheckbox249);
		interface->closeBox();
		interface->openVerticalBox("Del10-->");
		interface->addCheckButton("r 10", &fcheckbox10);
		interface->addCheckButton("r 26", &fcheckbox26);
		interface->addCheckButton("r 42", &fcheckbox42);
		interface->addCheckButton("r 58", &fcheckbox58);
		interface->addCheckButton("r 74", &fcheckbox74);
		interface->addCheckButton("r 90", &fcheckbox90);
		interface->addCheckButton("r106", &fcheckbox106);
		interface->addCheckButton("r122", &fcheckbox122);
		interface->addCheckButton("r138", &fcheckbox138);
		interface->addCheckButton("r154", &fcheckbox154);
		interface->addCheckButton("r170", &fcheckbox170);
		interface->addCheckButton("r186", &fcheckbox186);
		interface->addCheckButton("r202", &fcheckbox202);
		interface->addCheckButton("r218", &fcheckbox218);
		interface->addCheckButton("r234", &fcheckbox234);
		interface->addCheckButton("r250", &fcheckbox250);
		interface->closeBox();
		interface->openVerticalBox("Del11-->");
		interface->addCheckButton("r 11", &fcheckbox11);
		interface->addCheckButton("r 27", &fcheckbox27);
		interface->addCheckButton("r 43", &fcheckbox43);
		interface->addCheckButton("r 59", &fcheckbox59);
		interface->addCheckButton("r 75", &fcheckbox75);
		interface->addCheckButton("r 91", &fcheckbox91);
		interface->addCheckButton("r107", &fcheckbox107);
		interface->addCheckButton("r123", &fcheckbox123);
		interface->addCheckButton("r139", &fcheckbox139);
		interface->addCheckButton("r155", &fcheckbox155);
		interface->addCheckButton("r171", &fcheckbox171);
		interface->addCheckButton("r187", &fcheckbox187);
		interface->addCheckButton("r203", &fcheckbox203);
		interface->addCheckButton("r219", &fcheckbox219);
		interface->addCheckButton("r235", &fcheckbox235);
		interface->addCheckButton("r251", &fcheckbox251);
		interface->closeBox();
		interface->openVerticalBox("Del12-->");
		interface->addCheckButton("r 12", &fcheckbox12);
		interface->addCheckButton("r 28", &fcheckbox28);
		interface->addCheckButton("r 44", &fcheckbox44);
		interface->addCheckButton("r 60", &fcheckbox60);
		interface->addCheckButton("r 76", &fcheckbox76);
		interface->addCheckButton("r 92", &fcheckbox92);
		interface->addCheckButton("r108", &fcheckbox108);
		interface->addCheckButton("r124", &fcheckbox124);
		interface->addCheckButton("r140", &fcheckbox140);
		interface->addCheckButton("r156", &fcheckbox156);
		interface->addCheckButton("r172", &fcheckbox172);
		interface->addCheckButton("r188", &fcheckbox188);
		interface->addCheckButton("r204", &fcheckbox204);
		interface->addCheckButton("r220", &fcheckbox220);
		interface->addCheckButton("r236", &fcheckbox236);
		interface->addCheckButton("r252", &fcheckbox252);
		interface->closeBox();
		interface->openVerticalBox("Del13-->");
		interface->addCheckButton("r 13", &fcheckbox13);
		interface->addCheckButton("r 29", &fcheckbox29);
		interface->addCheckButton("r 45", &fcheckbox45);
		interface->addCheckButton("r 61", &fcheckbox61);
		interface->addCheckButton("r 77", &fcheckbox77);
		interface->addCheckButton("r 93", &fcheckbox93);
		interface->addCheckButton("r109", &fcheckbox109);
		interface->addCheckButton("r125", &fcheckbox125);
		interface->addCheckButton("r141", &fcheckbox141);
		interface->addCheckButton("r157", &fcheckbox157);
		interface->addCheckButton("r173", &fcheckbox173);
		interface->addCheckButton("r189", &fcheckbox189);
		interface->addCheckButton("r205", &fcheckbox205);
		interface->addCheckButton("r221", &fcheckbox221);
		interface->addCheckButton("r237", &fcheckbox237);
		interface->addCheckButton("r253", &fcheckbox253);
		interface->closeBox();
		interface->openVerticalBox("Del14-->");
		interface->addCheckButton("r 14", &fcheckbox14);
		interface->addCheckButton("r 30", &fcheckbox30);
		interface->addCheckButton("r 46", &fcheckbox46);
		interface->addCheckButton("r 62", &fcheckbox62);
		interface->addCheckButton("r 78", &fcheckbox78);
		interface->addCheckButton("r 94", &fcheckbox94);
		interface->addCheckButton("r110", &fcheckbox110);
		interface->addCheckButton("r126", &fcheckbox126);
		interface->addCheckButton("r142", &fcheckbox142);
		interface->addCheckButton("r158", &fcheckbox158);
		interface->addCheckButton("r174", &fcheckbox174);
		interface->addCheckButton("r190", &fcheckbox190);
		interface->addCheckButton("r206", &fcheckbox206);
		interface->addCheckButton("r222", &fcheckbox222);
		interface->addCheckButton("r238", &fcheckbox238);
		interface->addCheckButton("r254", &fcheckbox254);
		interface->closeBox();
		interface->openVerticalBox("Del15-->");
		interface->addCheckButton("r 15", &fcheckbox15);
		interface->addCheckButton("r 31", &fcheckbox31);
		interface->addCheckButton("r 47", &fcheckbox47);
		interface->addCheckButton("r 63", &fcheckbox63);
		interface->addCheckButton("r 79", &fcheckbox79);
		interface->addCheckButton("r 95", &fcheckbox95);
		interface->addCheckButton("r111", &fcheckbox111);
		interface->addCheckButton("r127", &fcheckbox127);
		interface->addCheckButton("r143", &fcheckbox143);
		interface->addCheckButton("r159", &fcheckbox159);
		interface->addCheckButton("r175", &fcheckbox175);
		interface->addCheckButton("r191", &fcheckbox191);
		interface->addCheckButton("r207", &fcheckbox207);
		interface->addCheckButton("r223", &fcheckbox223);
		interface->addCheckButton("r239", &fcheckbox239);
		interface->addCheckButton("r255", &fcheckbox255);
		interface->closeBox();
		interface->closeBox();
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		double 	fSlow0 = exp((0 - (fConst1 / double(fslider0))));
		double 	fSlow1 = (1.0 - fSlow0);
		double 	fSlow2 = (double(fslider1) * fSlow1);
		double 	fSlow3 = double(fslider2);
		double 	fSlow4 = ((int((fSlow3 < 127)))?fSlow3:127);
		double 	fSlow5 = ((int((fSlow4 < 1)))?0:(4096 * pow(1.07177,(fSlow4 - 127))));
		double 	fSlow6 = double(fslider4);
		double 	fSlow7 = ((fSlow6 * double(fslider3)) * fSlow1);
		double 	fSlow8 = (double(fslider5) * fSlow1);
		double 	fSlow9 = (double(fcheckbox0) * fSlow1);
		double 	fSlow10 = (double(fslider6) * fSlow1);
		double 	fSlow11 = (double(fslider7) * fSlow1);
		double 	fSlow12 = (double(fslider8) * fSlow1);
		double 	fSlow13 = (double(fcheckbox1) * fSlow1);
		double 	fSlow14 = (double(fslider9) * fSlow1);
		double 	fSlow15 = (double(fslider10) * fSlow1);
		double 	fSlow16 = (double(fcheckbox2) * fSlow1);
		double 	fSlow17 = (double(fslider11) * fSlow1);
		double 	fSlow18 = (double(fslider12) * fSlow1);
		double 	fSlow19 = (double(fcheckbox3) * fSlow1);
		double 	fSlow20 = (double(fslider13) * fSlow1);
		double 	fSlow21 = (double(fslider14) * fSlow1);
		double 	fSlow22 = (double(fcheckbox4) * fSlow1);
		double 	fSlow23 = (double(fslider15) * fSlow1);
		double 	fSlow24 = (double(fslider16) * fSlow1);
		double 	fSlow25 = (double(fcheckbox5) * fSlow1);
		double 	fSlow26 = (double(fslider17) * fSlow1);
		double 	fSlow27 = (double(fslider18) * fSlow1);
		double 	fSlow28 = (double(fcheckbox6) * fSlow1);
		double 	fSlow29 = (double(fslider19) * fSlow1);
		double 	fSlow30 = (double(fslider20) * fSlow1);
		double 	fSlow31 = (double(fcheckbox7) * fSlow1);
		double 	fSlow32 = (double(fslider21) * fSlow1);
		double 	fSlow33 = (double(fslider22) * fSlow1);
		double 	fSlow34 = (double(fcheckbox8) * fSlow1);
		double 	fSlow35 = (double(fslider23) * fSlow1);
		double 	fSlow36 = (double(fslider24) * fSlow1);
		double 	fSlow37 = (double(fcheckbox9) * fSlow1);
		double 	fSlow38 = (double(fslider25) * fSlow1);
		double 	fSlow39 = (double(fslider26) * fSlow1);
		double 	fSlow40 = (double(fcheckbox10) * fSlow1);
		double 	fSlow41 = (double(fslider27) * fSlow1);
		double 	fSlow42 = (double(fslider28) * fSlow1);
		double 	fSlow43 = (double(fcheckbox11) * fSlow1);
		double 	fSlow44 = (double(fslider29) * fSlow1);
		double 	fSlow45 = (double(fslider30) * fSlow1);
		double 	fSlow46 = (double(fcheckbox12) * fSlow1);
		double 	fSlow47 = (double(fslider31) * fSlow1);
		double 	fSlow48 = (double(fslider32) * fSlow1);
		double 	fSlow49 = (double(fcheckbox13) * fSlow1);
		double 	fSlow50 = (double(fslider33) * fSlow1);
		double 	fSlow51 = (double(fslider34) * fSlow1);
		double 	fSlow52 = (double(fcheckbox14) * fSlow1);
		double 	fSlow53 = (double(fslider35) * fSlow1);
		double 	fSlow54 = (double(fslider36) * fSlow1);
		double 	fSlow55 = (double(fcheckbox15) * fSlow1);
		double 	fSlow56 = (double(fslider37) * fSlow1);
		double 	fSlow57 = double(fslider39);
		double 	fSlow58 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider38)))));
		double 	fSlow59 = ((fSlow6 * double(fslider40)) * fSlow1);
		double 	fSlow60 = (double(fcheckbox16) * fSlow1);
		double 	fSlow61 = (double(fslider41) * fSlow1);
		double 	fSlow62 = (double(fcheckbox17) * fSlow1);
		double 	fSlow63 = (double(fcheckbox18) * fSlow1);
		double 	fSlow64 = (double(fcheckbox19) * fSlow1);
		double 	fSlow65 = (double(fcheckbox20) * fSlow1);
		double 	fSlow66 = (double(fcheckbox21) * fSlow1);
		double 	fSlow67 = (double(fcheckbox22) * fSlow1);
		double 	fSlow68 = (double(fcheckbox23) * fSlow1);
		double 	fSlow69 = (double(fcheckbox24) * fSlow1);
		double 	fSlow70 = (double(fcheckbox25) * fSlow1);
		double 	fSlow71 = (double(fcheckbox26) * fSlow1);
		double 	fSlow72 = (double(fcheckbox27) * fSlow1);
		double 	fSlow73 = (double(fcheckbox28) * fSlow1);
		double 	fSlow74 = (double(fcheckbox29) * fSlow1);
		double 	fSlow75 = (double(fcheckbox30) * fSlow1);
		double 	fSlow76 = (double(fcheckbox31) * fSlow1);
		double 	fSlow77 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider42)))));
		double 	fSlow78 = ((fSlow6 * double(fslider43)) * fSlow1);
		double 	fSlow79 = (double(fcheckbox32) * fSlow1);
		double 	fSlow80 = (double(fslider44) * fSlow1);
		double 	fSlow81 = (double(fcheckbox33) * fSlow1);
		double 	fSlow82 = (double(fcheckbox34) * fSlow1);
		double 	fSlow83 = (double(fcheckbox35) * fSlow1);
		double 	fSlow84 = (double(fcheckbox36) * fSlow1);
		double 	fSlow85 = (double(fcheckbox37) * fSlow1);
		double 	fSlow86 = (double(fcheckbox38) * fSlow1);
		double 	fSlow87 = (double(fcheckbox39) * fSlow1);
		double 	fSlow88 = (double(fcheckbox40) * fSlow1);
		double 	fSlow89 = (double(fcheckbox41) * fSlow1);
		double 	fSlow90 = (double(fcheckbox42) * fSlow1);
		double 	fSlow91 = (double(fcheckbox43) * fSlow1);
		double 	fSlow92 = (double(fcheckbox44) * fSlow1);
		double 	fSlow93 = (double(fcheckbox45) * fSlow1);
		double 	fSlow94 = (double(fcheckbox46) * fSlow1);
		double 	fSlow95 = (double(fcheckbox47) * fSlow1);
		double 	fSlow96 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider45)))));
		double 	fSlow97 = ((fSlow6 * double(fslider46)) * fSlow1);
		double 	fSlow98 = (double(fcheckbox48) * fSlow1);
		double 	fSlow99 = (double(fslider47) * fSlow1);
		double 	fSlow100 = (double(fcheckbox49) * fSlow1);
		double 	fSlow101 = (double(fcheckbox50) * fSlow1);
		double 	fSlow102 = (double(fcheckbox51) * fSlow1);
		double 	fSlow103 = (double(fcheckbox52) * fSlow1);
		double 	fSlow104 = (double(fcheckbox53) * fSlow1);
		double 	fSlow105 = (double(fcheckbox54) * fSlow1);
		double 	fSlow106 = (double(fcheckbox55) * fSlow1);
		double 	fSlow107 = (double(fcheckbox56) * fSlow1);
		double 	fSlow108 = (double(fcheckbox57) * fSlow1);
		double 	fSlow109 = (double(fcheckbox58) * fSlow1);
		double 	fSlow110 = (double(fcheckbox59) * fSlow1);
		double 	fSlow111 = (double(fcheckbox60) * fSlow1);
		double 	fSlow112 = (double(fcheckbox61) * fSlow1);
		double 	fSlow113 = (double(fcheckbox62) * fSlow1);
		double 	fSlow114 = (double(fcheckbox63) * fSlow1);
		double 	fSlow115 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider48)))));
		double 	fSlow116 = ((fSlow6 * double(fslider49)) * fSlow1);
		double 	fSlow117 = (double(fcheckbox64) * fSlow1);
		double 	fSlow118 = (double(fslider50) * fSlow1);
		double 	fSlow119 = (double(fcheckbox65) * fSlow1);
		double 	fSlow120 = (double(fcheckbox66) * fSlow1);
		double 	fSlow121 = (double(fcheckbox67) * fSlow1);
		double 	fSlow122 = (double(fcheckbox68) * fSlow1);
		double 	fSlow123 = (double(fcheckbox69) * fSlow1);
		double 	fSlow124 = (double(fcheckbox70) * fSlow1);
		double 	fSlow125 = (double(fcheckbox71) * fSlow1);
		double 	fSlow126 = (double(fcheckbox72) * fSlow1);
		double 	fSlow127 = (double(fcheckbox73) * fSlow1);
		double 	fSlow128 = (double(fcheckbox74) * fSlow1);
		double 	fSlow129 = (double(fcheckbox75) * fSlow1);
		double 	fSlow130 = (double(fcheckbox76) * fSlow1);
		double 	fSlow131 = (double(fcheckbox77) * fSlow1);
		double 	fSlow132 = (double(fcheckbox78) * fSlow1);
		double 	fSlow133 = (double(fcheckbox79) * fSlow1);
		double 	fSlow134 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider51)))));
		double 	fSlow135 = ((fSlow6 * double(fslider52)) * fSlow1);
		double 	fSlow136 = (double(fcheckbox80) * fSlow1);
		double 	fSlow137 = (double(fslider53) * fSlow1);
		double 	fSlow138 = (double(fcheckbox81) * fSlow1);
		double 	fSlow139 = (double(fcheckbox82) * fSlow1);
		double 	fSlow140 = (double(fcheckbox83) * fSlow1);
		double 	fSlow141 = (double(fcheckbox84) * fSlow1);
		double 	fSlow142 = (double(fcheckbox85) * fSlow1);
		double 	fSlow143 = (double(fcheckbox86) * fSlow1);
		double 	fSlow144 = (double(fcheckbox87) * fSlow1);
		double 	fSlow145 = (double(fcheckbox88) * fSlow1);
		double 	fSlow146 = (double(fcheckbox89) * fSlow1);
		double 	fSlow147 = (double(fcheckbox90) * fSlow1);
		double 	fSlow148 = (double(fcheckbox91) * fSlow1);
		double 	fSlow149 = (double(fcheckbox92) * fSlow1);
		double 	fSlow150 = (double(fcheckbox93) * fSlow1);
		double 	fSlow151 = (double(fcheckbox94) * fSlow1);
		double 	fSlow152 = (double(fcheckbox95) * fSlow1);
		double 	fSlow153 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider54)))));
		double 	fSlow154 = ((fSlow6 * double(fslider55)) * fSlow1);
		double 	fSlow155 = (double(fcheckbox96) * fSlow1);
		double 	fSlow156 = (double(fslider56) * fSlow1);
		double 	fSlow157 = (double(fcheckbox97) * fSlow1);
		double 	fSlow158 = (double(fcheckbox98) * fSlow1);
		double 	fSlow159 = (double(fcheckbox99) * fSlow1);
		double 	fSlow160 = (double(fcheckbox100) * fSlow1);
		double 	fSlow161 = (double(fcheckbox101) * fSlow1);
		double 	fSlow162 = (double(fcheckbox102) * fSlow1);
		double 	fSlow163 = (double(fcheckbox103) * fSlow1);
		double 	fSlow164 = (double(fcheckbox104) * fSlow1);
		double 	fSlow165 = (double(fcheckbox105) * fSlow1);
		double 	fSlow166 = (double(fcheckbox106) * fSlow1);
		double 	fSlow167 = (double(fcheckbox107) * fSlow1);
		double 	fSlow168 = (double(fcheckbox108) * fSlow1);
		double 	fSlow169 = (double(fcheckbox109) * fSlow1);
		double 	fSlow170 = (double(fcheckbox110) * fSlow1);
		double 	fSlow171 = (double(fcheckbox111) * fSlow1);
		double 	fSlow172 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider57)))));
		double 	fSlow173 = ((fSlow6 * double(fslider58)) * fSlow1);
		double 	fSlow174 = (double(fcheckbox112) * fSlow1);
		double 	fSlow175 = (double(fslider59) * fSlow1);
		double 	fSlow176 = (double(fcheckbox113) * fSlow1);
		double 	fSlow177 = (double(fcheckbox114) * fSlow1);
		double 	fSlow178 = (double(fcheckbox115) * fSlow1);
		double 	fSlow179 = (double(fcheckbox116) * fSlow1);
		double 	fSlow180 = (double(fcheckbox117) * fSlow1);
		double 	fSlow181 = (double(fcheckbox118) * fSlow1);
		double 	fSlow182 = (double(fcheckbox119) * fSlow1);
		double 	fSlow183 = (double(fcheckbox120) * fSlow1);
		double 	fSlow184 = (double(fcheckbox121) * fSlow1);
		double 	fSlow185 = (double(fcheckbox122) * fSlow1);
		double 	fSlow186 = (double(fcheckbox123) * fSlow1);
		double 	fSlow187 = (double(fcheckbox124) * fSlow1);
		double 	fSlow188 = (double(fcheckbox125) * fSlow1);
		double 	fSlow189 = (double(fcheckbox126) * fSlow1);
		double 	fSlow190 = (double(fcheckbox127) * fSlow1);
		double 	fSlow191 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider60)))));
		double 	fSlow192 = ((fSlow6 * double(fslider61)) * fSlow1);
		double 	fSlow193 = (double(fcheckbox128) * fSlow1);
		double 	fSlow194 = (double(fslider62) * fSlow1);
		double 	fSlow195 = (double(fcheckbox129) * fSlow1);
		double 	fSlow196 = (double(fcheckbox130) * fSlow1);
		double 	fSlow197 = (double(fcheckbox131) * fSlow1);
		double 	fSlow198 = (double(fcheckbox132) * fSlow1);
		double 	fSlow199 = (double(fcheckbox133) * fSlow1);
		double 	fSlow200 = (double(fcheckbox134) * fSlow1);
		double 	fSlow201 = (double(fcheckbox135) * fSlow1);
		double 	fSlow202 = (double(fcheckbox136) * fSlow1);
		double 	fSlow203 = (double(fcheckbox137) * fSlow1);
		double 	fSlow204 = (double(fcheckbox138) * fSlow1);
		double 	fSlow205 = (double(fcheckbox139) * fSlow1);
		double 	fSlow206 = (double(fcheckbox140) * fSlow1);
		double 	fSlow207 = (double(fcheckbox141) * fSlow1);
		double 	fSlow208 = (double(fcheckbox142) * fSlow1);
		double 	fSlow209 = (double(fcheckbox143) * fSlow1);
		double 	fSlow210 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider63)))));
		double 	fSlow211 = ((fSlow6 * double(fslider64)) * fSlow1);
		double 	fSlow212 = (double(fcheckbox144) * fSlow1);
		double 	fSlow213 = (double(fslider65) * fSlow1);
		double 	fSlow214 = (double(fcheckbox145) * fSlow1);
		double 	fSlow215 = (double(fcheckbox146) * fSlow1);
		double 	fSlow216 = (double(fcheckbox147) * fSlow1);
		double 	fSlow217 = (double(fcheckbox148) * fSlow1);
		double 	fSlow218 = (double(fcheckbox149) * fSlow1);
		double 	fSlow219 = (double(fcheckbox150) * fSlow1);
		double 	fSlow220 = (double(fcheckbox151) * fSlow1);
		double 	fSlow221 = (double(fcheckbox152) * fSlow1);
		double 	fSlow222 = (double(fcheckbox153) * fSlow1);
		double 	fSlow223 = (double(fcheckbox154) * fSlow1);
		double 	fSlow224 = (double(fcheckbox155) * fSlow1);
		double 	fSlow225 = (double(fcheckbox156) * fSlow1);
		double 	fSlow226 = (double(fcheckbox157) * fSlow1);
		double 	fSlow227 = (double(fcheckbox158) * fSlow1);
		double 	fSlow228 = (double(fcheckbox159) * fSlow1);
		double 	fSlow229 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider66)))));
		double 	fSlow230 = ((fSlow6 * double(fslider67)) * fSlow1);
		double 	fSlow231 = (double(fcheckbox160) * fSlow1);
		double 	fSlow232 = (double(fslider68) * fSlow1);
		double 	fSlow233 = (double(fcheckbox161) * fSlow1);
		double 	fSlow234 = (double(fcheckbox162) * fSlow1);
		double 	fSlow235 = (double(fcheckbox163) * fSlow1);
		double 	fSlow236 = (double(fcheckbox164) * fSlow1);
		double 	fSlow237 = (double(fcheckbox165) * fSlow1);
		double 	fSlow238 = (double(fcheckbox166) * fSlow1);
		double 	fSlow239 = (double(fcheckbox167) * fSlow1);
		double 	fSlow240 = (double(fcheckbox168) * fSlow1);
		double 	fSlow241 = (double(fcheckbox169) * fSlow1);
		double 	fSlow242 = (double(fcheckbox170) * fSlow1);
		double 	fSlow243 = (double(fcheckbox171) * fSlow1);
		double 	fSlow244 = (double(fcheckbox172) * fSlow1);
		double 	fSlow245 = (double(fcheckbox173) * fSlow1);
		double 	fSlow246 = (double(fcheckbox174) * fSlow1);
		double 	fSlow247 = (double(fcheckbox175) * fSlow1);
		double 	fSlow248 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider69)))));
		double 	fSlow249 = ((fSlow6 * double(fslider70)) * fSlow1);
		double 	fSlow250 = (double(fcheckbox176) * fSlow1);
		double 	fSlow251 = (double(fslider71) * fSlow1);
		double 	fSlow252 = (double(fcheckbox177) * fSlow1);
		double 	fSlow253 = (double(fcheckbox178) * fSlow1);
		double 	fSlow254 = (double(fcheckbox179) * fSlow1);
		double 	fSlow255 = (double(fcheckbox180) * fSlow1);
		double 	fSlow256 = (double(fcheckbox181) * fSlow1);
		double 	fSlow257 = (double(fcheckbox182) * fSlow1);
		double 	fSlow258 = (double(fcheckbox183) * fSlow1);
		double 	fSlow259 = (double(fcheckbox184) * fSlow1);
		double 	fSlow260 = (double(fcheckbox185) * fSlow1);
		double 	fSlow261 = (double(fcheckbox186) * fSlow1);
		double 	fSlow262 = (double(fcheckbox187) * fSlow1);
		double 	fSlow263 = (double(fcheckbox188) * fSlow1);
		double 	fSlow264 = (double(fcheckbox189) * fSlow1);
		double 	fSlow265 = (double(fcheckbox190) * fSlow1);
		double 	fSlow266 = (double(fcheckbox191) * fSlow1);
		double 	fSlow267 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider72)))));
		double 	fSlow268 = ((fSlow6 * double(fslider73)) * fSlow1);
		double 	fSlow269 = (double(fcheckbox192) * fSlow1);
		double 	fSlow270 = (double(fslider74) * fSlow1);
		double 	fSlow271 = (double(fcheckbox193) * fSlow1);
		double 	fSlow272 = (double(fcheckbox194) * fSlow1);
		double 	fSlow273 = (double(fcheckbox195) * fSlow1);
		double 	fSlow274 = (double(fcheckbox196) * fSlow1);
		double 	fSlow275 = (double(fcheckbox197) * fSlow1);
		double 	fSlow276 = (double(fcheckbox198) * fSlow1);
		double 	fSlow277 = (double(fcheckbox199) * fSlow1);
		double 	fSlow278 = (double(fcheckbox200) * fSlow1);
		double 	fSlow279 = (double(fcheckbox201) * fSlow1);
		double 	fSlow280 = (double(fcheckbox202) * fSlow1);
		double 	fSlow281 = (double(fcheckbox203) * fSlow1);
		double 	fSlow282 = (double(fcheckbox204) * fSlow1);
		double 	fSlow283 = (double(fcheckbox205) * fSlow1);
		double 	fSlow284 = (double(fcheckbox206) * fSlow1);
		double 	fSlow285 = (double(fcheckbox207) * fSlow1);
		double 	fSlow286 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider75)))));
		double 	fSlow287 = ((fSlow6 * double(fslider76)) * fSlow1);
		double 	fSlow288 = (double(fcheckbox208) * fSlow1);
		double 	fSlow289 = (double(fslider77) * fSlow1);
		double 	fSlow290 = (double(fcheckbox209) * fSlow1);
		double 	fSlow291 = (double(fcheckbox210) * fSlow1);
		double 	fSlow292 = (double(fcheckbox211) * fSlow1);
		double 	fSlow293 = (double(fcheckbox212) * fSlow1);
		double 	fSlow294 = (double(fcheckbox213) * fSlow1);
		double 	fSlow295 = (double(fcheckbox214) * fSlow1);
		double 	fSlow296 = (double(fcheckbox215) * fSlow1);
		double 	fSlow297 = (double(fcheckbox216) * fSlow1);
		double 	fSlow298 = (double(fcheckbox217) * fSlow1);
		double 	fSlow299 = (double(fcheckbox218) * fSlow1);
		double 	fSlow300 = (double(fcheckbox219) * fSlow1);
		double 	fSlow301 = (double(fcheckbox220) * fSlow1);
		double 	fSlow302 = (double(fcheckbox221) * fSlow1);
		double 	fSlow303 = (double(fcheckbox222) * fSlow1);
		double 	fSlow304 = (double(fcheckbox223) * fSlow1);
		double 	fSlow305 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider78)))));
		double 	fSlow306 = ((fSlow6 * double(fslider79)) * fSlow1);
		double 	fSlow307 = (double(fcheckbox224) * fSlow1);
		double 	fSlow308 = (double(fslider80) * fSlow1);
		double 	fSlow309 = (double(fcheckbox225) * fSlow1);
		double 	fSlow310 = (double(fcheckbox226) * fSlow1);
		double 	fSlow311 = (double(fcheckbox227) * fSlow1);
		double 	fSlow312 = (double(fcheckbox228) * fSlow1);
		double 	fSlow313 = (double(fcheckbox229) * fSlow1);
		double 	fSlow314 = (double(fcheckbox230) * fSlow1);
		double 	fSlow315 = (double(fcheckbox231) * fSlow1);
		double 	fSlow316 = (double(fcheckbox232) * fSlow1);
		double 	fSlow317 = (double(fcheckbox233) * fSlow1);
		double 	fSlow318 = (double(fcheckbox234) * fSlow1);
		double 	fSlow319 = (double(fcheckbox235) * fSlow1);
		double 	fSlow320 = (double(fcheckbox236) * fSlow1);
		double 	fSlow321 = (double(fcheckbox237) * fSlow1);
		double 	fSlow322 = (double(fcheckbox238) * fSlow1);
		double 	fSlow323 = (double(fcheckbox239) * fSlow1);
		double 	fSlow324 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider81)))));
		double 	fSlow325 = ((fSlow6 * double(fslider82)) * fSlow1);
		double 	fSlow326 = (double(fcheckbox240) * fSlow1);
		double 	fSlow327 = (double(fslider83) * fSlow1);
		double 	fSlow328 = (double(fcheckbox241) * fSlow1);
		double 	fSlow329 = (double(fcheckbox242) * fSlow1);
		double 	fSlow330 = (double(fcheckbox243) * fSlow1);
		double 	fSlow331 = (double(fcheckbox244) * fSlow1);
		double 	fSlow332 = (double(fcheckbox245) * fSlow1);
		double 	fSlow333 = (double(fcheckbox246) * fSlow1);
		double 	fSlow334 = (double(fcheckbox247) * fSlow1);
		double 	fSlow335 = (double(fcheckbox248) * fSlow1);
		double 	fSlow336 = (double(fcheckbox249) * fSlow1);
		double 	fSlow337 = (double(fcheckbox250) * fSlow1);
		double 	fSlow338 = (double(fcheckbox251) * fSlow1);
		double 	fSlow339 = (double(fcheckbox252) * fSlow1);
		double 	fSlow340 = (double(fcheckbox253) * fSlow1);
		double 	fSlow341 = (double(fcheckbox254) * fSlow1);
		double 	fSlow342 = (double(fcheckbox255) * fSlow1);
		double 	fSlow343 = (fSlow1 * int((fConst6 * (fSlow57 * double(fslider84)))));
		double 	fSlow344 = (double(fslider85) * fSlow1);
		double 	fSlow345 = (double(fslider86) * fSlow1);
		double 	fSlow346 = (double(fslider87) * fSlow1);
		double 	fSlow347 = (double(fslider88) * fSlow1);
		double 	fSlow348 = (double(fslider89) * fSlow1);
		double 	fSlow349 = (double(fslider90) * fSlow1);
		double 	fSlow350 = (double(fslider91) * fSlow1);
		double 	fSlow351 = (double(fslider92) * fSlow1);
		double 	fSlow352 = (double(fslider93) * fSlow1);
		double 	fSlow353 = (double(fslider94) * fSlow1);
		double 	fSlow354 = (double(fslider95) * fSlow1);
		double 	fSlow355 = (double(fslider96) * fSlow1);
		double 	fSlow356 = (double(fslider97) * fSlow1);
		double 	fSlow357 = (double(fslider98) * fSlow1);
		double 	fSlow358 = (double(fslider99) * fSlow1);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* input6 = input[6];
		FAUSTFLOAT* input7 = input[7];
		FAUSTFLOAT* input8 = input[8];
		FAUSTFLOAT* input9 = input[9];
		FAUSTFLOAT* input10 = input[10];
		FAUSTFLOAT* input11 = input[11];
		FAUSTFLOAT* input12 = input[12];
		FAUSTFLOAT* input13 = input[13];
		FAUSTFLOAT* input14 = input[14];
		FAUSTFLOAT* input15 = input[15];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		FAUSTFLOAT* output8 = output[8];
		FAUSTFLOAT* output9 = output[9];
		FAUSTFLOAT* output10 = output[10];
		FAUSTFLOAT* output11 = output[11];
		FAUSTFLOAT* output12 = output[12];
		FAUSTFLOAT* output13 = output[13];
		FAUSTFLOAT* output14 = output[14];
		FAUSTFLOAT* output15 = output[15];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((fSlow0 * fRec0[1]) + fSlow2);
			fVec0[0] = fSlow5;
			double fTemp0 = ((int((fSlow5 != fVec0[1])))?fConst2:(fRec20[1] - 1));
			fRec20[0] = fTemp0;
			fRec21[0] = ((int((fTemp0 <= 0)))?fSlow5:(fRec21[1] + ((fSlow5 - fRec21[1]) / fTemp0)));
			fRec19[0] = ((fSlow0 * fRec19[1]) + (fSlow1 * fRec21[0]));
			double fTemp1 = double(fRec19[0]);
			fRec22[0] = ((fSlow0 * fRec22[1]) + fSlow7);
			double fTemp2 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec22[0])) - 69))) - 261.625977))) / fTemp1);
			fRec18[0] = fmod((fRec18[1] + (fConst4 * double(fTemp2))),1.0);
			double fTemp3 = ((int((fTemp2 > 0)))?fRec18[0]:(1.0 + fRec18[0]));
			double fTemp4 = (0.5 + fTemp3);
			double fTemp5 = (fTemp4 - floor(fTemp4));
			fVec1[0] = fTemp5;
			double fTemp6 = (32768.0 * fVec1[0]);
			int iTemp7 = int(fTemp6);
			double fTemp8 = ftbl0[iTemp7];
			fRec23[0] = ((fSlow0 * fRec23[1]) + fSlow8);
			double fTemp9 = (1 - (0.75 * fRec23[0]));
			fRec24[0] = ((fSlow0 * fRec24[1]) + fSlow9);
			fRec25[0] = ((fSlow0 * fRec25[1]) + fSlow10);
			fRec26[0] = ((fSlow0 * fRec26[1]) + fSlow11);
			fRec27[0] = ((fSlow0 * fRec27[1]) + fSlow12);
			double fTemp10 = (1 - (0.75 * fRec27[0]));
			fRec28[0] = ((fSlow0 * fRec28[1]) + fSlow13);
			fRec29[0] = ((fSlow0 * fRec29[1]) + fSlow14);
			fRec30[0] = ((fSlow0 * fRec30[1]) + fSlow15);
			double fTemp11 = (1 - (0.75 * fRec30[0]));
			fRec31[0] = ((fSlow0 * fRec31[1]) + fSlow16);
			fRec32[0] = ((fSlow0 * fRec32[1]) + fSlow17);
			fRec33[0] = ((fSlow0 * fRec33[1]) + fSlow18);
			double fTemp12 = (1 - (0.75 * fRec33[0]));
			fRec34[0] = ((fSlow0 * fRec34[1]) + fSlow19);
			fRec35[0] = ((fSlow0 * fRec35[1]) + fSlow20);
			fRec36[0] = ((fSlow0 * fRec36[1]) + fSlow21);
			double fTemp13 = (1 - (0.75 * fRec36[0]));
			fRec37[0] = ((fSlow0 * fRec37[1]) + fSlow22);
			fRec38[0] = ((fSlow0 * fRec38[1]) + fSlow23);
			fRec39[0] = ((fSlow0 * fRec39[1]) + fSlow24);
			double fTemp14 = (1 - (0.75 * fRec39[0]));
			fRec40[0] = ((fSlow0 * fRec40[1]) + fSlow25);
			fRec41[0] = ((fSlow0 * fRec41[1]) + fSlow26);
			fRec42[0] = ((fSlow0 * fRec42[1]) + fSlow27);
			double fTemp15 = (1 - (0.75 * fRec42[0]));
			fRec43[0] = ((fSlow0 * fRec43[1]) + fSlow28);
			fRec44[0] = ((fSlow0 * fRec44[1]) + fSlow29);
			fRec45[0] = ((fSlow0 * fRec45[1]) + fSlow30);
			double fTemp16 = (1 - (0.75 * fRec45[0]));
			fRec46[0] = ((fSlow0 * fRec46[1]) + fSlow31);
			fRec47[0] = ((fSlow0 * fRec47[1]) + fSlow32);
			fRec48[0] = ((fSlow0 * fRec48[1]) + fSlow33);
			double fTemp17 = (1 - (0.75 * fRec48[0]));
			fRec49[0] = ((fSlow0 * fRec49[1]) + fSlow34);
			fRec50[0] = ((fSlow0 * fRec50[1]) + fSlow35);
			fRec51[0] = ((fSlow0 * fRec51[1]) + fSlow36);
			double fTemp18 = (1 - (0.75 * fRec51[0]));
			fRec52[0] = ((fSlow0 * fRec52[1]) + fSlow37);
			fRec53[0] = ((fSlow0 * fRec53[1]) + fSlow38);
			fRec54[0] = ((fSlow0 * fRec54[1]) + fSlow39);
			double fTemp19 = (1 - (0.75 * fRec54[0]));
			fRec55[0] = ((fSlow0 * fRec55[1]) + fSlow40);
			fRec56[0] = ((fSlow0 * fRec56[1]) + fSlow41);
			fRec57[0] = ((fSlow0 * fRec57[1]) + fSlow42);
			double fTemp20 = (1 - (0.75 * fRec57[0]));
			fRec58[0] = ((fSlow0 * fRec58[1]) + fSlow43);
			fRec59[0] = ((fSlow0 * fRec59[1]) + fSlow44);
			fRec60[0] = ((fSlow0 * fRec60[1]) + fSlow45);
			double fTemp21 = (1 - (0.75 * fRec60[0]));
			fRec61[0] = ((fSlow0 * fRec61[1]) + fSlow46);
			fRec62[0] = ((fSlow0 * fRec62[1]) + fSlow47);
			fRec63[0] = ((fSlow0 * fRec63[1]) + fSlow48);
			double fTemp22 = (1 - (0.75 * fRec63[0]));
			fRec64[0] = ((fSlow0 * fRec64[1]) + fSlow49);
			fRec65[0] = ((fSlow0 * fRec65[1]) + fSlow50);
			fRec66[0] = ((fSlow0 * fRec66[1]) + fSlow51);
			double fTemp23 = (1 - (0.75 * fRec66[0]));
			fRec67[0] = ((fSlow0 * fRec67[1]) + fSlow52);
			fRec68[0] = ((fSlow0 * fRec68[1]) + fSlow53);
			fRec69[0] = ((fSlow0 * fRec69[1]) + fSlow54);
			double fTemp24 = (1 - (0.75 * fRec69[0]));
			fRec70[0] = ((fSlow0 * fRec70[1]) + fSlow55);
			fRec71[0] = ((fSlow0 * fRec71[1]) + fSlow56);
			double fTemp25 = ((((fRec71[0] * fRec70[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec67[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec64[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec61[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec58[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec55[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec52[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec49[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec46[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec43[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec40[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec37[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec34[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec31[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec28[0]) * fRec2[1]) * fTemp10) + (((double)input0[i] * fRec26[0]) + (((fRec25[0] * fRec24[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec2[IOTA&2097151] = fTemp25;
			fRec73[0] = fmod((fConst5 + fRec73[1]),1.0);
			double fTemp26 = (65536.0 * fRec73[0]);
			int iTemp27 = int(fTemp26);
			double fTemp28 = ftbl0[iTemp27];
			double fTemp29 = (1.0 + (fTemp28 + ((fTemp26 - floor(fTemp26)) * (ftbl0[((1 + iTemp27) % 65536)] - fTemp28))));
			fVec3[0] = fTemp29;
			double fTemp30 = (0.5 * fVec3[0]);
			double fTemp31 = (1 - fTemp30);
			fVec4[0] = fTemp31;
			int iTemp32 = (fVec4[1] <= 0.001);
			int iTemp33 = (fVec4[0] > 0.001);
			fRec74[0] = ((fSlow0 * fRec74[1]) + fSlow58);
			int iTemp34 = (1 - (iTemp33 * iTemp32));
			fRec72[0] = ((fRec72[1] * iTemp34) + ((fRec74[0] * iTemp33) * iTemp32));
			int iTemp35 = ((0.5 * fVec3[1]) <= 0.001);
			int iTemp36 = (fTemp30 > 0.001);
			int iTemp37 = (1 - (iTemp36 * iTemp35));
			fRec75[0] = ((fRec75[1] * iTemp37) + ((fRec74[0] * iTemp36) * iTemp35));
			double fTemp38 = ((0.5 * (fVec3[0] * fVec2[(IOTA-int((int(fRec75[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec2[(IOTA-int((int(fRec72[0]) & 2097151)))&2097151]));
			int iTemp39 = (fTemp38 < -1);
			int iTemp40 = (fTemp38 > 1);
			double fTemp41 = ((iTemp40 + ((fTemp38 * (1 - iTemp39)) * (1 - iTemp40))) - iTemp39);
			double fTemp42 = (fRec23[0] * fTemp41);
			fVec5[IOTA&262143] = fTemp42;
			int iTemp43 = (fVec1[1] <= 0.01);
			int iTemp44 = (fVec1[0] > 0.01);
			fRec76[0] = ((fRec76[1] * (1 - (iTemp44 * iTemp43))) + ((fRec19[0] * iTemp44) * iTemp43));
			double fTemp45 = (fConst6 * (fRec76[0] * fVec1[0]));
			int iTemp46 = int(fTemp45);
			int iTemp47 = (1 + iTemp46);
			double fTemp48 = (0.25 + fTemp3);
			double fTemp49 = (fTemp48 - floor(fTemp48));
			fVec6[0] = fTemp49;
			double fTemp50 = (32768.0 * fVec6[0]);
			int iTemp51 = int(fTemp50);
			double fTemp52 = ftbl0[iTemp51];
			int iTemp53 = (fVec6[1] <= 0.01);
			int iTemp54 = (fVec6[0] > 0.01);
			fRec77[0] = ((fRec77[1] * (1 - (iTemp54 * iTemp53))) + ((fRec19[0] * iTemp54) * iTemp53));
			double fTemp55 = (fConst6 * (fRec77[0] * fVec6[0]));
			int iTemp56 = int(fTemp55);
			int iTemp57 = (1 + iTemp56);
			double fTemp58 = (fTemp3 - floor(fTemp3));
			fVec7[0] = fTemp58;
			double fTemp59 = (32768.0 * fVec7[0]);
			int iTemp60 = int(fTemp59);
			double fTemp61 = ftbl0[iTemp60];
			int iTemp62 = (fVec7[1] <= 0.01);
			int iTemp63 = (fVec7[0] > 0.01);
			fRec78[0] = ((fRec78[1] * (1 - (iTemp63 * iTemp62))) + ((fRec19[0] * iTemp63) * iTemp62));
			double fTemp64 = (fConst6 * (fRec78[0] * fVec7[0]));
			int iTemp65 = int(fTemp64);
			int iTemp66 = (1 + iTemp65);
			double fTemp67 = (0.75 + fTemp3);
			double fTemp68 = (fTemp67 - floor(fTemp67));
			fVec8[0] = fTemp68;
			double fTemp69 = (32768.0 * fVec8[0]);
			int iTemp70 = int(fTemp69);
			double fTemp71 = ftbl0[iTemp70];
			int iTemp72 = (fVec8[1] <= 0.01);
			int iTemp73 = (fVec8[0] > 0.01);
			fRec79[0] = ((fRec79[1] * (1 - (iTemp73 * iTemp72))) + ((fRec19[0] * iTemp73) * iTemp72));
			double fTemp74 = (fConst6 * (fRec79[0] * fVec8[0]));
			int iTemp75 = int(fTemp74);
			int iTemp76 = (1 + iTemp75);
			fRec1[0] = (((1 - fRec23[0]) * fTemp41) + ((((fVec5[(IOTA-int((iTemp75 & 262143)))&262143] * (iTemp76 - fTemp74)) + ((fTemp74 - iTemp75) * fVec5[(IOTA-int((int(iTemp76) & 262143)))&262143])) * (fTemp71 + ((fTemp69 - floor(fTemp69)) * (ftbl0[((1 + iTemp70) % 65536)] - fTemp71)))) + (((((fVec5[(IOTA-int((iTemp65 & 262143)))&262143] * (iTemp66 - fTemp64)) + ((fTemp64 - iTemp65) * fVec5[(IOTA-int((int(iTemp66) & 262143)))&262143])) * (fTemp61 + ((fTemp59 - floor(fTemp59)) * (ftbl0[((1 + iTemp60) % 65536)] - fTemp61)))) + (((fVec5[(IOTA-int((iTemp56 & 262143)))&262143] * (iTemp57 - fTemp55)) + ((fTemp55 - iTemp56) * fVec5[(IOTA-int((int(iTemp57) & 262143)))&262143])) * (fTemp52 + ((fTemp50 - floor(fTemp50)) * (ftbl0[((1 + iTemp51) % 65536)] - fTemp52))))) + (((fVec5[(IOTA-int((iTemp46 & 262143)))&262143] * (iTemp47 - fTemp45)) + ((fTemp45 - iTemp46) * fVec5[(IOTA-int((int(iTemp47) & 262143)))&262143])) * (fTemp8 + ((fTemp6 - floor(fTemp6)) * (ftbl0[((1 + iTemp7) % 65536)] - fTemp8)))))));
			fRec81[0] = ((fSlow0 * fRec81[1]) + fSlow59);
			double fTemp77 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec81[0])) - 69))) - 261.625977))) / fTemp1);
			fRec80[0] = fmod((fRec80[1] + (fConst4 * double(fTemp77))),1.0);
			double fTemp78 = ((int((fTemp77 > 0)))?fRec80[0]:(1.0 + fRec80[0]));
			double fTemp79 = (0.5 + fTemp78);
			double fTemp80 = (fTemp79 - floor(fTemp79));
			fVec9[0] = fTemp80;
			double fTemp81 = (32768.0 * fVec9[0]);
			int iTemp82 = int(fTemp81);
			double fTemp83 = ftbl0[iTemp82];
			fRec82[0] = ((fSlow0 * fRec82[1]) + fSlow60);
			fRec83[0] = ((fSlow0 * fRec83[1]) + fSlow61);
			fRec84[0] = ((fSlow0 * fRec84[1]) + fSlow62);
			fRec85[0] = ((fSlow0 * fRec85[1]) + fSlow63);
			fRec86[0] = ((fSlow0 * fRec86[1]) + fSlow64);
			fRec87[0] = ((fSlow0 * fRec87[1]) + fSlow65);
			fRec88[0] = ((fSlow0 * fRec88[1]) + fSlow66);
			fRec89[0] = ((fSlow0 * fRec89[1]) + fSlow67);
			fRec90[0] = ((fSlow0 * fRec90[1]) + fSlow68);
			fRec91[0] = ((fSlow0 * fRec91[1]) + fSlow69);
			fRec92[0] = ((fSlow0 * fRec92[1]) + fSlow70);
			fRec93[0] = ((fSlow0 * fRec93[1]) + fSlow71);
			fRec94[0] = ((fSlow0 * fRec94[1]) + fSlow72);
			fRec95[0] = ((fSlow0 * fRec95[1]) + fSlow73);
			fRec96[0] = ((fSlow0 * fRec96[1]) + fSlow74);
			fRec97[0] = ((fSlow0 * fRec97[1]) + fSlow75);
			fRec98[0] = ((fSlow0 * fRec98[1]) + fSlow76);
			double fTemp84 = ((((fRec71[0] * fRec98[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec97[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec96[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec95[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec94[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec93[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec92[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec91[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec90[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec89[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec88[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec87[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec86[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec85[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec84[0]) * fRec2[1]) * fTemp10) + (((double)input1[i] * fRec83[0]) + (((fRec25[0] * fRec82[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec10[IOTA&2097151] = fTemp84;
			fRec100[0] = ((fSlow0 * fRec100[1]) + fSlow77);
			fRec99[0] = ((iTemp34 * fRec99[1]) + ((fRec100[0] * iTemp33) * iTemp32));
			fRec101[0] = ((iTemp37 * fRec101[1]) + ((fRec100[0] * iTemp36) * iTemp35));
			double fTemp85 = ((0.5 * (fVec3[0] * fVec10[(IOTA-int((int(fRec101[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec10[(IOTA-int((int(fRec99[0]) & 2097151)))&2097151]));
			int iTemp86 = (fTemp85 < -1);
			int iTemp87 = (fTemp85 > 1);
			double fTemp88 = ((iTemp87 + ((fTemp85 * (1 - iTemp86)) * (1 - iTemp87))) - iTemp86);
			double fTemp89 = (fRec27[0] * fTemp88);
			fVec11[IOTA&262143] = fTemp89;
			int iTemp90 = (fVec9[1] <= 0.01);
			int iTemp91 = (fVec9[0] > 0.01);
			fRec102[0] = ((fRec102[1] * (1 - (iTemp91 * iTemp90))) + ((fRec19[0] * iTemp91) * iTemp90));
			double fTemp92 = (fConst6 * (fRec102[0] * fVec9[0]));
			int iTemp93 = int(fTemp92);
			int iTemp94 = (1 + iTemp93);
			double fTemp95 = (0.25 + fTemp78);
			double fTemp96 = (fTemp95 - floor(fTemp95));
			fVec12[0] = fTemp96;
			double fTemp97 = (32768.0 * fVec12[0]);
			int iTemp98 = int(fTemp97);
			double fTemp99 = ftbl0[iTemp98];
			int iTemp100 = (fVec12[1] <= 0.01);
			int iTemp101 = (fVec12[0] > 0.01);
			fRec103[0] = ((fRec103[1] * (1 - (iTemp101 * iTemp100))) + ((fRec19[0] * iTemp101) * iTemp100));
			double fTemp102 = (fConst6 * (fRec103[0] * fVec12[0]));
			int iTemp103 = int(fTemp102);
			int iTemp104 = (1 + iTemp103);
			double fTemp105 = (fTemp78 - floor(fTemp78));
			fVec13[0] = fTemp105;
			double fTemp106 = (32768.0 * fVec13[0]);
			int iTemp107 = int(fTemp106);
			double fTemp108 = ftbl0[iTemp107];
			int iTemp109 = (fVec13[1] <= 0.01);
			int iTemp110 = (fVec13[0] > 0.01);
			fRec104[0] = ((fRec104[1] * (1 - (iTemp110 * iTemp109))) + ((fRec19[0] * iTemp110) * iTemp109));
			double fTemp111 = (fConst6 * (fRec104[0] * fVec13[0]));
			int iTemp112 = int(fTemp111);
			int iTemp113 = (1 + iTemp112);
			double fTemp114 = (0.75 + fTemp78);
			double fTemp115 = (fTemp114 - floor(fTemp114));
			fVec14[0] = fTemp115;
			double fTemp116 = (32768.0 * fVec14[0]);
			int iTemp117 = int(fTemp116);
			double fTemp118 = ftbl0[iTemp117];
			int iTemp119 = (fVec14[1] <= 0.01);
			int iTemp120 = (fVec14[0] > 0.01);
			fRec105[0] = ((fRec105[1] * (1 - (iTemp120 * iTemp119))) + ((fRec19[0] * iTemp120) * iTemp119));
			double fTemp121 = (fConst6 * (fRec105[0] * fVec14[0]));
			int iTemp122 = int(fTemp121);
			int iTemp123 = (1 + iTemp122);
			fRec2[0] = (((1 - fRec27[0]) * fTemp88) + ((((fVec11[(IOTA-int((iTemp122 & 262143)))&262143] * (iTemp123 - fTemp121)) + ((fTemp121 - iTemp122) * fVec11[(IOTA-int((int(iTemp123) & 262143)))&262143])) * (fTemp118 + ((fTemp116 - floor(fTemp116)) * (ftbl0[((1 + iTemp117) % 65536)] - fTemp118)))) + (((((fVec11[(IOTA-int((iTemp112 & 262143)))&262143] * (iTemp113 - fTemp111)) + ((fTemp111 - iTemp112) * fVec11[(IOTA-int((int(iTemp113) & 262143)))&262143])) * (fTemp108 + ((fTemp106 - floor(fTemp106)) * (ftbl0[((1 + iTemp107) % 65536)] - fTemp108)))) + (((fVec11[(IOTA-int((iTemp103 & 262143)))&262143] * (iTemp104 - fTemp102)) + ((fTemp102 - iTemp103) * fVec11[(IOTA-int((int(iTemp104) & 262143)))&262143])) * (fTemp99 + ((fTemp97 - floor(fTemp97)) * (ftbl0[((1 + iTemp98) % 65536)] - fTemp99))))) + (((fVec11[(IOTA-int((iTemp93 & 262143)))&262143] * (iTemp94 - fTemp92)) + ((fTemp92 - iTemp93) * fVec11[(IOTA-int((int(iTemp94) & 262143)))&262143])) * (fTemp83 + ((fTemp81 - floor(fTemp81)) * (ftbl0[((1 + iTemp82) % 65536)] - fTemp83)))))));
			fRec107[0] = ((fSlow0 * fRec107[1]) + fSlow78);
			double fTemp124 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec107[0])) - 69))) - 261.625977))) / fTemp1);
			fRec106[0] = fmod((fRec106[1] + (fConst4 * double(fTemp124))),1.0);
			double fTemp125 = ((int((fTemp124 > 0)))?fRec106[0]:(1.0 + fRec106[0]));
			double fTemp126 = (0.5 + fTemp125);
			double fTemp127 = (fTemp126 - floor(fTemp126));
			fVec15[0] = fTemp127;
			double fTemp128 = (32768.0 * fVec15[0]);
			int iTemp129 = int(fTemp128);
			double fTemp130 = ftbl0[iTemp129];
			fRec108[0] = ((fSlow0 * fRec108[1]) + fSlow79);
			fRec109[0] = ((fSlow0 * fRec109[1]) + fSlow80);
			fRec110[0] = ((fSlow0 * fRec110[1]) + fSlow81);
			fRec111[0] = ((fSlow0 * fRec111[1]) + fSlow82);
			fRec112[0] = ((fSlow0 * fRec112[1]) + fSlow83);
			fRec113[0] = ((fSlow0 * fRec113[1]) + fSlow84);
			fRec114[0] = ((fSlow0 * fRec114[1]) + fSlow85);
			fRec115[0] = ((fSlow0 * fRec115[1]) + fSlow86);
			fRec116[0] = ((fSlow0 * fRec116[1]) + fSlow87);
			fRec117[0] = ((fSlow0 * fRec117[1]) + fSlow88);
			fRec118[0] = ((fSlow0 * fRec118[1]) + fSlow89);
			fRec119[0] = ((fSlow0 * fRec119[1]) + fSlow90);
			fRec120[0] = ((fSlow0 * fRec120[1]) + fSlow91);
			fRec121[0] = ((fSlow0 * fRec121[1]) + fSlow92);
			fRec122[0] = ((fSlow0 * fRec122[1]) + fSlow93);
			fRec123[0] = ((fSlow0 * fRec123[1]) + fSlow94);
			fRec124[0] = ((fSlow0 * fRec124[1]) + fSlow95);
			double fTemp131 = ((((fRec71[0] * fRec124[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec123[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec122[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec121[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec120[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec119[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec118[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec117[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec116[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec115[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec114[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec113[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec112[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec111[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec110[0]) * fRec2[1]) * fTemp10) + (((double)input2[i] * fRec109[0]) + (((fRec25[0] * fRec108[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec16[IOTA&2097151] = fTemp131;
			fRec126[0] = ((fSlow0 * fRec126[1]) + fSlow96);
			fRec125[0] = ((iTemp34 * fRec125[1]) + ((fRec126[0] * iTemp33) * iTemp32));
			fRec127[0] = ((iTemp37 * fRec127[1]) + ((fRec126[0] * iTemp36) * iTemp35));
			double fTemp132 = ((0.5 * (fVec3[0] * fVec16[(IOTA-int((int(fRec127[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec16[(IOTA-int((int(fRec125[0]) & 2097151)))&2097151]));
			int iTemp133 = (fTemp132 < -1);
			int iTemp134 = (fTemp132 > 1);
			double fTemp135 = ((iTemp134 + ((fTemp132 * (1 - iTemp133)) * (1 - iTemp134))) - iTemp133);
			double fTemp136 = (fRec30[0] * fTemp135);
			fVec17[IOTA&262143] = fTemp136;
			int iTemp137 = (fVec15[1] <= 0.01);
			int iTemp138 = (fVec15[0] > 0.01);
			fRec128[0] = ((fRec128[1] * (1 - (iTemp138 * iTemp137))) + ((fRec19[0] * iTemp138) * iTemp137));
			double fTemp139 = (fConst6 * (fRec128[0] * fVec15[0]));
			int iTemp140 = int(fTemp139);
			int iTemp141 = (1 + iTemp140);
			double fTemp142 = (0.25 + fTemp125);
			double fTemp143 = (fTemp142 - floor(fTemp142));
			fVec18[0] = fTemp143;
			double fTemp144 = (32768.0 * fVec18[0]);
			int iTemp145 = int(fTemp144);
			double fTemp146 = ftbl0[iTemp145];
			int iTemp147 = (fVec18[1] <= 0.01);
			int iTemp148 = (fVec18[0] > 0.01);
			fRec129[0] = ((fRec129[1] * (1 - (iTemp148 * iTemp147))) + ((fRec19[0] * iTemp148) * iTemp147));
			double fTemp149 = (fConst6 * (fRec129[0] * fVec18[0]));
			int iTemp150 = int(fTemp149);
			int iTemp151 = (1 + iTemp150);
			double fTemp152 = (fTemp125 - floor(fTemp125));
			fVec19[0] = fTemp152;
			double fTemp153 = (32768.0 * fVec19[0]);
			int iTemp154 = int(fTemp153);
			double fTemp155 = ftbl0[iTemp154];
			int iTemp156 = (fVec19[1] <= 0.01);
			int iTemp157 = (fVec19[0] > 0.01);
			fRec130[0] = ((fRec130[1] * (1 - (iTemp157 * iTemp156))) + ((fRec19[0] * iTemp157) * iTemp156));
			double fTemp158 = (fConst6 * (fRec130[0] * fVec19[0]));
			int iTemp159 = int(fTemp158);
			int iTemp160 = (1 + iTemp159);
			double fTemp161 = (0.75 + fTemp125);
			double fTemp162 = (fTemp161 - floor(fTemp161));
			fVec20[0] = fTemp162;
			double fTemp163 = (32768.0 * fVec20[0]);
			int iTemp164 = int(fTemp163);
			double fTemp165 = ftbl0[iTemp164];
			int iTemp166 = (fVec20[1] <= 0.01);
			int iTemp167 = (fVec20[0] > 0.01);
			fRec131[0] = ((fRec131[1] * (1 - (iTemp167 * iTemp166))) + ((fRec19[0] * iTemp167) * iTemp166));
			double fTemp168 = (fConst6 * (fRec131[0] * fVec20[0]));
			int iTemp169 = int(fTemp168);
			int iTemp170 = (1 + iTemp169);
			fRec3[0] = (((1 - fRec30[0]) * fTemp135) + ((((fVec17[(IOTA-int((iTemp169 & 262143)))&262143] * (iTemp170 - fTemp168)) + ((fTemp168 - iTemp169) * fVec17[(IOTA-int((int(iTemp170) & 262143)))&262143])) * (fTemp165 + ((fTemp163 - floor(fTemp163)) * (ftbl0[((1 + iTemp164) % 65536)] - fTemp165)))) + (((((fVec17[(IOTA-int((iTemp159 & 262143)))&262143] * (iTemp160 - fTemp158)) + ((fTemp158 - iTemp159) * fVec17[(IOTA-int((int(iTemp160) & 262143)))&262143])) * (fTemp155 + ((fTemp153 - floor(fTemp153)) * (ftbl0[((1 + iTemp154) % 65536)] - fTemp155)))) + (((fVec17[(IOTA-int((iTemp150 & 262143)))&262143] * (iTemp151 - fTemp149)) + ((fTemp149 - iTemp150) * fVec17[(IOTA-int((int(iTemp151) & 262143)))&262143])) * (fTemp146 + ((fTemp144 - floor(fTemp144)) * (ftbl0[((1 + iTemp145) % 65536)] - fTemp146))))) + (((fVec17[(IOTA-int((iTemp140 & 262143)))&262143] * (iTemp141 - fTemp139)) + ((fTemp139 - iTemp140) * fVec17[(IOTA-int((int(iTemp141) & 262143)))&262143])) * (fTemp130 + ((fTemp128 - floor(fTemp128)) * (ftbl0[((1 + iTemp129) % 65536)] - fTemp130)))))));
			fRec133[0] = ((fSlow0 * fRec133[1]) + fSlow97);
			double fTemp171 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec133[0])) - 69))) - 261.625977))) / fTemp1);
			fRec132[0] = fmod((fRec132[1] + (fConst4 * double(fTemp171))),1.0);
			double fTemp172 = ((int((fTemp171 > 0)))?fRec132[0]:(1.0 + fRec132[0]));
			double fTemp173 = (0.5 + fTemp172);
			double fTemp174 = (fTemp173 - floor(fTemp173));
			fVec21[0] = fTemp174;
			double fTemp175 = (32768.0 * fVec21[0]);
			int iTemp176 = int(fTemp175);
			double fTemp177 = ftbl0[iTemp176];
			fRec134[0] = ((fSlow0 * fRec134[1]) + fSlow98);
			fRec135[0] = ((fSlow0 * fRec135[1]) + fSlow99);
			fRec136[0] = ((fSlow0 * fRec136[1]) + fSlow100);
			fRec137[0] = ((fSlow0 * fRec137[1]) + fSlow101);
			fRec138[0] = ((fSlow0 * fRec138[1]) + fSlow102);
			fRec139[0] = ((fSlow0 * fRec139[1]) + fSlow103);
			fRec140[0] = ((fSlow0 * fRec140[1]) + fSlow104);
			fRec141[0] = ((fSlow0 * fRec141[1]) + fSlow105);
			fRec142[0] = ((fSlow0 * fRec142[1]) + fSlow106);
			fRec143[0] = ((fSlow0 * fRec143[1]) + fSlow107);
			fRec144[0] = ((fSlow0 * fRec144[1]) + fSlow108);
			fRec145[0] = ((fSlow0 * fRec145[1]) + fSlow109);
			fRec146[0] = ((fSlow0 * fRec146[1]) + fSlow110);
			fRec147[0] = ((fSlow0 * fRec147[1]) + fSlow111);
			fRec148[0] = ((fSlow0 * fRec148[1]) + fSlow112);
			fRec149[0] = ((fSlow0 * fRec149[1]) + fSlow113);
			fRec150[0] = ((fSlow0 * fRec150[1]) + fSlow114);
			double fTemp178 = ((((fRec71[0] * fRec150[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec149[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec148[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec147[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec146[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec145[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec144[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec143[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec142[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec141[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec140[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec139[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec138[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec137[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec136[0]) * fRec2[1]) * fTemp10) + (((double)input3[i] * fRec135[0]) + (((fRec25[0] * fRec134[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec22[IOTA&2097151] = fTemp178;
			fRec152[0] = ((fSlow0 * fRec152[1]) + fSlow115);
			fRec151[0] = ((iTemp34 * fRec151[1]) + ((fRec152[0] * iTemp33) * iTemp32));
			fRec153[0] = ((iTemp37 * fRec153[1]) + ((fRec152[0] * iTemp36) * iTemp35));
			double fTemp179 = ((0.5 * (fVec3[0] * fVec22[(IOTA-int((int(fRec153[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec22[(IOTA-int((int(fRec151[0]) & 2097151)))&2097151]));
			int iTemp180 = (fTemp179 < -1);
			int iTemp181 = (fTemp179 > 1);
			double fTemp182 = ((iTemp181 + ((fTemp179 * (1 - iTemp180)) * (1 - iTemp181))) - iTemp180);
			double fTemp183 = (fRec33[0] * fTemp182);
			fVec23[IOTA&262143] = fTemp183;
			int iTemp184 = (fVec21[1] <= 0.01);
			int iTemp185 = (fVec21[0] > 0.01);
			fRec154[0] = ((fRec154[1] * (1 - (iTemp185 * iTemp184))) + ((fRec19[0] * iTemp185) * iTemp184));
			double fTemp186 = (fConst6 * (fRec154[0] * fVec21[0]));
			int iTemp187 = int(fTemp186);
			int iTemp188 = (1 + iTemp187);
			double fTemp189 = (0.25 + fTemp172);
			double fTemp190 = (fTemp189 - floor(fTemp189));
			fVec24[0] = fTemp190;
			double fTemp191 = (32768.0 * fVec24[0]);
			int iTemp192 = int(fTemp191);
			double fTemp193 = ftbl0[iTemp192];
			int iTemp194 = (fVec24[1] <= 0.01);
			int iTemp195 = (fVec24[0] > 0.01);
			fRec155[0] = ((fRec155[1] * (1 - (iTemp195 * iTemp194))) + ((fRec19[0] * iTemp195) * iTemp194));
			double fTemp196 = (fConst6 * (fRec155[0] * fVec24[0]));
			int iTemp197 = int(fTemp196);
			int iTemp198 = (1 + iTemp197);
			double fTemp199 = (fTemp172 - floor(fTemp172));
			fVec25[0] = fTemp199;
			double fTemp200 = (32768.0 * fVec25[0]);
			int iTemp201 = int(fTemp200);
			double fTemp202 = ftbl0[iTemp201];
			int iTemp203 = (fVec25[1] <= 0.01);
			int iTemp204 = (fVec25[0] > 0.01);
			fRec156[0] = ((fRec156[1] * (1 - (iTemp204 * iTemp203))) + ((fRec19[0] * iTemp204) * iTemp203));
			double fTemp205 = (fConst6 * (fRec156[0] * fVec25[0]));
			int iTemp206 = int(fTemp205);
			int iTemp207 = (1 + iTemp206);
			double fTemp208 = (0.75 + fTemp172);
			double fTemp209 = (fTemp208 - floor(fTemp208));
			fVec26[0] = fTemp209;
			double fTemp210 = (32768.0 * fVec26[0]);
			int iTemp211 = int(fTemp210);
			double fTemp212 = ftbl0[iTemp211];
			int iTemp213 = (fVec26[1] <= 0.01);
			int iTemp214 = (fVec26[0] > 0.01);
			fRec157[0] = ((fRec157[1] * (1 - (iTemp214 * iTemp213))) + ((fRec19[0] * iTemp214) * iTemp213));
			double fTemp215 = (fConst6 * (fRec157[0] * fVec26[0]));
			int iTemp216 = int(fTemp215);
			int iTemp217 = (1 + iTemp216);
			fRec4[0] = (((1 - fRec33[0]) * fTemp182) + ((((fVec23[(IOTA-int((iTemp216 & 262143)))&262143] * (iTemp217 - fTemp215)) + ((fTemp215 - iTemp216) * fVec23[(IOTA-int((int(iTemp217) & 262143)))&262143])) * (fTemp212 + ((fTemp210 - floor(fTemp210)) * (ftbl0[((1 + iTemp211) % 65536)] - fTemp212)))) + (((((fVec23[(IOTA-int((iTemp206 & 262143)))&262143] * (iTemp207 - fTemp205)) + ((fTemp205 - iTemp206) * fVec23[(IOTA-int((int(iTemp207) & 262143)))&262143])) * (fTemp202 + ((fTemp200 - floor(fTemp200)) * (ftbl0[((1 + iTemp201) % 65536)] - fTemp202)))) + (((fVec23[(IOTA-int((iTemp197 & 262143)))&262143] * (iTemp198 - fTemp196)) + ((fTemp196 - iTemp197) * fVec23[(IOTA-int((int(iTemp198) & 262143)))&262143])) * (fTemp193 + ((fTemp191 - floor(fTemp191)) * (ftbl0[((1 + iTemp192) % 65536)] - fTemp193))))) + (((fVec23[(IOTA-int((iTemp187 & 262143)))&262143] * (iTemp188 - fTemp186)) + ((fTemp186 - iTemp187) * fVec23[(IOTA-int((int(iTemp188) & 262143)))&262143])) * (fTemp177 + ((fTemp175 - floor(fTemp175)) * (ftbl0[((1 + iTemp176) % 65536)] - fTemp177)))))));
			fRec159[0] = ((fSlow0 * fRec159[1]) + fSlow116);
			double fTemp218 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec159[0])) - 69))) - 261.625977))) / fTemp1);
			fRec158[0] = fmod((fRec158[1] + (fConst4 * double(fTemp218))),1.0);
			double fTemp219 = ((int((fTemp218 > 0)))?fRec158[0]:(1.0 + fRec158[0]));
			double fTemp220 = (0.5 + fTemp219);
			double fTemp221 = (fTemp220 - floor(fTemp220));
			fVec27[0] = fTemp221;
			double fTemp222 = (32768.0 * fVec27[0]);
			int iTemp223 = int(fTemp222);
			double fTemp224 = ftbl0[iTemp223];
			fRec160[0] = ((fSlow0 * fRec160[1]) + fSlow117);
			fRec161[0] = ((fSlow0 * fRec161[1]) + fSlow118);
			fRec162[0] = ((fSlow0 * fRec162[1]) + fSlow119);
			fRec163[0] = ((fSlow0 * fRec163[1]) + fSlow120);
			fRec164[0] = ((fSlow0 * fRec164[1]) + fSlow121);
			fRec165[0] = ((fSlow0 * fRec165[1]) + fSlow122);
			fRec166[0] = ((fSlow0 * fRec166[1]) + fSlow123);
			fRec167[0] = ((fSlow0 * fRec167[1]) + fSlow124);
			fRec168[0] = ((fSlow0 * fRec168[1]) + fSlow125);
			fRec169[0] = ((fSlow0 * fRec169[1]) + fSlow126);
			fRec170[0] = ((fSlow0 * fRec170[1]) + fSlow127);
			fRec171[0] = ((fSlow0 * fRec171[1]) + fSlow128);
			fRec172[0] = ((fSlow0 * fRec172[1]) + fSlow129);
			fRec173[0] = ((fSlow0 * fRec173[1]) + fSlow130);
			fRec174[0] = ((fSlow0 * fRec174[1]) + fSlow131);
			fRec175[0] = ((fSlow0 * fRec175[1]) + fSlow132);
			fRec176[0] = ((fSlow0 * fRec176[1]) + fSlow133);
			double fTemp225 = ((((fRec71[0] * fRec176[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec175[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec174[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec173[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec172[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec171[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec170[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec169[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec168[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec167[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec166[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec165[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec164[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec163[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec162[0]) * fRec2[1]) * fTemp10) + (((double)input4[i] * fRec161[0]) + (((fRec25[0] * fRec160[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec28[IOTA&2097151] = fTemp225;
			fRec178[0] = ((fSlow0 * fRec178[1]) + fSlow134);
			fRec177[0] = ((iTemp34 * fRec177[1]) + ((fRec178[0] * iTemp33) * iTemp32));
			fRec179[0] = ((iTemp37 * fRec179[1]) + ((fRec178[0] * iTemp36) * iTemp35));
			double fTemp226 = ((0.5 * (fVec3[0] * fVec28[(IOTA-int((int(fRec179[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec28[(IOTA-int((int(fRec177[0]) & 2097151)))&2097151]));
			int iTemp227 = (fTemp226 < -1);
			int iTemp228 = (fTemp226 > 1);
			double fTemp229 = ((iTemp228 + ((fTemp226 * (1 - iTemp227)) * (1 - iTemp228))) - iTemp227);
			double fTemp230 = (fRec36[0] * fTemp229);
			fVec29[IOTA&262143] = fTemp230;
			int iTemp231 = (fVec27[1] <= 0.01);
			int iTemp232 = (fVec27[0] > 0.01);
			fRec180[0] = ((fRec180[1] * (1 - (iTemp232 * iTemp231))) + ((fRec19[0] * iTemp232) * iTemp231));
			double fTemp233 = (fConst6 * (fRec180[0] * fVec27[0]));
			int iTemp234 = int(fTemp233);
			int iTemp235 = (1 + iTemp234);
			double fTemp236 = (0.25 + fTemp219);
			double fTemp237 = (fTemp236 - floor(fTemp236));
			fVec30[0] = fTemp237;
			double fTemp238 = (32768.0 * fVec30[0]);
			int iTemp239 = int(fTemp238);
			double fTemp240 = ftbl0[iTemp239];
			int iTemp241 = (fVec30[1] <= 0.01);
			int iTemp242 = (fVec30[0] > 0.01);
			fRec181[0] = ((fRec181[1] * (1 - (iTemp242 * iTemp241))) + ((fRec19[0] * iTemp242) * iTemp241));
			double fTemp243 = (fConst6 * (fRec181[0] * fVec30[0]));
			int iTemp244 = int(fTemp243);
			int iTemp245 = (1 + iTemp244);
			double fTemp246 = (fTemp219 - floor(fTemp219));
			fVec31[0] = fTemp246;
			double fTemp247 = (32768.0 * fVec31[0]);
			int iTemp248 = int(fTemp247);
			double fTemp249 = ftbl0[iTemp248];
			int iTemp250 = (fVec31[1] <= 0.01);
			int iTemp251 = (fVec31[0] > 0.01);
			fRec182[0] = ((fRec182[1] * (1 - (iTemp251 * iTemp250))) + ((fRec19[0] * iTemp251) * iTemp250));
			double fTemp252 = (fConst6 * (fRec182[0] * fVec31[0]));
			int iTemp253 = int(fTemp252);
			int iTemp254 = (1 + iTemp253);
			double fTemp255 = (0.75 + fTemp219);
			double fTemp256 = (fTemp255 - floor(fTemp255));
			fVec32[0] = fTemp256;
			double fTemp257 = (32768.0 * fVec32[0]);
			int iTemp258 = int(fTemp257);
			double fTemp259 = ftbl0[iTemp258];
			int iTemp260 = (fVec32[1] <= 0.01);
			int iTemp261 = (fVec32[0] > 0.01);
			fRec183[0] = ((fRec183[1] * (1 - (iTemp261 * iTemp260))) + ((fRec19[0] * iTemp261) * iTemp260));
			double fTemp262 = (fConst6 * (fRec183[0] * fVec32[0]));
			int iTemp263 = int(fTemp262);
			int iTemp264 = (1 + iTemp263);
			fRec5[0] = (((1 - fRec36[0]) * fTemp229) + ((((fVec29[(IOTA-int((iTemp263 & 262143)))&262143] * (iTemp264 - fTemp262)) + ((fTemp262 - iTemp263) * fVec29[(IOTA-int((int(iTemp264) & 262143)))&262143])) * (fTemp259 + ((fTemp257 - floor(fTemp257)) * (ftbl0[((1 + iTemp258) % 65536)] - fTemp259)))) + (((((fVec29[(IOTA-int((iTemp253 & 262143)))&262143] * (iTemp254 - fTemp252)) + ((fTemp252 - iTemp253) * fVec29[(IOTA-int((int(iTemp254) & 262143)))&262143])) * (fTemp249 + ((fTemp247 - floor(fTemp247)) * (ftbl0[((1 + iTemp248) % 65536)] - fTemp249)))) + (((fVec29[(IOTA-int((iTemp244 & 262143)))&262143] * (iTemp245 - fTemp243)) + ((fTemp243 - iTemp244) * fVec29[(IOTA-int((int(iTemp245) & 262143)))&262143])) * (fTemp240 + ((fTemp238 - floor(fTemp238)) * (ftbl0[((1 + iTemp239) % 65536)] - fTemp240))))) + (((fVec29[(IOTA-int((iTemp234 & 262143)))&262143] * (iTemp235 - fTemp233)) + ((fTemp233 - iTemp234) * fVec29[(IOTA-int((int(iTemp235) & 262143)))&262143])) * (fTemp224 + ((fTemp222 - floor(fTemp222)) * (ftbl0[((1 + iTemp223) % 65536)] - fTemp224)))))));
			fRec185[0] = ((fSlow0 * fRec185[1]) + fSlow135);
			double fTemp265 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec185[0])) - 69))) - 261.625977))) / fTemp1);
			fRec184[0] = fmod((fRec184[1] + (fConst4 * double(fTemp265))),1.0);
			double fTemp266 = ((int((fTemp265 > 0)))?fRec184[0]:(1.0 + fRec184[0]));
			double fTemp267 = (0.5 + fTemp266);
			double fTemp268 = (fTemp267 - floor(fTemp267));
			fVec33[0] = fTemp268;
			double fTemp269 = (32768.0 * fVec33[0]);
			int iTemp270 = int(fTemp269);
			double fTemp271 = ftbl0[iTemp270];
			fRec186[0] = ((fSlow0 * fRec186[1]) + fSlow136);
			fRec187[0] = ((fSlow0 * fRec187[1]) + fSlow137);
			fRec188[0] = ((fSlow0 * fRec188[1]) + fSlow138);
			fRec189[0] = ((fSlow0 * fRec189[1]) + fSlow139);
			fRec190[0] = ((fSlow0 * fRec190[1]) + fSlow140);
			fRec191[0] = ((fSlow0 * fRec191[1]) + fSlow141);
			fRec192[0] = ((fSlow0 * fRec192[1]) + fSlow142);
			fRec193[0] = ((fSlow0 * fRec193[1]) + fSlow143);
			fRec194[0] = ((fSlow0 * fRec194[1]) + fSlow144);
			fRec195[0] = ((fSlow0 * fRec195[1]) + fSlow145);
			fRec196[0] = ((fSlow0 * fRec196[1]) + fSlow146);
			fRec197[0] = ((fSlow0 * fRec197[1]) + fSlow147);
			fRec198[0] = ((fSlow0 * fRec198[1]) + fSlow148);
			fRec199[0] = ((fSlow0 * fRec199[1]) + fSlow149);
			fRec200[0] = ((fSlow0 * fRec200[1]) + fSlow150);
			fRec201[0] = ((fSlow0 * fRec201[1]) + fSlow151);
			fRec202[0] = ((fSlow0 * fRec202[1]) + fSlow152);
			double fTemp272 = ((((fRec71[0] * fRec202[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec201[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec200[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec199[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec198[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec197[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec196[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec195[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec194[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec193[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec192[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec191[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec190[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec189[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec188[0]) * fRec2[1]) * fTemp10) + (((double)input5[i] * fRec187[0]) + (((fRec25[0] * fRec186[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec34[IOTA&2097151] = fTemp272;
			fRec204[0] = ((fSlow0 * fRec204[1]) + fSlow153);
			fRec203[0] = ((iTemp34 * fRec203[1]) + ((fRec204[0] * iTemp33) * iTemp32));
			fRec205[0] = ((iTemp37 * fRec205[1]) + ((fRec204[0] * iTemp36) * iTemp35));
			double fTemp273 = ((0.5 * (fVec3[0] * fVec34[(IOTA-int((int(fRec205[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec34[(IOTA-int((int(fRec203[0]) & 2097151)))&2097151]));
			int iTemp274 = (fTemp273 < -1);
			int iTemp275 = (fTemp273 > 1);
			double fTemp276 = ((iTemp275 + ((fTemp273 * (1 - iTemp274)) * (1 - iTemp275))) - iTemp274);
			double fTemp277 = (fRec39[0] * fTemp276);
			fVec35[IOTA&262143] = fTemp277;
			int iTemp278 = (fVec33[1] <= 0.01);
			int iTemp279 = (fVec33[0] > 0.01);
			fRec206[0] = ((fRec206[1] * (1 - (iTemp279 * iTemp278))) + ((fRec19[0] * iTemp279) * iTemp278));
			double fTemp280 = (fConst6 * (fRec206[0] * fVec33[0]));
			int iTemp281 = int(fTemp280);
			int iTemp282 = (1 + iTemp281);
			double fTemp283 = (0.25 + fTemp266);
			double fTemp284 = (fTemp283 - floor(fTemp283));
			fVec36[0] = fTemp284;
			double fTemp285 = (32768.0 * fVec36[0]);
			int iTemp286 = int(fTemp285);
			double fTemp287 = ftbl0[iTemp286];
			int iTemp288 = (fVec36[1] <= 0.01);
			int iTemp289 = (fVec36[0] > 0.01);
			fRec207[0] = ((fRec207[1] * (1 - (iTemp289 * iTemp288))) + ((fRec19[0] * iTemp289) * iTemp288));
			double fTemp290 = (fConst6 * (fRec207[0] * fVec36[0]));
			int iTemp291 = int(fTemp290);
			int iTemp292 = (1 + iTemp291);
			double fTemp293 = (fTemp266 - floor(fTemp266));
			fVec37[0] = fTemp293;
			double fTemp294 = (32768.0 * fVec37[0]);
			int iTemp295 = int(fTemp294);
			double fTemp296 = ftbl0[iTemp295];
			int iTemp297 = (fVec37[1] <= 0.01);
			int iTemp298 = (fVec37[0] > 0.01);
			fRec208[0] = ((fRec208[1] * (1 - (iTemp298 * iTemp297))) + ((fRec19[0] * iTemp298) * iTemp297));
			double fTemp299 = (fConst6 * (fRec208[0] * fVec37[0]));
			int iTemp300 = int(fTemp299);
			int iTemp301 = (1 + iTemp300);
			double fTemp302 = (0.75 + fTemp266);
			double fTemp303 = (fTemp302 - floor(fTemp302));
			fVec38[0] = fTemp303;
			double fTemp304 = (32768.0 * fVec38[0]);
			int iTemp305 = int(fTemp304);
			double fTemp306 = ftbl0[iTemp305];
			int iTemp307 = (fVec38[1] <= 0.01);
			int iTemp308 = (fVec38[0] > 0.01);
			fRec209[0] = ((fRec209[1] * (1 - (iTemp308 * iTemp307))) + ((fRec19[0] * iTemp308) * iTemp307));
			double fTemp309 = (fConst6 * (fRec209[0] * fVec38[0]));
			int iTemp310 = int(fTemp309);
			int iTemp311 = (1 + iTemp310);
			fRec6[0] = (((1 - fRec39[0]) * fTemp276) + ((((fVec35[(IOTA-int((iTemp310 & 262143)))&262143] * (iTemp311 - fTemp309)) + ((fTemp309 - iTemp310) * fVec35[(IOTA-int((int(iTemp311) & 262143)))&262143])) * (fTemp306 + ((fTemp304 - floor(fTemp304)) * (ftbl0[((1 + iTemp305) % 65536)] - fTemp306)))) + (((((fVec35[(IOTA-int((iTemp300 & 262143)))&262143] * (iTemp301 - fTemp299)) + ((fTemp299 - iTemp300) * fVec35[(IOTA-int((int(iTemp301) & 262143)))&262143])) * (fTemp296 + ((fTemp294 - floor(fTemp294)) * (ftbl0[((1 + iTemp295) % 65536)] - fTemp296)))) + (((fVec35[(IOTA-int((iTemp291 & 262143)))&262143] * (iTemp292 - fTemp290)) + ((fTemp290 - iTemp291) * fVec35[(IOTA-int((int(iTemp292) & 262143)))&262143])) * (fTemp287 + ((fTemp285 - floor(fTemp285)) * (ftbl0[((1 + iTemp286) % 65536)] - fTemp287))))) + (((fVec35[(IOTA-int((iTemp281 & 262143)))&262143] * (iTemp282 - fTemp280)) + ((fTemp280 - iTemp281) * fVec35[(IOTA-int((int(iTemp282) & 262143)))&262143])) * (fTemp271 + ((fTemp269 - floor(fTemp269)) * (ftbl0[((1 + iTemp270) % 65536)] - fTemp271)))))));
			fRec211[0] = ((fSlow0 * fRec211[1]) + fSlow154);
			double fTemp312 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec211[0])) - 69))) - 261.625977))) / fTemp1);
			fRec210[0] = fmod((fRec210[1] + (fConst4 * double(fTemp312))),1.0);
			double fTemp313 = ((int((fTemp312 > 0)))?fRec210[0]:(1.0 + fRec210[0]));
			double fTemp314 = (0.5 + fTemp313);
			double fTemp315 = (fTemp314 - floor(fTemp314));
			fVec39[0] = fTemp315;
			double fTemp316 = (32768.0 * fVec39[0]);
			int iTemp317 = int(fTemp316);
			double fTemp318 = ftbl0[iTemp317];
			fRec212[0] = ((fSlow0 * fRec212[1]) + fSlow155);
			fRec213[0] = ((fSlow0 * fRec213[1]) + fSlow156);
			fRec214[0] = ((fSlow0 * fRec214[1]) + fSlow157);
			fRec215[0] = ((fSlow0 * fRec215[1]) + fSlow158);
			fRec216[0] = ((fSlow0 * fRec216[1]) + fSlow159);
			fRec217[0] = ((fSlow0 * fRec217[1]) + fSlow160);
			fRec218[0] = ((fSlow0 * fRec218[1]) + fSlow161);
			fRec219[0] = ((fSlow0 * fRec219[1]) + fSlow162);
			fRec220[0] = ((fSlow0 * fRec220[1]) + fSlow163);
			fRec221[0] = ((fSlow0 * fRec221[1]) + fSlow164);
			fRec222[0] = ((fSlow0 * fRec222[1]) + fSlow165);
			fRec223[0] = ((fSlow0 * fRec223[1]) + fSlow166);
			fRec224[0] = ((fSlow0 * fRec224[1]) + fSlow167);
			fRec225[0] = ((fSlow0 * fRec225[1]) + fSlow168);
			fRec226[0] = ((fSlow0 * fRec226[1]) + fSlow169);
			fRec227[0] = ((fSlow0 * fRec227[1]) + fSlow170);
			fRec228[0] = ((fSlow0 * fRec228[1]) + fSlow171);
			double fTemp319 = ((((fRec71[0] * fRec228[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec227[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec226[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec225[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec224[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec223[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec222[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec221[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec220[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec219[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec218[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec217[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec216[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec215[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec214[0]) * fRec2[1]) * fTemp10) + (((double)input6[i] * fRec213[0]) + (((fRec25[0] * fRec212[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec40[IOTA&2097151] = fTemp319;
			fRec230[0] = ((fSlow0 * fRec230[1]) + fSlow172);
			fRec229[0] = ((iTemp34 * fRec229[1]) + ((fRec230[0] * iTemp33) * iTemp32));
			fRec231[0] = ((iTemp37 * fRec231[1]) + ((fRec230[0] * iTemp36) * iTemp35));
			double fTemp320 = ((0.5 * (fVec3[0] * fVec40[(IOTA-int((int(fRec231[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec40[(IOTA-int((int(fRec229[0]) & 2097151)))&2097151]));
			int iTemp321 = (fTemp320 < -1);
			int iTemp322 = (fTemp320 > 1);
			double fTemp323 = ((iTemp322 + ((fTemp320 * (1 - iTemp321)) * (1 - iTemp322))) - iTemp321);
			double fTemp324 = (fRec42[0] * fTemp323);
			fVec41[IOTA&262143] = fTemp324;
			int iTemp325 = (fVec39[1] <= 0.01);
			int iTemp326 = (fVec39[0] > 0.01);
			fRec232[0] = ((fRec232[1] * (1 - (iTemp326 * iTemp325))) + ((fRec19[0] * iTemp326) * iTemp325));
			double fTemp327 = (fConst6 * (fRec232[0] * fVec39[0]));
			int iTemp328 = int(fTemp327);
			int iTemp329 = (1 + iTemp328);
			double fTemp330 = (0.25 + fTemp313);
			double fTemp331 = (fTemp330 - floor(fTemp330));
			fVec42[0] = fTemp331;
			double fTemp332 = (32768.0 * fVec42[0]);
			int iTemp333 = int(fTemp332);
			double fTemp334 = ftbl0[iTemp333];
			int iTemp335 = (fVec42[1] <= 0.01);
			int iTemp336 = (fVec42[0] > 0.01);
			fRec233[0] = ((fRec233[1] * (1 - (iTemp336 * iTemp335))) + ((fRec19[0] * iTemp336) * iTemp335));
			double fTemp337 = (fConst6 * (fRec233[0] * fVec42[0]));
			int iTemp338 = int(fTemp337);
			int iTemp339 = (1 + iTemp338);
			double fTemp340 = (fTemp313 - floor(fTemp313));
			fVec43[0] = fTemp340;
			double fTemp341 = (32768.0 * fVec43[0]);
			int iTemp342 = int(fTemp341);
			double fTemp343 = ftbl0[iTemp342];
			int iTemp344 = (fVec43[1] <= 0.01);
			int iTemp345 = (fVec43[0] > 0.01);
			fRec234[0] = ((fRec234[1] * (1 - (iTemp345 * iTemp344))) + ((fRec19[0] * iTemp345) * iTemp344));
			double fTemp346 = (fConst6 * (fRec234[0] * fVec43[0]));
			int iTemp347 = int(fTemp346);
			int iTemp348 = (1 + iTemp347);
			double fTemp349 = (0.75 + fTemp313);
			double fTemp350 = (fTemp349 - floor(fTemp349));
			fVec44[0] = fTemp350;
			double fTemp351 = (32768.0 * fVec44[0]);
			int iTemp352 = int(fTemp351);
			double fTemp353 = ftbl0[iTemp352];
			int iTemp354 = (fVec44[1] <= 0.01);
			int iTemp355 = (fVec44[0] > 0.01);
			fRec235[0] = ((fRec235[1] * (1 - (iTemp355 * iTemp354))) + ((fRec19[0] * iTemp355) * iTemp354));
			double fTemp356 = (fConst6 * (fRec235[0] * fVec44[0]));
			int iTemp357 = int(fTemp356);
			int iTemp358 = (1 + iTemp357);
			fRec7[0] = (((1 - fRec42[0]) * fTemp323) + ((((fVec41[(IOTA-int((iTemp357 & 262143)))&262143] * (iTemp358 - fTemp356)) + ((fTemp356 - iTemp357) * fVec41[(IOTA-int((int(iTemp358) & 262143)))&262143])) * (fTemp353 + ((fTemp351 - floor(fTemp351)) * (ftbl0[((1 + iTemp352) % 65536)] - fTemp353)))) + (((((fVec41[(IOTA-int((iTemp347 & 262143)))&262143] * (iTemp348 - fTemp346)) + ((fTemp346 - iTemp347) * fVec41[(IOTA-int((int(iTemp348) & 262143)))&262143])) * (fTemp343 + ((fTemp341 - floor(fTemp341)) * (ftbl0[((1 + iTemp342) % 65536)] - fTemp343)))) + (((fVec41[(IOTA-int((iTemp338 & 262143)))&262143] * (iTemp339 - fTemp337)) + ((fTemp337 - iTemp338) * fVec41[(IOTA-int((int(iTemp339) & 262143)))&262143])) * (fTemp334 + ((fTemp332 - floor(fTemp332)) * (ftbl0[((1 + iTemp333) % 65536)] - fTemp334))))) + (((fVec41[(IOTA-int((iTemp328 & 262143)))&262143] * (iTemp329 - fTemp327)) + ((fTemp327 - iTemp328) * fVec41[(IOTA-int((int(iTemp329) & 262143)))&262143])) * (fTemp318 + ((fTemp316 - floor(fTemp316)) * (ftbl0[((1 + iTemp317) % 65536)] - fTemp318)))))));
			fRec237[0] = ((fSlow0 * fRec237[1]) + fSlow173);
			double fTemp359 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec237[0])) - 69))) - 261.625977))) / fTemp1);
			fRec236[0] = fmod((fRec236[1] + (fConst4 * double(fTemp359))),1.0);
			double fTemp360 = ((int((fTemp359 > 0)))?fRec236[0]:(1.0 + fRec236[0]));
			double fTemp361 = (0.5 + fTemp360);
			double fTemp362 = (fTemp361 - floor(fTemp361));
			fVec45[0] = fTemp362;
			double fTemp363 = (32768.0 * fVec45[0]);
			int iTemp364 = int(fTemp363);
			double fTemp365 = ftbl0[iTemp364];
			fRec238[0] = ((fSlow0 * fRec238[1]) + fSlow174);
			fRec239[0] = ((fSlow0 * fRec239[1]) + fSlow175);
			fRec240[0] = ((fSlow0 * fRec240[1]) + fSlow176);
			fRec241[0] = ((fSlow0 * fRec241[1]) + fSlow177);
			fRec242[0] = ((fSlow0 * fRec242[1]) + fSlow178);
			fRec243[0] = ((fSlow0 * fRec243[1]) + fSlow179);
			fRec244[0] = ((fSlow0 * fRec244[1]) + fSlow180);
			fRec245[0] = ((fSlow0 * fRec245[1]) + fSlow181);
			fRec246[0] = ((fSlow0 * fRec246[1]) + fSlow182);
			fRec247[0] = ((fSlow0 * fRec247[1]) + fSlow183);
			fRec248[0] = ((fSlow0 * fRec248[1]) + fSlow184);
			fRec249[0] = ((fSlow0 * fRec249[1]) + fSlow185);
			fRec250[0] = ((fSlow0 * fRec250[1]) + fSlow186);
			fRec251[0] = ((fSlow0 * fRec251[1]) + fSlow187);
			fRec252[0] = ((fSlow0 * fRec252[1]) + fSlow188);
			fRec253[0] = ((fSlow0 * fRec253[1]) + fSlow189);
			fRec254[0] = ((fSlow0 * fRec254[1]) + fSlow190);
			double fTemp366 = ((((fRec71[0] * fRec254[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec253[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec252[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec251[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec250[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec249[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec248[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec247[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec246[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec245[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec244[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec243[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec242[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec241[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec240[0]) * fRec2[1]) * fTemp10) + (((double)input7[i] * fRec239[0]) + (((fRec25[0] * fRec238[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec46[IOTA&2097151] = fTemp366;
			fRec256[0] = ((fSlow0 * fRec256[1]) + fSlow191);
			fRec255[0] = ((iTemp34 * fRec255[1]) + ((fRec256[0] * iTemp33) * iTemp32));
			fRec257[0] = ((iTemp37 * fRec257[1]) + ((fRec256[0] * iTemp36) * iTemp35));
			double fTemp367 = ((0.5 * (fVec3[0] * fVec46[(IOTA-int((int(fRec257[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec46[(IOTA-int((int(fRec255[0]) & 2097151)))&2097151]));
			int iTemp368 = (fTemp367 < -1);
			int iTemp369 = (fTemp367 > 1);
			double fTemp370 = ((iTemp369 + ((fTemp367 * (1 - iTemp368)) * (1 - iTemp369))) - iTemp368);
			double fTemp371 = (fRec45[0] * fTemp370);
			fVec47[IOTA&262143] = fTemp371;
			int iTemp372 = (fVec45[1] <= 0.01);
			int iTemp373 = (fVec45[0] > 0.01);
			fRec258[0] = ((fRec258[1] * (1 - (iTemp373 * iTemp372))) + ((fRec19[0] * iTemp373) * iTemp372));
			double fTemp374 = (fConst6 * (fRec258[0] * fVec45[0]));
			int iTemp375 = int(fTemp374);
			int iTemp376 = (1 + iTemp375);
			double fTemp377 = (0.25 + fTemp360);
			double fTemp378 = (fTemp377 - floor(fTemp377));
			fVec48[0] = fTemp378;
			double fTemp379 = (32768.0 * fVec48[0]);
			int iTemp380 = int(fTemp379);
			double fTemp381 = ftbl0[iTemp380];
			int iTemp382 = (fVec48[1] <= 0.01);
			int iTemp383 = (fVec48[0] > 0.01);
			fRec259[0] = ((fRec259[1] * (1 - (iTemp383 * iTemp382))) + ((fRec19[0] * iTemp383) * iTemp382));
			double fTemp384 = (fConst6 * (fRec259[0] * fVec48[0]));
			int iTemp385 = int(fTemp384);
			int iTemp386 = (1 + iTemp385);
			double fTemp387 = (fTemp360 - floor(fTemp360));
			fVec49[0] = fTemp387;
			double fTemp388 = (32768.0 * fVec49[0]);
			int iTemp389 = int(fTemp388);
			double fTemp390 = ftbl0[iTemp389];
			int iTemp391 = (fVec49[1] <= 0.01);
			int iTemp392 = (fVec49[0] > 0.01);
			fRec260[0] = ((fRec260[1] * (1 - (iTemp392 * iTemp391))) + ((fRec19[0] * iTemp392) * iTemp391));
			double fTemp393 = (fConst6 * (fRec260[0] * fVec49[0]));
			int iTemp394 = int(fTemp393);
			int iTemp395 = (1 + iTemp394);
			double fTemp396 = (0.75 + fTemp360);
			double fTemp397 = (fTemp396 - floor(fTemp396));
			fVec50[0] = fTemp397;
			double fTemp398 = (32768.0 * fVec50[0]);
			int iTemp399 = int(fTemp398);
			double fTemp400 = ftbl0[iTemp399];
			int iTemp401 = (fVec50[1] <= 0.01);
			int iTemp402 = (fVec50[0] > 0.01);
			fRec261[0] = ((fRec261[1] * (1 - (iTemp402 * iTemp401))) + ((fRec19[0] * iTemp402) * iTemp401));
			double fTemp403 = (fConst6 * (fRec261[0] * fVec50[0]));
			int iTemp404 = int(fTemp403);
			int iTemp405 = (1 + iTemp404);
			fRec8[0] = (((1 - fRec45[0]) * fTemp370) + ((((fVec47[(IOTA-int((iTemp404 & 262143)))&262143] * (iTemp405 - fTemp403)) + ((fTemp403 - iTemp404) * fVec47[(IOTA-int((int(iTemp405) & 262143)))&262143])) * (fTemp400 + ((fTemp398 - floor(fTemp398)) * (ftbl0[((1 + iTemp399) % 65536)] - fTemp400)))) + (((((fVec47[(IOTA-int((iTemp394 & 262143)))&262143] * (iTemp395 - fTemp393)) + ((fTemp393 - iTemp394) * fVec47[(IOTA-int((int(iTemp395) & 262143)))&262143])) * (fTemp390 + ((fTemp388 - floor(fTemp388)) * (ftbl0[((1 + iTemp389) % 65536)] - fTemp390)))) + (((fVec47[(IOTA-int((iTemp385 & 262143)))&262143] * (iTemp386 - fTemp384)) + ((fTemp384 - iTemp385) * fVec47[(IOTA-int((int(iTemp386) & 262143)))&262143])) * (fTemp381 + ((fTemp379 - floor(fTemp379)) * (ftbl0[((1 + iTemp380) % 65536)] - fTemp381))))) + (((fVec47[(IOTA-int((iTemp375 & 262143)))&262143] * (iTemp376 - fTemp374)) + ((fTemp374 - iTemp375) * fVec47[(IOTA-int((int(iTemp376) & 262143)))&262143])) * (fTemp365 + ((fTemp363 - floor(fTemp363)) * (ftbl0[((1 + iTemp364) % 65536)] - fTemp365)))))));
			fRec263[0] = ((fSlow0 * fRec263[1]) + fSlow192);
			double fTemp406 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec263[0])) - 69))) - 261.625977))) / fTemp1);
			fRec262[0] = fmod((fRec262[1] + (fConst4 * double(fTemp406))),1.0);
			double fTemp407 = ((int((fTemp406 > 0)))?fRec262[0]:(1.0 + fRec262[0]));
			double fTemp408 = (0.5 + fTemp407);
			double fTemp409 = (fTemp408 - floor(fTemp408));
			fVec51[0] = fTemp409;
			double fTemp410 = (32768.0 * fVec51[0]);
			int iTemp411 = int(fTemp410);
			double fTemp412 = ftbl0[iTemp411];
			fRec264[0] = ((fSlow0 * fRec264[1]) + fSlow193);
			fRec265[0] = ((fSlow0 * fRec265[1]) + fSlow194);
			fRec266[0] = ((fSlow0 * fRec266[1]) + fSlow195);
			fRec267[0] = ((fSlow0 * fRec267[1]) + fSlow196);
			fRec268[0] = ((fSlow0 * fRec268[1]) + fSlow197);
			fRec269[0] = ((fSlow0 * fRec269[1]) + fSlow198);
			fRec270[0] = ((fSlow0 * fRec270[1]) + fSlow199);
			fRec271[0] = ((fSlow0 * fRec271[1]) + fSlow200);
			fRec272[0] = ((fSlow0 * fRec272[1]) + fSlow201);
			fRec273[0] = ((fSlow0 * fRec273[1]) + fSlow202);
			fRec274[0] = ((fSlow0 * fRec274[1]) + fSlow203);
			fRec275[0] = ((fSlow0 * fRec275[1]) + fSlow204);
			fRec276[0] = ((fSlow0 * fRec276[1]) + fSlow205);
			fRec277[0] = ((fSlow0 * fRec277[1]) + fSlow206);
			fRec278[0] = ((fSlow0 * fRec278[1]) + fSlow207);
			fRec279[0] = ((fSlow0 * fRec279[1]) + fSlow208);
			fRec280[0] = ((fSlow0 * fRec280[1]) + fSlow209);
			double fTemp413 = ((((fRec71[0] * fRec280[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec279[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec278[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec277[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec276[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec275[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec274[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec273[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec272[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec271[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec270[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec269[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec268[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec267[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec266[0]) * fRec2[1]) * fTemp10) + (((double)input8[i] * fRec265[0]) + (((fRec25[0] * fRec264[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec52[IOTA&2097151] = fTemp413;
			fRec282[0] = ((fSlow0 * fRec282[1]) + fSlow210);
			fRec281[0] = ((iTemp34 * fRec281[1]) + ((fRec282[0] * iTemp33) * iTemp32));
			fRec283[0] = ((iTemp37 * fRec283[1]) + ((fRec282[0] * iTemp36) * iTemp35));
			double fTemp414 = ((0.5 * (fVec3[0] * fVec52[(IOTA-int((int(fRec283[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec52[(IOTA-int((int(fRec281[0]) & 2097151)))&2097151]));
			int iTemp415 = (fTemp414 < -1);
			int iTemp416 = (fTemp414 > 1);
			double fTemp417 = ((iTemp416 + ((fTemp414 * (1 - iTemp415)) * (1 - iTemp416))) - iTemp415);
			double fTemp418 = (fRec48[0] * fTemp417);
			fVec53[IOTA&262143] = fTemp418;
			int iTemp419 = (fVec51[1] <= 0.01);
			int iTemp420 = (fVec51[0] > 0.01);
			fRec284[0] = ((fRec284[1] * (1 - (iTemp420 * iTemp419))) + ((fRec19[0] * iTemp420) * iTemp419));
			double fTemp421 = (fConst6 * (fRec284[0] * fVec51[0]));
			int iTemp422 = int(fTemp421);
			int iTemp423 = (1 + iTemp422);
			double fTemp424 = (0.25 + fTemp407);
			double fTemp425 = (fTemp424 - floor(fTemp424));
			fVec54[0] = fTemp425;
			double fTemp426 = (32768.0 * fVec54[0]);
			int iTemp427 = int(fTemp426);
			double fTemp428 = ftbl0[iTemp427];
			int iTemp429 = (fVec54[1] <= 0.01);
			int iTemp430 = (fVec54[0] > 0.01);
			fRec285[0] = ((fRec285[1] * (1 - (iTemp430 * iTemp429))) + ((fRec19[0] * iTemp430) * iTemp429));
			double fTemp431 = (fConst6 * (fRec285[0] * fVec54[0]));
			int iTemp432 = int(fTemp431);
			int iTemp433 = (1 + iTemp432);
			double fTemp434 = (fTemp407 - floor(fTemp407));
			fVec55[0] = fTemp434;
			double fTemp435 = (32768.0 * fVec55[0]);
			int iTemp436 = int(fTemp435);
			double fTemp437 = ftbl0[iTemp436];
			int iTemp438 = (fVec55[1] <= 0.01);
			int iTemp439 = (fVec55[0] > 0.01);
			fRec286[0] = ((fRec286[1] * (1 - (iTemp439 * iTemp438))) + ((fRec19[0] * iTemp439) * iTemp438));
			double fTemp440 = (fConst6 * (fRec286[0] * fVec55[0]));
			int iTemp441 = int(fTemp440);
			int iTemp442 = (1 + iTemp441);
			double fTemp443 = (0.75 + fTemp407);
			double fTemp444 = (fTemp443 - floor(fTemp443));
			fVec56[0] = fTemp444;
			double fTemp445 = (32768.0 * fVec56[0]);
			int iTemp446 = int(fTemp445);
			double fTemp447 = ftbl0[iTemp446];
			int iTemp448 = (fVec56[1] <= 0.01);
			int iTemp449 = (fVec56[0] > 0.01);
			fRec287[0] = ((fRec287[1] * (1 - (iTemp449 * iTemp448))) + ((fRec19[0] * iTemp449) * iTemp448));
			double fTemp450 = (fConst6 * (fRec287[0] * fVec56[0]));
			int iTemp451 = int(fTemp450);
			int iTemp452 = (1 + iTemp451);
			fRec9[0] = (((1 - fRec48[0]) * fTemp417) + ((((fVec53[(IOTA-int((iTemp451 & 262143)))&262143] * (iTemp452 - fTemp450)) + ((fTemp450 - iTemp451) * fVec53[(IOTA-int((int(iTemp452) & 262143)))&262143])) * (fTemp447 + ((fTemp445 - floor(fTemp445)) * (ftbl0[((1 + iTemp446) % 65536)] - fTemp447)))) + (((((fVec53[(IOTA-int((iTemp441 & 262143)))&262143] * (iTemp442 - fTemp440)) + ((fTemp440 - iTemp441) * fVec53[(IOTA-int((int(iTemp442) & 262143)))&262143])) * (fTemp437 + ((fTemp435 - floor(fTemp435)) * (ftbl0[((1 + iTemp436) % 65536)] - fTemp437)))) + (((fVec53[(IOTA-int((iTemp432 & 262143)))&262143] * (iTemp433 - fTemp431)) + ((fTemp431 - iTemp432) * fVec53[(IOTA-int((int(iTemp433) & 262143)))&262143])) * (fTemp428 + ((fTemp426 - floor(fTemp426)) * (ftbl0[((1 + iTemp427) % 65536)] - fTemp428))))) + (((fVec53[(IOTA-int((iTemp422 & 262143)))&262143] * (iTemp423 - fTemp421)) + ((fTemp421 - iTemp422) * fVec53[(IOTA-int((int(iTemp423) & 262143)))&262143])) * (fTemp412 + ((fTemp410 - floor(fTemp410)) * (ftbl0[((1 + iTemp411) % 65536)] - fTemp412)))))));
			fRec289[0] = ((fSlow0 * fRec289[1]) + fSlow211);
			double fTemp453 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec289[0])) - 69))) - 261.625977))) / fTemp1);
			fRec288[0] = fmod((fRec288[1] + (fConst4 * double(fTemp453))),1.0);
			double fTemp454 = ((int((fTemp453 > 0)))?fRec288[0]:(1.0 + fRec288[0]));
			double fTemp455 = (0.5 + fTemp454);
			double fTemp456 = (fTemp455 - floor(fTemp455));
			fVec57[0] = fTemp456;
			double fTemp457 = (32768.0 * fVec57[0]);
			int iTemp458 = int(fTemp457);
			double fTemp459 = ftbl0[iTemp458];
			fRec290[0] = ((fSlow0 * fRec290[1]) + fSlow212);
			fRec291[0] = ((fSlow0 * fRec291[1]) + fSlow213);
			fRec292[0] = ((fSlow0 * fRec292[1]) + fSlow214);
			fRec293[0] = ((fSlow0 * fRec293[1]) + fSlow215);
			fRec294[0] = ((fSlow0 * fRec294[1]) + fSlow216);
			fRec295[0] = ((fSlow0 * fRec295[1]) + fSlow217);
			fRec296[0] = ((fSlow0 * fRec296[1]) + fSlow218);
			fRec297[0] = ((fSlow0 * fRec297[1]) + fSlow219);
			fRec298[0] = ((fSlow0 * fRec298[1]) + fSlow220);
			fRec299[0] = ((fSlow0 * fRec299[1]) + fSlow221);
			fRec300[0] = ((fSlow0 * fRec300[1]) + fSlow222);
			fRec301[0] = ((fSlow0 * fRec301[1]) + fSlow223);
			fRec302[0] = ((fSlow0 * fRec302[1]) + fSlow224);
			fRec303[0] = ((fSlow0 * fRec303[1]) + fSlow225);
			fRec304[0] = ((fSlow0 * fRec304[1]) + fSlow226);
			fRec305[0] = ((fSlow0 * fRec305[1]) + fSlow227);
			fRec306[0] = ((fSlow0 * fRec306[1]) + fSlow228);
			double fTemp460 = ((((fRec71[0] * fRec306[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec305[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec304[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec303[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec302[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec301[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec300[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec299[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec298[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec297[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec296[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec295[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec294[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec293[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec292[0]) * fRec2[1]) * fTemp10) + (((double)input9[i] * fRec291[0]) + (((fRec25[0] * fRec290[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec58[IOTA&2097151] = fTemp460;
			fRec308[0] = ((fSlow0 * fRec308[1]) + fSlow229);
			fRec307[0] = ((iTemp34 * fRec307[1]) + ((fRec308[0] * iTemp33) * iTemp32));
			fRec309[0] = ((iTemp37 * fRec309[1]) + ((fRec308[0] * iTemp36) * iTemp35));
			double fTemp461 = ((0.5 * (fVec3[0] * fVec58[(IOTA-int((int(fRec309[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec58[(IOTA-int((int(fRec307[0]) & 2097151)))&2097151]));
			int iTemp462 = (fTemp461 < -1);
			int iTemp463 = (fTemp461 > 1);
			double fTemp464 = ((iTemp463 + ((fTemp461 * (1 - iTemp462)) * (1 - iTemp463))) - iTemp462);
			double fTemp465 = (fRec51[0] * fTemp464);
			fVec59[IOTA&262143] = fTemp465;
			int iTemp466 = (fVec57[1] <= 0.01);
			int iTemp467 = (fVec57[0] > 0.01);
			fRec310[0] = ((fRec310[1] * (1 - (iTemp467 * iTemp466))) + ((fRec19[0] * iTemp467) * iTemp466));
			double fTemp468 = (fConst6 * (fRec310[0] * fVec57[0]));
			int iTemp469 = int(fTemp468);
			int iTemp470 = (1 + iTemp469);
			double fTemp471 = (0.25 + fTemp454);
			double fTemp472 = (fTemp471 - floor(fTemp471));
			fVec60[0] = fTemp472;
			double fTemp473 = (32768.0 * fVec60[0]);
			int iTemp474 = int(fTemp473);
			double fTemp475 = ftbl0[iTemp474];
			int iTemp476 = (fVec60[1] <= 0.01);
			int iTemp477 = (fVec60[0] > 0.01);
			fRec311[0] = ((fRec311[1] * (1 - (iTemp477 * iTemp476))) + ((fRec19[0] * iTemp477) * iTemp476));
			double fTemp478 = (fConst6 * (fRec311[0] * fVec60[0]));
			int iTemp479 = int(fTemp478);
			int iTemp480 = (1 + iTemp479);
			double fTemp481 = (fTemp454 - floor(fTemp454));
			fVec61[0] = fTemp481;
			double fTemp482 = (32768.0 * fVec61[0]);
			int iTemp483 = int(fTemp482);
			double fTemp484 = ftbl0[iTemp483];
			int iTemp485 = (fVec61[1] <= 0.01);
			int iTemp486 = (fVec61[0] > 0.01);
			fRec312[0] = ((fRec312[1] * (1 - (iTemp486 * iTemp485))) + ((fRec19[0] * iTemp486) * iTemp485));
			double fTemp487 = (fConst6 * (fRec312[0] * fVec61[0]));
			int iTemp488 = int(fTemp487);
			int iTemp489 = (1 + iTemp488);
			double fTemp490 = (0.75 + fTemp454);
			double fTemp491 = (fTemp490 - floor(fTemp490));
			fVec62[0] = fTemp491;
			double fTemp492 = (32768.0 * fVec62[0]);
			int iTemp493 = int(fTemp492);
			double fTemp494 = ftbl0[iTemp493];
			int iTemp495 = (fVec62[1] <= 0.01);
			int iTemp496 = (fVec62[0] > 0.01);
			fRec313[0] = ((fRec313[1] * (1 - (iTemp496 * iTemp495))) + ((fRec19[0] * iTemp496) * iTemp495));
			double fTemp497 = (fConst6 * (fRec313[0] * fVec62[0]));
			int iTemp498 = int(fTemp497);
			int iTemp499 = (1 + iTemp498);
			fRec10[0] = (((1 - fRec51[0]) * fTemp464) + ((((fVec59[(IOTA-int((iTemp498 & 262143)))&262143] * (iTemp499 - fTemp497)) + ((fTemp497 - iTemp498) * fVec59[(IOTA-int((int(iTemp499) & 262143)))&262143])) * (fTemp494 + ((fTemp492 - floor(fTemp492)) * (ftbl0[((1 + iTemp493) % 65536)] - fTemp494)))) + (((((fVec59[(IOTA-int((iTemp488 & 262143)))&262143] * (iTemp489 - fTemp487)) + ((fTemp487 - iTemp488) * fVec59[(IOTA-int((int(iTemp489) & 262143)))&262143])) * (fTemp484 + ((fTemp482 - floor(fTemp482)) * (ftbl0[((1 + iTemp483) % 65536)] - fTemp484)))) + (((fVec59[(IOTA-int((iTemp479 & 262143)))&262143] * (iTemp480 - fTemp478)) + ((fTemp478 - iTemp479) * fVec59[(IOTA-int((int(iTemp480) & 262143)))&262143])) * (fTemp475 + ((fTemp473 - floor(fTemp473)) * (ftbl0[((1 + iTemp474) % 65536)] - fTemp475))))) + (((fVec59[(IOTA-int((iTemp469 & 262143)))&262143] * (iTemp470 - fTemp468)) + ((fTemp468 - iTemp469) * fVec59[(IOTA-int((int(iTemp470) & 262143)))&262143])) * (fTemp459 + ((fTemp457 - floor(fTemp457)) * (ftbl0[((1 + iTemp458) % 65536)] - fTemp459)))))));
			fRec315[0] = ((fSlow0 * fRec315[1]) + fSlow230);
			double fTemp500 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec315[0])) - 69))) - 261.625977))) / fTemp1);
			fRec314[0] = fmod((fRec314[1] + (fConst4 * double(fTemp500))),1.0);
			double fTemp501 = ((int((fTemp500 > 0)))?fRec314[0]:(1.0 + fRec314[0]));
			double fTemp502 = (0.5 + fTemp501);
			double fTemp503 = (fTemp502 - floor(fTemp502));
			fVec63[0] = fTemp503;
			double fTemp504 = (32768.0 * fVec63[0]);
			int iTemp505 = int(fTemp504);
			double fTemp506 = ftbl0[iTemp505];
			fRec316[0] = ((fSlow0 * fRec316[1]) + fSlow231);
			fRec317[0] = ((fSlow0 * fRec317[1]) + fSlow232);
			fRec318[0] = ((fSlow0 * fRec318[1]) + fSlow233);
			fRec319[0] = ((fSlow0 * fRec319[1]) + fSlow234);
			fRec320[0] = ((fSlow0 * fRec320[1]) + fSlow235);
			fRec321[0] = ((fSlow0 * fRec321[1]) + fSlow236);
			fRec322[0] = ((fSlow0 * fRec322[1]) + fSlow237);
			fRec323[0] = ((fSlow0 * fRec323[1]) + fSlow238);
			fRec324[0] = ((fSlow0 * fRec324[1]) + fSlow239);
			fRec325[0] = ((fSlow0 * fRec325[1]) + fSlow240);
			fRec326[0] = ((fSlow0 * fRec326[1]) + fSlow241);
			fRec327[0] = ((fSlow0 * fRec327[1]) + fSlow242);
			fRec328[0] = ((fSlow0 * fRec328[1]) + fSlow243);
			fRec329[0] = ((fSlow0 * fRec329[1]) + fSlow244);
			fRec330[0] = ((fSlow0 * fRec330[1]) + fSlow245);
			fRec331[0] = ((fSlow0 * fRec331[1]) + fSlow246);
			fRec332[0] = ((fSlow0 * fRec332[1]) + fSlow247);
			double fTemp507 = ((((fRec71[0] * fRec332[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec331[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec330[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec329[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec328[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec327[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec326[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec325[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec324[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec323[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec322[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec321[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec320[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec319[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec318[0]) * fRec2[1]) * fTemp10) + (((double)input10[i] * fRec317[0]) + (((fRec25[0] * fRec316[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec64[IOTA&2097151] = fTemp507;
			fRec334[0] = ((fSlow0 * fRec334[1]) + fSlow248);
			fRec333[0] = ((iTemp34 * fRec333[1]) + ((fRec334[0] * iTemp33) * iTemp32));
			fRec335[0] = ((iTemp37 * fRec335[1]) + ((fRec334[0] * iTemp36) * iTemp35));
			double fTemp508 = ((0.5 * (fVec3[0] * fVec64[(IOTA-int((int(fRec335[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec64[(IOTA-int((int(fRec333[0]) & 2097151)))&2097151]));
			int iTemp509 = (fTemp508 < -1);
			int iTemp510 = (fTemp508 > 1);
			double fTemp511 = ((iTemp510 + ((fTemp508 * (1 - iTemp509)) * (1 - iTemp510))) - iTemp509);
			double fTemp512 = (fRec54[0] * fTemp511);
			fVec65[IOTA&262143] = fTemp512;
			int iTemp513 = (fVec63[1] <= 0.01);
			int iTemp514 = (fVec63[0] > 0.01);
			fRec336[0] = ((fRec336[1] * (1 - (iTemp514 * iTemp513))) + ((fRec19[0] * iTemp514) * iTemp513));
			double fTemp515 = (fConst6 * (fRec336[0] * fVec63[0]));
			int iTemp516 = int(fTemp515);
			int iTemp517 = (1 + iTemp516);
			double fTemp518 = (0.25 + fTemp501);
			double fTemp519 = (fTemp518 - floor(fTemp518));
			fVec66[0] = fTemp519;
			double fTemp520 = (32768.0 * fVec66[0]);
			int iTemp521 = int(fTemp520);
			double fTemp522 = ftbl0[iTemp521];
			int iTemp523 = (fVec66[1] <= 0.01);
			int iTemp524 = (fVec66[0] > 0.01);
			fRec337[0] = ((fRec337[1] * (1 - (iTemp524 * iTemp523))) + ((fRec19[0] * iTemp524) * iTemp523));
			double fTemp525 = (fConst6 * (fRec337[0] * fVec66[0]));
			int iTemp526 = int(fTemp525);
			int iTemp527 = (1 + iTemp526);
			double fTemp528 = (fTemp501 - floor(fTemp501));
			fVec67[0] = fTemp528;
			double fTemp529 = (32768.0 * fVec67[0]);
			int iTemp530 = int(fTemp529);
			double fTemp531 = ftbl0[iTemp530];
			int iTemp532 = (fVec67[1] <= 0.01);
			int iTemp533 = (fVec67[0] > 0.01);
			fRec338[0] = ((fRec338[1] * (1 - (iTemp533 * iTemp532))) + ((fRec19[0] * iTemp533) * iTemp532));
			double fTemp534 = (fConst6 * (fRec338[0] * fVec67[0]));
			int iTemp535 = int(fTemp534);
			int iTemp536 = (1 + iTemp535);
			double fTemp537 = (0.75 + fTemp501);
			double fTemp538 = (fTemp537 - floor(fTemp537));
			fVec68[0] = fTemp538;
			double fTemp539 = (32768.0 * fVec68[0]);
			int iTemp540 = int(fTemp539);
			double fTemp541 = ftbl0[iTemp540];
			int iTemp542 = (fVec68[1] <= 0.01);
			int iTemp543 = (fVec68[0] > 0.01);
			fRec339[0] = ((fRec339[1] * (1 - (iTemp543 * iTemp542))) + ((fRec19[0] * iTemp543) * iTemp542));
			double fTemp544 = (fConst6 * (fRec339[0] * fVec68[0]));
			int iTemp545 = int(fTemp544);
			int iTemp546 = (1 + iTemp545);
			fRec11[0] = (((1 - fRec54[0]) * fTemp511) + ((((fVec65[(IOTA-int((iTemp545 & 262143)))&262143] * (iTemp546 - fTemp544)) + ((fTemp544 - iTemp545) * fVec65[(IOTA-int((int(iTemp546) & 262143)))&262143])) * (fTemp541 + ((fTemp539 - floor(fTemp539)) * (ftbl0[((1 + iTemp540) % 65536)] - fTemp541)))) + (((((fVec65[(IOTA-int((iTemp535 & 262143)))&262143] * (iTemp536 - fTemp534)) + ((fTemp534 - iTemp535) * fVec65[(IOTA-int((int(iTemp536) & 262143)))&262143])) * (fTemp531 + ((fTemp529 - floor(fTemp529)) * (ftbl0[((1 + iTemp530) % 65536)] - fTemp531)))) + (((fVec65[(IOTA-int((iTemp526 & 262143)))&262143] * (iTemp527 - fTemp525)) + ((fTemp525 - iTemp526) * fVec65[(IOTA-int((int(iTemp527) & 262143)))&262143])) * (fTemp522 + ((fTemp520 - floor(fTemp520)) * (ftbl0[((1 + iTemp521) % 65536)] - fTemp522))))) + (((fVec65[(IOTA-int((iTemp516 & 262143)))&262143] * (iTemp517 - fTemp515)) + ((fTemp515 - iTemp516) * fVec65[(IOTA-int((int(iTemp517) & 262143)))&262143])) * (fTemp506 + ((fTemp504 - floor(fTemp504)) * (ftbl0[((1 + iTemp505) % 65536)] - fTemp506)))))));
			fRec341[0] = ((fSlow0 * fRec341[1]) + fSlow249);
			double fTemp547 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec341[0])) - 69))) - 261.625977))) / fTemp1);
			fRec340[0] = fmod((fRec340[1] + (fConst4 * double(fTemp547))),1.0);
			double fTemp548 = ((int((fTemp547 > 0)))?fRec340[0]:(1.0 + fRec340[0]));
			double fTemp549 = (0.5 + fTemp548);
			double fTemp550 = (fTemp549 - floor(fTemp549));
			fVec69[0] = fTemp550;
			double fTemp551 = (32768.0 * fVec69[0]);
			int iTemp552 = int(fTemp551);
			double fTemp553 = ftbl0[iTemp552];
			fRec342[0] = ((fSlow0 * fRec342[1]) + fSlow250);
			fRec343[0] = ((fSlow0 * fRec343[1]) + fSlow251);
			fRec344[0] = ((fSlow0 * fRec344[1]) + fSlow252);
			fRec345[0] = ((fSlow0 * fRec345[1]) + fSlow253);
			fRec346[0] = ((fSlow0 * fRec346[1]) + fSlow254);
			fRec347[0] = ((fSlow0 * fRec347[1]) + fSlow255);
			fRec348[0] = ((fSlow0 * fRec348[1]) + fSlow256);
			fRec349[0] = ((fSlow0 * fRec349[1]) + fSlow257);
			fRec350[0] = ((fSlow0 * fRec350[1]) + fSlow258);
			fRec351[0] = ((fSlow0 * fRec351[1]) + fSlow259);
			fRec352[0] = ((fSlow0 * fRec352[1]) + fSlow260);
			fRec353[0] = ((fSlow0 * fRec353[1]) + fSlow261);
			fRec354[0] = ((fSlow0 * fRec354[1]) + fSlow262);
			fRec355[0] = ((fSlow0 * fRec355[1]) + fSlow263);
			fRec356[0] = ((fSlow0 * fRec356[1]) + fSlow264);
			fRec357[0] = ((fSlow0 * fRec357[1]) + fSlow265);
			fRec358[0] = ((fSlow0 * fRec358[1]) + fSlow266);
			double fTemp554 = ((((fRec71[0] * fRec358[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec357[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec356[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec355[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec354[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec353[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec352[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec351[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec350[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec349[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec348[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec347[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec346[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec345[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec344[0]) * fRec2[1]) * fTemp10) + (((double)input11[i] * fRec343[0]) + (((fRec25[0] * fRec342[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec70[IOTA&2097151] = fTemp554;
			fRec360[0] = ((fSlow0 * fRec360[1]) + fSlow267);
			fRec359[0] = ((iTemp34 * fRec359[1]) + ((fRec360[0] * iTemp33) * iTemp32));
			fRec361[0] = ((iTemp37 * fRec361[1]) + ((fRec360[0] * iTemp36) * iTemp35));
			double fTemp555 = ((0.5 * (fVec3[0] * fVec70[(IOTA-int((int(fRec361[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec70[(IOTA-int((int(fRec359[0]) & 2097151)))&2097151]));
			int iTemp556 = (fTemp555 < -1);
			int iTemp557 = (fTemp555 > 1);
			double fTemp558 = ((iTemp557 + ((fTemp555 * (1 - iTemp556)) * (1 - iTemp557))) - iTemp556);
			double fTemp559 = (fRec57[0] * fTemp558);
			fVec71[IOTA&262143] = fTemp559;
			int iTemp560 = (fVec69[1] <= 0.01);
			int iTemp561 = (fVec69[0] > 0.01);
			fRec362[0] = ((fRec362[1] * (1 - (iTemp561 * iTemp560))) + ((fRec19[0] * iTemp561) * iTemp560));
			double fTemp562 = (fConst6 * (fRec362[0] * fVec69[0]));
			int iTemp563 = int(fTemp562);
			int iTemp564 = (1 + iTemp563);
			double fTemp565 = (0.25 + fTemp548);
			double fTemp566 = (fTemp565 - floor(fTemp565));
			fVec72[0] = fTemp566;
			double fTemp567 = (32768.0 * fVec72[0]);
			int iTemp568 = int(fTemp567);
			double fTemp569 = ftbl0[iTemp568];
			int iTemp570 = (fVec72[1] <= 0.01);
			int iTemp571 = (fVec72[0] > 0.01);
			fRec363[0] = ((fRec363[1] * (1 - (iTemp571 * iTemp570))) + ((fRec19[0] * iTemp571) * iTemp570));
			double fTemp572 = (fConst6 * (fRec363[0] * fVec72[0]));
			int iTemp573 = int(fTemp572);
			int iTemp574 = (1 + iTemp573);
			double fTemp575 = (fTemp548 - floor(fTemp548));
			fVec73[0] = fTemp575;
			double fTemp576 = (32768.0 * fVec73[0]);
			int iTemp577 = int(fTemp576);
			double fTemp578 = ftbl0[iTemp577];
			int iTemp579 = (fVec73[1] <= 0.01);
			int iTemp580 = (fVec73[0] > 0.01);
			fRec364[0] = ((fRec364[1] * (1 - (iTemp580 * iTemp579))) + ((fRec19[0] * iTemp580) * iTemp579));
			double fTemp581 = (fConst6 * (fRec364[0] * fVec73[0]));
			int iTemp582 = int(fTemp581);
			int iTemp583 = (1 + iTemp582);
			double fTemp584 = (0.75 + fTemp548);
			double fTemp585 = (fTemp584 - floor(fTemp584));
			fVec74[0] = fTemp585;
			double fTemp586 = (32768.0 * fVec74[0]);
			int iTemp587 = int(fTemp586);
			double fTemp588 = ftbl0[iTemp587];
			int iTemp589 = (fVec74[1] <= 0.01);
			int iTemp590 = (fVec74[0] > 0.01);
			fRec365[0] = ((fRec365[1] * (1 - (iTemp590 * iTemp589))) + ((fRec19[0] * iTemp590) * iTemp589));
			double fTemp591 = (fConst6 * (fRec365[0] * fVec74[0]));
			int iTemp592 = int(fTemp591);
			int iTemp593 = (1 + iTemp592);
			fRec12[0] = (((1 - fRec57[0]) * fTemp558) + ((((fVec71[(IOTA-int((iTemp592 & 262143)))&262143] * (iTemp593 - fTemp591)) + ((fTemp591 - iTemp592) * fVec71[(IOTA-int((int(iTemp593) & 262143)))&262143])) * (fTemp588 + ((fTemp586 - floor(fTemp586)) * (ftbl0[((1 + iTemp587) % 65536)] - fTemp588)))) + (((((fVec71[(IOTA-int((iTemp582 & 262143)))&262143] * (iTemp583 - fTemp581)) + ((fTemp581 - iTemp582) * fVec71[(IOTA-int((int(iTemp583) & 262143)))&262143])) * (fTemp578 + ((fTemp576 - floor(fTemp576)) * (ftbl0[((1 + iTemp577) % 65536)] - fTemp578)))) + (((fVec71[(IOTA-int((iTemp573 & 262143)))&262143] * (iTemp574 - fTemp572)) + ((fTemp572 - iTemp573) * fVec71[(IOTA-int((int(iTemp574) & 262143)))&262143])) * (fTemp569 + ((fTemp567 - floor(fTemp567)) * (ftbl0[((1 + iTemp568) % 65536)] - fTemp569))))) + (((fVec71[(IOTA-int((iTemp563 & 262143)))&262143] * (iTemp564 - fTemp562)) + ((fTemp562 - iTemp563) * fVec71[(IOTA-int((int(iTemp564) & 262143)))&262143])) * (fTemp553 + ((fTemp551 - floor(fTemp551)) * (ftbl0[((1 + iTemp552) % 65536)] - fTemp553)))))));
			fRec367[0] = ((fSlow0 * fRec367[1]) + fSlow268);
			double fTemp594 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec367[0])) - 69))) - 261.625977))) / fTemp1);
			fRec366[0] = fmod((fRec366[1] + (fConst4 * double(fTemp594))),1.0);
			double fTemp595 = ((int((fTemp594 > 0)))?fRec366[0]:(1.0 + fRec366[0]));
			double fTemp596 = (0.5 + fTemp595);
			double fTemp597 = (fTemp596 - floor(fTemp596));
			fVec75[0] = fTemp597;
			double fTemp598 = (32768.0 * fVec75[0]);
			int iTemp599 = int(fTemp598);
			double fTemp600 = ftbl0[iTemp599];
			fRec368[0] = ((fSlow0 * fRec368[1]) + fSlow269);
			fRec369[0] = ((fSlow0 * fRec369[1]) + fSlow270);
			fRec370[0] = ((fSlow0 * fRec370[1]) + fSlow271);
			fRec371[0] = ((fSlow0 * fRec371[1]) + fSlow272);
			fRec372[0] = ((fSlow0 * fRec372[1]) + fSlow273);
			fRec373[0] = ((fSlow0 * fRec373[1]) + fSlow274);
			fRec374[0] = ((fSlow0 * fRec374[1]) + fSlow275);
			fRec375[0] = ((fSlow0 * fRec375[1]) + fSlow276);
			fRec376[0] = ((fSlow0 * fRec376[1]) + fSlow277);
			fRec377[0] = ((fSlow0 * fRec377[1]) + fSlow278);
			fRec378[0] = ((fSlow0 * fRec378[1]) + fSlow279);
			fRec379[0] = ((fSlow0 * fRec379[1]) + fSlow280);
			fRec380[0] = ((fSlow0 * fRec380[1]) + fSlow281);
			fRec381[0] = ((fSlow0 * fRec381[1]) + fSlow282);
			fRec382[0] = ((fSlow0 * fRec382[1]) + fSlow283);
			fRec383[0] = ((fSlow0 * fRec383[1]) + fSlow284);
			fRec384[0] = ((fSlow0 * fRec384[1]) + fSlow285);
			double fTemp601 = ((((fRec71[0] * fRec384[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec383[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec382[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec381[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec380[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec379[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec378[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec377[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec376[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec375[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec374[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec373[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec372[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec371[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec370[0]) * fRec2[1]) * fTemp10) + (((double)input12[i] * fRec369[0]) + (((fRec25[0] * fRec368[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec76[IOTA&2097151] = fTemp601;
			fRec386[0] = ((fSlow0 * fRec386[1]) + fSlow286);
			fRec385[0] = ((iTemp34 * fRec385[1]) + ((fRec386[0] * iTemp33) * iTemp32));
			fRec387[0] = ((iTemp37 * fRec387[1]) + ((fRec386[0] * iTemp36) * iTemp35));
			double fTemp602 = ((0.5 * (fVec3[0] * fVec76[(IOTA-int((int(fRec387[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec76[(IOTA-int((int(fRec385[0]) & 2097151)))&2097151]));
			int iTemp603 = (fTemp602 < -1);
			int iTemp604 = (fTemp602 > 1);
			double fTemp605 = ((iTemp604 + ((fTemp602 * (1 - iTemp603)) * (1 - iTemp604))) - iTemp603);
			double fTemp606 = (fRec60[0] * fTemp605);
			fVec77[IOTA&262143] = fTemp606;
			int iTemp607 = (fVec75[1] <= 0.01);
			int iTemp608 = (fVec75[0] > 0.01);
			fRec388[0] = ((fRec388[1] * (1 - (iTemp608 * iTemp607))) + ((fRec19[0] * iTemp608) * iTemp607));
			double fTemp609 = (fConst6 * (fRec388[0] * fVec75[0]));
			int iTemp610 = int(fTemp609);
			int iTemp611 = (1 + iTemp610);
			double fTemp612 = (0.25 + fTemp595);
			double fTemp613 = (fTemp612 - floor(fTemp612));
			fVec78[0] = fTemp613;
			double fTemp614 = (32768.0 * fVec78[0]);
			int iTemp615 = int(fTemp614);
			double fTemp616 = ftbl0[iTemp615];
			int iTemp617 = (fVec78[1] <= 0.01);
			int iTemp618 = (fVec78[0] > 0.01);
			fRec389[0] = ((fRec389[1] * (1 - (iTemp618 * iTemp617))) + ((fRec19[0] * iTemp618) * iTemp617));
			double fTemp619 = (fConst6 * (fRec389[0] * fVec78[0]));
			int iTemp620 = int(fTemp619);
			int iTemp621 = (1 + iTemp620);
			double fTemp622 = (fTemp595 - floor(fTemp595));
			fVec79[0] = fTemp622;
			double fTemp623 = (32768.0 * fVec79[0]);
			int iTemp624 = int(fTemp623);
			double fTemp625 = ftbl0[iTemp624];
			int iTemp626 = (fVec79[1] <= 0.01);
			int iTemp627 = (fVec79[0] > 0.01);
			fRec390[0] = ((fRec390[1] * (1 - (iTemp627 * iTemp626))) + ((fRec19[0] * iTemp627) * iTemp626));
			double fTemp628 = (fConst6 * (fRec390[0] * fVec79[0]));
			int iTemp629 = int(fTemp628);
			int iTemp630 = (1 + iTemp629);
			double fTemp631 = (0.75 + fTemp595);
			double fTemp632 = (fTemp631 - floor(fTemp631));
			fVec80[0] = fTemp632;
			double fTemp633 = (32768.0 * fVec80[0]);
			int iTemp634 = int(fTemp633);
			double fTemp635 = ftbl0[iTemp634];
			int iTemp636 = (fVec80[1] <= 0.01);
			int iTemp637 = (fVec80[0] > 0.01);
			fRec391[0] = ((fRec391[1] * (1 - (iTemp637 * iTemp636))) + ((fRec19[0] * iTemp637) * iTemp636));
			double fTemp638 = (fConst6 * (fRec391[0] * fVec80[0]));
			int iTemp639 = int(fTemp638);
			int iTemp640 = (1 + iTemp639);
			fRec13[0] = (((1 - fRec60[0]) * fTemp605) + ((((fVec77[(IOTA-int((iTemp639 & 262143)))&262143] * (iTemp640 - fTemp638)) + ((fTemp638 - iTemp639) * fVec77[(IOTA-int((int(iTemp640) & 262143)))&262143])) * (fTemp635 + ((fTemp633 - floor(fTemp633)) * (ftbl0[((1 + iTemp634) % 65536)] - fTemp635)))) + (((((fVec77[(IOTA-int((iTemp629 & 262143)))&262143] * (iTemp630 - fTemp628)) + ((fTemp628 - iTemp629) * fVec77[(IOTA-int((int(iTemp630) & 262143)))&262143])) * (fTemp625 + ((fTemp623 - floor(fTemp623)) * (ftbl0[((1 + iTemp624) % 65536)] - fTemp625)))) + (((fVec77[(IOTA-int((iTemp620 & 262143)))&262143] * (iTemp621 - fTemp619)) + ((fTemp619 - iTemp620) * fVec77[(IOTA-int((int(iTemp621) & 262143)))&262143])) * (fTemp616 + ((fTemp614 - floor(fTemp614)) * (ftbl0[((1 + iTemp615) % 65536)] - fTemp616))))) + (((fVec77[(IOTA-int((iTemp610 & 262143)))&262143] * (iTemp611 - fTemp609)) + ((fTemp609 - iTemp610) * fVec77[(IOTA-int((int(iTemp611) & 262143)))&262143])) * (fTemp600 + ((fTemp598 - floor(fTemp598)) * (ftbl0[((1 + iTemp599) % 65536)] - fTemp600)))))));
			fRec393[0] = ((fSlow0 * fRec393[1]) + fSlow287);
			double fTemp641 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec393[0])) - 69))) - 261.625977))) / fTemp1);
			fRec392[0] = fmod((fRec392[1] + (fConst4 * double(fTemp641))),1.0);
			double fTemp642 = ((int((fTemp641 > 0)))?fRec392[0]:(1.0 + fRec392[0]));
			double fTemp643 = (0.5 + fTemp642);
			double fTemp644 = (fTemp643 - floor(fTemp643));
			fVec81[0] = fTemp644;
			double fTemp645 = (32768.0 * fVec81[0]);
			int iTemp646 = int(fTemp645);
			double fTemp647 = ftbl0[iTemp646];
			fRec394[0] = ((fSlow0 * fRec394[1]) + fSlow288);
			fRec395[0] = ((fSlow0 * fRec395[1]) + fSlow289);
			fRec396[0] = ((fSlow0 * fRec396[1]) + fSlow290);
			fRec397[0] = ((fSlow0 * fRec397[1]) + fSlow291);
			fRec398[0] = ((fSlow0 * fRec398[1]) + fSlow292);
			fRec399[0] = ((fSlow0 * fRec399[1]) + fSlow293);
			fRec400[0] = ((fSlow0 * fRec400[1]) + fSlow294);
			fRec401[0] = ((fSlow0 * fRec401[1]) + fSlow295);
			fRec402[0] = ((fSlow0 * fRec402[1]) + fSlow296);
			fRec403[0] = ((fSlow0 * fRec403[1]) + fSlow297);
			fRec404[0] = ((fSlow0 * fRec404[1]) + fSlow298);
			fRec405[0] = ((fSlow0 * fRec405[1]) + fSlow299);
			fRec406[0] = ((fSlow0 * fRec406[1]) + fSlow300);
			fRec407[0] = ((fSlow0 * fRec407[1]) + fSlow301);
			fRec408[0] = ((fSlow0 * fRec408[1]) + fSlow302);
			fRec409[0] = ((fSlow0 * fRec409[1]) + fSlow303);
			fRec410[0] = ((fSlow0 * fRec410[1]) + fSlow304);
			double fTemp648 = ((((fRec71[0] * fRec410[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec409[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec408[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec407[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec406[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec405[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec404[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec403[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec402[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec401[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec400[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec399[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec398[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec397[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec396[0]) * fRec2[1]) * fTemp10) + (((double)input13[i] * fRec395[0]) + (((fRec25[0] * fRec394[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec82[IOTA&2097151] = fTemp648;
			fRec412[0] = ((fSlow0 * fRec412[1]) + fSlow305);
			fRec411[0] = ((iTemp34 * fRec411[1]) + ((fRec412[0] * iTemp33) * iTemp32));
			fRec413[0] = ((iTemp37 * fRec413[1]) + ((fRec412[0] * iTemp36) * iTemp35));
			double fTemp649 = ((0.5 * (fVec3[0] * fVec82[(IOTA-int((int(fRec413[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec82[(IOTA-int((int(fRec411[0]) & 2097151)))&2097151]));
			int iTemp650 = (fTemp649 < -1);
			int iTemp651 = (fTemp649 > 1);
			double fTemp652 = ((iTemp651 + ((fTemp649 * (1 - iTemp650)) * (1 - iTemp651))) - iTemp650);
			double fTemp653 = (fRec63[0] * fTemp652);
			fVec83[IOTA&262143] = fTemp653;
			int iTemp654 = (fVec81[1] <= 0.01);
			int iTemp655 = (fVec81[0] > 0.01);
			fRec414[0] = ((fRec414[1] * (1 - (iTemp655 * iTemp654))) + ((fRec19[0] * iTemp655) * iTemp654));
			double fTemp656 = (fConst6 * (fRec414[0] * fVec81[0]));
			int iTemp657 = int(fTemp656);
			int iTemp658 = (1 + iTemp657);
			double fTemp659 = (0.25 + fTemp642);
			double fTemp660 = (fTemp659 - floor(fTemp659));
			fVec84[0] = fTemp660;
			double fTemp661 = (32768.0 * fVec84[0]);
			int iTemp662 = int(fTemp661);
			double fTemp663 = ftbl0[iTemp662];
			int iTemp664 = (fVec84[1] <= 0.01);
			int iTemp665 = (fVec84[0] > 0.01);
			fRec415[0] = ((fRec415[1] * (1 - (iTemp665 * iTemp664))) + ((fRec19[0] * iTemp665) * iTemp664));
			double fTemp666 = (fConst6 * (fRec415[0] * fVec84[0]));
			int iTemp667 = int(fTemp666);
			int iTemp668 = (1 + iTemp667);
			double fTemp669 = (fTemp642 - floor(fTemp642));
			fVec85[0] = fTemp669;
			double fTemp670 = (32768.0 * fVec85[0]);
			int iTemp671 = int(fTemp670);
			double fTemp672 = ftbl0[iTemp671];
			int iTemp673 = (fVec85[1] <= 0.01);
			int iTemp674 = (fVec85[0] > 0.01);
			fRec416[0] = ((fRec416[1] * (1 - (iTemp674 * iTemp673))) + ((fRec19[0] * iTemp674) * iTemp673));
			double fTemp675 = (fConst6 * (fRec416[0] * fVec85[0]));
			int iTemp676 = int(fTemp675);
			int iTemp677 = (1 + iTemp676);
			double fTemp678 = (0.75 + fTemp642);
			double fTemp679 = (fTemp678 - floor(fTemp678));
			fVec86[0] = fTemp679;
			double fTemp680 = (32768.0 * fVec86[0]);
			int iTemp681 = int(fTemp680);
			double fTemp682 = ftbl0[iTemp681];
			int iTemp683 = (fVec86[1] <= 0.01);
			int iTemp684 = (fVec86[0] > 0.01);
			fRec417[0] = ((fRec417[1] * (1 - (iTemp684 * iTemp683))) + ((fRec19[0] * iTemp684) * iTemp683));
			double fTemp685 = (fConst6 * (fRec417[0] * fVec86[0]));
			int iTemp686 = int(fTemp685);
			int iTemp687 = (1 + iTemp686);
			fRec14[0] = (((1 - fRec63[0]) * fTemp652) + ((((fVec83[(IOTA-int((iTemp686 & 262143)))&262143] * (iTemp687 - fTemp685)) + ((fTemp685 - iTemp686) * fVec83[(IOTA-int((int(iTemp687) & 262143)))&262143])) * (fTemp682 + ((fTemp680 - floor(fTemp680)) * (ftbl0[((1 + iTemp681) % 65536)] - fTemp682)))) + (((((fVec83[(IOTA-int((iTemp676 & 262143)))&262143] * (iTemp677 - fTemp675)) + ((fTemp675 - iTemp676) * fVec83[(IOTA-int((int(iTemp677) & 262143)))&262143])) * (fTemp672 + ((fTemp670 - floor(fTemp670)) * (ftbl0[((1 + iTemp671) % 65536)] - fTemp672)))) + (((fVec83[(IOTA-int((iTemp667 & 262143)))&262143] * (iTemp668 - fTemp666)) + ((fTemp666 - iTemp667) * fVec83[(IOTA-int((int(iTemp668) & 262143)))&262143])) * (fTemp663 + ((fTemp661 - floor(fTemp661)) * (ftbl0[((1 + iTemp662) % 65536)] - fTemp663))))) + (((fVec83[(IOTA-int((iTemp657 & 262143)))&262143] * (iTemp658 - fTemp656)) + ((fTemp656 - iTemp657) * fVec83[(IOTA-int((int(iTemp658) & 262143)))&262143])) * (fTemp647 + ((fTemp645 - floor(fTemp645)) * (ftbl0[((1 + iTemp646) % 65536)] - fTemp647)))))));
			fRec419[0] = ((fSlow0 * fRec419[1]) + fSlow306);
			double fTemp688 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec419[0])) - 69))) - 261.625977))) / fTemp1);
			fRec418[0] = fmod((fRec418[1] + (fConst4 * double(fTemp688))),1.0);
			double fTemp689 = ((int((fTemp688 > 0)))?fRec418[0]:(1.0 + fRec418[0]));
			double fTemp690 = (0.5 + fTemp689);
			double fTemp691 = (fTemp690 - floor(fTemp690));
			fVec87[0] = fTemp691;
			double fTemp692 = (32768.0 * fVec87[0]);
			int iTemp693 = int(fTemp692);
			double fTemp694 = ftbl0[iTemp693];
			fRec420[0] = ((fSlow0 * fRec420[1]) + fSlow307);
			fRec421[0] = ((fSlow0 * fRec421[1]) + fSlow308);
			fRec422[0] = ((fSlow0 * fRec422[1]) + fSlow309);
			fRec423[0] = ((fSlow0 * fRec423[1]) + fSlow310);
			fRec424[0] = ((fSlow0 * fRec424[1]) + fSlow311);
			fRec425[0] = ((fSlow0 * fRec425[1]) + fSlow312);
			fRec426[0] = ((fSlow0 * fRec426[1]) + fSlow313);
			fRec427[0] = ((fSlow0 * fRec427[1]) + fSlow314);
			fRec428[0] = ((fSlow0 * fRec428[1]) + fSlow315);
			fRec429[0] = ((fSlow0 * fRec429[1]) + fSlow316);
			fRec430[0] = ((fSlow0 * fRec430[1]) + fSlow317);
			fRec431[0] = ((fSlow0 * fRec431[1]) + fSlow318);
			fRec432[0] = ((fSlow0 * fRec432[1]) + fSlow319);
			fRec433[0] = ((fSlow0 * fRec433[1]) + fSlow320);
			fRec434[0] = ((fSlow0 * fRec434[1]) + fSlow321);
			fRec435[0] = ((fSlow0 * fRec435[1]) + fSlow322);
			fRec436[0] = ((fSlow0 * fRec436[1]) + fSlow323);
			double fTemp695 = ((((fRec71[0] * fRec436[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec435[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec434[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec433[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec432[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec431[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec430[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec429[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec428[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec427[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec426[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec425[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec424[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec423[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec422[0]) * fRec2[1]) * fTemp10) + (((double)input14[i] * fRec421[0]) + (((fRec25[0] * fRec420[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec88[IOTA&2097151] = fTemp695;
			fRec438[0] = ((fSlow0 * fRec438[1]) + fSlow324);
			fRec437[0] = ((iTemp34 * fRec437[1]) + ((fRec438[0] * iTemp33) * iTemp32));
			fRec439[0] = ((iTemp37 * fRec439[1]) + ((fRec438[0] * iTemp36) * iTemp35));
			double fTemp696 = ((0.5 * (fVec3[0] * fVec88[(IOTA-int((int(fRec439[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec88[(IOTA-int((int(fRec437[0]) & 2097151)))&2097151]));
			int iTemp697 = (fTemp696 < -1);
			int iTemp698 = (fTemp696 > 1);
			double fTemp699 = ((iTemp698 + ((fTemp696 * (1 - iTemp697)) * (1 - iTemp698))) - iTemp697);
			double fTemp700 = (fRec66[0] * fTemp699);
			fVec89[IOTA&262143] = fTemp700;
			int iTemp701 = (fVec87[1] <= 0.01);
			int iTemp702 = (fVec87[0] > 0.01);
			fRec440[0] = ((fRec440[1] * (1 - (iTemp702 * iTemp701))) + ((fRec19[0] * iTemp702) * iTemp701));
			double fTemp703 = (fConst6 * (fRec440[0] * fVec87[0]));
			int iTemp704 = int(fTemp703);
			int iTemp705 = (1 + iTemp704);
			double fTemp706 = (0.25 + fTemp689);
			double fTemp707 = (fTemp706 - floor(fTemp706));
			fVec90[0] = fTemp707;
			double fTemp708 = (32768.0 * fVec90[0]);
			int iTemp709 = int(fTemp708);
			double fTemp710 = ftbl0[iTemp709];
			int iTemp711 = (fVec90[1] <= 0.01);
			int iTemp712 = (fVec90[0] > 0.01);
			fRec441[0] = ((fRec441[1] * (1 - (iTemp712 * iTemp711))) + ((fRec19[0] * iTemp712) * iTemp711));
			double fTemp713 = (fConst6 * (fRec441[0] * fVec90[0]));
			int iTemp714 = int(fTemp713);
			int iTemp715 = (1 + iTemp714);
			double fTemp716 = (fTemp689 - floor(fTemp689));
			fVec91[0] = fTemp716;
			double fTemp717 = (32768.0 * fVec91[0]);
			int iTemp718 = int(fTemp717);
			double fTemp719 = ftbl0[iTemp718];
			int iTemp720 = (fVec91[1] <= 0.01);
			int iTemp721 = (fVec91[0] > 0.01);
			fRec442[0] = ((fRec442[1] * (1 - (iTemp721 * iTemp720))) + ((fRec19[0] * iTemp721) * iTemp720));
			double fTemp722 = (fConst6 * (fRec442[0] * fVec91[0]));
			int iTemp723 = int(fTemp722);
			int iTemp724 = (1 + iTemp723);
			double fTemp725 = (0.75 + fTemp689);
			double fTemp726 = (fTemp725 - floor(fTemp725));
			fVec92[0] = fTemp726;
			double fTemp727 = (32768.0 * fVec92[0]);
			int iTemp728 = int(fTemp727);
			double fTemp729 = ftbl0[iTemp728];
			int iTemp730 = (fVec92[1] <= 0.01);
			int iTemp731 = (fVec92[0] > 0.01);
			fRec443[0] = ((fRec443[1] * (1 - (iTemp731 * iTemp730))) + ((fRec19[0] * iTemp731) * iTemp730));
			double fTemp732 = (fConst6 * (fRec443[0] * fVec92[0]));
			int iTemp733 = int(fTemp732);
			int iTemp734 = (1 + iTemp733);
			fRec15[0] = (((1 - fRec66[0]) * fTemp699) + ((((fVec89[(IOTA-int((iTemp733 & 262143)))&262143] * (iTemp734 - fTemp732)) + ((fTemp732 - iTemp733) * fVec89[(IOTA-int((int(iTemp734) & 262143)))&262143])) * (fTemp729 + ((fTemp727 - floor(fTemp727)) * (ftbl0[((1 + iTemp728) % 65536)] - fTemp729)))) + (((((fVec89[(IOTA-int((iTemp723 & 262143)))&262143] * (iTemp724 - fTemp722)) + ((fTemp722 - iTemp723) * fVec89[(IOTA-int((int(iTemp724) & 262143)))&262143])) * (fTemp719 + ((fTemp717 - floor(fTemp717)) * (ftbl0[((1 + iTemp718) % 65536)] - fTemp719)))) + (((fVec89[(IOTA-int((iTemp714 & 262143)))&262143] * (iTemp715 - fTemp713)) + ((fTemp713 - iTemp714) * fVec89[(IOTA-int((int(iTemp715) & 262143)))&262143])) * (fTemp710 + ((fTemp708 - floor(fTemp708)) * (ftbl0[((1 + iTemp709) % 65536)] - fTemp710))))) + (((fVec89[(IOTA-int((iTemp704 & 262143)))&262143] * (iTemp705 - fTemp703)) + ((fTemp703 - iTemp704) * fVec89[(IOTA-int((int(iTemp705) & 262143)))&262143])) * (fTemp694 + ((fTemp692 - floor(fTemp692)) * (ftbl0[((1 + iTemp693) % 65536)] - fTemp694)))))));
			fRec445[0] = ((fSlow0 * fRec445[1]) + fSlow325);
			double fTemp735 = ((0 - (3.8224 * ((440 * pow(1.05946309436,((0.01 * (6000 + fRec445[0])) - 69))) - 261.625977))) / fTemp1);
			fRec444[0] = fmod((fRec444[1] + (fConst4 * double(fTemp735))),1.0);
			double fTemp736 = ((int((fTemp735 > 0)))?fRec444[0]:(1.0 + fRec444[0]));
			double fTemp737 = (0.5 + fTemp736);
			double fTemp738 = (fTemp737 - floor(fTemp737));
			fVec93[0] = fTemp738;
			double fTemp739 = (32768.0 * fVec93[0]);
			int iTemp740 = int(fTemp739);
			double fTemp741 = ftbl0[iTemp740];
			fRec446[0] = ((fSlow0 * fRec446[1]) + fSlow326);
			fRec447[0] = ((fSlow0 * fRec447[1]) + fSlow327);
			fRec448[0] = ((fSlow0 * fRec448[1]) + fSlow328);
			fRec449[0] = ((fSlow0 * fRec449[1]) + fSlow329);
			fRec450[0] = ((fSlow0 * fRec450[1]) + fSlow330);
			fRec451[0] = ((fSlow0 * fRec451[1]) + fSlow331);
			fRec452[0] = ((fSlow0 * fRec452[1]) + fSlow332);
			fRec453[0] = ((fSlow0 * fRec453[1]) + fSlow333);
			fRec454[0] = ((fSlow0 * fRec454[1]) + fSlow334);
			fRec455[0] = ((fSlow0 * fRec455[1]) + fSlow335);
			fRec456[0] = ((fSlow0 * fRec456[1]) + fSlow336);
			fRec457[0] = ((fSlow0 * fRec457[1]) + fSlow337);
			fRec458[0] = ((fSlow0 * fRec458[1]) + fSlow338);
			fRec459[0] = ((fSlow0 * fRec459[1]) + fSlow339);
			fRec460[0] = ((fSlow0 * fRec460[1]) + fSlow340);
			fRec461[0] = ((fSlow0 * fRec461[1]) + fSlow341);
			fRec462[0] = ((fSlow0 * fRec462[1]) + fSlow342);
			double fTemp742 = ((((fRec71[0] * fRec462[0]) * fRec16[1]) * fTemp24) + ((((fRec68[0] * fRec461[0]) * fRec15[1]) * fTemp23) + ((((fRec65[0] * fRec460[0]) * fRec14[1]) * fTemp22) + ((((fRec62[0] * fRec459[0]) * fRec13[1]) * fTemp21) + ((((fRec59[0] * fRec458[0]) * fRec12[1]) * fTemp20) + ((((fRec56[0] * fRec457[0]) * fRec11[1]) * fTemp19) + ((((fRec53[0] * fRec456[0]) * fRec10[1]) * fTemp18) + ((((fRec50[0] * fRec455[0]) * fRec9[1]) * fTemp17) + ((((fRec47[0] * fRec454[0]) * fRec8[1]) * fTemp16) + ((((fRec44[0] * fRec453[0]) * fRec7[1]) * fTemp15) + ((((fRec41[0] * fRec452[0]) * fRec6[1]) * fTemp14) + ((((fRec38[0] * fRec451[0]) * fRec5[1]) * fTemp13) + ((((fRec35[0] * fRec450[0]) * fRec4[1]) * fTemp12) + ((((fRec32[0] * fRec449[0]) * fRec3[1]) * fTemp11) + ((((fRec29[0] * fRec448[0]) * fRec2[1]) * fTemp10) + (((double)input15[i] * fRec447[0]) + (((fRec25[0] * fRec446[0]) * fRec1[1]) * fTemp9)))))))))))))))));
			fVec94[IOTA&2097151] = fTemp742;
			fRec464[0] = ((fSlow0 * fRec464[1]) + fSlow343);
			fRec463[0] = ((iTemp34 * fRec463[1]) + ((fRec464[0] * iTemp33) * iTemp32));
			fRec465[0] = ((iTemp37 * fRec465[1]) + ((fRec464[0] * iTemp36) * iTemp35));
			double fTemp743 = ((0.5 * (fVec3[0] * fVec94[(IOTA-int((int(fRec465[0]) & 2097151)))&2097151])) + (fVec4[0] * fVec94[(IOTA-int((int(fRec463[0]) & 2097151)))&2097151]));
			int iTemp744 = (fTemp743 < -1);
			int iTemp745 = (fTemp743 > 1);
			double fTemp746 = ((iTemp745 + ((fTemp743 * (1 - iTemp744)) * (1 - iTemp745))) - iTemp744);
			double fTemp747 = (fRec69[0] * fTemp746);
			fVec95[IOTA&262143] = fTemp747;
			int iTemp748 = (fVec93[1] <= 0.01);
			int iTemp749 = (fVec93[0] > 0.01);
			fRec466[0] = ((fRec466[1] * (1 - (iTemp749 * iTemp748))) + ((fRec19[0] * iTemp749) * iTemp748));
			double fTemp750 = (fConst6 * (fRec466[0] * fVec93[0]));
			int iTemp751 = int(fTemp750);
			int iTemp752 = (1 + iTemp751);
			double fTemp753 = (0.25 + fTemp736);
			double fTemp754 = (fTemp753 - floor(fTemp753));
			fVec96[0] = fTemp754;
			double fTemp755 = (32768.0 * fVec96[0]);
			int iTemp756 = int(fTemp755);
			double fTemp757 = ftbl0[iTemp756];
			int iTemp758 = (fVec96[1] <= 0.01);
			int iTemp759 = (fVec96[0] > 0.01);
			fRec467[0] = ((fRec467[1] * (1 - (iTemp759 * iTemp758))) + ((fRec19[0] * iTemp759) * iTemp758));
			double fTemp760 = (fConst6 * (fRec467[0] * fVec96[0]));
			int iTemp761 = int(fTemp760);
			int iTemp762 = (1 + iTemp761);
			double fTemp763 = (fTemp736 - floor(fTemp736));
			fVec97[0] = fTemp763;
			double fTemp764 = (32768.0 * fVec97[0]);
			int iTemp765 = int(fTemp764);
			double fTemp766 = ftbl0[iTemp765];
			int iTemp767 = (fVec97[1] <= 0.01);
			int iTemp768 = (fVec97[0] > 0.01);
			fRec468[0] = ((fRec468[1] * (1 - (iTemp768 * iTemp767))) + ((fRec19[0] * iTemp768) * iTemp767));
			double fTemp769 = (fConst6 * (fRec468[0] * fVec97[0]));
			int iTemp770 = int(fTemp769);
			int iTemp771 = (1 + iTemp770);
			double fTemp772 = (0.75 + fTemp736);
			double fTemp773 = (fTemp772 - floor(fTemp772));
			fVec98[0] = fTemp773;
			double fTemp774 = (32768.0 * fVec98[0]);
			int iTemp775 = int(fTemp774);
			double fTemp776 = ftbl0[iTemp775];
			int iTemp777 = (fVec98[1] <= 0.01);
			int iTemp778 = (fVec98[0] > 0.01);
			fRec469[0] = ((fRec469[1] * (1 - (iTemp778 * iTemp777))) + ((fRec19[0] * iTemp778) * iTemp777));
			double fTemp779 = (fConst6 * (fRec469[0] * fVec98[0]));
			int iTemp780 = int(fTemp779);
			int iTemp781 = (1 + iTemp780);
			fRec16[0] = (((1 - fRec69[0]) * fTemp746) + ((((fVec95[(IOTA-int((iTemp780 & 262143)))&262143] * (iTemp781 - fTemp779)) + ((fTemp779 - iTemp780) * fVec95[(IOTA-int((int(iTemp781) & 262143)))&262143])) * (fTemp776 + ((fTemp774 - floor(fTemp774)) * (ftbl0[((1 + iTemp775) % 65536)] - fTemp776)))) + (((((fVec95[(IOTA-int((iTemp770 & 262143)))&262143] * (iTemp771 - fTemp769)) + ((fTemp769 - iTemp770) * fVec95[(IOTA-int((int(iTemp771) & 262143)))&262143])) * (fTemp766 + ((fTemp764 - floor(fTemp764)) * (ftbl0[((1 + iTemp765) % 65536)] - fTemp766)))) + (((fVec95[(IOTA-int((iTemp761 & 262143)))&262143] * (iTemp762 - fTemp760)) + ((fTemp760 - iTemp761) * fVec95[(IOTA-int((int(iTemp762) & 262143)))&262143])) * (fTemp757 + ((fTemp755 - floor(fTemp755)) * (ftbl0[((1 + iTemp756) % 65536)] - fTemp757))))) + (((fVec95[(IOTA-int((iTemp751 & 262143)))&262143] * (iTemp752 - fTemp750)) + ((fTemp750 - iTemp751) * fVec95[(IOTA-int((int(iTemp752) & 262143)))&262143])) * (fTemp741 + ((fTemp739 - floor(fTemp739)) * (ftbl0[((1 + iTemp740) % 65536)] - fTemp741)))))));
			output0[i] = (FAUSTFLOAT)(fRec1[0] * fRec0[0]);
			fRec470[0] = ((fSlow0 * fRec470[1]) + fSlow344);
			output1[i] = (FAUSTFLOAT)(fRec2[0] * fRec470[0]);
			fRec471[0] = ((fSlow0 * fRec471[1]) + fSlow345);
			output2[i] = (FAUSTFLOAT)(fRec3[0] * fRec471[0]);
			fRec472[0] = ((fSlow0 * fRec472[1]) + fSlow346);
			output3[i] = (FAUSTFLOAT)(fRec4[0] * fRec472[0]);
			fRec473[0] = ((fSlow0 * fRec473[1]) + fSlow347);
			output4[i] = (FAUSTFLOAT)(fRec5[0] * fRec473[0]);
			fRec474[0] = ((fSlow0 * fRec474[1]) + fSlow348);
			output5[i] = (FAUSTFLOAT)(fRec6[0] * fRec474[0]);
			fRec475[0] = ((fSlow0 * fRec475[1]) + fSlow349);
			output6[i] = (FAUSTFLOAT)(fRec7[0] * fRec475[0]);
			fRec476[0] = ((fSlow0 * fRec476[1]) + fSlow350);
			output7[i] = (FAUSTFLOAT)(fRec8[0] * fRec476[0]);
			fRec477[0] = ((fSlow0 * fRec477[1]) + fSlow351);
			output8[i] = (FAUSTFLOAT)(fRec9[0] * fRec477[0]);
			fRec478[0] = ((fSlow0 * fRec478[1]) + fSlow352);
			output9[i] = (FAUSTFLOAT)(fRec10[0] * fRec478[0]);
			fRec479[0] = ((fSlow0 * fRec479[1]) + fSlow353);
			output10[i] = (FAUSTFLOAT)(fRec11[0] * fRec479[0]);
			fRec480[0] = ((fSlow0 * fRec480[1]) + fSlow354);
			output11[i] = (FAUSTFLOAT)(fRec12[0] * fRec480[0]);
			fRec481[0] = ((fSlow0 * fRec481[1]) + fSlow355);
			output12[i] = (FAUSTFLOAT)(fRec13[0] * fRec481[0]);
			fRec482[0] = ((fSlow0 * fRec482[1]) + fSlow356);
			output13[i] = (FAUSTFLOAT)(fRec14[0] * fRec482[0]);
			fRec483[0] = ((fSlow0 * fRec483[1]) + fSlow357);
			output14[i] = (FAUSTFLOAT)(fRec15[0] * fRec483[0]);
			fRec484[0] = ((fSlow0 * fRec484[1]) + fSlow358);
			output15[i] = (FAUSTFLOAT)(fRec16[0] * fRec484[0]);
			// post processing
			fRec484[1] = fRec484[0];
			fRec483[1] = fRec483[0];
			fRec482[1] = fRec482[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec479[1] = fRec479[0];
			fRec478[1] = fRec478[0];
			fRec477[1] = fRec477[0];
			fRec476[1] = fRec476[0];
			fRec475[1] = fRec475[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec472[1] = fRec472[0];
			fRec471[1] = fRec471[0];
			fRec470[1] = fRec470[0];
			fRec16[1] = fRec16[0];
			fRec469[1] = fRec469[0];
			fVec98[1] = fVec98[0];
			fRec468[1] = fRec468[0];
			fVec97[1] = fVec97[0];
			fRec467[1] = fRec467[0];
			fVec96[1] = fVec96[0];
			fRec466[1] = fRec466[0];
			fRec465[1] = fRec465[0];
			fRec463[1] = fRec463[0];
			fRec464[1] = fRec464[0];
			fRec462[1] = fRec462[0];
			fRec461[1] = fRec461[0];
			fRec460[1] = fRec460[0];
			fRec459[1] = fRec459[0];
			fRec458[1] = fRec458[0];
			fRec457[1] = fRec457[0];
			fRec456[1] = fRec456[0];
			fRec455[1] = fRec455[0];
			fRec454[1] = fRec454[0];
			fRec453[1] = fRec453[0];
			fRec452[1] = fRec452[0];
			fRec451[1] = fRec451[0];
			fRec450[1] = fRec450[0];
			fRec449[1] = fRec449[0];
			fRec448[1] = fRec448[0];
			fRec447[1] = fRec447[0];
			fRec446[1] = fRec446[0];
			fVec93[1] = fVec93[0];
			fRec444[1] = fRec444[0];
			fRec445[1] = fRec445[0];
			fRec15[1] = fRec15[0];
			fRec443[1] = fRec443[0];
			fVec92[1] = fVec92[0];
			fRec442[1] = fRec442[0];
			fVec91[1] = fVec91[0];
			fRec441[1] = fRec441[0];
			fVec90[1] = fVec90[0];
			fRec440[1] = fRec440[0];
			fRec439[1] = fRec439[0];
			fRec437[1] = fRec437[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[1] = fRec435[0];
			fRec434[1] = fRec434[0];
			fRec433[1] = fRec433[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec430[1] = fRec430[0];
			fRec429[1] = fRec429[0];
			fRec428[1] = fRec428[0];
			fRec427[1] = fRec427[0];
			fRec426[1] = fRec426[0];
			fRec425[1] = fRec425[0];
			fRec424[1] = fRec424[0];
			fRec423[1] = fRec423[0];
			fRec422[1] = fRec422[0];
			fRec421[1] = fRec421[0];
			fRec420[1] = fRec420[0];
			fVec87[1] = fVec87[0];
			fRec418[1] = fRec418[0];
			fRec419[1] = fRec419[0];
			fRec14[1] = fRec14[0];
			fRec417[1] = fRec417[0];
			fVec86[1] = fVec86[0];
			fRec416[1] = fRec416[0];
			fVec85[1] = fVec85[0];
			fRec415[1] = fRec415[0];
			fVec84[1] = fVec84[0];
			fRec414[1] = fRec414[0];
			fRec413[1] = fRec413[0];
			fRec411[1] = fRec411[0];
			fRec412[1] = fRec412[0];
			fRec410[1] = fRec410[0];
			fRec409[1] = fRec409[0];
			fRec408[1] = fRec408[0];
			fRec407[1] = fRec407[0];
			fRec406[1] = fRec406[0];
			fRec405[1] = fRec405[0];
			fRec404[1] = fRec404[0];
			fRec403[1] = fRec403[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec400[1] = fRec400[0];
			fRec399[1] = fRec399[0];
			fRec398[1] = fRec398[0];
			fRec397[1] = fRec397[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec394[1] = fRec394[0];
			fVec81[1] = fVec81[0];
			fRec392[1] = fRec392[0];
			fRec393[1] = fRec393[0];
			fRec13[1] = fRec13[0];
			fRec391[1] = fRec391[0];
			fVec80[1] = fVec80[0];
			fRec390[1] = fRec390[0];
			fVec79[1] = fVec79[0];
			fRec389[1] = fRec389[0];
			fVec78[1] = fVec78[0];
			fRec388[1] = fRec388[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec386[1] = fRec386[0];
			fRec384[1] = fRec384[0];
			fRec383[1] = fRec383[0];
			fRec382[1] = fRec382[0];
			fRec381[1] = fRec381[0];
			fRec380[1] = fRec380[0];
			fRec379[1] = fRec379[0];
			fRec378[1] = fRec378[0];
			fRec377[1] = fRec377[0];
			fRec376[1] = fRec376[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec373[1] = fRec373[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec370[1] = fRec370[0];
			fRec369[1] = fRec369[0];
			fRec368[1] = fRec368[0];
			fVec75[1] = fVec75[0];
			fRec366[1] = fRec366[0];
			fRec367[1] = fRec367[0];
			fRec12[1] = fRec12[0];
			fRec365[1] = fRec365[0];
			fVec74[1] = fVec74[0];
			fRec364[1] = fRec364[0];
			fVec73[1] = fVec73[0];
			fRec363[1] = fRec363[0];
			fVec72[1] = fVec72[0];
			fRec362[1] = fRec362[0];
			fRec361[1] = fRec361[0];
			fRec359[1] = fRec359[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec357[1] = fRec357[0];
			fRec356[1] = fRec356[0];
			fRec355[1] = fRec355[0];
			fRec354[1] = fRec354[0];
			fRec353[1] = fRec353[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec350[1] = fRec350[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec347[1] = fRec347[0];
			fRec346[1] = fRec346[0];
			fRec345[1] = fRec345[0];
			fRec344[1] = fRec344[0];
			fRec343[1] = fRec343[0];
			fRec342[1] = fRec342[0];
			fVec69[1] = fVec69[0];
			fRec340[1] = fRec340[0];
			fRec341[1] = fRec341[0];
			fRec11[1] = fRec11[0];
			fRec339[1] = fRec339[0];
			fVec68[1] = fVec68[0];
			fRec338[1] = fRec338[0];
			fVec67[1] = fVec67[0];
			fRec337[1] = fRec337[0];
			fVec66[1] = fVec66[0];
			fRec336[1] = fRec336[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec334[1] = fRec334[0];
			fRec332[1] = fRec332[0];
			fRec331[1] = fRec331[0];
			fRec330[1] = fRec330[0];
			fRec329[1] = fRec329[0];
			fRec328[1] = fRec328[0];
			fRec327[1] = fRec327[0];
			fRec326[1] = fRec326[0];
			fRec325[1] = fRec325[0];
			fRec324[1] = fRec324[0];
			fRec323[1] = fRec323[0];
			fRec322[1] = fRec322[0];
			fRec321[1] = fRec321[0];
			fRec320[1] = fRec320[0];
			fRec319[1] = fRec319[0];
			fRec318[1] = fRec318[0];
			fRec317[1] = fRec317[0];
			fRec316[1] = fRec316[0];
			fVec63[1] = fVec63[0];
			fRec314[1] = fRec314[0];
			fRec315[1] = fRec315[0];
			fRec10[1] = fRec10[0];
			fRec313[1] = fRec313[0];
			fVec62[1] = fVec62[0];
			fRec312[1] = fRec312[0];
			fVec61[1] = fVec61[0];
			fRec311[1] = fRec311[0];
			fVec60[1] = fVec60[0];
			fRec310[1] = fRec310[0];
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec304[1] = fRec304[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec301[1] = fRec301[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec298[1] = fRec298[0];
			fRec297[1] = fRec297[0];
			fRec296[1] = fRec296[0];
			fRec295[1] = fRec295[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec290[1] = fRec290[0];
			fVec57[1] = fVec57[0];
			fRec288[1] = fRec288[0];
			fRec289[1] = fRec289[0];
			fRec9[1] = fRec9[0];
			fRec287[1] = fRec287[0];
			fVec56[1] = fVec56[0];
			fRec286[1] = fRec286[0];
			fVec55[1] = fVec55[0];
			fRec285[1] = fRec285[0];
			fVec54[1] = fVec54[0];
			fRec284[1] = fRec284[0];
			fRec283[1] = fRec283[0];
			fRec281[1] = fRec281[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec279[1] = fRec279[0];
			fRec278[1] = fRec278[0];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec275[1] = fRec275[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec272[1] = fRec272[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec269[1] = fRec269[0];
			fRec268[1] = fRec268[0];
			fRec267[1] = fRec267[0];
			fRec266[1] = fRec266[0];
			fRec265[1] = fRec265[0];
			fRec264[1] = fRec264[0];
			fVec51[1] = fVec51[0];
			fRec262[1] = fRec262[0];
			fRec263[1] = fRec263[0];
			fRec8[1] = fRec8[0];
			fRec261[1] = fRec261[0];
			fVec50[1] = fVec50[0];
			fRec260[1] = fRec260[0];
			fVec49[1] = fVec49[0];
			fRec259[1] = fRec259[0];
			fVec48[1] = fVec48[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec256[1] = fRec256[0];
			fRec254[1] = fRec254[0];
			fRec253[1] = fRec253[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec250[1] = fRec250[0];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec246[1] = fRec246[0];
			fRec245[1] = fRec245[0];
			fRec244[1] = fRec244[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec238[1] = fRec238[0];
			fVec45[1] = fVec45[0];
			fRec236[1] = fRec236[0];
			fRec237[1] = fRec237[0];
			fRec7[1] = fRec7[0];
			fRec235[1] = fRec235[0];
			fVec44[1] = fVec44[0];
			fRec234[1] = fRec234[0];
			fVec43[1] = fVec43[0];
			fRec233[1] = fRec233[0];
			fVec42[1] = fVec42[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec227[1] = fRec227[0];
			fRec226[1] = fRec226[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			fRec218[1] = fRec218[0];
			fRec217[1] = fRec217[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fVec39[1] = fVec39[0];
			fRec210[1] = fRec210[0];
			fRec211[1] = fRec211[0];
			fRec6[1] = fRec6[0];
			fRec209[1] = fRec209[0];
			fVec38[1] = fVec38[0];
			fRec208[1] = fRec208[0];
			fVec37[1] = fVec37[0];
			fRec207[1] = fRec207[0];
			fVec36[1] = fVec36[0];
			fRec206[1] = fRec206[0];
			fRec205[1] = fRec205[0];
			fRec203[1] = fRec203[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec201[1] = fRec201[0];
			fRec200[1] = fRec200[0];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec197[1] = fRec197[0];
			fRec196[1] = fRec196[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec193[1] = fRec193[0];
			fRec192[1] = fRec192[0];
			fRec191[1] = fRec191[0];
			fRec190[1] = fRec190[0];
			fRec189[1] = fRec189[0];
			fRec188[1] = fRec188[0];
			fRec187[1] = fRec187[0];
			fRec186[1] = fRec186[0];
			fVec33[1] = fVec33[0];
			fRec184[1] = fRec184[0];
			fRec185[1] = fRec185[0];
			fRec5[1] = fRec5[0];
			fRec183[1] = fRec183[0];
			fVec32[1] = fVec32[0];
			fRec182[1] = fRec182[0];
			fVec31[1] = fVec31[0];
			fRec181[1] = fRec181[0];
			fVec30[1] = fVec30[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec178[1] = fRec178[0];
			fRec176[1] = fRec176[0];
			fRec175[1] = fRec175[0];
			fRec174[1] = fRec174[0];
			fRec173[1] = fRec173[0];
			fRec172[1] = fRec172[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec169[1] = fRec169[0];
			fRec168[1] = fRec168[0];
			fRec167[1] = fRec167[0];
			fRec166[1] = fRec166[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec163[1] = fRec163[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec160[1] = fRec160[0];
			fVec27[1] = fVec27[0];
			fRec158[1] = fRec158[0];
			fRec159[1] = fRec159[0];
			fRec4[1] = fRec4[0];
			fRec157[1] = fRec157[0];
			fVec26[1] = fVec26[0];
			fRec156[1] = fRec156[0];
			fVec25[1] = fVec25[0];
			fRec155[1] = fRec155[0];
			fVec24[1] = fVec24[0];
			fRec154[1] = fRec154[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec146[1] = fRec146[0];
			fRec145[1] = fRec145[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec142[1] = fRec142[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec139[1] = fRec139[0];
			fRec138[1] = fRec138[0];
			fRec137[1] = fRec137[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fVec21[1] = fVec21[0];
			fRec132[1] = fRec132[0];
			fRec133[1] = fRec133[0];
			fRec3[1] = fRec3[0];
			fRec131[1] = fRec131[0];
			fVec20[1] = fVec20[0];
			fRec130[1] = fRec130[0];
			fVec19[1] = fVec19[0];
			fRec129[1] = fRec129[0];
			fVec18[1] = fVec18[0];
			fRec128[1] = fRec128[0];
			fRec127[1] = fRec127[0];
			fRec125[1] = fRec125[0];
			fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec121[1] = fRec121[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec118[1] = fRec118[0];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			fRec115[1] = fRec115[0];
			fRec114[1] = fRec114[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fVec15[1] = fVec15[0];
			fRec106[1] = fRec106[0];
			fRec107[1] = fRec107[0];
			fRec2[1] = fRec2[0];
			fRec105[1] = fRec105[0];
			fVec14[1] = fVec14[0];
			fRec104[1] = fRec104[0];
			fVec13[1] = fVec13[0];
			fRec103[1] = fRec103[0];
			fVec12[1] = fVec12[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec100[1] = fRec100[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			fVec9[1] = fVec9[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			fRec1[1] = fRec1[0];
			fRec79[1] = fRec79[0];
			fVec8[1] = fVec8[0];
			fRec78[1] = fRec78[0];
			fVec7[1] = fVec7[0];
			fRec77[1] = fRec77[0];
			fVec6[1] = fVec6[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec72[1] = fRec72[0];
			fRec74[1] = fRec74[0];
			fVec4[1] = fVec4[0];
			fVec3[1] = fVec3[0];
			fRec73[1] = fRec73[0];
			IOTA = IOTA+1;
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fVec1[1] = fVec1[0];
			fRec18[1] = fRec18[0];
			fRec22[1] = fRec22[0];
			fRec19[1] = fRec19[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
		}
	}
};


double 	mydsp::ftbl0[65536];

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  		/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2		/* should be defined somewhere ?? */

#define EXTERNAL_VERSION "0.56"

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
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

 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_GUI_H
#define FAUST_GUI_H

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

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two.  */

inline ringbuffer_t *
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

inline void
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

inline int
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

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading.  This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
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

/* Return the number of bytes available for writing.  This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
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

/* The copying data reader.  Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
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

/* The copying data reader w/o read pointer advance.  Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
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

/* The copying data writer.  Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
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

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current readable data at `rb'.  If
   the readable data is in one segment the second segment has zero
   length.  */

inline void
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

/* The non-copying data writer.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current writeable data at `rb'.  If
   the writeable data is in one segment the second segment has zero
   length.  */

inline void
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

#include <list>
#include <map>
#include <vector>

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*>  fGuiList;
        zmap                    fZoneMap;
        bool                    fStopped;
        
     public:
            
        GUI() : fStopped(false) 
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all 
            zmap::iterator g;
            for (g = fZoneMap.begin(); g != fZoneMap.end(); g++) {
                delete (*g).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        } 	

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual void run() {};
        
        virtual void stop()		{ fStopped = true; }
        bool stopped() 	{ return fStopped; }

        virtual void declare(FAUSTFLOAT* , const char* , const char*) {}
        
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI*            fGUI;
        FAUSTFLOAT*     fZone;
        FAUSTFLOAT      fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone) : fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321)) 
        { 
            ui->registerZone(zone, this); 
        }

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
                
        FAUSTFLOAT		cache()	{ return fCache; }
        virtual void 	reflectZone() = 0;	
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem
{
	uiCallback	fCallback;
	void*		fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT 	v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Allows to group a set of zones.
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

// en cours d'installation de callback : a finir!!!!!

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT	v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        delete (*it);
    }
}

// For precise timestamped control
struct DatedControl {

    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}

};
  
#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
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

 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <string>
#include <utility>
#include <iostream>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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

 ************************************************************************
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

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
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
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

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF           = 0x80,
            MIDI_NOTE_ON            = 0x90,
            MIDI_CONTROL_CHANGE     = 0xB0,
            MIDI_PROGRAM_CHANGE     = 0xC0,
            MIDI_PITCH_BEND         = 0xE0,
            MIDI_AFTERTOUCH         = 0xD0,	// aka channel pressure
            MIDI_POLY_AFTERTOUCH    = 0xA0,	// aka key pressure
            MIDI_CLOCK              = 0xF8,
            MIDI_START              = 0xFA,
            MIDI_STOP               = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        virtual void addMidiIn(midi* midi_dsp) { fMidiInputs.push_back(midi_dsp); }
        virtual void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return false; }
        virtual void stop_midi() {}
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
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
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }


};

#endif // __midi__
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
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


 ************************************************************************
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

            Range(double x, double y) : fLo(std::min(x,y)), fHi(std::max(x,y)) {}
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
// Linear conversion between ui and faust values
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
// Logarithmic conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, log(std::max(DBL_MIN,fmin)), log(std::max(DBL_MIN,fmax)))
        {}

        virtual double ui2faust(double x) 	{ return exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(log(std::max(x, DBL_MIN))); }

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

        virtual double ui2faust(double x) { return log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(exp(x)); }

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

        FAUSTFLOAT*     fZone;
        Interpolator    fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue() {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently "ctrl, keyon, keypress, pgm, chanpress, pitchwheel/pitchbend meta data is handled.
 ******************************************************************************/
 
class uiMidiItem : public uiItem {
 
    protected:
    
         midi* fMidiOut;
         bool fInputCtrl;

    public:
    
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input)
            :uiItem(ui, zone), fMidiOut(midi_out), fInputCtrl(input) {}
        virtual ~uiMidiItem() {}
 
};
 
class uiMidiTimedItem : public uiMidiItem
{
    protected:
    
        bool fDelete;
   
    public:
       
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiMidiTimedItem() 
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }

        void modifyZone(double date, FAUSTFLOAT v) 	
        { 
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cout << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
        
        // TODO
        virtual void reflectZone() {}

};

// MIDI sync

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
                fMidiOut->start_sync(0);
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
                fMidiOut->stop_sync(0);
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
        
        void modifyZone(double date, FAUSTFLOAT v) 	
        { 
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
};

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
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fConverter(0., 16383, double(min), double(max))
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
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
        
        void modifyZone(int v) 	
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
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyPress : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (sscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (sscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (sscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (sscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (sscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (sscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:

        MidiUI(midi_handler* midi_handler)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
        }
        
        void run() { fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- widget's layouts

        virtual void openTabBox(const char* label)
        {}
        virtual void openHorizontalBox(const char* label)
        {}
        virtual void openVerticalBox(const char* label)
        {}
        virtual void closeBox()
        {}

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
            return 0;
        }
        
        void keyOff(double date,  int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
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
            if (fKeyPressTable.find(press) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[press].size(); i++) {
                    fKeyPressTable[press][i]->modifyZone(FAUSTFLOAT(press));
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
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
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

#ifdef POLY
/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/
/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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
 
 
 ************************************************************************
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <math.h>
#include <float.h>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

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
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, float value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        float getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return 0.;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAdress(int index) 
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
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


 ************************************************************************
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************************************************************
 ************************************************************************
 FAUST compiler
 Copyright (C) 2003-2015 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
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

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
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

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
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
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
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
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
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
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

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
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
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
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
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
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
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
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
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
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            metadatas[key] = value;
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

inline FAUSTFLOAT STR2REAL(const std::string& s)  { return (strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

struct JSONUIDecoder {

    std::string fName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems; 

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
        } else {
            fName = "";
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = atoi(fMetadatas["inputs"].c_str());
        } else {
            fNumInputs = 0;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = atoi(fMetadatas["outputs"].c_str());
        } else {
            fNumOutputs = 0;
        }   
             
        vector<itemInfo*>::iterator it;
        fInputItems = 0;
        fOutputItems = 0;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (type == "vslider" || type == "hslider" || type == "nentry" || type == "button") {
                fInputItems++;
            } else if (type == "hbargraph" || type == "vbargraph") {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (type == "vslider" || type == "hslider" || type == "nentry" || type == "button") {
                isInItem = true;
            } else if (type == "hbargraph" || type == "vbargraph") {
                isOutItem = true;        
            }
            
            // Meta data declaration for input items
            if ((*it)->type.find("group") == string::npos && (*it)->type.find("bargraph") == string::npos && (*it)->type != "close") {
                fInControl[counterIn] = init;
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if ((*it)->type.find("bargraph") != string::npos) {
                fOutControl[counterOut] = init;
                for (int i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (int i = 0; i < (*it)->meta.size(); i++) {
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
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

typedef void (*metadataFun) (Meta* m);

class proxy_dsp : public dsp {

    private:
        
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
        }
          
        proxy_dsp(dsp* dsp, metadataFun fun = 0)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            if (fun) { fun(&builder); }
            dsp->buildUserInterface(&builder);
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
        virtual void init(int samplingRate) {}
        virtual void instanceInit(int samplingRate) {}
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// ends_with(<str>,<end>) : returns true if <str> ends with <end>
static bool ends_with(std::string const& str, std::string const& end)
{
	unsigned int l1 = str.length();
	unsigned int l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

class GroupUI : public GUI, public PathBuilder
{
    
    private:
    
        std::map<std::string, uiGroupItem*> fLabelZoneMap;
        
        void insertMap(std::string label, FAUSTFLOAT* zone)
        {   
            if (!ends_with(label, "/gate") 
                && !ends_with(label, "/freq") 
                && !ends_with(label, "/gain")) {
                
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
        };
        virtual ~GroupUI() 
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        };
        
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
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
            
};

// One voice of polyphony
struct dsp_voice : public MapUI, public dsp {
       
    int fNote;          // Playing note actual pitch
    int fDate;          // KeyOn date
    bool fTrigger;      // True if stolen note and need for envelop re-trigger
    FAUSTFLOAT fLevel;  // Last audio block level

    dsp_voice()
    {
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
    }
 
};

struct voice_factory {

    virtual dsp_voice* create() = 0;
    virtual void metadata(Meta* meta) = 0;
    
};

struct mydsp_voice : public dsp_voice {

    mydsp fVoice;
     
    mydsp_voice():dsp_voice()
    {
        fVoice.buildUserInterface(this);
    }
    
    virtual int getNumInputs() { return fVoice.getNumInputs(); }
    virtual int getNumOutputs() { return fVoice.getNumOutputs(); }
    virtual void buildUserInterface(UI* ui_interface) { fVoice.buildUserInterface(ui_interface); }
    virtual void init(int samplingRate) { fVoice.init(samplingRate); }
    virtual void instanceInit(int samplingRate) { fVoice.instanceInit(samplingRate); }
    virtual void compute(int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fVoice.compute(len, inputs, outputs); }

};

struct mydsp_voice_factory : public voice_factory {

    virtual dsp_voice* create() { return new mydsp_voice(); }
    virtual void metadata(Meta* meta) { mydsp::metadata(meta); }

};

// Polyphonic DSP
class mydsp_poly : public dsp, public midi {

    private:
    
        voice_factory* fVoiceFactory;
        std::vector<dsp_voice*> fVoiceTable; // Individual voices
        dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control
        
        std::string fGateLabel;
        std::string fGainLabel;
        std::string fFreqLabel;
        FAUSTFLOAT fPanic;
        
        int fPolyphony;
        bool fVoiceControl;
        bool fGroupControl;
        
        GroupUI fGroups;
        
        FAUSTFLOAT** fMixBuffer;
        int fNumOutputs;
        int fDate;
        
        std::vector<MidiUI*> fMidiUIList;
        
        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer) 
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < fNumOutputs; i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }
        
        inline double midiToFreq(double note) 
        {
            return 440.0 * pow(2.0, (note-69.0)/12.0);
        }
        
        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer) 
        {
            for (int i = 0; i < fNumOutputs; i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
          
        inline int getVoice(int note, bool steal = false)
        {
            for (int i = 0; i < fPolyphony; i++) {
                if (fVoiceTable[i]->fNote == note) {
                    if (steal) { fVoiceTable[i]->fDate = fDate++; }
                    return i;
                }
            }
             
            if (steal) {
                int voice = kNoVoice;
                int date = INT_MAX;
                for (int i = 0; i < fPolyphony; i++) {
                    // Try to steal a voice in kReleaseVoice mode...
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        printf("Steal release voice : voice_date = %d cur_date = %d voice = %d\n", fVoiceTable[i]->fDate, fDate, i);
                        fVoiceTable[i]->fDate = fDate++;
                        fVoiceTable[i]->fTrigger = true;
                        return i;
                    // Otherwise steal oldest voice...
                    } else if (fVoiceTable[i]->fDate < date) {
                        date = fVoiceTable[i]->fDate;
                        voice = i;
                    }
                }
                printf("Steal playing voice : voice_date = %d cur_date = %d voice = %d\n", fVoiceTable[voice]->fDate, fDate, voice);
                fVoiceTable[voice]->fDate = fDate++;
                fVoiceTable[voice]->fTrigger = true;
                return voice;
            } else {
                return kNoVoice;
            }
        }
        
        inline void init(int max_polyphony, voice_factory* factory, bool control, bool group)
        {
            fVoiceControl = control;
            fGroupControl = group;
            fPolyphony = max_polyphony;
            fFreqLabel = fGateLabel = fGainLabel = "";
            
            // Create voices
            for (int i = 0; i < fPolyphony; i++) {
                fVoiceTable.push_back(factory->create());
            }
            
            // Init audio output buffers
            fNumOutputs = fVoiceTable[0]->getNumOutputs();
            fMixBuffer = new FAUSTFLOAT*[fNumOutputs];
            for (int i = 0; i < fNumOutputs; i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }
            
            // Groups all uiItem for a given path
            fVoiceGroup = new proxy_dsp(fVoiceTable[0], mydsp::metadata);
            fVoiceGroup->buildUserInterface(&fGroups);
            for (int i = 0; i < fPolyphony; i++) {
                fVoiceTable[i]->buildUserInterface(&fGroups);
            }
            
            fDate = 0;
            
            // Keep gain, freq and gate labels
            std::map<std::string, FAUSTFLOAT*>::iterator it;
            for (it = fVoiceTable[0]->getMap().begin(); it != fVoiceTable[0]->getMap().end(); it++) {
                std::string label = (*it).first;
                if (ends_with(label, "/gate")) {
                    fGateLabel = label;
                } else if (ends_with(label, "/freq")) {
                    fFreqLabel = label;
                } else if (ends_with(label, "/gain")) {
                    fGainLabel = label;
                }
            }
        }
        
        void uIBuilder(UI* ui_interface)
        {
            ui_interface->openTabBox("Polyphonic");
            
            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            
            // In not group, also add individual voices UI
            if (!fGroupControl) {
                for (int i = 0; i < fPolyphony; i++) {
                    char buffer[32];
                    snprintf(buffer, 31, ((fPolyphony < 8) ? "Voice%d" : "V%d"), i+1);
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }
            
            ui_interface->closeBox();
        }
        
        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff();
            }
        }
        
        inline bool checkPolyphony() 
        {
            if (fFreqLabel == "") {
                printf("DSP is not polyphonic...\n");
                return false;
            } else {
                return true;;
            }
        }
        
        inline void computeSlice(dsp* dsp, int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 
        {
            if (slice > 0) {
                FAUSTFLOAT** inputs_slice = (FAUSTFLOAT**)alloca(dsp->getNumInputs() * sizeof(FAUSTFLOAT*));
                for (int chan = 0; chan < dsp->getNumInputs(); chan++) {
                    inputs_slice[chan] = &(inputs[chan][offset]);
                }
                
                FAUSTFLOAT** outputs_slice = (FAUSTFLOAT**)alloca(dsp->getNumOutputs() * sizeof(FAUSTFLOAT*));
                for (int chan = 0; chan < dsp->getNumOutputs(); chan++) {
                    outputs_slice[chan] = &(outputs[chan][offset]);
                }
                
                dsp->compute(slice, inputs_slice, outputs_slice);
            } 
        }
        
        inline unsigned int isPowerOfTwo(unsigned int n)
        {
            return !(n & (n - 1));
        }
    
        // Always returns a voice
        int newVoiceAux()
        {
            int voice = getVoice(kFreeVoice, true);
            assert(voice != kNoVoice);
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }
    
    public:
    
        /**
         * Constructor.
         *
         * @param max_polyphony - number of voices of polyphony
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler). 
         *                 If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                 a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(int max_polyphony,
                bool control = false,   
                bool group = true):fGroups(&fPanic, panic, this)
        {
            fVoiceFactory = new mydsp_voice_factory();
            init(max_polyphony, fVoiceFactory, control, group);
        }
    
        void metadata(Meta* meta) { fVoiceFactory->metadata(meta); }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < fNumOutputs; i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
            
            for (int i = 0; i < fPolyphony; i++) {
                delete fVoiceTable[i];
            }
            
            delete fVoiceGroup;
            
            // Remove object from all MidiUI interfaces that handle it
            for (int i = 0; i < fMidiUIList.size(); i++) {
                fMidiUIList[i]->removeMidiIn(this); 
            }
            
            delete fVoiceFactory;
        }
    
        void init(int sample_rate)
        {
            // Init voices
            for (int i = 0; i < fPolyphony; i++) {
                fVoiceTable[i]->init(sample_rate);
            }
        }
    
        void instanceInit(int sample_rate)
        {
            // Init voices
            for (int i = 0; i < fPolyphony; i++) {
                fVoiceTable[i]->instanceInit(sample_rate);
            }
        }
    
        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);
            
            // First clear the outputs
            clearOutput(count, outputs);
            
            if (fVoiceControl) {
                // Mix all playing voices
                for (int i = 0; i < fPolyphony; i++) {
                    if (fVoiceTable[i]->fNote != kFreeVoice) {
                        if (fVoiceTable[i]->fTrigger) {
                            //If stolen note and need for envelop re-trigger
                            int slice = isPowerOfTwo(count) ? count/2 : 1;
                            fVoiceTable[i]->setParamValue(fGateLabel, 0.0f);
                            computeSlice(fVoiceTable[i], 0, slice, inputs, fMixBuffer);
                            fVoiceTable[i]->setParamValue(fGateLabel, 1.0f);
                            computeSlice(fVoiceTable[i], slice, count - slice, inputs, fMixBuffer);
                            fVoiceTable[i]->fTrigger = false;
                        } else {
                            // Compute regular voice
                            fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                        }
                        // Mix it in result
                        fVoiceTable[i]->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((fVoiceTable[i]->fLevel < VOICE_STOP_LEVEL) && (fVoiceTable[i]->fNote == kReleaseVoice)) {
                            fVoiceTable[i]->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (int i = 0; i < fPolyphony; i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }
        
        int getNumInputs()
        {
            return fVoiceTable[0]->getNumInputs();
        }
        
        int getNumOutputs()
        {
            return fVoiceTable[0]->getNumOutputs();
        }
        
        void buildUserInterface(UI* ui_interface) 
        {   
            // Add itself to the MidiUI object
            MidiUI* midi_ui = dynamic_cast<MidiUI*>(ui_interface);
            if (midi_ui) { 
                fMidiUIList.push_back(midi_ui);
                midi_ui->addMidiIn(this); 
            }
            
            if (fPolyphony > 1) {
                uIBuilder(ui_interface);
            } else {
                fVoiceTable[0]->buildUserInterface(ui_interface);
            }
        }
    
        MapUI* newVoice()
        {
            return fVoiceTable[newVoiceAux()];
        }
        
        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->setParamValue(fGateLabel, 0.0f);
                // Release voice
                (*it)->fNote = kReleaseVoice;
            } else {
                printf("Voice not found\n");
            }
        }
        
        // Pure MIDI control
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = newVoiceAux();
                fVoiceTable[voice]->setParamValue(fFreqLabel, midiToFreq(pitch));
                fVoiceTable[voice]->setParamValue(fGainLabel, float(velocity)/127.f);
                fVoiceTable[voice]->setParamValue(fGateLabel, 1.0f);
                fVoiceTable[voice]->fNote = pitch;
                return fVoiceTable[voice];
            }
            
            return 0;
        }
        
        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getVoice(pitch);
                if (voice != kNoVoice) {
                    // No use of velocity for now...
                    fVoiceTable[voice]->setParamValue(fGateLabel, 0.0f);
                    // Release voice
                    fVoiceTable[voice]->fNote = kReleaseVoice;
                } else {
                    printf("Playing pitch = %d not found\n", pitch);
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
 
        // Additional API
        void allNotesOff()
        {
            if (checkPolyphony()) {
                for (int i = 0; i < fPolyphony; i++) {
                    fVoiceTable[i]->setParamValue(fGateLabel, 0.0f);
                    fVoiceTable[i]->fNote = kReleaseVoice;
                    fVoiceTable[i]->fTrigger = false;
                }
            }
        }
};

#endif // __poly_dsp__
#endif

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

		virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0,1.0,f);}
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            sprintf(buffer, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            sprintf(buffer, "Button(double): %s", fLabel.c_str());
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
            stringstream s; 
            s << "Slider(double): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
		}

		void setValue(FAUSTFLOAT f) {*fZone = range(fMin,fMax,f);}
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
            stringstream s; 
            s << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
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
        
        string name = string((s)->s_name);
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
            
            stringstream num_val;
            num_val << num + i;
            char param_name[256];
            
            switch (ndigit - count_digit(num_val.str())) {
                case 0: 
                    sprintf(param_name, "%s%s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 1: 
                    sprintf(param_name, "%s %s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 2: 
                    sprintf(param_name, "%s  %s", prefix.c_str(), num_val.str().c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name, value); 
            
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
#ifdef POLY
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            obj->m_dsp = new mydsp_poly(av[0].a_w.w_long, true, true);
        } else {
            obj->m_dsp = new mydsp();
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_dsp->buildUserInterface(obj->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        obj->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(obj);
      
        // Send JSON to JS script
        faust_create_jsui(obj);
    
        systhread_mutex_unlock(obj->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}
#endif

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* obj, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            obj->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            obj->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            obj->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
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
            post("Generate UI from JSON...");
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
    mydsp::metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    x->m_dsp = new mydsp();
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
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
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    post((char*)"------------------");
    for (mspUI::iterator it = x->m_dspUI->begin1(); it != x->m_dspUI->end1(); ++it) {
        char param[1024];
        it->second->toString(param);
        post(param);
    }
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher... to we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
            /*
			post((char*)"------------------");
			for (mspUI::iterator it = x->m_dspUI->begin1(); it != x->m_dspUI->end1(); ++it) {
				char param[1024];
				it->second->toString(param);
				post(param);
			}
            */
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
    delete x->m_midiHandler;
    delete x->m_midiUI;
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
            faust_update_outputs(x);
        }
    #ifdef MIDICTRL
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
#ifdef POLY
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
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
    post((char*)"Copyright (c) 2012-2016 Grame");
    Max_Meta1 meta1;
    mydsp::metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        mydsp::metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/




