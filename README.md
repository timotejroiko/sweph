# Sweph

The definitive Swiss Ephemeris bindings for Node.js  
Everything you need to create Astrology and Astronomy applications with JavaScript and Node.JS

* 100% API coverage
* Built-in Typescript declarations and ESM exports
* Built-in intellisense documentation
* Version matched
* Built with Node's N-API

[Official programmer's documentation for the Swiss Ephemeris by Astrodienst AG](https://www.astro.com/swisseph/swephprg.htm)  
[Official guide for the Swiss Ephemeris by Astrodienst AG](https://www.astro.com/ftp/swisseph/doc/swisseph.htm)  
[Sweph on GitHub](https://github.com/timotejroiko/sweph)  
[Sweph on NPM](https://npmjs.com/package/sweph)

## Installation and Licensing

This library follows the licensing requirements for the Swiss Ephemeris by Astrodienst AG.

### - GPL

Up to and including version `2.10.0`, this library is licensed under `GPL-2.0`.  
To install and use this library under GPL, use `npm install sweph@gpl` or `npm install sweph@2.10.0`.

### - AGPL

Starting from version `2.10.1` and later, this library is licensed under `AGPL-3.0`.  
To install and use the latest version of this library under AGPL, use `npm install sweph` or `npm install sweph@latest`.

### - LGPL

If you own a professional license for the Swiss Ephemeris, you may use any version of this library under `LGPL-3.0`.

## Versioning

This library is version locked to the Swiss Ephemeris in addition to its own revisions. For example, version `2.10.1-1` corresponds to the Swiss Ephemeris version `2.10.1` and this library's revision `1`.

Updates to this library will be released under new revisions, while updates to Swiss Ephemeris will be released under matching SemVer versions.

## Documentation

This library is fully typed and documented via intellisense. To access its documentation simply hover over its functions in your favorite code editor:

![docs_example](docs.gif)

## Ephemeris files

Ephemeris files are required to enable high precision calculations for planets and asteroids. This library does not include any ephemeris files by default, but you can download them from the official Swiss Ephemeris Github repository (main planets only) or the official Astrodienst Dropox folder (all files):

* Swiss Ephemeris Github: [https://github.com/aloistr/swisseph/tree/master/ephe](https://github.com/aloistr/swisseph/tree/master/ephe)
* Astrodienst Dropbox [https://www.dropbox.com/scl/fo/y3naz62gy6f6qfrhquu7u/h?rlkey=ejltdhb262zglm7eo6yfj2940&dl=0](https://www.dropbox.com/scl/fo/y3naz62gy6f6qfrhquu7u/h?rlkey=ejltdhb262zglm7eo6yfj2940&dl=0)

Each main ephemeris file covers a range of 600 years starting from the century indicated in its name, for example the file `sepl_18.se1` is valid from year 1800 until year 2400. The following files are available:

* sepl files - planets
* seplm files - planets (BC)
* semo files - moon
* semom files - moon (BC)
* seas files - main asteroids
* seasm files - main asteroids (BC)

For advanced usage, the following files and folders can also be found in the dropbox link:

* all_ast - files for all asteroids (600 years range)
* long_ast - files for named asteroids (6000 years range)
* jpl binary files - files for NASA's JPL ephemerides
* ephe/sat folder - files for planetary moons

To use the files, download them, store them in some folder, then call `set_ephe_path()` to point the library to that folder. Asteroid files should be placed in `astxxx` subfolders, the same way they appear in the dropbox asteroids section. Files for planetary moons should be placed in a `sat` subfolder.

More information can be found in the files sections of the [Swiss Ephemeris documentation](https://www.astro.com/ftp/swisseph/doc/swisseph.htm).

## Contributing

If you find any inaccuracy or bug in this library, or if you find an upstream update that is not yet included in this library, feel free to open an issue or a pull request.

## Limitations

* While worker_threads are supported, the underlying C library is single threaded and contains process-wide settings. Functions such as `set_ephe_path()` or `set_sid_mode()` will affect the entire process, including all worker_threads. While you can still use worker_threads as long as you don't change settings from other threads in the middle of calculations, true thread-safe multithreading can only be achieved using child_process.

* This library is a C/C++ add-on designed for Node.JS only, it will not work in browsers, other JS engines or in any other environment that does not support native C/C++ add-ons made with Node's N-API. In order to install this library, the target system must have the necessary build tools installed, such as `python`, `make` and `gcc` on Linux, `xcode` on Mac, `visual c++ build tools` on Windows, and/or other equivalent solutions.

## Copyright

Copyright © 2021-2023, Timotej Valentin Rojko

This library is offered free of charge for any type of use, including commercial use, however, if you're an individual or a company using this library in commercial products and/or services, consider subscribing to the appropriate sponsorship level [here](https://github.com/sponsors/timotejroiko) and get priority support for your business.
