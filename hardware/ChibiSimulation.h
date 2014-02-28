#ifndef __ChibiSimulation__
#define __ChibiSimulation__

#include "emulator.h"

class ChibiSimulation_t : public mod_t {
 public:
  dat_t<128> ChibiSimulation_Controller_Fifo_1__io_deq_dat_str;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__io_deq_val;
  dat_t<1> ChibiSimulation_Controller_WordMapper_1__io_rx_rdy;
  dat_t<128> ChibiSimulation_Controller_WordMapper_1__io_rx_dat_str;
  dat_t<64> ChibiSimulation_Controller_Fifo_1__io_deq_dat_id;
  dat_t<64> ChibiSimulation_Controller_WordMapper_1__io_rx_dat_id;
  dat_t<192> T0;
  dat_t<1> ChibiSimulation_Controller_WordMapper_1__io_rx_val;
  mem_t<192,1> ChibiSimulation_Controller_WordMapper_1__res;
  dat_t<1> ChibiSimulation_Controller__reset;
  dat_t<1> ChibiSimulation_Controller_WordMapper_1__reset;
  dat_t<1> R1;
  dat_t<1> R1_shadow;
  dat_t<1> ChibiSimulation_Controller_WordMapper_1__is_full;
  dat_t<1> ChibiSimulation_Controller_WordMapper_1__is_full_shadow;
  dat_t<128> ChibiSimulation_Controller_Fifo_0__io_deq_dat_str;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__io_deq_val;
  dat_t<1> ChibiSimulation_Controller_WordMapper_0__io_rx_rdy;
  dat_t<128> ChibiSimulation_Controller_WordMapper_0__io_rx_dat_str;
  dat_t<64> ChibiSimulation_Controller_Fifo_0__io_deq_dat_id;
  dat_t<64> ChibiSimulation_Controller_WordMapper_0__io_rx_dat_id;
  dat_t<192> T2;
  dat_t<1> ChibiSimulation_Controller_WordMapper_0__io_rx_val;
  mem_t<192,1> ChibiSimulation_Controller_WordMapper_0__res;
  dat_t<1> ChibiSimulation_Controller_WordMapper_0__reset;
  dat_t<1> R3;
  dat_t<1> R3_shadow;
  dat_t<1> ChibiSimulation_Controller_WordMapper_0__is_full;
  dat_t<1> ChibiSimulation_Controller_WordMapper_0__is_full_shadow;
  dat_t<32> ChibiSimulation_Controller_WordMapper_1__io_tx_dat_int;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__io_enq_rdy;
  dat_t<1> ChibiSimulation_Controller_WordMapper_1__io_tx_val;
  dat_t<32> ChibiSimulation_Controller_Fifo_3__io_enq_dat_int;
  dat_t<128> ChibiSimulation_Controller_WordMapper_1__io_tx_dat_str;
  dat_t<128> ChibiSimulation_Controller_Fifo_3__io_enq_dat_str;
  dat_t<32> ChibiSimulation_Controller_WordMapper_1__io_tx_dat_id;
  dat_t<32> ChibiSimulation_Controller_Fifo_3__io_enq_dat_id;
  dat_t<192> T4;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__io_enq_val;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__do_enq;
  dat_t<1> T5;
  mem_t<192,2> ChibiSimulation_Controller_Fifo_3__ram;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__reset;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__io_deq_val;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__io_deq_rdy;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__is_full;
  dat_t<1> ChibiSimulation_Controller_Fifo_3__is_full_shadow;
  dat_t<2> ChibiSimulation_Controller_Fifo_3__enq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_3__enq_ptr_shadow;
  dat_t<2> ChibiSimulation_Controller_Fifo_3__deq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_3__deq_ptr_shadow;
  dat_t<32> ChibiSimulation_Controller_WordMapper_0__io_tx_dat_int;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__io_enq_rdy;
  dat_t<1> ChibiSimulation_Controller_WordMapper_0__io_tx_val;
  dat_t<32> ChibiSimulation_Controller_Fifo_2__io_enq_dat_int;
  dat_t<128> ChibiSimulation_Controller_WordMapper_0__io_tx_dat_str;
  dat_t<128> ChibiSimulation_Controller_Fifo_2__io_enq_dat_str;
  dat_t<32> ChibiSimulation_Controller_WordMapper_0__io_tx_dat_id;
  dat_t<32> ChibiSimulation_Controller_Fifo_2__io_enq_dat_id;
  dat_t<192> T6;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__io_enq_val;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__do_enq;
  dat_t<1> T7;
  mem_t<192,2> ChibiSimulation_Controller_Fifo_2__ram;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__reset;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__io_deq_val;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__io_deq_rdy;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__is_full;
  dat_t<1> ChibiSimulation_Controller_Fifo_2__is_full_shadow;
  dat_t<2> ChibiSimulation_Controller_Fifo_2__enq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_2__enq_ptr_shadow;
  dat_t<2> ChibiSimulation_Controller_Fifo_2__deq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_2__deq_ptr_shadow;
  dat_t<128> ChibiSimulation_Fifo_0__io_deq_dat_str;
  dat_t<128> ChibiSimulation_Controller__io_rx_dat_str;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__io_enq_rdy;
  dat_t<1> ChibiSimulation_Fifo_0__io_deq_val;
  dat_t<1> ChibiSimulation_Controller__io_rx_val;
  dat_t<128> ChibiSimulation_Controller_Fifo_1__io_enq_dat_str;
  dat_t<64> ChibiSimulation_Fifo_0__io_deq_dat_id;
  dat_t<64> ChibiSimulation_Controller__io_rx_dat_id;
  dat_t<64> ChibiSimulation_Controller_Fifo_1__io_enq_dat_id;
  dat_t<192> T8;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__io_enq_val;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__do_enq;
  dat_t<1> T9;
  mem_t<192,2> ChibiSimulation_Controller_Fifo_1__ram;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__reset;
  dat_t<2> ChibiSimulation_Controller_Fifo_1__enq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_1__enq_ptr_shadow;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__io_deq_rdy;
  dat_t<2> ChibiSimulation_Controller_Fifo_1__deq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_1__deq_ptr_shadow;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__is_full;
  dat_t<1> ChibiSimulation_Controller_Fifo_1__is_full_shadow;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__io_enq_rdy;
  dat_t<128> ChibiSimulation_Controller_Fifo_0__io_enq_dat_str;
  dat_t<64> ChibiSimulation_Controller_Fifo_0__io_enq_dat_id;
  dat_t<192> T10;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__io_enq_val;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__do_enq;
  dat_t<1> T11;
  mem_t<192,2> ChibiSimulation_Controller_Fifo_0__ram;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__reset;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__io_deq_rdy;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__is_full;
  dat_t<1> ChibiSimulation_Controller_Fifo_0__is_full_shadow;
  dat_t<2> ChibiSimulation_Controller_Fifo_0__enq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_0__enq_ptr_shadow;
  dat_t<2> ChibiSimulation_Controller_Fifo_0__deq_ptr;
  dat_t<2> ChibiSimulation_Controller_Fifo_0__deq_ptr_shadow;
  dat_t<2> ChibiSimulation_Controller__inCounter;
  dat_t<2> ChibiSimulation_Controller__inCounter_shadow;
  dat_t<32> ChibiSimulation_Controller_Fifo_2__io_deq_dat_int;
  dat_t<32> ChibiSimulation_Controller_Fifo_3__io_deq_dat_int;
  dat_t<32> ChibiSimulation_Controller__io_tx_dat_int;
  dat_t<32> ChibiSimulation_Fifo_1__io_enq_dat_int;
  dat_t<128> ChibiSimulation_Controller_Fifo_2__io_deq_dat_str;
  dat_t<128> ChibiSimulation_Controller_Fifo_3__io_deq_dat_str;
  dat_t<128> ChibiSimulation_Controller__io_tx_dat_str;
  dat_t<128> ChibiSimulation_Fifo_1__io_enq_dat_str;
  dat_t<32> ChibiSimulation_Controller_Fifo_2__io_deq_dat_id;
  dat_t<32> ChibiSimulation_Controller_Fifo_3__io_deq_dat_id;
  dat_t<32> ChibiSimulation_Controller__io_tx_dat_id;
  dat_t<32> ChibiSimulation_Fifo_1__io_enq_dat_id;
  dat_t<192> T12;
  dat_t<1> ChibiSimulation_Fifo_1__io_enq_rdy;
  dat_t<1> ChibiSimulation_Controller__io_tx_val;
  dat_t<1> ChibiSimulation_Fifo_1__io_enq_val;
  dat_t<1> ChibiSimulation_Fifo_1__do_enq;
  dat_t<1> T13;
  mem_t<192,2> ChibiSimulation_Fifo_1__ram;
  dat_t<1> ChibiSimulation_Fifo_1__reset;
  dat_t<1> ChibiSimulation_Fifo_1__io_deq_val;
  dat_t<1> ChibiSimulation_Fifo_1__io_deq_rdy;
  dat_t<1> ChibiSimulation_Fifo_1__is_full;
  dat_t<1> ChibiSimulation_Fifo_1__is_full_shadow;
  dat_t<2> ChibiSimulation_Fifo_1__enq_ptr;
  dat_t<2> ChibiSimulation_Fifo_1__enq_ptr_shadow;
  dat_t<2> ChibiSimulation_Fifo_1__deq_ptr;
  dat_t<2> ChibiSimulation_Fifo_1__deq_ptr_shadow;
  dat_t<128> ChibiSimulation__io_in_dat_str;
  dat_t<128> ChibiSimulation_Fifo_0__io_enq_dat_str;
  dat_t<64> ChibiSimulation__io_in_dat_id;
  dat_t<64> ChibiSimulation_Fifo_0__io_enq_dat_id;
  dat_t<192> T14;
  dat_t<1> ChibiSimulation_Fifo_0__io_enq_rdy;
  dat_t<1> ChibiSimulation__io_in_val;
  dat_t<1> ChibiSimulation_Fifo_0__io_enq_val;
  dat_t<1> ChibiSimulation_Fifo_0__do_enq;
  dat_t<1> T15;
  mem_t<192,2> ChibiSimulation_Fifo_0__ram;
  dat_t<1> ChibiSimulation_Fifo_0__reset;
  dat_t<1> ChibiSimulation_Fifo_0__io_deq_rdy;
  dat_t<1> ChibiSimulation_Fifo_0__is_full;
  dat_t<1> ChibiSimulation_Fifo_0__is_full_shadow;
  dat_t<2> ChibiSimulation_Fifo_0__enq_ptr;
  dat_t<2> ChibiSimulation_Fifo_0__enq_ptr_shadow;
  dat_t<2> ChibiSimulation_Fifo_0__deq_ptr;
  dat_t<2> ChibiSimulation_Fifo_0__deq_ptr_shadow;
  dat_t<32> ChibiSimulation_Fifo_1__io_deq_dat_id;
  dat_t<32> ChibiSimulation__io_out_dat_id;
  dat_t<128> ChibiSimulation_Fifo_1__io_deq_dat_str;
  dat_t<128> ChibiSimulation__io_out_dat_str;
  dat_t<32> ChibiSimulation_Fifo_1__io_deq_dat_int;
  dat_t<32> ChibiSimulation__io_out_dat_int;
  dat_t<1> ChibiSimulation__io_out_val;
  int clk;
  int clk_cnt;

  void init ( bool rand_init = false );
  void clock_lo ( dat_t<1> reset );
  void clock_hi ( dat_t<1> reset );
  int clock ( dat_t<1> reset );
  void print ( FILE* f, FILE* e);
  bool scan ( FILE* f );
  void dump ( FILE* f, int t );
  char* mmap_read();
  void mmap_write(int id, char* value);
  int* find_dir();
  int idToName[2][10000];
  int prevId;
  int prevId2;
};



#endif
