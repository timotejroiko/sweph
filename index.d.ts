declare module "sweph" {
	/**
	 * Close and cleanup swisseph
	 */
	export function close(): void;

	/**
	 * Set user-defined delta T
	 * @param t_acc Delta T value
	 */
	export function set_delta_t_userdef(t_acc: number): void;

	/**
	 * Set ephemeris files location
	 * @param path Path to ephemeris files
	 */
	export function set_ephe_path(path: string): void;

	/**
	 * Set JPL file location
	 * @param file Path to JPL file
	 */
	export function set_jpl_file(file: string): void;

	/**
	 * Set ayanamsa for sidereal mode
	 * @param sid_mode Ayanamsa ID
	 * @param t0 Reference date for custom ayanamsas
	 * @param ayan_t0 Initial value for custom ayanamsas
	 */
	export function set_sid_mode(sid_mode: number, t0: number, ayan_t0: number): void;

	/**
	 * Set user-defined tidal acceleration
	 * @param t_acc tidal acceleration value
	 */
	export function set_tid_acc(t_acc: number): void;

	/**
	 * Set geographic coordinates for topocentric mode
	 * @param geolon Geographic longitude
	 * @param geolat Geographic latitude
	 * @param elevation Elevation
	 */
	export function set_topo(geolon: number, geolat: number, elevation: number): void;

	/**
	 * Get swisseph version
	 */
	export function version(): string;

	/**
	 * Get library path
	 */
	export function get_library_path(): string;

	/**
	 * Get tidal acceleration value
	 */
	export function get_tid_acc(): number;

	/**
	 * Get the name of a planet or object
	 * @param ipl Object ID
	 */
	export function get_planet_name(ipl: number): string;
}
