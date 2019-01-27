//mTapMessageHandler
//Alain Bonardi, 2016
//
//--------------------------------------------------------------------------------------// 
inlets = 1;
outlets = 3;
//--------------------------------------------------------------------------------------//
//global variables
var dur, fdbk, tra, xvd, fdMat, inp, out;
var lineNumber = 16;
var durStretch = 1.;
var winDelay = 100;
var winHarmo = 30;
var traStretch = 1;
var smoothDur = 50;

//the js mTapMessageHandler.js object should have one parameter that is the size//
//of the arrays//
//by default, the size is 16//

if (jsarguments.length == 2) {
	lineNumber = jsarguments[1];
	post("mTapMessageHandler initialization with", lineNumber, "delay lines\n");
}
else {
	post("missing line number as argument of the js object\n");
}

var dur = new Array(lineNumber);
var fdbk = new Array(lineNumber);
var tra = new Array(lineNumber);
var xvd = new Array(lineNumber);
var fdMat = new Array(lineNumber*lineNumber);
var inp = new Array(lineNumber);
var out = new Array(lineNumber);

//--------------------------------------------------------------------------------------//
//FUNCTIONS ARE ORGANIZED AS FOLLOWS
//-durations of delays
//-feedbacks of delays
//-transpositions in midicents
//-xvd of each line (harmonizer versus delay proportion)
//inputs and outputs//
//-global parameters
//-mFdMat coefficients

//--------------------------------------------------------------------------------------//
//Fonctions formatage à 2 ou 3 chiffres des indices//
function format2(i)
{
	if (i < 10)
		{
			return '0'+i;
		}
	else
		{
			return i;
		}
}
//--------------------------------------------------------------------------------------//
function format3(i)
{
	if (i < 10)
		{
			return '00'+i;
		}
	else
		{
			if (i < 100)
				{
					return '0'+i;
				}
			else
				{
					return i;
				}
		}
}

//--------------------------------------------------------------------------------------//
//
//-----DURATIONS
//
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//setDuration1 function
//--------------------------------------------------------------------------------------//
function setDuration1(i, x)
{
	dur[i] = x;
	var label = 'd'+format2(i);
	outlet(0, label, x);
}

//--------------------------------------------------------------------------------------//
//setDuration2 function
//--------------------------------------------------------------------------------------//
function setDuration2(i, x)
{
	if (dur[i] != x)
	{
		setDuration1(i, x);
	}
}

//--------------------------------------------------------------------------------------//
//setDuration function
//--------------------------------------------------------------------------------------//
function setDuration(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all durations//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			setDuration2(i, j);
		}
	}
	else
	{
		//several arguments are passed//
		j = arguments[0];//starting index//
		for (i = 1; i < arguments.length; i++) {
			k = j+i-1;
			if (k < lineNumber) {
				setDuration2(k, arguments[i]);
			}
		}
	}
}

//--------------------------------------------------------------------------------------//
//durUI function
//--------------------------------------------------------------------------------------//
function durUI(a)
{
	//variable size
	var i, j, k;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		k = j+i-1;
		if (k < lineNumber) {
			setDuration2(k, arguments[i]);
		}
	}
}

//--------------------------------------------------------------------------------------//
//outputAllDurations function
//--------------------------------------------------------------------------------------//
function outputAllDurations()
{
	outlet(1, "mDelToDisplay", dur);
}

//*****END OF DURATION FUNCTIONS********************************************************//

//--------------------------------------------------------------------------------------//
//
//-----FEEDBACKS
//
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//setFd1 function
//--------------------------------------------------------------------------------------//
function setFd1(i, x)
{
	fdbk[i] = x;
	var label = 'fd'+format2(i);
	//post("i=", i, "\n");
	outlet(0, label, x);
}

//--------------------------------------------------------------------------------------//
//setFd2 function
//--------------------------------------------------------------------------------------//
function setFd2(i, x)
{
	if (fdbk[i] != x)
	{
		setFd1(i, x);
	}
}

