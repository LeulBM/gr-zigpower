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


#ifndef INCLUDED_ZIGPOWER_PACKET_SINK_POWER_H
#define INCLUDED_ZIGPOWER_PACKET_SINK_POWER_H

#include <zigpower/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace zigpower {

    /*!
     * \brief <+description of block+>
     * \ingroup zigpower
     *
     */
    class ZIGPOWER_API packet_sink_power : virtual public gr::block
    {
     public:

      typedef boost::shared_ptr<packet_sink_power> sptr;
      static sptr make(unsigned int threshold, unsigned int rssi_samp);

    };

  } // namespace zigpower
} // namespace gr

#endif /* INCLUDED_ZIGPOWER_PACKET_SINK_POWER_H */

