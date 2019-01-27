//----------------------------------------------------------------------------------------// 
//GLOBAL VARIABLES AND MESSAGES
//----------------------------------------------------------------------------------------// 
inlets = 1;
outlets = 1;
var tapMsg = 'toMTap';
var inCtrlMsg = 'toInputController';
var timerOnOffMsg = 'timerOnOff';
var timerBang = 'timerBang';
var toState = 'toState';
var toAttackNumber = 'toAttackNumber';
var toReleaseNumber = 'toReleaseNumber';
var toFreqShift = 'toFreqShift';
var toSpat = 'toSpat';
var transfoInput = 'transfoInput';
var envDur = 'envDur';
var envType = 'envType';
var openCloseForced = 'openCloseForced';
var relForced = 'relForced';
var relForcedDur = 'relForcedDur';
var outNumber = 0;
var scheduledTaskNumber = 0;
var pianoHasStarted = 0;
var seqFinished = 0;
//----------------------------------------------------------------------------------------// 
var beatDuration = 600;
var newtStretch = 1;
var state = 0; //state number//
var attackNumber = 0;
var releaseNumber = 0;
var chrono;
var spat;
//durations captured in sequence 2//
var d21 = 3000;
//----------------------------------------------------------------------------------------//
//global variables for spatialization//
//----------------------------------------------------------------------------------------//
//harmoniques ambisoniques à l'ordre 3//
var h0 = 0;
var h_1 = 1;
var h1 = 2;
var h_2 = 3;
var h2 = 4;
var h_3 = 5;
var h3 = 6;
//encodeurs de 1 à 4//
var encoder1 = 7;
var encoder2 = 8;
var encoder3 = 9;
var encoder4 = 10;
//sorties du mTap de 0 à 15//
var mt0 = 0;
var mt1 = 1;
var mt2 = 2;
var mt3 = 3;
var mt4 = 4;
var mt5 = 5;
var mt6 = 6;
var mt7 = 7;
var mt8 = 8;
var mt9 = 9;
var mt10 = 10;
var mt11 = 11;
var mt12 = 12;
var mt13 = 13;
var mt14 = 14;
var mt15 = 15;
//piano direct//
var pianodir = 16;
//----------------------------------------------------------------------------------------//
//INSTRUMENT CLASS INSTANCES//
//----------------------------------------------------------------------------------------//
var bass2oct0, hcymbal0, dgliss0, timb0, quintu0;
var thickchord1, quintd1, trem1;
var cmotive2ostinato, cmotive2arpege;
var infRev61, infRev62;
var refbass9, dgliss9, hcymbal9, harmonicset9;

//----------------------------------------------------------------------------------------// 
//FUNCTIONS TO SEND MESSAGES TO MTAP CONTROLLLER
//----------------------------------------------------------------------------------------//
//-setDuration(i, v)
//-outputAllDurations()
//-setTransposition(i, v)
//-outputAllTranspositions()
//-setFd(i, v)
//-outputAllFds()
//-setHvd(i, x)
//-outputAllHvds()
//-setInp(i, v)
//-outputAllInps()
//-setOut(i, v)
//-outputAllOuts()
//-mFdMatColumnReset(i0, n)
//-mFdMat(x, y, val)
//-mFdMarReset()
//-updateMTapDisplays()
//-setGlobalParameters(tStre, wD, hStre, wH)
//----------------------------------------------------------------------------------------// 
function setDuration(i, v) {
	outlet(outNumber, tapMsg, 'setDuration', i, v);
}
//----------------------------------------------------------------------------------------// 
function outputAllDurations() {
	outlet(outNumber, tapMsg, 'outputAllDurations');
}
//----------------------------------------------------------------------------------------// 
function setTransposition(i, v) {
	outlet(0, tapMsg, 'setTransposition', i, v);
}
//----------------------------------------------------------------------------------------// 
function outputAllTranspositions() {
	outlet(0, tapMsg, 'outputAllTranspositions');
}	
//----------------------------------------------------------------------------------------// 
function setFd(i, v) {
	outlet(0, tapMsg, 'setFd', i, v);
}
//----------------------------------------------------------------------------------------// 
function outputAllFds() {
	outlet(0, tapMsg, 'outputAllFds');
}
//----------------------------------------------------------------------------------------// 
function setHvd(i, v) {
	outlet(0, tapMsg, 'setHvd', i, v);
}
//----------------------------------------------------------------------------------------// 
function outputAllHvds() {
	outlet(0, tapMsg, 'outputAllHvds');
}
//----------------------------------------------------------------------------------------// 
function setInp(i, v) {
	outlet(0, tapMsg, 'setInp', i, v); 
}
//----------------------------------------------------------------------------------------// 
function outputAllInps() {
	outlet(0, tapMsg, 'outputAllInps');
}
//----------------------------------------------------------------------------------------// 
function setOut(i, v) {
	outlet(0, tapMsg, 'setOutAndOutput', i, v);
}
//----------------------------------------------------------------------------------------// 
function outputAllOuts() {
	outlet(0, tapMsg, 'outputAllOuts');
}
//----------------------------------------------------------------------------------------// 
function mFdMatColumnReset(i0, n) {
	outlet(0, tapMsg, 'mFdMatColumnReset', i0, n);
}
//----------------------------------------------------------------------------------------// 
function mFdMat(x, y, val) {
	outlet(0, tapMsg, 'mFdMat', x, y, val);
}
//----------------------------------------------------------------------------------------// 
function mFdMatReset() {
	outlet(0, tapMsg, 'mFdMatReset');
}
//----------------------------------------------------------------------------------------// 
function updateMTapDisplays() {
	outputAllDurations();
	outputAllTranspositions();
	outputAllFds();
	outputAllHvds();
	outputAllInps();
	outputAllOuts();
}
//----------------------------------------------------------------------------------------// 
function setGlobalParameters(tStre, wD, hStre, wH, sdur) {
	setTStretch(tStre);
	outlet(0, tapMsg, 'wDel', wD);
	setHStretch(hStre);
	outlet(0, tapMsg, 'wHarmo', wH);
	setSmoothDur(sdur);
}
//----------------------------------------------------------------------------------------// 
function setFreqShift(fs) {
	outlet(0, toFreqShift, fs);
}
//----------------------------------------------------------------------------------------// 
function setSpat(spatConfig) {
	outlet(0, toSpat, spatConfig);
}
//----------------------------------------------------------------------------------------// 
function setTStretch(tStre) {
	outlet(0, tapMsg, 'tStretch', tStre);
}
//----------------------------------------------------------------------------------------// 
function setHStretch(hStre) {
	outlet(0, tapMsg, 'hStretch', hStre);
}
//----------------------------------------------------------------------------------------// 
function setSmoothDur(sdur) {
	outlet(0, tapMsg, 'smoothDuration', sdur);
}
//----------------------------------------------------------------------------------------// 
//setColumn function
//----------------------------------------------------------------------------------------// 
function setColumn(colNum, dur, tra, fdbk, hvd, inp, out) {
	setDuration(colNum, dur);
	setTransposition(colNum, tra);
	setFd(colNum, fdbk);
	setHvd(colNum, hvd);
	setInp(colNum, inp);
	setOut(colNum, out);
}

