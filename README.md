## Rowing set countdown

A simple countdown timer for a rowing machine, it starts with a 10 second
countdown and then 20 seconds of rowing, with a 10 second break repeated how
ever long you want.

The hardware used for this project is an [Atom
matrix](https://shop.m5stack.com/collections/atom-series/products/atom-matrix-esp32-development-kit?variant=39524837195948)
which has a 5x5 led display so it can't display numbers higher then 19.

Building:
```
pio run
```

Uploading (in my case the stack is on /dev/ttyUSB0)
```
pio run -t upload --upload-port /dev/ttyUSB0
```
