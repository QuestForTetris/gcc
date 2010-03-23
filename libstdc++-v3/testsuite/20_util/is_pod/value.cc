// { dg-options "-std=gnu++0x" }
// 2010-02-21  Paolo Carlini  <pcarlini@suse.de>
//
// Copyright (C) 2010 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <type_traits>
#include <testsuite_hooks.h>
#include <testsuite_tr1.h>

struct NType   // neither trivial nor standard-layout
{
  int i;
  int j;
  virtual ~NType();
};

struct TType   // trivial but not standard-layout
{
  int i;

private:
  int j;
};

struct SLType  // standard-layout but not trivial
{
  int i;
  int j;
  ~SLType();
};

struct PODType // both trivial and standard-layout
{
  int i;
  int j;
};

void test01()
{
  bool test __attribute__((unused)) = true;
  using std::is_pod;
  using namespace __gnu_test;

  VERIFY( (test_category<is_pod, int>(true)) );
  VERIFY( (test_category<is_pod, float>(true)) );
  VERIFY( (test_category<is_pod, EnumType>(true)) );
  VERIFY( (test_category<is_pod, int*>(true)) );
  VERIFY( (test_category<is_pod, int(*)(int)>(true)) );
  VERIFY( (test_category<is_pod, int (ClassType::*)>(true)) );
  VERIFY( (test_category<is_pod, int (ClassType::*) (int)>(true)) );
  VERIFY( (test_category<is_pod, int[2]>(true)) );
  VERIFY( (test_category<is_pod, float[][3]>(true)) );
  VERIFY( (test_category<is_pod, EnumType[2][3][4]>(true)) );
  VERIFY( (test_category<is_pod, int*[3]>(true)) );
  VERIFY( (test_category<is_pod, int(*[][2])(int)>(true)) );
  VERIFY( (test_category<is_pod, int (ClassType::*[2][3])>(true)) );
  VERIFY( (test_category<is_pod, int (ClassType::*[][2][3]) (int)>(true)) );
  VERIFY( (test_category<is_pod, ClassType>(true)) );
  VERIFY( (test_category<is_pod, PODType>(true)) );

  VERIFY( (test_category<is_pod, void>(false)) );
  VERIFY( (test_category<is_pod, NType>(false)) );
  VERIFY( (test_category<is_pod, TType>(false)) );
  VERIFY( (test_category<is_pod, SLType>(false)) );
}

int main()
{
  test01();
  return 0;
}
