{
	"targets": [
		{
			"target_name": "swisseph",
			"type": "static_library",
			"direct_dependent_settings": {
				"include_dirs": [
					"swisseph"
				]
			},
			"sources": [
				"swisseph/swecl.c",
				"swisseph/swedate.c",
				"swisseph/swehel.c",
				"swisseph/swehouse.c",
				"swisseph/swejpl.c",
				"swisseph/swemmoon.c",
				"swisseph/swemplan.c",
				"swisseph/sweph.c",
				"swisseph/swephlib.c"
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
				},
			}
		}
	]
}