//----------------------------------------------------------
// author: "Alain Bonardi"
// name: "mTRandomEnv"
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

        virtual int getNumInputs() 										= 0;
        virtual int getNumOutputs() 									= 0;
        virtual void buildUserInterface(UI* ui_interface) 				= 0;
        virtual void init(int samplingRate) 							= 0;
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 	= 0;
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

        virtual int getNumInputs()                          { return fDSP->getNumInputs(); }
        virtual int getNumOutputs()                         { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface)   { fDSP->buildUserInterface(ui_interface); }
        virtual void init(int samplingRate)                 { fDSP->init(samplingRate); }
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
inline int int2pow2(int x)		{ int r=0; while ((1<<r)<x) r++; return r; }

long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

const char* lopts(char* argv[], const char* name, const char* def)
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
		int 	iRec0[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec0[i] = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				iRec0[0] = (1 + iRec0[1]);
				output[i] = sin((9.587379924285257e-05 * double((iRec0[0] - 1))));
				// post processing
				iRec0[1] = iRec0[0];
			}
		}
	};


	static double 	ftbl0[65536];
	FAUSTFLOAT 	fentry0;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fRec2[2];
	double 	fConst3;
	double 	fRec1[2];
	double 	fVec0[2];
	FAUSTFLOAT 	fslider0;
	double 	fRec4[2];
	int 	iRec5[2];
	int 	iRec3[2];
	int 	iRec13[2];
	int 	iRec14[2];
	int 	iRec15[2];
	int 	iRec16[2];
	int 	iRec17[2];
	int 	iRec18[2];
	int 	iRec19[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("library_path", "mTRandomEnv8");
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
		m->declare("name", "mTRandomEnv");
	}

	virtual int getNumInputs() 	{ return 8; }
	virtual int getNumOutputs() 	{ return 8; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fentry0 = 1e+01;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = exp((0 - (5e+01 / double(iConst0))));
		fConst2 = (1.0 - fConst1);
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fConst3 = (1.0 / double(iConst0));
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		fslider0 = 0.5;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) iRec5[i] = 0;
		for (int i=0; i<2; i++) iRec3[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) iRec16[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) iRec19[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("RandomEnv");
		interface->addNumEntry("freq", &fentry0, 1e+01, 0.01, 1e+02, 0.01);
		interface->addHorizontalSlider("shortening", &fslider0, 0.5, 0.0, 1.0, 0.01);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		double 	fSlow0 = (fConst2 * double(fentry0));
		double 	fSlow1 = (fConst2 * double(fslider0));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* input6 = input[6];
		FAUSTFLOAT* input7 = input[7];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		for (int i=0; i<count; i++) {
			fRec2[0] = ((fConst1 * fRec2[1]) + fSlow0);
			fRec1[0] = fmod((fRec1[1] + (fConst3 * double(fRec2[0]))),1.0);
			double fTemp0 = ((int((fRec2[0] > 0)))?fRec1[0]:(1.0 + fRec1[0]));
			fVec0[0] = fTemp0;
			double fTemp1 = (32768.0 * fVec0[0]);
			int iTemp2 = int(fTemp1);
			double fTemp3 = ftbl0[iTemp2];
			double fTemp4 = (fTemp3 + ((fTemp1 - floor(fTemp1)) * (ftbl0[((1 + iTemp2) % 65536)] - fTemp3)));
			fRec4[0] = ((fConst1 * fRec4[1]) + fSlow1);
			double fTemp5 = ((2 * fRec4[0]) - 1);
			int iTemp6 = (1103515245 * (12345 + iRec5[1]));
			int iTemp7 = (1103515245 * (12345 + iTemp6));
			int iTemp8 = (1103515245 * (12345 + iTemp7));
			int iTemp9 = (1103515245 * (12345 + iTemp8));
			int iTemp10 = (1103515245 * (12345 + iTemp9));
			int iTemp11 = (1103515245 * (12345 + iTemp10));
			int iTemp12 = (1103515245 * (12345 + iTemp11));
			iRec5[0] = (1103515245 * (12345 + iTemp12));
			int 	iRec6 = iTemp12;
			int 	iRec7 = iTemp11;
			int 	iRec8 = iTemp10;
			int 	iRec9 = iTemp9;
			int 	iRec10 = iTemp8;
			int 	iRec11 = iTemp7;
			int 	iRec12 = iTemp6;
			int iTemp13 = ((fVec0[0] > 0.001) * (fVec0[1] <= 0.001));
			int iTemp14 = (1 - iTemp13);
			iRec3[0] = ((iTemp14 * iRec3[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec5[0]) > fTemp5)));
			output0[i] = (FAUSTFLOAT)(((double)input0[i] * iRec3[0]) * fTemp4);
			iRec13[0] = ((iTemp14 * iRec13[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec6) > fTemp5)));
			output1[i] = (FAUSTFLOAT)(((double)input1[i] * iRec13[0]) * fTemp4);
			iRec14[0] = ((iTemp14 * iRec14[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec7) > fTemp5)));
			output2[i] = (FAUSTFLOAT)(((double)input2[i] * iRec14[0]) * fTemp4);
			iRec15[0] = ((iTemp14 * iRec15[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec8) > fTemp5)));
			output3[i] = (FAUSTFLOAT)(((double)input3[i] * iRec15[0]) * fTemp4);
			iRec16[0] = ((iTemp14 * iRec16[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec9) > fTemp5)));
			output4[i] = (FAUSTFLOAT)(((double)input4[i] * iRec16[0]) * fTemp4);
			iRec17[0] = ((iTemp14 * iRec17[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec10) > fTemp5)));
			output5[i] = (FAUSTFLOAT)(((double)input5[i] * iRec17[0]) * fTemp4);
			iRec18[0] = ((iTemp14 * iRec18[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec11) > fTemp5)));
			output6[i] = (FAUSTFLOAT)(((double)input6[i] * iRec18[0]) * fTemp4);
			iRec19[0] = ((iTemp14 * iRec19[1]) + (iTemp13 * ((4.656612875245797e-10 * iRec12) > fTemp5)));
			output7[i] = (FAUSTFLOAT)(((double)input7[i] * iRec19[0]) * fTemp4);
			// post processing
			iRec19[1] = iRec19[0];
			iRec18[1] = iRec18[0];
			iRec17[1] = iRec17[0];
			iRec16[1] = iRec16[0];
			iRec15[1] = iRec15[0];
			iRec14[1] = iRec14[0];
			iRec13[1] = iRec13[0];
			iRec3[1] = iRec3[0];
			iRec5[1] = iRec5[0];
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
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

