"use strict";

const x = require("./build/Release/sweph.node");
x.constants = {};

x.constants.SE_AUNIT_TO_KM = 149597870.700;
x.constants.SE_AUNIT_TO_LIGHTYEAR = 1 / 63241.07708427;
x.constants.SE_AUNIT_TO_PARSEC = 1 / 206264.8062471;

x.constants.SE_JUL_CAL = 0;
x.constants.SE_GREG_CAL = 1;

x.constants.SE_ECL_NUT = -1;

x.constants.SE_SUN = 0;
x.constants.SE_MOON = 1;
x.constants.SE_MERCURY = 2;
x.constants.SE_VENUS = 3;
x.constants.SE_MARS = 4;
x.constants.SE_JUPITER = 5;
x.constants.SE_SATURN = 6;
x.constants.SE_URANUS = 7;
x.constants.SE_NEPTUNE = 8;
x.constants.SE_PLUTO = 9;
x.constants.SE_MEAN_NODE = 10;
x.constants.SE_TRUE_NODE = 11;
x.constants.SE_MEAN_APOG = 12;
x.constants.SE_OSCU_APOG = 13;
x.constants.SE_EARTH = 14;
x.constants.SE_CHIRON = 15;
x.constants.SE_PHOLUS = 16;
x.constants.SE_CERES = 17;
x.constants.SE_PALLAS = 18;
x.constants.SE_JUNO = 19;
x.constants.SE_VESTA = 20;
x.constants.SE_INTP_APOG = 21;
x.constants.SE_INTP_PERG = 22;

x.constants.SE_NPLANETS = 23;

x.constants.SE_PLMOON_OFFSET = 9000;
x.constants.SE_AST_OFFSET = 10000;
x.constants.SE_VARUNA = x.constants.SE_AST_OFFSET + 20000;

x.constants.SE_FICT_OFFSET = 40;
x.constants.SE_FICT_OFFSET_1 = 39;
x.constants.SE_FICT_MAX = 999;
x.constants.SE_NFICT_ELEM = 15;

x.constants.SE_COMET_OFFSET = 1000;

x.constants.SE_NALL_NAT_POINTS = x.constants.SE_NPLANETS + x.constants.SE_NFICT_ELEM;

x.constants.SE_CUPIDO = 40;
x.constants.SE_HADES = 41;
x.constants.SE_ZEUS = 42;
x.constants.SE_KRONOS = 43;
x.constants.SE_APOLLON = 44;
x.constants.SE_ADMETOS = 45;
x.constants.SE_VULKANUS = 46;
x.constants.SE_POSEIDON = 47;
x.constants.SE_ISIS = 48;
x.constants.SE_NIBIRU = 49;
x.constants.SE_HARRINGTON = 50;
x.constants.SE_NEPTUNE_LEVERRIER = 51;
x.constants.SE_NEPTUNE_ADAMS = 52;
x.constants.SE_PLUTO_LOWELL = 53;
x.constants.SE_PLUTO_PICKERING = 54;
x.constants.SE_VULCAN = 55;
x.constants.SE_WHITE_MOON = 56;
x.constants.SE_PROSERPINA = 57;
x.constants.SE_WALDEMATH = 58;

x.constants.SE_FIXSTAR = -10;

x.constants.SE_ASC = 0;
x.constants.SE_MC = 1;
x.constants.SE_ARMC = 2;
x.constants.SE_VERTEX = 3;
x.constants.SE_EQUASC = 4;
x.constants.SE_COASC1 = 5;
x.constants.SE_COASC2 = 6;
x.constants.SE_POLASC = 7;
x.constants.SE_NASCMC = 8;

x.constants.SEFLG_JPLEPH = 1;
x.constants.SEFLG_SWIEPH = 2;
x.constants.SEFLG_MOSEPH = 4;

