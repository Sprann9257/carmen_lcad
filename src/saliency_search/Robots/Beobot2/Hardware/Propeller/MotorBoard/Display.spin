{
 ************************************************************************************************************
 *                                                                                                          *
 *  AUTO-RECOVER NOTICE: This file was automatically recovered from an earlier Propeller Tool session.      *
 *                                                                                                          *
 *  ORIGINAL FOLDER:     T:\School\Beobot2\Hardware\Propeller\MotorBoard\                                   *
 *  TIME AUTO-SAVED:     2 hours, 41 minutes ago (2009/9/6 上午 05:24:07)                                     *
 *                                                                                                          *
 *  OPTIONS:             1)  RESTORE THIS FILE by deleting these comments and selecting File -> Save.       *
 *                           The existing file in the original folder will be replaced by this one.         *
 *                                                                                                          *
 *                           -- OR --                                                                       *
 *                                                                                                          *
 *                       2)  IGNORE THIS FILE by closing it without saving.                                 *
 *                           This file will be discarded and the original will be left intact.              *
 *                                                                                                          *
 ************************************************************************************************************
.}
CON
  _clkmode = xtal1 + pll16x
  _xinfreq = 5_000_000

  LCD_PIN = 16 
  DRAW = 1
OBJ
        lcd:"GraphicLcd"

PUB Main|i,x,y
'  repeat
'    dira[13]:=1
'    outa[13]:=0


  lcd.start(LCD_PIN)
 
'  lcd.clearscreen
  waitcnt(clkfreq/4+cnt)
'repeat i from 0 to 100
a
  repeat i from 0 to 20
 ' lcd.motorscreen  
  lcd.motor(i*5,i*5,i*5,1,0)                
  waitcnt(clkfreq/2+cnt)
  waitcnt(clkfreq/2+cnt)                
  waitcnt(clkfreq/2+cnt)
  waitcnt(clkfreq/2+cnt)
  waitcnt(clkfreq/2+cnt)
  waitcnt(clkfreq/2+cnt)
  lcd.clearscreen    
'  waitcnt(clkfreq/2+cnt)
  lcd.motorscreen
  waitcnt(clkfreq/2+cnt)      
'  lcd.SplashScreen   
'  lcd.movexy(10,10)
'  repeat
'   lcd.str(string("Hello World"))'
'  lcd.clearscreen
'repeat 
'  repeat i from 0 to 100
'  i := 50
{
                lcd.movexy(0,68)                   
                lcd.str(string("Speed:"))
                lcd.dec(i)
                lcd.bar(55,60,50,10,i,1)
                                                 
                lcd.movexy(0,67-12)
                lcd.str(string("Turn :"))
                lcd.bar(55,67-20,50,10,i,1)                
                lcd.dec(i)

                
                lcd.movexy(0,67-25)
                lcd.str(string("CAP  :"))
                lcd.bar(55,34,50,10,i,1)                
                lcd.dec(i)

                lcd.movexy(0,67-37)
                lcd.str(string("Mode :"))
                lcd.movexy(37,67-37)      
                lcd.str(string("Automatic"))
'                lcd.bar(55,24,50,10,i,1)                
                'lcd.dec(i)

                lcd.movexy(20,90)
                lcd.str(string("Emergency Mode: ON"))
                lcd.DrawSolidbox(20,100,130,120,1)
'                lcd.DrawLine(20,100,130,120,1)
'                lcd.DrawLine(20,120,130,100,1)

               lcd.DrawCircle(135,50,24,1)
               lcd.DrawCircle(135,50,22,1)
               
               lcd.DrawCircle(125-4,56,4,1)                                              
               lcd.Drawbox(124-4,38,126-4,54,1)
               
               lcd.Drawbox(131-5,38,133-5,60,1)
               lcd.Drawbox(131-5,38,138-5,40,1)
               
               lcd.DrawCircle(139-4,43,4,1)
               lcd.Drawbox(140-1,39,142-1,47,1)
               
               lcd.Drawbox(142+1,39,144+1,60,1)               
               lcd.DrawCircle(148+1,43,4,1)               
}                              
'lcd.demo               
{repeat   
   repeat i from 0 to 100
      'lcd.drawcircle(80,50,i,1)
      lcd.dec(i)
      lcd.str(string(" ")) 
       waitcnt(clkfreq/40+cnt)
   lcd.clearscreen
'  lcd.SplashScreen   

}
{  
repeat  
  repeat i from 0 to 100
    lcd.bar(10,10,10,30,i,0)    
    lcd.bar(20,10,10,30,20+i,0)    
    lcd.bar(30,10,10,30,30+i,0)        
    waitcnt(clkfreq/20+cnt)
    'if(i == 50)
    '  lcd.clearscreen
  lcd.clearscreen
}  
{  
  repeat i from 0 to 100
    lcd.bar(10,10,10,30,100-i,0)    
    waitcnt(clkfreq/4+cnt)
   ' if(i == 50)
   '   lcd.clearscreen
  lcd.clearscreen  
}
{repeat
'  lcd.movexy(10,10)     
'  lcd.str(string("Hello"))'
    repeat i from 0 to 10
      lcd.drawbox(10,10,30,30+i,1)
 'l     waitcnt(clkfreq/32+cnt)
 }         {}
