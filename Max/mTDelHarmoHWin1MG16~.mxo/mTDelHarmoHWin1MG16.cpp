/* ------------------------------------------------------------
name: "mTDelHarmoHWin1MG16"
Code generated with Faust 2.0.a56 (http://faust.grame.fr)
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

//----------------------------------------------------------------
//  BaseUI with empty methods
//----------------------------------------------------------------

class BaseUI : public UI
{
    
    public:
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        
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
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }

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

#include <string>

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
    
        /** Global init, calls the following methods :
         * - static class 'classInit' : static table initialisation
         * - 'instanceInit' : constants and instance table initialisation
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
 * DSP factory class
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual dsp* createDSPInstance() = 0;
    
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

#include <math.h>

double sin(double dummy0);

class mydspSIG0 {
	
  private:
	
	int iRec72[2];
	
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
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			iRec72[l60] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, double* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec72[0] = (iRec72[1] + 1);
			output[i] = sin((9.5873799242852573e-05 * double((iRec72[0] + -1))));
			iRec72[1] = iRec72[0];
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

double exp(double dummy0);
double floor(double dummy0);
double pow(double dummy0, double dummy1);
static double ftbl0mydspSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
	
 private:
	
	int IOTA;
	int fSamplingFreq;
	double fVec0[1048576];
	double fVec7[1048576];
	double fVec14[1048576];
	double fVec20[1048576];
	double fVec26[1048576];
	double fVec31[1048576];
	double fVec37[1048576];
	double fVec43[1048576];
	double fVec49[1048576];
	double fVec55[1048576];
	double fVec61[1048576];
	double fVec67[1048576];
	double fVec73[1048576];
	double fVec79[1048576];
	double fVec85[1048576];
	double fVec91[1048576];
	double fVec1[262144];
	double fVec8[262144];
	double fVec15[262144];
	double fVec21[262144];
	double fVec27[262144];
	double fVec32[262144];
	double fVec38[262144];
	double fVec44[262144];
	double fVec50[262144];
	double fVec56[262144];
	double fVec62[262144];
	double fVec68[262144];
	double fVec74[262144];
	double fVec80[262144];
	double fVec86[262144];
	double fVec92[262144];
	double fRec16[2];
	double fRec17[2];
	double fRec18[2];
	double fRec19[2];
	double fRec20[2];
	double fRec21[2];
	double fRec22[2];
	double fRec23[2];
	double fRec24[2];
	double fRec25[2];
	double fRec26[2];
	double fRec27[2];
	double fRec28[2];
	double fRec29[2];
	double fRec30[2];
	double fRec31[2];
	double fRec32[2];
	double fRec33[2];
	double fRec34[2];
	double fRec35[2];
	double fRec36[2];
	double fRec37[2];
	double fRec38[2];
	double fRec39[2];
	double fRec40[2];
	double fRec41[2];
	double fRec42[2];
	double fRec43[2];
	double fRec44[2];
	double fRec45[2];
	double fRec46[2];
	double fRec47[2];
	double fRec48[2];
	double fRec49[2];
	double fRec50[2];
	double fRec51[2];
	double fRec52[2];
	double fRec53[2];
	double fRec54[2];
	double fRec55[2];
	double fRec56[2];
	double fRec57[2];
	double fRec58[2];
	double fRec59[2];
	double fRec60[2];
	double fRec61[2];
	double fRec62[2];
	double fRec63[2];
	double fRec64[2];
	double fRec65[2];
	double fRec67[2];
	double fVec2[2];
	double fRec69[2];
	double fRec70[2];
	double fRec68[2];
	double fRec66[2];
	double fVec3[2];
	double fRec71[2];
	double fVec4[2];
	double fRec73[2];
	double fVec5[2];
	double fRec74[2];
	double fVec6[2];
	double fRec75[2];
	double fRec0[2];
	double fRec76[2];
	double fRec77[2];
	double fRec78[2];
	double fRec79[2];
	double fRec80[2];
	double fRec81[2];
	double fRec82[2];
	double fRec83[2];
	double fRec84[2];
	double fRec85[2];
	double fRec86[2];
	double fRec87[2];
	double fRec88[2];
	double fRec89[2];
	double fRec90[2];
	double fRec91[2];
	double fRec92[2];
	double fRec93[2];
	double fRec95[2];
	double fRec94[2];
	double fVec9[2];
	double fRec96[2];
	double fVec10[2];
	double fRec97[2];
	double fVec11[2];
	double fRec98[2];
	double fVec12[2];
	double fRec99[2];
	double fRec1[2];
	double fRec101[2];
	double fRec100[2];
	double fVec13[2];
	double fRec102[2];
	double fRec103[2];
	double fRec104[2];
	double fRec105[2];
	double fRec106[2];
	double fRec107[2];
	double fRec108[2];
	double fRec109[2];
	double fRec110[2];
	double fRec111[2];
	double fRec112[2];
	double fRec113[2];
	double fRec114[2];
	double fRec115[2];
	double fRec116[2];
	double fRec117[2];
	double fRec118[2];
	double fRec119[2];
	double fRec120[2];
	double fVec16[2];
	double fRec121[2];
	double fVec17[2];
	double fRec122[2];
	double fVec18[2];
	double fRec123[2];
	double fRec2[2];
	double fRec125[2];
	double fRec124[2];
	double fVec19[2];
	double fRec126[2];
	double fRec127[2];
	double fRec128[2];
	double fRec129[2];
	double fRec130[2];
	double fRec131[2];
	double fRec132[2];
	double fRec133[2];
	double fRec134[2];
	double fRec135[2];
	double fRec136[2];
	double fRec137[2];
	double fRec138[2];
	double fRec139[2];
	double fRec140[2];
	double fRec141[2];
	double fRec142[2];
	double fRec143[2];
	double fRec144[2];
	double fVec22[2];
	double fRec145[2];
	double fVec23[2];
	double fRec146[2];
	double fVec24[2];
	double fRec147[2];
	double fRec3[2];
	double fRec149[2];
	double fRec148[2];
	double fVec25[2];
	double fRec150[2];
	double fRec151[2];
	double fRec152[2];
	double fRec153[2];
	double fRec154[2];
	double fRec155[2];
	double fRec156[2];
	double fRec157[2];
	double fRec158[2];
	double fRec159[2];
	double fRec160[2];
	double fRec161[2];
	double fRec162[2];
	double fRec163[2];
	double fRec164[2];
	double fRec165[2];
	double fRec166[2];
	double fRec167[2];
	double fRec168[2];
	double fVec28[2];
	double fRec169[2];
	double fVec29[2];
	double fRec170[2];
	double fVec30[2];
	double fRec171[2];
	double fRec4[2];
	double fRec172[2];
	double fRec173[2];
	double fRec174[2];
	double fRec175[2];
	double fRec176[2];
	double fRec177[2];
	double fRec178[2];
	double fRec179[2];
	double fRec180[2];
	double fRec181[2];
	double fRec182[2];
	double fRec183[2];
	double fRec184[2];
	double fRec185[2];
	double fRec186[2];
	double fRec187[2];
	double fRec188[2];
	double fRec189[2];
	double fRec191[2];
	double fRec190[2];
	double fVec33[2];
	double fRec192[2];
	double fVec34[2];
	double fRec193[2];
	double fVec35[2];
	double fRec194[2];
	double fVec36[2];
	double fRec195[2];
	double fRec5[2];
	double fRec196[2];
	double fRec197[2];
	double fRec198[2];
	double fRec199[2];
	double fRec200[2];
	double fRec201[2];
	double fRec202[2];
	double fRec203[2];
	double fRec204[2];
	double fRec205[2];
	double fRec206[2];
	double fRec207[2];
	double fRec208[2];
	double fRec209[2];
	double fRec210[2];
	double fRec211[2];
	double fRec212[2];
	double fRec213[2];
	double fRec215[2];
	double fRec214[2];
	double fVec39[2];
	double fRec216[2];
	double fVec40[2];
	double fRec217[2];
	double fVec41[2];
	double fRec218[2];
	double fVec42[2];
	double fRec219[2];
	double fRec6[2];
	double fRec220[2];
	double fRec221[2];
	double fRec222[2];
	double fRec223[2];
	double fRec224[2];
	double fRec225[2];
	double fRec226[2];
	double fRec227[2];
	double fRec228[2];
	double fRec229[2];
	double fRec230[2];
	double fRec231[2];
	double fRec232[2];
	double fRec233[2];
	double fRec234[2];
	double fRec235[2];
	double fRec236[2];
	double fRec237[2];
	double fRec239[2];
	double fRec238[2];
	double fVec45[2];
	double fRec240[2];
	double fVec46[2];
	double fRec241[2];
	double fVec47[2];
	double fRec242[2];
	double fVec48[2];
	double fRec243[2];
	double fRec7[2];
	double fRec244[2];
	double fRec245[2];
	double fRec246[2];
	double fRec247[2];
	double fRec248[2];
	double fRec249[2];
	double fRec250[2];
	double fRec251[2];
	double fRec252[2];
	double fRec253[2];
	double fRec254[2];
	double fRec255[2];
	double fRec256[2];
	double fRec257[2];
	double fRec258[2];
	double fRec259[2];
	double fRec260[2];
	double fRec261[2];
	double fRec263[2];
	double fRec262[2];
	double fVec51[2];
	double fRec264[2];
	double fVec52[2];
	double fRec265[2];
	double fVec53[2];
	double fRec266[2];
	double fVec54[2];
	double fRec267[2];
	double fRec8[2];
	double fRec268[2];
	double fRec269[2];
	double fRec270[2];
	double fRec271[2];
	double fRec272[2];
	double fRec273[2];
	double fRec274[2];
	double fRec275[2];
	double fRec276[2];
	double fRec277[2];
	double fRec278[2];
	double fRec279[2];
	double fRec280[2];
	double fRec281[2];
	double fRec282[2];
	double fRec283[2];
	double fRec284[2];
	double fRec285[2];
	double fRec287[2];
	double fRec286[2];
	double fVec57[2];
	double fRec288[2];
	double fVec58[2];
	double fRec289[2];
	double fVec59[2];
	double fRec290[2];
	double fVec60[2];
	double fRec291[2];
	double fRec9[2];
	double fRec292[2];
	double fRec293[2];
	double fRec294[2];
	double fRec295[2];
	double fRec296[2];
	double fRec297[2];
	double fRec298[2];
	double fRec299[2];
	double fRec300[2];
	double fRec301[2];
	double fRec302[2];
	double fRec303[2];
	double fRec304[2];
	double fRec305[2];
	double fRec306[2];
	double fRec307[2];
	double fRec308[2];
	double fRec309[2];
	double fRec311[2];
	double fRec310[2];
	double fVec63[2];
	double fRec312[2];
	double fVec64[2];
	double fRec313[2];
	double fVec65[2];
	double fRec314[2];
	double fVec66[2];
	double fRec315[2];
	double fRec10[2];
	double fRec316[2];
	double fRec317[2];
	double fRec318[2];
	double fRec319[2];
	double fRec320[2];
	double fRec321[2];
	double fRec322[2];
	double fRec323[2];
	double fRec324[2];
	double fRec325[2];
	double fRec326[2];
	double fRec327[2];
	double fRec328[2];
	double fRec329[2];
	double fRec330[2];
	double fRec331[2];
	double fRec332[2];
	double fRec333[2];
	double fRec335[2];
	double fRec334[2];
	double fVec69[2];
	double fRec336[2];
	double fVec70[2];
	double fRec337[2];
	double fVec71[2];
	double fRec338[2];
	double fVec72[2];
	double fRec339[2];
	double fRec11[2];
	double fRec340[2];
	double fRec341[2];
	double fRec342[2];
	double fRec343[2];
	double fRec344[2];
	double fRec345[2];
	double fRec346[2];
	double fRec347[2];
	double fRec348[2];
	double fRec349[2];
	double fRec350[2];
	double fRec351[2];
	double fRec352[2];
	double fRec353[2];
	double fRec354[2];
	double fRec355[2];
	double fRec356[2];
	double fRec357[2];
	double fRec359[2];
	double fRec358[2];
	double fVec75[2];
	double fRec360[2];
	double fVec76[2];
	double fRec361[2];
	double fVec77[2];
	double fRec362[2];
	double fVec78[2];
	double fRec363[2];
	double fRec12[2];
	double fRec364[2];
	double fRec365[2];
	double fRec366[2];
	double fRec367[2];
	double fRec368[2];
	double fRec369[2];
	double fRec370[2];
	double fRec371[2];
	double fRec372[2];
	double fRec373[2];
	double fRec374[2];
	double fRec375[2];
	double fRec376[2];
	double fRec377[2];
	double fRec378[2];
	double fRec379[2];
	double fRec380[2];
	double fRec381[2];
	double fRec383[2];
	double fRec382[2];
	double fVec81[2];
	double fRec384[2];
	double fVec82[2];
	double fRec385[2];
	double fVec83[2];
	double fRec386[2];
	double fVec84[2];
	double fRec387[2];
	double fRec13[2];
	double fRec388[2];
	double fRec389[2];
	double fRec390[2];
	double fRec391[2];
	double fRec392[2];
	double fRec393[2];
	double fRec394[2];
	double fRec395[2];
	double fRec396[2];
	double fRec397[2];
	double fRec398[2];
	double fRec399[2];
	double fRec400[2];
	double fRec401[2];
	double fRec402[2];
	double fRec403[2];
	double fRec404[2];
	double fRec405[2];
	double fRec407[2];
	double fRec406[2];
	double fVec87[2];
	double fRec408[2];
	double fVec88[2];
	double fRec409[2];
	double fVec89[2];
	double fRec410[2];
	double fVec90[2];
	double fRec411[2];
	double fRec14[2];
	double fRec412[2];
	double fRec413[2];
	double fRec414[2];
	double fRec415[2];
	double fRec416[2];
	double fRec417[2];
	double fRec418[2];
	double fRec419[2];
	double fRec420[2];
	double fRec421[2];
	double fRec422[2];
	double fRec423[2];
	double fRec424[2];
	double fRec425[2];
	double fRec426[2];
	double fRec427[2];
	double fRec428[2];
	double fRec429[2];
	double fRec431[2];
	double fRec430[2];
	double fVec93[2];
	double fRec432[2];
	double fVec94[2];
	double fRec433[2];
	double fVec95[2];
	double fRec434[2];
	double fVec96[2];
	double fRec435[2];
	double fRec15[2];
	double fRec436[2];
	double fRec437[2];
	double fRec438[2];
	double fRec439[2];
	double fRec440[2];
	double fRec441[2];
	double fRec442[2];
	double fRec443[2];
	double fRec444[2];
	double fRec445[2];
	double fRec446[2];
	double fRec447[2];
	double fRec448[2];
	double fRec449[2];
	double fRec450[2];
	double fRec451[2];
	FAUSTFLOAT fHslider0;
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fCheckbox10;
	FAUSTFLOAT fHslider23;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fCheckbox11;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	FAUSTFLOAT fCheckbox12;
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fCheckbox13;
	FAUSTFLOAT fHslider29;
	FAUSTFLOAT fHslider30;
	FAUSTFLOAT fCheckbox14;
	FAUSTFLOAT fHslider31;
	FAUSTFLOAT fHslider32;
	FAUSTFLOAT fCheckbox15;
	FAUSTFLOAT fHslider33;
	double fConst2;
	FAUSTFLOAT fHslider34;
	FAUSTFLOAT fHslider35;
	double fConst3;
	FAUSTFLOAT fHslider36;
	FAUSTFLOAT fHslider37;
	FAUSTFLOAT fHslider38;
	double fConst4;
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
	FAUSTFLOAT fHslider39;
	FAUSTFLOAT fHslider40;
	FAUSTFLOAT fHslider41;
	FAUSTFLOAT fHslider42;
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
	FAUSTFLOAT fHslider43;
	FAUSTFLOAT fHslider44;
	FAUSTFLOAT fHslider45;
	FAUSTFLOAT fHslider46;
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
	FAUSTFLOAT fHslider47;
	FAUSTFLOAT fCheckbox63;
	FAUSTFLOAT fHslider48;
	FAUSTFLOAT fHslider49;
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
	FAUSTFLOAT fHslider50;
	FAUSTFLOAT fCheckbox79;
	FAUSTFLOAT fHslider51;
	FAUSTFLOAT fCheckbox80;
	FAUSTFLOAT fCheckbox81;
	FAUSTFLOAT fCheckbox82;
	FAUSTFLOAT fCheckbox83;
	FAUSTFLOAT fCheckbox84;
	FAUSTFLOAT fCheckbox85;
	FAUSTFLOAT fCheckbox86;
	FAUSTFLOAT fHslider52;
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
	FAUSTFLOAT fHslider54;
	FAUSTFLOAT fHslider55;
	FAUSTFLOAT fHslider56;
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
	FAUSTFLOAT fHslider57;
	FAUSTFLOAT fHslider58;
	FAUSTFLOAT fHslider59;
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
	FAUSTFLOAT fHslider60;
	FAUSTFLOAT fHslider61;
	FAUSTFLOAT fHslider62;
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
	FAUSTFLOAT fHslider63;
	FAUSTFLOAT fHslider64;
	FAUSTFLOAT fHslider65;
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
	FAUSTFLOAT fHslider66;
	FAUSTFLOAT fHslider67;
	FAUSTFLOAT fHslider68;
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
	FAUSTFLOAT fHslider69;
	FAUSTFLOAT fHslider70;
	FAUSTFLOAT fHslider71;
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
	FAUSTFLOAT fHslider72;
	FAUSTFLOAT fHslider73;
	FAUSTFLOAT fHslider74;
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
	FAUSTFLOAT fHslider75;
	FAUSTFLOAT fHslider76;
	FAUSTFLOAT fHslider77;
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
	FAUSTFLOAT fHslider78;
	FAUSTFLOAT fHslider79;
	FAUSTFLOAT fHslider80;
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
	FAUSTFLOAT fHslider81;
	FAUSTFLOAT fHslider82;
	FAUSTFLOAT fHslider83;
	FAUSTFLOAT fHslider84;
	FAUSTFLOAT fHslider85;
	FAUSTFLOAT fHslider86;
	FAUSTFLOAT fHslider87;
	FAUSTFLOAT fHslider88;
	FAUSTFLOAT fHslider89;
	FAUSTFLOAT fHslider90;
	FAUSTFLOAT fHslider91;
	FAUSTFLOAT fHslider92;
	FAUSTFLOAT fHslider93;
	FAUSTFLOAT fHslider94;
	FAUSTFLOAT fHslider95;
	FAUSTFLOAT fHslider96;
	FAUSTFLOAT fHslider97;
	FAUSTFLOAT fHslider98;
	FAUSTFLOAT fHslider99;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics_lib_name", "Faust Basic Element Library");
		m->declare("basics_lib_version", "0.0");
		m->declare("compilation_options", "-single -scal");
		m->declare("delays_lib_name", "Faust Delay Library");
		m->declare("delays_lib_version", "0.0");
		m->declare("library_path", "mTDelHarmoHWin1MG16");
		m->declare("maths_lib_author", "GRAME");
		m->declare("maths_lib_copyright", "GRAME");
		m->declare("maths_lib_license", "LGPL with exception");
		m->declare("maths_lib_name", "Faust Math Library");
		m->declare("maths_lib_version", "2.0");
		m->declare("name", "mTDelHarmoHWin1MG16");
		m->declare("oscillators_lib_name", "Faust Oscillator Library");
		m->declare("oscillators_lib_version", "0.0");
		m->declare("signals_lib_name", "Faust Signal Routing Library");
		m->declare("signals_lib_version", "0.0");
	}

	virtual int getNumInputs() {
		return 1;
		
	}
	virtual int getNumOutputs() {
		return 16;
		
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
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
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
		fConst0 = min(192000.0, max(1.0, double(fSamplingFreq)));
		fConst1 = (1000.0 / fConst0);
		fConst2 = (0.001 * fConst0);
		fConst3 = (1.0 / fConst0);
		fConst4 = (0.029999999999999999 * fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0);
		fHslider1 = FAUSTFLOAT(20.0);
		fHslider2 = FAUSTFLOAT(0.0);
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
		fHslider33 = FAUSTFLOAT(1.0);
		fHslider34 = FAUSTFLOAT(100.0);
		fHslider35 = FAUSTFLOAT(1.0);
		fHslider36 = FAUSTFLOAT(0.0);
		fHslider37 = FAUSTFLOAT(1.0);
		fHslider38 = FAUSTFLOAT(64.0);
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
		fHslider39 = FAUSTFLOAT(1.0);
		fHslider40 = FAUSTFLOAT(200.0);
		fHslider41 = FAUSTFLOAT(0.0);
		fHslider42 = FAUSTFLOAT(0.0);
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
		fHslider43 = FAUSTFLOAT(1.0);
		fHslider44 = FAUSTFLOAT(300.0);
		fHslider45 = FAUSTFLOAT(0.0);
		fHslider46 = FAUSTFLOAT(400.0);
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
		fHslider47 = FAUSTFLOAT(1.0);
		fCheckbox63 = FAUSTFLOAT(0.0);
		fHslider48 = FAUSTFLOAT(0.0);
		fHslider49 = FAUSTFLOAT(500.0);
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
		fHslider50 = FAUSTFLOAT(1.0);
		fCheckbox79 = FAUSTFLOAT(0.0);
		fHslider51 = FAUSTFLOAT(600.0);
		fCheckbox80 = FAUSTFLOAT(0.0);
		fCheckbox81 = FAUSTFLOAT(0.0);
		fCheckbox82 = FAUSTFLOAT(0.0);
		fCheckbox83 = FAUSTFLOAT(0.0);
		fCheckbox84 = FAUSTFLOAT(0.0);
		fCheckbox85 = FAUSTFLOAT(0.0);
		fCheckbox86 = FAUSTFLOAT(0.0);
		fHslider52 = FAUSTFLOAT(1.0);
		fCheckbox87 = FAUSTFLOAT(0.0);
		fCheckbox88 = FAUSTFLOAT(0.0);
		fCheckbox89 = FAUSTFLOAT(0.0);
		fCheckbox90 = FAUSTFLOAT(0.0);
		fCheckbox91 = FAUSTFLOAT(0.0);
		fCheckbox92 = FAUSTFLOAT(0.0);
		fCheckbox93 = FAUSTFLOAT(0.0);
		fCheckbox94 = FAUSTFLOAT(0.0);
		fCheckbox95 = FAUSTFLOAT(0.0);
		fHslider53 = FAUSTFLOAT(0.0);
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
		fHslider54 = FAUSTFLOAT(1.0);
		fHslider55 = FAUSTFLOAT(700.0);
		fHslider56 = FAUSTFLOAT(0.0);
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
		fHslider57 = FAUSTFLOAT(1.0);
		fHslider58 = FAUSTFLOAT(800.0);
		fHslider59 = FAUSTFLOAT(0.0);
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
		fHslider60 = FAUSTFLOAT(1.0);
		fHslider61 = FAUSTFLOAT(900.0);
		fHslider62 = FAUSTFLOAT(0.0);
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
		fHslider63 = FAUSTFLOAT(1.0);
		fHslider64 = FAUSTFLOAT(1000.0);
		fHslider65 = FAUSTFLOAT(0.0);
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
		fHslider66 = FAUSTFLOAT(1.0);
		fHslider67 = FAUSTFLOAT(1100.0);
		fHslider68 = FAUSTFLOAT(0.0);
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
		fHslider69 = FAUSTFLOAT(1.0);
		fHslider70 = FAUSTFLOAT(1200.0);
		fHslider71 = FAUSTFLOAT(0.0);
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
		fHslider72 = FAUSTFLOAT(1.0);
		fHslider73 = FAUSTFLOAT(1300.0);
		fHslider74 = FAUSTFLOAT(0.0);
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
		fHslider75 = FAUSTFLOAT(1.0);
		fHslider76 = FAUSTFLOAT(1400.0);
		fHslider77 = FAUSTFLOAT(0.0);
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
		fHslider78 = FAUSTFLOAT(1.0);
		fHslider79 = FAUSTFLOAT(1500.0);
		fHslider80 = FAUSTFLOAT(0.0);
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
		fHslider81 = FAUSTFLOAT(1.0);
		fHslider82 = FAUSTFLOAT(1600.0);
		fHslider83 = FAUSTFLOAT(0.0);
		fHslider84 = FAUSTFLOAT(1.0);
		fHslider85 = FAUSTFLOAT(1.0);
		fHslider86 = FAUSTFLOAT(1.0);
		fHslider87 = FAUSTFLOAT(1.0);
		fHslider88 = FAUSTFLOAT(1.0);
		fHslider89 = FAUSTFLOAT(1.0);
		fHslider90 = FAUSTFLOAT(1.0);
		fHslider91 = FAUSTFLOAT(1.0);
		fHslider92 = FAUSTFLOAT(1.0);
		fHslider93 = FAUSTFLOAT(1.0);
		fHslider94 = FAUSTFLOAT(1.0);
		fHslider95 = FAUSTFLOAT(1.0);
		fHslider96 = FAUSTFLOAT(1.0);
		fHslider97 = FAUSTFLOAT(1.0);
		fHslider98 = FAUSTFLOAT(1.0);
		fHslider99 = FAUSTFLOAT(1.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec16[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec17[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec18[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec19[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec20[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec21[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec22[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec23[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec24[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec25[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec26[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec27[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec28[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec29[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec30[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec31[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec32[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec33[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec34[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec35[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec36[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec37[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec38[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec39[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec40[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec41[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec42[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec43[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec44[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec45[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec46[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec47[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec48[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec49[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec50[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec51[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec52[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec53[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec54[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec55[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec56[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec57[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec58[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec59[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec60[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec61[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec62[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec63[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec64[l48] = 0.0;
			
		}
		IOTA = 0;
		for (int l49 = 0; (l49 < 1048576); l49 = (l49 + 1)) {
			fVec0[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec65[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 262144); l51 = (l51 + 1)) {
			fVec1[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec67[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fVec2[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec69[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec70[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec68[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec66[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fVec3[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec71[l59] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fVec4[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec73[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fVec5[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec74[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fVec6[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec75[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec0[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec76[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec77[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec78[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec79[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec80[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec81[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec82[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec83[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec84[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec85[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec86[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec87[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec88[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec89[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec90[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec91[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec92[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 1048576); l85 = (l85 + 1)) {
			fVec7[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec93[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 262144); l87 = (l87 + 1)) {
			fVec8[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec95[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec94[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fVec9[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec96[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fVec10[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec97[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fVec11[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec98[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fVec12[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec99[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec1[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec101[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec100[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fVec13[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec102[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec103[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec104[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec105[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec106[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec107[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec108[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec109[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec110[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec111[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec112[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec113[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec114[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec115[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec116[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec117[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec118[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec119[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 1048576); l120 = (l120 + 1)) {
			fVec14[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec120[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 262144); l122 = (l122 + 1)) {
			fVec15[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fVec16[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec121[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fVec17[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec122[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fVec18[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec123[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec2[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec125[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec124[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fVec19[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec126[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec127[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec128[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec129[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec130[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec131[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec132[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec133[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec134[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec135[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec136[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec137[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec138[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec139[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec140[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec141[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec142[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec143[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec144[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 1048576); l152 = (l152 + 1)) {
			fVec20[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 262144); l153 = (l153 + 1)) {
			fVec21[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fVec22[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec145[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fVec23[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec146[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fVec24[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec147[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec3[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec149[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec148[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fVec25[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec150[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec151[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec152[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec153[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec154[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec155[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec156[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec157[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec158[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec159[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec160[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec161[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec162[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec163[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec164[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec165[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec166[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec167[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec168[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 1048576); l183 = (l183 + 1)) {
			fVec26[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 262144); l184 = (l184 + 1)) {
			fVec27[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fVec28[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec169[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fVec29[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec170[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fVec30[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec171[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec4[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec172[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec173[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec174[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec175[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec176[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec177[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec178[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec179[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec180[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec181[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec182[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec183[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec184[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec185[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec186[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec187[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec188[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec189[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 1048576); l210 = (l210 + 1)) {
			fVec31[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 262144); l211 = (l211 + 1)) {
			fVec32[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec191[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec190[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fVec33[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec192[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fVec34[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec193[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fVec35[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec194[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fVec36[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec195[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec5[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec196[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec197[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec198[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec199[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec200[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec201[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec202[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec203[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec204[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec205[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec206[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec207[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec208[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec209[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec210[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec211[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec212[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 1048576); l240 = (l240 + 1)) {
			fVec37[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec213[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 262144); l242 = (l242 + 1)) {
			fVec38[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec215[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec214[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fVec39[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec216[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fVec40[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec217[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fVec41[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec218[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fVec42[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec219[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec6[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec220[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec221[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec222[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec223[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec224[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec225[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec226[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec227[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec228[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec229[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec230[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec231[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec232[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec233[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec234[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec235[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec236[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 1048576); l271 = (l271 + 1)) {
			fVec43[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec237[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 262144); l273 = (l273 + 1)) {
			fVec44[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec239[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec238[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fVec45[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec240[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fVec46[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec241[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fVec47[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec242[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fVec48[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec243[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec7[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec244[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec245[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec246[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec247[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec248[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec249[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec250[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec251[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec252[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec253[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec254[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec255[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec256[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec257[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec258[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec259[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec260[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 1048576); l302 = (l302 + 1)) {
			fVec49[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec261[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 262144); l304 = (l304 + 1)) {
			fVec50[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec263[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec262[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fVec51[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec264[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fVec52[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec265[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fVec53[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec266[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fVec54[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec267[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec8[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec268[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec269[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec270[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec271[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec272[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec273[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec274[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec275[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec276[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec277[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec278[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec279[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec280[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec281[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec282[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec283[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec284[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 1048576); l333 = (l333 + 1)) {
			fVec55[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec285[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 262144); l335 = (l335 + 1)) {
			fVec56[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec287[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec286[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fVec57[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec288[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fVec58[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec289[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fVec59[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec290[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fVec60[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec291[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec9[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec292[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec293[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec294[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec295[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec296[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec297[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec298[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec299[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec300[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec301[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec302[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec303[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec304[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec305[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec306[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec307[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec308[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 1048576); l364 = (l364 + 1)) {
			fVec61[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec309[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 262144); l366 = (l366 + 1)) {
			fVec62[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec311[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec310[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fVec63[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec312[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fVec64[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec313[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fVec65[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec314[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fVec66[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec315[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec10[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec316[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec317[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec318[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec319[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec320[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec321[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec322[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec323[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec324[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec325[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec326[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec327[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec328[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec329[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec330[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec331[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec332[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 1048576); l395 = (l395 + 1)) {
			fVec67[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec333[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 262144); l397 = (l397 + 1)) {
			fVec68[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec335[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec334[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fVec69[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec336[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fVec70[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec337[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fVec71[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec338[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fVec72[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec339[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec11[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec340[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec341[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec342[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec343[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec344[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec345[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec346[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec347[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec348[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec349[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec350[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec351[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec352[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec353[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec354[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec355[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec356[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 1048576); l426 = (l426 + 1)) {
			fVec73[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec357[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 262144); l428 = (l428 + 1)) {
			fVec74[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec359[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec358[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fVec75[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec360[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fVec76[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec361[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fVec77[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec362[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fVec78[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec363[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec12[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec364[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec365[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec366[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec367[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec368[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec369[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec370[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec371[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec372[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec373[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec374[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec375[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec376[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec377[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec378[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec379[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec380[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 1048576); l457 = (l457 + 1)) {
			fVec79[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec381[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 262144); l459 = (l459 + 1)) {
			fVec80[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec383[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec382[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fVec81[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec384[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fVec82[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec385[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fVec83[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec386[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fVec84[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec387[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec13[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec388[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec389[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec390[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec391[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec392[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec393[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec394[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec395[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec396[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec397[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec398[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec399[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec400[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec401[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec402[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec403[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec404[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 1048576); l488 = (l488 + 1)) {
			fVec85[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec405[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 262144); l490 = (l490 + 1)) {
			fVec86[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec407[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec406[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fVec87[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec408[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fVec88[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec409[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fVec89[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec410[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fVec90[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec411[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec14[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec412[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec413[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec414[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec415[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec416[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec417[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec418[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec419[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec420[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec421[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec422[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec423[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec424[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec425[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec426[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec427[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec428[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 1048576); l519 = (l519 + 1)) {
			fVec91[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec429[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 262144); l521 = (l521 + 1)) {
			fVec92[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec431[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec430[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fVec93[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec432[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fVec94[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec433[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fVec95[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec434[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fVec96[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec435[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec15[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec436[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec437[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec438[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec439[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec440[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec441[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec442[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec443[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec444[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec445[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec446[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec447[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec448[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec449[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec450[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec451[l548] = 0.0;
			
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
		ui_interface->openVerticalBox("0x00");
		ui_interface->openHorizontalBox("Global_Parameters");
		ui_interface->declare(&fHslider35, "7", "");
		ui_interface->addHorizontalSlider("dStretch", &fHslider35, 1.0, 0.01, 10.0, 0.01);
		ui_interface->declare(&fHslider37, "7", "");
		ui_interface->addHorizontalSlider("hStretch", &fHslider37, 1.0, -10.0, 10.0, 0.01);
		ui_interface->addHorizontalSlider("hWin", &fHslider38, 64.0, 1.0, 127.0, 0.01);
		ui_interface->addHorizontalSlider("smoothDuration", &fHslider1, 20.0, 10.0, 5000.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Lines");
		ui_interface->openVerticalBox("Del_Durations");
		ui_interface->addHorizontalSlider("d 0", &fHslider34, 100.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 1", &fHslider40, 200.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 2", &fHslider44, 300.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 3", &fHslider46, 400.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 4", &fHslider49, 500.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 5", &fHslider51, 600.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 6", &fHslider55, 700.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 7", &fHslider58, 800.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 8", &fHslider61, 900.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d 9", &fHslider64, 1000.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d10", &fHslider67, 1100.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d11", &fHslider70, 1200.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d12", &fHslider73, 1300.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d13", &fHslider76, 1400.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d14", &fHslider79, 1500.0, 0.0, 43000.0, 1.0);
		ui_interface->addHorizontalSlider("d15", &fHslider82, 1600.0, 0.0, 43000.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del_Feedbacks");
		ui_interface->addHorizontalSlider("fd 0", &fHslider2, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 1", &fHslider3, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 2", &fHslider5, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 3", &fHslider7, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 4", &fHslider9, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 5", &fHslider11, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 6", &fHslider13, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 7", &fHslider15, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 8", &fHslider17, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd 9", &fHslider19, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd10", &fHslider21, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd11", &fHslider23, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd12", &fHslider25, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd13", &fHslider27, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd14", &fHslider29, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->addHorizontalSlider("fd15", &fHslider31, 0.0, 0.0, 0.98999999999999999, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("EffeX_vs_Del");
		ui_interface->addHorizontalSlider("xvd 0", &fHslider0, 1.0, 0.0, 1.0, 0.01);
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
		ui_interface->addHorizontalSlider("tr 0", &fHslider36, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 1", &fHslider41, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 2", &fHslider42, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 3", &fHslider45, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 4", &fHslider48, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 5", &fHslider53, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 6", &fHslider56, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 7", &fHslider59, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 8", &fHslider62, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr 9", &fHslider65, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr10", &fHslider68, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr11", &fHslider71, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr12", &fHslider74, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr13", &fHslider77, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr14", &fHslider80, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->addHorizontalSlider("tr15", &fHslider83, 0.0, -2400.0, 2400.0, 1.0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_input");
		ui_interface->declare(&fHslider33, "5", "");
		ui_interface->addHorizontalSlider("inp 0", &fHslider33, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider39, "5", "");
		ui_interface->addHorizontalSlider("inp 1", &fHslider39, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider43, "5", "");
		ui_interface->addHorizontalSlider("inp 2", &fHslider43, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider47, "5", "");
		ui_interface->addHorizontalSlider("inp 3", &fHslider47, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider50, "5", "");
		ui_interface->addHorizontalSlider("inp 4", &fHslider50, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider52, "5", "");
		ui_interface->addHorizontalSlider("inp 5", &fHslider52, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider54, "5", "");
		ui_interface->addHorizontalSlider("inp 6", &fHslider54, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider57, "5", "");
		ui_interface->addHorizontalSlider("inp 7", &fHslider57, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider60, "5", "");
		ui_interface->addHorizontalSlider("inp 8", &fHslider60, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider63, "5", "");
		ui_interface->addHorizontalSlider("inp 9", &fHslider63, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider66, "5", "");
		ui_interface->addHorizontalSlider("inp10", &fHslider66, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider69, "5", "");
		ui_interface->addHorizontalSlider("inp11", &fHslider69, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider72, "5", "");
		ui_interface->addHorizontalSlider("inp12", &fHslider72, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider75, "5", "");
		ui_interface->addHorizontalSlider("inp13", &fHslider75, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider78, "5", "");
		ui_interface->addHorizontalSlider("inp14", &fHslider78, 1.0, 0.0, 1.0, 0.01);
		ui_interface->declare(&fHslider81, "5", "");
		ui_interface->addHorizontalSlider("inp15", &fHslider81, 1.0, 0.0, 1.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Line_output");
		ui_interface->declare(&fHslider84, "6", "");
		ui_interface->addHorizontalSlider("out 0", &fHslider84, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider85, "6", "");
		ui_interface->addHorizontalSlider("out 1", &fHslider85, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider86, "6", "");
		ui_interface->addHorizontalSlider("out 2", &fHslider86, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider87, "6", "");
		ui_interface->addHorizontalSlider("out 3", &fHslider87, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider88, "6", "");
		ui_interface->addHorizontalSlider("out 4", &fHslider88, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider89, "6", "");
		ui_interface->addHorizontalSlider("out 5", &fHslider89, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider90, "6", "");
		ui_interface->addHorizontalSlider("out 6", &fHslider90, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider91, "6", "");
		ui_interface->addHorizontalSlider("out 7", &fHslider91, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider92, "6", "");
		ui_interface->addHorizontalSlider("out 8", &fHslider92, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider93, "6", "");
		ui_interface->addHorizontalSlider("out 9", &fHslider93, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider94, "6", "");
		ui_interface->addHorizontalSlider("out10", &fHslider94, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider95, "6", "");
		ui_interface->addHorizontalSlider("out11", &fHslider95, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider96, "6", "");
		ui_interface->addHorizontalSlider("out12", &fHslider96, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider97, "6", "");
		ui_interface->addHorizontalSlider("out13", &fHslider97, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider98, "6", "");
		ui_interface->addHorizontalSlider("out14", &fHslider98, 1.0, 0.0, 4.0, 0.01);
		ui_interface->declare(&fHslider99, "6", "");
		ui_interface->addHorizontalSlider("out15", &fHslider99, 1.0, 0.0, 4.0, 0.01);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Reinjection_Matrix");
		ui_interface->openVerticalBox("Del 0-->");
		ui_interface->addCheckButton("r  0",&fCheckbox0);
		ui_interface->addCheckButton("r 16",&fCheckbox16);
		ui_interface->addCheckButton("r 32",&fCheckbox32);
		ui_interface->addCheckButton("r 48",&fCheckbox63);
		ui_interface->addCheckButton("r 64",&fCheckbox79);
		ui_interface->addCheckButton("r 80",&fCheckbox86);
		ui_interface->addCheckButton("r 96",&fCheckbox96);
		ui_interface->addCheckButton("r112",&fCheckbox112);
		ui_interface->addCheckButton("r128",&fCheckbox128);
		ui_interface->addCheckButton("r144",&fCheckbox144);
		ui_interface->addCheckButton("r160",&fCheckbox160);
		ui_interface->addCheckButton("r176",&fCheckbox176);
		ui_interface->addCheckButton("r192",&fCheckbox192);
		ui_interface->addCheckButton("r208",&fCheckbox208);
		ui_interface->addCheckButton("r224",&fCheckbox224);
		ui_interface->addCheckButton("r240",&fCheckbox240);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 1-->");
		ui_interface->addCheckButton("r  1",&fCheckbox1);
		ui_interface->addCheckButton("r 17",&fCheckbox17);
		ui_interface->addCheckButton("r 33",&fCheckbox33);
		ui_interface->addCheckButton("r 49",&fCheckbox62);
		ui_interface->addCheckButton("r 65",&fCheckbox78);
		ui_interface->addCheckButton("r 81",&fCheckbox85);
		ui_interface->addCheckButton("r 97",&fCheckbox97);
		ui_interface->addCheckButton("r113",&fCheckbox113);
		ui_interface->addCheckButton("r129",&fCheckbox129);
		ui_interface->addCheckButton("r145",&fCheckbox145);
		ui_interface->addCheckButton("r161",&fCheckbox161);
		ui_interface->addCheckButton("r177",&fCheckbox177);
		ui_interface->addCheckButton("r193",&fCheckbox193);
		ui_interface->addCheckButton("r209",&fCheckbox209);
		ui_interface->addCheckButton("r225",&fCheckbox225);
		ui_interface->addCheckButton("r241",&fCheckbox241);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 2-->");
		ui_interface->addCheckButton("r  2",&fCheckbox2);
		ui_interface->addCheckButton("r 18",&fCheckbox18);
		ui_interface->addCheckButton("r 34",&fCheckbox34);
		ui_interface->addCheckButton("r 50",&fCheckbox61);
		ui_interface->addCheckButton("r 66",&fCheckbox77);
		ui_interface->addCheckButton("r 82",&fCheckbox84);
		ui_interface->addCheckButton("r 98",&fCheckbox98);
		ui_interface->addCheckButton("r114",&fCheckbox114);
		ui_interface->addCheckButton("r130",&fCheckbox130);
		ui_interface->addCheckButton("r146",&fCheckbox146);
		ui_interface->addCheckButton("r162",&fCheckbox162);
		ui_interface->addCheckButton("r178",&fCheckbox178);
		ui_interface->addCheckButton("r194",&fCheckbox194);
		ui_interface->addCheckButton("r210",&fCheckbox210);
		ui_interface->addCheckButton("r226",&fCheckbox226);
		ui_interface->addCheckButton("r242",&fCheckbox242);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 3-->");
		ui_interface->addCheckButton("r  3",&fCheckbox3);
		ui_interface->addCheckButton("r 19",&fCheckbox19);
		ui_interface->addCheckButton("r 35",&fCheckbox35);
		ui_interface->addCheckButton("r 51",&fCheckbox60);
		ui_interface->addCheckButton("r 67",&fCheckbox76);
		ui_interface->addCheckButton("r 83",&fCheckbox83);
		ui_interface->addCheckButton("r 99",&fCheckbox99);
		ui_interface->addCheckButton("r115",&fCheckbox115);
		ui_interface->addCheckButton("r131",&fCheckbox131);
		ui_interface->addCheckButton("r147",&fCheckbox147);
		ui_interface->addCheckButton("r163",&fCheckbox163);
		ui_interface->addCheckButton("r179",&fCheckbox179);
		ui_interface->addCheckButton("r195",&fCheckbox195);
		ui_interface->addCheckButton("r211",&fCheckbox211);
		ui_interface->addCheckButton("r227",&fCheckbox227);
		ui_interface->addCheckButton("r243",&fCheckbox243);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 4-->");
		ui_interface->addCheckButton("r  4",&fCheckbox4);
		ui_interface->addCheckButton("r 20",&fCheckbox20);
		ui_interface->addCheckButton("r 36",&fCheckbox36);
		ui_interface->addCheckButton("r 52",&fCheckbox59);
		ui_interface->addCheckButton("r 68",&fCheckbox75);
		ui_interface->addCheckButton("r 84",&fCheckbox82);
		ui_interface->addCheckButton("r100",&fCheckbox100);
		ui_interface->addCheckButton("r116",&fCheckbox116);
		ui_interface->addCheckButton("r132",&fCheckbox132);
		ui_interface->addCheckButton("r148",&fCheckbox148);
		ui_interface->addCheckButton("r164",&fCheckbox164);
		ui_interface->addCheckButton("r180",&fCheckbox180);
		ui_interface->addCheckButton("r196",&fCheckbox196);
		ui_interface->addCheckButton("r212",&fCheckbox212);
		ui_interface->addCheckButton("r228",&fCheckbox228);
		ui_interface->addCheckButton("r244",&fCheckbox244);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 5-->");
		ui_interface->addCheckButton("r  5",&fCheckbox5);
		ui_interface->addCheckButton("r 21",&fCheckbox21);
		ui_interface->addCheckButton("r 37",&fCheckbox37);
		ui_interface->addCheckButton("r 53",&fCheckbox58);
		ui_interface->addCheckButton("r 69",&fCheckbox74);
		ui_interface->addCheckButton("r 85",&fCheckbox81);
		ui_interface->addCheckButton("r101",&fCheckbox101);
		ui_interface->addCheckButton("r117",&fCheckbox117);
		ui_interface->addCheckButton("r133",&fCheckbox133);
		ui_interface->addCheckButton("r149",&fCheckbox149);
		ui_interface->addCheckButton("r165",&fCheckbox165);
		ui_interface->addCheckButton("r181",&fCheckbox181);
		ui_interface->addCheckButton("r197",&fCheckbox197);
		ui_interface->addCheckButton("r213",&fCheckbox213);
		ui_interface->addCheckButton("r229",&fCheckbox229);
		ui_interface->addCheckButton("r245",&fCheckbox245);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 6-->");
		ui_interface->addCheckButton("r  6",&fCheckbox6);
		ui_interface->addCheckButton("r 22",&fCheckbox22);
		ui_interface->addCheckButton("r 38",&fCheckbox38);
		ui_interface->addCheckButton("r 54",&fCheckbox57);
		ui_interface->addCheckButton("r 70",&fCheckbox73);
		ui_interface->addCheckButton("r 86",&fCheckbox80);
		ui_interface->addCheckButton("r102",&fCheckbox102);
		ui_interface->addCheckButton("r118",&fCheckbox118);
		ui_interface->addCheckButton("r134",&fCheckbox134);
		ui_interface->addCheckButton("r150",&fCheckbox150);
		ui_interface->addCheckButton("r166",&fCheckbox166);
		ui_interface->addCheckButton("r182",&fCheckbox182);
		ui_interface->addCheckButton("r198",&fCheckbox198);
		ui_interface->addCheckButton("r214",&fCheckbox214);
		ui_interface->addCheckButton("r230",&fCheckbox230);
		ui_interface->addCheckButton("r246",&fCheckbox246);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 7-->");
		ui_interface->addCheckButton("r  7",&fCheckbox7);
		ui_interface->addCheckButton("r 23",&fCheckbox23);
		ui_interface->addCheckButton("r 39",&fCheckbox39);
		ui_interface->addCheckButton("r 55",&fCheckbox56);
		ui_interface->addCheckButton("r 71",&fCheckbox72);
		ui_interface->addCheckButton("r 87",&fCheckbox94);
		ui_interface->addCheckButton("r103",&fCheckbox103);
		ui_interface->addCheckButton("r119",&fCheckbox119);
		ui_interface->addCheckButton("r135",&fCheckbox135);
		ui_interface->addCheckButton("r151",&fCheckbox151);
		ui_interface->addCheckButton("r167",&fCheckbox167);
		ui_interface->addCheckButton("r183",&fCheckbox183);
		ui_interface->addCheckButton("r199",&fCheckbox199);
		ui_interface->addCheckButton("r215",&fCheckbox215);
		ui_interface->addCheckButton("r231",&fCheckbox231);
		ui_interface->addCheckButton("r247",&fCheckbox247);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 8-->");
		ui_interface->addCheckButton("r  8",&fCheckbox8);
		ui_interface->addCheckButton("r 24",&fCheckbox24);
		ui_interface->addCheckButton("r 40",&fCheckbox40);
		ui_interface->addCheckButton("r 56",&fCheckbox55);
		ui_interface->addCheckButton("r 72",&fCheckbox71);
		ui_interface->addCheckButton("r 88",&fCheckbox95);
		ui_interface->addCheckButton("r104",&fCheckbox104);
		ui_interface->addCheckButton("r120",&fCheckbox120);
		ui_interface->addCheckButton("r136",&fCheckbox136);
		ui_interface->addCheckButton("r152",&fCheckbox152);
		ui_interface->addCheckButton("r168",&fCheckbox168);
		ui_interface->addCheckButton("r184",&fCheckbox184);
		ui_interface->addCheckButton("r200",&fCheckbox200);
		ui_interface->addCheckButton("r216",&fCheckbox216);
		ui_interface->addCheckButton("r232",&fCheckbox232);
		ui_interface->addCheckButton("r248",&fCheckbox248);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del 9-->");
		ui_interface->addCheckButton("r  9",&fCheckbox9);
		ui_interface->addCheckButton("r 25",&fCheckbox25);
		ui_interface->addCheckButton("r 41",&fCheckbox41);
		ui_interface->addCheckButton("r 57",&fCheckbox54);
		ui_interface->addCheckButton("r 73",&fCheckbox70);
		ui_interface->addCheckButton("r 89",&fCheckbox93);
		ui_interface->addCheckButton("r105",&fCheckbox105);
		ui_interface->addCheckButton("r121",&fCheckbox121);
		ui_interface->addCheckButton("r137",&fCheckbox137);
		ui_interface->addCheckButton("r153",&fCheckbox153);
		ui_interface->addCheckButton("r169",&fCheckbox169);
		ui_interface->addCheckButton("r185",&fCheckbox185);
		ui_interface->addCheckButton("r201",&fCheckbox201);
		ui_interface->addCheckButton("r217",&fCheckbox217);
		ui_interface->addCheckButton("r233",&fCheckbox233);
		ui_interface->addCheckButton("r249",&fCheckbox249);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del10-->");
		ui_interface->addCheckButton("r 10",&fCheckbox10);
		ui_interface->addCheckButton("r 26",&fCheckbox26);
		ui_interface->addCheckButton("r 42",&fCheckbox42);
		ui_interface->addCheckButton("r 58",&fCheckbox53);
		ui_interface->addCheckButton("r 74",&fCheckbox69);
		ui_interface->addCheckButton("r 90",&fCheckbox92);
		ui_interface->addCheckButton("r106",&fCheckbox106);
		ui_interface->addCheckButton("r122",&fCheckbox122);
		ui_interface->addCheckButton("r138",&fCheckbox138);
		ui_interface->addCheckButton("r154",&fCheckbox154);
		ui_interface->addCheckButton("r170",&fCheckbox170);
		ui_interface->addCheckButton("r186",&fCheckbox186);
		ui_interface->addCheckButton("r202",&fCheckbox202);
		ui_interface->addCheckButton("r218",&fCheckbox218);
		ui_interface->addCheckButton("r234",&fCheckbox234);
		ui_interface->addCheckButton("r250",&fCheckbox250);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del11-->");
		ui_interface->addCheckButton("r 11",&fCheckbox11);
		ui_interface->addCheckButton("r 27",&fCheckbox27);
		ui_interface->addCheckButton("r 43",&fCheckbox43);
		ui_interface->addCheckButton("r 59",&fCheckbox52);
		ui_interface->addCheckButton("r 75",&fCheckbox68);
		ui_interface->addCheckButton("r 91",&fCheckbox91);
		ui_interface->addCheckButton("r107",&fCheckbox107);
		ui_interface->addCheckButton("r123",&fCheckbox123);
		ui_interface->addCheckButton("r139",&fCheckbox139);
		ui_interface->addCheckButton("r155",&fCheckbox155);
		ui_interface->addCheckButton("r171",&fCheckbox171);
		ui_interface->addCheckButton("r187",&fCheckbox187);
		ui_interface->addCheckButton("r203",&fCheckbox203);
		ui_interface->addCheckButton("r219",&fCheckbox219);
		ui_interface->addCheckButton("r235",&fCheckbox235);
		ui_interface->addCheckButton("r251",&fCheckbox251);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del12-->");
		ui_interface->addCheckButton("r 12",&fCheckbox12);
		ui_interface->addCheckButton("r 28",&fCheckbox28);
		ui_interface->addCheckButton("r 44",&fCheckbox44);
		ui_interface->addCheckButton("r 60",&fCheckbox51);
		ui_interface->addCheckButton("r 76",&fCheckbox67);
		ui_interface->addCheckButton("r 92",&fCheckbox90);
		ui_interface->addCheckButton("r108",&fCheckbox108);
		ui_interface->addCheckButton("r124",&fCheckbox124);
		ui_interface->addCheckButton("r140",&fCheckbox140);
		ui_interface->addCheckButton("r156",&fCheckbox156);
		ui_interface->addCheckButton("r172",&fCheckbox172);
		ui_interface->addCheckButton("r188",&fCheckbox188);
		ui_interface->addCheckButton("r204",&fCheckbox204);
		ui_interface->addCheckButton("r220",&fCheckbox220);
		ui_interface->addCheckButton("r236",&fCheckbox236);
		ui_interface->addCheckButton("r252",&fCheckbox252);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del13-->");
		ui_interface->addCheckButton("r 13",&fCheckbox13);
		ui_interface->addCheckButton("r 29",&fCheckbox29);
		ui_interface->addCheckButton("r 45",&fCheckbox45);
		ui_interface->addCheckButton("r 61",&fCheckbox50);
		ui_interface->addCheckButton("r 77",&fCheckbox66);
		ui_interface->addCheckButton("r 93",&fCheckbox89);
		ui_interface->addCheckButton("r109",&fCheckbox109);
		ui_interface->addCheckButton("r125",&fCheckbox125);
		ui_interface->addCheckButton("r141",&fCheckbox141);
		ui_interface->addCheckButton("r157",&fCheckbox157);
		ui_interface->addCheckButton("r173",&fCheckbox173);
		ui_interface->addCheckButton("r189",&fCheckbox189);
		ui_interface->addCheckButton("r205",&fCheckbox205);
		ui_interface->addCheckButton("r221",&fCheckbox221);
		ui_interface->addCheckButton("r237",&fCheckbox237);
		ui_interface->addCheckButton("r253",&fCheckbox253);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del14-->");
		ui_interface->addCheckButton("r 14",&fCheckbox14);
		ui_interface->addCheckButton("r 30",&fCheckbox30);
		ui_interface->addCheckButton("r 46",&fCheckbox46);
		ui_interface->addCheckButton("r 62",&fCheckbox49);
		ui_interface->addCheckButton("r 78",&fCheckbox65);
		ui_interface->addCheckButton("r 94",&fCheckbox88);
		ui_interface->addCheckButton("r110",&fCheckbox110);
		ui_interface->addCheckButton("r126",&fCheckbox126);
		ui_interface->addCheckButton("r142",&fCheckbox142);
		ui_interface->addCheckButton("r158",&fCheckbox158);
		ui_interface->addCheckButton("r174",&fCheckbox174);
		ui_interface->addCheckButton("r190",&fCheckbox190);
		ui_interface->addCheckButton("r206",&fCheckbox206);
		ui_interface->addCheckButton("r222",&fCheckbox222);
		ui_interface->addCheckButton("r238",&fCheckbox238);
		ui_interface->addCheckButton("r254",&fCheckbox254);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Del15-->");
		ui_interface->addCheckButton("r 15",&fCheckbox15);
		ui_interface->addCheckButton("r 31",&fCheckbox31);
		ui_interface->addCheckButton("r 47",&fCheckbox47);
		ui_interface->addCheckButton("r 63",&fCheckbox48);
		ui_interface->addCheckButton("r 79",&fCheckbox64);
		ui_interface->addCheckButton("r 95",&fCheckbox87);
		ui_interface->addCheckButton("r111",&fCheckbox111);
		ui_interface->addCheckButton("r127",&fCheckbox127);
		ui_interface->addCheckButton("r143",&fCheckbox143);
		ui_interface->addCheckButton("r159",&fCheckbox159);
		ui_interface->addCheckButton("r175",&fCheckbox175);
		ui_interface->addCheckButton("r191",&fCheckbox191);
		ui_interface->addCheckButton("r207",&fCheckbox207);
		ui_interface->addCheckButton("r223",&fCheckbox223);
		ui_interface->addCheckButton("r239",&fCheckbox239);
		ui_interface->addCheckButton("r255",&fCheckbox255);
		ui_interface->closeBox();
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
		FAUSTFLOAT* output8 = outputs[8];
		FAUSTFLOAT* output9 = outputs[9];
		FAUSTFLOAT* output10 = outputs[10];
		FAUSTFLOAT* output11 = outputs[11];
		FAUSTFLOAT* output12 = outputs[12];
		FAUSTFLOAT* output13 = outputs[13];
		FAUSTFLOAT* output14 = outputs[14];
		FAUSTFLOAT* output15 = outputs[15];
		double fSlow0 = exp((0.0 - (fConst1 / double(fHslider1))));
		double fSlow1 = (1.0 - fSlow0);
		double fSlow2 = (double(fHslider0) * fSlow1);
		double fSlow3 = (double(fHslider2) * fSlow1);
		double fSlow4 = (double(fCheckbox0) * fSlow1);
		double fSlow5 = (double(fHslider3) * fSlow1);
		double fSlow6 = (double(fHslider4) * fSlow1);
		double fSlow7 = (double(fCheckbox1) * fSlow1);
		double fSlow8 = (double(fHslider5) * fSlow1);
		double fSlow9 = (double(fHslider6) * fSlow1);
		double fSlow10 = (double(fCheckbox2) * fSlow1);
		double fSlow11 = (double(fHslider7) * fSlow1);
		double fSlow12 = (double(fHslider8) * fSlow1);
		double fSlow13 = (double(fCheckbox3) * fSlow1);
		double fSlow14 = (double(fHslider9) * fSlow1);
		double fSlow15 = (double(fHslider10) * fSlow1);
		double fSlow16 = (double(fCheckbox4) * fSlow1);
		double fSlow17 = (double(fHslider11) * fSlow1);
		double fSlow18 = (double(fHslider12) * fSlow1);
		double fSlow19 = (double(fCheckbox5) * fSlow1);
		double fSlow20 = (double(fHslider13) * fSlow1);
		double fSlow21 = (double(fHslider14) * fSlow1);
		double fSlow22 = (double(fCheckbox6) * fSlow1);
		double fSlow23 = (double(fHslider15) * fSlow1);
		double fSlow24 = (double(fHslider16) * fSlow1);
		double fSlow25 = (double(fCheckbox7) * fSlow1);
		double fSlow26 = (double(fHslider17) * fSlow1);
		double fSlow27 = (double(fHslider18) * fSlow1);
		double fSlow28 = (double(fCheckbox8) * fSlow1);
		double fSlow29 = (double(fHslider19) * fSlow1);
		double fSlow30 = (double(fHslider20) * fSlow1);
		double fSlow31 = (double(fCheckbox9) * fSlow1);
		double fSlow32 = (double(fHslider21) * fSlow1);
		double fSlow33 = (double(fHslider22) * fSlow1);
		double fSlow34 = (double(fCheckbox10) * fSlow1);
		double fSlow35 = (double(fHslider23) * fSlow1);
		double fSlow36 = (double(fHslider24) * fSlow1);
		double fSlow37 = (double(fCheckbox11) * fSlow1);
		double fSlow38 = (double(fHslider25) * fSlow1);
		double fSlow39 = (double(fHslider26) * fSlow1);
		double fSlow40 = (double(fCheckbox12) * fSlow1);
		double fSlow41 = (double(fHslider27) * fSlow1);
		double fSlow42 = (double(fHslider28) * fSlow1);
		double fSlow43 = (double(fCheckbox13) * fSlow1);
		double fSlow44 = (double(fHslider29) * fSlow1);
		double fSlow45 = (double(fHslider30) * fSlow1);
		double fSlow46 = (double(fCheckbox14) * fSlow1);
		double fSlow47 = (double(fHslider31) * fSlow1);
		double fSlow48 = (double(fHslider32) * fSlow1);
		double fSlow49 = (double(fCheckbox15) * fSlow1);
		double fSlow50 = (double(fHslider33) * fSlow1);
		double fSlow51 = double(fHslider35);
		double fSlow52 = (fSlow1 * double(int((fConst2 * (double(fHslider34) * fSlow51)))));
		double fSlow53 = double(fHslider37);
		double fSlow54 = ((double(fHslider36) * fSlow53) * fSlow1);
		double fSlow55 = double(fHslider38);
		double fSlow56 = ((fSlow55 < 127.0)?fSlow55:127.0);
		double fSlow57 = ((fSlow56 < 1.0)?0.0:(4096.0 * pow(1.0717699999999999, (fSlow56 + -127.0))));
		double fSlow58 = (double(fCheckbox16) * fSlow1);
		double fSlow59 = (double(fCheckbox17) * fSlow1);
		double fSlow60 = (double(fCheckbox18) * fSlow1);
		double fSlow61 = (double(fCheckbox19) * fSlow1);
		double fSlow62 = (double(fCheckbox20) * fSlow1);
		double fSlow63 = (double(fCheckbox21) * fSlow1);
		double fSlow64 = (double(fCheckbox22) * fSlow1);
		double fSlow65 = (double(fCheckbox23) * fSlow1);
		double fSlow66 = (double(fCheckbox24) * fSlow1);
		double fSlow67 = (double(fCheckbox25) * fSlow1);
		double fSlow68 = (double(fCheckbox26) * fSlow1);
		double fSlow69 = (double(fCheckbox27) * fSlow1);
		double fSlow70 = (double(fCheckbox28) * fSlow1);
		double fSlow71 = (double(fCheckbox29) * fSlow1);
		double fSlow72 = (double(fCheckbox30) * fSlow1);
		double fSlow73 = (double(fCheckbox31) * fSlow1);
		double fSlow74 = (double(fHslider39) * fSlow1);
		double fSlow75 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider40))))));
		double fSlow76 = ((fSlow53 * double(fHslider41)) * fSlow1);
		double fSlow77 = ((fSlow53 * double(fHslider42)) * fSlow1);
		double fSlow78 = (double(fCheckbox32) * fSlow1);
		double fSlow79 = (double(fCheckbox33) * fSlow1);
		double fSlow80 = (double(fCheckbox34) * fSlow1);
		double fSlow81 = (double(fCheckbox35) * fSlow1);
		double fSlow82 = (double(fCheckbox36) * fSlow1);
		double fSlow83 = (double(fCheckbox37) * fSlow1);
		double fSlow84 = (double(fCheckbox38) * fSlow1);
		double fSlow85 = (double(fCheckbox39) * fSlow1);
		double fSlow86 = (double(fCheckbox40) * fSlow1);
		double fSlow87 = (double(fCheckbox41) * fSlow1);
		double fSlow88 = (double(fCheckbox42) * fSlow1);
		double fSlow89 = (double(fCheckbox43) * fSlow1);
		double fSlow90 = (double(fCheckbox44) * fSlow1);
		double fSlow91 = (double(fCheckbox45) * fSlow1);
		double fSlow92 = (double(fCheckbox46) * fSlow1);
		double fSlow93 = (double(fCheckbox47) * fSlow1);
		double fSlow94 = (double(fHslider43) * fSlow1);
		double fSlow95 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider44))))));
		double fSlow96 = ((fSlow53 * double(fHslider45)) * fSlow1);
		double fSlow97 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider46))))));
		double fSlow98 = (double(fCheckbox48) * fSlow1);
		double fSlow99 = (double(fCheckbox49) * fSlow1);
		double fSlow100 = (double(fCheckbox50) * fSlow1);
		double fSlow101 = (double(fCheckbox51) * fSlow1);
		double fSlow102 = (double(fCheckbox52) * fSlow1);
		double fSlow103 = (double(fCheckbox53) * fSlow1);
		double fSlow104 = (double(fCheckbox54) * fSlow1);
		double fSlow105 = (double(fCheckbox55) * fSlow1);
		double fSlow106 = (double(fCheckbox56) * fSlow1);
		double fSlow107 = (double(fCheckbox57) * fSlow1);
		double fSlow108 = (double(fCheckbox58) * fSlow1);
		double fSlow109 = (double(fCheckbox59) * fSlow1);
		double fSlow110 = (double(fCheckbox60) * fSlow1);
		double fSlow111 = (double(fCheckbox61) * fSlow1);
		double fSlow112 = (double(fCheckbox62) * fSlow1);
		double fSlow113 = (double(fHslider47) * fSlow1);
		double fSlow114 = (double(fCheckbox63) * fSlow1);
		double fSlow115 = ((fSlow53 * double(fHslider48)) * fSlow1);
		double fSlow116 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider49))))));
		double fSlow117 = (double(fCheckbox64) * fSlow1);
		double fSlow118 = (double(fCheckbox65) * fSlow1);
		double fSlow119 = (double(fCheckbox66) * fSlow1);
		double fSlow120 = (double(fCheckbox67) * fSlow1);
		double fSlow121 = (double(fCheckbox68) * fSlow1);
		double fSlow122 = (double(fCheckbox69) * fSlow1);
		double fSlow123 = (double(fCheckbox70) * fSlow1);
		double fSlow124 = (double(fCheckbox71) * fSlow1);
		double fSlow125 = (double(fCheckbox72) * fSlow1);
		double fSlow126 = (double(fCheckbox73) * fSlow1);
		double fSlow127 = (double(fCheckbox74) * fSlow1);
		double fSlow128 = (double(fCheckbox75) * fSlow1);
		double fSlow129 = (double(fCheckbox76) * fSlow1);
		double fSlow130 = (double(fCheckbox77) * fSlow1);
		double fSlow131 = (double(fCheckbox78) * fSlow1);
		double fSlow132 = (double(fHslider50) * fSlow1);
		double fSlow133 = (double(fCheckbox79) * fSlow1);
		double fSlow134 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider51))))));
		double fSlow135 = (double(fCheckbox80) * fSlow1);
		double fSlow136 = (double(fCheckbox81) * fSlow1);
		double fSlow137 = (double(fCheckbox82) * fSlow1);
		double fSlow138 = (double(fCheckbox83) * fSlow1);
		double fSlow139 = (double(fCheckbox84) * fSlow1);
		double fSlow140 = (double(fCheckbox85) * fSlow1);
		double fSlow141 = (double(fCheckbox86) * fSlow1);
		double fSlow142 = (double(fHslider52) * fSlow1);
		double fSlow143 = (double(fCheckbox87) * fSlow1);
		double fSlow144 = (double(fCheckbox88) * fSlow1);
		double fSlow145 = (double(fCheckbox89) * fSlow1);
		double fSlow146 = (double(fCheckbox90) * fSlow1);
		double fSlow147 = (double(fCheckbox91) * fSlow1);
		double fSlow148 = (double(fCheckbox92) * fSlow1);
		double fSlow149 = (double(fCheckbox93) * fSlow1);
		double fSlow150 = (double(fCheckbox94) * fSlow1);
		double fSlow151 = (double(fCheckbox95) * fSlow1);
		double fSlow152 = ((fSlow53 * double(fHslider53)) * fSlow1);
		double fSlow153 = (double(fCheckbox96) * fSlow1);
		double fSlow154 = (double(fCheckbox97) * fSlow1);
		double fSlow155 = (double(fCheckbox98) * fSlow1);
		double fSlow156 = (double(fCheckbox99) * fSlow1);
		double fSlow157 = (double(fCheckbox100) * fSlow1);
		double fSlow158 = (double(fCheckbox101) * fSlow1);
		double fSlow159 = (double(fCheckbox102) * fSlow1);
		double fSlow160 = (double(fCheckbox103) * fSlow1);
		double fSlow161 = (double(fCheckbox104) * fSlow1);
		double fSlow162 = (double(fCheckbox105) * fSlow1);
		double fSlow163 = (double(fCheckbox106) * fSlow1);
		double fSlow164 = (double(fCheckbox107) * fSlow1);
		double fSlow165 = (double(fCheckbox108) * fSlow1);
		double fSlow166 = (double(fCheckbox109) * fSlow1);
		double fSlow167 = (double(fCheckbox110) * fSlow1);
		double fSlow168 = (double(fCheckbox111) * fSlow1);
		double fSlow169 = (double(fHslider54) * fSlow1);
		double fSlow170 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider55))))));
		double fSlow171 = ((fSlow53 * double(fHslider56)) * fSlow1);
		double fSlow172 = (double(fCheckbox112) * fSlow1);
		double fSlow173 = (double(fCheckbox113) * fSlow1);
		double fSlow174 = (double(fCheckbox114) * fSlow1);
		double fSlow175 = (double(fCheckbox115) * fSlow1);
		double fSlow176 = (double(fCheckbox116) * fSlow1);
		double fSlow177 = (double(fCheckbox117) * fSlow1);
		double fSlow178 = (double(fCheckbox118) * fSlow1);
		double fSlow179 = (double(fCheckbox119) * fSlow1);
		double fSlow180 = (double(fCheckbox120) * fSlow1);
		double fSlow181 = (double(fCheckbox121) * fSlow1);
		double fSlow182 = (double(fCheckbox122) * fSlow1);
		double fSlow183 = (double(fCheckbox123) * fSlow1);
		double fSlow184 = (double(fCheckbox124) * fSlow1);
		double fSlow185 = (double(fCheckbox125) * fSlow1);
		double fSlow186 = (double(fCheckbox126) * fSlow1);
		double fSlow187 = (double(fCheckbox127) * fSlow1);
		double fSlow188 = (double(fHslider57) * fSlow1);
		double fSlow189 = (fSlow1 * double(int((fConst2 * (double(fHslider58) * fSlow51)))));
		double fSlow190 = ((fSlow53 * double(fHslider59)) * fSlow1);
		double fSlow191 = (double(fCheckbox128) * fSlow1);
		double fSlow192 = (double(fCheckbox129) * fSlow1);
		double fSlow193 = (double(fCheckbox130) * fSlow1);
		double fSlow194 = (double(fCheckbox131) * fSlow1);
		double fSlow195 = (double(fCheckbox132) * fSlow1);
		double fSlow196 = (double(fCheckbox133) * fSlow1);
		double fSlow197 = (double(fCheckbox134) * fSlow1);
		double fSlow198 = (double(fCheckbox135) * fSlow1);
		double fSlow199 = (double(fCheckbox136) * fSlow1);
		double fSlow200 = (double(fCheckbox137) * fSlow1);
		double fSlow201 = (double(fCheckbox138) * fSlow1);
		double fSlow202 = (double(fCheckbox139) * fSlow1);
		double fSlow203 = (double(fCheckbox140) * fSlow1);
		double fSlow204 = (double(fCheckbox141) * fSlow1);
		double fSlow205 = (double(fCheckbox142) * fSlow1);
		double fSlow206 = (double(fCheckbox143) * fSlow1);
		double fSlow207 = (double(fHslider60) * fSlow1);
		double fSlow208 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider61))))));
		double fSlow209 = ((fSlow53 * double(fHslider62)) * fSlow1);
		double fSlow210 = (double(fCheckbox144) * fSlow1);
		double fSlow211 = (double(fCheckbox145) * fSlow1);
		double fSlow212 = (double(fCheckbox146) * fSlow1);
		double fSlow213 = (double(fCheckbox147) * fSlow1);
		double fSlow214 = (double(fCheckbox148) * fSlow1);
		double fSlow215 = (double(fCheckbox149) * fSlow1);
		double fSlow216 = (double(fCheckbox150) * fSlow1);
		double fSlow217 = (double(fCheckbox151) * fSlow1);
		double fSlow218 = (double(fCheckbox152) * fSlow1);
		double fSlow219 = (double(fCheckbox153) * fSlow1);
		double fSlow220 = (double(fCheckbox154) * fSlow1);
		double fSlow221 = (double(fCheckbox155) * fSlow1);
		double fSlow222 = (double(fCheckbox156) * fSlow1);
		double fSlow223 = (double(fCheckbox157) * fSlow1);
		double fSlow224 = (double(fCheckbox158) * fSlow1);
		double fSlow225 = (double(fCheckbox159) * fSlow1);
		double fSlow226 = (double(fHslider63) * fSlow1);
		double fSlow227 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider64))))));
		double fSlow228 = ((fSlow53 * double(fHslider65)) * fSlow1);
		double fSlow229 = (double(fCheckbox160) * fSlow1);
		double fSlow230 = (double(fCheckbox161) * fSlow1);
		double fSlow231 = (double(fCheckbox162) * fSlow1);
		double fSlow232 = (double(fCheckbox163) * fSlow1);
		double fSlow233 = (double(fCheckbox164) * fSlow1);
		double fSlow234 = (double(fCheckbox165) * fSlow1);
		double fSlow235 = (double(fCheckbox166) * fSlow1);
		double fSlow236 = (double(fCheckbox167) * fSlow1);
		double fSlow237 = (double(fCheckbox168) * fSlow1);
		double fSlow238 = (double(fCheckbox169) * fSlow1);
		double fSlow239 = (double(fCheckbox170) * fSlow1);
		double fSlow240 = (double(fCheckbox171) * fSlow1);
		double fSlow241 = (double(fCheckbox172) * fSlow1);
		double fSlow242 = (double(fCheckbox173) * fSlow1);
		double fSlow243 = (double(fCheckbox174) * fSlow1);
		double fSlow244 = (double(fCheckbox175) * fSlow1);
		double fSlow245 = (double(fHslider66) * fSlow1);
		double fSlow246 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider67))))));
		double fSlow247 = ((fSlow53 * double(fHslider68)) * fSlow1);
		double fSlow248 = (double(fCheckbox176) * fSlow1);
		double fSlow249 = (double(fCheckbox177) * fSlow1);
		double fSlow250 = (double(fCheckbox178) * fSlow1);
		double fSlow251 = (double(fCheckbox179) * fSlow1);
		double fSlow252 = (double(fCheckbox180) * fSlow1);
		double fSlow253 = (double(fCheckbox181) * fSlow1);
		double fSlow254 = (double(fCheckbox182) * fSlow1);
		double fSlow255 = (double(fCheckbox183) * fSlow1);
		double fSlow256 = (double(fCheckbox184) * fSlow1);
		double fSlow257 = (double(fCheckbox185) * fSlow1);
		double fSlow258 = (double(fCheckbox186) * fSlow1);
		double fSlow259 = (double(fCheckbox187) * fSlow1);
		double fSlow260 = (double(fCheckbox188) * fSlow1);
		double fSlow261 = (double(fCheckbox189) * fSlow1);
		double fSlow262 = (double(fCheckbox190) * fSlow1);
		double fSlow263 = (double(fCheckbox191) * fSlow1);
		double fSlow264 = (double(fHslider69) * fSlow1);
		double fSlow265 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider70))))));
		double fSlow266 = ((fSlow53 * double(fHslider71)) * fSlow1);
		double fSlow267 = (double(fCheckbox192) * fSlow1);
		double fSlow268 = (double(fCheckbox193) * fSlow1);
		double fSlow269 = (double(fCheckbox194) * fSlow1);
		double fSlow270 = (double(fCheckbox195) * fSlow1);
		double fSlow271 = (double(fCheckbox196) * fSlow1);
		double fSlow272 = (double(fCheckbox197) * fSlow1);
		double fSlow273 = (double(fCheckbox198) * fSlow1);
		double fSlow274 = (double(fCheckbox199) * fSlow1);
		double fSlow275 = (double(fCheckbox200) * fSlow1);
		double fSlow276 = (double(fCheckbox201) * fSlow1);
		double fSlow277 = (double(fCheckbox202) * fSlow1);
		double fSlow278 = (double(fCheckbox203) * fSlow1);
		double fSlow279 = (double(fCheckbox204) * fSlow1);
		double fSlow280 = (double(fCheckbox205) * fSlow1);
		double fSlow281 = (double(fCheckbox206) * fSlow1);
		double fSlow282 = (double(fCheckbox207) * fSlow1);
		double fSlow283 = (double(fHslider72) * fSlow1);
		double fSlow284 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider73))))));
		double fSlow285 = ((double(fHslider74) * fSlow53) * fSlow1);
		double fSlow286 = (double(fCheckbox208) * fSlow1);
		double fSlow287 = (double(fCheckbox209) * fSlow1);
		double fSlow288 = (double(fCheckbox210) * fSlow1);
		double fSlow289 = (double(fCheckbox211) * fSlow1);
		double fSlow290 = (double(fCheckbox212) * fSlow1);
		double fSlow291 = (double(fCheckbox213) * fSlow1);
		double fSlow292 = (double(fCheckbox214) * fSlow1);
		double fSlow293 = (double(fCheckbox215) * fSlow1);
		double fSlow294 = (double(fCheckbox216) * fSlow1);
		double fSlow295 = (double(fCheckbox217) * fSlow1);
		double fSlow296 = (double(fCheckbox218) * fSlow1);
		double fSlow297 = (double(fCheckbox219) * fSlow1);
		double fSlow298 = (double(fCheckbox220) * fSlow1);
		double fSlow299 = (double(fCheckbox221) * fSlow1);
		double fSlow300 = (double(fCheckbox222) * fSlow1);
		double fSlow301 = (double(fCheckbox223) * fSlow1);
		double fSlow302 = (double(fHslider75) * fSlow1);
		double fSlow303 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider76))))));
		double fSlow304 = ((fSlow53 * double(fHslider77)) * fSlow1);
		double fSlow305 = (double(fCheckbox224) * fSlow1);
		double fSlow306 = (double(fCheckbox225) * fSlow1);
		double fSlow307 = (double(fCheckbox226) * fSlow1);
		double fSlow308 = (double(fCheckbox227) * fSlow1);
		double fSlow309 = (double(fCheckbox228) * fSlow1);
		double fSlow310 = (double(fCheckbox229) * fSlow1);
		double fSlow311 = (double(fCheckbox230) * fSlow1);
		double fSlow312 = (double(fCheckbox231) * fSlow1);
		double fSlow313 = (double(fCheckbox232) * fSlow1);
		double fSlow314 = (double(fCheckbox233) * fSlow1);
		double fSlow315 = (double(fCheckbox234) * fSlow1);
		double fSlow316 = (double(fCheckbox235) * fSlow1);
		double fSlow317 = (double(fCheckbox236) * fSlow1);
		double fSlow318 = (double(fCheckbox237) * fSlow1);
		double fSlow319 = (double(fCheckbox238) * fSlow1);
		double fSlow320 = (double(fCheckbox239) * fSlow1);
		double fSlow321 = (double(fHslider78) * fSlow1);
		double fSlow322 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider79))))));
		double fSlow323 = ((fSlow53 * double(fHslider80)) * fSlow1);
		double fSlow324 = (double(fCheckbox240) * fSlow1);
		double fSlow325 = (double(fCheckbox241) * fSlow1);
		double fSlow326 = (double(fCheckbox242) * fSlow1);
		double fSlow327 = (double(fCheckbox243) * fSlow1);
		double fSlow328 = (double(fCheckbox244) * fSlow1);
		double fSlow329 = (double(fCheckbox245) * fSlow1);
		double fSlow330 = (double(fCheckbox246) * fSlow1);
		double fSlow331 = (double(fCheckbox247) * fSlow1);
		double fSlow332 = (double(fCheckbox248) * fSlow1);
		double fSlow333 = (double(fCheckbox249) * fSlow1);
		double fSlow334 = (double(fCheckbox250) * fSlow1);
		double fSlow335 = (double(fCheckbox251) * fSlow1);
		double fSlow336 = (double(fCheckbox252) * fSlow1);
		double fSlow337 = (double(fCheckbox253) * fSlow1);
		double fSlow338 = (double(fCheckbox254) * fSlow1);
		double fSlow339 = (double(fCheckbox255) * fSlow1);
		double fSlow340 = (double(fHslider81) * fSlow1);
		double fSlow341 = (fSlow1 * double(int((fConst2 * (fSlow51 * double(fHslider82))))));
		double fSlow342 = ((fSlow53 * double(fHslider83)) * fSlow1);
		double fSlow343 = (double(fHslider84) * fSlow1);
		double fSlow344 = (double(fHslider85) * fSlow1);
		double fSlow345 = (double(fHslider86) * fSlow1);
		double fSlow346 = (double(fHslider87) * fSlow1);
		double fSlow347 = (double(fHslider88) * fSlow1);
		double fSlow348 = (double(fHslider89) * fSlow1);
		double fSlow349 = (double(fHslider90) * fSlow1);
		double fSlow350 = (double(fHslider91) * fSlow1);
		double fSlow351 = (double(fHslider92) * fSlow1);
		double fSlow352 = (double(fHslider93) * fSlow1);
		double fSlow353 = (double(fHslider94) * fSlow1);
		double fSlow354 = (double(fHslider95) * fSlow1);
		double fSlow355 = (double(fHslider96) * fSlow1);
		double fSlow356 = (double(fHslider97) * fSlow1);
		double fSlow357 = (double(fHslider98) * fSlow1);
		double fSlow358 = (double(fHslider99) * fSlow1);
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec16[0] = (fSlow2 + (fSlow0 * fRec16[1]));
			fRec17[0] = (fSlow3 + (fSlow0 * fRec17[1]));
			double fTemp0 = (1.0 - (0.75 * fRec16[0]));
			double fTemp1 = ((fRec0[1] * fRec17[0]) * fTemp0);
			fRec18[0] = (fSlow4 + (fSlow0 * fRec18[1]));
			fRec19[0] = (fSlow5 + (fSlow0 * fRec19[1]));
			fRec20[0] = (fSlow6 + (fSlow0 * fRec20[1]));
			double fTemp2 = (1.0 - (0.75 * fRec20[0]));
			double fTemp3 = ((fRec1[1] * fRec19[0]) * fTemp2);
			fRec21[0] = (fSlow7 + (fSlow0 * fRec21[1]));
			fRec22[0] = (fSlow8 + (fSlow0 * fRec22[1]));
			fRec23[0] = (fSlow9 + (fSlow0 * fRec23[1]));
			double fTemp4 = (1.0 - (0.75 * fRec23[0]));
			double fTemp5 = ((fRec2[1] * fRec22[0]) * fTemp4);
			fRec24[0] = (fSlow10 + (fSlow0 * fRec24[1]));
			fRec25[0] = (fSlow11 + (fSlow0 * fRec25[1]));
			fRec26[0] = (fSlow12 + (fSlow0 * fRec26[1]));
			double fTemp6 = (1.0 - (0.75 * fRec26[0]));
			double fTemp7 = ((fRec3[1] * fRec25[0]) * fTemp6);
			fRec27[0] = (fSlow13 + (fSlow0 * fRec27[1]));
			fRec28[0] = (fSlow14 + (fSlow0 * fRec28[1]));
			fRec29[0] = (fSlow15 + (fSlow0 * fRec29[1]));
			double fTemp8 = (1.0 - (0.75 * fRec29[0]));
			double fTemp9 = ((fRec4[1] * fRec28[0]) * fTemp8);
			fRec30[0] = (fSlow16 + (fSlow0 * fRec30[1]));
			fRec31[0] = (fSlow17 + (fSlow0 * fRec31[1]));
			fRec32[0] = (fSlow18 + (fSlow0 * fRec32[1]));
			double fTemp10 = (1.0 - (0.75 * fRec32[0]));
			double fTemp11 = ((fRec5[1] * fRec31[0]) * fTemp10);
			fRec33[0] = (fSlow19 + (fSlow0 * fRec33[1]));
			fRec34[0] = (fSlow20 + (fSlow0 * fRec34[1]));
			fRec35[0] = (fSlow21 + (fSlow0 * fRec35[1]));
			double fTemp12 = (1.0 - (0.75 * fRec35[0]));
			double fTemp13 = ((fRec6[1] * fRec34[0]) * fTemp12);
			fRec36[0] = (fSlow22 + (fSlow0 * fRec36[1]));
			fRec37[0] = (fSlow23 + (fSlow0 * fRec37[1]));
			fRec38[0] = (fSlow24 + (fSlow0 * fRec38[1]));
			double fTemp14 = (1.0 - (0.75 * fRec38[0]));
			double fTemp15 = ((fRec7[1] * fRec37[0]) * fTemp14);
			fRec39[0] = (fSlow25 + (fSlow0 * fRec39[1]));
			fRec40[0] = (fSlow26 + (fSlow0 * fRec40[1]));
			fRec41[0] = (fSlow27 + (fSlow0 * fRec41[1]));
			double fTemp16 = (1.0 - (0.75 * fRec41[0]));
			double fTemp17 = ((fRec8[1] * fRec40[0]) * fTemp16);
			fRec42[0] = (fSlow28 + (fSlow0 * fRec42[1]));
			fRec43[0] = (fSlow29 + (fSlow0 * fRec43[1]));
			fRec44[0] = (fSlow30 + (fSlow0 * fRec44[1]));
			double fTemp18 = (1.0 - (0.75 * fRec44[0]));
			double fTemp19 = ((fRec9[1] * fRec43[0]) * fTemp18);
			fRec45[0] = (fSlow31 + (fSlow0 * fRec45[1]));
			fRec46[0] = (fSlow32 + (fSlow0 * fRec46[1]));
			fRec47[0] = (fSlow33 + (fSlow0 * fRec47[1]));
			double fTemp20 = (1.0 - (0.75 * fRec47[0]));
			double fTemp21 = ((fRec10[1] * fRec46[0]) * fTemp20);
			fRec48[0] = (fSlow34 + (fSlow0 * fRec48[1]));
			fRec49[0] = (fSlow35 + (fSlow0 * fRec49[1]));
			fRec50[0] = (fSlow36 + (fSlow0 * fRec50[1]));
			double fTemp22 = (1.0 - (0.75 * fRec50[0]));
			double fTemp23 = ((fRec11[1] * fRec49[0]) * fTemp22);
			fRec51[0] = (fSlow37 + (fSlow0 * fRec51[1]));
			fRec52[0] = (fSlow38 + (fSlow0 * fRec52[1]));
			fRec53[0] = (fSlow39 + (fSlow0 * fRec53[1]));
			double fTemp24 = (1.0 - (0.75 * fRec53[0]));
			double fTemp25 = ((fRec12[1] * fRec52[0]) * fTemp24);
			fRec54[0] = (fSlow40 + (fSlow0 * fRec54[1]));
			fRec55[0] = (fSlow41 + (fSlow0 * fRec55[1]));
			fRec56[0] = (fSlow42 + (fSlow0 * fRec56[1]));
			double fTemp26 = (1.0 - (0.75 * fRec56[0]));
			double fTemp27 = ((fRec13[1] * fRec55[0]) * fTemp26);
			fRec57[0] = (fSlow43 + (fSlow0 * fRec57[1]));
			fRec58[0] = (fSlow44 + (fSlow0 * fRec58[1]));
			fRec59[0] = (fSlow45 + (fSlow0 * fRec59[1]));
			double fTemp28 = (1.0 - (0.75 * fRec59[0]));
			double fTemp29 = ((fRec14[1] * fRec58[0]) * fTemp28);
			fRec60[0] = (fSlow46 + (fSlow0 * fRec60[1]));
			fRec61[0] = (fSlow47 + (fSlow0 * fRec61[1]));
			fRec62[0] = (fSlow48 + (fSlow0 * fRec62[1]));
			double fTemp30 = (1.0 - (0.75 * fRec62[0]));
			double fTemp31 = ((fRec15[1] * fRec61[0]) * fTemp30);
			fRec63[0] = (fSlow49 + (fSlow0 * fRec63[1]));
			double fTemp32 = double(input0[i]);
			fRec64[0] = (fSlow50 + (fSlow0 * fRec64[1]));
			double fTemp33 = (((((((((((((((((fTemp1 * fRec18[0]) + (fTemp3 * fRec21[0])) + (fTemp5 * fRec24[0])) + (fTemp7 * fRec27[0])) + (fTemp9 * fRec30[0])) + (fTemp11 * fRec33[0])) + (fTemp13 * fRec36[0])) + (fTemp15 * fRec39[0])) + (fTemp17 * fRec42[0])) + (fTemp19 * fRec45[0])) + (fTemp21 * fRec48[0])) + (fTemp23 * fRec51[0])) + (fTemp25 * fRec54[0])) + (fTemp27 * fRec57[0])) + (fTemp29 * fRec60[0])) + (fTemp31 * fRec63[0])) + (fTemp32 * fRec64[0]));
			fVec0[(IOTA & 1048575)] = fTemp33;
			fRec65[0] = (fSlow52 + (fSlow0 * fRec65[1]));
			int iTemp34 = int(fRec65[0]);
			double fTemp35 = floor(fRec65[0]);
			double fTemp36 = ((fVec0[((IOTA - (iTemp34 & 1048575)) & 1048575)] * (fTemp35 + (1.0 - fRec65[0]))) + ((fRec65[0] - fTemp35) * fVec0[((IOTA - ((iTemp34 + 1) & 1048575)) & 1048575)]));
			int iTemp37 = (fTemp36 > 1.0);
			int iTemp38 = (fTemp36 < -1.0);
			double fTemp39 = ((double(iTemp37) + ((fTemp36 * double((1 - iTemp38))) * double((1 - iTemp37)))) - double(iTemp38));
			double fTemp40 = (fRec16[0] * fTemp39);
			fVec1[(IOTA & 262143)] = fTemp40;
			fRec67[0] = (fSlow54 + (fSlow0 * fRec67[1]));
			fVec2[0] = fSlow57;
			double fTemp41 = ((fSlow57 != fVec2[1])?fConst4:(fRec69[1] + -1.0));
			fRec69[0] = fTemp41;
			fRec70[0] = ((fTemp41 <= 0.0)?fSlow57:(fRec70[1] + ((fSlow57 - fRec70[1]) / fTemp41)));
			fRec68[0] = ((fSlow0 * fRec68[1]) + (fSlow1 * fRec70[0]));
			double fTemp42 = (fRec66[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec67[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec66[0] = (fTemp42 - floor(fTemp42));
			double fTemp43 = (fRec66[0] - floor(fRec66[0]));
			fVec3[0] = fTemp43;
			int iTemp44 = (fTemp43 > 0.001);
			int iTemp45 = (fVec3[1] <= 0.001);
			fRec71[0] = ((fRec71[1] * double((1 - (iTemp44 * iTemp45)))) + ((fRec68[0] * double(iTemp44)) * double(iTemp45)));
			double fTemp46 = (fConst2 * (fTemp43 * fRec71[0]));
			int iTemp47 = int(fTemp46);
			double fTemp48 = floor(fTemp46);
			double fTemp49 = (0.5 * fTemp43);
			double fTemp50 = (65536.0 * (fTemp49 - floor(fTemp49)));
			int iTemp51 = int(fTemp50);
			double fTemp52 = (fRec66[0] + (0.25 - floor((fRec66[0] + 0.25))));
			fVec4[0] = fTemp52;
			int iTemp53 = (fTemp52 > 0.001);
			int iTemp54 = (fVec4[1] <= 0.001);
			fRec73[0] = ((fRec73[1] * double((1 - (iTemp53 * iTemp54)))) + ((fRec68[0] * double(iTemp53)) * double(iTemp54)));
			double fTemp55 = (fConst2 * (fTemp52 * fRec73[0]));
			int iTemp56 = int(fTemp55);
			double fTemp57 = floor(fTemp55);
			double fTemp58 = (0.5 * fTemp52);
			double fTemp59 = (65536.0 * (fTemp58 - floor(fTemp58)));
			int iTemp60 = int(fTemp59);
			double fTemp61 = (fRec66[0] + (0.5 - floor((fRec66[0] + 0.5))));
			fVec5[0] = fTemp61;
			int iTemp62 = (fTemp61 > 0.001);
			int iTemp63 = (fVec5[1] <= 0.001);
			fRec74[0] = ((fRec74[1] * double((1 - (iTemp62 * iTemp63)))) + ((fRec68[0] * double(iTemp62)) * double(iTemp63)));
			double fTemp64 = (fConst2 * (fTemp61 * fRec74[0]));
			int iTemp65 = int(fTemp64);
			double fTemp66 = floor(fTemp64);
			double fTemp67 = (0.5 * fTemp61);
			double fTemp68 = (65536.0 * (fTemp67 - floor(fTemp67)));
			int iTemp69 = int(fTemp68);
			double fTemp70 = (fRec66[0] + (0.75 - floor((fRec66[0] + 0.75))));
			fVec6[0] = fTemp70;
			int iTemp71 = (fTemp70 > 0.001);
			int iTemp72 = (fVec6[1] <= 0.001);
			fRec75[0] = ((fRec75[1] * double((1 - (iTemp71 * iTemp72)))) + ((fRec68[0] * double(iTemp71)) * double(iTemp72)));
			double fTemp73 = (fConst2 * (fTemp70 * fRec75[0]));
			int iTemp74 = int(fTemp73);
			double fTemp75 = floor(fTemp73);
			double fTemp76 = (0.5 * fTemp70);
			double fTemp77 = (65536.0 * (fTemp76 - floor(fTemp76)));
			int iTemp78 = int(fTemp77);
			fRec0[0] = (((((((fVec1[((IOTA - (iTemp47 & 262143)) & 262143)] * (fTemp48 + (1.0 - fTemp46))) + ((fTemp46 - fTemp48) * fVec1[((IOTA - ((iTemp47 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp51] + ((fTemp50 - floor(fTemp50)) * (ftbl0mydspSIG0[((iTemp51 + 1) % 65536)] - ftbl0mydspSIG0[iTemp51])))) + (((fVec1[((IOTA - (iTemp56 & 262143)) & 262143)] * (fTemp57 + (1.0 - fTemp55))) + ((fTemp55 - fTemp57) * fVec1[((IOTA - ((iTemp56 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp60] + ((fTemp59 - floor(fTemp59)) * (ftbl0mydspSIG0[((iTemp60 + 1) % 65536)] - ftbl0mydspSIG0[iTemp60]))))) + (((fVec1[((IOTA - (iTemp65 & 262143)) & 262143)] * (fTemp66 + (1.0 - fTemp64))) + ((fTemp64 - fTemp66) * fVec1[((IOTA - ((iTemp65 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp69] + ((fTemp68 - floor(fTemp68)) * (ftbl0mydspSIG0[((iTemp69 + 1) % 65536)] - ftbl0mydspSIG0[iTemp69]))))) + (((fVec1[((IOTA - (iTemp74 & 262143)) & 262143)] * (fTemp75 + (1.0 - fTemp73))) + ((fTemp73 - fTemp75) * fVec1[((IOTA - ((iTemp74 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp78] + ((fTemp77 - floor(fTemp77)) * (ftbl0mydspSIG0[((iTemp78 + 1) % 65536)] - ftbl0mydspSIG0[iTemp78]))))) + (fTemp39 * (1.0 - fRec16[0])));
			fRec76[0] = (fSlow58 + (fSlow0 * fRec76[1]));
			fRec77[0] = (fSlow59 + (fSlow0 * fRec77[1]));
			fRec78[0] = (fSlow60 + (fSlow0 * fRec78[1]));
			fRec79[0] = (fSlow61 + (fSlow0 * fRec79[1]));
			fRec80[0] = (fSlow62 + (fSlow0 * fRec80[1]));
			fRec81[0] = (fSlow63 + (fSlow0 * fRec81[1]));
			fRec82[0] = (fSlow64 + (fSlow0 * fRec82[1]));
			fRec83[0] = (fSlow65 + (fSlow0 * fRec83[1]));
			fRec84[0] = (fSlow66 + (fSlow0 * fRec84[1]));
			fRec85[0] = (fSlow67 + (fSlow0 * fRec85[1]));
			fRec86[0] = (fSlow68 + (fSlow0 * fRec86[1]));
			fRec87[0] = (fSlow69 + (fSlow0 * fRec87[1]));
			fRec88[0] = (fSlow70 + (fSlow0 * fRec88[1]));
			fRec89[0] = (fSlow71 + (fSlow0 * fRec89[1]));
			fRec90[0] = (fSlow72 + (fSlow0 * fRec90[1]));
			fRec91[0] = (fSlow73 + (fSlow0 * fRec91[1]));
			fRec92[0] = (fSlow74 + (fSlow0 * fRec92[1]));
			double fTemp79 = (((((((((((((((((fTemp1 * fRec76[0]) + (fTemp3 * fRec77[0])) + (fTemp5 * fRec78[0])) + (fTemp7 * fRec79[0])) + (fTemp9 * fRec80[0])) + (fTemp11 * fRec81[0])) + (fTemp13 * fRec82[0])) + (fTemp15 * fRec83[0])) + (fTemp17 * fRec84[0])) + (fTemp19 * fRec85[0])) + (fTemp21 * fRec86[0])) + (fTemp23 * fRec87[0])) + (fTemp25 * fRec88[0])) + (fTemp27 * fRec89[0])) + (fTemp29 * fRec90[0])) + (fTemp31 * fRec91[0])) + (fTemp32 * fRec92[0]));
			fVec7[(IOTA & 1048575)] = fTemp79;
			fRec93[0] = (fSlow75 + (fSlow0 * fRec93[1]));
			int iTemp80 = int(fRec93[0]);
			double fTemp81 = floor(fRec93[0]);
			double fTemp82 = ((fVec7[((IOTA - (iTemp80 & 1048575)) & 1048575)] * (fTemp81 + (1.0 - fRec93[0]))) + ((fRec93[0] - fTemp81) * fVec7[((IOTA - ((iTemp80 + 1) & 1048575)) & 1048575)]));
			int iTemp83 = (fTemp82 > 1.0);
			int iTemp84 = (fTemp82 < -1.0);
			double fTemp85 = ((double(iTemp83) + ((fTemp82 * double((1 - iTemp84))) * double((1 - iTemp83)))) - double(iTemp84));
			double fTemp86 = (fRec20[0] * fTemp85);
			fVec8[(IOTA & 262143)] = fTemp86;
			fRec95[0] = (fSlow76 + (fSlow0 * fRec95[1]));
			double fTemp87 = (fRec94[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec95[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec94[0] = (fTemp87 - floor(fTemp87));
			double fTemp88 = (fRec94[0] - floor(fRec94[0]));
			fVec9[0] = fTemp88;
			int iTemp89 = (fTemp88 > 0.001);
			int iTemp90 = (fVec9[1] <= 0.001);
			fRec96[0] = ((fRec96[1] * double((1 - (iTemp89 * iTemp90)))) + ((fRec68[0] * double(iTemp89)) * double(iTemp90)));
			double fTemp91 = (fConst2 * (fTemp88 * fRec96[0]));
			int iTemp92 = int(fTemp91);
			double fTemp93 = floor(fTemp91);
			double fTemp94 = (0.5 * fTemp88);
			double fTemp95 = (65536.0 * (fTemp94 - floor(fTemp94)));
			int iTemp96 = int(fTemp95);
			double fTemp97 = (fRec94[0] + (0.25 - floor((fRec94[0] + 0.25))));
			fVec10[0] = fTemp97;
			int iTemp98 = (fTemp97 > 0.001);
			int iTemp99 = (fVec10[1] <= 0.001);
			fRec97[0] = ((fRec97[1] * double((1 - (iTemp98 * iTemp99)))) + ((fRec68[0] * double(iTemp98)) * double(iTemp99)));
			double fTemp100 = (fConst2 * (fTemp97 * fRec97[0]));
			int iTemp101 = int(fTemp100);
			double fTemp102 = floor(fTemp100);
			double fTemp103 = (0.5 * fTemp97);
			double fTemp104 = (65536.0 * (fTemp103 - floor(fTemp103)));
			int iTemp105 = int(fTemp104);
			double fTemp106 = (fRec94[0] + (0.5 - floor((fRec94[0] + 0.5))));
			fVec11[0] = fTemp106;
			int iTemp107 = (fTemp106 > 0.001);
			int iTemp108 = (fVec11[1] <= 0.001);
			fRec98[0] = ((fRec98[1] * double((1 - (iTemp107 * iTemp108)))) + ((fRec68[0] * double(iTemp107)) * double(iTemp108)));
			double fTemp109 = (fConst2 * (fTemp106 * fRec98[0]));
			int iTemp110 = int(fTemp109);
			double fTemp111 = floor(fTemp109);
			double fTemp112 = (0.5 * fTemp106);
			double fTemp113 = (65536.0 * (fTemp112 - floor(fTemp112)));
			int iTemp114 = int(fTemp113);
			double fTemp115 = (fRec94[0] + (0.75 - floor((fRec94[0] + 0.75))));
			fVec12[0] = fTemp115;
			int iTemp116 = (fTemp115 > 0.001);
			int iTemp117 = (fVec12[1] <= 0.001);
			fRec99[0] = ((fRec99[1] * double((1 - (iTemp116 * iTemp117)))) + ((fRec68[0] * double(iTemp116)) * double(iTemp117)));
			double fTemp118 = (fConst2 * (fTemp115 * fRec99[0]));
			int iTemp119 = int(fTemp118);
			double fTemp120 = floor(fTemp118);
			double fTemp121 = (0.5 * fTemp115);
			double fTemp122 = (65536.0 * (fTemp121 - floor(fTemp121)));
			int iTemp123 = int(fTemp122);
			fRec1[0] = (((((((fVec8[((IOTA - (iTemp92 & 262143)) & 262143)] * (fTemp93 + (1.0 - fTemp91))) + ((fTemp91 - fTemp93) * fVec8[((IOTA - ((iTemp92 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp96] + ((fTemp95 - floor(fTemp95)) * (ftbl0mydspSIG0[((iTemp96 + 1) % 65536)] - ftbl0mydspSIG0[iTemp96])))) + (((fVec8[((IOTA - (iTemp101 & 262143)) & 262143)] * (fTemp102 + (1.0 - fTemp100))) + ((fTemp100 - fTemp102) * fVec8[((IOTA - ((iTemp101 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp105] + ((fTemp104 - floor(fTemp104)) * (ftbl0mydspSIG0[((iTemp105 + 1) % 65536)] - ftbl0mydspSIG0[iTemp105]))))) + (((fVec8[((IOTA - (iTemp110 & 262143)) & 262143)] * (fTemp111 + (1.0 - fTemp109))) + ((fTemp109 - fTemp111) * fVec8[((IOTA - ((iTemp110 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp114] + ((fTemp113 - floor(fTemp113)) * (ftbl0mydspSIG0[((iTemp114 + 1) % 65536)] - ftbl0mydspSIG0[iTemp114]))))) + (((fVec8[((IOTA - (iTemp119 & 262143)) & 262143)] * (fTemp120 + (1.0 - fTemp118))) + ((fTemp118 - fTemp120) * fVec8[((IOTA - ((iTemp119 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp123] + ((fTemp122 - floor(fTemp122)) * (ftbl0mydspSIG0[((iTemp123 + 1) % 65536)] - ftbl0mydspSIG0[iTemp123]))))) + (fTemp85 * (1.0 - fRec20[0])));
			fRec101[0] = (fSlow77 + (fSlow0 * fRec101[1]));
			double fTemp124 = (fRec100[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec101[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec100[0] = (fTemp124 - floor(fTemp124));
			double fTemp125 = (fRec100[0] + (0.75 - floor((fRec100[0] + 0.75))));
			fVec13[0] = fTemp125;
			double fTemp126 = (0.5 * fTemp125);
			double fTemp127 = (65536.0 * (fTemp126 - floor(fTemp126)));
			int iTemp128 = int(fTemp127);
			int iTemp129 = ((fTemp125 > 0.001) * (fVec13[1] <= 0.001));
			fRec102[0] = ((fRec102[1] * double((1 - iTemp129))) + (double(iTemp129) * fRec68[0]));
			double fTemp130 = (fConst2 * (fTemp125 * fRec102[0]));
			double fTemp131 = floor(fTemp130);
			fRec103[0] = (fSlow78 + (fSlow0 * fRec103[1]));
			fRec104[0] = (fSlow79 + (fSlow0 * fRec104[1]));
			fRec105[0] = (fSlow80 + (fSlow0 * fRec105[1]));
			fRec106[0] = (fSlow81 + (fSlow0 * fRec106[1]));
			fRec107[0] = (fSlow82 + (fSlow0 * fRec107[1]));
			fRec108[0] = (fSlow83 + (fSlow0 * fRec108[1]));
			fRec109[0] = (fSlow84 + (fSlow0 * fRec109[1]));
			fRec110[0] = (fSlow85 + (fSlow0 * fRec110[1]));
			fRec111[0] = (fSlow86 + (fSlow0 * fRec111[1]));
			fRec112[0] = (fSlow87 + (fSlow0 * fRec112[1]));
			fRec113[0] = (fSlow88 + (fSlow0 * fRec113[1]));
			fRec114[0] = (fSlow89 + (fSlow0 * fRec114[1]));
			fRec115[0] = (fSlow90 + (fSlow0 * fRec115[1]));
			fRec116[0] = (fSlow91 + (fSlow0 * fRec116[1]));
			fRec117[0] = (fSlow92 + (fSlow0 * fRec117[1]));
			fRec118[0] = (fSlow93 + (fSlow0 * fRec118[1]));
			fRec119[0] = (fSlow94 + (fSlow0 * fRec119[1]));
			double fTemp132 = (((((((((((((((((fTemp1 * fRec103[0]) + (fTemp3 * fRec104[0])) + (fTemp5 * fRec105[0])) + (fTemp7 * fRec106[0])) + (fTemp9 * fRec107[0])) + (fTemp11 * fRec108[0])) + (fTemp13 * fRec109[0])) + (fTemp15 * fRec110[0])) + (fTemp17 * fRec111[0])) + (fTemp19 * fRec112[0])) + (fTemp21 * fRec113[0])) + (fTemp23 * fRec114[0])) + (fTemp25 * fRec115[0])) + (fTemp27 * fRec116[0])) + (fTemp29 * fRec117[0])) + (fTemp31 * fRec118[0])) + (fTemp32 * fRec119[0]));
			fVec14[(IOTA & 1048575)] = fTemp132;
			fRec120[0] = (fSlow95 + (fSlow0 * fRec120[1]));
			int iTemp133 = int(fRec120[0]);
			double fTemp134 = floor(fRec120[0]);
			double fTemp135 = ((fVec14[((IOTA - (iTemp133 & 1048575)) & 1048575)] * (fTemp134 + (1.0 - fRec120[0]))) + ((fRec120[0] - fTemp134) * fVec14[((IOTA - ((iTemp133 + 1) & 1048575)) & 1048575)]));
			int iTemp136 = (fTemp135 > 1.0);
			int iTemp137 = (fTemp135 < -1.0);
			double fTemp138 = ((double(iTemp136) + ((fTemp135 * double((1 - iTemp137))) * double((1 - iTemp136)))) - double(iTemp137));
			double fTemp139 = (fTemp138 * fRec23[0]);
			fVec15[(IOTA & 262143)] = fTemp139;
			int iTemp140 = int(fTemp130);
			double fTemp141 = (fRec100[0] + (0.5 - floor((fRec100[0] + 0.5))));
			fVec16[0] = fTemp141;
			double fTemp142 = (0.5 * fTemp141);
			double fTemp143 = (65536.0 * (fTemp142 - floor(fTemp142)));
			int iTemp144 = int(fTemp143);
			int iTemp145 = ((fTemp141 > 0.001) * (fVec16[1] <= 0.001));
			fRec121[0] = ((fRec121[1] * double((1 - iTemp145))) + (double(iTemp145) * fRec68[0]));
			double fTemp146 = (fConst2 * (fTemp141 * fRec121[0]));
			double fTemp147 = floor(fTemp146);
			int iTemp148 = int(fTemp146);
			double fTemp149 = (fRec100[0] + (0.25 - floor((fRec100[0] + 0.25))));
			fVec17[0] = fTemp149;
			double fTemp150 = (0.5 * fTemp149);
			double fTemp151 = (65536.0 * (fTemp150 - floor(fTemp150)));
			int iTemp152 = int(fTemp151);
			int iTemp153 = ((fTemp149 > 0.001) * (fVec17[1] <= 0.001));
			fRec122[0] = ((fRec122[1] * double((1 - iTemp153))) + (double(iTemp153) * fRec68[0]));
			double fTemp154 = (fConst2 * (fTemp149 * fRec122[0]));
			double fTemp155 = floor(fTemp154);
			int iTemp156 = int(fTemp154);
			double fTemp157 = (fRec100[0] - floor(fRec100[0]));
			fVec18[0] = fTemp157;
			double fTemp158 = (0.5 * fTemp157);
			double fTemp159 = (65536.0 * (fTemp158 - floor(fTemp158)));
			int iTemp160 = int(fTemp159);
			int iTemp161 = ((fTemp157 > 0.001) * (fVec18[1] <= 0.001));
			fRec123[0] = ((fRec123[1] * double((1 - iTemp161))) + (double(iTemp161) * fRec68[0]));
			double fTemp162 = (fConst2 * (fTemp157 * fRec123[0]));
			double fTemp163 = floor(fTemp162);
			int iTemp164 = int(fTemp162);
			fRec2[0] = (((ftbl0mydspSIG0[iTemp128] + ((fTemp127 - floor(fTemp127)) * (ftbl0mydspSIG0[((iTemp128 + 1) % 65536)] - ftbl0mydspSIG0[iTemp128]))) * (((fTemp131 + (1.0 - fTemp130)) * fVec15[((IOTA - (iTemp140 & 262143)) & 262143)]) + ((fTemp130 - fTemp131) * fVec15[((IOTA - ((iTemp140 + 1) & 262143)) & 262143)]))) + (((ftbl0mydspSIG0[iTemp144] + ((fTemp143 - floor(fTemp143)) * (ftbl0mydspSIG0[((iTemp144 + 1) % 65536)] - ftbl0mydspSIG0[iTemp144]))) * (((fTemp147 + (1.0 - fTemp146)) * fVec15[((IOTA - (iTemp148 & 262143)) & 262143)]) + ((fTemp146 - fTemp147) * fVec15[((IOTA - ((iTemp148 + 1) & 262143)) & 262143)]))) + (((ftbl0mydspSIG0[iTemp152] + ((fTemp151 - floor(fTemp151)) * (ftbl0mydspSIG0[((iTemp152 + 1) % 65536)] - ftbl0mydspSIG0[iTemp152]))) * (((fTemp155 + (1.0 - fTemp154)) * fVec15[((IOTA - (iTemp156 & 262143)) & 262143)]) + ((fTemp154 - fTemp155) * fVec15[((IOTA - ((iTemp156 + 1) & 262143)) & 262143)]))) + ((fTemp138 * (1.0 - fRec23[0])) + ((ftbl0mydspSIG0[iTemp160] + ((fTemp159 - floor(fTemp159)) * (ftbl0mydspSIG0[((iTemp160 + 1) % 65536)] - ftbl0mydspSIG0[iTemp160]))) * (((fTemp163 + (1.0 - fTemp162)) * fVec15[((IOTA - (iTemp164 & 262143)) & 262143)]) + ((fTemp162 - fTemp163) * fVec15[((IOTA - ((iTemp164 + 1) & 262143)) & 262143)])))))));
			fRec125[0] = (fSlow96 + (fSlow0 * fRec125[1]));
			double fTemp165 = (fRec124[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec125[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec124[0] = (fTemp165 - floor(fTemp165));
			double fTemp166 = (fRec124[0] - floor(fRec124[0]));
			fVec19[0] = fTemp166;
			double fTemp167 = (0.5 * fTemp166);
			double fTemp168 = (65536.0 * (fTemp167 - floor(fTemp167)));
			int iTemp169 = int(fTemp168);
			int iTemp170 = ((fTemp166 > 0.001) * (fVec19[1] <= 0.001));
			fRec126[0] = ((fRec126[1] * double((1 - iTemp170))) + (double(iTemp170) * fRec68[0]));
			double fTemp171 = (fConst2 * (fTemp166 * fRec126[0]));
			double fTemp172 = floor(fTemp171);
			fRec127[0] = (fSlow97 + (fSlow0 * fRec127[1]));
			double fTemp173 = floor(fRec127[0]);
			fRec128[0] = (fSlow98 + (fSlow0 * fRec128[1]));
			fRec129[0] = (fSlow99 + (fSlow0 * fRec129[1]));
			fRec130[0] = (fSlow100 + (fSlow0 * fRec130[1]));
			fRec131[0] = (fSlow101 + (fSlow0 * fRec131[1]));
			fRec132[0] = (fSlow102 + (fSlow0 * fRec132[1]));
			fRec133[0] = (fSlow103 + (fSlow0 * fRec133[1]));
			fRec134[0] = (fSlow104 + (fSlow0 * fRec134[1]));
			fRec135[0] = (fSlow105 + (fSlow0 * fRec135[1]));
			fRec136[0] = (fSlow106 + (fSlow0 * fRec136[1]));
			fRec137[0] = (fSlow107 + (fSlow0 * fRec137[1]));
			fRec138[0] = (fSlow108 + (fSlow0 * fRec138[1]));
			fRec139[0] = (fSlow109 + (fSlow0 * fRec139[1]));
			fRec140[0] = (fSlow110 + (fSlow0 * fRec140[1]));
			fRec141[0] = (fSlow111 + (fSlow0 * fRec141[1]));
			fRec142[0] = (fSlow112 + (fSlow0 * fRec142[1]));
			fRec143[0] = (fSlow113 + (fSlow0 * fRec143[1]));
			fRec144[0] = (fSlow114 + (fSlow0 * fRec144[1]));
			double fTemp174 = ((((fRec128[0] * fRec15[1]) * fRec61[0]) * fTemp30) + ((((fRec129[0] * fRec14[1]) * fRec58[0]) * fTemp28) + ((((fRec130[0] * fRec13[1]) * fRec55[0]) * fTemp26) + ((((fRec131[0] * fRec12[1]) * fRec52[0]) * fTemp24) + ((((fRec132[0] * fRec11[1]) * fRec49[0]) * fTemp22) + ((((fRec133[0] * fRec10[1]) * fRec46[0]) * fTemp20) + ((((fRec134[0] * fRec9[1]) * fRec43[0]) * fTemp18) + ((((fRec135[0] * fRec8[1]) * fRec40[0]) * fTemp16) + ((((fRec136[0] * fRec7[1]) * fRec37[0]) * fTemp14) + ((((fRec137[0] * fRec6[1]) * fRec34[0]) * fTemp12) + ((((fRec138[0] * fRec5[1]) * fRec31[0]) * fTemp10) + ((((fRec139[0] * fRec4[1]) * fRec28[0]) * fTemp8) + ((((fRec140[0] * fRec3[1]) * fRec25[0]) * fTemp6) + ((((fRec141[0] * fRec2[1]) * fRec22[0]) * fTemp4) + ((((fRec142[0] * fRec1[1]) * fRec19[0]) * fTemp2) + ((fTemp32 * fRec143[0]) + (((fRec144[0] * fRec0[1]) * fRec17[0]) * fTemp0)))))))))))))))));
			fVec20[(IOTA & 1048575)] = fTemp174;
			int iTemp175 = int(fRec127[0]);
			double fTemp176 = (((fTemp173 + (1.0 - fRec127[0])) * fVec20[((IOTA - (iTemp175 & 1048575)) & 1048575)]) + ((fRec127[0] - fTemp173) * fVec20[((IOTA - ((iTemp175 + 1) & 1048575)) & 1048575)]));
			int iTemp177 = (fTemp176 > 1.0);
			int iTemp178 = (fTemp176 < -1.0);
			double fTemp179 = ((double(iTemp177) + ((fTemp176 * double((1 - iTemp178))) * double((1 - iTemp177)))) - double(iTemp178));
			double fTemp180 = (fRec26[0] * fTemp179);
			fVec21[(IOTA & 262143)] = fTemp180;
			int iTemp181 = int(fTemp171);
			double fTemp182 = (fRec124[0] + (0.25 - floor((fRec124[0] + 0.25))));
			fVec22[0] = fTemp182;
			double fTemp183 = (0.5 * fTemp182);
			double fTemp184 = (65536.0 * (fTemp183 - floor(fTemp183)));
			int iTemp185 = int(fTemp184);
			int iTemp186 = ((fTemp182 > 0.001) * (fVec22[1] <= 0.001));
			fRec145[0] = ((fRec145[1] * double((1 - iTemp186))) + (double(iTemp186) * fRec68[0]));
			double fTemp187 = (fConst2 * (fTemp182 * fRec145[0]));
			double fTemp188 = floor(fTemp187);
			int iTemp189 = int(fTemp187);
			double fTemp190 = (fRec124[0] + (0.5 - floor((fRec124[0] + 0.5))));
			fVec23[0] = fTemp190;
			double fTemp191 = (0.5 * fTemp190);
			double fTemp192 = (65536.0 * (fTemp191 - floor(fTemp191)));
			int iTemp193 = int(fTemp192);
			int iTemp194 = ((fTemp190 > 0.001) * (fVec23[1] <= 0.001));
			fRec146[0] = ((fRec146[1] * double((1 - iTemp194))) + (double(iTemp194) * fRec68[0]));
			double fTemp195 = (fConst2 * (fTemp190 * fRec146[0]));
			double fTemp196 = floor(fTemp195);
			int iTemp197 = int(fTemp195);
			double fTemp198 = (fRec124[0] + (0.75 - floor((fRec124[0] + 0.75))));
			fVec24[0] = fTemp198;
			double fTemp199 = (0.5 * fTemp198);
			double fTemp200 = (65536.0 * (fTemp199 - floor(fTemp199)));
			int iTemp201 = int(fTemp200);
			int iTemp202 = ((fTemp198 > 0.001) * (fVec24[1] <= 0.001));
			fRec147[0] = ((fRec147[1] * double((1 - iTemp202))) + (double(iTemp202) * fRec68[0]));
			double fTemp203 = (fConst2 * (fTemp198 * fRec147[0]));
			double fTemp204 = floor(fTemp203);
			int iTemp205 = int(fTemp203);
			fRec3[0] = ((((((ftbl0mydspSIG0[iTemp169] + ((fTemp168 - floor(fTemp168)) * (ftbl0mydspSIG0[((iTemp169 + 1) % 65536)] - ftbl0mydspSIG0[iTemp169]))) * (((fTemp172 + (1.0 - fTemp171)) * fVec21[((IOTA - (iTemp181 & 262143)) & 262143)]) + ((fTemp171 - fTemp172) * fVec21[((IOTA - ((iTemp181 + 1) & 262143)) & 262143)]))) + ((ftbl0mydspSIG0[iTemp185] + ((fTemp184 - floor(fTemp184)) * (ftbl0mydspSIG0[((iTemp185 + 1) % 65536)] - ftbl0mydspSIG0[iTemp185]))) * (((fTemp188 + (1.0 - fTemp187)) * fVec21[((IOTA - (iTemp189 & 262143)) & 262143)]) + ((fTemp187 - fTemp188) * fVec21[((IOTA - ((iTemp189 + 1) & 262143)) & 262143)])))) + ((ftbl0mydspSIG0[iTemp193] + ((fTemp192 - floor(fTemp192)) * (ftbl0mydspSIG0[((iTemp193 + 1) % 65536)] - ftbl0mydspSIG0[iTemp193]))) * (((fTemp196 + (1.0 - fTemp195)) * fVec21[((IOTA - (iTemp197 & 262143)) & 262143)]) + ((fTemp195 - fTemp196) * fVec21[((IOTA - ((iTemp197 + 1) & 262143)) & 262143)])))) + ((ftbl0mydspSIG0[iTemp201] + ((fTemp200 - floor(fTemp200)) * (ftbl0mydspSIG0[((iTemp201 + 1) % 65536)] - ftbl0mydspSIG0[iTemp201]))) * (((fTemp204 + (1.0 - fTemp203)) * fVec21[((IOTA - (iTemp205 & 262143)) & 262143)]) + ((fTemp203 - fTemp204) * fVec21[((IOTA - ((iTemp205 + 1) & 262143)) & 262143)])))) + ((1.0 - fRec26[0]) * fTemp179));
			fRec149[0] = (fSlow115 + (fSlow0 * fRec149[1]));
			double fTemp206 = (fRec148[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec149[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec148[0] = (fTemp206 - floor(fTemp206));
			double fTemp207 = (fRec148[0] - floor(fRec148[0]));
			fVec25[0] = fTemp207;
			double fTemp208 = (0.5 * fTemp207);
			double fTemp209 = (65536.0 * (fTemp208 - floor(fTemp208)));
			int iTemp210 = int(fTemp209);
			int iTemp211 = ((fTemp207 > 0.001) * (fVec25[1] <= 0.001));
			fRec150[0] = ((fRec150[1] * double((1 - iTemp211))) + (double(iTemp211) * fRec68[0]));
			double fTemp212 = (fConst2 * (fTemp207 * fRec150[0]));
			double fTemp213 = floor(fTemp212);
			fRec151[0] = (fSlow116 + (fSlow0 * fRec151[1]));
			double fTemp214 = floor(fRec151[0]);
			fRec152[0] = (fSlow117 + (fSlow0 * fRec152[1]));
			fRec153[0] = (fSlow118 + (fSlow0 * fRec153[1]));
			fRec154[0] = (fSlow119 + (fSlow0 * fRec154[1]));
			fRec155[0] = (fSlow120 + (fSlow0 * fRec155[1]));
			fRec156[0] = (fSlow121 + (fSlow0 * fRec156[1]));
			fRec157[0] = (fSlow122 + (fSlow0 * fRec157[1]));
			fRec158[0] = (fSlow123 + (fSlow0 * fRec158[1]));
			fRec159[0] = (fSlow124 + (fSlow0 * fRec159[1]));
			fRec160[0] = (fSlow125 + (fSlow0 * fRec160[1]));
			fRec161[0] = (fSlow126 + (fSlow0 * fRec161[1]));
			fRec162[0] = (fSlow127 + (fSlow0 * fRec162[1]));
			fRec163[0] = (fSlow128 + (fSlow0 * fRec163[1]));
			fRec164[0] = (fSlow129 + (fSlow0 * fRec164[1]));
			fRec165[0] = (fSlow130 + (fSlow0 * fRec165[1]));
			fRec166[0] = (fSlow131 + (fSlow0 * fRec166[1]));
			fRec167[0] = (fSlow132 + (fSlow0 * fRec167[1]));
			fRec168[0] = (fSlow133 + (fSlow0 * fRec168[1]));
			double fTemp215 = ((((fRec152[0] * fRec15[1]) * fRec61[0]) * fTemp30) + ((((fRec153[0] * fRec14[1]) * fRec58[0]) * fTemp28) + ((((fRec154[0] * fRec13[1]) * fRec55[0]) * fTemp26) + ((((fRec155[0] * fRec12[1]) * fRec52[0]) * fTemp24) + ((((fRec156[0] * fRec11[1]) * fRec49[0]) * fTemp22) + ((((fRec157[0] * fRec10[1]) * fRec46[0]) * fTemp20) + ((((fRec158[0] * fRec9[1]) * fRec43[0]) * fTemp18) + ((((fRec159[0] * fRec8[1]) * fRec40[0]) * fTemp16) + ((((fRec160[0] * fRec7[1]) * fRec37[0]) * fTemp14) + ((((fRec161[0] * fRec6[1]) * fRec34[0]) * fTemp12) + ((((fRec162[0] * fRec5[1]) * fRec31[0]) * fTemp10) + ((((fRec163[0] * fRec4[1]) * fRec28[0]) * fTemp8) + ((((fRec164[0] * fRec3[1]) * fRec25[0]) * fTemp6) + ((((fRec165[0] * fRec2[1]) * fRec22[0]) * fTemp4) + ((((fRec166[0] * fRec1[1]) * fRec19[0]) * fTemp2) + ((fTemp32 * fRec167[0]) + (((fRec168[0] * fRec0[1]) * fRec17[0]) * fTemp0)))))))))))))))));
			fVec26[(IOTA & 1048575)] = fTemp215;
			int iTemp216 = int(fRec151[0]);
			double fTemp217 = (((fTemp214 + (1.0 - fRec151[0])) * fVec26[((IOTA - (iTemp216 & 1048575)) & 1048575)]) + ((fRec151[0] - fTemp214) * fVec26[((IOTA - ((iTemp216 + 1) & 1048575)) & 1048575)]));
			int iTemp218 = (fTemp217 > 1.0);
			int iTemp219 = (fTemp217 < -1.0);
			double fTemp220 = ((double(iTemp218) + ((fTemp217 * double((1 - iTemp219))) * double((1 - iTemp218)))) - double(iTemp219));
			double fTemp221 = (fRec29[0] * fTemp220);
			fVec27[(IOTA & 262143)] = fTemp221;
			int iTemp222 = int(fTemp212);
			double fTemp223 = (fRec148[0] + (0.25 - floor((fRec148[0] + 0.25))));
			fVec28[0] = fTemp223;
			double fTemp224 = (0.5 * fTemp223);
			double fTemp225 = (65536.0 * (fTemp224 - floor(fTemp224)));
			int iTemp226 = int(fTemp225);
			int iTemp227 = ((fTemp223 > 0.001) * (fVec28[1] <= 0.001));
			fRec169[0] = ((fRec169[1] * double((1 - iTemp227))) + (double(iTemp227) * fRec68[0]));
			double fTemp228 = (fConst2 * (fTemp223 * fRec169[0]));
			double fTemp229 = floor(fTemp228);
			int iTemp230 = int(fTemp228);
			double fTemp231 = (fRec148[0] + (0.5 - floor((fRec148[0] + 0.5))));
			fVec29[0] = fTemp231;
			double fTemp232 = (0.5 * fTemp231);
			double fTemp233 = (65536.0 * (fTemp232 - floor(fTemp232)));
			int iTemp234 = int(fTemp233);
			int iTemp235 = ((fTemp231 > 0.001) * (fVec29[1] <= 0.001));
			fRec170[0] = ((fRec170[1] * double((1 - iTemp235))) + (double(iTemp235) * fRec68[0]));
			double fTemp236 = (fConst2 * (fTemp231 * fRec170[0]));
			double fTemp237 = floor(fTemp236);
			int iTemp238 = int(fTemp236);
			double fTemp239 = (fRec148[0] + (0.75 - floor((fRec148[0] + 0.75))));
			fVec30[0] = fTemp239;
			double fTemp240 = (0.5 * fTemp239);
			double fTemp241 = (65536.0 * (fTemp240 - floor(fTemp240)));
			int iTemp242 = int(fTemp241);
			int iTemp243 = ((fTemp239 > 0.001) * (fVec30[1] <= 0.001));
			fRec171[0] = ((fRec171[1] * double((1 - iTemp243))) + (double(iTemp243) * fRec68[0]));
			double fTemp244 = (fConst2 * (fTemp239 * fRec171[0]));
			double fTemp245 = floor(fTemp244);
			int iTemp246 = int(fTemp244);
			fRec4[0] = ((((((ftbl0mydspSIG0[iTemp210] + ((fTemp209 - floor(fTemp209)) * (ftbl0mydspSIG0[((iTemp210 + 1) % 65536)] - ftbl0mydspSIG0[iTemp210]))) * (((fTemp213 + (1.0 - fTemp212)) * fVec27[((IOTA - (iTemp222 & 262143)) & 262143)]) + ((fTemp212 - fTemp213) * fVec27[((IOTA - ((iTemp222 + 1) & 262143)) & 262143)]))) + ((ftbl0mydspSIG0[iTemp226] + ((fTemp225 - floor(fTemp225)) * (ftbl0mydspSIG0[((iTemp226 + 1) % 65536)] - ftbl0mydspSIG0[iTemp226]))) * (((fTemp229 + (1.0 - fTemp228)) * fVec27[((IOTA - (iTemp230 & 262143)) & 262143)]) + ((fTemp228 - fTemp229) * fVec27[((IOTA - ((iTemp230 + 1) & 262143)) & 262143)])))) + ((ftbl0mydspSIG0[iTemp234] + ((fTemp233 - floor(fTemp233)) * (ftbl0mydspSIG0[((iTemp234 + 1) % 65536)] - ftbl0mydspSIG0[iTemp234]))) * (((fTemp237 + (1.0 - fTemp236)) * fVec27[((IOTA - (iTemp238 & 262143)) & 262143)]) + ((fTemp236 - fTemp237) * fVec27[((IOTA - ((iTemp238 + 1) & 262143)) & 262143)])))) + ((ftbl0mydspSIG0[iTemp242] + ((fTemp241 - floor(fTemp241)) * (ftbl0mydspSIG0[((iTemp242 + 1) % 65536)] - ftbl0mydspSIG0[iTemp242]))) * (((fTemp245 + (1.0 - fTemp244)) * fVec27[((IOTA - (iTemp246 & 262143)) & 262143)]) + ((fTemp244 - fTemp245) * fVec27[((IOTA - ((iTemp246 + 1) & 262143)) & 262143)])))) + ((1.0 - fRec29[0]) * fTemp220));
			fRec172[0] = (fSlow134 + (fSlow0 * fRec172[1]));
			double fTemp247 = floor(fRec172[0]);
			fRec173[0] = (fSlow135 + (fSlow0 * fRec173[1]));
			fRec174[0] = (fSlow136 + (fSlow0 * fRec174[1]));
			fRec175[0] = (fSlow137 + (fSlow0 * fRec175[1]));
			fRec176[0] = (fSlow138 + (fSlow0 * fRec176[1]));
			fRec177[0] = (fSlow139 + (fSlow0 * fRec177[1]));
			fRec178[0] = (fSlow140 + (fSlow0 * fRec178[1]));
			fRec179[0] = (fSlow141 + (fSlow0 * fRec179[1]));
			fRec180[0] = (fSlow142 + (fSlow0 * fRec180[1]));
			fRec181[0] = (fSlow143 + (fSlow0 * fRec181[1]));
			fRec182[0] = (fSlow144 + (fSlow0 * fRec182[1]));
			fRec183[0] = (fSlow145 + (fSlow0 * fRec183[1]));
			fRec184[0] = (fSlow146 + (fSlow0 * fRec184[1]));
			fRec185[0] = (fSlow147 + (fSlow0 * fRec185[1]));
			fRec186[0] = (fSlow148 + (fSlow0 * fRec186[1]));
			fRec187[0] = (fSlow149 + (fSlow0 * fRec187[1]));
			fRec188[0] = (fSlow150 + (fSlow0 * fRec188[1]));
			fRec189[0] = (fSlow151 + (fSlow0 * fRec189[1]));
			double fTemp248 = ((((fRec173[0] * fRec6[1]) * fRec34[0]) * fTemp12) + ((((fRec174[0] * fRec5[1]) * fRec31[0]) * fTemp10) + ((((fRec175[0] * fRec4[1]) * fRec28[0]) * fTemp8) + ((((fRec176[0] * fRec3[1]) * fRec25[0]) * fTemp6) + ((((fRec177[0] * fRec2[1]) * fRec22[0]) * fTemp4) + ((((fRec178[0] * fRec1[1]) * fRec19[0]) * fTemp2) + ((((fRec179[0] * fRec0[1]) * fRec17[0]) * fTemp0) + ((fTemp32 * fRec180[0]) + ((fTemp31 * fRec181[0]) + ((fTemp29 * fRec182[0]) + ((fTemp27 * fRec183[0]) + ((fTemp25 * fRec184[0]) + ((fTemp23 * fRec185[0]) + ((fTemp21 * fRec186[0]) + ((fTemp19 * fRec187[0]) + ((fTemp15 * fRec188[0]) + (fTemp17 * fRec189[0])))))))))))))))));
			fVec31[(IOTA & 1048575)] = fTemp248;
			int iTemp249 = int(fRec172[0]);
			double fTemp250 = (((fTemp247 + (1.0 - fRec172[0])) * fVec31[((IOTA - (iTemp249 & 1048575)) & 1048575)]) + ((fRec172[0] - fTemp247) * fVec31[((IOTA - ((iTemp249 + 1) & 1048575)) & 1048575)]));
			int iTemp251 = (fTemp250 > 1.0);
			int iTemp252 = (fTemp250 < -1.0);
			double fTemp253 = ((double(iTemp251) + ((fTemp250 * double((1 - iTemp252))) * double((1 - iTemp251)))) - double(iTemp252));
			double fTemp254 = (fRec32[0] * fTemp253);
			fVec32[(IOTA & 262143)] = fTemp254;
			fRec191[0] = (fSlow152 + (fSlow0 * fRec191[1]));
			double fTemp255 = (fRec190[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec191[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec190[0] = (fTemp255 - floor(fTemp255));
			double fTemp256 = (fRec190[0] + (0.75 - floor((fRec190[0] + 0.75))));
			fVec33[0] = fTemp256;
			int iTemp257 = (fTemp256 > 0.001);
			int iTemp258 = (fVec33[1] <= 0.001);
			fRec192[0] = ((fRec192[1] * double((1 - (iTemp257 * iTemp258)))) + ((fRec68[0] * double(iTemp257)) * double(iTemp258)));
			double fTemp259 = (fConst2 * (fTemp256 * fRec192[0]));
			int iTemp260 = int(fTemp259);
			double fTemp261 = floor(fTemp259);
			double fTemp262 = (0.5 * fTemp256);
			double fTemp263 = (65536.0 * (fTemp262 - floor(fTemp262)));
			int iTemp264 = int(fTemp263);
			double fTemp265 = (fRec190[0] + (0.5 - floor((fRec190[0] + 0.5))));
			fVec34[0] = fTemp265;
			int iTemp266 = (fTemp265 > 0.001);
			int iTemp267 = (fVec34[1] <= 0.001);
			fRec193[0] = ((fRec193[1] * double((1 - (iTemp266 * iTemp267)))) + ((fRec68[0] * double(iTemp266)) * double(iTemp267)));
			double fTemp268 = (fConst2 * (fTemp265 * fRec193[0]));
			int iTemp269 = int(fTemp268);
			double fTemp270 = floor(fTemp268);
			double fTemp271 = (0.5 * fTemp265);
			double fTemp272 = (65536.0 * (fTemp271 - floor(fTemp271)));
			int iTemp273 = int(fTemp272);
			double fTemp274 = (fRec190[0] - floor(fRec190[0]));
			fVec35[0] = fTemp274;
			double fTemp275 = (0.5 * fTemp274);
			double fTemp276 = (65536.0 * (fTemp275 - floor(fTemp275)));
			int iTemp277 = int(fTemp276);
			int iTemp278 = (fTemp274 > 0.001);
			int iTemp279 = (fVec35[1] <= 0.001);
			fRec194[0] = ((fRec194[1] * double((1 - (iTemp278 * iTemp279)))) + ((fRec68[0] * double(iTemp278)) * double(iTemp279)));
			double fTemp280 = (fConst2 * (fTemp274 * fRec194[0]));
			double fTemp281 = floor(fTemp280);
			int iTemp282 = int(fTemp280);
			double fTemp283 = (fRec190[0] + (0.25 - floor((fRec190[0] + 0.25))));
			fVec36[0] = fTemp283;
			double fTemp284 = (0.5 * fTemp283);
			double fTemp285 = (65536.0 * (fTemp284 - floor(fTemp284)));
			int iTemp286 = int(fTemp285);
			int iTemp287 = (fTemp283 > 0.001);
			int iTemp288 = (fVec36[1] <= 0.001);
			fRec195[0] = ((fRec195[1] * double((1 - (iTemp287 * iTemp288)))) + ((fRec68[0] * double(iTemp287)) * double(iTemp288)));
			double fTemp289 = (fConst2 * (fTemp283 * fRec195[0]));
			double fTemp290 = floor(fTemp289);
			int iTemp291 = int(fTemp289);
			fRec5[0] = (((((((fVec32[((IOTA - (iTemp260 & 262143)) & 262143)] * (fTemp261 + (1.0 - fTemp259))) + (fVec32[((IOTA - ((iTemp260 + 1) & 262143)) & 262143)] * (fTemp259 - fTemp261))) * (ftbl0mydspSIG0[iTemp264] + ((fTemp263 - floor(fTemp263)) * (ftbl0mydspSIG0[((iTemp264 + 1) % 65536)] - ftbl0mydspSIG0[iTemp264])))) + (((fVec32[((IOTA - (iTemp269 & 262143)) & 262143)] * (fTemp270 + (1.0 - fTemp268))) + (fVec32[((IOTA - ((iTemp269 + 1) & 262143)) & 262143)] * (fTemp268 - fTemp270))) * (ftbl0mydspSIG0[iTemp273] + ((fTemp272 - floor(fTemp272)) * (ftbl0mydspSIG0[((iTemp273 + 1) % 65536)] - ftbl0mydspSIG0[iTemp273]))))) + ((1.0 - fRec32[0]) * fTemp253)) + ((ftbl0mydspSIG0[iTemp277] + ((fTemp276 - floor(fTemp276)) * (ftbl0mydspSIG0[((iTemp277 + 1) % 65536)] - ftbl0mydspSIG0[iTemp277]))) * (((fTemp281 + (1.0 - fTemp280)) * fVec32[((IOTA - (iTemp282 & 262143)) & 262143)]) + ((fTemp280 - fTemp281) * fVec32[((IOTA - ((iTemp282 + 1) & 262143)) & 262143)])))) + ((ftbl0mydspSIG0[iTemp286] + ((fTemp285 - floor(fTemp285)) * (ftbl0mydspSIG0[((iTemp286 + 1) % 65536)] - ftbl0mydspSIG0[iTemp286]))) * (((fTemp290 + (1.0 - fTemp289)) * fVec32[((IOTA - (iTemp291 & 262143)) & 262143)]) + ((fTemp289 - fTemp290) * fVec32[((IOTA - ((iTemp291 + 1) & 262143)) & 262143)]))));
			fRec196[0] = (fSlow153 + (fSlow0 * fRec196[1]));
			fRec197[0] = (fSlow154 + (fSlow0 * fRec197[1]));
			fRec198[0] = (fSlow155 + (fSlow0 * fRec198[1]));
			fRec199[0] = (fSlow156 + (fSlow0 * fRec199[1]));
			fRec200[0] = (fSlow157 + (fSlow0 * fRec200[1]));
			fRec201[0] = (fSlow158 + (fSlow0 * fRec201[1]));
			fRec202[0] = (fSlow159 + (fSlow0 * fRec202[1]));
			fRec203[0] = (fSlow160 + (fSlow0 * fRec203[1]));
			fRec204[0] = (fSlow161 + (fSlow0 * fRec204[1]));
			fRec205[0] = (fSlow162 + (fSlow0 * fRec205[1]));
			fRec206[0] = (fSlow163 + (fSlow0 * fRec206[1]));
			fRec207[0] = (fSlow164 + (fSlow0 * fRec207[1]));
			fRec208[0] = (fSlow165 + (fSlow0 * fRec208[1]));
			fRec209[0] = (fSlow166 + (fSlow0 * fRec209[1]));
			fRec210[0] = (fSlow167 + (fSlow0 * fRec210[1]));
			fRec211[0] = (fSlow168 + (fSlow0 * fRec211[1]));
			fRec212[0] = (fSlow169 + (fSlow0 * fRec212[1]));
			double fTemp292 = (((((((((((((((((fTemp1 * fRec196[0]) + (fTemp3 * fRec197[0])) + (fTemp5 * fRec198[0])) + (fTemp7 * fRec199[0])) + (fTemp9 * fRec200[0])) + (fTemp11 * fRec201[0])) + (fTemp13 * fRec202[0])) + (fTemp15 * fRec203[0])) + (fTemp17 * fRec204[0])) + (fTemp19 * fRec205[0])) + (fTemp21 * fRec206[0])) + (fTemp23 * fRec207[0])) + (fTemp25 * fRec208[0])) + (fTemp27 * fRec209[0])) + (fTemp29 * fRec210[0])) + (fTemp31 * fRec211[0])) + (fTemp32 * fRec212[0]));
			fVec37[(IOTA & 1048575)] = fTemp292;
			fRec213[0] = (fSlow170 + (fSlow0 * fRec213[1]));
			int iTemp293 = int(fRec213[0]);
			double fTemp294 = floor(fRec213[0]);
			double fTemp295 = ((fVec37[((IOTA - (iTemp293 & 1048575)) & 1048575)] * (fTemp294 + (1.0 - fRec213[0]))) + ((fRec213[0] - fTemp294) * fVec37[((IOTA - ((iTemp293 + 1) & 1048575)) & 1048575)]));
			int iTemp296 = (fTemp295 > 1.0);
			int iTemp297 = (fTemp295 < -1.0);
			double fTemp298 = ((double(iTemp296) + ((fTemp295 * double((1 - iTemp297))) * double((1 - iTemp296)))) - double(iTemp297));
			double fTemp299 = (fRec35[0] * fTemp298);
			fVec38[(IOTA & 262143)] = fTemp299;
			fRec215[0] = (fSlow171 + (fSlow0 * fRec215[1]));
			double fTemp300 = (fRec214[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec215[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec214[0] = (fTemp300 - floor(fTemp300));
			double fTemp301 = (fRec214[0] - floor(fRec214[0]));
			fVec39[0] = fTemp301;
			int iTemp302 = (fTemp301 > 0.001);
			int iTemp303 = (fVec39[1] <= 0.001);
			fRec216[0] = ((fRec216[1] * double((1 - (iTemp302 * iTemp303)))) + ((fRec68[0] * double(iTemp302)) * double(iTemp303)));
			double fTemp304 = (fConst2 * (fTemp301 * fRec216[0]));
			int iTemp305 = int(fTemp304);
			double fTemp306 = floor(fTemp304);
			double fTemp307 = (0.5 * fTemp301);
			double fTemp308 = (65536.0 * (fTemp307 - floor(fTemp307)));
			int iTemp309 = int(fTemp308);
			double fTemp310 = (fRec214[0] + (0.25 - floor((fRec214[0] + 0.25))));
			fVec40[0] = fTemp310;
			int iTemp311 = (fTemp310 > 0.001);
			int iTemp312 = (fVec40[1] <= 0.001);
			fRec217[0] = ((fRec217[1] * double((1 - (iTemp311 * iTemp312)))) + ((fRec68[0] * double(iTemp311)) * double(iTemp312)));
			double fTemp313 = (fConst2 * (fTemp310 * fRec217[0]));
			int iTemp314 = int(fTemp313);
			double fTemp315 = floor(fTemp313);
			double fTemp316 = (0.5 * fTemp310);
			double fTemp317 = (65536.0 * (fTemp316 - floor(fTemp316)));
			int iTemp318 = int(fTemp317);
			double fTemp319 = (fRec214[0] + (0.5 - floor((fRec214[0] + 0.5))));
			fVec41[0] = fTemp319;
			int iTemp320 = (fTemp319 > 0.001);
			int iTemp321 = (fVec41[1] <= 0.001);
			fRec218[0] = ((fRec218[1] * double((1 - (iTemp320 * iTemp321)))) + ((fRec68[0] * double(iTemp320)) * double(iTemp321)));
			double fTemp322 = (fConst2 * (fTemp319 * fRec218[0]));
			int iTemp323 = int(fTemp322);
			double fTemp324 = floor(fTemp322);
			double fTemp325 = (0.5 * fTemp319);
			double fTemp326 = (65536.0 * (fTemp325 - floor(fTemp325)));
			int iTemp327 = int(fTemp326);
			double fTemp328 = (fRec214[0] + (0.75 - floor((fRec214[0] + 0.75))));
			fVec42[0] = fTemp328;
			int iTemp329 = (fTemp328 > 0.001);
			int iTemp330 = (fVec42[1] <= 0.001);
			fRec219[0] = ((fRec219[1] * double((1 - (iTemp329 * iTemp330)))) + ((fRec68[0] * double(iTemp329)) * double(iTemp330)));
			double fTemp331 = (fConst2 * (fTemp328 * fRec219[0]));
			int iTemp332 = int(fTemp331);
			double fTemp333 = floor(fTemp331);
			double fTemp334 = (0.5 * fTemp328);
			double fTemp335 = (65536.0 * (fTemp334 - floor(fTemp334)));
			int iTemp336 = int(fTemp335);
			fRec6[0] = (((((((fVec38[((IOTA - (iTemp305 & 262143)) & 262143)] * (fTemp306 + (1.0 - fTemp304))) + ((fTemp304 - fTemp306) * fVec38[((IOTA - ((iTemp305 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp309] + ((fTemp308 - floor(fTemp308)) * (ftbl0mydspSIG0[((iTemp309 + 1) % 65536)] - ftbl0mydspSIG0[iTemp309])))) + (((fVec38[((IOTA - (iTemp314 & 262143)) & 262143)] * (fTemp315 + (1.0 - fTemp313))) + ((fTemp313 - fTemp315) * fVec38[((IOTA - ((iTemp314 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp318] + ((fTemp317 - floor(fTemp317)) * (ftbl0mydspSIG0[((iTemp318 + 1) % 65536)] - ftbl0mydspSIG0[iTemp318]))))) + (((fVec38[((IOTA - (iTemp323 & 262143)) & 262143)] * (fTemp324 + (1.0 - fTemp322))) + ((fTemp322 - fTemp324) * fVec38[((IOTA - ((iTemp323 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp327] + ((fTemp326 - floor(fTemp326)) * (ftbl0mydspSIG0[((iTemp327 + 1) % 65536)] - ftbl0mydspSIG0[iTemp327]))))) + (((fVec38[((IOTA - (iTemp332 & 262143)) & 262143)] * (fTemp333 + (1.0 - fTemp331))) + ((fTemp331 - fTemp333) * fVec38[((IOTA - ((iTemp332 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp336] + ((fTemp335 - floor(fTemp335)) * (ftbl0mydspSIG0[((iTemp336 + 1) % 65536)] - ftbl0mydspSIG0[iTemp336]))))) + (fTemp298 * (1.0 - fRec35[0])));
			fRec220[0] = (fSlow172 + (fSlow0 * fRec220[1]));
			fRec221[0] = (fSlow173 + (fSlow0 * fRec221[1]));
			fRec222[0] = (fSlow174 + (fSlow0 * fRec222[1]));
			fRec223[0] = (fSlow175 + (fSlow0 * fRec223[1]));
			fRec224[0] = (fSlow176 + (fSlow0 * fRec224[1]));
			fRec225[0] = (fSlow177 + (fSlow0 * fRec225[1]));
			fRec226[0] = (fSlow178 + (fSlow0 * fRec226[1]));
			fRec227[0] = (fSlow179 + (fSlow0 * fRec227[1]));
			fRec228[0] = (fSlow180 + (fSlow0 * fRec228[1]));
			fRec229[0] = (fSlow181 + (fSlow0 * fRec229[1]));
			fRec230[0] = (fSlow182 + (fSlow0 * fRec230[1]));
			fRec231[0] = (fSlow183 + (fSlow0 * fRec231[1]));
			fRec232[0] = (fSlow184 + (fSlow0 * fRec232[1]));
			fRec233[0] = (fSlow185 + (fSlow0 * fRec233[1]));
			fRec234[0] = (fSlow186 + (fSlow0 * fRec234[1]));
			fRec235[0] = (fSlow187 + (fSlow0 * fRec235[1]));
			fRec236[0] = (fSlow188 + (fSlow0 * fRec236[1]));
			double fTemp337 = (((((((((((((((((fTemp1 * fRec220[0]) + (fTemp3 * fRec221[0])) + (fTemp5 * fRec222[0])) + (fTemp7 * fRec223[0])) + (fTemp9 * fRec224[0])) + (fTemp11 * fRec225[0])) + (fTemp13 * fRec226[0])) + (fTemp15 * fRec227[0])) + (fTemp17 * fRec228[0])) + (fTemp19 * fRec229[0])) + (fTemp21 * fRec230[0])) + (fTemp23 * fRec231[0])) + (fTemp25 * fRec232[0])) + (fTemp27 * fRec233[0])) + (fTemp29 * fRec234[0])) + (fTemp31 * fRec235[0])) + (fTemp32 * fRec236[0]));
			fVec43[(IOTA & 1048575)] = fTemp337;
			fRec237[0] = (fSlow189 + (fSlow0 * fRec237[1]));
			int iTemp338 = int(fRec237[0]);
			double fTemp339 = floor(fRec237[0]);
			double fTemp340 = ((fVec43[((IOTA - (iTemp338 & 1048575)) & 1048575)] * (fTemp339 + (1.0 - fRec237[0]))) + ((fRec237[0] - fTemp339) * fVec43[((IOTA - ((iTemp338 + 1) & 1048575)) & 1048575)]));
			int iTemp341 = (fTemp340 > 1.0);
			int iTemp342 = (fTemp340 < -1.0);
			double fTemp343 = ((double(iTemp341) + ((fTemp340 * double((1 - iTemp342))) * double((1 - iTemp341)))) - double(iTemp342));
			double fTemp344 = (fRec38[0] * fTemp343);
			fVec44[(IOTA & 262143)] = fTemp344;
			fRec239[0] = (fSlow190 + (fSlow0 * fRec239[1]));
			double fTemp345 = (fRec238[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec239[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec238[0] = (fTemp345 - floor(fTemp345));
			double fTemp346 = (fRec238[0] - floor(fRec238[0]));
			fVec45[0] = fTemp346;
			int iTemp347 = (fTemp346 > 0.001);
			int iTemp348 = (fVec45[1] <= 0.001);
			fRec240[0] = ((fRec240[1] * double((1 - (iTemp347 * iTemp348)))) + ((fRec68[0] * double(iTemp347)) * double(iTemp348)));
			double fTemp349 = (fConst2 * (fTemp346 * fRec240[0]));
			int iTemp350 = int(fTemp349);
			double fTemp351 = floor(fTemp349);
			double fTemp352 = (0.5 * fTemp346);
			double fTemp353 = (65536.0 * (fTemp352 - floor(fTemp352)));
			int iTemp354 = int(fTemp353);
			double fTemp355 = (fRec238[0] + (0.25 - floor((fRec238[0] + 0.25))));
			fVec46[0] = fTemp355;
			int iTemp356 = (fTemp355 > 0.001);
			int iTemp357 = (fVec46[1] <= 0.001);
			fRec241[0] = ((fRec241[1] * double((1 - (iTemp356 * iTemp357)))) + ((fRec68[0] * double(iTemp356)) * double(iTemp357)));
			double fTemp358 = (fConst2 * (fTemp355 * fRec241[0]));
			int iTemp359 = int(fTemp358);
			double fTemp360 = floor(fTemp358);
			double fTemp361 = (0.5 * fTemp355);
			double fTemp362 = (65536.0 * (fTemp361 - floor(fTemp361)));
			int iTemp363 = int(fTemp362);
			double fTemp364 = (fRec238[0] + (0.5 - floor((fRec238[0] + 0.5))));
			fVec47[0] = fTemp364;
			int iTemp365 = (fTemp364 > 0.001);
			int iTemp366 = (fVec47[1] <= 0.001);
			fRec242[0] = ((fRec242[1] * double((1 - (iTemp365 * iTemp366)))) + ((fRec68[0] * double(iTemp365)) * double(iTemp366)));
			double fTemp367 = (fConst2 * (fTemp364 * fRec242[0]));
			int iTemp368 = int(fTemp367);
			double fTemp369 = floor(fTemp367);
			double fTemp370 = (0.5 * fTemp364);
			double fTemp371 = (65536.0 * (fTemp370 - floor(fTemp370)));
			int iTemp372 = int(fTemp371);
			double fTemp373 = (fRec238[0] + (0.75 - floor((fRec238[0] + 0.75))));
			fVec48[0] = fTemp373;
			int iTemp374 = (fTemp373 > 0.001);
			int iTemp375 = (fVec48[1] <= 0.001);
			fRec243[0] = ((fRec243[1] * double((1 - (iTemp374 * iTemp375)))) + ((fRec68[0] * double(iTemp374)) * double(iTemp375)));
			double fTemp376 = (fConst2 * (fTemp373 * fRec243[0]));
			int iTemp377 = int(fTemp376);
			double fTemp378 = floor(fTemp376);
			double fTemp379 = (0.5 * fTemp373);
			double fTemp380 = (65536.0 * (fTemp379 - floor(fTemp379)));
			int iTemp381 = int(fTemp380);
			fRec7[0] = (((((((fVec44[((IOTA - (iTemp350 & 262143)) & 262143)] * (fTemp351 + (1.0 - fTemp349))) + ((fTemp349 - fTemp351) * fVec44[((IOTA - ((iTemp350 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp354] + ((fTemp353 - floor(fTemp353)) * (ftbl0mydspSIG0[((iTemp354 + 1) % 65536)] - ftbl0mydspSIG0[iTemp354])))) + (((fVec44[((IOTA - (iTemp359 & 262143)) & 262143)] * (fTemp360 + (1.0 - fTemp358))) + ((fTemp358 - fTemp360) * fVec44[((IOTA - ((iTemp359 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp363] + ((fTemp362 - floor(fTemp362)) * (ftbl0mydspSIG0[((iTemp363 + 1) % 65536)] - ftbl0mydspSIG0[iTemp363]))))) + (((fVec44[((IOTA - (iTemp368 & 262143)) & 262143)] * (fTemp369 + (1.0 - fTemp367))) + ((fTemp367 - fTemp369) * fVec44[((IOTA - ((iTemp368 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp372] + ((fTemp371 - floor(fTemp371)) * (ftbl0mydspSIG0[((iTemp372 + 1) % 65536)] - ftbl0mydspSIG0[iTemp372]))))) + (((fVec44[((IOTA - (iTemp377 & 262143)) & 262143)] * (fTemp378 + (1.0 - fTemp376))) + ((fTemp376 - fTemp378) * fVec44[((IOTA - ((iTemp377 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp381] + ((fTemp380 - floor(fTemp380)) * (ftbl0mydspSIG0[((iTemp381 + 1) % 65536)] - ftbl0mydspSIG0[iTemp381]))))) + (fTemp343 * (1.0 - fRec38[0])));
			fRec244[0] = (fSlow191 + (fSlow0 * fRec244[1]));
			fRec245[0] = (fSlow192 + (fSlow0 * fRec245[1]));
			fRec246[0] = (fSlow193 + (fSlow0 * fRec246[1]));
			fRec247[0] = (fSlow194 + (fSlow0 * fRec247[1]));
			fRec248[0] = (fSlow195 + (fSlow0 * fRec248[1]));
			fRec249[0] = (fSlow196 + (fSlow0 * fRec249[1]));
			fRec250[0] = (fSlow197 + (fSlow0 * fRec250[1]));
			fRec251[0] = (fSlow198 + (fSlow0 * fRec251[1]));
			fRec252[0] = (fSlow199 + (fSlow0 * fRec252[1]));
			fRec253[0] = (fSlow200 + (fSlow0 * fRec253[1]));
			fRec254[0] = (fSlow201 + (fSlow0 * fRec254[1]));
			fRec255[0] = (fSlow202 + (fSlow0 * fRec255[1]));
			fRec256[0] = (fSlow203 + (fSlow0 * fRec256[1]));
			fRec257[0] = (fSlow204 + (fSlow0 * fRec257[1]));
			fRec258[0] = (fSlow205 + (fSlow0 * fRec258[1]));
			fRec259[0] = (fSlow206 + (fSlow0 * fRec259[1]));
			fRec260[0] = (fSlow207 + (fSlow0 * fRec260[1]));
			double fTemp382 = (((((((((((((((((fTemp1 * fRec244[0]) + (fTemp3 * fRec245[0])) + (fTemp5 * fRec246[0])) + (fTemp7 * fRec247[0])) + (fTemp9 * fRec248[0])) + (fTemp11 * fRec249[0])) + (fTemp13 * fRec250[0])) + (fTemp15 * fRec251[0])) + (fTemp17 * fRec252[0])) + (fTemp19 * fRec253[0])) + (fTemp21 * fRec254[0])) + (fTemp23 * fRec255[0])) + (fTemp25 * fRec256[0])) + (fTemp27 * fRec257[0])) + (fTemp29 * fRec258[0])) + (fTemp31 * fRec259[0])) + (fTemp32 * fRec260[0]));
			fVec49[(IOTA & 1048575)] = fTemp382;
			fRec261[0] = (fSlow208 + (fSlow0 * fRec261[1]));
			int iTemp383 = int(fRec261[0]);
			double fTemp384 = floor(fRec261[0]);
			double fTemp385 = ((fVec49[((IOTA - (iTemp383 & 1048575)) & 1048575)] * (fTemp384 + (1.0 - fRec261[0]))) + ((fRec261[0] - fTemp384) * fVec49[((IOTA - ((iTemp383 + 1) & 1048575)) & 1048575)]));
			int iTemp386 = (fTemp385 > 1.0);
			int iTemp387 = (fTemp385 < -1.0);
			double fTemp388 = ((double(iTemp386) + ((fTemp385 * double((1 - iTemp387))) * double((1 - iTemp386)))) - double(iTemp387));
			double fTemp389 = (fRec41[0] * fTemp388);
			fVec50[(IOTA & 262143)] = fTemp389;
			fRec263[0] = (fSlow209 + (fSlow0 * fRec263[1]));
			double fTemp390 = (fRec262[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec263[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec262[0] = (fTemp390 - floor(fTemp390));
			double fTemp391 = (fRec262[0] - floor(fRec262[0]));
			fVec51[0] = fTemp391;
			int iTemp392 = (fTemp391 > 0.001);
			int iTemp393 = (fVec51[1] <= 0.001);
			fRec264[0] = ((fRec264[1] * double((1 - (iTemp392 * iTemp393)))) + ((fRec68[0] * double(iTemp392)) * double(iTemp393)));
			double fTemp394 = (fConst2 * (fTemp391 * fRec264[0]));
			int iTemp395 = int(fTemp394);
			double fTemp396 = floor(fTemp394);
			double fTemp397 = (0.5 * fTemp391);
			double fTemp398 = (65536.0 * (fTemp397 - floor(fTemp397)));
			int iTemp399 = int(fTemp398);
			double fTemp400 = (fRec262[0] + (0.25 - floor((fRec262[0] + 0.25))));
			fVec52[0] = fTemp400;
			int iTemp401 = (fTemp400 > 0.001);
			int iTemp402 = (fVec52[1] <= 0.001);
			fRec265[0] = ((fRec265[1] * double((1 - (iTemp401 * iTemp402)))) + ((fRec68[0] * double(iTemp401)) * double(iTemp402)));
			double fTemp403 = (fConst2 * (fTemp400 * fRec265[0]));
			int iTemp404 = int(fTemp403);
			double fTemp405 = floor(fTemp403);
			double fTemp406 = (0.5 * fTemp400);
			double fTemp407 = (65536.0 * (fTemp406 - floor(fTemp406)));
			int iTemp408 = int(fTemp407);
			double fTemp409 = (fRec262[0] + (0.5 - floor((fRec262[0] + 0.5))));
			fVec53[0] = fTemp409;
			int iTemp410 = (fTemp409 > 0.001);
			int iTemp411 = (fVec53[1] <= 0.001);
			fRec266[0] = ((fRec266[1] * double((1 - (iTemp410 * iTemp411)))) + ((fRec68[0] * double(iTemp410)) * double(iTemp411)));
			double fTemp412 = (fConst2 * (fTemp409 * fRec266[0]));
			int iTemp413 = int(fTemp412);
			double fTemp414 = floor(fTemp412);
			double fTemp415 = (0.5 * fTemp409);
			double fTemp416 = (65536.0 * (fTemp415 - floor(fTemp415)));
			int iTemp417 = int(fTemp416);
			double fTemp418 = (fRec262[0] + (0.75 - floor((fRec262[0] + 0.75))));
			fVec54[0] = fTemp418;
			int iTemp419 = (fTemp418 > 0.001);
			int iTemp420 = (fVec54[1] <= 0.001);
			fRec267[0] = ((fRec267[1] * double((1 - (iTemp419 * iTemp420)))) + ((fRec68[0] * double(iTemp419)) * double(iTemp420)));
			double fTemp421 = (fConst2 * (fTemp418 * fRec267[0]));
			int iTemp422 = int(fTemp421);
			double fTemp423 = floor(fTemp421);
			double fTemp424 = (0.5 * fTemp418);
			double fTemp425 = (65536.0 * (fTemp424 - floor(fTemp424)));
			int iTemp426 = int(fTemp425);
			fRec8[0] = (((((((fVec50[((IOTA - (iTemp395 & 262143)) & 262143)] * (fTemp396 + (1.0 - fTemp394))) + ((fTemp394 - fTemp396) * fVec50[((IOTA - ((iTemp395 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp399] + ((fTemp398 - floor(fTemp398)) * (ftbl0mydspSIG0[((iTemp399 + 1) % 65536)] - ftbl0mydspSIG0[iTemp399])))) + (((fVec50[((IOTA - (iTemp404 & 262143)) & 262143)] * (fTemp405 + (1.0 - fTemp403))) + ((fTemp403 - fTemp405) * fVec50[((IOTA - ((iTemp404 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp408] + ((fTemp407 - floor(fTemp407)) * (ftbl0mydspSIG0[((iTemp408 + 1) % 65536)] - ftbl0mydspSIG0[iTemp408]))))) + (((fVec50[((IOTA - (iTemp413 & 262143)) & 262143)] * (fTemp414 + (1.0 - fTemp412))) + ((fTemp412 - fTemp414) * fVec50[((IOTA - ((iTemp413 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp417] + ((fTemp416 - floor(fTemp416)) * (ftbl0mydspSIG0[((iTemp417 + 1) % 65536)] - ftbl0mydspSIG0[iTemp417]))))) + (((fVec50[((IOTA - (iTemp422 & 262143)) & 262143)] * (fTemp423 + (1.0 - fTemp421))) + ((fTemp421 - fTemp423) * fVec50[((IOTA - ((iTemp422 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp426] + ((fTemp425 - floor(fTemp425)) * (ftbl0mydspSIG0[((iTemp426 + 1) % 65536)] - ftbl0mydspSIG0[iTemp426]))))) + (fTemp388 * (1.0 - fRec41[0])));
			fRec268[0] = (fSlow210 + (fSlow0 * fRec268[1]));
			fRec269[0] = (fSlow211 + (fSlow0 * fRec269[1]));
			fRec270[0] = (fSlow212 + (fSlow0 * fRec270[1]));
			fRec271[0] = (fSlow213 + (fSlow0 * fRec271[1]));
			fRec272[0] = (fSlow214 + (fSlow0 * fRec272[1]));
			fRec273[0] = (fSlow215 + (fSlow0 * fRec273[1]));
			fRec274[0] = (fSlow216 + (fSlow0 * fRec274[1]));
			fRec275[0] = (fSlow217 + (fSlow0 * fRec275[1]));
			fRec276[0] = (fSlow218 + (fSlow0 * fRec276[1]));
			fRec277[0] = (fSlow219 + (fSlow0 * fRec277[1]));
			fRec278[0] = (fSlow220 + (fSlow0 * fRec278[1]));
			fRec279[0] = (fSlow221 + (fSlow0 * fRec279[1]));
			fRec280[0] = (fSlow222 + (fSlow0 * fRec280[1]));
			fRec281[0] = (fSlow223 + (fSlow0 * fRec281[1]));
			fRec282[0] = (fSlow224 + (fSlow0 * fRec282[1]));
			fRec283[0] = (fSlow225 + (fSlow0 * fRec283[1]));
			fRec284[0] = (fSlow226 + (fSlow0 * fRec284[1]));
			double fTemp427 = (((((((((((((((((fTemp1 * fRec268[0]) + (fTemp3 * fRec269[0])) + (fTemp5 * fRec270[0])) + (fTemp7 * fRec271[0])) + (fTemp9 * fRec272[0])) + (fTemp11 * fRec273[0])) + (fTemp13 * fRec274[0])) + (fTemp15 * fRec275[0])) + (fTemp17 * fRec276[0])) + (fTemp19 * fRec277[0])) + (fTemp21 * fRec278[0])) + (fTemp23 * fRec279[0])) + (fTemp25 * fRec280[0])) + (fTemp27 * fRec281[0])) + (fTemp29 * fRec282[0])) + (fTemp31 * fRec283[0])) + (fTemp32 * fRec284[0]));
			fVec55[(IOTA & 1048575)] = fTemp427;
			fRec285[0] = (fSlow227 + (fSlow0 * fRec285[1]));
			int iTemp428 = int(fRec285[0]);
			double fTemp429 = floor(fRec285[0]);
			double fTemp430 = ((fVec55[((IOTA - (iTemp428 & 1048575)) & 1048575)] * (fTemp429 + (1.0 - fRec285[0]))) + ((fRec285[0] - fTemp429) * fVec55[((IOTA - ((iTemp428 + 1) & 1048575)) & 1048575)]));
			int iTemp431 = (fTemp430 > 1.0);
			int iTemp432 = (fTemp430 < -1.0);
			double fTemp433 = ((double(iTemp431) + ((fTemp430 * double((1 - iTemp432))) * double((1 - iTemp431)))) - double(iTemp432));
			double fTemp434 = (fRec44[0] * fTemp433);
			fVec56[(IOTA & 262143)] = fTemp434;
			fRec287[0] = (fSlow228 + (fSlow0 * fRec287[1]));
			double fTemp435 = (fRec286[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec287[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec286[0] = (fTemp435 - floor(fTemp435));
			double fTemp436 = (fRec286[0] - floor(fRec286[0]));
			fVec57[0] = fTemp436;
			int iTemp437 = (fTemp436 > 0.001);
			int iTemp438 = (fVec57[1] <= 0.001);
			fRec288[0] = ((fRec288[1] * double((1 - (iTemp437 * iTemp438)))) + ((fRec68[0] * double(iTemp437)) * double(iTemp438)));
			double fTemp439 = (fConst2 * (fTemp436 * fRec288[0]));
			int iTemp440 = int(fTemp439);
			double fTemp441 = floor(fTemp439);
			double fTemp442 = (0.5 * fTemp436);
			double fTemp443 = (65536.0 * (fTemp442 - floor(fTemp442)));
			int iTemp444 = int(fTemp443);
			double fTemp445 = (fRec286[0] + (0.25 - floor((fRec286[0] + 0.25))));
			fVec58[0] = fTemp445;
			int iTemp446 = (fTemp445 > 0.001);
			int iTemp447 = (fVec58[1] <= 0.001);
			fRec289[0] = ((fRec289[1] * double((1 - (iTemp446 * iTemp447)))) + ((fRec68[0] * double(iTemp446)) * double(iTemp447)));
			double fTemp448 = (fConst2 * (fTemp445 * fRec289[0]));
			int iTemp449 = int(fTemp448);
			double fTemp450 = floor(fTemp448);
			double fTemp451 = (0.5 * fTemp445);
			double fTemp452 = (65536.0 * (fTemp451 - floor(fTemp451)));
			int iTemp453 = int(fTemp452);
			double fTemp454 = (fRec286[0] + (0.5 - floor((fRec286[0] + 0.5))));
			fVec59[0] = fTemp454;
			int iTemp455 = (fTemp454 > 0.001);
			int iTemp456 = (fVec59[1] <= 0.001);
			fRec290[0] = ((fRec290[1] * double((1 - (iTemp455 * iTemp456)))) + ((fRec68[0] * double(iTemp455)) * double(iTemp456)));
			double fTemp457 = (fConst2 * (fTemp454 * fRec290[0]));
			int iTemp458 = int(fTemp457);
			double fTemp459 = floor(fTemp457);
			double fTemp460 = (0.5 * fTemp454);
			double fTemp461 = (65536.0 * (fTemp460 - floor(fTemp460)));
			int iTemp462 = int(fTemp461);
			double fTemp463 = (fRec286[0] + (0.75 - floor((fRec286[0] + 0.75))));
			fVec60[0] = fTemp463;
			int iTemp464 = (fTemp463 > 0.001);
			int iTemp465 = (fVec60[1] <= 0.001);
			fRec291[0] = ((fRec291[1] * double((1 - (iTemp464 * iTemp465)))) + ((fRec68[0] * double(iTemp464)) * double(iTemp465)));
			double fTemp466 = (fConst2 * (fTemp463 * fRec291[0]));
			int iTemp467 = int(fTemp466);
			double fTemp468 = floor(fTemp466);
			double fTemp469 = (0.5 * fTemp463);
			double fTemp470 = (65536.0 * (fTemp469 - floor(fTemp469)));
			int iTemp471 = int(fTemp470);
			fRec9[0] = (((((((fVec56[((IOTA - (iTemp440 & 262143)) & 262143)] * (fTemp441 + (1.0 - fTemp439))) + ((fTemp439 - fTemp441) * fVec56[((IOTA - ((iTemp440 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp444] + ((fTemp443 - floor(fTemp443)) * (ftbl0mydspSIG0[((iTemp444 + 1) % 65536)] - ftbl0mydspSIG0[iTemp444])))) + (((fVec56[((IOTA - (iTemp449 & 262143)) & 262143)] * (fTemp450 + (1.0 - fTemp448))) + ((fTemp448 - fTemp450) * fVec56[((IOTA - ((iTemp449 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp453] + ((fTemp452 - floor(fTemp452)) * (ftbl0mydspSIG0[((iTemp453 + 1) % 65536)] - ftbl0mydspSIG0[iTemp453]))))) + (((fVec56[((IOTA - (iTemp458 & 262143)) & 262143)] * (fTemp459 + (1.0 - fTemp457))) + ((fTemp457 - fTemp459) * fVec56[((IOTA - ((iTemp458 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp462] + ((fTemp461 - floor(fTemp461)) * (ftbl0mydspSIG0[((iTemp462 + 1) % 65536)] - ftbl0mydspSIG0[iTemp462]))))) + (((fVec56[((IOTA - (iTemp467 & 262143)) & 262143)] * (fTemp468 + (1.0 - fTemp466))) + ((fTemp466 - fTemp468) * fVec56[((IOTA - ((iTemp467 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp471] + ((fTemp470 - floor(fTemp470)) * (ftbl0mydspSIG0[((iTemp471 + 1) % 65536)] - ftbl0mydspSIG0[iTemp471]))))) + (fTemp433 * (1.0 - fRec44[0])));
			fRec292[0] = (fSlow229 + (fSlow0 * fRec292[1]));
			fRec293[0] = (fSlow230 + (fSlow0 * fRec293[1]));
			fRec294[0] = (fSlow231 + (fSlow0 * fRec294[1]));
			fRec295[0] = (fSlow232 + (fSlow0 * fRec295[1]));
			fRec296[0] = (fSlow233 + (fSlow0 * fRec296[1]));
			fRec297[0] = (fSlow234 + (fSlow0 * fRec297[1]));
			fRec298[0] = (fSlow235 + (fSlow0 * fRec298[1]));
			fRec299[0] = (fSlow236 + (fSlow0 * fRec299[1]));
			fRec300[0] = (fSlow237 + (fSlow0 * fRec300[1]));
			fRec301[0] = (fSlow238 + (fSlow0 * fRec301[1]));
			fRec302[0] = (fSlow239 + (fSlow0 * fRec302[1]));
			fRec303[0] = (fSlow240 + (fSlow0 * fRec303[1]));
			fRec304[0] = (fSlow241 + (fSlow0 * fRec304[1]));
			fRec305[0] = (fSlow242 + (fSlow0 * fRec305[1]));
			fRec306[0] = (fSlow243 + (fSlow0 * fRec306[1]));
			fRec307[0] = (fSlow244 + (fSlow0 * fRec307[1]));
			fRec308[0] = (fSlow245 + (fSlow0 * fRec308[1]));
			double fTemp472 = (((((((((((((((((fTemp1 * fRec292[0]) + (fTemp3 * fRec293[0])) + (fTemp5 * fRec294[0])) + (fTemp7 * fRec295[0])) + (fTemp9 * fRec296[0])) + (fTemp11 * fRec297[0])) + (fTemp13 * fRec298[0])) + (fTemp15 * fRec299[0])) + (fTemp17 * fRec300[0])) + (fTemp19 * fRec301[0])) + (fTemp21 * fRec302[0])) + (fTemp23 * fRec303[0])) + (fTemp25 * fRec304[0])) + (fTemp27 * fRec305[0])) + (fTemp29 * fRec306[0])) + (fTemp31 * fRec307[0])) + (fTemp32 * fRec308[0]));
			fVec61[(IOTA & 1048575)] = fTemp472;
			fRec309[0] = (fSlow246 + (fSlow0 * fRec309[1]));
			int iTemp473 = int(fRec309[0]);
			double fTemp474 = floor(fRec309[0]);
			double fTemp475 = ((fVec61[((IOTA - (iTemp473 & 1048575)) & 1048575)] * (fTemp474 + (1.0 - fRec309[0]))) + ((fRec309[0] - fTemp474) * fVec61[((IOTA - ((iTemp473 + 1) & 1048575)) & 1048575)]));
			int iTemp476 = (fTemp475 > 1.0);
			int iTemp477 = (fTemp475 < -1.0);
			double fTemp478 = ((double(iTemp476) + ((fTemp475 * double((1 - iTemp477))) * double((1 - iTemp476)))) - double(iTemp477));
			double fTemp479 = (fRec47[0] * fTemp478);
			fVec62[(IOTA & 262143)] = fTemp479;
			fRec311[0] = (fSlow247 + (fSlow0 * fRec311[1]));
			double fTemp480 = (fRec310[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec311[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec310[0] = (fTemp480 - floor(fTemp480));
			double fTemp481 = (fRec310[0] - floor(fRec310[0]));
			fVec63[0] = fTemp481;
			int iTemp482 = (fTemp481 > 0.001);
			int iTemp483 = (fVec63[1] <= 0.001);
			fRec312[0] = ((fRec312[1] * double((1 - (iTemp482 * iTemp483)))) + ((fRec68[0] * double(iTemp482)) * double(iTemp483)));
			double fTemp484 = (fConst2 * (fTemp481 * fRec312[0]));
			int iTemp485 = int(fTemp484);
			double fTemp486 = floor(fTemp484);
			double fTemp487 = (0.5 * fTemp481);
			double fTemp488 = (65536.0 * (fTemp487 - floor(fTemp487)));
			int iTemp489 = int(fTemp488);
			double fTemp490 = (fRec310[0] + (0.25 - floor((fRec310[0] + 0.25))));
			fVec64[0] = fTemp490;
			int iTemp491 = (fTemp490 > 0.001);
			int iTemp492 = (fVec64[1] <= 0.001);
			fRec313[0] = ((fRec313[1] * double((1 - (iTemp491 * iTemp492)))) + ((fRec68[0] * double(iTemp491)) * double(iTemp492)));
			double fTemp493 = (fConst2 * (fTemp490 * fRec313[0]));
			int iTemp494 = int(fTemp493);
			double fTemp495 = floor(fTemp493);
			double fTemp496 = (0.5 * fTemp490);
			double fTemp497 = (65536.0 * (fTemp496 - floor(fTemp496)));
			int iTemp498 = int(fTemp497);
			double fTemp499 = (fRec310[0] + (0.5 - floor((fRec310[0] + 0.5))));
			fVec65[0] = fTemp499;
			int iTemp500 = (fTemp499 > 0.001);
			int iTemp501 = (fVec65[1] <= 0.001);
			fRec314[0] = ((fRec314[1] * double((1 - (iTemp500 * iTemp501)))) + ((fRec68[0] * double(iTemp500)) * double(iTemp501)));
			double fTemp502 = (fConst2 * (fTemp499 * fRec314[0]));
			int iTemp503 = int(fTemp502);
			double fTemp504 = floor(fTemp502);
			double fTemp505 = (0.5 * fTemp499);
			double fTemp506 = (65536.0 * (fTemp505 - floor(fTemp505)));
			int iTemp507 = int(fTemp506);
			double fTemp508 = (fRec310[0] + (0.75 - floor((fRec310[0] + 0.75))));
			fVec66[0] = fTemp508;
			int iTemp509 = (fTemp508 > 0.001);
			int iTemp510 = (fVec66[1] <= 0.001);
			fRec315[0] = ((fRec315[1] * double((1 - (iTemp509 * iTemp510)))) + ((fRec68[0] * double(iTemp509)) * double(iTemp510)));
			double fTemp511 = (fConst2 * (fTemp508 * fRec315[0]));
			int iTemp512 = int(fTemp511);
			double fTemp513 = floor(fTemp511);
			double fTemp514 = (0.5 * fTemp508);
			double fTemp515 = (65536.0 * (fTemp514 - floor(fTemp514)));
			int iTemp516 = int(fTemp515);
			fRec10[0] = (((((((fVec62[((IOTA - (iTemp485 & 262143)) & 262143)] * (fTemp486 + (1.0 - fTemp484))) + ((fTemp484 - fTemp486) * fVec62[((IOTA - ((iTemp485 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp489] + ((fTemp488 - floor(fTemp488)) * (ftbl0mydspSIG0[((iTemp489 + 1) % 65536)] - ftbl0mydspSIG0[iTemp489])))) + (((fVec62[((IOTA - (iTemp494 & 262143)) & 262143)] * (fTemp495 + (1.0 - fTemp493))) + ((fTemp493 - fTemp495) * fVec62[((IOTA - ((iTemp494 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp498] + ((fTemp497 - floor(fTemp497)) * (ftbl0mydspSIG0[((iTemp498 + 1) % 65536)] - ftbl0mydspSIG0[iTemp498]))))) + (((fVec62[((IOTA - (iTemp503 & 262143)) & 262143)] * (fTemp504 + (1.0 - fTemp502))) + ((fTemp502 - fTemp504) * fVec62[((IOTA - ((iTemp503 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp507] + ((fTemp506 - floor(fTemp506)) * (ftbl0mydspSIG0[((iTemp507 + 1) % 65536)] - ftbl0mydspSIG0[iTemp507]))))) + (((fVec62[((IOTA - (iTemp512 & 262143)) & 262143)] * (fTemp513 + (1.0 - fTemp511))) + ((fTemp511 - fTemp513) * fVec62[((IOTA - ((iTemp512 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp516] + ((fTemp515 - floor(fTemp515)) * (ftbl0mydspSIG0[((iTemp516 + 1) % 65536)] - ftbl0mydspSIG0[iTemp516]))))) + (fTemp478 * (1.0 - fRec47[0])));
			fRec316[0] = (fSlow248 + (fSlow0 * fRec316[1]));
			fRec317[0] = (fSlow249 + (fSlow0 * fRec317[1]));
			fRec318[0] = (fSlow250 + (fSlow0 * fRec318[1]));
			fRec319[0] = (fSlow251 + (fSlow0 * fRec319[1]));
			fRec320[0] = (fSlow252 + (fSlow0 * fRec320[1]));
			fRec321[0] = (fSlow253 + (fSlow0 * fRec321[1]));
			fRec322[0] = (fSlow254 + (fSlow0 * fRec322[1]));
			fRec323[0] = (fSlow255 + (fSlow0 * fRec323[1]));
			fRec324[0] = (fSlow256 + (fSlow0 * fRec324[1]));
			fRec325[0] = (fSlow257 + (fSlow0 * fRec325[1]));
			fRec326[0] = (fSlow258 + (fSlow0 * fRec326[1]));
			fRec327[0] = (fSlow259 + (fSlow0 * fRec327[1]));
			fRec328[0] = (fSlow260 + (fSlow0 * fRec328[1]));
			fRec329[0] = (fSlow261 + (fSlow0 * fRec329[1]));
			fRec330[0] = (fSlow262 + (fSlow0 * fRec330[1]));
			fRec331[0] = (fSlow263 + (fSlow0 * fRec331[1]));
			fRec332[0] = (fSlow264 + (fSlow0 * fRec332[1]));
			double fTemp517 = (((((((((((((((((fTemp1 * fRec316[0]) + (fTemp3 * fRec317[0])) + (fTemp5 * fRec318[0])) + (fTemp7 * fRec319[0])) + (fTemp9 * fRec320[0])) + (fTemp11 * fRec321[0])) + (fTemp13 * fRec322[0])) + (fTemp15 * fRec323[0])) + (fTemp17 * fRec324[0])) + (fTemp19 * fRec325[0])) + (fTemp21 * fRec326[0])) + (fTemp23 * fRec327[0])) + (fTemp25 * fRec328[0])) + (fTemp27 * fRec329[0])) + (fTemp29 * fRec330[0])) + (fTemp31 * fRec331[0])) + (fTemp32 * fRec332[0]));
			fVec67[(IOTA & 1048575)] = fTemp517;
			fRec333[0] = (fSlow265 + (fSlow0 * fRec333[1]));
			int iTemp518 = int(fRec333[0]);
			double fTemp519 = floor(fRec333[0]);
			double fTemp520 = ((fVec67[((IOTA - (iTemp518 & 1048575)) & 1048575)] * (fTemp519 + (1.0 - fRec333[0]))) + ((fRec333[0] - fTemp519) * fVec67[((IOTA - ((iTemp518 + 1) & 1048575)) & 1048575)]));
			int iTemp521 = (fTemp520 > 1.0);
			int iTemp522 = (fTemp520 < -1.0);
			double fTemp523 = ((double(iTemp521) + ((fTemp520 * double((1 - iTemp522))) * double((1 - iTemp521)))) - double(iTemp522));
			double fTemp524 = (fRec50[0] * fTemp523);
			fVec68[(IOTA & 262143)] = fTemp524;
			fRec335[0] = (fSlow266 + (fSlow0 * fRec335[1]));
			double fTemp525 = (fRec334[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec335[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec334[0] = (fTemp525 - floor(fTemp525));
			double fTemp526 = (fRec334[0] - floor(fRec334[0]));
			fVec69[0] = fTemp526;
			int iTemp527 = (fTemp526 > 0.001);
			int iTemp528 = (fVec69[1] <= 0.001);
			fRec336[0] = ((fRec336[1] * double((1 - (iTemp527 * iTemp528)))) + ((fRec68[0] * double(iTemp527)) * double(iTemp528)));
			double fTemp529 = (fConst2 * (fTemp526 * fRec336[0]));
			int iTemp530 = int(fTemp529);
			double fTemp531 = floor(fTemp529);
			double fTemp532 = (0.5 * fTemp526);
			double fTemp533 = (65536.0 * (fTemp532 - floor(fTemp532)));
			int iTemp534 = int(fTemp533);
			double fTemp535 = (fRec334[0] + (0.25 - floor((fRec334[0] + 0.25))));
			fVec70[0] = fTemp535;
			int iTemp536 = (fTemp535 > 0.001);
			int iTemp537 = (fVec70[1] <= 0.001);
			fRec337[0] = ((fRec337[1] * double((1 - (iTemp536 * iTemp537)))) + ((fRec68[0] * double(iTemp536)) * double(iTemp537)));
			double fTemp538 = (fConst2 * (fTemp535 * fRec337[0]));
			int iTemp539 = int(fTemp538);
			double fTemp540 = floor(fTemp538);
			double fTemp541 = (0.5 * fTemp535);
			double fTemp542 = (65536.0 * (fTemp541 - floor(fTemp541)));
			int iTemp543 = int(fTemp542);
			double fTemp544 = (fRec334[0] + (0.5 - floor((fRec334[0] + 0.5))));
			fVec71[0] = fTemp544;
			int iTemp545 = (fTemp544 > 0.001);
			int iTemp546 = (fVec71[1] <= 0.001);
			fRec338[0] = ((fRec338[1] * double((1 - (iTemp545 * iTemp546)))) + ((fRec68[0] * double(iTemp545)) * double(iTemp546)));
			double fTemp547 = (fConst2 * (fTemp544 * fRec338[0]));
			int iTemp548 = int(fTemp547);
			double fTemp549 = floor(fTemp547);
			double fTemp550 = (0.5 * fTemp544);
			double fTemp551 = (65536.0 * (fTemp550 - floor(fTemp550)));
			int iTemp552 = int(fTemp551);
			double fTemp553 = (fRec334[0] + (0.75 - floor((fRec334[0] + 0.75))));
			fVec72[0] = fTemp553;
			int iTemp554 = (fTemp553 > 0.001);
			int iTemp555 = (fVec72[1] <= 0.001);
			fRec339[0] = ((fRec339[1] * double((1 - (iTemp554 * iTemp555)))) + ((fRec68[0] * double(iTemp554)) * double(iTemp555)));
			double fTemp556 = (fConst2 * (fTemp553 * fRec339[0]));
			int iTemp557 = int(fTemp556);
			double fTemp558 = floor(fTemp556);
			double fTemp559 = (0.5 * fTemp553);
			double fTemp560 = (65536.0 * (fTemp559 - floor(fTemp559)));
			int iTemp561 = int(fTemp560);
			fRec11[0] = (((((((fVec68[((IOTA - (iTemp530 & 262143)) & 262143)] * (fTemp531 + (1.0 - fTemp529))) + ((fTemp529 - fTemp531) * fVec68[((IOTA - ((iTemp530 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp534] + ((fTemp533 - floor(fTemp533)) * (ftbl0mydspSIG0[((iTemp534 + 1) % 65536)] - ftbl0mydspSIG0[iTemp534])))) + (((fVec68[((IOTA - (iTemp539 & 262143)) & 262143)] * (fTemp540 + (1.0 - fTemp538))) + ((fTemp538 - fTemp540) * fVec68[((IOTA - ((iTemp539 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp543] + ((fTemp542 - floor(fTemp542)) * (ftbl0mydspSIG0[((iTemp543 + 1) % 65536)] - ftbl0mydspSIG0[iTemp543]))))) + (((fVec68[((IOTA - (iTemp548 & 262143)) & 262143)] * (fTemp549 + (1.0 - fTemp547))) + ((fTemp547 - fTemp549) * fVec68[((IOTA - ((iTemp548 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp552] + ((fTemp551 - floor(fTemp551)) * (ftbl0mydspSIG0[((iTemp552 + 1) % 65536)] - ftbl0mydspSIG0[iTemp552]))))) + (((fVec68[((IOTA - (iTemp557 & 262143)) & 262143)] * (fTemp558 + (1.0 - fTemp556))) + ((fTemp556 - fTemp558) * fVec68[((IOTA - ((iTemp557 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp561] + ((fTemp560 - floor(fTemp560)) * (ftbl0mydspSIG0[((iTemp561 + 1) % 65536)] - ftbl0mydspSIG0[iTemp561]))))) + (fTemp523 * (1.0 - fRec50[0])));
			fRec340[0] = (fSlow267 + (fSlow0 * fRec340[1]));
			fRec341[0] = (fSlow268 + (fSlow0 * fRec341[1]));
			fRec342[0] = (fSlow269 + (fSlow0 * fRec342[1]));
			fRec343[0] = (fSlow270 + (fSlow0 * fRec343[1]));
			fRec344[0] = (fSlow271 + (fSlow0 * fRec344[1]));
			fRec345[0] = (fSlow272 + (fSlow0 * fRec345[1]));
			fRec346[0] = (fSlow273 + (fSlow0 * fRec346[1]));
			fRec347[0] = (fSlow274 + (fSlow0 * fRec347[1]));
			fRec348[0] = (fSlow275 + (fSlow0 * fRec348[1]));
			fRec349[0] = (fSlow276 + (fSlow0 * fRec349[1]));
			fRec350[0] = (fSlow277 + (fSlow0 * fRec350[1]));
			fRec351[0] = (fSlow278 + (fSlow0 * fRec351[1]));
			fRec352[0] = (fSlow279 + (fSlow0 * fRec352[1]));
			fRec353[0] = (fSlow280 + (fSlow0 * fRec353[1]));
			fRec354[0] = (fSlow281 + (fSlow0 * fRec354[1]));
			fRec355[0] = (fSlow282 + (fSlow0 * fRec355[1]));
			fRec356[0] = (fSlow283 + (fSlow0 * fRec356[1]));
			double fTemp562 = (((((((((((((((((fTemp1 * fRec340[0]) + (fTemp3 * fRec341[0])) + (fTemp5 * fRec342[0])) + (fTemp7 * fRec343[0])) + (fTemp9 * fRec344[0])) + (fTemp11 * fRec345[0])) + (fTemp13 * fRec346[0])) + (fTemp15 * fRec347[0])) + (fTemp17 * fRec348[0])) + (fTemp19 * fRec349[0])) + (fTemp21 * fRec350[0])) + (fTemp23 * fRec351[0])) + (fTemp25 * fRec352[0])) + (fTemp27 * fRec353[0])) + (fTemp29 * fRec354[0])) + (fTemp31 * fRec355[0])) + (fTemp32 * fRec356[0]));
			fVec73[(IOTA & 1048575)] = fTemp562;
			fRec357[0] = (fSlow284 + (fSlow0 * fRec357[1]));
			int iTemp563 = int(fRec357[0]);
			double fTemp564 = floor(fRec357[0]);
			double fTemp565 = ((fVec73[((IOTA - (iTemp563 & 1048575)) & 1048575)] * (fTemp564 + (1.0 - fRec357[0]))) + ((fRec357[0] - fTemp564) * fVec73[((IOTA - ((iTemp563 + 1) & 1048575)) & 1048575)]));
			int iTemp566 = (fTemp565 > 1.0);
			int iTemp567 = (fTemp565 < -1.0);
			double fTemp568 = ((double(iTemp566) + ((fTemp565 * double((1 - iTemp567))) * double((1 - iTemp566)))) - double(iTemp567));
			double fTemp569 = (fRec53[0] * fTemp568);
			fVec74[(IOTA & 262143)] = fTemp569;
			fRec359[0] = (fSlow285 + (fSlow0 * fRec359[1]));
			double fTemp570 = (fRec358[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec359[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec358[0] = (fTemp570 - floor(fTemp570));
			double fTemp571 = (fRec358[0] - floor(fRec358[0]));
			fVec75[0] = fTemp571;
			int iTemp572 = (fTemp571 > 0.001);
			int iTemp573 = (fVec75[1] <= 0.001);
			fRec360[0] = ((fRec360[1] * double((1 - (iTemp572 * iTemp573)))) + ((fRec68[0] * double(iTemp572)) * double(iTemp573)));
			double fTemp574 = (fConst2 * (fTemp571 * fRec360[0]));
			int iTemp575 = int(fTemp574);
			double fTemp576 = floor(fTemp574);
			double fTemp577 = (0.5 * fTemp571);
			double fTemp578 = (65536.0 * (fTemp577 - floor(fTemp577)));
			int iTemp579 = int(fTemp578);
			double fTemp580 = (fRec358[0] + (0.25 - floor((fRec358[0] + 0.25))));
			fVec76[0] = fTemp580;
			int iTemp581 = (fTemp580 > 0.001);
			int iTemp582 = (fVec76[1] <= 0.001);
			fRec361[0] = ((fRec361[1] * double((1 - (iTemp581 * iTemp582)))) + ((fRec68[0] * double(iTemp581)) * double(iTemp582)));
			double fTemp583 = (fConst2 * (fTemp580 * fRec361[0]));
			int iTemp584 = int(fTemp583);
			double fTemp585 = floor(fTemp583);
			double fTemp586 = (0.5 * fTemp580);
			double fTemp587 = (65536.0 * (fTemp586 - floor(fTemp586)));
			int iTemp588 = int(fTemp587);
			double fTemp589 = (fRec358[0] + (0.5 - floor((fRec358[0] + 0.5))));
			fVec77[0] = fTemp589;
			int iTemp590 = (fTemp589 > 0.001);
			int iTemp591 = (fVec77[1] <= 0.001);
			fRec362[0] = ((fRec362[1] * double((1 - (iTemp590 * iTemp591)))) + ((fRec68[0] * double(iTemp590)) * double(iTemp591)));
			double fTemp592 = (fConst2 * (fTemp589 * fRec362[0]));
			int iTemp593 = int(fTemp592);
			double fTemp594 = floor(fTemp592);
			double fTemp595 = (0.5 * fTemp589);
			double fTemp596 = (65536.0 * (fTemp595 - floor(fTemp595)));
			int iTemp597 = int(fTemp596);
			double fTemp598 = (fRec358[0] + (0.75 - floor((fRec358[0] + 0.75))));
			fVec78[0] = fTemp598;
			int iTemp599 = (fTemp598 > 0.001);
			int iTemp600 = (fVec78[1] <= 0.001);
			fRec363[0] = ((fRec363[1] * double((1 - (iTemp599 * iTemp600)))) + ((fRec68[0] * double(iTemp599)) * double(iTemp600)));
			double fTemp601 = (fConst2 * (fTemp598 * fRec363[0]));
			int iTemp602 = int(fTemp601);
			double fTemp603 = floor(fTemp601);
			double fTemp604 = (0.5 * fTemp598);
			double fTemp605 = (65536.0 * (fTemp604 - floor(fTemp604)));
			int iTemp606 = int(fTemp605);
			fRec12[0] = (((((((fVec74[((IOTA - (iTemp575 & 262143)) & 262143)] * (fTemp576 + (1.0 - fTemp574))) + ((fTemp574 - fTemp576) * fVec74[((IOTA - ((iTemp575 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp579] + ((fTemp578 - floor(fTemp578)) * (ftbl0mydspSIG0[((iTemp579 + 1) % 65536)] - ftbl0mydspSIG0[iTemp579])))) + (((fVec74[((IOTA - (iTemp584 & 262143)) & 262143)] * (fTemp585 + (1.0 - fTemp583))) + ((fTemp583 - fTemp585) * fVec74[((IOTA - ((iTemp584 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp588] + ((fTemp587 - floor(fTemp587)) * (ftbl0mydspSIG0[((iTemp588 + 1) % 65536)] - ftbl0mydspSIG0[iTemp588]))))) + (((fVec74[((IOTA - (iTemp593 & 262143)) & 262143)] * (fTemp594 + (1.0 - fTemp592))) + ((fTemp592 - fTemp594) * fVec74[((IOTA - ((iTemp593 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp597] + ((fTemp596 - floor(fTemp596)) * (ftbl0mydspSIG0[((iTemp597 + 1) % 65536)] - ftbl0mydspSIG0[iTemp597]))))) + (((fVec74[((IOTA - (iTemp602 & 262143)) & 262143)] * (fTemp603 + (1.0 - fTemp601))) + ((fTemp601 - fTemp603) * fVec74[((IOTA - ((iTemp602 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp606] + ((fTemp605 - floor(fTemp605)) * (ftbl0mydspSIG0[((iTemp606 + 1) % 65536)] - ftbl0mydspSIG0[iTemp606]))))) + (fTemp568 * (1.0 - fRec53[0])));
			fRec364[0] = (fSlow286 + (fSlow0 * fRec364[1]));
			fRec365[0] = (fSlow287 + (fSlow0 * fRec365[1]));
			fRec366[0] = (fSlow288 + (fSlow0 * fRec366[1]));
			fRec367[0] = (fSlow289 + (fSlow0 * fRec367[1]));
			fRec368[0] = (fSlow290 + (fSlow0 * fRec368[1]));
			fRec369[0] = (fSlow291 + (fSlow0 * fRec369[1]));
			fRec370[0] = (fSlow292 + (fSlow0 * fRec370[1]));
			fRec371[0] = (fSlow293 + (fSlow0 * fRec371[1]));
			fRec372[0] = (fSlow294 + (fSlow0 * fRec372[1]));
			fRec373[0] = (fSlow295 + (fSlow0 * fRec373[1]));
			fRec374[0] = (fSlow296 + (fSlow0 * fRec374[1]));
			fRec375[0] = (fSlow297 + (fSlow0 * fRec375[1]));
			fRec376[0] = (fSlow298 + (fSlow0 * fRec376[1]));
			fRec377[0] = (fSlow299 + (fSlow0 * fRec377[1]));
			fRec378[0] = (fSlow300 + (fSlow0 * fRec378[1]));
			fRec379[0] = (fSlow301 + (fSlow0 * fRec379[1]));
			fRec380[0] = (fSlow302 + (fSlow0 * fRec380[1]));
			double fTemp607 = (((((((((((((((((fTemp1 * fRec364[0]) + (fTemp3 * fRec365[0])) + (fTemp5 * fRec366[0])) + (fTemp7 * fRec367[0])) + (fTemp9 * fRec368[0])) + (fTemp11 * fRec369[0])) + (fTemp13 * fRec370[0])) + (fTemp15 * fRec371[0])) + (fTemp17 * fRec372[0])) + (fTemp19 * fRec373[0])) + (fTemp21 * fRec374[0])) + (fTemp23 * fRec375[0])) + (fTemp25 * fRec376[0])) + (fTemp27 * fRec377[0])) + (fTemp29 * fRec378[0])) + (fTemp31 * fRec379[0])) + (fTemp32 * fRec380[0]));
			fVec79[(IOTA & 1048575)] = fTemp607;
			fRec381[0] = (fSlow303 + (fSlow0 * fRec381[1]));
			int iTemp608 = int(fRec381[0]);
			double fTemp609 = floor(fRec381[0]);
			double fTemp610 = ((fVec79[((IOTA - (iTemp608 & 1048575)) & 1048575)] * (fTemp609 + (1.0 - fRec381[0]))) + ((fRec381[0] - fTemp609) * fVec79[((IOTA - ((iTemp608 + 1) & 1048575)) & 1048575)]));
			int iTemp611 = (fTemp610 > 1.0);
			int iTemp612 = (fTemp610 < -1.0);
			double fTemp613 = ((double(iTemp611) + ((fTemp610 * double((1 - iTemp612))) * double((1 - iTemp611)))) - double(iTemp612));
			double fTemp614 = (fRec56[0] * fTemp613);
			fVec80[(IOTA & 262143)] = fTemp614;
			fRec383[0] = (fSlow304 + (fSlow0 * fRec383[1]));
			double fTemp615 = (fRec382[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec383[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec382[0] = (fTemp615 - floor(fTemp615));
			double fTemp616 = (fRec382[0] - floor(fRec382[0]));
			fVec81[0] = fTemp616;
			int iTemp617 = (fTemp616 > 0.001);
			int iTemp618 = (fVec81[1] <= 0.001);
			fRec384[0] = ((fRec384[1] * double((1 - (iTemp617 * iTemp618)))) + ((fRec68[0] * double(iTemp617)) * double(iTemp618)));
			double fTemp619 = (fConst2 * (fTemp616 * fRec384[0]));
			int iTemp620 = int(fTemp619);
			double fTemp621 = floor(fTemp619);
			double fTemp622 = (0.5 * fTemp616);
			double fTemp623 = (65536.0 * (fTemp622 - floor(fTemp622)));
			int iTemp624 = int(fTemp623);
			double fTemp625 = (fRec382[0] + (0.25 - floor((fRec382[0] + 0.25))));
			fVec82[0] = fTemp625;
			int iTemp626 = (fTemp625 > 0.001);
			int iTemp627 = (fVec82[1] <= 0.001);
			fRec385[0] = ((fRec385[1] * double((1 - (iTemp626 * iTemp627)))) + ((fRec68[0] * double(iTemp626)) * double(iTemp627)));
			double fTemp628 = (fConst2 * (fTemp625 * fRec385[0]));
			int iTemp629 = int(fTemp628);
			double fTemp630 = floor(fTemp628);
			double fTemp631 = (0.5 * fTemp625);
			double fTemp632 = (65536.0 * (fTemp631 - floor(fTemp631)));
			int iTemp633 = int(fTemp632);
			double fTemp634 = (fRec382[0] + (0.5 - floor((fRec382[0] + 0.5))));
			fVec83[0] = fTemp634;
			int iTemp635 = (fTemp634 > 0.001);
			int iTemp636 = (fVec83[1] <= 0.001);
			fRec386[0] = ((fRec386[1] * double((1 - (iTemp635 * iTemp636)))) + ((fRec68[0] * double(iTemp635)) * double(iTemp636)));
			double fTemp637 = (fConst2 * (fTemp634 * fRec386[0]));
			int iTemp638 = int(fTemp637);
			double fTemp639 = floor(fTemp637);
			double fTemp640 = (0.5 * fTemp634);
			double fTemp641 = (65536.0 * (fTemp640 - floor(fTemp640)));
			int iTemp642 = int(fTemp641);
			double fTemp643 = (fRec382[0] + (0.75 - floor((fRec382[0] + 0.75))));
			fVec84[0] = fTemp643;
			int iTemp644 = (fTemp643 > 0.001);
			int iTemp645 = (fVec84[1] <= 0.001);
			fRec387[0] = ((fRec387[1] * double((1 - (iTemp644 * iTemp645)))) + ((fRec68[0] * double(iTemp644)) * double(iTemp645)));
			double fTemp646 = (fConst2 * (fTemp643 * fRec387[0]));
			int iTemp647 = int(fTemp646);
			double fTemp648 = floor(fTemp646);
			double fTemp649 = (0.5 * fTemp643);
			double fTemp650 = (65536.0 * (fTemp649 - floor(fTemp649)));
			int iTemp651 = int(fTemp650);
			fRec13[0] = (((((((fVec80[((IOTA - (iTemp620 & 262143)) & 262143)] * (fTemp621 + (1.0 - fTemp619))) + ((fTemp619 - fTemp621) * fVec80[((IOTA - ((iTemp620 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp624] + ((fTemp623 - floor(fTemp623)) * (ftbl0mydspSIG0[((iTemp624 + 1) % 65536)] - ftbl0mydspSIG0[iTemp624])))) + (((fVec80[((IOTA - (iTemp629 & 262143)) & 262143)] * (fTemp630 + (1.0 - fTemp628))) + ((fTemp628 - fTemp630) * fVec80[((IOTA - ((iTemp629 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp633] + ((fTemp632 - floor(fTemp632)) * (ftbl0mydspSIG0[((iTemp633 + 1) % 65536)] - ftbl0mydspSIG0[iTemp633]))))) + (((fVec80[((IOTA - (iTemp638 & 262143)) & 262143)] * (fTemp639 + (1.0 - fTemp637))) + ((fTemp637 - fTemp639) * fVec80[((IOTA - ((iTemp638 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp642] + ((fTemp641 - floor(fTemp641)) * (ftbl0mydspSIG0[((iTemp642 + 1) % 65536)] - ftbl0mydspSIG0[iTemp642]))))) + (((fVec80[((IOTA - (iTemp647 & 262143)) & 262143)] * (fTemp648 + (1.0 - fTemp646))) + ((fTemp646 - fTemp648) * fVec80[((IOTA - ((iTemp647 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp651] + ((fTemp650 - floor(fTemp650)) * (ftbl0mydspSIG0[((iTemp651 + 1) % 65536)] - ftbl0mydspSIG0[iTemp651]))))) + (fTemp613 * (1.0 - fRec56[0])));
			fRec388[0] = (fSlow305 + (fSlow0 * fRec388[1]));
			fRec389[0] = (fSlow306 + (fSlow0 * fRec389[1]));
			fRec390[0] = (fSlow307 + (fSlow0 * fRec390[1]));
			fRec391[0] = (fSlow308 + (fSlow0 * fRec391[1]));
			fRec392[0] = (fSlow309 + (fSlow0 * fRec392[1]));
			fRec393[0] = (fSlow310 + (fSlow0 * fRec393[1]));
			fRec394[0] = (fSlow311 + (fSlow0 * fRec394[1]));
			fRec395[0] = (fSlow312 + (fSlow0 * fRec395[1]));
			fRec396[0] = (fSlow313 + (fSlow0 * fRec396[1]));
			fRec397[0] = (fSlow314 + (fSlow0 * fRec397[1]));
			fRec398[0] = (fSlow315 + (fSlow0 * fRec398[1]));
			fRec399[0] = (fSlow316 + (fSlow0 * fRec399[1]));
			fRec400[0] = (fSlow317 + (fSlow0 * fRec400[1]));
			fRec401[0] = (fSlow318 + (fSlow0 * fRec401[1]));
			fRec402[0] = (fSlow319 + (fSlow0 * fRec402[1]));
			fRec403[0] = (fSlow320 + (fSlow0 * fRec403[1]));
			fRec404[0] = (fSlow321 + (fSlow0 * fRec404[1]));
			double fTemp652 = (((((((((((((((((fTemp1 * fRec388[0]) + (fTemp3 * fRec389[0])) + (fTemp5 * fRec390[0])) + (fTemp7 * fRec391[0])) + (fTemp9 * fRec392[0])) + (fTemp11 * fRec393[0])) + (fTemp13 * fRec394[0])) + (fTemp15 * fRec395[0])) + (fTemp17 * fRec396[0])) + (fTemp19 * fRec397[0])) + (fTemp21 * fRec398[0])) + (fTemp23 * fRec399[0])) + (fTemp25 * fRec400[0])) + (fTemp27 * fRec401[0])) + (fTemp29 * fRec402[0])) + (fTemp31 * fRec403[0])) + (fTemp32 * fRec404[0]));
			fVec85[(IOTA & 1048575)] = fTemp652;
			fRec405[0] = (fSlow322 + (fSlow0 * fRec405[1]));
			int iTemp653 = int(fRec405[0]);
			double fTemp654 = floor(fRec405[0]);
			double fTemp655 = ((fVec85[((IOTA - (iTemp653 & 1048575)) & 1048575)] * (fTemp654 + (1.0 - fRec405[0]))) + ((fRec405[0] - fTemp654) * fVec85[((IOTA - ((iTemp653 + 1) & 1048575)) & 1048575)]));
			int iTemp656 = (fTemp655 > 1.0);
			int iTemp657 = (fTemp655 < -1.0);
			double fTemp658 = ((double(iTemp656) + ((fTemp655 * double((1 - iTemp657))) * double((1 - iTemp656)))) - double(iTemp657));
			double fTemp659 = (fRec59[0] * fTemp658);
			fVec86[(IOTA & 262143)] = fTemp659;
			fRec407[0] = (fSlow323 + (fSlow0 * fRec407[1]));
			double fTemp660 = (fRec406[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec407[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec406[0] = (fTemp660 - floor(fTemp660));
			double fTemp661 = (fRec406[0] - floor(fRec406[0]));
			fVec87[0] = fTemp661;
			int iTemp662 = (fTemp661 > 0.001);
			int iTemp663 = (fVec87[1] <= 0.001);
			fRec408[0] = ((fRec408[1] * double((1 - (iTemp662 * iTemp663)))) + ((fRec68[0] * double(iTemp662)) * double(iTemp663)));
			double fTemp664 = (fConst2 * (fTemp661 * fRec408[0]));
			int iTemp665 = int(fTemp664);
			double fTemp666 = floor(fTemp664);
			double fTemp667 = (0.5 * fTemp661);
			double fTemp668 = (65536.0 * (fTemp667 - floor(fTemp667)));
			int iTemp669 = int(fTemp668);
			double fTemp670 = (fRec406[0] + (0.25 - floor((fRec406[0] + 0.25))));
			fVec88[0] = fTemp670;
			int iTemp671 = (fTemp670 > 0.001);
			int iTemp672 = (fVec88[1] <= 0.001);
			fRec409[0] = ((fRec409[1] * double((1 - (iTemp671 * iTemp672)))) + ((fRec68[0] * double(iTemp671)) * double(iTemp672)));
			double fTemp673 = (fConst2 * (fTemp670 * fRec409[0]));
			int iTemp674 = int(fTemp673);
			double fTemp675 = floor(fTemp673);
			double fTemp676 = (0.5 * fTemp670);
			double fTemp677 = (65536.0 * (fTemp676 - floor(fTemp676)));
			int iTemp678 = int(fTemp677);
			double fTemp679 = (fRec406[0] + (0.5 - floor((fRec406[0] + 0.5))));
			fVec89[0] = fTemp679;
			int iTemp680 = (fTemp679 > 0.001);
			int iTemp681 = (fVec89[1] <= 0.001);
			fRec410[0] = ((fRec410[1] * double((1 - (iTemp680 * iTemp681)))) + ((fRec68[0] * double(iTemp680)) * double(iTemp681)));
			double fTemp682 = (fConst2 * (fTemp679 * fRec410[0]));
			int iTemp683 = int(fTemp682);
			double fTemp684 = floor(fTemp682);
			double fTemp685 = (0.5 * fTemp679);
			double fTemp686 = (65536.0 * (fTemp685 - floor(fTemp685)));
			int iTemp687 = int(fTemp686);
			double fTemp688 = (fRec406[0] + (0.75 - floor((fRec406[0] + 0.75))));
			fVec90[0] = fTemp688;
			int iTemp689 = (fTemp688 > 0.001);
			int iTemp690 = (fVec90[1] <= 0.001);
			fRec411[0] = ((fRec411[1] * double((1 - (iTemp689 * iTemp690)))) + ((fRec68[0] * double(iTemp689)) * double(iTemp690)));
			double fTemp691 = (fConst2 * (fTemp688 * fRec411[0]));
			int iTemp692 = int(fTemp691);
			double fTemp693 = floor(fTemp691);
			double fTemp694 = (0.5 * fTemp688);
			double fTemp695 = (65536.0 * (fTemp694 - floor(fTemp694)));
			int iTemp696 = int(fTemp695);
			fRec14[0] = (((((((fVec86[((IOTA - (iTemp665 & 262143)) & 262143)] * (fTemp666 + (1.0 - fTemp664))) + ((fTemp664 - fTemp666) * fVec86[((IOTA - ((iTemp665 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp669] + ((fTemp668 - floor(fTemp668)) * (ftbl0mydspSIG0[((iTemp669 + 1) % 65536)] - ftbl0mydspSIG0[iTemp669])))) + (((fVec86[((IOTA - (iTemp674 & 262143)) & 262143)] * (fTemp675 + (1.0 - fTemp673))) + ((fTemp673 - fTemp675) * fVec86[((IOTA - ((iTemp674 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp678] + ((fTemp677 - floor(fTemp677)) * (ftbl0mydspSIG0[((iTemp678 + 1) % 65536)] - ftbl0mydspSIG0[iTemp678]))))) + (((fVec86[((IOTA - (iTemp683 & 262143)) & 262143)] * (fTemp684 + (1.0 - fTemp682))) + ((fTemp682 - fTemp684) * fVec86[((IOTA - ((iTemp683 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp687] + ((fTemp686 - floor(fTemp686)) * (ftbl0mydspSIG0[((iTemp687 + 1) % 65536)] - ftbl0mydspSIG0[iTemp687]))))) + (((fVec86[((IOTA - (iTemp692 & 262143)) & 262143)] * (fTemp693 + (1.0 - fTemp691))) + ((fTemp691 - fTemp693) * fVec86[((IOTA - ((iTemp692 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp696] + ((fTemp695 - floor(fTemp695)) * (ftbl0mydspSIG0[((iTemp696 + 1) % 65536)] - ftbl0mydspSIG0[iTemp696]))))) + (fTemp658 * (1.0 - fRec59[0])));
			fRec412[0] = (fSlow324 + (fSlow0 * fRec412[1]));
			fRec413[0] = (fSlow325 + (fSlow0 * fRec413[1]));
			fRec414[0] = (fSlow326 + (fSlow0 * fRec414[1]));
			fRec415[0] = (fSlow327 + (fSlow0 * fRec415[1]));
			fRec416[0] = (fSlow328 + (fSlow0 * fRec416[1]));
			fRec417[0] = (fSlow329 + (fSlow0 * fRec417[1]));
			fRec418[0] = (fSlow330 + (fSlow0 * fRec418[1]));
			fRec419[0] = (fSlow331 + (fSlow0 * fRec419[1]));
			fRec420[0] = (fSlow332 + (fSlow0 * fRec420[1]));
			fRec421[0] = (fSlow333 + (fSlow0 * fRec421[1]));
			fRec422[0] = (fSlow334 + (fSlow0 * fRec422[1]));
			fRec423[0] = (fSlow335 + (fSlow0 * fRec423[1]));
			fRec424[0] = (fSlow336 + (fSlow0 * fRec424[1]));
			fRec425[0] = (fSlow337 + (fSlow0 * fRec425[1]));
			fRec426[0] = (fSlow338 + (fSlow0 * fRec426[1]));
			fRec427[0] = (fSlow339 + (fSlow0 * fRec427[1]));
			fRec428[0] = (fSlow340 + (fSlow0 * fRec428[1]));
			double fTemp697 = (((((((((((((((((fTemp1 * fRec412[0]) + (fTemp3 * fRec413[0])) + (fTemp5 * fRec414[0])) + (fTemp7 * fRec415[0])) + (fTemp9 * fRec416[0])) + (fTemp11 * fRec417[0])) + (fTemp13 * fRec418[0])) + (fTemp15 * fRec419[0])) + (fTemp17 * fRec420[0])) + (fTemp19 * fRec421[0])) + (fTemp21 * fRec422[0])) + (fTemp23 * fRec423[0])) + (fTemp25 * fRec424[0])) + (fTemp27 * fRec425[0])) + (fTemp29 * fRec426[0])) + (fTemp31 * fRec427[0])) + (fTemp32 * fRec428[0]));
			fVec91[(IOTA & 1048575)] = fTemp697;
			fRec429[0] = (fSlow341 + (fSlow0 * fRec429[1]));
			int iTemp698 = int(fRec429[0]);
			double fTemp699 = floor(fRec429[0]);
			double fTemp700 = ((fVec91[((IOTA - (iTemp698 & 1048575)) & 1048575)] * (fTemp699 + (1.0 - fRec429[0]))) + ((fRec429[0] - fTemp699) * fVec91[((IOTA - ((iTemp698 + 1) & 1048575)) & 1048575)]));
			int iTemp701 = (fTemp700 > 1.0);
			int iTemp702 = (fTemp700 < -1.0);
			double fTemp703 = ((double(iTemp701) + ((fTemp700 * double((1 - iTemp702))) * double((1 - iTemp701)))) - double(iTemp702));
			double fTemp704 = (fRec62[0] * fTemp703);
			fVec92[(IOTA & 262143)] = fTemp704;
			fRec431[0] = (fSlow342 + (fSlow0 * fRec431[1]));
			double fTemp705 = (fRec430[1] + (fConst3 * ((0.0 - (3.8224 * ((440.0 * pow(2.0, (0.083333333333333329 * ((0.01 * (fRec431[0] + 6000.0)) + -69.0)))) + -261.62597699999998))) / fRec68[0])));
			fRec430[0] = (fTemp705 - floor(fTemp705));
			double fTemp706 = (fRec430[0] - floor(fRec430[0]));
			fVec93[0] = fTemp706;
			int iTemp707 = (fTemp706 > 0.001);
			int iTemp708 = (fVec93[1] <= 0.001);
			fRec432[0] = ((fRec432[1] * double((1 - (iTemp707 * iTemp708)))) + ((fRec68[0] * double(iTemp707)) * double(iTemp708)));
			double fTemp709 = (fConst2 * (fTemp706 * fRec432[0]));
			int iTemp710 = int(fTemp709);
			double fTemp711 = floor(fTemp709);
			double fTemp712 = (0.5 * fTemp706);
			double fTemp713 = (65536.0 * (fTemp712 - floor(fTemp712)));
			int iTemp714 = int(fTemp713);
			double fTemp715 = (fRec430[0] + (0.25 - floor((fRec430[0] + 0.25))));
			fVec94[0] = fTemp715;
			int iTemp716 = (fTemp715 > 0.001);
			int iTemp717 = (fVec94[1] <= 0.001);
			fRec433[0] = ((fRec433[1] * double((1 - (iTemp716 * iTemp717)))) + ((fRec68[0] * double(iTemp716)) * double(iTemp717)));
			double fTemp718 = (fConst2 * (fTemp715 * fRec433[0]));
			int iTemp719 = int(fTemp718);
			double fTemp720 = floor(fTemp718);
			double fTemp721 = (0.5 * fTemp715);
			double fTemp722 = (65536.0 * (fTemp721 - floor(fTemp721)));
			int iTemp723 = int(fTemp722);
			double fTemp724 = (fRec430[0] + (0.5 - floor((fRec430[0] + 0.5))));
			fVec95[0] = fTemp724;
			int iTemp725 = (fTemp724 > 0.001);
			int iTemp726 = (fVec95[1] <= 0.001);
			fRec434[0] = ((fRec434[1] * double((1 - (iTemp725 * iTemp726)))) + ((fRec68[0] * double(iTemp725)) * double(iTemp726)));
			double fTemp727 = (fConst2 * (fTemp724 * fRec434[0]));
			int iTemp728 = int(fTemp727);
			double fTemp729 = floor(fTemp727);
			double fTemp730 = (0.5 * fTemp724);
			double fTemp731 = (65536.0 * (fTemp730 - floor(fTemp730)));
			int iTemp732 = int(fTemp731);
			double fTemp733 = (fRec430[0] + (0.75 - floor((fRec430[0] + 0.75))));
			fVec96[0] = fTemp733;
			int iTemp734 = (fTemp733 > 0.001);
			int iTemp735 = (fVec96[1] <= 0.001);
			fRec435[0] = ((fRec435[1] * double((1 - (iTemp734 * iTemp735)))) + ((fRec68[0] * double(iTemp734)) * double(iTemp735)));
			double fTemp736 = (fConst2 * (fTemp733 * fRec435[0]));
			int iTemp737 = int(fTemp736);
			double fTemp738 = floor(fTemp736);
			double fTemp739 = (0.5 * fTemp733);
			double fTemp740 = (65536.0 * (fTemp739 - floor(fTemp739)));
			int iTemp741 = int(fTemp740);
			fRec15[0] = (((((((fVec92[((IOTA - (iTemp710 & 262143)) & 262143)] * (fTemp711 + (1.0 - fTemp709))) + ((fTemp709 - fTemp711) * fVec92[((IOTA - ((iTemp710 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp714] + ((fTemp713 - floor(fTemp713)) * (ftbl0mydspSIG0[((iTemp714 + 1) % 65536)] - ftbl0mydspSIG0[iTemp714])))) + (((fVec92[((IOTA - (iTemp719 & 262143)) & 262143)] * (fTemp720 + (1.0 - fTemp718))) + ((fTemp718 - fTemp720) * fVec92[((IOTA - ((iTemp719 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp723] + ((fTemp722 - floor(fTemp722)) * (ftbl0mydspSIG0[((iTemp723 + 1) % 65536)] - ftbl0mydspSIG0[iTemp723]))))) + (((fVec92[((IOTA - (iTemp728 & 262143)) & 262143)] * (fTemp729 + (1.0 - fTemp727))) + ((fTemp727 - fTemp729) * fVec92[((IOTA - ((iTemp728 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp732] + ((fTemp731 - floor(fTemp731)) * (ftbl0mydspSIG0[((iTemp732 + 1) % 65536)] - ftbl0mydspSIG0[iTemp732]))))) + (((fVec92[((IOTA - (iTemp737 & 262143)) & 262143)] * (fTemp738 + (1.0 - fTemp736))) + ((fTemp736 - fTemp738) * fVec92[((IOTA - ((iTemp737 + 1) & 262143)) & 262143)])) * (ftbl0mydspSIG0[iTemp741] + ((fTemp740 - floor(fTemp740)) * (ftbl0mydspSIG0[((iTemp741 + 1) % 65536)] - ftbl0mydspSIG0[iTemp741]))))) + (fTemp703 * (1.0 - fRec62[0])));
			fRec436[0] = (fSlow343 + (fSlow0 * fRec436[1]));
			output0[i] = FAUSTFLOAT((fRec0[0] * fRec436[0]));
			fRec437[0] = (fSlow344 + (fSlow0 * fRec437[1]));
			output1[i] = FAUSTFLOAT((fRec1[0] * fRec437[0]));
			fRec438[0] = (fSlow345 + (fSlow0 * fRec438[1]));
			output2[i] = FAUSTFLOAT((fRec2[0] * fRec438[0]));
			fRec439[0] = (fSlow346 + (fSlow0 * fRec439[1]));
			output3[i] = FAUSTFLOAT((fRec3[0] * fRec439[0]));
			fRec440[0] = (fSlow347 + (fSlow0 * fRec440[1]));
			output4[i] = FAUSTFLOAT((fRec4[0] * fRec440[0]));
			fRec441[0] = (fSlow348 + (fSlow0 * fRec441[1]));
			output5[i] = FAUSTFLOAT((fRec5[0] * fRec441[0]));
			fRec442[0] = (fSlow349 + (fSlow0 * fRec442[1]));
			output6[i] = FAUSTFLOAT((fRec6[0] * fRec442[0]));
			fRec443[0] = (fSlow350 + (fSlow0 * fRec443[1]));
			output7[i] = FAUSTFLOAT((fRec7[0] * fRec443[0]));
			fRec444[0] = (fSlow351 + (fSlow0 * fRec444[1]));
			output8[i] = FAUSTFLOAT((fRec8[0] * fRec444[0]));
			fRec445[0] = (fSlow352 + (fSlow0 * fRec445[1]));
			output9[i] = FAUSTFLOAT((fRec9[0] * fRec445[0]));
			fRec446[0] = (fSlow353 + (fSlow0 * fRec446[1]));
			output10[i] = FAUSTFLOAT((fRec10[0] * fRec446[0]));
			fRec447[0] = (fSlow354 + (fSlow0 * fRec447[1]));
			output11[i] = FAUSTFLOAT((fRec11[0] * fRec447[0]));
			fRec448[0] = (fSlow355 + (fSlow0 * fRec448[1]));
			output12[i] = FAUSTFLOAT((fRec12[0] * fRec448[0]));
			fRec449[0] = (fSlow356 + (fSlow0 * fRec449[1]));
			output13[i] = FAUSTFLOAT((fRec13[0] * fRec449[0]));
			fRec450[0] = (fSlow357 + (fSlow0 * fRec450[1]));
			output14[i] = FAUSTFLOAT((fRec14[0] * fRec450[0]));
			fRec451[0] = (fSlow358 + (fSlow0 * fRec451[1]));
			output15[i] = FAUSTFLOAT((fRec15[0] * fRec451[0]));
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
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
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec54[1] = fRec54[0];
			fRec55[1] = fRec55[0];
			fRec56[1] = fRec56[0];
			fRec57[1] = fRec57[0];
			fRec58[1] = fRec58[0];
			fRec59[1] = fRec59[0];
			fRec60[1] = fRec60[0];
			fRec61[1] = fRec61[0];
			fRec62[1] = fRec62[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			IOTA = (IOTA + 1);
			fRec65[1] = fRec65[0];
			fRec67[1] = fRec67[0];
			fVec2[1] = fVec2[0];
			fRec69[1] = fRec69[0];
			fRec70[1] = fRec70[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fVec3[1] = fVec3[0];
			fRec71[1] = fRec71[0];
			fVec4[1] = fVec4[0];
			fRec73[1] = fRec73[0];
			fVec5[1] = fVec5[0];
			fRec74[1] = fRec74[0];
			fVec6[1] = fVec6[0];
			fRec75[1] = fRec75[0];
			fRec0[1] = fRec0[0];
			fRec76[1] = fRec76[0];
			fRec77[1] = fRec77[0];
			fRec78[1] = fRec78[0];
			fRec79[1] = fRec79[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			fRec82[1] = fRec82[0];
			fRec83[1] = fRec83[0];
			fRec84[1] = fRec84[0];
			fRec85[1] = fRec85[0];
			fRec86[1] = fRec86[0];
			fRec87[1] = fRec87[0];
			fRec88[1] = fRec88[0];
			fRec89[1] = fRec89[0];
			fRec90[1] = fRec90[0];
			fRec91[1] = fRec91[0];
			fRec92[1] = fRec92[0];
			fRec93[1] = fRec93[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fVec9[1] = fVec9[0];
			fRec96[1] = fRec96[0];
			fVec10[1] = fVec10[0];
			fRec97[1] = fRec97[0];
			fVec11[1] = fVec11[0];
			fRec98[1] = fRec98[0];
			fVec12[1] = fVec12[0];
			fRec99[1] = fRec99[0];
			fRec1[1] = fRec1[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fVec13[1] = fVec13[0];
			fRec102[1] = fRec102[0];
			fRec103[1] = fRec103[0];
			fRec104[1] = fRec104[0];
			fRec105[1] = fRec105[0];
			fRec106[1] = fRec106[0];
			fRec107[1] = fRec107[0];
			fRec108[1] = fRec108[0];
			fRec109[1] = fRec109[0];
			fRec110[1] = fRec110[0];
			fRec111[1] = fRec111[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			fRec114[1] = fRec114[0];
			fRec115[1] = fRec115[0];
			fRec116[1] = fRec116[0];
			fRec117[1] = fRec117[0];
			fRec118[1] = fRec118[0];
			fRec119[1] = fRec119[0];
			fRec120[1] = fRec120[0];
			fVec16[1] = fVec16[0];
			fRec121[1] = fRec121[0];
			fVec17[1] = fVec17[0];
			fRec122[1] = fRec122[0];
			fVec18[1] = fVec18[0];
			fRec123[1] = fRec123[0];
			fRec2[1] = fRec2[0];
			fRec125[1] = fRec125[0];
			fRec124[1] = fRec124[0];
			fVec19[1] = fVec19[0];
			fRec126[1] = fRec126[0];
			fRec127[1] = fRec127[0];
			fRec128[1] = fRec128[0];
			fRec129[1] = fRec129[0];
			fRec130[1] = fRec130[0];
			fRec131[1] = fRec131[0];
			fRec132[1] = fRec132[0];
			fRec133[1] = fRec133[0];
			fRec134[1] = fRec134[0];
			fRec135[1] = fRec135[0];
			fRec136[1] = fRec136[0];
			fRec137[1] = fRec137[0];
			fRec138[1] = fRec138[0];
			fRec139[1] = fRec139[0];
			fRec140[1] = fRec140[0];
			fRec141[1] = fRec141[0];
			fRec142[1] = fRec142[0];
			fRec143[1] = fRec143[0];
			fRec144[1] = fRec144[0];
			fVec22[1] = fVec22[0];
			fRec145[1] = fRec145[0];
			fVec23[1] = fVec23[0];
			fRec146[1] = fRec146[0];
			fVec24[1] = fVec24[0];
			fRec147[1] = fRec147[0];
			fRec3[1] = fRec3[0];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fVec25[1] = fVec25[0];
			fRec150[1] = fRec150[0];
			fRec151[1] = fRec151[0];
			fRec152[1] = fRec152[0];
			fRec153[1] = fRec153[0];
			fRec154[1] = fRec154[0];
			fRec155[1] = fRec155[0];
			fRec156[1] = fRec156[0];
			fRec157[1] = fRec157[0];
			fRec158[1] = fRec158[0];
			fRec159[1] = fRec159[0];
			fRec160[1] = fRec160[0];
			fRec161[1] = fRec161[0];
			fRec162[1] = fRec162[0];
			fRec163[1] = fRec163[0];
			fRec164[1] = fRec164[0];
			fRec165[1] = fRec165[0];
			fRec166[1] = fRec166[0];
			fRec167[1] = fRec167[0];
			fRec168[1] = fRec168[0];
			fVec28[1] = fVec28[0];
			fRec169[1] = fRec169[0];
			fVec29[1] = fVec29[0];
			fRec170[1] = fRec170[0];
			fVec30[1] = fVec30[0];
			fRec171[1] = fRec171[0];
			fRec4[1] = fRec4[0];
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
			fRec191[1] = fRec191[0];
			fRec190[1] = fRec190[0];
			fVec33[1] = fVec33[0];
			fRec192[1] = fRec192[0];
			fVec34[1] = fVec34[0];
			fRec193[1] = fRec193[0];
			fVec35[1] = fVec35[0];
			fRec194[1] = fRec194[0];
			fVec36[1] = fVec36[0];
			fRec195[1] = fRec195[0];
			fRec5[1] = fRec5[0];
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
			fRec215[1] = fRec215[0];
			fRec214[1] = fRec214[0];
			fVec39[1] = fVec39[0];
			fRec216[1] = fRec216[0];
			fVec40[1] = fVec40[0];
			fRec217[1] = fRec217[0];
			fVec41[1] = fVec41[0];
			fRec218[1] = fRec218[0];
			fVec42[1] = fVec42[0];
			fRec219[1] = fRec219[0];
			fRec6[1] = fRec6[0];
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
			fRec239[1] = fRec239[0];
			fRec238[1] = fRec238[0];
			fVec45[1] = fVec45[0];
			fRec240[1] = fRec240[0];
			fVec46[1] = fVec46[0];
			fRec241[1] = fRec241[0];
			fVec47[1] = fVec47[0];
			fRec242[1] = fRec242[0];
			fVec48[1] = fVec48[0];
			fRec243[1] = fRec243[0];
			fRec7[1] = fRec7[0];
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
			fRec263[1] = fRec263[0];
			fRec262[1] = fRec262[0];
			fVec51[1] = fVec51[0];
			fRec264[1] = fRec264[0];
			fVec52[1] = fVec52[0];
			fRec265[1] = fRec265[0];
			fVec53[1] = fVec53[0];
			fRec266[1] = fRec266[0];
			fVec54[1] = fVec54[0];
			fRec267[1] = fRec267[0];
			fRec8[1] = fRec8[0];
			fRec268[1] = fRec268[0];
			fRec269[1] = fRec269[0];
			fRec270[1] = fRec270[0];
			fRec271[1] = fRec271[0];
			fRec272[1] = fRec272[0];
			fRec273[1] = fRec273[0];
			fRec274[1] = fRec274[0];
			fRec275[1] = fRec275[0];
			fRec276[1] = fRec276[0];
			fRec277[1] = fRec277[0];
			fRec278[1] = fRec278[0];
			fRec279[1] = fRec279[0];
			fRec280[1] = fRec280[0];
			fRec281[1] = fRec281[0];
			fRec282[1] = fRec282[0];
			fRec283[1] = fRec283[0];
			fRec284[1] = fRec284[0];
			fRec285[1] = fRec285[0];
			fRec287[1] = fRec287[0];
			fRec286[1] = fRec286[0];
			fVec57[1] = fVec57[0];
			fRec288[1] = fRec288[0];
			fVec58[1] = fVec58[0];
			fRec289[1] = fRec289[0];
			fVec59[1] = fVec59[0];
			fRec290[1] = fRec290[0];
			fVec60[1] = fVec60[0];
			fRec291[1] = fRec291[0];
			fRec9[1] = fRec9[0];
			fRec292[1] = fRec292[0];
			fRec293[1] = fRec293[0];
			fRec294[1] = fRec294[0];
			fRec295[1] = fRec295[0];
			fRec296[1] = fRec296[0];
			fRec297[1] = fRec297[0];
			fRec298[1] = fRec298[0];
			fRec299[1] = fRec299[0];
			fRec300[1] = fRec300[0];
			fRec301[1] = fRec301[0];
			fRec302[1] = fRec302[0];
			fRec303[1] = fRec303[0];
			fRec304[1] = fRec304[0];
			fRec305[1] = fRec305[0];
			fRec306[1] = fRec306[0];
			fRec307[1] = fRec307[0];
			fRec308[1] = fRec308[0];
			fRec309[1] = fRec309[0];
			fRec311[1] = fRec311[0];
			fRec310[1] = fRec310[0];
			fVec63[1] = fVec63[0];
			fRec312[1] = fRec312[0];
			fVec64[1] = fVec64[0];
			fRec313[1] = fRec313[0];
			fVec65[1] = fVec65[0];
			fRec314[1] = fRec314[0];
			fVec66[1] = fVec66[0];
			fRec315[1] = fRec315[0];
			fRec10[1] = fRec10[0];
			fRec316[1] = fRec316[0];
			fRec317[1] = fRec317[0];
			fRec318[1] = fRec318[0];
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
			fRec335[1] = fRec335[0];
			fRec334[1] = fRec334[0];
			fVec69[1] = fVec69[0];
			fRec336[1] = fRec336[0];
			fVec70[1] = fVec70[0];
			fRec337[1] = fRec337[0];
			fVec71[1] = fVec71[0];
			fRec338[1] = fRec338[0];
			fVec72[1] = fVec72[0];
			fRec339[1] = fRec339[0];
			fRec11[1] = fRec11[0];
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
			fRec354[1] = fRec354[0];
			fRec355[1] = fRec355[0];
			fRec356[1] = fRec356[0];
			fRec357[1] = fRec357[0];
			fRec359[1] = fRec359[0];
			fRec358[1] = fRec358[0];
			fVec75[1] = fVec75[0];
			fRec360[1] = fRec360[0];
			fVec76[1] = fVec76[0];
			fRec361[1] = fRec361[0];
			fVec77[1] = fVec77[0];
			fRec362[1] = fRec362[0];
			fVec78[1] = fVec78[0];
			fRec363[1] = fRec363[0];
			fRec12[1] = fRec12[0];
			fRec364[1] = fRec364[0];
			fRec365[1] = fRec365[0];
			fRec366[1] = fRec366[0];
			fRec367[1] = fRec367[0];
			fRec368[1] = fRec368[0];
			fRec369[1] = fRec369[0];
			fRec370[1] = fRec370[0];
			fRec371[1] = fRec371[0];
			fRec372[1] = fRec372[0];
			fRec373[1] = fRec373[0];
			fRec374[1] = fRec374[0];
			fRec375[1] = fRec375[0];
			fRec376[1] = fRec376[0];
			fRec377[1] = fRec377[0];
			fRec378[1] = fRec378[0];
			fRec379[1] = fRec379[0];
			fRec380[1] = fRec380[0];
			fRec381[1] = fRec381[0];
			fRec383[1] = fRec383[0];
			fRec382[1] = fRec382[0];
			fVec81[1] = fVec81[0];
			fRec384[1] = fRec384[0];
			fVec82[1] = fVec82[0];
			fRec385[1] = fRec385[0];
			fVec83[1] = fVec83[0];
			fRec386[1] = fRec386[0];
			fVec84[1] = fVec84[0];
			fRec387[1] = fRec387[0];
			fRec13[1] = fRec13[0];
			fRec388[1] = fRec388[0];
			fRec389[1] = fRec389[0];
			fRec390[1] = fRec390[0];
			fRec391[1] = fRec391[0];
			fRec392[1] = fRec392[0];
			fRec393[1] = fRec393[0];
			fRec394[1] = fRec394[0];
			fRec395[1] = fRec395[0];
			fRec396[1] = fRec396[0];
			fRec397[1] = fRec397[0];
			fRec398[1] = fRec398[0];
			fRec399[1] = fRec399[0];
			fRec400[1] = fRec400[0];
			fRec401[1] = fRec401[0];
			fRec402[1] = fRec402[0];
			fRec403[1] = fRec403[0];
			fRec404[1] = fRec404[0];
			fRec405[1] = fRec405[0];
			fRec407[1] = fRec407[0];
			fRec406[1] = fRec406[0];
			fVec87[1] = fVec87[0];
			fRec408[1] = fRec408[0];
			fVec88[1] = fVec88[0];
			fRec409[1] = fRec409[0];
			fVec89[1] = fVec89[0];
			fRec410[1] = fRec410[0];
			fVec90[1] = fVec90[0];
			fRec411[1] = fRec411[0];
			fRec14[1] = fRec14[0];
			fRec412[1] = fRec412[0];
			fRec413[1] = fRec413[0];
			fRec414[1] = fRec414[0];
			fRec415[1] = fRec415[0];
			fRec416[1] = fRec416[0];
			fRec417[1] = fRec417[0];
			fRec418[1] = fRec418[0];
			fRec419[1] = fRec419[0];
			fRec420[1] = fRec420[0];
			fRec421[1] = fRec421[0];
			fRec422[1] = fRec422[0];
			fRec423[1] = fRec423[0];
			fRec424[1] = fRec424[0];
			fRec425[1] = fRec425[0];
			fRec426[1] = fRec426[0];
			fRec427[1] = fRec427[0];
			fRec428[1] = fRec428[0];
			fRec429[1] = fRec429[0];
			fRec431[1] = fRec431[0];
			fRec430[1] = fRec430[0];
			fVec93[1] = fVec93[0];
			fRec432[1] = fRec432[0];
			fVec94[1] = fVec94[0];
			fRec433[1] = fRec433[0];
			fVec95[1] = fVec95[0];
			fRec434[1] = fRec434[0];
			fVec96[1] = fVec96[0];
			fRec435[1] = fRec435[0];
			fRec15[1] = fRec15[0];
			fRec436[1] = fRec436[0];
			fRec437[1] = fRec437[0];
			fRec438[1] = fRec438[0];
			fRec439[1] = fRec439[0];
			fRec440[1] = fRec440[0];
			fRec441[1] = fRec441[0];
			fRec442[1] = fRec442[0];
			fRec443[1] = fRec443[0];
			fRec444[1] = fRec444[0];
			fRec445[1] = fRec445[0];
			fRec446[1] = fRec446[0];
			fRec447[1] = fRec447[0];
			fRec448[1] = fRec448[0];
			fRec449[1] = fRec449[0];
			fRec450[1] = fRec450[0];
			fRec451[1] = fRec451[0];
			
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

#define ASSIST_INLET 	1  		/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2		/* should be defined somewhere ?? */

