volatile uint32_t toggle_count;

void TrinketTone(uint16_t frequency, uint32_t duration) {
    // scan through prescalars to find the best fit
    uint32_t ocr = F_CPU/frequency/2;
    uint8_t prescalarBits = 1;
    while (ocr>255) {
        prescalarBits++;
        ocr /= 2;
    }
    // CTC mode; toggle OC1A pin; set prescalar
    TCCR1 = 0x90 | prescalarBits;

    // Calculate note duration in terms of toggle count
    // Duration will be tracked by timer1 ISR
    toggle_count = frequency * duration / 500;
    OCR1C = ocr-1; // Set the OCR
    bitWrite(TIMSK, OCIE1A, 1); // enable interrupt
    while(TCCR1 != 0x90);
}

ISR(TIMER1_COMPA_vect) {
    if (toggle_count != 0) // done yet?
        toggle_count--; // no, keep counting
    else // yes,
        TCCR1 = 0x90; // stop the counter
}
