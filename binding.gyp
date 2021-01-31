{
	"targets": [
		{
			"target_name": "sweph",
			"sources": [
				"src/sweph.cpp",
				"<!@(node -p \"const { readdirSync, readFileSync, writeFileSync } = require(`fs`); const file = readdirSync(`./src/functions`).map((x,i) => readFileSync(`./src/functions/${x}`, `utf8`).replace(/args/g, `args${i}`).replace(`#include <sweph.h>`, ``)).reduce((a,b) => a + b,`#include <sweph.h>`); writeFileSync(`./src/functions.cpp`, file, `utf8`); `src/functions.cpp`\")"
			],
			"include_dirs": [
				"<!(node -p \"require('node-addon-api').include_dir\")",
				"src"
			],
			'dependencies': [
	  			'deps/swisseph.gyp:swisseph'
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
