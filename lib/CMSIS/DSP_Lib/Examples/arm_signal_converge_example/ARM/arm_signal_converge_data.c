/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date: 16/10/14 6:00p $Revision:  V1.4.0
*
* Project:      CMSIS DSP Library
* Title:            arm_signal_converge_data.c
*
* Description:   Test input data for Floating point LMS Norm FIR filter
*
* Target Processor: Cortex-M4/Cortex-M3/Cortex-M0
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*   - Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   - Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*   - Neither the name of ARM LIMITED nor the names of its contributors
*     may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
* -------------------------------------------------------------------- */

#include "arm_math.h"

/* ----------------------------------------------------------------------
** Test input data for Floating point LMS Norm FIR filter
** Generated by the MATLAB randn() function
** ------------------------------------------------------------------- */

float32_t testInput_f32[1536] =
{
    -0.432565,  -1.665584,  0.125332,   0.287676,   -1.146471,  1.190915,   1.189164,   -0.037633,
    0.327292,   0.174639,   -0.186709,  0.725791,   -0.588317,  2.183186,   -0.136396,  0.113931,
    1.066768,   0.059281,   -0.095648,  -0.832349,  0.294411,   -1.336182,  0.714325,   1.623562,
    -0.691776,  0.857997,   1.254001,   -1.593730,  -1.440964,  0.571148,   -0.399886,  0.689997,
    0.815622,   0.711908,   1.290250,   0.668601,   1.190838,   -1.202457,  -0.019790,  -0.156717,
    -1.604086,  0.257304,   -1.056473,  1.415141,   -0.805090,  0.528743,   0.219321,   -0.921902,
    -2.170674,  -0.059188,  -1.010634,  0.614463,   0.507741,   1.692430,   0.591283,   -0.643595,
    0.380337,   -1.009116,  -0.019511,  -0.048221,  0.000043,   -0.317859,  1.095004,   -1.873990,
    0.428183,   0.895638,   0.730957,   0.577857,   0.040314,   0.677089,   0.568900,   -0.255645,
    -0.377469,  -0.295887,  -1.475135,  -0.234004,  0.118445,   0.314809,   1.443508,   -0.350975,
    0.623234,   0.799049,   0.940890,   -0.992092,  0.212035,   0.237882,   -1.007763,  -0.742045,
    1.082295,   -0.131500,  0.389880,   0.087987,   -0.635465,  -0.559573,  0.443653,   -0.949904,
    0.781182,   0.568961,   -0.821714,  -0.265607,  -1.187777,  -2.202321,  0.986337,   -0.518635,
    0.327368,   0.234057,   0.021466,   -1.003944,  -0.947146,  -0.374429,  -1.185886,  -1.055903,
    1.472480,   0.055744,   -1.217317,  -0.041227,  -1.128344,  -1.349278,  -0.261102,  0.953465,
    0.128644,   0.656468,   -1.167819,  -0.460605,  -0.262440,  -1.213152,  -1.319437,  0.931218,
    0.011245,   -0.645146,  0.805729,   0.231626,   -0.989760,  1.339586,   0.289502,   1.478917,
    1.138028,   -0.684139,  -1.291936,  -0.072926,  -0.330599,  -0.843628,  0.497770,   1.488490,
    -0.546476,  -0.846758,  -0.246337,  0.663024,   -0.854197,  -1.201315,  -0.119869,  -0.065294,
    0.485296,   -0.595491,  -0.149668,  -0.434752,  -0.079330,  1.535152,   -0.606483,  -1.347363,
    0.469383,   -0.903567,  0.035880,   -0.627531,  0.535398,   0.552884,   -0.203690,  -2.054325,
    0.132561,   1.592941,   1.018412,   -1.580402,  -0.078662,  -0.681657,  -1.024553,  -1.234353,
    0.288807,   -0.429303,  0.055801,   -0.367874,  -0.464973,  0.370961,   0.728283,   2.112160,
    -1.357298,  -1.022610,  1.037834,   -0.389800,  -1.381266,  0.315543,   1.553243,   0.707894,
    1.957385,   0.504542,   1.864529,   -0.339812,  -1.139779,  -0.211123,  1.190245,   -1.116209,
    0.635274,   -0.601412,  0.551185,   -1.099840,  0.085991,   -2.004563,  -0.493088,  0.462048,
    -0.321005,  1.236556,   -0.631280,  -2.325211,  -1.231637,  1.055648,   -0.113224,  0.379224,
    0.944200,   -2.120427,  -0.644679,  -0.704302,  -1.018137,  -0.182082,  1.521013,   -0.038439,
    1.227448,   -0.696205,  0.007524,   -0.782893,  0.586939,   -0.251207,  0.480136,   0.668155,
    -0.078321,  0.889173,   2.309287,   0.524639,   -0.011787,  0.913141,   0.055941,   -1.107070,
    0.485498,   -0.005005,  -0.276218,  1.276452,   1.863401,   -0.522559,  0.103424,   -0.807649,
    0.680439,   -2.364590,  0.990115,   0.218899,   0.261662,   1.213444,   -0.274667,  -0.133134,
    -1.270500,  -1.663606,  -0.703554,  0.280880,   -0.541209,  -1.333531,  1.072686,   -0.712085,
    -0.011286,  -0.000817,  -0.249436,  0.396575,   -0.264013,  -1.664011,  -1.028975,  0.243095,
    -1.256590,  -0.347183,  -0.941372,  -1.174560,  -1.021142,  -0.401667,  0.173666,   -0.116118,
    1.064119,   -0.245386,  -1.517539,  0.009734,   0.071373,   0.316536,   0.499826,   1.278084,
    -0.547816,  0.260808,   -0.013177,  -0.580264,  2.136308,   -0.257617,  -1.409528,  1.770101,
    0.325546,   -1.119040,  0.620350,   1.269782,   -0.896043,  0.135175,   -0.139040,  -1.163395,
    1.183720,   -0.015430,  0.536219,   -0.716429,  -0.655559,  0.314363,   0.106814,   1.848216,
    -0.275106,  2.212554,   1.508526,   -1.945079,  -1.680543,  -0.573534,  -0.185817,  0.008934,
    0.836950,   -0.722271,  -0.721490,  -0.201181,  -0.020464,  0.278890,   1.058295,   0.621673,
    -1.750615,  0.697348,   0.811486,   0.636345,   1.310080,   0.327098,   -0.672993,  -0.149327,
    -2.449018,  0.473286,   0.116946,   -0.591104,  -0.654708,  -1.080662,  -0.047731,  0.379345,
    -0.330361,  -0.499898,  -0.035979,  -0.174760,  -0.957265,  1.292548,   0.440910,   1.280941,
    -0.497730,  -1.118717,  0.807650,   0.041200,   -0.756209,  -0.089129,  -2.008850,  1.083918,
    -0.981191,  -0.688489,  1.339479,   -0.909243,  -0.412858,  -0.506163,  1.619748,   0.080901,
    -1.081056,  -1.124518,  1.735676,   1.937459,   1.635068,   -1.255940,  -0.213538,  -0.198932,
    0.307499,   -0.572325,  -0.977648,  -0.446809,  1.082092,   2.372648,   0.229288,   -0.266623,
    0.701672,   -0.487590,  1.862480,   1.106851,   -1.227566,  -0.669885,  1.340929,   0.388083,
    0.393059,   -1.707334,  0.227859,   0.685633,   -0.636790,  -1.002606,  -0.185621,  -1.054033,
    -0.071539,  0.279198,   1.373275,   0.179841,   -0.542017,  1.634191,   0.825215,   0.230761,
    0.671634,   -0.508078,  0.856352,   0.268503,   0.624975,   -1.047338,  1.535670,   0.434426,
    -1.917136,  0.469940,   1.274351,   0.638542,   1.380782,   1.319843,   -0.909429,  -2.305605,
    1.788730,   0.390798,   0.020324,   -0.405977,  -1.534895,  0.221373,   -1.374479,  -0.839286,
    -0.208643,  0.755913,   0.375734,   -1.345413,  1.481876,   0.032736,   1.870453,   -1.208991,
    -0.782632,  -0.767299,  -0.107200,  -0.977057,  -0.963988,  -2.379172,  -0.838188,  0.257346,
    -0.183834,  -0.167615,  -0.116989,  0.168488,   -0.501206,  -0.705076,  0.508165,   -0.420922,
    0.229133,   -0.959497,  -0.146043,  0.744538,   -0.890496,  0.139062,   -0.236144,  -0.075459,
    -0.358572,  -2.077635,  -0.143546,  1.393341,   0.651804,   -0.377134,  -0.661443,  0.248958,
    -0.383516,  -0.528480,  0.055388,   1.253769,   -2.520004,  0.584856,   -1.008064,  0.944285,
    -2.423957,  -0.223831,  0.058070,   -0.424614,  -0.202918,  -1.513077,  -1.126352,  -0.815002,
    0.366614,   -0.586107,  1.537409,   0.140072,   -1.862767,  -0.454193,  -0.652074,  0.103318,
    -0.220632,  -0.279043,  -0.733662,  -0.064534,  -1.444004,  0.612340,   -1.323503,  -0.661577,
    -0.146115,  0.248085,   -0.076633,  1.738170,   1.621972,   0.626436,   0.091814,   -0.807607,
    -0.461337,  -1.405969,  -0.374530,  -0.470911,  1.751296,   0.753225,   0.064989,   -0.292764,
    0.082823,   0.766191,   2.236850,   0.326887,   0.863304,   0.679387,   0.554758,   1.001630,
    1.259365,   0.044151,   -0.314138,  0.226708,   0.996692,   1.215912,   -0.542702,  0.912228,
    -0.172141,  -0.335955,  0.541487,   0.932111,   -0.570253,  -1.498605,  -0.050346,  0.553025,
    0.083498,   1.577524,   -0.330774,  0.795155,   -0.784800,  -1.263121,  0.666655,   -1.392632,
    -1.300562,  -0.605022,  -1.488565,  0.558543,   -0.277354,  -1.293685,  -0.888435,  -0.986520,
    -0.071618,  -2.414591,  -0.694349,  -1.391389,  0.329648,   0.598544,   0.147175,   -0.101439,
    -2.634981,  0.028053,   -0.876310,  -0.265477,  -0.327578,  -1.158247,  0.580053,   0.239756,
    -0.350885,  0.892098,   1.578299,   -1.108174,  -0.025931,  -1.110628,  0.750834,   0.500167,
    -0.517261,  -0.559209,  -0.753371,  0.925813,   -0.248520,  -0.149835,  -1.258415,  0.312620,
    2.690277,   0.289696,   -1.422803,  0.246786,   -1.435773,  0.148573,   -1.693073,  0.719188,
    1.141773,   1.551936,   1.383630,   -0.758092,  0.442663,   0.911098,   -1.074086,  0.201762,
    0.762863,   -1.288187,  -0.952962,  0.778175,   -0.006331,  0.524487,   1.364272,   0.482039,
    -0.787066,  0.751999,   -0.166888,  -0.816228,  2.094065,   0.080153,   -0.937295,  0.635739,
    1.682028,   0.593634,   0.790153,   0.105254,   -0.158579,  0.870907,   -0.194759,  0.075474,
    -0.526635,  -0.685484,  -0.268388,  -1.188346,  0.248579,   0.102452,   -0.041007,  -2.247582,
    -0.510776,  0.249243,   0.369197,   0.179197,   -0.037283,  -1.603310,  0.339372,   -0.131135,
    0.485190,   0.598751,   -0.086031,  0.325292,   -0.335143,  -0.322449,  -0.382374,  -0.953371,
    0.233576,   1.235245,   -0.578532,  -0.501537,  0.722864,   0.039498,   1.541279,   -1.701053,
    -1.033741,  -0.763708,  2.176426,   0.431612,   -0.443765,  0.029996,   -0.315671,  0.977846,
    0.018295,   0.817963,   0.702341,   -0.231271,  -0.113690,  0.127941,   -0.799410,  -0.238612,
    -0.089463,  -1.023264,  0.937538,   -1.131719,  -0.710702,  -1.169501,  1.065437,   -0.680394,
    -1.725773,  0.813200,   1.441867,   0.672272,   0.138665,   -0.859534,  -0.752251,  1.229615,
    1.150754,   -0.608025,  0.806158,   0.217133,   -0.373461,  -0.832030,  0.286866,   -1.818892,
    -1.573051,  2.015666,   -0.071982,  2.628909,   -0.243317,  0.173276,   0.923207,   -0.178553,
    -0.521705,  1.431962,   -0.870117,  0.807542,   -0.510635,  0.743514,   0.847898,   -0.829901,
    0.532994,   1.032848,   -1.052024,  0.362114,   -0.036787,  -1.227636,  -0.275099,  -0.160435,
    -1.083575,  -1.954213,  -0.909487,  -0.005579,  -1.723490,  1.263077,   -0.600433,  -2.063925,
    0.110911,   1.487614,   0.053002,   0.161981,   -0.026878,  0.173576,   0.882168,   0.182294,
    0.755295,   0.508035,   0.131880,   0.280104,   -0.982848,  -0.944087,  -0.013058,  0.354345,
    -0.894709,  0.812111,   0.109537,   2.731644,   0.411079,   -1.306862,  0.383806,   0.499504,
    -0.510786,  0.234922,   -0.597825,  0.020771,   0.419443,   1.191104,   0.771214,   -2.644222,
    0.285430,   0.826093,   -0.008122,  0.858438,   0.774788,   1.305945,   1.231503,   0.958564,
    -1.654548,  -0.990396,  0.685236,   -0.974870,  -0.606726,  0.686794,   0.020049,   1.063801,
    -1.341050,  0.479510,   -1.633974,  -1.442665,  0.293781,   -0.140364,  -1.130341,  -0.292538,
    -0.582536,  -0.896348,  0.248601,   -1.489663,  0.313509,   -2.025084,  0.528990,   0.343471,
    0.758193,   -0.691940,  0.680179,   -1.072541,  0.899772,   -2.123092,  0.284712,   -0.733323,
    -0.773376,  0.151842,   -0.336843,  0.970761,   -0.107236,  1.013492,   -0.475347,  0.068948,
    0.398592,   1.116326,   0.620451,   -0.287674,  -1.371773,  -0.685868,  0.331685,   -0.997722,
    0.291418,   1.107078,   0.244959,   0.164976,   0.406231,   1.215981,   1.448424,   -1.025137,
    0.205418,   0.588882,   -0.264024,  2.495318,   0.855948,   -0.850954,  0.811879,   0.700242,
    0.759938,   -1.712909,  1.537021,   -1.609847,  1.109526,   -1.109704,  0.385469,   0.965231,
    0.818297,   0.037049,   -0.926012,  -0.111919,  -0.803030,  -1.665006,  -0.901401,  0.588350,
    0.554159,   -0.415173,  0.061795,   0.457432,   0.199014,   0.257558,   2.080730,   -2.277237,
    0.339022,   0.289894,   0.662261,   -0.580860,  0.887752,   0.171871,   0.848821,   0.963769,
    1.321918,   -0.064345,  1.317053,   0.228017,   -1.429637,  -0.149701,  -0.504968,  -1.729141,
    -0.417472,  -0.614969,  0.720777,   0.339364,   0.882845,   0.284245,   -0.145541,  -0.089646,
    0.289161,   1.164831,   0.805729,   -1.355643,  0.120893,   -0.222178,  0.571732,   -0.300140,
    1.134277,   -0.179356,  -1.467067,  1.395346,   0.440836,   0.565384,   -0.693623,  0.833869,
    -2.237378,  1.097644,   -0.001617,  -1.614573,  -1.228727,  0.207405,   0.220942,   -1.006073,
    -0.453067,  1.399453,   -0.461964,  0.032716,   0.798783,   0.896816,   0.137892,   -1.619146,
    -1.646606,  0.428707,   -0.737231,  0.564926,   -1.384167,  0.460268,   0.629384,   0.379847,
    -1.013330,  -0.347243,  0.441912,   -1.590240,  -0.701417,  -1.077601,  1.002220,   1.729481,
    0.709032,   -0.747897,  0.228862,   -0.223497,  -0.853275,  0.345627,   0.109764,   -1.133039,
    -0.683124,  -0.277856,  0.654790,   -1.248394,  -0.597539,  -0.481813,  0.983372,   1.762121,
    1.427402,   0.911763,   0.326823,   0.069619,   -1.499763,  -0.418223,  -0.021037,  0.228425,
    -1.008196,  -0.664622,  0.558177,   -1.188542,  -0.775481,  0.271042,   1.534976,   -1.052283,
    0.625559,   -0.797626,  -0.313522,  -0.602210,  1.259060,   0.858484,   -2.105292,  -0.360937,
    0.553557,   -1.556384,  -0.206666,  -0.425568,  0.493778,   -0.870908,  0.079828,   -0.521619,
    -1.413861,  -0.384293,  -0.457922,  -0.291471,  -0.301224,  -1.588594,  1.094287,   1.324167,
    -0.126480,  -0.737164,  0.213719,   -0.400529,  0.064938,   -1.757996,  1.686748,   0.327400,
    0.715967,   1.598648,   -2.064741,  -0.743632,  0.176185,   0.527839,   -0.553153,  0.298280,
    -1.226607,  -0.189676,  -0.301713,  0.956956,   -0.533366,  -0.901082,  -0.892552,  0.278717,
    -0.745807,  1.603464,   0.574270,   0.320655,   -0.151383,  0.315762,   1.343703,   -2.237832,
    1.292906,   -0.378459,  0.002521,   0.884641,   0.582450,   -1.614244,  -1.503666,  0.573586,
    -0.910537,  -1.631277,  -0.359138,  -0.397616,  -1.161307,  -1.109838,  0.290672,   -1.910239,
    1.314768,   0.665319,   -0.275115,  -0.023022,  -0.907976,  -1.043657,  0.373516,   0.901532,
    1.278539,   -0.128456,  0.612821,   1.956518,   2.266326,   -0.373959,  2.238039,   -0.159580,
    -0.703281,  0.563477,   -0.050296,  1.163593,   0.658808,   -1.550089,  -3.029118,  0.540578,
    -1.008998,  0.908047,   1.582303,   -0.979088,  1.007902,   0.158491,   -0.586927,  1.574082,
    -0.516649,  1.227800,   1.583876,   -2.088950,  2.949545,   1.356125,   1.050068,   -0.767170,
    -0.257653,  -1.371845,  -1.267656,  -0.894948,  0.589089,   1.842629,   1.347967,   -0.491253,
    -2.177568,  0.237000,   -0.735411,  -1.779419,  0.448030,   0.581214,   0.856607,   -0.266263,
    -0.417470,  -0.205806,  -0.174323,  0.217577,   1.684295,   0.119528,   0.650667,   2.080061,
    -0.339225,  0.730113,   0.293969,   -0.849109,  -2.533858,  -2.378941,  -0.346276,  -0.610937,
    -0.408192,  -1.415611,  0.227122,   0.207974,   -0.719718,  0.757762,   -1.643135,  -1.056813,
    -0.251662,  -1.298441,  1.233255,   1.494625,   0.235938,   -1.404359,  0.658791,   -2.556613,
    -0.534945,  3.202525,   0.439198,   -1.149901,  0.886765,   -0.283386,  1.035336,   -0.364878,
    1.341987,   1.008872,   0.213874,   -0.299264,  0.255849,   -0.190826,  -0.079060,  0.699851,
    -0.796540,  -0.801284,  -0.007599,  -0.726810,  -1.490902,  0.870335,   -0.265675,  -1.566695,
    -0.394636,  -0.143855,  -2.334247,  -1.357539,  -1.815689,  1.108422,   -0.142115,  1.112757,
    0.559264,   0.478370,   -0.679385,  0.284967,   -1.332935,  -0.723980,  -0.663600,  0.198443,
    -1.794868,  -1.387673,  0.197768,   1.469328,   0.366493,   -0.442775,  -0.048563,  0.077709,
    1.957910,   -0.072848,  0.938810,   -0.079608,  -0.800959,  0.309424,   1.051826,   -1.664211,
    -1.090792,  -0.191731,  0.463401,   -0.924147,  -0.649657,  0.622893,   -1.335107,  1.047689,
    0.863327,   -0.642411,  0.660010,   1.294116,   0.314579,   0.859573,   0.128670,   0.016568,
    -0.072801,  -0.994310,  -0.747358,  -0.030814,  0.988355,   -0.599017,  1.476644,   -0.813801,
    0.645040,   -1.309919,  -0.867425,  -0.474233,  0.222417,   1.871323,   0.110001,   -0.411341,
    0.511242,   -1.199117,  -0.096361,  0.445817,   -0.295825,  -0.167996,  0.179543,   0.421118,
    1.677678,   1.996949,   0.696964,   -1.366382,  0.363045,   -0.567044,  -1.044154,  0.697139,
    0.484026,   -0.193751,  -0.378095,  -0.886374,  -1.840197,  -1.628195,  -1.173789,  -0.415411,
    0.175088,   0.229433,   -1.240889,  0.700004,   0.426877,   1.454803,   -0.510186,  -0.006657,
    -0.525496,  0.717698,   1.088374,   0.500552,   2.771790,   -0.160309,  0.429489,   -1.966817,
    -0.546019,  -1.888395,  -0.107952,  -1.316144,  -0.672632,  -0.902365,  -0.154798,  0.947242,
    1.550375,   0.429040,   -0.560795,  0.179304,   -0.771509,  -0.943390,  -1.407569,  -1.906131,
    -0.065293,  0.672149,   0.206147,   -0.008124,  0.020042,   -0.558447,  1.886079,   -0.219975,
    -1.414395,  -0.302811,  -0.569574,  -0.121495,  -0.390171,  -0.844287,  -1.737757,  -0.449520,
    -1.547933,  -0.095776,  0.907714,   2.369602,   0.519768,   0.410525,   1.052585,   0.428784,
    1.295088,   -0.186053,  0.130733,   -0.657627,  -0.759267,  -0.595170,  0.812400,   0.069541,
    -1.833687,  1.827363,   0.654075,   -1.544769,  -0.375109,  0.207688,   -0.765615,  -0.106355,
    0.338769,   1.033461,   -1.404822,  -1.030570,  -0.643372,  0.170787,   1.344839,   1.936273,
    0.741336,   0.811980,   -0.142808,  -0.099858,  -0.800131,  0.493249,   1.237574,   1.295951,
    -0.278196,  0.217127,   0.630728,   -0.548549,  0.229632,   0.355311,   0.521284,   -0.615971,
    1.345803,   0.974922,   -2.377934,  -1.092319,  -0.325710,  -2.012228,  1.567660,   0.233337,
    0.646420,   -1.129412,  0.197038,   1.696870,   0.726034,   0.792526,   0.603357,   -0.058405,
    -1.108666,  2.144229,   -1.352821,  0.457021,   0.391175,   2.073013,   -0.323318,  1.468132,
    -0.502399,  0.209593,   0.754800,   -0.948189,  0.613157,   1.760503,   0.088762,   2.595570,
    -0.675470,  2.786804,   -0.016827,  0.271651,   -0.914102,  -1.951371,  -0.317418,  0.588333,
    0.828996,   -1.674851,  -1.922293,  -0.436662,  0.044974,   2.416609,   -0.309892,  0.187583,
    0.947699,   -0.525703,  -1.115605,  -1.592320,  1.174844,   0.485144,   1.645480,   -0.454233,
    1.008768,   2.049403,   0.602020,   0.017860,   -1.610426,  1.238752,   0.683587,   -0.780716,
    0.530979,   2.134498,   0.354361,   0.231700,   1.287980,   -0.013488,  -1.333345,  -0.556343,
    0.755597,   -0.911854,  1.371684,   0.245580,   0.118845,   0.384690,   -0.070152,  -0.578309,
    0.469308,   1.299687,   1.634798,   -0.702809,  0.807253,   -1.027451,  1.294496,   0.014930,
    0.218705,   1.713188,   -2.078805,  0.112917,   -1.086491,  -1.558311,  0.637406,   -0.404576,
    -0.403325,  0.084076,   -0.435349,  -0.562623,  0.878062,   -0.814650,  -0.258363,  0.493299,
    -0.802694,  -0.008329,  0.627571,   0.154382,   2.580735,   -1.306246,  1.023526,   0.777795,
    -0.833884,  -0.586663,  0.065664,   -0.012342,  -0.076987,  -1.558587,  1.702607,   -0.468984,
    0.094619,   0.287071,   0.919354,   0.510136,   0.245440,   -1.400519,  0.969571,   1.593698,
    -1.437917,  -1.534230,  -0.074710,  0.081459,   -0.843240,  -0.564640,  -0.028207,  -1.243702,
    0.733039,   0.059580,   0.149144,   1.595857,   -0.777250,  1.550277,   1.055002,   -0.166654,
    0.314484,   1.419571,   0.327348,   0.475653,   0.398754,   -0.072770,  1.314784,   0.978279,
    1.722114,   -0.412302,  0.565133,   0.739851,   0.220138,   1.312807,   0.629152,   -1.107987,
    -0.447001,  -0.725993,  0.354045,   -0.506772,  -2.103747,  -0.664684,  1.450110,   -0.329805,
    2.701872,   -1.634939,  -0.536325,  0.547223,   1.492603,   -0.455243,  -0.496416,  1.235260,
    0.040926,   0.748467,   1.230764,   0.304903,   1.077771,   0.765151,   -1.319580,  -0.509191,
    0.555116,   -1.957625,  -0.760453,  -2.443886,  -0.659366,  -0.114779,  0.300079,   -0.583996,
    -3.073745,  1.551042,   -0.407369,  1.428095,   -1.353242,  0.903970,   0.541671,   -0.465020
};



