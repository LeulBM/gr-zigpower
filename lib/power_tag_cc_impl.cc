/* -*- c++ -*- */
/* 
 * Copyright 2021 Leul Berhane-Meskel.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "power_tag_cc_impl.h"
//#include <volk/volk.h>
//#include <fftw3.h>

namespace gr {
  namespace zigpower {

    power_tag_cc::sptr
    power_tag_cc::make()
    {
      return gnuradio::get_initial_sptr
        (new power_tag_cc_impl());
    }

    /*
     * The private constructor
     */
    power_tag_cc_impl::power_tag_cc_impl()
      : gr::sync_block("power_tag_cc",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
		const int alignment_multiple = volk_get_alignment() / sizeof(gr_complex);
		set_alignment(std::max(1, alignment_multiple));
    }

    /*
     * Our virtual destructor.
     */
    power_tag_cc_impl::~power_tag_cc_impl() { }


    int power_tag_cc_impl::work(int noutput_items,
        						gr_vector_const_void_star &input_items,
        						gr_vector_void_star &output_items) {

		const gr_complex* in = (const gr_complex*)input_items[0];
		gr_complex* out = (gr_complex*)output_items[0];

		// Store magnitudes in array
		float* mags = (float*) volk_malloc(sizeof(float)*noutput_items, volk_get_alignment());
		volk_32fc_magnitude_squared_32f(mags, in, noutput_items);

		//Loop over mag values, calculate RSS in "dB" for each and add tag at that offset
		for(int i = 0; i<noutput_items; i++) {
			float rss = 10 * log10(std::max(mags[i], (float)1e-18));	
			add_item_tag(0, 
						nitems_written(0) + i, 
						pmt::string_to_symbol("signal_strength"), 
						pmt::from_float(rss));
		}

		//Copy input samples as output
		memcpy(out, in, sizeof(gr_complex) * noutput_items);

		// Free memory for magnitude array
		volk_free(mags);

      	// Tell runtime system how many output items we produced.
      	return noutput_items;
    }

  } /* namespace zigpower */
} /* namespace gr */

