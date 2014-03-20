! { dg-do compile } 
! { dg-additional-options "-fdump-tree-original" } 

program test
  implicit none
  integer :: q, i, j, k, m, n, o, p, r, s, t, u, v, w
  logical :: l

  !$acc kernels if(l) async copy(i), copyin(j), copyout(k), create(m) &
  !$acc present(o), pcopy(p), pcopyin(r), pcopyout(s), pcreate(t) &
  !$acc deviceptr(u)
  !$acc end kernels

end program test
! { dg-prune-output "unimplemented" }
! { dg-final { scan-tree-dump-times "pragma acc kernels" 1 "original" } } 

! { dg-final { scan-tree-dump-times "if" 1 "original" } }
! { dg-final { scan-tree-dump-times "async" 1 "original" } } 

! { dg-final { scan-tree-dump-times "map\\(force_tofrom:i\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(force_to:j\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(force_from:k\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(force_alloc:m\\)" 1 "original" } } 

! { dg-final { scan-tree-dump-times "map\\(force_present:o\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(tofrom:p\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(to:r\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(from:s\\)" 1 "original" } } 
! { dg-final { scan-tree-dump-times "map\\(alloc:t\\)" 1 "original" } } 

! { dg-final { scan-tree-dump-times "map\\(force_deviceptr:u\\)" 1 "original" } } 
! { dg-final { cleanup-tree-dump "original" } } 
