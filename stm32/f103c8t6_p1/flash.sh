#!/bin/bash

project_name="f103c8t6_p1"

# Flash
openocd -s /usr/share/openocd/scripts -f openocd.cfg \
        -c "program target/thumbv7m-none-eabi/debug/$project_name verify reset exit"
