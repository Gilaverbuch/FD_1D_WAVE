# FD_1D_WAVE
1D finite difference wave

Explain about the makefile

Explain about the input parameters

velocity profile contains three arguments in the following order: distance[m]	density[kg/m^3]		velocity [m/s]	 

Compile and run 

Easy plot with gnuplot:
cd results/	

gnuplot		

do for [i=1:set_number] {plot  "wave_signal".i.".txt" with lines ; pause 0.1; set xrange[0:10000];set yrange[-1:1]};

