*     LanHEP output produced at Sun Aug 29 18:46:14 2010
*     Model named 'Stand. Model (Feyn. gauge)'

      double precision Sqrt2, pi, degree, hbar_c2,bogus
      parameter (Sqrt2=1.41421356237309504880168872421D0)
      parameter (pi = 3.1415926535897932384626433832795029D0)
      parameter (degree = pi/180D0)
      parameter (hbar_c2 = 3.8937966D8)
      parameter (bogus = -1D123)
      double complex cI
      parameter (cI = (0D0, 1D0))

      double precision Divergence
      common /renorm/ Divergence

      double precision EE, GG, SW, s12, s23, s13, CW, c12, c23
      double precision c13, Vud, Vus, Vub, Vcd, Vcs, Vcb, Vtd
      double precision Vts, Vtb, MZ, wZ, MW, wW, Mm, Mt, Mc, Ms
      double precision Mtop, wtop, Mb, MH, wH

      double precision AAABR(55)

      common /mdl_para/
     &    EE, GG, SW, s12, s23, s13, CW, c12, c23, c13, Vud, Vus,
     &    Vub, Vcd, Vcs, Vcb, Vtd, Vts, Vtb, MZ, wZ, MW, wW, Mm,
     &    Mt, Mc, Ms, Mtop, wtop, Mb, MH, wH, AAABR