x.constants.SEFLG_HELCTR = 8;
x.constants.SEFLG_TRUEPOS = 16;
x.constants.SEFLG_J2000 = 32;
x.constants.SEFLG_NONUT = 64;
x.constants.SEFLG_SPEED3 = 128;
x.constants.SEFLG_SPEED = 256;
x.constants.SEFLG_NOGDEFL = 512;
x.constants.SEFLG_NOABERR = 1024;
x.constants.SEFLG_ASTROMETRIC = x.constants.SEFLG_NOABERR | x.constants.SEFLG_NOGDEFL;
x.constants.SEFLG_EQUATORIAL = 2 * 1024;
x.constants.SEFLG_XYZ = 4 * 1024;
x.constants.SEFLG_RADIANS = 8 * 1024;
x.constants.SEFLG_BARYCTR = 16 * 1024;
x.constants.SEFLG_TOPOCTR = 32 * 1024;
x.constants.SEFLG_ORBEL_AA = x.constants.SEFLG_TOPOCTR;
x.constants.SEFLG_TROPICAL = 0;
x.constants.SEFLG_SIDEREAL = 64 * 1024;
x.constants.SEFLG_ICRS = 128 * 1024;
x.constants.SEFLG_DPSIDEPS_1980 = 256 * 1024;
x.constants.SEFLG_JPLHOR = x.constants.SEFLG_DPSIDEPS_1980;
x.constants.SEFLG_JPLHOR_APPROX = 512 * 1024;
x.constants.SEFLG_CENTER_BODY = 1024 * 1024;
x.constants.SEFLG_TEST_PLMOON = 2 * 1024 * 1024 | x.constants.SEFLG_J2000 | x.constants.SEFLG_ICRS | x.constants.SEFLG_HELCTR | x.constants.SEFLG_TRUEPOS;

x.constants.SE_SIDBITS = 256;
x.constants.SE_SIDBIT_ECL_T0 = 256;
x.constants.SE_SIDBIT_SSY_PLANE = 512;
x.constants.SE_SIDBIT_USER_UT = 1024;
x.constants.SE_SIDBIT_ECL_DATE = 2048;
x.constants.SE_SIDBIT_NO_PREC_OFFSET = 4096;
x.constants.SE_SIDBIT_PREC_ORIG = 8192;

x.constants.SE_SIDM_FAGAN_BRADLEY = 0;
x.constants.SE_SIDM_LAHIRI = 1;
x.constants.SE_SIDM_DELUCE = 2;
x.constants.SE_SIDM_RAMAN = 3;
x.constants.SE_SIDM_USHASHASHI = 4;
x.constants.SE_SIDM_KRISHNAMURTI = 5;
x.constants.SE_SIDM_DJWHAL_KHUL = 6;
x.constants.SE_SIDM_YUKTESHWAR = 7;
x.constants.SE_SIDM_JN_BHASIN = 8;
x.constants.SE_SIDM_BABYL_KUGLER1 = 9;
x.constants.SE_SIDM_BABYL_KUGLER2 = 10;
x.constants.SE_SIDM_BABYL_KUGLER3 = 11;
x.constants.SE_SIDM_BABYL_HUBER = 12;
x.constants.SE_SIDM_BABYL_ETPSC = 13;
x.constants.SE_SIDM_ALDEBARAN_15TAU = 14;
x.constants.SE_SIDM_HIPPARCHOS = 15;
x.constants.SE_SIDM_SASSANIAN = 16;
x.constants.SE_SIDM_GALCENT_0SAG = 17;
x.constants.SE_SIDM_J2000 = 18;
x.constants.SE_SIDM_J1900 = 19;
x.constants.SE_SIDM_B1950 = 20;
x.constants.SE_SIDM_SURYASIDDHANTA = 21;
x.constants.SE_SIDM_SURYASIDDHANTA_MSUN = 22;
x.constants.SE_SIDM_ARYABHATA = 23;
x.constants.SE_SIDM_ARYABHATA_MSUN = 24;
x.constants.SE_SIDM_SS_REVATI = 25;
x.constants.SE_SIDM_SS_CITRA = 26;
x.constants.SE_SIDM_TRUE_CITRA = 27;
x.constants.SE_SIDM_TRUE_REVATI = 28;
x.constants.SE_SIDM_TRUE_PUSHYA = 29;
x.constants.SE_SIDM_GALCENT_RGILBRAND = 30;
x.constants.SE_SIDM_GALEQU_IAU1958 = 31;
x.constants.SE_SIDM_GALEQU_TRUE = 32;
x.constants.SE_SIDM_GALEQU_MULA = 33;
x.constants.SE_SIDM_GALALIGN_MARDYKS = 34;
x.constants.SE_SIDM_TRUE_MULA = 35;
x.constants.SE_SIDM_GALCENT_MULA_WILHELM = 36;
x.constants.SE_SIDM_ARYABHATA_522 = 37;
x.constants.SE_SIDM_BABYL_BRITTON = 38;
x.constants.SE_SIDM_TRUE_SHEORAN = 39;
x.constants.SE_SIDM_GALCENT_COCHRANE = 40;
x.constants.SE_SIDM_GALEQU_FIORENZA = 41;
x.constants.SE_SIDM_VALENS_MOON = 42;
x.constants.SE_SIDM_LAHIRI_1940 = 43;
x.constants.SE_SIDM_LAHIRI_VP285 = 44;
x.constants.SE_SIDM_KRISHNAMURTI_VP291 = 45;
x.constants.SE_SIDM_LAHIRI_ICRC = 46;
x.constants.SE_SIDM_USER = 255;