//--------------------------------------------------------------------------------------//
//setFd function
//--------------------------------------------------------------------------------------//
function setFd(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all durations//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			setFd2(i, j);
		}
	}
	else
	{
		//several arguments are passed//
		j = arguments[0];//starting index//
		for (i = 1; i < arguments.length; i++) {
			k = j+i-1;
			if (k < lineNumber) {
				setFd2(k, arguments[i]);
			}
		}
	}
}

//--------------------------------------------------------------------------------------//
//fdUI function
//--------------------------------------------------------------------------------------//
function fdUI(a)
{
	//variable size
	var i, j, k;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		k = j+i-1;
		if (k < lineNumber) {
			setFd2(k, arguments[i]);
		}
	}
}

//--------------------------------------------------------------------------------------//
//outputAllFds function
//--------------------------------------------------------------------------------------//
function outputAllFds()
{
	outlet(1, "mFdToDisplay", fdbk);
}

//*****END OF FEEDBACK FUNCTIONS********************************************************//

//--------------------------------------------------------------------------------------//
//
//-----TRANSPOSITIONS
//
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//setTransposition1 function
//--------------------------------------------------------------------------------------//
function setTransposition1(i, x)
{
	tra[i] = x;
	var label = 'tr'+format2(i);
	outlet(0, label, x);
}

//--------------------------------------------------------------------------------------//
//setTransposition2 function
//--------------------------------------------------------------------------------------//
function setTransposition2(i, x)
{
	if (tra[i] != x)
	{
		setTransposition1(i, x);
	}
}

//--------------------------------------------------------------------------------------//
//setTransposition function
//--------------------------------------------------------------------------------------//
function setTransposition(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all durations//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			setTransposition2(i, j);
		}
	}
	else
	{
		//several arguments are passed//
		j = arguments[0];//starting index//
		for (i = 1; i < arguments.length; i++) {
			k = j+i-1;
			if (k < lineNumber) {
				setTransposition2(k, arguments[i]);
			}
		}
	}
}

//--------------------------------------------------------------------------------------//
//traUI function
//--------------------------------------------------------------------------------------//
function traUI(a)
{
	//variable size
	var i, j, k;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		k = j+i-1;
		if (k < lineNumber) {
			setTransposition2(k, arguments[i]);
		}
	}
}


//--------------------------------------------------------------------------------------//
//outputAllTranspositions function
//--------------------------------------------------------------------------------------//
function outputAllTranspositions()
{
	outlet(1, "mTraToDisplay", tra);
}

//*****END OF TRANSPOSITION FUNCTIONS***************************************************//



//--------------------------------------------------------------------------------------//
//
//-----xvd COEFFICIENTS = HARMONIZERS VERSUS DELAYS
//
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//setxvd1 function
//--------------------------------------------------------------------------------------//
function setXvd1(i, x)
{
	xvd[i] = x;
	var label = 'xvd'+format2(i);
	outlet(0, label, x);
}

//--------------------------------------------------------------------------------------//
//setxvd2 function
//--------------------------------------------------------------------------------------//
function setXvd2(i, x)
{
	if (xvd[i] != x)
	{
		setXvd1(i, x);
	}
}

//--------------------------------------------------------------------------------------//
//setxvd function
//--------------------------------------------------------------------------------------//
function setXvd(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all durations//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			setXvd2(i, j);
		}
	}
	else
	{
		//several arguments are passed//
		j = arguments[0];//starting index//
		for (i = 1; i < arguments.length; i++) {
			k = j+i-1;
			if (k < lineNumber) {
				setXvd2(k, arguments[i]);
			}
		}
	}
}

//--------------------------------------------------------------------------------------//
//xvdUI function
//--------------------------------------------------------------------------------------//
function xvdUI(a)
{
	//variable size
	var i, j, k;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		k = j+i-1;
		if (k < lineNumber) {
			setXvd2(k, arguments[i]);
		}
	}
}


