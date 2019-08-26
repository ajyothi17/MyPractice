obj-m:= soc_camera.o

KDIR:=/home/jyothi/rpi3/linux
ARCH:=arm
PWD:= $(shell pwd)
CROSS_COMPILE:=/home/jyothi/raspberry-pi3/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-

all:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers 
	rm app_soc_camera	