x.constants.SE_NSIDM_PREDEF = 47;

x.constants.SE_NODBIT_MEAN = 1;
x.constants.SE_NODBIT_OSCU = 2;
x.constants.SE_NODBIT_OSCU_BAR = 4;
x.constants.SE_NODBIT_FOPOINT = 256;

x.constants.SEFLG_DEFAULTEPH = x.constants.SEFLG_SWIEPH;

x.constants.SE_MAX_STNAME = 256;

x.constants.SE_ECL_CENTRAL = 1;
x.constants.SE_ECL_NONCENTRAL = 2;
x.constants.SE_ECL_TOTAL = 4;
x.constants.SE_ECL_ANNULAR = 8;
x.constants.SE_ECL_PARTIAL = 16;
x.constants.SE_ECL_ANNULAR_TOTAL = 32;
x.constants.SE_ECL_HYBRID = 32;
x.constants.SE_ECL_PENUMBRAL = 64;
x.constants.SE_ECL_ALLTYPES_SOLAR = x.constants.SE_ECL_CENTRAL | x.constants.SE_ECL_NONCENTRAL | x.constants.SE_ECL_TOTAL | x.constants.SE_ECL_ANNULAR | x.constants.SE_ECL_PARTIAL | x.constants.SE_ECL_ANNULAR_TOTAL;
x.constants.SE_ECL_ALLTYPES_LUNAR = x.constants.SE_ECL_TOTAL | x.constants.SE_ECL_PARTIAL | x.constants.SE_ECL_PENUMBRAL;
x.constants.SE_ECL_VISIBLE = 128;
x.constants.SE_ECL_MAX_VISIBLE = 256;
x.constants.SE_ECL_1ST_VISIBLE = 512;
x.constants.SE_ECL_PARTBEG_VISIBLE = 512;
x.constants.SE_ECL_2ND_VISIBLE = 1024;
x.constants.SE_ECL_TOTBEG_VISIBLE = 1024;
x.constants.SE_ECL_3RD_VISIBLE = 2048;
x.constants.SE_ECL_TOTEND_VISIBLE = 2048;
x.constants.SE_ECL_4TH_VISIBLE = 4096;
x.constants.SE_ECL_PARTEND_VISIBLE = 4096;
x.constants.SE_ECL_PENUMBBEG_VISIBLE = 8192;
x.constants.SE_ECL_PENUMBEND_VISIBLE = 16384;
x.constants.SE_ECL_OCC_BEG_DAYLIGHT = 8192;
x.constants.SE_ECL_OCC_END_DAYLIGHT = 16384;
x.constants.SE_ECL_ONE_TRY = 32 * 1024;

x.constants.SE_CALC_RISE = 1;
x.constants.SE_CALC_SET = 2;
x.constants.SE_CALC_MTRANSIT = 4;
x.constants.SE_CALC_ITRANSIT = 8;
x.constants.SE_BIT_DISC_CENTER = 256;
x.constants.SE_BIT_DISC_BOTTOM = 8192;
x.constants.SE_BIT_GEOCTR_NO_ECL_LAT = 128;
x.constants.SE_BIT_NO_REFRACTION = 512;
x.constants.SE_BIT_CIVIL_TWILIGHT = 1024;
x.constants.SE_BIT_NAUTIC_TWILIGHT = 2048;
x.constants.SE_BIT_ASTRO_TWILIGHT = 4096;
x.constants.SE_BIT_FIXED_DISC_SIZE = 16384;
x.constants.SE_BIT_FORCE_SLOW_METHOD = 32768;
x.constants.SE_BIT_HINDU_RISING = x.constants.SE_BIT_DISC_CENTER | x.constants.SE_BIT_NO_REFRACTION | x.constants.SE_BIT_GEOCTR_NO_ECL_LAT;

x.constants.SE_ECL2HOR = 0;
x.constants.SE_EQU2HOR = 1;
x.constants.SE_HOR2ECL = 0;
x.constants.SE_HOR2EQU = 1;

x.constants.SE_TRUE_TO_APP = 0;
x.constants.SE_APP_TO_TRUE = 1;

