#pragma once
#ifndef SWEPH_H
#define SWEPH_H

#include <napi.h>
#include <swephexp.h>

void sweph_close(const Napi::CallbackInfo& info);
void sweph_set_ephe_path(const Napi::CallbackInfo& info);
void sweph_set_jpl_file(const Napi::CallbackInfo& info);
void sweph_set_tid_acc(const Napi::CallbackInfo& info);
void sweph_set_delta_t_userdef(const Napi::CallbackInfo& info);
void sweph_set_topo(const Napi::CallbackInfo& info);
void sweph_set_sid_mode(const Napi::CallbackInfo& info);
Napi::String sweph_version(const Napi::CallbackInfo& info);
Napi::String sweph_get_library_path(const Napi::CallbackInfo& info);
Napi::Number sweph_get_tid_acc(const Napi::CallbackInfo& info);
Napi::Value sweph_get_planet_name(const Napi::CallbackInfo& info);
Napi::Value sweph_calc(const Napi::CallbackInfo& info);
Napi::Value sweph_calc_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_fixstar(const Napi::CallbackInfo& info);
Napi::Value sweph_fixstar_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_fixstar_mag(const Napi::CallbackInfo& info);
Napi::Value sweph_fixstar2(const Napi::CallbackInfo& info);
Napi::Value sweph_fixstar2_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_fixstar2_mag(const Napi::CallbackInfo& info);
Napi::Value sweph_nod_aps(const Napi::CallbackInfo& info);
Napi::Value sweph_nod_aps_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_get_orbital_elements(const Napi::CallbackInfo& info);
Napi::Value sweph_orbit_max_min_true_distance(const Napi::CallbackInfo& info);
Napi::Value sweph_sol_eclipse_when_loc(const Napi::CallbackInfo& info);
Napi::Value sweph_sol_eclipse_when_glob(const Napi::CallbackInfo& info);
Napi::Value sweph_sol_eclipse_how(const Napi::CallbackInfo& info);
Napi::Value sweph_sol_eclipse_where(const Napi::CallbackInfo& info);
Napi::Value sweph_lun_occult_when_loc(const Napi::CallbackInfo& info);
Napi::Value sweph_lun_occult_when_glob(const Napi::CallbackInfo& info);
Napi::Value sweph_lun_occult_where(const Napi::CallbackInfo& info);
Napi::Value sweph_lun_eclipse_when(const Napi::CallbackInfo& info);
Napi::Value sweph_lun_eclipse_when_loc(const Napi::CallbackInfo& info);
Napi::Value sweph_lun_eclipse_how(const Napi::CallbackInfo& info);
Napi::Value sweph_rise_trans(const Napi::CallbackInfo& info);
Napi::Value sweph_rise_trans_true_hor(const Napi::CallbackInfo& info);
Napi::Value sweph_pheno(const Napi::CallbackInfo& info);
Napi::Value sweph_pheno_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_azalt(const Napi::CallbackInfo& info);
Napi::Value sweph_azalt_rev(const Napi::CallbackInfo& info);
Napi::Value sweph_refrac(const Napi::CallbackInfo& info);
Napi::Value sweph_refrac_extended(const Napi::CallbackInfo& info);
Napi::Value sweph_vis_limit_mag(const Napi::CallbackInfo& info);
Napi::Value sweph_heliacal_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_heliacal_pheno_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_julday(const Napi::CallbackInfo& info);
Napi::Value sweph_revjul(const Napi::CallbackInfo& info);
Napi::Value sweph_date_conversion(const Napi::CallbackInfo& info);
Napi::Value sweph_utc_time_zone(const Napi::CallbackInfo& info);
Napi::Value sweph_utc_to_jd(const Napi::CallbackInfo& info);
Napi::Value sweph_jdet_to_utc(const Napi::CallbackInfo& info);
Napi::Value sweph_jdut1_to_utc(const Napi::CallbackInfo& info);
Napi::Value sweph_time_equ(const Napi::CallbackInfo& info);
Napi::Value sweph_lmt_to_lat(const Napi::CallbackInfo& info);
Napi::Value sweph_lat_to_lmt(const Napi::CallbackInfo& info);
Napi::Value sweph_deltat(const Napi::CallbackInfo& info);
Napi::Value sweph_deltat_ex(const Napi::CallbackInfo& info);
Napi::Value sweph_get_ayanamsa(const Napi::CallbackInfo& info);
Napi::Value sweph_get_ayanamsa_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_get_ayanamsa_ex(const Napi::CallbackInfo& info);
Napi::Value sweph_get_ayanamsa_ex_ut(const Napi::CallbackInfo& info);
Napi::Value sweph_get_ayanamsa_name(const Napi::CallbackInfo& info);
Napi::Value sweph_house_name(const Napi::CallbackInfo& info);
Napi::Value sweph_houses(const Napi::CallbackInfo& info);
Napi::Value sweph_houses_ex(const Napi::CallbackInfo& info);
Napi::Value sweph_houses_ex2(const Napi::CallbackInfo& info);
Napi::Value sweph_houses_armc(const Napi::CallbackInfo& info);
Napi::Value sweph_houses_armc_ex2(const Napi::CallbackInfo& info);
Napi::Value sweph_house_pos(const Napi::CallbackInfo& info);
Napi::Value sweph_gauquelin_sector(const Napi::CallbackInfo& info);
Napi::Value sweph_sidtime(const Napi::CallbackInfo& info);
Napi::Value sweph_sidtime0(const Napi::CallbackInfo& info);
Napi::Value sweph_cotrans(const Napi::CallbackInfo& info);
Napi::Value sweph_cotrans_sp(const Napi::CallbackInfo& info);
Napi::Value sweph_degnorm(const Napi::CallbackInfo& info);
Napi::Value sweph_radnorm(const Napi::CallbackInfo& info);
Napi::Value sweph_csnorm(const Napi::CallbackInfo& info);
Napi::Value sweph_split_deg(const Napi::CallbackInfo& info);
Napi::Value sweph_difcsn(const Napi::CallbackInfo& info);
Napi::Value sweph_difcs2n(const Napi::CallbackInfo& info);
Napi::Value sweph_difdegn(const Napi::CallbackInfo& info);
Napi::Value sweph_difdeg2n(const Napi::CallbackInfo& info);
Napi::Value sweph_csroundsec(const Napi::CallbackInfo& info);
Napi::Value sweph_d2l(const Napi::CallbackInfo& info);
Napi::Value sweph_day_of_week(const Napi::CallbackInfo& info);
Napi::Value sweph_cs2timestr(const Napi::CallbackInfo& info);
Napi::Value sweph_cs2lonlatstr(const Napi::CallbackInfo& info);
Napi::Value sweph_cs2degstr(const Napi::CallbackInfo& info);

#endif 