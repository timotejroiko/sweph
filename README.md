# Sweph

The definitive Swiss Ephemeris bindings for Node.js  
Everything you need to create Astrology and Astronomy applications with JavaScript and node

* 100% API coverage
* Built-in Typescript declarations and ESM exports
* Built-in intellisense documentation
* Version matched
* Made with the N-API

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

This library does not include any ephemeris files. To use the Swiss Ephemeris files, download them from [https://www.astro.com/ftp/swisseph/ephe/](https://www.astro.com/ftp/swisseph/ephe/) and call `set_ephe_path()` to point the library to the folder containing the ephemeris files.

Each main ephemeris file covers a range of 600 years starting from the century indicated in its name, for example the file `sepl_18.se1` is valid from year 1800 until year 2400. The following files are available:

* sepl files - planets (AD)
* seplm files - planets (BC)
* semo files - moon (AD)
* semom files - moon (BC)
* seas files - main asteroids (AD)
* seasm files - main asteroids (BC)

For advanced usage, the following files can also be found:

* astxxx folders - files for individual asteroids (600 years)
* longfiles folder - files for individual asteroids (6000 years)
* jplfiles folder - files for NASA's JPL ephemerides
* sat folder - files for planetary moons

More information can be found in the [Swiss Ephemeris files documentation](https://www.astro.com/ftp/swisseph/doc/swisseph.htm).

## Contributing

If you find any inaccuracy or bug in this library, or if you find an upstream update that is not yet included in this library, feel free to open an issue or a pull request.

## Limitations

* While worker_threads are supported, the underlying C library is single threaded and contains process-wide settings. Functions such as `set_ephe_path()` or `set_sid_mode()` will affect the entire process, including all worker_threads. While you can still use worker_threads as long as you don't change settings from other threads in the middle of calculations, true thread-safe multithreading can only be achieved using child_process.

* This library is a C/C++ add-on designed for Node.JS only, it will not work in browsers, other JS engines or in any other environment that does not support native C/C++ add-ons. In order to install this library, the target system must have the necessary build tools installed, such as `python`, `make` and `gcc` on Linux, `xcode` on Mac, `visual c++` on Windows, and/or other equivalent solutions.

## Copyright

Copyright © 2021-2023, Timotej Valentin Rojko

This library is offered free of charge for any type of use, including commercial use, however, if you're an individual or a company using this library in commercial products and/or services, consider subscribing to the appropriate sponsorship level [here](https://github.com/sponsors/timotejroiko) and get priority support for your business.