x.constants.SE_DE_NUMBER = 431;
x.constants.SE_FNAME_DE200 = "de200.eph";
x.constants.SE_FNAME_DE403 = "de403.eph";
x.constants.SE_FNAME_DE404 = "de404.eph";
x.constants.SE_FNAME_DE405 = "de405.eph";
x.constants.SE_FNAME_DE406 = "de406.eph";
x.constants.SE_FNAME_DE431 = "de431.eph";
x.constants.SE_FNAME_DFT = x.constants.SE_FNAME_DE431;
x.constants.SE_FNAME_DFT2 = x.constants.SE_FNAME_DE406;
x.constants.SE_STARFILE_OLD = "fixstars.cat";
x.constants.SE_STARFILE = "sefstars.txt";
x.constants.SE_ASTNAMFILE = "seasnam.txt";
x.constants.SE_FICTFILE = "seorbel.txt";

x.constants.SE_SPLIT_DEG_ROUND_SEC = 1;
x.constants.SE_SPLIT_DEG_ROUND_MIN = 2;
x.constants.SE_SPLIT_DEG_ROUND_DEG = 4;
x.constants.SE_SPLIT_DEG_ZODIACAL = 8;
x.constants.SE_SPLIT_DEG_NAKSHATRA = 1024;
x.constants.SE_SPLIT_DEG_KEEP_SIGN = 16;
x.constants.SE_SPLIT_DEG_KEEP_DEG = 32;

x.constants.SE_HELIACAL_RISING = 1;
x.constants.SE_HELIACAL_SETTING = 2;
x.constants.SE_MORNING_FIRST = x.constants.SE_HELIACAL_RISING;
x.constants.SE_EVENING_LAST = x.constants.SE_HELIACAL_SETTING;
x.constants.SE_EVENING_FIRST = 3;
x.constants.SE_MORNING_LAST = 4;
x.constants.SE_ACRONYCHAL_RISING = 5;
x.constants.SE_ACRONYCHAL_SETTING = 6;
x.constants.SE_COSMICAL_SETTING = x.constants.SE_ACRONYCHAL_SETTING;

x.constants.SE_HELFLAG_LONG_SEARCH = 128;
x.constants.SE_HELFLAG_HIGH_PRECISION = 256;
x.constants.SE_HELFLAG_OPTICAL_PARAMS = 512;
x.constants.SE_HELFLAG_NO_DETAILS = 1024;
x.constants.SE_HELFLAG_SEARCH_1_PERIOD = 1 << 11;
x.constants.SE_HELFLAG_VISLIM_DARK = 1 << 12;
x.constants.SE_HELFLAG_VISLIM_NOMOON = 1 << 13;
x.constants.SE_HELFLAG_VISLIM_PHOTOPIC = 1 << 14;
x.constants.SE_HELFLAG_VISLIM_SCOTOPIC = 1 << 15;
x.constants.SE_HELFLAG_AV = 1 << 16;
x.constants.SE_HELFLAG_AVKIND_VR = 1 << 16;
x.constants.SE_HELFLAG_AVKIND_PTO = 1 << 17;
x.constants.SE_HELFLAG_AVKIND_MIN7 = 1 << 18;
x.constants.SE_HELFLAG_AVKIND_MIN9 = 1 << 19;
x.constants.SE_HELFLAG_AVKIND = x.constants.SE_HELFLAG_AVKIND_VR | x.constants.SE_HELFLAG_AVKIND_PTO | x.constants.SE_HELFLAG_AVKIND_MIN7 | x.constants.SE_HELFLAG_AVKIND_MIN9;
x.constants.TJD_INVALID = 99999999.0;
x.constants.SIMULATE_VICTORVB = 1;

x.constants.SE_PHOTOPIC_FLAG = 0;
x.constants.SE_SCOTOPIC_FLAG = 1;
x.constants.SE_MIXEDOPIC_FLAG = 2;

x.constants.SE_TIDAL_DE200 = -23.8946;
x.constants.SE_TIDAL_DE403 = -25.580;
x.constants.SE_TIDAL_DE404 = -25.580;
x.constants.SE_TIDAL_DE405 = -25.826;
x.constants.SE_TIDAL_DE406 = -25.826;
x.constants.SE_TIDAL_DE421 = -25.85;
x.constants.SE_TIDAL_DE422 = -25.85;
x.constants.SE_TIDAL_DE430 = -25.82;
x.constants.SE_TIDAL_DE431 = -25.80;
x.constants.SE_TIDAL_26 = -26.0;
x.constants.SE_TIDAL_STEPHENSON_2016 = -25.85;
x.constants.SE_TIDAL_DEFAULT = x.constants.SE_TIDAL_DE431;
x.constants.SE_TIDAL_AUTOMATIC = 999999;
x.constants.SE_TIDAL_MOSEPH = x.constants.SE_TIDAL_DE404;
x.constants.SE_TIDAL_SWIEPH = x.constants.SE_TIDAL_DEFAULT;
x.constants.SE_TIDAL_JPLEPH = x.constants.SE_TIDAL_DEFAULT;

