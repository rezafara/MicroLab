@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "C:\Projects\Micro Proccessor LAB\E1\ledShift-lab\labels.tmp" -fI -W+ie -C V2E -o "C:\Projects\Micro Proccessor LAB\E1\ledShift-lab\ledShift-lab.hex" -d "C:\Projects\Micro Proccessor LAB\E1\ledShift-lab\ledShift-lab.obj" -e "C:\Projects\Micro Proccessor LAB\E1\ledShift-lab\ledShift-lab.eep" -m "C:\Projects\Micro Proccessor LAB\E1\ledShift-lab\ledShift-lab.map" "C:\Projects\Micro Proccessor LAB\E1\ledShift-lab\ledShift-lab.asm"