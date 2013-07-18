// ---------------------------------------------------------------------
// $Id$
//
// Copyright (C) 2007 - 2013 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------



// check creation and output of a matrix using an array


#include "../tests.h"
#include "full_matrix_common.h"


std::string output_file_name = "full_matrix_04/output";


template <typename number>
void
check ()
{
  const number array[] = { 1, 2, 3, 4, 5,
			   6, 7, 8, 9, 0,
			   1, 2, 3, 4, 5,
			   6, 7, 8, 9, 0,
			   1, 2, 3, 4, 5 };
  
  FullMatrix<number> m (5,5,array);

  print_matrix (m);
}

