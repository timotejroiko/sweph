{
	"targets": [
		{
			"target_name": "sweph",
			"sources": [
				"<(module_root_dir)/src/*.cpp"
			],
			"include_dirs": [
				"<(module_root_dir)/node_modules/node-addon-api"
			],
			'dependencies': [
      			'<(module_root_dir)/deps/swisseph.gyp:swisseph'
      		],
			"cflags!": [ "-fno-exceptions" ],
			"cflags_cc!": [ "-fno-exceptions" ],
			"xcode_settings": {
				"GCC_ENABLE_CPP_EXCEPTIONS": "YES",
				"CLANG_CXX_LIBRARY": "libc++",
				"MACOSX_DEPLOYMENT_TARGET": "10.7",
			},
			"msvs_settings": {
				"VCCLCompilerTool": { "ExceptionHandling": 1 },
			}
		}
	]
}
