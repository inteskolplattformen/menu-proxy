import { LocalDate } from "js-joda";
import { Day, School, SchoolID } from "../types";

export type ListSchools = () => Promise<School[]>;

export type QuerySchool = (id: SchoolID) => Promise<School>;

export interface GetMenuQuery {
	school: SchoolID;
	first: LocalDate;
	last: LocalDate;
}

export type GetMenu = (query: GetMenuQuery) => Promise<Day[]>;

export interface ProviderInfo {
	name: string;
	id: string;
}

export interface ProviderImplementation {
	listSchools: ListSchools;
	querySchool: QuerySchool;
	getMenu: GetMenu;
}

export interface Provider {
	info: ProviderInfo;
	implementation: ProviderImplementation;
}