#define EXTERNAL_VERSION "0.59"

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

        virtual void addMidiIn(midi* midi_dsp) { fMidiInputs.push_back(midi_dsp); }
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
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
		FAUSTFLOAT wheel2bend(float v){
			return pow(2.0,(v/16383.0*4-2)/12);
		}

		int bend2wheel(float v){
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

// ends_with(<str>,<end>) : returns true if <str> ends with <end>
static inline bool ends_with(std::string const& str, std::string const& end)
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

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {
    
    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop re-trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGateLabel;
    std::string fGainLabel;
    std::string fFreqLabel;

    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractLabels(fGateLabel, fFreqLabel, fGainLabel);
    }
    
    void extractLabels(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string label = (*it).first;
            if (ends_with(label, "/gate")) {
                gate = label;
            } else if (ends_with(label, "/freq")) {
                freq = label;
            } else if (ends_with(label, "/gain")) {
                gain = label;
            }
        }
    }
    
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqLabel, midiToFreq(pitch));
        setParamValue(fGainLabel, float(velocity)/127.f);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }
    
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqLabel, midiToFreq(pitch));
        setParamValue(fGainLabel, velocity);
        fNote = pitch;
        fTrigger = true; // so that envelop is always re-initialized
    }
    
    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGateLabel, FAUSTFLOAT(0));
        if (hard) {
            // Stops immediately
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
            // New note, so re-trigger
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }
    
    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGateLabel, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGateLabel, FAUSTFLOAT(1));
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
    
        std::vector<MidiUI*> fMidiUIList;
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
            if (fVoiceTable.size() > 1) {
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
            
            // Remove object from all MidiUI interfaces that handle it
            for (int i = 0; i < fMidiUIList.size(); i++) {
                fMidiUIList[i]->removeMidiIn(this);
            }
        }
    
        // DSP API
        void buildUserInterface(UI* ui_interface)
        {
            // Add itself to the MidiUI object
            MidiUI* midi_ui = dynamic_cast<MidiUI*>(ui_interface);
            if (midi_ui) {
                fMidiUIList.push_back(midi_ui);
                midi_ui->addMidiIn(this);
            }
            
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

struct MyMeta : public Meta, public std::map<std::string, std::string>
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
};

