# tps43-ek
Experiment kit of Azoteq TPS43 for study in advance of designing [Girasole40](https://github.com/mjdigit/Girasole40).

![photo of tps43-ek](images/tps43-ek.jpg)

## Parts List (WIP)
(In study)

### Parts need to be prepared/purchased
|Part|Quantity|Where I bought it|Remarks|
|---|---|---|---|
|Wired controller board|1|AliExpress|RP2040-Zero (w/ pin headers)|
|Choc socket|4|yushakobo|e.g. Kailh PG1350 KeySwitches Contact (CPG135001S30)|
|Choc V2 switch|4|AliExpress|-|
|Keycap|4|AliExpress|-|
|Touchpad Module TPS43|1|MOUSER|-|
|Polycarbonate sheet for touchpad (0.5mm thickness) <br/>or<br/> PVC sheet for touchpad (0.5mm thikness)|1|Amazon|Need to be cut to suit TPS43|
|PET double-sided adhesive sheet|1|Amazon|Need to be cut to suit TPS43|
|M2 Spacer (3.5mm)|4|yushakobo|-|
|M2 Spacer (5.0mm)|4|yushakobo|-|
|M2 screw (3.5mm)|16|yushakobo|-|
|FPC cable (6pin, 0.5mm pitch, 50mm length)|1|Amazon|-|
|Diode|4|MOUSER|1N4148W|
|Resister 1608 1Kohm|2|akizukidenshi|-|
|Capaciter 1608 10uF|1|akizukidenshi|-|
|FPC socket (6pin, 0.5mm pitch)|1|Amazon|-|
|Rubber feet|5|Amazon|-|

### Parts need to be ordered/printed
|Part|Quantity|Remarks|
|---|---|---|
|Touchpad mount plate|1|<image src="images/TouchpadMountPlate.png" height="100px"/><br>gerber/gerber-touchpad.zip|
|Top plate|1|<image src="images/TopPlate.png" height="100px"/><br>gerber/gerber-top.zip|
|Main plate|1|<image src="images/MainPlate.png" height="100px"/><br>gerber/gerber.zip|
|Bottom plate|1|<image src="images/BottomPlate.png" height="100px"/><br>gerber/gerber-bottom.zip|

## Build Guide (WIP)
### !!! Important Notice !!!
Since I had placed SCL on pin0 and SDA on pin1, which assignment does not work on RP2040-Zero I2C0, some hand bridging is required.
There is no plan to be fix the gerber because this tps-43ek is just experimental project towards Girasole40.

### Assemble passive components on main plate
#### Front side
Solder FPC socket on the main plate.

![Build Guide-Mainplate Front 01](images/BuildGuide-mainplate-front01.jpg)

It's better to check resistance between the pads on main plate and TPS43 with connecting each other to check it successfully soldered.

![Build Guide-Mainplate Front 02](images/BuildGuide-mainplate-front02.jpg)

Solder resisters and a capacitor on front side of the main plate.

![Build Guide-Mainplate Front 03](images/BuildGuide-mainplate-front03.jpg)


#### Back side
Solder diodes then switch sockets on back side of the main plate.

![Build Guide-Mainplate Back 01](images/BuildGuide-mainplate-back01.jpg)


#### RP2040-Zero
Put pin headers then put RP2040-Zero on front side (DO NOT solder yet). 

![Build Guide-Mainplate RP2040 01](images/BuildGuide-mainplate-rp01.jpg)

Solder the pin headers on back side.

![Build Guide-Mainplate RP2040 02](images/BuildGuide-mainplate-rp02.jpg)

Put off RP2040-Zero then remove yellow plastic parts.

![Build Guide-Mainplate RP2040 03](images/BuildGuide-mainplate-rp03.jpg)

Put RP2040-Zero again and solder it. Then cutoff the pins on Front side and Back side using nipper.

![Build Guide-Mainplate RP2040 04](images/BuildGuide-mainplate-rp04.jpg)


#### Work Around: Replace SCL and SDA
As written on "Important Notice", it is required to place SDA on pin0 and SCL on pin1. Please connect each other in the below pads the cutoff the wire towards FPC connector.

![Build Guide-Mainplate work around 01](images/BuildGuide-mainplate-wa01.jpg)

![Build Guide-Mainplate work around 02](images/BuildGuide-mainplate-wa02.jpg)



#### Check whether touchpad works
Connect the main plate and TPS43 using FPC connector.

Connect your PC to RP2040-Zero with pushing BOOT switch. RP2040-Zero will be recognized as mass strage "RPI-RP2". Put the .uf2 file build by the following instruction into it.

Touch TPS43 and check whether touchpad works.

### Assemble the touchpad
Cut PET double-sided adhesive sheet to suit TPS43.

![Build Guide-Touchpad step 01](images/BuildGuide-touchpad-01.jpg)

Adhere Polycarbonate sheet on TPS43 then cut it to suit TPS43.

![Build Guide-Touchpad step 02](images/BuildGuide-touchpad-02.jpg)

![Build Guide-Touchpad step 03](images/BuildGuide-touchpad-03.jpg)

Put double-sided tape on inside on dashed line of the Touchpad mount plate.

![Build Guide-Touchpad step 04](images/BuildGuide-touchpad-04.jpg)

Then, put the plate onto TPS43.

![Build Guide-Touchpad step 05](images/BuildGuide-touchpad-05.jpg)

Note that you can also use PVC sheet instead of Polycarbonate sheet, though I feel touch experience is better on Polycarbonate sheet.

![Build Guide-Touchpad a case using PVC sheet](images/BuildGuide-touchpad-06.jpg)


### Assemble plates
Put top plate on the main plate. Then put keyboard switches.

![Build Guide-Assemble step 01](images/BuildGuide-assemble-01.jpg)

Connect the touchpad plate and the main plate with FPC cable.

![Build Guide-Assemble step 02](images/BuildGuide-assemble-02.jpg)

Then put the touchpad plate on the main plate using 3.5mm spacers and screws.

![Build Guide-Assemble step 03](images/BuildGuide-assemble-03.jpg)

Put the plates on bottom plate using spacers and screws. And put keycaps.

![Build Guide-Assemble step 04](images/BuildGuide-assemble-04.jpg)

Finally, put rubber feets on the bottom plate.

![Build Guide-Assemble step 05](images/BuildGuide-assemble-05.jpg)


## Default layout
![Default Keymap](images/DefaultKeymap.png)

You can rotate touchpad and keys using rotate layer.

![Rotate Layer Keymap](images/RotateLayerKeymap.png)