#define EXTERNAL_VERSION "0.55"

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
    map<string, t_object*> m_output_table;
    short m_where;
    bool m_mute;
    void** args;
    mspUI* dspUI;
    mydsp* dsp;
    char* m_json;
} t_faust;

void *faust_class;

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
        if (isdigit(name[i])) return true;
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) count++;
    }
    return count;
}

void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    bool res = false;
    string name = string((s)->s_name);
     
    if (ac < 0) return;
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->dspUI->isValue(name)) {
        
        string name = string((s)->s_name);
        float off = 0.0f;
        float on = 1.0f;
        obj->dspUI->setValue(name, off);
        obj->dspUI->setValue(name, on);
        
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
                case A_LONG: {
                    value = (float)ap[0].a_w.w_long;
                    break;
                }
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
            res = obj->dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

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
        t_symbol *scriptingname = jbox_get_varname(obj); // scripting name
        if (scriptingname && x->dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name] = obj;
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, t_object*>::iterator it;
    for (it =  x->m_output_table.begin(); it != x->m_output_table.end(); it++) {
        FAUSTFLOAT value = x->dspUI->isOutputValue((*it).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            object_method_typed((*it).second, gensym("float"), 1, &at_value, 0);
        }
    }
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_mute = false;

    x->dsp = new mydsp();
    x->dspUI = new mspUI();

    x->dsp->init(long(sys_getsr()));
    x->dsp->buildUserInterface(x->dspUI);
    
    // Prepare JSON
    JSONUI builder(x->dsp->getNumInputs(), x->dsp->getNumOutputs());
    x->dsp->metadata(&builder);
    x->dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
    
    int num_input;
    
    if (x->dspUI->isMulti()) {
        num_input = x->dsp->getNumInputs() + 1;
    } else {
        num_input = x->dsp->getNumInputs();
    }
    
    x->args = (void**)calloc((num_input + x->dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different
    
    // send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    post((char*)"------------------");
    for (mspUI::iterator it = x->dspUI->begin1(); it != x->dspUI->end1(); ++it) {
        char param[256];
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
            if (x->dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
            /*
			post((char*)"------------------");
			for (mspUI::iterator it = x->dspUI->begin1(); it != x->dspUI->end1(); ++it) {
				char param[256];
				it->second->toString(param);
				post(param);
			}
            */
        } else if (a < x->dsp->getNumInputs()) {
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
	if (x->dsp) delete x->dsp;
	if (x->dspUI) delete x->dspUI;
	if (x->args) free(x->args);
    if (x->m_json) free(x->m_json);
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (x->m_mute) {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    } else {
        if (x->dspUI->isMulti()) {
            x->dspUI->setMultiValues(ins[0], sampleframes);
            x->dsp->compute(sampleframes, ++ins, outs);
        } else {
            x->dsp->compute(sampleframes, ins, outs);
        }
        faust_update_outputs(x);
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

	dsp* thedsp = new mydsp();
    mspUI dspUI;
	thedsp->buildUserInterface(&dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2015 Grame");
    Max_Meta1 meta1;
    mydsp::metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        mydsp::metadata(&meta2);
        post("------------------------------");
    }
    
    delete(thedsp);
	return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/