//----------------------------------------------------------------------------------------// 
//allReset function
//----------------------------------------------------------------------------------------// 
function allReset() {
	outlet(0, tapMsg, 'mDel', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	outlet(0, tapMsg, 'mTra', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	outlet(0, tapMsg, 'mFd', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	outlet(0, tapMsg, 'mHvd', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	outlet(0, tapMsg, 'mInp', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	outlet(0, tapMsg, 'mOut', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	mFdMatReset();
}


//----------------------------------------------------------------------------------------// 
//common functions for classes
//----------------------------------------------------------------------------------------// 
function setAllInputOn(i0, n) {
	var i;
	for (i = 0; i < n; i++) {
 		setInp(i0+i, 1);
	}
	outputAllInps();
}

function setAllInputOff(i0, n) {
	var i;
	for (i = 0; i < n; i++) {
 		setInp(i0+i, 0);
	}
	outputAllInps();
}

//----------------------------------------------------------------------------------------// 
//inputController functions
//----------------------------------------------------------------------------------------// 
function setEnvDel(envdel) {
	outlet(0, inCtrlMsg, envDel, envdel);
}

function setEnvType(envty) {
	outlet(0, inCtrlMsg, envType, envty);
}

function setEnvDur(envdur) {
	outlet(0, inCtrlMsg, envDur, envdur);
}

function setRelForced(relf) {
	outlet(0, inCtrlMsg, relForced, relf);
}

function setRelForcedDur(relfd) {
	outlet(0, inCtrlMsg, relForcedDur, relfd);
}

function setFirstOnset(firston) {
	outlet(0, inCtrlMsg, 'firstOnset', firston);
}

function setOpenCloseForced(ocf) {
	outlet(0, inCtrlMsg, openCloseForced, ocf);
}

function setOpenEnvTrigger() {
	setOpenCloseForced(1);
}

function setCloseEnvTrigger() {
	setOpenCloseForced(0);
}

function setTransfoInput(ti) {
	outlet(0, inCtrlMsg, transfoInput, ti);
}

function setDetectionOnOff(detecton) {
	outlet(0, inCtrlMsg, 'detectionOnOff', detecton);
}

function setDetectionOn() {
	setDetectionOnOff(1);
}

function setDetectionOff() {
	setDetectionOnOff(0);
}

function skipToNext(evt, del) {
	outlet(0, 'triggersNext', evt, del);
}

function setProcessedLevel(l) {
	//passing level only//
	outlet(0, inCtrlMsg, 'setProcessedLevel', l);
}

function setProcessedLevel(l, d) {
	//passing level and duration of evolution//
	outlet(0, inCtrlMsg, 'setProcessedLevel', l, d);
}

function setDirectLevel(l) {
	//passing level only//
	outlet(0, inCtrlMsg, 'setDirectLevel', l);
}

function setDirectLevel(l,d) {
	//passing level and duration of evolution//
	outlet(0, inCtrlMsg, 'setDirectLevel', l, d);
}

function displayPianoStart() {
	outlet(0, 'toPianoStart', pianoHasStarted);
}

function pianoNotStarted() {
	pianoHasStarted = 0;
	displayPianoStart();
}

function pianoStarted() {
	pianoHasStarted = 1;
	displayPianoStart();
}

function displaySeqFinished() {
	outlet(0, 'toSeqFinished', seqFinished);
}

function seqIsNotFinished() {
	seqFinished = 0;
	displaySeqFinished();
}

function seqIsFinished() {
	seqFinished = 1;
	displaySeqFinished();
}

function begOfSeq() {
	pianoNotStarted();
	seqIsNotFinished();
}

function endOfSeq() {
	seqIsFinished();
	pianoNotStarted();
	allReset();
}
//----------------------------------------------------------------------------------------// 
//Chronometer class
//----------------------------------------------------------------------------------------// 
var Chronometer = function() {
	this.topNumber = 0;
}

Chronometer.prototype.top = function() {
	this.topNumber = this.topNumber + 1;
	outlet(0, inCtrlMsg, timerBang, 1);
}

Chronometer.prototype.able = function() {
	outlet(0, inCtrlMsg, timerOnOffMsg, 1);
}

Chronometer.prototype.disable = function() {
	outlet(0, inCtrlMsg, timerOnOffMsg, 0);
}

//----------------------------------------------------------------------------------------// 
//Spatializer class
//----------------------------------------------------------------------------------------// 
var Spatializer = function() {
	this.clear;
}

Spatializer.prototype.clear = function() {
	outlet(0, toSpat, 'clear');
}

Spatializer.prototype.connect = function(indm, inds) {
	outlet(0, toSpat, indm, inds, 1);
}

Spatializer.prototype.setRotSpeeds = function(v1, v2, v3, v4) {
	outlet(0, toSpat, 'rotSpeeds', v1, v2, v3, v4);
}

Spatializer.prototype.setRotPhases = function(ph1, ph2, ph3, ph4) {
	outlet(0, toSpat, 'rotPhases', ph1, ph2, ph3, ph4);
}

Spatializer.prototype.multiplePairs = function(a) {
	//receives the starting index i and several indices of spatialization inputs j0, j1, j2, etc.//
	//i is connected to j0, i+1 to j1, i+2 to j2 etc.//
	var i, j;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		this.connect(j+i-1, arguments[i]);
	}
} 

Spatializer.prototype.oneOutToSeveral = function(a) {
	//receives the index i of the output and several indices of spatialization inputs j0, j1, j2, etc. to connect to//
	//i is connected to j0 and j1 and j2, etc.//
	var i, j;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		this.connect(j, arguments[i]);
	}
}

Spatializer.prototype.setConfig = function(index) {
	this.clear();
	switch (index)
	{
		case 0 : 
			//this is config #0 for sequence 0//
			//Bass2octava
			this.multiplePairs(mt0, h_1, h1, h_2, h2);
			//highCymbal
			this.multiplePairs(mt4, h_3, h3);
			//Downglissando
			this.multiplePairs(mt6, encoder1, encoder2, encoder3);
			//Timbales
			//mt9 and mt10 not connected (volume = 0)
			this.multiplePairs(mt11, h_1, h1);
			//Quinteup
			//mt13 not connected (volume = 0)
			this.multiplePairs(mt14, h_2, h2);
			//Direct piano
			this.connect(pianodir, encoder4);
			//rotSpeeds
			this.setRotSpeeds(0.77, -0.66, 0.3, 0.1);
			//rotPhases//
			this.setRotPhases(0., 0., 0., 0.);
		break;
		case 1:
			//this is config #1 for sequences 1 and 4//
			//Thickchord
			//mt0 not connected (volume = 0)
			this.multiplePairs(mt1, h_1, h1, h_2, h2, h_3, h3);
			this.oneOutToSeveral(mt7, encoder1, h_2);
			this.oneOutToSeveral(mt8, encoder2, h2);
			this.oneOutToSeveral(mt9, encoder3, h_3);
			//Quintedown
			this.oneOutToSeveral(mt10, encoder3, h_1);
			this.oneOutToSeveral(mt11, encoder2, h1);
			this.oneOutToSeveral(mt12, encoder1, h_2)
			this.connect(mt13, h2);
			//Tremolo
			this.multiplePairs(mt14, h_3, h3);
			//direct piano
			this.oneOutToSeveral(pianodir, h_3, h3);
			//rotSpeeds
			this.setRotSpeeds(0.3, -0.25, 0.2, 0.);
			//rotPhases
			this.setRotPhases(0., 0., 0., 0.);
		break;
		case 2:
			//this is config #2 for sequence 2//
			//circularmotive
			this.multiplePairs(mt0, h_1, h1, h_2, h2, h_3, h3, h_1, h1);
			//circularmotive
			this.multiplePairs(mt8, h_2, h2, h_3, h3, h_1, h1, h_2, h2);
			//direct piano
			this.oneOutToSeveral(pianodir, h0, encoder1);
			//rotSpeeds
			this.setRotSpeeds(0.29, -0.22, 0.33, -0.24);
			//rotPhases
			this.setRotPhases(0., 0.5, 0, 0.5);
		break;
		case 3:
			//this is config #3 for sequence 6//
			//ReflectiveBass
			this.oneOutToSeveral(mt0, h_1, h_3);
			this.oneOutToSeveral(mt1, h1, h3);
			this.multiplePairs(mt2, h_2, h2);
			//Downglissando
			this.oneOutToSeveral(mt4, h2, encoder1);
			this.oneOutToSeveral(mt5, h_3, encoder2);
			this.oneOutToSeveral(mt6, h3, encoder3);
			//HighCymbal
			this.connect(mt7, encoder4);
			this.connect(mt8, encoder3);
			//Harmonicset
			this.oneOutToSeveral(mt9, h_1, encoder4);
			this.oneOutToSeveral(mt10, h1, encoder3);
			this.oneOutToSeveral(mt11, h_2, encoder4);
			this.oneOutToSeveral(mt12, h2, encoder3);
			this.oneOutToSeveral(mt13, h_3, encoder4);
			this.oneOutToSeveral(mt14, h3, encoder3);
			//direct piano
			this.connect(pianodir, h0);
			//rotSpeeds
			this.setRotSpeeds(1.5, -1.2, 0.1, 0.3);
			//rotPhases
			this.setRotPhases(0., 0., 0., 0.)
		break;
		case 4:
			//this is config #4 for the final sequence//
			//ReflectiveBass
			this.oneOutToSeveral(mt0, h_1, h_3);
			this.oneOutToSeveral(mt1, h1, h3);
			this.multiplePairs(mt2, h_2, h2);
			//Downglissando
			this.oneOutToSeveral(mt4, h2, encoder1);
			this.oneOutToSeveral(mt5, h_3, encoder2);
			this.oneOutToSeveral(mt6, h3, encoder3);
			//HighCymbal
			this.connect(mt7, encoder4);
			this.connect(mt8, encoder3);
			//Harmonicset
			this.oneOutToSeveral(mt9, h_1, encoder1, encoder4);
			this.oneOutToSeveral(mt10, h1, encoder2, encoder3);
			this.oneOutToSeveral(mt11, h_2, encoder1, encoder4);
			this.oneOutToSeveral(mt12, h2, encoder2, encoder3);
			this.oneOutToSeveral(mt13, h_3, encoder1, encoder4);
			this.oneOutToSeveral(mt14, h3, encoder2, encoder3);
			//direct piano
			this.connect(pianodir, h0);
			//rotSpeeds
			this.setRotSpeeds(1.5, -1.2, 0.1, 0.3);
			//rotPhases
			this.setRotPhases(0., 0., 0., 0.)
		break;
		case 5:
			//this is config #5 for sequence 5//
			//circularmotive
			this.multiplePairs(mt0, h_1, h1, h_2, h2);
			this.multiplePairs(mt4, h_2, h2, h_3, h3);
			//circularmotive
			this.multiplePairs(mt8, h1, h_1, h2, h_2);
			this.multiplePairs(mt12, h3, h_3, h2, h_2);
			//direct piano
			this.oneOutToSeveral(pianodir, h0, encoder1);
			//rotSpeeds
			this.setRotSpeeds(0.29, -0.22, 0.33, -0.24);
			//rotPhases
			this.setRotPhases(0., 0.5, 0, 0.5);
			/*
			//circularmotive
			this.multiplePairs(mt0, h_1, h1);
			this.oneOutToSeveral(mt2, h_2, encoder3);
			this.oneOutToSeveral(mt3, h2, encoder4);
			this.multiplePairs(mt4, h_2, h2, h_3, h3);
			//circularmotive
			this.multiplePairs(mt8, h1, h_1);
			this.oneOutToSeveral(mt10, h2, encoder3);
			this.oneOutToSeveral(mt11, h_2, encoder4);
			this.multiplePairs(mt12, h3, h_3, h2, h_2);
			//direct piano
			this.oneOutToSeveral(pianodir, h0, encoder1);
			//rotSpeeds
			this.setRotSpeeds(0.29, -0.22, 0.33, -0.24);
			//rotPhases
			this.setRotPhases(0., 0.5, 0, 0.5);
			*/
		break;
	}
}


//----------------------------------------------------------------------------------------// 
//Bass2octava class//
//transpositeur à la double octave inférieure avec 4 lignes à retard//
//----------------------------------------------------------------------------------------// 
var Bass2octava = function(index) {
	//une seule donnee dans cette classe : l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	this.index = index;
	//this.outlevel = 1.;//trop fort en octophonie
	this.outlevel = 0.5;
	this.highIn = 0.7;
	this.lowIn = 0.6;
	this.reinjLevel = 0.1;
	//equivalent du constructeur//
	//Parameter definition for the four delay lines//
	setColumn(index, 0, -1800, 0, 1, this.highIn, this.outlevel);
	setColumn(index+1, 460, -1800, 0, 1, this.highIn, this.outlevel);
	setColumn(index+2, 1610, 0, this.reinjLevel, 1, 0, this.outlevel);
	setColumn(index+3, 1750, 0, this.reinjLevel, 1, 0, this.outlevel);
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 4 lignes//
	mFdMatColumnReset(index, 4);
	mFdMat(1+index, 2+index, 1);
	//display update
	updateMTapDisplays()
};

//methodes de la classe basse2octaves
Bass2octava.prototype.line2On = function() {
	setFd(this.index+1, this.reinjLevel);
	setInp(this.index, this.lowIn);
	setInp(this.index+1, this.lowIn);
	outputAllFds();
	outputAllInps();
};

Bass2octava.prototype.line2Off = function() {
	setFd(this.index+1, 0);
	setInp(this.index, this.highIn);
	setInp(this.index+1, this.highIn);
	outputAllFds();
	outputAllInps();
};

Bass2octava.prototype.echoOn = function() {
	mFdMat(this.index+1, this.index+3, 1);
	mFdMat(this.index+2, this.index+2, 1);
	mFdMat(this.index+3, this.index+3, 1);
};

Bass2octava.prototype.echoOff = function() {
	mFdMat(this.index+1, this.index+3, 0);
	mFdMat(this.index+2, this.index+2, 0);
	mFdMat(this.index+3, this.index+3, 0);
};

Bass2octava.prototype.off = function() {
	setOut(this.index, 0);
	setOut(this.index+1, 0);
	setOut(this.index+2, 0);
	setOut(this.index+3, 0);
	outputAllOuts();
};	


//----------------------------------------------------------------------------------------// 
//Highcymbal class//
//Transposition à l'octave supérieure avec un delay d'environ 1 seconde//
//Instrument sur 2 lignes à retard
//----------------------------------------------------------------------------------------// 
var Highcymbal = function(index) {
	//une seule donnee dans cette classe : l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	this.index = index;
	this.columnNumber = 2;
	//equivalent du constructeur//
	//Parameter definition for the 2 delay lines//
	setColumn(index, 920, 1250, 0, 1, 0, 0.12);
	setColumn(index+1, 1030, 1210, 0, 1, 0, 0.1);
	//reinitialisation de mFdMat sur les 2 lignes//
	//pas de valeur non nulle//
	mFdMatColumnReset(index, 2);
	//display update
	updateMTapDisplays()
}

//Methodes de la classe highcymbal//
Highcymbal.prototype.inputOn = function() {
	setAllInputOn(this.index, this.columnNumber);
}

Highcymbal.prototype.inputOff = function() {
	setAllInputOff(this.index, this.columnNumber);
}

Highcymbal.prototype.setLevel = function(l1, l2) {
	setOut(this.index, l1);
	setOut(this.index+1, l2);
	outputAllOuts();
}

//----------------------------------------------------------------------------------------// 
//classe Downglissando//
//Small interval down glissando with reinjection using 3 lines//
//----------------------------------------------------------------------------------------// 
var Downglissando = function(index) {
	//une seule donnee dans cette classe : l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	this.index = index;
	this.outLevel = 0.8;
	//equivalent du constructeur//
	//Parameter definition for the 3 delay lines//
	setColumn(index, 325, -180, 0.999, 1, 0, this.outLevel);
	setColumn(index+1, 250, -90, 0.999, 1, 0, this.outLevel);
	setColumn(index+2, 280, 0, 0.8, 1, 0, this.outLevel);
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 3 lignes//
	mFdMatColumnReset(index, 3);
	mFdMat(index, index+2, 1);
	mFdMat(index+1, index+1, 1);
	mFdMat(index+2, index+2, 1);
	
	//display update
	updateMTapDisplays()
};

//Methodes de la classe Downglissando//
Downglissando.prototype.inputOn = function() {
	setInp(this.index, 1);
	setInp(this.index+1, 1);
	outputAllInps();
}

Downglissando.prototype.inputOff = function() {
	setInp(this.index, 0);
	setInp(this.index+1, 0);
	outputAllInps();
}

Downglissando.prototype.on = function() {
	setOut(this.index, 1);
	setOut(this.index+1, 1);
	setOut(this.index+2, 1);
	outputAllOuts();
}

Downglissando.prototype.off = function() {
	setOut(this.index, 0);
	setOut(this.index+1, 0);
	setOut(this.index+2, 0);
	outputAllOuts();
}

//----------------------------------------------------------------------------------------// 
//classe Timbales//
//transposition vers le grave sur 4 lignes évoquant le son de timbale//
//----------------------------------------------------------------------------------------// 
var Timbales = function(index) {
	//2 donnees//
	//-l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	//-la valeur basse de reinjection//
	this.index = index;
	this.outLevel = 0.8;
	this.lowReinj = 0.15;
	//equivalent du constructeur//
	//Parameter definition for the 4 delay lines//
	setColumn(index, 2650, 0, 0.999, 1, 0, 0);
	setColumn(index+1, 3400, 0, 0.999, 1, 0, 0);
	setColumn(index+2, 0, -1730, 0, 1, 0, this.outLevel);
	setColumn(index+3, 0, -2100, 0, 1, 0, this.outLevel);
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 4 lignes//
	mFdMatColumnReset(index, 4);
	mFdMat(index, index, 1);
	mFdMat(index, index+2, 1);
	mFdMat(index+1, index+1, 1);
	mFdMat(index+1, index+3, 1);
	//display update
	updateMTapDisplays()
};

//methodes de la classe basse2octaves
Timbales.prototype.on = function() {
	setOut(this.index+2, this.outLevel);
	setOut(this.index+3, this.outLevel);
	outputAllOuts();
};

Timbales.prototype.off = function() {
	setOut(this.index+2, 0);
	setOut(this.index+3, 0);
	outputAllOuts();
};

Timbales.prototype.inputOn = function() {
	setInp(this.index, 1);
	setInp(this.index+1, 1);
	outputAllInps();
};

Timbales.prototype.inputOff = function() {
	setInp(this.index, 0);
	setInp(this.index+1, 0);
	outputAllInps();
};

Timbales.prototype.lowReinjection = function() {
	setFd(this.index, this.lowReinj);
	setFd(this.index+1, this.lowReinj);
	outputAllFds();
}


//----------------------------------------------------------------------------------------// 
//classe Quinteup//
//Transposition quinte vers le haut//
//cet instrument utilise 3 lignes à retard//
//----------------------------------------------------------------------------------------// 
var Quinteup = function(index) {
	//une seule donnee dans cette classe : l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	this.index = index;
	//equivalent du constructeur//
	//Parameter definition for the 3 delay lines//
	setColumn(index, 25, 0, 0.999, 1, 0, 0);
	setColumn(index+1, 0, 697, 0, 0.87, 0, 1);
	setColumn(index+2, 0, 703, 0, 0.89, 0, 1);
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 3 lignes//
	mFdMatColumnReset(index, 3);
	mFdMat(index, index, 1);
	mFdMat(index, index+1, 1);
	mFdMat(index, index+2, 1);
	
	//display update
	updateMTapDisplays()
};

//Methodes de la classe Quinteup//
Quinteup.prototype.inputOn = function() {
	setInp(this.index, 1);
	outputAllInps();
}

Quinteup.prototype.inputOff = function() {
	setInp(this.index, 0);
	outputAllInps();
}

/*
Quinteup.protoype.off = function() {
	setOut(this.index+1, 0);
	setOut(this.index+2, 0);
	outputAllOuts();
}*/

//----------------------------------------------------------------------------------------// 
//classe ThickChord//
//cree un accord et une 'aura' de cet accord sur une note de départ 
//10 lignes à retard necessaires
//----------------------------------------------------------------------------------------// 
var ThickChord = function(index) {
	//une seule donnee dans cette classe : l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	this.index = index;
	this.outLevel1 = 1;
	this.outLevel2 = 0.8;
	//equivalent du constructeur//
	//Parameter definition for the 10 delay lines//
	setColumn(index, beatDuration*0.5, 0, 0.5, 1, 1, 0);
	setColumn(index+1, 0, 300, 0, 1, 0, this.outLevel1);
	setColumn(index+2, 0, 400, 0, 1, 0, this.outLevel1);
	setColumn(index+3, 0, 500, 0, 1, 0, this.outLevel1);
	setColumn(index+4, 0, 900, 0, 1, 0, this.outLevel1);
	setColumn(index+5, 0, 800, 0, 1, 0, this.outLevel1);
	setColumn(index+6, 0, 500, 0, 1, 0, this.outLevel1);
	setColumn(index+7, 0, 500, 0.999, 1, 1, this.outLevel2);
	setColumn(index+8, 0, 800, 0.999, 1, 1, this.outLevel2);
	setColumn(index+9, 0, 900, 0.999, 1, 1, this.outLevel2);	
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 4 lignes//
	mFdMatColumnReset(index, 10);
	mFdMat(index, index, 1);
	mFdMat(index, index+1, 1);
	mFdMat(index, index+2, 1);
	mFdMat(index, index+3, 1);
	mFdMat(index, index+4, 1);
	mFdMat(index, index+5, 1);
	mFdMat(index, index+6, 1);
	//display update
	updateMTapDisplays()
};

//methodes de la classe basse2octaves
ThickChord.prototype.setTranspositions = function(tr1, tr2, tr3, tr4, tr5, tr6) {
	setTransposition(this.index+1, tr1);
	setTransposition(this.index+2, tr2);
	setTransposition(this.index+3, tr3);
	setTransposition(this.index+4, tr4);
	setTransposition(this.index+5, tr5);
	setTransposition(this.index+6, tr6);
	//symmetry : tr7 = tr6 / tr8 = tr5 / tr9 = tr4
	setTransposition(this.index+7, tr6);
	setTransposition(this.index+8, tr5);
	setTransposition(this.index+9, tr4);
	outputAllTranspositions();
}

ThickChord.prototype.setMainFd = function(fdbk) {
	setFd(this.index, fdbk);
	outputAllFds();
}

ThickChord.prototype.on = function() {
	setOut(this.index+1, this.outLevel1);
	setOut(this.index+2, this.outLevel1);
	setOut(this.index+3, this.outLevel1);
	setOut(this.index+4, this.outLevel1);
	setOut(this.index+5, this.outLevel1);
	setOut(this.index+6, this.outLevel1);
	setOut(this.index+7, this.outLevel2);
	setOut(this.index+8, this.outLevel2);
	setOut(this.index+9, this.outLevel2);
	outputAllOuts();
}

ThickChord.prototype.off = function() {
	setOut(this.index+1, 0);
	setOut(this.index+2, 0);
	setOut(this.index+3, 0);
	setOut(this.index+4, 0);
	setOut(this.index+5, 0);
	setOut(this.index+6, 0);
	setOut(this.index+7, 0);
	setOut(this.index+8, 0);
	setOut(this.index+9, 0);
	outputAllOuts();
}

//----------------------------------------------------------------------------------------// 
//Quintedown class//
//Transposition quinte vers le bas//
//cet instrument utilise 2 lignes à retard//
//----------------------------------------------------------------------------------------// 
var Quintedown = function(index) {
	//une seule donnee dans cette classe : l'index de l'instrument, ie le numero de la 1ere ligne a retard//
	this.index = index;
	this.outLevel = 0.5;
	this.lowReinjection = 0.58;//0.68
	this.highReinjection = 0.7;//0.8
	//equivalent du constructeur//
	//Parameter definition for the 2 delay lines//
	setColumn(index, 110, -700, this.highReinjection, 1, 1, this.outLevel);
	setColumn(index+1, 125, -700, this.highReinjection, 1, 1, this.outLevel);
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 3 lignes//
	mFdMatColumnReset(index, 2);
	mFdMat(index, index, 1);
	mFdMat(index, index+1, 1);
	mFdMat(index+1, index+1, 1);
	mFdMat(index+1, index, 1);
	//display update
	updateMTapDisplays();
};

//Quintedown class methods//
Quintedown.prototype.longDuration = function() {
	setDuration(this.index, 886);
	setDuration(this.index+1, 1012);
	outputAllDurations();
}

Quintedown.prototype.shortDuration = function() {
	setDuration(this.index, 110);
	setDuration(this.index+1, 125);
	outputAllDurations();
}

Quintedown.prototype.highReinjection = function() {
	setFd(this.index, this.highReinjection);
	setFd(this.index+1, this.highReinjection);
	outputAllFds();
}

Quintedown.prototype.lowReinjection = function() {
	setFd(this.index, this.lowReinjection);
	setFd(this.index+1, this.lowReinjection);
	outputAllFds();
}

Quintedown.prototype.noReinjection = function() {
	setFd(this.index, 0);
	setFd(this.index+1, 0);
	outputAllFds();
}

Quintedown.prototype.on = function() {
	setOut(this.index, this.outLevel);
	setOut(this.index, this.outLevel);
	outputAllOuts();
}

Quintedown.prototype.off = function() {
	setOut(this.index, 0);
	setOut(this.index, 0);
	outputAllOuts();
}

//----------------------------------------------------------------------------------------// 
//Circularmotive class//
////
//cet instrument utilise 4 lignes à retard//
//----------------------------------------------------------------------------------------// 
var Circularmotive = function(index, delta) {
	this.index = index;
	this.delta = delta;
	this.columnNumber = 8;
	this.highLevel = 0.9;
	this.mediumLevel = 0.6;
	this.lowLevel = 0.5;
	this.highReinj = 0.95;
	//equivalent du constructeur//
	//Parameter definition for the 8 delay lines//
	setColumn(index, 1200, 0, 0.5, 0, 1, this.lowLevel);
	setColumn(index+1, 1300, 0, 0.5, 0, 1, this.lowLevel);
	setColumn(index+2, 2080, 0, this.highReinj, 0, 1, this.mediumLevel);
	setColumn(index+3, 2080, 0, this.highReinj, 0, 1, this.mediumLevel);
	setColumn(index+4, 2080, delta, this.highReinj, 1, 0, this.highLevel);
	setColumn(index+5, 2080, -delta, this.highReinj, 1, 0, this.highLevel);
	setColumn(index+6, 2080, delta, this.highReinj, 1, 0, this.highLevel);
	setColumn(index+7, 2080, -delta, this.highReinj, 1, 0, this.highLevel);
	//reinitialisation de mFdMat et remplissage des valeurs non nulles sur les 3 lignes//
	mFdMatColumnReset(index, 8);
	mFdMat(index, index, 1);
	mFdMat(index+1, index+1, 1);
	//mFdMat(index+2, index+2, 1);
	//mFdMat(index+3, index+3, 1);
	//mFdMat(index, index+2, 1);
	//mFdMat(index+1, index+3, 1);
	mFdMat(index+2, index+4, 1);
	mFdMat(index+3, index+5, 1);
	mFdMat(index+4, index+6, 1);
	mFdMat(index+5, index+7, 1);
	mFdMat(index+6, index+4, 1);
	mFdMat(index+7, index+5, 1);
	//display update
	updateMTapDisplays();
};

Circularmotive.prototype.setDelay = function(dur) {
	var coeff = 0.85;
	setDuration(this.index+2, dur);
	setDuration(this.index+3, dur);
	setDuration(this.index+4, dur*coeff);
	setDuration(this.index+5, dur*coeff);
	setDuration(this.index+6, dur*coeff);
	setDuration(this.index+7, dur*coeff);
	outputAllDurations();
	//setFd(this.index, 0.5);
	//setFd(this.index+1, 0.5);
	//outputAllFds();
}

Circularmotive.prototype.setEcho1Delay = function(dur) {
	setDuration(this.index, dur);
	setDuration(this.index+1, dur*1.1);
	outputAllDurations();
}

Circularmotive.prototype.inputOn = function() {
	setAllInputOn(this.index, this.columnNumber);
}

Circularmotive.prototype.inputOff = function() {
	setAllInputOff(this.index, this.columnNumber);
}

Circularmotive.prototype.setTransposition = function(delta) {
	setTransposition(this.index+4, delta);
	setTransposition(this.index+5, -delta);
	setTransposition(this.index+6, delta);
	setTransposition(this.index+7, -delta);
	outputAllTranspositions();
}

Circularmotive.prototype.setMainReinjectionOn = function() {
	mFdMat(this.index+2, this.index+2, 1);
	mFdMat(this.index+3, this.index+3, 1);
}

Circularmotive.prototype.setMainReinjectionOff = function() {
	mFdMat(this.index+2, this.index+2, 0);
	mFdMat(this.index+3, this.index+3, 0);
}

Circularmotive.prototype.setMainReinjection = function(mainReinj) {
	setFd(this.index+2, mainReinj);
	setFd(this.index+3, mainReinj);
	outputAllFds();
}

//----------------------------------------------------------------------------------------// 
//tremolo class//
////
//cet instrument utilise 2 lignes à retard//
//----------------------------------------------------------------------------------------// 
var Tremolo = function(index) {
	this.index = index;
	this.columnNumber = 2;
	this.reinjection = 0.8;
	this.inputLevel = 0.35;
	this.outputLevel = 0.2;
	setColumn(index, 0, 0, this.reinjection, 0, 0, this.outputLevel);
	setColumn(index+1, 0, 0, this.reinjection, 0, 0, this.outputLevel);
	mFdMatColumnReset(index, 2);
	mFdMat(index, index, 1);
	mFdMat(index+1, index+1, 1);
	//display update
	updateMTapDisplays();
}

Tremolo.prototype.inputOn = function() {
	setAllInputOn(this.index, this.columnNumber);
}

Tremolo.prototype.inputOff = function() {
	setAllInputOff(this.index, this.columnNumber);
}

//----------------------------------------------------------------------------------------// 
//Reflectivebass//
////
//this instrument uses 4 delay lines//
//----------------------------------------------------------------------------------------// 
var Reflectivebass = function(index, envDur) {
	this.index = index;
	this.columnNumber = 4;
	this.envDur = envDur;//enveloppe duration for delay stretch = 1//
	setEnvDur(envDur);
	this.stretch = 1;
	this.delayLevel = 0.65;
	this.highLevel = 1.5;
	setColumn(index, 1392, -1200, 1, 1, 1, this.highLevel);
	setColumn(index+1, 1012, -700, 1, 1, 1, this.highLevel);
	setColumn(index+2, 1172, 0, 0.55, 0, 1, this.delayLevel);
	setColumn(index+3, 2152, 0, 0.53, 0, 1, this.delayLevel);
	mFdMatColumnReset(index, 4);
	mFdMat(index, index, 1);
	mFdMat(index+1, index+1, 1);
	mFdMat(index+2, index+2, 1);
	mFdMat(index+3, index+3, 1);
	mFdMat(index+2, index, 1);
	mFdMat(index+2, index+1, 1);
	mFdMat(index+3, index, 1);
	mFdMat(index+3, index+1, 1);
	//display update
	updateMTapDisplays();
}

Reflectivebass.prototype.inputOn = function() {
	setAllInputOn(this.index, this.columnNumber);
}

Reflectivebass.prototype.inputOff = function() {
	setAllInputOff(this.index, this.columnNumber);
}

Reflectivebass.prototype.delayOff = function() {
	setOut(this.index+2, 0);
	setOut(this.index+3, 0);	
	outputAllOuts();
}

Reflectivebass.prototype.delayOn = function() {
	setOut(this.index+2, this.delayLevel);
	setOut(this.index+3, this.delayLevel);	
	outputAllOuts();
}	

//----------------------------------------------------------------------------------------// 
//HarmonicSet//
////
//this instrument uses 6 delay lines//
//----------------------------------------------------------------------------------------// 
var Harmonicset = function(index, elemDel) {
	this.index = index;
	this.columnNumber = 6;
	this.harmoLevel = 1.5;
	this.delBasis = elemDel;
	setColumn(index, 1*this.delBasis, 1200, 1, 1, 1, this.harmoLevel);
	setColumn(index+1, 1*this.delBasis, 700, 1, 1, 0, this.harmoLevel);
	setColumn(index+2, 1*this.delBasis, 500, 1, 1, 0, this.harmoLevel);
	setColumn(index+3, 1*this.delBasis, 380, 1, 1, 0, this.harmoLevel);
	setColumn(index+4, 1*this.delBasis, 320, 1, 1, 0, this.harmoLevel);
	setColumn(index+5, 1*this.delBasis, 350, 1, 1, 0, this.harmoLevel);
	mFdMatColumnReset(index, this.columnNumber);
	mFdMat(index, index+1, 1);
	mFdMat(index+1, index+2, 1);
	mFdMat(index+2, index+3, 1);
	mFdMat(index+3, index+4, 1);
	mFdMat(index+4, index+5, 1);
	updateMTapDisplays();
}

Harmonicset.prototype.inputOn = function() {
	setInp(this.index, 1);
	outputAllInps();
}

Harmonicset.prototype.inputOff = function() {
	setInp(this.index, 0);
	outputAllInps();
}

Harmonicset.prototype.toLow = function() {
	setTransposition(this.index, -1200);
	setTransposition(this.index+1, -700);
	setTransposition(this.index+2, -500);
	setTransposition(this.index+3, -380);
	setTransposition(this.index+4, -320);
	setTransposition(this.index+5, -350);
	outputAllTranspositions();
}

Harmonicset.prototype.toHigh = function() {
	setTransposition(this.index, 1200);
	setTransposition(this.index+1, 700);
	setTransposition(this.index+2, 500);
	setTransposition(this.index+3, 380);
	setTransposition(this.index+4, 320);
	setTransposition(this.index+5, 350);
	outputAllTranspositions();
}

Harmonicset.prototype.on = function() {
	setOut(this.index, this.harmoLevel);
	setOut(this.index+1, this.harmoLevel);
	setOut(this.index+2, this.harmoLevel);
	setOut(this.index+3, this.harmoLevel);
	setOut(this.index+4, this.harmoLevel);
	setOut(this.index+5, this.harmoLevel);
	outputAllOuts();
}

Harmonicset.prototype.off = function() {
	setOut(this.index, 0);
	setOut(this.index+1, 0);
	setOut(this.index+2, 0);
	setOut(this.index+3, 0);
	setOut(this.index+4, 0);
	setOut(this.index+5, 0);
	outputAllOuts();
}

//----------------------------------------------------------------------------------------// 
//infiniteReverb//
////
//this instrument uses 8 delay lines//
//----------------------------------------------------------------------------------------// 
var infiniteReverb = function(index, dt, fd, tr1, tr2, tr3, tr4, c1, c2, c3, c4) {
	this.index = index;
	this.columnNumber = 8;
	this.reinjection = 0.8;
	//Parameter definition for the 8 delay lines//
	setColumn(index, c1*dt, tr1, this.reinjection, 1, 1, 0);
	setColumn(index+1, c2*dt, tr2, this.reinjection, 1, 1, 0);
	setColumn(index+2, c3*dt, tr3, this.reinjection, 1, 1, 0);
	setColumn(index+3, c4*dt, tr4, this.reinjection, 1, 1, 0);
	setColumn(index+4, 4*dt, 0, fd, 0, 0, 3);
	setColumn(index+5, 4*dt, 0, fd, 0, 0, 3);
	setColumn(index+6, 4*dt, 0, fd, 0, 0, 3);
	setColumn(index+7, 4*dt, 0, fd, 0, 0, 3);
	//
	mFdMatColumnReset(index, 4);
	mFdMat(index, index+4, 1);
	mFdMat(index+1, index+5, 1);
	mFdMat(index+2, index+6, 1);
	mFdMat(index+3, index+7, 1);	
	mFdMat(index+4, index+4, 1);
	
	//mFdMat(index+4, index, 1);//réinjection vers le bloc initial
	mFdMat(index+5, index+5, 1);
	//mFdMat(index+5, index+1, 1);
	mFdMat(index+6, index+6, 1);
	//mFdMat(index+6, index+2, 1);
	mFdMat(index+7, index+7, 1);
	//mFdMat(index+7, index+3, 1);
	//display update
	updateMTapDisplays();
}

infiniteReverb.prototype.inputOn = function() {
	setInp(this.index, 1);
	setInp(this.index+1, 1);
	setInp(this.index+2, 1);
	setInp(this.index+3, 1);
	outputAllInps();
}

infiniteReverb.prototype.inputOff = function() {
	setInp(this.index, 0);
	setInp(this.index+1, 0);
	setInp(this.index+2, 0);
	setInp(this.index+3, 0);
	outputAllInps();
}

infiniteReverb.prototype.setFd = function(fd) {
	setFd(this.index, fd);
	setFd(this.index+1, fd);
	setFd(this.index+2, fd);
	setFd(this.index+3, fd);
	outputAllFds();
}


//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// DESCRIPTION OF SEQUENCES
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
//SEQUENCE 0
//----------------------------------------------------------------------------------------//
function seq0() {
	allReset();
	bass2oct0 = new Bass2octava(0);
	hcymbal0 = new Highcymbal(4);
	dgliss0 = new Downglissando(6);
	timb0 = new Timbales(9);
	quintu0 = new Quinteup(13);
	setGlobalParameters(1, 100, 1, 30, 500);
	setFreqShift(1);
	setCloseEnvTrigger();
	setTransfoInput(0);
	setProcessedLevel(125);
	setDirectLevel(100);
	spat.setConfig(0);
	setFirstOnset(0);
	begOfSeq();
	state = 0;
	nextState();
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 1
//----------------------------------------------------------------------------------------//
function seq1() {
	allReset();
	thickchord1 = new ThickChord(0);
	quintd1 = new Quintedown(10);
	trem1 = new Tremolo(14);
	setGlobalParameters(1, 100, 1, 50, 500);
	setFreqShift(8);
	setCloseEnvTrigger();
	setProcessedLevel(127);
	setDirectLevel(110);
	spat.setConfig(1);
	setFirstOnset(0);
	begOfSeq();
	state = 100;
	nextState();
}
//----------------------------------------------------------------------------------------//
//SEQUENCE 2
//----------------------------------------------------------------------------------------//
function seq2() {
	allReset();
	cmotive2ostinato = new Circularmotive(0, 300);
	cmotive2arpege = new Circularmotive(8, 250);
	//at the beginning of sequence 2, input is off for cmotive2arpege//
	cmotive2arpege.inputOff();
	setGlobalParameters(1, 100, 1, 30, 150);
	setFreqShift(1);
	setCloseEnvTrigger();
	setTransfoInput(0);
	chrono.able();
	setProcessedLevel(123);
	setDirectLevel(100);
	spat.setConfig(2);
	setFirstOnset(0);
	begOfSeq();
	state = 200;
	nextState();
}

//----------------------------------------------------------------------------------------//
//SEQUENCE 3
//----------------------------------------------------------------------------------------//
function seq3() {
	allReset();
	bass2oct0 = new Bass2octava(0);
	hcymbal0 = new Highcymbal(4);
	dgliss0 = new Downglissando(6);
	timb0 = new Timbales(9);
	quintu0 = new Quinteup(13);
	setGlobalParameters(1, 100, 1, 90, 500);
	setFreqShift(1);
	setCloseEnvTrigger();
	setTransfoInput(0);
	setProcessedLevel(127);
	setDirectLevel(100);
	spat.setConfig(0);
	setFirstOnset(0);
	begOfSeq();
	state = 300;
	nextState();
}

//----------------------------------------------------------------------------------------//
//SEQUENCE 4
//----------------------------------------------------------------------------------------//
function seq4() {
	allReset();
	thickchord1 = new ThickChord(0);
	quintd1 = new Quintedown(10);
	trem1 = new Tremolo(14);
	setGlobalParameters(1, 100, 1, 50, 500);
	setFreqShift(3);
	setCloseEnvTrigger();
	setProcessedLevel(115);
	setDirectLevel(110);
	spat.setConfig(1);
	setFirstOnset(0);
	begOfSeq();
	state = 400;
	nextState();
}

//----------------------------------------------------------------------------------------//
//SEQUENCE 5
//----------------------------------------------------------------------------------------//
function seq5() {
	allReset();
	cmotive2ostinato = new Circularmotive(0, 300);
	cmotive2arpege = new Circularmotive(8, 250);
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	setGlobalParameters(1, 100, 1, 30, 150);
	setFreqShift(1);
	setCloseEnvTrigger();
	setTransfoInput(0);
	chrono.able();
	setProcessedLevel(120);
	setDirectLevel(100);
	spat.setConfig(5);
	setFirstOnset(0);
	begOfSeq();
	state = 500;
	nextState();
}

//----------------------------------------------------------------------------------------//
//SEQUENCE 6
//----------------------------------------------------------------------------------------//
function seq6() {
	allReset();
	refbass9 = new Reflectivebass(0, 2000);
	dgliss9 = new Downglissando(4);
	hcymbal9 = new Highcymbal(7);
	harmonicset9 = new Harmonicset(9, 500);
	setGlobalParameters(3, 100, 1.9, 127, 500);
	setEnvDur(275);
	setTransfoInput(60);
	dgliss9.on();
	dgliss9.inputOff();
	hcymbal9.inputOff();
	hcymbal9.setLevel(0.4, 0.38);
	harmonicset9.inputOn();
	harmonicset9.on();
	refbass9.inputOff();	
	setFreqShift(1);
	setOpenEnvTrigger();
	setProcessedLevel(127);
	setDirectLevel(120);
	spat.setConfig(3);
	setFirstOnset(0);
	beatDuration = 600;
	begOfSeq();
	state = 600;
	nextState();
}
//----------------------------------------------------------------------------------------//
//SEQUENCE FINALE 9
//----------------------------------------------------------------------------------------//
function seq9() {
	allReset();
	refbass9 = new Reflectivebass(0, 2000);
	dgliss9 = new Downglissando(4);
	hcymbal9 = new Highcymbal(7);
	harmonicset9 = new Harmonicset(9, 500);
	setGlobalParameters(2, 100, 0.4, 100, 50);
	setFreqShift(1);
	setCloseEnvTrigger();
	setTransfoInput(0);
	setProcessedLevel(120);
	setDirectLevel(120);
	spat.setConfig(4);
	setFirstOnset(1);
	begOfSeq();
	state = 900;
	nextState();
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 0
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function state1()
{
		post("Starts initial sequence______________________________\n");
		//initializes bass2oct0 by switching off its 2nd line//
		bass2oct0.line2Off();		
		//ables chronometer//
		chrono.able();
}

//----------------------------------------------------------------------------------------//
function state2()
{
		post("=====state", state, "\n");
		//expands bass2oct0 by switching on its 2nd line
		bass2oct0.line2On();
}
//----------------------------------------------------------------------------------------//
function state3()
{
		post("=====state", state, "\n");
		//starts Highcymbal//
		hcymbal0.inputOn();
		//disables chronometer//
		chrono.disable();
		//schedules state 4//
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state4()
{
		post("=====state", state, "\n");
		dgliss0.inputOn();
		dgliss0.on();
}
//----------------------------------------------------------------------------------------//
function state5()
{
		post("=====state", state, "\n");
		dgliss0.inputOff();
		dgliss0.off();
		//schedules event 6
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state6()
{
		post("=====state", state, "\n");
		dgliss0.inputOn();
		dgliss0.on();
		hcymbal0.inputOff();
		nextStateBeatScheduled(10);
}
//----------------------------------------------------------------------------------------//
function state7()
{
		post("=====state", state, "\n");
		dgliss0.inputOff();
		dgliss0.off();
		setTStretch(newtStretch * 0.5);
		bass2oct0.echoOn();
		timb0.on();
		timb0.inputOn();
		//nextStateBeatScheduled(5.0);
}
//----------------------------------------------------------------------------------------//
function state8()
{	
		post("=====state", state, "\n");
		hcymbal0.inputOn();
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state9()
{
		post("=====state", state, "\n");
		dgliss0.inputOn();
		dgliss0.on();
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state10()
{
		post("=====state", state, "\n");
		quintu0.inputOn();
		hcymbal0.inputOff();
		setTStretch(newtStretch * 2.5);
		nextStateBeatScheduled(8.2);
}
//----------------------------------------------------------------------------------------//
function state11()
{
		post("=====state", state, "\n");
		timb0.inputOff();
		nextStateBeatScheduled(16.0);
}
//----------------------------------------------------------------------------------------//
function state12()
{	
		post("=====state", state, "\n");
		bass2oct0.echoOff();
		bass2oct0.line2Off();		
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state13()
{
		post("=====state", state, "\n");
		//bass2oct0.off();
		dgliss0.off();
		nextStateBeatScheduled(10.0);
}
//----------------------------------------------------------------------------------------//
function state14()
{
		//allReset();
		bass2oct0.off();
		hcymbal0.setLevel(0, 0);
		//dgliss0.off();
		timb0.off();
		//quintu0.off();
		nextStateBeatScheduled(5.0);
}
//----------------------------------------------------------------------------------------//
function state15()
{
		endOfSeq();
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 1
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------//
function state101() {
	//nothing particular, since all initializations are provided by seq1 function//
	post("Starts sequence 1\n");
}
//----------------------------------------------------------------------------------------//
function state102() {

		trem1.inputOn();
		quintd1.longDuration();
		quintd1.lowReinjection();
		thickchord1.setTranspositions(400, 500, 700, 900, 800, 500);
}
//----------------------------------------------------------------------------------------//
function state103() {

		trem1.inputOff();
		thickchord1.setTranspositions(300, 500, 600, 1000, 900, 600);
		thickchord1.setMainFd(0.4);
}
//----------------------------------------------------------------------------------------//
function state104() {

		trem1.inputOn();
}		
//----------------------------------------------------------------------------------------//
function state105() {

		quintd1.shortDuration();
		quintd1.highReinjection();
		thickchord1.setTranspositions(200, 400, 500, 1000, 800, 500);
		thickchord1.setMainFd(0.3);
}
//----------------------------------------------------------------------------------------//
function state106() {

		trem1.inputOn();
}
//----------------------------------------------------------------------------------------//
function state107() {

		trem1.inputOff();
		quintd1.longDuration();
		quintd1.lowReinjection();
		thickchord1.setTranspositions(300, 500, 600, 1000, 800, 500);
		thickchord1.setMainFd(0.2);
}
//----------------------------------------------------------------------------------------//
function state108() {

		thickchord1.setTranspositions(600, 700, 800, 900, 800, 400);
		thickchord1.setMainFd(0.3);
}
//----------------------------------------------------------------------------------------//
function state109() {

		trem1.inputOn();
}
//----------------------------------------------------------------------------------------//
function state110() {

		trem1.inputOff();
}
//----------------------------------------------------------------------------------------//
function state111() {

		thickchord1.setTranspositions(100, 600, 800, 900, 800, 600);
		thickchord1.setMainFd(0.4);
		quintd1.noReinjection();
		nextStateTimeScheduled(6000);
}
//----------------------------------------------------------------------------------------//
function state112() {
		endOfSeq();
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 2
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------//
function state201() {
	post("Starts sequence 2\n");
}
//----------------------------------------------------------------------------------------//
function state202() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state203() {
	//set cmotive2arpege input on and cmotive2ostinato input off//
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
}
//----------------------------------------------------------------------------------------//
function state204() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state205() {
	//set cmotive2arpege input off and cmotive2ostinato input on//
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2ostinato.setTransposition(200);
	chrono.able();
}
//----------------------------------------------------------------------------------------//
function state206() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state207() {
	//set cmotive2arpege input on and cmotive2ostinato input off//
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	cmotive2arpege.setTransposition(150);
}
//----------------------------------------------------------------------------------------//
function state208() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state209() {
	//set cmotive2arpege input off and cmotive2ostinato input on//
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2ostinato.setTransposition(100);
	chrono.able();
}
//----------------------------------------------------------------------------------------//
function state210() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state211() {
	//set cmotive2arpege input on and cmotive2ostinato input off//
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	cmotive2arpege.setTransposition(50);
}
//----------------------------------------------------------------------------------------//
function state212() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state213() {
	//set cmotive2arpege input off and cmotive2ostinato input on//
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	//cmotive2ostinato.setMainReinjectionOn();
	chrono.able();
}
//----------------------------------------------------------------------------------------//
function state214() {
	cmotive2ostinato.setTransposition(250);
	cmotive2ostinato.setEcho1Delay(d21*0.66);
	cmotive2ostinato.setDelay(d21*3.33);
}
//----------------------------------------------------------------------------------------//
function state215() {
	//set cmotive2arpege input on and cmotive2ostinato input off//
	cmotive2arpege.setTransposition(250);
	cmotive2arpege.setEcho1Delay(d21*0.33);
	cmotive2arpege.setDelay(d21);
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	nextStateTimeScheduled(d21*1.33);
}
//----------------------------------------------------------------------------------------//
function state216() {

	//cmotive2ostinato.setMainReinjectionOff();
}
//----------------------------------------------------------------------------------------//
function state217() {

	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2arpege.setTransposition(100);
}
//----------------------------------------------------------------------------------------//
function state218() {

	//outlet(0, tapMsg, 'tStretch', 1);
	//cmotive2ostinato.setMainReinjectionOff();
	//cmotive2arpege.setTransposition(250);
	cmotive2ostinato.setMainReinjectionOn();
}
//----------------------------------------------------------------------------------------//
function state219() {

	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	cmotive2arpege.setTransposition(100);
	cmotive2arpege.setEcho1Delay(d21*0.33);
	cmotive2arpege.setDelay(d21);
	cmotive2arpege.setMainReinjectionOn();
}
//----------------------------------------------------------------------------------------//
function state220() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state221() {

	//cmotive2ostinato.setMainReinjectionOff();
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2ostinato.setTransposition(100);
	cmotive2ostinato.setEcho1Delay(d21*0.33);
	cmotive2ostinato.setDelay(d21);
}
//----------------------------------------------------------------------------------------//
function state222() {
	//nothing particular
}
//----------------------------------------------------------------------------------------//
function state223() {

	//cmotive2arpege.setMainReinjectionOff();
	cmotive2ostinato.setMainReinjection(0.1);
	cmotive2arpege.setMainReinjection(0.1);
	post('State223\n');
	nextStateTimeScheduled(2000);
}
//----------------------------------------------------------------------------------------// 
function state224() {
	//cmotive2arpege.setMainReinjectionOff();
	cmotive2ostinato.setMainReinjection(0.1);
	cmotive2arpege.setMainReinjection(0.1);
	nextStateTimeScheduled(2000);
}
//----------------------------------------------------------------------------------------// 
function state225() {
	//cmotive2arpege.setMainReinjectionOff();
	cmotive2ostinato.setMainReinjection(0.05);
	cmotive2arpege.setMainReinjection(0.05);
	nextStateTimeScheduled(2000);
}
//----------------------------------------------------------------------------------------// 
function state226() {
	//cmotive2arpege.setMainReinjectionOff();
	cmotive2ostinato.setMainReinjection(0.);
	cmotive2arpege.setMainReinjection(0.);
	nextStateTimeScheduled(6000);
}
//----------------------------------------------------------------------------------------// 
function state227() {
	endOfSeq();
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 3
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function state301()
{
		//initializes bass2oct0 by switching off its 2nd line//
		bass2oct0.line2Off();
		//ables chronometer//	
		//timb0.on();
		//timb0.inputOn();
		chrono.able();
}
//----------------------------------------------------------------------------------------//
function state302()
{
		//expands bass2oct0 by switching on its 2nd line
		//bass2oct0.line2On();
}
//----------------------------------------------------------------------------------------//
function state303()
{

		//starts Highcymbal//
	
		//disables chronometer//
		chrono.disable();
		bass2oct0.line2On();
}
//----------------------------------------------------------------------------------------//
function state304()
{	
		dgliss0.inputOn();
		nextStateBeatScheduled(8.8);
}
//----------------------------------------------------------------------------------------//
function state305()
{
		dgliss0.inputOff();
		hcymbal0.inputOn();
		nextStateBeatScheduled(7.2);
}
//----------------------------------------------------------------------------------------//
function state306()
{
		dgliss0.inputOn();
		hcymbal0.inputOff();
		nextStateBeatScheduled(6.0);
}
//----------------------------------------------------------------------------------------//
function state307()
{
		dgliss0.inputOff();
		setTStretch(newtStretch * 0.6);
		timb0.on();
		timb0.inputOn();
		nextStateBeatScheduled(11.0);
}
//----------------------------------------------------------------------------------------//
function state308()
{
		quintu0.inputOn();
		setTStretch(newtStretch * 2.5);
		hcymbal0.inputOff();
		nextStateBeatScheduled(25.0);
}
//----------------------------------------------------------------------------------------// 
function state309()
{
		bass2oct0.echoOff();
		bass2oct0.line2Off();	
		nextStateBeatScheduled(5.0);
}
//----------------------------------------------------------------------------------------// 
function state310()
{
		endOfSeq();
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 4
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function state401()
{
		thickchord1.setMainFd(0.9);
		thickchord1.setTranspositions(200, 300, 400, 500, 600, 800);
		trem1.inputOn();
		quintd1.longDuration();
		quintd1.lowReinjection();
}
//----------------------------------------------------------------------------------------//
function state402()
{
		trem1.inputOff();
		thickchord1.setMainFd(0.4);	
}
//----------------------------------------------------------------------------------------//
function state403()
{
		//thickchord1.setTranspositions(600, 700, 800, 900, 800, 400);
		thickchord1.setMainFd(0.6);	
}
//----------------------------------------------------------------------------------------//
function state404()
{
		thickchord1.setMainFd(0.9);	
		trem1.inputOn();
		thickchord1.setTranspositions(100, 200, 400, 500, 600, 800);
		//thickchord1.setMainFd(0.9);	
}
//----------------------------------------------------------------------------------------//
function state405()
{
		trem1.inputOff();
		thickchord1.setMainFd(0.4);	
}
//----------------------------------------------------------------------------------------//
function state406()
{
		thickchord1.setMainFd(0.5);	
}
//----------------------------------------------------------------------------------------//
function state407()
{
		thickchord1.setMainFd(0.6);	
}
//----------------------------------------------------------------------------------------//
function state408()
{
		thickchord1.setMainFd(0.9);	
		trem1.inputOn();
		thickchord1.setTranspositions(100, 200, 400, 600, 700, 800);
		quintd1.highReinjection();
		//thickchord1.setMainFd(0.9);	
}
//----------------------------------------------------------------------------------------//
function state409()
{
		thickchord1.setMainFd(0.1);	
}
//----------------------------------------------------------------------------------------//
function state410()
{
		thickchord1.setMainFd(0.5);	
		nextStateTimeScheduled(5000);
}
//----------------------------------------------------------------------------------------//
function state411()
{
		endOfSeq();
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 5
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------//
function state501() {
	post("Starts sequence 5\n");
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
}
//----------------------------------------------------------------------------------------//
function state502() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state503() {
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2arpege.setTransposition(200);
}
//----------------------------------------------------------------------------------------//
function state504() {
	//schedules event 505//
	nextStateBeatScheduled(4.5);
}

//----------------------------------------------------------------------------------------//
function state505() {
	//set cmotive2arpege input off and cmotive2ostinato input on//
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	cmotive2ostinato.setTransposition(150);
}
//----------------------------------------------------------------------------------------//
function state506() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state507() {
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2arpege.setTransposition(100);
}
//----------------------------------------------------------------------------------------//
function state508() {
	//schedules event 505//
	nextStateBeatScheduled(6.0);
}

//----------------------------------------------------------------------------------------//
function state509() {
	//set cmotive2arpege input off and cmotive2ostinato input on//
	cmotive2arpege.inputOn();
	cmotive2ostinato.inputOff();
	cmotive2ostinato.setTransposition(50);
}
//----------------------------------------------------------------------------------------//
function state510() {
	//nothing particular//
}
//----------------------------------------------------------------------------------------//
function state511() {
	cmotive2arpege.inputOff();
	cmotive2ostinato.inputOn();
	cmotive2arpege.setTransposition(0);
	nextStateBeatScheduled(3);
}
//----------------------------------------------------------------------------------------//
function state512() {
	cmotive2ostinato.setMainReinjection(0.);
	cmotive2arpege.setMainReinjection(0.);
	nextStateBeatScheduled(2);
}
//----------------------------------------------------------------------------------------//
function state513() {
	cmotive2ostinato.setMainReinjection(0.);
	cmotive2arpege.setMainReinjection(0.);
	nextStateBeatScheduled(1);
}
//----------------------------------------------------------------------------------------//
function state514() {
	cmotive2ostinato.setMainReinjection(0.);
	cmotive2arpege.setMainReinjection(0.);
	nextStateBeatScheduled(1);
}
//----------------------------------------------------------------------------------------//
function state515() {
	cmotive2ostinato.setMainReinjection(0.);
	cmotive2arpege.setMainReinjection(0.);
	nextStateBeatScheduled(5);
}
//----------------------------------------------------------------------------------------//
function state516() {
	endOfSeq();
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 6
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function state601()
{
		post("Starts sequence 6______________________________\n");
		setFirstOnset(1);
		setOpenEnvTrigger();
		setTStretch(3);
		setHStretch(1.9);
}
//----------------------------------------------------------------------------------------//
function state602()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		hcymbal9.inputOn();
		setTStretch(2);
		setHStretch(1.9);
}
//----------------------------------------------------------------------------------------//
function state603()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(1);
		dgliss9.inputOn();
		setHStretch(1.9);
}
//----------------------------------------------------------------------------------------//
function state604()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		refbass9.inputOn();
		setTStretch(0.95);
		setHStretch(2);
}
//----------------------------------------------------------------------------------------//
function state605()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.9);
		setHStretch(2.1);
}
//----------------------------------------------------------------------------------------//
function state606()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.85);
		setHStretch(2.2);
}
//----------------------------------------------------------------------------------------//
function state607()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.8);
		setHStretch(2.3);
}
//----------------------------------------------------------------------------------------//
function state608()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.75);
		setHStretch(2.5);
}
//----------------------------------------------------------------------------------------//
function state609()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.7);
		setHStretch(2.8);
}
//----------------------------------------------------------------------------------------//
function state610()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.65);
		setHStretch(3.1);
}
//----------------------------------------------------------------------------------------//
function state611()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.6);
		setHStretch(3.2);
}
//----------------------------------------------------------------------------------------//
function state612()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.4);
		setHStretch(3.3);
}
//----------------------------------------------------------------------------------------//
function state613()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.3);
		setHStretch(3.6);
}
//----------------------------------------------------------------------------------------//
function state614()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.2);
		nextStateTimeScheduled(4000);
		//setHStretch(4);
}
//----------------------------------------------------------------------------------------//
function state615()
{
		endOfSeq();
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
// STATES OF SEQUENCE 9
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function state901()
{
		post("Starts final sequence______________________________\n");
		setTransfoInput(100);
		setEnvDur(225);
		setFirstOnset(1);
		setOpenEnvTrigger();
		dgliss9.on();
		dgliss9.inputOn();
		hcymbal9.inputOff();
		harmonicset9.inputOff();
		
}
//----------------------------------------------------------------------------------------//
function state902()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(15.0);
}
//----------------------------------------------------------------------------------------//
function state903()
{
		post("=====state", state, "\n");
		setTStretch(1.8);
		setHStretch(0.5);
		setTransfoInput(95);
		setOpenEnvTrigger();
}
//----------------------------------------------------------------------------------------//
function state904()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(11.0);	
}
//----------------------------------------------------------------------------------------//
function state905()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTransfoInput(90);
		setTStretch(1.6);
		setHStretch(0.6);
}
//----------------------------------------------------------------------------------------//
function state906()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(10.0);	
}
//----------------------------------------------------------------------------------------//
function state907()
{
		post("=====state", state, "\n");
		setTStretch(1.2);
		setTransfoInput(85);
		setHStretch(0.7);
		setOpenEnvTrigger();
}
//----------------------------------------------------------------------------------------//
function state908()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(7.0);	
}
//----------------------------------------------------------------------------------------//
function state909()
{
		post("=====state", state, "\n");
		setTStretch(1);
		setTransfoInput(80);
		setEnvDur(250);
		setHStretch(0.8);
		setOpenEnvTrigger();
}
//----------------------------------------------------------------------------------------//
function state910()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state911()
{
		post("=====state", state, "\n");
		setTStretch(0.6);
		setTransfoInput(50);
		setHStretch(0.9);
		setEnvDur(300);
		setOpenEnvTrigger();
}
//----------------------------------------------------------------------------------------//
function state912()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(11.0);
}
//----------------------------------------------------------------------------------------//
function state913()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.1);
		setEnvDur(700);
		setTransfoInput(0);
		setEnvDur(700);
		setHStretch(1);
}
//----------------------------------------------------------------------------------------//
function state914()
{
		post("=====state", state, "\n");
		hcymbal9.inputOn();
		nextStateBeatScheduled(6.0);
}
//----------------------------------------------------------------------------------------//
function state915()
{
		post("=====state", state, "\n");
		setTStretch(0.07);
}
//----------------------------------------------------------------------------------------//
function state916()
{
		post("=====state", state, "\n");
		hcymbal9.setLevel(0.30, 0.28);
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state917()
{
		post("=====state", state, "\n");
		setTStretch(0.1);
		nextStateBeatScheduled(8.0);
}
//----------------------------------------------------------------------------------------//
function state918()
{
		post("=====state", state, "\n");
		setTStretch(0.3);
		nextStateBeatScheduled(6.0);
}
//----------------------------------------------------------------------------------------//
function state919()
{
		post("=====state", state, "\n");
		//setTStretch(0.3);
		nextStateBeatScheduled(3.0);
}
//----------------------------------------------------------------------------------------//
function state920()
{
		post("=====state", state, "\n");
		setTStretch(0.5);
		nextStateBeatScheduled(3.0);
}
//----------------------------------------------------------------------------------------//
function state921()
{
		post("=====state", state, "\n");
		setTStretch(0.7);
}
//----------------------------------------------------------------------------------------//
function state922()
{
		post("=====state", state, "\n");
		refbass9.inputOff();	

		hcymbal9.setLevel(0.4, 0.38);
		nextStateBeatScheduled(6.0);
}
//----------------------------------------------------------------------------------------//
function state923()
{
		post("=====state", state, "\n");
		harmonicset9.inputOn();
		setHStretch(0.85);
		nextStateBeatScheduled(6.0);
}
//----------------------------------------------------------------------------------------//
function state924()
{
		post("=====state", state, "\n");
		setHStretch(0.7);
		nextStateBeatScheduled(4.0);	
}
//----------------------------------------------------------------------------------------//
function state925()
{
		post("=====state", state, "\n");
		setHStretch(0.55);
		nextStateBeatScheduled(4.0);
}
//----------------------------------------------------------------------------------------//
function state926()
{
		post("=====state", state, "\n");
		setHStretch(0.4);
		nextStateBeatScheduled(8.0);
}
//----------------------------------------------------------------------------------------//
function state927()
{
		post("=====state", state, "\n");
		setHStretch(0.25);
		nextStateBeatScheduled(11.0);
}
//----------------------------------------------------------------------------------------//
function state928()
{
		post("=====state", state, "\n");
		refbass9.inputOn();
		setTStretch(0.3);
		setHStretch(0.4);
		setTransfoInput(100);
		setEnvDur(150);
		setOpenEnvTrigger();
}
//----------------------------------------------------------------------------------------//
function state929()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state930()
{
		post("=====state", state, "\n");
		setTStretch(0.5);
		setHStretch(0.5);
		setEnvDur(175);
		setOpenEnvTrigger();
}
//----------------------------------------------------------------------------------------//
function state931()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(10.0);
}
//----------------------------------------------------------------------------------------//
function state932()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.6);
		setHStretch(0.6);
		setEnvDur(200);
		setTransfoInput(90);
}
//----------------------------------------------------------------------------------------//
function state933()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(9.0);
}
//----------------------------------------------------------------------------------------//
function state934()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.7);
		setHStretch(0.7);
		setEnvDur(225);
		setTransfoInput(80);
}
//----------------------------------------------------------------------------------------//
function state935()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(7.0);
}
//----------------------------------------------------------------------------------------//
function state936()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.8);
		setHStretch(0.8);
		setEnvDur(250);
		setTransfoInput(70);
}
//----------------------------------------------------------------------------------------//
function state937()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(4.0);
}
//----------------------------------------------------------------------------------------//
function state938()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.9);
		setHStretch(0.9);
		setEnvDur(275);
		setTransfoInput(60);
}
//----------------------------------------------------------------------------------------//
function state939()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(5.0);
}
//----------------------------------------------------------------------------------------//
function state940()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		//hcymbal9.inputOff();
		//harmonicset9.inputOff();
		harmonicset9.toLow();
		//setTStretch(0.07);
		setHStretch(1);
		setEnvDur(300);
		setTransfoInput(50);
}
//----------------------------------------------------------------------------------------//
function state941()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(6.0);
}
//----------------------------------------------------------------------------------------//
function state942()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.3);
		setTransfoInput(25);
}
//----------------------------------------------------------------------------------------//
function state943()
{
		post("=====state", state, "\n");
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state944()
{
		post("=====state", state, "\n");
		setOpenEnvTrigger();
		setTStretch(0.3);
		setHStretch(0.25);
		setTransfoInput(10);
		refbass9.inputOff();
}
//----------------------------------------------------------------------------------------//
function state945()
{
		post("=====state", state, "\n");
		//harmonicset9.inputOff();
		
		setTStretch(0.7);
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state946()
{
		post("=====state", state, "\n");
		setHStretch(0.4);
		setTStretch(0.5);
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state947()
{
		post("=====state", state, "\n");
		setHStretch(0.55);
		setTStretch(0.3);
		nextStateBeatScheduled(8.0);
}
//----------------------------------------------------------------------------------------//
function state948()
{
		post("=====state", state, "\n");
		setHStretch(0.7);
		setTStretch(0.2);
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state949()
{
		post("=====state", state, "\n");
		setHStretch(0.8);
		setTStretch(0.1);
		nextStateBeatScheduled(12.0);
}
//----------------------------------------------------------------------------------------//
function state950()
{
		post("=====state", state, "\n");
		harmonicset9.inputOff();
		nextStateBeatScheduled(2.5);
}
//----------------------------------------------------------------------------------------//
function state951()
{
		post("=====state", state, "\n");
		refbass9.inputOn();
		nextStateTimeScheduled(8000);
}
//----------------------------------------------------------------------------------------//
function state952()
{
		endOfSeq();
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------// 

//----------------------------------------------------------------------------------------// 
function start()
{	
	scheduledTaskNumber = 0;
	chrono = new Chronometer();
	spat = new Spatializer();
}
//----------------------------------------------------------------------------------------// 
function nextState()
{
	state = state + 1;
	handleState();
}
//----------------------------------------------------------------------------------------// 
function topAndNext() {
	chrono.top();
	nextState();
}
//----------------------------------------------------------------------------------------// 
function topStopNext() {
	chrono.top();
	//disables chrono//
	chrono.disable();
	//skips to next event//
	nextState();
}
//----------------------------------------------------------------------------------------// 
function prevState()
{
	if (state > 1) {
		state = state - 1;
	}
	handleState();
}
//----------------------------------------------------------------------------------------// 
function handleState()
{
	post("__________handling state", state, "\n");
	outlet(0, toState, state);
	resetAttackAndReleaseNumber();
}
//----------------------------------------------------------------------------------------// 
function resetAttackNumber() {
	attackNumber = 0;
	displayAttackNumber();
}
//----------------------------------------------------------------------------------------// 
function incAttackNumber() {
	attackNumber = attackNumber + 1;
	displayAttackNumber();
}

//----------------------------------------------------------------------------------------// 
function displayAttackNumber()
{
	outlet(0, toAttackNumber, attackNumber);
}
//----------------------------------------------------------------------------------------// 
function resetReleaseNumber() {
	releaseNumber = 0;
	displayReleaseNumber();
}
//----------------------------------------------------------------------------------------// 
function incReleaseNumber() {
	releaseNumber = releaseNumber + 1;
	displayReleaseNumber();
}

//----------------------------------------------------------------------------------------// 
function displayReleaseNumber()
{
	outlet(0, toReleaseNumber, releaseNumber);
}
//----------------------------------------------------------------------------------------// 
function resetAttackAndReleaseNumber() {
	resetAttackNumber();
	resetReleaseNumber();
}
//----------------------------------------------------------------------------------------// 
function attackPost() {
	post("=>attack at", state, "\n");
}
//----------------------------------------------------------------------------------------// 
function releasePost() {
	post("<=release at", state, "\n");
}
//----------------------------------------------------------------------------------------// 
function msecDuration(n)
{
	post("***** msecDuration at", state, "\n");
	switch(state) {
//SEQUENCE INITIALE//
		case 3:
			post("Seq0_processes beat duration\n");
			beatDuration = n * 0.5;
			newtStretch = (beatDuration + 0.0) / 610.0;//etirement/contraction de tous les delays selon ce coefficient//
			setTStretch(newtStretch);
			post("beatDuration at state 3/msecDuration =", beatDuration, "\n");
			//outlet(0, tapMsg, 'tStretch', newtStretch);
		break;
//SEQUENCE 2//
		case 202:
			post("Seq2_processes ostinato 1 duration\n");
			//duration of the first gruppetto of seq 2//
			d21 = n;
			beatDuration = n * 0.333;
			cmotive2ostinato.setDelay(n);
			cmotive2arpege.setDelay(n);
		break;
//SEQUENCE 3//
		case 303:
			post("Seq300_processes beat duration\n");
			beatDuration = n * 0.5;
			newtStretch = 0.6*(beatDuration + 0.0) / 610.0;//etirement/contraction de tous les delays selon ce coefficient//
			setTStretch(newtStretch);
		break;
//SEQUENCE 5//
		case 502:
			post("Seq5_processes arpeggio 1 duration\n");
			d51 = n;
			cmotive2ostinato.setDelay(n*0.333);
			cmotive2arpege.setDelay(n*0.5);
			beatDuration = n*0.1111;
		default:
			post("msecDuration should not be callet at event#", state, "\n");
		break;
	}
}
//----------------------------------------------------------------------------------------// 
function postNoAction() {
	post("XXXXX Nothing triggered for attack", attackNumber, "at state", state, "\n");
}
//----------------------------------------------------------------------------------------//
function nextStateBeatScheduled(beatNumber) {
	var delay;
	//
	delay = beatNumber*beatDuration;
	//nextStateTimeScheduled(delay);
	skipToNext(delay);
}
//----------------------------------------------------------------------------------------//
function nextStateTimeScheduled(del) {
	skipToNext(del);
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function attack()
{
	incAttackNumber();

	switch(state) {
		case 1:
			//on est dans l'état 1 (start effectué)//
			//on mémorise cette 1ère attaque//
			pianoStarted();
			if (attackNumber == 1)
			{
				attackPost();
				chrono.top();
				//on passe à l'état 2 dans 1000 ms//
				nextStateTimeScheduled(1000);
			}
			break;
		case 2 : 
			//on est dans l'état 2//
			//on mémorise cette 2ème attaque//
			if (attackNumber == 1)
			{
				attackPost();
				chrono.top();
				//on passe à l'état 3 dans 2100 ms//
				nextStateTimeScheduled(2100);
			}
			break;
		case 4 :
			switch(attackNumber) {
				case 2:
					nextStateBeatScheduled(1.0);
				break;
				default :
					postNoAction();
			}
			break;
		case 7 :
			attackPost();
			switch(attackNumber) {
				case 1:
					nextStateBeatScheduled(4.5);
					break;
				default :
					postNoAction();
			}
			break;
//SEQUENCE 1//
		case 101 :
			pianoStarted();
			break;
//SEQUENCE 2//
		case 201:
			pianoStarted();
			attackPost();
			//beginning of ostinato 1//
			topAndNext();
			break;
		case 203:
			pianoStarted();
			attackPost();
			//beginning of arpeggio 1//
			topAndNext();
			break;
		case 205:
			attackPost();
			//beginning of ostinato 2//
			topAndNext();
			break;
		case 207:
			attackPost();
			//beginning of arpeggio 2//
			topAndNext();
			break;
		case 209:
			attackPost();
			//beginning of ostinato 3//
			topAndNext();
			break;
		case 211:
			attackPost();
			//beginning of arpeggio 3//
			topAndNext();
			break;
		case 213:
			attackPost();
			//beginning of ostinato 4//
			topAndNext();
			break;
		case 217:
			attackPost();
			//beginning of arpeggio 4//
			topAndNext();
			break;
		case 219:
			attackPost();
			//beginning of arpeggio 5//
			topAndNext();
			break;	
		case 221:
			attackPost();
			//beginning of arpeggio 6//
			topAndNext();
			break;	
//SEQUENCE 3//			
		case 301:
			//on est dans l'état 301 (start effectué)//
			//on passe à l'état 302 dans 1000 ms//
			pianoStarted();
			attackPost();
			chrono.top();
			nextStateTimeScheduled(1000);
			//tsk1 = new Task(nextState, this);
			//tsk1.schedule(1000);
			break;
		case 302 : 
			//on est dans l'état 302//
			//on passe à l'état 303 dans 1100 ms//
			attackPost();
			chrono.top();
			nextStateTimeScheduled(1100);
			//tsk2 = new Task(nextState, this);
			//tsk2.schedule(1100);
			break;
		case 303 :
			//on est dans l'état 303//
			attackPost();
			if (attackNumber <= 1) {
				nextStateBeatScheduled(11.3);
				//tsk3 = new Task(nextState, this);
				//tsk3.schedule(11.3*beatDuration);//11 temps et quelques plus tard//
			}
			break;
//SEQUENCE 4//
		case 401:
			pianoStarted();
		break;
//SEQUENCE 5//
		case 501:
			pianoStarted();
			attackPost();
			//beginning of arpeggio 1//
			topAndNext();
		break;
		case 503:
			attackPost();
			//beginning of ostinato 1//
			topAndNext();
		break;
		case 505:
			attackPost();
			//beginning of ostinato 1//
			topAndNext();
		break;
		case 507:
			attackPost();
			//beginning of ostinato 1//
			topAndNext();
		break;
		case 509:
			attackPost();
			//beginning of ostinato 1//
			topAndNext();
		break;
//SEQUENCE 6//
		case 601:
			pianoStarted();
			attackPost();
			topAndNext();
		break;
		case 602:
			attackPost();
			topAndNext();
		break;
		case 603:
			attackPost();
			topAndNext();
		break;
		case 604:
			attackPost();
			topAndNext();
		break;
		case 605:
			attackPost();
			topAndNext();
		break;
		case 606:
			attackPost();
			topAndNext();
		break;
		case 607:
			attackPost();
			topAndNext();
		break;
		case 608:
			attackPost();
			topAndNext();
		break;
		case 609:
			attackPost();
			topAndNext();
		break;
		case 610:
			attackPost();
			topAndNext();
		break;
		case 611:
			attackPost();
			topAndNext();
		break;
		case 612:
			attackPost();
			switch(attackNumber) {
				case 1:
					nextStateBeatScheduled(5.5);
					break;
				default :
					postNoAction();
			}
		break;
		case 613:
			attackPost();
			switch(attackNumber) {
				case 1:
					nextStateBeatScheduled(5.3);
					break;
				default :
					postNoAction();
			}
		break;
//SEQUENCE 9//			
		case 901:
			pianoStarted();
			attackPost();
			nextState();
			break;
		case 903:
			attackPost();
			nextState();
			break;
		case 905:
			attackPost();
			nextState();
			break;
		case 907:
			attackPost();
			nextState();
			break;
		case 909:
			attackPost();
			nextState();
			break;
		case 911:
			attackPost();
			nextState();
			break;
		case 913:
			attackPost();
			nextState();
			break;
		case 915:
			attackPost();
			nextState();
			break;
		case 921:
			attackPost();
			nextState();
			break;
		case 928:
			attackPost();
			nextState();
			break;
		case 930:
			attackPost();
			nextState();
			break;
		case 932:
			attackPost();
			nextState();
			break;
		case 934:
			attackPost();
			nextState();
			break;
		case 936:
			attackPost();
			nextState();
			break;
		case 938:
			attackPost();
			nextState();
			break;
		case 940:
			attackPost();
			nextState();
			break;
		case 942:
			attackPost();
			nextState();
			break;
		case 944:
			attackPost();
			nextState();
			break;
		default:
			post("attack at", state, "_No automatic triggering\n");
			break;
	}
}

//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function soundStop() {
	//var myTsk;
	incReleaseNumber();
	switch(state) {
		case 202:
			releasePost();
			//end of ostinato 1//
			topStopNext();
			break;
		case 204:
			releasePost();
			//end of arpeggio 1//
			nextState();
			break;
		case 206:
			releasePost();
			//end of ostinato 2//
			topStopNext();
			break;
		case 208:
			releasePost();
			//end of arpeggio 2//
			nextState();
			break;
		case 210:
			releasePost();
			//end of ostinato 3//
			topStopNext();
			break;	
		case 212:
			releasePost();
			//end of arpeggio 3//
			nextState();
			break;
		case 214:
			releasePost();
			//end of ostinato 4//
			topStopNext();
			break;
		case 216:
			releasePost();
			//end of ostinato 5//
			topStopNext();
			break;
		case 218:
			releasePost();
			//end of arpeggio 4//
			nextState();
			break;
		case 220:
			releasePost();
			//end of arpeggio 5//
			nextState();
			break;	
		case 222:
			releasePost();
			//end of arpeggio 6//
			nextState();
			break;	
//SEQUENCE 5//
		case 502:
			releasePost();
			//end of ostinato 1//
			topStopNext();
			break;
		case 506:
			releasePost();
			//end of ostinato 1//
			topStopNext();
			break;
		case 510:
			releasePost();
			//end of ostinato 1//
			topStopNext();
			break;
		defaut:
			post("release at", state, "_No automatic triggering\n");
			break;
	}
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
function anything()
{
		//does nothing
}

