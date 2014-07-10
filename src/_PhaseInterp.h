#define _DataFrame _C(CDSP2_DataFrame, _, _T1)

RTFunc(void, CSVP_PhaseInterp, _DataFrame* Dest, _DataFrame* Sorc1,
    _DataFrame* Sorc2, _T1 Ratio);
RTFunc(void, CSVP_PhaseSync, _DataFrame* Dest, _T1* Freq, _T1 Phse0);

#undef  _DataFrame

