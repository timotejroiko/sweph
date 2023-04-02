{
	"targets": [
		{
			"target_name": "sweph",
			"sources": [
				"src/sweph.cpp",
				"src/functions.cpp"
			],
			"include_dirs": [
				"<!(node -p \"require('node-addon-api').include_dir\")",
				"src"
			],
			"dependencies": [
	  			"swisseph"
	  		],
			"defines": [
				"NAPI_DISABLE_CPP_EXCEPTIONS"
			]
		},
		{
			"target_name": "swisseph",
			'type': "static_library",
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
			"direct_dependent_settings": {
				"include_dirs": [
					"swisseph"
				]
			}
		}
	]
}
