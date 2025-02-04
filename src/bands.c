/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  Xiegu X6100 LVGL GUI
 *
 *  Copyright (c) 2022-2023 Belousov Oleg aka R1CBU
 */

#include "bands.h"

#include "params/params.h"
#include "radio.h"
#include "info.h"
#include "spectrum.h"
#include "waterfall.h"
#include "main_screen.h"
#include "pannel.h"
#include "voice.h"
#include "dsp.h"
#include "pubsub_ids.h"

#include "lvgl/lvgl.h"

void bands_activate(uint64_t *freq) {
    // params_lock();
    // params_band_save(params.band_id);
    // params.band_id = params.current_band.id;
    // params_band_load(params.band_id);
    // params_unlock(&params.dirty.band);

    // if (freq) {
    //     params_band_cur_freq_set(*freq);
    // } else {
    //     uint64_t new_freq = params_band_cur_freq_get();
    //     if ((new_freq < params.current_band.start_freq) || (new_freq > params.current_band.stop_freq)) {
    //         new_freq = (params.current_band.start_freq + params.current_band.stop_freq) / 2;
    //         params_band_cur_freq_set(new_freq);
    //     }
    // }


    // radio_vfo_set();
    // radio_filters_setup();
    // spectrum_min_max_reset();
    // waterfall_min_max_reset();
}

void bands_change(bool up) {
    // if (params_bands_find_next(params_band_cur_freq_get(), up)) {
    //     bands_activate(NULL);
    //     radio_load_atu();
    //     info_params_set();
    //     pannel_visible();
    //     spectrum_clear();
    //     main_screen_band_set();

    //     voice_say_text_fmt("Band %s", params.current_band.name);
    // }
}
