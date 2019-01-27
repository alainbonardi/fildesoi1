import("math.lib");
import("hoa.lib");

freq(ind) = hslider("freq%ind", 1, -10, 10, 0.01);
phase(ind) = hslider("phase%ind", 0, 0, 1, 0.01);

//phasor basique à fréquence positive//
basicPhasor(f) = (_, 1. : fmod) ~ +(float(f)/float(SR));

//adaptation aux éventuelles fréquences négatives comme pour Max//
maxPhasor(f) = basicPhasor(f) + (f < 0);

//ajout d'une phase//
maxPhasorWithPhase(f, p) = (1-vn) * x + vn * p
with {
		vn = (f == 0);
		x = (maxPhasor(f), p, 1) : (+, _) : fmod;
};
phasedAngle(f, p) = maxPhasorWithPhase(f, p) * 2 * PI;

myEncoder(sig, angle) = encoder(3, sig, angle);
phasedEncoder(f, p) = (_, phasedAngle(f, p)) : myEncoder;
phasedEncoderBlock = par(i, 4, phasedEncoder(freq(i), phase(i))) :> (_, _, _, _, _, _, _);

process = (_, _, _, _, _, _, _, phasedEncoderBlock) :> (_, _, _, _, _, _, _);