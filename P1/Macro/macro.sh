#!/bin/csh -vx
echo "" >> salida.dat
@ i = 600
while ( $i < 18600 )
./quicksort $i >> salida.dat
@ i += 600
end