//--------------------------------------------------------------------------------------//
//outputAllxvds function
//--------------------------------------------------------------------------------------//
function outputAllXvds()
{
	outlet(1, "mXvdToDisplay", xvd);
}

//*****END OF Xvd FUNCTIONS*************************************************************//


//--------------------------------------------------------------------------------------//
//
//-----AMPLITUDES OF INPUTS
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//setInp1 function
//--------------------------------------------------------------------------------------//
function setInp1(i, x)
{
	inp[i] = x;
	var label = 'inp'+format2(i);
	outlet(0, label, x);
}

//--------------------------------------------------------------------------------------//
//setInp2 function
//--------------------------------------------------------------------------------------//
function setInp2(i, x)
{
	if (inp[i] != x)
	{
		setInp1(i, x);
	}
}

//--------------------------------------------------------------------------------------//
//setInp function
//--------------------------------------------------------------------------------------//
function setInp(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all durations//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			setInp2(i, j);
		}
	}
	else
	{
		//several arguments are passed//
		j = arguments[0];//starting index//
		for (i = 1; i < arguments.length; i++) {
			k = j+i-1;
			if (k < lineNumber) {
				setInp2(k, arguments[i]);
			}
		}
	}
}

//--------------------------------------------------------------------------------------//
//mInpUI function
//--------------------------------------------------------------------------------------//
function inpUI(a)
{
	//variable size
	var i, j, k;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		k = j+i-1;
		if (k < lineNumber) {
			setInp2(k, arguments[i]);
		}
	}
}


//--------------------------------------------------------------------------------------//
//outputAllInps function
//--------------------------------------------------------------------------------------//
function outputAllInps()
{
	outlet(1, "mInpToDisplay", inp);
}

//*****END OF INP FUNCTIONS*************************************************************//


//--------------------------------------------------------------------------------------//
//
//-----AMPLITUDES OF OUTPUTS
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//setOut1 function
//--------------------------------------------------------------------------------------//
function setOut1(i, x)
{
	out[i] = x;
	var label = 'out'+format2(i);
	outlet(0, label, x);
}

//--------------------------------------------------------------------------------------//
//setOut2 function
//--------------------------------------------------------------------------------------//
function setOut2(i, x)
{
	if (out[i] != x)
	{
		setOut1(i, x);
	}
}

//--------------------------------------------------------------------------------------//
//setOut function
//--------------------------------------------------------------------------------------//
function setOut(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all durations//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			setOut2(i, j);
		}
	}
	else
	{
		//several arguments are passed//
		j = arguments[0];//starting index//
		for (i = 1; i < arguments.length; i++) {
			k = j+i-1;
			if (k < lineNumber) {
				setOut2(k, arguments[i]);
			}
		}
	}
}


//--------------------------------------------------------------------------------------//
//outUI function
//--------------------------------------------------------------------------------------//
function outUI(a)
{
	//variable size
	var i, j, k;
	j = arguments[0];//starting index//
	for (i = 1; i < arguments.length; i++)
	{
		k = j+i-1;
		if (k < lineNumber) {
			setOut2(k, arguments[i]);
		}
	}
}


//--------------------------------------------------------------------------------------//
//outputAllOuts function
//--------------------------------------------------------------------------------------//
function outputAllOuts()
{
	outlet(1, "mOutToDisplay", out);
}

//*****END OF OUTPUT FUNCTIONS**********************************************************//



//--------------------------------------------------------------------------------------//
//
//-----GLOBAL PARAMETERS
//
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
//tStretch function
//--------------------------------------------------------------------------------------//
function tStretch(s)
{
	durStretch = s;
	outlet(0, "dStretch", s);
	outlet(1, "dStretchToDisplay", s);
}

//--------------------------------------------------------------------------------------//
//tStretchUI function
//--------------------------------------------------------------------------------------//
function tStretchUI(s)
{
	if (durStretch != s)
	{
		durStretch = s;
		outlet(0, "dStretch", s);
	}
}

