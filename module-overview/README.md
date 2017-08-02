# Module Overview

These are the sensors / outputs at https://www.amazon.com/gp/product/B01CS6UMKQ . 

If the pictures seem distorted sometimes, there's a reason for that. My phone camera has less ability to focus than a goldfish, so I was using water to focus it. I put a droplet of water on the lens. This made the pictures *much* sharper, but meant that the pictures had to be taken straight down. The distortion is due to the shape of the drop.

You don't know the meaning of manual focus until you're adjusting the size of a drop of water on a lens.

## Contents

[Light Sensors](#light-sensors)

[Light Output](#light-output)

[Sound Sensors](#sound-sensors)

[Sound Output](#sound-output)

[Temperature Sensors](#temperature-sensors)

[Magnetic Sensors](#magnetic-sensors)

[Switches](#switches)

[Misc. Sensors](#misc-sensors)

[Misc. Output](#misc-output)

[Other](#other)



### Light Sensors

This uses IR to track objects.
![tracker](pictures/tracker.jpg)

This uses IR to avoid objects.
![avoid](pictures/avoid.jpg)

This is a heartbeat monitor.
![heartbeat-monitor](pictures/heartbeat-monitor.jpg)

This is an IR receiver. See also the IR emitter in the [Light Output](pictures/###Light Output) section.
![ir-receiver](pictures/ir-receiver.jpg)

This detects if the light beam going through it has been interrupted.
![light-blocker](pictures/light-blocker.jpg)

This detects the presence of light.
![photoresistor](pictures/photoresistor.jpg)

### Light Output
This is an LED with the three primary colors of light. In theory you could make all colors with this, but they don't mix very well.
![3-color-led](pictures/3-color-led.jpg)

This is a three color SMD (Surface Mount Device). It can output any color.
![3-color-smd](pictures/3-color-smd.jpg)

The following two pictures are of two color LEDs. There isn't much of a difference between them, and they can't really output the combination of the two colors.
![3mm-3-color-led](pictures/3mm-2-color-led.jpg)
![5mm-3-color-led](pictures/5mm-2-color-led.jpg)

This flashes / pulses in seven colors.
![7-color-flash](pictures/7-color-flash.jpg)

This shines a laser.
![laser](pictures/laser.jpg)

This emits IR.
![ir-emitter](pictures/ir-emitter.jpg)

These are "light cups". The idea behind these is basically to put the two tilt switches against each other, tip to tip, and rock both modules back and forth. This will trigger one switch but not the other, and the arduino can make it seem like light is pouring from one into the other by adjusting the brightness of each depending on their tilt.
![light-cup](pictures/light-cup.jpg)

### Sound Sensors
This detects small sounds.
![small-sound](pictures/small-sound.jpg)

This detects big sounds.
![big-sound](pictures/big-sound.jpg)

This uses ultrasonic sound to figure out how far away an object is, like a bat. It's accurate 1"-16'.
![ultrasonic](pictures/ultrasonic.jpg)

### Sound Output
The following are buzzers.
![buzzer](pictures/buzzer.jpg)
![passive-buzzer](pictures/passive-buzzer.jpg)

### Temperature Sensors
This detects both temperature and humidity.
![temp-and-humidity](pictures/temp-and-humidity.jpg)

These detect temperature, analog or digital.
![analog-temp](pictures/analog-temp.jpg)
![digital-temp](pictures/digital-temp.jpg)
![temp](pictures/temp.jpg)

### Magnetic Sensors
These are magnetic sensors.
![analog-hall](pictures/analog-hall.jpg)
![hall-magnetic](pictures/hall-magnetic.jpg)
![linear-hall](pictures/linear-hall.jpg)

### Switches
This has an internal ball and is used as a tilt switch.
![ball-switch](pictures/ball-switch.jpg)

This has a blob of mercury to close a connection.
![tilt-switch](pictures/tilt-switch.jpg)

These are reed switches. They activate on presense of a magnetic field.
![mini-reed-switch](pictures/mini-reed-switch.jpg)
![reed-switch](pictures/reed-switch.jpg)

This is a button switch. Must remain pressed to remain toggled.
![button-switch](pictures/button-switch.jpg)

### Misc. Sensors
This is both a gyroscope and accelerometer.
![gyroscope-accelerator](pictures/gyroscope-accelerator.jpg)

This detects fire.
![flame](pictures/flame.jpg)

This is a joystick.
![joystick](pictures/joystick.jpg)

This detects the presence of certain gasses.
![MQ-2-gas](pictures/MQ-2-gas.jpg)

This scrolls along the number line when twisted, and can be pressed as a button.
![rotary-encoder](pictures/rotary-encoder.jpg)

This detects being shocked.
![shock](pictures/shock.jpg)

This measures soil moisture. Not shown: the wires provided with it.
![soil-moisture](pictures/soil-moisture.jpg)

This detects water.
![water](pictures/water.jpg)

This detects being touched.
![touch](pictures/touch.jpg)

### Misc. Output
This is a relay module.
![relay](pictures/relay.jpg)

### Other
This is a real-time-clock module. It keeps the time, even when unplugged. 
![rtc](pictures/rtc.jpg)

This is an SD card reader.
![sd-card-reader](pictures/sd-card-reader.jpg)

This is a power supply, converting an input supply to 3.3V or 5V.
![power-supply](pictures/power-supply.jpg)

This is a step down module. It takes the input voltage and decreases it.
![step-down](pictures/step-down.jpg)

