inlets = 1;
outlets = 1;
//var tapMsg = 'toMTap';
var tapOutNumber = 0;
//----------------------------------------------------------------------------------------//
//INSTRUMENT CLASS INSTANCES//
//----------------------------------------------------------------------------------------//
var spectralThird0;
//----------------------------------------------------------------------------------------// 
//FUNCTIONS TO SEND MESSAGES TO MTAP CONTROLLLER
//----------------------------------------------------------------------------------------//
function setColumn(colNum, dur, tra, fdbk, xvd, inp, out) {
	outlet(tapOutNumber, 'setColumn', colNum, dur, tra, fdbk, xvd, inp, out);
}
function allReset() {
	outlet(tapOutNumber, 'init');
}
function displayAll() {
	outlet(tapOutNumber, 'displayAll');
}
//----------------------------------------------------------------------------------------// 
//SPECTRAL THIRD CLASS
//----------------------------------------------------------------------------------------//
var spectralThird = function(index) {
		this.index = index;
		//constructeur//
		//Definition des paramètres pour les 12 lignes mobilisees//
		setColumn(index, 300, 386, 0.99, 1, 1, 1);
		displayAll();
};
function state0() {
	allReset();
	spectralThird0 = new spectralThird(0);
}; 