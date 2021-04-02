/* -*- c++ -*- */
/* 
 * Copyright 2021 <+YOU OR YOUR COMPANY+>.
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

#ifndef INCLUDED_ZIGPOWER_POWER_TAG_CC_IMPL_H
#define INCLUDED_ZIGPOWER_POWER_TAG_CC_IMPL_H

#include <zigpower/power_tag_cc.h>

namespace gr {
  namespace zigpower {

    class power_tag_cc_impl : public power_tag_cc
    {
     private:
      // Nothing to declare in this block.

     public:
      power_tag_cc_impl();
      ~power_tag_cc_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace zigpower
} // namespace gr

#endif /* INCLUDED_ZIGPOWER_POWER_TAG_CC_IMPL_H */

