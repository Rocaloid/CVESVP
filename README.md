CVESVP
======

CVE Spectral Voice Processing Library

Todo & Plan List
===

* Implement `PSOLAIterlyzer`(in: `Wave`, out: `PulseList`)
* Implement `PSOLAItersizer`(in: `Position` `DataFrame`, out: `Wave`)
* Implement `VOTFromWave` based on `STFTIterlyzer`(in: `Wave`, out: `Position`)
* Implement `Sinusoid` structure and `List_Sinusoid` and `Sinusoid_ToReal`
* Implement `HNMFrame` structure and `List_HNMFrame`
* Implement `SinusoidIterlyzer`(in: `Wave`, out: `List_Sinusoid`)
* Implement `SinusoidItersizer`(in: `Position` `Sinusoid`, out: `Wave`)
* Implement `HNMIterlyzer`(in: `Wave`, out: `List_HNMFrame`)
* Implement `HNMItersizer` based on `SinusoidItersizer`(in: `Position` `HNMFrame`, out: `Wave`)
* Implement `PulseIterlyzer`(in: `Wave`, out: `PulseList`)
* PSOLA manipulating utilities

