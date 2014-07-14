CVESVP
======

CVE Spectral Voice Processing Library

Todo & Plan List
===

####Step1: Voice(Low Level) Modeling

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
- [x] Implement `F0Iterlyzer`(in: `Wave`, out: `Real`)
- [x] Phase control points for `SinusoidItersizer`

####Step2: Structural Changes & Minor Improvements

- [x] Replace `CDSP2_If_Debug_Check` with `RAssert`
- [x] Down integrate Lists to CVEDSP2
- [x] Conversion between `HNMFrame` and `HNMContour`
- [x] Implement `F0FromWave_YIN`
- [ ] Implement `GainIterfector` in CVEDSP2(in: `Wave` `Wave`, out: `Wave`)
- [ ] Implement `MixIterfector` in CVEDSP2(in: `Wave` `Wave`, out: `Wave`)
- [ ] Implement `PulseItersizer` in CVEDSP2(in: `Position`, out: `Wave`)
- [ ] Implement `TurbIterfector`(in: `Wave` `Wave`, out: `Wave`)

####Step3: Voice Manipulation

- [ ] Timbre adjustment related to pitch scaling
- [ ] Implement `GenKlatt` based on `FWindow`
- [ ] Implement `EpRParam` structure
- [ ] Implement `EpRParam_ToHNMContour`
- [ ] EpR fitting algorithm
- [ ] EpR manipulating utilities
- [ ] PSOLA manipulating utilities

####Others/External

- [ ] Implement `VMaxIndex`, `VMinIndex`, `VMaxEI`, `VMinEI`, `VLog` in RFNL
- [ ] More interpolation kernels(Cubic, Sinc) in RFNL
- [ ] Default analysis window for `_F0.rc`/Window Cache