/* ----------------------------------------------------------------------
** Coefficients for 32-tap filter for Floating point LMS FIR filter
*  FIR high pass filter with cutoff freq 9.6kHz (transition 9.6KHz to 11.52KHz)
** ------------------------------------------------------------------- */
float32_t lmsNormCoeff_f32[32] =
{
    -0.004240,  0.002301,   0.008860,   -0.000000,  -0.019782,  -0.010543,  0.032881,   0.034736,
    -0.037374,  -0.069586,  0.022397,   0.102169,   0.014185,   -0.115908,  -0.061648,  0.101018,
    0.101018,   -0.061648,  -0.115908,  0.014185,   0.102169,   0.022397,   -0.069586,  -0.037374,
    0.034736,   0.032881,   -0.010543,  -0.019782,  -0.000000,  0.008860,   0.002301,   -0.004240

};

/* ----------------------------------------------------------------------
** Coefficients for 32-tap filter for Floating point FIR filter
*  FIR low pass filter with cutoff freq 24Hz (transition 24Hz to 240Hz)
** ------------------------------------------------------------------- */
const float32_t FIRCoeff_f32[32] =
{
    0.004502,   0.005074,   0.006707,   0.009356,   0.012933,   0.017303,   0.022298,   0.027717,
    0.033338,   0.038930,   0.044258,   0.049098,   0.053243,   0.056519,   0.058784,   0.059941,
    0.059941,   0.058784,   0.056519,   0.053243,   0.049098,   0.044258,   0.038930,   0.033338,
    0.027717,   0.022298,   0.017303,   0.012933,   0.009356,   0.006707,   0.005074,   0.004502

};

