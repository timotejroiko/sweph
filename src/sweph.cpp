#include <sweph.h>

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports["close"] = Napi::Function::New(env, sweph_close);
	exports["set_delta_t_userdef"] = Napi::Function::New(env, sweph_set_delta_t_userdef);
	exports["set_ephe_path"] = Napi::Function::New(env, sweph_set_ephe_path);
	exports["set_jpl_file"] = Napi::Function::New(env, sweph_set_jpl_file);
	exports["set_sid_mode"] = Napi::Function::New(env, sweph_set_sid_mode);
	exports["set_tid_acc"] = Napi::Function::New(env, sweph_set_tid_acc);
	exports["set_topo"] = Napi::Function::New(env, sweph_set_topo);
	exports["version"] = Napi::Function::New(env, sweph_version);
	exports["get_library_path"] = Napi::Function::New(env, sweph_get_library_path);
	exports["get_tid_acc"] = Napi::Function::New(env, sweph_get_tid_acc);
	exports["get_planet_name"] = Napi::Function::New(env, sweph_get_planet_name);
	exports["get_current_file_data"] = Napi::Function::New(env, sweph_get_current_file_data);
	exports["get_orbital_elements"] = Napi::Function::New(env, sweph_get_orbital_elements);
	exports["get_ayanamsa_name"] = Napi::Function::New(env, sweph_get_ayanamsa_name);
	exports["get_ayanamsa_ex_ut"] = Napi::Function::New(env, sweph_get_ayanamsa_ex_ut);
	exports["get_ayanamsa_ex"] = Napi::Function::New(env, sweph_get_ayanamsa_ex);
	exports["get_ayanamsa_ut"] = Napi::Function::New(env, sweph_get_ayanamsa_ut);
	exports["get_ayanamsa"] = Napi::Function::New(env, sweph_get_ayanamsa);
	exports["calc"] = Napi::Function::New(env, sweph_calc);
	exports["calc_ut"] = Napi::Function::New(env, sweph_calc_ut);
	exports["calc_pctr"] = Napi::Function::New(env, sweph_calc_pctr);
	exports["fixstar"] = Napi::Function::New(env, sweph_fixstar);
	exports["fixstar_ut"] = Napi::Function::New(env, sweph_fixstar_ut);
	exports["fixstar_mag"] = Napi::Function::New(env, sweph_fixstar_mag);
	exports["fixstar2"] = Napi::Function::New(env, sweph_fixstar2);
	exports["fixstar2_ut"] = Napi::Function::New(env, sweph_fixstar2_ut);
	exports["fixstar2_mag"] = Napi::Function::New(env, sweph_fixstar2_mag);
	exports["nod_aps"] = Napi::Function::New(env, sweph_nod_aps);
	exports["nod_aps_ut"] = Napi::Function::New(env, sweph_nod_aps_ut);
	exports["orbit_max_min_true_distance"] = Napi::Function::New(env, sweph_orbit_max_min_true_distance);
	exports["sol_eclipse_when_loc"] = Napi::Function::New(env, sweph_sol_eclipse_when_loc);
	exports["sol_eclipse_when_glob"] = Napi::Function::New(env, sweph_sol_eclipse_when_glob);
	exports["sol_eclipse_how"] = Napi::Function::New(env, sweph_sol_eclipse_how);
	exports["sol_eclipse_where"] = Napi::Function::New(env, sweph_sol_eclipse_where);
	exports["lun_occult_when_loc"] = Napi::Function::New(env, sweph_lun_occult_when_loc);
	exports["lun_occult_when_glob"] = Napi::Function::New(env, sweph_lun_occult_when_glob);
	exports["lun_occult_where"] = Napi::Function::New(env, sweph_lun_occult_where);
	exports["lun_eclipse_when_loc"] = Napi::Function::New(env, sweph_lun_eclipse_when_loc);
	exports["lun_eclipse_when"] = Napi::Function::New(env, sweph_lun_eclipse_when);
	exports["lun_eclipse_how"] = Napi::Function::New(env, sweph_lun_eclipse_how);
	exports["rise_trans"] = Napi::Function::New(env, sweph_rise_trans);
	exports["rise_trans_true_hor"] = Napi::Function::New(env, sweph_rise_trans_true_hor);
	exports["pheno"] = Napi::Function::New(env, sweph_pheno);
	exports["pheno_ut"] = Napi::Function::New(env, sweph_pheno_ut);
	exports["azalt"] = Napi::Function::New(env, sweph_azalt);
	exports["azalt_rev"] = Napi::Function::New(env, sweph_azalt_rev);
	exports["refrac"] = Napi::Function::New(env, sweph_refrac);
	exports["refrac_extended"] = Napi::Function::New(env, sweph_refrac_extended);
	exports["heliacal_ut"] = Napi::Function::New(env, sweph_heliacal_ut);
	exports["vis_limit_mag"] = Napi::Function::New(env, sweph_vis_limit_mag);
	exports["heliacal_pheno_ut"] = Napi::Function::New(env, sweph_heliacal_pheno_ut);
	exports["julday"] = Napi::Function::New(env, sweph_julday);
	exports["date_conversion"] = Napi::Function::New(env, sweph_date_conversion);
	exports["revjul"] = Napi::Function::New(env, sweph_revjul);
	exports["utc_time_zone"] = Napi::Function::New(env, sweph_utc_time_zone);
	exports["utc_to_jd"] = Napi::Function::New(env, sweph_utc_to_jd);
	exports["jdet_to_utc"] = Napi::Function::New(env, sweph_jdet_to_utc);
	exports["jdut1_to_utc"] = Napi::Function::New(env, sweph_jdut1_to_utc);
	exports["time_equ"] = Napi::Function::New(env, sweph_time_equ);
	exports["lmt_to_lat"] = Napi::Function::New(env, sweph_lmt_to_lat);
	exports["lat_to_lmt"] = Napi::Function::New(env, sweph_lat_to_lmt);
	exports["deltat"] = Napi::Function::New(env, sweph_deltat);
	exports["deltat_ex"] = Napi::Function::New(env, sweph_deltat_ex);
	exports["house_name"] = Napi::Function::New(env, sweph_house_name);
	exports["houses"] = Napi::Function::New(env, sweph_houses);
	exports["houses_armc"] = Napi::Function::New(env, sweph_houses_armc);
	exports["houses_armc_ex2"] = Napi::Function::New(env, sweph_houses_armc_ex2);
	exports["houses_ex"] = Napi::Function::New(env, sweph_houses_ex);
	exports["houses_ex2"] = Napi::Function::New(env, sweph_houses_ex2);
	exports["house_pos"] = Napi::Function::New(env, sweph_house_pos);
	exports["gauquelin_sector"] = Napi::Function::New(env, sweph_gauquelin_sector);
	exports["sidtime"] = Napi::Function::New(env, sweph_sidtime);
	exports["sidtime0"] = Napi::Function::New(env, sweph_sidtime0);
	exports["cotrans"] = Napi::Function::New(env, sweph_cotrans);
	exports["cotrans_sp"] = Napi::Function::New(env, sweph_cotrans_sp);
	exports["degnorm"] = Napi::Function::New(env, sweph_degnorm);
	exports["radnorm"] = Napi::Function::New(env, sweph_radnorm);
	exports["split_deg"] = Napi::Function::New(env, sweph_split_deg);
	exports["csnorm"] = Napi::Function::New(env, sweph_csnorm);
	exports["difcsn"] = Napi::Function::New(env, sweph_difcsn);
	exports["difdegn"] = Napi::Function::New(env, sweph_difdegn);
	exports["difcs2n"] = Napi::Function::New(env, sweph_difcs2n);
	exports["difdeg2n"] = Napi::Function::New(env, sweph_difdeg2n);
	exports["csroundsec"] = Napi::Function::New(env, sweph_csroundsec);
	exports["d2l"] = Napi::Function::New(env, sweph_d2l);
	exports["day_of_week"] = Napi::Function::New(env, sweph_day_of_week);
	exports["cs2timestr"] = Napi::Function::New(env, sweph_cs2timestr);
	exports["cs2lonlatstr"] = Napi::Function::New(env, sweph_cs2lonlatstr);
	exports["cs2degstr"] = Napi::Function::New(env, sweph_cs2degstr);
	return exports;
}

