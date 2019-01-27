//----------------------------------------------------------
// name: "FilDeSoi1SoundProcess"
//
// Code generated with Faust 0.9.96 (http://faust.grame.fr)
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


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
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
struct Meta;

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
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** Global init, calls the following methods:
         * - static class 'classInit': static table initialisation
         * - 'instanceInit': constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Herz
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
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
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
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
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


#ifdef POLY2
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

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>

// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
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
            delete fDSP1;
            delete fDSP2;
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
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
         
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {}
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
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
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            FAUSTFLOAT** inputs_dsp2 = (FAUSTFLOAT**)alloca(fDSP2->getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                inputs_dsp2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            
            FAUSTFLOAT** outputs_dsp2 = (FAUSTFLOAT**)alloca(fDSP2->getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                outputs_dsp2[chan] = inputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, inputs_dsp2, outputs_dsp2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
#include "effect.cpp"
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
		int fSamplingFreq;
		int 	iRec17[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec17[i] = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				iRec17[0] = (iRec17[1] + 1);
				output[i] = sin((9.587379924285257e-05 * double((iRec17[0] + -1))));
				// post processing
				iRec17[1] = iRec17[0];
			}
		}
	};


	FAUSTFLOAT 	fcheckbox0;
	FAUSTFLOAT 	fcheckbox1;
	FAUSTFLOAT 	fcheckbox2;
	FAUSTFLOAT 	fcheckbox3;
	FAUSTFLOAT 	fcheckbox4;
	FAUSTFLOAT 	fslider0;
	double 	fConst0;
	double 	fConst1;
	FAUSTFLOAT 	fslider1;
	double 	fRec0[2];
	FAUSTFLOAT 	fcheckbox5;
	FAUSTFLOAT 	fcheckbox6;
	FAUSTFLOAT 	fcheckbox7;
	FAUSTFLOAT 	fcheckbox8;
	FAUSTFLOAT 	fcheckbox9;
	static double 	ftbl0[65536];
	double 	fConst2;
	double 	fConst3;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	double 	fVec0[2];
	double 	fConst4;
	double 	fRec19[2];
	double 	fRec20[2];
	double 	fRec18[2];
	double 	fVec1[2];
	double 	fConst5;
	double 	fRec21[2];
	FAUSTFLOAT 	fslider5;
	double 	fConst6;
	double 	fRec22[2];
	double 	fVec2[2];
	FAUSTFLOAT 	fcheckbox10;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	double 	fRec23[2];
	FAUSTFLOAT 	fcheckbox11;
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	double 	fRec24[2];
	FAUSTFLOAT 	fcheckbox12;
	FAUSTFLOAT 	fslider10;
	double 	fRec25[2];
	FAUSTFLOAT 	fcheckbox13;
	FAUSTFLOAT 	fslider11;
	FAUSTFLOAT 	fslider12;
	double 	fRec26[2];
	FAUSTFLOAT 	fcheckbox14;
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	double 	fRec27[2];
	FAUSTFLOAT 	fslider15;
	double 	fRec28[2];
	FAUSTFLOAT 	fslider16;
	double 	fRec29[2];
	FAUSTFLOAT 	fcheckbox15;
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	double 	fRec30[2];
	FAUSTFLOAT 	fcheckbox16;
	FAUSTFLOAT 	fslider19;
	FAUSTFLOAT 	fslider20;
	double 	fRec31[2];
	FAUSTFLOAT 	fcheckbox17;
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	double 	fRec32[2];
	FAUSTFLOAT 	fcheckbox18;
	FAUSTFLOAT 	fslider23;
	FAUSTFLOAT 	fslider24;
	double 	fRec33[2];
	FAUSTFLOAT 	fcheckbox19;
	FAUSTFLOAT 	fslider25;
	FAUSTFLOAT 	fslider26;
	double 	fRec34[2];
	FAUSTFLOAT 	fcheckbox20;
	FAUSTFLOAT 	fslider27;
	FAUSTFLOAT 	fslider28;
	double 	fRec35[2];
	FAUSTFLOAT 	fcheckbox21;
	FAUSTFLOAT 	fslider29;
	FAUSTFLOAT 	fslider30;
	double 	fRec36[2];
	FAUSTFLOAT 	fcheckbox22;
	FAUSTFLOAT 	fslider31;
	FAUSTFLOAT 	fslider32;
	double 	fRec37[2];
	FAUSTFLOAT 	fcheckbox23;
	FAUSTFLOAT 	fslider33;
	FAUSTFLOAT 	fslider34;
	double 	fRec38[2];
	FAUSTFLOAT 	fcheckbox24;
	FAUSTFLOAT 	fslider35;
	FAUSTFLOAT 	fslider36;
	double 	fRec39[2];
	FAUSTFLOAT 	fcheckbox25;
	FAUSTFLOAT 	fslider37;
	FAUSTFLOAT 	fslider38;
	double 	fRec40[2];
	int 	IOTA;
	double 	fVec3[1048576];
	FAUSTFLOAT 	fslider39;
	FAUSTFLOAT 	fslider40;
	int 	iRec41[2];
	double 	fVec4[2];
	int 	iRec42[2];
	double 	fVec5[262144];
	double 	fVec6[2];
	double 	fRec43[2];
	double 	fVec7[2];
	double 	fRec44[2];
	double 	fVec8[2];
	double 	fRec45[2];
	double 	fRec1[2];
	FAUSTFLOAT 	fslider41;
	double 	fRec46[2];
	double 	fVec9[2];
	double 	fRec47[2];
	FAUSTFLOAT 	fcheckbox26;
	FAUSTFLOAT 	fcheckbox27;
	FAUSTFLOAT 	fcheckbox28;
	FAUSTFLOAT 	fcheckbox29;
	FAUSTFLOAT 	fcheckbox30;
	FAUSTFLOAT 	fslider42;
	double 	fRec48[2];
	FAUSTFLOAT 	fcheckbox31;
	FAUSTFLOAT 	fcheckbox32;
	FAUSTFLOAT 	fcheckbox33;
	FAUSTFLOAT 	fcheckbox34;
	FAUSTFLOAT 	fcheckbox35;
	FAUSTFLOAT 	fcheckbox36;
	FAUSTFLOAT 	fcheckbox37;
	FAUSTFLOAT 	fcheckbox38;
	FAUSTFLOAT 	fcheckbox39;
	FAUSTFLOAT 	fcheckbox40;
	FAUSTFLOAT 	fcheckbox41;
	double 	fVec10[1048576];
	FAUSTFLOAT 	fslider43;
	int 	iRec49[2];
	int 	iRec50[2];
	double 	fVec11[262144];
	double 	fVec12[2];
	double 	fRec51[2];
	double 	fVec13[2];
	double 	fRec52[2];
	double 	fVec14[2];
	double 	fRec53[2];
	double 	fRec2[2];
	FAUSTFLOAT 	fslider44;
	double 	fRec54[2];
	double 	fVec15[2];
	double 	fRec55[2];
	FAUSTFLOAT 	fcheckbox42;
	FAUSTFLOAT 	fcheckbox43;
	FAUSTFLOAT 	fcheckbox44;
	FAUSTFLOAT 	fcheckbox45;
	FAUSTFLOAT 	fcheckbox46;
	FAUSTFLOAT 	fslider45;
	double 	fRec56[2];
	FAUSTFLOAT 	fcheckbox47;
	FAUSTFLOAT 	fcheckbox48;
	FAUSTFLOAT 	fcheckbox49;
	FAUSTFLOAT 	fcheckbox50;
	FAUSTFLOAT 	fcheckbox51;
	FAUSTFLOAT 	fcheckbox52;
	FAUSTFLOAT 	fcheckbox53;
	FAUSTFLOAT 	fcheckbox54;
	FAUSTFLOAT 	fcheckbox55;
	FAUSTFLOAT 	fcheckbox56;
	FAUSTFLOAT 	fcheckbox57;
	double 	fVec16[1048576];
	FAUSTFLOAT 	fslider46;
	int 	iRec57[2];
	int 	iRec58[2];
	double 	fVec17[262144];
	double 	fVec18[2];
	double 	fRec59[2];
	double 	fVec19[2];
	double 	fRec60[2];
	double 	fVec20[2];
	double 	fRec61[2];
	double 	fRec3[2];
	FAUSTFLOAT 	fslider47;
	double 	fRec62[2];
	double 	fVec21[2];
	double 	fRec63[2];
	FAUSTFLOAT 	fcheckbox58;
	FAUSTFLOAT 	fcheckbox59;
	FAUSTFLOAT 	fcheckbox60;
	FAUSTFLOAT 	fcheckbox61;
	FAUSTFLOAT 	fcheckbox62;
	FAUSTFLOAT 	fslider48;
	double 	fRec64[2];
	FAUSTFLOAT 	fcheckbox63;
	FAUSTFLOAT 	fcheckbox64;
	FAUSTFLOAT 	fcheckbox65;
	FAUSTFLOAT 	fcheckbox66;
	FAUSTFLOAT 	fcheckbox67;
	FAUSTFLOAT 	fcheckbox68;
	FAUSTFLOAT 	fcheckbox69;
	FAUSTFLOAT 	fcheckbox70;
	FAUSTFLOAT 	fcheckbox71;
	FAUSTFLOAT 	fcheckbox72;
	FAUSTFLOAT 	fcheckbox73;
	double 	fVec22[1048576];
	FAUSTFLOAT 	fslider49;
	int 	iRec65[2];
	int 	iRec66[2];
	double 	fVec23[262144];
	double 	fVec24[2];
	double 	fRec67[2];
	double 	fVec25[2];
	double 	fRec68[2];
	double 	fVec26[2];
	double 	fRec69[2];
	double 	fRec4[2];
	FAUSTFLOAT 	fslider50;
	double 	fRec70[2];
	double 	fVec27[2];
	double 	fRec71[2];
	FAUSTFLOAT 	fcheckbox74;
	FAUSTFLOAT 	fcheckbox75;
	FAUSTFLOAT 	fcheckbox76;
	FAUSTFLOAT 	fcheckbox77;
	FAUSTFLOAT 	fcheckbox78;
	FAUSTFLOAT 	fslider51;
	double 	fRec72[2];
	FAUSTFLOAT 	fcheckbox79;
	FAUSTFLOAT 	fcheckbox80;
	FAUSTFLOAT 	fcheckbox81;
	FAUSTFLOAT 	fcheckbox82;
	FAUSTFLOAT 	fcheckbox83;
	FAUSTFLOAT 	fcheckbox84;
	FAUSTFLOAT 	fcheckbox85;
	FAUSTFLOAT 	fcheckbox86;
	FAUSTFLOAT 	fcheckbox87;
	FAUSTFLOAT 	fcheckbox88;
	FAUSTFLOAT 	fcheckbox89;
	double 	fVec28[1048576];
	FAUSTFLOAT 	fslider52;
	int 	iRec73[2];
	int 	iRec74[2];
	double 	fVec29[262144];
	double 	fVec30[2];
	double 	fRec75[2];
	double 	fVec31[2];
	double 	fRec76[2];
	double 	fVec32[2];
	double 	fRec77[2];
	double 	fRec5[2];
	FAUSTFLOAT 	fslider53;
	double 	fRec78[2];
	double 	fVec33[2];
	double 	fRec79[2];
	FAUSTFLOAT 	fcheckbox90;
	FAUSTFLOAT 	fcheckbox91;
	FAUSTFLOAT 	fcheckbox92;
	FAUSTFLOAT 	fcheckbox93;
	FAUSTFLOAT 	fcheckbox94;
	FAUSTFLOAT 	fslider54;
	double 	fRec80[2];
	FAUSTFLOAT 	fcheckbox95;
	FAUSTFLOAT 	fcheckbox96;
	FAUSTFLOAT 	fcheckbox97;
	FAUSTFLOAT 	fcheckbox98;
	FAUSTFLOAT 	fcheckbox99;
	FAUSTFLOAT 	fcheckbox100;
	FAUSTFLOAT 	fcheckbox101;
	FAUSTFLOAT 	fcheckbox102;
	FAUSTFLOAT 	fcheckbox103;
	FAUSTFLOAT 	fcheckbox104;
	FAUSTFLOAT 	fcheckbox105;
	double 	fVec34[1048576];
	FAUSTFLOAT 	fslider55;
	int 	iRec81[2];
	int 	iRec82[2];
	double 	fVec35[262144];
	double 	fVec36[2];
	double 	fRec83[2];
	double 	fVec37[2];
	double 	fRec84[2];
	double 	fVec38[2];
	double 	fRec85[2];
	double 	fRec6[2];
	FAUSTFLOAT 	fslider56;
	double 	fRec86[2];
	double 	fVec39[2];
	double 	fRec87[2];
	FAUSTFLOAT 	fcheckbox106;
	FAUSTFLOAT 	fcheckbox107;
	FAUSTFLOAT 	fcheckbox108;
	FAUSTFLOAT 	fcheckbox109;
	FAUSTFLOAT 	fcheckbox110;
	FAUSTFLOAT 	fslider57;
	double 	fRec88[2];
	FAUSTFLOAT 	fcheckbox111;
	FAUSTFLOAT 	fcheckbox112;
	FAUSTFLOAT 	fcheckbox113;
	FAUSTFLOAT 	fcheckbox114;
	FAUSTFLOAT 	fcheckbox115;
	FAUSTFLOAT 	fcheckbox116;
	FAUSTFLOAT 	fcheckbox117;
	FAUSTFLOAT 	fcheckbox118;
	FAUSTFLOAT 	fcheckbox119;
	FAUSTFLOAT 	fcheckbox120;
	FAUSTFLOAT 	fcheckbox121;
	double 	fVec40[1048576];
	FAUSTFLOAT 	fslider58;
	int 	iRec89[2];
	int 	iRec90[2];
	double 	fVec41[262144];
	double 	fVec42[2];
	double 	fRec91[2];
	double 	fVec43[2];
	double 	fRec92[2];
	double 	fVec44[2];
	double 	fRec93[2];
	double 	fRec7[2];
	FAUSTFLOAT 	fslider59;
	double 	fRec94[2];
	double 	fVec45[2];
	double 	fRec95[2];
	FAUSTFLOAT 	fcheckbox122;
	FAUSTFLOAT 	fcheckbox123;
	FAUSTFLOAT 	fcheckbox124;
	FAUSTFLOAT 	fcheckbox125;
	FAUSTFLOAT 	fcheckbox126;
	FAUSTFLOAT 	fslider60;
	double 	fRec96[2];
	FAUSTFLOAT 	fcheckbox127;
	FAUSTFLOAT 	fcheckbox128;
	FAUSTFLOAT 	fcheckbox129;
	FAUSTFLOAT 	fcheckbox130;
	FAUSTFLOAT 	fcheckbox131;
	FAUSTFLOAT 	fcheckbox132;
	FAUSTFLOAT 	fcheckbox133;
	FAUSTFLOAT 	fcheckbox134;
	FAUSTFLOAT 	fcheckbox135;
	FAUSTFLOAT 	fcheckbox136;
	FAUSTFLOAT 	fcheckbox137;
	double 	fVec46[1048576];
	FAUSTFLOAT 	fslider61;
	int 	iRec97[2];
	int 	iRec98[2];
	double 	fVec47[262144];
	double 	fVec48[2];
	double 	fRec99[2];
	double 	fVec49[2];
	double 	fRec100[2];
	double 	fVec50[2];
	double 	fRec101[2];
	double 	fRec8[2];
	FAUSTFLOAT 	fslider62;
	double 	fRec102[2];
	double 	fVec51[2];
	double 	fRec103[2];
	FAUSTFLOAT 	fcheckbox138;
	FAUSTFLOAT 	fcheckbox139;
	FAUSTFLOAT 	fcheckbox140;
	FAUSTFLOAT 	fcheckbox141;
	FAUSTFLOAT 	fcheckbox142;
	FAUSTFLOAT 	fslider63;
	double 	fRec104[2];
	FAUSTFLOAT 	fcheckbox143;
	FAUSTFLOAT 	fcheckbox144;
	FAUSTFLOAT 	fcheckbox145;
	FAUSTFLOAT 	fcheckbox146;
	FAUSTFLOAT 	fcheckbox147;
	FAUSTFLOAT 	fcheckbox148;
	FAUSTFLOAT 	fcheckbox149;
	FAUSTFLOAT 	fcheckbox150;
	FAUSTFLOAT 	fcheckbox151;
	FAUSTFLOAT 	fcheckbox152;
	FAUSTFLOAT 	fcheckbox153;
	double 	fVec52[1048576];
	FAUSTFLOAT 	fslider64;
	int 	iRec105[2];
	int 	iRec106[2];
	double 	fVec53[262144];
	double 	fVec54[2];
	double 	fRec107[2];
	double 	fVec55[2];
	double 	fRec108[2];
	double 	fVec56[2];
	double 	fRec109[2];
	double 	fRec9[2];
	FAUSTFLOAT 	fslider65;
	double 	fRec110[2];
	double 	fVec57[2];
	double 	fRec111[2];
	FAUSTFLOAT 	fcheckbox154;
	FAUSTFLOAT 	fcheckbox155;
	FAUSTFLOAT 	fcheckbox156;
	FAUSTFLOAT 	fcheckbox157;
	FAUSTFLOAT 	fcheckbox158;
	FAUSTFLOAT 	fslider66;
	double 	fRec112[2];
	FAUSTFLOAT 	fcheckbox159;
	FAUSTFLOAT 	fcheckbox160;
	FAUSTFLOAT 	fcheckbox161;
	FAUSTFLOAT 	fcheckbox162;
	FAUSTFLOAT 	fcheckbox163;
	FAUSTFLOAT 	fcheckbox164;
	FAUSTFLOAT 	fcheckbox165;
	FAUSTFLOAT 	fcheckbox166;
	FAUSTFLOAT 	fcheckbox167;
	FAUSTFLOAT 	fcheckbox168;
	FAUSTFLOAT 	fcheckbox169;
	double 	fVec58[1048576];
	FAUSTFLOAT 	fslider67;
	int 	iRec113[2];
	int 	iRec114[2];
	double 	fVec59[262144];
	double 	fVec60[2];
	double 	fRec115[2];
	double 	fVec61[2];
	double 	fRec116[2];
	double 	fVec62[2];
	double 	fRec117[2];
	double 	fRec10[2];
	FAUSTFLOAT 	fslider68;
	double 	fRec118[2];
	double 	fVec63[2];
	double 	fRec119[2];
	FAUSTFLOAT 	fcheckbox170;
	FAUSTFLOAT 	fcheckbox171;
	FAUSTFLOAT 	fcheckbox172;
	FAUSTFLOAT 	fcheckbox173;
	FAUSTFLOAT 	fcheckbox174;
	FAUSTFLOAT 	fslider69;
	double 	fRec120[2];
	FAUSTFLOAT 	fcheckbox175;
	FAUSTFLOAT 	fcheckbox176;
	FAUSTFLOAT 	fcheckbox177;
	FAUSTFLOAT 	fcheckbox178;
	FAUSTFLOAT 	fcheckbox179;
	FAUSTFLOAT 	fcheckbox180;
	FAUSTFLOAT 	fcheckbox181;
	FAUSTFLOAT 	fcheckbox182;
	FAUSTFLOAT 	fcheckbox183;
	FAUSTFLOAT 	fcheckbox184;
	FAUSTFLOAT 	fcheckbox185;
	double 	fVec64[1048576];
	FAUSTFLOAT 	fslider70;
	int 	iRec121[2];
	int 	iRec122[2];
	double 	fVec65[262144];
	double 	fVec66[2];
	double 	fRec123[2];
	double 	fVec67[2];
	double 	fRec124[2];
	double 	fVec68[2];
	double 	fRec125[2];
	double 	fRec11[2];
	FAUSTFLOAT 	fslider71;
	double 	fRec126[2];
	double 	fVec69[2];
	double 	fRec127[2];
	FAUSTFLOAT 	fcheckbox186;
	FAUSTFLOAT 	fcheckbox187;
	FAUSTFLOAT 	fcheckbox188;
	FAUSTFLOAT 	fcheckbox189;
	FAUSTFLOAT 	fcheckbox190;
	FAUSTFLOAT 	fslider72;
	double 	fRec128[2];
	FAUSTFLOAT 	fcheckbox191;
	FAUSTFLOAT 	fcheckbox192;
	FAUSTFLOAT 	fcheckbox193;
	FAUSTFLOAT 	fcheckbox194;
	FAUSTFLOAT 	fcheckbox195;
	FAUSTFLOAT 	fcheckbox196;
	FAUSTFLOAT 	fcheckbox197;
	FAUSTFLOAT 	fcheckbox198;
	FAUSTFLOAT 	fcheckbox199;
	FAUSTFLOAT 	fcheckbox200;
	FAUSTFLOAT 	fcheckbox201;
	double 	fVec70[1048576];
	FAUSTFLOAT 	fslider73;
	int 	iRec129[2];
	int 	iRec130[2];
	double 	fVec71[262144];
	double 	fVec72[2];
	double 	fRec131[2];
	double 	fVec73[2];
	double 	fRec132[2];
	double 	fVec74[2];
	double 	fRec133[2];
	double 	fRec12[2];
	FAUSTFLOAT 	fslider74;
	double 	fRec134[2];
	double 	fVec75[2];
	double 	fRec135[2];
	FAUSTFLOAT 	fcheckbox202;
	FAUSTFLOAT 	fcheckbox203;
	FAUSTFLOAT 	fcheckbox204;
	FAUSTFLOAT 	fcheckbox205;
	FAUSTFLOAT 	fcheckbox206;
	FAUSTFLOAT 	fslider75;
	double 	fRec136[2];
	FAUSTFLOAT 	fcheckbox207;
	FAUSTFLOAT 	fcheckbox208;
	FAUSTFLOAT 	fcheckbox209;
	FAUSTFLOAT 	fcheckbox210;
	FAUSTFLOAT 	fcheckbox211;
	FAUSTFLOAT 	fcheckbox212;
	FAUSTFLOAT 	fcheckbox213;
	FAUSTFLOAT 	fcheckbox214;
	FAUSTFLOAT 	fcheckbox215;
	FAUSTFLOAT 	fcheckbox216;
	FAUSTFLOAT 	fcheckbox217;
	double 	fVec76[1048576];
	FAUSTFLOAT 	fslider76;
	int 	iRec137[2];
	int 	iRec138[2];
	double 	fVec77[262144];
	double 	fVec78[2];
	double 	fRec139[2];
	double 	fVec79[2];
	double 	fRec140[2];
	double 	fVec80[2];
	double 	fRec141[2];
	double 	fRec13[2];
	FAUSTFLOAT 	fslider77;
	double 	fRec142[2];
	double 	fVec81[2];
	double 	fRec143[2];
	FAUSTFLOAT 	fcheckbox218;
	FAUSTFLOAT 	fcheckbox219;
	FAUSTFLOAT 	fcheckbox220;
	FAUSTFLOAT 	fcheckbox221;
	FAUSTFLOAT 	fcheckbox222;
	FAUSTFLOAT 	fslider78;
	double 	fRec144[2];
	FAUSTFLOAT 	fcheckbox223;
	FAUSTFLOAT 	fcheckbox224;
	FAUSTFLOAT 	fcheckbox225;
	FAUSTFLOAT 	fcheckbox226;
	FAUSTFLOAT 	fcheckbox227;
	FAUSTFLOAT 	fcheckbox228;
	FAUSTFLOAT 	fcheckbox229;
	FAUSTFLOAT 	fcheckbox230;
	FAUSTFLOAT 	fcheckbox231;
	FAUSTFLOAT 	fcheckbox232;
	FAUSTFLOAT 	fcheckbox233;
	double 	fVec82[1048576];
	FAUSTFLOAT 	fslider79;
	int 	iRec145[2];
	int 	iRec146[2];
	double 	fVec83[262144];
	double 	fVec84[2];
	double 	fRec147[2];
	double 	fVec85[2];
	double 	fRec148[2];
	double 	fVec86[2];
	double 	fRec149[2];
	double 	fRec14[2];
	FAUSTFLOAT 	fcheckbox234;
	FAUSTFLOAT 	fcheckbox235;
	FAUSTFLOAT 	fcheckbox236;
	FAUSTFLOAT 	fcheckbox237;
	FAUSTFLOAT 	fcheckbox238;
	FAUSTFLOAT 	fcheckbox239;
	FAUSTFLOAT 	fcheckbox240;
	FAUSTFLOAT 	fcheckbox241;
	FAUSTFLOAT 	fcheckbox242;
	FAUSTFLOAT 	fcheckbox243;
	FAUSTFLOAT 	fcheckbox244;
	FAUSTFLOAT 	fslider80;
	double 	fRec150[2];
	FAUSTFLOAT 	fcheckbox245;
	FAUSTFLOAT 	fcheckbox246;
	FAUSTFLOAT 	fcheckbox247;
	FAUSTFLOAT 	fcheckbox248;
	FAUSTFLOAT 	fcheckbox249;
	double 	fVec87[1048576];
	FAUSTFLOAT 	fslider81;
	int 	iRec151[2];
	int 	iRec152[2];
	double 	fVec88[262144];
	FAUSTFLOAT 	fslider82;
	double 	fRec153[2];
	double 	fVec89[2];
	double 	fRec154[2];
	double 	fVec90[2];
	double 	fRec155[2];
	double 	fVec91[2];
	double 	fRec156[2];
	double 	fVec92[2];
	double 	fRec157[2];
	double 	fRec15[2];
	FAUSTFLOAT 	fslider83;
	double 	fRec158[2];
	double 	fVec93[2];
	double 	fRec159[2];
	FAUSTFLOAT 	fcheckbox250;
	FAUSTFLOAT 	fcheckbox251;
	FAUSTFLOAT 	fcheckbox252;
	FAUSTFLOAT 	fcheckbox253;
	FAUSTFLOAT 	fcheckbox254;
	FAUSTFLOAT 	fcheckbox255;
	FAUSTFLOAT 	fcheckbox256;
	FAUSTFLOAT 	fcheckbox257;
	FAUSTFLOAT 	fcheckbox258;
	FAUSTFLOAT 	fcheckbox259;
	FAUSTFLOAT 	fcheckbox260;
	FAUSTFLOAT 	fcheckbox261;
	FAUSTFLOAT 	fcheckbox262;
	FAUSTFLOAT 	fcheckbox263;
	FAUSTFLOAT 	fcheckbox264;
	FAUSTFLOAT 	fcheckbox265;
	FAUSTFLOAT 	fslider84;
	double 	fRec160[2];
	double 	fVec94[1048576];
	FAUSTFLOAT 	fslider85;
	int 	iRec161[2];
	int 	iRec162[2];
	double 	fVec95[262144];
	double 	fVec96[2];
	double 	fRec163[2];
	double 	fVec97[2];
	double 	fRec164[2];
	double 	fVec98[2];
	double 	fRec165[2];
	double 	fRec16[2];
	FAUSTFLOAT 	fslider86;
	double 	fRec166[2];
	FAUSTFLOAT 	fcheckbox266;
	FAUSTFLOAT 	fcheckbox267;
	FAUSTFLOAT 	fcheckbox268;
	FAUSTFLOAT 	fcheckbox269;
	FAUSTFLOAT 	fcheckbox270;
	FAUSTFLOAT 	fslider87;
	double 	fRec167[2];
	FAUSTFLOAT 	fcheckbox271;
	FAUSTFLOAT 	fcheckbox272;
	FAUSTFLOAT 	fcheckbox273;
	FAUSTFLOAT 	fcheckbox274;
	FAUSTFLOAT 	fcheckbox275;
	FAUSTFLOAT 	fslider88;
	double 	fRec168[2];
	FAUSTFLOAT 	fcheckbox276;
	FAUSTFLOAT 	fcheckbox277;
	FAUSTFLOAT 	fcheckbox278;
	FAUSTFLOAT 	fcheckbox279;
	FAUSTFLOAT 	fcheckbox280;
	FAUSTFLOAT 	fslider89;
	double 	fRec169[2];
	FAUSTFLOAT 	fcheckbox281;
	FAUSTFLOAT 	fcheckbox282;
	FAUSTFLOAT 	fcheckbox283;
	FAUSTFLOAT 	fcheckbox284;
	FAUSTFLOAT 	fcheckbox285;
	FAUSTFLOAT 	fslider90;
	double 	fRec170[2];
	FAUSTFLOAT 	fcheckbox286;
	FAUSTFLOAT 	fcheckbox287;
	FAUSTFLOAT 	fcheckbox288;
	FAUSTFLOAT 	fcheckbox289;
	FAUSTFLOAT 	fcheckbox290;
	FAUSTFLOAT 	fslider91;
	double 	fRec171[2];
	FAUSTFLOAT 	fcheckbox291;
	FAUSTFLOAT 	fcheckbox292;
	FAUSTFLOAT 	fcheckbox293;
	FAUSTFLOAT 	fcheckbox294;
	FAUSTFLOAT 	fcheckbox295;
	FAUSTFLOAT 	fslider92;
	double 	fRec172[2];
	FAUSTFLOAT 	fcheckbox296;
	FAUSTFLOAT 	fcheckbox297;
	FAUSTFLOAT 	fcheckbox298;
	FAUSTFLOAT 	fcheckbox299;
	FAUSTFLOAT 	fcheckbox300;
	FAUSTFLOAT 	fslider93;
	double 	fRec173[2];
	FAUSTFLOAT 	fcheckbox301;
	FAUSTFLOAT 	fcheckbox302;
	FAUSTFLOAT 	fcheckbox303;
	FAUSTFLOAT 	fcheckbox304;
	FAUSTFLOAT 	fcheckbox305;
	FAUSTFLOAT 	fslider94;
	double 	fRec174[2];
	FAUSTFLOAT 	fcheckbox306;
	FAUSTFLOAT 	fcheckbox307;
	FAUSTFLOAT 	fcheckbox308;
	FAUSTFLOAT 	fcheckbox309;
	FAUSTFLOAT 	fcheckbox310;
	FAUSTFLOAT 	fslider95;
	double 	fRec175[2];
	FAUSTFLOAT 	fcheckbox311;
	FAUSTFLOAT 	fcheckbox312;
	FAUSTFLOAT 	fcheckbox313;
	FAUSTFLOAT 	fcheckbox314;
	FAUSTFLOAT 	fcheckbox315;
	FAUSTFLOAT 	fslider96;
	double 	fRec176[2];
	FAUSTFLOAT 	fcheckbox316;
	FAUSTFLOAT 	fcheckbox317;
	FAUSTFLOAT 	fcheckbox318;
	FAUSTFLOAT 	fcheckbox319;
	FAUSTFLOAT 	fcheckbox320;
	FAUSTFLOAT 	fslider97;
	double 	fRec177[2];
	FAUSTFLOAT 	fcheckbox321;
	FAUSTFLOAT 	fcheckbox322;
	FAUSTFLOAT 	fcheckbox323;
	FAUSTFLOAT 	fcheckbox324;
	FAUSTFLOAT 	fcheckbox325;
	FAUSTFLOAT 	fslider98;
	double 	fRec178[2];
	FAUSTFLOAT 	fcheckbox326;
	FAUSTFLOAT 	fcheckbox327;
	FAUSTFLOAT 	fcheckbox328;
	FAUSTFLOAT 	fcheckbox329;
	FAUSTFLOAT 	fcheckbox330;
	FAUSTFLOAT 	fslider99;
	double 	fRec179[2];
	FAUSTFLOAT 	fcheckbox331;
	FAUSTFLOAT 	fcheckbox332;
	FAUSTFLOAT 	fcheckbox333;
	FAUSTFLOAT 	fcheckbox334;
	FAUSTFLOAT 	fcheckbox335;
	FAUSTFLOAT 	fslider100;
	double 	fRec180[2];
	FAUSTFLOAT 	fcheckbox336;
	FAUSTFLOAT 	fcheckbox337;
	FAUSTFLOAT 	fcheckbox338;
	FAUSTFLOAT 	fcheckbox339;
	FAUSTFLOAT 	fcheckbox340;
	FAUSTFLOAT 	fslider101;
	double 	fRec181[2];
	FAUSTFLOAT 	fslider102;
	double 	fRec182[2];
	FAUSTFLOAT 	fslider103;
	FAUSTFLOAT 	fslider104;
	double 	fRec183[2];
	FAUSTFLOAT 	fslider105;
	FAUSTFLOAT 	fslider106;
	double 	fRec184[2];
	FAUSTFLOAT 	fslider107;
	FAUSTFLOAT 	fslider108;
	double 	fRec185[2];
	FAUSTFLOAT 	fcheckbox341;
	FAUSTFLOAT 	fcheckbox342;
	FAUSTFLOAT 	fcheckbox343;
	FAUSTFLOAT 	fcheckbox344;
	FAUSTFLOAT 	fcheckbox345;
	FAUSTFLOAT 	fcheckbox346;
	FAUSTFLOAT 	fcheckbox347;
	FAUSTFLOAT 	fcheckbox348;
	FAUSTFLOAT 	fcheckbox349;
	FAUSTFLOAT 	fcheckbox350;
	FAUSTFLOAT 	fcheckbox351;
	FAUSTFLOAT 	fcheckbox352;
	FAUSTFLOAT 	fcheckbox353;
	FAUSTFLOAT 	fcheckbox354;
	FAUSTFLOAT 	fcheckbox355;
	FAUSTFLOAT 	fcheckbox356;
	FAUSTFLOAT 	fslider109;
	FAUSTFLOAT 	fslider110;
	double 	fRec186[2];
	FAUSTFLOAT 	fcheckbox357;
	FAUSTFLOAT 	fslider111;
	double 	fRec187[2];
	FAUSTFLOAT 	fentry0;
	double 	fRec188[2];
	int 	iRec190[2];
	FAUSTFLOAT 	fslider112;
	int 	iRec189[2];
	FAUSTFLOAT 	fcheckbox358;
	FAUSTFLOAT 	fcheckbox359;
	FAUSTFLOAT 	fcheckbox360;
	FAUSTFLOAT 	fcheckbox361;
	FAUSTFLOAT 	fcheckbox362;
	FAUSTFLOAT 	fcheckbox363;
	FAUSTFLOAT 	fcheckbox364;
	FAUSTFLOAT 	fcheckbox365;
	FAUSTFLOAT 	fcheckbox366;
	FAUSTFLOAT 	fcheckbox367;
	FAUSTFLOAT 	fcheckbox368;
	FAUSTFLOAT 	fcheckbox369;
	FAUSTFLOAT 	fcheckbox370;
	FAUSTFLOAT 	fcheckbox371;
	FAUSTFLOAT 	fcheckbox372;
	FAUSTFLOAT 	fcheckbox373;
	FAUSTFLOAT 	fcheckbox374;
	int 	iRec196[2];
	FAUSTFLOAT 	fcheckbox375;
	FAUSTFLOAT 	fcheckbox376;
	FAUSTFLOAT 	fcheckbox377;
	FAUSTFLOAT 	fcheckbox378;
	FAUSTFLOAT 	fcheckbox379;
	FAUSTFLOAT 	fcheckbox380;
	FAUSTFLOAT 	fcheckbox381;
	FAUSTFLOAT 	fcheckbox382;
	FAUSTFLOAT 	fcheckbox383;
	FAUSTFLOAT 	fcheckbox384;
	FAUSTFLOAT 	fcheckbox385;
	FAUSTFLOAT 	fcheckbox386;
	FAUSTFLOAT 	fcheckbox387;
	FAUSTFLOAT 	fcheckbox388;
	FAUSTFLOAT 	fcheckbox389;
	FAUSTFLOAT 	fcheckbox390;
	FAUSTFLOAT 	fcheckbox391;
	int 	iRec197[2];
	FAUSTFLOAT 	fcheckbox392;
	int 	iRec198[2];
	FAUSTFLOAT 	fcheckbox393;
	FAUSTFLOAT 	fcheckbox394;
	FAUSTFLOAT 	fcheckbox395;
	FAUSTFLOAT 	fcheckbox396;
	FAUSTFLOAT 	fcheckbox397;
	FAUSTFLOAT 	fcheckbox398;
	FAUSTFLOAT 	fcheckbox399;
	FAUSTFLOAT 	fcheckbox400;
	FAUSTFLOAT 	fcheckbox401;
	FAUSTFLOAT 	fcheckbox402;
	FAUSTFLOAT 	fcheckbox403;
	FAUSTFLOAT 	fcheckbox404;
	FAUSTFLOAT 	fcheckbox405;
	FAUSTFLOAT 	fcheckbox406;
	FAUSTFLOAT 	fcheckbox407;
	FAUSTFLOAT 	fcheckbox408;
	FAUSTFLOAT 	fcheckbox409;
	FAUSTFLOAT 	fcheckbox410;
	FAUSTFLOAT 	fcheckbox411;
	FAUSTFLOAT 	fcheckbox412;
	FAUSTFLOAT 	fcheckbox413;
	FAUSTFLOAT 	fcheckbox414;
	FAUSTFLOAT 	fcheckbox415;
	FAUSTFLOAT 	fcheckbox416;
	FAUSTFLOAT 	fcheckbox417;
	FAUSTFLOAT 	fcheckbox418;
	FAUSTFLOAT 	fcheckbox419;
	FAUSTFLOAT 	fcheckbox420;
	FAUSTFLOAT 	fcheckbox421;
	FAUSTFLOAT 	fcheckbox422;
	FAUSTFLOAT 	fcheckbox423;
	FAUSTFLOAT 	fcheckbox424;
	FAUSTFLOAT 	fcheckbox425;
	int 	iRec199[2];
	FAUSTFLOAT 	fcheckbox426;
	int 	iRec200[2];
	FAUSTFLOAT 	fcheckbox427;
	FAUSTFLOAT 	fcheckbox428;
	FAUSTFLOAT 	fcheckbox429;
	FAUSTFLOAT 	fcheckbox430;
	FAUSTFLOAT 	fcheckbox431;
	FAUSTFLOAT 	fcheckbox432;
	FAUSTFLOAT 	fcheckbox433;
	FAUSTFLOAT 	fcheckbox434;
	FAUSTFLOAT 	fcheckbox435;
	FAUSTFLOAT 	fcheckbox436;
	FAUSTFLOAT 	fcheckbox437;
	FAUSTFLOAT 	fcheckbox438;
	FAUSTFLOAT 	fcheckbox439;
	FAUSTFLOAT 	fcheckbox440;
	FAUSTFLOAT 	fcheckbox441;
	FAUSTFLOAT 	fcheckbox442;
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("compilation_options", "-single -scal");
		m->declare("library_path", "FilDeSoi1SoundProcess");
		m->declare("basics_lib_name", "Faust Basic Element Library");
		m->declare("basics_lib_version", "0.0");
		m->declare("delays_lib_name", "Faust Delay Library");
		m->declare("delays_lib_version", "0.0");
		m->declare("hoa_lib_author", "Pierre Guillot");
		m->declare("hoa_lib_copyright", "2012-2013 Guillot, Paris, Colafrancesco, CICM labex art H2H, U. Paris 8");
		m->declare("hoa_lib_name", "High Order Ambisonics library");
		m->declare("maths_lib_author", "GRAME");
		m->declare("maths_lib_copyright", "GRAME");
		m->declare("maths_lib_license", "LGPL with exception");
		m->declare("maths_lib_name", "Faust Math Library");
		m->declare("maths_lib_version", "2.0");
		m->declare("name", "FilDeSoi1SoundProcess");
		m->declare("noises_lib_name", "Faust Noise Generator Library");
		m->declare("noises_lib_version", "0.0");
		m->declare("oscillators_lib_name", "Faust Oscillator Library");
		m->declare("oscillators_lib_version", "0.0");
		m->declare("signals_lib_name", "Faust Signal Routing Library");
		m->declare("signals_lib_version", "0.0");
	}

	virtual int getNumInputs() { return 1; }
	virtual int getNumOutputs() { return 7; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05, max(1.0, (double)fSamplingFreq));
		fConst1 = (1e+03 / fConst0);
		fConst2 = double(fConst0);
		fConst3 = (1.0 / fConst2);
		fConst4 = (0.03 * fConst0);
		fConst5 = (0.001 * fConst0);
		fConst6 = (double(30) / fConst2);
	}
	virtual void instanceResetUserInterface() {
		fcheckbox0 = 0.0;
		fcheckbox1 = 0.0;
		fcheckbox2 = 0.0;
		fcheckbox3 = 0.0;
		fcheckbox4 = 0.0;
		fslider0 = -34.0;
		fslider1 = 2e+01;
		fcheckbox5 = 0.0;
		fcheckbox6 = 0.0;
		fcheckbox7 = 0.0;
		fcheckbox8 = 0.0;
		fcheckbox9 = 0.0;
		fslider2 = 0.0;
		fslider3 = 1.0;
		fslider4 = 64.0;
		fslider5 = 1.0;
		fcheckbox10 = 0.0;
		fslider6 = 1.0;
		fslider7 = 0.0;
		fcheckbox11 = 0.0;
		fslider8 = 1.0;
		fslider9 = 0.0;
		fcheckbox12 = 0.0;
		fslider10 = 0.0;
		fcheckbox13 = 0.0;
		fslider11 = 1.0;
		fslider12 = 0.0;
		fcheckbox14 = 0.0;
		fslider13 = 1.0;
		fslider14 = 0.0;
		fslider15 = 0.0;
		fslider16 = 1.0;
		fcheckbox15 = 0.0;
		fslider17 = 1.0;
		fslider18 = 0.0;
		fcheckbox16 = 0.0;
		fslider19 = 1.0;
		fslider20 = 0.0;
		fcheckbox17 = 0.0;
		fslider21 = 1.0;
		fslider22 = 0.0;
		fcheckbox18 = 0.0;
		fslider23 = 1.0;
		fslider24 = 0.0;
		fcheckbox19 = 0.0;
		fslider25 = 1.0;
		fslider26 = 0.0;
		fcheckbox20 = 0.0;
		fslider27 = 1.0;
		fslider28 = 0.0;
		fcheckbox21 = 0.0;
		fslider29 = 1.0;
		fslider30 = 0.0;
		fcheckbox22 = 0.0;
		fslider31 = 1.0;
		fslider32 = 0.0;
		fcheckbox23 = 0.0;
		fslider33 = 1.0;
		fslider34 = 0.0;
		fcheckbox24 = 0.0;
		fslider35 = 1.0;
		fslider36 = 0.0;
		fcheckbox25 = 0.0;
		fslider37 = 1.0;
		fslider38 = 0.0;
		fslider39 = 1.0;
		fslider40 = 1e+02;
		fslider41 = 0.0;
		fcheckbox26 = 0.0;
		fcheckbox27 = 0.0;
		fcheckbox28 = 0.0;
		fcheckbox29 = 0.0;
		fcheckbox30 = 0.0;
		fslider42 = 1.0;
		fcheckbox31 = 0.0;
		fcheckbox32 = 0.0;
		fcheckbox33 = 0.0;
		fcheckbox34 = 0.0;
		fcheckbox35 = 0.0;
		fcheckbox36 = 0.0;
		fcheckbox37 = 0.0;
		fcheckbox38 = 0.0;
		fcheckbox39 = 0.0;
		fcheckbox40 = 0.0;
		fcheckbox41 = 0.0;
		fslider43 = 2e+02;
		fslider44 = 0.0;
		fcheckbox42 = 0.0;
		fcheckbox43 = 0.0;
		fcheckbox44 = 0.0;
		fcheckbox45 = 0.0;
		fcheckbox46 = 0.0;
		fslider45 = 1.0;
		fcheckbox47 = 0.0;
		fcheckbox48 = 0.0;
		fcheckbox49 = 0.0;
		fcheckbox50 = 0.0;
		fcheckbox51 = 0.0;
		fcheckbox52 = 0.0;
		fcheckbox53 = 0.0;
		fcheckbox54 = 0.0;
		fcheckbox55 = 0.0;
		fcheckbox56 = 0.0;
		fcheckbox57 = 0.0;
		fslider46 = 3e+02;
		fslider47 = 0.0;
		fcheckbox58 = 0.0;
		fcheckbox59 = 0.0;
		fcheckbox60 = 0.0;
		fcheckbox61 = 0.0;
		fcheckbox62 = 0.0;
		fslider48 = 1.0;
		fcheckbox63 = 0.0;
		fcheckbox64 = 0.0;
		fcheckbox65 = 0.0;
		fcheckbox66 = 0.0;
		fcheckbox67 = 0.0;
		fcheckbox68 = 0.0;
		fcheckbox69 = 0.0;
		fcheckbox70 = 0.0;
		fcheckbox71 = 0.0;
		fcheckbox72 = 0.0;
		fcheckbox73 = 0.0;
		fslider49 = 4e+02;
		fslider50 = 0.0;
		fcheckbox74 = 0.0;
		fcheckbox75 = 0.0;
		fcheckbox76 = 0.0;
		fcheckbox77 = 0.0;
		fcheckbox78 = 0.0;
		fslider51 = 1.0;
		fcheckbox79 = 0.0;
		fcheckbox80 = 0.0;
		fcheckbox81 = 0.0;
		fcheckbox82 = 0.0;
		fcheckbox83 = 0.0;
		fcheckbox84 = 0.0;
		fcheckbox85 = 0.0;
		fcheckbox86 = 0.0;
		fcheckbox87 = 0.0;
		fcheckbox88 = 0.0;
		fcheckbox89 = 0.0;
		fslider52 = 5e+02;
		fslider53 = 0.0;
		fcheckbox90 = 0.0;
		fcheckbox91 = 0.0;
		fcheckbox92 = 0.0;
		fcheckbox93 = 0.0;
		fcheckbox94 = 0.0;
		fslider54 = 1.0;
		fcheckbox95 = 0.0;
		fcheckbox96 = 0.0;
		fcheckbox97 = 0.0;
		fcheckbox98 = 0.0;
		fcheckbox99 = 0.0;
		fcheckbox100 = 0.0;
		fcheckbox101 = 0.0;
		fcheckbox102 = 0.0;
		fcheckbox103 = 0.0;
		fcheckbox104 = 0.0;
		fcheckbox105 = 0.0;
		fslider55 = 6e+02;
		fslider56 = 0.0;
		fcheckbox106 = 0.0;
		fcheckbox107 = 0.0;
		fcheckbox108 = 0.0;
		fcheckbox109 = 0.0;
		fcheckbox110 = 0.0;
		fslider57 = 1.0;
		fcheckbox111 = 0.0;
		fcheckbox112 = 0.0;
		fcheckbox113 = 0.0;
		fcheckbox114 = 0.0;
		fcheckbox115 = 0.0;
		fcheckbox116 = 0.0;
		fcheckbox117 = 0.0;
		fcheckbox118 = 0.0;
		fcheckbox119 = 0.0;
		fcheckbox120 = 0.0;
		fcheckbox121 = 0.0;
		fslider58 = 7e+02;
		fslider59 = 0.0;
		fcheckbox122 = 0.0;
		fcheckbox123 = 0.0;
		fcheckbox124 = 0.0;
		fcheckbox125 = 0.0;
		fcheckbox126 = 0.0;
		fslider60 = 1.0;
		fcheckbox127 = 0.0;
		fcheckbox128 = 0.0;
		fcheckbox129 = 0.0;
		fcheckbox130 = 0.0;
		fcheckbox131 = 0.0;
		fcheckbox132 = 0.0;
		fcheckbox133 = 0.0;
		fcheckbox134 = 0.0;
		fcheckbox135 = 0.0;
		fcheckbox136 = 0.0;
		fcheckbox137 = 0.0;
		fslider61 = 8e+02;
		fslider62 = 0.0;
		fcheckbox138 = 0.0;
		fcheckbox139 = 0.0;
		fcheckbox140 = 0.0;
		fcheckbox141 = 0.0;
		fcheckbox142 = 0.0;
		fslider63 = 1.0;
		fcheckbox143 = 0.0;
		fcheckbox144 = 0.0;
		fcheckbox145 = 0.0;
		fcheckbox146 = 0.0;
		fcheckbox147 = 0.0;
		fcheckbox148 = 0.0;
		fcheckbox149 = 0.0;
		fcheckbox150 = 0.0;
		fcheckbox151 = 0.0;
		fcheckbox152 = 0.0;
		fcheckbox153 = 0.0;
		fslider64 = 9e+02;
		fslider65 = 0.0;
		fcheckbox154 = 0.0;
		fcheckbox155 = 0.0;
		fcheckbox156 = 0.0;
		fcheckbox157 = 0.0;
		fcheckbox158 = 0.0;
		fslider66 = 1.0;
		fcheckbox159 = 0.0;
		fcheckbox160 = 0.0;
		fcheckbox161 = 0.0;
		fcheckbox162 = 0.0;
		fcheckbox163 = 0.0;
		fcheckbox164 = 0.0;
		fcheckbox165 = 0.0;
		fcheckbox166 = 0.0;
		fcheckbox167 = 0.0;
		fcheckbox168 = 0.0;
		fcheckbox169 = 0.0;
		fslider67 = 1e+03;
		fslider68 = 0.0;
		fcheckbox170 = 0.0;
		fcheckbox171 = 0.0;
		fcheckbox172 = 0.0;
		fcheckbox173 = 0.0;
		fcheckbox174 = 0.0;
		fslider69 = 1.0;
		fcheckbox175 = 0.0;
		fcheckbox176 = 0.0;
		fcheckbox177 = 0.0;
		fcheckbox178 = 0.0;
		fcheckbox179 = 0.0;
		fcheckbox180 = 0.0;
		fcheckbox181 = 0.0;
		fcheckbox182 = 0.0;
		fcheckbox183 = 0.0;
		fcheckbox184 = 0.0;
		fcheckbox185 = 0.0;
		fslider70 = 1.1e+03;
		fslider71 = 0.0;
		fcheckbox186 = 0.0;
		fcheckbox187 = 0.0;
		fcheckbox188 = 0.0;
		fcheckbox189 = 0.0;
		fcheckbox190 = 0.0;
		fslider72 = 1.0;
		fcheckbox191 = 0.0;
		fcheckbox192 = 0.0;
		fcheckbox193 = 0.0;
		fcheckbox194 = 0.0;
		fcheckbox195 = 0.0;
		fcheckbox196 = 0.0;
		fcheckbox197 = 0.0;
		fcheckbox198 = 0.0;
		fcheckbox199 = 0.0;
		fcheckbox200 = 0.0;
		fcheckbox201 = 0.0;
		fslider73 = 1.2e+03;
		fslider74 = 0.0;
		fcheckbox202 = 0.0;
		fcheckbox203 = 0.0;
		fcheckbox204 = 0.0;
		fcheckbox205 = 0.0;
		fcheckbox206 = 0.0;
		fslider75 = 1.0;
		fcheckbox207 = 0.0;
		fcheckbox208 = 0.0;
		fcheckbox209 = 0.0;
		fcheckbox210 = 0.0;
		fcheckbox211 = 0.0;
		fcheckbox212 = 0.0;
		fcheckbox213 = 0.0;
		fcheckbox214 = 0.0;
		fcheckbox215 = 0.0;
		fcheckbox216 = 0.0;
		fcheckbox217 = 0.0;
		fslider76 = 1.3e+03;
		fslider77 = 0.0;
		fcheckbox218 = 0.0;
		fcheckbox219 = 0.0;
		fcheckbox220 = 0.0;
		fcheckbox221 = 0.0;
		fcheckbox222 = 0.0;
		fslider78 = 1.0;
		fcheckbox223 = 0.0;
		fcheckbox224 = 0.0;
		fcheckbox225 = 0.0;
		fcheckbox226 = 0.0;
		fcheckbox227 = 0.0;
		fcheckbox228 = 0.0;
		fcheckbox229 = 0.0;
		fcheckbox230 = 0.0;
		fcheckbox231 = 0.0;
		fcheckbox232 = 0.0;
		fcheckbox233 = 0.0;
		fslider79 = 1.4e+03;
		fcheckbox234 = 0.0;
		fcheckbox235 = 0.0;
		fcheckbox236 = 0.0;
		fcheckbox237 = 0.0;
		fcheckbox238 = 0.0;
		fcheckbox239 = 0.0;
		fcheckbox240 = 0.0;
		fcheckbox241 = 0.0;
		fcheckbox242 = 0.0;
		fcheckbox243 = 0.0;
		fcheckbox244 = 0.0;
		fslider80 = 1.0;
		fcheckbox245 = 0.0;
		fcheckbox246 = 0.0;
		fcheckbox247 = 0.0;
		fcheckbox248 = 0.0;
		fcheckbox249 = 0.0;
		fslider81 = 1.5e+03;
		fslider82 = 0.0;
		fslider83 = 0.0;
		fcheckbox250 = 0.0;
		fcheckbox251 = 0.0;
		fcheckbox252 = 0.0;
		fcheckbox253 = 0.0;
		fcheckbox254 = 0.0;
		fcheckbox255 = 0.0;
		fcheckbox256 = 0.0;
		fcheckbox257 = 0.0;
		fcheckbox258 = 0.0;
		fcheckbox259 = 0.0;
		fcheckbox260 = 0.0;
		fcheckbox261 = 0.0;
		fcheckbox262 = 0.0;
		fcheckbox263 = 0.0;
		fcheckbox264 = 0.0;
		fcheckbox265 = 0.0;
		fslider84 = 1.0;
		fslider85 = 1.6e+03;
		fslider86 = 1.0;
		fcheckbox266 = 0.0;
		fcheckbox267 = 0.0;
		fcheckbox268 = 0.0;
		fcheckbox269 = 0.0;
		fcheckbox270 = 0.0;
		fslider87 = 1.0;
		fcheckbox271 = 0.0;
		fcheckbox272 = 0.0;
		fcheckbox273 = 0.0;
		fcheckbox274 = 0.0;
		fcheckbox275 = 0.0;
		fslider88 = 1.0;
		fcheckbox276 = 0.0;
		fcheckbox277 = 0.0;
		fcheckbox278 = 0.0;
		fcheckbox279 = 0.0;
		fcheckbox280 = 0.0;
		fslider89 = 1.0;
		fcheckbox281 = 0.0;
		fcheckbox282 = 0.0;
		fcheckbox283 = 0.0;
		fcheckbox284 = 0.0;
		fcheckbox285 = 0.0;
		fslider90 = 1.0;
		fcheckbox286 = 0.0;
		fcheckbox287 = 0.0;
		fcheckbox288 = 0.0;
		fcheckbox289 = 0.0;
		fcheckbox290 = 0.0;
		fslider91 = 1.0;
		fcheckbox291 = 0.0;
		fcheckbox292 = 0.0;
		fcheckbox293 = 0.0;
		fcheckbox294 = 0.0;
		fcheckbox295 = 0.0;
		fslider92 = 1.0;
		fcheckbox296 = 0.0;
		fcheckbox297 = 0.0;
		fcheckbox298 = 0.0;
		fcheckbox299 = 0.0;
		fcheckbox300 = 0.0;
		fslider93 = 1.0;
		fcheckbox301 = 0.0;
		fcheckbox302 = 0.0;
		fcheckbox303 = 0.0;
		fcheckbox304 = 0.0;
		fcheckbox305 = 0.0;
		fslider94 = 1.0;
		fcheckbox306 = 0.0;
		fcheckbox307 = 0.0;
		fcheckbox308 = 0.0;
		fcheckbox309 = 0.0;
		fcheckbox310 = 0.0;
		fslider95 = 1.0;
		fcheckbox311 = 0.0;
		fcheckbox312 = 0.0;
		fcheckbox313 = 0.0;
		fcheckbox314 = 0.0;
		fcheckbox315 = 0.0;
		fslider96 = 1.0;
		fcheckbox316 = 0.0;
		fcheckbox317 = 0.0;
		fcheckbox318 = 0.0;
		fcheckbox319 = 0.0;
		fcheckbox320 = 0.0;
		fslider97 = 1.0;
		fcheckbox321 = 0.0;
		fcheckbox322 = 0.0;
		fcheckbox323 = 0.0;
		fcheckbox324 = 0.0;
		fcheckbox325 = 0.0;
		fslider98 = 1.0;
		fcheckbox326 = 0.0;
		fcheckbox327 = 0.0;
		fcheckbox328 = 0.0;
		fcheckbox329 = 0.0;
		fcheckbox330 = 0.0;
		fslider99 = 1.0;
		fcheckbox331 = 0.0;
		fcheckbox332 = 0.0;
		fcheckbox333 = 0.0;
		fcheckbox334 = 0.0;
		fcheckbox335 = 0.0;
		fslider100 = 1.0;
		fcheckbox336 = 0.0;
		fcheckbox337 = 0.0;
		fcheckbox338 = 0.0;
		fcheckbox339 = 0.0;
		fcheckbox340 = 0.0;
		fslider101 = 1.0;
		fslider102 = 0.0;
		fslider103 = 0.1;
		fslider104 = 0.0;
		fslider105 = 0.1;
		fslider106 = 0.0;
		fslider107 = 0.1;
		fslider108 = 0.0;
		fcheckbox341 = 0.0;
		fcheckbox342 = 0.0;
		fcheckbox343 = 0.0;
		fcheckbox344 = 0.0;
		fcheckbox345 = 0.0;
		fcheckbox346 = 0.0;
		fcheckbox347 = 0.0;
		fcheckbox348 = 0.0;
		fcheckbox349 = 0.0;
		fcheckbox350 = 0.0;
		fcheckbox351 = 0.0;
		fcheckbox352 = 0.0;
		fcheckbox353 = 0.0;
		fcheckbox354 = 0.0;
		fcheckbox355 = 0.0;
		fcheckbox356 = 0.0;
		fslider109 = 0.1;
		fslider110 = 0.0;
		fcheckbox357 = 0.0;
		fslider111 = 0.0;
		fentry0 = 1e+01;
		fslider112 = 0.5;
		fcheckbox358 = 0.0;
		fcheckbox359 = 0.0;
		fcheckbox360 = 0.0;
		fcheckbox361 = 0.0;
		fcheckbox362 = 0.0;
		fcheckbox363 = 0.0;
		fcheckbox364 = 0.0;
		fcheckbox365 = 0.0;
		fcheckbox366 = 0.0;
		fcheckbox367 = 0.0;
		fcheckbox368 = 0.0;
		fcheckbox369 = 0.0;
		fcheckbox370 = 0.0;
		fcheckbox371 = 0.0;
		fcheckbox372 = 0.0;
		fcheckbox373 = 0.0;
		fcheckbox374 = 0.0;
		fcheckbox375 = 0.0;
		fcheckbox376 = 0.0;
		fcheckbox377 = 0.0;
		fcheckbox378 = 0.0;
		fcheckbox379 = 0.0;
		fcheckbox380 = 0.0;
		fcheckbox381 = 0.0;
		fcheckbox382 = 0.0;
		fcheckbox383 = 0.0;
		fcheckbox384 = 0.0;
		fcheckbox385 = 0.0;
		fcheckbox386 = 0.0;
		fcheckbox387 = 0.0;
		fcheckbox388 = 0.0;
		fcheckbox389 = 0.0;
		fcheckbox390 = 0.0;
		fcheckbox391 = 0.0;
		fcheckbox392 = 0.0;
		fcheckbox393 = 0.0;
		fcheckbox394 = 0.0;
		fcheckbox395 = 0.0;
		fcheckbox396 = 0.0;
		fcheckbox397 = 0.0;
		fcheckbox398 = 0.0;
		fcheckbox399 = 0.0;
		fcheckbox400 = 0.0;
		fcheckbox401 = 0.0;
		fcheckbox402 = 0.0;
		fcheckbox403 = 0.0;
		fcheckbox404 = 0.0;
		fcheckbox405 = 0.0;
		fcheckbox406 = 0.0;
		fcheckbox407 = 0.0;
		fcheckbox408 = 0.0;
		fcheckbox409 = 0.0;
		fcheckbox410 = 0.0;
		fcheckbox411 = 0.0;
		fcheckbox412 = 0.0;
		fcheckbox413 = 0.0;
		fcheckbox414 = 0.0;
		fcheckbox415 = 0.0;
		fcheckbox416 = 0.0;
		fcheckbox417 = 0.0;
		fcheckbox418 = 0.0;
		fcheckbox419 = 0.0;
		fcheckbox420 = 0.0;
		fcheckbox421 = 0.0;
		fcheckbox422 = 0.0;
		fcheckbox423 = 0.0;
		fcheckbox424 = 0.0;
		fcheckbox425 = 0.0;
		fcheckbox426 = 0.0;
		fcheckbox427 = 0.0;
		fcheckbox428 = 0.0;
		fcheckbox429 = 0.0;
		fcheckbox430 = 0.0;
		fcheckbox431 = 0.0;
		fcheckbox432 = 0.0;
		fcheckbox433 = 0.0;
		fcheckbox434 = 0.0;
		fcheckbox435 = 0.0;
		fcheckbox436 = 0.0;
		fcheckbox437 = 0.0;
		fcheckbox438 = 0.0;
		fcheckbox439 = 0.0;
		fcheckbox440 = 0.0;
		fcheckbox441 = 0.0;
		fcheckbox442 = 0.0;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		IOTA = 0;
		for (int i=0; i<1048576; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) iRec42[i] = 0;
		for (int i=0; i<262144; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<1048576; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) iRec49[i] = 0;
		for (int i=0; i<2; i++) iRec50[i] = 0;
		for (int i=0; i<262144; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<1048576; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) iRec57[i] = 0;
		for (int i=0; i<2; i++) iRec58[i] = 0;
		for (int i=0; i<262144; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<1048576; i++) fVec22[i] = 0;
		for (int i=0; i<2; i++) iRec65[i] = 0;
		for (int i=0; i<2; i++) iRec66[i] = 0;
		for (int i=0; i<262144; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fVec24[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fVec26[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fVec27[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<1048576; i++) fVec28[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<262144; i++) fVec29[i] = 0;
		for (int i=0; i<2; i++) fVec30[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fVec31[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fVec32[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fVec33[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<1048576; i++) fVec34[i] = 0;
		for (int i=0; i<2; i++) iRec81[i] = 0;
		for (int i=0; i<2; i++) iRec82[i] = 0;
		for (int i=0; i<262144; i++) fVec35[i] = 0;
		for (int i=0; i<2; i++) fVec36[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fVec37[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fVec38[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fVec39[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<1048576; i++) fVec40[i] = 0;
		for (int i=0; i<2; i++) iRec89[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<262144; i++) fVec41[i] = 0;
		for (int i=0; i<2; i++) fVec42[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fVec43[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fVec44[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fVec45[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<1048576; i++) fVec46[i] = 0;
		for (int i=0; i<2; i++) iRec97[i] = 0;
		for (int i=0; i<2; i++) iRec98[i] = 0;
		for (int i=0; i<262144; i++) fVec47[i] = 0;
		for (int i=0; i<2; i++) fVec48[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fVec49[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fVec50[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fVec51[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<1048576; i++) fVec52[i] = 0;
		for (int i=0; i<2; i++) iRec105[i] = 0;
		for (int i=0; i<2; i++) iRec106[i] = 0;
		for (int i=0; i<262144; i++) fVec53[i] = 0;
		for (int i=0; i<2; i++) fVec54[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fVec55[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fVec56[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fVec57[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<1048576; i++) fVec58[i] = 0;
		for (int i=0; i<2; i++) iRec113[i] = 0;
		for (int i=0; i<2; i++) iRec114[i] = 0;
		for (int i=0; i<262144; i++) fVec59[i] = 0;
		for (int i=0; i<2; i++) fVec60[i] = 0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		for (int i=0; i<2; i++) fVec61[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<2; i++) fVec62[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<2; i++) fVec63[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<1048576; i++) fVec64[i] = 0;
		for (int i=0; i<2; i++) iRec121[i] = 0;
		for (int i=0; i<2; i++) iRec122[i] = 0;
		for (int i=0; i<262144; i++) fVec65[i] = 0;
		for (int i=0; i<2; i++) fVec66[i] = 0;
		for (int i=0; i<2; i++) fRec123[i] = 0;
		for (int i=0; i<2; i++) fVec67[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<2; i++) fVec68[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fVec69[i] = 0;
		for (int i=0; i<2; i++) fRec127[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<1048576; i++) fVec70[i] = 0;
		for (int i=0; i<2; i++) iRec129[i] = 0;
		for (int i=0; i<2; i++) iRec130[i] = 0;
		for (int i=0; i<262144; i++) fVec71[i] = 0;
		for (int i=0; i<2; i++) fVec72[i] = 0;
		for (int i=0; i<2; i++) fRec131[i] = 0;
		for (int i=0; i<2; i++) fVec73[i] = 0;
		for (int i=0; i<2; i++) fRec132[i] = 0;
		for (int i=0; i<2; i++) fVec74[i] = 0;
		for (int i=0; i<2; i++) fRec133[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec134[i] = 0;
		for (int i=0; i<2; i++) fVec75[i] = 0;
		for (int i=0; i<2; i++) fRec135[i] = 0;
		for (int i=0; i<2; i++) fRec136[i] = 0;
		for (int i=0; i<1048576; i++) fVec76[i] = 0;
		for (int i=0; i<2; i++) iRec137[i] = 0;
		for (int i=0; i<2; i++) iRec138[i] = 0;
		for (int i=0; i<262144; i++) fVec77[i] = 0;
		for (int i=0; i<2; i++) fVec78[i] = 0;
		for (int i=0; i<2; i++) fRec139[i] = 0;
		for (int i=0; i<2; i++) fVec79[i] = 0;
		for (int i=0; i<2; i++) fRec140[i] = 0;
		for (int i=0; i<2; i++) fVec80[i] = 0;
		for (int i=0; i<2; i++) fRec141[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec142[i] = 0;
		for (int i=0; i<2; i++) fVec81[i] = 0;
		for (int i=0; i<2; i++) fRec143[i] = 0;
		for (int i=0; i<2; i++) fRec144[i] = 0;
		for (int i=0; i<1048576; i++) fVec82[i] = 0;
		for (int i=0; i<2; i++) iRec145[i] = 0;
		for (int i=0; i<2; i++) iRec146[i] = 0;
		for (int i=0; i<262144; i++) fVec83[i] = 0;
		for (int i=0; i<2; i++) fVec84[i] = 0;
		for (int i=0; i<2; i++) fRec147[i] = 0;
		for (int i=0; i<2; i++) fVec85[i] = 0;
		for (int i=0; i<2; i++) fRec148[i] = 0;
		for (int i=0; i<2; i++) fVec86[i] = 0;
		for (int i=0; i<2; i++) fRec149[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec150[i] = 0;
		for (int i=0; i<1048576; i++) fVec87[i] = 0;
		for (int i=0; i<2; i++) iRec151[i] = 0;
		for (int i=0; i<2; i++) iRec152[i] = 0;
		for (int i=0; i<262144; i++) fVec88[i] = 0;
		for (int i=0; i<2; i++) fRec153[i] = 0;
		for (int i=0; i<2; i++) fVec89[i] = 0;
		for (int i=0; i<2; i++) fRec154[i] = 0;
		for (int i=0; i<2; i++) fVec90[i] = 0;
		for (int i=0; i<2; i++) fRec155[i] = 0;
		for (int i=0; i<2; i++) fVec91[i] = 0;
		for (int i=0; i<2; i++) fRec156[i] = 0;
		for (int i=0; i<2; i++) fVec92[i] = 0;
		for (int i=0; i<2; i++) fRec157[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec158[i] = 0;
		for (int i=0; i<2; i++) fVec93[i] = 0;
		for (int i=0; i<2; i++) fRec159[i] = 0;
		for (int i=0; i<2; i++) fRec160[i] = 0;
		for (int i=0; i<1048576; i++) fVec94[i] = 0;
		for (int i=0; i<2; i++) iRec161[i] = 0;
		for (int i=0; i<2; i++) iRec162[i] = 0;
		for (int i=0; i<262144; i++) fVec95[i] = 0;
		for (int i=0; i<2; i++) fVec96[i] = 0;
		for (int i=0; i<2; i++) fRec163[i] = 0;
		for (int i=0; i<2; i++) fVec97[i] = 0;
		for (int i=0; i<2; i++) fRec164[i] = 0;
		for (int i=0; i<2; i++) fVec98[i] = 0;
		for (int i=0; i<2; i++) fRec165[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec166[i] = 0;
		for (int i=0; i<2; i++) fRec167[i] = 0;
		for (int i=0; i<2; i++) fRec168[i] = 0;
		for (int i=0; i<2; i++) fRec169[i] = 0;
		for (int i=0; i<2; i++) fRec170[i] = 0;
		for (int i=0; i<2; i++) fRec171[i] = 0;
		for (int i=0; i<2; i++) fRec172[i] = 0;
		for (int i=0; i<2; i++) fRec173[i] = 0;
		for (int i=0; i<2; i++) fRec174[i] = 0;
		for (int i=0; i<2; i++) fRec175[i] = 0;
		for (int i=0; i<2; i++) fRec176[i] = 0;
		for (int i=0; i<2; i++) fRec177[i] = 0;
		for (int i=0; i<2; i++) fRec178[i] = 0;
		for (int i=0; i<2; i++) fRec179[i] = 0;
		for (int i=0; i<2; i++) fRec180[i] = 0;
		for (int i=0; i<2; i++) fRec181[i] = 0;
		for (int i=0; i<2; i++) fRec182[i] = 0;
		for (int i=0; i<2; i++) fRec183[i] = 0;
		for (int i=0; i<2; i++) fRec184[i] = 0;
		for (int i=0; i<2; i++) fRec185[i] = 0;
		for (int i=0; i<2; i++) fRec186[i] = 0;
		for (int i=0; i<2; i++) fRec187[i] = 0;
		for (int i=0; i<2; i++) fRec188[i] = 0;
		for (int i=0; i<2; i++) iRec190[i] = 0;
		for (int i=0; i<2; i++) iRec189[i] = 0;
		for (int i=0; i<2; i++) iRec196[i] = 0;
		for (int i=0; i<2; i++) iRec197[i] = 0;
		for (int i=0; i<2; i++) iRec198[i] = 0;
		for (int i=0; i<2; i++) iRec199[i] = 0;
		for (int i=0; i<2; i++) iRec200[i] = 0;
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
		ui_interface->openVerticalBox("0x00");
		ui_interface->openHorizontalBox("Encoders");
		ui_interface->addHorizontalSlider("rotfreq0", &fslider109, 0.1, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("rotfreq1", &fslider107, 0.1, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("rotfreq2", &fslider105, 0.1, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("rotfreq3", &fslider103, 0.1, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("rotphase0", &fslider110, 0.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase1", &fslider108, 0.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase2", &fslider106, 0.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("rotphase3", &fslider104, 0.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Global_Parameters");
		ui_interface->declare(&fslider39, "7", "");
		ui_interface->addHorizontalSlider("dStretch", &fslider39, 1.0, 0.01, 1e+01, 0.01);
		ui_interface->declare(&fslider15, "7", "");
		ui_interface->addHorizontalSlider("delharmoGain", &fslider15, 0.0, -127.0, 18.0, 0.01);
		ui_interface->declare(&fslider102, "7", "");
		ui_interface->addHorizontalSlider("generalGain", &fslider102, 0.0, -127.0, 18.0, 0.01);
		ui_interface->declare(&fslider0, "7", "");
		ui_interface->addHorizontalSlider("guitarGain", &fslider0, -34.0, -127.0, 18.0, 0.01);
		ui_interface->declare(&fslider3, "7", "");
		ui_interface->addHorizontalSlider("hStretch", &fslider3, 1.0, -1e+01, 1e+01, 0.01);
		ui_interface->addHorizontalSlider("hWin", &fslider4, 64.0, 1.0, 127.0, 0.01);
		ui_interface->addHorizontalSlider("smoothDuration", &fslider1, 2e+01, 1e+01, 5e+03, 1.0);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lines");
		ui_interface->openVerticalBox("Del_Durations");
		ui_interface->addHorizontalSlider("d 0", &fslider40, 1e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 1", &fslider43, 2e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 2", &fslider46, 3e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 3", &fslider49, 4e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 4", &fslider52, 5e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 5", &fslider55, 6e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 6", &fslider58, 7e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 7", &fslider61, 8e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 8", &fslider64, 9e+02, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d 9", &fslider67, 1e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d10", &fslider70, 1.1e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d11", &fslider73, 1.2e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d12", &fslider76, 1.3e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d13", &fslider79, 1.4e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d14", &fslider81, 1.5e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->addHorizontalSlider("d15", &fslider85, 1.6e+03, 0.0, 2.1e+04, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del_Feedbacks");
		ui_interface->addHorizontalSlider("fd 0", &fslider10, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 1", &fslider36, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 2", &fslider14, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 3", &fslider12, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 4", &fslider7, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 5", &fslider9, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 6", &fslider38, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 7", &fslider34, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 8", &fslider32, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd 9", &fslider30, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd10", &fslider28, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd11", &fslider26, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd12", &fslider24, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd13", &fslider22, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd14", &fslider20, 0.0, 0.0, 0.99, 0.01);
		ui_interface->addHorizontalSlider("fd15", &fslider18, 0.0, 0.0, 0.99, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("EffeX_vs_Del");
		ui_interface->addHorizontalSlider("xvd 0", &fslider5, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 1", &fslider35, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 2", &fslider13, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 3", &fslider11, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 4", &fslider6, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 5", &fslider8, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 6", &fslider37, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 7", &fslider33, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 8", &fslider31, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd 9", &fslider29, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd10", &fslider27, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd11", &fslider25, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd12", &fslider23, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd13", &fslider21, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd14", &fslider19, 1.0, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("xvd15", &fslider17, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Harmo_Transpositions");
		ui_interface->addHorizontalSlider("tr 0", &fslider2, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 1", &fslider41, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 2", &fslider44, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 3", &fslider47, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 4", &fslider50, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 5", &fslider53, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 6", &fslider56, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 7", &fslider59, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 8", &fslider62, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr 9", &fslider65, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr10", &fslider68, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr11", &fslider71, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr12", &fslider74, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr13", &fslider77, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr14", &fslider82, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->addHorizontalSlider("tr15", &fslider83, 0.0, -2.4e+03, 2.4e+03, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_input");
		ui_interface->declare(&fslider16, "5", "");
		ui_interface->addHorizontalSlider("inp 0", &fslider16, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider42, "5", "");
		ui_interface->addHorizontalSlider("inp 1", &fslider42, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider45, "5", "");
		ui_interface->addHorizontalSlider("inp 2", &fslider45, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider48, "5", "");
		ui_interface->addHorizontalSlider("inp 3", &fslider48, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider51, "5", "");
		ui_interface->addHorizontalSlider("inp 4", &fslider51, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider54, "5", "");
		ui_interface->addHorizontalSlider("inp 5", &fslider54, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider57, "5", "");
		ui_interface->addHorizontalSlider("inp 6", &fslider57, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider60, "5", "");
		ui_interface->addHorizontalSlider("inp 7", &fslider60, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider63, "5", "");
		ui_interface->addHorizontalSlider("inp 8", &fslider63, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider66, "5", "");
		ui_interface->addHorizontalSlider("inp 9", &fslider66, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider69, "5", "");
		ui_interface->addHorizontalSlider("inp10", &fslider69, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider72, "5", "");
		ui_interface->addHorizontalSlider("inp11", &fslider72, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider75, "5", "");
		ui_interface->addHorizontalSlider("inp12", &fslider75, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider78, "5", "");
		ui_interface->addHorizontalSlider("inp13", &fslider78, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider80, "5", "");
		ui_interface->addHorizontalSlider("inp14", &fslider80, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider84, "5", "");
		ui_interface->addHorizontalSlider("inp15", &fslider84, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_output");
		ui_interface->declare(&fslider92, "6", "");
		ui_interface->addHorizontalSlider("out 0", &fslider92, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider90, "6", "");
		ui_interface->addHorizontalSlider("out 1", &fslider90, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider99, "6", "");
		ui_interface->addHorizontalSlider("out 2", &fslider99, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider86, "6", "");
		ui_interface->addHorizontalSlider("out 3", &fslider86, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider93, "6", "");
		ui_interface->addHorizontalSlider("out 4", &fslider93, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider98, "6", "");
		ui_interface->addHorizontalSlider("out 5", &fslider98, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider101, "6", "");
		ui_interface->addHorizontalSlider("out 6", &fslider101, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider95, "6", "");
		ui_interface->addHorizontalSlider("out 7", &fslider95, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider88, "6", "");
		ui_interface->addHorizontalSlider("out 8", &fslider88, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider94, "6", "");
		ui_interface->addHorizontalSlider("out 9", &fslider94, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider87, "6", "");
		ui_interface->addHorizontalSlider("out10", &fslider87, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider97, "6", "");
		ui_interface->addHorizontalSlider("out11", &fslider97, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider89, "6", "");
		ui_interface->addHorizontalSlider("out12", &fslider89, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider96, "6", "");
		ui_interface->addHorizontalSlider("out13", &fslider96, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider100, "6", "");
		ui_interface->addHorizontalSlider("out14", &fslider100, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fslider91, "6", "");
		ui_interface->addHorizontalSlider("out15", &fslider91, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Reinjection_Matrix");
		ui_interface->openVerticalBox("Del 0-->");
		ui_interface->addCheckButton("r  0", &fcheckbox12);
		ui_interface->addCheckButton("r 16", &fcheckbox30);
		ui_interface->addCheckButton("r 32", &fcheckbox46);
		ui_interface->addCheckButton("r 48", &fcheckbox62);
		ui_interface->addCheckButton("r 64", &fcheckbox78);
		ui_interface->addCheckButton("r 80", &fcheckbox94);
		ui_interface->addCheckButton("r 96", &fcheckbox110);
		ui_interface->addCheckButton("r112", &fcheckbox126);
		ui_interface->addCheckButton("r128", &fcheckbox142);
		ui_interface->addCheckButton("r144", &fcheckbox158);
		ui_interface->addCheckButton("r160", &fcheckbox174);
		ui_interface->addCheckButton("r176", &fcheckbox190);
		ui_interface->addCheckButton("r192", &fcheckbox206);
		ui_interface->addCheckButton("r208", &fcheckbox222);
		ui_interface->addCheckButton("r224", &fcheckbox245);
		ui_interface->addCheckButton("r240", &fcheckbox252);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 1-->");
		ui_interface->addCheckButton("r  1", &fcheckbox24);
		ui_interface->addCheckButton("r 17", &fcheckbox40);
		ui_interface->addCheckButton("r 33", &fcheckbox56);
		ui_interface->addCheckButton("r 49", &fcheckbox72);
		ui_interface->addCheckButton("r 65", &fcheckbox88);
		ui_interface->addCheckButton("r 81", &fcheckbox104);
		ui_interface->addCheckButton("r 97", &fcheckbox120);
		ui_interface->addCheckButton("r113", &fcheckbox136);
		ui_interface->addCheckButton("r129", &fcheckbox152);
		ui_interface->addCheckButton("r145", &fcheckbox168);
		ui_interface->addCheckButton("r161", &fcheckbox184);
		ui_interface->addCheckButton("r177", &fcheckbox200);
		ui_interface->addCheckButton("r193", &fcheckbox216);
		ui_interface->addCheckButton("r209", &fcheckbox232);
		ui_interface->addCheckButton("r225", &fcheckbox242);
		ui_interface->addCheckButton("r241", &fcheckbox255);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 2-->");
		ui_interface->addCheckButton("r  2", &fcheckbox14);
		ui_interface->addCheckButton("r 18", &fcheckbox29);
		ui_interface->addCheckButton("r 34", &fcheckbox45);
		ui_interface->addCheckButton("r 50", &fcheckbox61);
		ui_interface->addCheckButton("r 66", &fcheckbox77);
		ui_interface->addCheckButton("r 82", &fcheckbox93);
		ui_interface->addCheckButton("r 98", &fcheckbox109);
		ui_interface->addCheckButton("r114", &fcheckbox125);
		ui_interface->addCheckButton("r130", &fcheckbox141);
		ui_interface->addCheckButton("r146", &fcheckbox157);
		ui_interface->addCheckButton("r162", &fcheckbox173);
		ui_interface->addCheckButton("r178", &fcheckbox189);
		ui_interface->addCheckButton("r194", &fcheckbox205);
		ui_interface->addCheckButton("r210", &fcheckbox221);
		ui_interface->addCheckButton("r226", &fcheckbox246);
		ui_interface->addCheckButton("r242", &fcheckbox251);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 3-->");
		ui_interface->addCheckButton("r  3", &fcheckbox13);
		ui_interface->addCheckButton("r 19", &fcheckbox28);
		ui_interface->addCheckButton("r 35", &fcheckbox42);
		ui_interface->addCheckButton("r 51", &fcheckbox58);
		ui_interface->addCheckButton("r 67", &fcheckbox74);
		ui_interface->addCheckButton("r 83", &fcheckbox90);
		ui_interface->addCheckButton("r 99", &fcheckbox106);
		ui_interface->addCheckButton("r115", &fcheckbox122);
		ui_interface->addCheckButton("r131", &fcheckbox138);
		ui_interface->addCheckButton("r147", &fcheckbox154);
		ui_interface->addCheckButton("r163", &fcheckbox170);
		ui_interface->addCheckButton("r179", &fcheckbox186);
		ui_interface->addCheckButton("r195", &fcheckbox202);
		ui_interface->addCheckButton("r211", &fcheckbox218);
		ui_interface->addCheckButton("r227", &fcheckbox249);
		ui_interface->addCheckButton("r243", &fcheckbox253);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 4-->");
		ui_interface->addCheckButton("r  4", &fcheckbox10);
		ui_interface->addCheckButton("r 20", &fcheckbox27);
		ui_interface->addCheckButton("r 36", &fcheckbox44);
		ui_interface->addCheckButton("r 52", &fcheckbox60);
		ui_interface->addCheckButton("r 68", &fcheckbox76);
		ui_interface->addCheckButton("r 84", &fcheckbox92);
		ui_interface->addCheckButton("r100", &fcheckbox108);
		ui_interface->addCheckButton("r116", &fcheckbox124);
		ui_interface->addCheckButton("r132", &fcheckbox140);
		ui_interface->addCheckButton("r148", &fcheckbox156);
		ui_interface->addCheckButton("r164", &fcheckbox172);
		ui_interface->addCheckButton("r180", &fcheckbox188);
		ui_interface->addCheckButton("r196", &fcheckbox204);
		ui_interface->addCheckButton("r212", &fcheckbox220);
		ui_interface->addCheckButton("r228", &fcheckbox247);
		ui_interface->addCheckButton("r244", &fcheckbox254);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 5-->");
		ui_interface->addCheckButton("r  5", &fcheckbox11);
		ui_interface->addCheckButton("r 21", &fcheckbox26);
		ui_interface->addCheckButton("r 37", &fcheckbox43);
		ui_interface->addCheckButton("r 53", &fcheckbox59);
		ui_interface->addCheckButton("r 69", &fcheckbox75);
		ui_interface->addCheckButton("r 85", &fcheckbox91);
		ui_interface->addCheckButton("r101", &fcheckbox107);
		ui_interface->addCheckButton("r117", &fcheckbox123);
		ui_interface->addCheckButton("r133", &fcheckbox139);
		ui_interface->addCheckButton("r149", &fcheckbox155);
		ui_interface->addCheckButton("r165", &fcheckbox171);
		ui_interface->addCheckButton("r181", &fcheckbox187);
		ui_interface->addCheckButton("r197", &fcheckbox203);
		ui_interface->addCheckButton("r213", &fcheckbox219);
		ui_interface->addCheckButton("r229", &fcheckbox248);
		ui_interface->addCheckButton("r245", &fcheckbox250);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 6-->");
		ui_interface->addCheckButton("r  6", &fcheckbox25);
		ui_interface->addCheckButton("r 22", &fcheckbox41);
		ui_interface->addCheckButton("r 38", &fcheckbox57);
		ui_interface->addCheckButton("r 54", &fcheckbox73);
		ui_interface->addCheckButton("r 70", &fcheckbox89);
		ui_interface->addCheckButton("r 86", &fcheckbox105);
		ui_interface->addCheckButton("r102", &fcheckbox121);
		ui_interface->addCheckButton("r118", &fcheckbox137);
		ui_interface->addCheckButton("r134", &fcheckbox153);
		ui_interface->addCheckButton("r150", &fcheckbox169);
		ui_interface->addCheckButton("r166", &fcheckbox185);
		ui_interface->addCheckButton("r182", &fcheckbox201);
		ui_interface->addCheckButton("r198", &fcheckbox217);
		ui_interface->addCheckButton("r214", &fcheckbox233);
		ui_interface->addCheckButton("r230", &fcheckbox243);
		ui_interface->addCheckButton("r246", &fcheckbox256);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 7-->");
		ui_interface->addCheckButton("r  7", &fcheckbox23);
		ui_interface->addCheckButton("r 23", &fcheckbox39);
		ui_interface->addCheckButton("r 39", &fcheckbox55);
		ui_interface->addCheckButton("r 55", &fcheckbox71);
		ui_interface->addCheckButton("r 71", &fcheckbox87);
		ui_interface->addCheckButton("r 87", &fcheckbox103);
		ui_interface->addCheckButton("r103", &fcheckbox119);
		ui_interface->addCheckButton("r119", &fcheckbox135);
		ui_interface->addCheckButton("r135", &fcheckbox151);
		ui_interface->addCheckButton("r151", &fcheckbox167);
		ui_interface->addCheckButton("r167", &fcheckbox183);
		ui_interface->addCheckButton("r183", &fcheckbox199);
		ui_interface->addCheckButton("r199", &fcheckbox215);
		ui_interface->addCheckButton("r215", &fcheckbox231);
		ui_interface->addCheckButton("r231", &fcheckbox241);
		ui_interface->addCheckButton("r247", &fcheckbox257);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 8-->");
		ui_interface->addCheckButton("r  8", &fcheckbox22);
		ui_interface->addCheckButton("r 24", &fcheckbox38);
		ui_interface->addCheckButton("r 40", &fcheckbox54);
		ui_interface->addCheckButton("r 56", &fcheckbox70);
		ui_interface->addCheckButton("r 72", &fcheckbox86);
		ui_interface->addCheckButton("r 88", &fcheckbox102);
		ui_interface->addCheckButton("r104", &fcheckbox118);
		ui_interface->addCheckButton("r120", &fcheckbox134);
		ui_interface->addCheckButton("r136", &fcheckbox150);
		ui_interface->addCheckButton("r152", &fcheckbox166);
		ui_interface->addCheckButton("r168", &fcheckbox182);
		ui_interface->addCheckButton("r184", &fcheckbox198);
		ui_interface->addCheckButton("r200", &fcheckbox214);
		ui_interface->addCheckButton("r216", &fcheckbox230);
		ui_interface->addCheckButton("r232", &fcheckbox240);
		ui_interface->addCheckButton("r248", &fcheckbox258);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 9-->");
		ui_interface->addCheckButton("r  9", &fcheckbox21);
		ui_interface->addCheckButton("r 25", &fcheckbox37);
		ui_interface->addCheckButton("r 41", &fcheckbox53);
		ui_interface->addCheckButton("r 57", &fcheckbox69);
		ui_interface->addCheckButton("r 73", &fcheckbox85);
		ui_interface->addCheckButton("r 89", &fcheckbox101);
		ui_interface->addCheckButton("r105", &fcheckbox117);
		ui_interface->addCheckButton("r121", &fcheckbox133);
		ui_interface->addCheckButton("r137", &fcheckbox149);
		ui_interface->addCheckButton("r153", &fcheckbox165);
		ui_interface->addCheckButton("r169", &fcheckbox181);
		ui_interface->addCheckButton("r185", &fcheckbox197);
		ui_interface->addCheckButton("r201", &fcheckbox213);
		ui_interface->addCheckButton("r217", &fcheckbox229);
		ui_interface->addCheckButton("r233", &fcheckbox239);
		ui_interface->addCheckButton("r249", &fcheckbox259);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del10-->");
		ui_interface->addCheckButton("r 10", &fcheckbox20);
		ui_interface->addCheckButton("r 26", &fcheckbox36);
		ui_interface->addCheckButton("r 42", &fcheckbox52);
		ui_interface->addCheckButton("r 58", &fcheckbox68);
		ui_interface->addCheckButton("r 74", &fcheckbox84);
		ui_interface->addCheckButton("r 90", &fcheckbox100);
		ui_interface->addCheckButton("r106", &fcheckbox116);
		ui_interface->addCheckButton("r122", &fcheckbox132);
		ui_interface->addCheckButton("r138", &fcheckbox148);
		ui_interface->addCheckButton("r154", &fcheckbox164);
		ui_interface->addCheckButton("r170", &fcheckbox180);
		ui_interface->addCheckButton("r186", &fcheckbox196);
		ui_interface->addCheckButton("r202", &fcheckbox212);
		ui_interface->addCheckButton("r218", &fcheckbox228);
		ui_interface->addCheckButton("r234", &fcheckbox238);
		ui_interface->addCheckButton("r250", &fcheckbox260);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del11-->");
		ui_interface->addCheckButton("r 11", &fcheckbox19);
		ui_interface->addCheckButton("r 27", &fcheckbox35);
		ui_interface->addCheckButton("r 43", &fcheckbox51);
		ui_interface->addCheckButton("r 59", &fcheckbox67);
		ui_interface->addCheckButton("r 75", &fcheckbox83);
		ui_interface->addCheckButton("r 91", &fcheckbox99);
		ui_interface->addCheckButton("r107", &fcheckbox115);
		ui_interface->addCheckButton("r123", &fcheckbox131);
		ui_interface->addCheckButton("r139", &fcheckbox147);
		ui_interface->addCheckButton("r155", &fcheckbox163);
		ui_interface->addCheckButton("r171", &fcheckbox179);
		ui_interface->addCheckButton("r187", &fcheckbox195);
		ui_interface->addCheckButton("r203", &fcheckbox211);
		ui_interface->addCheckButton("r219", &fcheckbox227);
		ui_interface->addCheckButton("r235", &fcheckbox237);
		ui_interface->addCheckButton("r251", &fcheckbox261);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del12-->");
		ui_interface->addCheckButton("r 12", &fcheckbox18);
		ui_interface->addCheckButton("r 28", &fcheckbox34);
		ui_interface->addCheckButton("r 44", &fcheckbox50);
		ui_interface->addCheckButton("r 60", &fcheckbox66);
		ui_interface->addCheckButton("r 76", &fcheckbox82);
		ui_interface->addCheckButton("r 92", &fcheckbox98);
		ui_interface->addCheckButton("r108", &fcheckbox114);
		ui_interface->addCheckButton("r124", &fcheckbox130);
		ui_interface->addCheckButton("r140", &fcheckbox146);
		ui_interface->addCheckButton("r156", &fcheckbox162);
		ui_interface->addCheckButton("r172", &fcheckbox178);
		ui_interface->addCheckButton("r188", &fcheckbox194);
		ui_interface->addCheckButton("r204", &fcheckbox210);
		ui_interface->addCheckButton("r220", &fcheckbox226);
		ui_interface->addCheckButton("r236", &fcheckbox236);
		ui_interface->addCheckButton("r252", &fcheckbox262);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del13-->");
		ui_interface->addCheckButton("r 13", &fcheckbox17);
		ui_interface->addCheckButton("r 29", &fcheckbox33);
		ui_interface->addCheckButton("r 45", &fcheckbox49);
		ui_interface->addCheckButton("r 61", &fcheckbox65);
		ui_interface->addCheckButton("r 77", &fcheckbox81);
		ui_interface->addCheckButton("r 93", &fcheckbox97);
		ui_interface->addCheckButton("r109", &fcheckbox113);
		ui_interface->addCheckButton("r125", &fcheckbox129);
		ui_interface->addCheckButton("r141", &fcheckbox145);
		ui_interface->addCheckButton("r157", &fcheckbox161);
		ui_interface->addCheckButton("r173", &fcheckbox177);
		ui_interface->addCheckButton("r189", &fcheckbox193);
		ui_interface->addCheckButton("r205", &fcheckbox209);
		ui_interface->addCheckButton("r221", &fcheckbox225);
		ui_interface->addCheckButton("r237", &fcheckbox235);
		ui_interface->addCheckButton("r253", &fcheckbox263);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del14-->");
		ui_interface->addCheckButton("r 14", &fcheckbox16);
		ui_interface->addCheckButton("r 30", &fcheckbox32);
		ui_interface->addCheckButton("r 46", &fcheckbox48);
		ui_interface->addCheckButton("r 62", &fcheckbox64);
		ui_interface->addCheckButton("r 78", &fcheckbox80);
		ui_interface->addCheckButton("r 94", &fcheckbox96);
		ui_interface->addCheckButton("r110", &fcheckbox112);
		ui_interface->addCheckButton("r126", &fcheckbox128);
		ui_interface->addCheckButton("r142", &fcheckbox144);
		ui_interface->addCheckButton("r158", &fcheckbox160);
		ui_interface->addCheckButton("r174", &fcheckbox176);
		ui_interface->addCheckButton("r190", &fcheckbox192);
		ui_interface->addCheckButton("r206", &fcheckbox208);
		ui_interface->addCheckButton("r222", &fcheckbox224);
		ui_interface->addCheckButton("r238", &fcheckbox234);
		ui_interface->addCheckButton("r254", &fcheckbox264);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del15-->");
		ui_interface->addCheckButton("r 15", &fcheckbox15);
		ui_interface->addCheckButton("r 31", &fcheckbox31);
		ui_interface->addCheckButton("r 47", &fcheckbox47);
		ui_interface->addCheckButton("r 63", &fcheckbox63);
		ui_interface->addCheckButton("r 79", &fcheckbox79);
		ui_interface->addCheckButton("r 95", &fcheckbox95);
		ui_interface->addCheckButton("r111", &fcheckbox111);
		ui_interface->addCheckButton("r127", &fcheckbox127);
		ui_interface->addCheckButton("r143", &fcheckbox143);
		ui_interface->addCheckButton("r159", &fcheckbox159);
		ui_interface->addCheckButton("r175", &fcheckbox175);
		ui_interface->addCheckButton("r191", &fcheckbox191);
		ui_interface->addCheckButton("r207", &fcheckbox207);
		ui_interface->addCheckButton("r223", &fcheckbox223);
		ui_interface->addCheckButton("r239", &fcheckbox244);
		ui_interface->addCheckButton("r255", &fcheckbox265);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("SpatializationMatrix");
		ui_interface->openVerticalBox("Sig 0-->");
		ui_interface->addCheckButton("sp  0", &fcheckbox291);
		ui_interface->addCheckButton("sp 17", &fcheckbox342);
		ui_interface->addCheckButton("sp 34", &fcheckbox366);
		ui_interface->addCheckButton("sp 51", &fcheckbox382);
		ui_interface->addCheckButton("sp 68", &fcheckbox400);
		ui_interface->addCheckButton("sp 85", &fcheckbox414);
		ui_interface->addCheckButton("sp102", &fcheckbox434);
		ui_interface->addCheckButton("sp119", &fcheckbox292);
		ui_interface->addCheckButton("sp136", &fcheckbox293);
		ui_interface->addCheckButton("sp153", &fcheckbox294);
		ui_interface->addCheckButton("sp170", &fcheckbox295);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 1-->");
		ui_interface->addCheckButton("sp  1", &fcheckbox284);
		ui_interface->addCheckButton("sp 18", &fcheckbox343);
		ui_interface->addCheckButton("sp 35", &fcheckbox364);
		ui_interface->addCheckButton("sp 52", &fcheckbox383);
		ui_interface->addCheckButton("sp 69", &fcheckbox401);
		ui_interface->addCheckButton("sp 86", &fcheckbox413);
		ui_interface->addCheckButton("sp103", &fcheckbox435);
		ui_interface->addCheckButton("sp120", &fcheckbox285);
		ui_interface->addCheckButton("sp137", &fcheckbox283);
		ui_interface->addCheckButton("sp154", &fcheckbox282);
		ui_interface->addCheckButton("sp171", &fcheckbox281);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 2-->");
		ui_interface->addCheckButton("sp  2", &fcheckbox326);
		ui_interface->addCheckButton("sp 19", &fcheckbox341);
		ui_interface->addCheckButton("sp 36", &fcheckbox363);
		ui_interface->addCheckButton("sp 53", &fcheckbox385);
		ui_interface->addCheckButton("sp 70", &fcheckbox403);
		ui_interface->addCheckButton("sp 87", &fcheckbox412);
		ui_interface->addCheckButton("sp104", &fcheckbox437);
		ui_interface->addCheckButton("sp121", &fcheckbox327);
		ui_interface->addCheckButton("sp138", &fcheckbox328);
		ui_interface->addCheckButton("sp155", &fcheckbox329);
		ui_interface->addCheckButton("sp172", &fcheckbox330);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 3-->");
		ui_interface->addCheckButton("sp  3", &fcheckbox5);
		ui_interface->addCheckButton("sp 20", &fcheckbox344);
		ui_interface->addCheckButton("sp 37", &fcheckbox362);
		ui_interface->addCheckButton("sp 54", &fcheckbox379);
		ui_interface->addCheckButton("sp 71", &fcheckbox397);
		ui_interface->addCheckButton("sp 88", &fcheckbox411);
		ui_interface->addCheckButton("sp105", &fcheckbox431);
		ui_interface->addCheckButton("sp122", &fcheckbox6);
		ui_interface->addCheckButton("sp139", &fcheckbox7);
		ui_interface->addCheckButton("sp156", &fcheckbox8);
		ui_interface->addCheckButton("sp173", &fcheckbox9);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 4-->");
		ui_interface->addCheckButton("sp  4", &fcheckbox296);
		ui_interface->addCheckButton("sp 21", &fcheckbox345);
		ui_interface->addCheckButton("sp 38", &fcheckbox361);
		ui_interface->addCheckButton("sp 55", &fcheckbox378);
		ui_interface->addCheckButton("sp 72", &fcheckbox396);
		ui_interface->addCheckButton("sp 89", &fcheckbox410);
		ui_interface->addCheckButton("sp106", &fcheckbox430);
		ui_interface->addCheckButton("sp123", &fcheckbox297);
		ui_interface->addCheckButton("sp140", &fcheckbox298);
		ui_interface->addCheckButton("sp157", &fcheckbox299);
		ui_interface->addCheckButton("sp174", &fcheckbox300);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 5-->");
		ui_interface->addCheckButton("sp  5", &fcheckbox321);
		ui_interface->addCheckButton("sp 22", &fcheckbox346);
		ui_interface->addCheckButton("sp 39", &fcheckbox360);
		ui_interface->addCheckButton("sp 56", &fcheckbox377);
		ui_interface->addCheckButton("sp 73", &fcheckbox395);
		ui_interface->addCheckButton("sp 90", &fcheckbox417);
		ui_interface->addCheckButton("sp107", &fcheckbox429);
		ui_interface->addCheckButton("sp124", &fcheckbox322);
		ui_interface->addCheckButton("sp141", &fcheckbox323);
		ui_interface->addCheckButton("sp158", &fcheckbox324);
		ui_interface->addCheckButton("sp175", &fcheckbox325);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 6-->");
		ui_interface->addCheckButton("sp  6", &fcheckbox339);
		ui_interface->addCheckButton("sp 23", &fcheckbox347);
		ui_interface->addCheckButton("sp 40", &fcheckbox367);
		ui_interface->addCheckButton("sp 57", &fcheckbox376);
		ui_interface->addCheckButton("sp 74", &fcheckbox394);
		ui_interface->addCheckButton("sp 91", &fcheckbox418);
		ui_interface->addCheckButton("sp108", &fcheckbox428);
		ui_interface->addCheckButton("sp125", &fcheckbox340);
		ui_interface->addCheckButton("sp142", &fcheckbox338);
		ui_interface->addCheckButton("sp159", &fcheckbox337);
		ui_interface->addCheckButton("sp176", &fcheckbox336);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 7-->");
		ui_interface->addCheckButton("sp  7", &fcheckbox306);
		ui_interface->addCheckButton("sp 24", &fcheckbox348);
		ui_interface->addCheckButton("sp 41", &fcheckbox369);
		ui_interface->addCheckButton("sp 58", &fcheckbox381);
		ui_interface->addCheckButton("sp 75", &fcheckbox399);
		ui_interface->addCheckButton("sp 92", &fcheckbox416);
		ui_interface->addCheckButton("sp109", &fcheckbox433);
		ui_interface->addCheckButton("sp126", &fcheckbox307);
		ui_interface->addCheckButton("sp143", &fcheckbox308);
		ui_interface->addCheckButton("sp160", &fcheckbox309);
		ui_interface->addCheckButton("sp177", &fcheckbox310);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 8-->");
		ui_interface->addCheckButton("sp  8", &fcheckbox271);
		ui_interface->addCheckButton("sp 25", &fcheckbox349);
		ui_interface->addCheckButton("sp 42", &fcheckbox368);
		ui_interface->addCheckButton("sp 59", &fcheckbox384);
		ui_interface->addCheckButton("sp 76", &fcheckbox402);
		ui_interface->addCheckButton("sp 93", &fcheckbox415);
		ui_interface->addCheckButton("sp110", &fcheckbox436);
		ui_interface->addCheckButton("sp127", &fcheckbox272);
		ui_interface->addCheckButton("sp144", &fcheckbox273);
		ui_interface->addCheckButton("sp161", &fcheckbox274);
		ui_interface->addCheckButton("sp178", &fcheckbox275);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig 9-->");
		ui_interface->addCheckButton("sp  9", &fcheckbox301);
		ui_interface->addCheckButton("sp 26", &fcheckbox350);
		ui_interface->addCheckButton("sp 43", &fcheckbox365);
		ui_interface->addCheckButton("sp 60", &fcheckbox380);
		ui_interface->addCheckButton("sp 77", &fcheckbox398);
		ui_interface->addCheckButton("sp 94", &fcheckbox409);
		ui_interface->addCheckButton("sp111", &fcheckbox432);
		ui_interface->addCheckButton("sp128", &fcheckbox302);
		ui_interface->addCheckButton("sp145", &fcheckbox303);
		ui_interface->addCheckButton("sp162", &fcheckbox304);
		ui_interface->addCheckButton("sp179", &fcheckbox305);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig10-->");
		ui_interface->addCheckButton("sp 10", &fcheckbox266);
		ui_interface->addCheckButton("sp 27", &fcheckbox351);
		ui_interface->addCheckButton("sp 44", &fcheckbox359);
		ui_interface->addCheckButton("sp 61", &fcheckbox386);
		ui_interface->addCheckButton("sp 78", &fcheckbox404);
		ui_interface->addCheckButton("sp 95", &fcheckbox419);
		ui_interface->addCheckButton("sp112", &fcheckbox438);
		ui_interface->addCheckButton("sp129", &fcheckbox267);
		ui_interface->addCheckButton("sp146", &fcheckbox268);
		ui_interface->addCheckButton("sp163", &fcheckbox269);
		ui_interface->addCheckButton("sp180", &fcheckbox270);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig11-->");
		ui_interface->addCheckButton("sp 11", &fcheckbox316);
		ui_interface->addCheckButton("sp 28", &fcheckbox352);
		ui_interface->addCheckButton("sp 45", &fcheckbox358);
		ui_interface->addCheckButton("sp 62", &fcheckbox375);
		ui_interface->addCheckButton("sp 79", &fcheckbox393);
		ui_interface->addCheckButton("sp 96", &fcheckbox420);
		ui_interface->addCheckButton("sp113", &fcheckbox427);
		ui_interface->addCheckButton("sp130", &fcheckbox317);
		ui_interface->addCheckButton("sp147", &fcheckbox318);
		ui_interface->addCheckButton("sp164", &fcheckbox319);
		ui_interface->addCheckButton("sp181", &fcheckbox320);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig12-->");
		ui_interface->addCheckButton("sp 12", &fcheckbox279);
		ui_interface->addCheckButton("sp 29", &fcheckbox353);
		ui_interface->addCheckButton("sp 46", &fcheckbox370);
		ui_interface->addCheckButton("sp 63", &fcheckbox387);
		ui_interface->addCheckButton("sp 80", &fcheckbox405);
		ui_interface->addCheckButton("sp 97", &fcheckbox421);
		ui_interface->addCheckButton("sp114", &fcheckbox439);
		ui_interface->addCheckButton("sp131", &fcheckbox280);
		ui_interface->addCheckButton("sp148", &fcheckbox278);
		ui_interface->addCheckButton("sp165", &fcheckbox277);
		ui_interface->addCheckButton("sp182", &fcheckbox276);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig13-->");
		ui_interface->addCheckButton("sp 13", &fcheckbox311);
		ui_interface->addCheckButton("sp 30", &fcheckbox354);
		ui_interface->addCheckButton("sp 47", &fcheckbox371);
		ui_interface->addCheckButton("sp 64", &fcheckbox388);
		ui_interface->addCheckButton("sp 81", &fcheckbox406);
		ui_interface->addCheckButton("sp 98", &fcheckbox422);
		ui_interface->addCheckButton("sp115", &fcheckbox440);
		ui_interface->addCheckButton("sp132", &fcheckbox312);
		ui_interface->addCheckButton("sp149", &fcheckbox313);
		ui_interface->addCheckButton("sp166", &fcheckbox314);
		ui_interface->addCheckButton("sp183", &fcheckbox315);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig14-->");
		ui_interface->addCheckButton("sp 14", &fcheckbox334);
		ui_interface->addCheckButton("sp 31", &fcheckbox355);
		ui_interface->addCheckButton("sp 48", &fcheckbox372);
		ui_interface->addCheckButton("sp 65", &fcheckbox389);
		ui_interface->addCheckButton("sp 82", &fcheckbox407);
		ui_interface->addCheckButton("sp 99", &fcheckbox423);
		ui_interface->addCheckButton("sp116", &fcheckbox441);
		ui_interface->addCheckButton("sp133", &fcheckbox335);
		ui_interface->addCheckButton("sp150", &fcheckbox333);
		ui_interface->addCheckButton("sp167", &fcheckbox332);
		ui_interface->addCheckButton("sp184", &fcheckbox331);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig15-->");
		ui_interface->addCheckButton("sp 15", &fcheckbox286);
		ui_interface->addCheckButton("sp 32", &fcheckbox356);
		ui_interface->addCheckButton("sp 49", &fcheckbox373);
		ui_interface->addCheckButton("sp 66", &fcheckbox390);
		ui_interface->addCheckButton("sp 83", &fcheckbox408);
		ui_interface->addCheckButton("sp100", &fcheckbox424);
		ui_interface->addCheckButton("sp117", &fcheckbox442);
		ui_interface->addCheckButton("sp134", &fcheckbox287);
		ui_interface->addCheckButton("sp151", &fcheckbox288);
		ui_interface->addCheckButton("sp168", &fcheckbox289);
		ui_interface->addCheckButton("sp185", &fcheckbox290);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Sig16-->");
		ui_interface->addCheckButton("sp 16", &fcheckbox0);
		ui_interface->addCheckButton("sp 33", &fcheckbox357);
		ui_interface->addCheckButton("sp 50", &fcheckbox374);
		ui_interface->addCheckButton("sp 67", &fcheckbox391);
		ui_interface->addCheckButton("sp 84", &fcheckbox392);
		ui_interface->addCheckButton("sp101", &fcheckbox425);
		ui_interface->addCheckButton("sp118", &fcheckbox426);
		ui_interface->addCheckButton("sp135", &fcheckbox1);
		ui_interface->addCheckButton("sp152", &fcheckbox2);
		ui_interface->addCheckButton("sp169", &fcheckbox3);
		ui_interface->addCheckButton("sp186", &fcheckbox4);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("RandomEnv");
		ui_interface->addNumEntry("renv_freq", &fentry0, 1e+01, 0.01, 1e+02, 0.01);
		ui_interface->addHorizontalSlider("renv_short", &fslider112, 0.5, 0.0, 1.0, 0.01);
		ui_interface->addHorizontalSlider("renv_trim", &fslider111, 0.0, -127.0, 18.0, 0.01);
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		double 	fSlow0 = double(fcheckbox1);
		double 	fSlow1 = double(fcheckbox2);
		double 	fSlow2 = double(fcheckbox3);
		double 	fSlow3 = double(fcheckbox4);
		double 	fSlow4 = ((((double(fcheckbox0) + fSlow0) + fSlow1) + fSlow2) + fSlow3);
		double 	fSlow5 = exp((0 - (fConst1 / double(fslider1))));
		double 	fSlow6 = (1.0 - fSlow5);
		double 	fSlow7 = (double(fslider0) * fSlow6);
		double 	fSlow8 = double(fcheckbox6);
		double 	fSlow9 = double(fcheckbox7);
		double 	fSlow10 = double(fcheckbox8);
		double 	fSlow11 = double(fcheckbox9);
		double 	fSlow12 = ((((double(fcheckbox5) + fSlow8) + fSlow9) + fSlow10) + fSlow11);
		double 	fSlow13 = double(fslider3);
		double 	fSlow14 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((double(fslider2) * fSlow13) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow15 = double(fslider4);
		double 	fSlow16 = ((int((fSlow15 < 127)))?fSlow15:127);
		double 	fSlow17 = ((int((fSlow16 < 1)))?0:(4096 * pow(1.07177,(fSlow16 + -127))));
		double 	fSlow18 = double(fslider5);
		double 	fSlow19 = double(fslider6);
		double 	fSlow20 = (1 - (0.75 * fSlow19));
		double 	fSlow21 = (double(fcheckbox10) * fSlow20);
		double 	fSlow22 = (double(fslider7) * fSlow6);
		double 	fSlow23 = double(fslider8);
		double 	fSlow24 = (1 - (0.75 * fSlow23));
		double 	fSlow25 = (double(fcheckbox11) * fSlow24);
		double 	fSlow26 = (double(fslider9) * fSlow6);
		double 	fSlow27 = (1 - (0.75 * fSlow18));
		double 	fSlow28 = (double(fcheckbox12) * fSlow27);
		double 	fSlow29 = (double(fslider10) * fSlow6);
		double 	fSlow30 = double(fslider11);
		double 	fSlow31 = (1 - (0.75 * fSlow30));
		double 	fSlow32 = (double(fcheckbox13) * fSlow31);
		double 	fSlow33 = (double(fslider12) * fSlow6);
		double 	fSlow34 = double(fslider13);
		double 	fSlow35 = (1 - (0.75 * fSlow34));
		double 	fSlow36 = (double(fcheckbox14) * fSlow35);
		double 	fSlow37 = (double(fslider14) * fSlow6);
		double 	fSlow38 = (double(fslider15) * fSlow6);
		double 	fSlow39 = (double(fslider16) * fSlow6);
		double 	fSlow40 = double(fslider17);
		double 	fSlow41 = (1 - (0.75 * fSlow40));
		double 	fSlow42 = (double(fcheckbox15) * fSlow41);
		double 	fSlow43 = (double(fslider18) * fSlow6);
		double 	fSlow44 = double(fslider19);
		double 	fSlow45 = (1 - (0.75 * fSlow44));
		double 	fSlow46 = (double(fcheckbox16) * fSlow45);
		double 	fSlow47 = (double(fslider20) * fSlow6);
		double 	fSlow48 = double(fslider21);
		double 	fSlow49 = (1 - (0.75 * fSlow48));
		double 	fSlow50 = (double(fcheckbox17) * fSlow49);
		double 	fSlow51 = (double(fslider22) * fSlow6);
		double 	fSlow52 = double(fslider23);
		double 	fSlow53 = (1 - (0.75 * fSlow52));
		double 	fSlow54 = (double(fcheckbox18) * fSlow53);
		double 	fSlow55 = (double(fslider24) * fSlow6);
		double 	fSlow56 = double(fslider25);
		double 	fSlow57 = (1 - (0.75 * fSlow56));
		double 	fSlow58 = (double(fcheckbox19) * fSlow57);
		double 	fSlow59 = (double(fslider26) * fSlow6);
		double 	fSlow60 = double(fslider27);
		double 	fSlow61 = (1 - (0.75 * fSlow60));
		double 	fSlow62 = (double(fcheckbox20) * fSlow61);
		double 	fSlow63 = (double(fslider28) * fSlow6);
		double 	fSlow64 = double(fslider29);
		double 	fSlow65 = (1 - (0.75 * fSlow64));
		double 	fSlow66 = (double(fcheckbox21) * fSlow65);
		double 	fSlow67 = (double(fslider30) * fSlow6);
		double 	fSlow68 = double(fslider31);
		double 	fSlow69 = (1 - (0.75 * fSlow68));
		double 	fSlow70 = (double(fcheckbox22) * fSlow69);
		double 	fSlow71 = (double(fslider32) * fSlow6);
		double 	fSlow72 = double(fslider33);
		double 	fSlow73 = (1 - (0.75 * fSlow72));
		double 	fSlow74 = (double(fcheckbox23) * fSlow73);
		double 	fSlow75 = (double(fslider34) * fSlow6);
		double 	fSlow76 = double(fslider35);
		double 	fSlow77 = (1 - (0.75 * fSlow76));
		double 	fSlow78 = (double(fcheckbox24) * fSlow77);
		double 	fSlow79 = (double(fslider36) * fSlow6);
		double 	fSlow80 = double(fslider37);
		double 	fSlow81 = (1 - (0.75 * fSlow80));
		double 	fSlow82 = (double(fcheckbox25) * fSlow81);
		double 	fSlow83 = (double(fslider38) * fSlow6);
		double 	fSlow84 = double(fslider39);
		int 	iSlow85 = int((fConst5 * (fSlow84 * double(fslider40))));
		double 	fSlow86 = (1 - fSlow18);
		double 	fSlow87 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider41)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow88 = (double(fcheckbox26) * fSlow24);
		double 	fSlow89 = (double(fcheckbox27) * fSlow20);
		double 	fSlow90 = (double(fcheckbox28) * fSlow31);
		double 	fSlow91 = (double(fcheckbox29) * fSlow35);
		double 	fSlow92 = (double(fcheckbox30) * fSlow27);
		double 	fSlow93 = (double(fslider42) * fSlow6);
		double 	fSlow94 = (double(fcheckbox31) * fSlow41);
		double 	fSlow95 = (double(fcheckbox32) * fSlow45);
		double 	fSlow96 = (double(fcheckbox33) * fSlow49);
		double 	fSlow97 = (double(fcheckbox34) * fSlow53);
		double 	fSlow98 = (double(fcheckbox35) * fSlow57);
		double 	fSlow99 = (double(fcheckbox36) * fSlow61);
		double 	fSlow100 = (double(fcheckbox37) * fSlow65);
		double 	fSlow101 = (double(fcheckbox38) * fSlow69);
		double 	fSlow102 = (double(fcheckbox39) * fSlow73);
		double 	fSlow103 = (double(fcheckbox40) * fSlow77);
		double 	fSlow104 = (double(fcheckbox41) * fSlow81);
		int 	iSlow105 = int((fConst5 * (fSlow84 * double(fslider43))));
		double 	fSlow106 = (1 - fSlow76);
		double 	fSlow107 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider44)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow108 = (double(fcheckbox42) * fSlow31);
		double 	fSlow109 = (double(fcheckbox43) * fSlow24);
		double 	fSlow110 = (double(fcheckbox44) * fSlow20);
		double 	fSlow111 = (double(fcheckbox45) * fSlow35);
		double 	fSlow112 = (double(fcheckbox46) * fSlow27);
		double 	fSlow113 = (double(fslider45) * fSlow6);
		double 	fSlow114 = (double(fcheckbox47) * fSlow41);
		double 	fSlow115 = (double(fcheckbox48) * fSlow45);
		double 	fSlow116 = (double(fcheckbox49) * fSlow49);
		double 	fSlow117 = (double(fcheckbox50) * fSlow53);
		double 	fSlow118 = (double(fcheckbox51) * fSlow57);
		double 	fSlow119 = (double(fcheckbox52) * fSlow61);
		double 	fSlow120 = (double(fcheckbox53) * fSlow65);
		double 	fSlow121 = (double(fcheckbox54) * fSlow69);
		double 	fSlow122 = (double(fcheckbox55) * fSlow73);
		double 	fSlow123 = (double(fcheckbox56) * fSlow77);
		double 	fSlow124 = (double(fcheckbox57) * fSlow81);
		int 	iSlow125 = int((fConst5 * (fSlow84 * double(fslider46))));
		double 	fSlow126 = (1 - fSlow34);
		double 	fSlow127 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider47)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow128 = (double(fcheckbox58) * fSlow31);
		double 	fSlow129 = (double(fcheckbox59) * fSlow24);
		double 	fSlow130 = (double(fcheckbox60) * fSlow20);
		double 	fSlow131 = (double(fcheckbox61) * fSlow35);
		double 	fSlow132 = (double(fcheckbox62) * fSlow27);
		double 	fSlow133 = (double(fslider48) * fSlow6);
		double 	fSlow134 = (double(fcheckbox63) * fSlow41);
		double 	fSlow135 = (double(fcheckbox64) * fSlow45);
		double 	fSlow136 = (double(fcheckbox65) * fSlow49);
		double 	fSlow137 = (double(fcheckbox66) * fSlow53);
		double 	fSlow138 = (double(fcheckbox67) * fSlow57);
		double 	fSlow139 = (double(fcheckbox68) * fSlow61);
		double 	fSlow140 = (double(fcheckbox69) * fSlow65);
		double 	fSlow141 = (double(fcheckbox70) * fSlow69);
		double 	fSlow142 = (double(fcheckbox71) * fSlow73);
		double 	fSlow143 = (double(fcheckbox72) * fSlow77);
		double 	fSlow144 = (double(fcheckbox73) * fSlow81);
		int 	iSlow145 = int((fConst5 * (fSlow84 * double(fslider49))));
		double 	fSlow146 = (1 - fSlow30);
		double 	fSlow147 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider50)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow148 = (double(fcheckbox74) * fSlow31);
		double 	fSlow149 = (double(fcheckbox75) * fSlow24);
		double 	fSlow150 = (double(fcheckbox76) * fSlow20);
		double 	fSlow151 = (double(fcheckbox77) * fSlow35);
		double 	fSlow152 = (double(fcheckbox78) * fSlow27);
		double 	fSlow153 = (double(fslider51) * fSlow6);
		double 	fSlow154 = (double(fcheckbox79) * fSlow41);
		double 	fSlow155 = (double(fcheckbox80) * fSlow45);
		double 	fSlow156 = (double(fcheckbox81) * fSlow49);
		double 	fSlow157 = (double(fcheckbox82) * fSlow53);
		double 	fSlow158 = (double(fcheckbox83) * fSlow57);
		double 	fSlow159 = (double(fcheckbox84) * fSlow61);
		double 	fSlow160 = (double(fcheckbox85) * fSlow65);
		double 	fSlow161 = (double(fcheckbox86) * fSlow69);
		double 	fSlow162 = (double(fcheckbox87) * fSlow73);
		double 	fSlow163 = (double(fcheckbox88) * fSlow77);
		double 	fSlow164 = (double(fcheckbox89) * fSlow81);
		int 	iSlow165 = int((fConst5 * (fSlow84 * double(fslider52))));
		double 	fSlow166 = (1 - fSlow19);
		double 	fSlow167 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider53)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow168 = (double(fcheckbox90) * fSlow31);
		double 	fSlow169 = (double(fcheckbox91) * fSlow24);
		double 	fSlow170 = (double(fcheckbox92) * fSlow20);
		double 	fSlow171 = (double(fcheckbox93) * fSlow35);
		double 	fSlow172 = (double(fcheckbox94) * fSlow27);
		double 	fSlow173 = (double(fslider54) * fSlow6);
		double 	fSlow174 = (double(fcheckbox95) * fSlow41);
		double 	fSlow175 = (double(fcheckbox96) * fSlow45);
		double 	fSlow176 = (double(fcheckbox97) * fSlow49);
		double 	fSlow177 = (double(fcheckbox98) * fSlow53);
		double 	fSlow178 = (double(fcheckbox99) * fSlow57);
		double 	fSlow179 = (double(fcheckbox100) * fSlow61);
		double 	fSlow180 = (double(fcheckbox101) * fSlow65);
		double 	fSlow181 = (double(fcheckbox102) * fSlow69);
		double 	fSlow182 = (double(fcheckbox103) * fSlow73);
		double 	fSlow183 = (double(fcheckbox104) * fSlow77);
		double 	fSlow184 = (double(fcheckbox105) * fSlow81);
		int 	iSlow185 = int((fConst5 * (fSlow84 * double(fslider55))));
		double 	fSlow186 = (1 - fSlow23);
		double 	fSlow187 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider56)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow188 = (double(fcheckbox106) * fSlow31);
		double 	fSlow189 = (double(fcheckbox107) * fSlow24);
		double 	fSlow190 = (double(fcheckbox108) * fSlow20);
		double 	fSlow191 = (double(fcheckbox109) * fSlow35);
		double 	fSlow192 = (double(fcheckbox110) * fSlow27);
		double 	fSlow193 = (double(fslider57) * fSlow6);
		double 	fSlow194 = (double(fcheckbox111) * fSlow41);
		double 	fSlow195 = (double(fcheckbox112) * fSlow45);
		double 	fSlow196 = (double(fcheckbox113) * fSlow49);
		double 	fSlow197 = (double(fcheckbox114) * fSlow53);
		double 	fSlow198 = (double(fcheckbox115) * fSlow57);
		double 	fSlow199 = (double(fcheckbox116) * fSlow61);
		double 	fSlow200 = (double(fcheckbox117) * fSlow65);
		double 	fSlow201 = (double(fcheckbox118) * fSlow69);
		double 	fSlow202 = (double(fcheckbox119) * fSlow73);
		double 	fSlow203 = (double(fcheckbox120) * fSlow77);
		double 	fSlow204 = (double(fcheckbox121) * fSlow81);
		int 	iSlow205 = int((fConst5 * (fSlow84 * double(fslider58))));
		double 	fSlow206 = (1 - fSlow80);
		double 	fSlow207 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider59)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow208 = (double(fcheckbox122) * fSlow31);
		double 	fSlow209 = (double(fcheckbox123) * fSlow24);
		double 	fSlow210 = (double(fcheckbox124) * fSlow20);
		double 	fSlow211 = (double(fcheckbox125) * fSlow35);
		double 	fSlow212 = (double(fcheckbox126) * fSlow27);
		double 	fSlow213 = (double(fslider60) * fSlow6);
		double 	fSlow214 = (double(fcheckbox127) * fSlow41);
		double 	fSlow215 = (double(fcheckbox128) * fSlow45);
		double 	fSlow216 = (double(fcheckbox129) * fSlow49);
		double 	fSlow217 = (double(fcheckbox130) * fSlow53);
		double 	fSlow218 = (double(fcheckbox131) * fSlow57);
		double 	fSlow219 = (double(fcheckbox132) * fSlow61);
		double 	fSlow220 = (double(fcheckbox133) * fSlow65);
		double 	fSlow221 = (double(fcheckbox134) * fSlow69);
		double 	fSlow222 = (double(fcheckbox135) * fSlow73);
		double 	fSlow223 = (double(fcheckbox136) * fSlow77);
		double 	fSlow224 = (double(fcheckbox137) * fSlow81);
		int 	iSlow225 = int((fConst5 * (fSlow84 * double(fslider61))));
		double 	fSlow226 = (1 - fSlow72);
		double 	fSlow227 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider62)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow228 = (double(fcheckbox138) * fSlow31);
		double 	fSlow229 = (double(fcheckbox139) * fSlow24);
		double 	fSlow230 = (double(fcheckbox140) * fSlow20);
		double 	fSlow231 = (double(fcheckbox141) * fSlow35);
		double 	fSlow232 = (double(fcheckbox142) * fSlow27);
		double 	fSlow233 = (double(fslider63) * fSlow6);
		double 	fSlow234 = (double(fcheckbox143) * fSlow41);
		double 	fSlow235 = (double(fcheckbox144) * fSlow45);
		double 	fSlow236 = (double(fcheckbox145) * fSlow49);
		double 	fSlow237 = (double(fcheckbox146) * fSlow53);
		double 	fSlow238 = (double(fcheckbox147) * fSlow57);
		double 	fSlow239 = (double(fcheckbox148) * fSlow61);
		double 	fSlow240 = (double(fcheckbox149) * fSlow65);
		double 	fSlow241 = (double(fcheckbox150) * fSlow69);
		double 	fSlow242 = (double(fcheckbox151) * fSlow73);
		double 	fSlow243 = (double(fcheckbox152) * fSlow77);
		double 	fSlow244 = (double(fcheckbox153) * fSlow81);
		int 	iSlow245 = int((fConst5 * (fSlow84 * double(fslider64))));
		double 	fSlow246 = (1 - fSlow68);
		double 	fSlow247 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider65)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow248 = (double(fcheckbox154) * fSlow31);
		double 	fSlow249 = (double(fcheckbox155) * fSlow24);
		double 	fSlow250 = (double(fcheckbox156) * fSlow20);
		double 	fSlow251 = (double(fcheckbox157) * fSlow35);
		double 	fSlow252 = (double(fcheckbox158) * fSlow27);
		double 	fSlow253 = (double(fslider66) * fSlow6);
		double 	fSlow254 = (double(fcheckbox159) * fSlow41);
		double 	fSlow255 = (double(fcheckbox160) * fSlow45);
		double 	fSlow256 = (double(fcheckbox161) * fSlow49);
		double 	fSlow257 = (double(fcheckbox162) * fSlow53);
		double 	fSlow258 = (double(fcheckbox163) * fSlow57);
		double 	fSlow259 = (double(fcheckbox164) * fSlow61);
		double 	fSlow260 = (double(fcheckbox165) * fSlow65);
		double 	fSlow261 = (double(fcheckbox166) * fSlow69);
		double 	fSlow262 = (double(fcheckbox167) * fSlow73);
		double 	fSlow263 = (double(fcheckbox168) * fSlow77);
		double 	fSlow264 = (double(fcheckbox169) * fSlow81);
		int 	iSlow265 = int((fConst5 * (fSlow84 * double(fslider67))));
		double 	fSlow266 = (1 - fSlow64);
		double 	fSlow267 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider68)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow268 = (double(fcheckbox170) * fSlow31);
		double 	fSlow269 = (double(fcheckbox171) * fSlow24);
		double 	fSlow270 = (double(fcheckbox172) * fSlow20);
		double 	fSlow271 = (double(fcheckbox173) * fSlow35);
		double 	fSlow272 = (double(fcheckbox174) * fSlow27);
		double 	fSlow273 = (double(fslider69) * fSlow6);
		double 	fSlow274 = (double(fcheckbox175) * fSlow41);
		double 	fSlow275 = (double(fcheckbox176) * fSlow45);
		double 	fSlow276 = (double(fcheckbox177) * fSlow49);
		double 	fSlow277 = (double(fcheckbox178) * fSlow53);
		double 	fSlow278 = (double(fcheckbox179) * fSlow57);
		double 	fSlow279 = (double(fcheckbox180) * fSlow61);
		double 	fSlow280 = (double(fcheckbox181) * fSlow65);
		double 	fSlow281 = (double(fcheckbox182) * fSlow69);
		double 	fSlow282 = (double(fcheckbox183) * fSlow73);
		double 	fSlow283 = (double(fcheckbox184) * fSlow77);
		double 	fSlow284 = (double(fcheckbox185) * fSlow81);
		int 	iSlow285 = int((fConst5 * (fSlow84 * double(fslider70))));
		double 	fSlow286 = (1 - fSlow60);
		double 	fSlow287 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider71)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow288 = (double(fcheckbox186) * fSlow31);
		double 	fSlow289 = (double(fcheckbox187) * fSlow24);
		double 	fSlow290 = (double(fcheckbox188) * fSlow20);
		double 	fSlow291 = (double(fcheckbox189) * fSlow35);
		double 	fSlow292 = (double(fcheckbox190) * fSlow27);
		double 	fSlow293 = (double(fslider72) * fSlow6);
		double 	fSlow294 = (double(fcheckbox191) * fSlow41);
		double 	fSlow295 = (double(fcheckbox192) * fSlow45);
		double 	fSlow296 = (double(fcheckbox193) * fSlow49);
		double 	fSlow297 = (double(fcheckbox194) * fSlow53);
		double 	fSlow298 = (double(fcheckbox195) * fSlow57);
		double 	fSlow299 = (double(fcheckbox196) * fSlow61);
		double 	fSlow300 = (double(fcheckbox197) * fSlow65);
		double 	fSlow301 = (double(fcheckbox198) * fSlow69);
		double 	fSlow302 = (double(fcheckbox199) * fSlow73);
		double 	fSlow303 = (double(fcheckbox200) * fSlow77);
		double 	fSlow304 = (double(fcheckbox201) * fSlow81);
		int 	iSlow305 = int((fConst5 * (fSlow84 * double(fslider73))));
		double 	fSlow306 = (1 - fSlow56);
		double 	fSlow307 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider74)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow308 = (double(fcheckbox202) * fSlow31);
		double 	fSlow309 = (double(fcheckbox203) * fSlow24);
		double 	fSlow310 = (double(fcheckbox204) * fSlow20);
		double 	fSlow311 = (double(fcheckbox205) * fSlow35);
		double 	fSlow312 = (double(fcheckbox206) * fSlow27);
		double 	fSlow313 = (double(fslider75) * fSlow6);
		double 	fSlow314 = (double(fcheckbox207) * fSlow41);
		double 	fSlow315 = (double(fcheckbox208) * fSlow45);
		double 	fSlow316 = (double(fcheckbox209) * fSlow49);
		double 	fSlow317 = (double(fcheckbox210) * fSlow53);
		double 	fSlow318 = (double(fcheckbox211) * fSlow57);
		double 	fSlow319 = (double(fcheckbox212) * fSlow61);
		double 	fSlow320 = (double(fcheckbox213) * fSlow65);
		double 	fSlow321 = (double(fcheckbox214) * fSlow69);
		double 	fSlow322 = (double(fcheckbox215) * fSlow73);
		double 	fSlow323 = (double(fcheckbox216) * fSlow77);
		double 	fSlow324 = (double(fcheckbox217) * fSlow81);
		int 	iSlow325 = int((fConst5 * (fSlow84 * double(fslider76))));
		double 	fSlow326 = (1 - fSlow52);
		double 	fSlow327 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider77)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow328 = (double(fcheckbox218) * fSlow31);
		double 	fSlow329 = (double(fcheckbox219) * fSlow24);
		double 	fSlow330 = (double(fcheckbox220) * fSlow20);
		double 	fSlow331 = (double(fcheckbox221) * fSlow35);
		double 	fSlow332 = (double(fcheckbox222) * fSlow27);
		double 	fSlow333 = (double(fslider78) * fSlow6);
		double 	fSlow334 = (double(fcheckbox223) * fSlow41);
		double 	fSlow335 = (double(fcheckbox224) * fSlow45);
		double 	fSlow336 = (double(fcheckbox225) * fSlow49);
		double 	fSlow337 = (double(fcheckbox226) * fSlow53);
		double 	fSlow338 = (double(fcheckbox227) * fSlow57);
		double 	fSlow339 = (double(fcheckbox228) * fSlow61);
		double 	fSlow340 = (double(fcheckbox229) * fSlow65);
		double 	fSlow341 = (double(fcheckbox230) * fSlow69);
		double 	fSlow342 = (double(fcheckbox231) * fSlow73);
		double 	fSlow343 = (double(fcheckbox232) * fSlow77);
		double 	fSlow344 = (double(fcheckbox233) * fSlow81);
		int 	iSlow345 = int((fConst5 * (fSlow84 * double(fslider79))));
		double 	fSlow346 = (1 - fSlow48);
		double 	fSlow347 = (double(fcheckbox234) * fSlow45);
		double 	fSlow348 = (double(fcheckbox235) * fSlow49);
		double 	fSlow349 = (double(fcheckbox236) * fSlow53);
		double 	fSlow350 = (double(fcheckbox237) * fSlow57);
		double 	fSlow351 = (double(fcheckbox238) * fSlow61);
		double 	fSlow352 = (double(fcheckbox239) * fSlow65);
		double 	fSlow353 = (double(fcheckbox240) * fSlow69);
		double 	fSlow354 = (double(fcheckbox241) * fSlow73);
		double 	fSlow355 = (double(fcheckbox242) * fSlow77);
		double 	fSlow356 = (double(fcheckbox243) * fSlow81);
		double 	fSlow357 = (double(fcheckbox244) * fSlow41);
		double 	fSlow358 = (double(fslider80) * fSlow6);
		double 	fSlow359 = (double(fcheckbox245) * fSlow27);
		double 	fSlow360 = (double(fcheckbox246) * fSlow35);
		double 	fSlow361 = (double(fcheckbox247) * fSlow20);
		double 	fSlow362 = (double(fcheckbox248) * fSlow24);
		double 	fSlow363 = (double(fcheckbox249) * fSlow31);
		int 	iSlow364 = int((fConst5 * (fSlow84 * double(fslider81))));
		double 	fSlow365 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider82)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow366 = (1 - fSlow44);
		double 	fSlow367 = (fConst3 * (0 - (3.8224 * ((4.4e+02 * pow(2.0,(0.08333333333333333 * ((0.01 * ((fSlow13 * double(fslider83)) + 6000)) + -69.0)))) + -261.625977))));
		double 	fSlow368 = (double(fcheckbox250) * fSlow24);
		double 	fSlow369 = (double(fcheckbox251) * fSlow35);
		double 	fSlow370 = (double(fcheckbox252) * fSlow27);
		double 	fSlow371 = (double(fcheckbox253) * fSlow31);
		double 	fSlow372 = (double(fcheckbox254) * fSlow20);
		double 	fSlow373 = (double(fcheckbox255) * fSlow77);
		double 	fSlow374 = (double(fcheckbox256) * fSlow81);
		double 	fSlow375 = (double(fcheckbox257) * fSlow73);
		double 	fSlow376 = (double(fcheckbox258) * fSlow69);
		double 	fSlow377 = (double(fcheckbox259) * fSlow65);
		double 	fSlow378 = (double(fcheckbox260) * fSlow61);
		double 	fSlow379 = (double(fcheckbox261) * fSlow57);
		double 	fSlow380 = (double(fcheckbox262) * fSlow53);
		double 	fSlow381 = (double(fcheckbox263) * fSlow49);
		double 	fSlow382 = (double(fcheckbox264) * fSlow45);
		double 	fSlow383 = (double(fcheckbox265) * fSlow41);
		double 	fSlow384 = (double(fslider84) * fSlow6);
		int 	iSlow385 = int((fConst5 * (fSlow84 * double(fslider85))));
		double 	fSlow386 = (1 - fSlow40);
		double 	fSlow387 = (double(fslider86) * fSlow6);
		double 	fSlow388 = double(fcheckbox267);
		double 	fSlow389 = double(fcheckbox268);
		double 	fSlow390 = double(fcheckbox269);
		double 	fSlow391 = double(fcheckbox270);
		double 	fSlow392 = ((((double(fcheckbox266) + fSlow388) + fSlow389) + fSlow390) + fSlow391);
		double 	fSlow393 = (double(fslider87) * fSlow6);
		double 	fSlow394 = double(fcheckbox272);
		double 	fSlow395 = double(fcheckbox273);
		double 	fSlow396 = double(fcheckbox274);
		double 	fSlow397 = double(fcheckbox275);
		double 	fSlow398 = ((((double(fcheckbox271) + fSlow394) + fSlow395) + fSlow396) + fSlow397);
		double 	fSlow399 = (double(fslider88) * fSlow6);
		double 	fSlow400 = double(fcheckbox276);
		double 	fSlow401 = double(fcheckbox277);
		double 	fSlow402 = double(fcheckbox278);
		double 	fSlow403 = double(fcheckbox280);
		double 	fSlow404 = (fSlow400 + (fSlow401 + (fSlow402 + (double(fcheckbox279) + fSlow403))));
		double 	fSlow405 = (double(fslider89) * fSlow6);
		double 	fSlow406 = double(fcheckbox281);
		double 	fSlow407 = double(fcheckbox282);
		double 	fSlow408 = double(fcheckbox283);
		double 	fSlow409 = double(fcheckbox285);
		double 	fSlow410 = (fSlow406 + (fSlow407 + (fSlow408 + (double(fcheckbox284) + fSlow409))));
		double 	fSlow411 = (double(fslider90) * fSlow6);
		double 	fSlow412 = double(fcheckbox287);
		double 	fSlow413 = double(fcheckbox288);
		double 	fSlow414 = double(fcheckbox289);
		double 	fSlow415 = double(fcheckbox290);
		double 	fSlow416 = ((((double(fcheckbox286) + fSlow412) + fSlow413) + fSlow414) + fSlow415);
		double 	fSlow417 = (double(fslider91) * fSlow6);
		double 	fSlow418 = double(fcheckbox292);
		double 	fSlow419 = double(fcheckbox293);
		double 	fSlow420 = double(fcheckbox294);
		double 	fSlow421 = double(fcheckbox295);
		double 	fSlow422 = ((((double(fcheckbox291) + fSlow418) + fSlow419) + fSlow420) + fSlow421);
		double 	fSlow423 = (double(fslider92) * fSlow6);
		double 	fSlow424 = double(fcheckbox297);
		double 	fSlow425 = double(fcheckbox298);
		double 	fSlow426 = double(fcheckbox299);
		double 	fSlow427 = double(fcheckbox300);
		double 	fSlow428 = ((((double(fcheckbox296) + fSlow424) + fSlow425) + fSlow426) + fSlow427);
		double 	fSlow429 = (double(fslider93) * fSlow6);
		double 	fSlow430 = double(fcheckbox302);
		double 	fSlow431 = double(fcheckbox303);
		double 	fSlow432 = double(fcheckbox304);
		double 	fSlow433 = double(fcheckbox305);
		double 	fSlow434 = ((((double(fcheckbox301) + fSlow430) + fSlow431) + fSlow432) + fSlow433);
		double 	fSlow435 = (double(fslider94) * fSlow6);
		double 	fSlow436 = double(fcheckbox307);
		double 	fSlow437 = double(fcheckbox308);
		double 	fSlow438 = double(fcheckbox309);
		double 	fSlow439 = double(fcheckbox310);
		double 	fSlow440 = ((((double(fcheckbox306) + fSlow436) + fSlow437) + fSlow438) + fSlow439);
		double 	fSlow441 = (double(fslider95) * fSlow6);
		double 	fSlow442 = double(fcheckbox312);
		double 	fSlow443 = double(fcheckbox313);
		double 	fSlow444 = double(fcheckbox314);
		double 	fSlow445 = double(fcheckbox315);
		double 	fSlow446 = ((((double(fcheckbox311) + fSlow442) + fSlow443) + fSlow444) + fSlow445);
		double 	fSlow447 = (double(fslider96) * fSlow6);
		double 	fSlow448 = double(fcheckbox317);
		double 	fSlow449 = double(fcheckbox318);
		double 	fSlow450 = double(fcheckbox319);
		double 	fSlow451 = double(fcheckbox320);
		double 	fSlow452 = ((((double(fcheckbox316) + fSlow448) + fSlow449) + fSlow450) + fSlow451);
		double 	fSlow453 = (double(fslider97) * fSlow6);
		double 	fSlow454 = double(fcheckbox322);
		double 	fSlow455 = double(fcheckbox323);
		double 	fSlow456 = double(fcheckbox324);
		double 	fSlow457 = double(fcheckbox325);
		double 	fSlow458 = ((((double(fcheckbox321) + fSlow454) + fSlow455) + fSlow456) + fSlow457);
		double 	fSlow459 = (double(fslider98) * fSlow6);
		double 	fSlow460 = double(fcheckbox327);
		double 	fSlow461 = double(fcheckbox328);
		double 	fSlow462 = double(fcheckbox329);
		double 	fSlow463 = double(fcheckbox330);
		double 	fSlow464 = ((((double(fcheckbox326) + fSlow460) + fSlow461) + fSlow462) + fSlow463);
		double 	fSlow465 = (double(fslider99) * fSlow6);
		double 	fSlow466 = double(fcheckbox331);
		double 	fSlow467 = double(fcheckbox332);
		double 	fSlow468 = double(fcheckbox333);
		double 	fSlow469 = double(fcheckbox335);
		double 	fSlow470 = (fSlow466 + (fSlow467 + (fSlow468 + (double(fcheckbox334) + fSlow469))));
		double 	fSlow471 = (double(fslider100) * fSlow6);
		double 	fSlow472 = double(fcheckbox336);
		double 	fSlow473 = double(fcheckbox337);
		double 	fSlow474 = double(fcheckbox338);
		double 	fSlow475 = double(fcheckbox340);
		double 	fSlow476 = (fSlow472 + (fSlow473 + (fSlow474 + (double(fcheckbox339) + fSlow475))));
		double 	fSlow477 = (double(fslider101) * fSlow6);
		double 	fSlow478 = (fSlow6 * double(fslider102));
		double 	fSlow479 = double(fslider103);
		int 	iSlow480 = (fSlow479 == 0);
		double 	fSlow481 = double(fslider104);
		double 	fSlow482 = (iSlow480 * fSlow481);
		int 	iSlow483 = (1 - iSlow480);
		double 	fSlow484 = (fConst3 * fSlow479);
		double 	fSlow485 = double(fslider105);
		int 	iSlow486 = (fSlow485 == 0);
		double 	fSlow487 = double(fslider106);
		double 	fSlow488 = (iSlow486 * fSlow487);
		int 	iSlow489 = (1 - iSlow486);
		double 	fSlow490 = (fConst3 * fSlow485);
		double 	fSlow491 = double(fslider107);
		int 	iSlow492 = (fSlow491 == 0);
		double 	fSlow493 = double(fslider108);
		double 	fSlow494 = (iSlow492 * fSlow493);
		int 	iSlow495 = (1 - iSlow492);
		double 	fSlow496 = (fConst3 * fSlow491);
		double 	fSlow497 = double(fcheckbox341);
		double 	fSlow498 = double(fcheckbox342);
		double 	fSlow499 = double(fcheckbox343);
		double 	fSlow500 = double(fcheckbox344);
		double 	fSlow501 = double(fcheckbox345);
		double 	fSlow502 = double(fcheckbox346);
		double 	fSlow503 = double(fcheckbox347);
		double 	fSlow504 = double(fcheckbox348);
		double 	fSlow505 = double(fcheckbox349);
		double 	fSlow506 = double(fcheckbox350);
		double 	fSlow507 = double(fcheckbox351);
		double 	fSlow508 = double(fcheckbox352);
		double 	fSlow509 = double(fcheckbox353);
		double 	fSlow510 = double(fcheckbox354);
		double 	fSlow511 = double(fcheckbox355);
		double 	fSlow512 = double(fcheckbox356);
		double 	fSlow513 = double(fslider109);
		int 	iSlow514 = (fSlow513 == 0);
		double 	fSlow515 = double(fslider110);
		double 	fSlow516 = (iSlow514 * fSlow515);
		int 	iSlow517 = (1 - iSlow514);
		double 	fSlow518 = (fConst3 * fSlow513);
		double 	fSlow519 = double(fcheckbox357);
		double 	fSlow520 = (double(fslider111) * fSlow6);
		double 	fSlow521 = (fConst3 * double(fentry0));
		double 	fSlow522 = ((2 * double(fslider112)) + -1);
		double 	fSlow523 = double(fcheckbox358);
		double 	fSlow524 = double(fcheckbox359);
		double 	fSlow525 = double(fcheckbox360);
		double 	fSlow526 = double(fcheckbox361);
		double 	fSlow527 = double(fcheckbox362);
		double 	fSlow528 = double(fcheckbox363);
		double 	fSlow529 = double(fcheckbox364);
		double 	fSlow530 = double(fcheckbox365);
		double 	fSlow531 = double(fcheckbox366);
		double 	fSlow532 = double(fcheckbox367);
		double 	fSlow533 = double(fcheckbox368);
		double 	fSlow534 = double(fcheckbox369);
		double 	fSlow535 = double(fcheckbox370);
		double 	fSlow536 = double(fcheckbox371);
		double 	fSlow537 = double(fcheckbox372);
		double 	fSlow538 = double(fcheckbox373);
		double 	fSlow539 = double(fcheckbox374);
		double 	fSlow540 = double(fcheckbox375);
		double 	fSlow541 = double(fcheckbox376);
		double 	fSlow542 = double(fcheckbox377);
		double 	fSlow543 = double(fcheckbox378);
		double 	fSlow544 = double(fcheckbox379);
		double 	fSlow545 = double(fcheckbox380);
		double 	fSlow546 = double(fcheckbox381);
		double 	fSlow547 = double(fcheckbox382);
		double 	fSlow548 = double(fcheckbox383);
		double 	fSlow549 = double(fcheckbox384);
		double 	fSlow550 = double(fcheckbox385);
		double 	fSlow551 = double(fcheckbox386);
		double 	fSlow552 = double(fcheckbox387);
		double 	fSlow553 = double(fcheckbox388);
		double 	fSlow554 = double(fcheckbox389);
		double 	fSlow555 = double(fcheckbox390);
		double 	fSlow556 = double(fcheckbox391);
		double 	fSlow557 = double(fcheckbox392);
		double 	fSlow558 = double(fcheckbox393);
		double 	fSlow559 = double(fcheckbox394);
		double 	fSlow560 = double(fcheckbox395);
		double 	fSlow561 = double(fcheckbox396);
		double 	fSlow562 = double(fcheckbox397);
		double 	fSlow563 = double(fcheckbox398);
		double 	fSlow564 = double(fcheckbox399);
		double 	fSlow565 = double(fcheckbox400);
		double 	fSlow566 = double(fcheckbox401);
		double 	fSlow567 = double(fcheckbox402);
		double 	fSlow568 = double(fcheckbox403);
		double 	fSlow569 = double(fcheckbox404);
		double 	fSlow570 = double(fcheckbox405);
		double 	fSlow571 = double(fcheckbox406);
		double 	fSlow572 = double(fcheckbox407);
		double 	fSlow573 = double(fcheckbox408);
		double 	fSlow574 = double(fcheckbox409);
		double 	fSlow575 = double(fcheckbox410);
		double 	fSlow576 = double(fcheckbox411);
		double 	fSlow577 = double(fcheckbox412);
		double 	fSlow578 = double(fcheckbox413);
		double 	fSlow579 = double(fcheckbox414);
		double 	fSlow580 = double(fcheckbox415);
		double 	fSlow581 = double(fcheckbox416);
		double 	fSlow582 = double(fcheckbox417);
		double 	fSlow583 = double(fcheckbox418);
		double 	fSlow584 = double(fcheckbox419);
		double 	fSlow585 = double(fcheckbox420);
		double 	fSlow586 = double(fcheckbox421);
		double 	fSlow587 = double(fcheckbox422);
		double 	fSlow588 = double(fcheckbox423);
		double 	fSlow589 = double(fcheckbox424);
		double 	fSlow590 = double(fcheckbox425);
		double 	fSlow591 = double(fcheckbox426);
		double 	fSlow592 = double(fcheckbox427);
		double 	fSlow593 = double(fcheckbox428);
		double 	fSlow594 = double(fcheckbox429);
		double 	fSlow595 = double(fcheckbox430);
		double 	fSlow596 = double(fcheckbox431);
		double 	fSlow597 = double(fcheckbox432);
		double 	fSlow598 = double(fcheckbox433);
		double 	fSlow599 = double(fcheckbox434);
		double 	fSlow600 = double(fcheckbox435);
		double 	fSlow601 = double(fcheckbox436);
		double 	fSlow602 = double(fcheckbox437);
		double 	fSlow603 = double(fcheckbox438);
		double 	fSlow604 = double(fcheckbox439);
		double 	fSlow605 = double(fcheckbox440);
		double 	fSlow606 = double(fcheckbox441);
		double 	fSlow607 = double(fcheckbox442);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		for (int i=0; i<count; i++) {
			double fTemp0 = (double)input0[i];
			fRec0[0] = (fSlow7 + (fSlow5 * fRec0[1]));
			int iTemp1 = (fRec0[0] > -127.0);
			double fTemp2 = pow(10,(0.05 * fRec0[0]));
			double fTemp3 = ((fTemp0 * iTemp1) * fTemp2);
			fVec0[0] = fSlow17;
			double fTemp4 = ((int((fSlow17 != fVec0[1])))?fConst4:(fRec19[1] + -1));
			fRec19[0] = fTemp4;
			fRec20[0] = ((int((fTemp4 <= 0)))?fSlow17:(fRec20[1] + ((fSlow17 - fRec20[1]) / fTemp4)));
			double fTemp5 = double(fRec20[0]);
			double fTemp6 = (fRec18[1] + (fSlow14 / fTemp5));
			fRec18[0] = (fTemp6 - floor(fTemp6));
			double fTemp7 = (fRec18[0] - floor(fRec18[0]));
			fVec1[0] = fTemp7;
			double fTemp8 = (0.5 * fVec1[0]);
			double fTemp9 = (65536.0 * (fTemp8 - floor(fTemp8)));
			int iTemp10 = int(fTemp9);
			double fTemp11 = ftbl0[iTemp10];
			int iTemp12 = (fVec1[0] > 0.001);
			int iTemp13 = (fVec1[1] <= 0.001);
			fRec21[0] = ((fRec21[1] * (1 - (iTemp12 * iTemp13))) + ((fRec20[0] * iTemp12) * iTemp13));
			double fTemp14 = (fConst5 * (fVec1[0] * fRec21[0]));
			double fTemp15 = floor(fTemp14);
			fRec22[0] = (fConst6 + (fRec22[1] - floor((fConst6 + fRec22[1]))));
			double fTemp16 = (65536.0 * (fRec22[0] - floor(fRec22[0])));
			int iTemp17 = int(fTemp16);
			double fTemp18 = ftbl0[iTemp17];
			double fTemp19 = ((fTemp18 + ((fTemp16 - floor(fTemp16)) * (ftbl0[((iTemp17 + 1) % 65536)] - fTemp18))) + 1.0);
			fVec2[0] = fTemp19;
			fRec23[0] = (fSlow22 + (fSlow5 * fRec23[1]));
			double fTemp20 = (fRec5[1] * fRec23[0]);
			fRec24[0] = (fSlow26 + (fSlow5 * fRec24[1]));
			double fTemp21 = (fRec6[1] * fRec24[0]);
			fRec25[0] = (fSlow29 + (fSlow5 * fRec25[1]));
			double fTemp22 = (fRec1[1] * fRec25[0]);
			fRec26[0] = (fSlow33 + (fSlow5 * fRec26[1]));
			double fTemp23 = (fRec4[1] * fRec26[0]);
			fRec27[0] = (fSlow37 + (fSlow5 * fRec27[1]));
			double fTemp24 = (fRec3[1] * fRec27[0]);
			fRec28[0] = (fSlow38 + (fSlow5 * fRec28[1]));
			double fTemp25 = ((fTemp0 * (fRec28[0] > -127.0)) * pow(10,(0.05 * fRec28[0])));
			fRec29[0] = (fSlow39 + (fSlow5 * fRec29[1]));
			fRec30[0] = (fSlow43 + (fSlow5 * fRec30[1]));
			double fTemp26 = (fRec16[1] * fRec30[0]);
			fRec31[0] = (fSlow47 + (fSlow5 * fRec31[1]));
			double fTemp27 = (fRec15[1] * fRec31[0]);
			fRec32[0] = (fSlow51 + (fSlow5 * fRec32[1]));
			double fTemp28 = (fRec14[1] * fRec32[0]);
			fRec33[0] = (fSlow55 + (fSlow5 * fRec33[1]));
			double fTemp29 = (fRec13[1] * fRec33[0]);
			fRec34[0] = (fSlow59 + (fSlow5 * fRec34[1]));
			double fTemp30 = (fRec12[1] * fRec34[0]);
			fRec35[0] = (fSlow63 + (fSlow5 * fRec35[1]));
			double fTemp31 = (fRec11[1] * fRec35[0]);
			fRec36[0] = (fSlow67 + (fSlow5 * fRec36[1]));
			double fTemp32 = (fRec10[1] * fRec36[0]);
			fRec37[0] = (fSlow71 + (fSlow5 * fRec37[1]));
			double fTemp33 = (fRec9[1] * fRec37[0]);
			fRec38[0] = (fSlow75 + (fSlow5 * fRec38[1]));
			double fTemp34 = (fRec8[1] * fRec38[0]);
			fRec39[0] = (fSlow79 + (fSlow5 * fRec39[1]));
			double fTemp35 = (fRec2[1] * fRec39[0]);
			fRec40[0] = (fSlow83 + (fSlow5 * fRec40[1]));
			double fTemp36 = (fRec7[1] * fRec40[0]);
			double fTemp37 = ((fSlow21 * fTemp20) + ((fSlow25 * fTemp21) + ((fSlow28 * fTemp22) + ((fSlow32 * fTemp23) + ((fSlow36 * fTemp24) + ((fTemp25 * fRec29[0]) + ((fSlow42 * fTemp26) + ((fSlow46 * fTemp27) + ((fSlow50 * fTemp28) + ((fSlow54 * fTemp29) + ((fSlow58 * fTemp30) + ((fSlow62 * fTemp31) + ((fSlow66 * fTemp32) + ((fSlow70 * fTemp33) + ((fSlow74 * fTemp34) + ((fSlow78 * fTemp35) + (fSlow82 * fTemp36)))))))))))))))));
			fVec3[IOTA&1048575] = fTemp37;
			double fTemp38 = (0.5 * fVec2[0]);
			int iTemp39 = ((fTemp38 > 0.001) * ((0.5 * fVec2[1]) <= 0.001));
			int iTemp40 = (1 - iTemp39);
			iRec41[0] = ((iRec41[1] * iTemp40) + (iSlow85 * iTemp39));
			double fTemp41 = (1 - fTemp38);
			fVec4[0] = fTemp41;
			int iTemp42 = ((fVec4[0] > 0.001) * (fVec4[1] <= 0.001));
			int iTemp43 = (1 - iTemp42);
			iRec42[0] = ((iRec42[1] * iTemp43) + (iSlow85 * iTemp42));
			double fTemp44 = ((0.5 * (fVec2[0] * fVec3[(IOTA-int((int(iRec41[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec3[(IOTA-int((int(iRec42[0]) & 1048575)))&1048575]));
			int iTemp45 = (fTemp44 > 1);
			int iTemp46 = (fTemp44 < -1);
			double fTemp47 = ((iTemp45 + ((fTemp44 * (1 - iTemp46)) * (1 - iTemp45))) - iTemp46);
			double fTemp48 = (fSlow18 * fTemp47);
			fVec5[IOTA&262143] = fTemp48;
			int iTemp49 = int(fTemp14);
			double fTemp50 = (fRec18[0] + (0.25 - floor((fRec18[0] + 0.25))));
			fVec6[0] = fTemp50;
			double fTemp51 = (0.5 * fVec6[0]);
			double fTemp52 = (65536.0 * (fTemp51 - floor(fTemp51)));
			int iTemp53 = int(fTemp52);
			double fTemp54 = ftbl0[iTemp53];
			int iTemp55 = (fVec6[0] > 0.001);
			int iTemp56 = (fVec6[1] <= 0.001);
			fRec43[0] = ((fRec43[1] * (1 - (iTemp55 * iTemp56))) + ((fRec20[0] * iTemp55) * iTemp56));
			double fTemp57 = (fConst5 * (fVec6[0] * fRec43[0]));
			double fTemp58 = floor(fTemp57);
			int iTemp59 = int(fTemp57);
			double fTemp60 = (fRec18[0] + (0.5 - floor((fRec18[0] + 0.5))));
			fVec7[0] = fTemp60;
			double fTemp61 = (0.5 * fVec7[0]);
			double fTemp62 = (65536.0 * (fTemp61 - floor(fTemp61)));
			int iTemp63 = int(fTemp62);
			double fTemp64 = ftbl0[iTemp63];
			int iTemp65 = (fVec7[0] > 0.001);
			int iTemp66 = (fVec7[1] <= 0.001);
			fRec44[0] = ((fRec44[1] * (1 - (iTemp65 * iTemp66))) + ((fRec20[0] * iTemp65) * iTemp66));
			double fTemp67 = (fConst5 * (fVec7[0] * fRec44[0]));
			double fTemp68 = floor(fTemp67);
			int iTemp69 = int(fTemp67);
			double fTemp70 = (fRec18[0] + (0.75 - floor((fRec18[0] + 0.75))));
			fVec8[0] = fTemp70;
			double fTemp71 = (0.5 * fVec8[0]);
			double fTemp72 = (65536.0 * (fTemp71 - floor(fTemp71)));
			int iTemp73 = int(fTemp72);
			double fTemp74 = ftbl0[iTemp73];
			int iTemp75 = (fVec8[0] > 0.001);
			int iTemp76 = (fVec8[1] <= 0.001);
			fRec45[0] = ((fRec45[1] * (1 - (iTemp75 * iTemp76))) + ((fRec20[0] * iTemp75) * iTemp76));
			double fTemp77 = (fConst5 * (fVec8[0] * fRec45[0]));
			double fTemp78 = floor(fTemp77);
			int iTemp79 = int(fTemp77);
			fRec1[0] = ((((((fTemp11 + ((fTemp9 - floor(fTemp9)) * (ftbl0[((iTemp10 + 1) % 65536)] - fTemp11))) * (((fTemp15 + (1 - fTemp14)) * fVec5[(IOTA-int((iTemp49 & 262143)))&262143]) + ((fTemp14 - fTemp15) * fVec5[(IOTA-int((int((iTemp49 + 1)) & 262143)))&262143]))) + ((fTemp54 + ((fTemp52 - floor(fTemp52)) * (ftbl0[((iTemp53 + 1) % 65536)] - fTemp54))) * (((fTemp58 + (1 - fTemp57)) * fVec5[(IOTA-int((iTemp59 & 262143)))&262143]) + ((fTemp57 - fTemp58) * fVec5[(IOTA-int((int((iTemp59 + 1)) & 262143)))&262143])))) + ((fTemp64 + ((fTemp62 - floor(fTemp62)) * (ftbl0[((iTemp63 + 1) % 65536)] - fTemp64))) * (((fTemp68 + (1 - fTemp67)) * fVec5[(IOTA-int((iTemp69 & 262143)))&262143]) + ((fTemp67 - fTemp68) * fVec5[(IOTA-int((int((iTemp69 + 1)) & 262143)))&262143])))) + ((fTemp74 + ((fTemp72 - floor(fTemp72)) * (ftbl0[((iTemp73 + 1) % 65536)] - fTemp74))) * (((fTemp78 + (1 - fTemp77)) * fVec5[(IOTA-int((iTemp79 & 262143)))&262143]) + ((fTemp77 - fTemp78) * fVec5[(IOTA-int((int((iTemp79 + 1)) & 262143)))&262143])))) + (fSlow86 * fTemp47));
			double fTemp80 = (fRec46[1] + (fSlow87 / fTemp5));
			fRec46[0] = (fTemp80 - floor(fTemp80));
			double fTemp81 = (fRec46[0] - floor(fRec46[0]));
			fVec9[0] = fTemp81;
			double fTemp82 = (0.5 * fVec9[0]);
			double fTemp83 = (65536.0 * (fTemp82 - floor(fTemp82)));
			int iTemp84 = int(fTemp83);
			double fTemp85 = ftbl0[iTemp84];
			int iTemp86 = (fVec9[0] > 0.001);
			int iTemp87 = (fVec9[1] <= 0.001);
			fRec47[0] = ((fRec47[1] * (1 - (iTemp86 * iTemp87))) + ((fRec20[0] * iTemp86) * iTemp87));
			double fTemp88 = (fConst5 * (fVec9[0] * fRec47[0]));
			double fTemp89 = floor(fTemp88);
			fRec48[0] = (fSlow93 + (fSlow5 * fRec48[1]));
			double fTemp90 = ((fSlow88 * fTemp21) + ((fSlow89 * fTemp20) + ((fSlow90 * fTemp23) + ((fSlow91 * fTemp24) + ((fSlow92 * fTemp22) + ((fTemp25 * fRec48[0]) + ((fSlow94 * fTemp26) + ((fSlow95 * fTemp27) + ((fSlow96 * fTemp28) + ((fSlow97 * fTemp29) + ((fSlow98 * fTemp30) + ((fSlow99 * fTemp31) + ((fSlow100 * fTemp32) + ((fSlow101 * fTemp33) + ((fSlow102 * fTemp34) + ((fSlow103 * fTemp35) + (fSlow104 * fTemp36)))))))))))))))));
			fVec10[IOTA&1048575] = fTemp90;
			iRec49[0] = ((iSlow105 * iTemp39) + (iTemp40 * iRec49[1]));
			iRec50[0] = ((iSlow105 * iTemp42) + (iTemp43 * iRec50[1]));
			double fTemp91 = ((0.5 * (fVec2[0] * fVec10[(IOTA-int((int(iRec49[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec10[(IOTA-int((int(iRec50[0]) & 1048575)))&1048575]));
			int iTemp92 = (fTemp91 > 1);
			int iTemp93 = (fTemp91 < -1);
			double fTemp94 = ((iTemp92 + ((fTemp91 * (1 - iTemp93)) * (1 - iTemp92))) - iTemp93);
			double fTemp95 = (fSlow76 * fTemp94);
			fVec11[IOTA&262143] = fTemp95;
			int iTemp96 = int(fTemp88);
			double fTemp97 = (fRec46[0] + (0.25 - floor((fRec46[0] + 0.25))));
			fVec12[0] = fTemp97;
			double fTemp98 = (0.5 * fVec12[0]);
			double fTemp99 = (65536.0 * (fTemp98 - floor(fTemp98)));
			int iTemp100 = int(fTemp99);
			double fTemp101 = ftbl0[iTemp100];
			int iTemp102 = (fVec12[0] > 0.001);
			int iTemp103 = (fVec12[1] <= 0.001);
			fRec51[0] = ((fRec51[1] * (1 - (iTemp102 * iTemp103))) + ((fRec20[0] * iTemp102) * iTemp103));
			double fTemp104 = (fConst5 * (fVec12[0] * fRec51[0]));
			double fTemp105 = floor(fTemp104);
			int iTemp106 = int(fTemp104);
			double fTemp107 = (fRec46[0] + (0.5 - floor((fRec46[0] + 0.5))));
			fVec13[0] = fTemp107;
			double fTemp108 = (0.5 * fVec13[0]);
			double fTemp109 = (65536.0 * (fTemp108 - floor(fTemp108)));
			int iTemp110 = int(fTemp109);
			double fTemp111 = ftbl0[iTemp110];
			int iTemp112 = (fVec13[0] > 0.001);
			int iTemp113 = (fVec13[1] <= 0.001);
			fRec52[0] = ((fRec52[1] * (1 - (iTemp112 * iTemp113))) + ((fRec20[0] * iTemp112) * iTemp113));
			double fTemp114 = (fConst5 * (fVec13[0] * fRec52[0]));
			double fTemp115 = floor(fTemp114);
			int iTemp116 = int(fTemp114);
			double fTemp117 = (fRec46[0] + (0.75 - floor((fRec46[0] + 0.75))));
			fVec14[0] = fTemp117;
			double fTemp118 = (0.5 * fVec14[0]);
			double fTemp119 = (65536.0 * (fTemp118 - floor(fTemp118)));
			int iTemp120 = int(fTemp119);
			double fTemp121 = ftbl0[iTemp120];
			int iTemp122 = (fVec14[0] > 0.001);
			int iTemp123 = (fVec14[1] <= 0.001);
			fRec53[0] = ((fRec53[1] * (1 - (iTemp122 * iTemp123))) + ((fRec20[0] * iTemp122) * iTemp123));
			double fTemp124 = (fConst5 * (fVec14[0] * fRec53[0]));
			double fTemp125 = floor(fTemp124);
			int iTemp126 = int(fTemp124);
			fRec2[0] = ((((((fTemp85 + ((fTemp83 - floor(fTemp83)) * (ftbl0[((iTemp84 + 1) % 65536)] - fTemp85))) * (((fTemp89 + (1 - fTemp88)) * fVec11[(IOTA-int((iTemp96 & 262143)))&262143]) + ((fTemp88 - fTemp89) * fVec11[(IOTA-int((int((iTemp96 + 1)) & 262143)))&262143]))) + ((fTemp101 + ((fTemp99 - floor(fTemp99)) * (ftbl0[((iTemp100 + 1) % 65536)] - fTemp101))) * (((fTemp105 + (1 - fTemp104)) * fVec11[(IOTA-int((iTemp106 & 262143)))&262143]) + ((fTemp104 - fTemp105) * fVec11[(IOTA-int((int((iTemp106 + 1)) & 262143)))&262143])))) + ((fTemp111 + ((fTemp109 - floor(fTemp109)) * (ftbl0[((iTemp110 + 1) % 65536)] - fTemp111))) * (((fTemp115 + (1 - fTemp114)) * fVec11[(IOTA-int((iTemp116 & 262143)))&262143]) + ((fTemp114 - fTemp115) * fVec11[(IOTA-int((int((iTemp116 + 1)) & 262143)))&262143])))) + ((fTemp121 + ((fTemp119 - floor(fTemp119)) * (ftbl0[((iTemp120 + 1) % 65536)] - fTemp121))) * (((fTemp125 + (1 - fTemp124)) * fVec11[(IOTA-int((iTemp126 & 262143)))&262143]) + ((fTemp124 - fTemp125) * fVec11[(IOTA-int((int((iTemp126 + 1)) & 262143)))&262143])))) + (fSlow106 * fTemp94));
			double fTemp127 = (fRec54[1] + (fSlow107 / fTemp5));
			fRec54[0] = (fTemp127 - floor(fTemp127));
			double fTemp128 = (fRec54[0] - floor(fRec54[0]));
			fVec15[0] = fTemp128;
			double fTemp129 = (0.5 * fVec15[0]);
			double fTemp130 = (65536.0 * (fTemp129 - floor(fTemp129)));
			int iTemp131 = int(fTemp130);
			double fTemp132 = ftbl0[iTemp131];
			int iTemp133 = (fVec15[0] > 0.001);
			int iTemp134 = (fVec15[1] <= 0.001);
			fRec55[0] = ((fRec55[1] * (1 - (iTemp133 * iTemp134))) + ((fRec20[0] * iTemp133) * iTemp134));
			double fTemp135 = (fConst5 * (fVec15[0] * fRec55[0]));
			double fTemp136 = floor(fTemp135);
			fRec56[0] = (fSlow113 + (fSlow5 * fRec56[1]));
			double fTemp137 = ((fSlow108 * fTemp23) + ((fSlow109 * fTemp21) + ((fSlow110 * fTemp20) + ((fSlow111 * fTemp24) + ((fSlow112 * fTemp22) + ((fTemp25 * fRec56[0]) + ((fSlow114 * fTemp26) + ((fSlow115 * fTemp27) + ((fSlow116 * fTemp28) + ((fSlow117 * fTemp29) + ((fSlow118 * fTemp30) + ((fSlow119 * fTemp31) + ((fSlow120 * fTemp32) + ((fSlow121 * fTemp33) + ((fSlow122 * fTemp34) + ((fSlow123 * fTemp35) + (fSlow124 * fTemp36)))))))))))))))));
			fVec16[IOTA&1048575] = fTemp137;
			iRec57[0] = ((iSlow125 * iTemp39) + (iTemp40 * iRec57[1]));
			iRec58[0] = ((iSlow125 * iTemp42) + (iTemp43 * iRec58[1]));
			double fTemp138 = ((0.5 * (fVec2[0] * fVec16[(IOTA-int((int(iRec57[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec16[(IOTA-int((int(iRec58[0]) & 1048575)))&1048575]));
			int iTemp139 = (fTemp138 > 1);
			int iTemp140 = (fTemp138 < -1);
			double fTemp141 = ((iTemp139 + ((fTemp138 * (1 - iTemp140)) * (1 - iTemp139))) - iTemp140);
			double fTemp142 = (fSlow34 * fTemp141);
			fVec17[IOTA&262143] = fTemp142;
			int iTemp143 = int(fTemp135);
			double fTemp144 = (fRec54[0] + (0.25 - floor((fRec54[0] + 0.25))));
			fVec18[0] = fTemp144;
			double fTemp145 = (0.5 * fVec18[0]);
			double fTemp146 = (65536.0 * (fTemp145 - floor(fTemp145)));
			int iTemp147 = int(fTemp146);
			double fTemp148 = ftbl0[iTemp147];
			int iTemp149 = (fVec18[0] > 0.001);
			int iTemp150 = (fVec18[1] <= 0.001);
			fRec59[0] = ((fRec59[1] * (1 - (iTemp149 * iTemp150))) + ((fRec20[0] * iTemp149) * iTemp150));
			double fTemp151 = (fConst5 * (fVec18[0] * fRec59[0]));
			double fTemp152 = floor(fTemp151);
			int iTemp153 = int(fTemp151);
			double fTemp154 = (fRec54[0] + (0.5 - floor((fRec54[0] + 0.5))));
			fVec19[0] = fTemp154;
			double fTemp155 = (0.5 * fVec19[0]);
			double fTemp156 = (65536.0 * (fTemp155 - floor(fTemp155)));
			int iTemp157 = int(fTemp156);
			double fTemp158 = ftbl0[iTemp157];
			int iTemp159 = (fVec19[0] > 0.001);
			int iTemp160 = (fVec19[1] <= 0.001);
			fRec60[0] = ((fRec60[1] * (1 - (iTemp159 * iTemp160))) + ((fRec20[0] * iTemp159) * iTemp160));
			double fTemp161 = (fConst5 * (fVec19[0] * fRec60[0]));
			double fTemp162 = floor(fTemp161);
			int iTemp163 = int(fTemp161);
			double fTemp164 = (fRec54[0] + (0.75 - floor((fRec54[0] + 0.75))));
			fVec20[0] = fTemp164;
			double fTemp165 = (0.5 * fVec20[0]);
			double fTemp166 = (65536.0 * (fTemp165 - floor(fTemp165)));
			int iTemp167 = int(fTemp166);
			double fTemp168 = ftbl0[iTemp167];
			int iTemp169 = (fVec20[0] > 0.001);
			int iTemp170 = (fVec20[1] <= 0.001);
			fRec61[0] = ((fRec61[1] * (1 - (iTemp169 * iTemp170))) + ((fRec20[0] * iTemp169) * iTemp170));
			double fTemp171 = (fConst5 * (fVec20[0] * fRec61[0]));
			double fTemp172 = floor(fTemp171);
			int iTemp173 = int(fTemp171);
			fRec3[0] = ((((((fTemp132 + ((fTemp130 - floor(fTemp130)) * (ftbl0[((iTemp131 + 1) % 65536)] - fTemp132))) * (((fTemp136 + (1 - fTemp135)) * fVec17[(IOTA-int((iTemp143 & 262143)))&262143]) + ((fTemp135 - fTemp136) * fVec17[(IOTA-int((int((iTemp143 + 1)) & 262143)))&262143]))) + ((fTemp148 + ((fTemp146 - floor(fTemp146)) * (ftbl0[((iTemp147 + 1) % 65536)] - fTemp148))) * (((fTemp152 + (1 - fTemp151)) * fVec17[(IOTA-int((iTemp153 & 262143)))&262143]) + ((fTemp151 - fTemp152) * fVec17[(IOTA-int((int((iTemp153 + 1)) & 262143)))&262143])))) + ((fTemp158 + ((fTemp156 - floor(fTemp156)) * (ftbl0[((iTemp157 + 1) % 65536)] - fTemp158))) * (((fTemp162 + (1 - fTemp161)) * fVec17[(IOTA-int((iTemp163 & 262143)))&262143]) + ((fTemp161 - fTemp162) * fVec17[(IOTA-int((int((iTemp163 + 1)) & 262143)))&262143])))) + ((fTemp168 + ((fTemp166 - floor(fTemp166)) * (ftbl0[((iTemp167 + 1) % 65536)] - fTemp168))) * (((fTemp172 + (1 - fTemp171)) * fVec17[(IOTA-int((iTemp173 & 262143)))&262143]) + ((fTemp171 - fTemp172) * fVec17[(IOTA-int((int((iTemp173 + 1)) & 262143)))&262143])))) + (fSlow126 * fTemp141));
			double fTemp174 = (fRec62[1] + (fSlow127 / fTemp5));
			fRec62[0] = (fTemp174 - floor(fTemp174));
			double fTemp175 = (fRec62[0] - floor(fRec62[0]));
			fVec21[0] = fTemp175;
			double fTemp176 = (0.5 * fVec21[0]);
			double fTemp177 = (65536.0 * (fTemp176 - floor(fTemp176)));
			int iTemp178 = int(fTemp177);
			double fTemp179 = ftbl0[iTemp178];
			int iTemp180 = (fVec21[0] > 0.001);
			int iTemp181 = (fVec21[1] <= 0.001);
			fRec63[0] = ((fRec63[1] * (1 - (iTemp180 * iTemp181))) + ((fRec20[0] * iTemp180) * iTemp181));
			double fTemp182 = (fConst5 * (fVec21[0] * fRec63[0]));
			double fTemp183 = floor(fTemp182);
			fRec64[0] = (fSlow133 + (fSlow5 * fRec64[1]));
			double fTemp184 = ((fSlow128 * fTemp23) + ((fSlow129 * fTemp21) + ((fSlow130 * fTemp20) + ((fSlow131 * fTemp24) + ((fSlow132 * fTemp22) + ((fTemp25 * fRec64[0]) + ((fSlow134 * fTemp26) + ((fSlow135 * fTemp27) + ((fSlow136 * fTemp28) + ((fSlow137 * fTemp29) + ((fSlow138 * fTemp30) + ((fSlow139 * fTemp31) + ((fSlow140 * fTemp32) + ((fSlow141 * fTemp33) + ((fSlow142 * fTemp34) + ((fSlow143 * fTemp35) + (fSlow144 * fTemp36)))))))))))))))));
			fVec22[IOTA&1048575] = fTemp184;
			iRec65[0] = ((iSlow145 * iTemp39) + (iTemp40 * iRec65[1]));
			iRec66[0] = ((iSlow145 * iTemp42) + (iTemp43 * iRec66[1]));
			double fTemp185 = ((0.5 * (fVec2[0] * fVec22[(IOTA-int((int(iRec65[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec22[(IOTA-int((int(iRec66[0]) & 1048575)))&1048575]));
			int iTemp186 = (fTemp185 > 1);
			int iTemp187 = (fTemp185 < -1);
			double fTemp188 = ((iTemp186 + ((fTemp185 * (1 - iTemp187)) * (1 - iTemp186))) - iTemp187);
			double fTemp189 = (fSlow30 * fTemp188);
			fVec23[IOTA&262143] = fTemp189;
			int iTemp190 = int(fTemp182);
			double fTemp191 = (fRec62[0] + (0.25 - floor((fRec62[0] + 0.25))));
			fVec24[0] = fTemp191;
			double fTemp192 = (0.5 * fVec24[0]);
			double fTemp193 = (65536.0 * (fTemp192 - floor(fTemp192)));
			int iTemp194 = int(fTemp193);
			double fTemp195 = ftbl0[iTemp194];
			int iTemp196 = (fVec24[0] > 0.001);
			int iTemp197 = (fVec24[1] <= 0.001);
			fRec67[0] = ((fRec67[1] * (1 - (iTemp196 * iTemp197))) + ((fRec20[0] * iTemp196) * iTemp197));
			double fTemp198 = (fConst5 * (fVec24[0] * fRec67[0]));
			double fTemp199 = floor(fTemp198);
			int iTemp200 = int(fTemp198);
			double fTemp201 = (fRec62[0] + (0.5 - floor((fRec62[0] + 0.5))));
			fVec25[0] = fTemp201;
			double fTemp202 = (0.5 * fVec25[0]);
			double fTemp203 = (65536.0 * (fTemp202 - floor(fTemp202)));
			int iTemp204 = int(fTemp203);
			double fTemp205 = ftbl0[iTemp204];
			int iTemp206 = (fVec25[0] > 0.001);
			int iTemp207 = (fVec25[1] <= 0.001);
			fRec68[0] = ((fRec68[1] * (1 - (iTemp206 * iTemp207))) + ((fRec20[0] * iTemp206) * iTemp207));
			double fTemp208 = (fConst5 * (fVec25[0] * fRec68[0]));
			double fTemp209 = floor(fTemp208);
			int iTemp210 = int(fTemp208);
			double fTemp211 = (fRec62[0] + (0.75 - floor((fRec62[0] + 0.75))));
			fVec26[0] = fTemp211;
			double fTemp212 = (0.5 * fVec26[0]);
			double fTemp213 = (65536.0 * (fTemp212 - floor(fTemp212)));
			int iTemp214 = int(fTemp213);
			double fTemp215 = ftbl0[iTemp214];
			int iTemp216 = (fVec26[0] > 0.001);
			int iTemp217 = (fVec26[1] <= 0.001);
			fRec69[0] = ((fRec69[1] * (1 - (iTemp216 * iTemp217))) + ((fRec20[0] * iTemp216) * iTemp217));
			double fTemp218 = (fConst5 * (fVec26[0] * fRec69[0]));
			double fTemp219 = floor(fTemp218);
			int iTemp220 = int(fTemp218);
			fRec4[0] = ((((((fTemp179 + ((fTemp177 - floor(fTemp177)) * (ftbl0[((iTemp178 + 1) % 65536)] - fTemp179))) * (((fTemp183 + (1 - fTemp182)) * fVec23[(IOTA-int((iTemp190 & 262143)))&262143]) + ((fTemp182 - fTemp183) * fVec23[(IOTA-int((int((iTemp190 + 1)) & 262143)))&262143]))) + ((fTemp195 + ((fTemp193 - floor(fTemp193)) * (ftbl0[((iTemp194 + 1) % 65536)] - fTemp195))) * (((fTemp199 + (1 - fTemp198)) * fVec23[(IOTA-int((iTemp200 & 262143)))&262143]) + ((fTemp198 - fTemp199) * fVec23[(IOTA-int((int((iTemp200 + 1)) & 262143)))&262143])))) + ((fTemp205 + ((fTemp203 - floor(fTemp203)) * (ftbl0[((iTemp204 + 1) % 65536)] - fTemp205))) * (((fTemp209 + (1 - fTemp208)) * fVec23[(IOTA-int((iTemp210 & 262143)))&262143]) + ((fTemp208 - fTemp209) * fVec23[(IOTA-int((int((iTemp210 + 1)) & 262143)))&262143])))) + ((fTemp215 + ((fTemp213 - floor(fTemp213)) * (ftbl0[((iTemp214 + 1) % 65536)] - fTemp215))) * (((fTemp219 + (1 - fTemp218)) * fVec23[(IOTA-int((iTemp220 & 262143)))&262143]) + ((fTemp218 - fTemp219) * fVec23[(IOTA-int((int((iTemp220 + 1)) & 262143)))&262143])))) + (fSlow146 * fTemp188));
			double fTemp221 = (fRec70[1] + (fSlow147 / fTemp5));
			fRec70[0] = (fTemp221 - floor(fTemp221));
			double fTemp222 = (fRec70[0] - floor(fRec70[0]));
			fVec27[0] = fTemp222;
			double fTemp223 = (0.5 * fVec27[0]);
			double fTemp224 = (65536.0 * (fTemp223 - floor(fTemp223)));
			int iTemp225 = int(fTemp224);
			double fTemp226 = ftbl0[iTemp225];
			int iTemp227 = (fVec27[0] > 0.001);
			int iTemp228 = (fVec27[1] <= 0.001);
			fRec71[0] = ((fRec71[1] * (1 - (iTemp227 * iTemp228))) + ((fRec20[0] * iTemp227) * iTemp228));
			double fTemp229 = (fConst5 * (fVec27[0] * fRec71[0]));
			double fTemp230 = floor(fTemp229);
			fRec72[0] = (fSlow153 + (fSlow5 * fRec72[1]));
			double fTemp231 = ((fSlow148 * fTemp23) + ((fSlow149 * fTemp21) + ((fSlow150 * fTemp20) + ((fSlow151 * fTemp24) + ((fSlow152 * fTemp22) + ((fTemp25 * fRec72[0]) + ((fSlow154 * fTemp26) + ((fSlow155 * fTemp27) + ((fSlow156 * fTemp28) + ((fSlow157 * fTemp29) + ((fSlow158 * fTemp30) + ((fSlow159 * fTemp31) + ((fSlow160 * fTemp32) + ((fSlow161 * fTemp33) + ((fSlow162 * fTemp34) + ((fSlow163 * fTemp35) + (fSlow164 * fTemp36)))))))))))))))));
			fVec28[IOTA&1048575] = fTemp231;
			iRec73[0] = ((iSlow165 * iTemp39) + (iTemp40 * iRec73[1]));
			iRec74[0] = ((iSlow165 * iTemp42) + (iTemp43 * iRec74[1]));
			double fTemp232 = ((0.5 * (fVec2[0] * fVec28[(IOTA-int((int(iRec73[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec28[(IOTA-int((int(iRec74[0]) & 1048575)))&1048575]));
			int iTemp233 = (fTemp232 > 1);
			int iTemp234 = (fTemp232 < -1);
			double fTemp235 = ((iTemp233 + ((fTemp232 * (1 - iTemp234)) * (1 - iTemp233))) - iTemp234);
			double fTemp236 = (fSlow19 * fTemp235);
			fVec29[IOTA&262143] = fTemp236;
			int iTemp237 = int(fTemp229);
			double fTemp238 = (fRec70[0] + (0.25 - floor((fRec70[0] + 0.25))));
			fVec30[0] = fTemp238;
			double fTemp239 = (0.5 * fVec30[0]);
			double fTemp240 = (65536.0 * (fTemp239 - floor(fTemp239)));
			int iTemp241 = int(fTemp240);
			double fTemp242 = ftbl0[iTemp241];
			int iTemp243 = (fVec30[0] > 0.001);
			int iTemp244 = (fVec30[1] <= 0.001);
			fRec75[0] = ((fRec75[1] * (1 - (iTemp243 * iTemp244))) + ((fRec20[0] * iTemp243) * iTemp244));
			double fTemp245 = (fConst5 * (fVec30[0] * fRec75[0]));
			double fTemp246 = floor(fTemp245);
			int iTemp247 = int(fTemp245);
			double fTemp248 = (fRec70[0] + (0.5 - floor((fRec70[0] + 0.5))));
			fVec31[0] = fTemp248;
			double fTemp249 = (0.5 * fVec31[0]);
			double fTemp250 = (65536.0 * (fTemp249 - floor(fTemp249)));
			int iTemp251 = int(fTemp250);
			double fTemp252 = ftbl0[iTemp251];
			int iTemp253 = (fVec31[0] > 0.001);
			int iTemp254 = (fVec31[1] <= 0.001);
			fRec76[0] = ((fRec76[1] * (1 - (iTemp253 * iTemp254))) + ((fRec20[0] * iTemp253) * iTemp254));
			double fTemp255 = (fConst5 * (fVec31[0] * fRec76[0]));
			double fTemp256 = floor(fTemp255);
			int iTemp257 = int(fTemp255);
			double fTemp258 = (fRec70[0] + (0.75 - floor((fRec70[0] + 0.75))));
			fVec32[0] = fTemp258;
			double fTemp259 = (0.5 * fVec32[0]);
			double fTemp260 = (65536.0 * (fTemp259 - floor(fTemp259)));
			int iTemp261 = int(fTemp260);
			double fTemp262 = ftbl0[iTemp261];
			int iTemp263 = (fVec32[0] > 0.001);
			int iTemp264 = (fVec32[1] <= 0.001);
			fRec77[0] = ((fRec77[1] * (1 - (iTemp263 * iTemp264))) + ((fRec20[0] * iTemp263) * iTemp264));
			double fTemp265 = (fConst5 * (fVec32[0] * fRec77[0]));
			double fTemp266 = floor(fTemp265);
			int iTemp267 = int(fTemp265);
			fRec5[0] = ((((((fTemp226 + ((fTemp224 - floor(fTemp224)) * (ftbl0[((iTemp225 + 1) % 65536)] - fTemp226))) * (((fTemp230 + (1 - fTemp229)) * fVec29[(IOTA-int((iTemp237 & 262143)))&262143]) + ((fTemp229 - fTemp230) * fVec29[(IOTA-int((int((iTemp237 + 1)) & 262143)))&262143]))) + ((fTemp242 + ((fTemp240 - floor(fTemp240)) * (ftbl0[((iTemp241 + 1) % 65536)] - fTemp242))) * (((fTemp246 + (1 - fTemp245)) * fVec29[(IOTA-int((iTemp247 & 262143)))&262143]) + ((fTemp245 - fTemp246) * fVec29[(IOTA-int((int((iTemp247 + 1)) & 262143)))&262143])))) + ((fTemp252 + ((fTemp250 - floor(fTemp250)) * (ftbl0[((iTemp251 + 1) % 65536)] - fTemp252))) * (((fTemp256 + (1 - fTemp255)) * fVec29[(IOTA-int((iTemp257 & 262143)))&262143]) + ((fTemp255 - fTemp256) * fVec29[(IOTA-int((int((iTemp257 + 1)) & 262143)))&262143])))) + ((fTemp262 + ((fTemp260 - floor(fTemp260)) * (ftbl0[((iTemp261 + 1) % 65536)] - fTemp262))) * (((fTemp266 + (1 - fTemp265)) * fVec29[(IOTA-int((iTemp267 & 262143)))&262143]) + ((fTemp265 - fTemp266) * fVec29[(IOTA-int((int((iTemp267 + 1)) & 262143)))&262143])))) + (fSlow166 * fTemp235));
			double fTemp268 = (fRec78[1] + (fSlow167 / fTemp5));
			fRec78[0] = (fTemp268 - floor(fTemp268));
			double fTemp269 = (fRec78[0] - floor(fRec78[0]));
			fVec33[0] = fTemp269;
			double fTemp270 = (0.5 * fVec33[0]);
			double fTemp271 = (65536.0 * (fTemp270 - floor(fTemp270)));
			int iTemp272 = int(fTemp271);
			double fTemp273 = ftbl0[iTemp272];
			int iTemp274 = (fVec33[0] > 0.001);
			int iTemp275 = (fVec33[1] <= 0.001);
			fRec79[0] = ((fRec79[1] * (1 - (iTemp274 * iTemp275))) + ((fRec20[0] * iTemp274) * iTemp275));
			double fTemp276 = (fConst5 * (fVec33[0] * fRec79[0]));
			double fTemp277 = floor(fTemp276);
			fRec80[0] = (fSlow173 + (fSlow5 * fRec80[1]));
			double fTemp278 = ((fSlow168 * fTemp23) + ((fSlow169 * fTemp21) + ((fSlow170 * fTemp20) + ((fSlow171 * fTemp24) + ((fSlow172 * fTemp22) + ((fTemp25 * fRec80[0]) + ((fSlow174 * fTemp26) + ((fSlow175 * fTemp27) + ((fSlow176 * fTemp28) + ((fSlow177 * fTemp29) + ((fSlow178 * fTemp30) + ((fSlow179 * fTemp31) + ((fSlow180 * fTemp32) + ((fSlow181 * fTemp33) + ((fSlow182 * fTemp34) + ((fSlow183 * fTemp35) + (fSlow184 * fTemp36)))))))))))))))));
			fVec34[IOTA&1048575] = fTemp278;
			iRec81[0] = ((iSlow185 * iTemp39) + (iTemp40 * iRec81[1]));
			iRec82[0] = ((iSlow185 * iTemp42) + (iTemp43 * iRec82[1]));
			double fTemp279 = ((0.5 * (fVec2[0] * fVec34[(IOTA-int((int(iRec81[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec34[(IOTA-int((int(iRec82[0]) & 1048575)))&1048575]));
			int iTemp280 = (fTemp279 > 1);
			int iTemp281 = (fTemp279 < -1);
			double fTemp282 = ((iTemp280 + ((fTemp279 * (1 - iTemp281)) * (1 - iTemp280))) - iTemp281);
			double fTemp283 = (fSlow23 * fTemp282);
			fVec35[IOTA&262143] = fTemp283;
			int iTemp284 = int(fTemp276);
			double fTemp285 = (fRec78[0] + (0.25 - floor((fRec78[0] + 0.25))));
			fVec36[0] = fTemp285;
			double fTemp286 = (0.5 * fVec36[0]);
			double fTemp287 = (65536.0 * (fTemp286 - floor(fTemp286)));
			int iTemp288 = int(fTemp287);
			double fTemp289 = ftbl0[iTemp288];
			int iTemp290 = (fVec36[0] > 0.001);
			int iTemp291 = (fVec36[1] <= 0.001);
			fRec83[0] = ((fRec83[1] * (1 - (iTemp290 * iTemp291))) + ((fRec20[0] * iTemp290) * iTemp291));
			double fTemp292 = (fConst5 * (fVec36[0] * fRec83[0]));
			double fTemp293 = floor(fTemp292);
			int iTemp294 = int(fTemp292);
			double fTemp295 = (fRec78[0] + (0.5 - floor((fRec78[0] + 0.5))));
			fVec37[0] = fTemp295;
			double fTemp296 = (0.5 * fVec37[0]);
			double fTemp297 = (65536.0 * (fTemp296 - floor(fTemp296)));
			int iTemp298 = int(fTemp297);
			double fTemp299 = ftbl0[iTemp298];
			int iTemp300 = (fVec37[0] > 0.001);
			int iTemp301 = (fVec37[1] <= 0.001);
			fRec84[0] = ((fRec84[1] * (1 - (iTemp300 * iTemp301))) + ((fRec20[0] * iTemp300) * iTemp301));
			double fTemp302 = (fConst5 * (fVec37[0] * fRec84[0]));
			double fTemp303 = floor(fTemp302);
			int iTemp304 = int(fTemp302);
			double fTemp305 = (fRec78[0] + (0.75 - floor((fRec78[0] + 0.75))));
			fVec38[0] = fTemp305;
			double fTemp306 = (0.5 * fVec38[0]);
			double fTemp307 = (65536.0 * (fTemp306 - floor(fTemp306)));
			int iTemp308 = int(fTemp307);
			double fTemp309 = ftbl0[iTemp308];
			int iTemp310 = (fVec38[0] > 0.001);
			int iTemp311 = (fVec38[1] <= 0.001);
			fRec85[0] = ((fRec85[1] * (1 - (iTemp310 * iTemp311))) + ((fRec20[0] * iTemp310) * iTemp311));
			double fTemp312 = (fConst5 * (fVec38[0] * fRec85[0]));
			double fTemp313 = floor(fTemp312);
			int iTemp314 = int(fTemp312);
			fRec6[0] = ((((((fTemp273 + ((fTemp271 - floor(fTemp271)) * (ftbl0[((iTemp272 + 1) % 65536)] - fTemp273))) * (((fTemp277 + (1 - fTemp276)) * fVec35[(IOTA-int((iTemp284 & 262143)))&262143]) + ((fTemp276 - fTemp277) * fVec35[(IOTA-int((int((iTemp284 + 1)) & 262143)))&262143]))) + ((fTemp289 + ((fTemp287 - floor(fTemp287)) * (ftbl0[((iTemp288 + 1) % 65536)] - fTemp289))) * (((fTemp293 + (1 - fTemp292)) * fVec35[(IOTA-int((iTemp294 & 262143)))&262143]) + ((fTemp292 - fTemp293) * fVec35[(IOTA-int((int((iTemp294 + 1)) & 262143)))&262143])))) + ((fTemp299 + ((fTemp297 - floor(fTemp297)) * (ftbl0[((iTemp298 + 1) % 65536)] - fTemp299))) * (((fTemp303 + (1 - fTemp302)) * fVec35[(IOTA-int((iTemp304 & 262143)))&262143]) + ((fTemp302 - fTemp303) * fVec35[(IOTA-int((int((iTemp304 + 1)) & 262143)))&262143])))) + ((fTemp309 + ((fTemp307 - floor(fTemp307)) * (ftbl0[((iTemp308 + 1) % 65536)] - fTemp309))) * (((fTemp313 + (1 - fTemp312)) * fVec35[(IOTA-int((iTemp314 & 262143)))&262143]) + ((fTemp312 - fTemp313) * fVec35[(IOTA-int((int((iTemp314 + 1)) & 262143)))&262143])))) + (fSlow186 * fTemp282));
			double fTemp315 = (fRec86[1] + (fSlow187 / fTemp5));
			fRec86[0] = (fTemp315 - floor(fTemp315));
			double fTemp316 = (fRec86[0] - floor(fRec86[0]));
			fVec39[0] = fTemp316;
			double fTemp317 = (0.5 * fVec39[0]);
			double fTemp318 = (65536.0 * (fTemp317 - floor(fTemp317)));
			int iTemp319 = int(fTemp318);
			double fTemp320 = ftbl0[iTemp319];
			int iTemp321 = (fVec39[0] > 0.001);
			int iTemp322 = (fVec39[1] <= 0.001);
			fRec87[0] = ((fRec87[1] * (1 - (iTemp321 * iTemp322))) + ((fRec20[0] * iTemp321) * iTemp322));
			double fTemp323 = (fConst5 * (fVec39[0] * fRec87[0]));
			double fTemp324 = floor(fTemp323);
			fRec88[0] = (fSlow193 + (fSlow5 * fRec88[1]));
			double fTemp325 = ((fSlow188 * fTemp23) + ((fSlow189 * fTemp21) + ((fSlow190 * fTemp20) + ((fSlow191 * fTemp24) + ((fSlow192 * fTemp22) + ((fTemp25 * fRec88[0]) + ((fSlow194 * fTemp26) + ((fSlow195 * fTemp27) + ((fSlow196 * fTemp28) + ((fSlow197 * fTemp29) + ((fSlow198 * fTemp30) + ((fSlow199 * fTemp31) + ((fSlow200 * fTemp32) + ((fSlow201 * fTemp33) + ((fSlow202 * fTemp34) + ((fSlow203 * fTemp35) + (fSlow204 * fTemp36)))))))))))))))));
			fVec40[IOTA&1048575] = fTemp325;
			iRec89[0] = ((iSlow205 * iTemp39) + (iTemp40 * iRec89[1]));
			iRec90[0] = ((iSlow205 * iTemp42) + (iTemp43 * iRec90[1]));
			double fTemp326 = ((0.5 * (fVec2[0] * fVec40[(IOTA-int((int(iRec89[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec40[(IOTA-int((int(iRec90[0]) & 1048575)))&1048575]));
			int iTemp327 = (fTemp326 > 1);
			int iTemp328 = (fTemp326 < -1);
			double fTemp329 = ((iTemp327 + ((fTemp326 * (1 - iTemp328)) * (1 - iTemp327))) - iTemp328);
			double fTemp330 = (fSlow80 * fTemp329);
			fVec41[IOTA&262143] = fTemp330;
			int iTemp331 = int(fTemp323);
			double fTemp332 = (fRec86[0] + (0.25 - floor((fRec86[0] + 0.25))));
			fVec42[0] = fTemp332;
			double fTemp333 = (0.5 * fVec42[0]);
			double fTemp334 = (65536.0 * (fTemp333 - floor(fTemp333)));
			int iTemp335 = int(fTemp334);
			double fTemp336 = ftbl0[iTemp335];
			int iTemp337 = (fVec42[0] > 0.001);
			int iTemp338 = (fVec42[1] <= 0.001);
			fRec91[0] = ((fRec91[1] * (1 - (iTemp337 * iTemp338))) + ((fRec20[0] * iTemp337) * iTemp338));
			double fTemp339 = (fConst5 * (fVec42[0] * fRec91[0]));
			double fTemp340 = floor(fTemp339);
			int iTemp341 = int(fTemp339);
			double fTemp342 = (fRec86[0] + (0.5 - floor((fRec86[0] + 0.5))));
			fVec43[0] = fTemp342;
			double fTemp343 = (0.5 * fVec43[0]);
			double fTemp344 = (65536.0 * (fTemp343 - floor(fTemp343)));
			int iTemp345 = int(fTemp344);
			double fTemp346 = ftbl0[iTemp345];
			int iTemp347 = (fVec43[0] > 0.001);
			int iTemp348 = (fVec43[1] <= 0.001);
			fRec92[0] = ((fRec92[1] * (1 - (iTemp347 * iTemp348))) + ((fRec20[0] * iTemp347) * iTemp348));
			double fTemp349 = (fConst5 * (fVec43[0] * fRec92[0]));
			double fTemp350 = floor(fTemp349);
			int iTemp351 = int(fTemp349);
			double fTemp352 = (fRec86[0] + (0.75 - floor((fRec86[0] + 0.75))));
			fVec44[0] = fTemp352;
			double fTemp353 = (0.5 * fVec44[0]);
			double fTemp354 = (65536.0 * (fTemp353 - floor(fTemp353)));
			int iTemp355 = int(fTemp354);
			double fTemp356 = ftbl0[iTemp355];
			int iTemp357 = (fVec44[0] > 0.001);
			int iTemp358 = (fVec44[1] <= 0.001);
			fRec93[0] = ((fRec93[1] * (1 - (iTemp357 * iTemp358))) + ((fRec20[0] * iTemp357) * iTemp358));
			double fTemp359 = (fConst5 * (fVec44[0] * fRec93[0]));
			double fTemp360 = floor(fTemp359);
			int iTemp361 = int(fTemp359);
			fRec7[0] = ((((((fTemp320 + ((fTemp318 - floor(fTemp318)) * (ftbl0[((iTemp319 + 1) % 65536)] - fTemp320))) * (((fTemp324 + (1 - fTemp323)) * fVec41[(IOTA-int((iTemp331 & 262143)))&262143]) + ((fTemp323 - fTemp324) * fVec41[(IOTA-int((int((iTemp331 + 1)) & 262143)))&262143]))) + ((fTemp336 + ((fTemp334 - floor(fTemp334)) * (ftbl0[((iTemp335 + 1) % 65536)] - fTemp336))) * (((fTemp340 + (1 - fTemp339)) * fVec41[(IOTA-int((iTemp341 & 262143)))&262143]) + ((fTemp339 - fTemp340) * fVec41[(IOTA-int((int((iTemp341 + 1)) & 262143)))&262143])))) + ((fTemp346 + ((fTemp344 - floor(fTemp344)) * (ftbl0[((iTemp345 + 1) % 65536)] - fTemp346))) * (((fTemp350 + (1 - fTemp349)) * fVec41[(IOTA-int((iTemp351 & 262143)))&262143]) + ((fTemp349 - fTemp350) * fVec41[(IOTA-int((int((iTemp351 + 1)) & 262143)))&262143])))) + ((fTemp356 + ((fTemp354 - floor(fTemp354)) * (ftbl0[((iTemp355 + 1) % 65536)] - fTemp356))) * (((fTemp360 + (1 - fTemp359)) * fVec41[(IOTA-int((iTemp361 & 262143)))&262143]) + ((fTemp359 - fTemp360) * fVec41[(IOTA-int((int((iTemp361 + 1)) & 262143)))&262143])))) + (fSlow206 * fTemp329));
			double fTemp362 = (fRec94[1] + (fSlow207 / fTemp5));
			fRec94[0] = (fTemp362 - floor(fTemp362));
			double fTemp363 = (fRec94[0] - floor(fRec94[0]));
			fVec45[0] = fTemp363;
			double fTemp364 = (0.5 * fVec45[0]);
			double fTemp365 = (65536.0 * (fTemp364 - floor(fTemp364)));
			int iTemp366 = int(fTemp365);
			double fTemp367 = ftbl0[iTemp366];
			int iTemp368 = (fVec45[0] > 0.001);
			int iTemp369 = (fVec45[1] <= 0.001);
			fRec95[0] = ((fRec95[1] * (1 - (iTemp368 * iTemp369))) + ((fRec20[0] * iTemp368) * iTemp369));
			double fTemp370 = (fConst5 * (fVec45[0] * fRec95[0]));
			double fTemp371 = floor(fTemp370);
			fRec96[0] = (fSlow213 + (fSlow5 * fRec96[1]));
			double fTemp372 = ((fSlow208 * fTemp23) + ((fSlow209 * fTemp21) + ((fSlow210 * fTemp20) + ((fSlow211 * fTemp24) + ((fSlow212 * fTemp22) + ((fTemp25 * fRec96[0]) + ((fSlow214 * fTemp26) + ((fSlow215 * fTemp27) + ((fSlow216 * fTemp28) + ((fSlow217 * fTemp29) + ((fSlow218 * fTemp30) + ((fSlow219 * fTemp31) + ((fSlow220 * fTemp32) + ((fSlow221 * fTemp33) + ((fSlow222 * fTemp34) + ((fSlow223 * fTemp35) + (fSlow224 * fTemp36)))))))))))))))));
			fVec46[IOTA&1048575] = fTemp372;
			iRec97[0] = ((iSlow225 * iTemp39) + (iTemp40 * iRec97[1]));
			iRec98[0] = ((iSlow225 * iTemp42) + (iTemp43 * iRec98[1]));
			double fTemp373 = ((0.5 * (fVec2[0] * fVec46[(IOTA-int((int(iRec97[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec46[(IOTA-int((int(iRec98[0]) & 1048575)))&1048575]));
			int iTemp374 = (fTemp373 > 1);
			int iTemp375 = (fTemp373 < -1);
			double fTemp376 = ((iTemp374 + ((fTemp373 * (1 - iTemp375)) * (1 - iTemp374))) - iTemp375);
			double fTemp377 = (fSlow72 * fTemp376);
			fVec47[IOTA&262143] = fTemp377;
			int iTemp378 = int(fTemp370);
			double fTemp379 = (fRec94[0] + (0.25 - floor((fRec94[0] + 0.25))));
			fVec48[0] = fTemp379;
			double fTemp380 = (0.5 * fVec48[0]);
			double fTemp381 = (65536.0 * (fTemp380 - floor(fTemp380)));
			int iTemp382 = int(fTemp381);
			double fTemp383 = ftbl0[iTemp382];
			int iTemp384 = (fVec48[0] > 0.001);
			int iTemp385 = (fVec48[1] <= 0.001);
			fRec99[0] = ((fRec99[1] * (1 - (iTemp384 * iTemp385))) + ((fRec20[0] * iTemp384) * iTemp385));
			double fTemp386 = (fConst5 * (fVec48[0] * fRec99[0]));
			double fTemp387 = floor(fTemp386);
			int iTemp388 = int(fTemp386);
			double fTemp389 = (fRec94[0] + (0.5 - floor((fRec94[0] + 0.5))));
			fVec49[0] = fTemp389;
			double fTemp390 = (0.5 * fVec49[0]);
			double fTemp391 = (65536.0 * (fTemp390 - floor(fTemp390)));
			int iTemp392 = int(fTemp391);
			double fTemp393 = ftbl0[iTemp392];
			int iTemp394 = (fVec49[0] > 0.001);
			int iTemp395 = (fVec49[1] <= 0.001);
			fRec100[0] = ((fRec100[1] * (1 - (iTemp394 * iTemp395))) + ((fRec20[0] * iTemp394) * iTemp395));
			double fTemp396 = (fConst5 * (fVec49[0] * fRec100[0]));
			double fTemp397 = floor(fTemp396);
			int iTemp398 = int(fTemp396);
			double fTemp399 = (fRec94[0] + (0.75 - floor((fRec94[0] + 0.75))));
			fVec50[0] = fTemp399;
			double fTemp400 = (0.5 * fVec50[0]);
			double fTemp401 = (65536.0 * (fTemp400 - floor(fTemp400)));
			int iTemp402 = int(fTemp401);
			double fTemp403 = ftbl0[iTemp402];
			int iTemp404 = (fVec50[0] > 0.001);
			int iTemp405 = (fVec50[1] <= 0.001);
			fRec101[0] = ((fRec101[1] * (1 - (iTemp404 * iTemp405))) + ((fRec20[0] * iTemp404) * iTemp405));
			double fTemp406 = (fConst5 * (fVec50[0] * fRec101[0]));
			double fTemp407 = floor(fTemp406);
			int iTemp408 = int(fTemp406);
			fRec8[0] = ((((((fTemp367 + ((fTemp365 - floor(fTemp365)) * (ftbl0[((iTemp366 + 1) % 65536)] - fTemp367))) * (((fTemp371 + (1 - fTemp370)) * fVec47[(IOTA-int((iTemp378 & 262143)))&262143]) + ((fTemp370 - fTemp371) * fVec47[(IOTA-int((int((iTemp378 + 1)) & 262143)))&262143]))) + ((fTemp383 + ((fTemp381 - floor(fTemp381)) * (ftbl0[((iTemp382 + 1) % 65536)] - fTemp383))) * (((fTemp387 + (1 - fTemp386)) * fVec47[(IOTA-int((iTemp388 & 262143)))&262143]) + ((fTemp386 - fTemp387) * fVec47[(IOTA-int((int((iTemp388 + 1)) & 262143)))&262143])))) + ((fTemp393 + ((fTemp391 - floor(fTemp391)) * (ftbl0[((iTemp392 + 1) % 65536)] - fTemp393))) * (((fTemp397 + (1 - fTemp396)) * fVec47[(IOTA-int((iTemp398 & 262143)))&262143]) + ((fTemp396 - fTemp397) * fVec47[(IOTA-int((int((iTemp398 + 1)) & 262143)))&262143])))) + ((fTemp403 + ((fTemp401 - floor(fTemp401)) * (ftbl0[((iTemp402 + 1) % 65536)] - fTemp403))) * (((fTemp407 + (1 - fTemp406)) * fVec47[(IOTA-int((iTemp408 & 262143)))&262143]) + ((fTemp406 - fTemp407) * fVec47[(IOTA-int((int((iTemp408 + 1)) & 262143)))&262143])))) + (fSlow226 * fTemp376));
			double fTemp409 = (fRec102[1] + (fSlow227 / fTemp5));
			fRec102[0] = (fTemp409 - floor(fTemp409));
			double fTemp410 = (fRec102[0] - floor(fRec102[0]));
			fVec51[0] = fTemp410;
			double fTemp411 = (0.5 * fVec51[0]);
			double fTemp412 = (65536.0 * (fTemp411 - floor(fTemp411)));
			int iTemp413 = int(fTemp412);
			double fTemp414 = ftbl0[iTemp413];
			int iTemp415 = (fVec51[0] > 0.001);
			int iTemp416 = (fVec51[1] <= 0.001);
			fRec103[0] = ((fRec103[1] * (1 - (iTemp415 * iTemp416))) + ((fRec20[0] * iTemp415) * iTemp416));
			double fTemp417 = (fConst5 * (fVec51[0] * fRec103[0]));
			double fTemp418 = floor(fTemp417);
			fRec104[0] = (fSlow233 + (fSlow5 * fRec104[1]));
			double fTemp419 = ((fSlow228 * fTemp23) + ((fSlow229 * fTemp21) + ((fSlow230 * fTemp20) + ((fSlow231 * fTemp24) + ((fSlow232 * fTemp22) + ((fTemp25 * fRec104[0]) + ((fSlow234 * fTemp26) + ((fSlow235 * fTemp27) + ((fSlow236 * fTemp28) + ((fSlow237 * fTemp29) + ((fSlow238 * fTemp30) + ((fSlow239 * fTemp31) + ((fSlow240 * fTemp32) + ((fSlow241 * fTemp33) + ((fSlow242 * fTemp34) + ((fSlow243 * fTemp35) + (fSlow244 * fTemp36)))))))))))))))));
			fVec52[IOTA&1048575] = fTemp419;
			iRec105[0] = ((iSlow245 * iTemp39) + (iTemp40 * iRec105[1]));
			iRec106[0] = ((iSlow245 * iTemp42) + (iTemp43 * iRec106[1]));
			double fTemp420 = ((0.5 * (fVec2[0] * fVec52[(IOTA-int((int(iRec105[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec52[(IOTA-int((int(iRec106[0]) & 1048575)))&1048575]));
			int iTemp421 = (fTemp420 > 1);
			int iTemp422 = (fTemp420 < -1);
			double fTemp423 = ((iTemp421 + ((fTemp420 * (1 - iTemp422)) * (1 - iTemp421))) - iTemp422);
			double fTemp424 = (fSlow68 * fTemp423);
			fVec53[IOTA&262143] = fTemp424;
			int iTemp425 = int(fTemp417);
			double fTemp426 = (fRec102[0] + (0.25 - floor((fRec102[0] + 0.25))));
			fVec54[0] = fTemp426;
			double fTemp427 = (0.5 * fVec54[0]);
			double fTemp428 = (65536.0 * (fTemp427 - floor(fTemp427)));
			int iTemp429 = int(fTemp428);
			double fTemp430 = ftbl0[iTemp429];
			int iTemp431 = (fVec54[0] > 0.001);
			int iTemp432 = (fVec54[1] <= 0.001);
			fRec107[0] = ((fRec107[1] * (1 - (iTemp431 * iTemp432))) + ((fRec20[0] * iTemp431) * iTemp432));
			double fTemp433 = (fConst5 * (fVec54[0] * fRec107[0]));
			double fTemp434 = floor(fTemp433);
			int iTemp435 = int(fTemp433);
			double fTemp436 = (fRec102[0] + (0.5 - floor((fRec102[0] + 0.5))));
			fVec55[0] = fTemp436;
			double fTemp437 = (0.5 * fVec55[0]);
			double fTemp438 = (65536.0 * (fTemp437 - floor(fTemp437)));
			int iTemp439 = int(fTemp438);
			double fTemp440 = ftbl0[iTemp439];
			int iTemp441 = (fVec55[0] > 0.001);
			int iTemp442 = (fVec55[1] <= 0.001);
			fRec108[0] = ((fRec108[1] * (1 - (iTemp441 * iTemp442))) + ((fRec20[0] * iTemp441) * iTemp442));
			double fTemp443 = (fConst5 * (fVec55[0] * fRec108[0]));
			double fTemp444 = floor(fTemp443);
			int iTemp445 = int(fTemp443);
			double fTemp446 = (fRec102[0] + (0.75 - floor((fRec102[0] + 0.75))));
			fVec56[0] = fTemp446;
			double fTemp447 = (0.5 * fVec56[0]);
			double fTemp448 = (65536.0 * (fTemp447 - floor(fTemp447)));
			int iTemp449 = int(fTemp448);
			double fTemp450 = ftbl0[iTemp449];
			int iTemp451 = (fVec56[0] > 0.001);
			int iTemp452 = (fVec56[1] <= 0.001);
			fRec109[0] = ((fRec109[1] * (1 - (iTemp451 * iTemp452))) + ((fRec20[0] * iTemp451) * iTemp452));
			double fTemp453 = (fConst5 * (fVec56[0] * fRec109[0]));
			double fTemp454 = floor(fTemp453);
			int iTemp455 = int(fTemp453);
			fRec9[0] = ((((((fTemp414 + ((fTemp412 - floor(fTemp412)) * (ftbl0[((iTemp413 + 1) % 65536)] - fTemp414))) * (((fTemp418 + (1 - fTemp417)) * fVec53[(IOTA-int((iTemp425 & 262143)))&262143]) + ((fTemp417 - fTemp418) * fVec53[(IOTA-int((int((iTemp425 + 1)) & 262143)))&262143]))) + ((fTemp430 + ((fTemp428 - floor(fTemp428)) * (ftbl0[((iTemp429 + 1) % 65536)] - fTemp430))) * (((fTemp434 + (1 - fTemp433)) * fVec53[(IOTA-int((iTemp435 & 262143)))&262143]) + ((fTemp433 - fTemp434) * fVec53[(IOTA-int((int((iTemp435 + 1)) & 262143)))&262143])))) + ((fTemp440 + ((fTemp438 - floor(fTemp438)) * (ftbl0[((iTemp439 + 1) % 65536)] - fTemp440))) * (((fTemp444 + (1 - fTemp443)) * fVec53[(IOTA-int((iTemp445 & 262143)))&262143]) + ((fTemp443 - fTemp444) * fVec53[(IOTA-int((int((iTemp445 + 1)) & 262143)))&262143])))) + ((fTemp450 + ((fTemp448 - floor(fTemp448)) * (ftbl0[((iTemp449 + 1) % 65536)] - fTemp450))) * (((fTemp454 + (1 - fTemp453)) * fVec53[(IOTA-int((iTemp455 & 262143)))&262143]) + ((fTemp453 - fTemp454) * fVec53[(IOTA-int((int((iTemp455 + 1)) & 262143)))&262143])))) + (fSlow246 * fTemp423));
			double fTemp456 = (fRec110[1] + (fSlow247 / fTemp5));
			fRec110[0] = (fTemp456 - floor(fTemp456));
			double fTemp457 = (fRec110[0] - floor(fRec110[0]));
			fVec57[0] = fTemp457;
			double fTemp458 = (0.5 * fVec57[0]);
			double fTemp459 = (65536.0 * (fTemp458 - floor(fTemp458)));
			int iTemp460 = int(fTemp459);
			double fTemp461 = ftbl0[iTemp460];
			int iTemp462 = (fVec57[0] > 0.001);
			int iTemp463 = (fVec57[1] <= 0.001);
			fRec111[0] = ((fRec111[1] * (1 - (iTemp462 * iTemp463))) + ((fRec20[0] * iTemp462) * iTemp463));
			double fTemp464 = (fConst5 * (fVec57[0] * fRec111[0]));
			double fTemp465 = floor(fTemp464);
			fRec112[0] = (fSlow253 + (fSlow5 * fRec112[1]));
			double fTemp466 = ((fSlow248 * fTemp23) + ((fSlow249 * fTemp21) + ((fSlow250 * fTemp20) + ((fSlow251 * fTemp24) + ((fSlow252 * fTemp22) + ((fTemp25 * fRec112[0]) + ((fSlow254 * fTemp26) + ((fSlow255 * fTemp27) + ((fSlow256 * fTemp28) + ((fSlow257 * fTemp29) + ((fSlow258 * fTemp30) + ((fSlow259 * fTemp31) + ((fSlow260 * fTemp32) + ((fSlow261 * fTemp33) + ((fSlow262 * fTemp34) + ((fSlow263 * fTemp35) + (fSlow264 * fTemp36)))))))))))))))));
			fVec58[IOTA&1048575] = fTemp466;
			iRec113[0] = ((iSlow265 * iTemp39) + (iTemp40 * iRec113[1]));
			iRec114[0] = ((iSlow265 * iTemp42) + (iTemp43 * iRec114[1]));
			double fTemp467 = ((0.5 * (fVec2[0] * fVec58[(IOTA-int((int(iRec113[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec58[(IOTA-int((int(iRec114[0]) & 1048575)))&1048575]));
			int iTemp468 = (fTemp467 > 1);
			int iTemp469 = (fTemp467 < -1);
			double fTemp470 = ((iTemp468 + ((fTemp467 * (1 - iTemp469)) * (1 - iTemp468))) - iTemp469);
			double fTemp471 = (fSlow64 * fTemp470);
			fVec59[IOTA&262143] = fTemp471;
			int iTemp472 = int(fTemp464);
			double fTemp473 = (fRec110[0] + (0.25 - floor((fRec110[0] + 0.25))));
			fVec60[0] = fTemp473;
			double fTemp474 = (0.5 * fVec60[0]);
			double fTemp475 = (65536.0 * (fTemp474 - floor(fTemp474)));
			int iTemp476 = int(fTemp475);
			double fTemp477 = ftbl0[iTemp476];
			int iTemp478 = (fVec60[0] > 0.001);
			int iTemp479 = (fVec60[1] <= 0.001);
			fRec115[0] = ((fRec115[1] * (1 - (iTemp478 * iTemp479))) + ((fRec20[0] * iTemp478) * iTemp479));
			double fTemp480 = (fConst5 * (fVec60[0] * fRec115[0]));
			double fTemp481 = floor(fTemp480);
			int iTemp482 = int(fTemp480);
			double fTemp483 = (fRec110[0] + (0.5 - floor((fRec110[0] + 0.5))));
			fVec61[0] = fTemp483;
			double fTemp484 = (0.5 * fVec61[0]);
			double fTemp485 = (65536.0 * (fTemp484 - floor(fTemp484)));
			int iTemp486 = int(fTemp485);
			double fTemp487 = ftbl0[iTemp486];
			int iTemp488 = (fVec61[0] > 0.001);
			int iTemp489 = (fVec61[1] <= 0.001);
			fRec116[0] = ((fRec116[1] * (1 - (iTemp488 * iTemp489))) + ((fRec20[0] * iTemp488) * iTemp489));
			double fTemp490 = (fConst5 * (fVec61[0] * fRec116[0]));
			double fTemp491 = floor(fTemp490);
			int iTemp492 = int(fTemp490);
			double fTemp493 = (fRec110[0] + (0.75 - floor((fRec110[0] + 0.75))));
			fVec62[0] = fTemp493;
			double fTemp494 = (0.5 * fVec62[0]);
			double fTemp495 = (65536.0 * (fTemp494 - floor(fTemp494)));
			int iTemp496 = int(fTemp495);
			double fTemp497 = ftbl0[iTemp496];
			int iTemp498 = (fVec62[0] > 0.001);
			int iTemp499 = (fVec62[1] <= 0.001);
			fRec117[0] = ((fRec117[1] * (1 - (iTemp498 * iTemp499))) + ((fRec20[0] * iTemp498) * iTemp499));
			double fTemp500 = (fConst5 * (fVec62[0] * fRec117[0]));
			double fTemp501 = floor(fTemp500);
			int iTemp502 = int(fTemp500);
			fRec10[0] = ((((((fTemp461 + ((fTemp459 - floor(fTemp459)) * (ftbl0[((iTemp460 + 1) % 65536)] - fTemp461))) * (((fTemp465 + (1 - fTemp464)) * fVec59[(IOTA-int((iTemp472 & 262143)))&262143]) + ((fTemp464 - fTemp465) * fVec59[(IOTA-int((int((iTemp472 + 1)) & 262143)))&262143]))) + ((fTemp477 + ((fTemp475 - floor(fTemp475)) * (ftbl0[((iTemp476 + 1) % 65536)] - fTemp477))) * (((fTemp481 + (1 - fTemp480)) * fVec59[(IOTA-int((iTemp482 & 262143)))&262143]) + ((fTemp480 - fTemp481) * fVec59[(IOTA-int((int((iTemp482 + 1)) & 262143)))&262143])))) + ((fTemp487 + ((fTemp485 - floor(fTemp485)) * (ftbl0[((iTemp486 + 1) % 65536)] - fTemp487))) * (((fTemp491 + (1 - fTemp490)) * fVec59[(IOTA-int((iTemp492 & 262143)))&262143]) + ((fTemp490 - fTemp491) * fVec59[(IOTA-int((int((iTemp492 + 1)) & 262143)))&262143])))) + ((fTemp497 + ((fTemp495 - floor(fTemp495)) * (ftbl0[((iTemp496 + 1) % 65536)] - fTemp497))) * (((fTemp501 + (1 - fTemp500)) * fVec59[(IOTA-int((iTemp502 & 262143)))&262143]) + ((fTemp500 - fTemp501) * fVec59[(IOTA-int((int((iTemp502 + 1)) & 262143)))&262143])))) + (fSlow266 * fTemp470));
			double fTemp503 = (fRec118[1] + (fSlow267 / fTemp5));
			fRec118[0] = (fTemp503 - floor(fTemp503));
			double fTemp504 = (fRec118[0] - floor(fRec118[0]));
			fVec63[0] = fTemp504;
			double fTemp505 = (0.5 * fVec63[0]);
			double fTemp506 = (65536.0 * (fTemp505 - floor(fTemp505)));
			int iTemp507 = int(fTemp506);
			double fTemp508 = ftbl0[iTemp507];
			int iTemp509 = (fVec63[0] > 0.001);
			int iTemp510 = (fVec63[1] <= 0.001);
			fRec119[0] = ((fRec119[1] * (1 - (iTemp509 * iTemp510))) + ((fRec20[0] * iTemp509) * iTemp510));
			double fTemp511 = (fConst5 * (fVec63[0] * fRec119[0]));
			double fTemp512 = floor(fTemp511);
			fRec120[0] = (fSlow273 + (fSlow5 * fRec120[1]));
			double fTemp513 = ((fSlow268 * fTemp23) + ((fSlow269 * fTemp21) + ((fSlow270 * fTemp20) + ((fSlow271 * fTemp24) + ((fSlow272 * fTemp22) + ((fTemp25 * fRec120[0]) + ((fSlow274 * fTemp26) + ((fSlow275 * fTemp27) + ((fSlow276 * fTemp28) + ((fSlow277 * fTemp29) + ((fSlow278 * fTemp30) + ((fSlow279 * fTemp31) + ((fSlow280 * fTemp32) + ((fSlow281 * fTemp33) + ((fSlow282 * fTemp34) + ((fSlow283 * fTemp35) + (fSlow284 * fTemp36)))))))))))))))));
			fVec64[IOTA&1048575] = fTemp513;
			iRec121[0] = ((iSlow285 * iTemp39) + (iTemp40 * iRec121[1]));
			iRec122[0] = ((iSlow285 * iTemp42) + (iTemp43 * iRec122[1]));
			double fTemp514 = ((0.5 * (fVec2[0] * fVec64[(IOTA-int((int(iRec121[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec64[(IOTA-int((int(iRec122[0]) & 1048575)))&1048575]));
			int iTemp515 = (fTemp514 > 1);
			int iTemp516 = (fTemp514 < -1);
			double fTemp517 = ((iTemp515 + ((fTemp514 * (1 - iTemp516)) * (1 - iTemp515))) - iTemp516);
			double fTemp518 = (fSlow60 * fTemp517);
			fVec65[IOTA&262143] = fTemp518;
			int iTemp519 = int(fTemp511);
			double fTemp520 = (fRec118[0] + (0.25 - floor((fRec118[0] + 0.25))));
			fVec66[0] = fTemp520;
			double fTemp521 = (0.5 * fVec66[0]);
			double fTemp522 = (65536.0 * (fTemp521 - floor(fTemp521)));
			int iTemp523 = int(fTemp522);
			double fTemp524 = ftbl0[iTemp523];
			int iTemp525 = (fVec66[0] > 0.001);
			int iTemp526 = (fVec66[1] <= 0.001);
			fRec123[0] = ((fRec123[1] * (1 - (iTemp525 * iTemp526))) + ((fRec20[0] * iTemp525) * iTemp526));
			double fTemp527 = (fConst5 * (fVec66[0] * fRec123[0]));
			double fTemp528 = floor(fTemp527);
			int iTemp529 = int(fTemp527);
			double fTemp530 = (fRec118[0] + (0.5 - floor((fRec118[0] + 0.5))));
			fVec67[0] = fTemp530;
			double fTemp531 = (0.5 * fVec67[0]);
			double fTemp532 = (65536.0 * (fTemp531 - floor(fTemp531)));
			int iTemp533 = int(fTemp532);
			double fTemp534 = ftbl0[iTemp533];
			int iTemp535 = (fVec67[0] > 0.001);
			int iTemp536 = (fVec67[1] <= 0.001);
			fRec124[0] = ((fRec124[1] * (1 - (iTemp535 * iTemp536))) + ((fRec20[0] * iTemp535) * iTemp536));
			double fTemp537 = (fConst5 * (fVec67[0] * fRec124[0]));
			double fTemp538 = floor(fTemp537);
			int iTemp539 = int(fTemp537);
			double fTemp540 = (fRec118[0] + (0.75 - floor((fRec118[0] + 0.75))));
			fVec68[0] = fTemp540;
			double fTemp541 = (0.5 * fVec68[0]);
			double fTemp542 = (65536.0 * (fTemp541 - floor(fTemp541)));
			int iTemp543 = int(fTemp542);
			double fTemp544 = ftbl0[iTemp543];
			int iTemp545 = (fVec68[0] > 0.001);
			int iTemp546 = (fVec68[1] <= 0.001);
			fRec125[0] = ((fRec125[1] * (1 - (iTemp545 * iTemp546))) + ((fRec20[0] * iTemp545) * iTemp546));
			double fTemp547 = (fConst5 * (fVec68[0] * fRec125[0]));
			double fTemp548 = floor(fTemp547);
			int iTemp549 = int(fTemp547);
			fRec11[0] = ((((((fTemp508 + ((fTemp506 - floor(fTemp506)) * (ftbl0[((iTemp507 + 1) % 65536)] - fTemp508))) * (((fTemp512 + (1 - fTemp511)) * fVec65[(IOTA-int((iTemp519 & 262143)))&262143]) + ((fTemp511 - fTemp512) * fVec65[(IOTA-int((int((iTemp519 + 1)) & 262143)))&262143]))) + ((fTemp524 + ((fTemp522 - floor(fTemp522)) * (ftbl0[((iTemp523 + 1) % 65536)] - fTemp524))) * (((fTemp528 + (1 - fTemp527)) * fVec65[(IOTA-int((iTemp529 & 262143)))&262143]) + ((fTemp527 - fTemp528) * fVec65[(IOTA-int((int((iTemp529 + 1)) & 262143)))&262143])))) + ((fTemp534 + ((fTemp532 - floor(fTemp532)) * (ftbl0[((iTemp533 + 1) % 65536)] - fTemp534))) * (((fTemp538 + (1 - fTemp537)) * fVec65[(IOTA-int((iTemp539 & 262143)))&262143]) + ((fTemp537 - fTemp538) * fVec65[(IOTA-int((int((iTemp539 + 1)) & 262143)))&262143])))) + ((fTemp544 + ((fTemp542 - floor(fTemp542)) * (ftbl0[((iTemp543 + 1) % 65536)] - fTemp544))) * (((fTemp548 + (1 - fTemp547)) * fVec65[(IOTA-int((iTemp549 & 262143)))&262143]) + ((fTemp547 - fTemp548) * fVec65[(IOTA-int((int((iTemp549 + 1)) & 262143)))&262143])))) + (fSlow286 * fTemp517));
			double fTemp550 = (fRec126[1] + (fSlow287 / fTemp5));
			fRec126[0] = (fTemp550 - floor(fTemp550));
			double fTemp551 = (fRec126[0] - floor(fRec126[0]));
			fVec69[0] = fTemp551;
			double fTemp552 = (0.5 * fVec69[0]);
			double fTemp553 = (65536.0 * (fTemp552 - floor(fTemp552)));
			int iTemp554 = int(fTemp553);
			double fTemp555 = ftbl0[iTemp554];
			int iTemp556 = (fVec69[0] > 0.001);
			int iTemp557 = (fVec69[1] <= 0.001);
			fRec127[0] = ((fRec127[1] * (1 - (iTemp556 * iTemp557))) + ((fRec20[0] * iTemp556) * iTemp557));
			double fTemp558 = (fConst5 * (fVec69[0] * fRec127[0]));
			double fTemp559 = floor(fTemp558);
			fRec128[0] = (fSlow293 + (fSlow5 * fRec128[1]));
			double fTemp560 = ((fSlow288 * fTemp23) + ((fSlow289 * fTemp21) + ((fSlow290 * fTemp20) + ((fSlow291 * fTemp24) + ((fSlow292 * fTemp22) + ((fTemp25 * fRec128[0]) + ((fSlow294 * fTemp26) + ((fSlow295 * fTemp27) + ((fSlow296 * fTemp28) + ((fSlow297 * fTemp29) + ((fSlow298 * fTemp30) + ((fSlow299 * fTemp31) + ((fSlow300 * fTemp32) + ((fSlow301 * fTemp33) + ((fSlow302 * fTemp34) + ((fSlow303 * fTemp35) + (fSlow304 * fTemp36)))))))))))))))));
			fVec70[IOTA&1048575] = fTemp560;
			iRec129[0] = ((iSlow305 * iTemp39) + (iTemp40 * iRec129[1]));
			iRec130[0] = ((iSlow305 * iTemp42) + (iTemp43 * iRec130[1]));
			double fTemp561 = ((0.5 * (fVec2[0] * fVec70[(IOTA-int((int(iRec129[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec70[(IOTA-int((int(iRec130[0]) & 1048575)))&1048575]));
			int iTemp562 = (fTemp561 > 1);
			int iTemp563 = (fTemp561 < -1);
			double fTemp564 = ((iTemp562 + ((fTemp561 * (1 - iTemp563)) * (1 - iTemp562))) - iTemp563);
			double fTemp565 = (fSlow56 * fTemp564);
			fVec71[IOTA&262143] = fTemp565;
			int iTemp566 = int(fTemp558);
			double fTemp567 = (fRec126[0] + (0.25 - floor((fRec126[0] + 0.25))));
			fVec72[0] = fTemp567;
			double fTemp568 = (0.5 * fVec72[0]);
			double fTemp569 = (65536.0 * (fTemp568 - floor(fTemp568)));
			int iTemp570 = int(fTemp569);
			double fTemp571 = ftbl0[iTemp570];
			int iTemp572 = (fVec72[0] > 0.001);
			int iTemp573 = (fVec72[1] <= 0.001);
			fRec131[0] = ((fRec131[1] * (1 - (iTemp572 * iTemp573))) + ((fRec20[0] * iTemp572) * iTemp573));
			double fTemp574 = (fConst5 * (fVec72[0] * fRec131[0]));
			double fTemp575 = floor(fTemp574);
			int iTemp576 = int(fTemp574);
			double fTemp577 = (fRec126[0] + (0.5 - floor((fRec126[0] + 0.5))));
			fVec73[0] = fTemp577;
			double fTemp578 = (0.5 * fVec73[0]);
			double fTemp579 = (65536.0 * (fTemp578 - floor(fTemp578)));
			int iTemp580 = int(fTemp579);
			double fTemp581 = ftbl0[iTemp580];
			int iTemp582 = (fVec73[0] > 0.001);
			int iTemp583 = (fVec73[1] <= 0.001);
			fRec132[0] = ((fRec132[1] * (1 - (iTemp582 * iTemp583))) + ((fRec20[0] * iTemp582) * iTemp583));
			double fTemp584 = (fConst5 * (fVec73[0] * fRec132[0]));
			double fTemp585 = floor(fTemp584);
			int iTemp586 = int(fTemp584);
			double fTemp587 = (fRec126[0] + (0.75 - floor((fRec126[0] + 0.75))));
			fVec74[0] = fTemp587;
			double fTemp588 = (0.5 * fVec74[0]);
			double fTemp589 = (65536.0 * (fTemp588 - floor(fTemp588)));
			int iTemp590 = int(fTemp589);
			double fTemp591 = ftbl0[iTemp590];
			int iTemp592 = (fVec74[0] > 0.001);
			int iTemp593 = (fVec74[1] <= 0.001);
			fRec133[0] = ((fRec133[1] * (1 - (iTemp592 * iTemp593))) + ((fRec20[0] * iTemp592) * iTemp593));
			double fTemp594 = (fConst5 * (fVec74[0] * fRec133[0]));
			double fTemp595 = floor(fTemp594);
			int iTemp596 = int(fTemp594);
			fRec12[0] = ((((((fTemp555 + ((fTemp553 - floor(fTemp553)) * (ftbl0[((iTemp554 + 1) % 65536)] - fTemp555))) * (((fTemp559 + (1 - fTemp558)) * fVec71[(IOTA-int((iTemp566 & 262143)))&262143]) + ((fTemp558 - fTemp559) * fVec71[(IOTA-int((int((iTemp566 + 1)) & 262143)))&262143]))) + ((fTemp571 + ((fTemp569 - floor(fTemp569)) * (ftbl0[((iTemp570 + 1) % 65536)] - fTemp571))) * (((fTemp575 + (1 - fTemp574)) * fVec71[(IOTA-int((iTemp576 & 262143)))&262143]) + ((fTemp574 - fTemp575) * fVec71[(IOTA-int((int((iTemp576 + 1)) & 262143)))&262143])))) + ((fTemp581 + ((fTemp579 - floor(fTemp579)) * (ftbl0[((iTemp580 + 1) % 65536)] - fTemp581))) * (((fTemp585 + (1 - fTemp584)) * fVec71[(IOTA-int((iTemp586 & 262143)))&262143]) + ((fTemp584 - fTemp585) * fVec71[(IOTA-int((int((iTemp586 + 1)) & 262143)))&262143])))) + ((fTemp591 + ((fTemp589 - floor(fTemp589)) * (ftbl0[((iTemp590 + 1) % 65536)] - fTemp591))) * (((fTemp595 + (1 - fTemp594)) * fVec71[(IOTA-int((iTemp596 & 262143)))&262143]) + ((fTemp594 - fTemp595) * fVec71[(IOTA-int((int((iTemp596 + 1)) & 262143)))&262143])))) + (fSlow306 * fTemp564));
			double fTemp597 = (fRec134[1] + (fSlow307 / fTemp5));
			fRec134[0] = (fTemp597 - floor(fTemp597));
			double fTemp598 = (fRec134[0] - floor(fRec134[0]));
			fVec75[0] = fTemp598;
			double fTemp599 = (0.5 * fVec75[0]);
			double fTemp600 = (65536.0 * (fTemp599 - floor(fTemp599)));
			int iTemp601 = int(fTemp600);
			double fTemp602 = ftbl0[iTemp601];
			int iTemp603 = (fVec75[0] > 0.001);
			int iTemp604 = (fVec75[1] <= 0.001);
			fRec135[0] = ((fRec135[1] * (1 - (iTemp603 * iTemp604))) + ((fRec20[0] * iTemp603) * iTemp604));
			double fTemp605 = (fConst5 * (fVec75[0] * fRec135[0]));
			double fTemp606 = floor(fTemp605);
			fRec136[0] = (fSlow313 + (fSlow5 * fRec136[1]));
			double fTemp607 = ((fSlow308 * fTemp23) + ((fSlow309 * fTemp21) + ((fSlow310 * fTemp20) + ((fSlow311 * fTemp24) + ((fSlow312 * fTemp22) + ((fTemp25 * fRec136[0]) + ((fSlow314 * fTemp26) + ((fSlow315 * fTemp27) + ((fSlow316 * fTemp28) + ((fSlow317 * fTemp29) + ((fSlow318 * fTemp30) + ((fSlow319 * fTemp31) + ((fSlow320 * fTemp32) + ((fSlow321 * fTemp33) + ((fSlow322 * fTemp34) + ((fSlow323 * fTemp35) + (fSlow324 * fTemp36)))))))))))))))));
			fVec76[IOTA&1048575] = fTemp607;
			iRec137[0] = ((iSlow325 * iTemp39) + (iTemp40 * iRec137[1]));
			iRec138[0] = ((iSlow325 * iTemp42) + (iTemp43 * iRec138[1]));
			double fTemp608 = ((0.5 * (fVec2[0] * fVec76[(IOTA-int((int(iRec137[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec76[(IOTA-int((int(iRec138[0]) & 1048575)))&1048575]));
			int iTemp609 = (fTemp608 > 1);
			int iTemp610 = (fTemp608 < -1);
			double fTemp611 = ((iTemp609 + ((fTemp608 * (1 - iTemp610)) * (1 - iTemp609))) - iTemp610);
			double fTemp612 = (fSlow52 * fTemp611);
			fVec77[IOTA&262143] = fTemp612;
			int iTemp613 = int(fTemp605);
			double fTemp614 = (fRec134[0] + (0.25 - floor((fRec134[0] + 0.25))));
			fVec78[0] = fTemp614;
			double fTemp615 = (0.5 * fVec78[0]);
			double fTemp616 = (65536.0 * (fTemp615 - floor(fTemp615)));
			int iTemp617 = int(fTemp616);
			double fTemp618 = ftbl0[iTemp617];
			int iTemp619 = (fVec78[0] > 0.001);
			int iTemp620 = (fVec78[1] <= 0.001);
			fRec139[0] = ((fRec139[1] * (1 - (iTemp619 * iTemp620))) + ((fRec20[0] * iTemp619) * iTemp620));
			double fTemp621 = (fConst5 * (fVec78[0] * fRec139[0]));
			double fTemp622 = floor(fTemp621);
			int iTemp623 = int(fTemp621);
			double fTemp624 = (fRec134[0] + (0.5 - floor((fRec134[0] + 0.5))));
			fVec79[0] = fTemp624;
			double fTemp625 = (0.5 * fVec79[0]);
			double fTemp626 = (65536.0 * (fTemp625 - floor(fTemp625)));
			int iTemp627 = int(fTemp626);
			double fTemp628 = ftbl0[iTemp627];
			int iTemp629 = (fVec79[0] > 0.001);
			int iTemp630 = (fVec79[1] <= 0.001);
			fRec140[0] = ((fRec140[1] * (1 - (iTemp629 * iTemp630))) + ((fRec20[0] * iTemp629) * iTemp630));
			double fTemp631 = (fConst5 * (fVec79[0] * fRec140[0]));
			double fTemp632 = floor(fTemp631);
			int iTemp633 = int(fTemp631);
			double fTemp634 = (fRec134[0] + (0.75 - floor((fRec134[0] + 0.75))));
			fVec80[0] = fTemp634;
			double fTemp635 = (0.5 * fVec80[0]);
			double fTemp636 = (65536.0 * (fTemp635 - floor(fTemp635)));
			int iTemp637 = int(fTemp636);
			double fTemp638 = ftbl0[iTemp637];
			int iTemp639 = (fVec80[0] > 0.001);
			int iTemp640 = (fVec80[1] <= 0.001);
			fRec141[0] = ((fRec141[1] * (1 - (iTemp639 * iTemp640))) + ((fRec20[0] * iTemp639) * iTemp640));
			double fTemp641 = (fConst5 * (fVec80[0] * fRec141[0]));
			double fTemp642 = floor(fTemp641);
			int iTemp643 = int(fTemp641);
			fRec13[0] = ((((((fTemp602 + ((fTemp600 - floor(fTemp600)) * (ftbl0[((iTemp601 + 1) % 65536)] - fTemp602))) * (((fTemp606 + (1 - fTemp605)) * fVec77[(IOTA-int((iTemp613 & 262143)))&262143]) + ((fTemp605 - fTemp606) * fVec77[(IOTA-int((int((iTemp613 + 1)) & 262143)))&262143]))) + ((fTemp618 + ((fTemp616 - floor(fTemp616)) * (ftbl0[((iTemp617 + 1) % 65536)] - fTemp618))) * (((fTemp622 + (1 - fTemp621)) * fVec77[(IOTA-int((iTemp623 & 262143)))&262143]) + ((fTemp621 - fTemp622) * fVec77[(IOTA-int((int((iTemp623 + 1)) & 262143)))&262143])))) + ((fTemp628 + ((fTemp626 - floor(fTemp626)) * (ftbl0[((iTemp627 + 1) % 65536)] - fTemp628))) * (((fTemp632 + (1 - fTemp631)) * fVec77[(IOTA-int((iTemp633 & 262143)))&262143]) + ((fTemp631 - fTemp632) * fVec77[(IOTA-int((int((iTemp633 + 1)) & 262143)))&262143])))) + ((fTemp638 + ((fTemp636 - floor(fTemp636)) * (ftbl0[((iTemp637 + 1) % 65536)] - fTemp638))) * (((fTemp642 + (1 - fTemp641)) * fVec77[(IOTA-int((iTemp643 & 262143)))&262143]) + ((fTemp641 - fTemp642) * fVec77[(IOTA-int((int((iTemp643 + 1)) & 262143)))&262143])))) + (fSlow326 * fTemp611));
			double fTemp644 = (fRec142[1] + (fSlow327 / fTemp5));
			fRec142[0] = (fTemp644 - floor(fTemp644));
			double fTemp645 = (fRec142[0] - floor(fRec142[0]));
			fVec81[0] = fTemp645;
			double fTemp646 = (0.5 * fVec81[0]);
			double fTemp647 = (65536.0 * (fTemp646 - floor(fTemp646)));
			int iTemp648 = int(fTemp647);
			double fTemp649 = ftbl0[iTemp648];
			int iTemp650 = (fVec81[0] > 0.001);
			int iTemp651 = (fVec81[1] <= 0.001);
			fRec143[0] = ((fRec143[1] * (1 - (iTemp650 * iTemp651))) + ((fRec20[0] * iTemp650) * iTemp651));
			double fTemp652 = (fConst5 * (fVec81[0] * fRec143[0]));
			double fTemp653 = floor(fTemp652);
			fRec144[0] = (fSlow333 + (fSlow5 * fRec144[1]));
			double fTemp654 = ((fSlow328 * fTemp23) + ((fSlow329 * fTemp21) + ((fSlow330 * fTemp20) + ((fSlow331 * fTemp24) + ((fSlow332 * fTemp22) + ((fTemp25 * fRec144[0]) + ((fSlow334 * fTemp26) + ((fSlow335 * fTemp27) + ((fSlow336 * fTemp28) + ((fSlow337 * fTemp29) + ((fSlow338 * fTemp30) + ((fSlow339 * fTemp31) + ((fSlow340 * fTemp32) + ((fSlow341 * fTemp33) + ((fSlow342 * fTemp34) + ((fSlow343 * fTemp35) + (fSlow344 * fTemp36)))))))))))))))));
			fVec82[IOTA&1048575] = fTemp654;
			iRec145[0] = ((iSlow345 * iTemp39) + (iTemp40 * iRec145[1]));
			iRec146[0] = ((iSlow345 * iTemp42) + (iTemp43 * iRec146[1]));
			double fTemp655 = ((0.5 * (fVec2[0] * fVec82[(IOTA-int((int(iRec145[0]) & 1048575)))&1048575])) + (fVec4[0] * fVec82[(IOTA-int((int(iRec146[0]) & 1048575)))&1048575]));
			int iTemp656 = (fTemp655 > 1);
			int iTemp657 = (fTemp655 < -1);
			double fTemp658 = ((iTemp656 + ((fTemp655 * (1 - iTemp657)) * (1 - iTemp656))) - iTemp657);
			double fTemp659 = (fSlow48 * fTemp658);
			fVec83[IOTA&262143] = fTemp659;
			int iTemp660 = int(fTemp652);
			double fTemp661 = (fRec142[0] + (0.25 - floor((fRec142[0] + 0.25))));
			fVec84[0] = fTemp661;
			double fTemp662 = (0.5 * fVec84[0]);
			double fTemp663 = (65536.0 * (fTemp662 - floor(fTemp662)));
			int iTemp664 = int(fTemp663);
			double fTemp665 = ftbl0[iTemp664];
			int iTemp666 = (fVec84[0] > 0.001);
			int iTemp667 = (fVec84[1] <= 0.001);
			fRec147[0] = ((fRec147[1] * (1 - (iTemp666 * iTemp667))) + ((fRec20[0] * iTemp666) * iTemp667));
			double fTemp668 = (fConst5 * (fVec84[0] * fRec147[0]));
			double fTemp669 = floor(fTemp668);
			int iTemp670 = int(fTemp668);
			double fTemp671 = (fRec142[0] + (0.5 - floor((fRec142[0] + 0.5))));
			fVec85[0] = fTemp671;
			double fTemp672 = (0.5 * fVec85[0]);
			double fTemp673 = (65536.0 * (fTemp672 - floor(fTemp672)));
			int iTemp674 = int(fTemp673);
			double fTemp675 = ftbl0[iTemp674];
			int iTemp676 = (fVec85[0] > 0.001);
			int iTemp677 = (fVec85[1] <= 0.001);
			fRec148[0] = ((fRec148[1] * (1 - (iTemp676 * iTemp677))) + ((fRec20[0] * iTemp676) * iTemp677));
			double fTemp678 = (fConst5 * (fVec85[0] * fRec148[0]));
			double fTemp679 = floor(fTemp678);
			int iTemp680 = int(fTemp678);
			double fTemp681 = (fRec142[0] + (0.75 - floor((fRec142[0] + 0.75))));
			fVec86[0] = fTemp681;
			double fTemp682 = (0.5 * fVec86[0]);
			double fTemp683 = (65536.0 * (fTemp682 - floor(fTemp682)));
			int iTemp684 = int(fTemp683);
			double fTemp685 = ftbl0[iTemp684];
			int iTemp686 = (fVec86[0] > 0.001);
			int iTemp687 = (fVec86[1] <= 0.001);
			fRec149[0] = ((fRec149[1] * (1 - (iTemp686 * iTemp687))) + ((fRec20[0] * iTemp686) * iTemp687));
			double fTemp688 = (fConst5 * (fVec86[0] * fRec149[0]));
			double fTemp689 = floor(fTemp688);
			int iTemp690 = int(fTemp688);
			fRec14[0] = ((((((fTemp649 + ((fTemp647 - floor(fTemp647)) * (ftbl0[((iTemp648 + 1) % 65536)] - fTemp649))) * (((fTemp653 + (1 - fTemp652)) * fVec83[(IOTA-int((iTemp660 & 262143)))&262143]) + ((fTemp652 - fTemp653) * fVec83[(IOTA-int((int((iTemp660 + 1)) & 262143)))&262143]))) + ((fTemp665 + ((fTemp663 - floor(fTemp663)) * (ftbl0[((iTemp664 + 1) % 65536)] - fTemp665))) * (((fTemp669 + (1 - fTemp668)) * fVec83[(IOTA-int((iTemp670 & 262143)))&262143]) + ((fTemp668 - fTemp669) * fVec83[(IOTA-int((int((iTemp670 + 1)) & 262143)))&262143])))) + ((fTemp675 + ((fTemp673 - floor(fTemp673)) * (ftbl0[((iTemp674 + 1) % 65536)] - fTemp675))) * (((fTemp679 + (1 - fTemp678)) * fVec83[(IOTA-int((iTemp680 & 262143)))&262143]) + ((fTemp678 - fTemp679) * fVec83[(IOTA-int((int((iTemp680 + 1)) & 262143)))&262143])))) + ((fTemp685 + ((fTemp683 - floor(fTemp683)) * (ftbl0[((iTemp684 + 1) % 65536)] - fTemp685))) * (((fTemp689 + (1 - fTemp688)) * fVec83[(IOTA-int((iTemp690 & 262143)))&262143]) + ((fTemp688 - fTemp689) * fVec83[(IOTA-int((int((iTemp690 + 1)) & 262143)))&262143])))) + (fSlow346 * fTemp658));
			fRec150[0] = (fSlow358 + (fSlow5 * fRec150[1]));
			double fTemp691 = (((((((((fSlow347 * fTemp27) + ((fSlow348 * fTemp28) + ((fSlow349 * fTemp29) + ((fSlow350 * fTemp30) + ((fSlow351 * fTemp31) + ((fSlow352 * fTemp32) + ((fSlow353 * fTemp33) + ((fSlow354 * fTemp34) + ((fSlow355 * fTemp35) + (fSlow356 * fTemp36)))))))))) + (fSlow357 * fTemp26)) + (fTemp25 * fRec150[0])) + (fSlow359 * fTemp22)) + (fSlow360 * fTemp24)) + (fSlow361 * fTemp20)) + (fSlow362 * fTemp21)) + (fSlow363 * fTemp23));
			fVec87[IOTA&1048575] = fTemp691;
			iRec151[0] = ((iTemp40 * iRec151[1]) + (iSlow364 * iTemp39));
			iRec152[0] = ((iTemp43 * iRec152[1]) + (iSlow364 * iTemp42));
			double fTemp692 = ((0.5 * (fVec87[(IOTA-int((int(iRec151[0]) & 1048575)))&1048575] * fVec2[0])) + (fVec87[(IOTA-int((int(iRec152[0]) & 1048575)))&1048575] * fVec4[0]));
			int iTemp693 = (fTemp692 > 1);
			int iTemp694 = (fTemp692 < -1);
			double fTemp695 = ((iTemp693 + ((fTemp692 * (1 - iTemp694)) * (1 - iTemp693))) - iTemp694);
			double fTemp696 = (fSlow44 * fTemp695);
			fVec88[IOTA&262143] = fTemp696;
			double fTemp697 = (fRec153[1] + (fSlow365 / fTemp5));
			fRec153[0] = (fTemp697 - floor(fTemp697));
			double fTemp698 = (fRec153[0] - floor(fRec153[0]));
			fVec89[0] = fTemp698;
			int iTemp699 = (fVec89[0] > 0.001);
			int iTemp700 = (fVec89[1] <= 0.001);
			fRec154[0] = ((fRec154[1] * (1 - (iTemp699 * iTemp700))) + ((fRec20[0] * iTemp699) * iTemp700));
			double fTemp701 = (fConst5 * (fVec89[0] * fRec154[0]));
			int iTemp702 = int(fTemp701);
			double fTemp703 = floor(fTemp701);
			double fTemp704 = (0.5 * fVec89[0]);
			double fTemp705 = (65536.0 * (fTemp704 - floor(fTemp704)));
			int iTemp706 = int(fTemp705);
			double fTemp707 = ftbl0[iTemp706];
			double fTemp708 = (fRec153[0] + (0.25 - floor((fRec153[0] + 0.25))));
			fVec90[0] = fTemp708;
			int iTemp709 = (fVec90[0] > 0.001);
			int iTemp710 = (fVec90[1] <= 0.001);
			fRec155[0] = ((fRec155[1] * (1 - (iTemp709 * iTemp710))) + ((fRec20[0] * iTemp709) * iTemp710));
			double fTemp711 = (fConst5 * (fVec90[0] * fRec155[0]));
			int iTemp712 = int(fTemp711);
			double fTemp713 = floor(fTemp711);
			double fTemp714 = (0.5 * fVec90[0]);
			double fTemp715 = (65536.0 * (fTemp714 - floor(fTemp714)));
			int iTemp716 = int(fTemp715);
			double fTemp717 = ftbl0[iTemp716];
			double fTemp718 = (fRec153[0] + (0.5 - floor((fRec153[0] + 0.5))));
			fVec91[0] = fTemp718;
			double fTemp719 = (0.5 * fVec91[0]);
			double fTemp720 = (65536.0 * (fTemp719 - floor(fTemp719)));
			int iTemp721 = int(fTemp720);
			double fTemp722 = ftbl0[iTemp721];
			int iTemp723 = (fVec91[0] > 0.001);
			int iTemp724 = (fVec91[1] <= 0.001);
			fRec156[0] = ((fRec156[1] * (1 - (iTemp723 * iTemp724))) + ((fRec20[0] * iTemp723) * iTemp724));
			double fTemp725 = (fConst5 * (fVec91[0] * fRec156[0]));
			double fTemp726 = floor(fTemp725);
			int iTemp727 = int(fTemp725);
			double fTemp728 = (fRec153[0] + (0.75 - floor((fRec153[0] + 0.75))));
			fVec92[0] = fTemp728;
			double fTemp729 = (0.5 * fVec92[0]);
			double fTemp730 = (65536.0 * (fTemp729 - floor(fTemp729)));
			int iTemp731 = int(fTemp730);
			double fTemp732 = ftbl0[iTemp731];
			int iTemp733 = (fVec92[0] > 0.001);
			int iTemp734 = (fVec92[1] <= 0.001);
			fRec157[0] = ((fRec157[1] * (1 - (iTemp733 * iTemp734))) + ((fRec20[0] * iTemp733) * iTemp734));
			double fTemp735 = (fConst5 * (fVec92[0] * fRec157[0]));
			double fTemp736 = floor(fTemp735);
			int iTemp737 = int(fTemp735);
			fRec15[0] = (((((((fVec88[(IOTA-int((iTemp702 & 262143)))&262143] * (fTemp703 + (1 - fTemp701))) + (fVec88[(IOTA-int((int((iTemp702 + 1)) & 262143)))&262143] * (fTemp701 - fTemp703))) * (fTemp707 + ((fTemp705 - floor(fTemp705)) * (ftbl0[((iTemp706 + 1) % 65536)] - fTemp707)))) + (((fVec88[(IOTA-int((iTemp712 & 262143)))&262143] * (fTemp713 + (1 - fTemp711))) + (fVec88[(IOTA-int((int((iTemp712 + 1)) & 262143)))&262143] * (fTemp711 - fTemp713))) * (fTemp717 + ((fTemp715 - floor(fTemp715)) * (ftbl0[((iTemp716 + 1) % 65536)] - fTemp717))))) + ((fTemp722 + ((fTemp720 - floor(fTemp720)) * (ftbl0[((iTemp721 + 1) % 65536)] - fTemp722))) * (((fTemp725 - fTemp726) * fVec88[(IOTA-int((int((iTemp727 + 1)) & 262143)))&262143]) + (fVec88[(IOTA-int((iTemp727 & 262143)))&262143] * (fTemp726 + (1 - fTemp725)))))) + ((fTemp732 + ((fTemp730 - floor(fTemp730)) * (ftbl0[((iTemp731 + 1) % 65536)] - fTemp732))) * (((fTemp736 + (1 - fTemp735)) * fVec88[(IOTA-int((iTemp737 & 262143)))&262143]) + ((fTemp735 - fTemp736) * fVec88[(IOTA-int((int((iTemp737 + 1)) & 262143)))&262143])))) + (fSlow366 * fTemp695));
			double fTemp738 = (fRec158[1] + (fSlow367 / fTemp5));
			fRec158[0] = (fTemp738 - floor(fTemp738));
			double fTemp739 = (fRec158[0] + (0.5 - floor((fRec158[0] + 0.5))));
			fVec93[0] = fTemp739;
			int iTemp740 = (fVec93[0] > 0.001);
			int iTemp741 = (fVec93[1] <= 0.001);
			fRec159[0] = ((fRec159[1] * (1 - (iTemp740 * iTemp741))) + ((fRec20[0] * iTemp740) * iTemp741));
			double fTemp742 = (fConst5 * (fVec93[0] * fRec159[0]));
			double fTemp743 = floor(fTemp742);
			fRec160[0] = (fSlow384 + (fSlow5 * fRec160[1]));
			double fTemp744 = (((((((((((((((((fSlow368 * fTemp21) + (fSlow369 * fTemp24)) + (fSlow370 * fTemp22)) + (fSlow371 * fTemp23)) + (fSlow372 * fTemp20)) + (fSlow373 * fTemp35)) + (fSlow374 * fTemp36)) + (fSlow375 * fTemp34)) + (fSlow376 * fTemp33)) + (fSlow377 * fTemp32)) + (fSlow378 * fTemp31)) + (fSlow379 * fTemp30)) + (fSlow380 * fTemp29)) + (fSlow381 * fTemp28)) + (fSlow382 * fTemp27)) + (fSlow383 * fTemp26)) + (fTemp25 * fRec160[0]));
			fVec94[IOTA&1048575] = fTemp744;
			iRec161[0] = ((iTemp40 * iRec161[1]) + (iSlow385 * iTemp39));
			iRec162[0] = ((iTemp43 * iRec162[1]) + (iSlow385 * iTemp42));
			double fTemp745 = ((0.5 * (fVec94[(IOTA-int((int(iRec161[0]) & 1048575)))&1048575] * fVec2[0])) + (fVec94[(IOTA-int((int(iRec162[0]) & 1048575)))&1048575] * fVec4[0]));
			int iTemp746 = (fTemp745 > 1);
			int iTemp747 = (fTemp745 < -1);
			double fTemp748 = ((iTemp746 + ((fTemp745 * (1 - iTemp747)) * (1 - iTemp746))) - iTemp747);
			double fTemp749 = (fSlow40 * fTemp748);
			fVec95[IOTA&262143] = fTemp749;
			int iTemp750 = int(fTemp742);
			double fTemp751 = (0.5 * fVec93[0]);
			double fTemp752 = (65536.0 * (fTemp751 - floor(fTemp751)));
			int iTemp753 = int(fTemp752);
			double fTemp754 = ftbl0[iTemp753];
			double fTemp755 = (fRec158[0] + (0.75 - floor((fRec158[0] + 0.75))));
			fVec96[0] = fTemp755;
			int iTemp756 = (fVec96[0] > 0.001);
			int iTemp757 = (fVec96[1] <= 0.001);
			fRec163[0] = ((fRec163[1] * (1 - (iTemp756 * iTemp757))) + ((fRec20[0] * iTemp756) * iTemp757));
			double fTemp758 = (fConst5 * (fVec96[0] * fRec163[0]));
			int iTemp759 = int(fTemp758);
			double fTemp760 = floor(fTemp758);
			double fTemp761 = (0.5 * fVec96[0]);
			double fTemp762 = (65536.0 * (fTemp761 - floor(fTemp761)));
			int iTemp763 = int(fTemp762);
			double fTemp764 = ftbl0[iTemp763];
			double fTemp765 = (fRec158[0] - floor(fRec158[0]));
			fVec97[0] = fTemp765;
			int iTemp766 = (fVec97[0] > 0.001);
			int iTemp767 = (fVec97[1] <= 0.001);
			fRec164[0] = ((fRec164[1] * (1 - (iTemp766 * iTemp767))) + ((fRec20[0] * iTemp766) * iTemp767));
			double fTemp768 = (fConst5 * (fVec97[0] * fRec164[0]));
			int iTemp769 = int(fTemp768);
			double fTemp770 = floor(fTemp768);
			double fTemp771 = (0.5 * fVec97[0]);
			double fTemp772 = (65536.0 * (fTemp771 - floor(fTemp771)));
			int iTemp773 = int(fTemp772);
			double fTemp774 = ftbl0[iTemp773];
			double fTemp775 = (fRec158[0] + (0.25 - floor((fRec158[0] + 0.25))));
			fVec98[0] = fTemp775;
			int iTemp776 = (fVec98[0] > 0.001);
			int iTemp777 = (fVec98[1] <= 0.001);
			fRec165[0] = ((fRec165[1] * (1 - (iTemp776 * iTemp777))) + ((fRec20[0] * iTemp776) * iTemp777));
			double fTemp778 = (fConst5 * (fVec98[0] * fRec165[0]));
			int iTemp779 = int(fTemp778);
			double fTemp780 = floor(fTemp778);
			double fTemp781 = (0.5 * fVec98[0]);
			double fTemp782 = (65536.0 * (fTemp781 - floor(fTemp781)));
			int iTemp783 = int(fTemp782);
			double fTemp784 = ftbl0[iTemp783];
			fRec16[0] = ((((((((fTemp743 + (1 - fTemp742)) * fVec95[(IOTA-int((iTemp750 & 262143)))&262143]) + (fVec95[(IOTA-int((int((iTemp750 + 1)) & 262143)))&262143] * (fTemp742 - fTemp743))) * (fTemp754 + ((fTemp752 - floor(fTemp752)) * (ftbl0[((iTemp753 + 1) % 65536)] - fTemp754)))) + (((fVec95[(IOTA-int((iTemp759 & 262143)))&262143] * (fTemp760 + (1 - fTemp758))) + (fVec95[(IOTA-int((int((iTemp759 + 1)) & 262143)))&262143] * (fTemp758 - fTemp760))) * (fTemp764 + ((fTemp762 - floor(fTemp762)) * (ftbl0[((iTemp763 + 1) % 65536)] - fTemp764))))) + (fSlow386 * fTemp748)) + (((fVec95[(IOTA-int((iTemp769 & 262143)))&262143] * (fTemp770 + (1 - fTemp768))) + (fVec95[(IOTA-int((int((iTemp769 + 1)) & 262143)))&262143] * (fTemp768 - fTemp770))) * (fTemp774 + ((fTemp772 - floor(fTemp772)) * (ftbl0[((iTemp773 + 1) % 65536)] - fTemp774))))) + (((fVec95[(IOTA-int((iTemp779 & 262143)))&262143] * (fTemp780 + (1 - fTemp778))) + (fVec95[(IOTA-int((int((iTemp779 + 1)) & 262143)))&262143] * (fTemp778 - fTemp780))) * (fTemp784 + ((fTemp782 - floor(fTemp782)) * (ftbl0[((iTemp783 + 1) % 65536)] - fTemp784)))));
			fRec166[0] = (fSlow387 + (fSlow5 * fRec166[1]));
			double fTemp785 = (fRec4[0] * fRec166[0]);
			fRec167[0] = (fSlow393 + (fSlow5 * fRec167[1]));
			double fTemp786 = (fRec11[0] * fRec167[0]);
			fRec168[0] = (fSlow399 + (fSlow5 * fRec168[1]));
			double fTemp787 = (fRec9[0] * fRec168[0]);
			fRec169[0] = (fSlow405 + (fSlow5 * fRec169[1]));
			double fTemp788 = (fRec13[0] * fRec169[0]);
			fRec170[0] = (fSlow411 + (fSlow5 * fRec170[1]));
			double fTemp789 = (fRec2[0] * fRec170[0]);
			fRec171[0] = (fSlow417 + (fSlow5 * fRec171[1]));
			double fTemp790 = (fRec16[0] * fRec171[0]);
			fRec172[0] = (fSlow423 + (fSlow5 * fRec172[1]));
			double fTemp791 = (fRec1[0] * fRec172[0]);
			fRec173[0] = (fSlow429 + (fSlow5 * fRec173[1]));
			double fTemp792 = (fRec5[0] * fRec173[0]);
			fRec174[0] = (fSlow435 + (fSlow5 * fRec174[1]));
			double fTemp793 = (fRec10[0] * fRec174[0]);
			fRec175[0] = (fSlow441 + (fSlow5 * fRec175[1]));
			double fTemp794 = (fRec8[0] * fRec175[0]);
			fRec176[0] = (fSlow447 + (fSlow5 * fRec176[1]));
			double fTemp795 = (fRec14[0] * fRec176[0]);
			fRec177[0] = (fSlow453 + (fSlow5 * fRec177[1]));
			double fTemp796 = (fRec12[0] * fRec177[0]);
			fRec178[0] = (fSlow459 + (fSlow5 * fRec178[1]));
			double fTemp797 = (fRec6[0] * fRec178[0]);
			fRec179[0] = (fSlow465 + (fSlow5 * fRec179[1]));
			double fTemp798 = (fRec3[0] * fRec179[0]);
			fRec180[0] = (fSlow471 + (fSlow5 * fRec180[1]));
			double fTemp799 = (fRec15[0] * fRec180[0]);
			fRec181[0] = (fSlow477 + (fSlow5 * fRec181[1]));
			double fTemp800 = (fRec7[0] * fRec181[0]);
			fRec182[0] = (fSlow478 + (fSlow5 * fRec182[1]));
			int iTemp801 = (fRec182[0] > -127.0);
			double fTemp802 = pow(10,(0.05 * fRec182[0]));
			output0[i] = (FAUSTFLOAT)((((((((((((((fSlow4 * fTemp3) + ((fSlow12 * fTemp785) + ((fSlow392 * fTemp786) + ((fSlow398 * fTemp787) + ((fSlow404 * fTemp788) + ((fSlow410 * fTemp789) + (fSlow416 * fTemp790))))))) + (fSlow422 * fTemp791)) + (fSlow428 * fTemp792)) + (fSlow434 * fTemp793)) + (fSlow440 * fTemp794)) + (fSlow446 * fTemp795)) + (fSlow452 * fTemp796)) + (fSlow458 * fTemp797)) + (fSlow464 * fTemp798)) + (fSlow470 * fTemp799)) + (fSlow476 * fTemp800)) * iTemp801) * fTemp802);
			double fTemp803 = (((((((((((((((((fSlow472 * fTemp800) + (fSlow421 * fTemp791)) + (fSlow427 * fTemp792)) + (fSlow463 * fTemp798)) + (fSlow11 * fTemp785)) + (fSlow457 * fTemp797)) + (fSlow406 * fTemp789)) + (fSlow439 * fTemp794)) + (fSlow397 * fTemp787)) + (fSlow433 * fTemp793)) + (fSlow391 * fTemp786)) + (fSlow451 * fTemp796)) + (fSlow400 * fTemp788)) + (fSlow445 * fTemp795)) + (fSlow466 * fTemp799)) + (fSlow415 * fTemp790)) + (fSlow3 * fTemp3));
			fRec183[0] = (fSlow484 + (fRec183[1] - floor((fSlow484 + fRec183[1]))));
			double fTemp804 = (fSlow482 + (iSlow483 * fmod((fSlow481 + fRec183[0]),1)));
			double fTemp805 = (6.283185307179586 * fTemp804);
			double fTemp806 = (((((((((((((((((fSlow473 * fTemp800) + (fSlow407 * fTemp789)) + (fSlow426 * fTemp792)) + (fSlow420 * fTemp791)) + (fSlow462 * fTemp798)) + (fSlow456 * fTemp797)) + (fSlow10 * fTemp785)) + (fSlow438 * fTemp794)) + (fSlow396 * fTemp787)) + (fSlow432 * fTemp793)) + (fSlow390 * fTemp786)) + (fSlow450 * fTemp796)) + (fSlow401 * fTemp788)) + (fSlow444 * fTemp795)) + (fSlow467 * fTemp799)) + (fSlow414 * fTemp790)) + (fSlow2 * fTemp3));
			fRec184[0] = (fSlow490 + (fRec184[1] - floor((fSlow490 + fRec184[1]))));
			double fTemp807 = (fSlow488 + (iSlow489 * fmod((fSlow487 + fRec184[0]),1)));
			double fTemp808 = (6.283185307179586 * fTemp807);
			double fTemp809 = (((((((((((((((((fSlow419 * fTemp791) + (fSlow408 * fTemp789)) + (fSlow461 * fTemp798)) + (fSlow9 * fTemp785)) + (fSlow425 * fTemp792)) + (fSlow455 * fTemp797)) + (fSlow474 * fTemp800)) + (fSlow437 * fTemp794)) + (fSlow395 * fTemp787)) + (fSlow431 * fTemp793)) + (fSlow389 * fTemp786)) + (fSlow449 * fTemp796)) + (fSlow402 * fTemp788)) + (fSlow443 * fTemp795)) + (fSlow468 * fTemp799)) + (fSlow413 * fTemp790)) + (fSlow1 * fTemp3));
			fRec185[0] = (fSlow496 + (fRec185[1] - floor((fSlow496 + fRec185[1]))));
			double fTemp810 = (fSlow494 + (iSlow495 * fmod((fSlow493 + fRec185[0]),1)));
			double fTemp811 = (6.283185307179586 * fTemp810);
			double fTemp812 = (((((((((((((((((fSlow418 * fTemp791) + (fSlow409 * fTemp789)) + (fSlow460 * fTemp798)) + (fSlow8 * fTemp785)) + (fSlow424 * fTemp792)) + (fSlow454 * fTemp797)) + (fSlow475 * fTemp800)) + (fSlow436 * fTemp794)) + (fSlow394 * fTemp787)) + (fSlow430 * fTemp793)) + (fSlow388 * fTemp786)) + (fSlow448 * fTemp796)) + (fSlow403 * fTemp788)) + (fSlow442 * fTemp795)) + (fSlow469 * fTemp799)) + (fSlow412 * fTemp790)) + (fSlow0 * fTemp3));
			fRec186[0] = (fSlow518 + (fRec186[1] - floor((fSlow518 + fRec186[1]))));
			double fTemp813 = (fSlow516 + (iSlow517 * fmod((fSlow515 + fRec186[0]),1)));
			double fTemp814 = (6.283185307179586 * fTemp813);
			double fTemp815 = (iTemp1 * fTemp2);
			fRec187[0] = (fSlow520 + (fSlow5 * fRec187[1]));
			fRec188[0] = (fSlow521 + (fRec188[1] - floor((fSlow521 + fRec188[1]))));
			double fTemp816 = (0.5 * fRec188[0]);
			double fTemp817 = (65536.0 * (fTemp816 - floor(fTemp816)));
			int iTemp818 = int(fTemp817);
			double fTemp819 = ftbl0[iTemp818];
			double fTemp820 = (((fRec187[0] > -127.0) * pow(10,(0.05 * fRec187[0]))) * (fTemp819 + ((fTemp817 - floor(fTemp817)) * (ftbl0[((iTemp818 + 1) % 65536)] - fTemp819))));
			int iTemp821 = ((fRec188[0] > 0.001) * (fRec188[1] <= 0.001));
			int iTemp822 = (1 - iTemp821);
			int iTemp823 = (1103515245 * (iRec190[1] + 12345));
			int iTemp824 = (1103515245 * (iTemp823 + 12345));
			int iTemp825 = (1103515245 * (iTemp824 + 12345));
			int iTemp826 = (1103515245 * (iTemp825 + 12345));
			int iTemp827 = (1103515245 * (iTemp826 + 12345));
			iRec190[0] = (1103515245 * (iTemp827 + 12345));
			int 	iRec191 = iTemp827;
			int 	iRec192 = iTemp826;
			int 	iRec193 = iTemp825;
			int 	iRec194 = iTemp824;
			int 	iRec195 = iTemp823;
			iRec189[0] = ((iRec189[1] * iTemp822) + (iTemp821 * ((4.656612875245797e-10 * iRec190[0]) > fSlow522)));
			output1[i] = (FAUSTFLOAT)(((((((((((((((((((((((fTemp803 * sin(fTemp805)) + (fTemp806 * sin(fTemp808))) + (fTemp809 * sin(fTemp811))) + (fSlow497 * fTemp798)) + (fSlow498 * fTemp791)) + (fSlow499 * fTemp789)) + (fSlow500 * fTemp785)) + (fSlow501 * fTemp792)) + (fSlow502 * fTemp797)) + (fSlow503 * fTemp800)) + (fSlow504 * fTemp794)) + (fSlow505 * fTemp787)) + (fSlow506 * fTemp793)) + (fSlow507 * fTemp786)) + (fSlow508 * fTemp796)) + (fSlow509 * fTemp788)) + (fSlow510 * fTemp795)) + (fSlow511 * fTemp799)) + (fSlow512 * fTemp790)) + (fTemp812 * sin(fTemp814))) + (fTemp0 * ((fSlow519 * fTemp815) + (fTemp820 * iRec189[0])))) * iTemp801) * fTemp802);
			iRec196[0] = ((iTemp822 * iRec196[1]) + (iTemp821 * ((4.656612875245797e-10 * iRec191) > fSlow522)));
			output2[i] = (FAUSTFLOAT)(((((((((((((((((((((((fTemp803 * cos(fTemp805)) + (fTemp806 * cos(fTemp808))) + (fTemp809 * cos(fTemp811))) + (fSlow523 * fTemp796)) + (fSlow524 * fTemp786)) + (fSlow525 * fTemp797)) + (fSlow526 * fTemp792)) + (fSlow527 * fTemp785)) + (fSlow528 * fTemp798)) + (fSlow529 * fTemp789)) + (fSlow530 * fTemp793)) + (fSlow531 * fTemp791)) + (fSlow532 * fTemp800)) + (fSlow533 * fTemp787)) + (fSlow534 * fTemp794)) + (fSlow535 * fTemp788)) + (fSlow536 * fTemp795)) + (fSlow537 * fTemp799)) + (fSlow538 * fTemp790)) + (fTemp812 * cos(fTemp814))) + (fTemp0 * ((fSlow539 * fTemp815) + (fTemp820 * iRec196[0])))) * iTemp801) * fTemp802);
			double fTemp828 = (12.566370614359172 * fTemp804);
			double fTemp829 = (12.566370614359172 * fTemp807);
			double fTemp830 = (12.566370614359172 * fTemp810);
			double fTemp831 = (12.566370614359172 * fTemp813);
			iRec197[0] = ((iTemp822 * iRec197[1]) + (iTemp821 * ((4.656612875245797e-10 * iRec192) > fSlow522)));
			output3[i] = (FAUSTFLOAT)(((((((((((((((((((((((fTemp803 * sin(fTemp828)) + (fTemp806 * sin(fTemp829))) + (fTemp809 * sin(fTemp830))) + (fSlow540 * fTemp796)) + (fSlow541 * fTemp800)) + (fSlow542 * fTemp797)) + (fSlow543 * fTemp792)) + (fSlow544 * fTemp785)) + (fSlow545 * fTemp793)) + (fSlow546 * fTemp794)) + (fSlow547 * fTemp791)) + (fSlow548 * fTemp789)) + (fSlow549 * fTemp787)) + (fSlow550 * fTemp798)) + (fSlow551 * fTemp786)) + (fSlow552 * fTemp788)) + (fSlow553 * fTemp795)) + (fSlow554 * fTemp799)) + (fSlow555 * fTemp790)) + (fTemp812 * sin(fTemp831))) + (fTemp0 * ((fSlow556 * fTemp815) + (fTemp820 * iRec197[0])))) * iTemp801) * fTemp802);
			iRec198[0] = ((iTemp822 * iRec198[1]) + (iTemp821 * ((4.656612875245797e-10 * iRec193) > fSlow522)));
			output4[i] = (FAUSTFLOAT)(((((((((((((((((((((((fTemp803 * cos(fTemp828)) + (fTemp806 * cos(fTemp829))) + (fTemp0 * ((fSlow557 * fTemp815) + (fTemp820 * iRec198[0])))) + (fTemp809 * cos(fTemp830))) + (fSlow558 * fTemp796)) + (fSlow559 * fTemp800)) + (fSlow560 * fTemp797)) + (fSlow561 * fTemp792)) + (fSlow562 * fTemp785)) + (fSlow563 * fTemp793)) + (fSlow564 * fTemp794)) + (fSlow565 * fTemp791)) + (fSlow566 * fTemp789)) + (fSlow567 * fTemp787)) + (fSlow568 * fTemp798)) + (fSlow569 * fTemp786)) + (fSlow570 * fTemp788)) + (fSlow571 * fTemp795)) + (fSlow572 * fTemp799)) + (fSlow573 * fTemp790)) + (fTemp812 * cos(fTemp831))) * iTemp801) * fTemp802);
			double fTemp832 = (18.84955592153876 * fTemp807);
			double fTemp833 = (18.84955592153876 * fTemp804);
			double fTemp834 = (18.84955592153876 * fTemp810);
			double fTemp835 = (18.84955592153876 * fTemp813);
			iRec199[0] = ((iTemp821 * ((4.656612875245797e-10 * iRec194) > fSlow522)) + (iTemp822 * iRec199[1]));
			output5[i] = (FAUSTFLOAT)((iTemp801 * fTemp802) * ((fTemp806 * sin(fTemp832)) + ((fTemp803 * sin(fTemp833)) + (((((((((((((((((((fTemp809 * sin(fTemp834)) + (fSlow574 * fTemp793)) + (fSlow575 * fTemp792)) + (fSlow576 * fTemp785)) + (fSlow577 * fTemp798)) + (fSlow578 * fTemp789)) + (fSlow579 * fTemp791)) + (fSlow580 * fTemp787)) + (fSlow581 * fTemp794)) + (fSlow582 * fTemp797)) + (fSlow583 * fTemp800)) + (fSlow584 * fTemp786)) + (fSlow585 * fTemp796)) + (fSlow586 * fTemp788)) + (fSlow587 * fTemp795)) + (fSlow588 * fTemp799)) + (fSlow589 * fTemp790)) + (fTemp812 * sin(fTemp835))) + (fTemp0 * ((fSlow590 * fTemp815) + (fTemp820 * iRec199[0])))))));
			iRec200[0] = ((iTemp821 * ((4.656612875245797e-10 * iRec195) > fSlow522)) + (iTemp822 * iRec200[1]));
			output6[i] = (FAUSTFLOAT)(((((((((((((((((((((((fTemp0 * ((fSlow591 * fTemp815) + (fTemp820 * iRec200[0]))) + (fTemp809 * cos(fTemp834))) + (fSlow592 * fTemp796)) + (fSlow593 * fTemp800)) + (fSlow594 * fTemp797)) + (fSlow595 * fTemp792)) + (fSlow596 * fTemp785)) + (fSlow597 * fTemp793)) + (fSlow598 * fTemp794)) + (fSlow599 * fTemp791)) + (fSlow600 * fTemp789)) + (fSlow601 * fTemp787)) + (fSlow602 * fTemp798)) + (fSlow603 * fTemp786)) + (fSlow604 * fTemp788)) + (fSlow605 * fTemp795)) + (fSlow606 * fTemp799)) + (fSlow607 * fTemp790)) + (fTemp812 * cos(fTemp835))) + (fTemp803 * cos(fTemp833))) + (fTemp806 * cos(fTemp832))) * iTemp801) * fTemp802);
			// post processing
			iRec200[1] = iRec200[0];
			iRec199[1] = iRec199[0];
			iRec198[1] = iRec198[0];
			iRec197[1] = iRec197[0];
			iRec196[1] = iRec196[0];
			iRec189[1] = iRec189[0];
			iRec190[1] = iRec190[0];
			fRec188[1] = fRec188[0];
			fRec187[1] = fRec187[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec184[1] = fRec184[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec181[1] = fRec181[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec178[1] = fRec178[0];
			fRec177[1] = fRec177[0];
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
			fRec16[1] = fRec16[0];
			fRec165[1] = fRec165[0];
			fVec98[1] = fVec98[0];
			fRec164[1] = fRec164[0];
			fVec97[1] = fVec97[0];
			fRec163[1] = fRec163[0];
			fVec96[1] = fVec96[0];
			iRec162[1] = iRec162[0];
			iRec161[1] = iRec161[0];
			fRec160[1] = fRec160[0];
			fRec159[1] = fRec159[0];
			fVec93[1] = fVec93[0];
			fRec158[1] = fRec158[0];
			fRec15[1] = fRec15[0];
			fRec157[1] = fRec157[0];
			fVec92[1] = fVec92[0];
			fRec156[1] = fRec156[0];
			fVec91[1] = fVec91[0];
			fRec155[1] = fRec155[0];
			fVec90[1] = fVec90[0];
			fRec154[1] = fRec154[0];
			fVec89[1] = fVec89[0];
			fRec153[1] = fRec153[0];
			iRec152[1] = iRec152[0];
			iRec151[1] = iRec151[0];
			fRec150[1] = fRec150[0];
			fRec14[1] = fRec14[0];
			fRec149[1] = fRec149[0];
			fVec86[1] = fVec86[0];
			fRec148[1] = fRec148[0];
			fVec85[1] = fVec85[0];
			fRec147[1] = fRec147[0];
			fVec84[1] = fVec84[0];
			iRec146[1] = iRec146[0];
			iRec145[1] = iRec145[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fVec81[1] = fVec81[0];
			fRec142[1] = fRec142[0];
			fRec13[1] = fRec13[0];
			fRec141[1] = fRec141[0];
			fVec80[1] = fVec80[0];
			fRec140[1] = fRec140[0];
			fVec79[1] = fVec79[0];
			fRec139[1] = fRec139[0];
			fVec78[1] = fVec78[0];
			iRec138[1] = iRec138[0];
			iRec137[1] = iRec137[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fVec75[1] = fVec75[0];
			fRec134[1] = fRec134[0];
			fRec12[1] = fRec12[0];
			fRec133[1] = fRec133[0];
			fVec74[1] = fVec74[0];
			fRec132[1] = fRec132[0];
			fVec73[1] = fVec73[0];
			fRec131[1] = fRec131[0];
			fVec72[1] = fVec72[0];
			iRec130[1] = iRec130[0];
			iRec129[1] = iRec129[0];
			fRec128[1] = fRec128[0];
			fRec127[1] = fRec127[0];
			fVec69[1] = fVec69[0];
			fRec126[1] = fRec126[0];
			fRec11[1] = fRec11[0];
			fRec125[1] = fRec125[0];
			fVec68[1] = fVec68[0];
			fRec124[1] = fRec124[0];
			fVec67[1] = fVec67[0];
			fRec123[1] = fRec123[0];
			fVec66[1] = fVec66[0];
			iRec122[1] = iRec122[0];
			iRec121[1] = iRec121[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fVec63[1] = fVec63[0];
			fRec118[1] = fRec118[0];
			fRec10[1] = fRec10[0];
			fRec117[1] = fRec117[0];
			fVec62[1] = fVec62[0];
			fRec116[1] = fRec116[0];
			fVec61[1] = fVec61[0];
			fRec115[1] = fRec115[0];
			fVec60[1] = fVec60[0];
			iRec114[1] = iRec114[0];
			iRec113[1] = iRec113[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fVec57[1] = fVec57[0];
			fRec110[1] = fRec110[0];
			fRec9[1] = fRec9[0];
			fRec109[1] = fRec109[0];
			fVec56[1] = fVec56[0];
			fRec108[1] = fRec108[0];
			fVec55[1] = fVec55[0];
			fRec107[1] = fRec107[0];
			fVec54[1] = fVec54[0];
			iRec106[1] = iRec106[0];
			iRec105[1] = iRec105[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fVec51[1] = fVec51[0];
			fRec102[1] = fRec102[0];
			fRec8[1] = fRec8[0];
			fRec101[1] = fRec101[0];
			fVec50[1] = fVec50[0];
			fRec100[1] = fRec100[0];
			fVec49[1] = fVec49[0];
			fRec99[1] = fRec99[0];
			fVec48[1] = fVec48[0];
			iRec98[1] = iRec98[0];
			iRec97[1] = iRec97[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fVec45[1] = fVec45[0];
			fRec94[1] = fRec94[0];
			fRec7[1] = fRec7[0];
			fRec93[1] = fRec93[0];
			fVec44[1] = fVec44[0];
			fRec92[1] = fRec92[0];
			fVec43[1] = fVec43[0];
			fRec91[1] = fRec91[0];
			fVec42[1] = fVec42[0];
			iRec90[1] = iRec90[0];
			iRec89[1] = iRec89[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fVec39[1] = fVec39[0];
			fRec86[1] = fRec86[0];
			fRec6[1] = fRec6[0];
			fRec85[1] = fRec85[0];
			fVec38[1] = fVec38[0];
			fRec84[1] = fRec84[0];
			fVec37[1] = fVec37[0];
			fRec83[1] = fRec83[0];
			fVec36[1] = fVec36[0];
			iRec82[1] = iRec82[0];
			iRec81[1] = iRec81[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fVec33[1] = fVec33[0];
			fRec78[1] = fRec78[0];
			fRec5[1] = fRec5[0];
			fRec77[1] = fRec77[0];
			fVec32[1] = fVec32[0];
			fRec76[1] = fRec76[0];
			fVec31[1] = fVec31[0];
			fRec75[1] = fRec75[0];
			fVec30[1] = fVec30[0];
			iRec74[1] = iRec74[0];
			iRec73[1] = iRec73[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fVec27[1] = fVec27[0];
			fRec70[1] = fRec70[0];
			fRec4[1] = fRec4[0];
			fRec69[1] = fRec69[0];
			fVec26[1] = fVec26[0];
			fRec68[1] = fRec68[0];
			fVec25[1] = fVec25[0];
			fRec67[1] = fRec67[0];
			fVec24[1] = fVec24[0];
			iRec66[1] = iRec66[0];
			iRec65[1] = iRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fVec21[1] = fVec21[0];
			fRec62[1] = fRec62[0];
			fRec3[1] = fRec3[0];
			fRec61[1] = fRec61[0];
			fVec20[1] = fVec20[0];
			fRec60[1] = fRec60[0];
			fVec19[1] = fVec19[0];
			fRec59[1] = fRec59[0];
			fVec18[1] = fVec18[0];
			iRec58[1] = iRec58[0];
			iRec57[1] = iRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fVec15[1] = fVec15[0];
			fRec54[1] = fRec54[0];
			fRec2[1] = fRec2[0];
			fRec53[1] = fRec53[0];
			fVec14[1] = fVec14[0];
			fRec52[1] = fRec52[0];
			fVec13[1] = fVec13[0];
			fRec51[1] = fRec51[0];
			fVec12[1] = fVec12[0];
			iRec50[1] = iRec50[0];
			iRec49[1] = iRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fVec9[1] = fVec9[0];
			fRec46[1] = fRec46[0];
			fRec1[1] = fRec1[0];
			fRec45[1] = fRec45[0];
			fVec8[1] = fVec8[0];
			fRec44[1] = fRec44[0];
			fVec7[1] = fVec7[0];
			fRec43[1] = fRec43[0];
			fVec6[1] = fVec6[0];
			iRec42[1] = iRec42[0];
			fVec4[1] = fVec4[0];
			iRec41[1] = iRec41[0];
			IOTA = IOTA+1;
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
			fVec2[1] = fVec2[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fVec1[1] = fVec1[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
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

#define EXTERNAL_VERSION "0.60"

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
        virtual bool run() { return false; };
    
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
    
        // -- metadata declarations

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

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
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
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
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

        virtual void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        virtual void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return true; }
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
            LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(log(std::max<double>(x, DBL_MIN))); }

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
        nvoices = atoi(numVoices.c_str());
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
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
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
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*log(v)/log(2)+2)/4*16383);
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
        
        void modifyZone(int v) 	
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
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
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
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
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
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAddress(int index)
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
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
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

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (strtod(s.c_str(), NULL)); }

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
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
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
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
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

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
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
        virtual void init(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceInit(int samplingRate) {}
        virtual void instanceConstants(int samplingRate) {}
        virtual void instanceResetUserInterface() {}
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

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
{
    return 440.0 * pow(2.0, (note-69.0)/12.0);
}

static inline unsigned int isPowerOfTwo(unsigned int n)
{
    return !(n & (n - 1));
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

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control

    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            FAUSTFLOAT** inputs_slice = (FAUSTFLOAT**)alloca(getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumInputs(); chan++) {
                inputs_slice[chan] = &(inputs[chan][offset]);
            }

            FAUSTFLOAT** outputs_slice = (FAUSTFLOAT**)alloca(getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                outputs_slice[chan] = &(outputs[chan][offset]);
            }

            compute(slice, inputs_slice, outputs_slice);
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
        for (int i = 0; i < fVoiceTable.size(); i++) {
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
        for (int i = 0; i < fVoiceTable.size(); i++) {
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

            // In not group, also add individual voices UI
            if (!fGroupControl) {
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 31, ((fVoiceTable.size() < 8) ? "Voice%d" : "V%d"), i+1);
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
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public decorator_dsp, public dsp_voice_group, public midi {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }

        inline int getVoice(int note, bool steal = false)
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == note) {
                    if (steal) {
                        fVoiceTable[i]->fDate = fDate++;
                    }
                    return i;
                }
            }

            if (steal) {
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
                        }
                    }
                }

                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    fVoiceTable[voice_release]->fDate = fDate++;
                    fVoiceTable[voice_release]->fTrigger = true;
                    return voice_release;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    fVoiceTable[voice_playing]->fDate = fDate++;
                    fVoiceTable[voice_playing]->fTrigger = true;
                    return voice_playing;
                } else {
                    assert(false);
                    return kNoVoice;
                }

            } else {
                return kNoVoice;
            }
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
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
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true):decorator_dsp(dsp), dsp_voice_group(panic, this, control, group)
        {
            fDate = 0;

            // Create voices
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
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }

        void instanceInit(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceInit(samplingRate);
            }
        }

        void instanceConstants(int samplingRate)
        {
            // Init voices
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), fVoiceTable.size(), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
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
                for (int i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[newVoiceAux()];
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

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = newVoiceAux();
                fVoiceTable[voice]->keyOn(pitch, velocity);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getVoice(pitch);
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

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (int i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
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
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            obj->m_dsp = dsp_poly;
        #endif
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_midiHandler->addMidiIn(dsp_poly);
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
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2017 Grame");
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




