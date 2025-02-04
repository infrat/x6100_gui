/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Xiegu X6100 LVGL GUI
 *
 *  Copyright (c) 2022-2023 Belousov Oleg aka R1CBU
 */

#pragma once

#include <stdbool.h>
#include <aether_radio/x6100_control/control.h>

#include "lvgl/lvgl.h"

#define RADIO_SAMPLES   (512)

typedef enum {
    RADIO_RX = 0,
    RADIO_TX,
    RADIO_ATU_START,
    RADIO_ATU_WAIT,
    RADIO_ATU_RUN,
    RADIO_SWRSCAN,

    RADIO_POWEROFF,
    RADIO_OFF
} radio_state_t;

typedef enum {
    RADIO_CHARGER_OFF = 0,
    RADIO_CHARGER_ON,
    RADIO_CHARGER_SHADOW
} radio_charger_t;

typedef void (*radio_state_change_t) ();

void radio_init(radio_state_change_t tx_cb, radio_state_change_t rx_cb);
void radio_bb_reset();
bool radio_tick();
radio_state_t radio_get_state();

/**
 * Set freq for radio without updating corresponding subject.
 * Useful for FT8 TX freq change and SWR scan
 */
void radio_set_freq(int32_t freq);
bool radio_check_freq(int32_t freq);
// int32_t radio_change_freq(int32_t df, int32_t *prev_freq);

// void radio_set_mode(x6100_vfo_t vfo,  x6100_mode_t mode);
// void radio_set_cur_mode(x6100_mode_t mode);
// x6100_mode_t radio_current_mode();

// x6100_vfo_t radio_set_vfo(x6100_vfo_t vfo);
x6100_vfo_t radio_toggle_vfo();

uint16_t radio_change_vol(int16_t df);
// uint16_t radio_change_rfg(int16_t df);
uint16_t radio_change_sql(int16_t df);
// uint32_t radio_change_filter_low(int32_t freq);
// uint32_t radio_change_filter_high(int32_t freq);
// uint32_t radio_change_filter_bw(int32_t bw);
uint16_t radio_change_moni(int16_t df);
bool radio_change_spmode(int16_t df);

void radio_change_mute();

// bool radio_change_pre();
// bool radio_change_att();
// void radio_change_agc();
// void radio_change_atu();
float radio_change_pwr(int16_t d);
void radio_set_pwr(float d);

// uint16_t radio_change_key_speed(int16_t d);
// x6100_key_mode_t radio_change_key_mode(int16_t d);
// x6100_iambic_mode_t radio_change_iambic_mode(int16_t d);
// uint16_t radio_change_key_tone(int16_t d);
// uint16_t radio_change_key_vol(int16_t d);
// bool radio_change_key_train(int16_t d);
// uint16_t radio_change_qsk_time(int16_t d);
// uint8_t radio_change_key_ratio(int16_t d);
radio_charger_t radio_change_charger(int16_t d);

x6100_mic_sel_t radio_change_mic(int16_t d);
uint8_t radio_change_hmic(int16_t d);
uint8_t radio_change_imic(int16_t d);

// bool radio_change_dnf(int16_t d);
// uint16_t radio_change_dnf_center(int16_t d);
// uint16_t radio_change_dnf_width(int16_t d);
// bool radio_change_nb(int16_t d);
// uint8_t radio_change_nb_level(int16_t d);
// uint8_t radio_change_nb_width(int16_t d);
// bool radio_change_nr(int16_t d);
// uint8_t radio_change_nr_level(int16_t d);

// bool radio_change_agc_hang(int16_t d);
// int8_t radio_change_agc_knee(int16_t d);
// uint8_t radio_change_agc_slope(int16_t d);

void radio_start_atu();
// void radio_load_atu();

bool radio_start_swrscan();
void radio_stop_swrscan();

void radio_vfo_set();
// void radio_filters_setup();

// void radio_filter_get(int32_t *from_freq, int32_t *to_freq);
void radio_poweroff();
void radio_set_ptt(bool tx);
void radio_set_modem(bool tx);


int16_t radio_change_xit(int16_t d);
int16_t radio_change_rit(int16_t d);

void radio_set_line_in(uint8_t d);
void radio_set_line_out(uint8_t d);

void radio_set_morse_key(bool on);