x.constants.SE_DELTAT_AUTOMATIC = -1E-10;

x.constants.SE_MODEL_DELTAT = 0;
x.constants.SE_MODEL_PREC_LONGTERM = 1;
x.constants.SE_MODEL_PREC_SHORTTERM = 2;
x.constants.SE_MODEL_NUT = 3;
x.constants.SE_MODEL_BIAS = 4;
x.constants.SE_MODEL_JPLHOR_MODE = 5;
x.constants.SE_MODEL_JPLHORA_MODE = 6;
x.constants.SE_MODEL_SIDT = 7;
x.constants.NSE_MODELS = 8;

x.constants.SEMOD_NPREC = 11;
x.constants.SEMOD_PREC_IAU_1976 = 1;
x.constants.SEMOD_PREC_LASKAR_1986 = 2;
x.constants.SEMOD_PREC_WILL_EPS_LASK = 3;
x.constants.SEMOD_PREC_WILLIAMS_1994 = 4;
x.constants.SEMOD_PREC_SIMON_1994 = 5;
x.constants.SEMOD_PREC_IAU_2000 = 6;
x.constants.SEMOD_PREC_BRETAGNON_2003 = 7;
x.constants.SEMOD_PREC_IAU_2006 = 8;
x.constants.SEMOD_PREC_VONDRAK_2011 = 9;
x.constants.SEMOD_PREC_OWEN_1990 = 10;
x.constants.SEMOD_PREC_NEWCOMB = 11;
x.constants.SEMOD_PREC_DEFAULT = x.constants.SEMOD_PREC_VONDRAK_2011;
x.constants.SEMOD_PREC_DEFAULT_SHORT = x.constants.SEMOD_PREC_VONDRAK_2011;

x.constants.SEMOD_NNUT = 5;
x.constants.SEMOD_NUT_IAU_1980 = 1;
x.constants.SEMOD_NUT_IAU_CORR_1987 = 2;
x.constants.SEMOD_NUT_IAU_2000A = 3;
x.constants.SEMOD_NUT_IAU_2000B = 4;
x.constants.SEMOD_NUT_WOOLARD = 5;
x.constants.SEMOD_NUT_DEFAULT = x.constants.SEMOD_NUT_IAU_2000B;

x.constants.SEMOD_NSIDT = 4;
x.constants.SEMOD_SIDT_IAU_1976 = 1;
x.constants.SEMOD_SIDT_IAU_2006 = 2;
x.constants.SEMOD_SIDT_IERS_CONV_2010 = 3;
x.constants.SEMOD_SIDT_LONGTERM = 4;
x.constants.SEMOD_SIDT_DEFAULT = x.constants.SEMOD_SIDT_LONGTERM;

x.constants.SEMOD_NBIAS = 3;
x.constants.SEMOD_BIAS_NONE = 1;
x.constants.SEMOD_BIAS_IAU2000 = 2;
x.constants.SEMOD_BIAS_IAU2006 = 3;
x.constants.SEMOD_BIAS_DEFAULT = x.constants.SEMOD_BIAS_IAU2006;

x.constants.SEMOD_NJPLHOR = 2;
x.constants.SEMOD_JPLHOR_LONG_AGREEMENT = 1;
x.constants.SEMOD_JPLHOR_DEFAULT = x.constants.SEMOD_JPLHOR_LONG_AGREEMENT;

x.constants.SEMOD_NJPLHORA = 3;
x.constants.SEMOD_JPLHORA_1 = 1;
x.constants.SEMOD_JPLHORA_2 = 2;
x.constants.SEMOD_JPLHORA_3 = 3;
x.constants.SEMOD_JPLHORA_DEFAULT = x.constants.SEMOD_JPLHORA_3;

x.constants.SEMOD_NDELTAT = 5;
x.constants.SEMOD_DELTAT_STEPHENSON_MORRISON_1984 = 1;
x.constants.SEMOD_DELTAT_STEPHENSON_1997 = 2;
x.constants.SEMOD_DELTAT_STEPHENSON_MORRISON_2004 = 3;
x.constants.SEMOD_DELTAT_ESPENAK_MEEUS_2006 = 4;
x.constants.SEMOD_DELTAT_STEPHENSON_ETC_2016 = 5;
x.constants.SEMOD_DELTAT_DEFAULT = x.constants.SEMOD_DELTAT_STEPHENSON_ETC_2016;

module.exports = x;
