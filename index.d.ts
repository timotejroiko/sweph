/**
 * ## Sweph
 * Definitive Swiss Ephemeris bindings for Node.js  
 * 
 * [Official documentation for the Swiss Ephemeris](https://www.astro.com/swisseph/swephprg.htm)  
 * [Sweph on Github](https://github.com/timotejroiko/sweph)  
 * [Sweph on NPM](http://npm.com/package/sweph)  
 * 
 * ### Usage Example
 * ```js
 * const { utc_to_jd, calc, houses_ex2, constants, set_ephe_path } = require("sweph");
 * // or - import { utc_to_jd, calc, houses, constants, set_ephe_path } from "sweph";
 * 
 * set_ephe_path("./ephemeris"); // folder containing your ephemeris files;
 * 
 * const date = utc_to_jd(2020, 1, 25, 15, 35, 0, constants.SE_GREG_CAL);
 * if(date.flag === constants.ERR) { throw new Error(date.error); }
 * 
 * const [ jd_et, jd_ut ] = date.data;
 * const flags = constants.SEFLG_SWIEPH | constants.SEFLG_SPEED;
 * const planets = calc(jd_et, constants.SE_SUN, flags);
 * if(planets.flag !== flags) { console.log(planets.error); }
 * 
 * const houses = houses_ex2(jd_ut, 0, 37, 54, "P");
 * if(houses.flag === constants.ERR) { console.log(houses.error) }
 * 
 * console.log(planets.data, houses.data)
 * ```
 */
declare module "sweph" {
	
	/**
	 * Reset swisseph state and cleanup file handles
	 * ```js
	 * sweph.close();
	 * ```
	 */
	export function close(): void;

	/**
	 * Set user-defined delta T
	 * @param t_acc Delta T value
	 */
	export function set_delta_t_userdef(t_acc: number): void;

	/**
	 * Set ephemeris files location
	 * @param path Path to ephemeris files
	 */
	export function set_ephe_path(path: string): void;

	/**
	 * Set JPL file location
	 * @param file Path to JPL file
	 */
	export function set_jpl_file(file: string): void;

	/**
	 * Set ayanamsa for sidereal mode
	 * @param sid_mode Ayanamsa ID
	 * @param t0 Reference date for custom ayanamsas
	 * @param ayan_t0 Initial value for custom ayanamsas
	 */
	export function set_sid_mode(sid_mode: number, t0: number, ayan_t0: number): void;

	/**
	 * Set user-defined tidal acceleration
	 * @param t_acc tidal acceleration value
	 */
	export function set_tid_acc(t_acc: number): void;

	/**
	 * Set geographic coordinates for topocentric mode
	 * @param geolon Geographic longitude
	 * @param geolat Geographic latitude
	 * @param elevation Elevation
	 */
	export function set_topo(geolon: number, geolat: number, elevation: number): void;

	/**
	 * Get swisseph version
	 */
	export function version(): string;

	/**
	 * Get library path
	 */
	export function get_library_path(): string;

	/**
	 * Get tidal acceleration value
	 */
	export function get_tid_acc(): number;

	/**
	 * Get the name of a planet or object
	 * @param ipl Object ID
	 */
	export function get_planet_name(ipl: number): string;