//--------------------------------------------------------------------------------------//
//hStretch function
//--------------------------------------------------------------------------------------//
function hStretch(s)
{
	traStretch = s;
	outlet(0, "hStretch", s);
	outlet(1, "hStretchToDisplay", s);
}

//--------------------------------------------------------------------------------------//
//hStretchUI function
//--------------------------------------------------------------------------------------//
function hStretchUI(s)
{
	if (traStretch != s)
	{
		traStretch = s;
		outlet(0, "hStretch", s);
	}
}

//--------------------------------------------------------------------------------------//
//wHarmo function
//--------------------------------------------------------------------------------------//
function wHarmo(x)
{
	winHarmo = x;
	outlet(0, "hWin", x);
	outlet(1, "hWinToDisplay", x);
}

//--------------------------------------------------------------------------------------//
//wHarmoUI function
//--------------------------------------------------------------------------------------//
function wHarmoUI(x)
{
	if (winHarmo != x)
	{
		winHarmo = x;
		outlet(0, "hWin", x);
	}
}

//--------------------------------------------------------------------------------------//
//smoothDuration function
//--------------------------------------------------------------------------------------//
function smoothDuration(x)
{
	smoothDur = x;
	outlet(0, "smoothDuration", x);
	outlet(1, "smoothDurToDisplay", x);
}

//--------------------------------------------------------------------------------------//
//smoothDuration function
//--------------------------------------------------------------------------------------//
function smoothDurationUI(x)
{
	if (smoothDur != x)
	{
		smoothDur = x;
		outlet(0, "smoothDuration", x);
	}
}


//*****END OF GLOBAL PARAMETERS FUNCTIONS***********************************************//

//--------------------------------------------------------------------------------------//
//
//-----FEEDBACK ROUTING MATRIX
//
//--------------------------------------------------------------------------------------//


//--------------------------------------------------------------------------------------//
//setFdMatCell function
//--------------------------------------------------------------------------------------//
function setFdMatCell(x, y, val)
{
	var ind; //index of the toggle in the matrix
	var faustMsg;
	//
	ind = x + lineNumber*y;
	if (fdMat[ind] != val)
	{
		fdMat[ind] = val;
		faustMsg = 'r'+format3(ind);
		outlet(0, faustMsg, val); 
	}
}

//--------------------------------------------------------------------------------------//
//setFdMat function
//--------------------------------------------------------------------------------------//
function setFdMat(x, y, val)
{
	setFdMatCell(x, y, val);
	outlet(2, x, y, val);
}

//--------------------------------------------------------------------------------------//
//setFdMatList function
//-either one value only is passed
//-or a list of triplets is given with two indices : i, j and a value
//--------------------------------------------------------------------------------------//
function setFdMatList(a)
{
	//variable size
	var i, j, k, l;
	l = arguments.length;
	//if only one argument this is the common value of all fdMat cells//
	if (l == 1) {
		j = arguments[0];
		for (i = 0; i < lineNumber; i++) {
			for (k = 0; k < lineNumber; k++) {
				setFdMat(i, k, j);
			}
		}
	}
	else
	{
		//several arguments are given as triplets//
		if ((arguments.length % 3) == 0)
		{
			j = arguments.length / 3;
			for (i = 0; i < j; i++) {
				k = 3 * i;
				setFdMat(arguments[k], arguments[k+1], arguments[k+2]);
			}
		}
	}
}


//--------------------------------------------------------------------------------------//
//fdMatUI function
//--------------------------------------------------------------------------------------//
function fdMatUI(x, y, val)
{
	setFdMatCell(x, y, val);
}

//--------------------------------------------------------------------------------------//
//fdMatReset function
//--------------------------------------------------------------------------------------//
function fdMatReset()
{
	var i, j;
	for (i = 0; i < lineNumber; i++) {
		for (j = 0; j < lineNumber; j++) {
			//post("***\n");
			setFdMat(i, j, 0);
		}
	}
}


