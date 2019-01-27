//--------------------------------------------------------------------------------------//
//---------------------------------------mTapAndCo--------------------------------------//
//
//--------------A TOOLBOX OF MULTI-DELAY AND SOUND TRANSFORMATIONS IN FAUST-------------//
//------------------------------------FOR MIXED MUSIC-----------------------------------//
//
//-------------------------BY ALAIN BONARDI - 2015 - 2016-------------------------------//
//--------------------------------------------------------------------------------------//

declare name "mTDelHarmoMG16";
declare author "Alain Bonardi";
declare licence "GPLv3";

import("stdfaust.lib");
//import("math.lib");
//import("maxmsp.lib"); 
//import("music.lib");
//import("filter.lib");

//smooth (filter.lib) : si.smooth, ba.tau2pole//
//line
//si.bus
//ba.selector
//ma.SR
//os.sinwaveform

//--------------------------------------------------------------------------------------//
//GENERAL MATRIX//
//--------------------------------------------------------------------------------------//
//matrix of N x M toggles//
//
toggle(c, in) = checkbox("h:Lines/h:Reinjection_Matrix/v:Del%2c-->/r%3in"):smoothLine;
Mixer(N,out) 	= par(in, N, *(toggle(in, in+out*N)) ) :> _ ;
Matrix(N,M) 	= par(in, N, _) <: par(out, M, Mixer(N, out));

//--------------------------------------------------------------------------------------//
//FEEDBACK REINJECTION MATRICES N x N
//--------------------------------------------------------------------------------------//
fdMatrix(N) = Matrix(N, N);

//--------------------------------------------------------------------------------------//
//CONTROL PARAMETERS
//--------------------------------------------------------------------------------------//
delayOverlappingFreq = 10;

millisec	= ma.SR/1000.0;
delay43s(d)		= delay(2097152,d);
tablesize 	= 1 << 16;
decimal(x)	= x - floor(x);

//Size of the harmonizer window for Doppler effect//
hWin = hslider("h:Global_Parameters/hWin", 64, 1, 127, 0.01) : pdLineDrive4096 : smoothLine;

//Duration of smoothing//
smoothDuration = hslider("h:Global_Parameters/smoothDuration", 20, 10, 5000, 1)/1000;

//Delay line parameters//

d(ind) = int(hslider("h:Lines/v:Del_Durations/d%2ind", (100*(ind+1)), 0, 43000, 1)*millisec*hslider("h:Global_Parameters/dStretch [7]", 1, 0.01, 10, 0.01)) : smoothLine;
fd(ind) = hslider("h:Lines/v:Del_Feedbacks/fd%2ind", 0, 0, 0.99, 0.01):smoothLine;

//Dispatching between harmonizer (1) and simple delay (0)//
xvd(ind) = hslider("h:Lines/v:EffeX_vs_Del/xvd%2ind", 1, 0, 1, 0.01):smoothLine;

//Transposition in midicents//
tr(ind) = hslider("h:Lines/v:Harmo_Transpositions/tr%2ind", 0, -2400, 2400, 1)*hslider("h:Global_Parameters/hStretch [7]", 1, -10, 10, 0.01) : smoothLine;

//Input gains//
//from 0 to 1//
inp(ind) = hslider("h:Lines/v:Line_input/inp%2ind [5]", 1, 0, 1, 0.01):smoothLine;

//OUTPUT GAINS//
//from 0 to 4 since harmonizers can fade the output signal//
out(ind) = hslider("h:Lines/v:Line_output/out%2ind [6]", 1, 0, 4, 0.01):smoothLine;


//--------------------------------------------------------------------------------------//
//DEFINITION OF A SMOOTHING FUNCTION FOR SLIDERS
//--------------------------------------------------------------------------------------//
smoothLine = si.smooth(ba.tau2pole(smoothDuration));

//--------------------------------------------------------------------------------------//
//DEFINITION OF A PUREDATA LIKE LINEDRIVE OBJECT
//--------------------------------------------------------------------------------------//
pdLineDrive(vol, ti, r, f, b, t) = transitionLineDrive
	with {
			//vol = current volume in Midi (0-127)
			//ti = current time of evolution (in msec)
			//r is the range, usually Midi range (127)
			//f is the factor, usually 2
			//b is the basis, usually 1.07177
			//t is the ramp time usually 30 ms

			pre_val = (ba.if (vol < r, vol, r));
			val = (ba.if (pre_val < 1, 0, f*pow(b, (pre_val - r))));
			pre_ti = (ba.if (ti < 1.46, t, ti));
			transitionLineDrive = line(val, pre_ti);
		};
