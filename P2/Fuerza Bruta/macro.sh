#!/bin/csh -vx
echo "" >> salidafb.dat
@ argc = 800
while ( $argc <= 24000 )
./fb $argc >> salidafb.dat
@ argc += 800
end


