//--------------------------------------------------------------------------------------//
//---------------------------------------mTapAndCo--------------------------------------//
//
//--------------A TOOLBOX OF MULTI-DELAY AND SOUND TRANSFORMATIONS IN FAUST-------------//
//------------------------------------FOR MIXED MUSIC-----------------------------------//
//
//-------------------------BY ALAIN BONARDI - 2015 - 2016-------------------------------//
//--------------------------------------------------------------------------------------//

declare name "mTRandomEnv";
declare author "Alain Bonardi";
declare licence "GPLv3";

import("math.lib");
import("maxmsp.lib"); 
import("music.lib");
import("filter.lib");

smoothLine = smooth(tau2pole(0.02));

rarefaction = hslider("h:RandomEnv/shortening", 0.5, 0, 1, 0.01) : smoothLine;
freq = nentry("h:RandomEnv/freq", 10, 0.01, 100, 0.01) : smoothLine;

//--------------------------------------------------------------------------------------//
//DEFINITION OF A SAMPLE AND HOLD FUNCTION
//--------------------------------------------------------------------------------------//
SH(x, trig) = (*(1-trig) + x*trig) ~ _;

//--------------------------------------------------------------------------------------//
//DEFINITION OF A PUREDATA LIKE PHASOR
//--------------------------------------------------------------------------------------//
//
basicPhasor(f) = (_, 1. : fmod) ~ +(float(f)/float(SR));
pdPhasor(f) = (if (f>0, basicPhasor(f), 1.+basicPhasor(f)));

//--------------------------------------------------------------------------------------//
//DEFINITION OF A SINUS FOR ENVELOPPING
//--------------------------------------------------------------------------------------//
sinusEnvelop(phase) = s1 + d * (s2 - s1)
	with {
			myIndex = phase * float(tablesize);
			i1 = int(myIndex);
			d = decimal(myIndex);
			i2 = (i1+1) % int(tablesize);
			s1 = rdtable(tablesize, sinwaveform, i1);
			s2 = rdtable(tablesize, sinwaveform, i2);
};

//--------------------------------------------------------------------------------------//
//INPUT DISPATCHING
//--------------------------------------------------------------------------------------//
//
//starting with 2n values sigA1, sigA2, ... sigAn, sigB1, sigB2, ... sigBn
//the result is the vector sigA1, sigB1, sigA2, sigB2, ..., sigAn, sigBn
//--------------------------------------------------------------------------------------//
inputSort(n) = bus(2*n) <: par(i, n, (selector(i, 2*n), selector(i+n, 2*n)));

shorteningEnv(f, s) = ((ramp : *(0.5) : sinusEnvelop), _) : *(factor)
	with {
			randTest = (_, (s : *(2) : -(1))) : >;
			ramp = pdPhasor(f);
			th = (ramp > 0.001) * (ramp@1 <= 0.001);
			factor = SH(randTest, th);
	};

mTShorteningEnv(n, f, s) = multinoise(n) : par(i, n, shorteningEnv(f, s));

mTShortening(n, f, s) = par(i, n, _), mTShorteningEnv(n, f, s) : inputSort(n) : par(i, n, *);
mTShortening4(f, s) = mTShortening(4, f, s);
mTShortening8(f, s) = mTShortening(8, f, s);
mTShortening16(f, s) = mTShortening(16, f, s);

process=mTShortening8(freq, rarefaction);