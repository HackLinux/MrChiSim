#include "ChibiSimulation.h"

void ChibiSimulation_t::init ( bool rand_init ) {
  if (rand_init) ChibiSimulation_Controller_WordMapper_1__res.randomize();
  if (rand_init) R1.randomize();
  if (rand_init) ChibiSimulation_Controller_WordMapper_1__is_full.randomize();
  if (rand_init) ChibiSimulation_Controller_WordMapper_0__res.randomize();
  if (rand_init) R3.randomize();
  if (rand_init) ChibiSimulation_Controller_WordMapper_0__is_full.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_3__ram.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_3__is_full.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_3__enq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_3__deq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_2__ram.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_2__is_full.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_2__enq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_2__deq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_1__ram.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_1__enq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_1__deq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_1__is_full.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_0__ram.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_0__is_full.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_0__enq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller_Fifo_0__deq_ptr.randomize();
  if (rand_init) ChibiSimulation_Controller__inCounter.randomize();
  if (rand_init) ChibiSimulation_Fifo_1__ram.randomize();
  if (rand_init) ChibiSimulation_Fifo_1__is_full.randomize();
  if (rand_init) ChibiSimulation_Fifo_1__enq_ptr.randomize();
  if (rand_init) ChibiSimulation_Fifo_1__deq_ptr.randomize();
  if (rand_init) ChibiSimulation_Fifo_0__ram.randomize();
  if (rand_init) ChibiSimulation_Fifo_0__is_full.randomize();
  if (rand_init) ChibiSimulation_Fifo_0__enq_ptr.randomize();
  if (rand_init) ChibiSimulation_Fifo_0__deq_ptr.randomize();
  nodes.clear();
  mems.clear();
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_deq_dat_str", &ChibiSimulation_Controller_Fifo_1__io_deq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_deq_val", &ChibiSimulation_Controller_Fifo_1__io_deq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_rx_rdy", &ChibiSimulation_Controller_WordMapper_1__io_rx_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_rx_dat_str", &ChibiSimulation_Controller_WordMapper_1__io_rx_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_deq_dat_id", &ChibiSimulation_Controller_Fifo_1__io_deq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_rx_dat_id", &ChibiSimulation_Controller_WordMapper_1__io_rx_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_rx_val", &ChibiSimulation_Controller_WordMapper_1__io_rx_val));
  mems.push_back(debug_mem_t("ChibiSimulation.Controller.WordMapper_1.res", &ChibiSimulation_Controller_WordMapper_1__res));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.is_full", &ChibiSimulation_Controller_WordMapper_1__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_deq_dat_str", &ChibiSimulation_Controller_Fifo_0__io_deq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_deq_val", &ChibiSimulation_Controller_Fifo_0__io_deq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_rx_rdy", &ChibiSimulation_Controller_WordMapper_0__io_rx_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_rx_dat_str", &ChibiSimulation_Controller_WordMapper_0__io_rx_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_deq_dat_id", &ChibiSimulation_Controller_Fifo_0__io_deq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_rx_dat_id", &ChibiSimulation_Controller_WordMapper_0__io_rx_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_rx_val", &ChibiSimulation_Controller_WordMapper_0__io_rx_val));
  mems.push_back(debug_mem_t("ChibiSimulation.Controller.WordMapper_0.res", &ChibiSimulation_Controller_WordMapper_0__res));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.is_full", &ChibiSimulation_Controller_WordMapper_0__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_tx_dat_int", &ChibiSimulation_Controller_WordMapper_1__io_tx_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_enq_rdy", &ChibiSimulation_Controller_Fifo_3__io_enq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_tx_val", &ChibiSimulation_Controller_WordMapper_1__io_tx_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_enq_dat_int", &ChibiSimulation_Controller_Fifo_3__io_enq_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_tx_dat_str", &ChibiSimulation_Controller_WordMapper_1__io_tx_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_enq_dat_str", &ChibiSimulation_Controller_Fifo_3__io_enq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_1.io_tx_dat_id", &ChibiSimulation_Controller_WordMapper_1__io_tx_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_enq_dat_id", &ChibiSimulation_Controller_Fifo_3__io_enq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_enq_val", &ChibiSimulation_Controller_Fifo_3__io_enq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.do_enq", &ChibiSimulation_Controller_Fifo_3__do_enq));
  mems.push_back(debug_mem_t("ChibiSimulation.Controller.Fifo_3.ram", &ChibiSimulation_Controller_Fifo_3__ram));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_deq_val", &ChibiSimulation_Controller_Fifo_3__io_deq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_deq_rdy", &ChibiSimulation_Controller_Fifo_3__io_deq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.is_full", &ChibiSimulation_Controller_Fifo_3__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.enq_ptr", &ChibiSimulation_Controller_Fifo_3__enq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.deq_ptr", &ChibiSimulation_Controller_Fifo_3__deq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_tx_dat_int", &ChibiSimulation_Controller_WordMapper_0__io_tx_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_enq_rdy", &ChibiSimulation_Controller_Fifo_2__io_enq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_tx_val", &ChibiSimulation_Controller_WordMapper_0__io_tx_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_enq_dat_int", &ChibiSimulation_Controller_Fifo_2__io_enq_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_tx_dat_str", &ChibiSimulation_Controller_WordMapper_0__io_tx_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_enq_dat_str", &ChibiSimulation_Controller_Fifo_2__io_enq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.WordMapper_0.io_tx_dat_id", &ChibiSimulation_Controller_WordMapper_0__io_tx_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_enq_dat_id", &ChibiSimulation_Controller_Fifo_2__io_enq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_enq_val", &ChibiSimulation_Controller_Fifo_2__io_enq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.do_enq", &ChibiSimulation_Controller_Fifo_2__do_enq));
  mems.push_back(debug_mem_t("ChibiSimulation.Controller.Fifo_2.ram", &ChibiSimulation_Controller_Fifo_2__ram));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_deq_val", &ChibiSimulation_Controller_Fifo_2__io_deq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_deq_rdy", &ChibiSimulation_Controller_Fifo_2__io_deq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.is_full", &ChibiSimulation_Controller_Fifo_2__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.enq_ptr", &ChibiSimulation_Controller_Fifo_2__enq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.deq_ptr", &ChibiSimulation_Controller_Fifo_2__deq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_deq_dat_str", &ChibiSimulation_Fifo_0__io_deq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_rx_dat_str", &ChibiSimulation_Controller__io_rx_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_enq_rdy", &ChibiSimulation_Controller_Fifo_1__io_enq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_deq_val", &ChibiSimulation_Fifo_0__io_deq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_rx_val", &ChibiSimulation_Controller__io_rx_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_enq_dat_str", &ChibiSimulation_Controller_Fifo_1__io_enq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_deq_dat_id", &ChibiSimulation_Fifo_0__io_deq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_rx_dat_id", &ChibiSimulation_Controller__io_rx_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_enq_dat_id", &ChibiSimulation_Controller_Fifo_1__io_enq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_enq_val", &ChibiSimulation_Controller_Fifo_1__io_enq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.do_enq", &ChibiSimulation_Controller_Fifo_1__do_enq));
  mems.push_back(debug_mem_t("ChibiSimulation.Controller.Fifo_1.ram", &ChibiSimulation_Controller_Fifo_1__ram));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.enq_ptr", &ChibiSimulation_Controller_Fifo_1__enq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.io_deq_rdy", &ChibiSimulation_Controller_Fifo_1__io_deq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.deq_ptr", &ChibiSimulation_Controller_Fifo_1__deq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_1.is_full", &ChibiSimulation_Controller_Fifo_1__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_enq_rdy", &ChibiSimulation_Controller_Fifo_0__io_enq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_enq_dat_str", &ChibiSimulation_Controller_Fifo_0__io_enq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_enq_dat_id", &ChibiSimulation_Controller_Fifo_0__io_enq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_enq_val", &ChibiSimulation_Controller_Fifo_0__io_enq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.do_enq", &ChibiSimulation_Controller_Fifo_0__do_enq));
  mems.push_back(debug_mem_t("ChibiSimulation.Controller.Fifo_0.ram", &ChibiSimulation_Controller_Fifo_0__ram));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.io_deq_rdy", &ChibiSimulation_Controller_Fifo_0__io_deq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.is_full", &ChibiSimulation_Controller_Fifo_0__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.enq_ptr", &ChibiSimulation_Controller_Fifo_0__enq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_0.deq_ptr", &ChibiSimulation_Controller_Fifo_0__deq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.inCounter", &ChibiSimulation_Controller__inCounter));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_deq_dat_int", &ChibiSimulation_Controller_Fifo_2__io_deq_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_deq_dat_int", &ChibiSimulation_Controller_Fifo_3__io_deq_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_tx_dat_int", &ChibiSimulation_Controller__io_tx_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_enq_dat_int", &ChibiSimulation_Fifo_1__io_enq_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_deq_dat_str", &ChibiSimulation_Controller_Fifo_2__io_deq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_deq_dat_str", &ChibiSimulation_Controller_Fifo_3__io_deq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_tx_dat_str", &ChibiSimulation_Controller__io_tx_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_enq_dat_str", &ChibiSimulation_Fifo_1__io_enq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_2.io_deq_dat_id", &ChibiSimulation_Controller_Fifo_2__io_deq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.Fifo_3.io_deq_dat_id", &ChibiSimulation_Controller_Fifo_3__io_deq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_tx_dat_id", &ChibiSimulation_Controller__io_tx_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_enq_dat_id", &ChibiSimulation_Fifo_1__io_enq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_enq_rdy", &ChibiSimulation_Fifo_1__io_enq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Controller.io_tx_val", &ChibiSimulation_Controller__io_tx_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_enq_val", &ChibiSimulation_Fifo_1__io_enq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.do_enq", &ChibiSimulation_Fifo_1__do_enq));
  mems.push_back(debug_mem_t("ChibiSimulation.Fifo_1.ram", &ChibiSimulation_Fifo_1__ram));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_deq_val", &ChibiSimulation_Fifo_1__io_deq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_deq_rdy", &ChibiSimulation_Fifo_1__io_deq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.is_full", &ChibiSimulation_Fifo_1__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.enq_ptr", &ChibiSimulation_Fifo_1__enq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.deq_ptr", &ChibiSimulation_Fifo_1__deq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.io_in_dat_str", &ChibiSimulation__io_in_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_enq_dat_str", &ChibiSimulation_Fifo_0__io_enq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.io_in_dat_id", &ChibiSimulation__io_in_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_enq_dat_id", &ChibiSimulation_Fifo_0__io_enq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_enq_rdy", &ChibiSimulation_Fifo_0__io_enq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.io_in_val", &ChibiSimulation__io_in_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_enq_val", &ChibiSimulation_Fifo_0__io_enq_val));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.do_enq", &ChibiSimulation_Fifo_0__do_enq));
  mems.push_back(debug_mem_t("ChibiSimulation.Fifo_0.ram", &ChibiSimulation_Fifo_0__ram));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.io_deq_rdy", &ChibiSimulation_Fifo_0__io_deq_rdy));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.is_full", &ChibiSimulation_Fifo_0__is_full));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.enq_ptr", &ChibiSimulation_Fifo_0__enq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_0.deq_ptr", &ChibiSimulation_Fifo_0__deq_ptr));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_deq_dat_id", &ChibiSimulation_Fifo_1__io_deq_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.io_out_dat_id", &ChibiSimulation__io_out_dat_id));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_deq_dat_str", &ChibiSimulation_Fifo_1__io_deq_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.io_out_dat_str", &ChibiSimulation__io_out_dat_str));
  nodes.push_back(debug_node_t("ChibiSimulation.Fifo_1.io_deq_dat_int", &ChibiSimulation_Fifo_1__io_deq_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.io_out_dat_int", &ChibiSimulation__io_out_dat_int));
  nodes.push_back(debug_node_t("ChibiSimulation.io_out_val", &ChibiSimulation__io_out_val));
}
void ChibiSimulation_t::clock_lo ( dat_t<1> reset ) {
  val_t ChibiSimulation_Controller__inNullBundle_str__w0, ChibiSimulation_Controller__inNullBundle_str__w1;
  { ChibiSimulation_Controller__inNullBundle_str__w0 = rand_val(); ChibiSimulation_Controller__inNullBundle_str__w1 = rand_val(); }
  val_t T16__w0;
  T16__w0 = (ChibiSimulation_Controller_Fifo_1__deq_ptr.values[0] >> 0) & 1;
  val_t T17__w0, T17__w1, T17__w2;
  { T17__w0 = ChibiSimulation_Controller_Fifo_1__ram.get(T16__w0, 0); T17__w1 = ChibiSimulation_Controller_Fifo_1__ram.get(T16__w0, 1); T17__w2 = ChibiSimulation_Controller_Fifo_1__ram.get(T16__w0, 2); }
  val_t T18__w0, T18__w1;
  { T18__w0 = T17__w0; T18__w1 = T17__w1; }
  { ChibiSimulation_Controller_Fifo_1__io_deq_dat_str.values[0] = T18__w0; ChibiSimulation_Controller_Fifo_1__io_deq_dat_str.values[1] = T18__w1; }
  val_t T19__w0;
  T19__w0 = ChibiSimulation_Controller_Fifo_1__enq_ptr.values[0] == ChibiSimulation_Controller_Fifo_1__deq_ptr.values[0];
  val_t T20__w0;
  T20__w0 = !ChibiSimulation_Controller_Fifo_1__is_full.values[0];
  val_t ChibiSimulation_Controller_Fifo_1__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_1__is_empty__w0 = T20__w0&&T19__w0; }
  val_t T21__w0;
  T21__w0 = !ChibiSimulation_Controller_Fifo_1__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_1__io_deq_val.values[0] = T21__w0; }
  val_t T22__w0;
  T22__w0 = !ChibiSimulation_Controller_WordMapper_1__is_full.values[0];
  { ChibiSimulation_Controller_WordMapper_1__io_rx_rdy.values[0] = T22__w0; }
  val_t T23__w0;
  { T23__w0 = ChibiSimulation_Controller_WordMapper_1__io_rx_rdy.values[0]&&ChibiSimulation_Controller_Fifo_1__io_deq_val.values[0]; }
  val_t T24__w0, T24__w1;
  { val_t __mask = -T23__w0; T24__w0 = ChibiSimulation_Controller__inNullBundle_str__w0 ^ ((ChibiSimulation_Controller__inNullBundle_str__w0 ^ ChibiSimulation_Controller_Fifo_1__io_deq_dat_str.values[0]) & __mask); T24__w1 = ChibiSimulation_Controller__inNullBundle_str__w1 ^ ((ChibiSimulation_Controller__inNullBundle_str__w1 ^ ChibiSimulation_Controller_Fifo_1__io_deq_dat_str.values[1]) & __mask); }
  val_t T25__w0;
  T25__w0 = !T23__w0;
  val_t T26__w0, T26__w1;
  { val_t __mask = -T25__w0; T26__w0 = T24__w0 ^ ((T24__w0 ^ ChibiSimulation_Controller__inNullBundle_str__w0) & __mask); T26__w1 = T24__w1 ^ ((T24__w1 ^ ChibiSimulation_Controller__inNullBundle_str__w1) & __mask); }
  { ChibiSimulation_Controller_WordMapper_1__io_rx_dat_str.values[0] = T26__w0; ChibiSimulation_Controller_WordMapper_1__io_rx_dat_str.values[1] = T26__w1; }
  val_t ChibiSimulation_Controller__inNullBundle_id__w0;
  { ChibiSimulation_Controller__inNullBundle_id__w0 = rand_val(); }
  val_t T27__w0;
  { T27__w0 = T17__w2; }
  { ChibiSimulation_Controller_Fifo_1__io_deq_dat_id.values[0] = T27__w0; }
  val_t T28__w0;
  { val_t __mask = -T23__w0; T28__w0 = ChibiSimulation_Controller__inNullBundle_id__w0 ^ ((ChibiSimulation_Controller__inNullBundle_id__w0 ^ ChibiSimulation_Controller_Fifo_1__io_deq_dat_id.values[0]) & __mask); }
  val_t T29__w0;
  { val_t __mask = -T25__w0; T29__w0 = T28__w0 ^ ((T28__w0 ^ ChibiSimulation_Controller__inNullBundle_id__w0) & __mask); }
  { ChibiSimulation_Controller_WordMapper_1__io_rx_dat_id.values[0] = T29__w0; }
  val_t T30__w0, T30__w1, T30__w2;
  { T30__w0 = ChibiSimulation_Controller_WordMapper_1__io_rx_dat_str.values[0]; T30__w1 = ChibiSimulation_Controller_WordMapper_1__io_rx_dat_str.values[1]; T30__w2 = ChibiSimulation_Controller_WordMapper_1__io_rx_dat_id.values[0]; }
  { T0.values[0] = T30__w0; T0.values[1] = T30__w1; T0.values[2] = T30__w2; }
  val_t T31__w0;
  { val_t __mask = -T25__w0; T31__w0 = T23__w0 ^ ((T23__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0] = T31__w0; }
  { ChibiSimulation_Controller__reset.values[0] = reset.values[0]; }
  { ChibiSimulation_Controller_WordMapper_1__reset.values[0] = ChibiSimulation_Controller__reset.values[0]; }
  val_t T32__w0;
  { T32__w0 = R1.values[0]+0x1L; }
  T32__w0 = T32__w0 & 1;
  val_t T33__w0;
  T33__w0 = R1.values[0] == 0x1L;
  val_t T34__w0;
  { val_t __mask = -T33__w0; T34__w0 = T32__w0 ^ ((T32__w0 ^ 0x0L) & __mask); }
  { R1_shadow.values[0] = TERNARY(ChibiSimulation_Controller_WordMapper_1__reset.values[0], 0x0L, T34__w0); }
  val_t T35__w0;
  { val_t __mask = -ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0]; T35__w0 = ChibiSimulation_Controller_WordMapper_1__is_full.values[0] ^ ((ChibiSimulation_Controller_WordMapper_1__is_full.values[0] ^ 0x1L) & __mask); }
  val_t T36__w0;
  T36__w0 = 0x1L == R1.values[0];
  val_t T37__w0;
  { T37__w0 = T36__w0&&ChibiSimulation_Controller_WordMapper_1__is_full.values[0]; }
  val_t T38__w0;
  { val_t __mask = -T37__w0; T38__w0 = T35__w0 ^ ((T35__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_WordMapper_1__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Controller_WordMapper_1__reset.values[0], 0x0L, T38__w0); }
  val_t T39__w0;
  T39__w0 = (ChibiSimulation_Controller_Fifo_0__deq_ptr.values[0] >> 0) & 1;
  val_t T40__w0, T40__w1, T40__w2;
  { T40__w0 = ChibiSimulation_Controller_Fifo_0__ram.get(T39__w0, 0); T40__w1 = ChibiSimulation_Controller_Fifo_0__ram.get(T39__w0, 1); T40__w2 = ChibiSimulation_Controller_Fifo_0__ram.get(T39__w0, 2); }
  val_t T41__w0, T41__w1;
  { T41__w0 = T40__w0; T41__w1 = T40__w1; }
  { ChibiSimulation_Controller_Fifo_0__io_deq_dat_str.values[0] = T41__w0; ChibiSimulation_Controller_Fifo_0__io_deq_dat_str.values[1] = T41__w1; }
  val_t T42__w0;
  T42__w0 = ChibiSimulation_Controller_Fifo_0__enq_ptr.values[0] == ChibiSimulation_Controller_Fifo_0__deq_ptr.values[0];
  val_t T43__w0;
  T43__w0 = !ChibiSimulation_Controller_Fifo_0__is_full.values[0];
  val_t ChibiSimulation_Controller_Fifo_0__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_0__is_empty__w0 = T43__w0&&T42__w0; }
  val_t T44__w0;
  T44__w0 = !ChibiSimulation_Controller_Fifo_0__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_0__io_deq_val.values[0] = T44__w0; }
  val_t T45__w0;
  T45__w0 = !ChibiSimulation_Controller_WordMapper_0__is_full.values[0];
  { ChibiSimulation_Controller_WordMapper_0__io_rx_rdy.values[0] = T45__w0; }
  val_t T46__w0;
  { T46__w0 = ChibiSimulation_Controller_WordMapper_0__io_rx_rdy.values[0]&&ChibiSimulation_Controller_Fifo_0__io_deq_val.values[0]; }
  val_t T47__w0, T47__w1;
  { val_t __mask = -T46__w0; T47__w0 = ChibiSimulation_Controller__inNullBundle_str__w0 ^ ((ChibiSimulation_Controller__inNullBundle_str__w0 ^ ChibiSimulation_Controller_Fifo_0__io_deq_dat_str.values[0]) & __mask); T47__w1 = ChibiSimulation_Controller__inNullBundle_str__w1 ^ ((ChibiSimulation_Controller__inNullBundle_str__w1 ^ ChibiSimulation_Controller_Fifo_0__io_deq_dat_str.values[1]) & __mask); }
  val_t T48__w0;
  T48__w0 = !T46__w0;
  val_t T49__w0, T49__w1;
  { val_t __mask = -T48__w0; T49__w0 = T47__w0 ^ ((T47__w0 ^ ChibiSimulation_Controller__inNullBundle_str__w0) & __mask); T49__w1 = T47__w1 ^ ((T47__w1 ^ ChibiSimulation_Controller__inNullBundle_str__w1) & __mask); }
  { ChibiSimulation_Controller_WordMapper_0__io_rx_dat_str.values[0] = T49__w0; ChibiSimulation_Controller_WordMapper_0__io_rx_dat_str.values[1] = T49__w1; }
  val_t T50__w0;
  { T50__w0 = T40__w2; }
  { ChibiSimulation_Controller_Fifo_0__io_deq_dat_id.values[0] = T50__w0; }
  val_t T51__w0;
  { val_t __mask = -T46__w0; T51__w0 = ChibiSimulation_Controller__inNullBundle_id__w0 ^ ((ChibiSimulation_Controller__inNullBundle_id__w0 ^ ChibiSimulation_Controller_Fifo_0__io_deq_dat_id.values[0]) & __mask); }
  val_t T52__w0;
  { val_t __mask = -T48__w0; T52__w0 = T51__w0 ^ ((T51__w0 ^ ChibiSimulation_Controller__inNullBundle_id__w0) & __mask); }
  { ChibiSimulation_Controller_WordMapper_0__io_rx_dat_id.values[0] = T52__w0; }
  val_t T53__w0, T53__w1, T53__w2;
  { T53__w0 = ChibiSimulation_Controller_WordMapper_0__io_rx_dat_str.values[0]; T53__w1 = ChibiSimulation_Controller_WordMapper_0__io_rx_dat_str.values[1]; T53__w2 = ChibiSimulation_Controller_WordMapper_0__io_rx_dat_id.values[0]; }
  { T2.values[0] = T53__w0; T2.values[1] = T53__w1; T2.values[2] = T53__w2; }
  val_t T54__w0;
  { val_t __mask = -T48__w0; T54__w0 = T46__w0 ^ ((T46__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0] = T54__w0; }
  { ChibiSimulation_Controller_WordMapper_0__reset.values[0] = ChibiSimulation_Controller__reset.values[0]; }
  val_t T55__w0;
  { T55__w0 = R3.values[0]+0x1L; }
  T55__w0 = T55__w0 & 1;
  val_t T56__w0;
  T56__w0 = R3.values[0] == 0x1L;
  val_t T57__w0;
  { val_t __mask = -T56__w0; T57__w0 = T55__w0 ^ ((T55__w0 ^ 0x0L) & __mask); }
  { R3_shadow.values[0] = TERNARY(ChibiSimulation_Controller_WordMapper_0__reset.values[0], 0x0L, T57__w0); }
  val_t T58__w0;
  { val_t __mask = -ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0]; T58__w0 = ChibiSimulation_Controller_WordMapper_0__is_full.values[0] ^ ((ChibiSimulation_Controller_WordMapper_0__is_full.values[0] ^ 0x1L) & __mask); }
  val_t T59__w0;
  T59__w0 = 0x1L == R3.values[0];
  val_t T60__w0;
  { T60__w0 = T59__w0&&ChibiSimulation_Controller_WordMapper_0__is_full.values[0]; }
  val_t T61__w0;
  { val_t __mask = -T60__w0; T61__w0 = T58__w0 ^ ((T58__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_WordMapper_0__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Controller_WordMapper_0__reset.values[0], 0x0L, T61__w0); }
  val_t ChibiSimulation_Controller__outNullBundle_int__w0;
  { ChibiSimulation_Controller__outNullBundle_int__w0 = rand_val(); }
  ChibiSimulation_Controller__outNullBundle_int__w0 = ChibiSimulation_Controller__outNullBundle_int__w0 & 4294967295;
  val_t T62__w0;
  { val_t __mask = -T37__w0; T62__w0 = 0x0L ^ ((0x0L ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller_WordMapper_1__io_tx_dat_int.values[0] = T62__w0; }
  val_t T63__w0;
  T63__w0 = !ChibiSimulation_Controller_Fifo_3__is_full.values[0];
  { ChibiSimulation_Controller_Fifo_3__io_enq_rdy.values[0] = T63__w0; }
  { ChibiSimulation_Controller_WordMapper_1__io_tx_val.values[0] = T37__w0; }
  val_t T64__w0;
  { T64__w0 = ChibiSimulation_Controller_WordMapper_1__io_tx_val.values[0]&&ChibiSimulation_Controller_Fifo_3__io_enq_rdy.values[0]; }
  val_t T65__w0;
  { val_t __mask = -T64__w0; T65__w0 = ChibiSimulation_Controller__outNullBundle_int__w0 ^ ((ChibiSimulation_Controller__outNullBundle_int__w0 ^ ChibiSimulation_Controller_WordMapper_1__io_tx_dat_int.values[0]) & __mask); }
  val_t T66__w0;
  T66__w0 = !T64__w0;
  val_t T67__w0;
  { val_t __mask = -T66__w0; T67__w0 = T65__w0 ^ ((T65__w0 ^ ChibiSimulation_Controller__outNullBundle_int__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__io_enq_dat_int.values[0] = T67__w0; }
  val_t ChibiSimulation_Controller__outNullBundle_str__w0, ChibiSimulation_Controller__outNullBundle_str__w1;
  { ChibiSimulation_Controller__outNullBundle_str__w0 = rand_val(); ChibiSimulation_Controller__outNullBundle_str__w1 = rand_val(); }
  val_t T68__w0, T68__w1, T68__w2;
  { T68__w0 = ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 0); T68__w1 = ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 1); T68__w2 = ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 2); }
  val_t T69__w0, T69__w1;
  { T69__w0 = T68__w0; T69__w1 = T68__w1; }
  val_t T70__w0, T70__w1;
  { val_t __mask = -T37__w0; T70__w0 = 0x0L ^ ((0x0L ^ T69__w0) & __mask); T70__w1 = 0L ^ ((0L ^ T69__w1) & __mask); }
  { ChibiSimulation_Controller_WordMapper_1__io_tx_dat_str.values[0] = T70__w0; ChibiSimulation_Controller_WordMapper_1__io_tx_dat_str.values[1] = T70__w1; }
  val_t T71__w0, T71__w1;
  { val_t __mask = -T64__w0; T71__w0 = ChibiSimulation_Controller__outNullBundle_str__w0 ^ ((ChibiSimulation_Controller__outNullBundle_str__w0 ^ ChibiSimulation_Controller_WordMapper_1__io_tx_dat_str.values[0]) & __mask); T71__w1 = ChibiSimulation_Controller__outNullBundle_str__w1 ^ ((ChibiSimulation_Controller__outNullBundle_str__w1 ^ ChibiSimulation_Controller_WordMapper_1__io_tx_dat_str.values[1]) & __mask); }
  val_t T72__w0, T72__w1;
  { val_t __mask = -T66__w0; T72__w0 = T71__w0 ^ ((T71__w0 ^ ChibiSimulation_Controller__outNullBundle_str__w0) & __mask); T72__w1 = T71__w1 ^ ((T71__w1 ^ ChibiSimulation_Controller__outNullBundle_str__w1) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__io_enq_dat_str.values[0] = T72__w0; ChibiSimulation_Controller_Fifo_3__io_enq_dat_str.values[1] = T72__w1; }
  val_t ChibiSimulation_Controller__outNullBundle_id__w0;
  { ChibiSimulation_Controller__outNullBundle_id__w0 = rand_val(); }
  ChibiSimulation_Controller__outNullBundle_id__w0 = ChibiSimulation_Controller__outNullBundle_id__w0 & 4294967295;
  val_t T73__w0, T73__w1, T73__w2;
  { T73__w0 = ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 0); T73__w1 = ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 1); T73__w2 = ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 2); }
  val_t T74__w0;
  { T74__w0 = T73__w2; }
  val_t T75__w0;
  { val_t __mask = -T37__w0; T75__w0 = 0x0L ^ ((0x0L ^ T74__w0) & __mask); }
  val_t T76__w0;
  { T76__w0 = T75__w0; }
  T76__w0 = T76__w0 & 4294967295;
  { ChibiSimulation_Controller_WordMapper_1__io_tx_dat_id.values[0] = T76__w0; }
  val_t T77__w0;
  { val_t __mask = -T64__w0; T77__w0 = ChibiSimulation_Controller__outNullBundle_id__w0 ^ ((ChibiSimulation_Controller__outNullBundle_id__w0 ^ ChibiSimulation_Controller_WordMapper_1__io_tx_dat_id.values[0]) & __mask); }
  val_t T78__w0;
  { val_t __mask = -T66__w0; T78__w0 = T77__w0 ^ ((T77__w0 ^ ChibiSimulation_Controller__outNullBundle_id__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__io_enq_dat_id.values[0] = T78__w0; }
  val_t T79__w0, T79__w1, T79__w2;
  { T79__w0 = ChibiSimulation_Controller_Fifo_3__io_enq_dat_str.values[0]; T79__w1 = ChibiSimulation_Controller_Fifo_3__io_enq_dat_str.values[1]; T79__w2 = ChibiSimulation_Controller_Fifo_3__io_enq_dat_id.values[0]; }
  val_t T80__w0, T80__w1, T80__w2;
  { T80__w0 = ChibiSimulation_Controller_Fifo_3__io_enq_dat_int.values[0] | T79__w0 << 32; T80__w1 = T79__w0 >> 32 | T79__w1 << 32; T80__w2 = T79__w1 >> 32 | T79__w2 << 32; }
  { T4.values[0] = T80__w0; T4.values[1] = T80__w1; T4.values[2] = T80__w2; }
  val_t T81__w0;
  { val_t __mask = -T66__w0; T81__w0 = T64__w0 ^ ((T64__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__io_enq_val.values[0] = T81__w0; }
  { ChibiSimulation_Controller_Fifo_3__do_enq.values[0] = ChibiSimulation_Controller_Fifo_3__io_enq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_3__io_enq_val.values[0]; }
  T5.values[0] = (ChibiSimulation_Controller_Fifo_3__enq_ptr.values[0] >> 0) & 1;
  { ChibiSimulation_Controller_Fifo_3__reset.values[0] = ChibiSimulation_Controller__reset.values[0]; }
  val_t T82__w0;
  T82__w0 = ChibiSimulation_Controller_Fifo_3__enq_ptr.values[0] == ChibiSimulation_Controller_Fifo_3__deq_ptr.values[0];
  val_t T83__w0;
  T83__w0 = !ChibiSimulation_Controller_Fifo_3__is_full.values[0];
  val_t ChibiSimulation_Controller_Fifo_3__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_3__is_empty__w0 = T83__w0&&T82__w0; }
  val_t T84__w0;
  T84__w0 = !ChibiSimulation_Controller_Fifo_3__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_3__io_deq_val.values[0] = T84__w0; }
  val_t T85__w0;
  T85__w0 = ChibiSimulation_Controller_Fifo_3__io_deq_val.values[0] == 0x1L;
  val_t T86__w0;
  T86__w0 = 0x1L == T85__w0;
  val_t T87__w0;
  { T87__w0 = T86__w0&&ChibiSimulation_Controller_Fifo_3__io_deq_val.values[0]; }
  val_t T88__w0;
  T88__w0 = !T87__w0;
  val_t T89__w0;
  { val_t __mask = -T88__w0; T89__w0 = T87__w0 ^ ((T87__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__io_deq_rdy.values[0] = T89__w0; }
  val_t ChibiSimulation_Controller_Fifo_3__do_deq__w0;
  { ChibiSimulation_Controller_Fifo_3__do_deq__w0 = ChibiSimulation_Controller_Fifo_3__io_deq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_3__io_deq_val.values[0]; }
  val_t T90__w0;
  { T90__w0 = ChibiSimulation_Controller_Fifo_3__do_deq__w0&&ChibiSimulation_Controller_Fifo_3__is_full.values[0]; }
  val_t T91__w0;
  { val_t __mask = -T90__w0; T91__w0 = ChibiSimulation_Controller_Fifo_3__is_full.values[0] ^ ((ChibiSimulation_Controller_Fifo_3__is_full.values[0] ^ 0x0L) & __mask); }
  val_t ChibiSimulation_Controller_Fifo_3__enq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_3__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_3__enq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_3__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_3__enq_ptr_inc__w0 & 3;
  val_t T92__w0;
  T92__w0 = ChibiSimulation_Controller_Fifo_3__enq_ptr_inc__w0 == ChibiSimulation_Controller_Fifo_3__deq_ptr.values[0];
  val_t T93__w0;
  { T93__w0 = ~ChibiSimulation_Controller_Fifo_3__do_deq__w0; }
  T93__w0 = T93__w0 & 1;
  val_t T94__w0;
  { T94__w0 = ChibiSimulation_Controller_Fifo_3__do_enq.values[0]&&T93__w0; }
  val_t T95__w0;
  { T95__w0 = T94__w0&&T92__w0; }
  val_t ChibiSimulation_Controller_Fifo_3__is_full_next__w0;
  { val_t __mask = -T95__w0; ChibiSimulation_Controller_Fifo_3__is_full_next__w0 = T91__w0 ^ ((T91__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_3__reset.values[0], 0x0L, ChibiSimulation_Controller_Fifo_3__is_full_next__w0); }
  val_t T96__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_3__do_enq.values[0]; T96__w0 = ChibiSimulation_Controller_Fifo_3__enq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_3__enq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_3__enq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__enq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_3__reset.values[0], 0x0L, T96__w0); }
  val_t ChibiSimulation_Controller_Fifo_3__deq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_3__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_3__deq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_3__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_3__deq_ptr_inc__w0 & 3;
  val_t T97__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_3__do_deq__w0; T97__w0 = ChibiSimulation_Controller_Fifo_3__deq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_3__deq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_3__deq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_3__deq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_3__reset.values[0], 0x0L, T97__w0); }
  val_t T98__w0;
  { val_t __mask = -T60__w0; T98__w0 = 0x0L ^ ((0x0L ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller_WordMapper_0__io_tx_dat_int.values[0] = T98__w0; }
  val_t T99__w0;
  T99__w0 = !ChibiSimulation_Controller_Fifo_2__is_full.values[0];
  { ChibiSimulation_Controller_Fifo_2__io_enq_rdy.values[0] = T99__w0; }
  { ChibiSimulation_Controller_WordMapper_0__io_tx_val.values[0] = T60__w0; }
  val_t T100__w0;
  { T100__w0 = ChibiSimulation_Controller_WordMapper_0__io_tx_val.values[0]&&ChibiSimulation_Controller_Fifo_2__io_enq_rdy.values[0]; }
  val_t T101__w0;
  { val_t __mask = -T100__w0; T101__w0 = ChibiSimulation_Controller__outNullBundle_int__w0 ^ ((ChibiSimulation_Controller__outNullBundle_int__w0 ^ ChibiSimulation_Controller_WordMapper_0__io_tx_dat_int.values[0]) & __mask); }
  val_t T102__w0;
  T102__w0 = !T100__w0;
  val_t T103__w0;
  { val_t __mask = -T102__w0; T103__w0 = T101__w0 ^ ((T101__w0 ^ ChibiSimulation_Controller__outNullBundle_int__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__io_enq_dat_int.values[0] = T103__w0; }
  val_t T104__w0, T104__w1, T104__w2;
  { T104__w0 = ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 0); T104__w1 = ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 1); T104__w2 = ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 2); }
  val_t T105__w0, T105__w1;
  { T105__w0 = T104__w0; T105__w1 = T104__w1; }
  val_t T106__w0, T106__w1;
  { val_t __mask = -T60__w0; T106__w0 = 0x0L ^ ((0x0L ^ T105__w0) & __mask); T106__w1 = 0L ^ ((0L ^ T105__w1) & __mask); }
  { ChibiSimulation_Controller_WordMapper_0__io_tx_dat_str.values[0] = T106__w0; ChibiSimulation_Controller_WordMapper_0__io_tx_dat_str.values[1] = T106__w1; }
  val_t T107__w0, T107__w1;
  { val_t __mask = -T100__w0; T107__w0 = ChibiSimulation_Controller__outNullBundle_str__w0 ^ ((ChibiSimulation_Controller__outNullBundle_str__w0 ^ ChibiSimulation_Controller_WordMapper_0__io_tx_dat_str.values[0]) & __mask); T107__w1 = ChibiSimulation_Controller__outNullBundle_str__w1 ^ ((ChibiSimulation_Controller__outNullBundle_str__w1 ^ ChibiSimulation_Controller_WordMapper_0__io_tx_dat_str.values[1]) & __mask); }
  val_t T108__w0, T108__w1;
  { val_t __mask = -T102__w0; T108__w0 = T107__w0 ^ ((T107__w0 ^ ChibiSimulation_Controller__outNullBundle_str__w0) & __mask); T108__w1 = T107__w1 ^ ((T107__w1 ^ ChibiSimulation_Controller__outNullBundle_str__w1) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__io_enq_dat_str.values[0] = T108__w0; ChibiSimulation_Controller_Fifo_2__io_enq_dat_str.values[1] = T108__w1; }
  val_t T109__w0, T109__w1, T109__w2;
  { T109__w0 = ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 0); T109__w1 = ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 1); T109__w2 = ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 2); }
  val_t T110__w0;
  { T110__w0 = T109__w2; }
  val_t T111__w0;
  { val_t __mask = -T60__w0; T111__w0 = 0x0L ^ ((0x0L ^ T110__w0) & __mask); }
  val_t T112__w0;
  { T112__w0 = T111__w0; }
  T112__w0 = T112__w0 & 4294967295;
  { ChibiSimulation_Controller_WordMapper_0__io_tx_dat_id.values[0] = T112__w0; }
  val_t T113__w0;
  { val_t __mask = -T100__w0; T113__w0 = ChibiSimulation_Controller__outNullBundle_id__w0 ^ ((ChibiSimulation_Controller__outNullBundle_id__w0 ^ ChibiSimulation_Controller_WordMapper_0__io_tx_dat_id.values[0]) & __mask); }
  val_t T114__w0;
  { val_t __mask = -T102__w0; T114__w0 = T113__w0 ^ ((T113__w0 ^ ChibiSimulation_Controller__outNullBundle_id__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__io_enq_dat_id.values[0] = T114__w0; }
  val_t T115__w0, T115__w1, T115__w2;
  { T115__w0 = ChibiSimulation_Controller_Fifo_2__io_enq_dat_str.values[0]; T115__w1 = ChibiSimulation_Controller_Fifo_2__io_enq_dat_str.values[1]; T115__w2 = ChibiSimulation_Controller_Fifo_2__io_enq_dat_id.values[0]; }
  val_t T116__w0, T116__w1, T116__w2;
  { T116__w0 = ChibiSimulation_Controller_Fifo_2__io_enq_dat_int.values[0] | T115__w0 << 32; T116__w1 = T115__w0 >> 32 | T115__w1 << 32; T116__w2 = T115__w1 >> 32 | T115__w2 << 32; }
  { T6.values[0] = T116__w0; T6.values[1] = T116__w1; T6.values[2] = T116__w2; }
  val_t T117__w0;
  { val_t __mask = -T102__w0; T117__w0 = T100__w0 ^ ((T100__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__io_enq_val.values[0] = T117__w0; }
  { ChibiSimulation_Controller_Fifo_2__do_enq.values[0] = ChibiSimulation_Controller_Fifo_2__io_enq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_2__io_enq_val.values[0]; }
  T7.values[0] = (ChibiSimulation_Controller_Fifo_2__enq_ptr.values[0] >> 0) & 1;
  { ChibiSimulation_Controller_Fifo_2__reset.values[0] = ChibiSimulation_Controller__reset.values[0]; }
  val_t T118__w0;
  T118__w0 = ChibiSimulation_Controller_Fifo_2__enq_ptr.values[0] == ChibiSimulation_Controller_Fifo_2__deq_ptr.values[0];
  val_t T119__w0;
  T119__w0 = !ChibiSimulation_Controller_Fifo_2__is_full.values[0];
  val_t ChibiSimulation_Controller_Fifo_2__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_2__is_empty__w0 = T119__w0&&T118__w0; }
  val_t T120__w0;
  T120__w0 = !ChibiSimulation_Controller_Fifo_2__is_empty__w0;
  { ChibiSimulation_Controller_Fifo_2__io_deq_val.values[0] = T120__w0; }
  val_t T121__w0;
  T121__w0 = 0x0L == T85__w0;
  val_t T122__w0;
  { T122__w0 = T121__w0&&ChibiSimulation_Controller_Fifo_2__io_deq_val.values[0]; }
  val_t T123__w0;
  T123__w0 = !T122__w0;
  val_t T124__w0;
  { val_t __mask = -T123__w0; T124__w0 = T122__w0 ^ ((T122__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__io_deq_rdy.values[0] = T124__w0; }
  val_t ChibiSimulation_Controller_Fifo_2__do_deq__w0;
  { ChibiSimulation_Controller_Fifo_2__do_deq__w0 = ChibiSimulation_Controller_Fifo_2__io_deq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_2__io_deq_val.values[0]; }
  val_t T125__w0;
  { T125__w0 = ChibiSimulation_Controller_Fifo_2__do_deq__w0&&ChibiSimulation_Controller_Fifo_2__is_full.values[0]; }
  val_t T126__w0;
  { val_t __mask = -T125__w0; T126__w0 = ChibiSimulation_Controller_Fifo_2__is_full.values[0] ^ ((ChibiSimulation_Controller_Fifo_2__is_full.values[0] ^ 0x0L) & __mask); }
  val_t ChibiSimulation_Controller_Fifo_2__enq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_2__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_2__enq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_2__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_2__enq_ptr_inc__w0 & 3;
  val_t T127__w0;
  T127__w0 = ChibiSimulation_Controller_Fifo_2__enq_ptr_inc__w0 == ChibiSimulation_Controller_Fifo_2__deq_ptr.values[0];
  val_t T128__w0;
  { T128__w0 = ~ChibiSimulation_Controller_Fifo_2__do_deq__w0; }
  T128__w0 = T128__w0 & 1;
  val_t T129__w0;
  { T129__w0 = ChibiSimulation_Controller_Fifo_2__do_enq.values[0]&&T128__w0; }
  val_t T130__w0;
  { T130__w0 = T129__w0&&T127__w0; }
  val_t ChibiSimulation_Controller_Fifo_2__is_full_next__w0;
  { val_t __mask = -T130__w0; ChibiSimulation_Controller_Fifo_2__is_full_next__w0 = T126__w0 ^ ((T126__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_2__reset.values[0], 0x0L, ChibiSimulation_Controller_Fifo_2__is_full_next__w0); }
  val_t T131__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_2__do_enq.values[0]; T131__w0 = ChibiSimulation_Controller_Fifo_2__enq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_2__enq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_2__enq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__enq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_2__reset.values[0], 0x0L, T131__w0); }
  val_t ChibiSimulation_Controller_Fifo_2__deq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_2__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_2__deq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_2__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_2__deq_ptr_inc__w0 & 3;
  val_t T132__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_2__do_deq__w0; T132__w0 = ChibiSimulation_Controller_Fifo_2__deq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_2__deq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_2__deq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_2__deq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_2__reset.values[0], 0x0L, T132__w0); }
  val_t T133__w0;
  T133__w0 = (ChibiSimulation_Fifo_0__deq_ptr.values[0] >> 0) & 1;
  val_t T134__w0, T134__w1, T134__w2;
  { T134__w0 = ChibiSimulation_Fifo_0__ram.get(T133__w0, 0); T134__w1 = ChibiSimulation_Fifo_0__ram.get(T133__w0, 1); T134__w2 = ChibiSimulation_Fifo_0__ram.get(T133__w0, 2); }
  val_t T135__w0, T135__w1;
  { T135__w0 = T134__w0; T135__w1 = T134__w1; }
  { ChibiSimulation_Fifo_0__io_deq_dat_str.values[0] = T135__w0; ChibiSimulation_Fifo_0__io_deq_dat_str.values[1] = T135__w1; }
  { ChibiSimulation_Controller__io_rx_dat_str.values[0] = ChibiSimulation_Fifo_0__io_deq_dat_str.values[0]; ChibiSimulation_Controller__io_rx_dat_str.values[1] = ChibiSimulation_Fifo_0__io_deq_dat_str.values[1]; }
  val_t T136__w0;
  T136__w0 = !ChibiSimulation_Controller_Fifo_1__is_full.values[0];
  { ChibiSimulation_Controller_Fifo_1__io_enq_rdy.values[0] = T136__w0; }
  val_t T137__w0;
  T137__w0 = ChibiSimulation_Fifo_0__enq_ptr.values[0] == ChibiSimulation_Fifo_0__deq_ptr.values[0];
  val_t T138__w0;
  T138__w0 = !ChibiSimulation_Fifo_0__is_full.values[0];
  val_t ChibiSimulation_Fifo_0__is_empty__w0;
  { ChibiSimulation_Fifo_0__is_empty__w0 = T138__w0&&T137__w0; }
  val_t T139__w0;
  T139__w0 = !ChibiSimulation_Fifo_0__is_empty__w0;
  { ChibiSimulation_Fifo_0__io_deq_val.values[0] = T139__w0; }
  val_t T140__w0;
  T140__w0 = !ChibiSimulation_Fifo_0__io_deq_val.values[0];
  val_t T141__w0;
  { val_t __mask = -T140__w0; T141__w0 = ChibiSimulation_Fifo_0__io_deq_val.values[0] ^ ((ChibiSimulation_Fifo_0__io_deq_val.values[0] ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller__io_rx_val.values[0] = T141__w0; }
  val_t T142__w0;
  T142__w0 = 0x1L == ChibiSimulation_Controller__inCounter.values[0];
  val_t T143__w0;
  { T143__w0 = T142__w0&&ChibiSimulation_Controller__io_rx_val.values[0]; }
  val_t T144__w0;
  { T144__w0 = T143__w0&&ChibiSimulation_Controller_Fifo_1__io_enq_rdy.values[0]; }
  val_t T145__w0, T145__w1;
  { val_t __mask = -T144__w0; T145__w0 = ChibiSimulation_Controller__inNullBundle_str__w0 ^ ((ChibiSimulation_Controller__inNullBundle_str__w0 ^ ChibiSimulation_Controller__io_rx_dat_str.values[0]) & __mask); T145__w1 = ChibiSimulation_Controller__inNullBundle_str__w1 ^ ((ChibiSimulation_Controller__inNullBundle_str__w1 ^ ChibiSimulation_Controller__io_rx_dat_str.values[1]) & __mask); }
  val_t T146__w0;
  T146__w0 = !T144__w0;
  val_t T147__w0, T147__w1;
  { val_t __mask = -T146__w0; T147__w0 = T145__w0 ^ ((T145__w0 ^ ChibiSimulation_Controller__inNullBundle_str__w0) & __mask); T147__w1 = T145__w1 ^ ((T145__w1 ^ ChibiSimulation_Controller__inNullBundle_str__w1) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__io_enq_dat_str.values[0] = T147__w0; ChibiSimulation_Controller_Fifo_1__io_enq_dat_str.values[1] = T147__w1; }
  val_t T148__w0;
  { T148__w0 = T134__w2; }
  { ChibiSimulation_Fifo_0__io_deq_dat_id.values[0] = T148__w0; }
  { ChibiSimulation_Controller__io_rx_dat_id.values[0] = ChibiSimulation_Fifo_0__io_deq_dat_id.values[0]; }
  val_t T149__w0;
  { val_t __mask = -T144__w0; T149__w0 = ChibiSimulation_Controller__inNullBundle_id__w0 ^ ((ChibiSimulation_Controller__inNullBundle_id__w0 ^ ChibiSimulation_Controller__io_rx_dat_id.values[0]) & __mask); }
  val_t T150__w0;
  { val_t __mask = -T146__w0; T150__w0 = T149__w0 ^ ((T149__w0 ^ ChibiSimulation_Controller__inNullBundle_id__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__io_enq_dat_id.values[0] = T150__w0; }
  val_t T151__w0, T151__w1, T151__w2;
  { T151__w0 = ChibiSimulation_Controller_Fifo_1__io_enq_dat_str.values[0]; T151__w1 = ChibiSimulation_Controller_Fifo_1__io_enq_dat_str.values[1]; T151__w2 = ChibiSimulation_Controller_Fifo_1__io_enq_dat_id.values[0]; }
  { T8.values[0] = T151__w0; T8.values[1] = T151__w1; T8.values[2] = T151__w2; }
  val_t T152__w0;
  { val_t __mask = -T146__w0; T152__w0 = T144__w0 ^ ((T144__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__io_enq_val.values[0] = T152__w0; }
  { ChibiSimulation_Controller_Fifo_1__do_enq.values[0] = ChibiSimulation_Controller_Fifo_1__io_enq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_1__io_enq_val.values[0]; }
  T9.values[0] = (ChibiSimulation_Controller_Fifo_1__enq_ptr.values[0] >> 0) & 1;
  { ChibiSimulation_Controller_Fifo_1__reset.values[0] = ChibiSimulation_Controller__reset.values[0]; }
  val_t ChibiSimulation_Controller_Fifo_1__enq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_1__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_1__enq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_1__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_1__enq_ptr_inc__w0 & 3;
  val_t T153__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_1__do_enq.values[0]; T153__w0 = ChibiSimulation_Controller_Fifo_1__enq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_1__enq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_1__enq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__enq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_1__reset.values[0], 0x0L, T153__w0); }
  val_t ChibiSimulation_Controller_Fifo_1__deq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_1__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_1__deq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_1__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_1__deq_ptr_inc__w0 & 3;
  val_t T154__w0;
  { val_t __mask = -T25__w0; T154__w0 = T23__w0 ^ ((T23__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__io_deq_rdy.values[0] = T154__w0; }
  val_t ChibiSimulation_Controller_Fifo_1__do_deq__w0;
  { ChibiSimulation_Controller_Fifo_1__do_deq__w0 = ChibiSimulation_Controller_Fifo_1__io_deq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_1__io_deq_val.values[0]; }
  val_t T155__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_1__do_deq__w0; T155__w0 = ChibiSimulation_Controller_Fifo_1__deq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_1__deq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_1__deq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__deq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_1__reset.values[0], 0x0L, T155__w0); }
  val_t T156__w0;
  { T156__w0 = ChibiSimulation_Controller_Fifo_1__do_deq__w0&&ChibiSimulation_Controller_Fifo_1__is_full.values[0]; }
  val_t T157__w0;
  { val_t __mask = -T156__w0; T157__w0 = ChibiSimulation_Controller_Fifo_1__is_full.values[0] ^ ((ChibiSimulation_Controller_Fifo_1__is_full.values[0] ^ 0x0L) & __mask); }
  val_t T158__w0;
  T158__w0 = ChibiSimulation_Controller_Fifo_1__enq_ptr_inc__w0 == ChibiSimulation_Controller_Fifo_1__deq_ptr.values[0];
  val_t T159__w0;
  { T159__w0 = ~ChibiSimulation_Controller_Fifo_1__do_deq__w0; }
  T159__w0 = T159__w0 & 1;
  val_t T160__w0;
  { T160__w0 = ChibiSimulation_Controller_Fifo_1__do_enq.values[0]&&T159__w0; }
  val_t T161__w0;
  { T161__w0 = T160__w0&&T158__w0; }
  val_t ChibiSimulation_Controller_Fifo_1__is_full_next__w0;
  { val_t __mask = -T161__w0; ChibiSimulation_Controller_Fifo_1__is_full_next__w0 = T157__w0 ^ ((T157__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller_Fifo_1__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_1__reset.values[0], 0x0L, ChibiSimulation_Controller_Fifo_1__is_full_next__w0); }
  val_t T162__w0;
  T162__w0 = !ChibiSimulation_Controller_Fifo_0__is_full.values[0];
  { ChibiSimulation_Controller_Fifo_0__io_enq_rdy.values[0] = T162__w0; }
  val_t T163__w0;
  T163__w0 = 0x0L == ChibiSimulation_Controller__inCounter.values[0];
  val_t T164__w0;
  { T164__w0 = T163__w0&&ChibiSimulation_Controller__io_rx_val.values[0]; }
  val_t T165__w0;
  { T165__w0 = T164__w0&&ChibiSimulation_Controller_Fifo_0__io_enq_rdy.values[0]; }
  val_t T166__w0, T166__w1;
  { val_t __mask = -T165__w0; T166__w0 = ChibiSimulation_Controller__inNullBundle_str__w0 ^ ((ChibiSimulation_Controller__inNullBundle_str__w0 ^ ChibiSimulation_Controller__io_rx_dat_str.values[0]) & __mask); T166__w1 = ChibiSimulation_Controller__inNullBundle_str__w1 ^ ((ChibiSimulation_Controller__inNullBundle_str__w1 ^ ChibiSimulation_Controller__io_rx_dat_str.values[1]) & __mask); }
  val_t T167__w0;
  T167__w0 = !T165__w0;
  val_t T168__w0, T168__w1;
  { val_t __mask = -T167__w0; T168__w0 = T166__w0 ^ ((T166__w0 ^ ChibiSimulation_Controller__inNullBundle_str__w0) & __mask); T168__w1 = T166__w1 ^ ((T166__w1 ^ ChibiSimulation_Controller__inNullBundle_str__w1) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__io_enq_dat_str.values[0] = T168__w0; ChibiSimulation_Controller_Fifo_0__io_enq_dat_str.values[1] = T168__w1; }
  val_t T169__w0;
  { val_t __mask = -T165__w0; T169__w0 = ChibiSimulation_Controller__inNullBundle_id__w0 ^ ((ChibiSimulation_Controller__inNullBundle_id__w0 ^ ChibiSimulation_Controller__io_rx_dat_id.values[0]) & __mask); }
  val_t T170__w0;
  { val_t __mask = -T167__w0; T170__w0 = T169__w0 ^ ((T169__w0 ^ ChibiSimulation_Controller__inNullBundle_id__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__io_enq_dat_id.values[0] = T170__w0; }
  val_t T171__w0, T171__w1, T171__w2;
  { T171__w0 = ChibiSimulation_Controller_Fifo_0__io_enq_dat_str.values[0]; T171__w1 = ChibiSimulation_Controller_Fifo_0__io_enq_dat_str.values[1]; T171__w2 = ChibiSimulation_Controller_Fifo_0__io_enq_dat_id.values[0]; }
  { T10.values[0] = T171__w0; T10.values[1] = T171__w1; T10.values[2] = T171__w2; }
  val_t T172__w0;
  { val_t __mask = -T167__w0; T172__w0 = T165__w0 ^ ((T165__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__io_enq_val.values[0] = T172__w0; }
  { ChibiSimulation_Controller_Fifo_0__do_enq.values[0] = ChibiSimulation_Controller_Fifo_0__io_enq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_0__io_enq_val.values[0]; }
  T11.values[0] = (ChibiSimulation_Controller_Fifo_0__enq_ptr.values[0] >> 0) & 1;
  { ChibiSimulation_Controller_Fifo_0__reset.values[0] = ChibiSimulation_Controller__reset.values[0]; }
  val_t T173__w0;
  { val_t __mask = -T48__w0; T173__w0 = T46__w0 ^ ((T46__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__io_deq_rdy.values[0] = T173__w0; }
  val_t ChibiSimulation_Controller_Fifo_0__do_deq__w0;
  { ChibiSimulation_Controller_Fifo_0__do_deq__w0 = ChibiSimulation_Controller_Fifo_0__io_deq_rdy.values[0]&&ChibiSimulation_Controller_Fifo_0__io_deq_val.values[0]; }
  val_t T174__w0;
  { T174__w0 = ChibiSimulation_Controller_Fifo_0__do_deq__w0&&ChibiSimulation_Controller_Fifo_0__is_full.values[0]; }
  val_t T175__w0;
  { val_t __mask = -T174__w0; T175__w0 = ChibiSimulation_Controller_Fifo_0__is_full.values[0] ^ ((ChibiSimulation_Controller_Fifo_0__is_full.values[0] ^ 0x0L) & __mask); }
  val_t ChibiSimulation_Controller_Fifo_0__enq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_0__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_0__enq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_0__enq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_0__enq_ptr_inc__w0 & 3;
  val_t T176__w0;
  T176__w0 = ChibiSimulation_Controller_Fifo_0__enq_ptr_inc__w0 == ChibiSimulation_Controller_Fifo_0__deq_ptr.values[0];
  val_t T177__w0;
  { T177__w0 = ~ChibiSimulation_Controller_Fifo_0__do_deq__w0; }
  T177__w0 = T177__w0 & 1;
  val_t T178__w0;
  { T178__w0 = ChibiSimulation_Controller_Fifo_0__do_enq.values[0]&&T177__w0; }
  val_t T179__w0;
  { T179__w0 = T178__w0&&T176__w0; }
  val_t ChibiSimulation_Controller_Fifo_0__is_full_next__w0;
  { val_t __mask = -T179__w0; ChibiSimulation_Controller_Fifo_0__is_full_next__w0 = T175__w0 ^ ((T175__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_0__reset.values[0], 0x0L, ChibiSimulation_Controller_Fifo_0__is_full_next__w0); }
  val_t T180__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_0__do_enq.values[0]; T180__w0 = ChibiSimulation_Controller_Fifo_0__enq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_0__enq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_0__enq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__enq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_0__reset.values[0], 0x0L, T180__w0); }
  val_t ChibiSimulation_Controller_Fifo_0__deq_ptr_inc__w0;
  { ChibiSimulation_Controller_Fifo_0__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_0__deq_ptr.values[0]+0x1L; }
  ChibiSimulation_Controller_Fifo_0__deq_ptr_inc__w0 = ChibiSimulation_Controller_Fifo_0__deq_ptr_inc__w0 & 3;
  val_t T181__w0;
  { val_t __mask = -ChibiSimulation_Controller_Fifo_0__do_deq__w0; T181__w0 = ChibiSimulation_Controller_Fifo_0__deq_ptr.values[0] ^ ((ChibiSimulation_Controller_Fifo_0__deq_ptr.values[0] ^ ChibiSimulation_Controller_Fifo_0__deq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Controller_Fifo_0__deq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Controller_Fifo_0__reset.values[0], 0x0L, T181__w0); }
  val_t T182__w0;
  { T182__w0 = ChibiSimulation_Controller__inCounter.values[0]+0x1L; }
  T182__w0 = T182__w0 & 3;
  val_t T183__w0;
  T183__w0 = ChibiSimulation_Controller__inCounter.values[0] == 0x1L;
  val_t T184__w0;
  { val_t __mask = -T183__w0; T184__w0 = T182__w0 ^ ((T182__w0 ^ 0x0L) & __mask); }
  val_t T185__w0;
  { val_t __mask = -T165__w0; T185__w0 = ChibiSimulation_Controller__inCounter.values[0] ^ ((ChibiSimulation_Controller__inCounter.values[0] ^ T184__w0) & __mask); }
  val_t T186__w0;
  { T186__w0 = ChibiSimulation_Controller__inCounter.values[0]+0x1L; }
  T186__w0 = T186__w0 & 3;
  val_t T187__w0;
  T187__w0 = ChibiSimulation_Controller__inCounter.values[0] == 0x1L;
  val_t T188__w0;
  { val_t __mask = -T187__w0; T188__w0 = T186__w0 ^ ((T186__w0 ^ 0x0L) & __mask); }
  val_t T189__w0;
  { val_t __mask = -T144__w0; T189__w0 = T185__w0 ^ ((T185__w0 ^ T188__w0) & __mask); }
  { ChibiSimulation_Controller__inCounter_shadow.values[0] = TERNARY(ChibiSimulation_Controller__reset.values[0], 0x0L, T189__w0); }
  val_t T190__w0;
  T190__w0 = (ChibiSimulation_Controller_Fifo_2__deq_ptr.values[0] >> 0) & 1;
  val_t T191__w0, T191__w1, T191__w2;
  { T191__w0 = ChibiSimulation_Controller_Fifo_2__ram.get(T190__w0, 0); T191__w1 = ChibiSimulation_Controller_Fifo_2__ram.get(T190__w0, 1); T191__w2 = ChibiSimulation_Controller_Fifo_2__ram.get(T190__w0, 2); }
  val_t T192__w0;
  { T192__w0 = T191__w0; }
  T192__w0 = T192__w0 & 4294967295;
  { ChibiSimulation_Controller_Fifo_2__io_deq_dat_int.values[0] = T192__w0; }
  val_t T193__w0;
  { val_t __mask = -T122__w0; T193__w0 = ChibiSimulation_Controller__outNullBundle_int__w0 ^ ((ChibiSimulation_Controller__outNullBundle_int__w0 ^ ChibiSimulation_Controller_Fifo_2__io_deq_dat_int.values[0]) & __mask); }
  val_t T194__w0;
  T194__w0 = (ChibiSimulation_Controller_Fifo_3__deq_ptr.values[0] >> 0) & 1;
  val_t T195__w0, T195__w1, T195__w2;
  { T195__w0 = ChibiSimulation_Controller_Fifo_3__ram.get(T194__w0, 0); T195__w1 = ChibiSimulation_Controller_Fifo_3__ram.get(T194__w0, 1); T195__w2 = ChibiSimulation_Controller_Fifo_3__ram.get(T194__w0, 2); }
  val_t T196__w0;
  { T196__w0 = T195__w0; }
  T196__w0 = T196__w0 & 4294967295;
  { ChibiSimulation_Controller_Fifo_3__io_deq_dat_int.values[0] = T196__w0; }
  val_t T197__w0;
  { val_t __mask = -T87__w0; T197__w0 = T193__w0 ^ ((T193__w0 ^ ChibiSimulation_Controller_Fifo_3__io_deq_dat_int.values[0]) & __mask); }
  { ChibiSimulation_Controller__io_tx_dat_int.values[0] = T197__w0; }
  { ChibiSimulation_Fifo_1__io_enq_dat_int.values[0] = ChibiSimulation_Controller__io_tx_dat_int.values[0]; }
  val_t T198__w0, T198__w1;
  { T198__w0 = T191__w0 >> 32 | T191__w1 << 32; T198__w1 = T191__w1 >> 32 | T191__w2 << 32; }
  { ChibiSimulation_Controller_Fifo_2__io_deq_dat_str.values[0] = T198__w0; ChibiSimulation_Controller_Fifo_2__io_deq_dat_str.values[1] = T198__w1; }
  val_t T199__w0, T199__w1;
  { val_t __mask = -T122__w0; T199__w0 = ChibiSimulation_Controller__outNullBundle_str__w0 ^ ((ChibiSimulation_Controller__outNullBundle_str__w0 ^ ChibiSimulation_Controller_Fifo_2__io_deq_dat_str.values[0]) & __mask); T199__w1 = ChibiSimulation_Controller__outNullBundle_str__w1 ^ ((ChibiSimulation_Controller__outNullBundle_str__w1 ^ ChibiSimulation_Controller_Fifo_2__io_deq_dat_str.values[1]) & __mask); }
  val_t T200__w0, T200__w1;
  { T200__w0 = T195__w0 >> 32 | T195__w1 << 32; T200__w1 = T195__w1 >> 32 | T195__w2 << 32; }
  { ChibiSimulation_Controller_Fifo_3__io_deq_dat_str.values[0] = T200__w0; ChibiSimulation_Controller_Fifo_3__io_deq_dat_str.values[1] = T200__w1; }
  val_t T201__w0, T201__w1;
  { val_t __mask = -T87__w0; T201__w0 = T199__w0 ^ ((T199__w0 ^ ChibiSimulation_Controller_Fifo_3__io_deq_dat_str.values[0]) & __mask); T201__w1 = T199__w1 ^ ((T199__w1 ^ ChibiSimulation_Controller_Fifo_3__io_deq_dat_str.values[1]) & __mask); }
  { ChibiSimulation_Controller__io_tx_dat_str.values[0] = T201__w0; ChibiSimulation_Controller__io_tx_dat_str.values[1] = T201__w1; }
  { ChibiSimulation_Fifo_1__io_enq_dat_str.values[0] = ChibiSimulation_Controller__io_tx_dat_str.values[0]; ChibiSimulation_Fifo_1__io_enq_dat_str.values[1] = ChibiSimulation_Controller__io_tx_dat_str.values[1]; }
  val_t T202__w0;
  { T202__w0 = T191__w2 >> 32; }
  T202__w0 = T202__w0 & 4294967295;
  { ChibiSimulation_Controller_Fifo_2__io_deq_dat_id.values[0] = T202__w0; }
  val_t T203__w0;
  { val_t __mask = -T122__w0; T203__w0 = ChibiSimulation_Controller__outNullBundle_id__w0 ^ ((ChibiSimulation_Controller__outNullBundle_id__w0 ^ ChibiSimulation_Controller_Fifo_2__io_deq_dat_id.values[0]) & __mask); }
  val_t T204__w0;
  { T204__w0 = T195__w2 >> 32; }
  T204__w0 = T204__w0 & 4294967295;
  { ChibiSimulation_Controller_Fifo_3__io_deq_dat_id.values[0] = T204__w0; }
  val_t T205__w0;
  { val_t __mask = -T87__w0; T205__w0 = T203__w0 ^ ((T203__w0 ^ ChibiSimulation_Controller_Fifo_3__io_deq_dat_id.values[0]) & __mask); }
  { ChibiSimulation_Controller__io_tx_dat_id.values[0] = T205__w0; }
  { ChibiSimulation_Fifo_1__io_enq_dat_id.values[0] = ChibiSimulation_Controller__io_tx_dat_id.values[0]; }
  val_t T206__w0, T206__w1, T206__w2;
  { T206__w0 = ChibiSimulation_Fifo_1__io_enq_dat_str.values[0]; T206__w1 = ChibiSimulation_Fifo_1__io_enq_dat_str.values[1]; T206__w2 = ChibiSimulation_Fifo_1__io_enq_dat_id.values[0]; }
  val_t T207__w0, T207__w1, T207__w2;
  { T207__w0 = ChibiSimulation_Fifo_1__io_enq_dat_int.values[0] | T206__w0 << 32; T207__w1 = T206__w0 >> 32 | T206__w1 << 32; T207__w2 = T206__w1 >> 32 | T206__w2 << 32; }
  { T12.values[0] = T207__w0; T12.values[1] = T207__w1; T12.values[2] = T207__w2; }
  val_t T208__w0;
  T208__w0 = !ChibiSimulation_Fifo_1__is_full.values[0];
  { ChibiSimulation_Fifo_1__io_enq_rdy.values[0] = T208__w0; }
  val_t T209__w0;
  { val_t __mask = -T87__w0; T209__w0 = T122__w0 ^ ((T122__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Controller__io_tx_val.values[0] = T209__w0; }
  val_t T210__w0;
  { T210__w0 = ChibiSimulation_Controller__io_tx_val.values[0]&&ChibiSimulation_Fifo_1__io_enq_rdy.values[0]; }
  val_t T211__w0;
  T211__w0 = !T210__w0;
  val_t T212__w0;
  { val_t __mask = -T211__w0; T212__w0 = T210__w0 ^ ((T210__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Fifo_1__io_enq_val.values[0] = T212__w0; }
  { ChibiSimulation_Fifo_1__do_enq.values[0] = ChibiSimulation_Fifo_1__io_enq_rdy.values[0]&&ChibiSimulation_Fifo_1__io_enq_val.values[0]; }
  T13.values[0] = (ChibiSimulation_Fifo_1__enq_ptr.values[0] >> 0) & 1;
  { ChibiSimulation_Fifo_1__reset.values[0] = reset.values[0]; }
  val_t T213__w0;
  T213__w0 = ChibiSimulation_Fifo_1__enq_ptr.values[0] == ChibiSimulation_Fifo_1__deq_ptr.values[0];
  val_t T214__w0;
  T214__w0 = !ChibiSimulation_Fifo_1__is_full.values[0];
  val_t ChibiSimulation_Fifo_1__is_empty__w0;
  { ChibiSimulation_Fifo_1__is_empty__w0 = T214__w0&&T213__w0; }
  val_t T215__w0;
  T215__w0 = !ChibiSimulation_Fifo_1__is_empty__w0;
  { ChibiSimulation_Fifo_1__io_deq_val.values[0] = T215__w0; }
  val_t T216__w0;
  T216__w0 = !ChibiSimulation_Fifo_1__io_deq_val.values[0];
  val_t T217__w0;
  { val_t __mask = -T216__w0; T217__w0 = ChibiSimulation_Fifo_1__io_deq_val.values[0] ^ ((ChibiSimulation_Fifo_1__io_deq_val.values[0] ^ 0x0L) & __mask); }
  { ChibiSimulation_Fifo_1__io_deq_rdy.values[0] = T217__w0; }
  val_t ChibiSimulation_Fifo_1__do_deq__w0;
  { ChibiSimulation_Fifo_1__do_deq__w0 = ChibiSimulation_Fifo_1__io_deq_rdy.values[0]&&ChibiSimulation_Fifo_1__io_deq_val.values[0]; }
  val_t T218__w0;
  { T218__w0 = ChibiSimulation_Fifo_1__do_deq__w0&&ChibiSimulation_Fifo_1__is_full.values[0]; }
  val_t T219__w0;
  { val_t __mask = -T218__w0; T219__w0 = ChibiSimulation_Fifo_1__is_full.values[0] ^ ((ChibiSimulation_Fifo_1__is_full.values[0] ^ 0x0L) & __mask); }
  val_t ChibiSimulation_Fifo_1__enq_ptr_inc__w0;
  { ChibiSimulation_Fifo_1__enq_ptr_inc__w0 = ChibiSimulation_Fifo_1__enq_ptr.values[0]+0x1L; }
  ChibiSimulation_Fifo_1__enq_ptr_inc__w0 = ChibiSimulation_Fifo_1__enq_ptr_inc__w0 & 3;
  val_t T220__w0;
  T220__w0 = ChibiSimulation_Fifo_1__enq_ptr_inc__w0 == ChibiSimulation_Fifo_1__deq_ptr.values[0];
  val_t T221__w0;
  { T221__w0 = ~ChibiSimulation_Fifo_1__do_deq__w0; }
  T221__w0 = T221__w0 & 1;
  val_t T222__w0;
  { T222__w0 = ChibiSimulation_Fifo_1__do_enq.values[0]&&T221__w0; }
  val_t T223__w0;
  { T223__w0 = T222__w0&&T220__w0; }
  val_t ChibiSimulation_Fifo_1__is_full_next__w0;
  { val_t __mask = -T223__w0; ChibiSimulation_Fifo_1__is_full_next__w0 = T219__w0 ^ ((T219__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Fifo_1__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Fifo_1__reset.values[0], 0x0L, ChibiSimulation_Fifo_1__is_full_next__w0); }
  val_t T224__w0;
  { val_t __mask = -ChibiSimulation_Fifo_1__do_enq.values[0]; T224__w0 = ChibiSimulation_Fifo_1__enq_ptr.values[0] ^ ((ChibiSimulation_Fifo_1__enq_ptr.values[0] ^ ChibiSimulation_Fifo_1__enq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Fifo_1__enq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Fifo_1__reset.values[0], 0x0L, T224__w0); }
  val_t ChibiSimulation_Fifo_1__deq_ptr_inc__w0;
  { ChibiSimulation_Fifo_1__deq_ptr_inc__w0 = ChibiSimulation_Fifo_1__deq_ptr.values[0]+0x1L; }
  ChibiSimulation_Fifo_1__deq_ptr_inc__w0 = ChibiSimulation_Fifo_1__deq_ptr_inc__w0 & 3;
  val_t T225__w0;
  { val_t __mask = -ChibiSimulation_Fifo_1__do_deq__w0; T225__w0 = ChibiSimulation_Fifo_1__deq_ptr.values[0] ^ ((ChibiSimulation_Fifo_1__deq_ptr.values[0] ^ ChibiSimulation_Fifo_1__deq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Fifo_1__deq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Fifo_1__reset.values[0], 0x0L, T225__w0); }
  { ChibiSimulation_Fifo_0__io_enq_dat_str.values[0] = ChibiSimulation__io_in_dat_str.values[0]; ChibiSimulation_Fifo_0__io_enq_dat_str.values[1] = ChibiSimulation__io_in_dat_str.values[1]; }
  { ChibiSimulation_Fifo_0__io_enq_dat_id.values[0] = ChibiSimulation__io_in_dat_id.values[0]; }
  val_t T226__w0, T226__w1, T226__w2;
  { T226__w0 = ChibiSimulation_Fifo_0__io_enq_dat_str.values[0]; T226__w1 = ChibiSimulation_Fifo_0__io_enq_dat_str.values[1]; T226__w2 = ChibiSimulation_Fifo_0__io_enq_dat_id.values[0]; }
  { T14.values[0] = T226__w0; T14.values[1] = T226__w1; T14.values[2] = T226__w2; }
  val_t T227__w0;
  T227__w0 = !ChibiSimulation_Fifo_0__is_full.values[0];
  { ChibiSimulation_Fifo_0__io_enq_rdy.values[0] = T227__w0; }
  val_t T228__w0;
  { T228__w0 = ChibiSimulation__io_in_val.values[0]&&ChibiSimulation_Fifo_0__io_enq_rdy.values[0]; }
  val_t T229__w0;
  T229__w0 = !T228__w0;
  val_t T230__w0;
  { val_t __mask = -T229__w0; T230__w0 = T228__w0 ^ ((T228__w0 ^ 0x0L) & __mask); }
  { ChibiSimulation_Fifo_0__io_enq_val.values[0] = T230__w0; }
  { ChibiSimulation_Fifo_0__do_enq.values[0] = ChibiSimulation_Fifo_0__io_enq_rdy.values[0]&&ChibiSimulation_Fifo_0__io_enq_val.values[0]; }
  T15.values[0] = (ChibiSimulation_Fifo_0__enq_ptr.values[0] >> 0) & 1;
  { ChibiSimulation_Fifo_0__reset.values[0] = reset.values[0]; }
  val_t T231__w0;
  { val_t __mask = -T140__w0; T231__w0 = ChibiSimulation_Fifo_0__io_deq_val.values[0] ^ ((ChibiSimulation_Fifo_0__io_deq_val.values[0] ^ 0x0L) & __mask); }
  { ChibiSimulation_Fifo_0__io_deq_rdy.values[0] = T231__w0; }
  val_t ChibiSimulation_Fifo_0__do_deq__w0;
  { ChibiSimulation_Fifo_0__do_deq__w0 = ChibiSimulation_Fifo_0__io_deq_rdy.values[0]&&ChibiSimulation_Fifo_0__io_deq_val.values[0]; }
  val_t T232__w0;
  { T232__w0 = ChibiSimulation_Fifo_0__do_deq__w0&&ChibiSimulation_Fifo_0__is_full.values[0]; }
  val_t T233__w0;
  { val_t __mask = -T232__w0; T233__w0 = ChibiSimulation_Fifo_0__is_full.values[0] ^ ((ChibiSimulation_Fifo_0__is_full.values[0] ^ 0x0L) & __mask); }
  val_t ChibiSimulation_Fifo_0__enq_ptr_inc__w0;
  { ChibiSimulation_Fifo_0__enq_ptr_inc__w0 = ChibiSimulation_Fifo_0__enq_ptr.values[0]+0x1L; }
  ChibiSimulation_Fifo_0__enq_ptr_inc__w0 = ChibiSimulation_Fifo_0__enq_ptr_inc__w0 & 3;
  val_t T234__w0;
  T234__w0 = ChibiSimulation_Fifo_0__enq_ptr_inc__w0 == ChibiSimulation_Fifo_0__deq_ptr.values[0];
  val_t T235__w0;
  { T235__w0 = ~ChibiSimulation_Fifo_0__do_deq__w0; }
  T235__w0 = T235__w0 & 1;
  val_t T236__w0;
  { T236__w0 = ChibiSimulation_Fifo_0__do_enq.values[0]&&T235__w0; }
  val_t T237__w0;
  { T237__w0 = T236__w0&&T234__w0; }
  val_t ChibiSimulation_Fifo_0__is_full_next__w0;
  { val_t __mask = -T237__w0; ChibiSimulation_Fifo_0__is_full_next__w0 = T233__w0 ^ ((T233__w0 ^ 0x1L) & __mask); }
  { ChibiSimulation_Fifo_0__is_full_shadow.values[0] = TERNARY(ChibiSimulation_Fifo_0__reset.values[0], 0x0L, ChibiSimulation_Fifo_0__is_full_next__w0); }
  val_t T238__w0;
  { val_t __mask = -ChibiSimulation_Fifo_0__do_enq.values[0]; T238__w0 = ChibiSimulation_Fifo_0__enq_ptr.values[0] ^ ((ChibiSimulation_Fifo_0__enq_ptr.values[0] ^ ChibiSimulation_Fifo_0__enq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Fifo_0__enq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Fifo_0__reset.values[0], 0x0L, T238__w0); }
  val_t ChibiSimulation_Fifo_0__deq_ptr_inc__w0;
  { ChibiSimulation_Fifo_0__deq_ptr_inc__w0 = ChibiSimulation_Fifo_0__deq_ptr.values[0]+0x1L; }
  ChibiSimulation_Fifo_0__deq_ptr_inc__w0 = ChibiSimulation_Fifo_0__deq_ptr_inc__w0 & 3;
  val_t T239__w0;
  { val_t __mask = -ChibiSimulation_Fifo_0__do_deq__w0; T239__w0 = ChibiSimulation_Fifo_0__deq_ptr.values[0] ^ ((ChibiSimulation_Fifo_0__deq_ptr.values[0] ^ ChibiSimulation_Fifo_0__deq_ptr_inc__w0) & __mask); }
  { ChibiSimulation_Fifo_0__deq_ptr_shadow.values[0] = TERNARY(ChibiSimulation_Fifo_0__reset.values[0], 0x0L, T239__w0); }
  val_t T240__w0;
  T240__w0 = (ChibiSimulation_Fifo_1__deq_ptr.values[0] >> 0) & 1;
  val_t T241__w0, T241__w1, T241__w2;
  { T241__w0 = ChibiSimulation_Fifo_1__ram.get(T240__w0, 0); T241__w1 = ChibiSimulation_Fifo_1__ram.get(T240__w0, 1); T241__w2 = ChibiSimulation_Fifo_1__ram.get(T240__w0, 2); }
  val_t T242__w0;
  { T242__w0 = T241__w2 >> 32; }
  T242__w0 = T242__w0 & 4294967295;
  { ChibiSimulation_Fifo_1__io_deq_dat_id.values[0] = T242__w0; }
  { ChibiSimulation__io_out_dat_id.values[0] = ChibiSimulation_Fifo_1__io_deq_dat_id.values[0]; }
  val_t T243__w0, T243__w1;
  { T243__w0 = T241__w0 >> 32 | T241__w1 << 32; T243__w1 = T241__w1 >> 32 | T241__w2 << 32; }
  { ChibiSimulation_Fifo_1__io_deq_dat_str.values[0] = T243__w0; ChibiSimulation_Fifo_1__io_deq_dat_str.values[1] = T243__w1; }
  { ChibiSimulation__io_out_dat_str.values[0] = ChibiSimulation_Fifo_1__io_deq_dat_str.values[0]; ChibiSimulation__io_out_dat_str.values[1] = ChibiSimulation_Fifo_1__io_deq_dat_str.values[1]; }
  val_t T244__w0;
  { T244__w0 = T241__w0; }
  T244__w0 = T244__w0 & 4294967295;
  { ChibiSimulation_Fifo_1__io_deq_dat_int.values[0] = T244__w0; }
  { ChibiSimulation__io_out_dat_int.values[0] = ChibiSimulation_Fifo_1__io_deq_dat_int.values[0]; }
  { ChibiSimulation__io_out_val.values[0] = ChibiSimulation_Fifo_1__io_deq_val.values[0]; }
}
void ChibiSimulation_t::clock_hi ( dat_t<1> reset ) {
  { ChibiSimulation_Controller_WordMapper_1__res.put(0x0L, 0, (T0.values[0] & (-ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0])) | (ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 0) & ~(-ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0]))); ChibiSimulation_Controller_WordMapper_1__res.put(0x0L, 1, (T0.values[1] & (-ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0])) | (ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 1) & ~(-ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0]))); ChibiSimulation_Controller_WordMapper_1__res.put(0x0L, 2, (T0.values[2] & (-ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0])) | (ChibiSimulation_Controller_WordMapper_1__res.get(0x0L, 2) & ~(-ChibiSimulation_Controller_WordMapper_1__io_rx_val.values[0]))); }
  { ChibiSimulation_Controller_WordMapper_0__res.put(0x0L, 0, (T2.values[0] & (-ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0])) | (ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 0) & ~(-ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0]))); ChibiSimulation_Controller_WordMapper_0__res.put(0x0L, 1, (T2.values[1] & (-ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0])) | (ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 1) & ~(-ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0]))); ChibiSimulation_Controller_WordMapper_0__res.put(0x0L, 2, (T2.values[2] & (-ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0])) | (ChibiSimulation_Controller_WordMapper_0__res.get(0x0L, 2) & ~(-ChibiSimulation_Controller_WordMapper_0__io_rx_val.values[0]))); }
  { ChibiSimulation_Controller_Fifo_3__ram.put(T5.values[0], 0, (T4.values[0] & (-ChibiSimulation_Controller_Fifo_3__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_3__ram.get(T5.values[0], 0) & ~(-ChibiSimulation_Controller_Fifo_3__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_3__ram.put(T5.values[0], 1, (T4.values[1] & (-ChibiSimulation_Controller_Fifo_3__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_3__ram.get(T5.values[0], 1) & ~(-ChibiSimulation_Controller_Fifo_3__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_3__ram.put(T5.values[0], 2, (T4.values[2] & (-ChibiSimulation_Controller_Fifo_3__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_3__ram.get(T5.values[0], 2) & ~(-ChibiSimulation_Controller_Fifo_3__do_enq.values[0]))); }
  { ChibiSimulation_Controller_Fifo_2__ram.put(T7.values[0], 0, (T6.values[0] & (-ChibiSimulation_Controller_Fifo_2__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_2__ram.get(T7.values[0], 0) & ~(-ChibiSimulation_Controller_Fifo_2__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_2__ram.put(T7.values[0], 1, (T6.values[1] & (-ChibiSimulation_Controller_Fifo_2__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_2__ram.get(T7.values[0], 1) & ~(-ChibiSimulation_Controller_Fifo_2__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_2__ram.put(T7.values[0], 2, (T6.values[2] & (-ChibiSimulation_Controller_Fifo_2__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_2__ram.get(T7.values[0], 2) & ~(-ChibiSimulation_Controller_Fifo_2__do_enq.values[0]))); }
  { ChibiSimulation_Controller_Fifo_1__ram.put(T9.values[0], 0, (T8.values[0] & (-ChibiSimulation_Controller_Fifo_1__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_1__ram.get(T9.values[0], 0) & ~(-ChibiSimulation_Controller_Fifo_1__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_1__ram.put(T9.values[0], 1, (T8.values[1] & (-ChibiSimulation_Controller_Fifo_1__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_1__ram.get(T9.values[0], 1) & ~(-ChibiSimulation_Controller_Fifo_1__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_1__ram.put(T9.values[0], 2, (T8.values[2] & (-ChibiSimulation_Controller_Fifo_1__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_1__ram.get(T9.values[0], 2) & ~(-ChibiSimulation_Controller_Fifo_1__do_enq.values[0]))); }
  { ChibiSimulation_Controller_Fifo_0__ram.put(T11.values[0], 0, (T10.values[0] & (-ChibiSimulation_Controller_Fifo_0__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_0__ram.get(T11.values[0], 0) & ~(-ChibiSimulation_Controller_Fifo_0__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_0__ram.put(T11.values[0], 1, (T10.values[1] & (-ChibiSimulation_Controller_Fifo_0__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_0__ram.get(T11.values[0], 1) & ~(-ChibiSimulation_Controller_Fifo_0__do_enq.values[0]))); ChibiSimulation_Controller_Fifo_0__ram.put(T11.values[0], 2, (T10.values[2] & (-ChibiSimulation_Controller_Fifo_0__do_enq.values[0])) | (ChibiSimulation_Controller_Fifo_0__ram.get(T11.values[0], 2) & ~(-ChibiSimulation_Controller_Fifo_0__do_enq.values[0]))); }
  { ChibiSimulation_Fifo_1__ram.put(T13.values[0], 0, (T12.values[0] & (-ChibiSimulation_Fifo_1__do_enq.values[0])) | (ChibiSimulation_Fifo_1__ram.get(T13.values[0], 0) & ~(-ChibiSimulation_Fifo_1__do_enq.values[0]))); ChibiSimulation_Fifo_1__ram.put(T13.values[0], 1, (T12.values[1] & (-ChibiSimulation_Fifo_1__do_enq.values[0])) | (ChibiSimulation_Fifo_1__ram.get(T13.values[0], 1) & ~(-ChibiSimulation_Fifo_1__do_enq.values[0]))); ChibiSimulation_Fifo_1__ram.put(T13.values[0], 2, (T12.values[2] & (-ChibiSimulation_Fifo_1__do_enq.values[0])) | (ChibiSimulation_Fifo_1__ram.get(T13.values[0], 2) & ~(-ChibiSimulation_Fifo_1__do_enq.values[0]))); }
  { ChibiSimulation_Fifo_0__ram.put(T15.values[0], 0, (T14.values[0] & (-ChibiSimulation_Fifo_0__do_enq.values[0])) | (ChibiSimulation_Fifo_0__ram.get(T15.values[0], 0) & ~(-ChibiSimulation_Fifo_0__do_enq.values[0]))); ChibiSimulation_Fifo_0__ram.put(T15.values[0], 1, (T14.values[1] & (-ChibiSimulation_Fifo_0__do_enq.values[0])) | (ChibiSimulation_Fifo_0__ram.get(T15.values[0], 1) & ~(-ChibiSimulation_Fifo_0__do_enq.values[0]))); ChibiSimulation_Fifo_0__ram.put(T15.values[0], 2, (T14.values[2] & (-ChibiSimulation_Fifo_0__do_enq.values[0])) | (ChibiSimulation_Fifo_0__ram.get(T15.values[0], 2) & ~(-ChibiSimulation_Fifo_0__do_enq.values[0]))); }
  R1 = R1_shadow;
  ChibiSimulation_Controller_WordMapper_1__is_full = ChibiSimulation_Controller_WordMapper_1__is_full_shadow;
  R3 = R3_shadow;
  ChibiSimulation_Controller_WordMapper_0__is_full = ChibiSimulation_Controller_WordMapper_0__is_full_shadow;
  ChibiSimulation_Controller_Fifo_3__is_full = ChibiSimulation_Controller_Fifo_3__is_full_shadow;
  ChibiSimulation_Controller_Fifo_3__enq_ptr = ChibiSimulation_Controller_Fifo_3__enq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_3__deq_ptr = ChibiSimulation_Controller_Fifo_3__deq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_2__is_full = ChibiSimulation_Controller_Fifo_2__is_full_shadow;
  ChibiSimulation_Controller_Fifo_2__enq_ptr = ChibiSimulation_Controller_Fifo_2__enq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_2__deq_ptr = ChibiSimulation_Controller_Fifo_2__deq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_1__enq_ptr = ChibiSimulation_Controller_Fifo_1__enq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_1__deq_ptr = ChibiSimulation_Controller_Fifo_1__deq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_1__is_full = ChibiSimulation_Controller_Fifo_1__is_full_shadow;
  ChibiSimulation_Controller_Fifo_0__is_full = ChibiSimulation_Controller_Fifo_0__is_full_shadow;
  ChibiSimulation_Controller_Fifo_0__enq_ptr = ChibiSimulation_Controller_Fifo_0__enq_ptr_shadow;
  ChibiSimulation_Controller_Fifo_0__deq_ptr = ChibiSimulation_Controller_Fifo_0__deq_ptr_shadow;
  ChibiSimulation_Controller__inCounter = ChibiSimulation_Controller__inCounter_shadow;
  ChibiSimulation_Fifo_1__is_full = ChibiSimulation_Fifo_1__is_full_shadow;
  ChibiSimulation_Fifo_1__enq_ptr = ChibiSimulation_Fifo_1__enq_ptr_shadow;
  ChibiSimulation_Fifo_1__deq_ptr = ChibiSimulation_Fifo_1__deq_ptr_shadow;
  ChibiSimulation_Fifo_0__is_full = ChibiSimulation_Fifo_0__is_full_shadow;
  ChibiSimulation_Fifo_0__enq_ptr = ChibiSimulation_Fifo_0__enq_ptr_shadow;
  ChibiSimulation_Fifo_0__deq_ptr = ChibiSimulation_Fifo_0__deq_ptr_shadow;
}
int ChibiSimulation_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}
void ChibiSimulation_t::print ( FILE* f, FILE* e ) {
  
  // Extract ID from Hardware Results - String Spliting
  int index;
  char *Id;
  Id = strtok(const_cast<char *>TO_CSTR(ChibiSimulation__io_out_dat_id), "x");
  Id = strtok(NULL, "x");
  index = atoi(Id);

  // Extract Valid Flags from Hardware Result - String Spliting
  char *tmp;
  int valid;
  tmp = strtok(const_cast<char *>(TO_CSTR(ChibiSimulation__io_out_val)), "x");
  tmp = strtok(NULL, "x");
  valid = atoi(tmp);

  // Check to make sure valid Resutlt and Unique example
  // Since the Simulation runs alot faster than the data is sent
  // it can try to send the results multiple times.
  // This check is to prevent that --- Strickly Speaking Valid should be enough.
  if((valid == 1) && (prevId != index) && (prevId2 != index)) {
    // Start to Create the Return String - WordCount
    char *res = new char[100];

    // Start with ID
    strcpy(res, TO_CSTR(ChibiSimulation__io_out_dat_id));
    strcat(res, " ");

    // Add Word
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_str));
    strcat(res, " ");

    // Add Count
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_int));
    
    // Write Return back to Software
    mmap_write(index, res);

    free(res);

    // Set the prevId flag to the current result to prevent sending the same
    // result multiple times
    prevId2 = prevId;
    prevId = index;
  }
}
bool ChibiSimulation_t::scan ( FILE* f ) {
  // Attempt to Read Result for a FIFO
  char *res;
  res = mmap_read();

  // Check if Result Valid
  if (res != NULL) {
    // Result Split for Entry into Hardware Modules
    char *tmp;
    tmp = strtok(res, " ");

    // Insert Unique Data Point ID
    str_to_dat(string(tmp), ChibiSimulation__io_in_dat_id);

    // Get pointer to next " " split
    tmp = strtok(NULL, " ");

    // Insert Data - Setup for WordCount
    str_to_dat(string(tmp), ChibiSimulation__io_in_dat_str);

    // Give 1 to in_val for new Data Point
    str_to_dat("1", ChibiSimulation__io_in_val);
  }

  free(res);
  return(!feof(f));
}


void ChibiSimulation_t::mmap_write(int id, char* str) {
  
  // First need to find the Name of the FIFO for the Results
  int i= 0;
  while(idToName[0][i] != id) i++;

  // ID Found - Create FIFO name
  char outName[100];
  sprintf(outName, "%s%dout", DIR_NAME, idToName[1][i]);  

  // Open Results FIFO
  int fd = open(outName, O_WRONLY);

  // Write to FIFO
  write(fd, str, SIZE);

  // Close FIFO
  close(fd);

  // Clear idToName of ID and Name
  idToName[0][i] = 0;
  idToName[1][i] = 0;
  
}

char* ChibiSimulation_t::mmap_read() {

  // FIND FIFO
  // READ -> TEST IF VALUE
    // IF VALUE RETURN RESULT
    // IF NOT VALUE LOOK FOR ANOTHER FIFO
  // IF NOT MORE FIFO RETURN NULL

  // Finds all FIFO's
  int *fifos;
  fifos = find_dir();

  char *res = (char *)malloc(SIZE);

  // Loop Through the Different FIFOs
  int i = 0;
  while(fifos[i] != 0) {
      // printf("+");
    // Create FIFO name
    char inName[100];
    sprintf(inName, "%s%din", DIR_NAME, fifos[i]);

    char flagName[100];
    sprintf(flagName, "%s%d", FLAG_NAME, fifos[i]);

    ssize_t r = 0;

    if( access(flagName, F_OK) != -1) {
      // Open FIFO - BLOCKING
      int fd = open(inName, O_RDONLY);

      // Attempt to Read Result
      r = read(fd, res, SIZE);

      // Close FIFO
      close(fd);
    }

    // Test Result - IF exists return res
    if (r > 0) {
      // Create a copy of the read to return
      char *the_res = (char *)malloc(SIZE);
      strcpy(the_res, res);

      // Need some way to track which ID corresponds to which fifo pair
      // Split to Get the ID
      char *tmp;
      tmp = strtok(res, " ");
      int resID = atoi(tmp);

      // Add ID and FIFO Name to idToName Array
      // Find Empty Entry
      int j = 0;
      while (idToName[0][j] != 0) j++;

      // Empty Found Add ID and Name to Array
      idToName[0][j] = resID; // ID
      idToName[1][j] = fifos[i]; // NAME

      free(res);
      free(fifos);
      return the_res;
    }

    i++;
  }

  // No Valid Results Found
  free(res);
  free(fifos);
  return NULL;
}

int* ChibiSimulation_t::find_dir() {
  
  // Directory Structure Variables
  DIR *dir;
  struct dirent *ent;

  // Array that holds fifo name
  int *fifos = (int*)malloc(sizeof(int)*20);
  int i = 0;

  // IF THERE IS A DIR
  if ((dir = opendir (DIR_NAME)) != NULL) {

    // While there are files to look at
    while ((ent = readdir (dir)) != NULL) {

      // Test to sure that it isn't curr/prev dir
      if(ent->d_name[0] != '.') {

        // Translate Name to Integer
        fifos[i] = atoi(ent->d_name);
        i++;
      }
    }

    // Once All FIFO are found close dir and return
    closedir (dir);
    return fifos;
  
  } else {

    /* could not open directory */
    perror ("Directory does not exist");
    exit(EXIT_FAILURE);
  }
}
void ChibiSimulation_t::dump(FILE *f, int t) {
}
