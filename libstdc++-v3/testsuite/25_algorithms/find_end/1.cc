// Copyright (C) 2005 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// 25.1.3 [lib.alg.find.end]

#include <algorithm>
#include <testsuite_hooks.h>
#include <testsuite_iterators.h>

using __gnu_test::test_container;
using __gnu_test::forward_iterator_wrapper;

typedef test_container<int, forward_iterator_wrapper> Container;

using std::find_end;

void
test1()
{
  int array[] = {0};
  Container con1(array, array);
  Container con2(array, array + 1);
  VERIFY(find_end(con1.begin(), con1.end(), con1.begin(), con1.end()).ptr == array);
  VERIFY(find_end(con1.begin(), con1.end(), con2.begin(), con2.end()).ptr == array);
  VERIFY(find_end(con2.begin(), con2.end(), con1.begin(), con1.end()).ptr == array + 1);
}

void 
test2()
{
  int array1[] = {2, 2, 1, 2, 2, 1};
  int array2[] = {2, 2};
  Container con1(array1, array1 + 6);
  Container con2(array2, array2 + 2);
  VERIFY(find_end(con1.begin(), con1.end(), con2.begin(), con2.end()).ptr == array1 + 3);
}

int main()
{
  test1();
  test2();
}
