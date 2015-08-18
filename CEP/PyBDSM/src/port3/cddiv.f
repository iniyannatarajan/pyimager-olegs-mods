      SUBROUTINE CDDIV(A,B,C)
      DOUBLE PRECISION A(2),B(2),C(2),G,H,T
C
C THIS ROUTINE DOES COMPLEX DOUBLE PRECISION
C DIVISION (C=A/B), FOLLOWING THE METHOD
C GIVEN IN ALGOL ON PAGES 357 AND 358 OF
C WILKINSON AND REINSCHS  BOOK-
C HANDBOOK FOR AUTOMATIC COMPUTATION
C SPRINGER-VERLAG 1971
C
C THIS VERSION HAS BEEN CHANGED SLIGHTLY TO PREVENT
C INPUTS A AND B FROM BEING DESTROYED.
C WRITTEN MARCH 20, 1975 BY P. FOX
C
C FOR ACCURACY THE COMPUTATION IS DONE DIFFERENTLY
C DEPENDING ON WHETHER THE REAL OR IMAGINARY PART OF
C B IS LARGER
C
      IF ( DABS(B(1)) .GT. DABS(B(2)) ) GO TO 10
      H = B(1)/B(2)
      G = H*B(1) + B(2)
      T = A(1)
      C(1) = (H * T  + A(2))/G
      C(2) = (H * A(2) - T)/G
      RETURN
C
C IF THE REAL PART OF B IS LARGER THAN THE IMAGINARY-
   10 H = B(2)/B(1)
      G = H*B(2) + B(1)
      T = A(1)
      C(1) = ( T  + H * A(2))/G
      C(2) = (A(2) - H * T)/G
      RETURN
      END