pdLineDrive4096 = (_, 30, 127, 4096, 1.07177, 30) : pdLineDrive;


//--------------------------------------------------------------------------------------//
//DEFINITION OF A PUREDATA LIKE PHASOR
//--------------------------------------------------------------------------------------//
//
basicPhasor(f) = (_, 1. : fmod) ~ +(float(f)/float(ma.SR));
pdPhasor(f) = (ba.if (f>0, basicPhasor(f), 1.+basicPhasor(f)));

//--------------------------------------------------------------------------------------//
//DEFINITION OF A SINUS FOR ENVELOPPING
//--------------------------------------------------------------------------------------//
sinusEnvelop(phase) = s1 + d * (s2 - s1)
	with {
			myIndex = phase * float(tablesize);
			i1 = int(myIndex);
			d = decimal(myIndex);
			i2 = (i1+1) % int(tablesize);
			s1 = rdtable(tablesize, os.sinwaveform, i1);
			s2 = rdtable(tablesize, os.sinwaveform, i2);
};

//--------------------------------------------------------------------------------------//
//DEFINITION OF A SAMPLE AND HOLD FUNCTION
//--------------------------------------------------------------------------------------//
SH(x, trig) = (*(1-trig) + x*trig) ~ _;


//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//
//CLASSICAL PROCESSES : DELAYS, DELAYS WITH HARMONIZERS, DELAYS WITH PITCH-SHba.ifTERS
//--------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//DOUBLE OVERLAPPED DELAY
//--------------------------------------------------------------------------------------//
//
//nsamp is an integer number corresponding to the number of samples of delay
//freq is the frequency of envelopping for the overlapping between the 2 delay lines
//--------------------------------------------------------------------------------------//
overlappedDoubleDelay43s(nsamp, freq) = doubleDelay
	with {
			env1 = freq : pdPhasor : sinusEnvelop : *(0.5) : +(0.5);
			env1c = 1 - env1;
			th1 = (env1 > 0.001) * (env1@1 <= 0.001); //env1 threshold crossing
			th2 = (env1c > 0.001) * (env1c@1 <= 0.001); //env1c threshold crossing
			doubleDelay =	_ <: (delay43s(SH(nsamp, th1)), delay43s(SH(nsamp, th2))) : (*(env1), *(env1c)) : + ;
		};

doubleDelay43s(nsamp) = overlappedDoubleDelay43s(nsamp, 30);

//--------------------------------------------------------------------------------------//
//MIDI TO FREQUENCY AND FREQUENCY TO MIDI FUNCTIONS
//--------------------------------------------------------------------------------------//
mtof = (1.05946309436, (_ : -(69))) : pow : *(440);
ftom = _ : /(440) : log : /(log(2)) : *(12) : +(69);

//--------------------------------------------------------------------------------------//
//CLIP FUNCTION BETWEEN -1 AND 1
//--------------------------------------------------------------------------------------//
clip(x) = (-1) * infTest + 1 * supTest + x * rangeTest
	with {
			infTest = (x < -1);
			supTest = (x > 1);
			rangeTest = (1 - infTest) * (1 - supTest);
};

//--------------------------------------------------------------------------------------//
//ELEMENTARY PITCH SHba.ifTER AND OVERLAPPED HARMONIZER
//--------------------------------------------------------------------------------------//
elemTranspo(moduleOffset, midicents, win) = dopplerDelay
			with {
					freq = midicents : +(6000) : *(0.01) : mtof : -(261.625977) : *(-3.8224) /(float(win));
					//shba.ifted phasor
					//la fonction decimal est déclarée dans music.lib
					adjustedPhasor = freq : pdPhasor : +(moduleOffset) : decimal;
					//threshold to input new control values
					th_trigger = (adjustedPhasor > 0.01) * (adjustedPhasor@1 <= 0.01);
					trig_win = (win, th_trigger):SH;
					delayTime = adjustedPhasor : *(trig_win) : *(millisec);
					variableDelay = fdelay5s(delayTime);
					cosinusEnvelop = adjustedPhasor : *(0.5) : sinusEnvelop;
					dopplerDelay = (variableDelay, cosinusEnvelop) : *;
				};

overlapped4Harmo(tra, win) = _ <: par(i, 4, elemTranspo(i/4, tra, win)) : (+, +) : + ;