	/**
	 * Swisseph Constants
	 */
	export namespace constants {
		const OK = 0;
		const ERR = -1;
		const SE_AUNIT_TO_KM = 149597870.7;
		const SE_AUNIT_TO_LIGHTYEAR = 0.000015812507409819728;
		const SE_AUNIT_TO_PARSEC = 0.000004848136811095274;   
		const SE_JUL_CAL = 0;
		const SE_GREG_CAL = 1;
		const SE_ECL_NUT = -1;
		const SE_SUN = 0;
		const SE_MOON = 1;
		const SE_MERCURY = 2;
		const SE_VENUS = 3;
		const SE_MARS = 4;
		const SE_JUPITER = 5;
		const SE_SATURN = 6;
		const SE_URANUS = 7;
		const SE_NEPTUNE = 8;
		const SE_PLUTO = 9;
		const SE_MEAN_NODE = 10;
		const SE_TRUE_NODE = 11;
		const SE_MEAN_APOG = 12;
		const SE_OSCU_APOG = 13;
		const SE_EARTH = 14;
		const SE_CHIRON = 15;
		const SE_PHOLUS = 16;
		const SE_CERES = 17;
		const SE_PALLAS = 18;
		const SE_JUNO = 19;
		const SE_VESTA = 20;
		const SE_INTP_APOG = 21;
		const SE_INTP_PERG = 22;
		const SE_NPLANETS = 23;
		const SE_PLMOON_OFFSET = 9000;
		const SE_AST_OFFSET = 10000;
		const SE_VARUNA = 30000;
		const SE_FICT_OFFSET = 40;
		const SE_FICT_OFFSET_1 = 39;
		const SE_FICT_MAX = 999;
		const SE_NFICT_ELEM = 15;
		const SE_COMET_OFFSET = 1000;
		const SE_NALL_NAT_POINTS = 38;
		const SE_CUPIDO = 40;
		const SE_HADES = 41;
		const SE_ZEUS = 42;
		const SE_KRONOS = 43;
		const SE_APOLLON = 44;
		const SE_ADMETOS = 45;
		const SE_VULKANUS = 46;
		const SE_POSEIDON = 47;
		const SE_ISIS = 48;
		const SE_NIBIRU = 49;
		const SE_HARRINGTON = 50;
		const SE_NEPTUNE_LEVERRIER = 51;
		const SE_NEPTUNE_ADAMS = 52;
		const SE_PLUTO_LOWELL = 53;
		const SE_PLUTO_PICKERING = 54;
		const SE_VULCAN = 55;
		const SE_WHITE_MOON = 56;
		const SE_PROSERPINA = 57;
		const SE_WALDEMATH = 58;
		const SE_FIXSTAR = -10;
		const SE_ASC = 0;
		const SE_MC = 1;
		const SE_ARMC = 2;
		const SE_VERTEX = 3;
		const SE_EQUASC = 4;
		const SE_COASC1 = 5;
		const SE_COASC2 = 6;
		const SE_POLASC = 7;
		const SE_NASCMC = 8;
		const SEFLG_JPLEPH = 1;
		const SEFLG_SWIEPH = 2;
		const SEFLG_MOSEPH = 4;
		const SEFLG_HELCTR = 8;
		const SEFLG_TRUEPOS = 16;
		const SEFLG_J2000 = 32;
		const SEFLG_NONUT = 64;
		const SEFLG_SPEED3 = 128;
		const SEFLG_SPEED = 256;
		const SEFLG_NOGDEFL = 512;
		const SEFLG_NOABERR = 1024;
		const SEFLG_ASTROMETRIC = 1536;
		const SEFLG_EQUATORIAL = 2048;
		const SEFLG_XYZ = 4096;
		const SEFLG_RADIANS = 8192;
		const SEFLG_BARYCTR = 16384;
		const SEFLG_TOPOCTR = 32768;
		const SEFLG_ORBEL_AA = 32768;
		const SEFLG_TROPICAL = 0;
		const SEFLG_SIDEREAL = 65536;
		const SEFLG_ICRS = 131072;
		const SEFLG_DPSIDEPS_1980 = 262144;
		const SEFLG_JPLHOR = 262144;
		const SEFLG_JPLHOR_APPROX = 524288;
		const SEFLG_CENTER_BODY = 1048576;
		const SEFLG_TEST_PLMOON = 2228280;
		const SE_SIDBITS = 256;
		const SE_SIDBIT_ECL_T0 = 256;
		const SE_SIDBIT_SSY_PLANE = 512;
		const SE_SIDBIT_USER_UT = 1024;
		const SE_SIDBIT_ECL_DATE = 2048;
		const SE_SIDBIT_NO_PREC_OFFSET = 4096;
		const SE_SIDBIT_PREC_ORIG = 8192;
		const SE_SIDM_FAGAN_BRADLEY = 0;
		const SE_SIDM_LAHIRI = 1;
		const SE_SIDM_DELUCE = 2;
		const SE_SIDM_RAMAN = 3;
		const SE_SIDM_USHASHASHI = 4;
		const SE_SIDM_KRISHNAMURTI = 5;
		const SE_SIDM_DJWHAL_KHUL = 6;
		const SE_SIDM_YUKTESHWAR = 7;
		const SE_SIDM_JN_BHASIN = 8;
		const SE_SIDM_BABYL_KUGLER1 = 9;
		const SE_SIDM_BABYL_KUGLER2 = 10;
		const SE_SIDM_BABYL_KUGLER3 = 11;
		const SE_SIDM_BABYL_HUBER = 12;
		const SE_SIDM_BABYL_ETPSC = 13;
		const SE_SIDM_ALDEBARAN_15TAU = 14;
		const SE_SIDM_HIPPARCHOS = 15;
		const SE_SIDM_SASSANIAN = 16;
		const SE_SIDM_GALCENT_0SAG = 17;
		const SE_SIDM_J2000 = 18;
		const SE_SIDM_J1900 = 19;
		const SE_SIDM_B1950 = 20;
		const SE_SIDM_SURYASIDDHANTA = 21;
		const SE_SIDM_SURYASIDDHANTA_MSUN = 22;
		const SE_SIDM_ARYABHATA = 23;
		const SE_SIDM_ARYABHATA_MSUN = 24;
		const SE_SIDM_SS_REVATI = 25;
		const SE_SIDM_SS_CITRA = 26;
		const SE_SIDM_TRUE_CITRA = 27;
		const SE_SIDM_TRUE_REVATI = 28;
		const SE_SIDM_TRUE_PUSHYA = 29;
		const SE_SIDM_GALCENT_RGILBRAND = 30;
		const SE_SIDM_GALEQU_IAU1958 = 31;
		const SE_SIDM_GALEQU_TRUE = 32;
		const SE_SIDM_GALEQU_MULA = 33;
		const SE_SIDM_GALALIGN_MARDYKS = 34;
		const SE_SIDM_TRUE_MULA = 35;
		const SE_SIDM_GALCENT_MULA_WILHELM = 36;
		const SE_SIDM_ARYABHATA_522 = 37;
		const SE_SIDM_BABYL_BRITTON = 38;
		const SE_SIDM_TRUE_SHEORAN = 39;
		const SE_SIDM_GALCENT_COCHRANE = 40;
		const SE_SIDM_GALEQU_FIORENZA = 41;
		const SE_SIDM_VALENS_MOON = 42;
		const SE_SIDM_LAHIRI_1940 = 43;
		const SE_SIDM_LAHIRI_VP285 = 44;
		const SE_SIDM_KRISHNAMURTI_VP291 = 45;
		const SE_SIDM_LAHIRI_ICRC = 46;
		const SE_SIDM_USER = 255;
		const SE_NSIDM_PREDEF = 47;
		const SE_NODBIT_MEAN = 1;
		const SE_NODBIT_OSCU = 2;
		const SE_NODBIT_OSCU_BAR = 4;
		const SE_NODBIT_FOPOINT = 256;
		const SEFLG_DEFAULTEPH = 2;
		const SE_MAX_STNAME = 256;
		const SE_ECL_CENTRAL = 1;
		const SE_ECL_NONCENTRAL = 2;
		const SE_ECL_TOTAL = 4;
		const SE_ECL_ANNULAR = 8;
		const SE_ECL_PARTIAL = 16;
		const SE_ECL_ANNULAR_TOTAL = 32;
		const SE_ECL_HYBRID = 32;
		const SE_ECL_PENUMBRAL = 64;
		const SE_ECL_ALLTYPES_SOLAR = 63;
		const SE_ECL_ALLTYPES_LUNAR = 84;
		const SE_ECL_VISIBLE = 128;
		const SE_ECL_MAX_VISIBLE = 256;
		const SE_ECL_1ST_VISIBLE = 512;
		const SE_ECL_PARTBEG_VISIBLE = 512;
		const SE_ECL_2ND_VISIBLE = 1024;
		const SE_ECL_TOTBEG_VISIBLE = 1024;
		const SE_ECL_3RD_VISIBLE = 2048;
		const SE_ECL_TOTEND_VISIBLE = 2048;
		const SE_ECL_4TH_VISIBLE = 4096;
		const SE_ECL_PARTEND_VISIBLE = 4096;
		const SE_ECL_PENUMBBEG_VISIBLE = 8192;
		const SE_ECL_PENUMBEND_VISIBLE = 16384;
		const SE_ECL_OCC_BEG_DAYLIGHT = 8192;
		const SE_ECL_OCC_END_DAYLIGHT = 16384;
		const SE_ECL_ONE_TRY = 32768;
		const SE_CALC_RISE = 1;
		const SE_CALC_SET = 2;
		const SE_CALC_MTRANSIT = 4;
		const SE_CALC_ITRANSIT = 8;
		const SE_BIT_DISC_CENTER = 256;
		const SE_BIT_DISC_BOTTOM = 8192;
		const SE_BIT_GEOCTR_NO_ECL_LAT = 128;
		const SE_BIT_NO_REFRACTION = 512;
		const SE_BIT_CIVIL_TWILIGHT = 1024;
		const SE_BIT_NAUTIC_TWILIGHT = 2048;
		const SE_BIT_ASTRO_TWILIGHT = 4096;
		const SE_BIT_FIXED_DISC_SIZE = 16384;
		const SE_BIT_FORCE_SLOW_METHOD = 32768;
		const SE_BIT_HINDU_RISING = 896;
		const SE_ECL2HOR = 0;
		const SE_EQU2HOR = 1;
		const SE_HOR2ECL = 0;
		const SE_HOR2EQU = 1;
		const SE_TRUE_TO_APP = 0;
		const SE_APP_TO_TRUE = 1;
		const SE_DE_NUMBER = 431;
		const SE_FNAME_DE200 = "de200.eph";
		const SE_FNAME_DE403 = "de403.eph";
		const SE_FNAME_DE404 = "de404.eph";
		const SE_FNAME_DE405 = "de405.eph";
		const SE_FNAME_DE406 = "de406.eph";
		const SE_FNAME_DE431 = "de431.eph";
		const SE_FNAME_DFT = "de431.eph";
		const SE_FNAME_DFT2 = "de406.eph";
		const SE_STARFILE_OLD = "fixstars.cat";
		const SE_STARFILE = "sefstars.txt";
		const SE_ASTNAMFILE = "seasnam.txt";
		const SE_FICTFILE = "seorbel.txt";
		const SE_SPLIT_DEG_ROUND_SEC = 1;
		const SE_SPLIT_DEG_ROUND_MIN = 2;
		const SE_SPLIT_DEG_ROUND_DEG = 4;
		const SE_SPLIT_DEG_ZODIACAL = 8;
		const SE_SPLIT_DEG_NAKSHATRA = 1024;
		const SE_SPLIT_DEG_KEEP_SIGN = 16;
		const SE_SPLIT_DEG_KEEP_DEG = 32;
		const SE_HELIACAL_RISING = 1;
		const SE_HELIACAL_SETTING = 2;
		const SE_MORNING_FIRST = 1;
		const SE_EVENING_LAST = 2;
		const SE_EVENING_FIRST = 3;
		const SE_MORNING_LAST = 4;
		const SE_ACRONYCHAL_RISING = 5;
		const SE_ACRONYCHAL_SETTING = 6;
		const SE_COSMICAL_SETTING = 6;
		const SE_HELFLAG_LONG_SEARCH = 128;
		const SE_HELFLAG_HIGH_PRECISION = 256;
		const SE_HELFLAG_OPTICAL_PARAMS = 512;
		const SE_HELFLAG_NO_DETAILS = 1024;
		const SE_HELFLAG_SEARCH_1_PERIOD = 2048;
		const SE_HELFLAG_VISLIM_DARK = 4096;
		const SE_HELFLAG_VISLIM_NOMOON = 8192;
		const SE_HELFLAG_VISLIM_PHOTOPIC = 16384;
		const SE_HELFLAG_VISLIM_SCOTOPIC = 32768;
		const SE_HELFLAG_AV = 65536;
		const SE_HELFLAG_AVKIND_VR = 65536;
		const SE_HELFLAG_AVKIND_PTO = 131072;
		const SE_HELFLAG_AVKIND_MIN7 = 262144;
		const SE_HELFLAG_AVKIND_MIN9 = 524288;
		const SE_HELFLAG_AVKIND = 983040;
		const TJD_INVALID = 99999999;
		const SIMULATE_VICTORVB = 1;
		const SE_PHOTOPIC_FLAG = 0;
		const SE_SCOTOPIC_FLAG = 1;
		const SE_MIXEDOPIC_FLAG = 2;
		const SE_TIDAL_DE200 = -23.8946;
		const SE_TIDAL_DE403 = -25.58;
		const SE_TIDAL_DE404 = -25.58;
		const SE_TIDAL_DE405 = -25.826;
		const SE_TIDAL_DE406 = -25.826;
		const SE_TIDAL_DE421 = -25.85;
		const SE_TIDAL_DE422 = -25.85;
		const SE_TIDAL_DE430 = -25.82;
		const SE_TIDAL_DE431 = -25.8;
		const SE_TIDAL_26 = -26;
		const SE_TIDAL_STEPHENSON_2016 = -25.85;
		const SE_TIDAL_DEFAULT = -25.8;
		const SE_TIDAL_AUTOMATIC = 999999;
		const SE_TIDAL_MOSEPH = -25.58;
		const SE_TIDAL_SWIEPH = -25.8;
		const SE_TIDAL_JPLEPH = -25.8;
		const SE_DELTAT_AUTOMATIC = 0.0000000001;
		const SE_MODEL_DELTAT = 0;
		const SE_MODEL_PREC_LONGTERM = 1;
		const SE_MODEL_PREC_SHORTTERM = 2;
		const SE_MODEL_NUT = 3;
		const SE_MODEL_BIAS = 4;
		const SE_MODEL_JPLHOR_MODE = 5;
		const SE_MODEL_JPLHORA_MODE = 6;
		const SE_MODEL_SIDT = 7;
		const NSE_MODELS = 8;
		const SEMOD_NPREC = 11;
		const SEMOD_PREC_IAU_1976 = 1;
		const SEMOD_PREC_LASKAR_1986 = 2;
		const SEMOD_PREC_WILL_EPS_LASK = 3;
		const SEMOD_PREC_WILLIAMS_1994 = 4;
		const SEMOD_PREC_SIMON_1994 = 5;
		const SEMOD_PREC_IAU_2000 = 6;
		const SEMOD_PREC_BRETAGNON_2003 = 7;
		const SEMOD_PREC_IAU_2006 = 8;
		const SEMOD_PREC_VONDRAK_2011 = 9;
		const SEMOD_PREC_OWEN_1990 = 10;
		const SEMOD_PREC_NEWCOMB = 11;
		const SEMOD_PREC_DEFAULT = 9;
		const SEMOD_PREC_DEFAULT_SHORT = 9;
		const SEMOD_NNUT = 5;
		const SEMOD_NUT_IAU_1980 = 1;
		const SEMOD_NUT_IAU_CORR_1987 = 2;
		const SEMOD_NUT_IAU_2000A = 3;
		const SEMOD_NUT_IAU_2000B = 4;
		const SEMOD_NUT_WOOLARD = 5;
		const SEMOD_NUT_DEFAULT = 4;
		const SEMOD_NSIDT = 4;
		const SEMOD_SIDT_IAU_1976 = 1;
		const SEMOD_SIDT_IAU_2006 = 2;
		const SEMOD_SIDT_IERS_CONV_2010 = 3;
		const SEMOD_SIDT_LONGTERM = 4;
		const SEMOD_SIDT_DEFAULT = 4;
		const SEMOD_NBIAS = 3;
		const SEMOD_BIAS_NONE = 1;
		const SEMOD_BIAS_IAU2000 = 2;
		const SEMOD_BIAS_IAU2006 = 3;
		const SEMOD_BIAS_DEFAULT = 3;
		const SEMOD_NJPLHOR = 2;
		const SEMOD_JPLHOR_LONG_AGREEMENT = 1;
		const SEMOD_JPLHOR_DEFAULT = 1;
		const SEMOD_NJPLHORA = 3;
		const SEMOD_JPLHORA_1 = 1;
		const SEMOD_JPLHORA_2 = 2;
		const SEMOD_JPLHORA_3 = 3;
		const SEMOD_JPLHORA_DEFAULT = 3;
		const SEMOD_NDELTAT = 5;
		const SEMOD_DELTAT_STEPHENSON_MORRISON_1984 = 1;
		const SEMOD_DELTAT_STEPHENSON_1997 = 2;
		const SEMOD_DELTAT_STEPHENSON_MORRISON_2004 = 3;
		const SEMOD_DELTAT_ESPENAK_MEEUS_2006 = 4;
		const SEMOD_DELTAT_STEPHENSON_ETC_2016 = 5;
		const SEMOD_DELTAT_DEFAULT = 5;
	}
}
