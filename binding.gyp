{
	"targets": [
		{
			"target_name": "sweph",
			"sources": [
				"<(module_root_dir)/src/sweph.cpp",
				"<(module_root_dir)/src/functions/*.cpp"
			],
			"include_dirs": [
				"<(module_root_dir)/node_modules/node-addon-api",
				"<(module_root_dir)/src"
			],
			'dependencies': [
	  			'<(module_root_dir)/deps/swisseph.gyp:swisseph'
	  		],
			"defines": [
				"NAPI_DISABLE_CPP_EXCEPTIONS"
			],
			"cflags": [
				"-flto",
				"-Ofast",
				"-march=native",
				"-pipe"
			],
			"cflags_cc": [
				"-flto",
				"-Ofast",
				"-march=native",
				"-pipe"
			],
			"msvs_settings": {
				"VCCLCompilerTool": {
					"AdditionalOptions": [
						"/O2",
						"/GL",
						"/Gw"
					]
				}
			}
		}
	]
}
