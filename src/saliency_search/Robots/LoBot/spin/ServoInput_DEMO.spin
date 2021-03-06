{{
=========================================================
                    Servo Input Demo        
=========================================================

      ┌──────────────────────────────────────────┐
      │ Copyright (c) 2008 David C. Gregory      │               
      │     See end of file for terms of use.    │               
      └──────────────────────────────────────────┘

See ServoInput.spin for documentation.

}}
CON

  _clkmode = xtal1 + pll16x    'Run at the full 80MHz
  _xinfreq = 5_000_000         '
      
OBJ

  read          : "ServoInput"
 ' text          : "vga_text"  
  num           : "Numbers"
  SERVO : "Servo4"   
  
DAT
  
  pins        LONG 0, 1, 2, 3
  pulseWidths LONG 1, 1, 1, 1

PUB start | counter
    
  num.init 
'  text.start(16)
  read.start(@pins,4,@pulseWidths)
  servo.start(1500,23,1250,22,1500,21,1000,20)  
  repeat
       counter := cnt + 10_000_000  'Run our loop at ~8Hz (80e6/10e6)  
    servo.move_to(0,pulseWidths[0],50)    'move two at once
    servo.wait(0)
       
  '    text.str(num.ToStr(pulseWidths[0],num#DEC))
   '   text.str(num.ToStr(pulseWidths[1],num#DEC))
    '  text.str(num.ToStr(pulseWidths[2],num#DEC))
     ' text.str(num.ToStr(pulseWidths[3],num#DEC))              
    '  text.out(13)
      
      waitcnt (counter)

{{
    ┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
    │                                                   TERMS OF USE: MIT License                                                  │                                                            
    ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
    │Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation    │ 
    │files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy,    │
    │modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software│
    │is furnished to do so, subject to the following conditions:                                                                   │
    │                                                                                                                              │
    │The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.│
    │                                                                                                                              │
    │THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE          │
    │WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR         │
    │COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,   │
    │ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                         │
    └──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
}}             