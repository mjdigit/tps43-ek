# tps43-ek
Experiment kit of Azoteq TPS43 for study in advance of designing Girasole40.

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
|Acrylic Board for touchpad (2mm thickness)|1|Amazon|Need to be cut to suit TPS43|
|M2 Spacer (5.0mm)|8|yushakobo|-|
|M2 screw (3.5mm)|16|yushakobo|-|
|FPC cable (6pin, 0.5mm pitch, 30mm length)|1|Amazon|T.B.D|
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
### Assemble the touchpad
Cut acrylic board to suit TPS43.

![Build Guide-Touchpad step 01](images/BuildGuide-touchpad-01.jpg)

Put double-sided tape on the acrylic board.

![Build Guide-Touchpad step 02](images/BuildGuide-touchpad-02.jpg)

Put the acrylic board onto TPS43.

![Build Guide-Touchpad step 03](images/BuildGuide-touchpad-03.jpg)
![Build Guide-Touchpad step 04](images/BuildGuide-touchpad-04.jpg)

Put double-sided tape on inside on dashed line of the Touchpad mount plate.

![Build Guide-Touchpad step 05](images/BuildGuide-touchpad-05.jpg)

Then, put it onto TPS43.

![Build Guide-Touchpad step 06](images/BuildGuide-touchpad-06.jpg)

### Assemble passive components on main plate
#### Back side
Solder diodes then switch sockets on back side of the main plate.

![Build Guide-Mainplate step 01](images/BuildGuide-mainplate-01.jpg)

#### Front side
Solder resisters and a capacitor on front side of the main plate.

![Build Guide-Mainplate step 02](images/BuildGuide-mainplate-02.jpg)

And, solder FPC socket on the main plate. (T.B.D.)

#### RP2040-Zero
Solder RP2040-Zero on the main plate using pin headers.

![Build Guide-Mainplate step 04](images/BuildGuide-mainplate-04.jpg)

Then cutoff the pins on Front side using nipper.

![Build Guide-Mainplate step 05](images/BuildGuide-mainplate-05.jpg)

### Assemble plates
Put top plate on the main plate. Then put keyboard switches.

![Build Guide-Assemble step 01](images/BuildGuide-assemble-01.jpg)

TODO: FPC Cable Connection

Put the touchpad plate on main plate using spacers and screws.

![Build Guide-Assemble step 04](images/BuildGuide-assemble-04.jpg)

Put the plates on bottom plate using spacers and screws. And put keycaps.

![Build Guide-Assemble step 05](images/BuildGuide-assemble-05.jpg)

Finally, put rubber feets on the bottom plate.

![Build Guide-Assemble step 06](images/BuildGuide-assemble-06.jpg)