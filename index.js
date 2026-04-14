/// <reference path="index.d.ts"/>
"use strict";

/** @type {Omit<import("sweph"), "constants" | "sweph" | "default">} */
// @ts-ignore
const s = require("node-gyp-build")(__dirname);
const c = require("./constants.js");

const sweph = {
    ...s,
    constants: c,
    sweph: s,
    default: s
}

module.exports = sweph;
