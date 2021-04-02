/* -*- c++ -*- */

#define ZIGPOWER_API

%include "gnuradio.i"                   // the common stuff

//load generated python docstrings
%include "zigpower_swig_doc.i"

%{
#include "zigpower/power_tag_cc.h"
#include "zigpower/packet_sink_power.h"
%}


%include "zigpower/power_tag_cc.h"
GR_SWIG_BLOCK_MAGIC2(zigpower, power_tag_cc);
%include "zigpower/packet_sink_power.h"
GR_SWIG_BLOCK_MAGIC2(zigpower, packet_sink_power);
