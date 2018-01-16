#!/bin/csh -vx
echo "" >> salida.dat
@ argc = 10
while ( $argc < 225 )
./shu $argc >> salida.dat

@ argc += 10
end

