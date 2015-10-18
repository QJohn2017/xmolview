//========================================================================
// FILE: cGau.h
//
// This an utility program to manipulate and genarate structure files
//
// Copyright 2011-2015 by Edmanuel Torres
// email:   eetorres@gmail.com
//
//========================================================================

#ifndef _CPDB_H_
#define _CPDB_H_

#include <config_debug.h>
#include <time.h>
#include <string.h>
#include <msmvtl/const.h>
#include <msmvtl/tmatrix.h>
#include <msmvtl/tvmath.h>
#include <atom_symbol.h>
#include <atom_color.h>
//#include <const.h>

class CPdb{

public:

  CPdb();
  ~CPdb(){};

  // read/write files
  void clear(void);
  // XYZ file
  bool read_file(std::string,std::string);
  //
  void write_file(void);
  void write_file(std::string);
  void write_file(std::string,std::string);
  //
  void eval_atomic_composition(void);
  // set functions
  void set_total_atoms(uint u){ __total_atoms=u;};
  void set_total_cells(const uint, const uint, const uint, const uint);
  void set_file_format(const uint);
  void set_export_format(const uint);
  void set_fragments(const TVector<uint>&,uint);
  void set_charges(TVector<real>&);
  void set_atomic_symbol_table(const TVector<std::string>&);
  //void eval_atomic_number_table(void);
  void set_direct(const TMatrix<real>&);
  void set_cartesian(const TMatrix<real>&);
  void set_atomic_symbols(TVector<std::string>& v);
  void set_atomic_numbers(bool b);
  //
  // get function
  bool is_direct(void);
  bool is_periodic(void);
  bool is_labels(void);
  bool is_charges(void);
  //
  ///string get_symbols(int);
  uint get_total_species(void);
  uint get_total_atoms(void);
  uint get_format(void);
  uint get_atomic_number(std::string,size_t);
  uint get_atomic_composition(uint);
  real get_cartesian(uint,uint);
  real get_direct(uint,uint);

  //TVector<std::string> get_symbols(void);
  TVector<std::string> get_atomic_symbols(void);
  TVector<std::string> get_atomic_labels(void);
  TVector<std::string> get_atomic_symbol_table(void);
  TVector<uint> get_atomic_composition_table(void);
  TVector<uint> get_atomic_number_table(void);
  TVector<uint> get_atom_table(void);
  TVector<uint> get_atomic_numbers(void);
  TVector<uint> get_fragment_table(void);

  TVector<real> get_direct(uint);
  TVector<real> get_cartesian(uint);
  TVector<real> get_direct_basis(void);
  TVector<real> get_charges(void);

  TMatrix<real> get_xyz_input(void);
  TMatrix<real> get_direct(void);
  TMatrix<real> get_cartesian(void);
  TMatrix<real> get_centered_cartesian(void);
  TMatrix<real> get_unit_uvw_to_xyz(void){ return unit_uvwTxyz;};
  TMatrix<real> get_uvw_to_xyz(void){ return uvwTxyz;};
  // vectorial functions
  void get_rot_angle(void);
  // Extra functions
  void write_copyright(std::ofstream&);
  std::string get_date(void){
    time_t rawtime;
    char * _st, tmp_buffer[256];
    std::string stime;
    time (&rawtime);
    sprintf(tmp_buffer,"%s",ctime(&rawtime));
    _st = strtok(tmp_buffer,"\n");
    stime = _st;
    return stime;
  };

protected:
  //
  char xyz_head_buffer[8][256];
  //char tmp_buffer[256], *pch, dyn;
  std::string __filename, __system_title;
  std::string __config_filename;
  //
  bool __is_direct;
  bool __is_periodic;
  bool __is_sort;
  bool __is_dummy;
  bool __is_labels;
  bool __is_numbers;
  bool __is_fragments;
  bool __is_charges;
  bool __is_symbol_table;
  //
  uint __x_cells;
  uint __y_cells;
  uint __z_cells;
  uint __total_cells;
  //
  real __lattice_constant;
  real __vacuum_space;
  //
  uint __atomic_species;
  uint __total_atoms, a1;
  uint __total_fragments;
  uint __file_format;
  uint __export_format;
  uint __header_lines;
  //
  TVector<real> _vx, _vy, _vz, v_xyz;
  TVector<real> v_atomic_charges;
  TVector<uint> v_atomic_composition_table;
  TVector<uint> v_atomic_number_table;
  TVector<uint> v_atomic_numbers;
  TVector<uint> v_fragment_table;
  TVector<uint> v_atom_table;
  TVector<size_t> v_atomic_symbol_size;
  TVector<std::string> v_atomic_symbols;
  TVector<std::string> v_atomic_labels;
  TVector<std::string> v_atomic_symbol_table;
  //
  TMatrix<real> m_xyz_input;
  TMatrix<real> m_uvw;
  TMatrix<real> m_xyz;
  // transformation matrices
  TMatrix<real> uvwTxyz, unit_uvwTxyz;
  TMatrix<real> scl_uvwTxyz;
  //
  void center_coordinates(void);
  bool get_pdb_format(void);
};

#endif