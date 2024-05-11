#![deny(unsafe_code)]
#![no_std]
#![no_main]

use core::fmt::Write;
use panic_halt as _;
use nb::block;
use cortex_m::asm::nop;
use cortex_m_rt::entry;
use stm32f1xx_hal::{
    pac,
    prelude::*,
    timer::Timer,
    serial::{Config, Serial},
};
use rtt_target::{rprintln, rtt_init_print};


#[entry]
fn main() -> ! {
    // Get access to the core peripherals from the cortex-m crate
    let cp = cortex_m::Peripherals::take().unwrap();
    // Get access to the device specific peripherals from the peripheral access crate
    let dp = pac::Peripherals::take().unwrap();

    // Take ownership over the raw flash and rcc devices and convert them into the corresponding
    // HAL structs
    let mut flash = dp.FLASH.constrain();
    let rcc = dp.RCC.constrain();

    // Freeze the configuration of all the clocks in the system and store the frozen frequencies in `clocks`
    let clocks = rcc.cfgr.freeze(&mut flash.acr);
    // Configure the syst timer to trigger an update every second
    let mut timer = Timer::syst(cp.SYST, &clocks).counter_hz();
    timer.start(10.Hz()).unwrap();

    // Acquire the GPIOC peripheral
    let mut gpioa = dp.GPIOA.split();
    let mut gpioc = dp.GPIOC.split();
    let mut afio = dp.AFIO.constrain();
    
    // Configure gpio C pin 13 & 14 & 15 as a push-pull output.
    // The `crh` register is passed to the function in order to configure the port. 
    // For pins 0-7, crl should be passed instead.
    let mut led1 = gpioc.pc13.into_push_pull_output(&mut gpioc.crh);
    let mut led2 = gpioc.pc14.into_push_pull_output(&mut gpioc.crh);
    let mut led3 = gpioc.pc15.into_push_pull_output(&mut gpioc.crh);
    
    // USART1 on Pins A9 and A10
    let pin_tx1 = gpioa.pa9.into_alternate_push_pull(&mut gpioa.crh);
    let pin_rx1 = gpioa.pa10;
    // Create an interface struct for USART1 with 9600 Baud
    let serial1 = Serial::new(
        dp.USART1,
        (pin_tx1, pin_rx1),
        &mut afio.mapr,
        Config::default()
            .baudrate(9600.bps())
            .parity_none(),
        &clocks,
    );
    let (mut tx1, mut _rx1) = serial1.split(); // Separate into tx and rx channels
    
    rtt_init_print!();
    rprintln!("RTT Service is String....");
    tx1.write_str("\nUART1 is String....\n").unwrap();
    loop {
        block!(timer.wait()).unwrap();
        rprintln!("Echo ....");
        tx1.write_str("Echo ....\n").unwrap();
        for _ in 0..100_000 {
            nop();
        }
        led1.toggle();
        led2.toggle();
        led3.toggle();
        tx1.write(b'S').unwrap();
        tx1.write(b'\n').unwrap();
    }
}
