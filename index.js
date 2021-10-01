"use strict";

const sweph = require("./build/Release/sweph.node");
sweph.constants = require("./constants.js");
sweph.sweph = sweph;
sweph.default = sweph;
module.exports = sweph;