bool sweph_is_type(int type, Napi::Value data) {
	switch (type) {
		case NUMBER: return data.IsNumber();
		case STRING: return data.IsString();
		case STRINGNULL: return data.IsString() || data.IsNull();
		case ARRAY: return data.IsArray();
		case TRUEFALSE: return data.IsBoolean();
		default: return false;
	}
}

bool sweph_type_check(const std::pair<int, const char*> types[], const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if((int)info.Length() < types[0].first) {
		Napi::TypeError::New(env, types[0].second).ThrowAsJavaScriptException();
		return false;
	}
	for(int i = 0; i < types[0].first; i++) {
		if(!sweph_is_type(types[i+1].first, info[i])) {
			Napi::TypeError::New(env, types[i+1].second).ThrowAsJavaScriptException();
			return false;
		}
	}
	return true;
}

bool sweph_double_array_converter(double *target, int size, Napi::Value data) {
	Napi::Array x = data.As<Napi::Array>();
	for(int i = 0; i < size; i++) {
		Napi::Value v = x[i];
		if(!v.IsNumber()) {
			return false;
		}
		target[i] = v.As<Napi::Number>().DoubleValue();
	}
	return true;
}

Napi::Array sweph_js_array_converter(double *src, int size, Napi::Env env) {
	Napi::Array array = Napi::Array::New(env);
	for(int i = 0; i < size; i++) {
		array[i] = Napi::Number::New(env, src[i]);
	}
	return array;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
