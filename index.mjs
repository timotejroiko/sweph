import { createRequire } from "module";
import c from "./constants.js";

const require = createRequire(import.meta.url);

/** @type {Omit<import("sweph"), "constants" | "sweph" | "default">} */
const s = require("./build/Release/sweph.node");

export const sweph = {
    ...s,
    constants: c,
    sweph: s,
    default: s
}

export default sweph;
export const constants = c;
export const close = s.close;
export const set_delta_t_userdef = s.set_delta_t_userdef;
export const set_ephe_path = s.set_ephe_path;
export const set_jpl_file = s.set_jpl_file;
export const set_sid_mode = s.set_sid_mode;
export const set_tid_acc = s.set_tid_acc;
export const set_topo = s.set_topo;
export const version = s.version;
export const get_library_path = s.get_library_path;
export const get_tid_acc = s.get_tid_acc;
export const get_planet_name = s.get_planet_name;
export const get_current_file_data = s.get_current_file_data;
export const get_orbital_elements = s.get_orbital_elements;
export const get_ayanamsa_name = s.get_ayanamsa_name;
export const get_ayanamsa_ex_ut = s.get_ayanamsa_ex_ut;
export const get_ayanamsa_ex = s.get_ayanamsa_ex;
export const get_ayanamsa_ut = s.get_ayanamsa_ut;
export const get_ayanamsa = s.get_ayanamsa;
export const calc = s.calc;
export const calc_ut = s.calc_ut;
export const calc_pctr = s.calc_pctr;
export const fixstar = s.fixstar;
export const fixstar_ut = s.fixstar_ut;
export const fixstar_mag = s.fixstar_mag;
export const fixstar2 = s.fixstar2;
export const fixstar2_ut = s.fixstar2_ut;
export const fixstar2_mag = s.fixstar2_mag;
export const nod_aps = s.nod_aps;
export const nod_aps_ut = s.nod_aps_ut;
export const orbit_max_min_true_distance = s.orbit_max_min_true_distance;
export const sol_eclipse_when_loc = s.sol_eclipse_when_loc;
export const sol_eclipse_when_glob = s.sol_eclipse_when_glob;
export const sol_eclipse_how = s.sol_eclipse_how;
export const sol_eclipse_where = s.sol_eclipse_where;
export const lun_occult_when_loc = s.lun_occult_when_loc;
export const lun_occult_when_glob = s.lun_occult_when_glob;
export const lun_occult_where = s.lun_occult_where;
export const lun_eclipse_when_loc = s.lun_eclipse_when_loc;
export const lun_eclipse_when = s.lun_eclipse_when;
export const lun_eclipse_how = s.lun_eclipse_how;
export const rise_trans = s.rise_trans;
export const rise_trans_true_hor = s.rise_trans_true_hor;
export const pheno = s.pheno;
export const pheno_ut = s.pheno_ut;
export const azalt = s.azalt;
export const azalt_rev = s.azalt_rev;
export const refrac = s.refrac;
export const refrac_extended = s.refrac_extended;
export const heliacal_ut = s.heliacal_ut;
export const vis_limit_mag = s.vis_limit_mag;
export const heliacal_pheno_ut = s.heliacal_pheno_ut;
export const julday = s.julday;
export const date_conversion = s.date_conversion;
export const revjul = s.revjul;
export const utc_time_zone = s.utc_time_zone;
export const utc_to_jd = s.utc_to_jd;
export const jdet_to_utc = s.jdet_to_utc;
export const jdut1_to_utc = s.jdut1_to_utc;
export const time_equ = s.time_equ;
export const lmt_to_lat = s.lmt_to_lat;
export const lat_to_lmt = s.lat_to_lmt;
export const deltat = s.deltat;
export const deltat_ex = s.deltat_ex;
export const house_name = s.house_name;
export const houses = s.houses;
export const houses_armc = s.houses_armc;
export const houses_armc_ex2 = s.houses_armc_ex2;
export const houses_ex = s.houses_ex;
export const houses_ex2 = s.houses_ex2;
export const house_pos = s.house_pos;
export const gauquelin_sector = s.gauquelin_sector;
export const sidtime = s.sidtime;
export const sidtime0 = s.sidtime0;
export const cotrans = s.cotrans;
export const cotrans_sp = s.cotrans_sp;
export const degnorm = s.degnorm;
export const radnorm = s.radnorm;
export const split_deg = s.split_deg;
export const csnorm = s.csnorm;
export const difcsn = s.difcsn;
export const difdegn = s.difdegn;
export const difcs2n = s.difcs2n;
export const difdeg2n = s.difdeg2n;
export const csroundsec = s.csroundsec;
export const d2l = s.d2l;
export const day_of_week = s.day_of_week;
export const cs2timestr = s.cs2timestr;
export const cs2lonlatstr = s.cs2lonlatstr;
export const cs2degstr = s.cs2degstr;
export const solcross = s.solcross;
export const solcross_ut = s.solcross_ut;
export const mooncross = s.mooncross;
export const mooncross_ut = s.mooncross_ut;
export const mooncross_node = s.mooncross_node;
export const mooncross_node_ut = s.mooncross_node_ut;
export const helio_cross = s.helio_cross;
export const helio_cross_ut = s.helio_cross_ut;
