CVESVP
======

CVE Spectral Voice Processing Library

Todo & Plan List
===

- [x] Spectrum filter utilities
- [x] Implement `PSOLAIterlyzer`(in: `Wave`, out: `PulseList`)
- [x] Implement `PSOLAItersizer`(in: `Position` `DataFrame`, out: `Wave`)
- [x] Implement `VOTFromWave` based on `STFTIterlyzer`(in: `Wave`, out: `Position`)
- [X] Implement `Sinusoid` structure and `List_Sinusoid` and `Sinusoid_ToReal`
- [x] Implement `HNMFrame` `HNMContour` structure and `List_HNMFrame`
- [x] Implement `SinusoidIterlyzer`(in: `Wave`, out: `List_Sinusoid`)
- [x] Implement `SinusoidItersizer`(in: `Position` `Sinusoid`, out: `Wave`)
- [x] Implement `HNMIterlyzer`(in: `Wave`, out: `List_HNMFrame`)
- [x] Glottal pulse & phase reconstruction in `SinusoidItersizer`
- [x] Implement `HNMItersizer` based on `SinusoidItersizer`(in: `Position` `HNMFrame`, out: `Wave`)
- [ ] Implement `F0Iterlyzer`(in: `Wave`, out: `Real`)
- [ ] Replace `CDSP2_If_Debug_Check` with `RAssert`
- [ ] Default analysis window for `_F0.rc`
- [ ] Implement `PulseIterlyzer`(in: `Wave`, out: `PulseList`)
- [ ] Implement `PulseItersizer`(in: `Position`, out: `Wave`)
- [ ] Implement `GainIterfector`(in: `Wave` `Wave`, out: `Wave`)
- [ ] Implement `MixIterfector`(in: `Wave` `Wave`, out: `Wave`)
- [ ] Implement `TurbIterfector`(in: `Wave` `Wave`, out: `Wave`)
- [ ] Implement `GenKlatt` based on `FWindow`
- [ ] Implement `EpRParam` structure
- [ ] Implement `EpRParam_ToHNMContour`
- [ ] EpR fitting algorithm
- [ ] EpR manipulating utilities
- [ ] PSOLA manipulating utilities
- [ ] Implement `VMaxIndex`, `VMinIndex`, `VMaxEI`, `VMinEI` in RFNL.