//--------------------------------------------------------------------------------------//
//fdMatColumnReset function
//resets n columns starting at i0
//--------------------------------------------------------------------------------------//
function fdMatColumnReset(i0, n)
{
	var i, j, k;
	for (i = i0; i < i0+n; i++) {
		k = i % lineNumber;
		for (j = 0; j < lineNumber; j++) {
			setFdMat(k, j, 0);
		}
	}
}

//--------------------------------------------------------------------------------------//
//fdMatInit function
//--------------------------------------------------------------------------------------//
function fdMatInit()
{
	var i;
	for (i = 0; i < lineNumber; i++) {
			setFdMat(i, i, 1);
	}
}


//--------------------------------------------------------------------------------------//
//anything function
//--------------------------------------------------------------------------------------//
function anything()
{
		post("Anything\n");
}

//--------------------------------------------------------------------------------------//
//displayAll function
//--------------------------------------------------------------------------------------//
function displayAll()
{
	outputAllDurations();
	outputAllFds();
	outputAllTranspositions();
	outputAllXvds();
	outputAllInps();
	outputAllOuts();
}

//--------------------------------------------------------------------------------------//
//init function
//--------------------------------------------------------------------------------------//
function init()
{
		setDuration(0);
		setFd(0.99);
		setTransposition(0);
		setXvd(1);
		setInp(0.0);
		setOut(0.0);
		wHarmo(30);
		hStretch(1);
		tStretch(1);
		smoothDuration(50);
		fdMatReset();
		displayAll();
}

//----------------------------------------------------------------------------------------// 
//setColumn function
//----------------------------------------------------------------------------------------// 
function setColumn(colNum, dur, tra, fdbk, xvd, inp, out) {
	setDuration2(colNum, dur);
	setTransposition2(colNum, tra);
	setFd2(colNum, fdbk);
	setXvd2(colNum, xvd);
	setInp2(colNum, inp);
	setOut2(colNum, out);
}

//--------------------------------------------------------------------------------------//
//demo1 function : upscale
//--------------------------------------------------------------------------------------//
function demo1()
{
		var i;
		init();
		setDuration(0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000);
		setTransposition(0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300, 325, 350, 375, 400);
		setInp(0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
		setOut(0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
		wHarmo(30);
		tStretch(0.1);
		hStretch(1);
		for (i = 0; i < 16; i++)
		{
			setFdMat(15, i, 1);
		}
		displayAll();
}

//--------------------------------------------------------------------------------------//
//demo2 function : motif test
//--------------------------------------------------------------------------------------//
function demo2()
{
		var i;
		init();
		setDuration(0, 300, 425, 800, 925, 1300, 1800, 2000, 2300, 200, 500, 600, 1000, 3000, 2500, 700, 300);
		setTransposition(0, 386, 772, -386, 180, 386, -772, -45, 180, 0, 0, 0, 0, -500, 50, -1000, -1200);
		setFd(8, 0.5, 0.5, 0.2, 0.5);
		setFd(13, 0);
		setInp(8, 1, 1, 1, 1, 1, 1, 1, 1);
		setOut(0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0.4, 1, 1);
		setXvd(0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0);
		wHarmo(24);
		tStretch(0.8);
		hStretch(4);
		for (i = 0; i < 12; i++)
		{
			setFdMat(i, i, 1);
		}
		setFdMatList(8, 0, 1, 9, 1, 1, 10, 2, 1, 11, 3, 1, 8, 4, 1, 9, 5, 1, 10, 6, 1, 11, 7, 1);
		setFdMatList(13, 0, 1, 13, 1, 1, 13, 2, 1, 13, 4, 1, 13, 6, 1, 13, 12, 1, 13, 13, 1, 13, 14, 1, 13, 15, 1);
		displayAll();
}