static void analyseMeta(bool& midi_sync, int& nvoices)
{
    mydsp* tmp_dsp = new mydsp();
    
    JSONUI jsonui;
    tmp_dsp->buildUserInterface(&jsonui);
    std::string json = jsonui.JSON();
    midi_sync = ((json.find("midi") != std::string::npos) &&
                 ((json.find("start") != std::string::npos) ||
                  (json.find("stop") != std::string::npos) ||
                  (json.find("clock") != std::string::npos)));
    
#ifdef NVOICES
    nvoices = NVOICES;
#else
    MyMeta meta;
    tmp_dsp->metadata(&meta);
    std::string numVoices = meta.get("nvoices", "0");
    nvoices = atoi(numVoices.c_str());
    if (nvoices < 0) nvoices = 0;
#endif
    
    delete tmp_dsp;
}

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
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true), new effect());
        #else
            obj->m_dsp = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #endif
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
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
    int nvoices = 1;
    
    analyseMeta(midi_sync, nvoices);
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 1) {
        post("polyphonic DSP voices = %d", nvoices);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(new mydsp_poly(new mydsp(), nvoices, true, true), new effect());
    #else
        x->m_dsp = new mydsp_poly(new mydsp(), nvoices, true, true);
    #endif
        
    #ifdef MIDICTRL
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





#endif
