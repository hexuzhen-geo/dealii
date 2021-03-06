// ---------------------------------------------------------------------
//
// Copyright (C) 2005 - 2017 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// test LAPACKFullMatrix::vmult() and Tvmult() for triangular matrices

/* MWE for size=3 in Octave:
R = [1,2,3; 0, 5, 6; 0, 0, 9]
x = [2; -7; 1]

> R*x
ans =

   -9
  -29
    9

R' * x
ans =

    2
  -31
  -27
*/

#include <deal.II/lac/full_matrix.h>
#include <deal.II/lac/lapack_full_matrix.h>
#include <deal.II/lac/vector.h>

#include <iostream>

#include "../tests.h"
#include "create_matrix.h"


template <typename NumberType>
void
test()
{
  const unsigned int           size = 3;
  LAPACKFullMatrix<NumberType> M(size);
  M.set_property(LAPACKSupport::upper_triangular);

  M                    = 0.;
  unsigned int counter = 1;
  for (unsigned int i = 0; i < size; ++i)
    for (unsigned int j = 0; j < size; ++j)
      {
        if (j >= i)
          M(i, j) = counter;

        counter++;
      }

  Vector<NumberType> x(size), y(size);
  x[0] = 2;
  x[1] = -7;
  x[2] = 1;

  M.vmult(y, x);
  y.print(deallog.get_file_stream(), 6, false);

  M.Tvmult(y, x);
  y.print(deallog.get_file_stream(), 6, false);
}


int
main()
{
  const std::string logname = "output";
  std::ofstream     logfile(logname.c_str());
  logfile.precision(3);
  deallog.attach(logfile);

  test<double>();
}
