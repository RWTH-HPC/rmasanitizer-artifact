
!---------------------------------------------------------------------
!---------------------------------------------------------------------

       subroutine  add

!---------------------------------------------------------------------
!---------------------------------------------------------------------

!---------------------------------------------------------------------
! addition of update to the vector u
!---------------------------------------------------------------------

       use sp_data
       implicit none

       integer  c, i, j, k, m

       do  c = 1, ncells
          do m = 1, 5
             do  k = start(3,c), cell_size(3,c)-end(3,c)-1
                do  j = start(2,c), cell_size(2,c)-end(2,c)-1
                   do  i = start(1,c), cell_size(1,c)-end(1,c)-1
                      u(i,j,k,m,c) = u(i,j,k,m,c) + rhs(i,j,k,m,c)
                   end do
                end do
             end do
          end do
       end do

       return
       end