overlapped4HarmoDryWet(tra, alpha, win) = _ <: (*(alpha), *(1-alpha)) : (overlapped4Harmo(tra, win), _) : +;


//--------------------------------------------------------------------------------------//
//INPUT DISPATCHING
//--------------------------------------------------------------------------------------//
//
//starting with 2n values sigA1, sigA2, ... sigAn, sigB1, sigB2, ... sigBn
//the result is the vector sigA1, sigB1, sigA2, sigB2, ..., sigAn, sigBn
//--------------------------------------------------------------------------------------//
inputSort(n) = si.bus(2*n) <: par(i, n, (ba.selector(i, 2*n), ba.selector(i+n, 2*n)));

//--------------------------------------------------------------------------------------//
//BLOCK DEFINITIONS
//--------------------------------------------------------------------------------------//
//delay block//
DelBlock(n) = par(i, n, (+ : doubleDelay43s(d(i))));

//harmonizer block//
HarmoBlock(n) = par(i, n, (clip : overlapped4HarmoDryWet(tr(i), xvd(i), hWin)));

//delay and harmonizer block//
DelHarmoBlock(n) = DelBlock(n) : HarmoBlock(n);

//feedback block//
fdBlock(n) = par(i, n, *(fd(i) : *(1 - xvd(i) * 0.75)));

//feedback and dispatching block//
fdToMatrixBlock(n) = fdBlock(n) : fdMatrix(n);

//n inlets with n gain controls//
inputBlock(n) = par(i, n, *(inp(i)));

//output gain block with n gain controls//
outputBlock(n) = par(i, n, *(out(i)));


//--------------------------------------------------------------------------------------//
//MTAP PROCESSES
//DELAY COMBINED WITH OTHER EFFECT DEFINITION
//(EFFECT IS EITHER NOTHING OR HARMONIZER OR FREQUENCY SHba.ifTER)
//--------------------------------------------------------------------------------------//
//
//mTDel(n) = n delay lines with reinjection
//mTDelHarmo(n) = n {delay lines + harmonizers} with reinjection
//mTDelFreqShba.ift(n) = n couples of freqshba.ifters (positive and negative circuits are split) 
//with 2n delay lines and reinjection
//
//each of them with two possibilities: 
//-either autoReinj which means a delay line can reinject sound only into itself (A)
//-or multReinj which means a delay line can reinject sound into any delay line (M)
//--------------------------------------------------------------------------------------//
mTDelA(n) = (inputSort(n) : DelBlock(n)) ~ (fdBlock(n));
mTDelHarmoA(n) = (inputSort(n) : DelHarmoBlock(n)) ~ (fdBlock(n));

mTDelM(n) = (inputSort(n) : DelBlock(n)) ~ (fdToMatrixBlock(n));
mTDelHarmoM(n) = (inputSort(n) : DelHarmoBlock(n)) ~ (fdToMatrixBlock(n));

//--------------------------------------------------------------------------------------//
//SAME PROCESSES WITH INPUT AND OUTPUT GAINS (G)
//--------------------------------------------------------------------------------------//
//
//mTDelAG : n inlets to n delay lines with auto reinjection
//mTDelMG : n inlets to n delay lines with multiple reinjection
//mTDelHarmoAG : n inlets to n {delay lines + harmonizers} with auto reinjection
//mTDelHarmoMG : n inlets to n {delay lines + harmonizers} with multiple reinjection
//mTDelFreqShba.iftAG : n inlets to n couples of freqshba.ifters with 2n delay lines with auto reinjection
//mTDelFreqShba.iftMG : n inlets to n couples of freqshba.ifters with 2n delay lines with multiple reinjection
//--------------------------------------------------------------------------------------//
//SIMPLE DELAYS
mTDelAG(n) = inputBlock(n) : mTDelA(n) : outputBlock(n);
mTDelMG(n) = inputBlock(n) : mTDelM(n) : outputBlock(n);

//--------------------------------------------------------------------------------------//
//DELAYS WITH HARMONIZERS
mTDelHarmoAG(n) = inputBlock(n) : mTDelHarmoA(n) : outputBlock(n);
mTDelHarmoMG(n) = inputBlock(n) : mTDelHarmoM(n) : outputBlock(n);



//--------------------------------------------------------------------------------------//
//PROCESS
//--------------------------------------------------------------------------------------//
process = _ <: mTDelHarmoMG(16);