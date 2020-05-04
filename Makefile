all: mini-sumo-bot.hex

mini-sumo-bot.hex: mini-sumo-bot.elf
	avr-objcopy  -j .text -j .data -O ihex $^ $@
	avr-size mini-sumo-bot.elf

mini-sumo-bot.elf: mini-sumo-bot.c
	avr-g++ -mmcu=atmega324p -DF_CPU=16000000 -Os -Wall -o $@ $^

clean:
	rm -rf mini-sumo-bot.elf mini-sumo-bot.hex
