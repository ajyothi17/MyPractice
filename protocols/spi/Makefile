obj-m:=Spi_Driver.o

KDIR:=/home/jyothi/raspberry-pi3/linux
CROSS_COMPILE=/home/jyothi/raspberry-pi3/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-
PWD:=$(shell pwd)

all:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
