// LICENSETEXT
// 
//   Copyright (C) 2007 : GreenSocs Ltd
//       http://www.greensocs.com/ , email: info@greensocs.com
// 
//   Developed by :
// 
//   Wolfgang Klingauf, Robert Guenzel
//     Technical University of Braunschweig, Dept. E.I.S.
//     http://www.eis.cs.tu-bs.de
// 
//   Mark Burton, Marcus Bartholomeu
//     GreenSocs Ltd
// 
// 
// The contents of this file are subject to the licensing terms specified
// in the file LICENSE. Please consult this file for restrictions and
// limitations that may apply.
// 
// ENDLICENSETEXT



#ifndef __TLM_B_IF_H__
#define __TLM_B_IF_H__

#include <boost/config.hpp> // needed for SystemC 2.1
#include <systemc>


namespace gs {


  template <class TRANSACTION>
  class tlm_b_if : public virtual sc_core::sc_interface
  {
  public:
    virtual void b_transact( TRANSACTION) = 0;
    virtual ~tlm_b_if(){}
  };

  template <class TRANSACTION>
  class tlm_multi_b_if : public virtual sc_core::sc_interface
  {
  public:
    virtual void b_transact(TRANSACTION, unsigned int index) = 0;
    virtual ~tlm_multi_b_if(){}
  };
  
  template <class TRANSACTION>
  class tlm_td_b_if : public virtual sc_core::sc_interface
  {
  public:
    virtual void b_transact( TRANSACTION, sc_core::sc_time& time) = 0;
    virtual ~tlm_td_b_if(){}
  };

  template <class TRANSACTION>
  class tlm_td_multi_b_if : public virtual sc_core::sc_interface
  {
  public:
    virtual void b_transact(TRANSACTION, sc_core::sc_time& time, unsigned int index) = 0;
    virtual ~tlm_td_multi_b_if(){}
  };
  
} // end of namespace gs

#endif
